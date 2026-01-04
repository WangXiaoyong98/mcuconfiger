

#include "spi_dma.h"

/***********************************************************************************************************************
* Definitons
***********************************************************************************************************************/

/*!
* @brief Structure definition for spi_master_dma_private_handle_t. The structure is private.
*/
typedef struct _spi_master_dma_private_handle
{
    SPI_Type *base;                    /*!< DSPI peripheral base address. */
    spi_master_dma_handle_t *handle; /*!< spi_master_dma_handle_t handle */
} spi_master_dma_private_handle_t;

/*!
* @brief Structure definition for dspi_slave_edma_private_handle_t. The structure is private.
*/
typedef struct _spi_slave_dma_private_handle
{
    SPI_Type *base;                   /*!< DSPI peripheral base address. */
    spi_slave_dma_handle_t *handle; /*!< spi_master_dma_handle_t handle */
} spi_slave_dma_private_handle_t;

/* @brief Has separate DMA RX and TX requests. */
#define SPI_HAS_SEPARATE_DMA_RX_TX_REQn(x) \
    ((x) == SPI1 ? (1) : \
    ((x) == SPI2 ? (0) : (-1)))

/***********************************************************************************************************************
* Prototypes
***********************************************************************************************************************/
/*!
* @brief DMA_SpiMasterCallback after the DSPI master transfer completed by using EDMA.
* This is not a public API as it is called from other driver functions.
*/
static void DMA_SpiMasterCallback(DMA_handle_t *edmaHandle,
                                    void *g_dspiEdmaPrivateHandle,
                                    bool transferDone,
                                    uint32_t tcds);

/*!
* @brief EDMA_DspiSlaveCallback after the DSPI slave transfer completed by using EDMA.
* This is not a public API as it is called from other driver functions.
*/
static void DMA_SpiSlaveCallback(DMA_handle_t *edmaHandle,
                                   void *g_dspiEdmaPrivateHandle,
                                   bool transferDone,
                                   uint32_t tcds);
/*!
* @brief Get instance number for DSPI module.
*
* This is not a public API and it's extern from fsl_dspi.c.
*
* @param base DSPI peripheral base address
*/
extern uint32_t SPI_GetInstance(SPI_Type *base);

/***********************************************************************************************************************
* Variables
***********************************************************************************************************************/

/*! @brief Pointers to dspi edma handles for each instance. */
spi_master_dma_private_handle_t g_spiMasterDmaPrivateHandle[2];
spi_slave_dma_private_handle_t g_spiSlaveDmaPrivateHandle[2];

/***********************************************************************************************************************
* Code
***********************************************************************************************************************/

void SPI_MasterCreateDmaHandle(SPI_Type *base,
                                 spi_master_dma_handle_t *handle,
                                 spi_master_dma_transfer_callback_t callback,
                                 void *userData,
                                 DMA_handle_t *edmaRxRegToRxDataHandle,
                                 DMA_handle_t *edmaTxDataToIntermediaryHandle,
                                 DMA_handle_t *edmaIntermediaryToTxRegHandle)
{
    assert(handle);

    /* Zero the handle. */
    memset(handle, 0, sizeof(*handle));

    uint32_t instance = SPI_GetInstance(base);

    g_spiMasterDmaPrivateHandle[instance].base = base;
    g_spiMasterDmaPrivateHandle[instance].handle = handle;

    handle->callback = callback;
    handle->userData = userData;

    handle->edmaRxRegToRxDataHandle = edmaRxRegToRxDataHandle;
    handle->edmaTxDataToIntermediaryHandle = edmaTxDataToIntermediaryHandle;
    handle->edmaIntermediaryToTxRegHandle = edmaIntermediaryToTxRegHandle;
}

sstat_t SPI_MasterTransferDMA(SPI_Type *base, spi_master_dma_handle_t *handle, spi_transfer_t *transfer)
{
    assert(handle && transfer);

    /* If the transfer count is zero, then return immediately.*/
    if (transfer->dataSize == 0)
    {
        return sStatus_InvalidArgument;
    }

    /* If both send buffer and receive buffer is null */
    if ((!(transfer->txData)) && (!(transfer->rxData)))
    {
        return sStatus_InvalidArgument;
    }

    /* Check that we're not busy.*/
    if (handle->state == sSPI_Busy)
    {
        return sStatus_SPI_Busy;
    }

    uint32_t instance = SPI_GetInstance(base);
    uint16_t wordToSend = 0;
    uint8_t dummyData = SPI_MASTER_DUMMY_DATA;
    uint8_t dataAlreadyFed = 0;
    uint8_t dataFedMax = 2;
    size_t tmpRemainingSendByteCount = 0;

    uint32_t rxAddr = SPI_GetRxRegisterAddress(base);
    uint32_t txAddr = SPI_MasterGetTxRegisterAddress(base);

    DMA_tcd_t *softwareTCD = (DMA_tcd_t *)((uint32_t)(&handle->dspiSoftwareTCD[1]) & (~0x1FU));

    DMA_transfer_config_t transferConfigA;
    DMA_transfer_config_t transferConfigB;
    DMA_transfer_config_t transferConfigC;

    handle->txBuffIfNull = ((uint32_t)SPI_MASTER_DUMMY_DATA << 8) | SPI_MASTER_DUMMY_DATA;

    handle->state = sSPI_Busy;

    spi_command_data_config_t commandStruct;
    SPI_StopTransfer(base);
    SPI_FlushFifo(base, true, true);
    SPI_ClearStatusFlags(base, sSPI_AllStatusFlag);

    commandStruct.whichPcs =
        (spi_which_pcs_t)(1U << ((transfer->configFlags & SPI_MASTER_PCS_MASK) >> SPI_MASTER_PCS_SHIFT));
    commandStruct.isEndOfQueue = false;
    commandStruct.clearTransferCount = false;
    commandStruct.whichCtar =
        (spi_ctar_selection_t)((transfer->configFlags & SPI_MASTER_CTAR_MASK) >> SPI_MASTER_CTAR_SHIFT);
    commandStruct.isPcsContinuous = (bool)(transfer->configFlags & sSPI_MasterPcsContinuous);
    handle->command = SPI_MasterGetFormattedCommand(&(commandStruct));

    commandStruct.isPcsContinuous = (bool)(transfer->configFlags & sSPI_MasterActiveAfterTransfer);
    handle->lastCommand = SPI_MasterGetFormattedCommand(&(commandStruct));

    handle->bitsPerFrame = ((base->CLKTAR[commandStruct.whichCtar] & SPI_CLKTAR_FSZ_MASK) >> SPI_CLKTAR_FSZ_SHIFT) + 1;

    if ((base->MCFGR & SPI_MCFGR_RXFD_MASK) || (base->MCFGR & SPI_MCFGR_TXFD_MASK))
    {
        handle->fifoSize = 1;
    }
    else
    {
        handle->fifoSize = SPI_FIFO_SIZEn(base);
    }
    handle->txData = transfer->txData;
    handle->rxData = transfer->rxData;
    handle->remainingSendByteCount = transfer->dataSize;
    handle->remainingReceiveByteCount = transfer->dataSize;
    handle->totalByteCount = transfer->dataSize;

    /* If using a shared RX/TX DMA request, then this limits the amount of data we can transfer 
     * due to the linked channel. The max bytes is 511 if 8-bit/frame or 1022 if 16-bit/frame
     */
    if (handle->bitsPerFrame > 8)
    {
        if (transfer->dataSize > 1022)
        {
            return sStatus_SPI_OutOfRange;
        }
    }
    else
    {
        if (transfer->dataSize > 511)
        {
            return sStatus_SPI_OutOfRange;
        }
    }

    SPI_DisableDMA(base, sSPI_RxDmaEnable | sSPI_TxDmaEnable);

    DMA_SetCallback(handle->edmaRxRegToRxDataHandle, DMA_SpiMasterCallback,
                     &g_spiMasterDmaPrivateHandle[instance]);

    handle->isThereExtraByte = false;
    if (handle->bitsPerFrame > 8)
    {
        if (handle->remainingSendByteCount % 2 == 1)
        {
            handle->remainingSendByteCount++;
            handle->remainingReceiveByteCount--;
            handle->isThereExtraByte = true;
        }
    }

    /*If spi has separate dma request , prepare the first data in "intermediary" .
    else (spi has shared dma request) , send first 2 data if there is fifo or send first 1 data if there is no fifo*/
    if (1 == SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
    {
        /* For DSPI instances with separate RX/TX DMA requests, we'll use the TX DMA request to
        * trigger the TX DMA channel and RX DMA request to trigger the RX DMA channel
        */

        /*Prepare the firt data*/
        if (handle->bitsPerFrame > 8)
        {
            /* If it's the last word */
            if (handle->remainingSendByteCount <= 2)
            {
                if (handle->txData)
                {
                    if (handle->isThereExtraByte)
                    {
                        wordToSend = *(handle->txData) | ((uint32_t)dummyData << 8);
                    }
                    else
                    {
                        wordToSend = *(handle->txData);
                        ++handle->txData; /* increment to next data byte */
                        wordToSend |= (unsigned)(*(handle->txData)) << 8U;
                    }
                }
                else
                {
                    wordToSend = ((uint32_t)dummyData << 8) | dummyData;
                }
                handle->lastCommand = (handle->lastCommand & 0xffff0000U) | wordToSend;
            }
            else /* For all words except the last word , frame > 8bits */
            {
                if (handle->txData)
                {
                    wordToSend = *(handle->txData);
                    ++handle->txData; /* increment to next data byte */
                    wordToSend |= (unsigned)(*(handle->txData)) << 8U;
                    ++handle->txData; /* increment to next data byte */
                }
                else
                {
                    wordToSend = ((uint32_t)dummyData << 8) | dummyData;
                }
                handle->command = (handle->command & 0xffff0000U) | wordToSend;
            }
        }
        else /* Optimized for bits/frame less than or equal to one byte. */
        {
            if (handle->txData)
            {
                wordToSend = *(handle->txData);
                ++handle->txData; /* increment to next data word*/
            }
            else
            {
                wordToSend = dummyData;
            }

            if (handle->remainingSendByteCount == 1)
            {
                handle->lastCommand = (handle->lastCommand & 0xffff0000U) | wordToSend;
            }
            else
            {
                handle->command = (handle->command & 0xffff0000U) | wordToSend;
            }
        }
    }

    else /*dspi has shared dma request*/

    {
        /* For DSPI instances with shared RX/TX DMA requests, we'll use the RX DMA request to
        * trigger ongoing transfers and will link to the TX DMA channel from the RX DMA channel.
        */

        /* If bits/frame is greater than one byte */
        if (handle->bitsPerFrame > 8)
        {
            while (SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag)
            {
                if (handle->remainingSendByteCount <= 2)
                {
                    if (handle->txData)
                    {
                        if (handle->isThereExtraByte)
                        {
                            wordToSend = *(handle->txData) | ((uint32_t)dummyData << 8);
                        }
                        else
                        {
                            wordToSend = *(handle->txData);
                            ++handle->txData;
                            wordToSend |= (unsigned)(*(handle->txData)) << 8U;
                        }
                    }
                    else
                    {
                        wordToSend = ((uint32_t)dummyData << 8) | dummyData;
                        ;
                    }
                    handle->remainingSendByteCount = 0;
                    base->PUSHTFR = (handle->lastCommand & 0xffff0000U) | wordToSend;
                }
                /* For all words except the last word */
                else
                {
                    if (handle->txData)
                    {
                        wordToSend = *(handle->txData);
                        ++handle->txData;
                        wordToSend |= (unsigned)(*(handle->txData)) << 8U;
                        ++handle->txData;
                    }
                    else
                    {
                        wordToSend = ((uint32_t)dummyData << 8) | dummyData;
                        ;
                    }
                    handle->remainingSendByteCount -= 2;
                    base->PUSHTFR = (handle->command & 0xffff0000U) | wordToSend;
                }

                /* Try to clear the TFFF; if the TX FIFO is full this will clear */
                SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

                dataAlreadyFed += 2;

                /* exit loop if send count is zero, else update local variables for next loop */
                if ((handle->remainingSendByteCount == 0) || (dataAlreadyFed == (dataFedMax * 2)))
                {
                    break;
                }
            } /* End of TX FIFO fill while loop */
        }
        else /* Optimized for bits/frame less than or equal to one byte. */
        {
            while (SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag)
            {
                if (handle->txData)
                {
                    wordToSend = *(handle->txData);
                    ++handle->txData;
                }
                else
                {
                    wordToSend = dummyData;
                }

                if (handle->remainingSendByteCount == 1)
                {
                    base->PUSHTFR = (handle->lastCommand & 0xffff0000U) | wordToSend;
                }
                else
                {
                    base->PUSHTFR = (handle->command & 0xffff0000U) | wordToSend;
                }

                /* Try to clear the TFFF; if the TX FIFO is full this will clear */
                SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

                --handle->remainingSendByteCount;

                dataAlreadyFed++;

                /* exit loop if send count is zero, else update local variables for next loop */
                if ((handle->remainingSendByteCount == 0) || (dataAlreadyFed == dataFedMax))
                {
                    break;
                }
            } /* End of TX FIFO fill while loop */
        }
    }

    /***channel_A *** used for carry the data from Rx_Data_Register(POPR) to User_Receive_Buffer*/
    DMA_ResetChannel(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel);

    transferConfigA.srcAddr = (uint32_t)rxAddr;
    transferConfigA.srcOffset = 0;

    if (handle->rxData)
    {
        transferConfigA.destAddr = (uint32_t) & (handle->rxData[0]);
        transferConfigA.destOffset = 1;
    }
    else
    {
        transferConfigA.destAddr = (uint32_t) & (handle->rxBuffIfNull);
        transferConfigA.destOffset = 0;
    }

    transferConfigA.destTransferSize = DMA_TransSize1Bytes;

    if (handle->bitsPerFrame <= 8)
    {
        transferConfigA.srcTransferSize = DMA_TransSize1Bytes;
        transferConfigA.minorLoopBytes = 1;
        transferConfigA.majorLoopCounts = handle->remainingReceiveByteCount;
    }
    else
    {
        transferConfigA.srcTransferSize = DMA_TransSize2Bytes;
        transferConfigA.minorLoopBytes = 2;
        transferConfigA.majorLoopCounts = handle->remainingReceiveByteCount / 2;
    }
    DMA_TcdSetTransferConfig((DMA_tcd_t *)&(handle->edmaRxRegToRxDataHandle->base->TCD[handle->edmaRxRegToRxDataHandle->channel]),
                           &transferConfigA, NULL);
    DMA_EnableChannelInterrupts(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                 DMA_MajorInterruptEnable);

    /***channel_B *** used for carry the data from User_Send_Buffer to "intermediary" because the SPIx_PUSHR should
    write the 32bits at once time . Then use channel_C to carry the "intermediary" to SPIx_PUSHR. Note that the
    SPIx_PUSHR upper 16 bits are the "command" and the low 16bits are data */
    DMA_ResetChannel(handle->edmaTxDataToIntermediaryHandle->base, handle->edmaTxDataToIntermediaryHandle->channel);
    
    if (handle->remainingSendByteCount > 0)
    {
        if (handle->txData)
        {
            transferConfigB.srcAddr = (uint32_t)(handle->txData);
            transferConfigB.srcOffset = 1;
        }
        else
        {
            transferConfigB.srcAddr = (uint32_t)(&handle->txBuffIfNull);
            transferConfigB.srcOffset = 0;
        }

        transferConfigB.destAddr = (uint32_t)(&handle->command);
        transferConfigB.destOffset = 0;

        transferConfigB.srcTransferSize = DMA_TransSize1Bytes;

        if (handle->bitsPerFrame <= 8)
        {
            transferConfigB.destTransferSize = DMA_TransSize1Bytes;
            transferConfigB.minorLoopBytes = 1;

            if (1 == SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
            {
                /*already prepared the first data in "intermediary" , so minus 1 */
                transferConfigB.majorLoopCounts = handle->remainingSendByteCount - 1;
            }
            else
            {
                /*Only enable channel_B minorlink to channel_C , so need to add one count due to the last time is
                majorlink , the majorlink would not trigger the channel_C*/
                transferConfigB.majorLoopCounts = handle->remainingSendByteCount + 1;
            }
        }
        else
        {
            transferConfigB.destTransferSize = DMA_TransSize2Bytes;
            transferConfigB.minorLoopBytes = 2;
            if (1 == SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
            {
                /*already prepared the first data in "intermediary" , so minus 1 */
                transferConfigB.majorLoopCounts = handle->remainingSendByteCount / 2 - 1;
            }
            else
            {
                /*Only enable channel_B minorlink to channel_C , so need to add one count due to the last time is
                * majorlink*/
                transferConfigB.majorLoopCounts = handle->remainingSendByteCount / 2 + 1;
            }
        }

        DMA_TcdSetTransferConfig((DMA_tcd_t *)(uint32_t)&(handle->edmaTxDataToIntermediaryHandle->base->TCD[handle->edmaTxDataToIntermediaryHandle->channel]), 
                                        (const DMA_transfer_config_t *)(uint32_t)&transferConfigB, NULL);
    }

    /***channel_C ***carry the "intermediary" to SPIx_PUSHR. used the edma Scatter Gather function on channel_C to
    handle the last data */
    DMA_ResetChannel(handle->edmaIntermediaryToTxRegHandle->base, handle->edmaIntermediaryToTxRegHandle->channel);
    
    if (((handle->remainingSendByteCount > 0) && (1 != SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))) ||
        ((((handle->remainingSendByteCount > 1) && (handle->bitsPerFrame <= 8)) ||
          ((handle->remainingSendByteCount > 2) && (handle->bitsPerFrame > 8))) &&
         (1 == SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))))
    {
        if (handle->txData)
        {
            uint32_t bufferIndex = 0;

            if (1 == SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
            {
                if (handle->bitsPerFrame <= 8)
                {
                    bufferIndex = handle->remainingSendByteCount - 1;
                }
                else
                {
                    bufferIndex = handle->remainingSendByteCount - 2;
                }
            }
            else
            {
                bufferIndex = handle->remainingSendByteCount;
            }

            if (handle->bitsPerFrame <= 8)
            {
                handle->lastCommand = (handle->lastCommand & 0xffff0000U) | handle->txData[bufferIndex - 1];
            }
            else
            {
                if (handle->isThereExtraByte)
                {
                    handle->lastCommand = (handle->lastCommand & 0xffff0000U) | handle->txData[bufferIndex - 2] |
                                          ((uint32_t)dummyData << 8);
                }
                else
                {
                    handle->lastCommand = (handle->lastCommand & 0xffff0000U) |
                                          ((uint32_t)handle->txData[bufferIndex - 1] << 8) |
                                          handle->txData[bufferIndex - 2];
                }
            }
        }
        else
        {
            if (handle->bitsPerFrame <= 8)
            {
                wordToSend = dummyData;
            }
            else
            {
                wordToSend = ((uint32_t)dummyData << 8) | dummyData;
            }
            handle->lastCommand = (handle->lastCommand & 0xffff0000U) | wordToSend;
        }
    }
    
    /*If spi has separate dma request , prepare the first data in "intermediary" .
      else (spi has shared dma request) , send first 2 data if there is fifo or send first 1 data if there is no fifo*/
    if ((1 == SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base)) ||
        ((1 != SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base)) && (handle->remainingSendByteCount > 0)))
    {
        transferConfigC.srcAddr = (uint32_t) & (handle->lastCommand);
        transferConfigC.destAddr = (uint32_t)txAddr;
        transferConfigC.srcTransferSize = DMA_TransSize4Bytes;
        transferConfigC.destTransferSize = DMA_TransSize4Bytes;
        transferConfigC.srcOffset = 0;
        transferConfigC.destOffset = 0;
        transferConfigC.minorLoopBytes = 4;
        transferConfigC.majorLoopCounts = 1;

        DMA_TcdReset(softwareTCD);
        DMA_TcdSetTransferConfig(softwareTCD, &transferConfigC, NULL);
    }

    if (((handle->remainingSendByteCount > 1) && (handle->bitsPerFrame <= 8)) ||
        ((handle->remainingSendByteCount > 2) && (handle->bitsPerFrame > 8)))
    {
        transferConfigC.srcAddr = (uint32_t)(&(handle->command));
        transferConfigC.destAddr = (uint32_t)txAddr;

        transferConfigC.srcTransferSize = DMA_TransSize4Bytes;
        transferConfigC.destTransferSize = DMA_TransSize4Bytes;
        transferConfigC.srcOffset = 0;
        transferConfigC.destOffset = 0;
        transferConfigC.minorLoopBytes = 4;

        if (handle->bitsPerFrame <= 8)
        {
            transferConfigC.majorLoopCounts = handle->remainingSendByteCount - 1;
        }
        else
        {
            transferConfigC.majorLoopCounts = handle->remainingSendByteCount / 2 - 1;
        }

        DMA_TcdSetTransferConfig((DMA_tcd_t *)&(handle->edmaIntermediaryToTxRegHandle->base->TCD[handle->edmaIntermediaryToTxRegHandle->channel]), 
                                 &transferConfigC, softwareTCD);
        DMA_EnableAutoStopRequest(handle->edmaIntermediaryToTxRegHandle->base,
                                   handle->edmaIntermediaryToTxRegHandle->channel, false);
    }
    else
    {
        DMA_TcdSetTransferConfig((DMA_tcd_t *)&(handle->edmaIntermediaryToTxRegHandle->base->TCD[handle->edmaIntermediaryToTxRegHandle->channel]), 
                                 &transferConfigC, NULL);
    }

    /*Start the EDMA channel_A , channel_B , channel_C transfer*/
    DMA_StartTransfer(handle->edmaRxRegToRxDataHandle);
    DMA_StartTransfer(handle->edmaTxDataToIntermediaryHandle);
    DMA_StartTransfer(handle->edmaIntermediaryToTxRegHandle);

    /*Set channel priority*/
    uint8_t channelPriorityLow = handle->edmaRxRegToRxDataHandle->channel;
    uint8_t channelPriorityMid = handle->edmaTxDataToIntermediaryHandle->channel;
    uint8_t channelPriorityHigh = handle->edmaIntermediaryToTxRegHandle->channel;
    uint8_t t = 0;

    if (channelPriorityLow > channelPriorityMid)
    {
        t = channelPriorityLow;
        channelPriorityLow = channelPriorityMid;
        channelPriorityMid = t;
    }

    if (channelPriorityLow > channelPriorityHigh)
    {
        t = channelPriorityLow;
        channelPriorityLow = channelPriorityHigh;
        channelPriorityHigh = t;
    }

    if (channelPriorityMid > channelPriorityHigh)
    {
        t = channelPriorityMid;
        channelPriorityMid = channelPriorityHigh;
        channelPriorityHigh = t;
    }

    DMA_channel_Preemption_config_t preemption_config_t;
    preemption_config_t.enableChannelPreemption = true;
    preemption_config_t.enablePreemptAbility = true;
    preemption_config_t.channelPriority = channelPriorityLow;

    if (1 != SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
    {
        DMA_SetChannelPreemptionConfig(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                        &preemption_config_t);

        preemption_config_t.channelPriority = channelPriorityMid;
        DMA_SetChannelPreemptionConfig(handle->edmaTxDataToIntermediaryHandle->base,
                                        handle->edmaTxDataToIntermediaryHandle->channel, &preemption_config_t);

        preemption_config_t.channelPriority = channelPriorityHigh;
        DMA_SetChannelPreemptionConfig(handle->edmaIntermediaryToTxRegHandle->base,
                                        handle->edmaIntermediaryToTxRegHandle->channel, &preemption_config_t);
    }
    else
    {
        DMA_SetChannelPreemptionConfig(handle->edmaIntermediaryToTxRegHandle->base,
                                        handle->edmaIntermediaryToTxRegHandle->channel, &preemption_config_t);

        preemption_config_t.channelPriority = channelPriorityMid;
        DMA_SetChannelPreemptionConfig(handle->edmaTxDataToIntermediaryHandle->base,
                                        handle->edmaTxDataToIntermediaryHandle->channel, &preemption_config_t);

        preemption_config_t.channelPriority = channelPriorityHigh;
        DMA_SetChannelPreemptionConfig(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                        &preemption_config_t);
    }

    /*Set the channel link.
    For DSPI instances with shared RX/TX DMA requests: Rx DMA request -> channel_A -> channel_B-> channel_C.
    For DSPI instances with separate RX and TX DMA requests:
    Rx DMA request -> channel_A
    Tx DMA request -> channel_C -> channel_B . (so need prepare the first data in "intermediary"  before the DMA
    transfer and then channel_B is used to prepare the next data to "intermediary" ) */
    if (1 == SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
    {
        /*if there is Tx DMA request , carry the 32bits data (handle->command) to PUSHTFR first , then link to channelB
        to prepare the next 32bits data (User_send_buffer to handle->command) */
        if (handle->remainingSendByteCount > 1)
        {
            DMA_SetChannelLink(handle->edmaIntermediaryToTxRegHandle->base,
                                handle->edmaIntermediaryToTxRegHandle->channel, DMAMinorLink,
                                handle->edmaTxDataToIntermediaryHandle->channel);
        }

        SPI_EnableDMA(base, sSPI_RxDmaEnable | sSPI_TxDmaEnable);
    }
    else
    {
        if (handle->remainingSendByteCount > 0)
        {
            DMA_SetChannelLink(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                DMAMinorLink, handle->edmaTxDataToIntermediaryHandle->channel);

            if (handle->isThereExtraByte)
            {
                DMA_SetChannelLink(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                    DMAMajorLink, handle->edmaTxDataToIntermediaryHandle->channel);
            }

            DMA_SetChannelLink(handle->edmaTxDataToIntermediaryHandle->base,
                                handle->edmaTxDataToIntermediaryHandle->channel, DMAMinorLink,
                                handle->edmaIntermediaryToTxRegHandle->channel);
        }

        SPI_EnableDMA(base, sSPI_RxDmaEnable);
    }

    SPI_StartTransfer(base);

    return sStatus_Success;
}

static void DMA_SpiMasterCallback(DMA_handle_t *edmaHandle,
                                    void *g_dspiEdmaPrivateHandle,
                                    bool transferDone,
                                    uint32_t tcds)
{
    spi_master_dma_private_handle_t *dspiEdmaPrivateHandle;

    dspiEdmaPrivateHandle = (spi_master_dma_private_handle_t *)g_dspiEdmaPrivateHandle;

    uint32_t dataReceived;

    SPI_DisableDMA((dspiEdmaPrivateHandle->base), sSPI_RxDmaEnable | sSPI_TxDmaEnable);

    if (dspiEdmaPrivateHandle->handle->isThereExtraByte)
    {
        while (!((dspiEdmaPrivateHandle->base)->STATR & SPI_STATR_RXFDF_MASK))
        {
        }
        dataReceived = (dspiEdmaPrivateHandle->base)->POPRFR;
        if (dspiEdmaPrivateHandle->handle->rxData)
        {
            (dspiEdmaPrivateHandle->handle->rxData[dspiEdmaPrivateHandle->handle->totalByteCount - 1]) = dataReceived;
        }
    }

    if (dspiEdmaPrivateHandle->handle->callback)
    {
        dspiEdmaPrivateHandle->handle->callback(dspiEdmaPrivateHandle->base, dspiEdmaPrivateHandle->handle,
                                                sStatus_Success, dspiEdmaPrivateHandle->handle->userData);
    }

    dspiEdmaPrivateHandle->handle->state = sSPI_Idle;
}

void DSPI_MasterAbortEDMA(SPI_Type *base, spi_master_dma_handle_t *handle)
{
    SPI_StopTransfer(base);

    SPI_DisableDMA(base, sSPI_RxDmaEnable | sSPI_TxDmaEnable);

    DMA_AbortTransfer(handle->edmaRxRegToRxDataHandle);
	//DMA_AbortTransfer(handle->edmaTxDataToTxRegHandle);
    DMA_AbortTransfer(handle->edmaTxDataToIntermediaryHandle);
    DMA_AbortTransfer(handle->edmaIntermediaryToTxRegHandle);

    handle->state = sSPI_Idle;
}

size_t DSPI_MasterGetTransferRemainingBytesEDMA(SPI_Type *base, spi_master_dma_handle_t *handle)
{
    size_t bytes;

    if (handle->state == sSPI_Busy)
    {
        bytes = DMA_GetRemainingBytes(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel);
    }
    else
    {
        bytes = 0;
    }
    return bytes;
}

void SPI_SlaveCreateDmaHandle(SPI_Type *base,
                                spi_slave_dma_handle_t *handle,
                                spi_slave_dma_transfer_callback_t callback,
                                void *userData,
                                DMA_handle_t *edmaRxRegToRxDataHandle,
                                DMA_handle_t *edmaTxDataToTxRegHandle)
{
    assert(handle);

    /* Zero the handle. */
    memset(handle, 0, sizeof(*handle));

    uint32_t instance = SPI_GetInstance(base);

    g_spiSlaveDmaPrivateHandle[instance].base = base;
    g_spiSlaveDmaPrivateHandle[instance].handle = handle;

    handle->callback = callback;
    handle->userData = userData;

    handle->edmaRxRegToRxDataHandle = edmaRxRegToRxDataHandle;
    handle->edmaTxDataToTxRegHandle = edmaTxDataToTxRegHandle;
}

sstat_t SPI_SlaveTransferDMA(SPI_Type *base, spi_slave_dma_handle_t *handle, spi_transfer_t *transfer)
{
    assert(handle && transfer);

    /* If send/receive length is zero */
    if (transfer->dataSize == 0)
    {
        return sStatus_InvalidArgument;
    }

    /* If both send buffer and receive buffer is null */
    if ((!(transfer->txData)) && (!(transfer->rxData)))
    {
        return sStatus_InvalidArgument;
    }

    /* Check that we're not busy.*/
    if (handle->state == sSPI_Busy)
    {
        return sStatus_SPI_Busy;
    }

    //DMA_tcd_t *softwareTCD = (DMA_tcd_t *)((uint32_t)(&handle->dspiSoftwareTCD[1]) & (~0x1FU));

    uint32_t instance = SPI_GetInstance(base);
    uint8_t whichCtar = (transfer->configFlags & SPI_SLAVE_CTAR_MASK) >> SPI_SLAVE_CTAR_SHIFT;
    handle->bitsPerFrame =
        (((base->CLKTAR_SLV[whichCtar]) & SPI_CLKTAR_SLV_FSZ_MASK) >> SPI_CLKTAR_SLV_FSZ_SHIFT) + 1;

    /* If using a shared RX/TX DMA request, then this limits the amount of data we can transfer
    * due to the linked channel. The max bytes is 511 if 8-bit/frame or 1022 if 16-bit/frame
    */
    if (1 != SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
    {
        if (handle->bitsPerFrame > 8)
        {
            if (transfer->dataSize > 1022)
            {
                return sStatus_SPI_OutOfRange;
            }
        }
        else
        {
            if (transfer->dataSize > 511)
            {
                return sStatus_SPI_OutOfRange;
            }
        }
    }

    if ((handle->bitsPerFrame > 8) && (transfer->dataSize < 2))
    {
        return sStatus_InvalidArgument;
    }

    DMA_SetCallback(handle->edmaRxRegToRxDataHandle, DMA_SpiSlaveCallback, &g_spiSlaveDmaPrivateHandle[instance]);

    handle->state = sSPI_Busy;

    /* Store transfer information */
    handle->txData                    = transfer->txData;
    handle->rxData                    = transfer->rxData;
    handle->remainingSendByteCount    = transfer->dataSize;
    handle->remainingReceiveByteCount = transfer->dataSize;
    handle->totalByteCount            = transfer->dataSize;
    handle->errorCount = 0;

    handle->isThereExtraByte = false;
    if (handle->bitsPerFrame > 8)
    {
        if (handle->remainingSendByteCount % 2 == 1)
        {
            handle->remainingSendByteCount++;
            handle->remainingReceiveByteCount--;
            handle->isThereExtraByte = true;
        }
    }

    uint16_t wordToSend = 0;
    uint8_t dummyData = SPI_SLAVE_DUMMY_DATA;
    uint8_t dataAlreadyFed = 0;
    uint8_t dataFedMax = 2;

    uint32_t rxAddr = SPI_GetRxRegisterAddress(base);
    uint32_t txAddr = SPI_SlaveGetTxRegisterAddress(base);

    DMA_transfer_config_t transferConfigA;
    DMA_transfer_config_t transferConfigC;

    SPI_StopTransfer(base);

    SPI_FlushFifo(base, true, true);
    SPI_ClearStatusFlags(base, sSPI_AllStatusFlag);

    SPI_DisableDMA(base, sSPI_RxDmaEnable | sSPI_TxDmaEnable);

    SPI_StartTransfer(base);

    /*if dspi has separate dma request , need not prepare data first .
    else (dspi has shared dma request) , send first 2 data into fifo if there is fifo or send first 1 data to
    slaveGetTxRegister if there is no fifo*/
    if (1 != SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
    {
        /* For DSPI instances with shared RX/TX DMA requests, we'll use the RX DMA request to
        * trigger ongoing transfers and will link to the TX DMA channel from the RX DMA channel.
        */
        /* If bits/frame is greater than one byte */
        if (handle->bitsPerFrame > 8)
        {
            while (SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag)
            {
                if (handle->txData)
                {
                    wordToSend = *(handle->txData);
                    ++handle->txData; /* Increment to next data byte */           
                	wordToSend |= (unsigned)(*(handle->txData)) << 8U;
                    ++handle->txData; /* Increment to next data byte */
                }
                else
                {
                    wordToSend = ((uint32_t)dummyData << 8) | dummyData;
                }
                handle->remainingSendByteCount -= 2; /* decrement remainingSendByteCount by 2 */
                base->PUSHTFR_SLV = wordToSend;

                /* Try to clear the TFFF; if the TX FIFO is full this will clear */
                SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

                dataAlreadyFed += 2;

                /* Exit loop if send count is zero, else update local variables for next loop */
                if ((handle->remainingSendByteCount == 0) || (dataAlreadyFed == (dataFedMax * 2)))
                {
                    break;
                }
            } /* End of TX FIFO fill while loop */
        }
        else /* Optimized for bits/frame less than or equal to one byte. */
        {
            while (SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag)
            {
                if (handle->txData)
                {
                    wordToSend = *(handle->txData);
                    /* Increment to next data word*/
                    ++handle->txData;
                }
                else
                {
                    wordToSend = dummyData;
                }

                base->PUSHTFR_SLV = wordToSend;

                /* Try to clear the TFFF; if the TX FIFO is full this will clear */
                SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
                /* Decrement remainingSendByteCount*/
                --handle->remainingSendByteCount;

                dataAlreadyFed++;

                /* Exit loop if send count is zero, else update local variables for next loop */
                if ((handle->remainingSendByteCount == 0) || (dataAlreadyFed == dataFedMax))
                {
                    break;
                }
            } /* End of TX FIFO fill while loop */
        }
    }

    /***channel_A *** used for carry the data from Rx_Data_Register(POPR) to User_Receive_Buffer*/
    if (handle->remainingReceiveByteCount > 0)
    {
        DMA_ResetChannel(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel);

        transferConfigA.srcAddr = (uint32_t)rxAddr;
        transferConfigA.srcOffset = 0;

        if (handle->rxData)
        {
            transferConfigA.destAddr = (uint32_t) & (handle->rxData[0]);
            transferConfigA.destOffset = 1;
        }
        else
        {
            transferConfigA.destAddr = (uint32_t) & (handle->rxBuffIfNull);
            transferConfigA.destOffset = 0;
        }

        transferConfigA.destTransferSize = DMA_TransSize1Bytes;

        if (handle->bitsPerFrame <= 8)
        {
            transferConfigA.srcTransferSize = DMA_TransSize1Bytes;
            transferConfigA.minorLoopBytes = 1;
            transferConfigA.majorLoopCounts = handle->remainingReceiveByteCount;
        }
        else
        {
            transferConfigA.srcTransferSize = DMA_TransSize2Bytes;
            transferConfigA.minorLoopBytes = 2;
            transferConfigA.majorLoopCounts = handle->remainingReceiveByteCount / 2;
        }
        
        DMA_TcdSetTransferConfig((DMA_tcd_t *)&(handle->edmaRxRegToRxDataHandle->base->TCD[handle->edmaRxRegToRxDataHandle->channel]),
                                     &transferConfigA, NULL);
        DMA_EnableChannelInterrupts(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                     DMA_MajorInterruptEnable);
    }

    if (handle->remainingSendByteCount > 0)
    {
        /***channel_C *** used for carry the data from User_Send_Buffer to Tx_Data_Register(PUSHR_SLAVE)*/
        DMA_ResetChannel(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel);

        transferConfigC.destAddr   = (uint32_t)txAddr;
        transferConfigC.destOffset = 0;

        if (NULL != handle->txData)
        {
            transferConfigC.srcAddr   = (uint32_t)(&(handle->txData[0]));
            transferConfigC.srcOffset = 1;
        }
        else
        {
            transferConfigC.srcAddr   = (uint32_t)(&handle->txBuffIfNull);
            transferConfigC.srcOffset = 0;
            if (handle->bitsPerFrame <= 8U)
            {
                handle->txBuffIfNull = dummyData;
            }
            else
            {
                handle->txBuffIfNull = ((uint32_t)dummyData << 8U) | dummyData;
            }
        }

        transferConfigC.srcTransferSize = DMA_TransSize1Bytes;

        if (handle->bitsPerFrame <= 8U)
        {
            transferConfigC.destTransferSize = DMA_TransSize1Bytes;
            transferConfigC.minorLoopBytes   = 1;
            transferConfigC.majorLoopCounts  = handle->remainingSendByteCount;
        }
        else
        {
            transferConfigC.destTransferSize = DMA_TransSize2Bytes;
            transferConfigC.minorLoopBytes   = 2;
            transferConfigC.majorLoopCounts  = handle->remainingSendByteCount / 2U;
        }

        DMA_TcdSetTransferConfig((DMA_tcd_t *)&(handle->edmaTxDataToTxRegHandle->base->TCD[handle->edmaTxDataToTxRegHandle->channel]),
                                    &transferConfigC, NULL);

        DMA_StartTransfer(handle->edmaTxDataToTxRegHandle);
    }

    DMA_StartTransfer(handle->edmaRxRegToRxDataHandle);

    /*Set channel priority*/
    uint8_t channelPriorityLow = handle->edmaRxRegToRxDataHandle->channel;
    uint8_t channelPriorityHigh = handle->edmaTxDataToTxRegHandle->channel;
    uint8_t t = 0;

    if (channelPriorityLow > channelPriorityHigh)
    {
        t = channelPriorityLow;
        channelPriorityLow = channelPriorityHigh;
        channelPriorityHigh = t;
    }

    DMA_channel_Preemption_config_t preemption_config_t;
    preemption_config_t.enableChannelPreemption = true;
    preemption_config_t.enablePreemptAbility = true;
    preemption_config_t.channelPriority = channelPriorityLow;

    if (1 != SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
    {
        DMA_SetChannelPreemptionConfig(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                        &preemption_config_t);

        preemption_config_t.channelPriority = channelPriorityHigh;
        DMA_SetChannelPreemptionConfig(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel,
                                        &preemption_config_t);
    }
    else
    {
        DMA_SetChannelPreemptionConfig(handle->edmaTxDataToTxRegHandle->base, handle->edmaTxDataToTxRegHandle->channel,
                                        &preemption_config_t);

        preemption_config_t.channelPriority = channelPriorityHigh;
        DMA_SetChannelPreemptionConfig(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                        &preemption_config_t);
    }

    /*Set the channel link.
    For DSPI instances with shared RX/TX DMA requests: Rx DMA request -> channel_A -> channel_C.
    For DSPI instances with separate RX and TX DMA requests:
    Rx DMA request -> channel_A
    Tx DMA request -> channel_C */
    if (1 != SPI_HAS_SEPARATE_DMA_RX_TX_REQn(base))
    {
        if (handle->remainingSendByteCount > 0)
        {
            DMA_SetChannelLink(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel,
                                DMAMinorLink, handle->edmaTxDataToTxRegHandle->channel);
        }
        SPI_EnableDMA(base, sSPI_RxDmaEnable);
    }
    else
    {
        SPI_EnableDMA(base, sSPI_RxDmaEnable | sSPI_TxDmaEnable);
    }

    return sStatus_Success;
}

static void DMA_SpiSlaveCallback(DMA_handle_t *edmaHandle,
                                   void *g_spiDmaPrivateHandle,
                                   bool transferDone,
                                   uint32_t tcds)
{
    spi_slave_dma_private_handle_t *spiDmaPrivateHandle;

    spiDmaPrivateHandle = (spi_slave_dma_private_handle_t *)g_spiDmaPrivateHandle;

    uint32_t dataReceived;

    SPI_DisableDMA((spiDmaPrivateHandle->base), sSPI_RxDmaEnable | sSPI_TxDmaEnable);

    if (spiDmaPrivateHandle->handle->isThereExtraByte)
    {
        while (!((spiDmaPrivateHandle->base)->STATR & SPI_STATR_RXFDF_MASK))
        {
        }
        dataReceived = (spiDmaPrivateHandle->base)->POPRFR;
        if (spiDmaPrivateHandle->handle->rxData)
        {
            (spiDmaPrivateHandle->handle->rxData[spiDmaPrivateHandle->handle->totalByteCount - 1]) = dataReceived;
        }
    }

    if (spiDmaPrivateHandle->handle->callback)
    {
        spiDmaPrivateHandle->handle->callback(spiDmaPrivateHandle->base, spiDmaPrivateHandle->handle,
                                                sStatus_Success, spiDmaPrivateHandle->handle->userData);
    }

    spiDmaPrivateHandle->handle->state = sSPI_Idle;
}

void DSPI_SlaveAbortEDMA(SPI_Type *base, spi_slave_dma_handle_t *handle)
{
    SPI_StopTransfer(base);

    SPI_DisableDMA(base, sSPI_RxDmaEnable | sSPI_TxDmaEnable);

    DMA_AbortTransfer(handle->edmaRxRegToRxDataHandle);
    DMA_AbortTransfer(handle->edmaTxDataToTxRegHandle);

    handle->state = sSPI_Idle;
}

size_t DSPI_SlaveGetTransferRemainingBytesEDMA(SPI_Type *base, spi_slave_dma_handle_t *handle)
{
    size_t bytes;

    if (handle->state == sSPI_Busy)
    {
        bytes = DMA_GetRemainingBytes(handle->edmaRxRegToRxDataHandle->base, handle->edmaRxRegToRxDataHandle->channel);
    }
    else
    {
        bytes = 0;
    }
    return bytes;
}
