/*
  ******************************************************************************
  * @file           : dma.h
  * @brief          : dma hal driver header file
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
#ifndef _DMA_H_
#define _DMA_H_

#include "driver_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DMA_CHANNEL_NUMBER 16

typedef enum _dma_channel_link_type
{
    DMALinkNone = 0x0U, /*!< No channel link  */
    DMAMinorLink,       /*!< Channel link after each minor loop */
    DMAMajorLink,       /*!< Channel link while major loop count exhausted */
} DMA_channel_link_type_t;

typedef enum _dma_transfer_size
{
    DMA_TransSize1Bytes  = 0x0U, /*!< Source/Destination data transfer size is 1 byte every time */
    DMA_TransSize2Bytes  = 0x1U, /*!< Source/Destination data transfer size is 2 bytes every time */
    DMA_TransSize4Bytes  = 0x2U, /*!< Source/Destination data transfer size is 4 bytes every time */
    DMA_TransSize16Bytes = 0x4U, /*!< Source/Destination data transfer size is 16 bytes every time */
    DMA_TransSize32Bytes = 0x5U, /*!< Source/Destination data transfer size is 32 bytes every time */
} DMA_transfer_size_t;

/*! @brief DMA interrupt source */
typedef enum _dma_interrupt_enable
{
    DMA_ErrorInterruptEnable = 0x1U,                  /*!< Enable interrupt while channel error occurs. */
    DMA_MajorInterruptEnable = DMA_CSR_INTMAJOR_MASK, /*!< Enable interrupt while major count exhausted. */
    DMA_HalfInterruptEnable  = DMA_CSR_INTHALF_MASK,  /*!< Enable interrupt while major count to half value. */
} DMA_interrupt_enable_t;

typedef enum _dma_transfer_type
{
    DMA_MemoryToMemory = 0x0U,  /*!< Transfer from memory to memory */
    DMA_PeripheralToMemory,     /*!< Transfer from peripheral to memory */
    DMA_MemoryToPeripheral,     /*!< Transfer from memory to peripheral */
    DMA_PeripheralToPeripheral, /*!< Transfer from Peripheral to peripheral */
} DMA_transfer_type_t;

/*! @brief DMA global configuration structure.*/
typedef struct _dma_config
{
    bool enableContinuousLinkMode;    /*!< Enable (true) continuous link mode. Upon minor loop completion, the channel
                                           activates again if that channel has a minor loop channel link enabled and
                                           the link channel is itself. */
    bool enableHaltOnError;           /*!< Enable (true) transfer halt on error. Any error causes the HALT bit to set.
                                           Subsequently, all service requests are ignored until the HALT bit is cleared.*/
    bool enableRoundRobinArbitration; /*!< Enable (true) round robin channel arbitration method or fixed priority
                                           arbitration is used for channel selection */
    bool enableDebugMode; /*!< Enable(true) DMA debug mode. When in debug mode, the DMA stalls the start of
                               a new channel. Executing channels are allowed to complete. */
} DMA_config_t;

/*!
 * @brief DMA transfer configuration
 *
 * This structure configures the source/destination transfer attribute.
 */
typedef struct _dma_transfer_config
{
    uint32_t srcAddr;                      /*!< Source data address. */
    uint32_t destAddr;                     /*!< Destination data address. */
    DMA_transfer_size_t srcTransferSize;  /*!< Source data transfer size. */
    DMA_transfer_size_t destTransferSize; /*!< Destination data transfer size. */
    int16_t srcOffset;                     /*!< Sign-extended offset applied to the current source address to
                                                form the next-state value as each source read is completed. */
    int16_t destOffset;                    /*!< Sign-extended offset applied to the current destination address to
                                                form the next-state value as each destination write is completed. */
    uint32_t minorLoopBytes;               /*!< Bytes to transfer in a minor loop*/
    uint32_t majorLoopCounts;              /*!< Major loop iteration count. */
} DMA_transfer_config_t;
/*!
 * @brief DMA TCD.
 *
 * This structure is same as TCD register which is described in reference manual,
 * and is used to configure the scatter/gather feature as a next hardware TCD.
 */
typedef struct _dma_tcd
{
    __IO uint32_t SADDR;     /*!< SADDR register, used to save source address */
    __IO uint16_t SOFF;      /*!< SOFF register, save offset bytes every transfer */
    __IO uint16_t ATTR;      /*!< ATTR register, source/destination transfer size and modulo */
    __IO uint32_t NBYTES;    /*!< Nbytes register, minor loop length in bytes */
    __IO uint32_t SLAST;     /*!< SLAST register */
    __IO uint32_t DADDR;     /*!< DADDR register, used for destination address */
    __IO uint16_t DOFF;      /*!< DOFF register, used for destination offset */
    __IO uint16_t CITER;     /*!< CITER register, current minor loop numbers, for unfinished minor loop.*/
    __IO uint32_t DLAST_SGA; /*!< DLASTSGA register, next tcd address used in scatter-gather mode */
    __IO uint16_t CSR;       /*!< CSR register, for TCD control status */
    __IO uint16_t BITER;     /*!< BITER register, begin minor loop count. */
} DMA_tcd_t;

struct _dma_handle;
typedef void (*dma_callback)(struct _dma_handle *handle, void *userData, bool transferDone, uint32_t tcds);

/*! @brief DMA transfer handle structure */
typedef struct _dma_handle
{
    dma_callback callback; /*!< Callback function for major count exhausted. */
    void *userData;         /*!< Callback function parameter. */
    DMA_Type *base;         /*!< DMA peripheral base address. */
    DMA_tcd_t *tcdPool;    /*!< Pointer to memory stored TCDs. */
    uint8_t channel;        /*!< DMA channel number. */
    volatile int8_t header; /*!< The first TCD index. Should point to the next TCD to be loaded into the DMA engine. */
    volatile int8_t tail;   /*!< The last TCD index. Should point to the next TCD to be stored into the memory pool. */
    volatile int8_t tcdUsed; /*!< The number of used TCD slots. Should reflect the number of TCDs can be used/loaded in
                                the memory. */
    volatile int8_t tcdSize; /*!< The total number of TCD slots in the queue. */
    uint8_t flags;           /*!< The status of the current channel. */
} DMA_handle_t;

/*! @brief DMA channel priority configuration */
typedef struct _dma_channel_Preemption_config
{
    bool enableChannelPreemption; /*!< If true: a channel can be suspended by other channel with higher priority */
    bool enablePreemptAbility;    /*!< If true: a channel can suspend other channel with low priority */
    uint8_t channelPriority;      /*!< Channel priority */
} DMA_channel_Preemption_config_t;

/*! @brief DMA minor offset configuration */
typedef struct _dma_minor_offset_config
{
    bool enableSrcMinorOffset;  /*!< Enable(true) or Disable(false) source minor loop offset. */
    bool enableDestMinorOffset; /*!< Enable(true) or Disable(false) destination minor loop offset. */
    uint32_t minorOffset;       /*!< Offset for a minor loop mapping. */
} DMA_minor_offset_config_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

void DMA_Init(DMA_Type *base, const DMA_config_t *config);

void DMA_Deinit(DMA_Type *base);

void DMA_GetDefaultConfig(DMA_config_t *config);

void DMA_ResetChannel(DMA_Type *base, uint32_t channel);

void DMA_SetMinorOffsetConfig(DMA_Type *base, uint32_t channel, const DMA_minor_offset_config_t *config);

void DMA_SetChannelPreemptionConfig(DMA_Type *base, uint32_t channel, const DMA_channel_Preemption_config_t *config);

void DMA_SetChannelLink(DMA_Type *base, uint32_t channel, uint8_t type, uint32_t linkedChannel);

void DMA_SetModulo(DMA_Type *base, uint32_t channel, uint8_t srcModulo, uint8_t destModulo);

void DMA_EnableChannelInterrupts(DMA_Type *base, uint32_t channel, uint32_t mask);

void DMA_DisableChannelInterrupts(DMA_Type *base, uint32_t channel, uint32_t mask);

void DMA_TcdReset(DMA_tcd_t *tcd);

void DMA_PrepareTransfer(DMA_transfer_config_t *config, void *srcAddr, uint32_t srcWidth, void *destAddr, uint32_t destWidth, uint32_t bytesEachRequest, uint32_t transferBytes, DMA_transfer_type_t type);

void DMA_TcdSetTransferConfig(DMA_tcd_t *tcd, const DMA_transfer_config_t *config, DMA_tcd_t *nextTcd);

uint32_t DMA_GetChannelStatusFlags(DMA_Type *base, uint32_t channel);

void DMA_ClearChannelStatusFlags(DMA_Type *base, uint32_t channel, uint32_t mask);

void DMA_CreateHandle(DMA_handle_t *handle, DMA_Type *base, uint32_t channel);

void DMA_InstallTCD(DMA_Type *base, uint32_t channel, DMA_tcd_t *tcd);

void DMA_TcdEnableInterrupts(DMA_tcd_t *tcd, uint32_t mask);

void DMA_TcdDisableInterrupts(DMA_tcd_t *tcd, uint32_t mask);

void DMA_StartTransfer(DMA_handle_t *handle);

void DMA_StopTransfer(DMA_handle_t *handle);

void DMA_AbortTransfer(DMA_handle_t *handle);

void DMA_SetCallback(DMA_handle_t *handle, dma_callback callback, void *userData);

uint32_t DMA_GetRemainingBytes(DMA_Type *base, uint32_t channel);

static inline void DMAMUX_EnableChannel(DMAMUX_Type *base, uint32_t channel)
{
    base->CHCFG[channel] |= DMAMUX_CHCFG_ENBL_MASK;
}

/*!
 * @brief Disables the DMAMUX channel.
 *
 * This function disables the DMAMUX channel.
 *
 * @note The user must disable the DMAMUX channel before configuring it.
 * @param base DMAMUX peripheral base address.
 * @param channel DMAMUX channel number.
 */
static inline void DMAMUX_DisableChannel(DMAMUX_Type *base, uint32_t channel)
{
    base->CHCFG[channel] &= ~(uint8_t)DMAMUX_CHCFG_ENBL_MASK;
}

/*!
 * @brief Configures the DMAMUX channel source.
 *
 * @param base DMAMUX peripheral base address.
 * @param channel DMAMUX channel number.
 * @param source Channel source, which is used to trigger the DMA transfer.
 */
static inline void DMAMUX_SetSource(DMAMUX_Type *base, uint32_t channel, uint32_t source)
{
    base->CHCFG[channel] = (uint8_t)((base->CHCFG[channel] & ~DMAMUX_CHCFG_SOURCE_MASK) | DMAMUX_CHCFG_SOURCE_SET(source));
}

/*!
 * @brief Enables the DMAMUX period trigger.
 *
 * This function enables the DMAMUX period trigger feature.
 *
 * @param base DMAMUX peripheral base address.
 * @param channel DMAMUX channel number.
 */
static inline void DMAMUX_EnablePeriodTrigger(DMAMUX_Type *base, uint32_t channel)
{
    base->CHCFG[channel] |= DMAMUX_CHCFG_TRIG_MASK;
}

/*!
 * @brief Disables the DMAMUX period trigger.
 *
 * This function disables the DMAMUX period trigger.
 *
 * @param base DMAMUX peripheral base address.
 * @param channel DMAMUX channel number.
 */
static inline void DMAMUX_DisablePeriodTrigger(DMAMUX_Type *base, uint32_t channel)
{
    base->CHCFG[channel] &= ~(uint8_t)DMAMUX_CHCFG_TRIG_MASK;
}

/*!
 * @brief Enables the DMA hardware channel request.
 *
 * This function enables the hardware channel request.
 *
 * @param base DMA peripheral base address.
 * @param channel DMA channel number.
 */
static inline void DMA_EnableChannelRequest(DMA_Type *base, uint32_t channel)
{
    base->SERQ = DMA_SERQ_SERQ_SET(channel);
}

/*!
 * @brief Disables the DMA hardware channel request.
 *
 * This function disables the hardware channel request.
 *
 * @param base DMA peripheral base address.
 * @param channel DMA channel number.
 */
static inline void DMA_DisableChannelRequest(DMA_Type *base, uint32_t channel)
{
    base->CERQ = DMA_CERQ_CERQ_SET(channel);
}

/*!
 * @brief Starts the DMA transfer by using the software trigger.
 *
 * This function starts a minor loop transfer.
 *
 * @param base DMA peripheral base address.
 * @param channel DMA channel number.
 */
static inline void DMA_TriggerChannelStart(DMA_Type *base, uint32_t channel)
{
    base->SSRT = DMA_SSRT_SSRT_SET(channel);
}

/*!
 * @brief Enable auto stop request for DMA transfer.
 *
 * If enable auto stop request, the EDMA hardware automatically disable hardware channel request.
 *
 * @param base EDMA peripheral base address.
 * @param channel EDMA channel number.
 * @param enable The command for enable(ture) or disable(false).
 */
static inline void DMA_EnableAutoStopRequest(DMA_Type *base, uint32_t channel, bool enable)
{
    assert(channel < DMA_CHANNEL_NUMBER);

    base->TCD[channel].CSR = (base->TCD[channel].CSR & (~DMA_CSR_DREQ_MASK)) | DMA_CSR_DREQ_SET(enable);
}
#if defined(__cplusplus)
}
#endif /* __cplusplus */
#endif /* _DMA_H_ */