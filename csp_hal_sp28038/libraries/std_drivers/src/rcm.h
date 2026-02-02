/*
  ******************************************************************************
  * @file           : rcm.h
  * @brief          : rcm driver header file
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
#ifndef _RCM_H_
#define _RCM_H_

#include "driver_common.h"

/*! @addtogroup rcm */
/*! @{*/

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*!
 * @brief System Reset Source Name definitions
 */
typedef enum _rcm_reset_source
{
/* RCM register bit width is 8. */
    RCM_SourceLvd     = RCM_SRS0_VDT_MASK,           /*!< Low-voltage detect reset */
    RCM_SourceWdog    = RCM_SRS0_WWDT_MASK,          /*!< Watchdog reset */
    RCM_SourcePin     = RCM_SRS0_RSTPIN_MASK,           /*!< External pin reset */
    RCM_SourcePor     = RCM_SRS0_POR_MASK,           /*!< Power on reset */    
    RCM_SourceJtag    = RCM_SRS1_JTAG_MASK << 8U,    /*!< JTAG generated reset */    
    RCM_SourceLockup  = RCM_SRS1_LOCKUP_MASK << 8U,  /*!< Core lock up reset */
    RCM_SourceSw      = RCM_SRS1_SW_MASK << 8U,      /*!< Software reset */    
    
    RCM_SourceAll = (int)0xffffffffU,
} rcm_reset_source_t;

/*!
 * @brief Reset pin filter select in Run and Wait modes.
 */
typedef enum _rcm_run_wait_filter_mode
{
    RCM_FilterDisable  = 0U, /*!< All filtering disabled */
    RCM_FilterBusClock = 1U, /*!< Bus clock filter enabled */
    RCM_FilterLpoClock = 2U  /*!< LPO clock filter enabled */
} rcm_run_wait_filter_mode_t;


/*!
 * @brief Reset pin filter configuration.
 */
typedef struct _rcm_reset_pin_filter_config
{
    bool enableFilterInStop;                    /*!< Reset pin filter select in stop mode. */
    rcm_run_wait_filter_mode_t filterInRunWait; /*!< Reset pin filter in run/wait mode. */
    uint8_t busClockFilterCount;                /*!< Reset pin bus clock filter width.  */
} rcm_reset_pin_filter_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*! @name Reset Control Module APIs*/
/*@{*/



/*!
 * @brief Gets the reset source status which caused a previous reset.
 *
 * This function gets the current reset source status. Use source masks
 * defined in the rcm_reset_source_t to get the desired source status.
 *
 * This is an example.
 * @code
 * uint32_t resetStatus;
 *
 * To get all reset source statuses.
 * resetStatus = RCM_GetPreviousResetSources(RCM) & RCM_SourceAll;
 *
 * To test whether the MCU is reset using Watchdog.
 * resetStatus = RCM_GetPreviousResetSources(RCM) & RCM_SourceWdog;
 *
 * To test multiple reset sources.
 * resetStatus = RCM_GetPreviousResetSources(RCM) & (RCM_SourceWdog | RCM_SourcePin);
 * @endcode
 *
 * @param base RCM peripheral base address.
 * @return All reset source status bit map.
 */
static uint32_t RCM_GetPreviousResetSources(RCM_Type *base)
{
    uint8_t tmpSrs0 = base->SRS0;
    uint8_t tmpSrs1 = base->SRS1;
    return (uint32_t)((uint32_t)tmpSrs0 | ((uint32_t)tmpSrs1 << 8U));
}

/*!
 * @brief Gets the sticky reset source status.
 *
 * This function gets the current reset source status that has not been cleared
 * by software for a specific source.
 *
 * This is an example.
 * @code
 * uint32_t resetStatus;
 *
 * To get all reset source statuses.
 * resetStatus = RCM_GetStickyResetSources(RCM) & RCM_SourceAll;
 *
 * To test whether the MCU is reset using Watchdog.
 * resetStatus = RCM_GetStickyResetSources(RCM) & RCM_SourceWdog;
 *
 * To test multiple reset sources.
 * resetStatus = RCM_GetStickyResetSources(RCM) & (RCM_SourceWdog | RCM_SourcePin);
 * @endcode
 *
 * @param base RCM peripheral base address.
 * @return All reset source status bit map.
 */
static uint32_t RCM_GetStickyResetSources(RCM_Type *base)
{
    return (base->SSRS0 | ((uint32_t)base->SSRS1 << 8U));
}

/*!
 * @brief Clears the sticky reset source status.
 *
 * This function clears the sticky system reset flags indicated by source masks.
 *
 * This is an example.
 * @code
 * Clears multiple reset sources.
 * RCM_ClearStickyResetSources(RCM_SourceWdog | RCM_SourcePin);
 * @endcode
 *
 * @param base RCM peripheral base address.
 * @param sourceMasks reset source status bit map
 */
static void RCM_ClearStickyResetSources(RCM_Type *base, uint32_t sourceMasks)
{
    base->SSRS0 = (uint8_t)(sourceMasks & 0xffU);
    base->SSRS1 = (uint8_t)((sourceMasks >> 8U) & 0xffU);
}

/*!
 * @brief Configures the reset pin filter.
 *
 * This function sets the reset pin filter including the filter source, filter
 * width, and so on.
 *
 * @param base RCM peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void RCM_ConfigureResetPinFilter(RCM_Type *base, const rcm_reset_pin_filter_config_t *config);

/*@}*/

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* _RCM_H_ */
