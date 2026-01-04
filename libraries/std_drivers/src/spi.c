//###########################################################################
//
// FILE:   spi.c
//
// TITLE:  SP28038 SPI driver.
//
//###########################################################################

#include "spi.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief Typedef for master interrupt handler. */
typedef void (*spi_master_isr_t)(SPI_Type *base, spi_master_handle_t *handle);

/*! @brief Typedef for slave interrupt handler. */
typedef void (*spi_slave_isr_t)(SPI_Type *base, spi_slave_handle_t *handle);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for spi module.
 *
 * @param base spi peripheral base address.
 */
uint32_t SPI_GetInstance(SPI_Type *base);


/*!
 * @brief Configures the spi peripheral chip select polarity.
 *
 * This function  takes in the desired peripheral chip select (Pcs) and it's corresponding desired polarity and
 * configures the Pcs signal to operate with the desired characteristic.
 *
 * @param base spi peripheral address.
 * @param pcs The particular peripheral chip select (parameter value is of type spi_which_pcs_t) for which we wish to
 *            apply the active high or active low characteristic.
 * @param activeLowOrHigh The setting for either "active high, inactive low (0)"  or "active low, inactive high(1)" of
 *                        type spi_pcs_polarity_config_t.
 */
static void SPI_SetOnePcsPolarity(SPI_Type *base, spi_which_pcs_t pcs, spi_pcs_polarity_config_t activeLowOrHigh);

/*!
 * @brief Master fill up the TX FIFO with data.
 * This is not a public API as it is called from other driver functions.
 */
static void SPI_MasterFillUpTxFifo(SPI_Type *base, spi_master_handle_t *handle);

/*!
 * @brief Master finish up a transfer.
 * It would call back if there is callback function and set the state to idle.
 * This is not a public API as it is called from other driver functions.
 */
static void SPI_MasterCompleteTransfer(SPI_Type *base, spi_master_handle_t *handle);

/*!
 * @brief Slave fill up the TX FIFO with data.
 * This is not a public API as it is called from other driver functions.
 */
static void SPI_SlaveFillUpTxFifo(SPI_Type *base, spi_slave_handle_t *handle);

/*!
 * @brief Slave finish up a transfer.
 * It would call back if there is callback function and set the state to idle.
 * This is not a public API as it is called from other driver functions.
 */
static void SPI_SlaveCompleteTransfer(SPI_Type *base, spi_slave_handle_t *handle);

/*!
 * @brief spi common interrupt handler.
 *
 * @param base spi peripheral address.
 * @param handle pointer to g_spiHandle which stores the transfer state.
 */
static void SPI_CommonIRQHandler(SPI_Type *base, void *param);

/*!
 * @brief Master prepare the transfer.
 * Basically it set up spi_master_handle .
 * This is not a public API as it is called from other driver functions. fsl_spi_edma.c also call this function.
 */
static void SPI_MasterPrepareTransfer(SPI_Type *base, spi_master_handle_t *handle, spi_transfer_t *transfer);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Defines constant value arrays for the baud rate pre-scalar and scalar divider values.*/
static const uint32_t s_baudratePrescaler[] = {2, 3, 5, 7};
static const uint32_t s_baudrateScaler[] = {2,   4,   6,    8,    16,   32,   64,    128,
                                            256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

static const uint32_t s_delayPrescaler[] = {1, 3, 5, 7};
static const uint32_t s_delayScaler[] = {2,   4,    8,    16,   32,   64,    128,   256,
                                         512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

/*! @brief Pointers to spi bases for each instance. */
SPI_Type *const s_spiBases[] = SPI_BASE_PTRS;

/*! @brief Pointers to spi IRQ number for each instance. */
const IRQn_Type s_spiIRQ[] = SPI_IRQS;

/*! @brief Pointers to spi clocks for each instance. */
//const clock_ip_name_t s_spiClock[] = SPI_CLOCKS;

/*! @brief Pointers to spi handles for each instance. */
void *g_spiHandle[SPI_COUNT] = {NULL};

/*! @brief Pointer to master IRQ handler for each instance. */
static spi_master_isr_t s_spiMasterIsr;

/*! @brief Pointer to slave IRQ handler for each instance. */
static spi_slave_isr_t s_spiSlaveIsr;

/**********************************************************************************************************************
* Code
*********************************************************************************************************************/
void delaynstep(int i)
{
    while(i--);
}

uint32_t SPI_GetInstance(SPI_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < SPI_COUNT; instance++)
    {
        if (s_spiBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < 5);

    return instance;
}

void SPI_MasterInit(SPI_Type *base, const spi_master_config_t *masterConfig, uint32_t srcClock_Hz)
{
    uint32_t temp;
    uint32_t actualBaudRate = 0;
    /* enable spi clock */
    //CLOCK_EnableClock(s_spiClock[SPI_GetInstance(base)]);

    SPI_Enable(base, true);
    SPI_StopTransfer(base);

    SPI_SetMasterSlaveMode(base, sSPI_Master);

    temp = base->MCFGR & (~(SPI_MCFGR_CSCKE_MASK | SPI_MCFGR_MTXFE_MASK | SPI_MCFGR_RFOOE_MASK | SPI_MCFGR_SMPPT_MASK |
                          SPI_MCFGR_TXFD_MASK | SPI_MCFGR_RXFD_MASK));

    base->MCFGR = temp | SPI_MCFGR_CSCKE_SET(masterConfig->enableContinuousSCK) |
                SPI_MCFGR_MTXFE_SET(masterConfig->enableModifiedTimingFormat) |
                SPI_MCFGR_RFOOE_SET(masterConfig->enableRxFifoOverWrite) | SPI_MCFGR_SMPPT_SET(masterConfig->samplePoint) |
                SPI_MCFGR_TXFD_SET(false) | SPI_MCFGR_RXFD_SET(false);

    SPI_SetOnePcsPolarity(base, masterConfig->whichPcs, masterConfig->pcsActiveHighOrLow);

    actualBaudRate =
        SPI_MasterSetBaudRate(base, masterConfig->whichCtar, masterConfig->ctarConfig.baudRate, srcClock_Hz);
    assert(actualBaudRate > 0);

    temp = base->CLKTAR[masterConfig->whichCtar] &
           ~(SPI_CLKTAR_FSZ_MASK | SPI_CLKTAR_CLKPOL_MASK | SPI_CLKTAR_CLKPHS_MASK | SPI_CLKTAR_LSBFST_MASK);

    base->CLKTAR[masterConfig->whichCtar] =
        temp | SPI_CLKTAR_FSZ_SET(masterConfig->ctarConfig.bitsPerFrame - 1) | SPI_CLKTAR_CLKPOL_SET(masterConfig->ctarConfig.cpol) |
        SPI_CLKTAR_CLKPHS_SET(masterConfig->ctarConfig.cpha) | SPI_CLKTAR_LSBFST_SET(masterConfig->ctarConfig.direction);

    SPI_MasterSetDelayTimes(base, masterConfig->whichCtar, sSPI_PcsToSck, srcClock_Hz,
                             masterConfig->ctarConfig.pcsToSckDelayInNanoSec);
    SPI_MasterSetDelayTimes(base, masterConfig->whichCtar, sSPI_LastSckToPcs, srcClock_Hz,
                             masterConfig->ctarConfig.lastSckToPcsDelayInNanoSec);
    SPI_MasterSetDelayTimes(base, masterConfig->whichCtar, sSPI_BetweenTransfer, srcClock_Hz,
                             masterConfig->ctarConfig.betweenTransferDelayInNanoSec);

    SPI_StartTransfer(base);
}

void SPI_MasterGetDefaultConfig(spi_master_config_t *masterConfig)
{
    masterConfig->whichCtar = sSPI_Ctar0;
    masterConfig->ctarConfig.baudRate = 500000;
    masterConfig->ctarConfig.bitsPerFrame = 8;
    masterConfig->ctarConfig.cpol = sSPI_ClockPolarityActiveHigh;
    masterConfig->ctarConfig.cpha = sSPI_ClockPhaseFirstEdge;
    masterConfig->ctarConfig.direction = sSPI_MsbFirst;

    masterConfig->ctarConfig.pcsToSckDelayInNanoSec = 1000;
    masterConfig->ctarConfig.lastSckToPcsDelayInNanoSec = 1000;
    masterConfig->ctarConfig.betweenTransferDelayInNanoSec = 1000;

    masterConfig->whichPcs = sSPI_Pcs0;
    masterConfig->pcsActiveHighOrLow = sSPI_PcsActiveLow;

    masterConfig->enableContinuousSCK = false;
    masterConfig->enableRxFifoOverWrite = false;
    masterConfig->enableModifiedTimingFormat = false;
    masterConfig->samplePoint = sSPI_SckToSin0Clock;
}

void SPI_SlaveInit(SPI_Type *base, const spi_slave_config_t *slaveConfig)
{
    uint32_t temp = 0;

    /* enable spi clock */
    //CLOCK_EnableClock(s_spiClock[spi_GetInstance(base)]);

    SPI_Enable(base, true);
    SPI_StopTransfer(base);

    SPI_SetMasterSlaveMode(base, sSPI_Slave);

    temp = base->MCFGR & (~(SPI_MCFGR_CSCKE_MASK | SPI_MCFGR_MTXFE_MASK | SPI_MCFGR_RFOOE_MASK | SPI_MCFGR_SMPPT_MASK |
                          SPI_MCFGR_TXFD_MASK | SPI_MCFGR_RXFD_MASK));

    base->MCFGR = temp | SPI_MCFGR_CSCKE_SET(slaveConfig->enableContinuousSCK) |
                SPI_MCFGR_MTXFE_SET(slaveConfig->enableModifiedTimingFormat) |
                SPI_MCFGR_RFOOE_SET(slaveConfig->enableRxFifoOverWrite) | SPI_MCFGR_SMPPT_SET(slaveConfig->samplePoint) |
                SPI_MCFGR_TXFD_SET(false) | SPI_MCFGR_RXFD_SET(false);

    SPI_SetOnePcsPolarity(base, sSPI_Pcs0, sSPI_PcsActiveLow);

    temp = base->CLKTAR[slaveConfig->whichCtar] &
           ~(SPI_CLKTAR_FSZ_MASK | SPI_CLKTAR_CLKPOL_MASK | SPI_CLKTAR_CLKPHS_MASK | SPI_CLKTAR_LSBFST_MASK);

    base->CLKTAR[slaveConfig->whichCtar] = temp | SPI_CLKTAR_SLV_FSZ_SET(slaveConfig->ctarConfig.bitsPerFrame - 1) |
                                         SPI_CLKTAR_SLV_CLKPOL_SET(slaveConfig->ctarConfig.cpol) |
                                         SPI_CLKTAR_SLV_CLKPHS_SET(slaveConfig->ctarConfig.cpha);

    SPI_StartTransfer(base);
}

void SPI_SlaveGetDefaultConfig(spi_slave_config_t *slaveConfig)
{
    slaveConfig->whichCtar = sSPI_Ctar0;
    slaveConfig->ctarConfig.bitsPerFrame = 8;
    slaveConfig->ctarConfig.cpol = sSPI_ClockPolarityActiveHigh;
    slaveConfig->ctarConfig.cpha = sSPI_ClockPhaseFirstEdge;

    slaveConfig->enableContinuousSCK = false;
    slaveConfig->enableRxFifoOverWrite = false;
    slaveConfig->enableModifiedTimingFormat = false;
    slaveConfig->samplePoint = sSPI_SckToSin0Clock;
}

void SPI_Deinit(SPI_Type *base)
{
    SPI_StopTransfer(base);
    SPI_Enable(base, false);

    /* disable spi clock */
    //CLOCK_DisableClock(s_spiClock[SPI_GetInstance(base)]);
}

static void SPI_SetOnePcsPolarity(SPI_Type *base, spi_which_pcs_t pcs, spi_pcs_polarity_config_t activeLowOrHigh)
{
    uint32_t temp;

    temp = base->MCFGR;

    if (activeLowOrHigh == sSPI_PcsActiveLow)
    {
        temp |= SPI_MCFGR_PCSIS_SET(pcs);
    }
    else
    {
        temp &= ~SPI_MCFGR_PCSIS_SET(pcs);
    }

    base->MCFGR = temp;
}

uint32_t SPI_MasterSetBaudRate(SPI_Type *base,
                                spi_ctar_selection_t whichCtar,
                                uint32_t baudRate_Bps,
                                uint32_t srcClock_Hz)
{
    /* for master mode configuration, if slave mode detected, return 0*/
    if (!SPI_IsMaster(base))
    {
        return 0;
    }
    uint32_t temp;
    uint32_t prescaler, bestPrescaler;
    uint32_t scaler, bestScaler;
    uint32_t dbr, bestDbr;
    uint32_t realBaudrate, bestBaudrate;
    uint32_t diff, min_diff;
    uint32_t baudrate = baudRate_Bps;

    /* find combination of prescaler and scaler resulting in baudrate closest to the requested value */
    min_diff = 0xFFFFFFFFU;
    bestPrescaler = 0;
    bestScaler = 0;
    bestDbr = 1;
    bestBaudrate = 0; /* required to avoid compilation warning */

    /* In all for loops, if min_diff = 0, the exit for loop*/
    for (prescaler = 0; (prescaler < 4) && min_diff; prescaler++)
    {
        for (scaler = 0; (scaler < 16) && min_diff; scaler++)
        {
            for (dbr = 1; (dbr < 3) && min_diff; dbr++)
            {
                realBaudrate = ((srcClock_Hz * dbr) / (s_baudratePrescaler[prescaler] * (s_baudrateScaler[scaler])));

                /* calculate the baud rate difference based on the conditional statement that states that the calculated
                * baud rate must not exceed the desired baud rate.
                */
                if (baudrate >= realBaudrate)
                {
                    diff = baudrate - realBaudrate;
                    if (min_diff > diff)
                    {
                        /* a better match found */
                        min_diff = diff;
                        bestPrescaler = prescaler;
                        bestScaler = scaler;
                        bestBaudrate = realBaudrate;
                        bestDbr = dbr;
                    }
                }
            }
        }
    }

    /* write the best dbr, prescalar, and baud rate scalar to the CLKTAR */
    temp = base->CLKTAR[whichCtar] & ~(SPI_CLKTAR_DBRT_MASK | SPI_CLKTAR_BRP_MASK | SPI_CLKTAR_BRS_MASK);

    base->CLKTAR[whichCtar] = temp | ((bestDbr - 1) << SPI_CLKTAR_DBRT_SHIFT) | (bestPrescaler << SPI_CLKTAR_BRP_SHIFT) |
                            (bestScaler << SPI_CLKTAR_BRS_SHIFT);

    /* return the actual calculated baud rate */
    return bestBaudrate;
}

void SPI_MasterSetDelayScaler(
    SPI_Type *base, spi_ctar_selection_t whichCtar, uint32_t prescaler, uint32_t scaler, spi_delay_type_t whichDelay)
{
    /* these settings are only relevant in master mode */
    if (SPI_IsMaster(base))
    {
        switch (whichDelay)
        {
            case sSPI_PcsToSck:
                base->CLKTAR[whichCtar] = (base->CLKTAR[whichCtar] & (~SPI_CLKTAR_PCSSDP_MASK) & (~SPI_CLKTAR_PCSSCKDS_MASK)) |
                                        SPI_CLKTAR_PCSSDP_SET(prescaler) | SPI_CLKTAR_PCSSCKDS_SET(scaler);
                break;
            case sSPI_LastSckToPcs:
                base->CLKTAR[whichCtar] = (base->CLKTAR[whichCtar] & (~SPI_CLKTAR_ASDP_MASK) & (~SPI_CLKTAR_ASDS_MASK)) |
                                        SPI_CLKTAR_ASDP_SET(prescaler) | SPI_CLKTAR_ASDS_SET(scaler);
                break;
            case sSPI_BetweenTransfer:
                base->CLKTAR[whichCtar] = (base->CLKTAR[whichCtar] & (~SPI_CLKTAR_DATXP_MASK) & (~SPI_CLKTAR_DATS_MASK)) |
                                        SPI_CLKTAR_DATXP_SET(prescaler) | SPI_CLKTAR_DATS_SET(scaler);
                break;
            default:
                break;
        }
    }
}

uint32_t SPI_MasterSetDelayTimes(SPI_Type *base,
                                  spi_ctar_selection_t whichCtar,
                                  spi_delay_type_t whichDelay,
                                  uint32_t srcClock_Hz,
                                  uint32_t delayTimeInNanoSec)
{
    /* for master mode configuration, if slave mode detected, return 0 */
    if (!SPI_IsMaster(base))
    {
        return 0;
    }

    uint32_t prescaler, bestPrescaler;
    uint32_t scaler, bestScaler;
    uint32_t realDelay, bestDelay;
    uint32_t diff, min_diff;
    uint32_t initialDelayNanoSec;

    /* find combination of prescaler and scaler resulting in the delay closest to the
    * requested value
    */
    min_diff = 0xFFFFFFFFU;
    /* Initialize prescaler and scaler to their max values to generate the max delay */
    bestPrescaler = 0x3;
    bestScaler = 0xF;
    bestDelay = (((1000000000U * 4) / srcClock_Hz) * s_delayPrescaler[bestPrescaler] * s_delayScaler[bestScaler]) / 4;

    /* First calculate the initial, default delay */
    initialDelayNanoSec = 1000000000U / srcClock_Hz * 2;

    /* If the initial, default delay is already greater than the desired delay, then
    * set the delays to their initial value (0) and return the delay. In other words,
    * there is no way to decrease the delay value further.
    */
    if (initialDelayNanoSec >= delayTimeInNanoSec)
    {
        SPI_MasterSetDelayScaler(base, whichCtar, 0, 0, whichDelay);
        return initialDelayNanoSec;
    }

    /* In all for loops, if min_diff = 0, the exit for loop */
    for (prescaler = 0; (prescaler < 4) && min_diff; prescaler++)
    {
        for (scaler = 0; (scaler < 16) && min_diff; scaler++)
        {
            realDelay = ((4000000000U / srcClock_Hz) * s_delayPrescaler[prescaler] * s_delayScaler[scaler]) / 4;

            /* calculate the delay difference based on the conditional statement
            * that states that the calculated delay must not be less then the desired delay
            */
            if (realDelay >= delayTimeInNanoSec)
            {
                diff = realDelay - delayTimeInNanoSec;
                if (min_diff > diff)
                {
                    /* a better match found */
                    min_diff = diff;
                    bestPrescaler = prescaler;
                    bestScaler = scaler;
                    bestDelay = realDelay;
                }
            }
        }
    }

    /* write the best dbr, prescalar, and baud rate scalar to the CLKTAR */
    SPI_MasterSetDelayScaler(base, whichCtar, bestPrescaler, bestScaler, whichDelay);

    /* return the actual calculated baud rate */
    return bestDelay;
}

void SPI_GetDefaultDataCommandConfig(spi_command_data_config_t *command)
{
    command->isPcsContinuous = false;
    command->whichCtar = sSPI_Ctar0;
    command->whichPcs = sSPI_Pcs0;
    command->isEndOfQueue = false;
    command->clearTransferCount = false;
}

void SPI_MasterWriteDataBlocking(SPI_Type *base, spi_command_data_config_t *command, uint16_t data)
{
    /* First, clear Transmit Complete Flag (TCF) */
    SPI_ClearStatusFlags(base, sSPI_TxCompleteFlag);

    while (!(SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag))
    {
        SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
    }

    base->PUSHTFR = SPI_PUSHTFR_CPCSE_SET(command->isPcsContinuous) | SPI_PUSHTFR_CLKTXAS_SET(command->whichCtar) |
                  SPI_PUSHTFR_SPCS_SET(command->whichPcs) | SPI_PUSHTFR_EQ_SET(command->isEndOfQueue) |
                  SPI_PUSHTFR_CTXCTR_SET(command->clearTransferCount) | SPI_PUSHTFR_TXDAT_SET(data);
    SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

    /* Wait till TCF sets */
    while (!(SPI_GetStatusFlags(base) & sSPI_TxCompleteFlag))
    {
    }
}

void SPI_MasterWriteCommandDataBlocking(SPI_Type *base, uint32_t data)
{
    /* First, clear Transmit Complete Flag (TCF) */
    SPI_ClearStatusFlags(base, sSPI_TxCompleteFlag);

    while (!(SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag))
    {
        SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
    }

    base->PUSHTFR = data;

    SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

    /* Wait till TCF sets */
    while (!(SPI_GetStatusFlags(base) & sSPI_TxCompleteFlag))
    {
    }
}

void SPI_SlaveWriteDataBlocking(SPI_Type *base, uint32_t data)
{
    /* First, clear Transmit Complete Flag (TCF) */
    SPI_ClearStatusFlags(base, sSPI_TxCompleteFlag);

    while (!(SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag))
    {
        SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
    }

    base->PUSHTFR_SLV = data;

    SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

    /* Wait till TCF sets */
    while (!(SPI_GetStatusFlags(base) & sSPI_TxCompleteFlag))
    {
    }
}

void SPI_EnableInterrupts(SPI_Type *base, uint32_t mask)
{
    if (mask & SPI_IRSER_TXFFRE_MASK)
    {
        base->IRSER &= ~SPI_IRSER_TXFFIRS_MASK;
    }
    if (mask & SPI_IRSER_RXFDRE_MASK)
    {
        base->IRSER &= ~SPI_IRSER_RXFDIRS_MASK;
    }
    base->IRSER |= mask;
}

sstat_t SPI_MasterTransferBlocking(SPI_Type *base, spi_transfer_t *transfer)
{
    assert(transfer);

    uint16_t wordToSend = 0;
    uint16_t wordReceived = 0;
    uint8_t dummyData = SPI_MASTER_DUMMY_DATA;
    uint8_t bitsPerFrame;

    uint32_t command;
    uint32_t lastCommand;

    uint8_t *txData;
    uint8_t *rxData;
    uint32_t remainingSendByteCount;
    uint32_t remainingReceiveByteCount;

    uint32_t fifoSize;
    spi_command_data_config_t commandStruct;

    /* If the transfer count is zero, then return immediately.*/
    if (transfer->dataSize == 0)
    {
        return sStatus_InvalidArgument;
    }

    SPI_StopTransfer(base);
    SPI_DisableInterrupts(base, sSPI_AllInterruptEnable);
    SPI_FlushFifo(base, true, true);
    SPI_ClearStatusFlags(base, sSPI_AllStatusFlag);

    /*Calculate the command and lastCommand*/
    commandStruct.whichPcs =
        (spi_which_pcs_t)(1U << ((transfer->configFlags & SPI_MASTER_PCS_MASK) >> SPI_MASTER_PCS_SHIFT));
    commandStruct.isEndOfQueue = false;
    commandStruct.clearTransferCount = false;
    commandStruct.whichCtar =
        (spi_ctar_selection_t)((transfer->configFlags & SPI_MASTER_CTAR_MASK) >> SPI_MASTER_CTAR_SHIFT);
    commandStruct.isPcsContinuous = (bool)(transfer->configFlags & sSPI_MasterPcsContinuous);

    command = SPI_MasterGetFormattedCommand(&(commandStruct));

    commandStruct.isPcsContinuous = (bool)(transfer->configFlags & sSPI_MasterActiveAfterTransfer);
    lastCommand = SPI_MasterGetFormattedCommand(&(commandStruct));

    /*Calculate the bitsPerFrame*/
    bitsPerFrame = ((base->CLKTAR[commandStruct.whichCtar] & SPI_CLKTAR_FSZ_MASK) >> SPI_CLKTAR_FSZ_SHIFT) + 1;

    txData = transfer->txData;
    rxData = transfer->rxData;
    remainingSendByteCount = transfer->dataSize;
    remainingReceiveByteCount = transfer->dataSize;

    if ((base->MCFGR & SPI_MCFGR_RXFD_MASK) || (base->MCFGR & SPI_MCFGR_TXFD_MASK))
    {
        fifoSize = 1;
    }
    else
    {
        fifoSize = SPI_FIFO_SIZEn(base);
    }

    SPI_StartTransfer(base);

    if (bitsPerFrame <= 8)
    {
        while (remainingSendByteCount > 0)
        {
            if (remainingSendByteCount == 1)
            {
                while ((remainingReceiveByteCount - remainingSendByteCount) >= fifoSize)
                {
                    if (SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag)
                    {
                        if (rxData != NULL)
                        {
                            *(rxData) = SPI_ReadData(base);
                            rxData++;
                        }
                        else
                        {
                            SPI_ReadData(base);
                        }
                        remainingReceiveByteCount--;

                        SPI_ClearStatusFlags(base, sSPI_RxFifoDrainRequestFlag);
                    }
                }

                while (!(SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag))
                {
                    SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
                }

                if (txData != NULL)
                {
                    base->PUSHTFR = (*txData) | (lastCommand);
                    txData++;
                }
                else
                {
                    base->PUSHTFR = (lastCommand) | (dummyData);
                }
                
                SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
                remainingSendByteCount--;

                while (remainingReceiveByteCount > 0)
                {
                    if (SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag)
                    {
                        if (rxData != NULL)
                        {
                            /* Read data from POPR*/
                            *(rxData) = SPI_ReadData(base);
                            rxData++;
                        }
                        else
                        {
                            SPI_ReadData(base);
                        }
                        remainingReceiveByteCount--;

                        SPI_ClearStatusFlags(base, sSPI_RxFifoDrainRequestFlag);
                    }
                }
            }
            else
            {
                /*Wait until Tx Fifo is not full*/
                while (!(SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag))
                {
                    SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
                }
                if (txData != NULL)
                {
                    base->PUSHTFR = command | (uint16_t)(*txData);
                    txData++;
                }
                else
                {
                    base->PUSHTFR = command | dummyData;
                }

                remainingSendByteCount--;

                SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

                if (SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag)
                {
                    if (rxData != NULL)
                    {
                        *(rxData) = SPI_ReadData(base);
                        rxData++;
                    }
                    else
                    {
                        SPI_ReadData(base);
                    }
                    remainingReceiveByteCount--;

                    SPI_ClearStatusFlags(base, sSPI_RxFifoDrainRequestFlag);
                }
            }
        }
    }
    else
    {
        while (remainingSendByteCount > 0)
        {
            if (remainingSendByteCount <= 2)
            {
                while (((remainingReceiveByteCount - remainingSendByteCount) / 2) >= fifoSize)
                {
                    if (SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag)
                    {
                        wordReceived = SPI_ReadData(base);

                        if (rxData != NULL)
                        {
                            *rxData = wordReceived;
                            ++rxData;
                            *rxData = wordReceived >> 8;
                            ++rxData;
                        }
                        remainingReceiveByteCount -= 2;

                        SPI_ClearStatusFlags(base, sSPI_RxFifoDrainRequestFlag);
                    }
                }

                while (!(SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag))
                {
                    SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
                }

                if (txData != NULL)
                {
                    wordToSend = *(txData);
                    ++txData;

                    if (remainingSendByteCount > 1)
                    {
                        wordToSend |= (unsigned)(*(txData)) << 8U;
                        ++txData;
                    }
                }
                else
                {
                    wordToSend = dummyData;
                }

                base->PUSHTFR = lastCommand | wordToSend;

                SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
                remainingSendByteCount = 0;

                while (remainingReceiveByteCount > 0)
                {
                    if (SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag)
                    {
                        wordReceived = SPI_ReadData(base);

                        if (remainingReceiveByteCount != 1)
                        {
                            if (rxData != NULL)
                            {
                                *(rxData) = wordReceived;
                                ++rxData;
                                *(rxData) = wordReceived >> 8;
                                ++rxData;
                            }
                            remainingReceiveByteCount -= 2;
                        }
                        else
                        {
                            if (rxData != NULL)
                            {
                                *(rxData) = wordReceived;
                                ++rxData;
                            }
                            remainingReceiveByteCount--;
                        }
                        SPI_ClearStatusFlags(base, sSPI_RxFifoDrainRequestFlag);
                    }
                }
            }
            else
            {
                /*Wait until Tx Fifo is not full*/
                while (!(SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag))
                {
                    SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
                }

                if (txData != NULL)
                {
                    wordToSend = *(txData);
                    ++txData;
                    wordToSend |= (unsigned)(*(txData)) << 8U;
                    ++txData;
                }
                else
                {
                    wordToSend = dummyData;
                }
                base->PUSHTFR = command | wordToSend;
                remainingSendByteCount -= 2;

                SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

                if (SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag)
                {
                    wordReceived = SPI_ReadData(base);

                    if (rxData != NULL)
                    {
                        *rxData = wordReceived;
                        ++rxData;
                        *rxData = wordReceived >> 8;
                        ++rxData;
                    }
                    remainingReceiveByteCount -= 2;

                    SPI_ClearStatusFlags(base, sSPI_RxFifoDrainRequestFlag);
                }
            }
        }
    }

    return sStatus_Success;
}
/*Transactional APIs -- Master*/

void SPI_MasterCreateHandle(SPI_Type *base,
                             spi_master_handle_t *handle,
                             spi_master_transfer_callback_t callback,
                             void *userData)
{
    assert(handle);

    /* Zero the handle. */
    memset(handle, 0, sizeof(*handle));

    g_spiHandle[SPI_GetInstance(base)] = handle;

    handle->callback = callback;
    handle->userData = userData;
}

static void SPI_MasterPrepareTransfer(SPI_Type *base, spi_master_handle_t *handle, spi_transfer_t *transfer)
{
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
}

sstat_t SPI_MasterTransferNonBlocking(SPI_Type *base, spi_master_handle_t *handle, spi_transfer_t *transfer)
{
    assert(handle && transfer);

    /* If the transfer count is zero, then return immediately.*/
    if (transfer->dataSize == 0)
    {
        return sStatus_InvalidArgument;
    }

    /* Check that we're not busy.*/
    if (handle->state == sSPI_Busy)
    {
        return sStatus_SPI_Busy;
    }

    handle->state = sSPI_Busy;

    SPI_MasterPrepareTransfer(base, handle, transfer);
    SPI_StartTransfer(base);

    /* Enable the NVIC for spi peripheral. */
    EnableIRQ(s_spiIRQ[SPI_GetInstance(base)]);

    SPI_MasterFillUpTxFifo(base, handle);

    /* RX FIFO Drain request: RFDF_RE to enable RFDF interrupt
    * Since SPI is a synchronous interface, we only need to enable the RX interrupt.
    * The IRQ handler will get the status of RX and TX interrupt flags.
    */
    s_spiMasterIsr = SPI_MasterHandleInterrupt;

    SPI_EnableInterrupts(base, sSPI_RxFifoDrainRequestInterruptEnable);

    return sStatus_Success;
}

static void SPI_MasterCompleteTransfer(SPI_Type *base, spi_master_handle_t *handle)
{
    /* Disable interrupt requests*/
    SPI_DisableInterrupts(base, sSPI_RxFifoDrainRequestInterruptEnable | sSPI_TxFifoFillRequestInterruptEnable);

    sstat_t status = 0;
    if (handle->state == sSPI_Error)
    {
        status = sStatus_SPI_Error;
    }
    else
    {
        status = sStatus_Success;
    }

    if (handle->callback)
    {
        handle->callback(base, handle, status, handle->userData);
    }

    /* The transfer is complete.*/
    handle->state = sSPI_Idle;
}

static void SPI_MasterFillUpTxFifo(SPI_Type *base, spi_master_handle_t *handle)
{
    uint16_t wordToSend = 0;
    uint8_t dummyData = SPI_MASTER_DUMMY_DATA;

    /* If bits/frame is greater than one byte */
    if (handle->bitsPerFrame > 8)
    {
        /* Fill the fifo until it is full or until the send word count is 0 or until the difference
        * between the remainingReceiveByteCount and remainingSendByteCount equals the FIFO depth.
        * The reason for checking the difference is to ensure we only send as much as the
        * RX FIFO can receive.
        * For this case where bitsPerFrame > 8, each entry in the FIFO contains 2 bytes of the
        * send data, hence the difference between the remainingReceiveByteCount and
        * remainingSendByteCount must be divided by 2 to convert this difference into a
        * 16-bit (2 byte) value.
        */
        while ((SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag) &&
               ((handle->remainingReceiveByteCount - handle->remainingSendByteCount) / 2 < handle->fifoSize))
        {
            if (handle->remainingSendByteCount <= 2)
            {
                if (handle->txData)
                {
                    if (handle->remainingSendByteCount == 1)
                    {
                        wordToSend = *(handle->txData);
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
                    wordToSend = dummyData;
                }
                handle->remainingSendByteCount = 0;
                base->PUSHTFR = handle->lastCommand | wordToSend;
            }
            /* For all words except the last word */
            else
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
                    wordToSend = dummyData;
                }
                handle->remainingSendByteCount -= 2; /* decrement remainingSendByteCount by 2 */
                base->PUSHTFR = handle->command | wordToSend;
            }

            /* Try to clear the TFFF; if the TX FIFO is full this will clear */
            SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

            /* exit loop if send count is zero, else update local variables for next loop */
            if (handle->remainingSendByteCount == 0)
            {
                break;
            }
        } /* End of TX FIFO fill while loop */
    }
    /* Optimized for bits/frame less than or equal to one byte. */
    else
    {
        /* Fill the fifo until it is full or until the send word count is 0 or until the difference
        * between the remainingReceiveByteCount and remainingSendByteCount equals the FIFO depth.
        * The reason for checking the difference is to ensure we only send as much as the
        * RX FIFO can receive.
        */
        while ((SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag) &&
               ((handle->remainingReceiveByteCount - handle->remainingSendByteCount) < handle->fifoSize))
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
                base->PUSHTFR = handle->lastCommand | wordToSend;
            }
            else
            {
                base->PUSHTFR = handle->command | wordToSend;
            }

            /* Try to clear the TFFF; if the TX FIFO is full this will clear */
            SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

            --handle->remainingSendByteCount;

            /* exit loop if send count is zero, else update local variables for next loop */
            if (handle->remainingSendByteCount == 0)
            {
                break;
            }
        }
    }
}

void SPI_MasterAbortTransfer(SPI_Type *base, spi_master_handle_t *handle)
{
    SPI_StopTransfer(base);

    /* Disable interrupt requests*/
    SPI_DisableInterrupts(base, sSPI_RxFifoDrainRequestInterruptEnable | sSPI_TxFifoFillRequestInterruptEnable);

    handle->state = sSPI_Idle;
}

void SPI_MasterHandleInterrupt(SPI_Type *base, spi_master_handle_t *handle)
{
    /* RECEIVE IRQ handler: Check read buffer only if there are remaining bytes to read. */
    if (handle->remainingReceiveByteCount)
    {
        /* Check read buffer.*/
        uint16_t wordReceived; /* Maximum supported data bit length in master mode is 16-bits */
       
        /* Optimized for bits/frame less than or equal to one byte. */
        //while ((SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag) && ((SPI_GetStatusFlags(base) & 0xF0) == 0x10))
        while (SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag) 
        {
            wordReceived = SPI_ReadData(base);
            /* clear the rx fifo drain request, needed for non-DMA applications as this flag
            * will remain set even if the rx fifo is empty. By manually clearing this flag, it
            * either remain clear if no more data is in the fifo, or it will set if there is
            * more data in the fifo.
            */
            SPI_ClearStatusFlags(base, sSPI_RxFifoDrainRequestFlag);

            /* Store read bytes into rx buffer only if a buffer pointer was provided */
            if (handle->rxData)
            {
                *handle->rxData = wordReceived;
                ++handle->rxData;
            }

            --handle->remainingReceiveByteCount;

            if (handle->remainingReceiveByteCount == 0)
            {
                break;
            }
            
            //base->MCFGR |= SPI_MCFGR_RXFC_SET(1); // flush the RX FIFO
        } /* End of RX FIFO drain while loop */
    }

    /* Check write buffer. We always have to send a word in order to keep the transfer
    * moving. So if the caller didn't provide a send buffer, we just send a zero.
    */
    if (handle->remainingSendByteCount)
    {
        SPI_MasterFillUpTxFifo(base, handle);
    }

    /* Check if we're done with this transfer.*/
    if ((handle->remainingSendByteCount == 0) && (handle->remainingReceiveByteCount == 0))
    {
        /* Complete the transfer and disable the interrupts */
        SPI_MasterCompleteTransfer(base, handle);
    }
}

/*Transactional APIs -- Slave*/
void SPI_SlaveCreateHandle(SPI_Type *base,
                            spi_slave_handle_t *handle,
                            spi_slave_transfer_callback_t callback,
                            void *userData)
{
    assert(handle);

    /* Zero the handle. */
    memset(handle, 0, sizeof(*handle));

    g_spiHandle[SPI_GetInstance(base)] = handle;

    handle->callback = callback;
    handle->userData = userData;
}

sstat_t SPI_SlaveTransferNonBlocking(SPI_Type *base, spi_slave_handle_t *handle, spi_transfer_t *transfer)
{
    assert(handle && transfer);

    /* If receive length is zero */
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
    handle->state = sSPI_Busy;

    /* Enable the NVIC for spi peripheral. */
    EnableIRQ(s_spiIRQ[SPI_GetInstance(base)]);

    /* Store transfer information */
    handle->txData = transfer->txData;
    handle->rxData = transfer->rxData;
    handle->remainingSendByteCount = transfer->dataSize;
    handle->remainingReceiveByteCount = transfer->dataSize;

    handle->errorCount = 0;

    uint8_t whichCtar = (transfer->configFlags & SPI_SLAVE_CTAR_MASK) >> SPI_SLAVE_CTAR_SHIFT;
    handle->bitsPerFrame =
        (((base->CLKTAR_SLV[whichCtar]) & SPI_CLKTAR_SLV_FSZ_MASK) >> SPI_CLKTAR_SLV_FSZ_SHIFT) + 1;

    SPI_StopTransfer(base);

    SPI_FlushFifo(base, true, true);
    SPI_ClearStatusFlags(base, sSPI_AllStatusFlag);

    SPI_StartTransfer(base);

    /* Prepare data to transmit */
    SPI_SlaveFillUpTxFifo(base, handle);

    s_spiSlaveIsr = SPI_SlaveHandleInterrupt;

    /* Enable RX FIFO drain request, the slave only use this interrupt */
    SPI_EnableInterrupts(base, sSPI_RxFifoDrainRequestInterruptEnable);

    if (handle->rxData)
    {
        /* RX FIFO overflow request enable */
        SPI_EnableInterrupts(base, sSPI_RxFifoOverflowInterruptEnable);
    }
    if (handle->txData)
    {
        /* TX FIFO underflow request enable */
        SPI_EnableInterrupts(base, sSPI_TxFifoUnderflowInterruptEnable);
        SPI_EnableInterrupts(base, sSPI_TxFifoFillRequestInterruptEnable);
    }

    return sStatus_Success;
}

static void SPI_SlaveFillUpTxFifo(SPI_Type *base, spi_slave_handle_t *handle)
{
    uint16_t transmitData = 0;

    /* Service the transmitter, if transmit buffer provided, transmit the data,
    * else transmit dummy pattern
    */
    while (SPI_GetStatusFlags(base) & sSPI_TxFifoFillRequestFlag)
    {
        /* Transmit data */
        if (handle->remainingSendByteCount > 0)
        {
            /* Have data to transmit, update the transmit data and push to FIFO */
            if (handle->bitsPerFrame <= 8)
            {
                /* bits/frame is 1 byte */
                if (handle->txData)
                {
                    /* Update transmit data and transmit pointer */
                    transmitData = *handle->txData;
                    handle->txData++;
                }

                /* Decrease remaining dataSize */
                --handle->remainingSendByteCount;
            }
        }
        else
        {
            break;
        }

        /* Write the data to the spi data register */
        base->PUSHTFR_SLV = transmitData;

        /* Try to clear TXFFF by writing a one to it; it will not clear if TX FIFO not full */
        SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);
    }
}

static void SPI_SlaveCompleteTransfer(SPI_Type *base, spi_slave_handle_t *handle)
{
    /* Disable interrupt requests */
    SPI_DisableInterrupts(base, sSPI_TxFifoUnderflowInterruptEnable | sSPI_TxFifoFillRequestInterruptEnable |
                                     sSPI_RxFifoOverflowInterruptEnable | sSPI_RxFifoDrainRequestInterruptEnable);

    /* The transfer is complete. */
    handle->txData = NULL;
    handle->rxData = NULL;
    handle->remainingReceiveByteCount = 0;
    handle->remainingSendByteCount = 0;

    sstat_t status = 0;
    if (handle->state == sSPI_Error)
    {
        status = sStatus_SPI_Error;
    }
    else
    {
        status = sStatus_Success;
    }

    if (handle->callback)
    {
        handle->callback(base, handle, status, handle->userData);
    }

    handle->state = sSPI_Idle;
}

void SPI_SlaveAbortTransfer(SPI_Type *base, spi_slave_handle_t *handle)
{
    SPI_StopTransfer(base);

    /* Disable interrupt requests */
    SPI_DisableInterrupts(base, sSPI_TxFifoUnderflowInterruptEnable | sSPI_TxFifoFillRequestInterruptEnable |
                                     sSPI_RxFifoOverflowInterruptEnable | sSPI_RxFifoDrainRequestInterruptEnable);

    handle->state = sSPI_Idle;
    handle->remainingSendByteCount = 0;
    handle->remainingReceiveByteCount = 0;
}

void SPI_SlaveHandleInterrupt(SPI_Type *base, spi_slave_handle_t *handle)
{
    uint8_t dummyPattern = SPI_SLAVE_DUMMY_DATA;
    uint32_t dataReceived;
    uint32_t dataSend = 0;

    /* Because SPI protocol is synchronous, the number of bytes that that slave received from the
    * master is the actual number of bytes that the slave transmitted to the master. So we only
    * monitor the received dataSize to know when the transfer is complete.
    */
    if (handle->remainingReceiveByteCount > 0)
    {
        while (SPI_GetStatusFlags(base) & sSPI_RxFifoDrainRequestFlag)
        {
            /* Have received data in the buffer. */
            dataReceived = base->POPRFR;
            /*Clear the rx fifo drain request, needed for non-DMA applications as this flag
            * will remain set even if the rx fifo is empty. By manually clearing this flag, it
            * either remain clear if no more data is in the fifo, or it will set if there is
            * more data in the fifo.
            */
            SPI_ClearStatusFlags(base, sSPI_RxFifoDrainRequestFlag);

            /* If bits/frame is one byte */
            if (handle->bitsPerFrame <= 8)
            {
                if (handle->rxData)
                {
                    /* Receive buffer is not null, store data into it */
                    *handle->rxData = dataReceived;
                    ++handle->rxData;
                }
                /* Descrease remaining receive byte count */
                --handle->remainingReceiveByteCount;

                if (handle->remainingSendByteCount > 0)
                {
                    if (handle->txData)
                    {
                        dataSend = *handle->txData;
                        ++handle->txData;
                    }
                    else
                    {
                        //dataSend = dummyPattern;
                    }

                    --handle->remainingSendByteCount;
                    /* Write the data to the spi data register */
                    base->PUSHTFR_SLV = dataSend;
                }
            }

            /* Try to clear TXFFF by writing a one to it; it will not clear if TX FIFO not full */
            SPI_ClearStatusFlags(base, sSPI_TxFifoFillRequestFlag);

            if (handle->remainingReceiveByteCount == 0)
            {
                break;
            }
        }
    }
    //if(handle->remainingSendByteCount)
    //{
    //    SPI_SlaveFillUpTxFifo(base, handle);
    //}
    
    /* Check if remaining receive byte count matches user request */
    if ((handle->remainingReceiveByteCount == 0) || (handle->state == sSPI_Error))
    {
        /* Other cases, stop the transfer. */
        SPI_SlaveCompleteTransfer(base, handle);
        return;
    }

    /* Catch tx fifo underflow conditions, service only if tx under flow interrupt enabled */
    if ((SPI_GetStatusFlags(base) & sSPI_TxFifoUnderflowFlag) && (base->IRSER & SPI_IRSER_TXFURE_MASK))
    {
        SPI_ClearStatusFlags(base, sSPI_TxFifoUnderflowFlag);
        /* Change state to error and clear flag */
        if (handle->txData)
        {
            handle->state = sSPI_Error;
        }
        handle->errorCount++;
    }
    /* Catch rx fifo overflow conditions, service only if rx over flow interrupt enabled */
    if ((SPI_GetStatusFlags(base) & sSPI_RxFifoOverflowFlag) && (base->IRSER & SPI_IRSER_RXFORE_MASK))
    {
        SPI_ClearStatusFlags(base, sSPI_RxFifoOverflowFlag);
        /* Change state to error and clear flag */
        if (handle->txData)
        {
            handle->state = sSPI_Error;
        }
        handle->errorCount++;
    }
}

static void SPI_CommonIRQHandler(SPI_Type *base, void *param)
{
    if (SPI_IsMaster(base))
    {
        s_spiMasterIsr(base, param);
    }
    else
    {
        s_spiSlaveIsr(base, param);
    }
}


#if 0
void SPI1_IRQHandler(void)
{
    //assert(g_spiHandle[0]);
    SPI_CommonIRQHandler(SPI1, g_spiHandle[0]);
}

void SPI2_IRQHandler(void)
{
    //assert(g_spiHandle[1]);
    SPI_CommonIRQHandler(SPI2, g_spiHandle[1]);
}
#endif

#if defined(SPI3)
void SPI3_IRQHandler(void)
{
    //assert(g_spiHandle[2]);
    SPI_CommonIRQHandler(SPI3, g_spiHandle[2]);
}
#endif

#if defined(SPI4)
void SPI4_IRQHandler(void)
{
    assert(g_spiHandle[3]);
    SPI_CommonIRQHandler(SPI4, g_spiHandle[3]);
}
#endif


#if (SPI_COUNT > 4)
#error "Should write the SPIx_DriverIRQHandler function that instance greater than 5 !"
#endif
