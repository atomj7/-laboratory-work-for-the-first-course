package com.innowise.contract.tool.service.dto;

import static org.assertj.core.api.Assertions.assertThat;

import com.innowise.contract.tool.web.rest.TestUtil;
import org.junit.jupiter.api.Test;

class ContractDtoTest {

    @Test
    void dtoEqualsVerifier() throws Exception {
        TestUtil.equalsVerifier(ContractDto.class);
        ContractDto contractDto1 = new ContractDto();
        contractDto1.setId(1L);
        ContractDto contractDto2 = new ContractDto();
        assertThat(contractDto1).isNotEqualTo(contractDto2);
        contractDto2.setId(contractDto1.getId());
        assertThat(contractDto1).isEqualTo(contractDto2);
        contractDto2.setId(2L);
        assertThat(contractDto1).isNotEqualTo(contractDto2);
        contractDto1.setId(null);
        assertThat(contractDto1).isNotEqualTo(contractDto2);
    }
}
