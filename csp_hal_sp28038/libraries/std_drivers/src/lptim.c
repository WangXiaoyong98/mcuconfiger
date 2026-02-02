/*
  ******************************************************************************
  * @file           : lptim.c
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

 #include "lptim.h"


 /*******************************************************************************
  * Prototypes
  ******************************************************************************/

 
 /*******************************************************************************
  * Variables
  ******************************************************************************/
 
 /*******************************************************************************
  * Code
  ******************************************************************************/

 
 /*!
  * brief Ungates the LPTIM clock and configures the peripheral for a basic operation.
  *
  * note This API should be called at the beginning of the application using the LPTIM driver.
  *
  * param base   LPTIM peripheral base address
  * param config A pointer to the LPTIM configuration structure.
  */
 void LPTIM_Init(LPTIM_Type *base, const lptim_config_t *config)
 {
     assert(NULL != config);
 
     
     /* Configure the timers operation mode and input pin setup */
     base->CSR = (LPTIM_CSR_TMS_SET(config->timerMode) | LPTIM_CSR_TFC_SET(config->enableFreeRunning) |
                  LPTIM_CSR_TPP_SET(config->pinPolarity) | LPTIM_CSR_TPS_SET(config->pinSelect));
 
     /* Configure the prescale value and clock source */
     base->PSR = (LPTIM_PSR_PRESCALE_SET(config->value) | LPTIM_PSR_PBYP_SET(config->bypassPrescaler) |
                  LPTIM_PSR_PCS_SET(config->prescalerClockSource));                 
 }
 
 /*!
  * brief Gates the LPTIM clock.
  *
  * param base LPTIM peripheral base address
  */
 void LPTIM_Deinit(LPTIM_Type *base)
 {
     /* Disable the LPTIM and reset the internal logic */
     base->CSR &= ~LPTIM_CSR_TEN_MASK;
 }
 /*!
  * brief Fills in the LPTIM configuration structure with default settings.
  *
  * The default values are as follows.
  * code
  *    config->timerMode = LPTIM_TimerModeTimeCounter;
  *    config->pinSelect = LPTIM_PinSelectInput_0;
  *    config->pinPolarity = LPTIM_PinPolarityActiveHigh;
  *    config->enableFreeRunning = false;
  *    config->bypassPrescaler = true;
  *    config->prescalerClockSource = LPTIM_PrescalerClock_1;
  *    config->value = LPTIM_Prescale_Glitch_0;
  * endcode
  * param config A pointer to the LPTIM configuration structure.
  */
 void LPTIM_GetDefaultConfig(lptim_config_t *config)
 {
     assert(NULL != config);
 
     /* Initializes the configure structure to zero. */
     (void)memset(config, 0, sizeof(*config));
 
     /* Use time counter mode */
     config->timerMode = LPTIM_TimerModeTimeCounter;
     /* Use input 0 as source in pulse counter mode */
     config->pinSelect = LPTIM_PinSelectInput_0;
     /* Pulse input pin polarity is active-high */
     config->pinPolarity = LPTIM_PinPolarityActiveHigh;
     /* Counter resets whenever TCF flag is set */
     config->enableFreeRunning = false;
     /* Bypass the prescaler */
     config->bypassPrescaler = true;
     /* LPTIM clock source */

     config->prescalerClockSource = LPTIM_PrescalerClock_1;
     /* Divide the prescaler clock by 2 */
     config->value = LPTIM_Prescale_Glitch_0;
 }

 

 