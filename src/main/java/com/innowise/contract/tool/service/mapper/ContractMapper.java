package com.innowise.contract.tool.service.mapper;

import com.innowise.contract.tool.domain.Client;
import com.innowise.contract.tool.domain.Contract;
import com.innowise.contract.tool.service.dto.ClientDto;
import com.innowise.contract.tool.service.dto.ContractDto;
import org.mapstruct.*;

/**
 * Mapper for the entity {@link Contract} and its DTO {@link ContractDto}.
 */
@Mapper(componentModel = "spring")
public interface ContractMapper extends EntityMapper<ContractDto, Contract> {
    @Mapping(target = "client", source = "client", qualifiedByName = "clientId")
    ContractDto toDto(Contract s);

    @Named("clientId")
    @BeanMapping(ignoreByDefault = true)
    @Mapping(target = "id", source = "id")
    ClientDto toDtoClientId(Client client);
}
