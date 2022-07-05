package com.innowise.contract.tool.service.mapper;

import com.innowise.contract.tool.domain.Contract;
import com.innowise.contract.tool.domain.Project;
import com.innowise.contract.tool.domain.Subcontract;
import com.innowise.contract.tool.service.dto.ContractDto;
import com.innowise.contract.tool.service.dto.ProjectDto;
import com.innowise.contract.tool.service.dto.SubcontractDto;
import org.mapstruct.*;

/**
 * Mapper for the entity {@link Subcontract} and its DTO {@link SubcontractDto}.
 */
@Mapper(componentModel = "spring")
public interface SubcontractMapper extends EntityMapper<SubcontractDto, Subcontract> {
    @Mapping(target = "contract", source = "contract", qualifiedByName = "contractId")
    @Mapping(target = "project", source = "project", qualifiedByName = "projectId")
    SubcontractDto toDto(Subcontract s);

    @Named("contractId")
    @BeanMapping(ignoreByDefault = true)
    @Mapping(target = "id", source = "id")
    ContractDto toDtoContractId(Contract contract);

    @Named("projectId")
    @BeanMapping(ignoreByDefault = true)
    @Mapping(target = "id", source = "id")
    ProjectDto toDtoProjectId(Project project);
}
