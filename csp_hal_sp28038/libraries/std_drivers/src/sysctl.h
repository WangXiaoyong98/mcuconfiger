/*
  ******************************************************************************
  * @file           : sysctl.h
  * @brief          : Sysctrl register definitions for hardware access
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

#ifndef SYSCTL_H
#define SYSCTL_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup sysctl_api SysCtl
//! @{
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
//#include "inc/hw_wwd.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "debug.h"


//
// Macro used for adding delay between 2 consecutive writes to CLKSRCCTL1
// register.
// Delay = 300 NOPs
//
#define SYSCTL_CLKSRCCTL_DELAY 

//
// Macro used for adding delay between 2 consecutive writes to memory mapped 
// register in System control
// Total delay = 3 * (DEVICE_SYSCLK_FREQ / INTOSC1 Freq) + 9
//
#define SYSCTL_REGWRITE_DELAY

//*****************************************************************************
//
// Defines for system control functions. Not intended for use by application
// code.
//
//*****************************************************************************

//
// Keys for WDKEY field. The first enables resets and the second resets.
//
#define SYSCTL_WD_ENRSTKEY      0xA602U
#define SYSCTL_WD_RSTKEY        0xB480U


//
//Keys for the System control registers write protection
//
#define SYSCTL_REG_KEY       0x00005A5AU
#define SYSCTL_PLL_KEY       0U

//
//Values to help access shifting of bits
//
#define SYSCTL_TYPE_LOCK_S              0xFU



//
// Default internal oscillator frequency, 8 MHz
//
#define SYSCTL_DEFAULT_OSC_FREQ     8000000U



//*****************************************************************************
//
// The following are values that can be passed to the SysCtl_setClock() API as
// the config parameter.
//
//*****************************************************************************
#define SYSCTL_DCC_BASE_0       0x00000000UL //!< DCC0 module
#define SYSCTL_DCC_BASE_1       0x10000000UL //!< DCC1 module

//
// System clock divider (PLLDIV)
//

#define SYSCTL_SYSDIV_M     0x00000F00UL // Mask for PLLDIV value in config
#define SYSCTL_SYSDIV_S     8U           // Shift for PLLDIV  value in config
//
// Mask and shift for Reference Clock Divider value in config
//
#define SYSCTL_REFDIV_M      0x00007C0000UL // Mask for Reference Clock Divider
#define SYSCTL_REFDIV_S      18U          // Shift for Reference Clock Divider

//
// Mask and shift for Output Clock Divider value in config
//
#define SYSCTL_ODIV_M        0x01800000UL
#define SYSCTL_ODIV_S        23U

//!
//! Macro to format Clock divider value. x is a number from 1 to 32.
//!
#define SYSCTL_REFDIV(x)     ((((uint32_t)(x)) << SYSCTL_REFDIV_S) &      \
                                  SYSCTL_REFDIV_M)

//!
//! Macro to format Clock divider value. x is a number from 1 to 32.
//!
#define SYSCTL_ODIV(x)       ((((uint32_t)(x)) << SYSCTL_ODIV_S) &        \
                                  SYSCTL_ODIV_M)



//! Macro to format system clock divider value. x must be values from 1 to 126.
#define SYSCTL_SYSDIV(x)    ((((uint32_t)(x) - 1U) << SYSCTL_SYSDIV_S) &        \
                                  SYSCTL_SYSDIV_M)

//
// Integer multiplier (IMULT)
//
//
// Mask for IMULT value in config
//
#define SYSCTL_IMULT_M      0x000000FFUL
#define SYSCTL_IMULT_S      0U           // Shift for IMULT value in config
//! Macro to format integer multiplier value. x is a number from 1 to 127.
//!
#define SYSCTL_IMULT(x)     (((x) << SYSCTL_IMULT_S) & SYSCTL_IMULT_M)

#ifndef DOXYGEN_PDF_IGNORE

//
// Oscillator source
//
// Also used with the SysCtl_selectOscSource(), SysCtl_turnOnOsc(),
// and SysCtl_turnOffOsc() functions as the oscSource parameter.
//
#define SYSCTL_OSCSRC_M         0x0030000UL // Mask for OSCSRC value in config
#define SYSCTL_OSCSRC_S         16U          // Shift for OSCSRC value in config
//! External oscillator (XTAL) in crystal mode
#define SYSCTL_OSCSRC_XTAL      0x0010000U
//! External oscillator (XTAL) in single-ended mode
#define SYSCTL_OSCSRC_XTAL_SE   0x0030000U
//! Internal oscillator INTOSC1
#define SYSCTL_OSCSRC_OSC1      0x00020000UL
//! Internal oscillator INTOSC30K
#define SYSCTL_OSCSRC_30K       0x00040000UL

//
// Enable/disable PLL
//
#define SYSCTL_PLL_ENABLE       0x80000000U //!< Enable PLL in POWERCFG register
#define SYSCTL_PLL_DISABLE      0x00000000U //!< Disable PLL in POWERCFG register
#define SYSCTL_PLL_BYPASS       0x40000000U //!< Bypass PLL in PLLCFG register

//
// Number of PLL retries for SW work around
//
#define SYSCTL_PLL_RETRIES              100U    // Number of PLL retries
#define SYSCTL_PLLLOCK_TIMEOUT          2000U   // PLL Lock timeout

//*****************************************************************************
//
// The following values define the adcsocSrc parameter for
// SysCtl_enableExtADCSOCSource() and SysCtl_disableExtADCSOCSource().
//
//*****************************************************************************
#define SYSCTL_ADCSOC_SRC_PWM1SOCA   0x1U //!<ePWM1 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM2SOCA   0x2U //!<ePWM2 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM3SOCA   0x4U //!<ePWM3 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM4SOCA   0x8U //!<ePWM4 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM5SOCA   0x10U //!<ePWM5 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM6SOCA   0x20U //!<ePWM6 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM7SOCA   0x40U //!<ePWM7 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM8SOCA   0x80U //!<ePWM8 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM1SOCB   0x10000U //!<ePWM1 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM2SOCB   0x20000U //!<ePWM2 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM3SOCB   0x40000U //!<ePWM3 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM4SOCB   0x80000U //!<ePWM4 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM5SOCB   0x100000U //!<ePWM5 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM6SOCB   0x200000U //!<ePWM6 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM7SOCB   0x400000U //!<ePWM7 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM8SOCB   0x800000U //!<ePWM8 SOCB for ADCSOCBO
#endif

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_enablePeripheral()
//! and SysCtl_disablePeripheral() as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_PERIPH_CLK_FMC    =  0U,   
    SYSCTL_PERIPH_CLK_DMAMUX =  1U,
    SYSCTL_PERIPH_CLK_LPTIM  =  3U,
    SYSCTL_PERIPH_CLK_CANA   =  4U,  
    SYSCTL_PERIPH_CLK_XBAR   =  8U,  
    SYSCTL_PERIPH_CLK_SPIA   =  12U, 
    SYSCTL_PERIPH_CLK_SPIB   =  13U, 
    SYSCTL_PERIPH_CLK_XINT   =  14U, 
    SYSCTL_PERIPH_CLK_SD1    =  16U,
    SYSCTL_PERIPH_CLK_CRC    =  18U, 
    SYSCTL_PERIPH_CLK_PTIM   =  23U, 
    SYSCTL_PERIPH_CLK_EPWM1  =  24U,
    SYSCTL_PERIPH_CLK_EPWM2  =  25U,
    SYSCTL_PERIPH_CLK_EPWM3  =  26U,
    SYSCTL_PERIPH_CLK_ADCA   =  27U, 
    SYSCTL_PERIPH_CLK_ADCB   =  28U, 
   
    SYSCTL_PERIPH_CLK_EQEP1  =  0x1000+0U ,
    SYSCTL_PERIPH_CLK_GPIOA  =  0x1000+9U ,
    SYSCTL_PERIPH_CLK_GPIOB  =  0x1000+10U,
    SYSCTL_PERIPH_CLK_ECAP1  =  0x1000+24U,
    SYSCTL_PERIPH_CLK_ECAP2  =  0x1000+25U,
   
    SYSCTL_PERIPH_CLK_EWM    =  0x2000+0U ,  
    SYSCTL_PERIPH_CLK_I2CA   =  0x2000+5U , 
    SYSCTL_PERIPH_CLK_I2CB   =  0x2000+6U , 
    SYSCTL_PERIPH_CLK_SCID   =  0x2000+9U , 
    SYSCTL_PERIPH_CLK_SCIE   =  0x2000+10U, 
    SYSCTL_PERIPH_CLK_SCIF   =  0x2000+11U, 
    SYSCTL_PERIPH_CLK_CMPSS1  = 0x2000+18U,
   
    SYSCTL_PERIPH_CLK_CANB     =  0x3000+4U ,  
    SYSCTL_PERIPH_CLK_EQEP2    =  0x3000+6U ,  
    SYSCTL_PERIPH_CLK_SPIC     =  0x3000+12U,   
    SYSCTL_PERIPH_CLK_SPID     =  0x3000+13U,   
    SYSCTL_PERIPH_CLK_EPWM4    =  0x3000+16U,  
    SYSCTL_PERIPH_CLK_EPWM5    =  0x3000+17U,  
    SYSCTL_PERIPH_CLK_EPWM6    =  0x3000+18U,  
    SYSCTL_PERIPH_CLK_EPWM7    =  0x3000+19U,  
    SYSCTL_PERIPH_CLK_ADCC     =  0x3000+27U,   
   
    SYSCTL_PERIPH_CLK_SCIA   =  0x4000+4U,
    SYSCTL_PERIPH_CLK_SCIB   =  0x4000+5U,
    SYSCTL_PERIPH_CLK_SCIC   =  0x4000+6U,
    SYSCTL_PERIPH_CLK_ECAP3  =  0x4000+9U,

    SYSCTL_PERIPH_CLK_DMA = 0x6000+1U, //!< DMA clock
    
    SYSCTL_PERIPH_CLK_TBCLKSYNC = 0xf000,   //TBCLKSYNC
    
} SysCtl_PeripheralPCLOCKCR;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_resetPeripheral() as
//! the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
 SYSCTL_PERIPH_RES_ADCA   =  0x00000000U,
 SYSCTL_PERIPH_RES_ADCB   =  0x00000001U,
 SYSCTL_PERIPH_RES_ADCC   =  0x00000002U,
 SYSCTL_PERIPH_RES_CMPSS1 =  0x00000003U,
 SYSCTL_PERIPH_RES_CRC    =  0x00000004U,
 SYSCTL_PERIPH_RES_SPIA   =  0x00000005U,
 SYSCTL_PERIPH_RES_SPIB   =  0x00000006U,
 SYSCTL_PERIPH_RES_SPIC   =  0x00000007U,
 SYSCTL_PERIPH_RES_SPID   =  0x00000008U,
 SYSCTL_PERIPH_RES_ECAP1  =  0x00000009U,
 SYSCTL_PERIPH_RES_ECAP2  =  0x0000000aU,
 SYSCTL_PERIPH_RES_ECAP3  =  0x0000000bU,
 SYSCTL_PERIPH_RES_EPWM1  =  0x0000000cU,
 SYSCTL_PERIPH_RES_EPWM2  =  0x0000000dU,
 SYSCTL_PERIPH_RES_EPWM3  =  0x0000000eU,
 SYSCTL_PERIPH_RES_EPWM4  =  0x0000000fU,
 SYSCTL_PERIPH_RES_EPWM5  =  0x00000010U,
 SYSCTL_PERIPH_RES_EPWM6  =  0x00000011U,
 SYSCTL_PERIPH_RES_EPWM7  =  0x00000012U,
 SYSCTL_PERIPH_RES_EQEP1  =  0x00000013U,
 SYSCTL_PERIPH_RES_EQEP2  =  0x00000014U,
 SYSCTL_PERIPH_RES_EWM    =  0x00000015U,
 SYSCTL_PERIPH_RES_I2CA   =  0x00000017U,
 SYSCTL_PERIPH_RES_I2CB   =  0x00000018U,
 SYSCTL_PERIPH_RES_SCIA   =  0x00000019U,
 SYSCTL_PERIPH_RES_SCIB   =  0x0000001aU,
 SYSCTL_PERIPH_RES_SCIC   =  0x0000001bU,
 SYSCTL_PERIPH_RES_SCID   =  0x0000001cU,
 SYSCTL_PERIPH_RES_SCIE   =  0x0000001dU,
 SYSCTL_PERIPH_RES_SCIF   =  0x0000001eU,
 SYSCTL_PERIPH_RES_CANA   =  0x0000001fU,

 SYSCTL_PERIPH_RES_CANB   =  0x10000000U, 
 SYSCTL_PERIPH_RES_PTIM   =  0x10000001U,
 SYSCTL_PERIPH_RES_SD1    =  0x10000005U,
 SYSCTL_PERIPH_RES_SD2    =  0x10000006U,
 SYSCTL_PERIPH_RES_XBAR   =  0x10000007U,
 SYSCTL_PERIPH_RES_XINT   =  0x10000008U,
 SYSCTL_PERIPH_RES_GPIOA  =  0x10000009U,
 SYSCTL_PERIPH_RES_GPIOB  =  0x1000000aU,
 SYSCTL_PERIPH_RES_GPIOC  =  0x1000000bU,
 SYSCTL_PERIPH_RES_LPTIM  =  0x1000000cU,

} SysCtl_PeripheralSOFTPRES;

//*****************************************************************************
//
// The following are values that can be passed to the SysCtl_clearResetCause()
// API as rstCauses or returned by the SysCtl_getResetCause() API.
//
//*****************************************************************************
#define RCM_CAUSE_POR                 0x00000080U //!< Power-on reset
#define RCM_CAUSE_XRS                 0x00000040U //!< External reset pin
#define RCM_CAUSE_WDRS                0x00000020U //!< Watchdog reset
#define RCM_CAUSE_VDT                 0x00000002U //!< Voltage detect reset
#define RCM_CAUSE_JTAG                0x00000100U //!< JTAG reset
#define RCM_CAUSE_LOCK                0x00000200U //!< Lockup Reset
#define RCM_CAUSE_SW                  0x00000400U //!< Software CPU reset

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setWatchdogPrescaler() as the \e prescaler parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_WD_PRESCALE_1  = 0,      //!< WDCLK = WWDTCLK / 1
    SYSCTL_WD_PRESCALE_2  = 1,      //!< WDCLK = WWDTCLK / 2
    SYSCTL_WD_PRESCALE_3  = 2,      //!< WDCLK = WWDTCLK / 3
    SYSCTL_WD_PRESCALE_4  = 3,      //!< WDCLK = WWDTCLK / 4
    SYSCTL_WD_PRESCALE_5  = 4,      //!< WDCLK = WWDTCLK / 5
    SYSCTL_WD_PRESCALE_6  = 5,      //!< WDCLK = WWDTCLK / 6
    SYSCTL_WD_PRESCALE_7  = 6,      //!< WDCLK = WWDTCLK / 7
    SYSCTL_WD_PRESCALE_8  = 7,      //!< WDCLK = WWDTCLK / 7
} SysCtl_WDPrescaler;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setWatchdogMode() as the \e prescaler parameter.
//
//*****************************************************************************
typedef enum
{
    //! Watchdog can generate a reset signal
    SYSCTL_WD_MODE_RESET,
    //! Watchdog can generate an interrupt signal; reset signal is disabled
    SYSCTL_WD_MODE_INTERRUPT
} SysCtl_WDMode;





//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_selectClockOutSource() as the \e source parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CLOCKOUT_LPO     = 3U,   //!< PLL System Clock post SYSCLKDIV
    SYSCTL_CLOCKOUT_IRC30K     = 5U,   //!< PLL Raw Clock
    SYSCTL_CLOCKOUT_INTOSC1    = 8U,   //!< Internal Oscillator 1
} SysCtl_ClockOut;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_setLowSpeedClock() as
//! the \e prescaler parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_LSPCLK_PRESCALE_1    = 0,    //!< BUSCLK = PLLSYSCLK / 1
    SYSCTL_LSPCLK_PRESCALE_2    = 1,    //!< BUSCLK = PLLSYSCLK / 2
    SYSCTL_LSPCLK_PRESCALE_3    = 2,    //!< BUSCLK = PLLSYSCLK / 3 
    SYSCTL_LSPCLK_PRESCALE_4    = 3,    //!< BUSCLK = PLLSYSCLK / 4 
    SYSCTL_LSPCLK_PRESCALE_5    = 4,    //!< BUSCLK = PLLSYSCLK / 4
    SYSCTL_LSPCLK_PRESCALE_6    = 5,    //!< BUSCLK = PLLSYSCLK / 6
    SYSCTL_LSPCLK_PRESCALE_7    = 6,    //!< BUSCLK = PLLSYSCLK / 7
    SYSCTL_LSPCLK_PRESCALE_8    = 7,    //!< BUSCLK = PLLSYSCLK / 8
    SYSCTL_LSPCLK_PRESCALE_9    = 8,    //!< BUSCLK = PLLSYSCLK / 9 
    SYSCTL_LSPCLK_PRESCALE_10   = 9,    //!< BUSCLK = PLLSYSCLK / 10
    SYSCTL_LSPCLK_PRESCALE_11   = 10,    //!< BUSCLK = PLLSYSCLK / 11
    SYSCTL_LSPCLK_PRESCALE_12   = 11,    //!< BUSCLK = PLLSYSCLK / 12
    SYSCTL_LSPCLK_PRESCALE_13   = 12,    //!< BUSCLK = PLLSYSCLK / 13
    SYSCTL_LSPCLK_PRESCALE_14   = 13,    //!< BUSCLK = PLLSYSCLK / 14
    SYSCTL_LSPCLK_PRESCALE_15   = 14,    //!< BUSCLK = PLLSYSCLK / 15
    SYSCTL_LSPCLK_PRESCALE_16   = 15,    //!< BUSCLK = PLLSYSCLK / 16
} SysCtl_LSPCLKPrescaler;
//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setExternalOscMode() as the \e mode parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_XTALMODE_CRYSTAL = 1U,   //!< XTAL Oscillator Crystal Mode
    SYSCTL_XTALMODE_SINGLE  = 2U    //!< XTAL Oscillator Single-Ended Mode, not 
                                    //support in sp28038v1
} SysCtl_ExternalOscMode;


//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncOutputConfig().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT  = 0X0U,  //!< EPWM1SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM2SYNCOUT  = 0X1U,  //!< EPWM2SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM3SYNCOUT  = 0X2U,  //!< EPWM3SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM4SYNCOUT  = 0X3U,  //!< EPWM4SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM5SYNCOUT  = 0X4U,  //!< EPWM5SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM6SYNCOUT  = 0X5U,  //!< EPWM6SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM7SYNCOUT  = 0X6U,  //!< EPWM7SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP1SYNCOUT  = 0x18,  //!< ECAP1SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP2SYNCOUT  = 0x19,  //!< ECAP2SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP3SYNCOUT  = 0x20,  //!< ECAP3SYNCOUT --> EXTSYNCOUT

} SysCtl_SyncOutputSource;

//*****************************************************************************
//
//! The following values define the \e parametric parameter for
//! SysCtl_getDeviceParametric().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_DEVICE_QUAL,       //!< Device Qualification Status
    SYSCTL_DEVICE_PINCOUNT,   //!< Device Pin Count
    SYSCTL_DEVICE_INSTASPIN,  //!< Device InstaSPIN Feature Set
    SYSCTL_DEVICE_FLASH,      //!< Device Flash size (KB)
    SYSCTL_DEVICE_FAMILY,     //!< Device Family
    SYSCTL_DEVICE_PARTNO,     //!< Device Part Number
    SYSCTL_DEVICE_CLASSID     //!< Device Class ID
} SysCtl_DeviceParametric;



//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setXClk() as \e divider parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_XCLKOUT_DIV_1  = 0,      //!<  XCLKOUT =  XCLKOUT / 1
    SYSCTL_XCLKOUT_DIV_2  = 1,      //!<  XCLKOUT =  XCLKOUT / 2
    SYSCTL_XCLKOUT_DIV_4  = 2,      //!<  XCLKOUT =  XCLKOUT / 4
    SYSCTL_XCLKOUT_DIV_8  = 3       //!<  XCLKOUT =  XCLKOUT / 8

}SysCtl_XClkDivider;


//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! Wrapper function for Device_cal function
//!
//! \param None
//!
//! This is a wrapper function for the Device_cal function available in the OTP
//! memory.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_deviceCal(void)
{
}

//*****************************************************************************
//
//! Resets a peripheral
//!
//! \param peripheral is the peripheral to reset.
//!
//! This function uses the SOFTPRESx registers to reset a specified peripheral.
//! Module registers will be returned to their reset states.
//!
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_resetPeripheral(SysCtl_PeripheralSOFTPRES peripheral)
{
    uint16_t regIndex;
    uint16_t bitIndex;

    //
    // Decode the peripheral variable.
    //
    regIndex = ((uint16_t)peripheral & 0xF000000U)>>28U;
    bitIndex = ((uint16_t)peripheral & 0x003FU);

    HWREG(SYSCTRL_BASE + SYSCTL_O_SOFTRST1 + regIndex) |= (1UL << bitIndex);
    HWREG(SYSCTRL_BASE + SYSCTL_O_SOFTRST1 + regIndex) &= ~(1UL << bitIndex);


}

//*****************************************************************************
//
//! Enables a peripheral.
//!
//! \param peripheral is the peripheral to enable.
//!
//! Peripherals are enabled with this function.  At power-up, all peripherals
//! are disabled; they must be enabled in order to operate or respond to
//! register reads/writes.
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint16_t regIndex;
    uint16_t bitIndex;

    //
    // Decode the peripheral variable.
    //
    regIndex = ((uint16_t)peripheral & 0x000F000U)>>10U;
    bitIndex = ((uint16_t)peripheral & 0x003FU);

    if(regIndex == 0x3C)
        regIndex = SYSCTL_O_TBCLKSYNC - SYSCTL_O_ISP1CGC1;
    //
    // Turn on the module clock.
    //
    HWREG(SYSCTRL_BASE + SYSCTL_O_ISP1CGC1 + regIndex) |= (1UL << bitIndex);

}

//*****************************************************************************
//
//! Disables a peripheral.
//!
//! \param peripheral is the peripheral to disable.
//!
//! Peripherals are disabled with this function.  Once disabled, they will not
//! operate or respond to register reads/writes.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint16_t regIndex;
    uint16_t bitIndex;

    //
    // Decode the peripheral variable.
    //
    regIndex = ((uint16_t)peripheral & 0x000F000U)>>12U;
    bitIndex = ((uint16_t)peripheral & 0x003FU);

    //
    // Turn off the module clock.
    //
   HWREG(SYSCTRL_BASE + SYSCTL_O_ISP1CGC1 + regIndex) &= ~(1UL << bitIndex);

}

//*****************************************************************************
//
//! Resets the device.
//!
//! This function performs a watchdog reset of the device.
//!
//! \return This function does not return.
//
//*****************************************************************************
static inline void
SysCtl_resetDevice(void)
{
    //
    // Write an incorrect check value to the watchdog control register
    // This will cause a device reset
    //
    NVIC_SystemReset();
    //
    // The device should have reset, so this should never be reached.  Just in
    // case, loop forever.
    //
    while((bool)1)
    {
    }
}

//*****************************************************************************
//
//! Gets the reason for a reset.
//!
//! This function will return the reason(s) for a reset.  Since the reset
//! reasons are sticky until either cleared by software or an external reset,
//! multiple reset reasons may be returned if multiple resets have occurred.
//! The reset reason will be a logical OR of
//! - \b RCM_CAUSE_POR - Power-on reset
//! - \b RCM_CAUSE_XRS - External reset pin
//! - \b RCM_CAUSE_WDRS - Watchdog reset
//! - \b RCM_CAUSE_VDT - Voltage detect reset
//! - \b RCM_CAUSE_JTAG - JTAG reset
//! - \b RCM_CAUSE_LOCK  - Lockup Reset
//! - \b RCM_CAUSE_SW - Software CPU reset
//!
//! \note If you re-purpose the reserved boot ROM RAM, the POR and XRS reset
//! statuses won't be accurate.
//!
//! \return Returns the reason(s) for a reset.
//
//*****************************************************************************
static inline uint32_t
SysCtl_getResetCause(void)
{
    uint32_t resetCauses;

    //
    // Read CPU reset register
    //
    resetCauses = RCM->SSRS0;

    resetCauses += RCM->SSRS1<<8;
    //
    // Return the reset reasons.
    //
    return(resetCauses);
}

//*****************************************************************************
//
//! Clears reset reasons.
//!
//! \param rstCauses are the reset causes to be cleared; must be a logical
//! OR of
//! - \b SYSCTL_CAUSE_POR - Power-on reset
//! - \b SYSCTL_CAUSE_XRS - External reset pin
//! - \b SYSCTL_CAUSE_WDRS - Watchdog reset
//! - \b SYSCTL_CAUSE_NMIWDRS - NMI watchdog reset
//! - \b SYSCTL_CAUSE_SCCRESET - SCCRESETn reset from DCSM
//! - \b SYSCTL_CAUSE_HWBISTN  - HWBISTn Reset
//! - \b SYSCTL_CAUSE_SIMRESET_CPU1RSN - SIMRESET_CPU1RSn
//! - \b SYSCTL_CAUSE_SIMRESET_XRSN - SIMRESET_XRSn
//!
//! This function clears the specified sticky reset reasons.  Once cleared,
//! another reset for the same reason can be detected, and a reset for a
//! different reason can be distinguished (instead of having two reset causes
//! set).  If the reset reason is used by an application, all reset causes
//! should be cleared after they are retrieved with SysCtl_getResetCause().
//!
//! \note Some reset causes are cleared by the boot ROM.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_clearResetCause(uint32_t rstCauses)
{
    //
    // Clear the given reset reasons.
    //
    RCM->SSRS0 = rstCauses&0xff;
    RCM->SSRS1 = (rstCauses>>8)&0xff;
}

//*****************************************************************************
//
//! Selects a clock source to mux to an external GPIO pin (XCLKOUT).
//!
//! \param source is the internal clock source to be configured.
//!
//! This function configures the specified clock source to be muxed to an
//! external clock out (XCLKOUT) GPIO pin. The \e source parameter may take a
//! value of one of the following values:
//! - \b SYSCTL_CLOCKOUT_LPO
//! - \b SYSCTL_CLOCKOUT_IRC30K
//! - \b SYSCTL_CLOCKOUT_INTOSC1
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectClockOutSource(SysCtl_ClockOut source)
{
 
    HWREG(SYSCTRL_BASE + SYSCTL_O_CLKOUTSEL) = source;

}

//*****************************************************************************
//
//! Set the external oscillator mode.
//!
//! \param mode is the external oscillator mode to be configured.
//!
//! This function sets the external oscillator mode specified by the \e mode
//! parameter which may take one of two values:
//! - \b SYSCTL_XTALMODE_CRYSTAL - Crystal Mode
//! - \b SYSCTL_XTALMODE_SINGLE  - Single-Ended Mode
//!
//! \note The external oscillator must be powered off before this configuration
//! can be performed.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setExternalOscMode(SysCtl_ExternalOscMode mode)
{
}



//*****************************************************************************
//
//! Turns on the specified oscillator sources.
//!
//! \param oscSource is the oscillator source to be configured.
//!
//! This function turns on the oscillator specified by the \e oscSource
//! parameter which may take a value of  \b SYSCTL_OSCSRC_XTAL
//! or \b SYSCTL_OSCSRC_OSC2.
//!
//! \note \b SYSCTL_OSCSRC_OSC1 is not a valid value for \e oscSource.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_turnOnOsc(uint32_t oscSource)
{
    ASSERT(
           (oscSource == SYSCTL_OSCSRC_OSC1) ||
           (oscSource == SYSCTL_OSCSRC_30K) ||
           (oscSource == SYSCTL_OSCSRC_XTAL)
          );


    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC1:
            //
            // Turn on INTOSC2
            //
            HWREG(SYSCTRL_BASE + SYSCTL_O_POWERCFG) &=  ~SYSCTL_O_IOSC8M_PD_M;
            break;

        case SYSCTL_OSCSRC_XTAL:
            //
            // Turn on XTALOSC
            //
            HWREG(SYSCTRL_BASE + SYSCTL_O_POWERCFG) &=  ~SYSCTL_O_XOSC16M_PD_M;
            break;

        case SYSCTL_OSCSRC_30K:
            //
            // Turn on XTALOSC
            //
            HWREG(SYSCTRL_BASE + SYSCTL_O_POWERCFG) &=  ~SYSCTL_O_IOSC30K_PD_M;
            break;

        default:
            //
            // Do nothing. Not a valid oscSource value.
            //
            break;
    }

}

//*****************************************************************************
//
//! Turns off the specified oscillator sources.
//!
//! \param oscSource is the oscillator source to be configured.
//!
//! This function turns off the oscillator specified by the \e oscSource
//! parameter which may take a value of  \b SYSCTL_OSCSRC_XTAL
//! or \b SYSCTL_OSCSRC_OSC2.
//!
//! \note \b SYSCTL_OSCSRC_OSC1 is not a valid value for \e oscSource.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_turnOffOsc(uint32_t oscSource)
{
    ASSERT(
           (oscSource == SYSCTL_OSCSRC_OSC1) ||
           (oscSource == SYSCTL_OSCSRC_30K) ||
           (oscSource == SYSCTL_OSCSRC_XTAL)
          );


    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC1:
            //
            // Turn off INTOSC1
            //
            HWREG(SYSCTRL_BASE + SYSCTL_O_POWERCFG) |= SYSCTL_O_IOSC8M_PD_M;
            break;

        case SYSCTL_OSCSRC_XTAL:
            //
            // Turn off XTALOSC
            //
            HWREG(SYSCTRL_BASE + SYSCTL_O_POWERCFG) |= SYSCTL_O_XOSC16M_PD_M;
            break;

        case SYSCTL_OSCSRC_30K:
            //
            // Turn off OSC30K
            //
            HWREG(SYSCTRL_BASE + SYSCTL_O_POWERCFG) |= SYSCTL_O_IOSC30K_PD_M;
            break;

        default:
            //
            // Do nothing. Not a valid oscSource value.
            //
            break;
    }
}

//*****************************************************************************
//
//! Enters IDLE mode.
//!
//! This function puts the device into IDLE mode. The CPU clock is gated while
//! all peripheral clocks are left running. Any enabled interrupt will wake the
//! CPU up from IDLE mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enterIdleMode(void)
{
 //sleep
  SCB->SCR &= SCB_SCR_SLEEPDEEP_Msk;
  __DSB();
  __WFI();
  __ISB();

}

//*****************************************************************************
//
//! Enters STANDBY mode.
//!
//! This function puts the device into STANDBY mode. This will gate both the
//! CPU clock and any peripheral clocks derived from SYSCLK. The watchdog is
//! left active, and an NMI or an optional watchdog interrupt will wake the
//! CPU subsystem from STANDBY mode.
//!
//! GPIOs may be configured to wake the CPU subsystem. See
//! SysCtl_enableLPMWakeupPin().
//!
//! The CPU will receive an interrupt (WAKEINT) on wakeup.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enterStandbyMode(void)
{
    //deep sleep
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __WFI();
    __ISB();

}


//*****************************************************************************
//
//! Configures whether the watchdog generates a reset or an interrupt signal.
//!
//! This function configures whether the watchdog generates a reset or an interrupt
//! signal. If the watchdog is configured to generate an interrupt, the
//! reset will be delayed by WCT(watchdog configuration time) time, that is 
//!  256 bus clock cycles.
//! \note Check the status of the watchdog interrupt using
//! SysCtl_isWatchdogInterruptActive() before calling this function. 
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setWatchdogMode(SysCtl_WDMode mode)
{
    if(mode == SYSCTL_WD_MODE_RESET)
        WWDT->STCTRLH &= ~WWDT_STCTRLH_IRQRSTEN_MASK;
    else
        WWDT->STCTRLH |= WWDT_STCTRLH_IRQRSTEN_MASK;
}

//*****************************************************************************
//
//! Gets the status of the watchdog interrupt signal.
//!
//! This function returns the status of the watchdog interrupt signal. If the
//! interrupt is active, this function will return \b true. If \b false, the
//! interrupt is NOT active.
//!
//! \return \b true if the interrupt is active and \b false if it is not.
//
//*****************************************************************************
static inline bool
SysCtl_isWatchdogInterruptActive(void)
{
    //
    // If the status bit is cleared, the WDINTn signal is active.
    //
    return((WWDT->STCTRLL & WWDT_STCTRLL_INTFLG_MASK)!=0) ? true : false;
}

//*****************************************************************************
//
//! Disables the watchdog.
//!
//! This function disables the watchdog timer. Note that the watchdog timer is
//! enabled on reset.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableWatchdog(void)
{
  WWDT->UNLOCK = WWDT_UNLOCK_WWDTUNLOCK_SET(0xC520); /* Key 1 */
  /* WWDT->UNLOCK: WWDTUNLOCK=0xD928 */
  WWDT->UNLOCK = WWDT_UNLOCK_WWDTUNLOCK_SET(0xD928); /* Key 2 */
  /* WWDT->STCTRLH: ?=0,DISTESTWWDT=0,BYTESEL=0,TESTSEL=0,TESTWWDT=0,?=0,?=1,WAITEN=1,STOPEN=1,DBGEN=0,ALLOWUPDATE=1,WINEN=0,IRQRSTEN=0,CLKSRC=1,WWDTEN=0 */
  WWDT->STCTRLH = WWDT_STCTRLH_BYTESEL_SET(0x00) |
                 WWDT_STCTRLH_WAITEN_MASK |
                 WWDT_STCTRLH_STOPEN_MASK |
                 WWDT_STCTRLH_ALLOWUPDATE_MASK |
                 WWDT_STCTRLH_CLKSRC_MASK |
                 0x0100U;
}

//*****************************************************************************
//
//! Enables the watchdog.
//!
//! This function enables the watchdog timer. Note that the watchdog timer is
//! enabled on reset.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableWatchdog(void)
{
    WWDT->UNLOCK = WWDT_UNLOCK_WWDTUNLOCK_SET(0xC520); /* Key 1 */
  /* WWDT->UNLOCK: WWDTUNLOCK=0xD928 */ 
    WWDT->UNLOCK = WWDT_UNLOCK_WWDTUNLOCK_SET(0xD928); /* Key 2 */

    WWDT->STCTRLH |= WWDT_STCTRLH_WWDTEN_MASK;
  
}

//*****************************************************************************
//
//! Checks if the watchdog is enabled or not
//!
//! This function returns the watchdog status whether it is enabled or disabled
//!
//! \return \b true if the watchdog is enabled & \b false if the watchdog is 
//! disabled
//
//*****************************************************************************
static inline bool
SysCtl_isWatchdogEnabled(void)
{

    //
    // Get the watchdog enable status
    //
    return (WWDT->STCTRLH & WWDT_STCTRLH_WWDTEN_MASK) ? true : false;
}

//*****************************************************************************
//
//! Services the watchdog.
//!
//! This function resets the watchdog.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_serviceWatchdog(void)
{
    //
    // Enable the counter to be reset and then reset it.
    //
    WWDT->REFRESH = SYSCTL_WD_ENRSTKEY;
    WWDT->REFRESH = SYSCTL_WD_RSTKEY;
}

//*****************************************************************************
//
//! Writes the first key to enter the watchdog reset.
//!
//! This function writes the first key to enter the watchdog reset.
//!
//! \note This function must be followed by a call to SysCtl_resetWatchdog within
//! 20 bus clock cycle, otherwise watchdog will reset the system.
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableWatchdogReset(void)
{
     //
    // Enable the counter to be reset
    //
    WWDT->REFRESH = SYSCTL_WD_ENRSTKEY;

}

//*****************************************************************************
//
//! Writes the second key to reset the watchdog.
//!
//! This function writes the second key to reset the watchdog.
//!
//! \note This function must follow SysCtl_enableWatchdogReset within
//! 20 bus clock cycle, otherwise watchdog will reset the system.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_resetWatchdog(void)
{
     //
    // Reset the watchdog counter
    //
    WWDT->REFRESH = SYSCTL_WD_RSTKEY;
 
}


//*****************************************************************************
//
//! Sets up watchdog clock (WDCLK) prescaler.
//!
//! \param prescaler is the value that configures the watchdog clock relative
//! to the value from the pre-divider.
//!
//! This function sets up the watchdog clock (WDCLK) prescaler.
//! The \e prescaler parameter divides PREDIVCLK down to WDCLK.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setWatchdogPrescaler(SysCtl_WDPrescaler prescaler)
{
    WWDT->PRESC = WWDT_PRESC_PRESCVAL_SET(prescaler);
}

//*****************************************************************************
//
//! Gets the watchdog counter value.
//!
//! \return Returns the current value of the 32-bit watchdog counter. If this
//! count value overflows, a watchdog output pulse is generated.
//
//*****************************************************************************
static inline uint16_t
SysCtl_getWatchdogCounterValue(void)
{
    //
    // Read and return the value of the watchdog counter.
    //
   return (uint32_t)((((uint32_t)WWDT->TMROUTH) << 16U) | (WWDT->TMROUTL));
}

//*****************************************************************************
//
//! Gets the watchdog reset status.
//!
//! This function returns the watchdog reset status. If this function returns
//! \b true, that indicates that a watchdog reset generated the last reset
//! condition. Otherwise, it was an external device or power-up reset
//! condition.
//!
//! \return Returns \b true if the watchdog generated the last reset condition.
//
//*****************************************************************************
static inline bool
SysCtl_getWatchdogResetStatus(void)
{
    //
    // Read and return the status of the watchdog reset status flag.
    //
    return((RCM->SRS0 & RCM_SRS0_WWDT_MASK) != 0U);
}

//*****************************************************************************
//
//! Clears the watchdog reset status.
//!
//! This function clears the watchdog reset status. To check if it was set
//! first, see SysCtl_getWatchdogResetStatus().
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_clearWatchdogResetStatus(void)
{

    //
    // Read and return the status of the watchdog reset status flag.
    //

    RCM->SSRS0 = RCM_SRS0_WWDT_MASK;
}

//*****************************************************************************
//
//! Set the minimum threshold value for windowed watchdog
//!
//! \param value is the value to set the window threshold
//!
//! This function sets the minimum threshold value used to define the lower
//! limit of the windowed watchdog functionality.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setWatchdogWindowValue(uint32_t value)
{
    //
    // Set the windowed value
    //
    WWDT->WINH = (uint16_t)((value >> 16U) & 0xFFFFU);
    WWDT->WINL = (uint16_t)((value)&0xFFFFU);


}


//*****************************************************************************
//
//! Configures the sync output source.
//!
//! \param syncSrc is sync output source selection.
//!
//! This function configures the sync output source from the ePWM modules. The
//! \e syncSrc parameter is a value \b SYSCTL_SYNC_OUT_SRC_XXXX, where XXXX is
//! a sync signal coming from an ePWM such as SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setSyncOutputConfig(SysCtl_SyncOutputSource syncSrc)
{
    //
    // Write the sync output source selection to the appropriate register.
    //

//    HWREG(SYSCTRL_BASE+SYSCTL_O_SYNCSELECT) |= syncSrc;
   while(1);   // this function is not implemented in SP2401_V1
}
//*****************************************************************************
//
//! Enables ePWM SOC signals to drive an external (off-chip) ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be enabled
//!
//! This function configures which ePWM SOC signals are enabled as a source for
//! either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical OR
//! of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Set the bits that correspond to signal to be enabled.
    //
    HWREG(SYSCTRL_BASE + SYSCTL_O_ADCSOCOUTSEL) = adcsocSrc;
}

//*****************************************************************************
//
//! Disables ePWM SOC signals from driving an external ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be disabled
//!
//! This function configures which ePWM SOC signals are disabled as a source
//! for either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical
//! OR of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Clear the bits that correspond to signal to be disabled.
    //
    HWREG(SYSCTRL_BASE + SYSCTL_O_ADCSOCOUTSEL) &= ~adcsocSrc;
}

//*****************************************************************************
//
//! Locks the SOC Select of the Trig X-BAR.
//!
//! This function locks the external ADC SOC select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_lockExtADCSOCSelect(void)
{
    //
    // Lock the ADCSOCOUTSELECT bit of the SYNCSOCLOCK register.
    //
//    HWREG(SYNCSOC_BASE + SYSCTL_O_SYNCSOCLOCK) =
//        SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT;
   while(1);   // this function is not implemented in SP2401_V1

}

//*****************************************************************************
//
//! Locks the Sync Select of the Trig X-BAR.
//!
//! This function locks Sync Input and Output Select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_lockSyncSelect(void)
{
    //
    // Lock the SYNCSELECT register.
    //
    //HWREG(SYNCSOC_BASE + SYSCTL_O_SYNCSOCLOCK) = SYSCTL_SYNCSOCLOCK_SYNCSELECT;
    while(1);   // this function is not implemented in SP2401_V1

}
//*****************************************************************************
//
//! Get the Device Silicon Revision ID
//!
//! This function returns the silicon revision ID for the device.
//!
//! \note This API is applicable only for the CPU1 subsystem.
//!
//! \return Returns the silicon revision ID value.
//
//*****************************************************************************
static inline uint32_t
SysCtl_getDeviceRevision(void)
{
    //
    // Returns the device silicon revision ID
    //
    return(HWREG(SYSCTRL_BASE + SYSCTL_O_DEVICEID1));
}



//*****************************************************************************
//
//! Sets up XCLK divider.
//!
//! \param divider is the value that configures the divider.
//!
//! This function sets up the XCLK divider. There is only one
//! divider that scales INTOSC1 to XCLK.
//!
//! The \e divider parameter can have one enumerated value from
//! SysCtl_XClkDivider
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setXClk(SysCtl_XClkDivider divider)
{
    //
    // Clears the divider then configures it.
    //
    //HWREG(SYNCSOC_BASE + SYSCTL_O_XCLKOUTDIVSEL) = divider;
    while(1);   // this function is not implemented in SP2401_V1
 
}

//*****************************************************************************
//
//! Sets up PLLSYSCLK divider.
//!
//! \param divider is the value that configures the divider.
//!
//! This function sets up the OUTDIV1. There is only one
//! divider that scales PLLSYSCLK to generate the core/system clock.
//!
//! The \e divider parameter can have any value (even/odd) from 1-16
//!
//! \return None.
//!
//!
//
//*****************************************************************************
static inline void
SysCtl_setPLLSysClk(uint16_t divider)
{
    HWREG(SYSCTRL_BASE+SYSCTL_O_CLKDIV) =  (HWREG(SYSCTRL_BASE+SYSCTL_O_CLKDIV)
                                             & ~(SYSCTL_O_CLKDIV_SYSDIV_M)) |
                                            (divider<<SYSCTL_O_CLKDIV_SYSDIV_S);
}


//*****************************************************************************
//
//! Simulates a reset to the CPU1
//!
//! \param rstCauses is the cause for the reset.
//!
//! The \e rstCauses parameter can be one/ more of these values:
//! SYSCTL_SIMRESET_CPU1RSN or SYSCTL_SIMRESET_XRSN
//!
//! \return None.
//!
//! \note This API exists only on CPU1
//
//*****************************************************************************
static inline void
SysCtl_simulateReset(uint32_t rstCauses)
{
    //
    //Write will succeed only if a matching key value is written
    //to the KEY field
    //Sets the appropriate reset bit.
    //
    NVIC_SystemReset();
}

static inline void
SysCtl_enableTBCLKSYNC()
{
    HWREG(SYSCTRL_BASE+SYSCTL_O_TBCLKSYNC) = (HWREG(SYSCTRL_BASE+SYSCTL_O_TBCLKSYNC)
                                                & ~(SYSCTL_TBCLKSYNC_TBCLKSYNC_M)) | 
                                                    (SYSCTL_TBCLKSYNC_TBCLKSYNC_M);
}

//*****************************************************************************
//
//! Delays for a fixed number of cycles.
//!
//! \param count is the number of delay loop iterations to perform.
//!
//! This function generates a constant length delay using assembly code. The
//! loop takes 5 cycles per iteration plus 9 cycles of overhead.
//!
//! \note If count is equal to zero, the loop will underflow and run for a
//! very long time.
//!
//! \note Refer to the macro DEVICE_DELAY_US(x) in device.h which can be used to
//! insert a delay in microseconds.
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_delay(uint32_t count);

//*****************************************************************************
//
//! Calculates the system clock frequency (SYSCLK).
//!
//! \param clockInHz is the frequency of the oscillator clock source (OSCCLK).
//!
//! This function determines the frequency of the system clock based on the
//! frequency of the oscillator clock source (from \e clockInHz) and the PLL
//! and clock divider configuration registers.
//!
//! \return Returns the system clock frequency. If a missing clock is detected,
//! the function will return the INTOSC1 frequency. This needs to be
//! corrected and cleared (see SysCtl_resetMCD()) before trying to call this
//! function again.
//
//*****************************************************************************
extern uint32_t
SysCtl_getClock(uint32_t clockInHz);

//*****************************************************************************
//
//! Configures the clocking of the device.
//!
//! \param config is the required configuration of the device clocking.
//!
//! This function configures the clocking of the device.  The input crystal
//! frequency, oscillator to be used, use of the PLL, and the system clock
//! divider are all configured with this function.
//!
//! The \e config parameter is the OR of several different values, many of
//! which are grouped into sets where only one can be chosen.
//!
//! - The system clock divider is chosen with the macro \b SYSCTL_SYSDIV(x)
//!   where x is either 1 or an even value up to 126.
//!
//! - The use of the PLL is chosen with ONLY one of the below modes:
//!   \b SYSCTL_PLL_ENABLE - This is to Enable the PLL Clock to the System
//!    or
//!   \b SYSCTL_PLL_BYPASS -This is to Bypass the PLLCLK from the System,
//!    this will also power up the PLL if the user desires to power up the PLL
//!    but not use it for System.
//!    or
//!   \b SYSCTL_PLL_DISABLE-This is to Power Down the PLL and Bypass the
//!    PLLCLK to the System.
//!
//! - The integer multiplier is chosen \b SYSCTL_IMULT(x) where x is a value
//!   from 1 to 127.
//!
//!
//! - The oscillator source chosen with \b SYSCTL_OSCSRC_OSC2,
//!   \b SYSCTL_OSCSRC_XTAL, \b SYSCTL_OSCSRC_XTAL_SE or \b SYSCTL_OSCSRC_OSC1.
//!
//! This function uses the DCC to check that the PLLRAWCLK is running at the
//! expected rate. If you are using the DCC, you must back up its configuration
//! before calling this function and restore it afterward.
//! Locking PLL sequence is only done if the multipliers are updated.
//!
//! \note See your device errata for more details about locking the PLL.
//!
//! \return Returns \b false if a missing clock error is detected. This needs
//! to be cleared (see SysCtl_resetMCD()) before trying to call this function
//! again. Also, returns \b false if the PLLRAWCLK is not running and its
//! expected rate. Otherwise, returns \b true.
//
//*****************************************************************************
extern bool
SysCtl_setClock(uint32_t config);

//*****************************************************************************
//
//! Validates PLL Raw Clock Frequency (PLLRAWCLK)
//!
//! \param base is the DCC module base address
//! \param oscSource is the Clock Source for the PLL that is also used for DCC
//! \param pllMultDiv has the PLL Multiplier Register configuration which
//!  include integer multiplier and divider values used to configure the
//!  DCC Counter1 clock
//!
//!  This function uses DCC module to validate the PLL clock frequency.
//!  It uses oscSource as a reference clock for DCC, and PLL is used as clock
//!  under test. As long as the Counter0 (running of oscSource) & Counter1
//!  (running of PLL) expire at the same time, DCC will not generate an Error.
//!  This function gives 100 attempts for PLL to lock and make sure frequency
//!  is as expected.
//!
//!  \note This function does not validate if PLL output frequency (PLLRAWCLK)
//!  is within the operating range as per the datasheet.
//!
//! - The \e oscSource parameter is the oscillator source chosen with
//!   \b SYSCTL_OSCSRC_OSC2, \b SYSCTL_OSCSRC_XTAL, \b SYSCTL_OSCSRC_XTAL_SE
//!    or \b SYSCTL_OSCSRC_OSC1.
//!
//! - The \e pllMultDiv parameter is a bitwise OR of \b SYSCTL_IMULT(x)
//!   where x is a value from 1 to 127 and both of the following divider
//!   values which is chosen with the macro \b SYSCTL_REFDIV(x) and
//!   SYSCTL_ODIV(x) where x is a value from 1 to 32 and can be different
//!   for both macros.
//!
//!  \return Returns \b true if the DCCSTATUS error flag is not set.
//!    Otherwise, returns \b false.
//
//*****************************************************************************
extern bool
SysCtl_isPLLValid(uint32_t base, uint32_t oscSource, uint32_t pllMultDiv);
//*****************************************************************************
//
//! Configures the external oscillator for the clocking of the device.
//!
//! This function configures the external oscillator (XTAL) to be used for the
//! clocking of the device in crystal mode. It follows the procedure to turn on
//! the oscillator, wait for it to power up, and select it as the source of the
//! system clock.
//!
//! Please note that this function blocks while it waits for the XTAL to power
//! up. If the XTAL does not manage to power up properly, the function will
//! loop for a long time. It is recommended that you modify this function to
//! add an appropriate timeout and error-handling procedure.
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_selectXTAL(void);

//*****************************************************************************
//
//! Configures the external oscillator for the clocking of the device in
//! single-ended mode.
//!
//! This function configures the external oscillator (XTAL) to be used for the
//! clocking of the device in single-ended mode. It follows the procedure to
//! turn on the oscillator, wait for it to power up, and select it as the
//! source of the system clock.
//!
//! Please note that this function blocks while it waits for the XTAL to power
//! up. If the XTAL does not manage to power up properly, the function will
//! loop for a long time. It is recommended that you modify this function to
//! add an appropriate timeout and error-handling procedure.
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_selectXTALSingleEnded(void);

//*****************************************************************************
//
//! Selects the oscillator to be used for the clocking of the device.
//!
//! \param oscSource is the oscillator source to be configured.
//!
//! This function configures the oscillator to be used in the clocking of the
//! device. The \e oscSource parameter may take a value of
//! \b SYSCTL_OSCSRC_OSC2, \b SYSCTL_OSCSRC_XTAL, \b SYSCTL_OSCSRC_XTAL_SE, or
//! \b SYSCTL_OSCSRC_OSC1.
//!
//! \sa SysCtl_turnOnOsc()
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_selectOscSource(uint32_t oscSource);

//*****************************************************************************
//
//! Calculates the low-speed peripheral clock frequency (BUSCLK).
//!
//! \param clockInHz is the frequency of the oscillator clock source (OSCCLK).
//!
//! This function determines the frequency of the low-speed peripheral clock
//! based on the frequency of the oscillator clock source (from \e clockInHz)
//! and the PLL and clock divider configuration registers.
//!
//! \return Returns the low-speed peripheral clock frequency.
//
//*****************************************************************************
extern uint32_t
SysCtl_getLowSpeedClock(uint32_t clockInHz);

//*****************************************************************************
//
//! Get the device part parametric value
//!
//! \param parametric is the requested device parametric value
//!
//! This function gets the device part parametric value.
//!
//! The \e parametric parameter can have one the following enumerated values:
//! - \b SYSCTL_DEVICE_QUAL      - Device Qualification Status
//! - \b SYSCTL_DEVICE_PINCOUNT  - Device Pin Count
//! - \b SYSCTL_DEVICE_INSTASPIN - Device InstaSPIN Feature Set
//! - \b SYSCTL_DEVICE_FLASH     - Device Flash size (KB)
//! - \b SYSCTL_DEVICE_FAMILY    - Device Family
//! - \b SYSCTL_DEVICE_PARTNO    - Device Part Number
//! - \b SYSCTL_DEVICE_CLASSID   - Device Class ID
//!
//! \note This API is applicable only for the CPU1 subsystem.
//!
//! \return Returns the specified parametric value.
//
//*****************************************************************************
extern uint16_t
SysCtl_getDeviceParametric(SysCtl_DeviceParametric parametric);


//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // SYSCTL_H
