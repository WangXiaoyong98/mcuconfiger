/*
  ******************************************************************************
  * @file           : hw_lptim.c
  * @brief          : hw_lptim program body
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

#ifndef HW_LPTIM_H
#define HW_LPTIM_H

//*************************************************************************************************
//
// The following are defines for the LPTIM register offsets
//
//*************************************************************************************************
#define LPTIM_O_CSR  0x00U  // Low Power Timer Control Status Register
#define LPTIM_O_PSR  0x04U  // Low Power Timer Prescale Register
#define LPTIM_O_CMR  0x08U  // Low Power Timer Compare Register
#define LPTIM_O_CNR  0x0CU  // Low Power Timer Counter Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the LPTIM_O_CSR register
//
//*************************************************************************************************
#define LPTIM_CSR_TEN    0x01U  // Timer enable
#define LPTIM_CSR_TMS    0x02U  // Timer mode selection
#define LPTIM_CSR_TFC    0x04U  // Timer runs the counter freely
#define LPTIM_CSR_TPP    0x08U  // Timer pin polarity
#define LPTIM_CSR_TPS_S  4U     // 
#define LPTIM_CSR_TPS_M  0x30U  // Timer pin selection
#define LPTIM_CSR_TIE    0x40U  // The timer interruption was enabled
#define LPTIM_CSR_TCF    0x80U  // Timer comparison flag


//*************************************************************************************************
//
// The following are defines for the bit fields in the LPTIM_O_PSR register
//
//*************************************************************************************************
#define LPTIM_PSR_PCS_S     0U  // Bits 1-0: Prescaler Clock Select. Selects the clock used by the LPTIM prescaler/glitch filter.
#define LPTIM_PSR_PCS_M     0x03U
#define LPTIM_PSR_PBYP      0x04U //Prescaler Bypass.
#define LPTIM_PSR_PRESCALE_S   3U //Bits 6-3: Prescaler value.
#define LPTIM_PSR_PRESCALE_M   0x78U //Bits 6-3: Prescaler value.



//*************************************************************************************************
//
// The following are defines for the bit fields in the LPTIM_O_CMR register
//
//*************************************************************************************************
#define LPTIM_CMR_COMPARE_S    0U
#define LPTIM_CMR_COMPARE_M    0xFFFFU          // Comparison value


//*************************************************************************************************
//
// The following are defines for the bit fields in the LPTIM_O_CNR register
//
//*************************************************************************************************
#define LPTIM_CNR_COUNTER_S    0U
#define LPTIM_CNR_COUNTER_M    0xFFFFU          // Count value

#endif
