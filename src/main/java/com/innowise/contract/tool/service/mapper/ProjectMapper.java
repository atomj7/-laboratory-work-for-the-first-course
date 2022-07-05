package com.innowise.contract.tool.service.mapper;

import com.innowise.contract.tool.domain.Client;
import com.innowise.contract.tool.domain.Project;
import com.innowise.contract.tool.service.dto.ClientDto;
import com.innowise.contract.tool.service.dto.ProjectDto;
import org.mapstruct.*;

/**
 * Mapper for the entity {@link Project} and its DTO {@link ProjectDto}.
 */
@Mapper(componentModel = "spring")
public interface ProjectMapper extends EntityMapper<ProjectDto, Project> {
    @Mapping(target = "client", source = "client", qualifiedByName = "clientId")
    ProjectDto toDto(Project s);

    @Named("clientId")
    @BeanMapping(ignoreByDefault = true)
    @Mapping(target = "id", source = "id")
    ClientDto toDtoClientId(Client client);
}
