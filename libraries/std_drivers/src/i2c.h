/*
  ******************************************************************************
  * @file           : i2c.h
  * @brief          : i2c hal driver header file
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
#ifndef I2C_H
#define I2C_H

#ifdef __cplusplus
extern "C" {
#endif
//I2C mode
#include <stdint.h>
#include "hw_i2c.h"
#include "sp28038.h"
#include "debug.h"
#include "sp28038_device.h"
//********************************************************
// * @brief I2C Control Set register description
//********************************************************
#define I2C_CONSET_AA             ((0x04))/*!< Assert acknowledge flag */
#define I2C_CONSET_SI             ((0x08))/*!< I2C interrupt flag */
#define I2C_CONSET_STO            ((0x10))/*!< STOP flag */
#define I2C_CONSET_STA            ((0x20))/*!< START flag */
#define I2C_CONSET_I2CEN          ((0x40))/*!< I2C interface enable */
#define I2C_CONSET_I2CINTEN       ((0x80))/*!< I2C interrupt enable */

//********************************************************
// * @brief I2C Control Clear register description
//********************************************************
#define I2C_CONCLR_AAC            (0x04)        /*!< Assert acknowledge Clear bit */
#define I2C_CONCLR_SIC            (0x08)        /*!< I2C interrupt Clear bit */
#define I2C_CONCLR_STAC           (0x20)        /*!< START flag Clear bit */
#define I2C_CONCLR_I2ENC          (0x40)        /*!< I2C interface Disable bit */

//********************************************************
// @brief I2C Status Code definition (I2C Status register)
//********************************************************
#define I2C_STAT_CODE_BITMASK       ((0xF8))/*!< Return Code mask in I2C status register */
#define I2C_STAT_CODE_ERROR         ((0xFF))/*!< Return Code error mask in I2C status register */

//********************************************************
//* @brief I2C Master transmit mode
//********************************************************
#define I2C_BUS_ERROR                                                                                                   0                               /* Bus Error */
#define I2C_STAT_M_TX_START                   ((0x08))/*!< A start condition has been transmitted */
#define I2C_STAT_M_TX_RESTART                 ((0x10))/*!< A repeat start condition has been transmitted */
#define I2C_STAT_M_TX_SLAW_ACK                ((0x18))/*!< SLA+W has been transmitted, ACK has been received */
#define I2C_STAT_M_TX_SLAW_NACK               ((0x20))/*!< SLA+W has been transmitted, NACK has been received */
#define I2C_STAT_M_TX_DAT_ACK                 ((0x28))/*!< Data has been transmitted, ACK has been received */
#define I2C_STAT_M_TX_DAT_NACK                ((0x30))/*!< Data has been transmitted, NACK has been received */
#define I2C_STAT_M_TX_ARB_LOST                ((0x38))/*!< Arbitration lost in SLA+R/W or Data bytes */

//********************************************************
//* @brief I2C Master receive mode
//********************************************************
#define I2C_STAT_M_RX_START                   ((0x08))/*!< A start condition has been transmitted */
#define I2C_STAT_M_RX_RESTART                 ((0x10))/*!< A repeat start condition has been transmitted */
#define I2C_STAT_M_RX_ARB_LOST                ((0x38))/*!< Arbitration lost */
#define I2C_STAT_M_RX_SLAR_ACK                ((0x40))/*!< SLA+R has been transmitted, ACK has been received */
#define I2C_STAT_M_RX_SLAR_NACK               ((0x48))/*!< SLA+R has been transmitted, NACK has been received */
#define I2C_STAT_M_RX_DAT_ACK                 ((0x50))/*!< Data has been received, ACK has been returned */
#define I2C_STAT_M_RX_DAT_NACK                ((0x58))/*!< Data has been received, NACK has been returned */

//********************************************************
//* @brief I2C Slave receive mode
//********************************************************
#define I2C_STAT_S_RX_SLAW_ACK                ((0x60))/*!< Own slave address has been received, ACK has been returned */
#define I2C_STAT_S_RX_ARB_LOST_M_SLA          ((0x68))/*!< Arbitration lost in SLA+R/W as master */
// #define I2C_I2STAT_S_RX_SLAW_ACK                             ((0x68)) /*!< Own SLA+W has been received, ACK returned */
#define I2C_STAT_S_RX_GENCALL_ACK             ((0x70))/*!< General call address has been received, ACK has been returned */
#define I2C_STAT_S_RX_ARB_LOST_M_GENCALL      ((0x78))/*!< Arbitration lost in SLA+R/W (GENERAL CALL) as master */
// #define I2C_I2STAT_S_RX_GENCALL_ACK                          ((0x78)) /*!< General call address has been received, ACK has been returned */
#define I2C_STAT_S_RX_PRE_SLA_DAT_ACK         ((0x80))/*!< Previously addressed with own SLA; Data has been received, ACK has been returned */
#define I2C_STAT_S_RX_PRE_SLA_DAT_NACK        ((0x88))/*!< Previously addressed with own SLA;Data has been received and NOT ACK has been returned */
#define I2C_STAT_S_RX_PRE_GENCALL_DAT_ACK     ((0x90))/*!< Previously addressed with General Call; Data has been received and ACK has been returned */
#define I2C_STAT_S_RX_PRE_GENCALL_DAT_NACK    ((0x98))/*!< Previously addressed with General Call; Data has been received and NOT ACK has been returned */
#define I2C_STAT_S_RX_STA_STO_SLVREC_SLVTRX   ((0xA0))/*!< A STOP condition or repeated START condition has been received while still addressed as 
                                                           SLV/REC (Slave Receive) or SLV/TRX (Slave Transmit) */

//********************************************************
// * @brief I2C Slave transmit mode
//********************************************************
#define I2C_STAT_S_TX_SLAR_ACK                ((0xA8))/*!< Own SLA+R has been received, ACK has been returned */
#define I2C_STAT_S_TX_ARB_LOST_M_SLA          ((0xB0))/*!< Arbitration lost in SLA+R/W as master */
// #define I2C_I2STAT_S_TX_SLAR_ACK                             ((0xB0)) /*!< Own SLA+R has been received, ACK has been returned */
#define I2C_STAT_S_TX_DAT_ACK                 ((0xB8))/*!< Data has been transmitted, ACK has been received */
#define I2C_STAT_S_TX_DAT_NACK                ((0xC0))/*!< Data has been transmitted, NACK has been received */
#define I2C_STAT_S_TX_LAST_DAT_ACK            ((0xC8))/*!< Last data byte in I2DAT has been transmitted (AA = 0); ACK has been received */

#define I2C_STAT_S_TX_LAST_DAT_NACK           0xD0 // Last byte transmitted in slave mode, Not ACK received
#define I2C_STAT_SEC_ADDR_ACK                 0xE0 // Second Address byte transmitted, ACK received
#define I2C_STAT_SEC_ADDR_NACK                0xE8 // Second Address byte transmitted, Not ACK received

#define I2C_SLAVE_TIME_OUT                      0x10000000UL/*!< Time out in case of using I2C slave mode */


/***************************** I2C Master *******************************/
typedef struct {
        uint8_t slaveAddr;              /*!< 7-bit I2C Slave address */
        uint8_t options;                /*!< Options for transfer*/
        uint16_t status;                /*!< Status of the current I2C transfer */
        uint16_t txSz;                  /*!< Number of bytes in transmit array,
                                                           if 0 only receive transfer will be carried on */
        uint16_t rxSz;                  /*!< Number of bytes to received,
                                                           if 0 only transmission we be carried on */
        uint8_t *txBuff;        /*!< Pointer to array of bytes to be transmitted */
        uint8_t *rxBuff;                /*!< Pointer memory where bytes received from I2C be stored */
} I2C_XFER_Type;

/***************************** I2C Slave **************************************************/

typedef enum I2C_ID {
    I2C1_ID,                                /**< ID I2C1 */
    I2C2_ID,                                /**< ID I2C2 */
    I2C_NUM_INTERFACE       /**< Number of I2C interfaces in the chip */
} I2C_ID_T;
typedef enum {
    I2C_SLAVE_GENERAL,      /**< Slave ID for general calls */
    I2C_SLAVE_0,            /**< Slave ID fo Slave Address 0 */
    I2C_SLAVE_1,            /**< Slave ID fo Slave Address 1 */
    I2C_SLAVE_2,            /**< Slave ID fo Slave Address 2 */
    I2C_SLAVE_3,            /**< Slave ID fo Slave Address 3 */
    I2C_SLAVE_NUM_INTERFACE /**< Number of slave interfaces */
} I2C_SLAVE_ID;
/**
* @brief       I2C master events
*/
typedef enum {
    I2C_EVENT_WAIT = 1,     /**< I2C Wait event */
    I2C_EVENT_DONE,         /**< Done event that wakes up Wait event */
    I2C_EVENT_LOCK,         /**< Re-entrency lock event for I2C transfer */
    I2C_EVENT_UNLOCK,       /**< Re-entrency unlock event for I2C transfer */
    I2C_EVENT_SLAVE_RX,     /**< Slave receive event */
    I2C_EVENT_SLAVE_TX,     /**< Slave transmit event */
} I2C_EVENT_T;


#define RET_SLAVE_TX    6       /**< Return value, when 1 byte TX'd successfully */
                                                                                                  

#define RET_SLAVE_RX    5       /**< Return value, when 1 byte RX'd successfully */
#define RET_SLAVE_IDLE  2       /**< Return value, when slave enter idle mode */
#define RET_SLAVE_BUSY  0       /**< Return value, when slave is busy */
/**
* @brief       I2C transfer status
*/
typedef enum {
    I2C_STATUS_DONE,        /**< Transfer done successfully */
    I2C_STATUS_NAK,         /**< NAK received during transfer */
    I2C_STATUS_ARBLOST,     /**< Aribitration lost during transfer */
    I2C_STATUS_BUSERR,      /**< Bus error in I2C transfer */
    I2C_STATUS_BUSY,        /**< I2C is busy doing transfer */
    I2C_STATUS_SLAVENAK,/**< NAK received after SLA+W or SLA+R */
} I2C_STATUS_T;

/** Ignore NACK during data transfer. By default transfer is aborted. */
#define I2CM_XFER_OPTION_IGNORE_NACK     0x01
/** ACK last byte received. By default we NACK last byte we receive per I2C spec. */
#define I2CM_XFER_OPTION_LAST_RX_ACK     0x02



#define I2CM_STATUS_OK              0x00                /*!< Requested Request was executed successfully. */
#define I2CM_STATUS_ERROR           0x01                /*!< Unknown error condition. */
#define I2CM_STATUS_NAK             0x02                /*!< No acknowledgement received from slave. */
#define I2CM_STATUS_BUS_ERROR       0x03                /*!< I2C bus error */
#define I2CM_STATUS_SLAVE_NAK       0x04                /*!< No device responded for given slave address during SLA+W or SLA+R */
#define I2CM_STATUS_ARBLOST         0x05                /*!< Arbitration lost. */
#define I2CM_STATUS_BUSY            0xFF                /*!< I2C transmitter is busy. */

/* Control flags */
#define I2C_CON_FLAGS (I2C_CONSET_AA | I2C_CONSET_SI | I2C_CONSET_STO | I2C_CONSET_STA)

#define I2C_StateChanged(i2c)   i2c->CONSET & I2C_CONSET_SI

#define   I2C_BusFree(i2c) !(i2c->CONSET & I2C_CON_FLAGS)

#define  I2C_GetCurState(i2c) i2c->STAT & I2C_STAT_CODE_BITMASK
//*****************************************************************************
//
//! \internal
//! Checks an I2C base address.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function determines if a I2C module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static inline bool
I2C_isBaseValid(uint32_t base)
{
    return(
           (base == I2CA_BASE) ||
           (base == I2CB_BASE)
          );
}
#endif
static inline I2C_TypeDef*
I2C_Pointer_Convert(uint32_t i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    return (I2C_TypeDef *)i2c;
}
static inline void
I2C_Master_SendStart(I2C_TypeDef *i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    i2c->CONSET = I2C_CONSET_I2CEN | I2C_CONSET_STA;
    //HWREG(i2c_base + I2C_O_CONSET) = I2C_CONSET_I2CEN | I2C_CONSET_STA;
}
static inline void
I2C_Master_ResetControl(I2C_TypeDef *i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    i2c->CONCLR = I2C_CONCLR_SIC | I2C_CONCLR_STAC | I2C_CONCLR_AAC;
    //HWREG(i2c_base + I2C_O_CONCLR) = I2C_CONCLR_SIC | I2C_CONCLR_STAC | I2C_CONCLR_AAC;
}
static inline void
I2C_Master_WriteByte(I2C_TypeDef *i2c, uint8_t data)
{
    ASSERT(I2C_isBaseValid(i2c));
    i2c->DAT = data;
    //HWREG(i2c_base + I2C_O_DAT) = （uint32_t）data;
}

static inline uint32_t
I2C_Master_ReadByte(I2C_TypeDef *i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    return i2c->DAT;
    //return HWREG(i2c_base + I2C_O_DAT);
}

static inline uint32_t
I2C_Master_NackNextByte(I2C_TypeDef *i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    i2c->CONCLR = I2C_CONCLR_AAC;
    //HWREG(i2c_base + I2C_O_CONCLR) = I2C_CONCLR_AAC;
    return 0;
}
static inline void
I2C_Master_SendStop(I2C_TypeDef *i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    i2c->CONSET = I2C_CONSET_STO;
    //HWREG(i2c_base + I2C_O_CONSET) = I2C_CONSET_STO;
}
static inline void
I2C_Master_ForceStart(I2C_TypeDef *i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    if (i2c->CONSET & I2C_CONSET_STA)
        i2c->CONSET = I2C_CON_FLAGS;
    else      
        I2C_Master_SendStart(i2c);
    /*if (HWREG(i2c_base + I2C_O_CONSET) & I2C_CONSET_STA)
        HWREG(i2c_base + I2C_O_CONSET) = I2C_CON_FLAGS;
    else
        I2C_Master_SendStart(i2c_base);*/
}

static inline void
I2C_Master_SendStartAfterStop(I2C_TypeDef *i2c) 
{
    ASSERT(I2C_isBaseValid(i2c));
    i2c->CONSET = I2C_CONSET_STO | I2C_CONSET_STA;
    //HWREG(i2c_base + I2C_O_CONSET) = I2C_CONSET_STO | I2C_CONSET_STA;
}

static inline void
I2C_ClearSI(I2C_TypeDef *i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    i2c->CONCLR = I2C_CONCLR_SIC | I2C_CONCLR_STAC;
    //HWREG(i2c_base + I2C_O_CONCLR) = I2C_CONCLR_SIC | I2C_CONCLR_STAC;
}

//*****************************************************************************
//
//! Enables the I2C module
//!
//! \param base is the base address of the I2C module
//!
//! This function enables the I2C module operation.
//!
//! \return None
//
//*****************************************************************************
//*****************************************************************************
//
//! Enables the I2C module
//!
//! \param i2c is the base address of the I2C module
//!
//! This function enables the I2C module operation.
//!
//! \return None
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
static inline
void I2C_enableModule(I2C_TypeDef *i2c)
{
    ASSERT(I2C_isBaseValid(i2c));
    //HWREG(base + I2C_CON) |= I2C_CON_I2CEN;
    i2c->CONSET = I2C_CONSET_I2CEN;
}

//*****************************************************************************
//
//! Disables the I2C module
//!
//! \param base is the base address of the I2C module
//!
//! This function disables the I2C module operation.
//!
//! \return None
//
//*****************************************************************************
//*****************************************************************************
//
//! Disables the I2C module
//!
//! \param i2c is the base address of the I2C module
//!
//! This function disables the I2C module operation.
//!
//! \return None
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
static inline void
I2C_disableModule(I2C_TypeDef *i2c) 
{
    ASSERT(I2C_isBaseValid(i2c));
    i2c->CONCLR = I2C_CONCLR_I2ENC;
    //HWREG(i2c_base + I2C_O_CONCLR) = I2C_CONCLR_I2ENC;
}

/**
 * @brief Handles I2C master transfer state machine
 * @param i2c Pointer to I2C peripheral register structure
 * @param xfer Pointer to transfer structure containing transfer parameters
 * @return Status of the transfer (I2C_STATUS_T)
 */
//*****************************************************************************
//
//! Handles I2C master transfer state machine
//!
//! \param i2c is the base address of the I2C module
//! \param xfer is the pointer to transfer structure
//!
//! This function handles the I2C master transfer state machine.
//!
//! \return Status of the transfer (I2C_STATUS_T)
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
uint32_t I2C_Master_XferHandler(I2C_TypeDef *i2c, I2C_XFER_Type *xfer);

/**
 * @brief Initiates non-blocking I2C master transfer
 * @param i2c Pointer to I2C peripheral register structure
 * @param xfer Pointer to transfer structure containing transfer parameters
 */
//*****************************************************************************
//
//! Initiates non-blocking I2C master transfer
//!
//! \param i2c is the base address of the I2C module
//! \param xfer is the pointer to transfer structure
//!
//! This function initiates a non-blocking I2C master transfer.
//!
//! \return None
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
void I2C_Master_Xfer(I2C_TypeDef *i2c, I2C_XFER_Type *xfer);

/**
 * @brief Performs blocking I2C master transfer
 * @param i2c Pointer to I2C peripheral register structure
 * @param xfer Pointer to transfer structure containing transfer parameters
 * @return Status of the transfer (I2C_STATUS_T)
 */
//*****************************************************************************
//
//! Performs blocking I2C master transfer
//!
//! \param i2c is the base address of the I2C module
//! \param xfer is the pointer to transfer structure
//!
//! This function performs a blocking I2C master transfer.
//!
//! \return Status of the transfer (I2C_STATUS_T)
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
uint32_t I2C_Master_XferBlocking(I2C_TypeDef *i2c, I2C_XFER_Type *xfer);

/**
 * @brief Writes data to I2C slave device
 * @param i2c Pointer to I2C peripheral register structure
 * @param buff Pointer to data buffer to transmit
 * @param len Number of bytes to write
 * @return Status of the transfer (I2C_STATUS_T)
 */
//*****************************************************************************
//
//! Writes data to I2C slave device
//!
//! \param i2c is the base address of the I2C module
//! \param buff is the pointer to data buffer
//! \param len is the number of bytes to write
//!
//! This function writes data to an I2C slave device.
//!
//! \return Status of the transfer (I2C_STATUS_T)
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
uint32_t I2C_Master_Write(I2C_TypeDef *i2c, const uint8_t *buff, uint32_t len);

/**
 * @brief Reads data from I2C slave device
 * @param i2c Pointer to I2C peripheral register structure
 * @param buff Pointer to buffer to store received data
 * @param len Number of bytes to read
 * @return Status of the transfer (I2C_STATUS_T)
 */
//*****************************************************************************
//
//! Reads data from I2C slave device
//!
//! \param i2c is the base address of the I2C module
//! \param buff is the pointer to buffer to store received data
//! \param len is the number of bytes to read
//!
//! This function reads data from an I2C slave device.
//!
//! \return Status of the transfer (I2C_STATUS_T)
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
uint32_t I2C_Master_Read(I2C_TypeDef *i2c, uint8_t *buff, uint32_t len);

/**
 * @brief Sets slave address and mask for specific slave ID
 * @param i2c Pointer to I2C peripheral register structure
 * @param sid Slave ID (I2C_SLAVE_ID)
 * @param addr 7-bit slave address
 * @param mask Address mask for address matching
 */
//*****************************************************************************
//
//! Sets slave address and mask for specific slave ID
//!
//! \param i2c is the base address of the I2C module
//! \param sid is the slave ID (I2C_SLAVE_ID)
//! \param addr is the 7-bit slave address
//! \param mask is the address mask for address matching
//!
//! This function sets the slave address and mask for a specific slave ID.
//!
//! \return None
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
void I2C_Set_Slave_Addr(I2C_TypeDef *i2c, I2C_SLAVE_ID sid, uint8_t addr, uint8_t mask);

/**
 * @brief Handles I2C slave transfer state machine
 * @param i2c Pointer to I2C peripheral register structure
 * @param xfer Pointer to transfer structure containing transfer parameters
 * @return Status of the transfer (I2C_STATUS_T)
 */
//*****************************************************************************
//
//! Handles I2C slave transfer state machine
//!
//! \param i2c is the base address of the I2C module
//! \param xfer is the pointer to transfer structure
//!
//! This function handles the I2C slave transfer state machine.
//!
//! \return Status of the transfer (I2C_STATUS_T)
//!
//! \note Copyright (c) 2025 starpower.inc
//
//*****************************************************************************
uint32_t I2C_Slave_XferHandler(I2C_TypeDef *i2c, I2C_XFER_Type *xfer);


#ifdef __cplusplus
}
#endif

#endif // I2C_H
