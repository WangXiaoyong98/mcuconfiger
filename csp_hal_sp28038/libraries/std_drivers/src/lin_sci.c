/*
  ******************************************************************************
  * @file           : lin_sci.c
  * @brief          : .
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lin_sci.h"
#include "lin.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/

SCI_TypeDef *const g_linSciBase[SP_SOC_SCI_COUNT] = SCI_BASE_PTRS; 

const IRQn_Type g_linSciRxTxIrqId[SP_SOC_SCI_COUNT] = SCI_RX_TX_IRQS;


const IRQn_Type g_linSciErrIrqId[SP_SOC_SCI_COUNT] = SCI_ERR_IRQS;


/*******************************************************************************
 * Static variables
 ******************************************************************************/
static uint32_t s_previousTwoBitTimeLength[SP_SOC_SCI_COUNT] = {0U};
static uint8_t s_wakeupSignal[SP_SOC_SCI_COUNT] = {0U};
static uint8_t s_countMeasure[SP_SOC_SCI_COUNT] = {0U};
static uint32_t s_timeMeasure[SP_SOC_SCI_COUNT] = {0U};

/*******************************************************************************
 * Static function prototypes
 ******************************************************************************/

static void LIN_SCI_EnableInterrupts(SCI_TypeDef *base, uint32_t mask);
static void LIN_SCI_DisableInterrupts(SCI_TypeDef *base, uint32_t mask);
static uint32_t LIN_SCI_GetInstance(SCI_TypeDef *base);
static sstat_t LIN_SCI_ClearStatusFlags(SCI_TypeDef *base, uint32_t mask);
static uint32_t LIN_SCI_GetStatusFlags(SCI_TypeDef *base);
static void LIN_SCI_ProcessBreakDetect(uint32_t instance);
static void LIN_SCI_CheckWakeupSignal(uint32_t instance);
static void LIN_SCI_AutobaudTimerValEval(uint32_t instance, uint32_t twoBitTimeLength);
static void LIN_SCI_EvalTwoBitTimeLength(uint32_t instance, uint32_t twoBitTimeLength);
static void LIN_SCI_ProcessFrame(uint32_t instance, uint8_t tmpByte);
static void LIN_SCI_ProcessFrameHeader(uint32_t instance, uint8_t tmpByte);
static void LIN_SCI_ProcessReceiveFrameData(uint32_t instance, uint8_t tmpByte);
static void LIN_SCI_ProcessSendFrameData(uint32_t instance, uint8_t tmpByte);

/*******************************************************************************
 * Code
 ******************************************************************************/
static void LIN_SCI_EnableInterrupts(SCI_TypeDef *base, uint32_t mask)
{
    base->SCICNFG |= ((mask << 8) & (SCI_CNFG_LBDIE_MASK | SCI_CNFG_RXEDGIE_MASK));
    base->SCIFCTL = (base->SCIFCTL & ~(SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK)) |
                 ((mask << 8) & (SCI_FCTL_TXOVIE_MASK | SCI_FCTL_RXUNIE_MASK));

    mask &= 0xFFFFFF00U;
    base->SCICTRL |= mask;
}

static void LIN_SCI_DisableInterrupts(SCI_TypeDef *base, uint32_t mask)
{
    base->SCICNFG &= ~((mask << 8) & (SCI_CNFG_LBDIE_MASK | SCI_CNFG_RXEDGIE_MASK));
    base->SCIFCTL = (base->SCIFCTL & ~(SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK)) &
                 ~((mask << 8) & (SCI_FCTL_TXOVIE_MASK | SCI_FCTL_RXUNIE_MASK));

    mask &= 0xFFFFFF00U;
    base->SCICTRL &= ~mask;
}

sstat_t LIN_SCI_CalculateBaudRate(
    SCI_TypeDef *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz, uint32_t *osr, uint16_t *sbr)
{
    assert(baudRate_Bps);
    sstat_t status = sStatus_Success;

    uint16_t sbrTemp;
    uint32_t osrTemp, tempDiff, calculatedBaud, baudDiff;

    /* This SCI instantiation uses a slightly different baud rate calculation
     * The idea is to use the best OSR (over-sampling rate) possible
     * Note, OSR is typically hard-set to 16 in other SCI instantiations
     * loop to find the best OSR value possible, one that generates minimum baudDiff
     * iterate through the rest of the supported values of OSR */

    baudDiff = baudRate_Bps;
    for (osrTemp = 4; osrTemp <= 32; osrTemp++)
    {
        /* calculate the temporary sbr value   */
        sbrTemp = (srcClock_Hz / (baudRate_Bps * osrTemp));
        /*set sbrTemp to 1 if the sourceClockInHz can not satisfy the desired baud rate*/
        if (sbrTemp == 0)
        {
            sbrTemp = 1;
        }
        /* Calculate the baud rate based on the temporary OSR and SBR values */
        calculatedBaud = (srcClock_Hz / (osrTemp * sbrTemp));

        tempDiff = calculatedBaud - baudRate_Bps;

        /* Select the better value between srb and (sbr + 1) */
        if (tempDiff > (baudRate_Bps - (srcClock_Hz / (osrTemp * (sbrTemp + 1)))))
        {
            tempDiff = baudRate_Bps - (srcClock_Hz / (osrTemp * (sbrTemp + 1)));
            sbrTemp++;
        }

        if (tempDiff <= baudDiff)
        {
            baudDiff = tempDiff;
            *osr = osrTemp; /* update and store the best OSR value calculated */
            *sbr = sbrTemp; /* update store the best SBR value calculated */
        }
    }

    if (baudDiff >= ((baudRate_Bps / 100) * 3))
    {
        status = sStatus_Fail;
    }
    return status;
}

void LIN_SCI_SetBaudRate(SCI_TypeDef *base, uint32_t *osr, uint16_t *sbr)
{
    uint32_t temp, oldCtrl;
    /* Store CTRL before disable Tx and Rx */
    oldCtrl = base->SCICTRL;

    /* Disable SCI TX RX before setting. */
    base->SCICTRL &= ~(SCI_CTRL_TXEN_MASK | SCI_CTRL_RXEN_MASK);

    temp = base->SCICNFG;

    /* Acceptable baud rate, check if OSR is between 4x and 7x oversampling.
     * If so, then "BOTHEDGE" sampling must be turned on */
    if ((*osr > 3) && (*osr < 8))
    {
        temp |= SCI_CNFG_TWOEDGE_MASK;
    }

    /* program the osr value (bit value is one less than actual value) */
    temp &= ~SCI_CNFG_OSR_MASK;
    temp |= SCI_CNFG_OSR_SET(*osr - 1);

    /* write the sbr value to the BAUD registers */
    temp &= ~SCI_CNFG_BRD_MASK;
    base->SCICNFG = temp | SCI_CNFG_BRD_SET(*sbr);

    /* Restore CTRL. */
    base->SCICTRL = oldCtrl;
}

static void LIN_SCI_SetBitCountPerChar(SCI_TypeDef *base, lin_sci_bit_count_per_char_t bitCountPerChar)
{
    if (bitCountPerChar == SCI_10_BITS_PER_CHAR)
    {
        base->SCICNFG = (base->SCICNFG & ~SCI_CNFG_TMOD_MASK) | ((uint32_t)1U << SCI_CNFG_TMOD_SHIFT);
    }
    else
    {
        /* config 8-bit (M=0) or 9-bits (M=1) */
        base->SCICTRL = (base->SCICTRL & ~SCI_CTRL_BITMOD_MASK) | ((uint32_t)bitCountPerChar << SCI_CTRL_BITMOD_SHIFT);
        /* clear M10 to make sure not 10-bit mode */
        base->SCICNFG &= ~SCI_CNFG_TMOD_MASK;
    }
}

static sstat_t LIN_SCI_ClearStatusFlags(SCI_TypeDef *base, uint32_t mask)
{
    uint32_t temp;
    sstat_t status;

    temp = (uint32_t)base->SCIFCTL;
    temp &= (uint32_t)(~(SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK));
    temp |= (mask << 16) & (SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK);
    base->SCIFCTL = temp;

    temp = (uint32_t)base->SCISTATUS;

    temp &= (uint32_t)(~(SCI_STATUS_LBDIF_MASK));
    temp |= mask & SCI_STATUS_LBDIF_MASK;

    temp &= (uint32_t)(~(SCI_STATUS_RXEDGIF_MASK | SCI_STATUS_IDLF_MASK | SCI_STATUS_ROF_MASK | SCI_STATUS_NOIF_MASK |
                         SCI_STATUS_FEF_MASK | SCI_STATUS_PEF_MASK));
    temp |= mask & (SCI_STATUS_RXEDGIF_MASK | SCI_STATUS_IDLF_MASK | SCI_STATUS_ROF_MASK | SCI_STATUS_NOIF_MASK |
                    SCI_STATUS_FEF_MASK | SCI_STATUS_PEF_MASK);
    base->SCISTATUS = temp;
    /* If some flags still pending. */
    if (mask & LIN_SCI_GetStatusFlags(base))
    {
        /* Some flags can only clear or set by the hardware itself, these flags are: SCI_TxDataRegEmptyFlag,
        SCI_TransmissionCompleteFlag, SCI_RxDataRegFullFlag, SCI_RxActiveFlag,
        SCI_NoiseErrorInRxDataRegFlag, SCI_ParityErrorInRxDataRegFlag,
        SCI_TxFifoEmptyFlag, SCI_RxFifoEmptyFlag. */
        status = Status_SCI_FlagCannotClearManually; /* flags can not clear manually */
    }
    else
    {
        status = sStatus_Success;
    }

    return status;
}

static uint32_t LIN_SCI_GetStatusFlags(SCI_TypeDef *base)
{
    uint32_t temp;
    temp = base->SCISTATUS;

    temp |= (base->SCIFCTL &
             (SCI_FCTL_TFEMPT_MASK | SCI_FCTL_RFEMPT_MASK | SCI_FCTL_TBOVF_MASK | SCI_FCTL_RBUNF_MASK)) >> 16;

    return temp;
}

static uint32_t LIN_SCI_GetInstance(SCI_TypeDef *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < SP_SOC_SCI_COUNT; instance++)
    {
        if (g_linSciBase[instance] == base)
        {
            break;
        }
    }

    assert(instance < SP_SOC_SCI_COUNT);

    return instance;
}

static lin_status_t LIN_SCI_QueueBreakChar(SCI_TypeDef *base)
{
    /* mask T0-T9 bits from data register */
    volatile uint16_t *dataRegBytes = (volatile uint16_t *)(&(base->SCIDATA));

    dataRegBytes[0] = SCI_DATA_FETSC_SET(1U);

    return LIN_SUCCESS;
}

static void LIN_SCI_ProcessBreakDetect(uint32_t instance)
{
    SCI_TypeDef *base = g_linSciBase[instance];
    /* Get the current LIN user configure structure of this SCI instance. */
    const lin_user_config_t *linUserConfig = g_linUserconfigPtr[instance];

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Clear LIN Break Detect Interrupt Flag */
    LIN_SCI_ClearStatusFlags(base, SCI_LinBreakFlag);

    /* Check if the current node is in SLEEP MODE */
    if (linCurrentState->currentNodeState == LIN_NODE_STATE_SLEEP_MODE)
    {
        /* Change the node's current state to IDLE */
        (void)LIN_SCI_GotoIdleState(base);
    }
    else
    {
        /* Set Break char detect length as 10 bits minimum */
        /* Disable LIN Break Detect Interrupt */
        /* Set Break char detect length as 10 bits minimum and interrupt */
        base->SCISTATUS &= ~SCI_STATUS_LBDE_MASK;
        LIN_SCI_DisableInterrupts(base, SCI_LinBreakInterruptEnable);

        /* Set flag LIN bus busy */
        linCurrentState->isBusBusy = true;

        /* Check if the current node is MASTER */
        if (linUserConfig->nodeFunction == (bool)LIN_MASTER) /* Master */
        {
            if (linCurrentState->currentNodeState == LIN_NODE_STATE_SEND_BREAK_FIELD)
            {
                /* Change the node's current state to SENDING PID */
                linCurrentState->currentNodeState = LIN_NODE_STATE_SEND_PID;

                LIN_SCI_WriteByte(base, 0x55);
            }
        }
        /* If the current node is SLAVE */
        else
        {
            /* Change the node's current state to RECEIVED BREAK FIELD */
            linCurrentState->currentEventId = LIN_RECV_BREAK_FIELD_OK;

            /* Callback function */
            if (linCurrentState->Callback != NULL)
            {
                linCurrentState->Callback(instance, linCurrentState);
            }

            /* Change the node's current state to RECEIVING SYNC FIELD */
            linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_SYNC;
        }
    }
}

static void LIN_SCI_CheckWakeupSignal(uint32_t instance)
{
    uint32_t wakeupSignalLength = 0U;

    SCI_TypeDef *base = g_linSciBase[instance];
    /* Get the current LIN user config structure of this SCI instance. */
    const lin_user_config_t *linUserConfig = g_linUserconfigPtr[instance];

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* if SCI_HAL_GetRxDataPolarity is 0: Receive Data is not inverted */
    if (LIN_SCI_GetRxDataPolarity(base) == false)
    {
        /* Start measure time */
        (void)linUserConfig->timerGetTimeIntervalCallback(&wakeupSignalLength);

        /* Set Receive Data Inverted */
        LIN_SCI_SetRxDataPolarity(base, true);
    }
    else
    {
        /* Set Receive Data is Not Inverted */
        LIN_SCI_SetRxDataPolarity(base, false);

        /* Calculate time interval between the falling and rising edge */
        if (linUserConfig->timerGetTimeIntervalCallback == NULL)
        {
            return;
        }
        (void)linUserConfig->timerGetTimeIntervalCallback(&wakeupSignalLength);

        /* If length of the dominant signal is from 150us to 5ms, it is a wakeup signal */
        if ((wakeupSignalLength >= 150000U) && (wakeupSignalLength <= 5000000U))
        {
            linCurrentState->currentEventId = LIN_WAKEUP_SIGNAL;

            /* Callback to handle event: Received a wakeup signal */
            if (linCurrentState->Callback != NULL)
            {
                linCurrentState->Callback(instance, linCurrentState);
            }

            /* Change node's state to IDLE */
            (void)LIN_SCI_GotoIdleState(base);
        }
    }
}

static void LIN_SCI_AutobaudTimerValEval(uint32_t instance, uint32_t twoBitTimeLength)
{
    uint32_t MasterBaudrate = 0U;

    /* Get the current LIN user config structure of this SCI instance. */
    lin_user_config_t *linUserConfig = g_linUserconfigPtr[instance];

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Check whether current node state is receive sync */
    bool checkNodeState = (linCurrentState->currentNodeState == LIN_NODE_STATE_RECV_SYNC);

    /* Evaluate average value against baudrate */
    LIN_SCI_EvalTwoBitTimeLength(instance, twoBitTimeLength);

    if ((linCurrentState->fallingEdgeInterruptCount > 4U) && checkNodeState)
    {
        if ((twoBitTimeLength >= TWO_BIT_DURATION_MIN_19200) && (twoBitTimeLength <= TWO_BIT_DURATION_MAX_19200))
        {
            MasterBaudrate = 19200U;
        }
        else if ((twoBitTimeLength >= TWO_BIT_DURATION_MIN_14400) && (twoBitTimeLength <= TWO_BIT_DURATION_MAX_14400))
        {
            MasterBaudrate = 14400U;
        }
        else if ((twoBitTimeLength >= TWO_BIT_DURATION_MIN_9600) && (twoBitTimeLength <= TWO_BIT_DURATION_MAX_9600))
        {
            MasterBaudrate = 9600U;
        }
        else if ((twoBitTimeLength >= TWO_BIT_DURATION_MIN_4800) && (twoBitTimeLength <= TWO_BIT_DURATION_MAX_4800))
        {
            MasterBaudrate = 4800U;
        }
        else if ((twoBitTimeLength >= TWO_BIT_DURATION_MIN_2400) && (twoBitTimeLength <= TWO_BIT_DURATION_MAX_2400))
        {
            MasterBaudrate = 2400U;
        }
        else
        {
            /* Complete if-elseif-else block to avoid violating MISRA 2012 Rule 15.7 */
        }

        /* Check Master Baudrate against node's current baudrate */
        if ((MasterBaudrate != 0U) && (linUserConfig->baudRate != MasterBaudrate))
        {
            linUserConfig->baudRate = MasterBaudrate;

            /* Assign wakeup signal to satisfy LIN Specifications specifies that
             * wakeup signal shall be in range from 250us to 5 ms.
             */
            if (linUserConfig->baudRate > 10000U)
            {
                /* Wakeup signal will be range from 400us to 800us depend on baudrate */
                s_wakeupSignal[instance] = 0x80U;
            }
            else
            {
                /* Wakeup signal will be range from 400us to 4ms depend on baudrate */
                s_wakeupSignal[instance] = 0xF8U;
            }
        }
        linCurrentState->currentEventId = LIN_BAUDRATE_ADJUSTED;
        /* Disable baudrate evaluation process */
        linCurrentState->baudrateEvalEnable = false;
        /* Callback function to handle this event */
        if (linCurrentState->Callback != NULL)
        {
            linCurrentState->Callback(instance, linCurrentState);
        }
        /* Interrupt in rising edge */

        linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_PID;
        linCurrentState->currentEventId = LIN_RECV_SYNC_OK;
    }
}

static void LIN_SCI_EvalTwoBitTimeLength(uint32_t instance, uint32_t twoBitTimeLength)
{
    SCI_TypeDef *base = g_linSciBase[instance];
    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    if (linCurrentState->fallingEdgeInterruptCount < 5U)
    {
        if (linCurrentState->fallingEdgeInterruptCount > 0U)
        {
            if ((twoBitTimeLength < TWO_BIT_DURATION_MIN_19200) ||
                ((twoBitTimeLength > TWO_BIT_DURATION_MAX_19200) && (twoBitTimeLength < TWO_BIT_DURATION_MIN_14400)) ||
                ((twoBitTimeLength > TWO_BIT_DURATION_MAX_14400) && (twoBitTimeLength < TWO_BIT_DURATION_MIN_9600)) ||
                ((twoBitTimeLength > TWO_BIT_DURATION_MAX_9600) && (twoBitTimeLength < TWO_BIT_DURATION_MIN_4800)) ||
                ((twoBitTimeLength > TWO_BIT_DURATION_MAX_4800) && (twoBitTimeLength < TWO_BIT_DURATION_MIN_2400)) ||
                (twoBitTimeLength > TWO_BIT_DURATION_MAX_2400))
            {
                /* cancel capturing */
                (void)LIN_SCI_GotoIdleState(base);
                linCurrentState->fallingEdgeInterruptCount = 0U;
            }
            else
            {
                if (linCurrentState->fallingEdgeInterruptCount > 1U)
                {
                    if ((twoBitTimeLength <
                         ((100U - BIT_RATE_TOLERANCE_UNSYNC) * s_previousTwoBitTimeLength[instance] / 100U)) ||
                        (twoBitTimeLength >
                         ((100U + BIT_RATE_TOLERANCE_UNSYNC) * s_previousTwoBitTimeLength[instance] / 100U)))
                    {
                        /* cancel capturing */
                        (void)LIN_SCI_GotoIdleState(base);
                        linCurrentState->fallingEdgeInterruptCount = 0U;
                    }
                }
            }
            s_previousTwoBitTimeLength[instance] = twoBitTimeLength;
        }
    }
    linCurrentState->fallingEdgeInterruptCount += 1U;
}

static void LIN_SCI_ProcessFrame(uint32_t instance, uint8_t tmpByte)
{
    /* Get the current LIN state of this SCI instance. */
    const lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Check node's current state */
    switch (linCurrentState->currentNodeState)
    {
        /* if current state is RECEIVE SYNC FIELD */
        case LIN_NODE_STATE_RECV_SYNC:

        /* if current state is MASTER SENDING PID */
        case LIN_NODE_STATE_SEND_PID:

        /* if current state is RECEIVE PID */
        case LIN_NODE_STATE_RECV_PID:
            LIN_SCI_ProcessFrameHeader(instance, tmpByte);
            break;
        /* if current state is RECEIVE DATA */
        case LIN_NODE_STATE_RECV_DATA:
            LIN_SCI_ProcessReceiveFrameData(instance, tmpByte);
            break;
        /* if current state is SENDING DATA */
        case LIN_NODE_STATE_SEND_DATA:
            LIN_SCI_ProcessSendFrameData(instance, tmpByte);
            break;

        default:
            /* Other node state */
            break;
    }
}

static void LIN_SCI_ProcessFrameHeader(uint32_t instance, uint8_t tmpByte)
{
    SCI_TypeDef *base = g_linSciBase[instance];
    /* Get the current LIN user config structure of this SCI instance. */
    const lin_user_config_t *linUserConfig = g_linUserconfigPtr[instance];

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Check node's current state */
    switch (linCurrentState->currentNodeState)
    {
        /* if current state is RECEIVE SYNC FIELD */
        case LIN_NODE_STATE_RECV_SYNC:
            if (tmpByte == 0x55U)
            {
                linCurrentState->currentEventId = LIN_RECV_SYNC_OK;

                /* Change node's current state to RECEIVE PID */
                linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_PID;
            }
            else
            {
                linCurrentState->currentEventId = LIN_RECV_SYNC_ERROR;

                /* Callback function to handle event RECEIVED SYNC FIELD ERROR */
                if (linCurrentState->Callback != NULL)
                {
                    linCurrentState->Callback(instance, linCurrentState);
                }

                /* Clear Bus busy flag */
                linCurrentState->isBusBusy = false;

                /* Change node's current state to IDLE */
                (void)LIN_SCI_GotoIdleState(base);
            }
            break;
        /* if current state is MASTER SENDING PID */
        case LIN_NODE_STATE_SEND_PID:
            /* Check if master node sent SYNC byte correctly before send PID */
            if (tmpByte == 0x55U)
            {
                /* Change node's current state to RECEIVING PID */
                linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_PID;
                /* Send the current PID byte */
                LIN_SCI_WriteByte(base, linCurrentState->currentPid);
            }
            /* In case of errors during header transmission, it is up to the implementer
             * how to handle these errors (stop/continue transmission) and to decide if the
             * corresponding response is valid or not.
             * By default, LIN Driver set isBusBusy to false, and change node's state to IDLE.
             */
            else
            {
                linCurrentState->currentEventId = LIN_RECV_SYNC_ERROR;
                /* Clear Bus busy flag */
                linCurrentState->isBusBusy = false;
                /* Change node's current state to IDLE */
                linCurrentState->currentNodeState = LIN_NODE_STATE_IDLE;
                /* Callback function to handle event RECEIVED SYNC FIELD ERROR */
                if (linCurrentState->Callback != NULL)
                {
                    linCurrentState->Callback(instance, linCurrentState);
                }
            }
            break;
        /* if current state is RECEIVE PID */
        case LIN_NODE_STATE_RECV_PID:
            /* if the node is MASTER */
            if (linUserConfig->nodeFunction == (bool)LIN_MASTER)
            {
                /* Check if master node sent PID correctly */
                if (tmpByte == linCurrentState->currentPid)
                {
                    /* Set current event ID to PID correct */
                    linCurrentState->currentEventId = LIN_PID_OK;

                    /* Clear Bus bus flag */
                    linCurrentState->isBusBusy = false;

                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }
                }
                /* In case of errors during header transmission, it is up to the implementer
                 * how to handle these errors (stop/continue transmission) and to decide if the
                 * corresponding response is valid or not.
                 * By default, LIN Driver set isBusBusy to false, and change node's state to IDLE.
                 */
                else
                {
                    /* Set current event ID to PID incorrect */
                    linCurrentState->currentEventId = LIN_PID_ERROR;
                    /* Clear bus busy flag */
                    linCurrentState->isBusBusy = false;
                    /* Change node's current state to IDLE */
                    linCurrentState->currentNodeState = LIN_NODE_STATE_IDLE;
                    /* Callback function to handle event MASTER SENT PID ERROR */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }
                }
            }
            /* If the node is SLAVE */
            else
            {
                /* Check the received PID */
                linCurrentState->currentId = LIN_ProcessParity(tmpByte, LIN_CHECK_PARITY);
                linCurrentState->currentPid = tmpByte;
                if (linCurrentState->currentId != 0xFFU)
                {
                    /* Set current event PID correct */
                    linCurrentState->currentEventId = LIN_PID_OK;

                    /* Clear Bus bus flag */
                    linCurrentState->isBusBusy = false;

                    /* Callback function to handle correct PID */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }
                }
                else
                {
                    /* Set current event PID incorrect */
                    linCurrentState->currentEventId = LIN_PID_ERROR;

                    /* Callback function to handle correct PID */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }

                    /* Clear Bus bus flag */
                    linCurrentState->isBusBusy = false;

                    /* Change node's current state to IDLE */
                    (void)LIN_SCI_GotoIdleState(base);
                }
            }
            break;
        default:
            /* Other node state */
            break;
    }
}

static void LIN_SCI_ProcessReceiveFrameData(uint32_t instance, uint8_t tmpByte)
{
    SCI_TypeDef *base = g_linSciBase[instance];
    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    if (linCurrentState->rxSize > (linCurrentState->cntByte + 1U))
    {
        *(linCurrentState->rxBuff) = tmpByte;
        linCurrentState->rxBuff++;
    }
    else
    {
        if ((linCurrentState->rxSize - linCurrentState->cntByte) == 1U)
        {
            linCurrentState->checkSum = tmpByte;
        }
    }

    linCurrentState->cntByte++;
    if (linCurrentState->cntByte == linCurrentState->rxSize)
    {
        /* Restore rxBuffer pointer */
        linCurrentState->rxBuff -= linCurrentState->rxSize - 1U;
        if (LIN_MakeChecksumByte(linCurrentState->rxBuff, linCurrentState->rxSize - 1U, linCurrentState->currentPid) ==
            linCurrentState->checkSum)
        {
            linCurrentState->currentEventId = LIN_RX_COMPLETED;
            linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_DATA_COMPLETED;

            /* callback function to handle RX COMPLETED */
            if (linCurrentState->Callback != NULL)
            {
                linCurrentState->Callback(instance, linCurrentState);
            }
            if (linCurrentState->isRxBlocking == true)
            {
                /* Post Semaphore to signal Rx Completed*/
                linCurrentState->rxCompleted = true;
            }
            /* Clear Bus bus flag */
            linCurrentState->isBusBusy = false;
            linCurrentState->isRxBusy = false;

            /* In case of receiving a go to sleep request, after callback, node is in SLEEP MODE */
            /* In this case, node is in SLEEP MODE state */
            if (linCurrentState->currentNodeState != LIN_NODE_STATE_SLEEP_MODE)
            {
                (void)LIN_SCI_GotoIdleState(base);
            }
        }
        else
        {
            linCurrentState->currentEventId = LIN_CHECKSUM_ERROR;

            /* callback function to handle checksum error */
            if (linCurrentState->Callback != NULL)
            {
                linCurrentState->Callback(instance, linCurrentState);
            }
            /* Clear Bus bus flag */
            linCurrentState->isBusBusy = false;
            linCurrentState->isRxBusy = false;
            /* Change node's current state to IDLE */
            (void)LIN_SCI_GotoIdleState(base);
        }
    }
}

static void LIN_SCI_ProcessSendFrameData(uint32_t instance, uint8_t tmpByte)
{
    bool sendFlag = true;
    uint8_t tmpSize;
    bool tmpCheckSumAndSize;
    bool tmpBuffAndSize;

    SCI_TypeDef *base = g_linSciBase[instance];

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    if ((bool)(LIN_SCI_GetStatusFlags(base) & SCI_TxDataRegEmptyFlag) == false)
    {
        linCurrentState->currentEventId = LIN_READBACK_ERROR;

        /* callback function to handle Readback error */
        if (linCurrentState->Callback != NULL)
        {
            linCurrentState->Callback(instance, linCurrentState);
        }
        if (linCurrentState->isTxBlocking == false)
        {
            /* Clear Bus bus flag */
            linCurrentState->isBusBusy = false;
            linCurrentState->isTxBusy = false;
            /* Change node's current state to IDLE */
            (void)LIN_SCI_GotoIdleState(base);
        }
        sendFlag = false;
    }
    else
    {
        tmpSize = linCurrentState->txSize - linCurrentState->cntByte;
        tmpCheckSumAndSize = (tmpSize == 1U) && (linCurrentState->checkSum != tmpByte);
        tmpBuffAndSize = (*linCurrentState->txBuff != tmpByte) && (tmpSize != 1U);
        if (tmpBuffAndSize || tmpCheckSumAndSize)
        {
            linCurrentState->currentEventId = LIN_READBACK_ERROR;

            /* callback function to handle Readback error */
            if (linCurrentState->Callback != NULL)
            {
                linCurrentState->Callback(instance, linCurrentState);
            }
            if (linCurrentState->isTxBlocking == false)
            {
                /* Clear Bus bus flag */
                linCurrentState->isBusBusy = false;
                linCurrentState->isTxBusy = false;
                /* Change node's current state to IDLE */
                (void)LIN_SCI_GotoIdleState(base);
            }
            sendFlag = false;
        }
        else
        {
            linCurrentState->txBuff++;
            linCurrentState->cntByte++;
        }
    }

    if (sendFlag == true)
    {
        if (linCurrentState->cntByte < linCurrentState->txSize)
        {
            /* Send checksum byte */
            if ((linCurrentState->txSize - linCurrentState->cntByte) == 1U)
            {
                LIN_SCI_WriteByte(base, linCurrentState->checkSum);
            }
            /* Send data bytes */
            else
            {
                LIN_SCI_WriteByte(base, *linCurrentState->txBuff);
            }
        }
        else
        {
            linCurrentState->currentEventId = LIN_TX_COMPLETED;
            linCurrentState->currentNodeState = LIN_NODE_STATE_SEND_DATA_COMPLETED;

            LIN_SCI_DisableInterrupts(base, SCI_RxDataRegFullFlag);
            /* callback function to handle event TX COMPLETED */
            if (linCurrentState->Callback != NULL)
            {
                linCurrentState->Callback(instance, linCurrentState);
            }
            /* Check if the transmission is non-blocking */
            if (linCurrentState->isTxBlocking == true)
            {
                linCurrentState->txCompleted = true;
            }
            /* Clear Bus bus flag */
            linCurrentState->isBusBusy = false;
            linCurrentState->isTxBusy = false;
            /* Change node's current state to IDLE */
            (void)LIN_SCI_GotoIdleState(base);
        }
    }
}

lin_status_t LIN_SCI_Init(SCI_TypeDef *base,
                             lin_user_config_t *linUserConfig,
                             lin_state_t *linCurrentState,
                             uint32_t linSourceClockFreq)
{
    uint32_t temp;
    uint32_t osrValue;
    uint16_t sbrValue;
    lin_status_t retVal = LIN_INITIALIZED;
    /* Assert parameters. */

    assert(linUserConfig);
    assert(linUserConfig->baudRate);

    uint32_t instance = LIN_SCI_GetInstance(base);

    if (linSourceClockFreq == 0U)
    {
        retVal = LIN_SCI_STAT_CLOCK_GATED_OFF;
    }
    else
    {
        /* if autobaud is enabled */
        if ((linUserConfig->autobaudEnable) && (linUserConfig->nodeFunction == (bool)LIN_SLAVE))
        {
            /* Setting Slave's baudrate to 19200 will help Slave node always detect LIN Break from Master */
            linUserConfig->baudRate = 19200U;
            linCurrentState->fallingEdgeInterruptCount = 0U;
            linCurrentState->baudrateEvalEnable = true;
            s_previousTwoBitTimeLength[instance] = 0U;
            s_countMeasure[instance] = 0U;
            s_timeMeasure[instance] = 0U;
        }

        /* SCI init */
        //CLOCK_EnableClock(s_sciClock[instance]);

        /* Reset values */
        base->SCICTRL = 0x00000000;
        /* Reset match addresses */
        base->SCIMATCH = 0x00000000;

        /* Reset IrDA modem features */
        base->SCIRSIR = 0x00000000;


        /* Reset FIFO feature */
        base->SCIFCTL = (SCI_FCTL_RBUNF_MASK | SCI_FCTL_TBOVF_MASK);
        /* Reset FIFO Watermark values */
        base->SCIWATMK = 0x00000000;


        if (LIN_SCI_CalculateBaudRate(base, linUserConfig->baudRate, linSourceClockFreq, &osrValue, &sbrValue) ==
            sStatus_Success)
        {
            /* Set baudrate to User's value */
            LIN_SCI_SetBaudRate(base, &osrValue, &sbrValue);

            /* config 8-bit (M=0) */
            LIN_SCI_SetBitCountPerChar(base, SCI_8_BITS_PER_CHAR);

            /* Set no parity mode */
            base->SCICTRL &= ~SCI_CTRL_PEN_MASK;
            base->SCICTRL &= ~SCI_CTRL_PSEL_MASK;

            /* config 1 stop bit  */
            temp = base->SCICNFG & ~SCI_CNFG_SBS_MASK;
            base->SCICNFG = temp | SCI_CNFG_SBS_SET(SCI_OneStopBit);

            /* Set Break char transmit length as 13 bits minimum */
            if (linUserConfig->nodeFunction == (bool)LIN_MASTER)
            {
                base->SCISTATUS |= SCI_STATUS_BCLEN_MASK;
            }

            DisableIRQ(g_linSciRxTxIrqId[instance]);

            /* Set Break char detect length as 13 bits minimum and interrupt */
            base->SCISTATUS |= SCI_STATUS_LBDE_MASK;
            LIN_SCI_EnableInterrupts(base, SCI_LinBreakInterruptEnable);


            LIN_SCI_EnableInterrupts(base,
                                        (SCI_FramingErrorInterruptEnable | SCI_RxDataRegFullInterruptEnable));
            EnableIRQ(g_linSciRxTxIrqId[instance]);

            /* Change node's current state to IDLE */
            linCurrentState->currentNodeState = LIN_NODE_STATE_IDLE;
            linCurrentState->linSourceClockFreq = linSourceClockFreq;
            /* Clear flags in current LIN state structure */
            linCurrentState->isTxBusy = false;
            linCurrentState->isRxBusy = false;
            linCurrentState->isBusBusy = false;
            linCurrentState->isRxBlocking = false;
            linCurrentState->isTxBlocking = false;
            linCurrentState->timeoutCounterFlag = false;
            linCurrentState->timeoutCounter = 0U;
            linCurrentState->txCompleted = false;
            linCurrentState->rxCompleted = false;
            linCurrentState->frame_index = 0U;

            /* Assign wakeup signal to satisfy LIN Specifications specifies that
             * wakeup signal shall be in range from 250us to 5 ms.
             */
            if (linUserConfig->baudRate > 10000U)
            {
                /* Wakeup signal will be range from 400us to 800us depend on baudrate */
                s_wakeupSignal[instance] = 0x80U;
            }
            else
            {
                /* Wakeup signal will be range from 400us to 4ms depend on baudrate */
                s_wakeupSignal[instance] = 0xF8U;
            }
            if (!((linUserConfig->autobaudEnable) && (linUserConfig->nodeFunction == (bool)LIN_SLAVE)))
            {
                /* Enable the SCI transmitter and receiver */
                base->SCICTRL |= (SCI_CTRL_TXEN_MASK | SCI_CTRL_RXEN_MASK);
            }
        }
        else
        {
            retVal = LIN_ERROR;
        }
    } /* End of if (linSourceClockFreq == 0U) */

    return retVal;
}

lin_status_t LIN_SCI_Deinit(SCI_TypeDef *base)
{
    lin_status_t retVal = LIN_SUCCESS;
    uint32_t instance = LIN_SCI_GetInstance(base);
    lin_state_t *linCurrentState = g_linStatePtr[instance];
    if ((linCurrentState == NULL) || (linCurrentState->linSourceClockFreq == 0U))
    {
        retVal = LIN_ERROR;
    }
    else
    {
        /* Wait until the data is completely shifted out of shift register */
        while (!(LIN_SCI_GetStatusFlags(base) & SCI_TransmissionCompleteFlag))
        {
            /* Do nothing */
        }

        /* Disable the SCI transmitter and receiver */
        base->SCICTRL &= ~(SCI_CTRL_TXEN_MASK | SCI_CTRL_RXEN_MASK);

        /* Disable SCI interrupt. */
        DisableIRQ(g_linSciRxTxIrqId[instance]);

        /* Disable SCI clock */
       // CLOCK_DisableClock(s_SciClock[instance]);

        /* Change node's current state to UNINIT */
        linCurrentState->currentNodeState = LIN_NODE_STATE_UNINIT;

        /* Clear our saved pointer to the LIN state structure */
        g_linStatePtr[instance] = NULL;
    }

    return retVal;
}

lin_status_t LIN_SCI_SendFrameDataBlocking(SCI_TypeDef *base,
                                              const uint8_t *txBuff,
                                              uint8_t txSize,
                                              uint32_t timeoutMSec)
{
    /* Assert parameters. */
    assert(txBuff);

    uint32_t instance = LIN_SCI_GetInstance(base);
    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];
    lin_status_t retVal = LIN_SUCCESS;
    /* Check whether current mode is sleep mode */
    bool checkSleepMode = (LIN_NODE_STATE_SLEEP_MODE == linCurrentState->currentNodeState);

    /* Check if txSize > 8 or equal to 0 or node's current state
     * is in SLEEP mode then return STATUS_ERROR */
    if ((8U < txSize) || (0U == txSize) || checkSleepMode)
    {
        retVal = LIN_ERROR;
    }
    else
    {
        /* Check if the LIN Bus is busy */
        if (linCurrentState->isBusBusy)
        {
            retVal = LIN_BUS_BUSY;
        }
        else
        {
            /* Make the checksum byte. */
            linCurrentState->checkSum = LIN_MakeChecksumByte(txBuff, txSize, linCurrentState->currentPid);

            /* Update the LIN state structure. */
            linCurrentState->txBuff = txBuff;
            /* Add a place for checksum byte */
            linCurrentState->txSize = txSize + 1U;
            linCurrentState->cntByte = 0U;
            linCurrentState->currentEventId = LIN_NO_EVENT;
            linCurrentState->isBusBusy = true;
            linCurrentState->isTxBusy = true;
            linCurrentState->isTxBlocking = true;
            linCurrentState->txCompleted = false;

            /* Set Break char detect length as 10 bits minimum */
            base->SCISTATUS &= ~SCI_STATUS_LBDE_MASK;

            LIN_SetTimeoutCounter(instance, timeoutMSec);
            /* Set node's current state to SEND_DATA */
            linCurrentState->currentNodeState = LIN_NODE_STATE_SEND_DATA;

            /* Start sending data */
            LIN_SCI_WriteByte(base, *linCurrentState->txBuff);
        }
    }
    return retVal;
}

lin_status_t LIN_SCI_SendFrameData(SCI_TypeDef *base, const uint8_t *txBuff, uint8_t txSize)
{
    /* Assert parameters. */
    assert(txBuff);

    uint32_t instance = LIN_SCI_GetInstance(base);
    lin_state_t *linCurrentState = g_linStatePtr[instance];
    lin_status_t retVal = LIN_SUCCESS;
    bool checkSleepMode = (LIN_NODE_STATE_SLEEP_MODE == linCurrentState->currentNodeState);

    /* Check if txSize > 8 or equal to 0 or node's current state
     * is in SLEEP mode then return STATUS_ERROR */
    if ((8U < txSize) || (0U == txSize) || checkSleepMode)
    {
        retVal = LIN_ERROR;
    }
    /* If txSixe is in range from 1 to 8 */
    else
    {
        /* Check if the LIN Bus is busy */
        if (linCurrentState->isBusBusy)
        {
            retVal = LIN_BUS_BUSY;
        }
        else
        {
            /* Make the checksum byte. */
            linCurrentState->checkSum = LIN_MakeChecksumByte(txBuff, txSize, linCurrentState->currentPid);

            /* Update the LIN state structure. */
            linCurrentState->txBuff = txBuff;
            /* Add a place for checksum byte */
            linCurrentState->txSize = txSize + 1U;
            linCurrentState->cntByte = 0U;
            linCurrentState->currentNodeState = LIN_NODE_STATE_SEND_DATA;
            linCurrentState->currentEventId = LIN_NO_EVENT;
            linCurrentState->isBusBusy = true;
            linCurrentState->isTxBusy = true;

/* Set Break char detect length as 10 bits minimum */
            /* Set Break char detect length as 10 bits minimum */
            base->SCISTATUS &= ~SCI_STATUS_LBDE_MASK;
            /* Start sending data */
            LIN_SCI_WriteByte(base, *linCurrentState->txBuff);
        }
    }
    return retVal;
}

lin_status_t LIN_SCI_GetTransmitStatus(SCI_TypeDef *base, uint8_t *bytesRemaining)
{
    lin_status_t retVal = LIN_SUCCESS;

    uint32_t instance = LIN_SCI_GetInstance(base);
    /* Get the current LIN state of this SCI instance. */
    const lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Get the number of bytes that is still needed to transmit */
    *bytesRemaining = linCurrentState->txSize - linCurrentState->cntByte;

    /* Return status of the on-going transmission */
    if ((linCurrentState->currentEventId == LIN_NO_EVENT) && (*bytesRemaining != 0U))
    {
        if (linCurrentState->timeoutCounterFlag == false)
        {
            retVal = LIN_TX_BUSY;
        }
        else
        {
            retVal = LIN_TIMEOUT;
        }
    }

    return retVal;
}

lin_status_t LIN_SCI_RecvFrmDataBlocking(SCI_TypeDef *base, uint8_t *rxBuff, uint8_t rxSize, uint32_t timeoutMSec)
{
    assert(rxBuff);

    uint32_t instance = LIN_SCI_GetInstance(base);

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];
    lin_status_t retVal = LIN_SUCCESS;
    /* Check whether current mode is sleep mode */
    bool checkSleepMode = (LIN_NODE_STATE_SLEEP_MODE == linCurrentState->currentNodeState);

    /* Check if rxSize > 8 or equal to 0 or node's current state
     * is in SLEEP mode then return STATUS_ERROR */
    if ((8U < rxSize) || (0U == rxSize) || checkSleepMode)
    {
        retVal = LIN_ERROR;
    }
    /* if rxSize is from 1 to 8 */
    else
    {
        /* Check if the LIN Bus is busy */
        if (linCurrentState->isBusBusy)
        {
            retVal = LIN_BUS_BUSY;
        }
        else
        {
            /* Update the LIN state structure. */
            linCurrentState->rxBuff = rxBuff;
            /* Add a place for checksum byte */
            linCurrentState->rxSize = rxSize + 1U;
            linCurrentState->cntByte = 0U;

            /* Start receiving data */
            linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_DATA;
            linCurrentState->currentEventId = LIN_NO_EVENT;
            linCurrentState->isBusBusy = true;
            linCurrentState->isRxBusy = true;
            linCurrentState->isRxBlocking = true;
            linCurrentState->rxCompleted = false;

            /* Set Break char detect length as 10 bits minimum */
            base->SCISTATUS &= ~SCI_STATUS_LBDE_MASK;

            LIN_SetTimeoutCounter(instance, timeoutMSec);
        }
    }

    return retVal;
}

lin_status_t LIN_SCI_RecvFrmData(SCI_TypeDef *base, uint8_t *rxBuff, uint8_t rxSize)
{
    assert(rxBuff);

    lin_status_t retVal = LIN_SUCCESS;

    uint32_t instance = LIN_SCI_GetInstance(base);

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Check whether current mode is sleep mode */
    bool checkSleepMode = (LIN_NODE_STATE_SLEEP_MODE == linCurrentState->currentNodeState);

    /* Check if rxSize > 8 or equal to 0 or node's current state
     * is in SLEEP mode then return STATUS_ERROR */
    if ((8U < rxSize) || (0U == rxSize) || checkSleepMode)
    {
        retVal = LIN_ERROR;
    }
    /* if rxSize is from 1 to 8 */
    else
    {
        /* Check if the LIN Bus is busy */
        if (linCurrentState->isBusBusy)
        {
            retVal = LIN_BUS_BUSY;
        }
        else
        {
            /* Update the LIN state structure. */
            linCurrentState->rxBuff = rxBuff;
            /* Add a place for checksum byte */
            linCurrentState->rxSize = rxSize + 1U;
            linCurrentState->cntByte = 0U;

            /* Start receiving data */
            linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_DATA;
            linCurrentState->currentEventId = LIN_NO_EVENT;
            linCurrentState->isBusBusy = true;
            linCurrentState->isRxBusy = true;
            linCurrentState->isRxBlocking = false;

            /* Set Break char detect length as 10 bits minimum */
            base->SCISTATUS &= ~SCI_STATUS_LBDE_MASK;
        }
    }

    return retVal;
}

lin_status_t LIN_SCI_AbortTransferData(SCI_TypeDef *base)
{
    lin_status_t retVal = LIN_SUCCESS;

    uint32_t instance = LIN_SCI_GetInstance(base);
    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Check if no transfer is running. */
    if (linCurrentState->isBusBusy)
    {
        /* Change node's current state to IDLE */
        (void)LIN_SCI_GotoIdleState(base);

        /* Clear LIN Bus Busy flag */
        linCurrentState->isTxBusy = false;
        linCurrentState->isRxBusy = false;
        linCurrentState->isBusBusy = false;
    }

    return retVal;
}

lin_status_t LIN_SCI_GetReceiveStatus(SCI_TypeDef *base, uint8_t *bytesRemaining)
{
    lin_status_t retVal = LIN_SUCCESS;

    uint32_t instance = LIN_SCI_GetInstance(base);
    /* Get the current LIN state of this SCI instance. */
    const lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Get the number of bytes that is still needed to receive */
    *bytesRemaining = linCurrentState->rxSize - linCurrentState->cntByte;

    /* Return status of the on-going reception */
    if ((linCurrentState->currentEventId == LIN_NO_EVENT) && (*bytesRemaining != 0U))
    {
        if (linCurrentState->timeoutCounterFlag == false)
        {
            retVal = LIN_RX_BUSY;
        }
        else
        {
            retVal = LIN_TIMEOUT;
        }
    }

    return retVal;
}

lin_status_t LIN_SCI_GoToSleepMode(SCI_TypeDef *base)
{
    lin_status_t retVal = LIN_SUCCESS;

    uint32_t instance = LIN_SCI_GetInstance(base);

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Update node's current state to SLEEP_MODE. */
    linCurrentState->currentNodeState = LIN_NODE_STATE_SLEEP_MODE;

    /* Set Receive data not inverted */
    LIN_SCI_SetRxDataPolarity(base, false);

    DisableIRQ(g_linSciRxTxIrqId[instance]);

    LIN_SCI_DisableInterrupts(base, SCI_LinBreakInterruptEnable);

    LIN_SCI_DisableInterrupts(base, (SCI_RxDataRegFullInterruptEnable | SCI_FramingErrorInterruptEnable));
    LIN_SCI_EnableInterrupts(base, SCI_RxActiveEdgeInterruptEnable);
    EnableIRQ(g_linSciRxTxIrqId[instance]);

    return retVal;
}

lin_status_t LIN_SCI_GotoIdleState(SCI_TypeDef *base)
{
    uint32_t instance = LIN_SCI_GetInstance(base);
    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Set Receive data not inverted */
    LIN_SCI_SetRxDataPolarity(base, false);

    DisableIRQ(g_linSciRxTxIrqId[instance]);

    /* Set Break char detect length as 13 bits minimum */
    base->SCISTATUS |= SCI_STATUS_LBDE_MASK;
    LIN_SCI_EnableInterrupts(base, SCI_LinBreakInterruptEnable);

    LIN_SCI_EnableInterrupts(base, (SCI_RxDataRegFullInterruptEnable | SCI_FramingErrorInterruptEnable));

    LIN_SCI_DisableInterrupts(base, SCI_RxActiveEdgeInterruptEnable);

    EnableIRQ(g_linSciRxTxIrqId[instance]);
    /* Change node's current state to IDLE */
    linCurrentState->currentNodeState = LIN_NODE_STATE_IDLE;

    return LIN_SUCCESS;
}

lin_status_t LIN_SCI_SendWakeupSignal(SCI_TypeDef *base)
{
    uint32_t instance = LIN_SCI_GetInstance(base);

    /* Get the current LIN state of this SCI instance. */
    const lin_state_t *linCurrentState = g_linStatePtr[instance];
    lin_status_t retVal = LIN_SUCCESS;

    if (linCurrentState->isBusBusy == false)
    {
        /* Send a wakeup signal */
        LIN_SCI_WriteByte(base, s_wakeupSignal[instance]);

    }
    else
    {
        retVal = LIN_BUS_BUSY;
    }

    return retVal;
}

lin_status_t LIN_SCI_MasterSendHeader(SCI_TypeDef *base, uint8_t id)
{
    lin_status_t retVal = LIN_SUCCESS;
    bool checkSleepMode = false;

    uint32_t instance = LIN_SCI_GetInstance(base);
    /* Get the current LIN user config structure of this SCI instance. */
    const lin_user_config_t *linUserConfig = g_linUserconfigPtr[instance];

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Check whether current mode is sleep mode */
    checkSleepMode = (LIN_NODE_STATE_SLEEP_MODE == linCurrentState->currentNodeState);
    /* Check if the current node is slave */
    if ((linUserConfig->nodeFunction == (bool)LIN_SLAVE) || (0x3FU < id) || checkSleepMode)
    {
        retVal = LIN_ERROR;
    }
    else
    {
        /* Check if the LIN bus is busy */
        if (linCurrentState->isBusBusy)
        {
            retVal = LIN_BUS_BUSY;
        }
        else
        {
            linCurrentState->currentId = id;

            /* Make parity for the current ID */
            linCurrentState->currentPid = LIN_ProcessParity(id, LIN_MAKE_PARITY);

            /* Send Break field */
            linCurrentState->currentNodeState = LIN_NODE_STATE_SEND_BREAK_FIELD;
            linCurrentState->currentEventId = LIN_NO_EVENT;
            linCurrentState->isBusBusy = true;

            /* Set Break char detect length as 13 bits minimum */
            base->SCISTATUS |= SCI_STATUS_LBDE_MASK;
            LIN_SCI_EnableInterrupts(base, SCI_LinBreakInterruptEnable);
            LIN_SCI_QueueBreakChar(base);
        }
    }

    return retVal;
}

lin_status_t LIN_SCI_EnableIRQ(SCI_TypeDef *base)
{
    lin_status_t retVal = LIN_SUCCESS;
    uint32_t instance = LIN_SCI_GetInstance(base);
    /* Get the current LIN state of this SCI instance. */
    const lin_state_t *linCurrentState = g_linStatePtr[instance];

    DisableIRQ(g_linSciRxTxIrqId[instance]);

    if (linCurrentState->currentNodeState == LIN_NODE_STATE_SLEEP_MODE)
    {
        /* Enable RX Input Active Edge interrupt */
        LIN_SCI_EnableInterrupts(base, SCI_RxActiveEdgeInterruptEnable);
    }
    else
    {
        LIN_SCI_EnableInterrupts(base, SCI_LinBreakInterruptEnable);
        LIN_SCI_EnableInterrupts(base, (SCI_RxDataRegFullInterruptEnable | SCI_FramingErrorInterruptEnable));
        EnableIRQ(g_linSciRxTxIrqId[instance]);
    }
    return retVal;
}

lin_status_t LIN_SCI_DisableIRQ(SCI_TypeDef *base)
{
    lin_status_t retVal = LIN_SUCCESS;

    uint32_t instance = LIN_SCI_GetInstance(base);

    /* Get the current LIN state of this SCI instance. */
    const lin_state_t *linCurrentState = g_linStatePtr[instance];

    if (linCurrentState->currentNodeState == LIN_NODE_STATE_SLEEP_MODE)
    {
        /* Disable RX Input Active Edge interrupt */
        LIN_SCI_DisableInterrupts(base, SCI_RxActiveEdgeInterruptEnable);
    }
    else
    {
        LIN_SCI_DisableInterrupts(base, SCI_LinBreakInterruptEnable);
        LIN_SCI_DisableInterrupts(base,
                                     (SCI_RxDataRegFullInterruptEnable | SCI_FramingErrorInterruptEnable));

        DisableIRQ(g_linSciRxTxIrqId[instance]);
    }
    /* Disable SCI interrupt. */
    return retVal;
}

lin_status_t LIN_SCI_AutoBaudCapture(uint32_t instance)
{
    /* Get base address of the SCI instance. */
    SCI_TypeDef *base = g_linSciBase[instance];
    /* Get the current LIN user config structure of this SCI instance. */
    const lin_user_config_t *linUserConfig = g_linUserconfigPtr[instance];
    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];
    lin_status_t retVal = LIN_BUS_BUSY;
    uint32_t tmpTime = 0U;

    if (linCurrentState->baudrateEvalEnable)
    {
        /* Calculate time between two bit (for service autobaud) */
        (void)linUserConfig->timerGetTimeIntervalCallback(&tmpTime);

        /* Get two bits time length */
        s_timeMeasure[instance] += tmpTime;
        s_countMeasure[instance]++;
        if ((s_countMeasure[instance] > 1U))
        {
            switch (linCurrentState->currentNodeState)
            {
                /* If current state is SLEEP MODE */
                case LIN_NODE_STATE_SLEEP_MODE:
                    /* If length of the dominant signal is from 150us to 5ms, it is a wakeup signal */
                    if ((tmpTime >= 150000U) && (tmpTime <= 5000000U))
                    {
                        linCurrentState->currentEventId = LIN_WAKEUP_SIGNAL;

                        /* Callback to handle event: Received a wakeup signal */
                        if (linCurrentState->Callback != NULL)
                        {
                            linCurrentState->Callback(instance, linCurrentState);
                        }

                        /* Change node's state to IDLE */
                        (void)LIN_SCI_GotoIdleState(base);
                    }
                    else
                    {
                        retVal = LIN_ERROR;
                    }
                    s_countMeasure[instance] = 0U;

                    break;
                /* If current state is IDLE */
                case LIN_NODE_STATE_IDLE:
                    /* Check break time minimum */
                    if (tmpTime >= AUTOBAUD_BREAK_TIME_MIN)
                    {
                        /* Set Break char detect length as 13 bits minimum and interrupt */
                        base->SCISTATUS &= ~SCI_STATUS_LBDE_MASK;
                        LIN_SCI_DisableInterrupts(base, SCI_LinBreakInterruptEnable);

                        /* Set flag LIN bus busy */
                        linCurrentState->isBusBusy = true;

                        /* Change the node's current state to RECEIVED BREAK FIELD */
                        linCurrentState->currentEventId = LIN_RECV_BREAK_FIELD_OK;

                        /* Callback function */
                        if (linCurrentState->Callback != NULL)
                        {
                            linCurrentState->Callback(instance, linCurrentState);
                        }

                        /* Change the node's current state to RECEIVING SYNC FIELD */
                        linCurrentState->currentNodeState = LIN_NODE_STATE_RECV_SYNC;

                        /* Start Autobaud Count(initialize number of measurements in sync byte) */
                        linCurrentState->fallingEdgeInterruptCount = 0U;

                        s_countMeasure[instance] = 1U;
                    }
                    else
                    {
                        s_countMeasure[instance] = 0U;
                        retVal = LIN_ERROR;
                    }

                    break;
                /* If current state is RECEIVE SYNC */
                default:
                    /* Calculate baudrate */
                    LIN_SCI_AutobaudTimerValEval(instance, s_timeMeasure[instance]);

                    /* Reset to measure in next times */
                    s_countMeasure[instance] = 0U;
                    s_timeMeasure[instance] = 0U;

                    if (linCurrentState->currentNodeState == LIN_NODE_STATE_IDLE)
                    {
                        retVal = LIN_ERROR;
                    }

                    break;
            }
        }
    }
    else
    {
        if (linCurrentState->fallingEdgeInterruptCount > 4U)
        {
            /* Enable the SCI transmitter and receiver */
            base->SCICTRL |= (SCI_CTRL_TXEN_MASK | SCI_CTRL_RXEN_MASK);

            linCurrentState->fallingEdgeInterruptCount = 0U;
        }

        retVal = LIN_SUCCESS;
    }

    return retVal;
}

void LIN_SCI_IRQHandler(SCI_TypeDef *base)
{
    uint8_t tmpByte = 0xFFU;

    uint32_t instance = LIN_SCI_GetInstance(base);

    /* Get the current LIN state of this SCI instance. */
    lin_state_t *linCurrentState = g_linStatePtr[instance];

    /* Check RX Input Active Edge interrupt enable */
    bool activeEdgeIntState = (bool)(base->SCICNFG & (1 << SCI_CNFG_RXEDGIE_SHIFT));

    /* If LIN break character has been detected. */
    if (LIN_SCI_GetStatusFlags(base) & SCI_LinBreakFlag)
    {
        LIN_SCI_ProcessBreakDetect(instance);
    }
    else
    {
        /* If SCI_RX Pin Active Edge has been detected. */
        if ((LIN_SCI_GetStatusFlags(base) & SCI_RxActiveEdgeFlag) && activeEdgeIntState)
        {
            /* Clear SCI_RX Pin Active Edge Interrupt Flag. Write 1 to clear */
            LIN_SCI_ClearStatusFlags(base, SCI_RxActiveEdgeFlag);

            /* Check if the node is in SLEEP MODE */
            /* If yes, then check if a wakeup signal has been received */
            if (linCurrentState->currentNodeState == LIN_NODE_STATE_SLEEP_MODE)
            {
                LIN_SCI_CheckWakeupSignal(instance);
            }
        }
        else
        {
            /* If Framing Error has been detected Write 1 to clear */
            if (LIN_SCI_GetStatusFlags(base) & SCI_FramingErrorFlag)
            {
                /* Clear Framing Error Interrupt Flag */
                LIN_SCI_ClearStatusFlags(base, SCI_FramingErrorFlag);

                /* Read dummy to clear SCI_RX_DATA_REG_FULL flag */
                LIN_SCI_ReadByte(base, &tmpByte);
                /* Set current event id to LIN_FRAME_ERROR */
                linCurrentState->currentEventId = LIN_FRAME_ERROR;

                if (linCurrentState->currentNodeState == LIN_NODE_STATE_SEND_DATA)
                {
                    /* Callback function to handle Framing Error Event */
                    if (linCurrentState->Callback != NULL)
                    {
                        linCurrentState->Callback(instance, linCurrentState);
                    }
                }

                if (linCurrentState->isRxBlocking == false)
                {
                    if (linCurrentState->currentNodeState == LIN_NODE_STATE_RECV_DATA)
                    {
                        /* Callback function to handle Framing Error Event */
                        if (linCurrentState->Callback != NULL)
                        {
                            linCurrentState->Callback(instance, linCurrentState);
                        }
                    }
                }

                /* Clear Bus busy Flag */
                linCurrentState->isBusBusy = false;
                /* Change node's state to IDLE */
                (void)LIN_SCI_GotoIdleState(base);
            }
            else
            {
                if (LIN_SCI_GetStatusFlags(base) & SCI_RxDataRegFullFlag)
                {
                    LIN_SCI_ClearStatusFlags(base, SCI_RxDataRegFullFlag);
                    /* Get data from Data Register & Clear SCI_RX_DATA_REG_FULL flag */
                    LIN_SCI_ReadByte(base, &tmpByte);
                    /* Process data in Data Register while receive, send data */
                    LIN_SCI_ProcessFrame(instance, tmpByte);
                }
            } /* End else: if (LIN_SCI_GetStatusFlags(base) & SCI_FramingErrorFlag) */
        }     /* End else: if ((LIN_SCI_GetStatusFlags(base) & SCI_RxActiveEdgeFlag) && activeEdgeIntState) */
    }         /* End else: if (LIN_SCI_GetStatusFlags(base) & SCI_LinBreakFlag) */

    /* Get status RX overrun flag */
    if (LIN_SCI_GetStatusFlags(base) & SCI_RxOverrunFlag)
    {
        /* Clear overrun flag */
        LIN_SCI_ClearStatusFlags(base, SCI_RxOverrunFlag);
    }
} 
