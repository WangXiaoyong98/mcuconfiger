
#ifndef _SPI_DMA_H_
#define _SPI_DMA_H_

#include "spi.h"
#include "dma.h"
/*!
 * @addtogroup spi_dma_driver
 * @{
 */
/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*!
* @brief Forward declaration of the dspi edma master handle typedefs.
*/
typedef struct _spi_master_edma_handle spi_master_dma_handle_t;

/*!
* @brief Forward declaration of the dspi edma slave handle typedefs.
*/
typedef struct _spi_slave_edma_handle spi_slave_dma_handle_t;

/*!
 * @brief Completion callback function pointer type.
 *
 * @param base DSPI peripheral base address.
 * @param handle Pointer to the handle for the DSPI master.
 * @param status Success or error code describing whether the transfer completed.
 * @param userData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*spi_master_dma_transfer_callback_t)(SPI_Type *base,
                                                     spi_master_dma_handle_t *handle,
                                                     sstat_t status,
                                                     void *userData);
/*!
 * @brief Completion callback function pointer type.
 *
 * @param base DSPI peripheral base address.
 * @param handle Pointer to the handle for the DSPI slave.
 * @param status Success or error code describing whether the transfer completed.
 * @param userData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*spi_slave_dma_transfer_callback_t)(SPI_Type *base,
                                                    spi_slave_dma_handle_t *handle,
                                                    sstat_t status,
                                                    void *userData);

/*! @brief DSPI master edma transfer handle structure used for transactional API. */
struct _spi_master_edma_handle
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

    uint32_t rxBuffIfNull; /*!< Used if there is not rxData for DMA purpose.*/
    uint32_t txBuffIfNull; /*!< Used if there is not txData for DMA purpose.*/

    volatile uint8_t state; /*!< DSPI transfer state , _spi_transfer_state.*/

    spi_master_dma_transfer_callback_t callback; /*!< Completion callback. */
    void *userData;                                /*!< Callback user data. */

    DMA_handle_t *edmaRxRegToRxDataHandle;        /*!<DMA_handle_t handle point used for RxReg to RxData buff*/
    DMA_handle_t *edmaTxDataToIntermediaryHandle; /*!<DMA_handle_t handle point used for TxData to Intermediary*/
    DMA_handle_t *edmaIntermediaryToTxRegHandle;  /*!<DMA_handle_t handle point used for Intermediary to TxReg*/

    DMA_tcd_t dspiSoftwareTCD[2]; /*!<SoftwareTCD , internal used*/
};

/*! @brief DSPI slave edma transfer handle structure used for transactional API.*/
struct _spi_slave_edma_handle
{
    uint32_t bitsPerFrame;          /*!< Desired number of bits per frame. */
    volatile bool isThereExtraByte; /*!< Is there extra byte.*/

    uint8_t *volatile txData;                  /*!< Send buffer. */
    uint8_t *volatile rxData;                  /*!< Receive buffer. */
    volatile size_t remainingSendByteCount;    /*!< Number of bytes remaining to send.*/
    volatile size_t remainingReceiveByteCount; /*!< Number of bytes remaining to receive.*/
    size_t totalByteCount;                     /*!< Number of transfer bytes*/

    uint32_t rxBuffIfNull; /*!< Used if there is not rxData for DMA purpose.*/
    uint32_t txBuffIfNull; /*!< Used if there is not txData for DMA purpose.*/
    uint32_t txLastData;   /*!< Used if there is an extra byte when 16bits per frame for DMA purpose.*/

    volatile uint8_t state; /*!< DSPI transfer state.*/

    uint32_t errorCount; /*!< Error count for slave transfer.*/

    spi_slave_dma_transfer_callback_t callback; /*!< Completion callback. */
    void *userData;                               /*!< Callback user data. */

    DMA_handle_t *edmaRxRegToRxDataHandle; /*!<DMA_handle_t handle point used for RxReg to RxData buff*/
    DMA_handle_t *edmaTxDataToTxRegHandle; /*!<DMA_handle_t handle point used for TxData to TxReg*/

    DMA_tcd_t dspiSoftwareTCD[2]; /*!<SoftwareTCD , internal used*/
};

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus*/

/*Transactional APIs*/

/*!
 * @brief Initialize the DSPI master edma handle.
 *
 * This function initializes the DSPI edma handle which can be used for other DSPI transactional APIs.  Usually, for a
 * specified DSPI instance, user need only call this API once to get the initialized handle.
 *
 * Note that DSPI edma has separated(rx and tx , 2 source) or shared(rx  and tx is the same source) dma request source .
 * (1)For separated dma request source , you should enable and set the Rx DMAMUX source for edmaRxRegToRxDataHandle and
 * Tx DMAMUX source for edmaIntermediaryToTxRegHandle.
 * (2)For shared dma request source , you should enable and set the Rx/Rx DMAMUX source for edmaRxRegToRxDataHandle .
 *
 * @param base DSPI peripheral base address.
 * @param handle DSPI handle pointer to spi_master_dma_handle_t.
 * @param callback dspi callback.
 * @param userData callback function parameter.
 * @param edmaRxRegToRxDataHandle edmaRxRegToRxDataHandle pointer to DMA_handle_t.
 * @param edmaTxDataToIntermediaryHandle edmaTxDataToIntermediaryHandle pointer to DMA_handle_t.
 * @param edmaIntermediaryToTxRegHandle edmaIntermediaryToTxRegHandle pointer to DMA_handle_t.
 */
void SPI_MasterCreateDmaHandle(SPI_Type *base,
                                 spi_master_dma_handle_t *handle,
                                 spi_master_dma_transfer_callback_t callback,
                                 void *userData,
                                 DMA_handle_t *edmaRxRegToRxDataHandle,
                                 DMA_handle_t *edmaTxDataToIntermediaryHandle,
                                 DMA_handle_t *edmaIntermediaryToTxRegHandle);

/*!
 * @brief DSPI master transfer data using EDMA.
 *
 * This function transfer data using EDMA , this is non-blocking function, will return right away, when all data
 * have been transfer, the callback function will be called.
 *
 * @param base DSPI peripheral base address.
 * @param handle pointer to spi_master_dma_handle_t structure which stores the transfer state.
 * @param transfer pointer to spi_transfer_t structure.
 * @return status of sstat_t.
 */
sstat_t SPI_MasterTransferDMA(SPI_Type *base, spi_master_dma_handle_t *handle, spi_transfer_t *transfer);

/*!
 * @brief DSPI master abort transfer which using edma.
 *
 * This function abort transfer which using edma.
 *
 * @param base DSPI peripheral base address.
 * @param handle pointer to spi_master_dma_handle_t structure which stores the transfer state.
 */
void SPI_MasterAbortDMA(SPI_Type *base, spi_master_dma_handle_t *handle);

/*!
 * @brief Get the master edma transfer remaining bytes.
 *
 * This function get the master edma transfer remaining bytes.
 *
 * @param base DSPI peripheral base address.
 * @param handle pointer to spi_master_dma_handle_t structure which stores the transfer state.
 * @return remaining bytes of size_t.
 */
size_t SPI_MasterGetTransferRemainingBytesDMA(SPI_Type *base, spi_master_dma_handle_t *handle);

/*!
 * @brief Initialize the dspi slave edma handle.
 *
 * This function initializes the DSPI edma handle which can be used for other DSPI transactional APIs.  Usually, for a
 * specified DSPI instance, user need only call this API once to get the initialized handle.
 *
 * Note that DSPI edma has separated(rx and tx , 2 source) or shared(rx  and tx is the same source) dma request source .
 * (1)For separated dma request source , you should enable and set the Rx DMAMUX source for edmaRxRegToRxDataHandle and
 * Tx DMAMUX source for edmaTxDataToTxRegHandle.
 * (2)For shared dma request source , you should enable and set the Rx/Rx DMAMUX source for edmaRxRegToRxDataHandle .
 *
 * @param base DSPI peripheral base address.
 * @param handle DSPI handle pointer to spi_slave_dma_handle_t.
 * @param callback dspi callback.
 * @param userData callback function parameter.
 * @param edmaRxRegToRxDataHandle edmaRxRegToRxDataHandle pointer to DMA_handle_t.
 * @param edmaTxDataToTxRegHandle edmaTxDataToTxRegHandle pointer to DMA_handle_t.
 */
void SPI_SlaveCreateDmaHandle(SPI_Type *base,
                                spi_slave_dma_handle_t *handle,
                                spi_slave_dma_transfer_callback_t callback,
                                void *userData,
                                DMA_handle_t *edmaRxRegToRxDataHandle,
                                DMA_handle_t *edmaTxDataToTxRegHandle);

/*!
 * @brief DSPI slave transfer data using EDMA.
 *
 * This function transfer data using EDMA , this is non-blocking function, will return right away, when all data
 * have been transfer, the callback function will be called.
 *
 * Note that slave EDMA transfer cannot support the situation that transfer_size is 1 when the bitsPerFrame is greater
 * than 8 .

 * @param base DSPI peripheral base address.
 * @param handle pointer to spi_slave_dma_handle_t structure which stores the transfer state.
 * @param transfer pointer to spi_transfer_t structure.
 * @return status of sstat_t.
 */
sstat_t SPI_SlaveTransferDMA(SPI_Type *base, spi_slave_dma_handle_t *handle, spi_transfer_t *transfer);

/*!
 * @brief DSPI slave abort transfer which using edma.
 *
 * This function abort transfer which using edma.
 *
 * @param base DSPI peripheral base address.
 * @param handle pointer to spi_slave_dma_handle_t structure which stores the transfer state.
 */
void SPI_SlaveAbortDMA(SPI_Type *base, spi_slave_dma_handle_t *handle);

/*!
 * @brief Get the slave edma transfer remaining bytes.
 *
 * This function get the slave edma transfer remaining bytes.
 *
 * @param base DSPI peripheral base address.
 * @param handle pointer to spi_slave_dma_handle_t structure which stores the transfer state.
 * @return remaining bytes of size_t.
 */
size_t SPI_SlaveGetTransferRemainingBytesDMA(SPI_Type *base, spi_slave_dma_handle_t *handle);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
       /*!
        *@}
        */

#endif /*_FSL_spi_EDMA_H_*/
