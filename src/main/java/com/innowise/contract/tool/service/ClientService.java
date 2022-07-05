package com.innowise.contract.tool.service;

import com.innowise.contract.tool.service.dto.ClientDto;
import org.springframework.data.domain.Pageable;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Interface for managing {@link com.innowise.contract.tool.domain.Client}.
 */
public interface ClientService {
    /**
     * Save a client.
     *
     * @param clientDto the entity to save.
     * @return the persisted entity.
     */
    Mono<ClientDto> save(ClientDto clientDto);

    /**
     * Updates a client.
     *
     * @param clientDto the entity to update.
     * @return the persisted entity.
     */
    Mono<ClientDto> update(ClientDto clientDto);

    /**
     * Partially updates a client.
     *
     * @param clientDto the entity to update partially.
     * @return the persisted entity.
     */
    Mono<ClientDto> partialUpdate(ClientDto clientDto);

    /**
     * Get all the clients.
     *
     * @param pageable the pagination information.
     * @return the list of entities.
     */
    Flux<ClientDto> findAll(Pageable pageable);

    /**
     * Returns the number of clients available.
     * @return the number of entities in the database.
     *
     */
    Mono<Long> countAll();

    /**
     * Get the "id" client.
     *
     * @param id the id of the entity.
     * @return the entity.
     */
    Mono<ClientDto> findOne(Long id);

    /**
     * Delete the "id" client.
     *
     * @param id the id of the entity.
     * @return a Mono to signal the deletion
     */
    Mono<Void> delete(Long id);
}
