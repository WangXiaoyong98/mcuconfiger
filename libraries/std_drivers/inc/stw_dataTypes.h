/*
  ******************************************************************************
  * @file           : stw_dataTypes.h
  * @brief          : header file containing standard data types.
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


#ifndef STW_DATATYPES_H_
#define STW_DATATYPES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

typedef uint16_t      Bool; /* In sync with xdc/std.h */
typedef uint32_t      UInt32;
typedef int32_t       Int32;
typedef uint16_t      UInt16;
typedef int16_t       Int16;
typedef char          Char;
typedef void *        Ptr;
typedef uint32_t      UArg;
typedef double        Double;
typedef uint64_t      UInt64;
typedef unsigned char tBoolean;
typedef float         Float32;

/* To fix Misra-C errors */
#ifndef TRUE
#define TRUE  ((Bool) 1)
#endif
#ifndef FALSE
#define FALSE ((Bool) 0)
#endif

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef STW_DATATYPES_H_ */
