/*
  ******************************************************************************
  * @file           : sci.h
  * @brief          : sci driver header file
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
#ifndef _SCI_H_
#define _SCI_H_

#include "driver_common.h"
/*!
 * @addtogroup SCI_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define SCI_NUMBER   6
#define SCI_FIFO_SIZEn(x) \
    (((x) == SCI1) ? (8) : \
    (((x) == SCI2) ? (8) : \
    (((x) == SCI3) ? (8) : \
    (((x) == SCI4) ? (8) : \
    (((x) == SCI5) ? (1) : \
    (((x) == SCI6) ? (1) : (-1)))))))

/*! @brief Retry times for waiting flag. */
#ifndef UART_RETRY_TIMES
#define UART_RETRY_TIMES 0U /* Defining to zero means to keep waiting for the flag until it is assert/deassert. */
#endif

/*! @brief Error codes for the SCI driver. */
enum
{
    sStatus_SCI_TxBusy                  = MAKE_STATUS(sStatusGroup_SCI, 0), /*!< TX busy */
    sStatus_SCI_RxBusy                  = MAKE_STATUS(sStatusGroup_SCI, 1), /*!< RX busy */
    sStatus_SCI_TxIdle                  = MAKE_STATUS(sStatusGroup_SCI, 2), /*!< SCI transmitter is idle. */
    sStatus_SCI_RxIdle                  = MAKE_STATUS(sStatusGroup_SCI, 3), /*!< SCI receiver is idle. */
    sStatus_SCI_TxWatermarkTooLarge     = MAKE_STATUS(sStatusGroup_SCI, 4), /*!< TX FIFO watermark too large  */
    sStatus_SCI_RxWatermarkTooLarge     = MAKE_STATUS(sStatusGroup_SCI, 5), /*!< RX FIFO watermark too large  */
    sStatus_SCI_FlagCannotClearManually = MAKE_STATUS(sStatusGroup_SCI, 6), /*!< Some flag can't manually clear */
    sStatus_SCI_Error                   = MAKE_STATUS(sStatusGroup_SCI, 7), /*!< Error happens on SCI. */
    sStatus_SCI_RxRingBufferOverrun =
        MAKE_STATUS(sStatusGroup_SCI, 8), /*!< SCI RX software ring buffer overrun. */
    sStatus_SCI_RxHardwareOverrun = MAKE_STATUS(sStatusGroup_SCI, 9),  /*!< SCI RX receiver overrun. */
    sStatus_SCI_NoiseError        = MAKE_STATUS(sStatusGroup_SCI, 10), /*!< SCI noise error. */
    sStatus_SCI_FramingError      = MAKE_STATUS(sStatusGroup_SCI, 11), /*!< SCI framing error. */
    sStatus_SCI_ParityError       = MAKE_STATUS(sStatusGroup_SCI, 12), /*!< SCI parity error. */
    sStatus_SCI_BaudrateNotSupport =
        MAKE_STATUS(sStatusGroup_SCI, 13), /*!< Baudrate is not support in current clock source */
    sStatus_SCI_IdleLineDetected = MAKE_STATUS(sStatusGroup_SCI, 14), /*!< IDLE flag. */
    sStatus_SCI_Timeout          = MAKE_STATUS(sStatusGroup_SCI, 15), /*!< SCI times out. */
};

/*! @brief SCI parity mode. */
typedef enum _SCI_parity_mode
{
    sSCI_ParityDisabled = 0x0U, /*!< Parity disabled */
    sSCI_ParityEven     = 0x2U, /*!< Parity enabled, type even, bit setting: PE|PT = 10 */
    sSCI_ParityOdd      = 0x3U, /*!< Parity enabled, type odd,  bit setting: PE|PT = 11 */
} SCI_parity_mode_t;


/*! @brief SCI stop bit count. */
typedef enum _SCI_stop_bit_count
{
    sSCI_OneStopBit = 0U, /*!< One stop bit */
    sSCI_TwoStopBit = 1U, /*!< Two stop bits */
} SCI_stop_bit_count_t;

/*! @brief SCI transmit CTS source. */
typedef enum _SCI_transmit_cts_source
{
    sSCI_CtsSourcePin         = 0U, /*!< CTS resource is the SCI_CTS pin. */
    sSCI_CtsSourceMatchResult = 1U, /*!< CTS resource is the match result. */
} SCI_transmit_cts_source_t;

/*! @brief SCI transmit CTS configure. */
typedef enum _SCI_transmit_cts_config
{
    sSCI_CtsSampleAtStart = 0U, /*!< CTS input is sampled at the start of each character. */
    sSCI_CtsSampleAtIdle  = 1U, /*!< CTS input is sampled when the transmitter is idle */
} SCI_transmit_cts_config_t;

/*! @brief SCI idle flag type defines when the receiver starts counting. */
typedef enum _SCI_idle_type_select
{
    sSCI_IdleTypeStartBit = 0U, /*!< Start counting after a valid start bit. */
    sSCI_IdleTypeStopBit  = 1U, /*!< Start counting after a stop bit. */
} SCI_idle_type_select_t;

/*! @brief SCI idle detected configuration.
 *  This structure defines the number of idle characters that must be received before
 *  the IDLE flag is set.
 */
typedef enum _SCI_idle_config
{
    sSCI_IdleCharacter1   = 0U, /*!< the number of idle characters. */
    sSCI_IdleCharacter2   = 1U, /*!< the number of idle characters. */
    sSCI_IdleCharacter4   = 2U, /*!< the number of idle characters. */
    sSCI_IdleCharacter8   = 3U, /*!< the number of idle characters. */
    sSCI_IdleCharacter16  = 4U, /*!< the number of idle characters. */
    sSCI_IdleCharacter32  = 5U, /*!< the number of idle characters. */
    sSCI_IdleCharacter64  = 6U, /*!< the number of idle characters. */
    sSCI_IdleCharacter128 = 7U, /*!< the number of idle characters. */
} SCI_idle_config_t;

/*!
 * @brief SCI interrupt configuration structure, default settings all disabled.
 *
 * This structure contains the settings for all SCI interrupt configurations.
 */
enum _SCI_interrupt_enable
{
    sSCI_LinBreakInterruptEnable = (SCI_CNFG_LBDIE_MASK >> 8), /*!< LIN break detect. */
    sSCI_RxActiveEdgeInterruptEnable         = (SCI_CNFG_RXEDGIE_MASK >> 8), /*!< Receive Active Edge. */
    sSCI_TxDataRegEmptyInterruptEnable       = (SCI_CTRL_TXIE_MASK),          /*!< Transmit data register empty. */
    sSCI_TransmissionCompleteInterruptEnable = (SCI_CTRL_TCFIE_MASK),         /*!< Transmission complete. */
    sSCI_RxDataRegFullInterruptEnable        = (SCI_CTRL_RXIE_MASK),          /*!< Receiver data register full. */
    sSCI_IdleLineInterruptEnable             = (SCI_CTRL_IDFIE_MASK),         /*!< Idle line. */
    sSCI_RxOverrunInterruptEnable            = (SCI_CTRL_OVIE_MASK),         /*!< Receiver Overrun. */
    sSCI_NoiseErrorInterruptEnable           = (SCI_CTRL_NFIE_MASK),         /*!< Noise error flag. */
    sSCI_FramingErrorInterruptEnable         = (SCI_CTRL_FEFIE_MASK),         /*!< Framing error flag. */
    sSCI_ParityErrorInterruptEnable          = (SCI_CTRL_PEFIE_MASK),         /*!< Parity error flag. */
    sSCI_TxFifoOverflowInterruptEnable  = (SCI_FCTL_TXOVIE_MASK >> 8), /*!< Transmit FIFO Overflow. */
    sSCI_RxFifoUnderflowInterruptEnable = (SCI_FCTL_RXUNIE_MASK >> 8), /*!< Receive FIFO Underflow. */
};

/*!
 * @brief SCI status flags.
 *
 * This provides constants for the SCI status flags for use in the SCI functions.
 */
enum _SCI_flags
{
    sSCI_TxDataRegEmptyFlag =
        (SCI_STATUS_TDREF_MASK), /*!< Transmit data register empty flag, sets when transmit buffer is empty */
    sSCI_TransmissionCompleteFlag =
        (SCI_STATUS_TCF_MASK), /*!< Transmission complete flag, sets when transmission activity complete */
    sSCI_RxDataRegFullFlag =
        (SCI_STATUS_RDFF_MASK), /*!< Receive data register full flag, sets when the receive data buffer is full */
    sSCI_IdleLineFlag  = (SCI_STATUS_IDLF_MASK), /*!< Idle line detect flag, sets when idle line detected */
    sSCI_RxOverrunFlag = (SCI_STATUS_ROF_MASK),   /*!< Receive Overrun, sets when new data is received before data is
                                                        read from receive register */
    sSCI_NoiseErrorFlag = (SCI_STATUS_NOIF_MASK),  /*!< Receive takes 3 samples of each received bit.  If any of these
                                                        samples differ, noise flag sets */
    sSCI_FramingErrorFlag =
        (SCI_STATUS_FEF_MASK), /*!< Frame error flag, sets if logic 0 was detected where stop bit expected */
    sSCI_ParityErrorFlag = (SCI_STATUS_PEF_MASK), /*!< If parity enabled, sets upon parity error detection */
    sSCI_LinBreakFlag = (int)(SCI_STATUS_LBDIF_MASK), /*!< LIN break detect interrupt flag, sets when LIN break
                                                         char detected and LIN circuit enabled */
    sSCI_RxActiveEdgeFlag =
        (SCI_STATUS_RXEDGIF_MASK), /*!< Receive pin active edge interrupt flag, sets when active edge detected */
    sSCI_RxActiveFlag =
        (SCI_STATUS_REAF_MASK), /*!< Receiver Active Flag (RAF), sets at beginning of valid start bit */
    sSCI_DataMatch1Flag = SCI_STATUS_M1F_MASK, /*!< The next character to be read from SCI_DATA matches MA1*/
    sSCI_DataMatch2Flag = SCI_STATUS_M2F_MASK, /*!< The next character to be read from SCI_DATA matches MA2*/
    sSCI_NoiseErrorInRxDataRegFlag =
        (SCI_DATA_NOISE_MASK >> 10), /*!< NOISY bit, sets if noise detected in current data word */
    sSCI_ParityErrorInRxDataRegFlag =
        (SCI_DATA_PARERR_MASK >> 10), /*!< PARITY bit, sets if noise detected in current data word */
    sSCI_TxFifoEmptyFlag = (SCI_FCTL_TFEMPT_MASK >> 16), /*!< TXEMPT bit, sets if transmit buffer is empty */
    sSCI_RxFifoEmptyFlag = (SCI_FCTL_RFEMPT_MASK >> 16), /*!< RXEMPT bit, sets if receive buffer is empty */
    sSCI_TxFifoOverflowFlag =
        (SCI_FCTL_TBOVF_MASK >> 16), /*!< TXOF bit, sets if transmit buffer overflow occurred */
    sSCI_RxFifoUnderflowFlag =
        (SCI_FCTL_RBUNF_MASK >> 16), /*!< RXUF bit, sets if receive buffer underflow occurred */
};

/*! @brief UART peripheral clock source */
typedef enum _hal_uart_clock_source
{
    kHAL_busClock =        0U,  /*!< Bus Clock */
    kHAL_iosc8M   =        1U,  /*!< Internal 8M IRC */
    kHAL_xosc16M  =        2U,  /*!< External 16M OSC */
    kHAL_ungatedBusClock = 3U,  /*!< Ungated Bus Clock */
} hal_uart_clock_source;

/*! @brief SCI configuration structure. */
typedef struct _SCI_config
{
    uint32_t baudRate_Bps;            /*!< SCI baud rate  */
    SCI_parity_mode_t parityMode;  /*!< Parity mode, disabled (default), even, odd */
//    SCI_data_bits_t dataBitsCount; /*!< Data bits count, eight (default), seven */
    bool isMsb;                       /*!< Data bits order, LSB (default), MSB */
    SCI_stop_bit_count_t stopBitCount; /*!< Number of stop bits, 1 stop bit (default) or 2 stop bits  */
    uint8_t txFifoWatermark; /*!< TX FIFO watermark */
    uint8_t rxFifoWatermark; /*!< RX FIFO watermark */
    bool enableRxRTS;                         /*!< RX RTS enable */
    bool enableTxCTS;                         /*!< TX CTS enable */
    SCI_transmit_cts_source_t txCtsSource; /*!< TX CTS source */
    SCI_transmit_cts_config_t txCtsConfig; /*!< TX CTS configure */
    SCI_idle_type_select_t rxIdleType; /*!< RX IDLE type. */
    SCI_idle_config_t rxIdleConfig;    /*!< RX IDLE configuration. */
    bool enableTx;                        /*!< Enable TX */
    bool enableRx;                        /*!< Enable RX */
    bool loopMode;                        /*!< Use loop mode to test */
    hal_uart_clock_source clock_source;
} SCI_config_t;

/*! @brief SCI transfer structure. */
typedef struct _SCI_transfer
{
    uint8_t *data;   /*!< The buffer of data to be transfer.*/
    size_t dataSize; /*!< The byte count to be transfer. */
} SCI_transfer_t;

/* Forward declaration of the handle typedef. */
typedef struct _SCI_handle SCI_handle_t;

/*! @brief SCI transfer callback function. */
typedef void (*SCI_transfer_callback_t)(SCI_TypeDef *base, SCI_handle_t *handle, sstat_t status, void *userData);

/*! @brief SCI handle structure. */
struct _SCI_handle
{
    uint8_t *volatile txData;   /*!< Address of remaining data to send. */
    volatile size_t txDataSize; /*!< Size of the remaining data to send. */
    size_t txDataSizeAll;       /*!< Size of the data to send out. */
    uint8_t *volatile rxData;   /*!< Address of remaining data to receive. */
    volatile size_t rxDataSize; /*!< Size of the remaining data to receive. */
    size_t rxDataSizeAll;       /*!< Size of the data to receive. */

    uint8_t *rxRingBuffer;              /*!< Start address of the receiver ring buffer. */
    size_t rxRingBufferSize;            /*!< Size of the ring buffer. */
    volatile uint16_t rxRingBufferHead; /*!< Index for the driver to store received data into ring buffer. */
    volatile uint16_t rxRingBufferTail; /*!< Index for the user to get data from the ring buffer. */

    SCI_transfer_callback_t callback; /*!< Callback function. */
    void *userData;                      /*!< SCI callback function parameter.*/

    volatile uint8_t txState; /*!< TX transfer state. */
    volatile uint8_t rxState; /*!< RX transfer state. */

};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */


/*!
 * @brief Resets the SCI using software.
 *
 * This function resets all internal logic and registers except the Global Register.
 * Remains set until cleared by software.
 *
 * @param base SCI peripheral base address.
 */
static inline void SCI_SoftwareReset(SCI_TypeDef *base)
{
    int32_t scibase = (int32_t)base;
    if(scibase == SCI1_BASE)
    {
        SYSCTRL->SOFTRST1 |= SYSCTRL_SOFTRST1_SCI1RST_MASK;
        SYSCTRL->SOFTRST1 &= ~SYSCTRL_SOFTRST1_SCI1RST_MASK;
    }
    else if(scibase == SCI2_BASE)
    {
        SYSCTRL->SOFTRST1 |= SYSCTRL_SOFTRST1_SCI2RST_MASK;
        SYSCTRL->SOFTRST1 &= ~SYSCTRL_SOFTRST1_SCI2RST_MASK;
    }
    else if(scibase == SCI3_BASE)
    {
        SYSCTRL->SOFTRST1 |= SYSCTRL_SOFTRST1_SCI3RST_MASK;
        SYSCTRL->SOFTRST1 &= ~SYSCTRL_SOFTRST1_SCI3RST_MASK;
    }
    else if(scibase == SCI4_BASE)
    {
        SYSCTRL->SOFTRST1 |= SYSCTRL_SOFTRST1_SCI4RST_MASK;
        SYSCTRL->SOFTRST1 &= ~SYSCTRL_SOFTRST1_SCI4RST_MASK;
    }
    else if(scibase == SCI5_BASE)
    {
        SYSCTRL->SOFTRST1 |= SYSCTRL_SOFTRST1_SCI5RST_MASK;
        SYSCTRL->SOFTRST1 &= ~SYSCTRL_SOFTRST1_SCI5RST_MASK;
    }
    else if(scibase == SCI6_BASE)
    {
        SYSCTRL->SOFTRST1 |= SYSCTRL_SOFTRST1_SCI6RST_MASK;
        SYSCTRL->SOFTRST1 &= ~SYSCTRL_SOFTRST1_SCI6RST_MASK;
    }
}
/* @} */

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes an SCI instance with the user configuration structure and the peripheral clock.
 *
 * This function configures the SCI module with user-defined settings. Call the SCI_GetDefaultConfig() function
 * to configure the configuration structure and get the default configuration.
 * The example below shows how to use this API to configure the SCI.
 * @code
 *  SCI_config_t SCIConfig;
 *  SCIConfig.baudRate_Bps = 115200U;
 *  SCIConfig.parityMode = sSCI_ParityDisabled;
 *  SCIConfig.dataBitsCount = sSCI_EightDataBits;
 *  SCIConfig.isMsb = false;
 *  SCIConfig.stopBitCount = sSCI_OneStopBit;
 *  SCIConfig.txFifoWatermark = 0;
 *  SCIConfig.rxFifoWatermark = 1;
 *  SCI_Init(SCI1, &SCIConfig, 20000000U);
 * @endcode
 *
 * @param base SCI peripheral base address.
 * @param config Pointer to a user-defined configuration structure.
 * @param srcClock_Hz SCI clock source frequency in HZ.
 * @retval sStatus_SCI_BaudrateNotSupport Baudrate is not support in current clock source.
 * @retval sStatus_Success SCI initialize succeed
 */
sstat_t SCI_Init(SCI_TypeDef *base, const SCI_config_t *config, uint32_t srcClock_Hz);

/*!
 * @brief Deinitializes a SCI instance.
 *
 * This function waits for transmit to complete, disables TX and RX, and disables the SCI clock.
 *
 * @param base SCI peripheral base address.
 */
void SCI_Deinit(SCI_TypeDef *base);

/*!
 * @brief Gets the default configuration structure.
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
 * @param config Pointer to a configuration structure.
 */
void SCI_GetDefaultConfig(SCI_config_t *config);

/*!
 * @brief Sets the SCI instance baudrate.
 *
 * This function configures the SCI module baudrate. This function is used to update
 * the SCI module baudrate after the SCI module is initialized by the SCI_Init.
 * @code
 *  SCI_SetBaudRate(SCI1, 115200U, 20000000U);
 * @endcode
 *
 * @param base SCI peripheral base address.
 * @param baudRate_Bps SCI baudrate to be set.
 * @param srcClock_Hz SCI clock source frequency in HZ.
 * @retval sStatus_SCI_BaudrateNotSupport Baudrate is not supported in the current clock source.
 * @retval sStatus_Success Set baudrate succeeded.
 */
sstat_t SCI_SetBaudRate(SCI_TypeDef *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz);

/* @} */

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets SCI status flags.
 *
 * This function gets all SCI status flags. The flags are returned as the logical
 * OR value of the enumerators @ref _SCI_flags. To check for a specific status,
 * compare the return value with enumerators in the @ref _SCI_flags.
 * For example, to check whether the TX is empty:
 * @code
 *     if (sSCI_TxDataRegEmptyFlag & SCI_GetStatusFlags(SCI1))
 *     {
 *         ...
 *     }
 * @endcode
 *
 * @param base SCI peripheral base address.
 * @return SCI status flags which are ORed by the enumerators in the _SCI_flags.
 */
uint32_t SCI_GetStatusFlags(SCI_TypeDef *base);

/*!
 * @brief Clears status flags with a provided mask.
 *
 * This function clears SCI status flags with a provided mask. Automatically cleared flags
 * can't be cleared by this function.
 * Flags that can only cleared or set by hardware are:
 *    sSCI_TxDataRegEmptyFlag, sSCI_TransmissionCompleteFlag, sSCI_RxDataRegFullFlag,
 *    sSCI_RxActiveFlag, sSCI_NoiseErrorInRxDataRegFlag, sSCI_ParityErrorInRxDataRegFlag,
 *    sSCI_TxFifoEmptyFlag,sSCI_RxFifoEmptyFlag
 * Note: This API should be called when the Tx/Rx is idle, otherwise it takes no effects.
 *
 * @param base SCI peripheral base address.
 * @param mask the status flags to be cleared. The user can use the enumerators in the
 *  _SCI_status_flag_t to do the OR operation and get the mask.
 * @return 0 succeed, others failed.
 * @retval sStatus_SCI_FlagCannotClearManually The flag can't be cleared by this function but
 *         it is cleared automatically by hardware.
 * @retval sStatus_Success Status in the mask are cleared.
 */
sstat_t SCI_ClearStatusFlags(SCI_TypeDef *base, uint32_t mask);

/* @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables SCI interrupts according to a provided mask.
 *
 * This function enables the SCI interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See the @ref _SCI_interrupt_enable.
 * This examples shows how to enable TX empty interrupt and RX full interrupt:
 * @code
 *     SCI_EnableInterrupts(SCI1,sSCI_TxDataRegEmptyInterruptEnable | sSCI_RxDataRegFullInterruptEnable);
 * @endcode
 *
 * @param base SCI peripheral base address.
 * @param mask The interrupts to enable. Logical OR of the enumeration _uart_interrupt_enable.
 */
void SCI_EnableInterrupts(SCI_TypeDef *base, uint32_t mask);

/*!
 * @brief Disables  SCI interrupts according to a provided mask.
 *
 * This function disables the SCI interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See @ref _SCI_interrupt_enable.
 * This example shows how to disable the TX empty interrupt and RX full interrupt:
 * @code
 *     SCI_DisableInterrupts(SCI1,sSCI_TxDataRegEmptyInterruptEnable | sSCI_RxDataRegFullInterruptEnable);
 * @endcode
 *
 * @param base SCI peripheral base address.
 * @param mask The interrupts to disable. Logical OR of @ref _SCI_interrupt_enable.
 */
void SCI_DisableInterrupts(SCI_TypeDef *base, uint32_t mask);

/*!
 * @brief Gets enabled SCI interrupts.
 *
 * This function gets the enabled SCI interrupts. The enabled interrupts are returned
 * as the logical OR value of the enumerators @ref _SCI_interrupt_enable. To check
 * a specific interrupt enable status, compare the return value with enumerators
 * in @ref _SCI_interrupt_enable.
 * For example, to check whether the TX empty interrupt is enabled:
 * @code
 *     uint32_t enabledInterrupts = SCI_GetEnabledInterrupts(SCI1);
 *
 *     if (sSCI_TxDataRegEmptyInterruptEnable & enabledInterrupts)
 *     {
 *         ...
 *     }
 * @endcode
 *
 * @param base SCI peripheral base address.
 * @return SCI interrupt flags which are logical OR of the enumerators in @ref _SCI_interrupt_enable.
 */
uint32_t SCI_GetEnabledInterrupts(SCI_TypeDef *base);


/*!
 * @brief Gets the SCI data register address.
 *
 * This function returns the SCI data register address, which is mainly used by the DMA/eDMA.
 *
 * @param base SCI peripheral base address.
 * @return SCI data register addresses which are used both by the transmitter and receiver.
 */
static inline uint32_t SCI_GetDataRegisterAddress(SCI_TypeDef *base)
{
    return (uint32_t) & (base->SCIDATA);
}

/*!
 * @brief Enables or disables the SCI transmitter DMA request.
 *
 * This function enables or disables the transmit data register empty flag, STAT[TDRE], to generate DMA requests.
 *
 * @param base SCI peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void SCI_EnableTxDMA(SCI_TypeDef *base, bool enable)
{
    if (enable)
    {
        base->SCICNFG |= SCI_CNFG_TDMAEN_MASK;
    }
    else
    {
        base->SCICNFG &= ~SCI_CNFG_TDMAEN_MASK;
    }
}

/*!
 * @brief Enables or disables the SCI receiver DMA.
 *
 * This function enables or disables the receiver data register full flag, STAT[RDRF], to generate DMA requests.
 *
 * @param base SCI peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void SCI_EnableRxDMA(SCI_TypeDef *base, bool enable)
{
    if (enable)
    {
        base->SCICNFG |= SCI_CNFG_RDMAEN_MASK;
    }
    else
    {
        base->SCICNFG &= ~SCI_CNFG_RDMAEN_MASK;
    }
}

/* @} */


/*!
 * @name Bus Operations
 * @{
 */

/*!
 * @brief Get the SCI instance from peripheral base address.
 *
 * @param base SCI peripheral base address.
 * @return SCI instance.
 */
uint32_t SCI_GetInstance(SCI_TypeDef *base);

/*!
 * @brief Enables or disables the SCI transmitter.
 *
 * This function enables or disables the SCI transmitter.
 *
 * @param base SCI peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void SCI_EnableTx(SCI_TypeDef *base, bool enable)
{
    if (enable)
    {
        base->SCICTRL |= SCI_CTRL_TXEN_MASK;
    }
    else
    {
        base->SCICTRL &= ~SCI_CTRL_TXEN_MASK;
    }
}

/*!
 * @brief Enables or disables the SCI receiver.
 *
 * This function enables or disables the SCI receiver.
 *
 * @param base SCI peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void SCI_EnableRx(SCI_TypeDef *base, bool enable)
{
    if (enable)
    {
        base->SCICTRL |= SCI_CTRL_RXEN_MASK;
    }
    else
    {
        base->SCICTRL &= ~SCI_CTRL_RXEN_MASK;
    }
}

/*!
 * @brief Writes to the transmitter register.
 *
 * This function writes data to the transmitter register directly. The upper layer must
 * ensure that the TX register is empty or that the TX FIFO has room before calling this function.
 *
 * @param base SCI peripheral base address.
 * @param data Data write to the TX register.
 */
static inline void SCI_WriteByte(SCI_TypeDef *base, uint8_t data)
{
    base->SCIDATA = data;
}

/*!
 * @brief Reads the receiver register.
 *
 * This function reads data from the receiver register directly. The upper layer must
 * ensure that the receiver register is full or that the RX FIFO has data before calling this function.
 *
 * @param base SCI peripheral base address.
 * @return Data read from data register.
 */
static inline uint8_t SCI_ReadByte(SCI_TypeDef *base)
{
    return (uint8_t)(base->SCIDATA);
}

/*!
 * @brief Writes to the transmitter register using a blocking method.
 *
 * This function polls the transmitter register, first waits for the register to be empty or TX FIFO to have room,
 * and writes data to the transmitter buffer, then waits for the dat to be sent out to the bus.
 *
 * @param base SCI peripheral base address.
 * @param data Start address of the data to write.
 * @param length Size of the data to write.
 * @retval sStatus_SCI_Timeout Transmission timed out and was aborted.
 * @retval sStatus_Success Successfully wrote all data.
 */
sstat_t SCI_WriteBlocking(SCI_TypeDef *base, const uint8_t *data, size_t length);

/*!
 * @brief Reads the receiver data register using a blocking method.
 *
 * This function polls the receiver register, waits for the receiver register full or receiver FIFO
 * has data, and reads data from the TX register.
 *
 * @param base SCI peripheral base address.
 * @param data Start address of the buffer to store the received data.
 * @param length Size of the buffer.
 * @retval sStatus_SCI_RxHardwareOverrun Receiver overrun happened while receiving data.
 * @retval sStatus_SCI_NoiseError Noise error happened while receiving data.
 * @retval sStatus_SCI_FramingError Framing error happened while receiving data.
 * @retval sStatus_SCI_ParityError Parity error happened while receiving data.
 * @retval sStatus_SCI_Timeout Transmission timed out and was aborted.
 * @retval sStatus_Success Successfully received all data.
 */
sstat_t SCI_ReadBlocking(SCI_TypeDef *base, uint8_t *data, size_t length);

/* @} */

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Initializes the SCI handle.
 *
 * This function initializes the SCI handle, which can be used for other SCI
 * transactional APIs. Usually, for a specified SCI instance,
 * call this API once to get the initialized handle.
 *
 * The SCI driver supports the "background" receiving, which means that user can set up
 * an RX ring buffer optionally. Data received is stored into the ring buffer even when the
 * user doesn't call the SCI_TransferReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, the user can get the received data from the ring buffer directly.
 * The ring buffer is disabled if passing NULL as @p ringBuffer.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 * @param callback Callback function.
 * @param userData User data.
 */
void SCI_TransferCreateHandle(SCI_TypeDef *base,
                                 SCI_handle_t *handle,
                                 SCI_transfer_callback_t callback,
                                 void *userData);
/*!
 * @brief Transmits a buffer of data using the interrupt method.
 *
 * This function send data using an interrupt method. This is a non-blocking function, which
 * returns directly without waiting for all data written to the transmitter register. When
 * all data is written to the TX register in the ISR, the SCI driver calls the callback
 * function and passes the @ref sStatus_SCI_TxIdle as status parameter.
 *
 * @note The sStatus_SCI_TxIdle is passed to the upper layer when all data are written
 * to the TX register. However, there is no check to ensure that all the data sent out. Before disabling the TX,
 * check the sSCI_TransmissionCompleteFlag to ensure that the transmit is finished.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 * @param xfer SCI transfer structure, see #SCI_transfer_t.
 * @retval sStatus_Success Successfully start the data transmission.
 * @retval sStatus_SCI_TxBusy Previous transmission still not finished, data not all written to the TX register.
 * @retval sStatus_InvalidArgument Invalid argument.
 */
sstat_t SCI_TransferSendNonBlocking(SCI_TypeDef *base, SCI_handle_t *handle, SCI_transfer_t *xfer);

/*!
 * @brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific UART handle.
 *
 * When the RX ring buffer is used, data received is stored into the ring buffer even when
 * the user doesn't call the UART_TransferReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, the user can get the received data from the ring buffer directly.
 *
 * @note When using RX ring buffer, one byte is reserved for internal use. In other
 * words, if @p ringBufferSize is 32, then only 31 bytes are used for saving data.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 * @param ringBuffer Start address of ring buffer for background receiving. Pass NULL to disable the ring buffer.
 * @param ringBufferSize size of the ring buffer.
 */
void SCI_TransferStartRingBuffer(SCI_TypeDef *base,
                                    SCI_handle_t *handle,
                                    uint8_t *ringBuffer,
                                    size_t ringBufferSize);

/*!
 * @brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ring buffer.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 */
void SCI_TransferStopRingBuffer(SCI_TypeDef *base, SCI_handle_t *handle);

/*!
 * @brief Get the length of received data in RX ring buffer.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 * @return Length of received data in RX ring buffer.
 */
size_t SCI_TransferGetRxRingBufferLength(SCI_TypeDef *base, SCI_handle_t *handle);

/*!
 * @brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt driven data sending. The user can get the remainBtyes to find out
 * how many bytes are not sent out.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 */
void SCI_TransferAbortSend(SCI_TypeDef *base, SCI_handle_t *handle);

/*!
 * @brief Gets the number of bytes that have been sent out to bus.
 *
 * This function gets the number of bytes that have been sent out to bus by an interrupt method.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 * @param count Send bytes count.
 * @retval sStatus_NoTransferInProgress No send in progress.
 * @retval sStatus_InvalidArgument Parameter is invalid.
 * @retval sStatus_Success Get successfully through the parameter \p count;
 */
sstat_t SCI_TransferGetSendCount(SCI_TypeDef *base, SCI_handle_t *handle, uint32_t *count);

/*!
 * @brief Receives a buffer of data using the interrupt method.
 *
 * This function receives data using an interrupt method. This is a non-blocking function
 * which returns without waiting to ensure that all data are received.
 * If the RX ring buffer is used and not empty, the data in the ring buffer is copied and
 * the parameter @p receivedBytes shows how many bytes are copied from the ring buffer.
 * After copying, if the data in the ring buffer is not enough for read, the receive
 * request is saved by the SCI driver. When the new data arrives, the receive request
 * is serviced first. When all data is received, the SCI driver notifies the upper layer
 * through a callback function and passes a status parameter sStatus_UART_RxIdle.
 * For example, the upper layer needs 10 bytes but there are only 5 bytes in ring buffer.
 * The 5 bytes are copied to xfer->data, which returns with the
 * parameter @p receivedBytes set to 5. For the remaining 5 bytes, the newly arrived data is
 * saved from xfer->data[5]. When 5 bytes are received, the SCI driver notifies the upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to xfer->data. When all data is received, the upper layer is notified.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 * @param xfer SCI transfer structure, see uart_transfer_t.
 * @param receivedBytes Bytes received from the ring buffer directly.
 * @retval sStatus_Success Successfully queue the transfer into the transmit queue.
 * @retval sStatus_SCI_RxBusy Previous receive request is not finished.
 * @retval sStatus_InvalidArgument Invalid argument.
 */
sstat_t SCI_TransferReceiveNonBlocking(SCI_TypeDef *base,
                                           SCI_handle_t *handle,
                                           SCI_transfer_t *xfer,
                                           size_t *receivedBytes);

/*!
 * @brief Aborts the interrupt-driven data receiving.
 *
 * This function aborts the interrupt-driven data receiving. The user can get the remainBytes to find out
 * how many bytes not received yet.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 */
void SCI_TransferAbortReceive(SCI_TypeDef *base, SCI_handle_t *handle);

/*!
 * @brief Gets the number of bytes that have been received.
 *
 * This function gets the number of bytes that have been received.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 * @param count Receive bytes count.
 * @retval sStatus_NoTransferInProgress No receive in progress.
 * @retval sStatus_InvalidArgument Parameter is invalid.
 * @retval sStatus_Success Get successfully through the parameter \p count;
 */
sstat_t SCI_TransferGetReceiveCount(SCI_TypeDef *base, SCI_handle_t *handle, uint32_t *count);

/*!
 * @brief SCI IRQ handle function.
 *
 * This function handles the SCI transmit and receive IRQ request.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 */
void SCI_TransferHandleIRQ(SCI_TypeDef *base, SCI_handle_t *handle);

/*!
 * @brief SCI Error IRQ handle function.
 *
 * This function handles the SCI error IRQ request.
 *
 * @param base SCI peripheral base address.
 * @param handle SCI handle pointer.
 */
void SCI_TransferHandleErrorIRQ(SCI_TypeDef *base, SCI_handle_t *handle);

/* @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* _SCI_H_ */
