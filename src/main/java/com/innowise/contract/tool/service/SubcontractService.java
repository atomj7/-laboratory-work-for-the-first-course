package com.innowise.contract.tool.service;

import com.innowise.contract.tool.service.dto.SubcontractDto;
import org.springframework.data.domain.Pageable;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Interface for managing {@link com.innowise.contract.tool.domain.Subcontract}.
 */
public interface SubcontractService {
    /**
     * Save a subcontract.
     *
     * @param subcontractDto the entity to save.
     * @return the persisted entity.
     */
    Mono<SubcontractDto> save(SubcontractDto subcontractDto);

    /**
     * Updates a subcontract.
     *
     * @param subcontractDto the entity to update.
     * @return the persisted entity.
     */
    Mono<SubcontractDto> update(SubcontractDto subcontractDto);

    /**
     * Partially updates a subcontract.
     *
     * @param subcontractDto the entity to update partially.
     * @return the persisted entity.
     */
    Mono<SubcontractDto> partialUpdate(SubcontractDto subcontractDto);

    /**
     * Get all the subcontracts.
     *
     * @param pageable the pagination information.
     * @return the list of entities.
     */
    Flux<SubcontractDto> findAll(Pageable pageable);

    /**
     * Returns the number of subcontracts available.
     * @return the number of entities in the database.
     *
     */
    Mono<Long> countAll();

    /**
     * Get the "id" subcontract.
     *
     * @param id the id of the entity.
     * @return the entity.
     */
    Mono<SubcontractDto> findOne(Long id);

    /**
     * Delete the "id" subcontract.
     *
     * @param id the id of the entity.
     * @return a Mono to signal the deletion
     */
    Mono<Void> delete(Long id);
}
