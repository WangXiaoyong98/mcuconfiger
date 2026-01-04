/*
  ******************************************************************************
  * @file           : lin_sci.h
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

#ifndef _LIN_SCI_H_
#define _LIN_SCI_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "driver_common.h"
#include "lin.h"

/*!
 * @addtogroup lin_sci_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

typedef enum _lin_sci_stop_bit_count
{
    SCI_OneStopBit = 0U, /*!< One stop bit */
    SCI_TwoStopBit = 1U, /*!< Two stop bits */
} lin_sci_stop_bit_count_t;

enum _lin_sci_flags
{
    SCI_TxDataRegEmptyFlag = (SCI_STATUS_TDREF_MASK), /*!< Transmit data register empty flag, sets when transmit buffer is empty */
    SCI_TransmissionCompleteFlag = (SCI_STATUS_TCF_MASK), /*!< Transmission complete flag, sets when transmission activity complete */
    SCI_RxDataRegFullFlag = (SCI_STATUS_RDFF_MASK), /*!< Receive data register full flag, sets when the receive data buffer is full */
    SCI_IdleLineFlag = (SCI_STATUS_IDLF_MASK), /*!< Idle line detect flag, sets when idle line detected */
    SCI_RxOverrunFlag = (SCI_STATUS_ROF_MASK),  /*!< Receive Overrun, sets when new data is received before data is read from receive register */
    SCI_NoiseErrorFlag = (SCI_STATUS_NOIF_MASK), /*!< Receive takes 3 samples of each received bit.  If any of these samples differ, noise flag sets */
    SCI_FramingErrorFlag = (SCI_STATUS_FEF_MASK), /*!< Frame error flag, sets if logic 0 was detected where stop bit expected */
    SCI_ParityErrorFlag = (SCI_STATUS_PEF_MASK), /*!< If parity enabled, sets upon parity error detection */
    SCI_LinBreakFlag = (SCI_STATUS_LBDIF_MASK), /*!< LIN break detect interrupt flag, sets when LIN break char detected and LIN circuit enabled */

    SCI_RxActiveEdgeFlag = (SCI_STATUS_RXEDGIF_MASK), /*!< Receive pin active edge interrupt flag, sets when active edge detected */
    SCI_RxActiveFlag = (SCI_STATUS_REAF_MASK), /*!< Receiver Active Flag (RAF), sets at beginning of valid start bit */

    SCI_DataMatch1Flag = SCI_STATUS_M1F_MASK, /*!< The next character to be read from SCI_DATA matches MA1*/
    SCI_DataMatch2Flag = SCI_STATUS_M2F_MASK, /*!< The next character to be read from SCI_DATA matches MA2*/


    SCI_NoiseErrorInRxDataRegFlag = (SCI_DATA_NOISE_MASK >> 10), /*!< NOISY bit, sets if noise detected in current data word */
    SCI_ParityErrorInRxDataRegFlag = (SCI_DATA_PARERR_MASK >> 10), /*!< PARITYE bit, sets if noise detected in current data word */


    SCI_TxFifoEmptyFlag = (SCI_FCTL_TFEMPT_MASK >> 16), /*!< TXEMPT bit, sets if transmit buffer is empty */
    SCI_RxFifoEmptyFlag = (SCI_FCTL_RFEMPT_MASK >> 16), /*!< RXEMPT bit, sets if receive buffer is empty */
    SCI_TxFifoOverflowFlag =
        (SCI_FCTL_TBOVF_MASK >> 16), /*!< TXOF bit, sets if transmit buffer overflow occurred */
    SCI_RxFifoUnderflowFlag =
        (SCI_FCTL_RBUNF_MASK >> 16), /*!< RXUF bit, sets if receive buffer underflow occurred */
};

enum _lin_sci_interrupt_enable
{
    SCI_LinBreakInterruptEnable = (SCI_CNFG_LBDIE_MASK >> 8), /*!< LIN break detect. */
    SCI_RxActiveEdgeInterruptEnable = (SCI_CNFG_RXEDGIE_MASK >> 8), /*!< Receive Active Edge. */
    SCI_TxDataRegEmptyInterruptEnable = (SCI_CTRL_TXIE_MASK),        /*!< Transmit data register empty. */
    SCI_TransmissionCompleteInterruptEnable = (SCI_CTRL_TCFIE_MASK), /*!< Transmission complete. */
    SCI_RxDataRegFullInterruptEnable = (SCI_CTRL_RXIE_MASK),         /*!< Receiver data register full. */
    SCI_IdleLineInterruptEnable = (SCI_CTRL_IDFIE_MASK),             /*!< Idle line. */
    SCI_RxOverrunInterruptEnable = (SCI_CTRL_OVIE_MASK),            /*!< Receiver Overrun. */
    SCI_NoiseErrorInterruptEnable = (SCI_CTRL_NFIE_MASK),           /*!< Noise error flag. */
    SCI_FramingErrorInterruptEnable = (SCI_CTRL_FEFIE_MASK),         /*!< Framing error flag. */
    SCI_ParityErrorInterruptEnable = (SCI_CTRL_PEFIE_MASK),          /*!< Parity error flag. */
    SCI_TxFifoOverflowInterruptEnable = (SCI_FCTL_TXOVIE_MASK >> 8),  /*!< Transmit FIFO Overflow. */
    SCI_RxFifoUnderflowInterruptEnable = (SCI_FCTL_RXUNIE_MASK >> 8), /*!< Receive FIFO Underflow. */
};

enum _lin_sci_status
{
    Status_SCI_TxBusy = MAKE_STATUS(sStatusGroup_SCI, 0),              /*!< TX busy */
    Status_SCI_RxBusy = MAKE_STATUS(sStatusGroup_SCI, 1),              /*!< RX busy */
    Status_SCI_TxIdle = MAKE_STATUS(sStatusGroup_SCI, 2),              /*!< SCI transmitter is idle. */
    Status_SCI_RxIdle = MAKE_STATUS(sStatusGroup_SCI, 3),              /*!< SCI receiver is idle. */
    Status_SCI_TxWatermarkTooLarge = MAKE_STATUS(sStatusGroup_SCI, 4), /*!< TX FIFO watermark too large  */
    Status_SCI_RxWatermarkTooLarge = MAKE_STATUS(sStatusGroup_SCI, 5), /*!< RX FIFO watermark too large  */
    Status_SCI_FlagCannotClearManually =
        MAKE_STATUS(sStatusGroup_SCI, 6),                    /*!< Some flag can't manually clear */
    Status_SCI_Error = MAKE_STATUS(sStatusGroup_SCI, 7), /*!< Error happens on SCI. */
    Status_SCI_RxRingBufferOverrun =
        MAKE_STATUS(sStatusGroup_SCI, 8), /*!< SCI RX software ring buffer overrun. */
    Status_SCI_RxHardwareOverrun = MAKE_STATUS(sStatusGroup_SCI, 9), /*!< SCI RX receiver overrun. */
    Status_SCI_NoiseError = MAKE_STATUS(sStatusGroup_SCI, 10),       /*!< SCI noise error. */
    Status_SCI_FramingError = MAKE_STATUS(sStatusGroup_SCI, 11),     /*!< SCI framing error. */
    Status_SCI_ParityError = MAKE_STATUS(sStatusGroup_SCI, 12),      /*!< SCI parity error. */
};

typedef enum
{
    SCI_8_BITS_PER_CHAR  = 0x0U, /*!< 8-bit data characters */
    SCI_9_BITS_PER_CHAR  = 0x1U, /*!< 9-bit data characters */
    SCI_10_BITS_PER_CHAR = 0x2U  /*!< 10-bit data characters */
} lin_sci_bit_count_per_char_t;



/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Accept Master baudrate deviation from the slave baudrate to be 2% */
#define AUTOBAUD_BAUDRATE_TOLERANCE (uint32_t)2U
#define BIT_RATE_TOLERANCE_UNSYNC (uint32_t)14U
/* calculate range of one bit time with baudrate 19200 by formula {1000000/19200*(100 + AUTOBAUD_BAUDRATE_TOLERANCE))/100} */
#define BIT_DURATION_MAX_19200 (uint32_t)(100000U * (100U + AUTOBAUD_BAUDRATE_TOLERANCE)/ 192U)
#define BIT_DURATION_MIN_19200 (uint32_t)(100000U * (100U - AUTOBAUD_BAUDRATE_TOLERANCE)/ 192U)
/* calculate range of one bit time with baudrate 14400 by formula {1000000/19200*(100 + AUTOBAUD_BAUDRATE_TOLERANCE))/100} */
#define BIT_DURATION_MAX_14400 (uint32_t)(100000U * (100U + AUTOBAUD_BAUDRATE_TOLERANCE)/ 144U)
#define BIT_DURATION_MIN_14400 (uint32_t)(100000U * (100U - AUTOBAUD_BAUDRATE_TOLERANCE)/ 144U)
/* calculate range of one bit time with baudrate 9600 by formula {1000000/19200*(100 + AUTOBAUD_BAUDRATE_TOLERANCE))/100} */
#define BIT_DURATION_MAX_9600 (uint32_t)(100000U * (100U + AUTOBAUD_BAUDRATE_TOLERANCE)/96U)
#define BIT_DURATION_MIN_9600 (uint32_t)(100000U * (100U - AUTOBAUD_BAUDRATE_TOLERANCE)/96U)
/* calculate range of one bit time with baudrate 4800 by formula {1000000/19200*(100 + AUTOBAUD_BAUDRATE_TOLERANCE))/100} */
#define BIT_DURATION_MAX_4800 (uint32_t)(100000U * (100U + AUTOBAUD_BAUDRATE_TOLERANCE)/48U)
#define BIT_DURATION_MIN_4800 (uint32_t)(100000U * (100U - AUTOBAUD_BAUDRATE_TOLERANCE)/48U)
/* calculate range of one bit time with baudrate 2400 by formula {1000000/19200*(100 + AUTOBAUD_BAUDRATE_TOLERANCE))/100} */
#define BIT_DURATION_MAX_2400 (uint32_t)(100000U * (100U + AUTOBAUD_BAUDRATE_TOLERANCE)/24U)
#define BIT_DURATION_MIN_2400 (uint32_t)(100000U * (100U - AUTOBAUD_BAUDRATE_TOLERANCE)/24U)

/* calculate range of two bit time with baudrate 19200 */
#define TWO_BIT_DURATION_MAX_19200 (2U*BIT_DURATION_MAX_19200)
#define TWO_BIT_DURATION_MIN_19200 (2U*BIT_DURATION_MIN_19200)
/* calculate range of two bit time with baudrate 14400 */
#define TWO_BIT_DURATION_MAX_14400 (2U*BIT_DURATION_MAX_14400)
#define TWO_BIT_DURATION_MIN_14400 (2U*BIT_DURATION_MIN_14400)
/* calculate range of two bit time with baudrate 9600 */
#define TWO_BIT_DURATION_MAX_9600 (2U*BIT_DURATION_MAX_9600)
#define TWO_BIT_DURATION_MIN_9600 (2U*BIT_DURATION_MIN_9600)
/* calculate range of two bit time with baudrate 4800 */
#define TWO_BIT_DURATION_MAX_4800 (2U*BIT_DURATION_MAX_4800)
#define TWO_BIT_DURATION_MIN_4800 (2U*BIT_DURATION_MIN_4800)
/* calculate range of two bit time with baudrate 2400 */
#define TWO_BIT_DURATION_MAX_2400 (2U*BIT_DURATION_MAX_2400)
#define TWO_BIT_DURATION_MIN_2400 (2U*BIT_DURATION_MIN_2400)

/* calculate range of 13 bit time minimum with baudrate 19200 for autobaud feature */
#define AUTOBAUD_BREAK_TIME_MIN    (13U * BIT_DURATION_MIN_19200)
/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initializes an LIN_SCI instance for LIN Network.
 *
 * The caller provides memory for the driver state structures during initialization.
 * The user must select the LIN_SCI clock source in the application to initialize the LIN_SCI.
 * This function initializes a SCI instance for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, set break field length to be 13 bit times minimum, enable
 * the break detect interrupt, Rx complete interrupt, frame error detect interrupt,
 * and enable the SCI module transmitter and receiver
 *
 * @param instance LIN_SCI instance number
 * @param linUserConfig user configuration structure of type #lin_user_config_t
 * @param linCurrentState pointer to the LIN_SCI driver state structure
 * @return An error code or lin_status_t
 */

static inline bool LIN_SCI_GetRxDataPolarity(const SCI_TypeDef * base)
{
    return (((base->SCISTATUS >> SCI_STATUS_RXINV_SHIFT) & 1U) > 0U);
}

static inline void LIN_SCI_SetRxDataPolarity(SCI_TypeDef * base, bool polarity)
{
    base->SCISTATUS = (base->SCISTATUS & ~SCI_STATUS_RXINV_MASK) | ((polarity ? 1UL : 0UL) << SCI_STATUS_RXINV_SHIFT);
}

static inline void LIN_SCI_WriteByte(SCI_TypeDef * base, uint8_t data)
{
    volatile uint8_t * dataRegBytes = (volatile uint8_t *)(&(base->SCIDATA));
    dataRegBytes[0] = data;
}

static inline void LIN_SCI_ReadByte(const SCI_TypeDef * base, uint8_t *readData)
{
    *readData = (uint8_t)base->SCIDATA;
}

sstat_t LIN_SCI_CalculateBaudRate(SCI_TypeDef *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz, uint32_t *osr, uint16_t *sbr);
void LIN_SCI_SetBaudRate(SCI_TypeDef *base, uint32_t *osr, uint16_t *sbr);

lin_status_t LIN_SCI_Init(SCI_TypeDef *base, lin_user_config_t *linUserConfig, lin_state_t * linCurrentState, uint32_t linSourceClockFreq);

/*!
 * @brief Shuts down the LIN_SCI by disabling interrupts and transmitter/receiver.
 *
 * @param instance LIN_SCI instance number
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_Deinit(SCI_TypeDef *base);


/*!
 * @brief Sends Frame data out through the LIN_SCI module using blocking method.
 *  This function will calculate the checksum byte and send it with the frame data.
 *  Blocking means that the function does not return until the transmission is complete.
 *
 * @param instance LIN_SCI instance number
 * @param txBuff  source buffer containing 8-bit data chars to send
 * @param txSize the number of bytes to send
 * @param timeoutMSec timeout value in milli seconds
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_SendFrameDataBlocking(SCI_TypeDef *base, const uint8_t * txBuff, uint8_t txSize, uint32_t timeoutMSec);

/*!
 * @brief Sends frame data out through the LIN_SCI module using non-blocking method.
 *  This enables an a-sync method for transmitting data.
 *  Non-blocking  means that the function returns immediately.
 *  The application has to get the transmit status to know when the transmit is complete.
 *  This function will calculate the checksum byte and send it with the frame data.
 *
 * @param instance LIN_SCI instance number
 * @param txBuff  source buffer containing 8-bit data chars to send
 * @param txSize  the number of bytes to send
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_SendFrameData(SCI_TypeDef *base, const uint8_t * txBuff, uint8_t txSize);

/*!
 * @brief Get status of an on-going non-blocking transmission
 *  While sending frame data using non-blocking method, users can
 *  use this function to get status of that transmission.
 *  This function return LIN_TX_BUSY while sending, or LIN_TIMEOUT
 *  if timeout has occurred, or return LIN_SUCCESS when the transmission is complete.
 *  The bytesRemaining shows number of bytes that still needed to transmit.
 *
 * @param instance LIN_SCI instance number
 * @param bytesRemaining  Number of bytes still needed to transmit
 * @return lin_status_t LIN_TX_BUSY, LIN_SUCCESS or LIN_TIMEOUT
 */
lin_status_t LIN_SCI_GetTransmitStatus(SCI_TypeDef *base, uint8_t * bytesRemaining);

/*!
 * @brief Receives frame data through the LIN_SCI module using blocking method.
 *  This function will check the checksum byte. If the checksum is correct, it
 *  will receive the frame data. Blocking means that the function does
 *  not return until the reception is complete.
 *
 * @param instance LIN_SCI instance number
 * @param rxBuff  buffer containing 8-bit received data
 * @param rxSize the number of bytes to receive
 * @param timeoutMSec timeout value in milli seconds
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_RecvFrmDataBlocking(SCI_TypeDef *base, uint8_t * rxBuff, uint8_t rxSize, uint32_t timeoutMSec);

/*!
 * @brief Receives frame data through the LIN_SCI module using non- blocking method.
 *  This function will check the checksum byte. If the checksum is correct, it will receive it with the frame data.
 *  Non-blocking  means that the function returns immediately.
 *  The application has to get the receive status to know when the reception is complete.
 *
 * @param instance LIN_SCI instance number
 * @param rxBuff  buffer containing 8-bit received data
 * @param rxSize the number of bytes to receive
 * @return An error code or lin_status_t
 */
 lin_status_t LIN_SCI_RecvFrmData(SCI_TypeDef *base, uint8_t * rxBuff, uint8_t rxSize);

/*!
 * @brief Aborts an on-going non-blocking transmission/reception.
 *  While performing a non-blocking transferring data, users can call this function
 *  to terminate immediately the transferring.
 *
 * @param instance LIN_SCI instance number
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_AbortTransferData(SCI_TypeDef *base);

/*!
 * @brief Get status of an on-going non-blocking reception
 *  While receiving frame data using non-blocking method, users can
 *  use this function to get status of that receiving.
 *  This function return the current event ID, LIN_RX_BUSY while receiving
 *  and return LIN_SUCCESS, or timeout (LIN_TIMEOUT) when the reception is complete.
 *  The bytesRemaining shows number of bytes that still needed to receive.
 *
 * @param instance LIN_SCI instance number
 * @param bytesRemaining  Number of bytes still needed to receive
 * @return lin_status_t LIN_RX_BUSY, LIN_TIMEOUT or LIN_SUCCESS
 */
lin_status_t LIN_SCI_GetReceiveStatus(SCI_TypeDef *base, uint8_t * bytesRemaining);

/*!
 * @brief This function puts current node to sleep mode
 * This function changes current node state to LIN_NODE_STATE_SLEEP_MODE
 *
 * @param instance LIN_SCI instance number
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_GoToSleepMode(SCI_TypeDef *base);

/*!
 * @brief Puts current LIN node to Idle state
 * This function changes current node state to LIN_NODE_STATE_IDLE
 *
 * @param instance LIN_SCI instance number
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_GotoIdleState(SCI_TypeDef *base);

/*!
 * @brief Sends a wakeup signal through the LIN_SCI interface
 *
 * @param instance LIN_SCI instance number
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_SendWakeupSignal(SCI_TypeDef *base);



/*!
 * @brief Sends frame header out through the LIN_SCI module using a non-blocking method.
 *  This function sends LIN Break field, sync field then the ID with
 *  correct parity.
 *
 * @param instance LIN_SCI instance number
 * @param id  Frame Identifier
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_MasterSendHeader(SCI_TypeDef *base, uint8_t id);

/*!
 * @brief Enables LIN_SCI hardware interrupts.
 *
 * @param instance LIN_SCI instance number
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_EnableIRQ(SCI_TypeDef *base);

/*!
 * @brief Disables LIN_SCI hardware interrupts.
 *
 * @param instance LIN_SCI instance number
 * @return An error code or lin_status_t
 */
lin_status_t LIN_SCI_DisableIRQ(SCI_TypeDef *base);

/*!
 * @brief This function capture bits time to detect break char, calculate
  * baudrate from sync bits and enable transceiver if autobaud successful.
  * This function should only be used in Slave.
  * The timer should be in mode input capture of both rising and falling edges.
  * The timer input capture pin should be externally connected to RXD pin.
 *
 * @param instance SCI instance
 * @return lin_status_t
 */
lin_status_t LIN_SCI_AutoBaudCapture(uint32_t instance);
/*!
 * @brief LIN_SCI RX TX interrupt handler
 *
 * @param instance LIN_SCI instance number
 * @return void
 */
void LIN_SCI_IRQHandler(SCI_TypeDef *base);

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_LIN_SCI_H_ */
