/*
  ******************************************************************************
  * @file           : hw_sysctl.h
  * @brief          : system control register map
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

#ifndef HW_SYSCTL_H
#define HW_SYSCTL_H

//*************************************************************************************************
//
// The following are defines for the SYSCTL register offsets
//
//*************************************************************************************************
#define SYSCTL_O_CLKDIV         0x4U         /**< Clock Divider Register */
#define SYSCTL_O_PLLCFG         0x8U     /**< PLL Configuration Register */
#define SYSCTL_O_CLKSW          0xCU     /**< Clock Switch Register */
#define SYSCTL_O_SYSREMAP       0x10U     /**< System Remap Register */
#define SYSCTL_O_POWERCFG       0x14U    /**< Power Configuration Register */
#define SYSCTL_O_UNLOCK         0x18U    /**< Unlock Register */
#define SYSCTL_O_ISP1CGC1       0x1CU    /**< ISP1 Clock Gating Control Register 1 */
#define SYSCTL_O_ISP1CGC2       0x20U    /**< ISP1 Clock Gating Control Register 2 */
#define SYSCTL_O_ISP1CGC3       0x24U    /**< ISP1 Clock Gating Control Register 3 */
#define SYSCTL_O_ISP2CGC1       0x28U    /**< ISP2 Clock Gating Control Register 1 */
#define SYSCTL_O_ISP2CGC2       0x2CU    /**< ISP2 Clock Gating Control Register 2 */
#define SYSCTL_O_ISP2CGC3       0x30U    /**< ISP2 Clock Gating Control Register 3 */
#define SYSCTL_O_ONPLATCGC      0x34U    /**< ON-Platform Clock Gating Control Register */
#define SYSCTL_O_SCICLKSEL      0x38U    /**< SCI Clock Select Register */
#define SYSCTL_O_CLKOUTSEL      0x3CU    /**< Clock Out Select Register */
#define SYSCTL_O_PLLDIV         0x40U    /**< PLL Divider Register */
#define SYSCTL_O_IOSC8MTRIM     0x44U    /**< 8MHz Internal Oscillator Trim Register */
#define SYSCTL_O_IOSC32KTRIM    0x48U    /**< 32KHz Internal Oscillator Trim Register */
#define SYSCTL_O_LDOCFG         0x4CU    /**< LDO Configuration Register */
#define SYSCTL_O_RESERVED2      0x50U    /**< Reserved */
#define SYSCTL_O_VDT1TRIM       0x54U    /**< VDT1 Trim Value Register */
#define SYSCTL_O_VDT2TRIM       0x58U    /**< VDT2 Trim Value Register */
#define SYSCTL_O_VDT1CON        0x5CU    /**< VDT1 Control Register */
#define SYSCTL_O_VDT2CON        0x60U    /**< VDT2 Control Register */
#define SYSCTL_O_TDTTRIM        0x64U    /**< TDT Trim Value Register */
#define SYSCTL_O_XOSCPYPASS     0x68U    /**< XOSC Power-Up Pass Register */
#define SYSCTL_O_CANCTR         0x6CU    /**< CAN Control Register */
#define SYSCTL_O_SOFTRST1       0x70U    /**< Software Reset Register 1 */
#define SYSCTL_O_SOFTRST2       0x74U    /**< Software Reset Register 4 */
#define SYSCTL_O_DEVICEID1      0x78U    /**< Device ID Register 1 */
#define SYSCTL_O_DEVICEID2      0x7CU    /**< Device ID Register 2 */
#define SYSCTL_O_TDTALARM       0x80U    /**< TDT Alarm Register */
#define SYSCTL_O_LDOTBGR        0x84U    /**< LDO TBGR Register */
#define SYSCTL_O_LDOTCBGR       0x88U    /**< LDO TCGR Register */
#define SYSCTL_O_LDOVDDOPT      0x8CU    /**< LDO VDDOPT Register */
#define SYSCTL_O_ADCSOCOUTSEL   0x90U    /**< ADC SOC Output Select Register */
#define SYSCTL_O_ACCUPORBDIS    0x94U    /**< ACCU POR Disable Register */
#define SYSCTL_O_FLSFASTWKUP    0x98U    /**< FLS Fast Wake-Up Register */
#define SYSCTL_O_FESR           0x9CU    /**< FLS Error Status Register */
#define SYSCTL_O_FECR           0xA0U    /**< FLS Error Clear Register */
#define SYSCTL_O_FEER           0xA4U    /**< FLS Error Enable Register */
#define SYSCTL_O_PORBREG1       0xA8U    /**< PORB Register 1 */
#define SYSCTL_O_PORBREG2       0xACU    /**< PORB Register 2 */
#define SYSCTL_O_SPANACFG       0xB0U    /**< Spanning A Configuration Register */
#define SYSCTL_O_PLLLDOTRIM     0xB4U    /**< PLL LDO Trim Register */
#define SYSCTL_O_SOFTIPT        0xB8U    /**< Software Interrupt Register */
#define SYSCTL_O_SLEEPWKTMREN   0xBCU    /**< Sleep Wake-Up Timer Enable Register */
#define SYSCTL_O_TBCLKSYNC      0xC0U    /**< TBCLK Synchronization Register */

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKDIV register
//
//*************************************************************************************************
#define SYSCTL_O_CLKDIV_SYSDIV_M      0xF0000000U   /**< System Clock Divider Mask */
#define SYSCTL_O_CLKDIV_SYSDIV_S      28U           /**< System Clock Divider Shift */
#define SYSCTL_O_CLKDIV_BUSDIV_M    0x0F000000U   /**< Bus Clock Divider Mask */
#define SYSCTL_O_CLKDIV_BUSDIV_S      24U           /**< Bus Clock Divider Shift */
#define SYSCTL_O_CLKYDIV_FTFDIV_M    0x000F0000U   /**< Flash Clock Divider Mask */
#define SYSCTL_O_CLKYDIV_FTFDIV_S      16U           /**< Flash Clock Divider Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the PLLCFG register
//
//*************************************************************************************************
#define SYSCTL_O_PLLCFG_PLLLOCK_M    0x00020000U   /**< PLL LOCK Mask */
#define SYSCTL_O_PLLCFG_PLLLOCK_S      17U           /**< PLL LOCK Shift */
#define SYSCTL_O_PLLCFG_PLLLOCKBYPASS_M    0x00010000U   /**< PLL LOCK BYPASS Mask */
#define SYSCTL_O_PLLCFG_PLLLOCKBYPASS_S      16U           /**< PLL LOCK BYPASS Shift */
#define SYSCTL_O_PLLCFG_ODIV_M        0x0000C000U   /**< PLL Output Divider Mask */
#define SYSCTL_O_PLLCFG_ODIV_S        14U           /**< PLL Output Divider Shift */
#define SYSCTL_O_PLLCFG_REFDIV_M    0x00003F00U   /**< PLL Reference Divider Mask */
#define SYSCTL_O_PLLCFG_REFDIV_S      8U            /**< PLL Reference Divider Shift */
#define SYSCTL_O_PLLCFG_IMULT_M        0x000000FFU   /**< PLL Integer Multiplier Mask */
#define SYSCTL_O_PLLCFG_IMULT_S        0U            /**< PLL Integer Multiplier Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSW register
//
//*************************************************************************************************
#define SYSCTL_O_CLKSW_SCGCLKSEL_M    0x00000004U   /**< MUX3 Mask */
#define SYSCTL_O_CLKSW_SCGCLKSEL_S      2U            /**< MUX3 Shift */
#define SYSCTL_O_CLKSW_PLLCLKSEL_M    0x00000002U   /**< MUX2 Mask */
#define SYSCTL_O_CLKSW_PLLCLKSEL_S      1U            /**< MUX2 Shift */
#define SYSCTL_O_CLKSW_CLKSRCSEL_M    0x00000001U   /**< MUX1 Mask */
#define SYSCTL_O_CLKSW_CLKSRCSEL_S      0U            /**< MUX1 Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSREMAP register
//
//*************************************************************************************************
#define SYSCTL_O_SYSREMAP_SYSRAMREMAP_M    0x00000003U   /**< SYSRAM Remap Mask */
#define SYSCTL_O_SYSREMAP_SYSRAMREMAP_S      0U            /**< SYSRAM Remap Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the POWERCFG register
//
//*************************************************************************************************
#define SYSCTL_O_POWERCFG_LDO_PD_M    0x00008000U   /**< LDO powerdown Mask */
#define SYSCTL_O_POWERCFG_LDO_PD_S      15U            /**< LDO powerdown Shift */
#define SYSCTL_O_POWERCFG_LDO_SLEEP_M    0x00004000U   /**< LDO sleep Mask */
#define SYSCTL_O_POWERCFG_LDO_SLEEP_S      14U            /**< LDO sleep Shift */
#define SYSCTL_O_PLL_PD_M          0x00000020U   /**< PLL powerdown Mask */
#define SYSCTL_O_PLL_PD_S            5U            /**< PLL powerdown Shift */
#define SYSCTL_O_XOSC16M_PD_M      0x00000010U   /**< XOSC16M powerdown Mask */
#define SYSCTL_O_XOSC16M_PD_S        4U            /**< XOSC16M powerdown Shift */
#define SYSCTL_O_IOSC30K_PD_M      0x00000008U   /**< IOSC30K powerdown Mask */
#define SYSCTL_O_IOSC30K_PD_S        3U            /**< IOSC30K powerdown Shift */
#define SYSCTL_O_IOSC8M_PD_M      0x00000004U   /**< IOSC8M powerdown Mask */
#define SYSCTL_O_IOSC8M_PD_S        2U            /**< IOSC8M powerdown Shift */
#define SYSCTL_O_FLASH1_PD_M      0x00000002U   /**< FLASH1 powerdown Mask */
#define SYSCTL_O_FLASH1_PD_S        1U            /**< FLASH1 powerdown Shift */
#define SYSCTL_O_FLASH0_PD_M      0x00000001U   /**< FLASH0 powerdown Mask */
#define SYSCTL_O_FLASH0_PD_S        0U            /**< FLASH0 powerdown Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the ISP1CGC1 register
//
//*************************************************************************************************
#define SYSCTL_O_ISP1CGC1_FMCGC_M     0x00000001U   /**< FMCGC Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_FMCGC_S       0U            /**< FMCGC Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_DMAMUXCG_M  0x00000002U   /**< DMAMUXCG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_DMAMUXCG_S    1U            /**< DMAMUXCG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_LPTIMCGC_M  0x00000008U   /**< GPIOACGC Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_LPTIMCGC_S    3U            /**< GPIOACGC Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_CAN1CG_M    0x00000010U   /**< CAN1CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_CAN1CG_S      4U            /**< CAN1CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_XBARCG_M    0x00000100U   /**< XBARCG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_XBARCG_S      8U            /**< XBARCG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_SPI1CG_M    0x00001000U   /**< SPI1CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_SPI1CG_S      12U            /**< SPI1CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_SPI2CG_M    0x00002000U   /**< SPI2CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_SPI2CG_S      13U            /**< SPI2CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_XINTCG_M    0x00004000U   /**< XINTCG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_XINTCG_S      14U            /**< XINTCG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_SDFM1CG_M    0x00010000U   /**< SDFM1CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_SDFM1CG_S      16U            /**< SDFM1CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_PTIMCG_M    0x00800000U   /**< PTIMCG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_PTIMCG_S      23U            /**< PTIMCG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_EPWM1CG_M   0x01000000U   /**< EPWM1CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_EPWM1CG_S      24U            /**< EPWM1CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_EPWM2CG_M   0x02000000U   /**< EPWM2CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_EPWM2CG_S      25U            /**< EPWM2CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_EPWM3CG_M   0x04000000U   /**< EPWM3CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_EPWM3CG_S      26U            /**< EPWM3CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_ADC1CG_M    0x08000000U   /**< ADC1CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_ADC1CG_S      27U            /**< ADC1CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC1_ADC2CG_M    0x10000000U   /**< ADC2CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC1_ADC2CG_S      28U            /**< ADC2CG Clock Gate Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the ISP1CGC2 register
//
//*************************************************************************************************
#define SYSCTL_O_ISP1CGC2_EQEP1CG_M    0x00000001U   /**< EQEP1CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC2_EQEP1CG_S      0U            /**< EQEP1CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC2_GPIOACG_M    0x00000200U   /**< GPIOACG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC2_GPIOACG_S      9U            /**< GPIOACG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC2_GPIOBCG_M    0x00000400U   /**< GPIOBCG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC2_GPIOBCG_S      10U            /**< GPIOBCG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC2_ECAP1CG_M    0x01000000U   /**< ECAP1CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC2_ECAP1CG_S      24U            /**< ECAP1CG Clock Gate Shift */
#define SYSCTL_O_ISP1CGC2_ECAP2CG_M    0x02000000U   /**< ECAP2CG Clock Gate Mask */
#define SYSCTL_O_ISP1CGC2_ECAP2CG_S      25U            /**< ECAP2CG Clock Gate Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the ISP1CGC3 register
//
//*************************************************************************************************
#define SYSCTL_O_ISP1CGC3_EWMCG_M    0x00000001U   /**< EWM Clock Gate Mask */
#define SYSCTL_O_ISP1CGC3_EWMCG_S      0U            /**< EWM Clock Gate Shift */
#define SYSCTL_O_ISP1CGC3_I2C1CG_M    0x00000020U   /**< I2C1 Clock Gate Mask */
#define SYSCTL_O_ISP1CGC3_I2C1CG_S      5U            /**< I2C1 Clock Gate Shift */
#define SYSCTL_O_ISP1CGC3_I2C2CG_M    0x00000040U   /**< I2C2 Clock Gate Mask */
#define SYSCTL_O_ISP1CGC3_I2C2CG_S      6U            /**< I2C2 Clock Gate Shift */
#define SYSCTL_O_ISP1CGC3_SCI4CG_M    0x00000200U   /**< SCI4 Clock Gate Mask */
#define SYSCTL_O_ISP1CGC3_SCI4CG_S      9U            /**< SCI4 Clock Gate Shift */
#define SYSCTL_O_ISP1CGC3_SCI5CG_M    0x00000400U   /**< SCI5 Clock Gate Mask */
#define SYSCTL_O_ISP1CGC3_SCI5CG_S      10U            /**< SCI5 Clock Gate Shift */
#define SYSCTL_O_ISP1CGC3_SCI6CG_M    0x00000800U   /**< SCI6 Clock Gate Mask */
#define SYSCTL_O_ISP1CGC3_SCI6CG_S      11U            /**< SCI6 Clock Gate Shift */
#define SYSCTL_O_ISP1CGC3_COMP1CG_M    0x00040000U   /**< COMP1 Clock Gate Mask */
#define SYSCTL_O_ISP1CGC3_COMP1CG_S      18U            /**< COMP1 Clock Gate Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the ISP2CGC1 register
//
//*************************************************************************************************
#define SYSCTL_O_ISP2CGC1_MCAN2_M    0x00000010U   /**< MCAN2 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_MCAN2_S      4U            /**< MCAN2 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC1_EQEP2_M    0x00000040U   /**< EQEP2 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_EQEP2_S      6U            /**< EQEP2 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC1_SPI3_M    0x000001000U   /**< SPI3 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_SPI3_S      12U            /**< SPI3 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC1_SPI4_M    0x000002000U   /**< SPI4 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_SPI4_S      13U            /**< SPI4 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC1_EPWM4_M    0x00010000U   /**< EPWM4 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_EPWM4_S      16U            /**< EPWM4 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC1_EPWM5_M    0x00020000U   /**< EPWM5 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_EPWM5_S      17U            /**< EPWM5 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC1_EPWM6_M    0x00040000U   /**< EPWM6 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_EPWM6_S      18U            /**< EPWM6 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC1_EPWM7_M    0x00080000U   /**< EPWM7 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_EPWM7_S      19U            /**< EPWM7 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC1_ADC3_M    0x08000000U   /**< ADC3 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC1_ADC3_S      27U            /**< ADC3 Clock Gate Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the ISP2CGC2 register
//
//*************************************************************************************************
#define SYSCTL_O_ISP2CGC2_SCI1CG_M    0x00000010U   /**< SCI1 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC2_SCI1CG_S      4U            /**< SCI1 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC2_SCI2CG_M    0x00000020U   /**< SCI2 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC2_SCI2CG_S      5U            /**< SCI2 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC2_SCI3CG_M    0x00000040U   /**< SCI3 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC2_SCI3CG_S      6U            /**< SCI3 Clock Gate Shift */
#define SYSCTL_O_ISP2CGC2_ECAP3CG_M    0x00000200U   /**< ECAP3 Clock Gate Mask */
#define SYSCTL_O_ISP2CGC2_ECAP3CG_S      9U            /**< ECAP3 Clock Gate Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the ONPLATCGC register
//
//*************************************************************************************************
#define SYSCTL_O_ONPLATCGC_DMA_M    0x00000002U   /**< DMA Clock Gate Mask */
#define SYSCTL_O_ONPLATCGC_DMA_S      1U            /**< DMA Clock Gate Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCICLKSEL register
//
//*************************************************************************************************
#define SYSCTL_O_SCICLKSEL_SCI1CLKSRC_M    0x00000003U   /**< SCI1 Clock Source Select Mask */
#define SYSCTL_O_SCICLKSEL_SCI1CLKSRC_S      0U            /**< SCI1 Clock Source Select Shift */
#define SYSCTL_O_SCICLKSEL_SCI2CLKSRC_M    0x0000000CU   /**< SCI2 Clock Source Select Mask */
#define SYSCTL_O_SCICLKSEL_SCI2CLKSRC_S      2U            /**< SCI2 Clock Source Select Shift */
#define SYSCTL_O_SCICLKSEL_SCI3CLKSRC_M    0x00000030U   /**< SCI3 Clock Source Select Mask */
#define SYSCTL_O_SCICLKSEL_SCI3CLKSRC_S      4U            /**< SCI3 Clock Source Select Shift */
#define SYSCTL_O_SCICLKSEL_SCI4CLKSRC_M    0x000000C0U   /**< SCI4 Clock Source Select Mask */
#define SYSCTL_O_SCICLKSEL_SCI4CLKSRC_S      6U           /**< SCI4 Clock Source Select Shift */
#define SYSCTL_O_SCICLKSEL_SCI5CLKSRC_M    0x00000300U   /**< SCI5 Clock Source Select Mask */
#define SYSCTL_O_SCICLKSEL_SCI5CLKSRC_S      8U            /**< SCI5 Clock Source Select Shift */
#define SYSCTL_O_SCICLKSEL_SCI6CLKSRC_M    0x00000C00U   /**< SCI6 Clock Source Select Mask */
#define SYSCTL_O_SCICLKSEL_SCI6CLKSRC_S      10U           /**< SCI6 Clock Source Select Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the VDT1CON register
//
//*************************************************************************************************
#define SYSCTL_O_VDT1CON_EN_M          0x00000001U   /**< VDT1 Enable Mask */
#define SYSCTL_O_VDT1CON_EN_S          0U            /**< VDT1 Enable Shift */
#define SYSCTL_O_VDT1CON_RSTEN_M       0x00000002U   /**< VDT1 Reset Enable Mask */
#define SYSCTL_O_VDT1CON_RSTEN_S       1U            /**< VDT1 Reset Enable Shift */
#define SYSCTL_O_VDT1CON_HSYTEN_M      0x00000004U   /**< VDT1  hysteresis Enable Mask */
#define SYSCTL_O_VDT1CON_HSYTEN_S      2U            /**< VDT1 hysteresis Enable Shift */
#define SYSCTL_O_VDT1CON_EDGINTEN_M    0x00000020U   /**< VDT1 both Edge Interrupt Enable Mask */
#define SYSCTL_O_VDT1CON_EDGINTEN_S    5U            /**< VDT1 both Edge Interrupt Enable Shift */
#define SYSCTL_O_VDT1CON_NEGINTEN_M    0x00000040U   /**< VDT1 Negative edge Interrupt Enable Mask */
#define SYSCTL_O_VDT1CON_NEGINTEN_S    6U            /**< VDT1 Negative edge Interrupt Enable Shift */
#define SYSCTL_O_VDT1CON_POSINTEN_M    0x00000080U   /**< VDT1 Positive edge Interrupt Enable Mask */
#define SYSCTL_O_VDT1CON_POSINTEN_S    7U            /**< VDT1 Positive edge Interrupt Enable Shift */
#define SYSCTL_O_VDT1CON_EDGINTFLG_M   0x00000100U   /**< VDT1 both Edge Interrupt Flag Mask */
#define SYSCTL_O_VDT1CON_EDGINTFLG_S   8U            /**< VDT1 both Edge Interrupt Flag Shift */
#define SYSCTL_O_VDT1CON_NEGINTFLG_M   0x00000200U   /**< VDT1 Negative edge Interrupt Flag Mask */
#define SYSCTL_O_VDT1CON_NEGINTFLG_S   9U            /**< VDT1 Negative edge Interrupt Flag Shift */
#define SYSCTL_O_VDT1CON_POSINTFLG_M   0x00000400U   /**< VDT1 Positive edge Interrupt Flag Mask */
#define SYSCTL_O_VDT1CON_POSINTFLG_S   10U           /**< VDT1 Positive edge Interrupt Flag Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the VDT2CON register
//
//*************************************************************************************************
#define SYSCTL_O_VDT2CON_EN_M    0x00000001U   /**< VDT2 Enable Mask */
#define SYSCTL_O_VDT2CON_EN_S      0U            /**< VDT2 Enable Shift */
#define SYSCTL_O_VDT2CON_RSTEN_M    0x00000002U   /**< VDT2 Reset Enable Mask */
#define SYSCTL_O_VDT2CON_RSTEN_S      1U            /**< VDT2 Reset Enable Shift */
#define SYSCTL_O_VDT2CON_HSYTEN_M    0x00000004U   /**< VDT2  hysteresis Enable Mask */
#define SYSCTL_O_VDT2CON_HSYTEN_S      2U            /**< VDT2 hysteresis Enable Shift */
#define SYSCTL_O_VDT2CON_EDGINTEN_M    0x00000020U   /**< VDT2 both Edge Interrupt Enable Mask */
#define SYSCTL_O_VDT2CON_EDGINTEN_S      5U          /**< VDT2 both Edge Interrupt Enable Shift */
#define SYSCTL_O_VDT2CON_NEGINTEN_M    0x00000040U   /**< VDT2 Negative edge Interrupt Enable Mask */
#define SYSCTL_O_VDT2CON_NEGINTEN_S      6U          /**< VDT2 Negative edge Interrupt Enable Shift */
#define SYSCTL_O_VDT2CON_POSINTEN_M    0x00000080U   /**< VDT2 Positive edge Interrupt Enable Mask */
#define SYSCTL_O_VDT2CON_POSINTEN_S      7U          /**< VDT2 Positive edge Interrupt Enable Shift */
#define SYSCTL_O_VDT2CON_EDGINTFLG_M    0x00000100U   /**< VDT2 both Edge Interrupt Flag Mask */
#define SYSCTL_O_VDT2CON_EDGINTFLG_S      8U          /**< VDT2 both Edge Interrupt Flag Shift */
#define SYSCTL_O_VDT2CON_NEGINTFLG_M    0x00000200U   /**< VDT2 Negative edge Interrupt Flag Mask */
#define SYSCTL_O_VDT2CON_NEGINTFLG_S      9U          /**< VDT2 Negative edge Interrupt Flag Shift */
#define SYSCTL_O_VDT2CON_POSINTFLG_M    0x00000400U   /**< VDT2 Positive edge Interrupt Flag Mask */
#define SYSCTL_O_VDT2CON_POSINTFLG_S      10U         /**< VDT2 Positive edge Interrupt Flag Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFT_RST1 register
//
//*************************************************************************************************
#define SYSCTL_O_SOFTRST1_ADC1RST_M    0x00000001U   /**< ADC1 Reset Mask */
#define SYSCTL_O_SOFTRST1_ADC1RST_S      0U            /**< ADC1 Reset Shift */
#define SYSCTL_O_SOFTRST1_ADC2RST_M    0x00000002U   /**< ADC2 Reset Mask */
#define SYSCTL_O_SOFTRST1_ADC2RST_S      1U            /**< ADC2 Reset Shift */
#define SYSCTL_O_SOFTRST1_ADC3RST_M    0x00000004U   /**< ADC3 Reset Mask */ 
#define SYSCTL_O_SOFTRST1_ADC3RST_S      2U            /**< ADC3 Reset Shift */
#define SYSCTL_O_SOFTRST1_COMP1RST_M    0x00000008U   /**< COMP1 Reset Mask */
#define SYSCTL_O_SOFTRST1_COMP1RST_S      3U            /**< COMP1 Reset Shift */
#define SYSCTL_O_SOFTRST1_CRCRST_M    0x00000010U   /**< CRC Reset Mask */
#define SYSCTL_O_SOFTRST1_CRCRST_S      4U            /**< CRC Reset Shift */
#define SYSCTL_O_SOFTRST1_SPI1RST_M    0x00000020U   /**< SPI1 Reset Mask */
#define SYSCTL_O_SOFTRST1_SPI1RST_S      5U            /**< SPI1 Reset Shift */
#define SYSCTL_O_SOFTRST1_SPI2RST_M    0x00000040U   /**< SPI2 Reset Mask */
#define SYSCTL_O_SOFTRST1_SPI2RST_S      6U            /**< SPI2 Reset Shift */
#define SYSCTL_O_SOFTRST1_SPI3RST_M    0x00000080U   /**< SPI3 Reset Mask */
#define SYSCTL_O_SOFTRST1_SPI3RST_S      7U            /**< SPI3 Reset Shift */
#define SYSCTL_O_SOFTRST1_SPI4RST_M    0x00000100U   /**< SPI4 Reset Mask */
#define SYSCTL_O_SOFTRST1_SPI4RST_S      8U            /**< SPI4 Reset Shift */
#define SYSCTL_O_SOFTRST1_ECAP1RST_M    0x00000200U   /**< ECAP1 Reset Mask */
#define SYSCTL_O_SOFTRST1_ECAP1RST_S      9U            /**< ECAP1 Reset Shift */
#define SYSCTL_O_SOFTRST1_ECAP2RST_M    0x00000400U   /**< ECAP2 Reset Mask */
#define SYSCTL_O_SOFTRST1_ECAP2RST_S      10U           /**< ECAP2 Reset Shift */
#define SYSCTL_O_SOFTRST1_ECAP3RST_M    0x00000800U   /**< ECAP3 Reset Mask */
#define SYSCTL_O_SOFTRST1_ECAP3RST_S      11U           /**< ECAP3 Reset Shift */
#define SYSCTL_O_SOFTRST1_EPWM1RST_M    0x00001000U   /**< EPWM1 Reset Mask */
#define SYSCTL_O_SOFTRST1_EPWM1RST_S      12U           /**< EPWM1 Reset Shift */
#define SYSCTL_O_SOFTRST1_EPWM2RST_M    0x00002000U   /**< EPWM2 Reset Mask */
#define SYSCTL_O_SOFTRST1_EPWM2RST_S      13U           /**< EPWM2 Reset Shift */
#define SYSCTL_O_SOFTRST1_EPWM3RST_M    0x00004000U   /**< EPWM3 Reset Mask */
#define SYSCTL_O_SOFTRST1_EPWM3RST_S      14U           /**< EPWM3 Reset Shift */
#define SYSCTL_O_SOFTRST1_EPWM4RST_M    0x00008000U   /**< EPWM4 Reset Mask */
#define SYSCTL_O_SOFTRST1_EPWM4RST_S      15U           /**< EPWM4 Reset Shift */
#define SYSCTL_O_SOFTRST1_EPWM5RST_M    0x00010000U   /**< EPWM5 Reset Mask */
#define SYSCTL_O_SOFTRST1_EPWM5RST_S      16U           /**< EPWM5 Reset Shift */
#define SYSCTL_O_SOFTRST1_EPWM6RST_M    0x00020000U   /**< EPWM6 Reset Mask */
#define SYSCTL_O_SOFTRST1_EPWM6RST_S      17U           /**< EPWM6 Reset Shift */
#define SYSCTL_O_SOFTRST1_EPWM7RST_M    0x00040000U   /**< EPWM7 Reset Mask */
#define SYSCTL_O_SOFTRST1_EPWM7RST_S      18U           /**< EPWM7 Reset Shift */
#define SYSCTL_O_SOFTRST1_EQEP1RST_M    0x00080000U   /**< EQEP1 Reset Mask */
#define SYSCTL_O_SOFTRST1_EQEP1RST_S      19U           /**< EQEP1 Reset Shift */
#define SYSCTL_O_SOFTRST1_EQEP2RST_M    0x00100000U   /**< EQEP2 Reset Mask */
#define SYSCTL_O_SOFTRST1_EQEP2RST_S      20U           /**< EQEP2 Reset Shift */
#define SYSCTL_O_SOFTRST1_EWMRST_M    0x00200000U   /**< EWM Reset Mask */
#define SYSCTL_O_SOFTRST1_EWMRST_S      21U           /**< EWM Reset Shift */
#define SYSCTL_O_SOFTRST1_I2C1RST_M    0x00800000U   /**< I2C1 Reset Mask */
#define SYSCTL_O_SOFTRST1_I2C1RST_S      23U           /**< I2C1 Reset Shift */
#define SYSCTL_O_SOFTRST1_I2C2RST_M    0x01000000U   /**< I2C2 Reset Mask */
#define SYSCTL_O_SOFTRST1_I2C2RST_S      24U           /**< I2C2 Reset Shift */
#define SYSCTL_O_SOFTRST1_SCI1RST_M    0x02000000U   /**< SCI1 Reset Mask */
#define SYSCTL_O_SOFTRST1_SCI1RST_S      25U           /**< SCI1 Reset Shift */
#define SYSCTL_O_SOFTRST1_SCI2RST_M    0x04000000U   /**< SCI2 Reset Mask */
#define SYSCTL_O_SOFTRST1_SCI2RST_S      26U           /**< SCI2 Reset Shift */
#define SYSCTL_O_SOFTRST1_SCI3RST_M    0x08000000U   /**< SCI3 Reset Mask */
#define SYSCTL_O_SOFTRST1_SCI3RST_S      27U           /**< SCI3 Reset Shift */
#define SYSCTL_O_SOFTRST1_SCI4RST_M    0x10000000U   /**< SCI4 Reset Mask */
#define SYSCTL_O_SOFTRST1_SCI4RST_S      28U           /**< SCI4 Reset Shift */
#define SYSCTL_O_SOFTRST1_SCI5RST_M    0x20000000U   /**< SCI5 Reset Mask */
#define SYSCTL_O_SOFTRST1_SCI5RST_S      29U           /**< SCI5 Reset Shift */
#define SYSCTL_O_SOFTRST1_SCI6RST_M    0x40000000U   /**< SCI6 Reset Mask */
#define SYSCTL_O_SOFTRST1_SCI6RST_S      30U           /**< SCI6 Reset Shift */
#define SYSCTL_O_SOFTRST1_MCAN1RST_M    0x80000000U   /**< MCAN1 Reset Mask */
#define SYSCTL_O_SOFTRST1_MCAN1RST_S      31U           /**< MCAN1 Reset Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFT_RST2 register
//
//*************************************************************************************************
#define SYSCTL_O_SOFTRST2_MCAN2RST_M    0x00000001U   /**< MCAN2 Reset Mask */  
#define SYSCTL_O_SOFTRST2_MCAN2RST_S      0U           /**< MCAN2 Reset Shift */
#define SYSCTL_O_SOFTRST2_PTIMRST_M    0x00000002U   /**< PTIM Reset Mask */
#define SYSCTL_O_SOFTRST2_PTIMRST_S      1U           /**< PTIM Reset Shift */
#define SYSCTL_O_SOFTRST2_SDFM1RST_M    0x00000008U   /**< SDFM1 Reset Mask */
#define SYSCTL_O_SOFTRST2_SDFM1RST_S      3U           /**< SDFM1 Reset Shift */
#define SYSCTL_O_SOFTRST2_SDFM2RST_M    0x00000010U   /**< SDFM2 Reset Mask */
#define SYSCTL_O_SOFTRST2_SDFM2RST_S      4U           /**< SDFM2 Reset Shift */
#define SYSCTL_O_SOFTRST2_XBARRST_M    0x00000020U   /**< XBAR Reset Mask */
#define SYSCTL_O_SOFTRST2_XBARRST_S      5U           /**< XBAR Reset Shift */
#define SYSCTL_O_SOFTRST2_XINTRST_M    0x00000040U   /**< XINT Reset Mask */
#define SYSCTL_O_SOFTRST2_XINTRST_S      6U           /**< XINT Reset Shift */
#define SYSCTL_O_SOFTRST2_GPIOARST_M    0x00000100U   /**< GPIOA Reset Mask */
#define SYSCTL_O_SOFTRST2_GPIOARST_S      8U           /**< GPIOA Reset Shift */
#define SYSCTL_O_SOFTRST2_GPIOBRST_M    0x00000200U   /**< GPIOB Reset Mask */
#define SYSCTL_O_SOFTRST2_GPIOBRST_S      9U           /**< GPIOB Reset Shift */
#define SYSCTL_O_SOFTRST2_GPIOCRST_M    0x00000400U   /**< GPIOC Reset Mask */
#define SYSCTL_O_SOFTRST2_GPIOCRST_S      10U          /**< GPIOC Reset Shift */
#define SYSCTL_O_SOFTRST2_LPTIMRST_M    0x00000800U   /**< LPTIM Reset Mask */
#define SYSCTL_O_SOFTRST2_LPTIMRST_S      11U          /**< LPTIM Reset Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the TDTALARM register
//
//*************************************************************************************************
#define SYSCTL_O_TDTALARM_TDEN_M         0x00000001U   /**< Temperature Alarm Enable Mask */
#define SYSCTL_O_TDTALARM_TDEN_S          0U           /**< Temperature Alarm Enable Shift */
#define SYSCTL_O_TDTALARM_TSTEN_M        0x00000004U   /**< Temperature Sensor Self Test Enable Mask */
#define SYSCTL_O_TDTALARM_TSTEN_S         2U           /**< Temperature Sensor Self Test Enable Shift */
#define SYSCTL_O_TDTALARM_TSTIN_M        0x00000008U   /**< Temperature Sensor Self Test Input Mask */
#define SYSCTL_O_TDTALARM_TSTIN_S         3U           /**< Temperature Sensor Self Test Input Shift */
#define SYSCTL_O_TDTALARM_HTREIE_M       0x0000010U    /**< High Temperature Alarm, Rise Edge Interrupt Enable Mask */
#define SYSCTL_O_TDTALARM_HTREIE_S        4U           /**< High Temperature Alarm, Rise Edge Interrupt Enable Shift */
#define SYSCTL_O_TDTALARM_HTFEIE_M       0x0000020U    /**< High Temperature Alarm, Fall Edge Interrupt Enable Mask */
#define SYSCTL_O_TDTALARM_HTFEIE_S        5U           /**< High Temperature Alarm, Fall Edge Interrupt Enable Shift */
#define SYSCTL_O_TDTALARM_LTREIE_M       0x0000040U    /**< Low Temperature Alarm, Rise Edge Interrupt Enable Mask */
#define SYSCTL_O_TDTALARM_LTREIE_S        6U           /**< Low Temperature Alarm, Rise Edge Interrupt Enable Shift */
#define SYSCTL_O_TDTALARM_LTFEIE_M       0x0000080U    /**< Low Temperature Alarm, Fall Edge Interrupt Enable Mask */
#define SYSCTL_O_TDTALARM_LTFEIE_S        7U           /**< Low Temperature Alarm, Fall Edge Interrupt Enable Shift */
#define SYSCTL_O_TDTALARM_ASALTIE_M      0x00000100U   /**< Async Low Temperature Interrupt Enable Mask */
#define SYSCTL_O_TDTALARM_ASALTIE_S       8U           /**< Async Low Temperature Interrupt Enable Shift */
#define SYSCTL_O_TDTALARM_ASHTIE_M       0x00000200U   /**< Async High Temperature Interrupt Enable Mask */
#define SYSCTL_O_TDTALARM_ASHTIE_S        9U           /**< Async High Temperature Interrupt Enable Shift */
#define SYSCTL_O_TDTALARM_ALARML_STS_M   0x00000400U   /**< Low Temperature Alarm Status Mask */
#define SYSCTL_O_TDTALARM_ALARML_STS_S    10U          /**< Low Temperature Alarm Status Shift */
#define SYSCTL_O_TDTALARM_ALARMH_STS_M   0x00000800U   /**< High Temperature Alarm Status Mask */
#define SYSCTL_O_TDTALARM_ALARMH_STS_S    11U          /**< High Temperature Alarm Status Shift */


//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCOUTSEL register
//
//*************************************************************************************************
#define SYSCTL_O_ADCSOCOUTSEL_PWM1SOCAEN_M 0x00000001U   /**< PWM1 SOCA Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM1SOCAEN_S    0U           /**< PWM1 SOCA Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM2SOCAEN_M 0x00000002U   /**< PWM2 SOCA Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM2SOCAEN_S    1U           /**< PWM2 SOCA Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM3SOCAEN_M 0x00000004U   /**< PWM3 SOCA Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM3SOCAEN_S    2U           /**< PWM3 SOCA Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM4SOCAEN_M 0x00000008U   /**< PWM4 SOCA Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM4SOCAEN_S    3U           /**< PWM4 SOCA Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM5SOCAEN_M 0x00000010U   /**< PWM5 SOCA Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM5SOCAEN_S    4U           /**< PWM5 SOCA Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM6SOCAEN_M 0x00000020U   /**< PWM6 SOCA Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM6SOCAEN_S    5U           /**< PWM6 SOCA Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM7SOCAEN_M 0x00000040U   /**< PWM7 SOCA Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM7SOCAEN_S    6U           /**< PWM7 SOCA Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM1SOCBEN_M 0x00000100U   /**< PWM1 SOCB Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM1SOCBEN_S    8U           /**< PWM1 SOCB Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM2SOCBEN_M 0x00000200U   /**< PWM2 SOCB Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM2SOCBEN_S    9U           /**< PWM2 SOCB Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM3SOCBEN_M 0x00000400U   /**< PWM3 SOCB Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM3SOCBEN_S   10U          /**< PWM3 SOCB Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM4SOCBEN_M 0x00000800U   /**< PWM4 SOCB Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM4SOCBEN_S   11U          /**< PWM4 SOCB Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM5SOCBEN_M 0x00001000U   /**< PWM5 SOCB Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM5SOCBEN_S   12U          /**< PWM5 SOCB Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM6SOCBEN_M 0x00002000U   /**< PWM6 SOCB Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM6SOCBEN_S   13U          /**< PWM6 SOCB Output Enable Shift */
#define SYSCTL_O_ADCSOCOUTSEL_PWM7SOCBEN_M 0x00004000U   /**< PWM7 SOCB Output Enable Mask */
#define SYSCTL_O_ADCSOCOUTSEL_PWM7SOCBEN_S   14U          /**< PWM7 SOCB Output Enable Shift */

//*************************************************************************************************
//
// The following are defines for the bit fields in the TBCLKSYNC register
//
//*************************************************************************************************
#define SYSCTL_TBCLKSYNC_TBCLKSYNC_M 0x00000001U   /**< PWM1 Clock Sync Mask */
#define SYSCTL_TBCLKSYNC_TBCLKSYNC_S    0U           /**< PWM1 Clock Sync Shift */


//*************************************************************************************************
//
// The following are defines for the RCM register offsets
//
//*************************************************************************************************
#define RCM_O_SRS0         0x0U         /**< System reset status Register */
#define RCM_O_SRS1         0x1U         /**< System reset status Register */
#define RCM_O_RPFC         0x2U         /**< Reset pin filter control Register */
#define RCM_O_RPFW         0x3U         /**< Reset pin filter width Register */

//*************************************************************************************************
//
// The following are defines for the bit fields in the SRS0 register
//
//*************************************************************************************************



#endif
