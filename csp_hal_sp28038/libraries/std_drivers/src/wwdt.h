/*
  ******************************************************************************
  * @file           : wwdt.h
  * @brief          : wwdt program body
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
#ifndef _WWDT_H_
#define _WWDT_H_

#include "driver_common.h"

/*!
 * @addtogroup wwdt
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/
/* WDOG module features */

/* @brief Watchdog is available. */



/*! @name Unlock sequence */
/*@{*/
#define WWDT_FIRST_WORD_OF_UNLOCK  (0xC520U) /*!< First word of unlock sequence */
#define WWDT_SECOND_WORD_OF_UNLOCK (0xD928U) /*!< Second word of unlock sequence */
/*@}*/

/*! @name Refresh sequence */
/*@{*/
#define WWDT_FIRST_WORD_OF_REFRESH  (0xA602U) /*!< First word of refresh sequence */
#define WWDT_SECOND_WORD_OF_REFRESH (0xB480U) /*!< Second word of refresh sequence */
/*@}*/

/*! @brief Describes WWDT clock source. */
typedef enum _wwdt_clock_source
{
    WWDT_LpoClockSource       = 0U, /*!< WWDT clock sourced from LPO*/
    WWDT_AlternateClockSource = 1U, /*!< WWDT clock sourced from alternate clock source*/
} wwdt_clock_source_t;

/*! @brief Defines WWDT work mode. */
typedef struct _wwdt_work_mode
{
    bool enableWait;  /*!< Enables or disables WWDT in wait mode  */
    bool enableStop;  /*!< Enables or disables WWDT in stop mode  */
    bool enableDebug; /*!< Enables or disables WWDT in debug mode */
} wwdt_work_mode_t;

/*! @brief Describes the selection of the clock prescaler. */
typedef enum _wwdt_clock_prescaler
{
    WWDT_ClockPrescalerDivide1 = 0x0U, /*!< Divided by 1 */
    WWDT_ClockPrescalerDivide2 = 0x1U, /*!< Divided by 2 */
    WWDT_ClockPrescalerDivide3 = 0x2U, /*!< Divided by 3 */
    WWDT_ClockPrescalerDivide4 = 0x3U, /*!< Divided by 4 */
    WWDT_ClockPrescalerDivide5 = 0x4U, /*!< Divided by 5 */
    WWDT_ClockPrescalerDivide6 = 0x5U, /*!< Divided by 6 */
    WWDT_ClockPrescalerDivide7 = 0x6U, /*!< Divided by 7 */
    WWDT_ClockPrescalerDivide8 = 0x7U, /*!< Divided by 8 */
} wwdt_clock_prescaler_t;

/*! @brief Describes WWDT configuration structure. */
typedef struct _wwdt_config
{
    bool enableWdog;                  /*!< Enables or disables WWDT */
    wwdt_clock_source_t clockSource;  /*!< Clock source select */
    wwdt_clock_prescaler_t prescaler; /*!< Clock prescaler value */
    wwdt_work_mode_t workMode;        /*!< Configures WWDT work mode in debug stop and wait mode */
    bool enableUpdate;                /*!< Update write-once register enable */
    bool enableInterrupt;             /*!< Enables or disables WWDT interrupt */
    bool enableWindowMode;            /*!< Enables or disables WWDT window mode */
    uint32_t windowValue;             /*!< Window value */
    uint32_t timeoutValue;            /*!< Timeout value */
} wwdt_config_t;

/*! @brief Describes WWDT test mode. */
typedef enum _wwdt_test_mode
{
    WWDT_QuickTest = 0U, /*!< Selects quick test */
    WWDT_ByteTest  = 1U, /*!< Selects byte test */
} wwdt_test_mode_t;

/*! @brief Describes WWDT tested byte selection in byte test mode. */
typedef enum _wwdt_tested_byte
{
    WWDT_TestByte0 = 0U, /*!< Byte 0 selected in byte test mode */
    WWDT_TestByte1 = 1U, /*!< Byte 1 selected in byte test mode */
    WWDT_TestByte2 = 2U, /*!< Byte 2 selected in byte test mode */
    WWDT_TestByte3 = 3U, /*!< Byte 3 selected in byte test mode */
} wwdt_tested_byte_t;

/*! @brief Describes WWDT test mode configuration structure. */
typedef struct _wwdt_test_config
{
    wwdt_test_mode_t testMode;     /*!< Selects test mode */
    wwdt_tested_byte_t testedByte; /*!< Selects tested byte in byte test mode */
    uint32_t timeoutValue;         /*!< Timeout value */
} wwdt_test_config_t;

/*!
 * @brief WWDT interrupt configuration structure, default settings all disabled.
 *
 * This structure contains the settings for all of the WWDT interrupt configurations.
 */
enum _wwdt_interrupt_enable_t
{
    WWDT_InterruptEnable = WWDT_STCTRLH_IRQRSTEN_MASK, /*!< WWDT timeout generates an interrupt before reset*/
};

/*!
 * @brief WWDT status flags.
 *
 * This structure contains the WWDT status flags for use in the WWDT functions.
 */
enum _wwdt_status_flags_t
{
    WWDT_RunningFlag = WWDT_STCTRLH_WWDTEN_MASK, /*!< Running flag, set when WWDT is enabled*/
    WWDT_TimeoutFlag = WWDT_STCTRLL_INTFLG_MASK, /*!< Interrupt flag, set when an exception occurs*/
};

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name WWDT Initialization and De-initialization
 * @{
 */

/*!
 * @brief Initializes the WWDT configuration structure.
 *
 * This function initializes the WWDT configuration structure to default values. The default
 * values are as follows.
 * @code
 *   wwdtConfig->enableWdog = true;
 *   wwdtConfig->clockSource = WWDT_LpoClockSource;
 *   wwdtConfig->prescaler = WWDT_ClockPrescalerDivide1;
 *   wwdtConfig->workMode.enableWait = true;
 *   wwdtConfig->workMode.enableStop = false;
 *   wwdtConfig->workMode.enableDebug = false;
 *   wwdtConfig->enableUpdate = true;
 *   wwdtConfig->enableInterrupt = false;
 *   wwdtConfig->enableWindowMode = false;
 *   wwdtConfig->windowValue = 0;
 *   wwdtConfig->timeoutValue = 0xFFFFU;
 * @endcode
 *
 * @param config Pointer to the WWDT configuration structure.
 * @see wwdt_config_t
 */
void WWDT_GetDefaultConfig(wwdt_config_t *config);

/*!
 * @brief Initializes the WWDT.
 *
 * This function initializes the WWDT. When called, the WWDT runs according to the configuration.
 * To reconfigure WWDT without forcing a reset first, enableUpdate must be set to true
 * in the configuration.
 *
 * This is an example.
 * @code
 *   wwdt_config_t config;
 *   WWDT_GetDefaultConfig(&config);
 *   config.timeoutValue = 0x7ffU;
 *   config.enableUpdate = true;
 *   WWDT_Init(wwdt_base,&config);
 * @endcode
 *
 * @param base   WWDT peripheral base address
 * @param config The configuration of WWDT
 */
void WWDT_Init(WWDT_Type *base, const wwdt_config_t *config);

/*!
 * @brief Shuts down the WWDT.
 *
 * This function shuts down the WWDT.
 * Ensure that the WWDT_STCTRLH.ALLOWUPDATE is 1 which indicates that the register update is enabled.
 */
void WWDT_Deinit(WWDT_Type *base);

/*!
 * @brief Configures the WWDT functional test.
 *
 * This function is used to configure the WWDT functional test. When called, the WWDT goes into test mode
 * and runs according to the configuration.
 * Ensure that the WWDT_STCTRLH.ALLOWUPDATE is 1 which means that the register update is enabled.
 *
 * This is an example.
 * @code
 *   wwdt_test_config_t test_config;
 *   test_config.testMode = WWDT_QuickTest;
 *   test_config.timeoutValue = 0xfffffu;
 *   WWDT_SetTestModeConfig(wwdt_base, &test_config);
 * @endcode
 * @param base   WWDT peripheral base address
 * @param config The functional test configuration of WWDT
 */
void WWDT_SetTestModeConfig(WWDT_Type *base, wwdt_test_config_t *config);

/* @} */

/*!
 * @name WWDT Functional Operation
 * @{
 */

/*!
 * @brief Enables the WWDT module.
 *
 * This function write value into WWDT_STCTRLH register to enable the WWDT, it is a write-once register,
 * make sure that the WCT window is still open and this register has not been written in this WCT
 * while this function is called.
 *
 * @param base WWDT peripheral base address
 */
static inline void WWDT_Enable(WWDT_Type *base)
{
    base->STCTRLH |= WWDT_STCTRLH_WWDTEN_MASK;
}

/*!
 * @brief Disables the WWDT module.
 *
 * This function writes a value into the WWDT_STCTRLH register to disable the WWDT. It is a write-once register.
 * Ensure that the WCT window is still open and that register has not been written to in this WCT
 * while the function is called.
 *
 * @param base WWDT peripheral base address
 */
static inline void WWDT_Disable(WWDT_Type *base)
{
    base->STCTRLH &= ~(uint16_t)WWDT_STCTRLH_WWDTEN_MASK;
}

/*!
 * @brief Enables the WWDT interrupt.
 *
 * This function writes a value into the WWDT_STCTRLH register to enable the WWDT interrupt. It is a write-once
 * register.
 * Ensure that the WCT window is still open and the register has not been written to in this WCT
 * while the function is called.
 *
 * @param base WWDT peripheral base address
 * @param mask The interrupts to enable
 *        The parameter can be combination of the following source if defined.
 *        @arg WWDT_InterruptEnable
 */
static inline void WWDT_EnableInterrupts(WWDT_Type *base, uint32_t mask)
{
    base->STCTRLH |= (uint16_t)mask;
}

/*!
 * @brief Disables the WWDT interrupt.
 *
 * This function writes a value into the WWDT_STCTRLH register to disable the WWDT interrupt. It is a write-once
 * register.
 * Ensure that the WCT window is still open and the register has not been written to in this WCT
 * while the function is called.
 *
 * @param base WWDT peripheral base address
 * @param mask The interrupts to disable
 *        The parameter can be combination of the following source if defined.
 *        @arg WWDT_InterruptEnable
 */
static inline void WWDT_DisableInterrupts(WWDT_Type *base, uint32_t mask)
{
    base->STCTRLH &= (uint16_t)~mask;
}

/*!
 * @brief Gets the WWDT all status flags.
 *
 * This function gets all status flags.
 *
 * This is an example for getting the Running Flag.
 * @code
 *   uint32_t status;
 *   status = WWDT_GetStatusFlags (wwdt_base) & WWDT_RunningFlag;
 * @endcode
 * @param base        WWDT peripheral base address
 * @return            State of the status flag: asserted (true) or not-asserted (false).@see _wwdt_status_flags_t
 *                    - true: a related status flag has been set.
 *                    - false: a related status flag is not set.
 */
uint32_t WWDT_GetStatusFlags(WWDT_Type *base);

/*!
 * @brief Clears the WWDT flag.
 *
 * This function clears the WWDT status flag.
 *
 * This is an example for clearing the timeout (interrupt) flag.
 * @code
 *   WWDT_ClearStatusFlags(wwdt_base,WWDT_TimeoutFlag);
 * @endcode
 * @param base        WWDT peripheral base address
 * @param mask        The status flags to clear.
 *                    The parameter could be any combination of the following values.
 *                    WWDT_TimeoutFlag
 */
void WWDT_ClearStatusFlags(WWDT_Type *base, uint32_t mask);

/*!
 * @brief Sets the WWDT timeout value.
 *
 * This function sets the timeout value.
 * It should be ensured that the time-out value for the WWDT is always greater than
 * 2xWCT time + 20 bus clock cycles.
 * This function writes a value into WWDT_TOVALH and WWDT_TOVALL registers which are wirte-once.
 * Ensure the WCT window is still open and the two registers have not been written to in this WCT
 * while the function is called.
 *
 * @param base WWDT peripheral base address
 * @param timeoutCount WWDT timeout value; count of WWDT clock tick.
 */
static inline void WWDT_SetTimeoutValue(WWDT_Type *base, uint32_t timeoutCount)
{
    base->TOVALH = (uint16_t)((timeoutCount >> 16U) & 0xFFFFU);
    base->TOVALL = (uint16_t)((timeoutCount)&0xFFFFU);
}

/*!
 * @brief Sets the WWDT window value.
 *
 * This function sets the WWDT window value.
 * This function writes a value into WWDT_WINH and WWDT_WINL registers which are wirte-once.
 * Ensure the WCT window is still open and the two registers have not been written to in this WCT
 * while the function is called.
 *
 * @param base WWDT peripheral base address
 * @param windowValue WWDT window value.
 */
static inline void WWDT_SetWindowValue(WWDT_Type *base, uint32_t windowValue)
{
    base->WINH = (uint16_t)((windowValue >> 16U) & 0xFFFFU);
    base->WINL = (uint16_t)((windowValue)&0xFFFFU);
}

/*!
 * @brief Unlocks the WWDT register written.
 *
 * This function unlocks the WWDT register written.
 * Before starting the unlock sequence and following configuration, disable the global interrupts.
 * Otherwise, an interrupt may invalidate the unlocking sequence and the WCT may expire.
 * After the configuration finishes, re-enable the global interrupts.
 *
 * @param base WWDT peripheral base address
 */
static inline void WWDT_Unlock(WWDT_Type *base)
{
    base->UNLOCK = WWDT_FIRST_WORD_OF_UNLOCK;
    base->UNLOCK = WWDT_SECOND_WORD_OF_UNLOCK;
}

/*!
 * @brief Refreshes the WWDT timer.
 *
 * This function feeds the WWDT.
 * This function should be called before the WWDT timer is in timeout. Otherwise, a reset is asserted.
 *
 * @param base WWDT peripheral base address
 */
void WWDT_Refresh(WWDT_Type *base);

/*!
 * @brief Gets the WWDT reset count.
 *
 * This function gets the WWDT reset count value.
 *
 * @param base WWDT peripheral base address
 * @return     WWDT reset count value.
 */
static inline uint16_t WWDT_GetResetCount(WWDT_Type *base)
{
    return base->RSTCNT;
}
/*!
 * @brief Clears the WWDT reset count.
 *
 * This function clears the WWDT reset count value.
 *
 * @param base WWDT peripheral base address
 */
static inline void WWDT_ClearResetCount(WWDT_Type *base)
{
    base->RSTCNT |= (uint16_t)UINT16_MAX;
}

/*@}*/

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* _WWDT_H_ */
