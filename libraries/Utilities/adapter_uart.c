/*
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sp28038_device.h"
//#include "uart.h"

#include "adapter_uart.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#ifndef NDEBUG
#if (defined(DEBUG_CONSOLE_ASSERT_DISABLE) && (DEBUG_CONSOLE_ASSERT_DISABLE > 0U))
#undef assert
#define assert(n)
#endif
#endif


/*! @brief uart state structure. */
typedef struct _hal_uart_state
{
    uint8_t instance;
} hal_uart_state_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static SCI_TypeDef *const s_UartAdapterBase[] = SCI_BASE_PTRS;

static hal_uart_status_t HAL_UartGetStatus(status_t status)
{
    if (SUCCESS == status)
    {
        return kStatus_HAL_UartSuccess;
    }
    else
    {
        return kStatus_HAL_UartError;
    }
}

hal_uart_status_t HAL_UartInit(hal_uart_handle_t handle, const hal_uart_config_t *config)
{
	  SCI_TypeDef* base;
    assert(config != NULL);
    assert(config->baudRate_Bps != 0U);
	  assert(config->instance < (sizeof(s_UartAdapterBase) / sizeof(SCI_TypeDef *)));
    assert((uint8_t)FSL_FEATURE_UART_FIFO_SIZEn(s_UartAdapterBase[config->instance]) >= config->txFifoWatermark);   //SCI1-4 has fifo, SCI5-6 hasn't
    assert((uint8_t)FSL_FEATURE_UART_FIFO_SIZEn(s_UartAdapterBase[config->instance]) >= config->rxFifoWatermark);

    status_t status = kStatus_HAL_UartSuccess;
    uint32_t temp;
    uint16_t sbr, sbrTemp;
    uint8_t osr, osrTemp;
    uint32_t tempDiff, calculatedBaud, baudDiff;

    baudDiff = config->baudRate_Bps;
    osr      = 0U;
    sbr      = 0U;
    for (osrTemp = 4U; osrTemp <= 32U; osrTemp++)
    {
        /* calculate the temporary sbr value   */
        sbrTemp = (uint16_t)((config->srcClock_Hz * 10U / (config->baudRate_Bps * (uint32_t)osrTemp) + 5U) / 10U);
        /*set sbrTemp to 1 if the sourceClockInHz can not satisfy the desired baud rate*/
        if (sbrTemp == 0U)
        {
            sbrTemp = 1U;
        }
        /* Calculate the baud rate based on the temporary OSR and SBR values */
        calculatedBaud = (config->srcClock_Hz / ((uint32_t)osrTemp * (uint32_t)sbrTemp));
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
        status = kStatus_HAL_UartBaudrateNotSupport;
    }
    else
    {
        /* Enable uart clock */
        //CLOCK_EnableClock(s_uartClock[UART_GetInstance(base)]);
        if(config->instance==0)
           SYSCTRL->ISP2CGC2 |= SYSCTRL_ISP2CGC2_SCI1_MASK;
        if(config->instance==1)
           SYSCTRL->ISP2CGC2 |= SYSCTRL_ISP2CGC2_SCI2_MASK;
        if(config->instance==2)
           SYSCTRL->ISP2CGC2 |= SYSCTRL_ISP2CGC2_SCI3_MASK;
        if(config->instance==3)
           SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_SCI4_MASK;
        if(config->instance==4)
           SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_SCI5_MASK;
        if(config->instance==5)
           SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_SCI5_MASK;

        SYSCTRL->SCICLKSEL = (SYSCTRL->SCICLKSEL&(~(3<<(2*config->instance))))   \
                            |(config->clockSource<<(2*config->instance));

        base = s_UartAdapterBase[config->instance];

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

        /* Set bit count and parity mode. */
        base->SCICNFG &= ~SCI_CNFG_TMOD_MASK;

        temp = base->SCICTRL & ~(SCI_CTRL_PEN_MASK | SCI_CTRL_PSEL_MASK | SCI_CTRL_BITMOD_MASK | SCI_CTRL_ILTS_MASK |
                              SCI_CTRL_IDLCFG_MASK);

        temp |= (uint8_t)config->parityMode | SCI_CTRL_IDLCFG_SET(config->rxIdleConfig) |
                SCI_CTRL_ILTS_SET(config->rxIdleType);


        if (kHAL_UartParityDisabled != config->parityMode)
        {
            temp |= SCI_CTRL_BITMOD_MASK; /* Eight data bits and one parity bit */
        }

        base->SCICTRL = temp;

        /* set stop bit per char */
        temp       = base->SCICNFG & ~SCI_CNFG_SBS_MASK;
        base->SCICNFG = temp | SCI_CNFG_SBS_SET((uint8_t)config->stopBitCount);

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

    return kStatus_HAL_UartSuccess;
}

hal_uart_status_t HAL_UartDeinit(hal_uart_handle_t handle)
{
    hal_uart_state_t *uartHandle;
    SCI_TypeDef* base;
    assert(handle);
    uint32_t temp;
    uartHandle = (hal_uart_state_t *)handle;

    base =s_UartAdapterBase[uartHandle->instance];

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

    temp |= (SCI_STATUS_M1F_MASK | SCI_STATUS_M2F_MASK);

    base->SCISTATUS |= temp;

    /* Disable the module. */
    base->SCICTRL = 0U;

    /* Disable sci clock */
    if(uartHandle->instance==1)
       SYSCTRL->ISP2CGC2 &= ~SYSCTRL_ISP2CGC2_SCI1_MASK;
    if(uartHandle->instance==2)
       SYSCTRL->ISP2CGC2 &= ~SYSCTRL_ISP2CGC2_SCI2_MASK;
    if(uartHandle->instance==3)
       SYSCTRL->ISP2CGC2 &= ~SYSCTRL_ISP2CGC2_SCI3_MASK;
    if(uartHandle->instance==4)
       SYSCTRL->ISP1CGC3 &= ~SYSCTRL_ISP1CGC3_SCI4_MASK;
    if(uartHandle->instance==5)
       SYSCTRL->ISP1CGC3 &= ~SYSCTRL_ISP1CGC3_SCI5_MASK;
    if(uartHandle->instance==6)
       SYSCTRL->ISP1CGC3 &= ~SYSCTRL_ISP1CGC3_SCI5_MASK;
        
    return kStatus_HAL_UartSuccess;
}

hal_uart_status_t HAL_UartSendBlocking(hal_uart_handle_t handle, const uint8_t *data, size_t length)
{
    SCI_TypeDef* base;
    hal_uart_state_t *uartHandle;
    assert(handle);
    assert(data);
    assert(length);

    uartHandle = (hal_uart_state_t *)handle;
    const uint8_t *dataAddress = data;
    size_t transferSize        = length;

    base = s_UartAdapterBase[uartHandle->instance];

    while (0U != transferSize)
    {
        while (0U == (base->SCISTATUS & SCI_STATUS_TDREF_MASK))
        {
        }
        base->SCIDATA = *(dataAddress);
        dataAddress++;
        transferSize--;
    }
    /* Ensure all the data in the transmit buffer are sent out to bus. */
    while (0U == (base->SCISTATUS & SCI_STATUS_TCF_MASK))
    {
    }
    return kStatus_HAL_UartSuccess;
}

uint32_t Uart_GetStatusFlags(SCI_TypeDef *base)
{
    uint32_t temp;
    temp = base->SCISTATUS;
    temp |= (base->SCIFCTL &
             (SCI_FCTL_TFEMPT_MASK | SCI_FCTL_RFEMPT_MASK | SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK)) >>
            16U;
    return temp;
}

status_t Uart_ClearStatusFlags(SCI_TypeDef *base, uint32_t mask)
{
    uint32_t temp;
    status_t status;

    temp = (uint32_t)base->SCIFCTL;
    temp &= (uint32_t)(~(SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK));
    temp |= (mask << 16U) & (SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK);
    base->SCIFCTL = temp;

    temp = (uint32_t)base->SCISTATUS;

    temp &= (uint32_t)(~(SCI_STATUS_RXEDGIF_MASK | SCI_STATUS_IDLF_MASK | SCI_STATUS_ROF_MASK | SCI_STATUS_NOIF_MASK |
                         SCI_STATUS_FEF_MASK | SCI_STATUS_PEF_MASK));
    temp |= mask & (SCI_STATUS_RXEDGIF_MASK | SCI_STATUS_IDLF_MASK | SCI_STATUS_ROF_MASK | SCI_STATUS_NOIF_MASK |
                    SCI_STATUS_FEF_MASK | SCI_STATUS_PEF_MASK);
    temp &= (uint32_t)(~(SCI_STATUS_M2F_MASK | SCI_STATUS_M1F_MASK));
    temp |= mask & (SCI_STATUS_M2F_MASK | SCI_STATUS_M1F_MASK);
    base->SCISTATUS = temp;
    /* If some flags still pending. */
    if (0U != (mask & Uart_GetStatusFlags(base)))
    {
        /* Some flags can only clear or set by the hardware itself, these flags are: kSCI_TxDataRegEmptyFlag,
        kSCI_TransmissionCompleteFlag, kSCI_RxDataRegFullFlag, kSCI_RxActiveFlag,
        kSCI_NoiseErrorInRxDataRegFlag, kSCI_ParityErrorInRxDataRegFlag,
        kSCI_TxFifoEmptyFlag, kSCI_RxFifoEmptyFlag. */
        status = kStatus_HAL_UartError; /* flags can not clear manually */
    }
    else
    {
        status = kStatus_HAL_UartSuccess;
    }

    return status;
}

hal_uart_status_t HAL_UartReceiveBlocking(hal_uart_handle_t handle, uint8_t *data, size_t length)
{
    hal_uart_state_t *uartHandle;
    status_t status = SUCCESS;
    assert(handle);
    assert(data);
    assert(length);
    SCI_TypeDef* base;
    
    uartHandle = (hal_uart_state_t *)handle;

    uint32_t statusFlag;
    base = s_UartAdapterBase[uartHandle->instance];

    while (0U != (length--))
    {
        while (0U == ((base->SCIWATMK & SCI_WATMK_RXCNT_MASK) >> SCI_WATMK_RXCNT_SHIFT))
        {
            statusFlag = Uart_GetStatusFlags(base);

            if (0U != (statusFlag & (uint32_t)kSCI_RxOverrunFlag))
            {
                status = ((SUCCESS == Uart_ClearStatusFlags(base, (uint32_t)kSCI_RxOverrunFlag)) ?
                              (kStatus_HAL_UartError) :
                              (kStatus_HAL_UartFlagCannotClearManually));
                /* Other error flags(FE, NF, and PF) are prevented from setting once OR is set, no need to check other
                 * error flags*/
                break;
            }

            if (0U != (statusFlag & (uint32_t)kSCI_ParityErrorFlag))
            {
                status = ((SUCCESS == Uart_ClearStatusFlags(base, (uint32_t)kSCI_ParityErrorFlag)) ?
                              (kStatus_HAL_UartError) :
                              (kStatus_HAL_UartFlagCannotClearManually));
            }

            if (0U != (statusFlag & (uint32_t)kSCI_FramingErrorFlag))
            {
                status = ((SUCCESS == Uart_ClearStatusFlags(base, (uint32_t)kSCI_FramingErrorFlag)) ?
                              (kStatus_HAL_UartError) :
                              (kStatus_HAL_UartFlagCannotClearManually));
            }

            if (0U != (statusFlag & (uint32_t)kSCI_NoiseErrorFlag))
            {
                status = ((SUCCESS == Uart_ClearStatusFlags(base, (uint32_t)kSCI_NoiseErrorFlag)) ?
                              (kStatus_HAL_UartError) :
                              (kStatus_HAL_UartFlagCannotClearManually));
            }
            if (SUCCESS != status)
            {
                break;
            }
        }

        if (SUCCESS == status)
        {
            *(data) = (uint8_t)base->SCIDATA;
            data++;
        }
        else
        {
            break;
        }
    }

    return HAL_UartGetStatus(status);
}