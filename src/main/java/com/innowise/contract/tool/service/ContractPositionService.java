package com.innowise.contract.tool.service;

import com.innowise.contract.tool.service.dto.ContractPositionDto;
import org.springframework.data.domain.Pageable;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Interface for managing {@link com.innowise.contract.tool.domain.ContractPosition}.
 */
public interface ContractPositionService {
    /**
     * Save a contractPosition.
     *
     * @param contractPositionDto the entity to save.
     * @return the persisted entity.
     */
    Mono<ContractPositionDto> save(ContractPositionDto contractPositionDto);

    /**
     * Updates a contractPosition.
     *
     * @param contractPositionDto the entity to update.
     * @return the persisted entity.
     */
    Mono<ContractPositionDto> update(ContractPositionDto contractPositionDto);

    /**
     * Partially updates a contractPosition.
     *
     * @param contractPositionDto the entity to update partially.
     * @return the persisted entity.
     */
    Mono<ContractPositionDto> partialUpdate(ContractPositionDto contractPositionDto);

    /**
     * Get all the contractPositions.
     *
     * @param pageable the pagination information.
     * @return the list of entities.
     */
    Flux<ContractPositionDto> findAll(Pageable pageable);

    /**
     * Returns the number of contractPositions available.
     * @return the number of entities in the database.
     *
     */
    Mono<Long> countAll();

    /**
     * Get the "id" contractPosition.
     *
     * @param id the id of the entity.
     * @return the entity.
     */
    Mono<ContractPositionDto> findOne(Long id);

    /**
     * Delete the "id" contractPosition.
     *
     * @param id the id of the entity.
     * @return a Mono to signal the deletion
     */
    Mono<Void> delete(Long id);
}
