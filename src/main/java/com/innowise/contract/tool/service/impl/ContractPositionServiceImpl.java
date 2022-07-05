package com.innowise.contract.tool.service.impl;

import com.innowise.contract.tool.domain.ContractPosition;
import com.innowise.contract.tool.repository.ContractPositionRepository;
import com.innowise.contract.tool.service.ContractPositionService;
import com.innowise.contract.tool.service.dto.ContractPositionDto;
import com.innowise.contract.tool.service.mapper.ContractPositionMapper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Implementation for managing {@link ContractPosition}.
 */
@Service
@Transactional
public class ContractPositionServiceImpl implements ContractPositionService {

    private final Logger log = LoggerFactory.getLogger(ContractPositionServiceImpl.class);

    private final ContractPositionRepository contractPositionRepository;

    private final ContractPositionMapper contractPositionMapper;

    public ContractPositionServiceImpl(
        ContractPositionRepository contractPositionRepository,
        ContractPositionMapper contractPositionMapper
    ) {
        this.contractPositionRepository = contractPositionRepository;
        this.contractPositionMapper = contractPositionMapper;
    }

    @Override
    public Mono<ContractPositionDto> save(ContractPositionDto contractPositionDto) {
        log.debug("Request to save ContractPosition : {}", contractPositionDto);
        return contractPositionRepository.save(contractPositionMapper.toEntity(contractPositionDto)).map(contractPositionMapper::toDto);
    }

    @Override
    public Mono<ContractPositionDto> update(ContractPositionDto contractPositionDto) {
        log.debug("Request to save ContractPosition : {}", contractPositionDto);
        return contractPositionRepository.save(contractPositionMapper.toEntity(contractPositionDto)).map(contractPositionMapper::toDto);
    }

    @Override
    public Mono<ContractPositionDto> partialUpdate(ContractPositionDto contractPositionDto) {
        log.debug("Request to partially update ContractPosition : {}", contractPositionDto);

        return contractPositionRepository
            .findById(contractPositionDto.getId())
            .map(existingContractPosition -> {
                contractPositionMapper.partialUpdate(existingContractPosition, contractPositionDto);

                return existingContractPosition;
            })
            .flatMap(contractPositionRepository::save)
            .map(contractPositionMapper::toDto);
    }

    @Override
    @Transactional(readOnly = true)
    public Flux<ContractPositionDto> findAll(Pageable pageable) {
        log.debug("Request to get all ContractPositions");
        return contractPositionRepository.findAllBy(pageable).map(contractPositionMapper::toDto);
    }

    public Mono<Long> countAll() {
        return contractPositionRepository.count();
    }

    @Override
    @Transactional(readOnly = true)
    public Mono<ContractPositionDto> findOne(Long id) {
        log.debug("Request to get ContractPosition : {}", id);
        return contractPositionRepository.findById(id).map(contractPositionMapper::toDto);
    }

    @Override
    public Mono<Void> delete(Long id) {
        log.debug("Request to delete ContractPosition : {}", id);
        return contractPositionRepository.deleteById(id);
    }
}
