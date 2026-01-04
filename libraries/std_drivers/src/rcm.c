/*
  ******************************************************************************
  * @file           : rcm.c
  * @brief          : rcm driver header file
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

#include "rcm.h"


/*!
 * brief Configures the reset pin filter.
 *
 * This function sets the reset pin filter including the filter source, filter
 * width, and so on.
 *
 * param base RCM peripheral base address.
 * param config Pointer to the configuration structure.
 */
void RCM_ConfigureResetPinFilter(RCM_Type *base, const rcm_reset_pin_filter_config_t *config)
{
    assert(NULL != config);
    base->RPFC = (((uint8_t)config->enableFilterInStop << RCM_RPFC_RSTFLTSS_SHIFT) | (uint8_t)config->filterInRunWait);
    if (config->filterInRunWait == RCM_FilterBusClock)
    {
        base->RPFW = config->busClockFilterCount;
    }
}


