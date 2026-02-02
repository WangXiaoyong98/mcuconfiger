/*
  ******************************************************************************
  * @file           : device.h
  * @brief          : device function header file
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

#ifndef __DEVICE_H__
#define __DEVICE_H__

#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//
#include "driverlib.h"


//*****************************************************************************
//
// Defines for pin numbers
//
//*****************************************************************************


//
// SP28038 EVB
//

//
// LEDs
//
#define DEVICE_GPIO_PIN_LED1        8U              // GPIO number for LED1
#define DEVICE_GPIO_PIN_LED2        12U             // GPIO number for LED2
#define DEVICE_GPIO_PIN_LED3        16U             // GPIO number for LED2
#define DEVICE_GPIO_PIN_LED4        17U             // GPIO number for LED2
#define DEVICE_GPIO_PIN_LED5        25U             // GPIO number for LED2
#define DEVICE_GPIO_PIN_LED6        40U             // GPIO number for LED2
#define DEVICE_GPIO_CFG_LED1        GPIO_8_GPIO8    // "pinConfig" for LED1
#define DEVICE_GPIO_CFG_LED2        GPIO_12_GPIO12  // "pinConfig" for LED2
#define DEVICE_GPIO_CFG_LED3        GPIO_16_GPIO16  // "pinConfig" for LED2
#define DEVICE_GPIO_CFG_LED4        GPIO_17_GPIO17  // "pinConfig" for LED2
#define DEVICE_GPIO_CFG_LED5        GPIO_25_GPIO25  // "pinConfig" for LED2
#define DEVICE_GPIO_CFG_LED6        GPIO_40_GPIO40  // "pinConfig" for LED2

//
// CANA
//
#define DEVICE_GPIO_PIN_CANRXA      30U              // GPIO number for CANRXA
#define DEVICE_GPIO_PIN_CANTXA      31U              // GPIO number for CANTXA
#define DEVICE_GPIO_CFG_CANRXA      GPIO_30_CANA_RX  // "pinConfig" for CANA RX
#define DEVICE_GPIO_CFG_CANTXA      GPIO_31_CANA_TX  // "pinConfig" for CANA TX

#define DEVICE_GPIO_PIN_CANTXB      42U              // GPIO number for CANTXA
#define DEVICE_GPIO_PIN_CANRXB      43U              // GPIO number for CANRXA
#define DEVICE_GPIO_CFG_CANRXB      GPIO_43_CANA_RX  // "pinConfig" for CANA RX
#define DEVICE_GPIO_CFG_CANTXB      GPIO_42_CANA_TX  // "pinConfig" for CANA TX

//
// SCI for USB-to-UART adapter on FTDI chip
//
#define DEVICE_GPIO_PIN_SCIRXDA     7U              // GPIO number for SCI RX
#define DEVICE_GPIO_PIN_SCITXDA     9U              // GPIO number for SCI TX
#define DEVICE_GPIO_CFG_SCIRXDA     GPIO_7_SCIA_RX  // "pinConfig" for SCI RX
#define DEVICE_GPIO_CFG_SCITXDA     GPIO_9_SCIA_TX  // "pinConfig" for SCI TX

//
// LINA
//
#define DEVICE_GPIO_PIN_LINTXA      22U             // GPIO number for LINA TX
#define DEVICE_GPIO_PIN_LINRXA      23U             // GPIO number for LINA RX
#define DEVICE_GPIO_CFG_LINTXA      GPIO_22_LINA_TX  // "pinConfig" for LINA TX
#define DEVICE_GPIO_CFG_LINRXA      GPIO_23_LINA_RX  // "pinConfig" for LINA RX


//
// I2C
//
#define DEVICE_GPIO_PIN_SDAA        32U  // GPIO number for I2C SDAA
#define DEVICE_GPIO_PIN_SCLA        33U  // GPIO number for I2C SCLA
#define DEVICE_GPIO_CFG_SDAA        GPIO_32_I2CA_SDA  // "pinConfig" for I2C SDAA
#define DEVICE_GPIO_CFG_SCLA        GPIO_33_I2CA_SCL  // "pinConfig" for I2C SCLA

//I2CB GPIO pins
#define DEVICE_GPIO_PIN_SDAB    28
#define DEVICE_GPIO_PIN_SCLB    29
#define DEVICE_GPIO_CFG_SDAB        GPIO_28_I2CB_SDA
#define DEVICE_GPIO_CFG_SCLB        GPIO_29_I2CB_SCL



//*****************************************************************************
//
// Defines related to clock configuration
//
//*****************************************************************************

//
// To use INTOSC as the clock source, comment the #define USE_PLL_SRC_XTAL,
// and uncomment the #define USE_PLL_SRC_INTOSC
//
//#define USE_PLL_SRC_XTAL
#define USE_PLL_SRC_INTOSC


#if defined(USE_PLL_SRC_XTAL)
//
// 16MHz XTAL on controlCARD is used as the PLL source.
// For use with SysCtl_getClock().
//
#define DEVICE_OSCSRC_FREQ          16000000U

//
// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = 16MHz (XTAL_OSC) * 70 (IMULT) / (2 (REFDIV) * 2 (ODIV) * 2(SYSDIV))
//
#define DEVICE_SETCLOCK_CFG          (SYSCTL_OSCSRC_XTAL | SYSCTL_IMULT(70) | \
                                      SYSCTL_REFDIV(2) | SYSCTL_ODIV(1) | \
                                      SYSCTL_SYSDIV(1) | SYSCTL_PLL_ENABLE | \
                                      SYSCTL_DCC_BASE_0)

//
// 140MHz SYSCLK frequency based on the above DEVICE_SETCLOCK_CFG. Update the
// code below if a different clock configuration is used!
//
#define DEVICE_SYSCLK_FREQ          140000000                 //((DEVICE_OSCSRC_FREQ * 70) / (2 * 2 * 2))

#elif defined(USE_PLL_SRC_INTOSC)
//
// 8MHz INTOSC on the device is used as the PLL source.
// For use with SysCtl_getClock().
//
#define DEVICE_OSCSRC_FREQ          8000000U

//
// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = 8MHz (INT_OSC) * 140 (IMULT) / (2 (REFDIV) * 3 (ODIV) * 1(SYSDIV))
//
#define DEVICE_SETCLOCK_CFG          (SYSCTL_OSCSRC_OSC1 | SYSCTL_IMULT(140) | \
                                      SYSCTL_REFDIV(2) | SYSCTL_ODIV(1) | \
                                      SYSCTL_SYSDIV(2) | SYSCTL_PLL_ENABLE | \
                                      SYSCTL_DCC_BASE_0)

//
// 140MHz SYSCLK frequency based on the above DEVICE_SETCLOCK_CFG. Update the
// code below if a different clock configuration is used!
//
#define DEVICE_SYSCLK_FREQ          ((DEVICE_OSCSRC_FREQ * 140) / (2 * 2 * 2))
#endif
#define CPU_FRQ_140MHZ   140000000

//*****************************************************************************
//
// Macro to call SysCtl_delay() to achieve a delay in microseconds. The macro
// will convert the desired delay in microseconds to the count value expected
// by the function. \b x is the number of microseconds to delay.
// 
//*****************************************************************************
//SysCtl_delay is assembly code in sysctl.c
#define DEVICE_DELAY_US(x) SysCtl_delay(((((long double)(x)) / (1000000.0L /  \
                              (long double)DEVICE_SYSCLK_FREQ)) - 9.0L) / 5.0L)


//*****************************************************************************
//
// Defines, Globals, and Header Includes related to Flash Support
//
//*****************************************************************************
#ifdef _FLASH
#include <stddef.h>

#ifndef CMDTOOL
extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadEnd;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
extern uint16_t RamfuncsRunEnd;
extern uint16_t RamfuncsRunSize;
#endif

#endif

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup device_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! @brief Function to initialize the device. Primarily initializes system
//!  control to aknown state by disabling the watchdog, setting up the
//!  SYSCLKOUT frequency, and enabling the clocks to the peripherals.
//!
//! \param None.
//! \return None.
//
//*****************************************************************************
extern void Device_init(void);

//*****************************************************************************
//
//!
//! @brief Function to verify the XTAL frequency
//! \param freq is the XTAL frequency in MHz
//! \return The function return true if the the actual XTAL frequency matches with the
//! input value
//
//*****************************************************************************
extern bool Device_verifyXTAL(float freq);

//*****************************************************************************
//!
//!
//! @brief Function to turn on all peripherals, enabling reads and writes to the
//! peripherals' registers.
//!
//! Note that to reduce power, unused peripherals should be disabled.
//!
//! @param None
//! @return None
//
//*****************************************************************************
extern void Device_enableAllPeripherals(void);
//*****************************************************************************
//!
//!
//! @brief Function to disable pin locks on GPIOs.
//!
//! @param None
//! @return None
//
//*****************************************************************************
extern void Device_initGPIO(void);

//*****************************************************************************
//!
//! @brief Error handling function to be called when an ASSERT is violated
//!
//! @param *filename File name in which the error has occurred
//! @param line Line number within the file
//! @return None
//
//*****************************************************************************
extern void __error__(const char *filename, uint32_t line);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#ifdef __cplusplus
}
#endif

#endif // __DEVICE_H__
