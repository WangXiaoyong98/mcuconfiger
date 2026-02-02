/*
  ******************************************************************************
  * @file           : hw_types.h
  * @brief          : type definitions for hardware access
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

#ifndef HW_TYPES_H
#define HW_TYPES_H

//*****************************************************************************
//
// Macros for hardware access
// caution: most of SP28038 registers are 32-bits access, take care to use half
// word or byte access.
//*****************************************************************************
    #define HWREG(x)                                                          \
            (*((volatile uint32_t *)(x)))
//    #define HWREGH(x)                                                       \
//            (*((volatile uint16_t *)(x)))
//    #define HWREGB(x)                                                       \
//            (*((volatile uint8_t *)(x)))
//*****************************************************************************
//
// SUCCESS and FAILURE for API return value
//
//*****************************************************************************
#define STATUS_S_SUCCESS    (0)
#define STATUS_E_FAILURE    (-1)
                  


//****************************************************************************
//
// For checking NULL pointers
//
//****************************************************************************
#ifndef NULL
#define NULL ((void *)0x0)
#endif

//*****************************************************************************
//
// 32-bit and 64-bit float type
//
//*****************************************************************************
typedef float         float32_t;
typedef long double   float64_t;


//
// C++ Bool Compatibility
//
#if defined(__cplusplus)
typedef bool _Bool;
#endif

/* To fix Misra-C errors */
#ifndef TRUE
#define TRUE  ((bool) 1)
#endif
#ifndef FALSE
#define FALSE ((bool) 0)
#endif

#endif // HW_TYPES_H
