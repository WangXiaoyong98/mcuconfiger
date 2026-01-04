/*
  ******************************************************************************
  * @file           : wwdt.c
  * @brief          : wwdt program body
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

#include "wwdt.h"


/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Initializes the WWDT configuration structure.
 *
 * This function initializes the WWDT configuration structure to default values. The default
 * values are as follows.
 * code
 *   wwdtConfig->enableWdog = true;
 *   wwdtConfig->clockSource = WWDT_LpoClockSource;
 *   wwdtConfig->prescaler = WWDT_ClockPrescalerDivide1;
 *   wwdtConfig->workMode.enableWait = true;
 *   wwdtConfig->workMode.enableStop = false;
 *   wwdtConfig->workMode.enableDebug = false;
 *   wwdtConfig->enableUpdate = true;
 *   wwdtConfig->enableInterrupt = false;
 *   wwdtConfig->enableWindowMode = false;
 *   wwdtConfig->windowValue = 0;
 *   wwdtConfig->timeoutValue = 0xFFFFU;
 * endcode
 *
 * param config Pointer to the WWDT configuration structure.
 * see wwdt_config_t
 */
void WWDT_GetDefaultConfig(wwdt_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableWdog  = true;
    config->clockSource = WWDT_LpoClockSource;
    config->prescaler   = WWDT_ClockPrescalerDivide1;
    config->workMode.enableWait = true;
    config->workMode.enableStop  = false;
    config->workMode.enableDebug = false;
    config->enableUpdate         = true;
    config->enableInterrupt      = false;
    config->enableWindowMode     = false;
    config->windowValue          = 0U;
    config->timeoutValue         = 0xFFFFU;
}

/*!
 * brief Initializes the WWDT.
 *
 * This function initializes the WWDT. When called, the WWDT runs according to the configuration.
 * To reconfigure WWDT without forcing a reset first, enableUpdate must be set to true
 * in the configuration.
 *
 * This is an example.
 * code
 *   wwdt_config_t config;
 *   WWDT_GetDefaultConfig(&config);
 *   config.timeoutValue = 0x7ffU;
 *   config.enableUpdate = true;
 *   WWDT_Init(wwdt_base,&config);
 * endcode
 *
 * param base   WWDT peripheral base address
 * param config The configuration of WWDT
 */
void WWDT_Init(WWDT_Type *base, const wwdt_config_t *config)
{
    assert(NULL != config);

    uint16_t value        = 0U;
    uint32_t primaskValue = 0U;

    value = WWDT_STCTRLH_WWDTEN_SET(config->enableWdog) | WWDT_STCTRLH_CLKSRC_SET(config->clockSource) |
            WWDT_STCTRLH_IRQRSTEN_SET(config->enableInterrupt) | WWDT_STCTRLH_WINEN_SET(config->enableWindowMode) |
            WWDT_STCTRLH_ALLOWUPDATE_SET(config->enableUpdate) | WWDT_STCTRLH_DBGEN_SET(config->workMode.enableDebug) |
            WWDT_STCTRLH_STOPEN_SET(config->workMode.enableStop) |
            WWDT_STCTRLH_WAITEN_SET(config->workMode.enableWait) |
            WWDT_STCTRLH_DISTESTWWDT_SET(1U);

    /* Disable the global interrupts. Otherwise, an interrupt could effectively invalidate the unlock sequence
     * and the WCT may expire. After the configuration finishes, re-enable the global interrupts. */
    primaskValue = DisableGlobalIRQ();
    WWDT_Unlock(base);
    /* Wait one bus clock cycle */
    base->RSTCNT = 0U;
    /* Set configuration */
    base->PRESC   = WWDT_PRESC_PRESCVAL_SET(config->prescaler);
    base->WINH    = (uint16_t)((config->windowValue >> 16U) & 0xFFFFU);
    base->WINL    = (uint16_t)((config->windowValue) & 0xFFFFU);
    base->TOVALH  = (uint16_t)((config->timeoutValue >> 16U) & 0xFFFFU);
    base->TOVALL  = (uint16_t)((config->timeoutValue) & 0xFFFFU);
    base->STCTRLH = value;
    EnableGlobalIRQ(primaskValue);
}

/*!
 * brief Shuts down the WWDT.
 *
 * This function shuts down the WWDT.
 * Ensure that the WWDT_STCTRLH.ALLOWUPDATE is 1 which indicates that the register update is enabled.
 */
void WWDT_Deinit(WWDT_Type *base)
{
    uint32_t primaskValue = 0U;

    /* Disable the global interrupts */
    primaskValue = DisableGlobalIRQ();
    WWDT_Unlock(base);
    /* Wait one bus clock cycle */
    base->RSTCNT = 0U;
    WWDT_Disable(base);
    EnableGlobalIRQ(primaskValue);
    WWDT_ClearResetCount(base);
}

/*!
 * brief Configures the WWDT functional test.
 *
 * This function is used to configure the WWDT functional test. When called, the WWDT goes into test mode
 * and runs according to the configuration.
 * Ensure that the WWDT_STCTRLH.ALLOWUPDATE is 1 which means that the register update is enabled.
 *
 * This is an example.
 * code
 *   wwdt_test_config_t test_config;
 *   test_config.testMode = WWDT_QuickTest;
 *   test_config.timeoutValue = 0xfffffu;
 *   WWDT_SetTestModeConfig(wwdt_base, &test_config);
 * endcode
 * param base   WWDT peripheral base address
 * param config The functional test configuration of WWDT
 */
void WWDT_SetTestModeConfig(WWDT_Type *base, wwdt_test_config_t *config)
{
    assert(NULL != config);

    uint16_t value        = 0U;
    uint32_t primaskValue = 0U;

    value = WWDT_STCTRLH_DISTESTWWDT_SET(0U) | WWDT_STCTRLH_TESTWWDT_SET(1U) | WWDT_STCTRLH_TESTSEL_SET(config->testMode) |
            WWDT_STCTRLH_BYTESEL_SET(config->testedByte) | WWDT_STCTRLH_IRQRSTEN_SET(0U) | WWDT_STCTRLH_WWDTEN_SET(1U) |
            WWDT_STCTRLH_ALLOWUPDATE_SET(1U);

    /* Disable the global interrupts. Otherwise, an interrupt could effectively invalidate the unlock sequence
     * and the WCT may expire. After the configuration finishes, re-enable the global interrupts. */
    primaskValue = DisableGlobalIRQ();
    WWDT_Unlock(base);
    /* Wait one bus clock cycle */
    base->RSTCNT = 0U;
    /* Set configuration */
    base->TOVALH  = (uint16_t)((config->timeoutValue >> 16U) & 0xFFFFU);
    base->TOVALL  = (uint16_t)((config->timeoutValue) & 0xFFFFU);
    base->STCTRLH = value;
    EnableGlobalIRQ(primaskValue);
}

/*!
 * brief Gets the WWDT all status flags.
 *
 * This function gets all status flags.
 *
 * This is an example for getting the Running Flag.
 * code
 *   uint32_t status;
 *   status = WWDT_GetStatusFlags (wwdt_base) & WWDT_RunningFlag;
 * endcode
 * param base        WWDT peripheral base address
 * return            State of the status flag: asserted (true) or not-asserted (false).see _wwdt_status_flags_t
 *                    - true: a related status flag has been set.
 *                    - false: a related status flag is not set.
 */
uint32_t WWDT_GetStatusFlags(WWDT_Type *base)
{
    uint32_t status_flag = 0U;

    status_flag |= ((uint32_t)base->STCTRLH & (uint32_t)WWDT_STCTRLH_WWDTEN_MASK);
    status_flag |= ((uint32_t)base->STCTRLL & (uint32_t)WWDT_STCTRLL_INTFLG_MASK);

    return status_flag;
}

/*!
 * brief Clears the WWDT flag.
 *
 * This function clears the WWDT status flag.
 *
 * This is an example for clearing the timeout (interrupt) flag.
 * code
 *   WWDT_ClearStatusFlags(wwdt_base,WWDT_TimeoutFlag);
 * endcode
 * param base        WWDT peripheral base address
 * param mask        The status flags to clear.
 *                    The parameter could be any combination of the following values.
 *                    WWDT_TimeoutFlag
 */
void WWDT_ClearStatusFlags(WWDT_Type *base, uint32_t mask)
{
    if (0U != (mask & (uint32_t)WWDT_TimeoutFlag))
    {
        base->STCTRLL |= WWDT_STCTRLL_INTFLG_MASK;
    }
}

/*!
 * brief Refreshes the WWDT timer.
 *
 * This function feeds the WWDT.
 * This function should be called before the WWDT timer is in timeout. Otherwise, a reset is asserted.
 *
 * param base WWDT peripheral base address
 */
void WWDT_Refresh(WWDT_Type *base)
{
    uint32_t primaskValue = 0U;

    /* Disable the global interrupt to protect refresh sequence */
    primaskValue  = DisableGlobalIRQ();
    base->REFRESH = WWDT_FIRST_WORD_OF_REFRESH;
    base->REFRESH = WWDT_SECOND_WORD_OF_REFRESH;
    EnableGlobalIRQ(primaskValue);
}
