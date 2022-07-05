package com.innowise.contract.tool.service.mapper;

import com.innowise.contract.tool.domain.Client;
import com.innowise.contract.tool.service.dto.ClientDto;
import org.mapstruct.*;

/**
 * Mapper for the entity {@link Client} and its DTO {@link ClientDto}.
 */
@Mapper(componentModel = "spring")
public interface ClientMapper extends EntityMapper<ClientDto, Client> {}
