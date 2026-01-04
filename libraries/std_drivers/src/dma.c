 /*
  ******************************************************************************
  * @file           : dma.c
  * @brief          : dma hal program body
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
 #include "dma.h"
 /*******************************************************************************
  * Prototypes
  ******************************************************************************/
 
 /*!
  * @brief Get instance offset.
  *
  * @param instance DMA peripheral instance number.
  */
 static uint32_t DMA_GetInstanceOffset(uint32_t instance);
 
 /*!
  * @brief Map transfer width.
  *
  * @param width transfer width.
  */
 /*******************************************************************************
  * Variables
  ******************************************************************************/
 
 /*! @brief Array to map DMA instance number to base pointer. */
 static DMA_Type *const s_DMABases[] = DMA_BASE_PTRS;
 
 
 /*! @brief Array to map DMA instance number to IRQ number. */
 static const IRQn_Type s_DMAIRQList[DMA_CHANNEL_NUMBER] = DMA_CHN_IRQS;
 
 /*! @brief Pointers to transfer handle for each DMA channel. */
 static DMA_handle_t *s_DMAHandle[DMA_CHANNEL_NUMBER];
 
 /*******************************************************************************
  * Code
  ******************************************************************************/
 
  /*!
  * brief Initializes the DMA peripheral.
  *
  * This function ungates the DMA clock and configures the DMA peripheral according
  * to the configuration structure.
  *
  * param base DMA peripheral base address.
  * param config A pointer to the configuration structure, see "DMA_config_t".
  * note This function enables the minor loop map feature.
  */
 void DMA_Init(DMA_Type *base, const DMA_config_t *config)
 {
     assert(config != NULL);
 
     uint32_t tmpreg;
     //SYSCTRL->ONPLATCGC |= SYSCTRL_ONPLATCGC_DMA_MASK;
      /* clear all the enabled request, status to make sure DMA status is in normal condition */
     base->ERQ = 0U;
     base->INT = 0xFFFFFFFFU;
     base->ERR = 0xFFFFFFFFU;
     /* Configure DMA peripheral according to the configuration structure. */
     tmpreg = base->CR;
     tmpreg &= ~(DMA_CR_ERCA_MASK | DMA_CR_HOE_MASK | DMA_CR_CLM_MASK | DMA_CR_EDBG_MASK);
     tmpreg |= (DMA_CR_ERCA_SET(config->enableRoundRobinArbitration) | DMA_CR_HOE_SET(config->enableHaltOnError) |
                DMA_CR_CLM_SET(config->enableContinuousLinkMode) | DMA_CR_EDBG_SET(config->enableDebugMode) | DMA_CR_EMLM_SET(1U));
     base->CR = tmpreg;
 }
 
 /*!
  * brief Deinitializes the DMA peripheral.
  *
  * This function gates the DMA clock.
  *
  * param base DMA peripheral base address.
  */
 void DMA_Deinit(DMA_Type *base)
 {
     /* Gate DMA peripheral clock */
     SYSCTRL->ONPLATCGC &= ~SYSCTRL_ONPLATCGC_DMA_MASK;
 }
 
 /*!
  * brief Gets the DMA default configuration structure.
  *
  * This function sets the configuration structure to default values.
  * The default configuration is set to the following values.
  * code
  *   config.enableContinuousLinkMode = false;
  *   config.enableHaltOnError = true;
  *   config.enableRoundRobinArbitration = false;
  *   config.enableDebugMode = false;
  * endcode
  *
  * param config A pointer to the DMA configuration structure.
  */
 void DMA_GetDefaultConfig(DMA_config_t *config)
 {
     assert(config != NULL);
 
     /* Initializes the configure structure to zero. */
     (void)memset(config, 0, sizeof(*config));
 
     config->enableRoundRobinArbitration = false;
     config->enableHaltOnError           = true;
     config->enableContinuousLinkMode    = false;
     config->enableDebugMode             = false;
 }
 
 /*!
 * brief Creates the DMA handle.
 *
 * This function is called if using the transactional API for DMA. This function
 * initializes the internal state of the DMA handle.
 *
 * param handle DMA handle pointer. The DMA handle stores callback function and
 *               parameters.
 * param base DMA peripheral base address.
 * param channel DMA channel number.
 */
void DMA_CreateHandle(DMA_handle_t *handle, DMA_Type *base, uint32_t channel)
{
    assert(handle != NULL);

    uint32_t channelIndex;
    DMA_tcd_t *tcdRegs;

    /* Zero the handle */
    (void)memset(handle, 0, sizeof(*handle));

    handle->base    = base;
    handle->channel = (uint8_t)channel;
    /* Get the DMA instance number */
    channelIndex = channel;
    s_DMAHandle[channelIndex] = handle;

    /* Enable NVIC interrupt */
    (void)EnableIRQ(s_DMAIRQList[channel]);

    /*
       Reset TCD registers to zero. Unlike the DMA_TcdReset(DREQ will be set),
       CSR will be 0. Because in order to suit DMA busy check mechanism in
       DMA_SubmitTransfer, CSR must be set 0.
    */
    tcdRegs            = (DMA_tcd_t *)(uint32_t)&handle->base->TCD[handle->channel];
    tcdRegs->SADDR     = 0;
    tcdRegs->SOFF      = 0;
    tcdRegs->ATTR      = 0;
    tcdRegs->NBYTES    = 0;
    tcdRegs->SLAST     = 0;
    tcdRegs->DADDR     = 0;
    tcdRegs->DOFF      = 0;
    tcdRegs->CITER     = 0;
    tcdRegs->DLAST_SGA = 0;
    tcdRegs->CSR       = 0;
    tcdRegs->BITER     = 0;
}
 /*!
  * brief Sets all TCD registers to default values.
  *
  * This function sets TCD registers for this channel to default values.
  *
  * param base DMA peripheral base address.
  * param channel DMA channel number.
  * note This function must not be called while the channel transfer is ongoing
  *       or it causes unpredictable results.
  * note This function enables the auto stop request feature.
  */
 void DMA_ResetChannel(DMA_Type *base, uint32_t channel)
 {
     DMA_TcdReset((DMA_tcd_t *)(uint32_t)&base->TCD[channel]);
 }
 
 
 
 /*!
  * brief Configures the DMA minor offset feature.
  *
  * The minor offset means that the signed-extended value is added to the source address or destination
  * address after each minor loop.
  *
  * param base DMA peripheral base address.
  * param channel DMA channel number.
  * param config A pointer to the minor offset configuration structure.
  */
 void DMA_SetMinorOffsetConfig(DMA_Type *base, uint32_t channel, const DMA_minor_offset_config_t *config)
 {
     assert(config != NULL);
 
     uint32_t tmpreg;
 
     tmpreg = base->TCD[channel].NBYTES_MLOFFYES;
     tmpreg &= ~(DMA_NBYTES_MLOFFYES_SMLOE_MASK | DMA_NBYTES_MLOFFYES_DMLOE_MASK | DMA_NBYTES_MLOFFYES_MLOFF_MASK);
     tmpreg |=
         (DMA_NBYTES_MLOFFYES_SMLOE_SET(config->enableSrcMinorOffset) |
          DMA_NBYTES_MLOFFYES_DMLOE_SET(config->enableDestMinorOffset) | DMA_NBYTES_MLOFFYES_MLOFF_SET(config->minorOffset));
     base->TCD[channel].NBYTES_MLOFFYES = tmpreg;
 }
 
 /*!
  * brief Configures the DMA channel preemption feature.
  *
  * This function configures the channel preemption attribute and the priority of the channel.
  *
  * param base DMA peripheral base address.
  * param channel DMA channel number
  * param config A pointer to the channel preemption configuration structure.
  */
 void DMA_SetChannelPreemptionConfig(DMA_Type *base, uint32_t channel, const DMA_channel_Preemption_config_t *config)
 {
     assert(config != NULL);
 
     bool tmpEnablePreemptAbility    = config->enablePreemptAbility;
     bool tmpEnableChannelPreemption = config->enableChannelPreemption;
     uint8_t tmpChannelPriority      = config->channelPriority;
     volatile uint8_t *tmpReg        = &base->DCHPRI3;
 
     ((volatile uint8_t *)tmpReg)[((channel) & ~0x03U) | (3U - ((channel)&0x03U))] =
         (DMA_DCHPRI0_DPA_SET((true == tmpEnablePreemptAbility ? 0U : 1U)) |
          DMA_DCHPRI0_ECP_SET((true == tmpEnableChannelPreemption ? 1U : 0U)) | DMA_DCHPRI0_CHPRI_SET(tmpChannelPriority));
 }
 
 /*!
  * brief Sets the channel link for the DMA transfer.
  *
  * This function configures either the minor link or the major link mode. The minor link means that the channel link is
  * triggered every time CITER decreases by 1. The major link means that the channel link is triggered when the CITER is
  * exhausted.
  *
  * param base DMA peripheral base address.
  * param channel DMA channel number.
  * param type A channel link type, which can be one of the following:
  *   arg DMALinkNone
  *   arg DMAMinorLink
  *   arg DMAMajorLink
  * param linkedChannel The linked channel number.
  * note Users should ensure that DONE flag is cleared before calling this interface, or the configuration is invalid.
  */
 void DMA_SetChannelLink(DMA_Type *base, uint32_t channel, uint8_t type, uint32_t linkedChannel)
 {
    DMA_tcd_t *tcd;
     
    assert(channel < (uint32_t)DMA_CHANNEL_NUMBER);
 
    tcd = (DMA_tcd_t *)(uint32_t)&base->TCD[channel];
    if (type == DMAMinorLink) /* Minor link config */
    {
        uint16_t tmpreg;

        /* Enable minor link */
        tcd->CITER |= DMA_CITER_ELINKYES_ELINK_MASK;
        tcd->BITER |= DMA_BITER_ELINKYES_ELINK_MASK;
        /* Set linked channel */
        tmpreg = tcd->CITER & (~(uint16_t)DMA_CITER_ELINKYES_LINKCH_MASK);
        tmpreg |= DMA_CITER_ELINKYES_LINKCH_SET(linkedChannel);
        tcd->CITER = tmpreg;
        tmpreg     = tcd->BITER & (~(uint16_t)DMA_BITER_ELINKYES_LINKCH_MASK);
        tmpreg |= DMA_BITER_ELINKYES_LINKCH_SET(linkedChannel);
        tcd->BITER = tmpreg;
    }
    else if (type == DMAMajorLink) /* Major link config */
    {
        uint16_t tmpreg;

        /* Enable major link */
        tcd->CSR |= DMA_CSR_MAJORELINK_MASK;
        /* Set major linked channel */
        tmpreg   = tcd->CSR & (~(uint16_t)DMA_CSR_MAJORLINKCH_MASK);
        tcd->CSR = tmpreg | DMA_CSR_MAJORLINKCH_SET(linkedChannel);
    }
    else /* Link none */
    {
        tcd->CITER &= ~(uint16_t)DMA_CITER_ELINKYES_ELINK_MASK;
        tcd->BITER &= ~(uint16_t)DMA_BITER_ELINKYES_ELINK_MASK;
        tcd->CSR &= ~(uint16_t)DMA_CSR_MAJORELINK_MASK;
    }
 }
 
 /*!
  * brief Sets the bandwidth for the DMA transfer.
  *
  * Because the DMA processes the minor loop, it continuously generates read/write sequences
  * until the minor count is exhausted. The bandwidth forces the DMA to stall after the completion of
  * each read/write access to control the bus request bandwidth seen by the crossbar switch.
  *
  * param base DMA peripheral base address.
  * param channel DMA channel number.
  * param bandWidth A bandwidth setting, which can be one of the following:
  *     arg kDMABandwidthStallNone
  *     arg kDMABandwidthStall4Cycle
  *     arg kDMABandwidthStall8Cycle
  */
 void DMA_SetBandWidth(DMA_Type *base, uint32_t channel, uint8_t bandWidth)
 {
     base->TCD[channel].CSR = (uint16_t)((base->TCD[channel].CSR & (~DMA_CSR_BWC_MASK)) | DMA_CSR_BWC_SET(bandWidth));
 }
 
 /*!
  * brief Sets the source modulo and the destination modulo for the DMA transfer.
  *
  * This function defines a specific address range specified to be the value after (SADDR + SOFF)/(DADDR + DOFF)
  * calculation is performed or the original register value. It provides the ability to implement a circular data
  * queue easily.
  *
  * param base DMA peripheral base address.
  * param channel DMA channel number.
  * param srcModulo A source modulo value.
  * param destModulo A destination modulo value.
  */
 void DMA_SetModulo(DMA_Type *base, uint32_t channel, uint8_t srcModulo, uint8_t destModulo)
 {
     uint16_t tmpreg;
 
     tmpreg                  = base->TCD[channel].ATTR & (~(uint16_t)(DMA_ATTR_SMOD_MASK | DMA_ATTR_DMOD_MASK));
     base->TCD[channel].ATTR = tmpreg | DMA_ATTR_DMOD_SET(destModulo) | DMA_ATTR_SMOD_SET(srcModulo);
 }
 
 /*!
  * brief Enables the interrupt source for the DMA transfer.
  *
  * param base DMA peripheral base address.
  * param channel DMA channel number.
  * param mask The mask of interrupt source to be set. Users need to use
  *             the defined DMA_interrupt_enable_t type.
  */
 void DMA_EnableChannelInterrupts(DMA_Type *base, uint32_t channel, uint32_t mask)
 {
     /* Enable error interrupt */
     if (0U != (mask & 1))
     {
         base->EEI |= ((uint32_t)0x1U << channel);
     }
 
     /* Enable Major interrupt */
     if (0U != (mask & DMA_CSR_INTMAJOR_MASK))
     {
         base->TCD[channel].CSR |= DMA_CSR_INTMAJOR_MASK;
     }
 
     /* Enable Half major interrupt */
     if (0U != (mask & DMA_CSR_INTHALF_MASK))
     {
         base->TCD[channel].CSR |= DMA_CSR_INTHALF_MASK;
     }
 }
 
 /*!
  * brief Disables the interrupt source for the DMA transfer.
  *
  * param base DMA peripheral base address.
  * param channel DMA channel number.
  * param mask The mask of the interrupt source to be set. Use
  *             the defined DMA_interrupt_enable_t type.
  */
 void DMA_DisableChannelInterrupts(DMA_Type *base, uint32_t channel, uint32_t mask)
 {
      /* Disable error interrupt */
     if (0U != (mask & 1))
     {
         base->EEI &= (~((uint32_t)0x1U << channel));
     }
 
     /* Disable Major interrupt */
     if (0U != (mask & (uint32_t)DMA_CSR_INTMAJOR_MASK))
     {
         base->TCD[channel].CSR &= ~(uint16_t)DMA_CSR_INTMAJOR_MASK;
     }
 
     /* Disable Half major interrupt */
     if (0U != (mask & (uint32_t)DMA_CSR_INTHALF_MASK))
     {
         base->TCD[channel].CSR &= ~(uint16_t)DMA_CSR_INTHALF_MASK;
     }
 }
 
 /*!
  * brief Sets all fields to default values for the TCD structure.
  *
  * This function sets all fields for this TCD structure to default value.
  *
  * param tcd Pointer to the TCD structure.
  * note This function enables the auto stop request feature.
  */
 void DMA_TcdReset(DMA_tcd_t *tcd)
 {
     assert(tcd != NULL);
     //assert(((uint32_t)tcd & 0x1FU) == 0U);
 
     /* Reset channel TCD */
     tcd->SADDR     = 0U;
     tcd->SOFF      = 0U;
     tcd->ATTR      = 0U;
     tcd->NBYTES    = 0U;
     tcd->SLAST     = 0U;
     tcd->DADDR     = 0U;
     tcd->DOFF      = 0U;
     tcd->CITER     = 0U;
     tcd->DLAST_SGA = 0U;
     /* Enable auto disable request feature */
     tcd->CSR   = DMA_CSR_DREQ_SET(true);
     tcd->BITER = 0U;
 }
 
 /*!
 * brief Gets the DMA channel status flags.
 *
 * param base DMA peripheral base address.
 * param channel DMA channel number.
 * return The mask of channel status flags. Users need to use the
 *         _DMA_channel_status_flags type to decode the return variables.
 */
uint32_t DMA_GetChannelStatusFlags(DMA_Type *base, uint32_t channel)
{
    uint32_t retval = 0;

    /* Get DONE bit flag */
    retval |= (((uint32_t)base->TCD[channel].CSR & DMA_CSR_DONE_MASK) >> DMA_CSR_DONE_SHIFT);
    /* Get ERROR bit flag */
    retval |= ((((uint32_t)base->ERR >> channel) & 0x1U) << 1U);
    /* Get INT bit flag */
    retval |= ((((uint32_t)base->INT >> channel) & 0x1U) << 2U);

    return retval;
}

/*!
 * brief Clears the DMA channel status Done flags.
 *
 * param base DMA peripheral base address.
 * param channel DMA channel number.
 */
void DMA_ClearChannelStatusDoneFlags(DMA_Type *base, uint32_t channel)
{
    base->CDNE = (uint8_t)channel;
}
/*!
 * brief Clears the DMA channel status Error flags.
 *
 * param base DMA peripheral base address.
 * param channel DMA channel number.
 */
void DMA_ClearChannelStatusErrorFlags(DMA_Type *base, uint32_t channel)
{
    base->CERR = (uint8_t)channel;
}
/*!
 * brief Clears the DMA channel status Interrupt flags.
 *
 * param base DMA peripheral base address.
 * param channel DMA channel number.
 */
void DMA_ClearChannelStatusIntFlags(DMA_Type *base, uint32_t channel)
{
    base->CINT = (uint8_t)channel;
}

/*!
 * brief Push content of TCD structure into hardware TCD register.
 *
 * param base DMA peripheral base address.
 * param channel DMA channel number.
 * param tcd Point to TCD structure.
 */
void DMA_InstallTCD(DMA_Type *base, uint32_t channel, DMA_tcd_t *tcd)
{
    assert(tcd != NULL);
    //assert(((uint32_t)tcd & 0x1FU) == 0U);

    /* Push tcd into hardware TCD register */
    base->TCD[channel].SADDR         = tcd->SADDR;
    base->TCD[channel].SOFF          = tcd->SOFF;
    base->TCD[channel].ATTR          = tcd->ATTR;
    base->TCD[channel].NBYTES_MLNO   = tcd->NBYTES;
    base->TCD[channel].SLAST         = tcd->SLAST;
    base->TCD[channel].DADDR         = tcd->DADDR;
    base->TCD[channel].DOFF          = tcd->DOFF;
    base->TCD[channel].CITER_ELINKNO = tcd->CITER;
    base->TCD[channel].DLAST_SGA     = tcd->DLAST_SGA;
    /* Clear DONE bit first, otherwise ESG cannot be set */
    base->TCD[channel].CSR           = 0;
    base->TCD[channel].CSR           = tcd->CSR;
    base->TCD[channel].BITER_ELINKNO = tcd->BITER;
}

/*!
 * brief DMA starts transfer.
 *
 * This function enables the channel request. Users can call this function after submitting the transfer request
 * or before submitting the transfer request.
 *
 * param handle DMA handle pointer.
 */
void DMA_StartTransfer(DMA_handle_t *handle)
{
    assert(handle != NULL);
    uint32_t tmpCSR = 0;

    if (handle->tcdPool == NULL)
    {
        handle->base->SERQ = DMA_SERQ_SERQ_SET(handle->channel);
    }
    else /* Use the TCD queue. */
    {
        uint32_t primask;
        DMA_tcd_t *tcdRegs = (DMA_tcd_t *)(uint32_t)&handle->base->TCD[handle->channel];

        handle->flags = true;

        /* Check if there was at least one descriptor submitted since reset (TCD in registers is valid) */
        if (tcdRegs->DLAST_SGA != 0U)
        {
            primask = DisableGlobalIRQ();
            /* Check if channel request is actually disable. */
            if ((handle->base->ERQ & ((uint32_t)1U << handle->channel)) == 0U)
            {
                /* Check if transfer is paused. */
                tmpCSR = tcdRegs->CSR;
                if ((0U == (tmpCSR & DMA_CSR_DONE_MASK)) || (0U != (tmpCSR & DMA_CSR_ESG_MASK)))
                {
                    /*
                        Re-enable channel request must be as soon as possible, so must put it into
                        critical section to avoid task switching or interrupt service routine.
                    */
                    handle->base->SERQ = DMA_SERQ_SERQ_SET(handle->channel);
                }
            }
            EnableGlobalIRQ(primask);
        }
    }
}

/*!
 * brief DMA stops transfer.
 *
 * This function disables the channel request to pause the transfer. Users can call DMA_StartTransfer()
 * again to resume the transfer.
 *
 * param handle DMA handle pointer.
 */
void DMA_StopTransfer(DMA_handle_t *handle)
{
    assert(handle != NULL);

    handle->flags = false;
    handle->base->CERQ = DMA_CERQ_CERQ_SET(handle->channel);
}

/*!
 * brief DMA aborts transfer.
 *
 * This function disables the channel request and clear transfer status bits.
 * Users can submit another transfer after calling this API.
 *
 * param handle DMA handle pointer.
 */
void DMA_AbortTransfer(DMA_handle_t *handle)
{
    handle->base->CERQ = DMA_CERQ_CERQ_SET(handle->channel);
    /*
        Clear CSR to release channel. Because if the given channel started transfer,
        CSR will be not zero. Because if it is the last transfer, DREQ will be set.
        If not, ESG will be set.
    */
    handle->base->TCD[handle->channel].CSR = 0;
    /* Cancel all next TCD transfer. */
    handle->base->TCD[handle->channel].DLAST_SGA = 0;

    /* Handle the tcd */

    if (handle->tcdPool != NULL)
    {
        handle->header  = 0;
        handle->tail    = 0;
        handle->tcdUsed = 0;
    }
}

/*!
 * brief Installs a callback function for the DMA transfer.
 *
 * This callback is called in the DMA IRQ handler. Use the callback to do something after
 * the current major loop transfer completes. This function will be called every time one tcd finished transfer.
 *
 * param handle DMA handle pointer.
 * param callback DMA callback function pointer.
 * param userData A parameter for the callback function.
 */
void DMA_SetCallback(DMA_handle_t *handle, dma_callback callback, void *userData)
{
    assert(handle != NULL);

    handle->callback = callback;
    handle->userData = userData;
}

static DMA_transfer_size_t EDMA_TransferWidthMapping(uint32_t width)
{
    DMA_transfer_size_t transferSize = DMA_TransSize1Bytes;

    /* map width to register value */
    switch (width)
    {
        /* width 8bit */
        case 1U:
            transferSize = DMA_TransSize1Bytes;
            break;
        /* width 16bit */
        case 2U:
            transferSize = DMA_TransSize2Bytes;
            break;
        /* width 32bit */
        case 4U:
            transferSize = DMA_TransSize4Bytes;
            break;
        /* width 128bit */
        case 16U:
            transferSize = DMA_TransSize16Bytes;
            break;
        /* width 256bit */
        case 32U:
            transferSize = DMA_TransSize32Bytes;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }

    return transferSize;
}
/*!
 * brief Prepares the DMA transfer structure configurations.
 *
 * This function prepares the transfer configuration structure according to the user input.
 *
 * param config The user configuration structure of type DMA_transfer_t.
 * param srcAddr DMA transfer source address.
 * param srcWidth DMA transfer source address width(bytes).
 * param srcOffset source address offset.
 * param destAddr DMA transfer destination address.
 * param destWidth DMA transfer destination address width(bytes).
 * param destOffset destination address offset.
 * param bytesEachRequest DMA transfer bytes per channel request.
 * param transferBytes DMA transfer bytes to be transferred.
 * note The data address and the data width must be consistent. For example, if the SRC
 *       is 4 bytes, the source address must be 4 bytes aligned, or it results in
 *       source address error (SAE).
 */
void DMA_PrepareTransferConfig(DMA_transfer_config_t *config,
                                void *srcAddr,
                                uint32_t srcWidth,
                                int16_t srcOffset,
                                void *destAddr,
                                uint32_t destWidth,
                                int16_t destOffset,
                                uint32_t bytesEachRequest,
                                uint32_t transferBytes)
{
    assert(config != NULL);
    assert(srcAddr != NULL);
    assert(destAddr != NULL);
    assert((srcWidth != 0U) && (srcWidth <= 32U) && ((srcWidth & (srcWidth - 1U)) == 0U));
    assert((destWidth != 0U) && (destWidth <= 32U) && ((destWidth & (destWidth - 1U)) == 0U));
    assert((transferBytes % bytesEachRequest) == 0U);
    assert((((uint32_t)(uint32_t *)srcAddr) % srcWidth) == 0U);
    assert((((uint32_t)(uint32_t *)destAddr) % destWidth) == 0U);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->destAddr = (uint32_t)(uint32_t *)destAddr;
    config->srcAddr  = (uint32_t)(uint32_t *)srcAddr;
    config->minorLoopBytes   = bytesEachRequest;
    config->majorLoopCounts  = transferBytes / bytesEachRequest;
    config->srcTransferSize  = EDMA_TransferWidthMapping(srcWidth);
    config->destTransferSize = EDMA_TransferWidthMapping(destWidth);
    config->destOffset       = destOffset;
    config->srcOffset        = srcOffset;
}

/*!
 * brief Prepares the DMA transfer structure.
 *
 * This function prepares the transfer configuration structure according to the user input.
 *
 * param config The user configuration structure of type DMA_transfer_t.
 * param srcAddr DMA transfer source address.
 * param srcWidth DMA transfer source address width(bytes).
 * param destAddr DMA transfer destination address.
 * param destWidth DMA transfer destination address width(bytes).
 * param bytesEachRequest DMA transfer bytes per channel request.
 * param transferBytes DMA transfer bytes to be transferred.
 * param type DMA transfer type.
 * note The data address and the data width must be consistent. For example, if the SRC
 *       is 4 bytes, the source address must be 4 bytes aligned, or it results in
 *       source address error (SAE).
 */
void DMA_PrepareTransfer(DMA_transfer_config_t *config,
                          void *srcAddr,
                          uint32_t srcWidth,
                          void *destAddr,
                          uint32_t destWidth,
                          uint32_t bytesEachRequest,
                          uint32_t transferBytes,
                          DMA_transfer_type_t type)
{
    assert(config != NULL);

    int16_t srcOffset = 0, destOffset = 0;

    switch (type)
    {
        case DMA_MemoryToMemory:
            destOffset = (int16_t)destWidth;
            srcOffset  = (int16_t)srcWidth;
            break;
        case DMA_MemoryToPeripheral:
            destOffset = 0;
            srcOffset  = (int16_t)srcWidth;
            break;
        case DMA_PeripheralToMemory:
            destOffset = (int16_t)destWidth;
            srcOffset  = 0;
            break;
        case DMA_PeripheralToPeripheral:
            destOffset = 0;
            srcOffset  = 0;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }

    DMA_PrepareTransferConfig(config, srcAddr, srcWidth, srcOffset, destAddr, destWidth, destOffset, bytesEachRequest,
                               transferBytes);
}
/*!
 * brief Configures the DMA TCD transfer attribute.
 *
 * The TCD is a transfer control descriptor. The content of the TCD is the same as the hardware TCD registers.
 * The STCD is used in the scatter-gather mode.
 * This function configures the TCD transfer attribute, including source address, destination address,
 * transfer size, address offset, and so on. It also configures the scatter gather feature if the
 * user supplies the next TCD address.
 *
 * param tcd Pointer to the TCD structure.
 * param config Pointer to DMA transfer configuration structure.
 * param nextTcd Pointer to the next TCD structure. It can be NULL if users
 *                do not want to enable scatter/gather feature.
 * note TCD address should be 32 bytes aligned or it causes an DMA error.
 * note If the nextTcd is not NULL, the scatter gather feature is enabled
 *       and DREQ bit is cleared in the previous transfer configuration, which
 *       is set in the DMA_TcdReset.
*/
void DMA_TcdSetTransferConfig(DMA_tcd_t *tcd, const DMA_transfer_config_t *config, DMA_tcd_t *nextTcd)
{
    assert(tcd != NULL);
    assert(((uint32_t)tcd & 0x1FU) == 0U);
    assert(config != NULL);
    assert(((uint32_t)nextTcd & 0x1FU) == 0U);
    assert((config->srcAddr % (1UL << (uint32_t)config->srcTransferSize)) == 0U);
    assert((config->destAddr % (1UL << (uint32_t)config->destTransferSize)) == 0U);

    /* source address */

    tcd->SADDR = config->srcAddr;
    /* destination address */
    tcd->DADDR = config->destAddr;
    /* Source data and destination data transfer size */
    tcd->ATTR = DMA_ATTR_SSIZE_SET(config->srcTransferSize) | DMA_ATTR_DSIZE_SET(config->destTransferSize);
    /* Source address signed offset */
    tcd->SOFF = (uint16_t)config->srcOffset;
    /* Destination address signed offset */
    tcd->DOFF = (uint16_t)config->destOffset;
    /* Minor byte transfer count */
    tcd->NBYTES = config->minorLoopBytes;
    /* Current major iteration count */
    tcd->CITER = (uint16_t)config->majorLoopCounts;
    /* Starting major iteration count */
    tcd->BITER = (uint16_t)config->majorLoopCounts;
    /* Enable scatter/gather processing */
    if (nextTcd != NULL)
    {
        tcd->DLAST_SGA = (uint32_t)nextTcd;

        /*
            Before call DMA_TcdSetTransferConfig or DMA_SetTransferConfig,
            user must call DMA_TcdReset or DMA_ResetChannel which will set
            DREQ, so must use "|" or "&" rather than "=".

            Clear the DREQ bit because scatter gather has been enabled, so the
            previous transfer is not the last transfer, and channel request should
            be enabled at the next transfer(the next TCD).
        */
        tcd->CSR = (tcd->CSR | (uint16_t)DMA_CSR_ESG_MASK) & ~(uint16_t)DMA_CSR_DREQ_MASK;
    }
}

/*!
 * brief Enables the interrupt source for the DMA TCD.
 *
 * param tcd Point to the TCD structure.
 * param mask The mask of interrupt source to be set. Users need to use
 *             the defined edma_interrupt_enable_t type.
 */
void DMA_TcdEnableInterrupts(DMA_tcd_t *tcd, uint32_t mask)
{
    assert(tcd != NULL);

    /* Enable Major interrupt */
    if (0U != (mask & (uint32_t)DMA_MajorInterruptEnable))
    {
        tcd->CSR |= DMA_CSR_INTMAJOR_MASK;
    }

    /* Enable Half major interrupt */
    if (0U != (mask & (uint32_t)DMA_HalfInterruptEnable))
    {
        tcd->CSR |= DMA_CSR_INTHALF_MASK;
    }
}

/*!
 * brief Disables the interrupt source for the DMA TCD.
 *
 * param tcd Point to the TCD structure.
 * param mask The mask of interrupt source to be set. Users need to use
 *             the defined edma_interrupt_enable_t type.
 */
void DMA_TcdDisableInterrupts(DMA_tcd_t *tcd, uint32_t mask)
{
    assert(tcd != NULL);

    /* Disable Major interrupt */
    if (0U != (mask & (uint32_t)DMA_MajorInterruptEnable))
    {
        tcd->CSR &= ~(uint16_t)DMA_CSR_INTMAJOR_MASK;
    }

    /* Disable Half major interrupt */
    if (0U != (mask & (uint32_t)DMA_HalfInterruptEnable))
    {
        tcd->CSR &= ~(uint16_t)DMA_CSR_INTHALF_MASK;
    }
}

uint32_t DMA_GetRemainingBytes(DMA_Type *base, uint32_t channel)
{
    assert(channel < DMA_CHANNEL_NUMBER);

    uint32_t nbytes = 0;
    uint32_t remainingBytes = 0;

    if (DMA_CSR_DONE_MASK & base->TCD[channel].CSR)
    {
        remainingBytes = 0;
    }
    else
    {
        /* Calculate the nbytes */
        if (base->TCD[channel].NBYTES_MLOFFYES & (DMA_NBYTES_MLOFFYES_SMLOE_MASK | DMA_NBYTES_MLOFFYES_DMLOE_MASK))
        {
            nbytes = (base->TCD[channel].NBYTES_MLOFFYES & DMA_NBYTES_MLOFFYES_NBYTES_MASK) >>
                     DMA_NBYTES_MLOFFYES_NBYTES_SHIFT;
        }
        else
        {
            nbytes =
                (base->TCD[channel].NBYTES_MLOFFNO & DMA_NBYTES_MLOFFNO_NBYTES_MASK) >> DMA_NBYTES_MLOFFNO_NBYTES_SHIFT;
        }
        /* Calculate the unfinished bytes */
        if (base->TCD[channel].CITER_ELINKNO & DMA_CITER_ELINKNO_ELINK_MASK)
        {
            remainingBytes = ((base->TCD[channel].CITER_ELINKYES & DMA_CITER_ELINKYES_CITER_MASK) >>
                              DMA_CITER_ELINKYES_CITER_SHIFT) *
                             nbytes;
        }
        else
        {
            remainingBytes =
                ((base->TCD[channel].CITER_ELINKNO & DMA_CITER_ELINKNO_CITER_MASK) >> DMA_CITER_ELINKNO_CITER_SHIFT) *
                nbytes;
        }
    }

    return remainingBytes;
}

 /*!
  * brief DMA IRQ handler for the current major loop transfer completion.
  *
  * This function clears the channel major interrupt flag and calls
  * the callback function if it is not NULL.
  *
  * Note:
  * For the case using TCD queue, when the major iteration count is exhausted, additional operations are performed.
  * These include the final address adjustments and reloading of the BITER field into the CITER.
  * Assertion of an optional interrupt request also occurs at this time, as does a possible fetch of a new TCD from
  * memory using the scatter/gather address pointer included in the descriptor (if scatter/gather is enabled).
  *
  * For instance, when the time interrupt of TCD[0] happens, the TCD[1] has already been loaded into the DMA engine.
  * As sga and sga_index are calculated based on the DLAST_SGA bitfield lies in the TCD_CSR register, the sga_index
  * in this case should be 2 (DLAST_SGA of TCD[1] stores the address of TCD[2]). Thus, the "tcdUsed" updated should be
  * (tcdUsed - 2U) which indicates the number of TCDs can be loaded in the memory pool (because TCD[0] and TCD[1] have
  * been loaded into the DMA engine at this point already.).
  *
  * See the "DMA basic data flow" in the DMA Functional description section of the Reference Manual for
  * further details.
  *
  * param handle DMA handle pointer.
  */
 void DMA_HandleIRQ(DMA_handle_t *handle)
 {
     assert(handle != NULL);
 
     bool transfer_done;
 
     /* Clear DMA interrupt flag */
     handle->base->CINT = handle->channel;
     /* Check if transfer is already finished. */
     transfer_done = ((handle->base->TCD[handle->channel].CSR & DMA_CSR_DONE_MASK) != 0U);
 
     if (handle->tcdPool == NULL)
     {
         if (handle->callback != NULL)
         {
             (handle->callback)(handle, handle->userData, transfer_done, 0);
         }
     }
     else /* Use the TCD queue. Please refer to the API descriptions in the DMA header file for detailed information. */
     {

        uint32_t sga = (uint32_t)handle->base->TCD[handle->channel].DLAST_SGA;
        uint32_t sga_index;
        int32_t tcds_done;
        uint8_t new_header;
        bool esg = ((handle->base->TCD[handle->channel].CSR & DMA_CSR_ESG_MASK) != 0U);

        /* Get the offset of the next transfer TCD blocks to be loaded into the DMA engine. */
        sga -= (uint32_t)handle->tcdPool;

         /* Get the index of the next transfer TCD blocks to be loaded into the DMA engine. */
        sga_index = sga / sizeof(DMA_tcd_t);
        /* Adjust header positions. */
        if (transfer_done)
        {
            /* New header shall point to the next TCD to be loaded (current one is already finished) */
            new_header = (uint8_t)sga_index;
        }
        else
        {
            /* New header shall point to this descriptor currently loaded (not finished yet) */
            new_header = sga_index != 0U ? (uint8_t)sga_index - 1U : (uint8_t)handle->tcdSize - 1U;
        }
        /* Calculate the number of finished TCDs */
        if (new_header == (uint8_t)handle->header)
        {
            int8_t tmpTcdUsed = handle->tcdUsed;
            int8_t tmpTcdSize = handle->tcdSize;

            /* check esg here for the case that application submit only one request, once the request complete:
             * new_header(1) = handle->header(1)
             * tcdUsed(1) != tcdSize(>1)
             * As the application submit only once, so scatter gather must not enabled, then tcds_done should be 1
             */
            if ((tmpTcdUsed == tmpTcdSize) || (!esg))
            {
                tcds_done = handle->tcdUsed;
            }
            else
            {
                /* No TCD in the memory are going to be loaded or internal error occurs. */
                tcds_done = 0;
            }
        }
        else
        {
            tcds_done = (int32_t)new_header - (int32_t)handle->header;
            if (tcds_done < 0)
            {
                tcds_done += handle->tcdSize;
            }
        }
        /* Advance header which points to the TCD to be loaded into the DMA engine from memory. */
        handle->header = (int8_t)new_header;
        /* Release TCD blocks. tcdUsed is the TCD number which can be used/loaded in the memory pool. */
        handle->tcdUsed -= (int8_t)tcds_done;
         if (NULL != handle->callback)
         {
             (handle->callback)(handle, handle->userData, transfer_done, tcds_done);
         }
  
         if (transfer_done)
         {
             handle->base->CDNE = handle->channel;
         }
     }
 }
 
 void DMA0_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[0]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA1_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[1]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA2_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[2]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA3_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[3]);
     SDK_ISR_EXIT_BARRIER;
 }
 
  void DMA4_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[4]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA5_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[5]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA6_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[6]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA7_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[7]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA8_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[8]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA9_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[9]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA10_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[10]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA11_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[11]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA12_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[12]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA13_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[13]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA14_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[14]);
     SDK_ISR_EXIT_BARRIER;
 }
 
 void DMA15_IRQHandler(void)
 {
     DMA_HandleIRQ(s_DMAHandle[15]);
     SDK_ISR_EXIT_BARRIER;
 }
  