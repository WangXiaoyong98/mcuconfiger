/*
  ******************************************************************************
  * @file           : i2c.c
  * @brief          : i2c hal program body
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
#include "i2c.h"
#include "hw_i2c.h"
#include "hw_types.h"

//*****************************************************************************
//
//! Initializes the I2C controller
//!
//! \param base is the base address of the I2C module
//! \param sysclkHz is the frequency of the system clock in Hz
//! \param bitRate is the desired I2C bit rate in Hz
//!
//! This function initializes the I2C controller by configuring the clock
//! and setting up the module for operation.
//!
//! \return None
//
//*****************************************************************************
void I2C_Init(I2C_TypeDef *i2c)
{
    /* Enable I2C clock */
    switch  ((uint32_t)i2c)
    {
        case (uint32_t)I2C1:
            SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_I2C1_MASK;
            SYSCTRL->SOFTRST1 |= SYSCTRL_SOFTRST1_I2C1RST_MASK;
            SYSCTRL->SOFTRST1 &= ~SYSCTRL_SOFTRST1_I2C1RST_MASK;
            break;
        case (uint32_t)I2C2:
            SYSCTRL->ISP1CGC3 |= SYSCTRL_ISP1CGC3_I2C2_MASK;
            SYSCTRL->SOFTRST1 |= SYSCTRL_SOFTRST1_I2C2RST_MASK;
            SYSCTRL->SOFTRST1 &= ~SYSCTRL_SOFTRST1_I2C2RST_MASK;
            break;
        default:
            return;
        }
    /* Reset I2C state machine */
    /* Reset STA, AA and SI. Stop flag should not be cleared as it is a reserved bit */
    i2c->CONCLR = I2C_CONCLR_AAC_MASK |I2C_CONCLR_SIC_MASK | I2C_CONCLR_STAC_MASK;
    i2c->CONSET = I2C_CONSET_AA_MASK | I2C_CONSET_I2CEN_MASK | I2C_CONSET_I2CIE_MASK;
}
//*****************************************************************************
//
//! Initializes the I2C controller Clock
//!
//! \param base is the base address of the I2C module
//! \param sysclkHz is the frequency of the system clock in Hz
//! \param bitRate is the desired I2C bit rate in Hz
//!
//! This function initializes the I2C controller by configuring the clock
//! and setting up the module for operation.
//!
//! \return None
//
//*****************************************************************************
void I2C_initController(I2C_TypeDef *i2c, uint32_t sysclkHz, uint32_t bitRate)
{
    uint32_t n,m;
    uint32_t i;
    float temp;
    if(bitRate==0)
        return FAIL;
    if(sysclkHz<bitRate)
        return FAIL;
    
    for(m=0;m<8;m++)
    {
        if(sysclkHz>>m) < (bitRate*16*10))      //16 is maximum of n+1
        {
            temp = (sysclkHz>>m)/((float)bitRate*10);
            n = (sysclkHz>>m)/(bitRate*10);
            if((temp-(float)n)>=0.5)
                n=(int)temp;
            break;
        }
    }
    if(m==8)
        return FAIL;

    i2c->CLK = (m<<4) | n;
    //HWREG(base + I2C_O_CLK) = (m<<4) | n;
    return SUCCESS;

}

/*****************************************************************************
Function Name    I2C_Master_XferHandler
Function Definition     uint32_t I2C_Master_XferHandler(I2C_TypeDef *i2c, I2C_XFER_Type *xfer)
Function Description    Transfer state change handler
Input Parameters        *i2c : pointer to i2c, I2C0/I2C1
xfer    : Pointer to a I2CM_XFER_T structure see notes below
Return Value    Returns non-zero value on completion of transfer. The @a status
          member of @a xfer structure contains the current status of the
                                        transfer at the end of the call.
Condition       No
Function called -

*****************************************************************************/
uint32_t I2C_Master_XferHandler(I2C_TypeDef *i2c, I2C_XFER_Type *xfer)
{
    uint32_t cclr = I2C_CON_FLAGS;

    switch (I2C_GetCurState(i2c)) {
        case I2C_STAT_M_TX_START:               /* Start condition on bus */
        case I2C_STAT_M_TX_RESTART:             /* Repeated start condition */
            i2c->DAT = (xfer->slaveAddr << 1) | (xfer->txSz == 0);
            break;

                /* Tx handling */
        case I2C_STAT_M_TX_SLAW_NACK:           /* SLA+W sent NAK received */
        case I2C_STAT_M_TX_DAT_NACK:            /* DATA sent NAK received */
            if ((xfer->options & I2CM_XFER_OPTION_IGNORE_NACK) == 0) {
                xfer->status = I2CM_STATUS_NAK;
                cclr &= ~I2C_CONSET_STO;
                break;
            }

        case I2C_STAT_M_TX_SLAW_ACK:            /* SLA+W sent and ACK received */
        case I2C_STAT_M_TX_DAT_ACK:             /* DATA sent and ACK received */
            if (!xfer->txSz) {
                if (xfer->rxSz) {
                    cclr &= ~I2C_CONSET_STA;
                }
                else {
                    xfer->status = I2CM_STATUS_OK;
                    cclr &= ~I2C_CONSET_STO;
                }

            }
            else {
                i2c->DAT = *xfer->txBuff++;
                xfer->txSz--;
            }
            break;

                /* Rx handling */
        case I2C_STAT_M_RX_DAT_NACK:            /* Data Received and NACK sent */
        case I2C_STAT_M_RX_DAT_ACK:             /* Data Received and ACK sent */
            *xfer->rxBuff++ = i2c->DAT;
            xfer->rxSz--;

        case I2C_STAT_M_RX_SLAR_ACK:            /* SLA+R sent and ACK received */
            if ((xfer->rxSz > 1) || (xfer->options & I2CM_XFER_OPTION_LAST_RX_ACK)) {
                cclr &= ~I2C_CONSET_AA;
                        }
            if (xfer->rxSz == 0) {
                xfer->status = I2CM_STATUS_OK;
                cclr &= ~I2C_CONSET_STO;
            }
            break;

       /* NAK Handling */
        case I2C_STAT_M_RX_SLAR_NACK:           /* SLA+R sent NAK received */
            xfer->status = I2CM_STATUS_SLAVE_NAK;
            cclr &= ~I2C_CONSET_STO;
            break;

        case I2C_STAT_M_TX_ARB_LOST:            /* Arbitration lost */
            xfer->status = I2CM_STATUS_ARBLOST;
            break;

        case I2C_BUS_ERROR:             /* Bus Error */
            xfer->status = I2CM_STATUS_BUS_ERROR;
            cclr &= ~I2C_CONSET_STO;
            break;

        default:
            xfer->status = I2CM_STATUS_ERROR;
            cclr &= ~I2C_CONSET_STO;
            break;
    }

    /* Set clear control flags */
    i2c->CONSET = cclr ^ I2C_CON_FLAGS;
    /* Stop flag should not be cleared as it is a reserved bit */
    i2c->CONCLR = cclr & (I2C_CONSET_AA | I2C_CONSET_SI | I2C_CONSET_STA);

    return xfer->status;
}
/*****************************************************************************
Function Name   I2C_Set_Slave_Addr
Function Definition     void I2C_Set_Slave_Addr(I2C_TypeDef *i2c, I2C_SLAVE_ID sid, uint8_t addr, uint8_t mask)
Function Description    Set up I2C slave address
Input Parameters        *i2c : pointer to i2c, I2C1/I2C2
uint32_t busSpeed: i2c slave address and address mask
Return Value    none
Condition       No
Function called -

*****************************************************************************/
void I2C_Set_Slave_Addr(I2C_TypeDef *i2c, I2C_SLAVE_ID sid, uint8_t addr, uint8_t mask)
{
    switch(sid)
    {
        case I2C_SLAVE_0:
            i2c->ADR0 = addr;
            i2c->ADRMASK0 = mask;
            break;
        case I2C_SLAVE_1:
            i2c->ADR1 = addr;
            i2c->ADRMASK1 = mask;
            break;
        case I2C_SLAVE_2:
            i2c->ADR2 = addr;
            i2c->ADRMASK2 = mask;
            break;
        case I2C_SLAVE_3:
            i2c->ADR3 = addr;
            i2c->ADRMASK3 = mask;
            break;
        case I2C_SLAVE_GENERAL:
            break;
        default:
            break;
    }
}
/*****************************************************************************
Function Name    I2C_Slave_XferHandler
Function Definition     uint32_t I2C_Slave_XferHandler(I2C_TypeDef *i2c, I2C_XFER_Type *xfer)
Function Description    Transfer state change handler
Input Parameters        *i2c : pointer to i2c, I2C1/I2C2
xfer    : Pointer to a I2C_XFER_Type structure see notes below
Return Value    Returns non-zero value on completion of transfer. The @a status
          member of @a xfer structure contains the current status of the
                                        transfer at the end of the call.
Condition       No
Function called -

*****************************************************************************/
uint32_t I2C_Slave_XferHandler(I2C_TypeDef *i2c, I2C_XFER_Type *xfer)
{
    uint32_t cclr = I2C_CON_FLAGS;
    int ret = RET_SLAVE_BUSY;

    xfer->status = I2C_STATUS_BUSY;
    switch (I2C_GetCurState(i2c))
    {
        case I2C_STAT_S_RX_PRE_SLA_DAT_ACK:             /* SLA: Data received + ACK sent */
        case I2C_STAT_S_RX_PRE_GENCALL_DAT_ACK:         /* GC: Data received + ACK sent */
            *xfer->rxBuff++ = i2c->DAT;

//          xfer->rxSz--;
            ret = RET_SLAVE_RX;
//          if (xfer->rxSz > 1) {
            cclr &= ~I2C_CONSET_AA;
//          }
            break;

        case I2C_STAT_S_RX_SLAW_ACK:            /* Own SLA+W received */
        case I2C_STAT_S_RX_ARB_LOST_M_SLA:              /* Own SLA+W received after losing arbitration */
        case I2C_STAT_S_RX_GENCALL_ACK:         /* GC+W received */
        case I2C_STAT_S_RX_ARB_LOST_M_GENCALL:          /* GC+W received after losing arbitration */
            xfer->slaveAddr = i2c->DAT & ~1;
//                      if (xfer->rxSz > 1
            cclr &= ~I2C_CONSET_AA;
//                      }
            break;

        case I2C_STAT_S_TX_SLAR_ACK:            /* SLA+R received */
        case I2C_STAT_S_TX_ARB_LOST_M_SLA:              /* SLA+R received after losing arbitration */
            xfer->slaveAddr = i2c->DAT & ~1;

        case I2C_STAT_S_TX_DAT_ACK:             /* DATA sent and ACK received */
            i2c->DAT = *xfer->txBuff++;
//                      xfer->txSz--;
//                      if (xfer->txSz > 0) {
            cclr &= ~I2C_CONSET_AA;
//                      }
            ret = RET_SLAVE_TX;
            break;

        case I2C_STAT_S_TX_DAT_NACK:            /* Data transmitted and NAK received */
        case I2C_STAT_S_TX_LAST_DAT_ACK:                /* Last data transmitted and ACK received */
        case I2C_STAT_S_RX_PRE_SLA_DAT_NACK:            /* SLA: Data received + NAK sent */
        case I2C_STAT_S_RX_PRE_GENCALL_DAT_NACK:                /* GC: Data received + NAK sent */
        case I2C_STAT_S_RX_STA_STO_SLVREC_SLVTRX:               /* STOP/Repeated START condition received */
            ret = RET_SLAVE_IDLE;
            cclr &= ~I2C_CONSET_AA;
            xfer->status = I2C_STATUS_DONE;
            if (xfer->slaveAddr & 1) {
                cclr &= ~I2C_CONSET_STA;
            }
            break;
    }

        /* Set clear control flags */
    i2c->CONSET = cclr ^ I2C_CON_FLAGS;
    i2c->CONCLR = cclr & ~I2C_CONSET_STO;

    return ret;
}
