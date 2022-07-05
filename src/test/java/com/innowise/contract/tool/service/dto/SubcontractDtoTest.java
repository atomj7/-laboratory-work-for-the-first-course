package com.innowise.contract.tool.service.dto;

import static org.assertj.core.api.Assertions.assertThat;

import com.innowise.contract.tool.web.rest.TestUtil;
import org.junit.jupiter.api.Test;

class SubcontractDtoTest {

    @Test
    void dtoEqualsVerifier() throws Exception {
        TestUtil.equalsVerifier(SubcontractDto.class);
        SubcontractDto subcontractDto1 = new SubcontractDto();
        subcontractDto1.setId(1L);
        SubcontractDto subcontractDto2 = new SubcontractDto();
        assertThat(subcontractDto1).isNotEqualTo(subcontractDto2);
        subcontractDto2.setId(subcontractDto1.getId());
        assertThat(subcontractDto1).isEqualTo(subcontractDto2);
        subcontractDto2.setId(2L);
        assertThat(subcontractDto1).isNotEqualTo(subcontractDto2);
        subcontractDto1.setId(null);
        assertThat(subcontractDto1).isNotEqualTo(subcontractDto2);
    }
}
