/*
  ******************************************************************************
  * @file           : ptim.c
  * @brief          : ptim program body
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

#include "ptim.h"



/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address to be used to gate or ungate the module clock
 *
 * @param base PTIM peripheral base address
 *
 * @return The PTIM instance
 */
static uint32_t PTIM_GetInstance(PTIM_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to PTIM bases for each instance. */
static PTIM_Type *const s_ptimBases[] = PTIM_BASE_PTRS;



/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t PTIM_GetInstance(PTIM_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_ptimBases); instance++)
    {
        if (s_ptimBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_ptimBases));

    return instance;
}

/*!
 * brief Ungates the PTIM clock, enables the PTIM module, and configures the peripheral for basic operations.
 *
 * note This API should be called at the beginning of the application using the PTIM driver.
 *
 * param base   PTIM peripheral base address
 * param config Pointer to the user's PTIM config structure
 */
void PTIM_Init(PTIM_Type *base, const ptim_config_t *config)
{
    assert(NULL != config);

    /* Enable PTIM timers */
    base->MCR &= ~PTIM_MCR_MDIS_MASK;


    /* Clear all status bits for all channels to make sure the status of all TCTRL registers is clean. */
    for (uint8_t i = 0U; i < (uint32_t)4; i++)
    {
        base->CHANNEL[i].TCTRL &= ~(PTIM_TCTRL_TEN_MASK | PTIM_TCTRL_TIE_MASK | PTIM_TCTRL_CHN_MASK);
    }

    /* Config timer operation when in debug mode */
    if (true == config->enableRunInDebug)
    {
        base->MCR &= ~PTIM_MCR_FRZ_MASK;
    }
    else
    {
        base->MCR |= PTIM_MCR_FRZ_MASK;
    }
}

/*!
 * brief Gates the PTIM clock and disables the PTIM module.
 *
 * param base PTIM peripheral base address
 */
void PTIM_Deinit(PTIM_Type *base)
{
    /* Disable PTIM timers */
    base->MCR |= PTIM_MCR_MDIS_MASK;
     /* Disable PTIM clock */
    SYSCTRL->ISP1CGC1 &=~SYSCTRL_ISP1CGC1_PTIM_SET(0);
}


/*!
 * brief Reads the current lifetime counter value.
 *
 * The lifetime timer is a 64-bit timer which chains timer 0 and timer 1 together.
 * Timer 0 and 1 are chained by calling the PTIM_SetTimerChainMode before using this timer.
 * The period of lifetime timer is equal to the "period of timer 0 * period of timer 1".
 * For the 64-bit value, the higher 32-bit has the value of timer 1, and the lower 32-bit
 * has the value of timer 0.
 *
 * param base PTIM peripheral base address
 *
 * return Current lifetime timer value
 */
uint64_t PTIM_GetLifetimeTimerCount(PTIM_Type *base)
{
    uint32_t valueH = 0U;
    uint32_t valueL = 0U;

    /* LTMR64H should be read before LTMR64L */
    valueH = base->LTMR64H;
    valueL = base->LTMR64L;

    return (((uint64_t)valueH << 32U) + (uint64_t)(valueL));
}


