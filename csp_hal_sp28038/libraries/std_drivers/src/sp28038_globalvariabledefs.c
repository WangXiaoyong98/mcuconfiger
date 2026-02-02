/*
  ******************************************************************************
  * @file    sp28038_globalvariabledefs.c
  * @brief   Peripherals register structure defination.
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

//
// Included Files
//
#include "SP28038_Device.h"     // SP28038 Headerfile Include File


//
// Define Global Peripheral Variables - 
//
volatile struct AES_REGS AesRegs  __attribute__((section(".bss.ARM.__at_"AES_REGS_ADDR)));

volatile struct CRC_REGS CrcRegs  __attribute__((section(".bss.ARM.__at_"CRC_REGS_ADDR)));

volatile struct ADC_REGS Adc1Regs  __attribute__((section(".bss.ARM.__at_"ADC1_REGS_ADDR)));

volatile struct ADC_REGS Adc2Regs  __attribute__((section(".bss.ARM.__at_"ADC2_REGS_ADDR)));

volatile struct ADC_REGS Adc3Regs  __attribute__((section(".bss.ARM.__at_"ADC3_REGS_ADDR)));

volatile struct ADC_RESULT_REGS Adc1Result  __attribute__((section(".bss.ARM.__at_"ADC1_RSEULT_REGS_ADDR)));

volatile struct ADC_RESULT_REGS Adc2Result  __attribute__((section(".bss.ARM.__at_"ADC2_RSEULT_REGS_ADDR)));

volatile struct ADC_RESULT_REGS Adc3Result  __attribute__((section(".bss.ARM.__at_"ADC3_RSEULT_REGS_ADDR)));

//volatile struct COMP1_REGS Comp1Regs  __attribute__((section(".bss.ARM.__at_"COMP1_REGS_ADDR)));

volatile struct PTIMR_REGS PtimRegs __attribute__((section(".bss.ARM.__at_"PTIM_REGS_ADDR)));

volatile struct LPTIMR_REGS LptimRegs __attribute__((section(".bss.ARM.__at_"LPTIM_REGS_ADDR)));

volatile struct MCAN_REGS MCanaRegs __attribute__((section(".bss.ARM.__at_"MCAN1_REGS_ADDR)));

volatile struct MCAN_REGS MCanbRegs __attribute__((section(".bss.ARM.__at_"MCAN2_REGS_ADDR)));

volatile struct EPWM_REGS EPwm1Regs  __attribute__((section(".bss.ARM.__at_"EPWM1_REGS_ADDR)));

volatile struct EPWM_REGS EPwm2Regs __attribute__((section(".bss.ARM.__at_"EPWM2_REGS_ADDR)));

volatile struct EPWM_REGS EPwm3Regs __attribute__((section(".bss.ARM.__at_"EPWM3_REGS_ADDR)));

volatile struct EPWM_REGS EPwm4Regs __attribute__((section(".bss.ARM.__at_"EPWM4_REGS_ADDR)));

volatile struct EPWM_REGS EPwm5Regs __attribute__((section(".bss.ARM.__at_"EPWM5_REGS_ADDR)));

volatile struct EPWM_REGS EPwm6Regs __attribute__((section(".bss.ARM.__at_"EPWM6_REGS_ADDR)));

volatile struct EPWM_REGS EPwm7Regs __attribute__((section(".bss.ARM.__at_"EPWM7_REGS_ADDR)));

volatile struct WD_REGS WdRegs  __attribute__((section(".bss.ARM.__at_"WWD_REGS_ADDR)));

volatile struct EWM_REGS EwmRegs  __attribute__((section(".bss.ARM.__at_"EWM_REGS_ADDR)));

volatile struct ECAP_REGS ECap1Regs __attribute__((section(".bss.ARM.__at_"ECAP1_REGS_ADDR)));

volatile struct ECAP_REGS ECap2Regs __attribute__((section(".bss.ARM.__at_"ECAP2_REGS_ADDR)));

volatile struct ECAP_REGS ECap3Regs __attribute__((section(".bss.ARM.__at_"ECAP3_REGS_ADDR)));

volatile struct EQEP_REGS EQep1Regs __attribute__((section(".bss.ARM.__at_"EQEP1_REGS_ADDR)));

volatile struct EQEP_REGS EQep2Regs __attribute__((section(".bss.ARM.__at_"EQEP2_REGS_ADDR)));

volatile struct PORT_REGS PortARegs __attribute__((section(".bss.ARM.__at_"PORTA_REGS_ADDR)));

volatile struct PORT_REGS PortBRegs __attribute__((section(".bss.ARM.__at_"PORTB_REGS_ADDR)));

volatile struct GPIO_REGS GPIOARegs __attribute__((section(".bss.ARM.__at_"GPIOA_REGS_ADDR)));

volatile struct GPIO_REGS GPIOBRegs __attribute__((section(".bss.ARM.__at_"GPIOB_REGS_ADDR)));

volatile struct EPWM_XBAR_REGS EPwmXbarRegs __attribute__((section(".bss.ARM.__at_"EPWMXBAR_REGS_ADDR)));

volatile struct INPUT_XBAR_REGS InputXbarRegs __attribute__((section(".bss.ARM.__at_"INPUTXBAR_REGS_ADDR)));

volatile struct OUTPUT_XBAR_REGS OutputXbarRegs __attribute__((section(".bss.ARM.__at_"OUTPUTXBAR_REGS_ADDR)));

volatile struct XBAR_REGS XbarRegs __attribute__((section(".bss.ARM.__at_"XBAR_REGS_ADDR)));

volatile struct DMA_REGS DmaRegs  __attribute__((section(".bss.ARM.__at_"DMA_REGS_ADDR)));

volatile struct DMAMUX_REGS DmamuxRegs  __attribute__((section(".bss.ARM.__at_"DMAMUX_REGS_ADDR)));

volatile struct I2C_REGS I2c1Regs __attribute__((section(".bss.ARM.__at_"I2C1_REGS_ADDR)));

volatile struct I2C_REGS I2c2Regs __attribute__((section(".bss.ARM.__at_"I2C2_REGS_ADDR)));

volatile struct SCI_REGS Sci1Regs __attribute__((section(".bss.ARM.__at_"SCI1_REGS_ADDR)));
#define Sci1Regs SciaRegs

volatile struct SCI_REGS Sci2Regs __attribute__((section(".bss.ARM.__at_"SCI2_REGS_ADDR)));
#define Sci2Regs ScibRegs

volatile struct SCI_REGS Sci3Regs __attribute__((section(".bss.ARM.__at_"SCI3_REGS_ADDR)));
#define Sci3Regs ScicRegs

volatile struct SCI_REGS Sci4Regs __attribute__((section(".bss.ARM.__at_"SCI4_REGS_ADDR)));
#define Sci4Regs ScidRegs

volatile struct SCI_REGS Sci5Regs __attribute__((section(".bss.ARM.__at_"SCI5_REGS_ADDR)));
#define Sci5Regs ScieRegs

volatile struct SCI_REGS Sci6Regs __attribute__((section(".bss.ARM.__at_"SCI6_REGS_ADDR)));
#define Sci5Regs ScieRegs

volatile struct SPI_REGS Spi1Regs __attribute__((section(".bss.ARM.__at_"SPI1_REGS_ADDR)));
volatile struct SPI_REGS Spi2Regs __attribute__((section(".bss.ARM.__at_"SPI2_REGS_ADDR)));
volatile struct SPI_REGS Spi3Regs __attribute__((section(".bss.ARM.__at_"SPI3_REGS_ADDR)));
volatile struct SPI_REGS Spi4Regs __attribute__((section(".bss.ARM.__at_"SPI4_REGS_ADDR)));

volatile struct SYSCTRL_REGS SysCtrlRegs __attribute__((section(".bss.ARM.__at_"SYSCTRL_REGS_ADDR)));

volatile struct FLASH_REGS FlashRegs __attribute__((section(".bss.ARM.__at_"FLASH_REGS_ADDR)));

volatile struct XINT_REGS XintRegs __attribute__((section(".bss.ARM.__at_"XINT_REGS_ADDR)));

void (*Flash_CallbackPtr) (void);

//
// End of file
//

