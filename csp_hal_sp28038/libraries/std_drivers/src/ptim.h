/*
  ******************************************************************************
  * @file           : ptim.h
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
#ifndef _PTIM_H_
#define _PTIM_H_

#include "driver_common.h"

/*!
 * @addtogroup ptim
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* PIT module features */



/*!
 * @brief List of PTIM channels
 * @note Actual number of available channels is SoC dependent
 */
typedef enum _ptim_chnl
{
    PTIM_Chnl_0 = 0U, /*!< PTIM channel number 0*/
    PTIM_Chnl_1,      /*!< PTIM channel number 1 */
    PTIM_Chnl_2,      /*!< PTIM channel number 2 */
    PTIM_Chnl_3,      /*!< PTIM channel number 3 */
} ptim_chnl_t;

/*! @brief List of PTIM interrupts */
typedef enum _ptim_interrupt_enable
{
    PTIM_TimerInterruptEnable = PTIM_TCTRL_TIE_MASK, /*!< Timer interrupt enable*/
} ptim_interrupt_enable_t;

/*! @brief List of PTIM status flags */
typedef enum _ptim_status_flags
{
    PTIM_TimerFlag = PTIM_TFLG_TIF_MASK, /*!< Timer flag */
} ptim_status_flags_t;

/*!
 * @brief PTIM configuration structure
 *
 * This structure holds the configuration settings for the PTIM peripheral. To initialize this
 * structure to reasonable defaults, call the PTIM_GetDefaultConfig() function and pass a
 * pointer to your config structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
typedef struct _ptim_config
{
    bool enableRunInDebug; /*!< true: Timers run in debug mode; false: Timers stop in debug mode */
} ptim_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Ungates the PTIM clock, enables the PTIM module, and configures the peripheral for basic operations.
 *
 * @note This API should be called at the beginning of the application using the PTIM driver.
 *
 * @param base   PTIM peripheral base address
 * @param config Pointer to the user's PTIM config structure
 */
void PTIM_Init(PTIM_Type *base, const ptim_config_t *config);

/*!
 * @brief Gates the PTIM clock and disables the PTIM module.
 *
 * @param base PTIM peripheral base address
 */
void PTIM_Deinit(PTIM_Type *base);

/*!
 * @brief Fills in the PTIM configuration structure with the default settings.
 *
 * The default values are as follows.
 * @code
 *     config->enableRunInDebug = false;
 * @endcode
 * @param config Pointer to the configuration structure.
 */
static inline void PTIM_GetDefaultConfig(ptim_config_t *config)
{
    assert(NULL != config);

    /* Timers are stopped in Debug mode */
    config->enableRunInDebug = false;
}


/*!
 * @brief Enables or disables chaining a timer with the previous timer.
 *
 * When a timer has a chain mode enabled, it only counts after the previous
 * timer has expired. If the timer n-1 has counted down to 0, counter n
 * decrements the value by one. Each timer is 32-bits, which allows the developers
 * to chain timers together and form a longer timer (64-bits and larger). The first timer
 * (timer 0) can't be chained to any other timer.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number which is chained with the previous timer
 * @param enable  Enable or disable chain.
 *                true:  Current timer is chained with the previous timer.
 *                false: Timer doesn't chain with other timers.
 */
static inline void PTIM_SetTimerChainMode(PTIM_Type *base, ptim_chnl_t channel, bool enable)
{
    if (enable)
    {
        base->CHANNEL[channel].TCTRL |= PTIM_TCTRL_CHN_MASK;
    }
    else
    {
        base->CHANNEL[channel].TCTRL &= ~PTIM_TCTRL_CHN_MASK;
    }
}

/*!
 * @name Interrupt Interface
 * @{
 */

/*!
 * @brief Enables the selected PTIM interrupts.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number
 * @param mask    The interrupts to enable. This is a logical OR of members of the
 *                enumeration ::ptim_interrupt_enable_t
 */
static inline void PTIM_EnableInterrupts(PTIM_Type *base, ptim_chnl_t channel, uint32_t mask)
{
    base->CHANNEL[channel].TCTRL |= mask;
}

/*!
 * @brief Disables the selected PTIM interrupts.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number
 * @param mask    The interrupts to disable. This is a logical OR of members of the
 *                enumeration ::ptim_interrupt_enable_t
 */
static inline void PTIM_DisableInterrupts(PTIM_Type *base, ptim_chnl_t channel, uint32_t mask)
{
    base->CHANNEL[channel].TCTRL &= ~mask;
}

/*!
 * @brief Gets the enabled PTIM interrupts.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number
 *
 * @return The enabled interrupts. This is the logical OR of members of the
 *         enumeration ::ptim_interrupt_enable_t
 */
static inline uint32_t PTIM_GetEnabledInterrupts(PTIM_Type *base, ptim_chnl_t channel)
{
    return (base->CHANNEL[channel].TCTRL & PTIM_TCTRL_TIE_MASK);
}

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Gets the PTIM status flags.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::ptim_status_flags_t
 */
static inline uint32_t PTIM_GetStatusFlags(PTIM_Type *base, ptim_chnl_t channel)
{
    return (base->CHANNEL[channel].TFLG & PTIM_TFLG_TIF_MASK);
}

/*!
 * @brief  Clears the PTIM status flags.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number
 * @param mask    The status flags to clear. This is a logical OR of members of the
 *                enumeration ::ptim_status_flags_t
 */
static inline void PTIM_ClearStatusFlags(PTIM_Type *base, ptim_chnl_t channel, uint32_t mask)
{
    base->CHANNEL[channel].TFLG = mask;
}


/*!
 * @name Read and Write the timer period
 * @{
 */

/*!
 * @brief Sets the timer period in units of count.
 *
 * Timers begin counting from the value set by this function until it reaches 0,
 * then it generates an interrupt and load this register value again.
 * Writing a new value to this register does not restart the timer. Instead, the value
 * is loaded after the timer expires.
 *
 * @note Users can call the utility macros provided in fsl_common.h to convert to ticks.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number
 * @param count   Timer period in units of ticks
 */
static inline void PTIM_SetTimerPeriod(PTIM_Type *base, ptim_chnl_t channel, uint32_t count)
{
    assert(count != 0U);
    /* According to RM, the LDVAL trigger = clock ticks -1 */
    base->CHANNEL[channel].LDVAL = count - 1U;
}

/*!
 * @brief Reads the current timer counting value.
 *
 * This function returns the real-time timer counting value, in a range from 0 to a
 * timer period.
 *
 * @note Users can call the utility macros provided in fsl_common.h to convert ticks to usec or msec.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number
 *
 * @return Current timer counting value in ticks
 */
static inline uint32_t PTIM_GetCurrentTimerCount(PTIM_Type *base, ptim_chnl_t channel)
{
    return base->CHANNEL[channel].CVAL;
}

/*!
 * @name Timer Start and Stop
 * @{
 */

/*!
 * @brief Starts the timer counting.
 *
 * After calling this function, timers load period value, count down to 0 and
 * then load the respective start value again. Each time a timer reaches 0,
 * it generates a trigger pulse and sets the timeout interrupt flag.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number.
 */
static inline void PTIM_StartTimer(PTIM_Type *base, ptim_chnl_t channel)
{
    base->CHANNEL[channel].TCTRL |= PTIM_TCTRL_TEN_MASK;
}

/*!
 * @brief Stops the timer counting.
 *
 * This function stops every timer counting. Timers reload their periods
 * respectively after the next time they call the PTIM_DRV_StartTimer.
 *
 * @param base    PTIM peripheral base address
 * @param channel Timer channel number.
 */
static inline void PTIM_StopTimer(PTIM_Type *base, ptim_chnl_t channel)
{
    base->CHANNEL[channel].TCTRL &= ~PTIM_TCTRL_TEN_MASK;
}


/*!
 * @brief Reads the current lifetime counter value.
 *
 * The lifetime timer is a 64-bit timer which chains timer 0 and timer 1 together.
 * Timer 0 and 1 are chained by calling the PTIM_SetTimerChainMode before using this timer.
 * The period of lifetime timer is equal to the "period of timer 0 * period of timer 1".
 * For the 64-bit value, the higher 32-bit has the value of timer 1, and the lower 32-bit
 * has the value of timer 0.
 *
 * @param base PTIM peripheral base address
 *
 * @return Current lifetime timer value
 */
uint64_t PTIM_GetLifetimeTimerCount(PTIM_Type *base);


#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* _PTIM_H_ */
