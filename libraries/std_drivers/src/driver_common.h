/*
  ******************************************************************************
  * @file           : driver_common.h
  * @brief          : common definitions for drivers
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
#ifndef _DRIVER_COMMON_H_
#define _DRIVER_COMMON_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "sp28038.h"
#include "assert.h"

#define MAKE_STATUS(group, code) ((((group)*100) + (code)))

/*! \public
 * @brief Generic status return codes.
 */
 enum _status_groups
{
    sStatusGroup_Generic = 0,                 /*!< Group number for generic status codes. */
    sStatusGroup_I2C = 1,                     /*!< Group number for UART status codes. */
    sStatusGroup_SCI = 2,                     /*!< Group number for LPSCI status codes. */
    sStatusGroup_SPI = 3,                     /*!< Group number for SPI status code.*/
    sStatusGroup_MCAN = 4,                    /*!< Group number for MCAN status codes. */
    sStatusGroup_DMA = 5,                     /*!< Group number for DMA status codes. */
    
    sStatusGroup_HAL_GPIO = 80,              /*!< Group number for HAL GPIO status codes. */
    sStatusGroup_HAL_UART = 81,              /*!< Group number for HAL UART status codes. */
    sStatusGroup_HAL_LPTIM = 82,             /*!< Group number for HAL TIMER status codes. */
    sStatusGroup_HAL_SPI = 83,               /*!< Group number for HAL SPI status codes. */
    sStatusGroup_HAL_I2C = 84,               /*!< Group number for HAL I2C status codes. */
};
enum
{
    sStatus_Success = MAKE_STATUS(sStatusGroup_Generic, 0),  /*!< Generic status for Success. */
    sStatus_Fail = MAKE_STATUS(sStatusGroup_Generic, 1),      /*!< Generic status for Fail. */
    sStatus_ReadOnly = MAKE_STATUS(sStatusGroup_Generic, 2),    /*!< Generic status for read only failure. */
    sStatus_OutOfRange = MAKE_STATUS(sStatusGroup_Generic, 3),   /*!< Generic status for out of range access. */
    sStatus_InvalidArgument = MAKE_STATUS(sStatusGroup_Generic, 4),   /*!< Generic status for invalid argument check. */
    sStatus_Timeout = MAKE_STATUS(sStatusGroup_Generic, 5),   /*!< Generic status for timeout. */
    sStatus_NoTransferInProgress = MAKE_STATUS(sStatusGroup_Generic, 6),   /*!< Generic status for no transfer in progress. */
};

/*! @brief Type used for all status and error return values. */
typedef int32_t sstat_t;

/*! @name Min/max macros */
/* @{ */
#if !defined(MIN)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#if !defined(MAX)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif
/* @} */

/*! @brief Computes the number of elements in an array. */
#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

/*! @name ISR exit barrier
 * @{
 *
 * ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
 * exception return operation might vector to incorrect interrupt.
 * For Cortex-M7, if core speed much faster than peripheral register write speed,
 * the peripheral interrupt flags may be still set after exiting ISR, this results to
 * the same error similar with errata 83869.
 */
#define SDK_ISR_EXIT_BARRIER __DSB()

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
        void DefaultISR(void);
#endif
/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
        extern "C"
{
#endif

    /*!
     * @brief Enable specific interrupt.
     * @param interrupt The IRQ number.
     * @retval sStatus_Success Interrupt enabled successfully
     * @retval sStatus_Fail Failed to enable the interrupt
     */
    static inline sstat_t EnableIRQ(IRQn_Type interrupt)
    {
        if(interrupt == Unused_IRQn)
        {
            return  sStatus_Fail;
        }
        NVIC_EnableIRQ(interrupt);

        return sStatus_Success;
    }

    /*!
     * @brief Disable specific interrupt.
     *
     * @param interrupt The IRQ number.
     * @retval sStatus_Success Interrupt disabled successfully
     * @retval sStatus_Fail Failed to disable the interrupt
     */
    static inline sstat_t DisableIRQ(IRQn_Type interrupt)
    {
        if(interrupt == Unused_IRQn)
        {
            return  sStatus_Fail;
        }
        NVIC_DisableIRQ(interrupt);
        
        return sStatus_Success;
    }

    /*!
     * @brief Disable the global IRQ
     *
     * Disable the global interrupt and return the current primask register. User is required to provided the primask
     * register for the EnableGlobalIRQ().
     *
     * @return Current primask value.
     */
    static inline uint32_t DisableGlobalIRQ(void)
    {
    uint32_t regPrimask = __get_PRIMASK();

    __disable_irq();

    return regPrimask;
    }

    /*!
     * @brief Enable the global IRQ
     *
     * Set the primask register with the provided primask value but not just enable the primask. The idea is for the
     * convenience of integration of RTOS. some RTOS get its own management mechanism of primask. User is required to
     * use the EnableGlobalIRQ() and DisableGlobalIRQ() in pair.
     *
     * @param primask value of primask register to be restored. The primask value is supposed to be provided by the
     * DisableGlobalIRQ().
     */
    static inline void EnableGlobalIRQ(uint32_t primask)
    {
        __set_PRIMASK(primask);
    }

#if defined(__cplusplus)
}
#endif

#endif /* _DRIVER_COMMON_H_ */
