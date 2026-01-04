/*
  ******************************************************************************
  * @file           : ewm.c
  * @brief          : ewm program body
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

#include "ewm.h"



/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Initializes the EWM peripheral.
 *
 * This function is used to initialize the EWM. After calling, the EWM
 * runs immediately according to the configuration.
 * Note that, except for the interrupt enable control bit, other control bits and registers are write once after a
 * CPU reset. Modifying them more than once generates a bus transfer error.
 *
 * This is an example.
 * code
 *   ewm_config_t config;
 *   EWM_GetDefaultConfig(&config);
 *   config.compareHighValue = 0xAAU;
 *   EWM_Init(ewm_base,&config);
 * endcode
 *
 * param base EWM peripheral base address
 * param config The configuration of the EWM
 */
void EWM_Init(EWM_Type *base, const ewm_config_t *config)
{
    assert(NULL != config);

    uint8_t value = 0U;
    SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_EWM_SET(1);
    
    value = EWM_CTRL_EWMEN_SET(config->enableEwm) | EWM_CTRL_ASSIN_SET(config->setInputAssertLogic) |
            EWM_CTRL_INEN_SET(config->enableEwmInput) | EWM_CTRL_INTEN_SET(config->enableInterrupt);

    base->CMPL = config->compareLowValue;
    base->CMPH = config->compareHighValue;
    base->CTRL = value;
}

/*!
 * brief Deinitializes the EWM peripheral.
 *
 * This function is used to shut down the EWM.
 *
 * param base EWM peripheral base address
 */
void EWM_Deinit(EWM_Type *base)
{
    EWM_DisableInterrupts(base, (uint32_t)EWM_InterruptEnable);
    SYSCTRL->ISP1CGC3 &= ~SYSCTRL_ISP1CGC3_EWM_SET(0);
}

/*!
 * brief Initializes the EWM configuration structure.
 *
 * This function initializes the EWM configuration structure to default values. The default
 * values are as follows.
 * code
 *   ewmConfig->enableEwm = true;
 *   ewmConfig->enableEwmInput = false;
 *   ewmConfig->setInputAssertLogic = false;
 *   ewmConfig->enableInterrupt = false;
 *   ewmConfig->ewm_lpo_clock_source_t = kEWM_LpoClockSource0;
 *   ewmConfig->prescaler = 0;
 *   ewmConfig->compareLowValue = 0;
 *   ewmConfig->compareHighValue = 0xFEU;
 * endcode
 *
 * param config Pointer to the EWM configuration structure.
 * see ewm_config_t
 */
void EWM_GetDefaultConfig(ewm_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableEwm           = true;
    config->enableEwmInput      = false;
    config->setInputAssertLogic = false;
    config->enableInterrupt     = false;
    config->compareLowValue  = 0U;
    config->compareHighValue = 0xFEU;
}

/*!
 * brief Services the EWM.
 *
 * This function resets the EWM counter to zero.
 *
 * param base EWM peripheral base address
 */
void EWM_Refresh(EWM_Type *base)
{
    uint32_t primaskValue = 0U;

    /* Disable the global interrupt to protect refresh sequence */
    primaskValue = DisableGlobalIRQ();
    base->SERV   = (uint8_t)0xB4U;
    base->SERV   = (uint8_t)0x2CU;
    EnableGlobalIRQ(primaskValue);
}
