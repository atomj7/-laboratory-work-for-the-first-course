package com.innowise.contract.tool.service.dto;

import static org.assertj.core.api.Assertions.assertThat;

import com.innowise.contract.tool.web.rest.TestUtil;
import org.junit.jupiter.api.Test;

class ContractPositionDtoTest {

    @Test
    void dtoEqualsVerifier() throws Exception {
        TestUtil.equalsVerifier(ContractPositionDto.class);
        ContractPositionDto contractPositionDto1 = new ContractPositionDto();
        contractPositionDto1.setId(1L);
        ContractPositionDto contractPositionDto2 = new ContractPositionDto();
        assertThat(contractPositionDto1).isNotEqualTo(contractPositionDto2);
        contractPositionDto2.setId(contractPositionDto1.getId());
        assertThat(contractPositionDto1).isEqualTo(contractPositionDto2);
        contractPositionDto2.setId(2L);
        assertThat(contractPositionDto1).isNotEqualTo(contractPositionDto2);
        contractPositionDto1.setId(null);
        assertThat(contractPositionDto1).isNotEqualTo(contractPositionDto2);
    }
}
