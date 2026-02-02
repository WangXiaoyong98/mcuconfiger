/*
  ******************************************************************************
  * @file           : sci.h
  * @brief          : sci hal program body
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
#include "sci.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* SCI transfer state. */
enum
{
    sSCI_TxIdle, /*!< TX idle. */
    sSCI_TxBusy, /*!< TX busy. */
    sSCI_RxIdle, /*!< RX idle. */
    sSCI_RxBusy  /*!< RX busy. */
};

/* Typedef for interrupt handler. */
typedef void (*SCI_isr_t)(SCI_TypeDef *base, SCI_handle_t *handle);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Check whether the RX ring buffer is full.
 *
 * @userData handle SCI handle pointer.
 * @retval true  RX ring buffer is full.
 * @retval false RX ring buffer is not full.
 */
static bool SCI_TransferIsRxRingBufferFull(SCI_TypeDef *base, SCI_handle_t *handle);

/*!
 * @brief Write to TX register using non-blocking method.
 *
 * This function writes data to the TX register directly, upper layer must make
 * sure the TX register is empty or TX FIFO has empty room before calling this function.
 *
 * @note This function does not check whether all the data has been sent out to bus,
 * so before disable TX, check sSCI_TransmissionCompleteFlag to ensure the TX is
 * finished.
 *
 * @param base SCI peripheral base address.
 * @param data Start address of the data to write.
 * @param length Size of the buffer to be sent.
 */
static void SCI_WriteNonBlocking(SCI_TypeDef *base, const uint8_t *data, size_t length);

/*!
 * @brief Read RX register using non-blocking method.
 *
 * This function reads data from the TX register directly, upper layer must make
 * sure the RX register is full or TX FIFO has data before calling this function.
 *
 * @param base SCI peripheral base address.
 * @param data Start address of the buffer to store the received data.
 * @param length Size of the buffer.
 */
static void SCI_ReadNonBlocking(SCI_TypeDef *base, uint8_t *data, size_t length);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Array of SCI peripheral base address. */
static SCI_TypeDef *const s_SCIBases[] = SCI_BASE_PTRS;
/* Array of SCI handle. */
static SCI_handle_t *s_SCIHandle[ARRAY_SIZE(s_SCIBases)];
/* Array of SCI IRQ number. */
static const IRQn_Type s_SCIIRQ[] = SCI_RX_TX_IRQS;

/* SCI ISR for transactional APIs. */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
static SCI_isr_t s_SCIIsr = (SCI_isr_t)DefaultISR;
#else
static SCI_isr_t s_SCIIsr;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Get the SCI instance from peripheral base address.
 *
 * param base SCI peripheral base address.
 * return SCI instance.
 */
uint32_t SCI_GetInstance(SCI_TypeDef *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0U; instance < ARRAY_SIZE(s_SCIBases); instance++)
    {
        if (s_SCIBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_SCIBases));

    return instance;
}

/*!
 * brief Get the length of received data in RX ring buffer.
 *
 * userData handle SCI handle pointer.
 * return Length of received data in RX ring buffer.
 */
size_t SCI_TransferGetRxRingBufferLength(SCI_TypeDef *base, SCI_handle_t *handle)
{
    assert(NULL != handle);

    size_t size;
    size_t tmpRxRingBufferSize   = handle->rxRingBufferSize;
    uint16_t tmpRxRingBufferTail = handle->rxRingBufferTail;
    uint16_t tmpRxRingBufferHead = handle->rxRingBufferHead;

    if (tmpRxRingBufferTail > tmpRxRingBufferHead)
    {
        size = ((size_t)tmpRxRingBufferHead + tmpRxRingBufferSize - (size_t)tmpRxRingBufferTail);
    }
    else
    {
        size = ((size_t)tmpRxRingBufferHead - (size_t)tmpRxRingBufferTail);
    }

    return size;
}

static bool SCI_TransferIsRxRingBufferFull(SCI_TypeDef *base, SCI_handle_t *handle)
{
    assert(NULL != handle);

    bool full;

    if (SCI_TransferGetRxRingBufferLength(base, handle) == (handle->rxRingBufferSize - 1U))
    {
        full = true;
    }
    else
    {
        full = false;
    }
    return full;
}

static void SCI_WriteNonBlocking(SCI_TypeDef *base, const uint8_t *data, size_t length)
{
    assert(NULL != data);

    size_t i;

    /* The Non Blocking write data API assume user have ensured there is enough space in
    peripheral to write. */
    for (i = 0; i < length; i++)
    {
        base->SCIDATA = data[i];
    }
}

static void SCI_ReadNonBlocking(SCI_TypeDef *base, uint8_t *data, size_t length)
{
    assert(NULL != data);

    size_t i;

    /* The Non Blocking read data API assume user have ensured there is enough space in
    peripheral to write. */
    for (i = 0; i < length; i++)
    {

        data[i] = (uint8_t)(base->SCIDATA);

    }
}

/*!
 * brief Initializes an SCI instance with the user configuration structure and the peripheral clock.
 *
 * This function configures the SCI module with user-defined settings. Call the SCI_GetDefaultConfig() function
 * to configure the configuration structure and get the default configuration.
 * The example below shows how to use this API to configure the SCI.
 * code
 *  SCI_config_t SCIConfig;
 *  SCIConfig.baudRate_Bps = 115200U;
 *  SCIConfig.parityMode = sSCI_ParityDisabled;
 *  SCIConfig.dataBitsCount = sSCI_EightDataBits;
 *  SCIConfig.isMsb = false;
 *  SCIConfig.stopBitCount = sSCI_OneStopBit;
 *  SCIConfig.txFifoWatermark = 0;
 *  SCIConfig.rxFifoWatermark = 1;
 *  SCI_Init(SCI1, &SCIConfig, 20000000U);
 * endcode
 *
 * param base SCI peripheral base address.
 * param config Pointer to a user-defined configuration structure.
 * param srcClock_Hz SCI clock source frequency in HZ.
 * retval sStatus_SCI_BaudrateNotSupport Baudrate is not support in current clock source.
 * retval sStatus_Success SCI initialize succeed
 */
sstat_t SCI_Init(SCI_TypeDef *base, const SCI_config_t *config, uint32_t srcClock_Hz)
{
    assert(NULL != config);
    assert(0U < config->baudRate_Bps);
    assert((uint8_t)SCI_FIFO_SIZEn(base) >= config->txFifoWatermark);
    assert((uint8_t)SCI_FIFO_SIZEn(base) >= config->rxFifoWatermark);

    sstat_t status = sStatus_Success;
    uint32_t temp;
    uint16_t sbr, sbrTemp;
    uint8_t osr, osrTemp;
    uint32_t tempDiff, calculatedBaud, baudDiff;

    /* This SCI instantiation uses a slightly different baud rate calculation
     * The idea is to use the best OSR (over-sampling rate) possible
     * Note, OSR is typically hard-set to 16 in other SCI instantiations
     * loop to find the best OSR value possible, one that generates minimum baudDiff
     * iterate through the rest of the supported values of OSR */

    baudDiff = config->baudRate_Bps;
    osr      = 0U;
    sbr      = 0U;
    for (osrTemp = 4U; osrTemp <= 32U; osrTemp++)
    {
        /* calculate the temporary sbr value   */
        sbrTemp = (uint16_t)((srcClock_Hz * 10U / (config->baudRate_Bps * (uint32_t)osrTemp) + 5U) / 10U);
        /*set sbrTemp to 1 if the sourceClockInHz can not satisfy the desired baud rate*/
        if (sbrTemp == 0U)
        {
            sbrTemp = 1U;
        }
        /* Calculate the baud rate based on the temporary OSR and SBR values */
        calculatedBaud = (srcClock_Hz / ((uint32_t)osrTemp * (uint32_t)sbrTemp));
        tempDiff       = calculatedBaud > config->baudRate_Bps ? (calculatedBaud - config->baudRate_Bps) :
                                                           (config->baudRate_Bps - calculatedBaud);

        if (tempDiff <= baudDiff)
        {
            baudDiff = tempDiff;
            osr      = osrTemp; /* update and store the best OSR value calculated */
            sbr      = sbrTemp; /* update store the best SBR value calculated */
        }
    }

    /* Check to see if actual baud rate is within 3% of desired baud rate
     * based on the best calculate OSR value */
    if (baudDiff > ((config->baudRate_Bps / 100U) * 3U))
    {
        /* Unacceptable baud rate difference of more than 3%*/
        status = sStatus_SCI_BaudrateNotSupport;
    }
    else
    {
        uint32_t instance = SCI_GetInstance(base);

        /* Enable SCI clock */
        if(instance == 0){
            SYSCTRL->ISP2CGC2 |= SYSCTRL_ISP2CGC2_SCI1_MASK;
            SYSCTRL->SCICLKSEL |= SYSCTRL_SCICLKSEL_SCI1CLKSRC_SET(config->clock_source);
        }
        else if(instance == 1){
            SYSCTRL->ISP2CGC2 |= SYSCTRL_ISP2CGC2_SCI2_MASK;
            SYSCTRL->SCICLKSEL |= SYSCTRL_SCICLKSEL_SCI2CLKSRC_SET(config->clock_source);
        }
        else if(instance == 2){
            SYSCTRL->ISP2CGC2 |= SYSCTRL_ISP2CGC2_SCI3_MASK;
            SYSCTRL->SCICLKSEL |= SYSCTRL_SCICLKSEL_SCI3CLKSRC_SET(config->clock_source);
        }
        else if(instance == 3){
            SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_SCI4_MASK;
            SYSCTRL->SCICLKSEL |= SYSCTRL_SCICLKSEL_SCI4CLKSRC_SET(config->clock_source);
        }
        else if(instance == 4){
            SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_SCI5_MASK;
            SYSCTRL->SCICLKSEL |= SYSCTRL_SCICLKSEL_SCI5CLKSRC_SET(config->clock_source);    
        }
        else if(instance == 5){ 
            SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_SCI6_MASK;
            SYSCTRL->SCICLKSEL |= SYSCTRL_SCICLKSEL_SCI6CLKSRC_SET(config->clock_source);
        }
        base->SCICTRL &= ~(SCI_CTRL_TXEN_MASK | SCI_CTRL_RXEN_MASK);

        temp = base->SCICNFG;

        /* Acceptable baud rate, check if OSR is between 4x and 7x oversampling.
         * If so, then "BOTHEDGE" sampling must be turned on */
        if ((osr > 3U) && (osr < 8U))
        {
            temp |= SCI_CNFG_TWOEDGE_MASK;
        }

        /* program the osr value (bit value is one less than actual value) */
        temp &= ~SCI_CNFG_OSR_MASK;
        temp |= SCI_CNFG_OSR_SET((uint32_t)osr - 1UL);

        /* write the sbr value to the BAUD registers */
        temp &= ~SCI_CNFG_BRD_MASK;
        base->SCICNFG = temp | SCI_CNFG_BRD_SET(sbr);

        /* Set bit count and parity mode. */
        base->SCICNFG &= ~SCI_CNFG_TMOD_MASK;

        temp = base->SCICTRL & ~(SCI_CTRL_PEN_MASK | SCI_CTRL_PSEL_MASK | SCI_CTRL_BITMOD_MASK | SCI_CTRL_ILTS_MASK |
                              SCI_CTRL_IDLCFG_MASK | SCI_CTRL_LMOD_MASK);

        temp |= (uint8_t)config->parityMode | SCI_CTRL_IDLCFG_SET(config->rxIdleConfig) |
                SCI_CTRL_ILTS_SET(config->rxIdleType) | SCI_CTRL_LMOD_SET(config->loopMode);

        if (sSCI_ParityDisabled != config->parityMode)
        {
            temp |= SCI_CTRL_BITMOD_MASK; /* Eight data bits and one parity bit */
        }

        base->SCICTRL = temp;

        /* set stop bit per char */
        temp       = base->SCICNFG & ~SCI_CNFG_SBS_MASK;
        base->SCICNFG = temp | SCI_CNFG_SBS_SET((uint8_t)config->stopBitCount);
#

        /* Set tx/rx WATER watermark
           Note:
           Take care of the RX FIFO, RX interrupt request only assert when received bytes
           equal or more than RX water mark, there is potential issue if RX water
           mark larger than 1.
           For example, if RX FIFO water mark is 2, upper layer needs 5 bytes and
           5 bytes are received. the last byte will be saved in FIFO but not trigger
           RX interrupt because the water mark is 2.
         */
        base->SCIWATMK = (((uint32_t)(config->rxFifoWatermark) << 16U) | config->txFifoWatermark);

        /* Enable tx/rx FIFO */
        base->SCIFCTL |= (SCI_FCTL_TXFIFOEN_MASK | SCI_FCTL_RXFIFOEN_MASK);

        /* Flush FIFO */
        base->SCIFCTL |= (SCI_FCTL_TXBUFCLR_MASK | SCI_FCTL_RXBUFCLR_MASK);

        /* Clear all status flags */
        temp = (SCI_STATUS_RXEDGIF_MASK | SCI_STATUS_IDLF_MASK | SCI_STATUS_ROF_MASK | SCI_STATUS_NOIF_MASK |
                SCI_STATUS_FEF_MASK | SCI_STATUS_PEF_MASK);

        temp |= SCI_STATUS_LBDIF_MASK;

        temp |= (SCI_STATUS_M1F_MASK | SCI_STATUS_M2F_MASK);

        /* Set the CTS configuration/TX CTS source. */
        base->SCIRSIR |= SCI_RSIR_CTSCFG_SET(config->txCtsConfig) | SCI_RSIR_CTSSRC_SET(config->txCtsSource);
        if (true == config->enableRxRTS)
        {
            /* Enable the receiver RTS(request-to-send) function. */
            base->SCIRSIR |= SCI_RSIR_RTSE_MASK;
        }
        if (true == config->enableTxCTS)
        {
            /* Enable the CTS(clear-to-send) function. */
            base->SCIRSIR |= SCI_RSIR_TCTSE_MASK;
        }

        /* Set data bits order. */
        if (true == config->isMsb)
        {
            temp |= SCI_STATUS_MSB_MASK;
        }
        else
        {
            temp &= ~SCI_STATUS_MSB_MASK;
        }

        base->SCISTATUS |= temp;

        /* Enable TX/RX base on configure structure. */
        temp = base->SCICTRL;
        if (true == config->enableTx)
        {
            temp |= SCI_CTRL_TXEN_MASK;
        }

        if (true == config->enableRx)
        {
            temp |= SCI_CTRL_RXEN_MASK;
        }

        base->SCICTRL = temp;
    }

    return status;
}
/*!
 * brief Deinitializes a SCI instance.
 *
 * This function waits for transmit to complete, disables TX and RX, and disables the SCI clock.
 *
 * param base SCI peripheral base address.
 */
void SCI_Deinit(SCI_TypeDef *base)
{
    uint32_t temp;

    /* Wait tx FIFO send out*/
    while (0U != ((base->SCIWATMK & SCI_WATMK_TXCNT_MASK) >> SCI_WATMK_TXWAT_SHIFT))
    {
    }
    /* Wait last char shift out */
    while (0U == (base->SCISTATUS & SCI_STATUS_TCF_MASK))
    {
    }

    /* Clear all status flags */
    temp = (SCI_STATUS_RXEDGIF_MASK | SCI_STATUS_IDLF_MASK | SCI_STATUS_ROF_MASK | SCI_STATUS_NOIF_MASK |
            SCI_STATUS_FEF_MASK | SCI_STATUS_PEF_MASK);

    temp |= SCI_STATUS_LBDIF_MASK;


    temp |= (SCI_STATUS_M1F_MASK | SCI_STATUS_M2F_MASK);


    base->SCISTATUS |= temp;

    /* Disable the module. */
    base->SCICTRL = 0U;

    uint32_t instance = SCI_GetInstance(base);

    /* Disable SCI clock */
        if(instance == 0)
            SYSCTRL->ISP2CGC2 &= ~SYSCTRL_ISP2CGC2_SCI1_MASK;
        else if(instance == 1)
            SYSCTRL->ISP2CGC2 &= ~SYSCTRL_ISP2CGC2_SCI2_MASK;
        else if(instance == 2)
            SYSCTRL->ISP2CGC2 &= ~SYSCTRL_ISP2CGC2_SCI3_MASK;
        else if(instance == 3)
            SYSCTRL->ISP1CGC3 &= ~SYSCTRL_ISP1CGC3_SCI4_MASK;
        else if(instance == 4)
            SYSCTRL->ISP1CGC3 &= ~SYSCTRL_ISP1CGC3_SCI5_MASK;
        else if(instance == 5)
            SYSCTRL->ISP1CGC3 &= ~SYSCTRL_ISP1CGC3_SCI6_MASK;

}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the SCI configuration structure to a default value. The default
 * values are:
 *   SCIConfig->baudRate_Bps = 115200U;
 *   SCIConfig->parityMode = sSCI_ParityDisabled;
 *   SCIConfig->dataBitsCount = sSCI_EightDataBits;
 *   SCIConfig->isMsb = false;
 *   SCIConfig->stopBitCount = sSCI_OneStopBit;
 *   SCIConfig->txFifoWatermark = 0;
 *   SCIConfig->rxFifoWatermark = 1;
 *   SCIConfig->rxIdleType = sSCI_IdleTypeStartBit;
 *   SCIConfig->rxIdleConfig = sSCI_IdleCharacter1;
 *   SCIConfig->enableTx = false;
 *   SCIConfig->enableRx = false;
 *
 * param config Pointer to a configuration structure.
 */
void SCI_GetDefaultConfig(SCI_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->baudRate_Bps  = 115200U;
    config->parityMode    = sSCI_ParityDisabled;
    config->isMsb         = false;
    config->stopBitCount = sSCI_OneStopBit;
    config->txFifoWatermark = 0U;
    config->rxFifoWatermark = 0U;
    config->enableRxRTS = false;
    config->enableTxCTS = false;
    config->txCtsConfig = sSCI_CtsSampleAtStart;
    config->txCtsSource = sSCI_CtsSourcePin;
    config->rxIdleType   = sSCI_IdleTypeStartBit;
    config->rxIdleConfig = sSCI_IdleCharacter1;
    config->enableTx     = false;
    config->enableRx     = false;
}

/*!
 * brief Sets the SCI instance baudrate.
 *
 * This function configures the SCI module baudrate. This function is used to update
 * the SCI module baudrate after the SCI module is initialized by the SCI_Init.
 * code
 *  SCI_SetBaudRate(SCI1, 115200U, 20000000U);
 * endcode
 *
 * param base SCI peripheral base address.
 * param baudRate_Bps SCI baudrate to be set.
 * param srcClock_Hz SCI clock source frequency in HZ.
 * retval sStatus_SCI_BaudrateNotSupport Baudrate is not supported in the current clock source.
 * retval sStatus_Success Set baudrate succeeded.
 */
sstat_t SCI_SetBaudRate(SCI_TypeDef *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz)
{
    assert(0U < baudRate_Bps);

    sstat_t status = sStatus_Success;
    uint32_t temp, oldCtrl;
    uint16_t sbr, sbrTemp;
    uint8_t osr, osrTemp;
    uint32_t tempDiff, calculatedBaud, baudDiff;

    /* This SCI instantiation uses a slightly different baud rate calculation
     * The idea is to use the best OSR (over-sampling rate) possible
     * Note, OSR is typically hard-set to 16 in other SCI instantiations
     * loop to find the best OSR value possible, one that generates minimum baudDiff
     * iterate through the rest of the supported values of OSR */

    baudDiff = baudRate_Bps;
    osr      = 0U;
    sbr      = 0U;
    for (osrTemp = 4U; osrTemp <= 32U; osrTemp++)
    {
        /* calculate the temporary sbr value   */
        sbrTemp = (uint16_t)((srcClock_Hz * 10U / (baudRate_Bps * (uint32_t)osrTemp) + 5U) / 10U);
        /*set sbrTemp to 1 if the sourceClockInHz can not satisfy the desired baud rate*/
        if (sbrTemp == 0U)
        {
            sbrTemp = 1U;
        }
        /* Calculate the baud rate based on the temporary OSR and SBR values */
        calculatedBaud = srcClock_Hz / ((uint32_t)osrTemp * (uint32_t)sbrTemp);

        tempDiff = calculatedBaud > baudRate_Bps ? (calculatedBaud - baudRate_Bps) : (baudRate_Bps - calculatedBaud);

        if (tempDiff <= baudDiff)
        {
            baudDiff = tempDiff;
            osr      = osrTemp; /* update and store the best OSR value calculated */
            sbr      = sbrTemp; /* update store the best SBR value calculated */
        }
    }

    /* Check to see if actual baud rate is within 3% of desired baud rate
     * based on the best calculate OSR value */
    if (baudDiff < (uint32_t)((baudRate_Bps / 100U) * 3U))
    {
        /* Store CTRL before disable Tx and Rx */
        oldCtrl = base->SCICTRL;

        /* Disable SCI TX RX before setting. */
        base->SCICTRL &= ~(SCI_CTRL_TXEN_MASK | SCI_CTRL_RXEN_MASK);

        temp = base->SCICNFG;

        /* Acceptable baud rate, check if OSR is between 4x and 7x oversampling.
         * If so, then "BOTHEDGE" sampling must be turned on */
        if ((osr > 3U) && (osr < 8U))
        {
            temp |= SCI_CNFG_TWOEDGE_MASK;
        }

        /* program the osr value (bit value is one less than actual value) */
        temp &= ~SCI_CNFG_OSR_MASK;
        temp |= SCI_CNFG_OSR_SET((uint32_t)osr - 1UL);

        /* write the sbr value to the BAUD registers */
        temp &= ~SCI_CNFG_BRD_MASK;
        base->SCICNFG = temp | SCI_CNFG_BRD_SET(sbr);

        /* Restore CTRL. */
        base->SCICTRL = oldCtrl;
    }
    else
    {
        /* Unacceptable baud rate difference of more than 3%*/
        status = sStatus_SCI_BaudrateNotSupport;
    }

    return status;
}

/*!
 * brief Enables SCI interrupts according to a provided mask.
 *
 * This function enables the SCI interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See the ref _SCI_interrupt_enable.
 * This examples shows how to enable TX empty interrupt and RX full interrupt:
 * code
 *     SCI_EnableInterrupts(SCI1,sSCI_TxDataRegEmptyInterruptEnable | sSCI_RxDataRegFullInterruptEnable);
 * endcode
 *
 * param base SCI peripheral base address.
 * param mask The interrupts to enable. Logical OR of ref _uart_interrupt_enable.
 */
void SCI_EnableInterrupts(SCI_TypeDef *base, uint32_t mask)
{
    base->SCICNFG |= ((mask << 8U) & (SCI_CNFG_LBDIE_MASK | SCI_CNFG_RXEDGIE_MASK));
    base->SCIFCTL = (base->SCIFCTL & ~(SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK)) |
                 ((mask << 8U) & (SCI_FCTL_TXOVIE_MASK | SCI_FCTL_RXUNIE_MASK));
    mask &= 0xFFFFFF00U;
    base->SCICTRL |= mask;
}

/*!
 * brief Disables  SCI interrupts according to a provided mask.
 *
 * This function disables the SCI interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See ref _SCI_interrupt_enable.
 * This example shows how to disable the TX empty interrupt and RX full interrupt:
 * code
 *     SCI_DisableInterrupts(SCI1,sSCI_TxDataRegEmptyInterruptEnable | sSCI_RxDataRegFullInterruptEnable);
 * endcode
 *
 * param base SCI peripheral base address.
 * param mask The interrupts to disable. Logical OR of ref _SCI_interrupt_enable.
 */
void SCI_DisableInterrupts(SCI_TypeDef *base, uint32_t mask)
{
    base->SCICNFG &= ~((mask << 8U) & (SCI_CNFG_LBDIE_MASK | SCI_CNFG_RXEDGIE_MASK));
    base->SCIFCTL = (base->SCIFCTL & ~(SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK)) &
                 ~((mask << 8U) & (SCI_FCTL_TXOVIE_MASK | SCI_FCTL_RXUNIE_MASK));
    mask &= 0xFFFFFF00U;
    base->SCICTRL &= ~mask;
}

/*!
 * brief Gets enabled SCI interrupts.
 *
 * This function gets the enabled SCI interrupts. The enabled interrupts are returned
 * as the logical OR value of the enumerators ref _SCI_interrupt_enable. To check
 * a specific interrupt enable status, compare the return value with enumerators
 * in ref _SCI_interrupt_enable.
 * For example, to check whether the TX empty interrupt is enabled:
 * code
 *     uint32_t enabledInterrupts = SCI_GetEnabledInterrupts(SCI1);
 *
 *     if (sSCI_TxDataRegEmptyInterruptEnable & enabledInterrupts)
 *     {
 *         ...
 *     }
 * endcode
 *
 * param base SCI peripheral base address.
 * return SCI interrupt flags which are logical OR of the enumerators in ref _SCI_interrupt_enable.
 */
uint32_t SCI_GetEnabledInterrupts(SCI_TypeDef *base)
{
    uint32_t temp;
    temp = (base->SCICNFG & (SCI_CNFG_LBDIE_MASK | SCI_CNFG_RXEDGIE_MASK)) >> 8U;
    temp |= (base->SCIFCTL & (SCI_FCTL_TXOVIE_MASK | SCI_FCTL_RXUNIE_MASK)) >> 8U;
    temp |= (uint32_t)(base->SCICTRL & 0xFF0C000u);

    return temp;
}

/*!
 * brief Gets SCI status flags.
 *
 * This function gets all SCI status flags. The flags are returned as the logical
 * OR value of the enumerators ref _SCI_flags. To check for a specific status,
 * compare the return value with enumerators in the ref _SCI_flags.
 * For example, to check whether the TX is empty:
 * code
 *     if (sSCI_TxDataRegEmptyFlag & SCI_GetStatusFlags(SCI1))
 *     {
 *         ...
 *     }
 * endcode
 *
 * param base SCI peripheral base address.
 * return SCI status flags which are ORed by the enumerators in the _SCI_flags.
 */
uint32_t SCI_GetStatusFlags(SCI_TypeDef *base)
{
    uint32_t temp;
    temp = base->SCISTATUS;
    temp |= (base->SCIFCTL &
             (SCI_FCTL_TFEMPT_MASK | SCI_FCTL_RFEMPT_MASK | SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK)) >>
            16U;
    return temp;
}

/*!
 * brief Clears status flags with a provided mask.
 *
 * This function clears SCI status flags with a provided mask. Automatically cleared flags
 * can't be cleared by this function.
 * Flags that can only cleared or set by hardware are:
 *    sSCI_TxDataRegEmptyFlag, sSCI_TransmissionCompleteFlag, sSCI_RxDataRegFullFlag,
 *    sSCI_RxActiveFlag, sSCI_NoiseErrorInRxDataRegFlag, sSCI_ParityErrorInRxDataRegFlag,
 *    sSCI_TxFifoEmptyFlag,sSCI_RxFifoEmptyFlag
 * Note: This API should be called when the Tx/Rx is idle, otherwise it takes no effects.
 *
 * param base SCI peripheral base address.
 * param mask the status flags to be cleared. The user can use the enumerators in the
 *  _SCI_status_flag_t to do the OR operation and get the mask.
 * return 0 succeed, others failed.
 * retval sStatus_SCI_FlagCannotClearManually The flag can't be cleared by this function but
 *         it is cleared automatically by hardware.
 * retval sStatus_Success Status in the mask are cleared.
 */
sstat_t SCI_ClearStatusFlags(SCI_TypeDef *base, uint32_t mask)
{
    uint32_t temp;
    sstat_t status;
    temp = (uint32_t)base->SCIFCTL;
    temp &= (uint32_t)(~(SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK));
    temp |= (mask << 16U) & (SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK);
    base->SCIFCTL = temp;
    temp = (uint32_t)base->SCISTATUS;
    temp &= (uint32_t)(~(SCI_STATUS_LBDIF_MASK));
    temp |= mask & SCI_STATUS_LBDIF_MASK;
    temp &= (uint32_t)(~(SCI_STATUS_RXEDGIF_MASK | SCI_STATUS_IDLF_MASK | SCI_STATUS_ROF_MASK | SCI_STATUS_NOIF_MASK |
                         SCI_STATUS_FEF_MASK | SCI_STATUS_PEF_MASK));
    temp |= mask & (SCI_STATUS_RXEDGIF_MASK | SCI_STATUS_IDLF_MASK | SCI_STATUS_ROF_MASK | SCI_STATUS_NOIF_MASK |
                    SCI_STATUS_FEF_MASK | SCI_STATUS_PEF_MASK);
    temp &= (uint32_t)(~(SCI_STATUS_M2F_MASK | SCI_STATUS_M1F_MASK));
    temp |= mask & (SCI_STATUS_M2F_MASK | SCI_STATUS_M1F_MASK);
    base->SCISTATUS = temp;
    /* If some flags still pending. */
    if (0U != (mask & SCI_GetStatusFlags(base)))
    {
        /* Some flags can only clear or set by the hardware itself, these flags are: sSCI_TxDataRegEmptyFlag,
        sSCI_TransmissionCompleteFlag, sSCI_RxDataRegFullFlag, sSCI_RxActiveFlag,
        sSCI_NoiseErrorInRxDataRegFlag, sSCI_ParityErrorInRxDataRegFlag,
        sSCI_TxFifoEmptyFlag, sSCI_RxFifoEmptyFlag. */
        status = sStatus_SCI_FlagCannotClearManually; /* flags can not clear manually */
    }
    else
    {
        status = sStatus_Success;
    }

    return status;
}

/*!
 * brief Writes to the transmitter register using a blocking method.
 *
 * This function polls the transmitter register, first waits for the register to be empty or TX FIFO to have room,
 * and writes data to the transmitter buffer, then waits for the data to be sent out to bus.
 *
 * param base SCI peripheral base address.
 * param data Start address of the data to write.
 * param length Size of the data to write.
 * retval sStatus_SCI_Timeout Transmission timed out and was aborted.
 * retval sStatus_Success Successfully wrote all data.
 */
sstat_t SCI_WriteBlocking(SCI_TypeDef *base, const uint8_t *data, size_t length)
{
    assert(NULL != data);

    const uint8_t *dataAddress = data;
    size_t transferSize        = length;

#if UART_RETRY_TIMES
    uint32_t waitTimes;
#endif

    while (0U != transferSize)
    {
#if UART_RETRY_TIMES
        waitTimes = UART_RETRY_TIMES;
        while ((0U == (base->SCISTATUS & SCI_STATUS_TDREF_MASK)) && (0U != --waitTimes))
#else
        while (0U == (base->SCISTATUS & SCI_STATUS_TDREF_MASK))
#endif
        {
        }
#if UART_RETRY_TIMES
        if (0U == waitTimes)
        {
            return sStatus_SCI_Timeout;
        }
#endif
        base->SCIDATA = *(dataAddress);
        dataAddress++;
        transferSize--;
    }
    /* Ensure all the data in the transmit buffer are sent out to bus. */
#if UART_RETRY_TIMES
    waitTimes = UART_RETRY_TIMES;
    while ((0U == (base->SCISTATUS & SCI_STATUS_TCF_MASK)) && (0U != --waitTimes))
#else
    while (0U == (base->SCISTATUS & SCI_STATUS_TCF_MASK))
#endif
    {
    }
#if UART_RETRY_TIMES
    if (0U == waitTimes)
    {
        return sStatus_SCI_Timeout;
    }
#endif
    return sStatus_Success;
}

/*!
 * brief Reads the receiver data register using a blocking method.
 *
 * This function polls the receiver register, waits for the receiver register full or receiver FIFO
 * has data, and reads data from the TX register.
 *
 * param base SCI peripheral base address.
 * param data Start address of the buffer to store the received data.
 * param length Size of the buffer.
 * retval sStatus_SCI_RxHardwareOverrun Receiver overrun happened while receiving data.
 * retval sStatus_SCI_NoiseError Noise error happened while receiving data.
 * retval sStatus_SCI_FramingError Framing error happened while receiving data.
 * retval sStatus_SCI_ParityError Parity error happened while receiving data.
 * retval sStatus_SCI_Timeout Transmission timed out and was aborted.
 * retval sStatus_Success Successfully received all data.
 */
sstat_t SCI_ReadBlocking(SCI_TypeDef *base, uint8_t *data, size_t length)
{
    assert(NULL != data);

    sstat_t status = sStatus_Success;
    uint32_t statusFlag;
    uint8_t *dataAddress = data;

#if UART_RETRY_TIMES
    uint32_t waitTimes;
#endif

    while (0U != (length--))
    {
#if UART_RETRY_TIMES
        waitTimes = UART_RETRY_TIMES;
#endif
        while (0U == ((base->SCIWATMK & SCI_WATMK_RXCNT_MASK) >> SCI_WATMK_RXCNT_SHIFT))
        {
#if UART_RETRY_TIMES
            if (0U == --waitTimes)
            {
                status = sStatus_SCI_Timeout;
                break;
            }
#endif
            statusFlag = SCI_GetStatusFlags(base);

            if (0U != (statusFlag & (uint32_t)sSCI_RxOverrunFlag))
            {
                status = ((sStatus_Success == SCI_ClearStatusFlags(base, (uint32_t)sSCI_RxOverrunFlag)) ?
                              (sStatus_SCI_RxHardwareOverrun) :
                              (sStatus_SCI_FlagCannotClearManually));
                /* Other error flags(FE, NF, and PF) are prevented from setting once OR is set, no need to check other
                 * error flags*/
                break;
            }

            if (0U != (statusFlag & (uint32_t)sSCI_ParityErrorFlag))
            {
                status = ((sStatus_Success == SCI_ClearStatusFlags(base, (uint32_t)sSCI_ParityErrorFlag)) ?
                              (sStatus_SCI_ParityError) :
                              (sStatus_SCI_FlagCannotClearManually));
            }

            if (0U != (statusFlag & (uint32_t)sSCI_FramingErrorFlag))
            {
                status = ((sStatus_Success == SCI_ClearStatusFlags(base, (uint32_t)sSCI_FramingErrorFlag)) ?
                              (sStatus_SCI_FramingError) :
                              (sStatus_SCI_FlagCannotClearManually));
            }

            if (0U != (statusFlag & (uint32_t)sSCI_NoiseErrorFlag))
            {
                status = ((sStatus_Success == SCI_ClearStatusFlags(base, (uint32_t)sSCI_NoiseErrorFlag)) ?
                              (sStatus_SCI_NoiseError) :
                              (sStatus_SCI_FlagCannotClearManually));
            }
            if (sStatus_Success != status)
            {
                break;
            }
        }

        if (sStatus_Success == status)
        {

            *(dataAddress) = (uint8_t)base->SCIDATA;
            dataAddress++;

        }
        else
        {
            break;
        }
    }

    return status;
}

/*!
 * brief Initializes the SCI handle.
 *
 * This function initializes the SCI handle, which can be used for other SCI
 * transactional APIs. Usually, for a specified SCI instance,
 * call this API once to get the initialized handle.
 *
 * The SCI driver supports the "background" receiving, which means that user can set up
 * an RX ring buffer optionally. Data received is stored into the ring buffer even when the
 * user doesn't call the SCI_TransferReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, the user can get the received data from the ring buffer directly.
 * The ring buffer is disabled if passing NULL as p ringBuffer.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 * param callback Callback function.
 * param userData User data.
 */
void SCI_TransferCreateHandle(SCI_TypeDef *base,
                                 SCI_handle_t *handle,
                                 SCI_transfer_callback_t callback,
                                 void *userData)
{
    assert(NULL != handle);

    uint32_t instance;

    /* Zero the handle. */
    (void)memset(handle, 0, sizeof(SCI_handle_t));

    /* Set the TX/RX state. */
    handle->rxState = (uint8_t)sSCI_RxIdle;
    handle->txState = (uint8_t)sSCI_TxIdle;

    /* Set the callback and user data. */
    handle->callback = callback;
    handle->userData = userData;

    /* Get instance from peripheral base address. */
    instance = SCI_GetInstance(base);

    /* Save the handle in global variables to support the double weak mechanism. */
    s_SCIHandle[instance] = handle;

    s_SCIIsr = SCI_TransferHandleIRQ;

/* Enable interrupt in NVIC. */
    (void)EnableIRQ(s_SCIIRQ[instance]);
}

/*!
 * brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific UART handle.
 *
 * When the RX ring buffer is used, data received is stored into the ring buffer even when
 * the user doesn't call the UART_TransferReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, the user can get the received data from the ring buffer directly.
 *
 * note When using RX ring buffer, one byte is reserved for internal use. In other
 * words, if p ringBufferSize is 32, then only 31 bytes are used for saving data.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 * param ringBuffer Start address of ring buffer for background receiving. Pass NULL to disable the ring buffer.
 * param ringBufferSize size of the ring buffer.
 */
void SCI_TransferStartRingBuffer(SCI_TypeDef *base,
                                    SCI_handle_t *handle,
                                    uint8_t *ringBuffer,
                                    size_t ringBufferSize)
{
    assert(NULL != handle);
    assert(NULL != ringBuffer);

    /* Setup the ring buffer address */
    handle->rxRingBuffer     = ringBuffer;
    handle->rxRingBufferSize = ringBufferSize;
    handle->rxRingBufferHead = 0U;
    handle->rxRingBufferTail = 0U;

    /* Enable the interrupt to accept the data when user need the ring buffer. */
    SCI_EnableInterrupts(
        base, (uint32_t)sSCI_RxDataRegFullInterruptEnable | (uint32_t)sSCI_RxOverrunInterruptEnable);
}

/*!
 * brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ring buffer.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 */
void SCI_TransferStopRingBuffer(SCI_TypeDef *base, SCI_handle_t *handle)
{
    assert(NULL != handle);

    if (handle->rxState == (uint8_t)sSCI_RxIdle)
    {
        SCI_DisableInterrupts(
            base, (uint32_t)sSCI_RxDataRegFullInterruptEnable | (uint32_t)sSCI_RxOverrunInterruptEnable);
    }

    handle->rxRingBuffer     = NULL;
    handle->rxRingBufferSize = 0U;
    handle->rxRingBufferHead = 0U;
    handle->rxRingBufferTail = 0U;
}

/*!
 * brief Transmits a buffer of data using the interrupt method.
 *
 * This function send data using an interrupt method. This is a non-blocking function, which
 * returns directly without waiting for all data written to the transmitter register. When
 * all data is written to the TX register in the ISR, the SCI driver calls the callback
 * function and passes the ref sStatus_SCI_TxIdle as status parameter.
 *
 * note The sStatus_SCI_TxIdle is passed to the upper layer when all data are written
 * to the TX register. However, there is no check to ensure that all the data sent out. Before disabling the TX,
 * check the sSCI_TransmissionCompleteFlag to ensure that the transmit is finished.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 * param xfer SCI transfer structure, see #SCI_transfer_t.
 * retval sStatus_Success Successfully start the data transmission.
 * retval sStatus_SCI_TxBusy Previous transmission still not finished, data not all written to the TX register.
 * retval sStatus_InvalidArgument Invalid argument.
 */
sstat_t SCI_TransferSendNonBlocking(SCI_TypeDef *base, SCI_handle_t *handle, SCI_transfer_t *xfer)
{
    assert(NULL != handle);
    assert(NULL != xfer);
    assert(NULL != xfer->data);
    assert(0U != xfer->dataSize);

    sstat_t status;

    /* Return error if current TX busy. */
    if ((uint8_t)sSCI_TxBusy == handle->txState)
    {
        status = sStatus_SCI_TxBusy;
    }
    else
    {
        handle->txData        = xfer->data;
        handle->txDataSize    = xfer->dataSize;
        handle->txDataSizeAll = xfer->dataSize;
        handle->txState       = (uint8_t)sSCI_TxBusy;

        /* Enable transmitter interrupt. */
        SCI_EnableInterrupts(base, (uint32_t)sSCI_TxDataRegEmptyInterruptEnable);

        status = sStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt driven data sending. The user can get the remainBtyes to find out
 * how many bytes are not sent out.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 */
void SCI_TransferAbortSend(SCI_TypeDef *base, SCI_handle_t *handle)
{
    assert(NULL != handle);

    SCI_DisableInterrupts(
        base, (uint32_t)sSCI_TxDataRegEmptyInterruptEnable | (uint32_t)sSCI_TransmissionCompleteInterruptEnable);

    handle->txDataSize = 0;
    handle->txState    = (uint8_t)sSCI_TxIdle;
}

/*!
 * brief Gets the number of bytes that have been sent out to bus.
 *
 * This function gets the number of bytes that have been sent out to bus by an interrupt method.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 * param count Send bytes count.
 * retval sStatus_NoTransferInProgress No send in progress.
 * retval sStatus_InvalidArgument Parameter is invalid.
 * retval sStatus_Success Get successfully through the parameter \p count;
 */
sstat_t SCI_TransferGetSendCount(SCI_TypeDef *base, SCI_handle_t *handle, uint32_t *count)
{
    assert(NULL != handle);
    assert(NULL != count);

    sstat_t status      = sStatus_Success;
    size_t tmptxDataSize = handle->txDataSize;

    if ((uint8_t)sSCI_TxIdle == handle->txState)
    {
        status = sStatus_NoTransferInProgress;
    }
    else
    {
        *count = handle->txDataSizeAll - tmptxDataSize -
                 ((base->SCIWATMK & SCI_WATMK_TXCNT_MASK) >> SCI_WATMK_TXCNT_SHIFT);
    }

    return status;
}

/*!
 * brief Receives a buffer of data using the interrupt method.
 *
 * This function receives data using an interrupt method. This is a non-blocking function
 * which returns without waiting to ensure that all data are received.
 * If the RX ring buffer is used and not empty, the data in the ring buffer is copied and
 * the parameter p receivedBytes shows how many bytes are copied from the ring buffer.
 * After copying, if the data in the ring buffer is not enough for read, the receive
 * request is saved by the SCI driver. When the new data arrives, the receive request
 * is serviced first. When all data is received, the SCI driver notifies the upper layer
 * through a callback function and passes a status parameter ref sStatus_UART_RxIdle.
 * For example, the upper layer needs 10 bytes but there are only 5 bytes in ring buffer.
 * The 5 bytes are copied to xfer->data, which returns with the
 * parameter p receivedBytes set to 5. For the remaining 5 bytes, the newly arrived data is
 * saved from xfer->data[5]. When 5 bytes are received, the SCI driver notifies the upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to xfer->data. When all data is received, the upper layer is notified.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 * param xfer SCI transfer structure, see #uart_transfer_t.
 * param receivedBytes Bytes received from the ring buffer directly.
 * retval sStatus_Success Successfully queue the transfer into the transmit queue.
 * retval sStatus_SCI_RxBusy Previous receive request is not finished.
 * retval sStatus_InvalidArgument Invalid argument.
 */
sstat_t SCI_TransferReceiveNonBlocking(SCI_TypeDef *base,
                                           SCI_handle_t *handle,
                                           SCI_transfer_t *xfer,
                                           size_t *receivedBytes)
{
    assert(NULL != handle);
    assert(NULL != xfer);
    assert(NULL != xfer->data);
    assert(0U != xfer->dataSize);

    uint32_t i;
    sstat_t status;
    /* How many bytes to copy from ring buffer to user memory. */
    size_t bytesToCopy = 0U;
    /* How many bytes to receive. */
    size_t bytesToReceive;
    /* How many bytes currently have received. */
    size_t bytesCurrentReceived;

    /* How to get data:
       1. If RX ring buffer is not enabled, then save xfer->data and xfer->dataSize
          to SCI handle, enable interrupt to store received data to xfer->data. When
          all data received, trigger callback.
       2. If RX ring buffer is enabled and not empty, get data from ring buffer first.
          If there are enough data in ring buffer, copy them to xfer->data and return.
          If there are not enough data in ring buffer, copy all of them to xfer->data,
          save the xfer->data remained empty space to SCI handle, receive data
          to this empty space and trigger callback when finished. */

    if ((uint8_t)sSCI_RxBusy == handle->rxState)
    {
        status = sStatus_SCI_RxBusy;
    }
    else
    {
        bytesToReceive       = xfer->dataSize;
        bytesCurrentReceived = 0;

        /* If RX ring buffer is used. */
        if (NULL != handle->rxRingBuffer)
        {
            /* Disable SCI RX IRQ, protect ring buffer. */
            SCI_DisableInterrupts(base, (uint32_t)sSCI_RxDataRegFullInterruptEnable);

            /* How many bytes in RX ring buffer currently. */
            bytesToCopy = SCI_TransferGetRxRingBufferLength(base, handle);

            if (0U != bytesToCopy)
            {
                bytesToCopy = MIN(bytesToReceive, bytesToCopy);

                bytesToReceive -= bytesToCopy;

                /* Copy data from ring buffer to user memory. */
                for (i = 0U; i < bytesToCopy; i++)
                {
                    xfer->data[bytesCurrentReceived] = handle->rxRingBuffer[handle->rxRingBufferTail];
                    bytesCurrentReceived++;

                    /* Wrap to 0. Not use modulo (%) because it might be large and slow. */
                    if (((uint32_t)handle->rxRingBufferTail + 1U) == handle->rxRingBufferSize)
                    {
                        handle->rxRingBufferTail = 0U;
                    }
                    else
                    {
                        handle->rxRingBufferTail++;
                    }
                }
            }

            /* If ring buffer does not have enough data, still need to read more data. */
            if (0U != bytesToReceive)
            {
                /* No data in ring buffer, save the request to SCI handle. */
                handle->rxData        = xfer->data + bytesCurrentReceived;
                handle->rxDataSize    = bytesToReceive;
                handle->rxDataSizeAll = bytesToReceive;
                handle->rxState       = (uint8_t)sSCI_RxBusy;
            }
            /* Enable SCI RX IRQ if previously enabled. */
            SCI_EnableInterrupts(base, (uint32_t)sSCI_RxDataRegFullInterruptEnable);

            /* Call user callback since all data are received. */
            if (0U == bytesToReceive)
            {
                if (NULL != handle->callback)
                {
                    handle->callback(base, handle, sStatus_SCI_RxIdle, handle->userData);
                }
            }
        }
        /* Ring buffer not used. */
        else
        {
            handle->rxData        = xfer->data + bytesCurrentReceived;
            handle->rxDataSize    = bytesToReceive;
            handle->rxDataSizeAll = bytesToReceive;
            handle->rxState       = (uint8_t)sSCI_RxBusy;

            /* Enable RX interrupt. */
            SCI_EnableInterrupts(base, (uint32_t)sSCI_RxDataRegFullInterruptEnable |
                                              (uint32_t)sSCI_RxOverrunInterruptEnable |
                                              (uint32_t)sSCI_IdleLineInterruptEnable);
        }

        /* Return the how many bytes have read. */
        if (NULL != receivedBytes)
        {
            *receivedBytes = bytesCurrentReceived;
        }

        status = sStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the interrupt-driven data receiving.
 *
 * This function aborts the interrupt-driven data receiving. The user can get the remainBytes to find out
 * how many bytes not received yet.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 */
void SCI_TransferAbortReceive(SCI_TypeDef *base, SCI_handle_t *handle)
{
    assert(NULL != handle);

    /* Only abort the receive to handle->rxData, the RX ring buffer is still working. */
    if (NULL == handle->rxRingBuffer)
    {
        /* Disable RX interrupt. */
        SCI_DisableInterrupts(base, (uint32_t)sSCI_RxDataRegFullInterruptEnable |
                                           (uint32_t)sSCI_RxOverrunInterruptEnable |
                                           (uint32_t)sSCI_IdleLineInterruptEnable);
    }

    handle->rxDataSize = 0U;
    handle->rxState    = (uint8_t)sSCI_RxIdle;
}

/*!
 * brief Gets the number of bytes that have been received.
 *
 * This function gets the number of bytes that have been received.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 * param count Receive bytes count.
 * retval sStatus_NoTransferInProgress No receive in progress.
 * retval sStatus_InvalidArgument Parameter is invalid.
 * retval sStatus_Success Get successfully through the parameter \p count;
 */
sstat_t SCI_TransferGetReceiveCount(SCI_TypeDef *base, SCI_handle_t *handle, uint32_t *count)
{
    assert(NULL != handle);
    assert(NULL != count);

    sstat_t status      = sStatus_Success;
    size_t tmprxDataSize = handle->rxDataSize;

    if ((uint8_t)sSCI_RxIdle == handle->rxState)
    {
        status = sStatus_NoTransferInProgress;
    }
    else
    {
        *count = handle->rxDataSizeAll - tmprxDataSize;
    }

    return status;
}

/*!
 * brief SCI IRQ handle function.
 *
 * This function handles the SCI transmit and receive IRQ request.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 */
void SCI_TransferHandleIRQ(SCI_TypeDef *base, SCI_handle_t *handle)
{
    assert(NULL != handle);

    uint8_t count;
    uint8_t tempCount;
    uint32_t status            = SCI_GetStatusFlags(base);
    uint32_t enabledInterrupts = SCI_GetEnabledInterrupts(base);
    uint16_t tpmRxRingBufferHead;
    uint32_t tpmData;

    /* If RX overrun. */
    if ((uint32_t)sSCI_RxOverrunFlag == ((uint32_t)sSCI_RxOverrunFlag & status))
    {
        /* Clear overrun flag, otherwise the RX does not work. */
        base->SCISTATUS = ((base->SCISTATUS & 0x3FE00000U) | SCI_STATUS_ROF_MASK);

        /* Trigger callback. */
        if (NULL != (handle->callback))
        {
            handle->callback(base, handle, sStatus_SCI_RxHardwareOverrun, handle->userData);
        }
    }

    /* If IDLE flag is set and the IDLE interrupt is enabled. */
    if ((0U != ((uint32_t)sSCI_IdleLineFlag & status)) &&
        (0U != ((uint32_t)sSCI_IdleLineInterruptEnable & enabledInterrupts)))
    {
        count = ((uint8_t)((base->SCIWATMK & SCI_WATMK_RXCNT_MASK) >> SCI_WATMK_RXCNT_SHIFT));

        while ((0U != handle->rxDataSize) && (0U != count))
        {
            tempCount = (uint8_t)MIN(handle->rxDataSize, count);

            /* Using non block API to read the data from the registers. */
            SCI_ReadNonBlocking(base, handle->rxData, tempCount);
            handle->rxData += tempCount;
            handle->rxDataSize -= tempCount;
            count -= tempCount;

            /* If rxDataSize is 0, disable idle line interrupt.*/
            if (0U == (handle->rxDataSize))
            {
                handle->rxState = (uint8_t)sSCI_RxIdle;

                SCI_DisableInterrupts(
                    base, (uint32_t)sSCI_RxDataRegFullInterruptEnable | (uint32_t)sSCI_RxOverrunInterruptEnable);
                if (NULL != handle->callback)
                {
                    handle->callback(base, handle, sStatus_SCI_RxIdle, handle->userData);
                }
            }
        }
        /* Clear IDLE flag.*/
        base->SCISTATUS |= SCI_STATUS_IDLF_MASK;

        /* If rxDataSize is 0, disable idle line interrupt.*/
        if (0U != (handle->rxDataSize))
        {
            SCI_DisableInterrupts(base, (uint32_t)sSCI_IdleLineInterruptEnable);
        }
        /* If callback is not NULL and rxDataSize is not 0. */
        if ((0U != handle->rxDataSize) && (NULL != handle->callback))
        {
            handle->callback(base, handle, sStatus_SCI_IdleLineDetected, handle->userData);
        }
    }
    /* Receive data register full */
    if ((0U != ((uint32_t)sSCI_RxDataRegFullFlag & status)) &&
        (0U != ((uint32_t)sSCI_RxDataRegFullInterruptEnable & enabledInterrupts)))
    {
/* Get the size that can be stored into buffer for this interrupt. */
        count = ((uint8_t)((base->SCIWATMK & SCI_WATMK_RXCNT_MASK) >> SCI_WATMK_RXCNT_SHIFT));

        /* If handle->rxDataSize is not 0, first save data to handle->rxData. */
        while ((0U != handle->rxDataSize) && (0U != count))
        {
            tempCount = (uint8_t)MIN(handle->rxDataSize, count);

            /* Using non block API to read the data from the registers. */
            SCI_ReadNonBlocking(base, handle->rxData, tempCount);
            handle->rxData += tempCount;
            handle->rxDataSize -= tempCount;
            count -= tempCount;

            /* If all the data required for upper layer is ready, trigger callback. */
            if (0U == handle->rxDataSize)
            {
                handle->rxState = (uint8_t)sSCI_RxIdle;

                if (NULL != handle->callback)
                {
                    handle->callback(base, handle, sStatus_SCI_RxIdle, handle->userData);
                }
            }
        }

        /* If use RX ring buffer, receive data to ring buffer. */
        if (NULL != handle->rxRingBuffer)
        {
            while (0U != count--)
            {
                /* If RX ring buffer is full, trigger callback to notify over run. */
                if (SCI_TransferIsRxRingBufferFull(base, handle))
                {
                    if (NULL != handle->callback)
                    {
                        handle->callback(base, handle, sStatus_SCI_RxRingBufferOverrun, handle->userData);
                    }
                }

                /* If ring buffer is still full after callback function, the oldest data is overridden. */
                if (SCI_TransferIsRxRingBufferFull(base, handle))
                {
                    /* Increase handle->rxRingBufferTail to make room for new data. */
                    if (((uint32_t)handle->rxRingBufferTail + 1U) == handle->rxRingBufferSize)
                    {
                        handle->rxRingBufferTail = 0U;
                    }
                    else
                    {
                        handle->rxRingBufferTail++;
                    }
                }

                /* Read data. */
                tpmRxRingBufferHead = handle->rxRingBufferHead;
                tpmData             = base->SCIDATA;
                handle->rxRingBuffer[tpmRxRingBufferHead] = (uint8_t)tpmData;

                /* Increase handle->rxRingBufferHead. */
                if (((uint32_t)handle->rxRingBufferHead + 1U) == handle->rxRingBufferSize)
                {
                    handle->rxRingBufferHead = 0U;
                }
                else
                {
                    handle->rxRingBufferHead++;
                }
            }
        }
        /* If no receive requst pending, stop RX interrupt. */
        else if (0U == handle->rxDataSize)
        {
            SCI_DisableInterrupts(
                base, (uint32_t)sSCI_RxDataRegFullInterruptEnable | (uint32_t)sSCI_RxOverrunInterruptEnable);
        }
        else
        {
        }
    }

    /* Send data register empty and the interrupt is enabled. */
    if ((0U != ((uint32_t)sSCI_TxDataRegEmptyFlag & status)) &&
        (0U != ((uint32_t)sSCI_TxDataRegEmptyInterruptEnable & enabledInterrupts)))
    {
/* Get the bytes that available at this moment. */
        count = (uint8_t)SCI_FIFO_SIZEn(base) -
                (uint8_t)((base->SCIWATMK & SCI_WATMK_TXCNT_MASK) >> SCI_WATMK_TXCNT_SHIFT);

        while ((0U != handle->txDataSize) && (0U != count))
        {
            tempCount = (uint8_t)MIN(handle->txDataSize, count);

            /* Using non block API to write the data to the registers. */
            SCI_WriteNonBlocking(base, handle->txData, tempCount);
            handle->txData += tempCount;
            handle->txDataSize -= tempCount;
            count -= tempCount;

            /* If all the data are written to data register, notify user with the callback, then TX finished. */
            if (0U == handle->txDataSize)
            {
                /* Disable TX register empty interrupt. */
                base->SCICTRL = (base->SCICTRL & ~SCI_CTRL_TXIE_MASK);
                /* Enable transmission complete interrupt. */
                SCI_EnableInterrupts(base, (uint32_t)sSCI_TransmissionCompleteInterruptEnable);
            }
        }
    }

    /* Transmission complete and the interrupt is enabled. */
    if ((0U != ((uint32_t)sSCI_TransmissionCompleteFlag & status)) &&
        (0U != ((uint32_t)sSCI_TransmissionCompleteInterruptEnable & enabledInterrupts)))
    {
        /* Set txState to idle only when all data has been sent out to bus. */
        handle->txState = (uint8_t)sSCI_TxIdle;
        /* Disable transmission complete interrupt. */
        SCI_DisableInterrupts(base, (uint32_t)sSCI_TransmissionCompleteInterruptEnable);

        /* Trigger callback. */
        if (NULL != handle->callback)
        {
            handle->callback(base, handle, sStatus_SCI_TxIdle, handle->userData);
        }
    }
}

/*!
 * brief SCI Error IRQ handle function.
 *
 * This function handles the SCI error IRQ request.
 *
 * param base SCI peripheral base address.
 * param handle SCI handle pointer.
 */
void SCI_TransferHandleErrorIRQ(SCI_TypeDef *base, SCI_handle_t *handle)
{
    /* To be implemented by User. */
}


#if defined(SCI1)
void SCI1_IRQHandler(void)
{
    s_SCIIsr(SCI1, s_SCIHandle[0]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(SCI2)
void SCI2_IRQHandler(void)
{
    s_SCIIsr(SCI2, s_SCIHandle[1]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(SCI3)
void SCI3_IRQHandler(void)
{
    s_SCIIsr(SCI3, s_SCIHandle[2]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(SCI4)
void SCI4_IRQHandler(void)
{
    s_SCIIsr(SCI4, s_SCIHandle[3]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(SCI5)
void SCI5_IRQHandler(void)
{
    s_SCIIsr(SCI5, s_SCIHandle[4]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(SCI6)
void SCI6_IRQHandler(void)
{
    s_SCIIsr(SCI6, s_SCIHandle[5]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

