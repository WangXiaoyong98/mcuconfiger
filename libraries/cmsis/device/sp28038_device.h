//###########################################################################
//
// FILE:   sp28038_device.h
//
// TITLE:  sp28038 Device Definitions.
//
//###########################################################################
//
//
// $Copyright:
// $
//###########################################################################

#ifndef SP28038_DEVICE_H
#define SP28038_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif



#define  EINT
#define  DINT
#define  ERTM
#define  DRTM

#define  EALLOW
 

#define  EDIS
#define  ESTOP0

#define M_INT1  0x0001
#define M_INT2  0x0002
#define M_INT3  0x0004
#define M_INT4  0x0008
#define M_INT5  0x0010
#define M_INT6  0x0020
#define M_INT7  0x0040
#define M_INT8  0x0080
#define M_INT9  0x0100
#define M_INT10 0x0200
#define M_INT11 0x0400
#define M_INT12 0x0800
#define M_INT13 0x1000
#define M_INT14 0x2000
#define M_DLOG  0x4000
#define M_RTOS  0x8000

#define BIT0    0x00000001
#define BIT1    0x00000002
#define BIT2    0x00000004
#define BIT3    0x00000008
#define BIT4    0x00000010
#define BIT5    0x00000020
#define BIT6    0x00000040
#define BIT7    0x00000080
#define BIT8    0x00000100
#define BIT9    0x00000200
#define BIT10   0x00000400
#define BIT11   0x00000800
#define BIT12   0x00001000
#define BIT13   0x00002000
#define BIT14   0x00004000
#define BIT15   0x00008000
#define BIT16   0x00010000
#define BIT17   0x00020000
#define BIT18   0x00040000
#define BIT19   0x00080000
#define BIT20   0x00100000
#define BIT21   0x00200000
#define BIT22   0x00400000
#define BIT23   0x00800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000

//
// For Portability, User Is Recommended To Use the C99 Standard integer types
//
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
//
// C++ Bool Compatibility
//
#if defined(__cplusplus)
typedef bool _Bool;
#endif

//
// C99 defines boolean type to be _Bool, but this doesn't match the format of
// the other standard integer types.  bool_t has been defined to fill this gap.
//
typedef _Bool bool_t;

//
// Used for a bool function return status
//
typedef _Bool status_t;

#ifndef SUCCESS
#define SUCCESS     true
#endif

#ifndef FAIL
#define FAIL        false
#endif

//
// The following data types are included for compatibility with legacy code,
// they are not recommended for use in new software.  Please use the C99
// types included above
//
typedef short                                   int16;
typedef int                                     int32;
typedef long long                               int64;
typedef unsigned short                          Uint16;
typedef unsigned int                            Uint32;
typedef unsigned long long                      Uint64;
typedef float                                   float32;
//typedef float         float32_t;
//typedef long double   float64_t;


//
// The following data types are for use with byte addressable peripherals.
// See compiler documentation on the byte_peripheral type attribute.
//
typedef unsigned short bp_16;
typedef unsigned int bp_32;

/*!
 * @name Time sensitive region
 * @{
 */
#if (defined(__ICCARM__))
#define AT_QUICKACCESS_SECTION_CODE(func) func @"CodeQuickAccess"
#define AT_QUICKACCESS_SECTION_DATA(var)  var @"DataQuickAccess"
#define AT_QUICKACCESS_SECTION_DATA_ALIGN(var, alignbytes) \
    SDK_PRAGMA(data_alignment = alignbytes) var @"DataQuickAccess"
#elif (defined(__CC_ARM) || defined(__ARMCC_VERSION))
#define AT_QUICKACCESS_SECTION_CODE(func) __attribute__((section("CodeQuickAccess"), __noinline__)) func
#define AT_QUICKACCESS_SECTION_DATA(var)  __attribute__((section("DataQuickAccess"))) var
#define AT_QUICKACCESS_SECTION_DATA_ALIGN(var, alignbytes) \
    __attribute__((section("DataQuickAccess"))) __attribute__((aligned(alignbytes))) var
#elif (defined(__GNUC__))
#define AT_QUICKACCESS_SECTION_CODE(func) __attribute__((section("CodeQuickAccess"), __noinline__)) func
#define AT_QUICKACCESS_SECTION_DATA(var)  __attribute__((section("DataQuickAccess"))) var
#define AT_QUICKACCESS_SECTION_DATA_ALIGN(var, alignbytes) \
    __attribute__((section("DataQuickAccess"))) var __attribute__((aligned(alignbytes)))
#else
#error Toolchain not supported.
#endif /* defined(__ICCARM__) */

/*! @name Ram Function */
#if (defined(__ICCARM__))
#define RAMFUNCTION_SECTION_CODE(func) func @"RamFunction"
#elif (defined(__CC_ARM) || defined(__ARMCC_VERSION))
#define RAMFUNCTION_SECTION_CODE(func) __attribute__((section("RamFunction"))) func
#elif (defined(__GNUC__))
#define RAMFUNCTION_SECTION_CODE(func) __attribute__((section("RamFunction"))) func
#else
#error Toolchain not supported.
#endif /* defined(__ICCARM__) */
//
// Include All Peripheral Header Files:
//
#include "hw_memmap.h"
#include "sp28038.h"
#if 0
#include "sp28038_adc.h"
#include "sp28038_crc.h"
//#include "f28003x_cmpss.h"
//#include "f28003x_cputimer.h"
#include "sp28038_dma.h"
#include "sp28038_ecap.h"
#include "sp28038_epwm.h"
#include "sp28038_epwm_xbar.h"
#include "sp28038_eqep.h"
#include "sp28038_flash.h"
#include "sp28038_gpio.h"
#include "sp28038_i2c.h"
#include "sp28038_input_xbar.h"
//#include "f28003x_memconfig.h"
#include "sp28038_output_xbar.h"
#include "sp28038_sci.h"
//#include "f28003x_sdfm.h"
//#include "f28003x_spi.h"
#include "sp28038_sysctrl.h"
#include "sp28038_wwd.h"
#include "sp28038_ewm.h"
#include "sp28038_xbar.h"
#include "sp28038_xint.h"
//#include "f28003x_tempsensorconv.h"
#include "sp28038_spi.h"

#include "sp28038_mcan.h"
#include "sp28038_ptim.h"
#include "sp28038_lptim.h"
#include "sp28038_aes.h"
#include "sp28038_dcc.h"
#endif    


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif                                  // end of SP28038_DEVICE_H definition

//===========================================================================
// End of file.
//===========================================================================
