/*
  ******************************************************************************
  * @file           : hw_flash.h
  * @brief          : flash register map
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

#ifndef HW_FLASH_H
#define HW_FLASH_H

//*************************************************************************************************
//
// The following are defines for the FLASH register offsets
//
//*************************************************************************************************
#define FLASH_O_CMD             0x4U     // Flash Command Register
#define FLASH_O_ADDR            0x8U     // Flash Address Register
#define FLASH_O_DATA_UM         0xCU     // Flash Data Register 1
#define FLASH_O_DATA_MU         0x10U    // Flash Data Register 2
#define FLASH_O_DATA_ML         0x14U    // Flash Data Register 3
#define FLASH_O_DATA_LM         0x18U    // Flash Data Register 4
#define FLASH_O_WAITCYCLE       0x1CU    // Flash Wait Cycle Register
#define FLASH_O_PROTECT         0x20U    // Flash Protect Register
#define FLASH_O_STAT            0x24U    // Flash Status Register
#define FLASH_O_CCTL            0x28U    // Flash Cache Control Register


#define SYSCTRL_O_ECC_FESR      0x0U    // Flash ECC Status Register
#define SYSCTRL_O_ECC_FECR      0x4U    // Flash ECC Control Register
#define SYSCTRL_O_ECC_FEER      0x8U    // Flash ECC Enable Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the Flash_STAT register
//
//*************************************************************************************************
#define FLASH_STAT_BUSY_S       0U
#define FLASH_STAT_BUSY_M       0x1U   // Flash BUSY

//*************************************************************************************************
//
// The following are defines for the bit fields in the Flash_STAT register
//
//*************************************************************************************************
#define FLASH_CCTL_CACHE_CLR_S            0U
#define FLASH_CCTL_CACHE_CLR_M            0x1U   // Cache clear
#define FLASH_CCTL_CACHE_DISABLE_S        1U
#define FLASH_CCTL_CACHE_DISABLE_M        0x2U   // Cache disable


//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSCTRL_FESR() register
//
//*************************************************************************************************
#define FLASH_ECC_ERROR_S   1U
#define FLASH_ECC_ERROR_M   0x2U   // Double Bit Error Detect Flag


//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSCTRL_FECR() register
//
//*************************************************************************************************
#define FLASH_ECC_FDFD_S     7U
#define FLASH_ECC_FDFD_M     0x80U        //Force Double Bit Error Detect
#define FLASH_ECC_DFDIE_S    1U
#define FLASH_ECC_DFDIE_M    2U           // Double Bit Error Detect Interrupt Enable


//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSCTRL_FEER() register
//
//*************************************************************************************************
#define FLASH_ECC_ENABLE_ENABLE_S   1U     // Write 1 to disable ECC
#define FLASH_ECC_ENABLE_ENABLE_M   0x2U   // Enable Flash ECC


//*************************************************************************************************
//
// Flash operation key
//
//*************************************************************************************************
#define PROTECT_KEY      0x5a5a
#define MAIN_AREA_KEY    0x5a5a
#define BOOT_AREA_KEY    0xbd39
#define DATA_AREA_KEY    0xda58
#endif
