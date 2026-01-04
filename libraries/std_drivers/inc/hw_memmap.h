/*
  ******************************************************************************
  * @file           : hw_memmap.h
  * @brief          : memory map register map
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

#ifndef HW_MEMMAP_H
#define HW_MEMMAP_H

#include "sp28038.h"
//*****************************************************************************
//
// The following are defines for the base address of the memories and
// peripherals.
//
//*****************************************************************************
#define AES_REGS_ADDR              "0x40031000U" 
#define CRC_REGS_ADDR              "0x40032000U" 
#define ADC1_RSEULT_REGS_ADDR      "0x4003B000U" 
#define ADC2_RSEULT_REGS_ADDR      "0x4003C000U" 
#define ADC3_RSEULT_REGS_ADDR      "0x400BB000U" 
#define ADC1_REGS_ADDR             "0x4003B050U" 
#define ADC2_REGS_ADDR             "0x4003C050U" 
#define ADC3_REGS_ADDR             "0x400BB050U" 
#define COMP1_REGS_ADDR            "0x400BA000U" 
#define PTIM_REGS_ADDR             "0x40037000U"
#define LPTIM_REGS_ADDR            "0x40022000U"
#define MCAN1_REGS_ADDR            "0x40024000U" 
#define MCAN2_REGS_ADDR            "0x400A4000U" 
#define EPWM1_REGS_ADDR            "0x40038000U"
#define EPWM2_REGS_ADDR            "0x40039000U"
#define EPWM3_REGS_ADDR            "0x4003A000U"
#define EPWM4_REGS_ADDR            "0x400B0000U"
#define EPWM5_REGS_ADDR            "0x400B1000U"
#define EPWM6_REGS_ADDR            "0x400B2000U"
#define EPWM7_REGS_ADDR            "0x400B3000U"
#define WWD_REGS_ADDR              "0x40052000U" 
#define EWM_REGS_ADDR              "0x40061000U" 
#define ECAP1_REGS_ADDR            "0x40058000U"
#define ECAP2_REGS_ADDR            "0x40059000U"
#define ECAP3_REGS_ADDR            "0x400C9000U"
#define EQEP1_REGS_ADDR            "0x40040000U"
#define EQEP2_REGS_ADDR            "0x400A6000U"
#define I2C1_REGS_ADDR             "0x40066000U"
#define I2C2_REGS_ADDR             "0x40067000U"
#define SCI1_REGS_ADDR             "0x400C4000U"
#define SCI2_REGS_ADDR             "0x400C5000U"
#define SCI3_REGS_ADDR             "0x400C6000U"
#define SCI4_REGS_ADDR             "0x4006A000U"
#define SCI5_REGS_ADDR             "0x4006B000U"
#define SCI6_REGS_ADDR             "0x4006C000U"
#define SYSCTRL_REGS_ADDR          "0x40048000U"
#define XINT_REGS_ADDR             "0x4002E000U"
#define PORTA_REGS_ADDR            "0x40049000U"
#define PORTB_REGS_ADDR            "0x4004A000U"
#define GPIOA_REGS_ADDR            "0x400FF000U"
#define GPIOB_REGS_ADDR            "0x400FF040U"
#define FLASH_REGS_ADDR            "0x40020000U"
#define DMAMUX_REGS_ADDR           "0x40021000U"
#define DMA_REGS_ADDR              "0x40008000U"
#define INPUTXBAR_REGS_ADDR        "0x40028000U"
#define XBAR_REGS_ADDR             "0x40028044U"
#define EPWMXBAR_REGS_ADDR         "0x40028064U"
#define OUTPUTXBAR_REGS_ADDR       "0x400280CCU"
#define SPI1_REGS_ADDR             "0x4002C000U"
#define SPI2_REGS_ADDR             "0x4002D000U"
#define SPI3_REGS_ADDR             "0x400AC000U"
#define SPI4_REGS_ADDR             "0x400AD000U"
#define RCM_REGS_ADDR              "0x4007F000U"
#define DCC1_REGS_ADDR             "0x40023000U"
#define DCC2_REGS_ADDR             "0x400A3000U"

//Defined in sp28038.h already
#if 0
#define CRC_BASE              0x40032000U 
#define ADC1_RSEULT_BASE      0x4003B000U 
#define ADC2_RSEULT_BASE      0x4003C000U 
#define ADC3_RSEULT_BASE      0x400BB000U 
#define ADC1_BASE             0x4003B050U 
#define ADC2_BASE             0x4003C050U 
#define ADC3_BASE             0x400BB050U 
#define COMP1_BASE            0x400BA000U 
#define PTIM_BASE             0x40037000U
#define LPTIM_BASE            0x40022000U
#define MCAN1_BASE            0x40024000U 
#define MCAN2_BASE            0x400A4000U 
#define EPWM1_BASE            0x40038000U
#define EPWM2_BASE            0x40039000U
#define EPWM3_BASE            0x4003A000U
#define EPWM4_BASE            0x400B0000U
#define EPWM5_BASE            0x400B1000U
#define EPWM6_BASE            0x400B2000U
#define EPWM7_BASE            0x400B3000U
#define WWD_BASE              0x40052000U 
#define EWM_BASE              0x40061000U 
#define ECAP1_BASE            0x40058000U
#define ECAP2_BASE            0x40059000U
#define ECAP3_BASE            0x400C9000U
#define EQEP1_BASE            0x40040000U
#define EQEP2_BASE            0x400A6000U
#define I2C1_BASE             0x40066000U
#define I2C2_BASE             0x40067000U
#define SCI1_BASE             0x400C4000U
#define SCI2_BASE             0x400C5000U
#define SCI3_BASE             0x400C6000U
#define SCI4_BASE             0x4006A000U
#define SCI5_BASE             0x4006B000U
#define SCI6_BASE             0x4006C000U
#define SYSCTRL_BASE          0x40048000U
#define XINT_BASE             0x4002E000U
#define PORTA_BASE            0x40049000U
#define PORTB_BASE            0x4004A000U
#define GPIOA_BASE            0x400FF000U
#define GPIOB_BASE            0x400FF040U
#define FLASH_BASE            0x40020000U
#define DMAMUX_BASE           0x40021000U
#define DMA_BASE              0x40008000U
#define INPUTXBAR_BASE        0x40028000U
#define XBAR_BASE             0x40028044U
#define EPWMXBAR_BASE         0x40028064U
#define OUTPUTXBAR_BASE       0x400280CCU
#endif

#define FLASH0ECC_BASE        0x4004809CU

#endif   /* HW_MEMMAP_H */