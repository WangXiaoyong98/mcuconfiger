//###########################################################################
//
// FILE:   spi.h
//
// TITLE:  SP28038 SPI driver.
//
//###########################################################################

#ifndef SPI_H
#define SPI_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup spi_api SPI
//! \brief This module is used for SPI configurations.
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "driver_common.h"

/*!
 * @addtogroup SPI_driver
 * @{
 */

/**********************************************************************************************************************
 * Definitions
 *********************************************************************************************************************/

/*! @brief SPI driver version. */
#define FSL_SPI_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0. */

/*! @brief SPI dummy data if no Tx/Rx data.*/
#define SPI_MASTER_DUMMY_DATA (0x00U) /*!< Master dummy data used for tx if there is not txData. */
#define SPI_SLAVE_DUMMY_DATA (0x5AU)  /*!< Slave dummy data used for tx if there is not txData. */

#define SPI_FIFO_SIZEn(x) \
    ((x) == SPI1 ? (4) : \
    ((x) == SPI2 ? (1) : (-1)))
#define SPI_COUNT (4)

/*! @brief Status for the SPI driver.*/
enum _SPI_status
{
    sStatus_SPI_Busy = MAKE_STATUS(sStatusGroup_SPI, 0),      /*!< SPI transfer is busy.*/
    sStatus_SPI_Error = MAKE_STATUS(sStatusGroup_SPI, 1),     /*!< SPI driver error. */
    sStatus_SPI_Idle = MAKE_STATUS(sStatusGroup_SPI, 2),      /*!< SPI is idle.*/
    sStatus_SPI_OutOfRange = MAKE_STATUS(sStatusGroup_SPI, 3) /*!< SPI transfer out Of range. */
};

/*! @brief SPI status flags in SPIx_SR register.*/
enum _SPI_flags
{
    sSPI_TxCompleteFlag = SPI_STATR_TXCF_MASK,          /*!< Transfer Complete Flag. */
    sSPI_EndOfQueueFlag = SPI_STATR_EQF_MASK,           /*!< End of Queue Flag.*/
    sSPI_TxFifoUnderflowFlag = SPI_STATR_TXFUF_MASK,    /*!< Transmit FIFO Underflow Flag.*/
    sSPI_TxFifoFillRequestFlag = SPI_STATR_TXFFF_MASK,  /*!< Transmit FIFO Fill Flag.*/
    sSPI_RxFifoOverflowFlag = SPI_STATR_RXFOF_MASK,     /*!< Receive FIFO Overflow Flag.*/
    sSPI_RxFifoDrainRequestFlag = SPI_STATR_RXFDF_MASK, /*!< Receive FIFO Drain Flag.*/
    sSPI_TxAndRxStatusFlag = SPI_STATR_TRSTAT_MASK,     /*!< The module is in Stopped/Running state.*/
    sSPI_AllStatusFlag = SPI_STATR_TXCF_MASK | SPI_STATR_EQF_MASK | SPI_STATR_TXFUF_MASK | SPI_STATR_TXFFF_MASK | SPI_STATR_RXFOF_MASK |
                          SPI_STATR_RXFDF_MASK | SPI_STATR_TRSTAT_MASK /*!< All status above.*/
};

/*! @brief SPI interrupt source.*/
enum _SPI_interrupt_enable
{
    sSPI_TxCompleteInterruptEnable = SPI_IRSER_TXCRE_MASK,          /*!< TCF  interrupt enable.*/
    sSPI_EndOfQueueInterruptEnable = SPI_IRSER_EQRE_MASK,           /*!< EOQF interrupt enable.*/
    sSPI_TxFifoUnderflowInterruptEnable = SPI_IRSER_TXFURE_MASK,    /*!< TFUF interrupt enable.*/
    sSPI_TxFifoFillRequestInterruptEnable = SPI_IRSER_TXFFRE_MASK,  /*!< TFFF interrupt enable, DMA disable.*/
    sSPI_RxFifoOverflowInterruptEnable = SPI_IRSER_RXFORE_MASK,     /*!< RFOF interrupt enable.*/
    sSPI_RxFifoDrainRequestInterruptEnable = SPI_IRSER_RXFDRE_MASK, /*!< RFDF interrupt enable, DMA disable.*/
    sSPI_AllInterruptEnable = SPI_IRSER_TXCRE_MASK | SPI_IRSER_EQRE_MASK | SPI_IRSER_TXFURE_MASK |
                               SPI_IRSER_TXFFRE_MASK | SPI_IRSER_RXFORE_MASK | SPI_IRSER_RXFDRE_MASK
    /*!< All above interrupts enable.*/
};

/*! @brief SPI DMA source.*/
enum _SPI_dma_enable
{
    sSPI_TxDmaEnable = (SPI_IRSER_TXFFRE_MASK | SPI_IRSER_TXFFIRS_MASK), /*!< TFFF flag generates DMA requests.
                                                                                No Tx interrupt request. */
    sSPI_RxDmaEnable = (SPI_IRSER_RXFDRE_MASK | SPI_IRSER_RXFDIRS_MASK)  /*!< RFDF flag generates DMA requests.
                                                                                No Rx interrupt request. */
};

/*! @brief SPI master or slave mode configuration.*/
typedef enum _SPI_master_slave_mode
{
    sSPI_Master = 1U, /*!< SPI peripheral operates in master mode.*/
    sSPI_Slave = 0U   /*!< SPI peripheral operates in slave mode.*/
} spi_master_slave_mode_t;

/*!
 * @brief SPI Sample Point: Controls when the SPI master samples SIN in Modified Transfer Format. This field is valid
 * only when CPHA bit in CTAR register is 0.
 */
typedef enum _SPI_master_sample_point
{
    sSPI_SckToSin0Clock = 0U, /*!< 0 system clocks between SCK edge and SIN sample.*/
    sSPI_SckToSin1Clock = 1U, /*!< 1 system clock  between SCK edge and SIN sample.*/
    sSPI_SckToSin2Clock = 2U  /*!< 2 system clocks between SCK edge and SIN sample.*/
} spi_master_sample_point_t;

/*! @brief SPI Peripheral Chip Select (Pcs) configuration (which Pcs to configure).*/
typedef enum _SPI_which_pcs_config
{
    sSPI_Pcs0 = 1U << 0, /*!< Pcs[0] */
    sSPI_Pcs1 = 1U << 1, /*!< Pcs[1] */
    sSPI_Pcs2 = 1U << 2, /*!< Pcs[2] */
    sSPI_Pcs3 = 1U << 3, /*!< Pcs[3] */
    sSPI_Pcs4 = 1U << 4, /*!< Pcs[4] */
    sSPI_Pcs5 = 1U << 5  /*!< Pcs[5] */
} spi_which_pcs_t;

/*! @brief SPI Peripheral Chip Select (Pcs) Polarity configuration.*/
typedef enum _SPI_pcs_polarity_config
{
    sSPI_PcsActiveHigh = 0U, /*!< Pcs Active High (idles low). */
    sSPI_PcsActiveLow = 1U   /*!< Pcs Active Low (idles high). */
} spi_pcs_polarity_config_t;

/*! @brief SPI Peripheral Chip Select (Pcs) Polarity.*/
enum _spi_pcs_polarity
{
    sSPI_Pcs0ActiveLow = 1U << 0, /*!< Pcs0 Active Low (idles high). */
    sSPI_Pcs1ActiveLow = 1U << 1, /*!< Pcs1 Active Low (idles high). */
    sSPI_Pcs2ActiveLow = 1U << 2, /*!< Pcs2 Active Low (idles high). */
    sSPI_Pcs3ActiveLow = 1U << 3, /*!< Pcs3 Active Low (idles high). */
    sSPI_Pcs4ActiveLow = 1U << 4, /*!< Pcs4 Active Low (idles high). */
    sSPI_Pcs5ActiveLow = 1U << 5, /*!< Pcs5 Active Low (idles high). */
    sSPI_PcsAllActiveLow = 0xFFU  /*!< Pcs0 to Pcs5 Active Low (idles high). */
};

/*! @brief SPI clock polarity configuration for a given CTAR.*/
typedef enum _SPI_clock_polarity
{
    sSPI_ClockPolarityActiveHigh = 0U, /*!< CPOL=0. Active-high SPI clock (idles low).*/
    sSPI_ClockPolarityActiveLow = 1U   /*!< CPOL=1. Active-low SPI clock (idles high).*/
} spi_clock_polarity_t;

/*! @brief SPI clock phase configuration for a given CTAR.*/
typedef enum _SPI_clock_phase
{
    sSPI_ClockPhaseFirstEdge = 0U, /*!< CPHA=0. Data is captured on the leading edge of the SCK and changed on the
                                         following edge.*/
    sSPI_ClockPhaseSecondEdge = 1U /*!< CPHA=1. Data is changed on the leading edge of the SCK and captured on the
                                        following edge.*/
} spi_clock_phase_t;

/*! @brief SPI data shifter direction options for a given CTAR.*/
typedef enum _SPI_shift_direction
{
    sSPI_MsbFirst = 0U, /*!< Data transfers start with most significant bit.*/
    sSPI_LsbFirst = 1U  /*!< Data transfers start with least significant bit.*/
} spi_shift_direction_t;

/*! @brief SPI delay type selection.*/
typedef enum _SPI_delay_type
{
    sSPI_PcsToSck = 1U,  /*!< Pcs-to-SCK delay. */
    sSPI_LastSckToPcs,   /*!< Last SCK edge to Pcs delay. */
    sSPI_BetweenTransfer /*!< Delay between transfers. */
} spi_delay_type_t;

/*! @brief SPI Clock and Transfer Attributes Register (CTAR) selection.*/
typedef enum _SPI_ctar_selection
{
    sSPI_Ctar0 = 0U, /*!< CTAR0 selection option for master or slave mode, note that CTAR0 and CTAR0_SLAVE are the
                         same register address. */
    sSPI_Ctar1 = 1U, /*!< CTAR1 selection option for master mode only. */
    sSPI_Ctar2 = 2U, /*!< CTAR2 selection option for master mode only , note that some device do not support CTAR2. */
    sSPI_Ctar3 = 3U, /*!< CTAR3 selection option for master mode only , note that some device do not support CTAR3. */
    sSPI_Ctar4 = 4U, /*!< CTAR4 selection option for master mode only , note that some device do not support CTAR4. */
    sSPI_Ctar5 = 5U, /*!< CTAR5 selection option for master mode only , note that some device do not support CTAR5. */
    sSPI_Ctar6 = 6U, /*!< CTAR6 selection option for master mode only , note that some device do not support CTAR6. */
    sSPI_Ctar7 = 7U  /*!< CTAR7 selection option for master mode only , note that some device do not support CTAR7. */
} spi_ctar_selection_t;

#define SPI_MASTER_CTAR_SHIFT (0U)   /*!< SPI master CTAR shift macro , internal used. */
#define SPI_MASTER_CTAR_MASK (0x0FU) /*!< SPI master CTAR mask macro , internal used. */
#define SPI_MASTER_PCS_SHIFT (4U)    /*!< SPI master PCS shift macro , internal used. */
#define SPI_MASTER_PCS_MASK (0xF0U)  /*!< SPI master PCS mask macro , internal used. */
/*! @brief Can use this enum for SPI master transfer configFlags. */
enum _SPI_transfer_config_flag_for_master
{
    sSPI_MasterCtar0 = 0U << SPI_MASTER_CTAR_SHIFT, /*!< SPI master transfer use CTAR0 setting. */
    sSPI_MasterCtar1 = 1U << SPI_MASTER_CTAR_SHIFT, /*!< SPI master transfer use CTAR1 setting. */
    sSPI_MasterCtar2 = 2U << SPI_MASTER_CTAR_SHIFT, /*!< SPI master transfer use CTAR2 setting. */
    sSPI_MasterCtar3 = 3U << SPI_MASTER_CTAR_SHIFT, /*!< SPI master transfer use CTAR3 setting. */
    sSPI_MasterCtar4 = 4U << SPI_MASTER_CTAR_SHIFT, /*!< SPI master transfer use CTAR4 setting. */
    sSPI_MasterCtar5 = 5U << SPI_MASTER_CTAR_SHIFT, /*!< SPI master transfer use CTAR5 setting. */
    sSPI_MasterCtar6 = 6U << SPI_MASTER_CTAR_SHIFT, /*!< SPI master transfer use CTAR6 setting. */
    sSPI_MasterCtar7 = 7U << SPI_MASTER_CTAR_SHIFT, /*!< SPI master transfer use CTAR7 setting. */

    sSPI_MasterPcs0 = 0U << SPI_MASTER_PCS_SHIFT, /*!< SPI master transfer use PCS0 signal. */
    sSPI_MasterPcs1 = 1U << SPI_MASTER_PCS_SHIFT, /*!< SPI master transfer use PCS1 signal. */
    sSPI_MasterPcs2 = 2U << SPI_MASTER_PCS_SHIFT, /*!< SPI master transfer use PCS2 signal.*/
    sSPI_MasterPcs3 = 3U << SPI_MASTER_PCS_SHIFT, /*!< SPI master transfer use PCS3 signal. */
    sSPI_MasterPcs4 = 4U << SPI_MASTER_PCS_SHIFT, /*!< SPI master transfer use PCS4 signal. */
    sSPI_MasterPcs5 = 5U << SPI_MASTER_PCS_SHIFT, /*!< SPI master transfer use PCS5 signal. */

    sSPI_MasterPcsContinuous = 1U << 20,       /*!< Is PCS signal continuous. */
    sSPI_MasterActiveAfterTransfer = 1U << 21, /*!< Is PCS signal active after last frame transfer.*/
};

#define SPI_SLAVE_CTAR_SHIFT (0U)   /*!< SPI slave CTAR shift macro , internal used. */
#define SPI_SLAVE_CTAR_MASK (0x07U) /*!< SPI slave CTAR mask macro , internal used. */
/*! @brief Can use this enum for SPI slave transfer configFlags. */
enum _spi_transfer_config_flag_for_slave
{
    sSPI_SlaveCtar0 = 0U << SPI_SLAVE_CTAR_SHIFT, /*!< SPI slave transfer use CTAR0 setting. */
                                                    /*!< SPI slave can only use PCS0. */
};

/*! @brief SPI transfer state, which is used for SPI transactiaonl APIs' state machine. */
enum _spi_transfer_state
{
    sSPI_Idle = 0x0U, /*!< Nothing in the transmitter/receiver. */
    sSPI_Busy,        /*!< Transfer queue is not finished. */
    sSPI_Error        /*!< Transfer error. */
};

/*! @brief SPI master command date configuration used for SPIx_PUSHR.*/
typedef struct _spi_command_data_config
{
    bool isPcsContinuous;            /*!< Option to enable the continuous assertion of chip select between transfers.*/
    spi_ctar_selection_t whichCtar; /*!< The desired Clock and Transfer Attributes
                                          Register (CTAR) to use for CTAS.*/
    spi_which_pcs_t whichPcs;       /*!< The desired Pcs signal to use for the data transfer.*/
    bool isEndOfQueue;               /*!< Signals that the current transfer is the last in the queue.*/
    bool clearTransferCount;         /*!< Clears SPI Transfer Counter (SPI_TCNT) before transmission starts.*/
} spi_command_data_config_t;

/*! @brief SPI master ctar config structure.*/
typedef struct _spi_master_ctar_config
{
    uint32_t baudRate;                /*!< Baud Rate for SPI. */
    uint32_t bitsPerFrame;            /*!< Bits per frame, minimum 4, maximum 16.*/
    spi_clock_polarity_t cpol;       /*!< Clock polarity. */
    spi_clock_phase_t cpha;          /*!< Clock phase. */
    spi_shift_direction_t direction; /*!< MSB or LSB data shift direction. */

    uint32_t pcsToSckDelayInNanoSec;        /*!< PCS to SCK delay time with nanosecond , set to 0 will set the minimum
                                               delay.It woulde set the boundary value if out of range that can be set.*/
    uint32_t lastSckToPcsDelayInNanoSec;    /*!< Last SCK to PCS delay time with nanosecond , set to 0 will set the
                                               minimum delay.It woulde set the boundary value if out of range that can be
                                               set.*/
    uint32_t betweenTransferDelayInNanoSec; /*!< After SCK delay time with nanosecond , set to 0 will set the minimum
                                             delay.It woulde set the boundary value if out of range that can be set.*/
} spi_master_ctar_config_t;

/*! @brief SPI master config structure.*/
typedef struct _spi_master_config
{
    spi_ctar_selection_t whichCtar;      /*!< Desired CTAR to use. */
    spi_master_ctar_config_t ctarConfig; /*!< Set the ctarConfig to the desired CTAR. */

    spi_which_pcs_t whichPcs;                     /*!< Desired Peripheral Chip Select (pcs). */
    spi_pcs_polarity_config_t pcsActiveHighOrLow; /*!< Desired PCS active high or low. */

    bool enableContinuousSCK;   /*!< CONT_SCKE, ctinuous SCK enable . Note that continuous SCK is only
                                     supported for CPHA = 1.*/
    bool enableRxFifoOverWrite; /*!< ROOE, Receive FIFO overflow overwrite enable. ROOE = 0, the incoming
                                     data is ignored, the data from the transfer that generated the overflow
                                     is either ignored. ROOE = 1, the incoming data is shifted in to the
                                     shift to the shift register. */

    bool enableModifiedTimingFormat;        /*!< Enables a modified transfer format to be used if it's true.*/
    spi_master_sample_point_t samplePoint; /*!< Controls when the module master samples SIN in Modified Transfer
                                                 Format. It's valid only when CPHA=0. */
} spi_master_config_t;

/*! @brief SPI slave ctar config structure.*/
typedef struct _spi_slave_ctar_config
{
    uint32_t bitsPerFrame;      /*!< Bits per frame, minimum 4, maximum 16.*/
    spi_clock_polarity_t cpol; /*!< Clock polarity. */
    spi_clock_phase_t cpha;    /*!< Clock phase. */
                                /*!< Slave only supports MSB , does not support LSB.*/
} spi_slave_ctar_config_t;

/*! @brief SPI slave config structure.*/
typedef struct _spi_slave_config
{
    spi_ctar_selection_t whichCtar;     /*!< Desired CTAR to use. */
    spi_slave_ctar_config_t ctarConfig; /*!< Set the ctarConfig to the desired CTAR. */

    bool enableContinuousSCK;               /*!< CONT_SCKE, ctinuous SCK enable. Note that continuous SCK is only
                                                 supported for CPHA = 1.*/
    bool enableRxFifoOverWrite;             /*!< ROOE, Receive FIFO overflow overwrite enable. ROOE = 0, the incoming
                                                 data is ignored, the data from the transfer that generated the overflow
                                                 is either ignored. ROOE = 1, the incoming data is shifted in to the
                                                 shift to the shift register. */
    bool enableModifiedTimingFormat;        /*!< Enables a modified transfer format to be used if it's true.*/
    spi_master_sample_point_t samplePoint; /*!< Controls when the module master samples SIN in Modified Transfer
                                               Format. It's valid only when CPHA=0. */
} spi_slave_config_t;

/*!
* @brief Forward declaration of the _spi_master_handle typedefs.
*/
typedef struct _spi_master_handle spi_master_handle_t;

/*!
* @brief Forward declaration of the _spi_slave_handle typedefs.
*/
typedef struct _spi_slave_handle spi_slave_handle_t;

/*!
 * @brief Completion callback function pointer type.
 *
 * @param base SPI peripheral address.
 * @param handle Pointer to the handle for the SPI master.
 * @param status Success or error code describing whether the transfer completed.
 * @param userData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*spi_master_transfer_callback_t)(SPI_Type *base,
                                                spi_master_handle_t *handle,
                                                sstat_t status,
                                                void *userData);
/*!
 * @brief Completion callback function pointer type.
 *
 * @param base SPI peripheral address.
 * @param handle Pointer to the handle for the SPI slave.
 * @param status Success or error code describing whether the transfer completed.
 * @param userData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*spi_slave_transfer_callback_t)(SPI_Type *base,
                                               spi_slave_handle_t *handle,
                                               sstat_t status,
                                               void *userData);

/*! @brief SPI master/slave transfer structure.*/
typedef struct _spi_transfer
{
    uint8_t *txData;          /*!< Send buffer. */
    uint8_t *rxData;          /*!< Receive buffer. */
    volatile size_t dataSize; /*!< Transfer bytes. */

    uint32_t configFlags; /*!< Transfer transfer config flags , set from _spi_transfer_config_flag_for_master if the
                             transfer is used for master or _spi_transfer_config_flag_for_slave enum if the transfer
                             is used for slave.*/
} spi_transfer_t;

/*! @brief SPI master transfer handle structure used for transactional API. */
struct _spi_master_handle
{
    uint32_t bitsPerFrame;         /*!< Desired number of bits per frame. */
    volatile uint32_t command;     /*!< Desired data command. */
    volatile uint32_t lastCommand; /*!< Desired last data command. */

    uint8_t fifoSize; /*!< Fifo dataSize. */

    volatile bool isPcsActiveAfterTransfer; /*!< Is PCS signal keep active after the last frame transfer.*/
    volatile bool isThereExtraByte;         /*!< Is there extra byte.*/

    uint8_t *volatile txData;                  /*!< Send buffer. */
    uint8_t *volatile rxData;                  /*!< Receive buffer. */
    volatile size_t remainingSendByteCount;    /*!< Number of bytes remaining to send.*/
    volatile size_t remainingReceiveByteCount; /*!< Number of bytes remaining to receive.*/
    size_t totalByteCount;                     /*!< Number of transfer bytes*/

    volatile uint8_t state; /*!< SPI transfer state , _SPI_transfer_state.*/

    spi_master_transfer_callback_t callback; /*!< Completion callback. */
    void *userData;                           /*!< Callback user data. */
};

/*! @brief SPI slave transfer handle structure used for transactional API. */
struct _spi_slave_handle
{
    uint32_t bitsPerFrame;          /*!< Desired number of bits per frame. */
    volatile bool isThereExtraByte; /*!< Is there extra byte.*/

    uint8_t *volatile txData;                  /*!< Send buffer. */
    uint8_t *volatile rxData;                  /*!< Receive buffer. */
    volatile size_t remainingSendByteCount;    /*!< Number of bytes remaining to send.*/
    volatile size_t remainingReceiveByteCount; /*!< Number of bytes remaining to receive.*/
    size_t totalByteCount;                     /*!< Number of transfer bytes*/

    volatile uint8_t state; /*!< SPI transfer state.*/

    volatile uint32_t errorCount; /*!< Error count for slave transfer.*/

    spi_slave_transfer_callback_t callback; /*!< Completion callback. */
    void *userData;                          /*!< Callback user data. */
};

/**********************************************************************************************************************
 * API
 *********************************************************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus*/

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief SPI master Init.
 *
 * This function initialize the SPI master config. An example use case is as follows:
 *  @code
 *   spi_master_config_t  masterConfig;
 *   masterConfig.whichCtar                                = sSPI_Ctar0;
 *   masterConfig.ctarConfig.baudRate                      = 500000000;
 *   masterConfig.ctarConfig.bitsPerFrame                  = 8;
 *   masterConfig.ctarConfig.cpol                          = sSPI_ClockPolarityActiveHigh;
 *   masterConfig.ctarConfig.cpha                          = sSPI_ClockPhaseFirstEdge;
 *   masterConfig.ctarConfig.direction                     = sSPI_MsbFirst;
 *   masterConfig.ctarConfig.pcsToSckDelayInNanoSec        = 1000000000 / masterConfig.ctarConfig.baudRate ;
 *   masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec    = 1000000000 / masterConfig.ctarConfig.baudRate ;
 *   masterConfig.ctarConfig.betweenTransferDelayInNanoSec = 1000000000 / masterConfig.ctarConfig.baudRate ;
 *   masterConfig.whichPcs                                 = sSPI_Pcs0;
 *   masterConfig.pcsActiveHighOrLow                       = sSPI_PcsActiveLow;
 *   masterConfig.enableContinuousSCK                      = false;
 *   masterConfig.enableRxFifoOverWrite                    = false;
 *   masterConfig.enableModifiedTimingFormat               = false;
 *   masterConfig.samplePoint                              = sSPI_SckToSin0Clock;
 *   SPI_MasterInit(base, &masterConfig, srcClock_Hz);
 *  @endcode
 *
 * @param base SPI peripheral address.
 * @param masterConfig Pointer to structure spi_master_config_t.
 * @param srcClock_Hz Module source input clock in Hertz
 */
void SPI_MasterInit(SPI_Type *base, const spi_master_config_t *masterConfig, uint32_t srcClock_Hz);

/*!
 * @brief Set the spi_master_config_t structure to default values.
 *
 * The purpose of this API is to get the config structure initialized for SPI_MasterInit().
 * User may use the initialized structure unchanged in SPI_MasterInit(), or modify some fields of the structure
 * before calling SPI_MasterInit().
 * Example:
 * @code
 *  spi_master_config_t  masterConfig;
 *  SPI_MasterGetDefaultConfig(&masterConfig);
 * @endcode
 * @param masterConfig pointer to spi_master_config_t structure
 */
void SPI_MasterGetDefaultConfig(spi_master_config_t *masterConfig);

/*!
 * @brief SPI slave configuration.
 *
 * This function initialize the SPI slave config. An example use case is as follows:
 *  @code
 *   SPI_slave_config_t  slaveConfig;
 *  slaveConfig->whichCtar                  = sSPI_Ctar0;
 *  slaveConfig->ctarConfig.bitsPerFrame    = 8;
 *  slaveConfig->ctarConfig.cpol            = sSPI_ClockPolarityActiveHigh;
 *  slaveConfig->ctarConfig.cpha            = sSPI_ClockPhaseFirstEdge;
 *  slaveConfig->enableContinuousSCK        = false;
 *  slaveConfig->enableRxFifoOverWrite      = false;
 *  slaveConfig->enableModifiedTimingFormat = false;
 *  slaveConfig->samplePoint                = sSPI_SckToSin0Clock;
 *   SPI_SlaveInit(base, &slaveConfig);
 *  @endcode
 *
 * @param base SPI peripheral address.
 * @param slaveConfig Pointer to structure spi_master_config_t.
 */
void SPI_SlaveInit(SPI_Type *base, const spi_slave_config_t *slaveConfig);

/*!
 * @brief Set the SPI_slave_config_t structure to default values.
 *
 * The purpose of this API is to get the config structure initialized for SPI_SlaveInit().
 * User may use the initialized structure unchanged in SPI_SlaveInit(), or modify some fields of the structure
 * before calling SPI_SlaveInit().
 * Example:
 * @code
 *  SPI_slave_config_t  slaveConfig;
 *  SPI_SlaveGetDefaultConfig(&slaveConfig);
 * @endcode
 * @param slaveConfig pointer to SPI_slave_config_t structure.
 */
void SPI_SlaveGetDefaultConfig(spi_slave_config_t *slaveConfig);

/*!
 * @brief De-initialize the SPI peripheral, call this API to disbale the SPI clock
 * @param base SPI peripheral address.
 */
void SPI_Deinit(SPI_Type *base);

/*!
 * @brief Enables the SPI peripheral and sets the MCR MDIS to 0.
 *
 * @param base SPI peripheral address.
 * @param enable pass true to enable module, false to disable module.
 */
static inline void SPI_Enable(SPI_Type *base, bool enable)
{
    if (enable)
    {
        base->MCFGR &= ~SPI_MCFGR_MD_MASK;
    }
    else
    {
        base->MCFGR |= SPI_MCFGR_MD_MASK;
    }
}

/*!
 *@}
*/

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the SPI status flag state.
 * @param base SPI peripheral address.
 * @return The SPI status(in SR register).
 */
static inline uint32_t SPI_GetStatusFlags(SPI_Type *base)
{
    return (base->STATR);
}

/*!
 * @brief Clears the SPI status flag.
 *
 * This function  clears the desired status bit by using a write-1-to-clear. The user passes in the base and the
 * desired status bit to clear.  The list of status bits is defined in the SPI_status_and_interrupt_request_t. The
 * function uses these bit positions in its algorithm to clear the desired flag state.
 * Example usage:
 * @code
 *  SPI_ClearStatusFlags(base, sSPI_TxCompleteFlag|sSPI_EndOfQueueFlag);
 * @endcode
 *
 * @param base SPI peripheral address.
 * @param statusFlag The status flag , used from type SPI_flags.
 */
static inline void SPI_ClearStatusFlags(SPI_Type *base, uint32_t statusFlags)
{
    base->STATR |= statusFlags; /*!< The status flags are cleared by writing 1 (w1c).*/
}

/*!
 *@}
*/

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enable the SPI interrupts.
 *
 * This function configures the various interrupt masks of the SPI.  The parameters are base, interrupt mask.
 * Note, for Tx Fill and Rx FIFO Drain requests, enable the interrupt request will disable the DMA request in the
 * meanwhile.
 * @code
 *  SPI_EnableInterrupts(base, sSPI_TxCompleteInterruptEnable | sSPI_EndOfQueueInterruptEnable );
 * @endcode
 *
 * @param base SPI peripheral address.
 * @param mask The interrupt mask, can use the enum _SPI_interrupt_enable.
 */
void SPI_EnableInterrupts(SPI_Type *base, uint32_t mask);

/*!
 * @brief Disable the SPI interrupts.
 *
 * @code
 *  SPI_DisableInterrupts(base, sSPI_TxCompleteInterruptEnable | sSPI_EndOfQueueInterruptEnable );
 * @endcode
 *
 * @param base SPI peripheral address.
 * @param mask The interrupt mask, can use the enum _SPI_interrupt_enable.
 */
static inline void SPI_DisableInterrupts(SPI_Type *base, uint32_t mask)
{
    base->IRSER &= ~mask;
}

/*!
 *@}
*/

/*!
 * @name DMA Control
 * @{
 */

/*!
 * @brief Enable the SPI DMA request.
 *
 * This function configures the Rx and Tx DMA mask of the SPI.  The parameters are base, DMA mask.
 * @code
 *  SPI_EnableDMA(base, sSPI_TxDmaEnable | sSPI_RxDmaEnable);
 * @endcode
 *
 * @param base SPI peripheral address.
 * @param interruptSrc The interrupt mask, can use the enum SPI_dma_enable.
 */
static inline void SPI_EnableDMA(SPI_Type *base, uint32_t mask)
{
    base->IRSER |= mask;
}

/*!
 * @brief Disable the SPI DMA request.
 *
 * This function configures the Rx and Tx DMA mask of the SPI.  The parameters are base, DMA mask.
 * @code
 *  SPI_DisableDMA(base, sSPI_TxDmaEnable | sSPI_RxDmaEnable);
 * @endcode
 *
 * @param base SPI peripheral address.
 * @param interruptSrc The interrupt mask, can use the enum SPI_dma_enable.
 */
static inline void SPI_DisableDMA(SPI_Type *base, uint32_t mask)
{
    base->IRSER &= ~mask;
}

/*!
 * @brief Gets the SPI master PUSHR data register address for DMA operation.
 *
 * This function gets the SPI master PUSHR data register address as this value is needed for DMA operation.
 *
 * @param base SPI peripheral address.
 * @return The SPI master PUSHR data register address.
 */
static inline uint32_t SPI_MasterGetTxRegisterAddress(SPI_Type *base)
{
    return (uint32_t) & (base->PUSHTFR);
}

/*!
 * @brief Gets the SPI slave PUSHR data register address for DMA operation.
 *
 * This function gets the SPI slave PUSHR data register address as this value is needed for DMA operation.
 *
 * @param base SPI peripheral address.
 * @return The SPI slave PUSHR data register address.
 */
static inline uint32_t SPI_SlaveGetTxRegisterAddress(SPI_Type *base)
{
    return (uint32_t) & (base->PUSHTFR_SLV);
}

/*!
 * @brief Gets the SPI POPR data register address for DMA operation.
 *
 * This function gets the SPI POPR data register address as this value is needed for DMA operation.
 *
 * @param base SPI peripheral address.
 * @return The SPI POPR data register address.
 */
static inline uint32_t SPI_GetRxRegisterAddress(SPI_Type *base)
{
    return (uint32_t) & (base->POPRFR);
}

/*!
 *@}
*/

/*!
 * @name Bus Operations
 * @{
 */

/*!
 * @brief Configures the SPI for master or slave.
 *
 * @param base SPI peripheral address.
 * @param mode Mode setting (master or slave) of type SPI_master_slave_mode_t.
 */
static inline void SPI_SetMasterSlaveMode(SPI_Type *base, spi_master_slave_mode_t mode)
{
    base->MCFGR = (base->MCFGR & (~SPI_MCFGR_MS_MASK)) | SPI_MCFGR_MS_SET(mode);
}

/*!
 * @brief Returns whether the SPI module is in master mode.
 *
 * @param base SPI peripheral address.
 * @return Returns true if the module is in master mode or false if the module is in slave mode.
 */
static inline bool SPI_IsMaster(SPI_Type *base)
{
    return (bool)((base->MCFGR) & SPI_MCFGR_MS_MASK);
}
/*!
 * @brief Starts the SPI transfers, clears HALT bit in MCR.
 *
 * This function would set the module ready to begin data transfer in either master or slave mode.
 *
 * @param base SPI peripheral address.
 */
static inline void SPI_StartTransfer(SPI_Type *base)
{
    base->MCFGR &= ~SPI_MCFGR_HT_MASK;
}
/*!
 * @brief Stops (halts) SPI transfers, sets HALT bit in MCR.
 *
 * This function call stops data transfers in either master or slave mode.
 *
 * @param base SPI peripheral address.
 */
static inline void SPI_StopTransfer(SPI_Type *base)
{
    base->MCFGR |= SPI_MCFGR_HT_MASK;
}

/*!
 * @brief Enables (or disables) the SPI FIFOs.
 *
 * This function  allows the caller to disable/enable the Tx and Rx FIFOs (independently).
 * Note that to disable, the caller must pass in a logic 0 (false) for the particular FIFO configuration.  To enable,
 * the caller must pass in a logic 1 (true).
 *
 * @param base SPI peripheral address.
 * @param enableTxFifo Disables (false) the TX FIFO, else enables (true) the TX FIFO
 * @param enableRxFifo Disables (false) the RX FIFO, else enables (true) the RX FIFO
 */
static inline void SPI_SetFifoEnable(SPI_Type *base, bool enableTxFifo, bool enableRxFifo)
{
    base->MCFGR = (base->MCFGR & (~(SPI_MCFGR_RXFD_MASK | SPI_MCFGR_TXFD_MASK))) | SPI_MCFGR_TXFD_SET(!enableTxFifo) |
                SPI_MCFGR_RXFD_SET(!enableRxFifo);
}

/*!
 * @brief Flushes the SPI FIFOs.
 *
 * @param base SPI peripheral address.
 * @param flushTxFifo Flushes (true) the Tx FIFO, else do not flush (false) the Tx FIFO
 * @param flushRxFifo Flushes (true) the Rx FIFO, else do not flush (false) the Rx FIFO
 */
static inline void SPI_FlushFifo(SPI_Type *base, bool flushTxFifo, bool flushRxFifo)
{
    base->MCFGR = (base->MCFGR & (~(SPI_MCFGR_TXFC_MASK | SPI_MCFGR_RXFC_MASK))) | SPI_MCFGR_TXFC_SET(flushTxFifo) |
                SPI_MCFGR_RXFC_SET(flushRxFifo);
}

/*!
 * @brief Configures all the SPI peripheral chip select polarity simultaneously.
 * This is an example:  PCS0,PCS1 set to active low and other PCS set to active high. Please note that the number of
 * PCS is specific to the device.
 * @code
 *  SPI_SetAllPcsPolarity(base, sSPI_Pcs0ActiveLow | sSPI_Pcs1ActiveLow);
   @endcode
 * @param base SPI peripheral address.
 * @param mask The PCS polarity mask ,  can use the enum _SPI_pcs_polarity.
 */
static inline void SPI_SetAllPcsPolarity(SPI_Type *base, uint32_t mask)
{
    base->MCFGR = (base->MCFGR & ~SPI_MCFGR_PCSIS_MASK) | SPI_MCFGR_PCSIS_SET(mask);
}

/*!
 * @brief Sets the SPI baud rate in bits per second.
 *
 * This function  takes in the desired baudRate_Bps (baud rate) and calculates the nearest possible baud rate without
 * exceeding the desired baud rate, and returns the calculated baud rate in bits-per-second. It requires that the
 * caller also provide the frequency of the module source clock (in Hertz).
 *
 * @param base SPI peripheral address.
 * @param whichCtar The desired Clock and Transfer Attributes Register (CTAR) of the type SPI_ctar_selection_t
 * @param baudRate_Bps The desired baud rate in bits per second
 * @param srcClock_Hz Module source input clock in Hertz
 * @return The actual calculated baud rate
 */
uint32_t SPI_MasterSetBaudRate(SPI_Type *base,
                                spi_ctar_selection_t whichCtar,
                                uint32_t baudRate_Bps,
                                uint32_t srcClock_Hz);

/*!
 * @brief Manually configures the delay prescaler and scaler for a particular CTAR.
 *
 * This function configures the Pcs to SCK delay pre-scalar (PcsSCK) and scalar (CSSCK), after SCK delay pre-scalar
 * (PASC) and scalar (ASC), and the delay after transfer pre-scalar (PDT)and scalar (DT).
 *
 * These delay names are available in type SPI_delay_type_t.
 *
 * The user passes which delay they want to configure along with the prescaler and scaler value.
 * This allows the user to directly set the prescaler/scaler values if they have pre-calculated them or if they simply
 * wish to manually increment either value.
 *
 * @param base SPI peripheral address.
 * @param whichCtar The desired Clock and Transfer Attributes Register (CTAR) of type SPI_ctar_selection_t.
 * @param prescaler The prescaler delay value (can be an integer 0, 1, 2, or 3).
 * @param scaler The scaler delay value (can be any integer between 0 to 15).
 * @param whichDelay The desired delay to configure, must be of type SPI_delay_type_t
 */
void SPI_MasterSetDelayScaler(
    SPI_Type *base, spi_ctar_selection_t whichCtar, uint32_t prescaler, uint32_t scaler, spi_delay_type_t whichDelay);

/*!
 * @brief Calculates the delay prescaler and scaler based on the desired delay input in nanoseconds.
 *
 * This function calculates the values for:
 * PCS to SCK delay pre-scalar (PCSSCK) and scalar (CSSCK), or
 * After SCK delay pre-scalar (PASC) and scalar (ASC), or
 * Delay after transfer pre-scalar (PDT)and scalar (DT).
 *
 * These delay names are available in type SPI_delay_type_t.
 *
 * The user passes which delay they want to configure along with the desired delay value in nanoseconds.  The function
 * calculates the values needed for the prescaler and scaler and returning the actual calculated delay as an exact
 * delay match may not be possible. In this case, the closest match is calculated without going below the desired
 * delay value input.
 * It is possible to input a very large delay value that exceeds the capability of the part, in which case the maximum
 * supported delay is returned. It is to the higher level peripheral driver to alert the user of an out of range delay
 * input.
 *
 * @param base SPI peripheral address.
 * @param whichCtar The desired Clock and Transfer Attributes Register (CTAR) of type SPI_ctar_selection_t.
 * @param whichDelay The desired delay to configure, must be of type SPI_delay_type_t
 * @param srcClock_Hz Module source input clock in Hertz
 * @param delayTimeInNanoSec The desired delay value in nanoseconds.
 * @return The actual calculated delay value.
 */
uint32_t SPI_MasterSetDelayTimes(SPI_Type *base,
                                  spi_ctar_selection_t whichCtar,
                                  spi_delay_type_t whichDelay,
                                  uint32_t srcClock_Hz,
                                  uint32_t delayTimeInNanoSec);

/*!
 * @brief Writes data into the data buffer for master mode.
 *
 * In master mode, the 16-bit data is appended to the 16-bit command info. The command portion
 * provides characteristics of the data such as: optional continuous chip select
 * operation between transfers, the desired Clock and Transfer Attributes register to use for the
 * associated SPI frame, the desired Pcs signal to use for the data transfer, whether the current
 * transfer is the last in the queue, and whether to clear the transfer count (normally needed when
 * sending the first frame of a data packet). This is an example:
 * @code
 *  SPI_command_data_config_t commandConfig;
 *  commandConfig.isPcsContinuous = true;
 *  commandConfig.whichCtar = kSPICtar0;
 *  commandConfig.whichPcs = kSPIPcs0;
 *  commandConfig.clearTransferCount = false;
 *  commandConfig.isEndOfQueue = false;
 *  SPI_MasterWriteData(base, &commandConfig, dataWord);
   @endcode
 *
 * @param base SPI peripheral address.
 * @param command Pointer to command structure.
 * @param data The data word to be sent.
 */
static inline void SPI_MasterWriteData(SPI_Type *base, spi_command_data_config_t *command, uint16_t data)
{
    base->PUSHTFR = SPI_PUSHTFR_CPCSE_SET(command->isPcsContinuous) | SPI_PUSHTFR_CLKTXAS_SET(command->whichCtar) |
                  SPI_PUSHTFR_SPCS_SET(command->whichPcs) | SPI_PUSHTFR_EQ_SET(command->isEndOfQueue) |
                  SPI_PUSHTFR_CTXCTR_SET(command->clearTransferCount) | SPI_PUSHTFR_TXDAT_SET(data);
}

/*!
 * @brief Set the SPI_command_data_config_t structure to default values.
 *
 * The purpose of this API is to get the config structure initialized for use in SPI_MasterWrite_xx().
 * User may use the initialized structure unchanged in SPI_MasterWrite_xx(), or modify some fields of the structure
 * before calling SPI_MasterWrite_xx().
 * Example:
 * @code
 *  SPI_command_data_config_t  command;
 *  SPI_GetDefaultDataCommandConfig(&command);
 * @endcode
 * @param command pointer to SPI_command_data_config_t structure.
 */
void SPI_GetDefaultDataCommandConfig(spi_command_data_config_t *command);

/*!
 * @brief Writes data into the data buffer, master mode and waits till complete to return.
 *
 * In master mode, the 16-bit data is appended to the 16-bit command info. The command portion
 * provides characteristics of the data such as: optional continuous chip select
 * operation between transfers, the desired Clock and Transfer Attributes register to use for the
 * associated SPI frame, the desired Pcs signal to use for the data transfer, whether the current
 * transfer is the last in the queue, and whether to clear the transfer count (normally needed when
 * sending the first frame of a data packet). This is an example:
 * @code
 *  SPI_command_config_t commandConfig;
 *  commandConfig.isPcsContinuous = true;
 *  commandConfig.whichCtar = kSPICtar0;
 *  commandConfig.whichPcs = kSPIPcs1;
 *  commandConfig.clearTransferCount = false;
 *  commandConfig.isEndOfQueue = false;
 *  SPI_MasterWriteDataBlocking(base, &commandConfig, dataWord);
 * @endcode
 *
 * Note that this function does not return until after the transmit is complete. Also note that the SPI must be
 * enabled and running in order to transmit data (MCR[MDIS] & [HALT] = 0). Since the SPI is a synchronous protocol,
 * receive data is available when transmit completes.
 *
 * @param base SPI peripheral address.
 * @param command Pointer to command structure.
 * @param data The data word to be sent.
 */
void SPI_MasterWriteDataBlocking(SPI_Type *base, spi_command_data_config_t *command, uint16_t data);

/*!
 * @brief Returns the SPI command word formatted to the PUSHR data register bit field.
 *
 * This function allows the caller to pass in the data command structure and returns the command word formatted
 * according to the SPI PUSHR register bit field placement. The user can then "OR" the returned command word with the
 * desired data to send and use the function SPI_HAL_WriteCommandDataMastermode or
 * SPI_HAL_WriteCommandDataMastermodeBlocking to write the entire 32-bit command data word to the PUSHR. This helps
 * improve performance in cases where the command structure is constant. For example, the user calls this function
 * before starting a transfer to generate the command word. When they are ready to transmit the data, they would OR
 * this formatted command word with the desired data to transmit. This process increases transmit performance when
 * compared to calling send functions such as SPI_HAL_WriteDataMastermode which format the command word each time a
 * data word is to be sent.
 *
 * @param command Pointer to command structure.
 * @return The command word formatted to the PUSHR data register bit field.
 */
static inline uint32_t SPI_MasterGetFormattedCommand(spi_command_data_config_t *command)
{
    /* Format the 16-bit command word according to the PUSHR data register bit field*/
    return (uint32_t)(SPI_PUSHTFR_CPCSE_SET(command->isPcsContinuous) | SPI_PUSHTFR_CLKTXAS_SET(command->whichCtar) |
                      SPI_PUSHTFR_SPCS_SET(command->whichPcs) | SPI_PUSHTFR_EQ_SET(command->isEndOfQueue) |
                      SPI_PUSHTFR_CTXCTR_SET(command->clearTransferCount));
}

/*!
 * @brief Writes a 32-bit data word (16-bit command appended with 16-bit data) into the data
 *        buffer, master mode and waits till complete to return.
 *
 * In this function, the user must append the 16-bit data to the 16-bit command info then provide the total 32-bit word
 * as the data to send.
 * The command portion provides characteristics of the data such as: optional continuous chip select operation between
 * transfers, the desired Clock and Transfer Attributes register to use for the associated SPI frame, the desired Pcs
 * signal to use for the data transfer, whether the current transfer is the last in the queue, and whether to clear the
 * transfer count (normally needed when sending the first frame of a data packet). The user is responsible for
 * appending this command with the data to send. This is an example:
 * @code
 *  dataWord = <16-bit command> | <16-bit data>;
 *  SPI_HAL_WriteCommandDataMastermodeBlocking(base, dataWord);
 * @endcode
 *
 * Note that this function does not return until after the transmit is complete. Also note that the SPI must be
 * enabled and running in order to transmit data (MCR[MDIS] & [HALT] = 0).
 * Since the SPI is a synchronous protocol, receive data is available when transmit completes.
 *
 *  For a blocking polling transfer , you can refer to below ways.
 *  Option 1:
*   uint32_t command_to_send = SPI_MasterGetFormattedCommand(&command);
*   uint32_t data0 = command_to_send | data_need_to_send_0;
*   uint32_t data1 = command_to_send | data_need_to_send_1;
*   uint32_t data2 = command_to_send | data_need_to_send_2;
*
*   SPI_MasterWriteCommandDataBlocking(base,data0);
*   SPI_MasterWriteCommandDataBlocking(base,data1);
*   SPI_MasterWriteCommandDataBlocking(base,data2);
*
*  Option 2:
*   SPI_MasterWriteDataBlocking(base,&command,data_need_to_send_0);
*   SPI_MasterWriteDataBlocking(base,&command,data_need_to_send_1);
*   SPI_MasterWriteDataBlocking(base,&command,data_need_to_send_2);
*
 * @param base SPI peripheral address.
 * @param data The data word (command and data combined) to be sent
 */
void SPI_MasterWriteCommandDataBlocking(SPI_Type *base, uint32_t data);

/*!
 * @brief Writes data into the data buffer, slave mode.
 *
 * In slave mode, up to 16-bit words may be written.
 *
 * @param base SPI peripheral address.
 * @param data The data to send.
 */
static inline void SPI_SlaveWriteData(SPI_Type *base, uint32_t data)
{
    base->PUSHTFR_SLV = data;
}

/*!
 * @brief Writes data into the data buffer, slave mode and waits till data was transmitted and return.
 *
 * In slave mode, up to 16-bit words may be written. The function first clears transmit complete flag then writes data
 * into data register, and finally wait tills the data is transmitted.
 *
 * @param base SPI peripheral address.
 * @param data The data to send.
 */
void SPI_SlaveWriteDataBlocking(SPI_Type *base, uint32_t data);

/*!
 * @brief Reads data from the data buffer.
 *
 * @param base SPI peripheral address.
 * @return The data from the read data buffer.
 */
static inline uint32_t SPI_ReadData(SPI_Type *base)
{
    return (base->POPRFR);
}

/*!
 * @brief SPI master transfer data using polling
 *
 * This function transfer data with polling, this is blocking function, will not return until all transfer have been
 * completed.
 *
 * @param base SPI peripheral base address.
 * @param transfer pointer to SPI_transfer_t structure.
 * @return status of sstat_t.
 */
sstat_t SPI_MasterTransferBlocking(SPI_Type *base, spi_transfer_t *transfer);

/*!
 *@}
*/

/*!
 * @name Transactional
 * @{
 */
/*Transactional APIs*/

/*!
 * @brief Initialize the SPI master handle.
 *
 * This function initializes the SPI handle which can be used for other SPI transactional APIs.  Usually, for a
 * specified SPI instance, user need only call this API once to get the initialized handle.
 *
 * @param base SPI peripheral base address.
 * @param handle SPI handle pointer to SPI_master_handle_t.
 * @param callback SPI callback.
 * @param userData callback function parameter.
 */
void SPI_MasterCreateHandle(SPI_Type *base,
                             spi_master_handle_t *handle,
                             spi_master_transfer_callback_t callback,
                             void *userData);

/*!
 * @brief SPI master transfer data using interrupt
 *
 * This function transfer data using interrupt , this is non-blocking function, will return right away, when all data
 * have been transfer, the callback function will be called.

 * @param base SPI peripheral base address.
 * @param handle pointer to SPI_master_handle_t structure which stores the transfer state.
 * @param transfer pointer to SPI_transfer_t structure.
 * @return status of sstat_t.
 */
sstat_t SPI_MasterTransferNonBlocking(SPI_Type *base, spi_master_handle_t *handle, spi_transfer_t *transfer);

/*!
 * @brief Get the master transfer remaining bytes.
 *
 * This function get the master transfer remaining bytes.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to SPI_master_handle_t structure which stores the transfer state.
 * @return remaining bytes of size_t.
 */
static inline size_t SPI_MasterGetTransferRemainingBytes(SPI_Type *base, spi_master_handle_t *handle)
{
    return handle->remainingReceiveByteCount;
}

/*!
 * @brief SPI master abort transfer which using interrupt.
 *
 * This function abort transfer which using interrupt.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to SPI_master_handle_t structure which stores the transfer state.
 */
void SPI_MasterAbortTransfer(SPI_Type *base, spi_master_handle_t *handle);

/*!
 * @brief SPI Master IRQ handler function
 *
 * This function process the SPI transmit and receive IRQ.

 * @param base SPI peripheral base address.
 * @param handle pointer to SPI_master_handle_t structure which stores the transfer state.
 */
void SPI_MasterHandleInterrupt(SPI_Type *base, spi_master_handle_t *handle);

/*!
 * @brief Initialize the SPI slave handle.
 *
 * This function initializes the SPI handle which can be used for other SPI transactional APIs.  Usually, for a
 * specified SPI instance, user need only call this API once to get the initialized handle.
 *
 * @param handle SPI handle pointer to SPI_slave_handle_t.
 * @param base SPI peripheral base address.
 * @param callback SPI callback.
 * @param userData callback function parameter.
 */
void SPI_SlaveCreateHandle(SPI_Type *base,
                            spi_slave_handle_t *handle,
                            spi_slave_transfer_callback_t callback,
                            void *userData);

/*!
 * @brief SPI slave transfer data using interrupt
 *
 * This function transfer data using interrupt , this is non-blocking function, will return right away, when all data
 * have been transfer, the callback function will be called.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to SPI_slave_handle_t structure which stores the transfer state.
 * @param transfer pointer to SPI_transfer_t structure.
 * @return status of sstat_t.
 */
sstat_t SPI_SlaveTransferNonBlocking(SPI_Type *base, spi_slave_handle_t *handle, spi_transfer_t *transfer);

/*!
 * @brief Get the slave transfer remaining bytes.
 *
 * This function get the slave transfer remaining bytes.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to SPI_slave_handle_t structure which stores the transfer state.
 * @return remaining bytes of size_t.
 */
static inline size_t SPI_SlaveGetTransferRemainingBytes(SPI_Type *base, spi_slave_handle_t *handle)
{
    return handle->remainingReceiveByteCount;
}

/*!
 * @brief SPI slave abort transfer which using interrupt.
 *
 * This function abort transfer which using interrupt.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to SPI_slave_handle_t structure which stores the transfer state.
 */
void SPI_SlaveAbortTransfer(SPI_Type *base, spi_slave_handle_t *handle);

/*!
 * @brief SPI Master IRQ handler function.
 *
 * This function process the SPI transmit and receive IRQ.
 *
 * @param base SPI peripheral base address.
 * @param handle pointer to SPI_slave_handle_t structure which stores the transfer state.
 */
void SPI_SlaveHandleInterrupt(SPI_Type *base, spi_slave_handle_t *handle);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // SPI_H
