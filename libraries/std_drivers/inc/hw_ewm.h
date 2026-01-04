/*
  ******************************************************************************
  * @file           : hw_ewm.h
  * @brief          : hw_ewm program body
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

#ifndef HW_EWM_H
#define HW_EWM_H

//*************************************************************************************************
//
// The following are defines for the ewm register offsets
//
//*************************************************************************************************

#define EWM_CTRL          0x00U  // Control Register
#define EWM_SERV          0x01U  // Service Register
#define EWM_CMPL          0x02U  // Compare Low Register
#define EWM_CMPH          0x03U  // Compare High Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the EWM_CTRL register
//
//*************************************************************************************************
#define EWM_CTRL_EWMEN    0x01U  // EWM is enabled
#define EWM_CTRL_ASSIN    0x02U  // Assertion state selection for EWM_in
#define EWM_CTRL_INEN     0x04U  // Input enable
#define EWM_CTRL_INTEN    0x08U  // Interrupt enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the EWM_SERV register
//
//*************************************************************************************************
#define EWM_SERV_SERVICE   0xFFU // 

//*************************************************************************************************
//
// The following are defines for the bit fields in the EWM_CMPL register
//
//*************************************************************************************************
#define EWM_CMPL_COMPAREL   0xFFU // Timer value


//*************************************************************************************************
//
// The following are defines for the bit fields in the EWM_CMPH register
//
//*************************************************************************************************
#define EWM_CMPH_COMPAREH   0xFFU // Timer value


#endif
