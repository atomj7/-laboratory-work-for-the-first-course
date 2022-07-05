package com.innowise.contract.tool.service.impl;

import com.innowise.contract.tool.domain.Subcontract;
import com.innowise.contract.tool.repository.SubcontractRepository;
import com.innowise.contract.tool.service.SubcontractService;
import com.innowise.contract.tool.service.dto.SubcontractDto;
import com.innowise.contract.tool.service.mapper.SubcontractMapper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Implementation for managing {@link Subcontract}.
 */
@Service
@Transactional
public class SubcontractServiceImpl implements SubcontractService {

    private final Logger log = LoggerFactory.getLogger(SubcontractServiceImpl.class);

    private final SubcontractRepository subcontractRepository;

    private final SubcontractMapper subcontractMapper;

    public SubcontractServiceImpl(SubcontractRepository subcontractRepository, SubcontractMapper subcontractMapper) {
        this.subcontractRepository = subcontractRepository;
        this.subcontractMapper = subcontractMapper;
    }

    @Override
    public Mono<SubcontractDto> save(SubcontractDto subcontractDto) {
        log.debug("Request to save Subcontract : {}", subcontractDto);
        return subcontractRepository.save(subcontractMapper.toEntity(subcontractDto)).map(subcontractMapper::toDto);
    }

    @Override
    public Mono<SubcontractDto> update(SubcontractDto subcontractDto) {
        log.debug("Request to save Subcontract : {}", subcontractDto);
        return subcontractRepository.save(subcontractMapper.toEntity(subcontractDto)).map(subcontractMapper::toDto);
    }

    @Override
    public Mono<SubcontractDto> partialUpdate(SubcontractDto subcontractDto) {
        log.debug("Request to partially update Subcontract : {}", subcontractDto);

        return subcontractRepository
            .findById(subcontractDto.getId())
            .map(existingSubcontract -> {
                subcontractMapper.partialUpdate(existingSubcontract, subcontractDto);

                return existingSubcontract;
            })
            .flatMap(subcontractRepository::save)
            .map(subcontractMapper::toDto);
    }

    @Override
    @Transactional(readOnly = true)
    public Flux<SubcontractDto> findAll(Pageable pageable) {
        log.debug("Request to get all Subcontracts");
        return subcontractRepository.findAllBy(pageable).map(subcontractMapper::toDto);
    }

    public Mono<Long> countAll() {
        return subcontractRepository.count();
    }

    @Override
    @Transactional(readOnly = true)
    public Mono<SubcontractDto> findOne(Long id) {
        log.debug("Request to get Subcontract : {}", id);
        return subcontractRepository.findById(id).map(subcontractMapper::toDto);
    }

    @Override
    public Mono<Void> delete(Long id) {
        log.debug("Request to delete Subcontract : {}", id);
        return subcontractRepository.deleteById(id);
    }
}
