package com.innowise.contract.tool.service;

import com.innowise.contract.tool.service.dto.ContractDto;
import org.springframework.data.domain.Pageable;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Interface for managing {@link com.innowise.contract.tool.domain.Contract}.
 */
public interface ContractService {
    /**
     * Save a contract.
     *
     * @param contractDto the entity to save.
     * @return the persisted entity.
     */
    Mono<ContractDto> save(ContractDto contractDto);

    /**
     * Updates a contract.
     *
     * @param contractDto the entity to update.
     * @return the persisted entity.
     */
    Mono<ContractDto> update(ContractDto contractDto);

    /**
     * Partially updates a contract.
     *
     * @param contractDto the entity to update partially.
     * @return the persisted entity.
     */
    Mono<ContractDto> partialUpdate(ContractDto contractDto);

    /**
     * Get all the contracts.
     *
     * @param pageable the pagination information.
     * @return the list of entities.
     */
    Flux<ContractDto> findAll(Pageable pageable);

    /**
     * Returns the number of contracts available.
     * @return the number of entities in the database.
     *
     */
    Mono<Long> countAll();

    /**
     * Get the "id" contract.
     *
     * @param id the id of the entity.
     * @return the entity.
     */
    Mono<ContractDto> findOne(Long id);

    /**
     * Delete the "id" contract.
     *
     * @param id the id of the entity.
     * @return a Mono to signal the deletion
     */
    Mono<Void> delete(Long id);
}
