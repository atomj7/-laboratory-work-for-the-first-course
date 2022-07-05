package com.innowise.contract.tool.service.impl;

import com.innowise.contract.tool.domain.Project;
import com.innowise.contract.tool.repository.ProjectRepository;
import com.innowise.contract.tool.service.ProjectService;
import com.innowise.contract.tool.service.dto.ProjectDto;
import com.innowise.contract.tool.service.mapper.ProjectMapper;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Implementation for managing {@link Project}.
 */
@Service
@Transactional
public class ProjectServiceImpl implements ProjectService {

    private final Logger log = LoggerFactory.getLogger(ProjectServiceImpl.class);

    private final ProjectRepository projectRepository;

    private final ProjectMapper projectMapper;

    public ProjectServiceImpl(ProjectRepository projectRepository, ProjectMapper projectMapper) {
        this.projectRepository = projectRepository;
        this.projectMapper = projectMapper;
    }

    @Override
    public Mono<ProjectDto> save(ProjectDto projectDto) {
        log.debug("Request to save Project : {}", projectDto);
        return projectRepository.save(projectMapper.toEntity(projectDto)).map(projectMapper::toDto);
    }

    @Override
    public Mono<ProjectDto> update(ProjectDto projectDto) {
        log.debug("Request to save Project : {}", projectDto);
        return projectRepository.save(projectMapper.toEntity(projectDto)).map(projectMapper::toDto);
    }

    @Override
    public Mono<ProjectDto> partialUpdate(ProjectDto projectDto) {
        log.debug("Request to partially update Project : {}", projectDto);

        return projectRepository
            .findById(projectDto.getId())
            .map(existingProject -> {
                projectMapper.partialUpdate(existingProject, projectDto);

                return existingProject;
            })
            .flatMap(projectRepository::save)
            .map(projectMapper::toDto);
    }

    @Override
    @Transactional(readOnly = true)
    public Flux<ProjectDto> findAll() {
        log.debug("Request to get all Projects");
        return projectRepository.findAll().map(projectMapper::toDto);
    }

    public Mono<Long> countAll() {
        return projectRepository.count();
    }

    @Override
    @Transactional(readOnly = true)
    public Mono<ProjectDto> findOne(Long id) {
        log.debug("Request to get Project : {}", id);
        return projectRepository.findById(id).map(projectMapper::toDto);
    }

    @Override
    public Mono<Void> delete(Long id) {
        log.debug("Request to delete Project : {}", id);
        return projectRepository.deleteById(id);
    }
}
