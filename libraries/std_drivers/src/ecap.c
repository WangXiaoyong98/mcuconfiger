/*
 ******************************************************************************
 * @file           : ecap.c
 * @brief          : ecap driver file.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 Starpower, Inc.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "ecap.h"

//*****************************************************************************
//
// ECAP_setEmulationMode
//
//*****************************************************************************
void ECAP_setEmulationMode(uint32_t base, ECAP_EmulationMode mode)
{
    ASSERT(ECAP_isBaseValid(base));


    //
    // Write to FREE/SOFT bit
    //
    HWREG(base + ECAP_O_ECCTL1) =
            ((HWREG(base + ECAP_O_ECCTL1) & (~ECAP_ECCTL1_FREE_SOFT_M)) |
             ((uint16_t)mode << ECAP_ECCTL1_FREE_SOFT_S));
}
