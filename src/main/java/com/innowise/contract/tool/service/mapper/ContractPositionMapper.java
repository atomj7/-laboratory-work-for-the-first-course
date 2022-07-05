package com.innowise.contract.tool.service.mapper;

import com.innowise.contract.tool.domain.ContractPosition;
import com.innowise.contract.tool.domain.Subcontract;
import com.innowise.contract.tool.service.dto.ContractPositionDto;
import com.innowise.contract.tool.service.dto.SubcontractDto;
import org.mapstruct.*;

/**
 * Mapper for the entity {@link ContractPosition} and its DTO {@link ContractPositionDto}.
 */
@Mapper(componentModel = "spring")
public interface ContractPositionMapper extends EntityMapper<ContractPositionDto, ContractPosition> {
    @Mapping(target = "subcontract", source = "subcontract", qualifiedByName = "subcontractId")
    ContractPositionDto toDto(ContractPosition s);

    @Named("subcontractId")
    @BeanMapping(ignoreByDefault = true)
    @Mapping(target = "id", source = "id")
    SubcontractDto toDtoSubcontractId(Subcontract subcontract);
}
