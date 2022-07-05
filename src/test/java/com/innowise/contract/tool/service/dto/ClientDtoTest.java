package com.innowise.contract.tool.service.dto;

import static org.assertj.core.api.Assertions.assertThat;

import com.innowise.contract.tool.web.rest.TestUtil;
import org.junit.jupiter.api.Test;

class ClientDtoTest {

    @Test
    void dtoEqualsVerifier() throws Exception {
        TestUtil.equalsVerifier(ClientDto.class);
        ClientDto clientDto1 = new ClientDto();
        clientDto1.setId(1L);
        ClientDto clientDto2 = new ClientDto();
        assertThat(clientDto1).isNotEqualTo(clientDto2);
        clientDto2.setId(clientDto1.getId());
        assertThat(clientDto1).isEqualTo(clientDto2);
        clientDto2.setId(2L);
        assertThat(clientDto1).isNotEqualTo(clientDto2);
        clientDto1.setId(null);
        assertThat(clientDto1).isNotEqualTo(clientDto2);
    }
}
