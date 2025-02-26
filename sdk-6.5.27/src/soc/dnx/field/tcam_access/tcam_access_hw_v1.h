#ifndef __TCAM_ACCESS_HW_V1__
#define __TCAM_ACCESS_HW_V1__

#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif

#include <include/soc/dnx/dbal/dbal_structures.h>
#include "tcam_access_defines.h"

shr_error_e dnx_tcam_access_hw_v1_payload_read(
    int unit,
    int core,
    uint32 action_bank_id,
    uint32 bank_offset,
    uint32 *payload);

shr_error_e dnx_tcam_access_hw_v1_payload_write(
    int unit,
    int core,
    uint32 action_bank_id,
    uint32 bank_offset,
    uint32 *payload);

shr_error_e dnx_tcam_access_hw_v1_entry_key_read(
    int unit,
    int core,
    uint32 bank_id,
    uint32 bank_offset,
    uint32 *data_key,
    uint32 *data_mask,
    uint8 *key_valid_bits);

shr_error_e dnx_tcam_access_hw_v1_entry_key_write(
    int unit,
    int core,
    uint32 bank_id,
    uint32 bank_offset,
    dnx_field_tcam_access_key_mode_e key_mode,
    dnx_field_tcam_access_part_e part,
    uint8 valid,
    uint32 *key,
    uint32 *key_mask);

shr_error_e dnx_tcam_access_hw_v1_tcam_hit_per_core_get(
    int unit,
    int core_id_specific,
    uint32 position,
    uint32 hw_bank_id,
    uint32 line_chunk_id,
    uint32 *mem_hit_field_value);

shr_error_e dnx_tcam_access_hw_v1_tcam_hit_per_core_flush(
    int unit,
    int core_id_specific,
    uint32 position,
    uint32 hw_bank_id,
    uint32 line_chunk_id,
    uint32 tcam_indirect_mask);

#endif
