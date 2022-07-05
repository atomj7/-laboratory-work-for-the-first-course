package com.innowise.contract.tool.web.rest;

import com.innowise.contract.tool.repository.ContractRepository;
import com.innowise.contract.tool.service.ContractService;
import com.innowise.contract.tool.service.dto.ContractDto;
import com.innowise.contract.tool.web.rest.errors.BadRequestAlertException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Optional;
import javax.validation.Valid;
import javax.validation.constraints.NotNull;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;
import org.springframework.data.domain.Pageable;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.http.server.reactive.ServerHttpRequest;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.server.ResponseStatusException;
import org.springframework.web.util.UriComponentsBuilder;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;
import tech.jhipster.web.util.HeaderUtil;
import tech.jhipster.web.util.PaginationUtil;
import tech.jhipster.web.util.reactive.ResponseUtil;

/**
 * REST controller for managing {@link com.innowise.contract.tool.domain.Contract}.
 */
@RestController
@RequestMapping("/api")
public class ContractResource {

    private final Logger log = LoggerFactory.getLogger(ContractResource.class);

    private static final String ENTITY_NAME = "contract";

    @Value("${jhipster.clientApp.name}")
    private String applicationName;

    private final ContractService contractService;

    private final ContractRepository contractRepository;

    public ContractResource(ContractService contractService, ContractRepository contractRepository) {
        this.contractService = contractService;
        this.contractRepository = contractRepository;
    }

    /**
     * {@code POST  /contracts} : Create a new contract.
     *
     * @param contractDto the contractDto to create.
     * @return the {@link ResponseEntity} with status {@code 201 (Created)} and with body the new contractDto, or with status {@code 400 (Bad Request)} if the contract has already an ID.
     * @throws URISyntaxException if the Location URI syntax is incorrect.
     */
    @PostMapping("/contracts")
    public Mono<ResponseEntity<ContractDto>> createContract(@Valid @RequestBody ContractDto contractDto) throws URISyntaxException {
        log.debug("REST request to save Contract : {}", contractDto);
        if (contractDto.getId() != null) {
            throw new BadRequestAlertException("A new contract cannot already have an ID", ENTITY_NAME, "idexists");
        }
        return contractService
            .save(contractDto)
            .map(result -> {
                try {
                    return ResponseEntity
                        .created(new URI("/api/contracts/" + result.getId()))
                        .headers(HeaderUtil.createEntityCreationAlert(applicationName, true, ENTITY_NAME, result.getId().toString()))
                        .body(result);
                } catch (URISyntaxException e) {
                    throw new RuntimeException(e);
                }
            });
    }

    /**
     * {@code PUT  /contracts/:id} : Updates an existing contract.
     *
     * @param id the id of the contractDto to save.
     * @param contractDto the contractDto to update.
     * @return the {@link ResponseEntity} with status {@code 200 (OK)} and with body the updated contractDto,
     * or with status {@code 400 (Bad Request)} if the contractDto is not valid,
     * or with status {@code 500 (Internal Server Error)} if the contractDto couldn't be updated.
     * @throws URISyntaxException if the Location URI syntax is incorrect.
     */
    @PutMapping("/contracts/{id}")
    public Mono<ResponseEntity<ContractDto>> updateContract(
        @PathVariable(value = "id", required = false) final Long id,
        @Valid @RequestBody ContractDto contractDto
    ) throws URISyntaxException {
        log.debug("REST request to update Contract : {}, {}", id, contractDto);
        if (contractDto.getId() == null) {
            throw new BadRequestAlertException("Invalid id", ENTITY_NAME, "idnull");
        }
        if (!Objects.equals(id, contractDto.getId())) {
            throw new BadRequestAlertException("Invalid ID", ENTITY_NAME, "idinvalid");
        }

        return contractRepository
            .existsById(id)
            .flatMap(exists -> {
                if (!exists) {
                    return Mono.error(new BadRequestAlertException("Entity not found", ENTITY_NAME, "idnotfound"));
                }

                return contractService
                    .update(contractDto)
                    .switchIfEmpty(Mono.error(new ResponseStatusException(HttpStatus.NOT_FOUND)))
                    .map(result ->
                        ResponseEntity
                            .ok()
                            .headers(HeaderUtil.createEntityUpdateAlert(applicationName, true, ENTITY_NAME, result.getId().toString()))
                            .body(result)
                    );
            });
    }

    /**
     * {@code PATCH  /contracts/:id} : Partial updates given fields of an existing contract, field will ignore if it is null
     *
     * @param id the id of the contractDto to save.
     * @param contractDto the contractDto to update.
     * @return the {@link ResponseEntity} with status {@code 200 (OK)} and with body the updated contractDto,
     * or with status {@code 400 (Bad Request)} if the contractDto is not valid,
     * or with status {@code 404 (Not Found)} if the contractDto is not found,
     * or with status {@code 500 (Internal Server Error)} if the contractDto couldn't be updated.
     * @throws URISyntaxException if the Location URI syntax is incorrect.
     */
    @PatchMapping(value = "/contracts/{id}", consumes = { "application/json", "application/merge-patch+json" })
    public Mono<ResponseEntity<ContractDto>> partialUpdateContract(
        @PathVariable(value = "id", required = false) final Long id,
        @NotNull @RequestBody ContractDto contractDto
    ) throws URISyntaxException {
        log.debug("REST request to partial update Contract partially : {}, {}", id, contractDto);
        if (contractDto.getId() == null) {
            throw new BadRequestAlertException("Invalid id", ENTITY_NAME, "idnull");
        }
        if (!Objects.equals(id, contractDto.getId())) {
            throw new BadRequestAlertException("Invalid ID", ENTITY_NAME, "idinvalid");
        }

        return contractRepository
            .existsById(id)
            .flatMap(exists -> {
                if (!exists) {
                    return Mono.error(new BadRequestAlertException("Entity not found", ENTITY_NAME, "idnotfound"));
                }

                Mono<ContractDto> result = contractService.partialUpdate(contractDto);

                return result
                    .switchIfEmpty(Mono.error(new ResponseStatusException(HttpStatus.NOT_FOUND)))
                    .map(res ->
                        ResponseEntity
                            .ok()
                            .headers(HeaderUtil.createEntityUpdateAlert(applicationName, true, ENTITY_NAME, res.getId().toString()))
                            .body(res)
                    );
            });
    }

    /**
     * {@code GET  /contracts} : get all the contracts.
     *
     * @param pageable the pagination information.
     * @param request a {@link ServerHttpRequest} request.
     * @return the {@link ResponseEntity} with status {@code 200 (OK)} and the list of contracts in body.
     */
    @GetMapping("/contracts")
    public Mono<ResponseEntity<List<ContractDto>>> getAllContracts(
        @org.springdoc.api.annotations.ParameterObject Pageable pageable,
        ServerHttpRequest request
    ) {
        log.debug("REST request to get a page of Contracts");
        return contractService
            .countAll()
            .zipWith(contractService.findAll(pageable).collectList())
            .map(countWithEntities ->
                ResponseEntity
                    .ok()
                    .headers(
                        PaginationUtil.generatePaginationHttpHeaders(
                            UriComponentsBuilder.fromHttpRequest(request),
                            new PageImpl<>(countWithEntities.getT2(), pageable, countWithEntities.getT1())
                        )
                    )
                    .body(countWithEntities.getT2())
            );
    }

    /**
     * {@code GET  /contracts/:id} : get the "id" contract.
     *
     * @param id the id of the contractDto to retrieve.
     * @return the {@link ResponseEntity} with status {@code 200 (OK)} and with body the contractDto, or with status {@code 404 (Not Found)}.
     */
    @GetMapping("/contracts/{id}")
    public Mono<ResponseEntity<ContractDto>> getContract(@PathVariable Long id) {
        log.debug("REST request to get Contract : {}", id);
        Mono<ContractDto> contractDto = contractService.findOne(id);
        return ResponseUtil.wrapOrNotFound(contractDto);
    }

    /**
     * {@code DELETE  /contracts/:id} : delete the "id" contract.
     *
     * @param id the id of the contractDto to delete.
     * @return the {@link ResponseEntity} with status {@code 204 (NO_CONTENT)}.
     */
    @DeleteMapping("/contracts/{id}")
    @ResponseStatus(code = HttpStatus.NO_CONTENT)
    public Mono<ResponseEntity<Void>> deleteContract(@PathVariable Long id) {
        log.debug("REST request to delete Contract : {}", id);
        return contractService
            .delete(id)
            .map(result ->
                ResponseEntity
                    .noContent()
                    .headers(HeaderUtil.createEntityDeletionAlert(applicationName, true, ENTITY_NAME, id.toString()))
                    .build()
            );
    }
}
