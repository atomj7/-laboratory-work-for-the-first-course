package com.innowise.contract.tool.service;

import com.innowise.contract.tool.service.dto.ProjectDto;
import java.util.List;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Interface for managing {@link com.innowise.contract.tool.domain.Project}.
 */
public interface ProjectService {
    /**
     * Save a project.
     *
     * @param projectDto the entity to save.
     * @return the persisted entity.
     */
    Mono<ProjectDto> save(ProjectDto projectDto);

    /**
     * Updates a project.
     *
     * @param projectDto the entity to update.
     * @return the persisted entity.
     */
    Mono<ProjectDto> update(ProjectDto projectDto);

    /**
     * Partially updates a project.
     *
     * @param projectDto the entity to update partially.
     * @return the persisted entity.
     */
    Mono<ProjectDto> partialUpdate(ProjectDto projectDto);

    /**
     * Get all the projects.
     *
     * @return the list of entities.
     */
    Flux<ProjectDto> findAll();

    /**
     * Returns the number of projects available.
     * @return the number of entities in the database.
     *
     */
    Mono<Long> countAll();

    /**
     * Get the "id" project.
     *
     * @param id the id of the entity.
     * @return the entity.
     */
    Mono<ProjectDto> findOne(Long id);

    /**
     * Delete the "id" project.
     *
     * @param id the id of the entity.
     * @return a Mono to signal the deletion
     */
    Mono<Void> delete(Long id);
}
