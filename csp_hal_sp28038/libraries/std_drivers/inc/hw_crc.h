/*
  ******************************************************************************
  * @file           : hw_crc.h
  * @brief          : hw_crc program body
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

#ifndef HW_CRC_H
#define HW_CRC_H

//*************************************************************************************************
//
// The following are defines for the CRC register offsets
//
//*************************************************************************************************
#define CRC_DATA          0x00U  // CRC Data register
#define CRC_GPOLY         0x04U  // CRC Polynomial register
#define CRC_CTRL          0x08U  // CRC Control register

//*************************************************************************************************
//
// The following are defines for the bit fields in the CRC_DATA register
//
//*************************************************************************************************
#define CRC_DATA_LL_S    0U  
#define CRC_DATA_LL_M    0xFFU // CRC Low Lower Byte

#define CRC_DATA_LU_S    8U  
#define CRC_DATA_LU_M    0xFF00U // CRC Low Upper Byte

#define CRC_DATA_HL_S    16U  
#define CRC_DATA_HL_M    0xFF0000U // CRC High Lower Byte

#define CRC_DATA_HU_S    24U  
#define CRC_DATA_HU_M    0xFF000000U // CRC High Upper Byte

//*************************************************************************************************
//
// The following are defines for the bit fields in the CRC_GPOLY register
//
//*************************************************************************************************
#define CRC_GPOLY_LOW_S     0U  
#define CRC_GPOLY_LOW_M     0xFFFFU  //Low Polynominal Half-word
#define CRC_GPOLY_HIGH_S    16U 
#define CRC_GPOLY_HIGH_M    0xFFFFU // High Polynominal Half-word

 
//*************************************************************************************************
//
// The following are defines for the bit fields in the CRC_CTRL register
//
//*************************************************************************************************
#define CRC_CTRL_TCRC         0x1000000
#define CRC_CTRL_WAS          0x2000000
#define CRC_CTRL_FXOR         0x4000000
#define CRC_CTRL_TOTR_S       28
#define CRC_CTRL_TOTR_M       0x30000000
#define CRC_CTRL_TOT_S        30
#define CRC_CTRL_TOT_M        0xC0000000



#endif
