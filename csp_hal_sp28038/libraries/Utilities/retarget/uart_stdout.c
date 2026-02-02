/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2010-2017   ARM Limited or its affiliates.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *      SVN Information
 *
 *      Checked In          : $Date: 2013-04-10 15:14:20 +0100 (Wed, 10 Apr 2013) $
 *
 *      Revision            : $Revision: 366156 $
 *
 *      Release Information : ME32F103-r2p1-00rel0
 *-----------------------------------------------------------------------------
 */

 /*

 UART functions for retargetting

 */
#include "sp28038.h"
/*
 * File:        uart.c
 * Purpose:     Provide common UART routines for serial IO
 *
 * Notes:       
 *              
 */
#define  UART   SCI1
/********************************************************************/
/*
 * Initialize the UART for 8N1 operation, interrupts disabled, and
 * no hardware flow-control
 *
 * NOTE: Since the UARTs are pinned out in multiple locations on most
 *       Kinetis devices, this driver does not enable UART pin functions.
 *       The desired pins should be enabled before calling this init function.
 *
 * Parameters:
 *  uartch      UART channel to initialize
 *  sysclk      UART module Clock in kHz(used to calculate baud)
 *  baud        UART baud rate
 */
void UartStdOutInit (int sysclk, int baud)
{
      UART->SCICTRL &= ~(SCI_CTRL_TXEN_MASK|SCI_CTRL_RXEN_MASK);
      UART->SCICNFG = SCI_CNFG_OSR_SET(3) + SCI_CNFG_TWOEDGE_MASK + SCI_CNFG_BRD_SET(sysclk/baud/4); //baud = clkin/((OSR+1)*SBR)
      UART->SCIRSIR = 0;
      UART->SCICTRL |= (SCI_CTRL_TXEN_MASK|SCI_CTRL_RXEN_MASK);

}
/********************************************************************/
/*
 * Wait for a character to be received on the specified UART
 *
 * Parameters:
 *  channel      UART channel to read from
 *
 * Return Values:
 *  the received character
 */
char UartGetc (void)
{
    /* Wait until character has been received */
  while (0U == (UART->SCISTATUS & SCI_STATUS_RDFF_MASK))
        {
        }
    /* Return the 8-bit data from the receiver */
  return  UART->SCIDATA;
}
/********************************************************************/
/*
 * Wait for space in the UART Tx FIFO and then send a character
 *
 * Parameters:
 *  channel      UART channel to send to
 *  ch			 character to send
 */ 
void UartPutc(char ch)
{
    /* Wait until space is available in the FIFO */
  while (0U == (UART->SCISTATUS & SCI_STATUS_TDREF_MASK))
        {
        }
  UART->SCIDATA = ch;    
    /* Send the character */
 }
/********************************************************************/
/*
 * Check to see if a character has been received
 *
 * Parameters:
 *  channel      UART channel to check for a character
 *
 * Return values:
 *  0       No character received
 *  1       Character has been received
 */
//int uart_getchar_present (UART_MemMapPtr channel)
//{
//    return (UART_S1_REG(channel) & UART_S1_RDRF_MASK);
//}
/********************************************************************/
    

#if 0
void UartStdOutInit(void)
{
  SSE050_UART0->BAUDDIV = 16;
  SSE050_UART0->CTRL    = 0x41; // High speed test mode, TX only
//  SSE050_GPIO1->ALTFUNCSET = (1<<5);
  return;
}
// Output a character
unsigned char UartPutc(unsigned char my_ch)
{
  while ((SSE050_UART0->STATE & 1)); // Wait if Transmit Holding register is full
  SSE050_UART0->DATA = my_ch; // write to transmit holding register
  return (my_ch);
}
// Get a character
unsigned char UartGetc(void)
{
  while ((SSE050_UART0->STATE & 2)==0); // Wait if Receive Holding register is empty
  return (SSE050_UART0->DATA);
}
#endif

void UartEndSimulation(void)
{
  UartPutc((char) 0x4); // End of simulation
  while(1);
}

