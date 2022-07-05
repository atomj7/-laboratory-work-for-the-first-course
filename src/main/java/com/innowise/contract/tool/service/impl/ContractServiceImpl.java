package com.innowise.contract.tool.service.impl;

import com.innowise.contract.tool.domain.Contract;
import com.innowise.contract.tool.repository.ContractRepository;
import com.innowise.contract.tool.service.ContractService;
import com.innowise.contract.tool.service.dto.ContractDto;
import com.innowise.contract.tool.service.mapper.ContractMapper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

/**
 * Service Implementation for managing {@link Contract}.
 */
@Service
@Transactional
public class ContractServiceImpl implements ContractService {

    private final Logger log = LoggerFactory.getLogger(ContractServiceImpl.class);

    private final ContractRepository contractRepository;

    private final ContractMapper contractMapper;

    public ContractServiceImpl(ContractRepository contractRepository, ContractMapper contractMapper) {
        this.contractRepository = contractRepository;
        this.contractMapper = contractMapper;
    }

    @Override
    public Mono<ContractDto> save(ContractDto contractDto) {
        log.debug("Request to save Contract : {}", contractDto);
        return contractRepository.save(contractMapper.toEntity(contractDto)).map(contractMapper::toDto);
    }

    @Override
    public Mono<ContractDto> update(ContractDto contractDto) {
        log.debug("Request to save Contract : {}", contractDto);
        return contractRepository.save(contractMapper.toEntity(contractDto)).map(contractMapper::toDto);
    }

    @Override
    public Mono<ContractDto> partialUpdate(ContractDto contractDto) {
        log.debug("Request to partially update Contract : {}", contractDto);

        return contractRepository
            .findById(contractDto.getId())
            .map(existingContract -> {
                contractMapper.partialUpdate(existingContract, contractDto);

                return existingContract;
            })
            .flatMap(contractRepository::save)
            .map(contractMapper::toDto);
    }

    @Override
    @Transactional(readOnly = true)
    public Flux<ContractDto> findAll(Pageable pageable) {
        log.debug("Request to get all Contracts");
        return contractRepository.findAllBy(pageable).map(contractMapper::toDto);
    }

    public Mono<Long> countAll() {
        return contractRepository.count();
    }

    @Override
    @Transactional(readOnly = true)
    public Mono<ContractDto> findOne(Long id) {
        log.debug("Request to get Contract : {}", id);
        return contractRepository.findById(id).map(contractMapper::toDto);
    }

    @Override
    public Mono<Void> delete(Long id) {
        log.debug("Request to delete Contract : {}", id);
        return contractRepository.deleteById(id);
    }
}
