/*
  ******************************************************************************
  * @file           : ewm.h
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
#ifndef _EWM_H_
#define _EWM_H_

#include "driver_common.h"

/*!
 * @addtogroup ewm
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/


/*!
 * @brief Data structure for EWM configuration.
 *
 * This structure is used to configure the EWM.
 */
typedef struct _ewm_config
{
    bool enableEwm;           /*!< Enable EWM module */
    bool enableEwmInput;      /*!< Enable EWM_in input */
    bool setInputAssertLogic; /*!< EWM_in signal assertion state */
    bool enableInterrupt;     /*!< Enable EWM interrupt */
    uint8_t compareLowValue;  /*!< Compare low-register value */
    uint8_t compareHighValue; /*!< Compare high-register value */
} ewm_config_t;

/*!
 * @brief EWM interrupt configuration structure with default settings all disabled.
 *
 * This structure contains the settings for all of EWM interrupt configurations.
 */
enum _ewm_interrupt_enable_t
{
    EWM_InterruptEnable = EWM_CTRL_INTEN_MASK, /*!< Enable the EWM to generate an interrupt*/
};

/*!
 * @brief EWM status flags.
 *
 * This structure contains the constants for the EWM status flags for use in the EWM functions.
 */
enum _ewm_status_flags_t
{
    EWM_RunningFlag = EWM_CTRL_EWMEN_MASK, /*!< Running flag, set when EWM is enabled*/
};

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name EWM initialization and de-initialization
 * @{
 */

/*!
 * @brief Initializes the EWM peripheral.
 *
 * This function is used to initialize the EWM. After calling, the EWM
 * runs immediately according to the configuration.
 * Note that, except for the interrupt enable control bit, other control bits and registers are write once after a
 * CPU reset. Modifying them more than once generates a bus transfer error.
 *
 * This is an example.
 * @code
 *   ewm_config_t config;
 *   EWM_GetDefaultConfig(&config);
 *   config.compareHighValue = 0xAAU;
 *   EWM_Init(ewm_base,&config);
 * @endcode
 *
 * @param base EWM peripheral base address
 * @param config The configuration of the EWM
 */
void EWM_Init(EWM_Type *base, const ewm_config_t *config);

/*!
 * @brief Deinitializes the EWM peripheral.
 *
 * This function is used to shut down the EWM.
 *
 * @param base EWM peripheral base address
 */
void EWM_Deinit(EWM_Type *base);

/*!
 * @brief Initializes the EWM configuration structure.
 *
 * This function initializes the EWM configuration structure to default values. The default
 * values are as follows.
 * @code
 *   ewmConfig->enableEwm = true;
 *   ewmConfig->enableEwmInput = false;
 *   ewmConfig->setInputAssertLogic = false;
 *   ewmConfig->enableInterrupt = false;
 *   ewmConfig->ewm_lpo_clock_source_t = kEWM_LpoClockSource0;
 *   ewmConfig->prescaler = 0;
 *   ewmConfig->compareLowValue = 0;
 *   ewmConfig->compareHighValue = 0xFEU;
 * @endcode
 *
 * @param config Pointer to the EWM configuration structure.
 * @see ewm_config_t
 */
void EWM_GetDefaultConfig(ewm_config_t *config);

/* @} */

/*!
 * @name EWM functional Operation
 * @{
 */

/*!
 * @brief Enables the EWM interrupt.
 *
 * This function enables the EWM interrupt.
 *
 * @param base EWM peripheral base address
 * @param mask The interrupts to enable
 *        The parameter can be combination of the following source if defined
 *        @arg kEWM_InterruptEnable
 */
static inline void EWM_EnableInterrupts(EWM_Type *base, uint32_t mask)
{
    base->CTRL |= (uint8_t)mask;
}

/*!
 * @brief Disables the EWM interrupt.
 *
 * This function enables the EWM interrupt.
 *
 * @param base EWM peripheral base address
 * @param mask The interrupts to disable
 *        The parameter can be combination of the following source if defined
 *        @arg kEWM_InterruptEnable
 */
static inline void EWM_DisableInterrupts(EWM_Type *base, uint32_t mask)
{
    base->CTRL &= (uint8_t)(~mask);
}

/*!
 * @brief Gets all status flags.
 *
 * This function gets all status flags.
 *
 * This is an example for getting the running flag.
 * @code
 *   uint32_t status;
 *   status = EWM_GetStatusFlags(ewm_base) & kEWM_RunningFlag;
 * @endcode
 * @param base        EWM peripheral base address
 * @return            State of the status flag: asserted (true) or not-asserted (false).@see _ewm_status_flags_t
 *                    - True: a related status flag has been set.
 *                    - False: a related status flag is not set.
 */
static inline uint32_t EWM_GetStatusFlags(EWM_Type *base)
{
    return ((uint32_t)base->CTRL & EWM_CTRL_EWMEN_MASK);
}

/*!
 * @brief Services the EWM.
 *
 * This function resets the EWM counter to zero.
 *
 * @param base EWM peripheral base address
 */
void EWM_Refresh(EWM_Type *base);

/*@}*/

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* _EWM_H_ */
