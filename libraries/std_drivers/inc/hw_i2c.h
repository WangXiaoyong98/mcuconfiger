/*
  ******************************************************************************
  * @file           : hw_i2c.h
  * @brief          : i2c register map
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

#ifndef HW_I2C_H
#define HW_I2C_H

//*************************************************************************************************
//
// I2C - Peripheral instance base addresses
//
//*************************************************************************************************
#define I2C1_BASE                 0x40066000u

//*************************************************************************************************
//
// The following are defines for the I2C register offsets
//
//*************************************************************************************************
#define I2C_O_CONSET       0x0U    // Configuration Set Register
#define I2C_O_CONCLR       0x4U    // Configuration Clear Register
#define I2C_O_STAT         0x8U    // Status Register
#define I2C_O_DAT          0xCU    // Data Register
#define I2C_O_CLK          0x10U   // Clock Register
#define I2C_O_ADR0         0x14U   // Address Register 0
#define I2C_O_ADRMASK0     0x18U   // Address Mask Register 0
#define I2C_O_XADR0        0x1CU   // Extended Address Register 0
#define I2C_O_XADRMASK0    0x20U   // Extended Address Mask Register 0
#define I2C_O_RST          0x24U   // Reset Register
#define I2C_O_ADR1         0x28U   // Address Register 1
#define I2C_O_ADRMASK1     0x2CU   // Address Mask Register 1
#define I2C_O_ADR2         0x30U   // Address Register 2
#define I2C_O_ADRMASK2     0x34U   // Address Mask Register 2
#define I2C_O_ADR3         0x38U   // Address Register 3
#define I2C_O_ADRMASK3     0x3CU   // Address Mask Register 3

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONSET register
//
//*************************************************************************************************
#define I2C_CONSET_ADRF_S        0U
#define I2C_CONSET_ADRF_M        0x1U      // Address Flag
#define I2C_CONSET_XADRF_S       1U
#define I2C_CONSET_XADRF_M       0x2U      // Extended Address Flag
#define I2C_CONSET_AA_S          2U
#define I2C_CONSET_AA_M          0x4U      // Acknowledge Action
#define I2C_CONSET_SI_S          3U
#define I2C_CONSET_SI_M          0x8U      // Interrupt Flag
#define I2C_CONSET_STO_S         4U
#define I2C_CONSET_STO_M         0x10U     // Stop Condition
#define I2C_CONSET_STA_S         5U
#define I2C_CONSET_STA_M         0x20U     // Start Condition
#define I2C_CONSET_I2CEN_S       6U
#define I2C_CONSET_I2CEN_M       0x40U     // I2C Enable
#define I2C_CONSET_I2CIE_S       7U
#define I2C_CONSET_I2CIE_M       0x80U     // I2C Interrupt Enable
#define I2C_CONSET_GCF_S         8U
#define I2C_CONSET_GCF_M         0x100U    // General Call Flag
#define I2C_CONSET_SSTAEN_S      9U
#define I2C_CONSET_SSTAEN_M      0x200U    // Repeated Start Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONCLR register
//
//*************************************************************************************************
#define I2C_CONCLR_AAC_S         2U
#define I2C_CONCLR_AAC_M         0x4U      // Acknowledge Action Clear
#define I2C_CONCLR_SIC_S         3U
#define I2C_CONCLR_SIC_M         0x8U      // Interrupt Flag Clear
#define I2C_CONCLR_STAC_S        5U
#define I2C_CONCLR_STAC_M        0x20U     // Start Condition Clear
#define I2C_CONCLR_I2ENC_S       6U
#define I2C_CONCLR_I2ENC_M       0x40U     // I2C Enable Clear
#define I2C_CONCLR_I2CIEC_S      7U
#define I2C_CONCLR_I2CIEC_M      0x80U     // I2C Interrupt Enable Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the STAT register
//
//*************************************************************************************************
#define I2C_STAT_STATUS_S        3U
#define I2C_STAT_STATUS_M        0xF8U     // Status Code

//*************************************************************************************************
//
// The following are defines for the bit fields in the DAT register
//
//*************************************************************************************************
#define I2C_DAT_DATA_S           0U
#define I2C_DAT_DATA_M           0xFFU     // Data

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLK register
//
//*************************************************************************************************
#define I2C_CLK_N_S              0U
#define I2C_CLK_N_M              0xFU      // Clock Divider N
#define I2C_CLK_M_S              4U
#define I2C_CLK_M_M              0x70U     // Clock Divider M

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADR0 register
//
//*************************************************************************************************
#define I2C_ADR0_GC_S            0U
#define I2C_ADR0_GC_M            0x1U      // General Call Enable
#define I2C_ADR0_ADDR_S          1U
#define I2C_ADR0_ADDR_M          0xFEU     // Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADRMASK0 register
//
//*************************************************************************************************
#define I2C_ADRMASK0_MASK_S      1U
#define I2C_ADRMASK0_MASK_M      0xFEU     // Address Mask

//*************************************************************************************************
//
// The following are defines for the bit fields in the XADR0 register
//
//*************************************************************************************************
#define I2C_XADR0_XADDR_S        1U
#define I2C_XADR0_XADDR_M        0xFEU     // Extended Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the XADRMASK0 register
//
//*************************************************************************************************
#define I2C_XADRMASK0_XADDR_S    1U
#define I2C_XADRMASK0_XADDR_M    0xFEU     // Extended Address Mask

//*************************************************************************************************
//
// The following are defines for the bit fields in the RST register
//
//*************************************************************************************************
#define I2C_RST_RST_S            0U
#define I2C_RST_RST_M            0xFFU     // Reset

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADR1-3 and ADRMASK1-3 registers
//
//*************************************************************************************************
#define I2C_ADR1_GC_S            0U
#define I2C_ADR1_GC_M            0x1U      // General Call Enable
#define I2C_ADR1_ADDR_S          1U
#define I2C_ADR1_ADDR_M          0xFEU     // Address
#define I2C_ADRMASK1_MASK_S      1U
#define I2C_ADRMASK1_MASK_M      0xFEU     // Address Mask

#define I2C_ADR2_GC_S            0U
#define I2C_ADR2_GC_M            0x1U      // General Call Enable
#define I2C_ADR2_ADDR_S          1U
#define I2C_ADR2_ADDR_M          0xFEU     // Address
#define I2C_ADRMASK2_MASK_S      1U
#define I2C_ADRMASK2_MASK_M      0xFEU     // Address Mask

#define I2C_ADR3_GC_S            0U
#define I2C_ADR3_GC_M            0x1U      // General Call Enable
#define I2C_ADR3_ADDR_S          1U
#define I2C_ADR3_ADDR_M          0xFEU     // Address
#define I2C_ADRMASK3_MASK_S      1U
#define I2C_ADRMASK3_MASK_M      0xFEU     // Address Mask

#endif  // HW_I2C_H
