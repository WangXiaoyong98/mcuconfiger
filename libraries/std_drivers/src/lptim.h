/*
  ******************************************************************************
  * @file           : lptim.h
  * @brief          : lptim program body
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
 #ifndef _LPTIM_H_
 #define _LPTIM_H_
 
#include "driver_common.h"
 
 /*!
  * @addtogroup lptim
  * @{
  */
 
 /*******************************************************************************
  * Definitions
  ******************************************************************************/
 extern uint32_t addrValue;

 /*! @brief LPTIM pin selection used in pulse counter mode.*/
 typedef enum _lptim_pin_select
 {
     LPTIM_PinSelectInput_0 = 0x0U, /*!< Pulse counter input 0 is selected */
     LPTIM_PinSelectInput_1 = 0x1U, /*!< Pulse counter input 1 is selected */
     LPTIM_PinSelectInput_2 = 0x2U, /*!< Pulse counter input 2 is selected */
     LPTIM_PinSelectInput_3 = 0x3U  /*!< Pulse counter input 3 is selected */
 } lptim_pin_select_t;
 
 /*! @brief LPTIM pin polarity used in pulse counter mode.*/
 typedef enum _lptim_pin_polarity
 {
     LPTIM_PinPolarityActiveHigh = 0x0U, /*!< Pulse Counter input source is active-high */
     LPTIM_PinPolarityActiveLow  = 0x1U  /*!< Pulse Counter input source is active-low */
 } lptim_pin_polarity_t;
 
 /*! @brief LPTIM timer mode selection.*/
 typedef enum _lptim_timer_mode
 {
     LPTIM_TimerModeTimeCounter  = 0x0U, /*!< Time Counter mode */
     LPTIM_TimerModePulseCounter = 0x1U  /*!< Pulse Counter mode */
 } lptim_timer_mode_t;
 
 /*! @brief LPTIM prescaler/glitch filter values*/
 typedef enum _lptim_prescaler_glitch_value
 {
     LPTIM_Prescale_Glitch_0  = 0x0U, /*!< Prescaler divide 2, glitch filter does not support this setting */
     LPTIM_Prescale_Glitch_1  = 0x1U, /*!< Prescaler divide 4, glitch filter 2 */
     LPTIM_Prescale_Glitch_2  = 0x2U, /*!< Prescaler divide 8, glitch filter 4 */
     LPTIM_Prescale_Glitch_3  = 0x3U, /*!< Prescaler divide 16, glitch filter 8 */
     LPTIM_Prescale_Glitch_4  = 0x4U, /*!< Prescaler divide 32, glitch filter 16 */
     LPTIM_Prescale_Glitch_5  = 0x5U, /*!< Prescaler divide 64, glitch filter 32 */
     LPTIM_Prescale_Glitch_6  = 0x6U, /*!< Prescaler divide 128, glitch filter 64 */
     LPTIM_Prescale_Glitch_7  = 0x7U, /*!< Prescaler divide 256, glitch filter 128 */
     LPTIM_Prescale_Glitch_8  = 0x8U, /*!< Prescaler divide 512, glitch filter 256 */
     LPTIM_Prescale_Glitch_9  = 0x9U, /*!< Prescaler divide 1024, glitch filter 512*/
     LPTIM_Prescale_Glitch_10 = 0xAU, /*!< Prescaler divide 2048 glitch filter 1024 */
     LPTIM_Prescale_Glitch_11 = 0xBU, /*!< Prescaler divide 4096, glitch filter 2048 */
     LPTIM_Prescale_Glitch_12 = 0xCU, /*!< Prescaler divide 8192, glitch filter 4096 */
     LPTIM_Prescale_Glitch_13 = 0xDU, /*!< Prescaler divide 16384, glitch filter 8192 */
     LPTIM_Prescale_Glitch_14 = 0xEU, /*!< Prescaler divide 32768, glitch filter 16384 */
     LPTIM_Prescale_Glitch_15 = 0xFU  /*!< Prescaler divide 65536, glitch filter 32768 */
 } lptim_prescaler_glitch_value_t;
 
 /*!
  * @brief LPTIM prescaler/glitch filter clock select.
  * @note Clock connections are SoC-specific
  */
 typedef enum _lptim_prescaler_clock_select
 {
     LPTIM_PrescalerClock_0 = 0x0U, /*!< Prescaler/glitch filter clock 0 selected. */
     LPTIM_PrescalerClock_1 = 0x1U, /*!< Prescaler/glitch filter clock 1 selected. */                    
     LPTIM_PrescalerClock_2 = 0x2U, /*!< Prescaler/glitch filter clock 2 selected. */
     LPTIM_PrescalerClock_3 = 0x3U, /*!< Prescaler/glitch filter clock 3 selected. */
 } lptim_prescaler_clock_select_t;
 
 /*! @brief List of the LPTIM interrupts */
 typedef enum _lptim_interrupt_enable
 {
     LPTIM_TimerInterruptEnable = LPTIM_CSR_TIE_MASK, /*!< Timer interrupt enable */
 } lptim_interrupt_enable_t;
 
 /*! @brief List of the LPTIM status flags */
 typedef enum _lptim_status_flags
 {
     LPTIM_TimerCompareFlag = LPTIM_CSR_TCF_MASK, /*!< Timer compare flag */
 } lptim_status_flags_t;
 
 /*!
  * @brief LPTIM config structure
  *
  * This structure holds the configuration settings for the LPTIM peripheral. To initialize this
  * structure to reasonable defaults, call the LPTIM_GetDefaultConfig() function and pass a
  * pointer to your configuration structure instance.
  *
  * The configuration struct can be made constant so it resides in flash.
  */
 typedef struct _lptim_config
 {
     lptim_timer_mode_t timerMode;     /*!< Time counter mode or pulse counter mode */
     lptim_pin_select_t pinSelect;     /*!< lptim pulse input pin select; used only in pulse counter mode */
     lptim_pin_polarity_t pinPolarity; /*!< lptim pulse input pin polarity; used only in pulse counter mode */
     bool enableFreeRunning;           /*!< True: enable free running, counter is reset on overflow
                                            False: counter is reset when the compare flag is set */
     bool bypassPrescaler;             /*!< True: bypass prescaler; false: use clock from prescaler */
     lptim_prescaler_clock_select_t prescalerClockSource; /*!< lptim clock source */
     lptim_prescaler_glitch_value_t value;                /*!< Prescaler or glitch filter value */
 } lptim_config_t;
 
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
  * @brief Ungates the lptim clock and configures the peripheral for a basic operation.
  *
  * @note This API should be called at the beginning of the application using the lptim driver.
  *
  * @param base   lptim peripheral base address
  * @param config A pointer to the lptim configuration structure.
  */
 void LPTIM_Init(LPTIM_Type *base, const lptim_config_t *config);
 
 /*!
  * @brief Gates the lptim clock.
  *
  * @param base lptim peripheral base address
  */
 void LPTIM_Deinit(LPTIM_Type *base);
 
 /*!
  * @brief Fills in the lptim configuration structure with default settings.
  *
  * The default values are as follows.
  * @code
  *    config->timerMode = LPTIM_TimerModeTimeCounter;
  *    config->pinSelect = LPTIM_PinSelectInput_0;
  *    config->pinPolarity = LPTIM_PinPolarityActiveHigh;
  *    config->enableFreeRunning = false;
  *    config->bypassPrescaler = true;
  *    config->prescalerClockSource = LPTIM_PrescalerClock_1;
  *    config->value = LPTIM_Prescale_Glitch_0;
  * @endcode
  * @param config A pointer to the lptim configuration structure.
  */
 void LPTIM_GetDefaultConfig(lptim_config_t *config);
 
 /*! @}*/
 
 /*!
  * @name Interrupt Interface
  * @{
  */
 
 /*!
  * @brief Enables the selected lptim interrupts.
  *
  * @param base lptim peripheral base address
  * @param mask The interrupts to enable. This is a logical OR of members of the
  *             enumeration ::lptim_interrupt_enable_t
  */
 static inline void LPTIM_EnableInterrupts(LPTIM_Type *base, uint32_t mask)
 {
     uint32_t reg = base->CSR;
     /* Clear the TCF bit so that we don't clear this w1c bit when writing back */
     reg &= ~(LPTIM_CSR_TCF_MASK);
     reg |= mask;
     base->CSR = reg;       
 }
 
 /*!
  * @brief Disables the selected lptim interrupts.
  *
  * @param base lptim peripheral base address
  * @param mask The interrupts to disable. This is a logical OR of members of the
  *             enumeration ::lptim_interrupt_enable_t.
  */
 static inline void LPTIM_DisableInterrupts(LPTIM_Type *base, uint32_t mask)
 {
     uint32_t reg = base->CSR;
 
     /* Clear the TCF bit so that we don't clear this w1c bit when writing back */
     reg &= ~(LPTIM_CSR_TCF_MASK);
     reg &= ~mask;
     base->CSR = reg;
 }
 
 /*!
  * @brief Gets the enabled lptim interrupts.
  *
  * @param base lptim peripheral base address
  *
  * @return The enabled interrupts. This is the logical OR of members of the
  *         enumeration ::lptim_interrupt_enable_t
  */
 static inline uint32_t LPTIM_GetEnabledInterrupts(LPTIM_Type *base)
 {
     return (base->CSR & LPTIM_CSR_TIE_MASK);
 }
  
 /*!
  * @name Status Interface
  * @{
  */
 
 /*!
  * @brief Gets the lptim status flags.
  *
  * @param base lptim peripheral base address
  *
  * @return The status flags. This is the logical OR of members of the
  *         enumeration ::lptim_status_flags_t
  */
 static inline uint32_t LPTIM_GetStatusFlags(LPTIM_Type *base)
 {
     return (base->CSR & LPTIM_CSR_TCF_MASK);
 }
 
 /*!
  * @brief  Clears the lptim status flags.
  *
  * @param base lptim peripheral base address
  * @param mask The status flags to clear. This is a logical OR of members of the
  *             enumeration ::lptim_status_flags_t.
  */
 static inline void LPTIM_ClearStatusFlags(LPTIM_Type *base, uint32_t mask)
 {
     base->CSR |= mask;
 }
 
 /*! @}*/
 
 /*!
  * @name Read and write the timer period
  * @{
  */
 
 /*!
  * @brief Sets the timer period in units of count.
  *
  * Timers counts from 0 until it equals the count value set here. The count value is written to
  * the CMR register.
  *
  * @note
  * 1. The TCF flag is set with the CNR equals the count provided here and then increments.
  * 2. Call the utility macros provided in the driver_common.h to convert to ticks.
  *
  * @param base  lptim peripheral base address
  * @param ticks A timer period in units of ticks, which should be equal or greater than 1.
  */
 static inline void LPTIM_SetTimerPeriod(LPTIM_Type *base, uint32_t ticks)
 {
     assert(ticks > 0U);
     base->CMR = LPTIM_CMR_COMPARE_SET(ticks - 1U);
 }
 
 /*!
  * @brief Reads the current timer counting value.
  *
  * This function returns the real-time timer counting value in a range from 0 to a
  * timer period.
  *
  * @note Call the utility macros provided in the driver_common.h to convert ticks to usec or msec.
  *
  * @param base lptim peripheral base address
  *
  * @return The current counter value in ticks
  */
 static inline uint32_t LPTIM_GetCurrentTimerCount(LPTIM_Type *base)
 {
     /* Must first write any value to the CNR. This synchronizes and registers the current value
      * of the CNR into a temporary register which can then be read
      */
     base->CNR = 0U;
     return (uint32_t)((base->CNR & LPTIM_CNR_COUNTER_MASK) >> LPTIM_CNR_COUNTER_SHIFT);
 }
 
 /*! @}*/
 
 /*!
  * @name Timer Start and Stop
  * @{
  */
 
 /*!
  * @brief Starts the timer.
  *
  * After calling this function, the timer counts up to the CMR register value.
  * Each time the timer reaches the CMR value and then increments, it generates a
  * trigger pulse and sets the timeout interrupt flag. An interrupt is also
  * triggered if the timer interrupt is enabled.
  *
  * @param base lptim peripheral base address
  */
 static inline void LPTIM_StartTimer(LPTIM_Type *base)
 {
     uint32_t reg = base->CSR;
 
     /* Clear the TCF bit to avoid clearing the w1c bit when writing back. */
     reg &= ~(LPTIM_CSR_TCF_MASK);
     reg |= LPTIM_CSR_TEN_MASK;
     base->CSR = reg;     
 }
 
 /*!
  * @brief Stops the timer.
  *
  * This function stops the timer and resets the timer's counter register.
  *
  * @param base lptim peripheral base address
  */
 static inline void LPTIM_StopTimer(LPTIM_Type *base)
 {
     uint32_t reg = base->CSR;
 
     /* Clear the TCF bit to avoid clearing the w1c bit when writing back. */
     reg &= ~(LPTIM_CSR_TCF_MASK);
     reg &= ~LPTIM_CSR_TEN_MASK;
     base->CSR = reg;
 }
 
 /*! @}*/
 
 #if defined(__cplusplus)
 }
 #endif
 
 /*! @}*/
 
 #endif /* _LPTIM_H_ */
 