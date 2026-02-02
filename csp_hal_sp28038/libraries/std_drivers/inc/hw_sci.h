/*
  ******************************************************************************
  * @file           : hw_sci.h
  * @brief          : sci register map
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

#ifndef HW_SCI_H
#define HW_SCI_H

//*************************************************************************************************
//
// The following are defines for the SCI register offsets
//
//*************************************************************************************************
#define SCI_O_SCICNFG           0x0U    // SCI Configuration Register
#define SCI_O_SCISTATUS         0x4U    // SCI Status Register
#define SCI_O_SCICTRL           0x8U    // SCI Control Register
#define SCI_O_SCIDATA           0xCU    // SCI DATA Register
#define SCI_O_SCIMATCH          0x10U   // SCI Match Register
#define SCI_O_SCIRSIR           0x14U   // SCI IR and RS232 setting Register
#define SCI_O_SCIFCTL           0x18U   // SCI FIFO control Register
#define SCI_O_SCIWATMK          0x1CU   // SCI FIFO watermark Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCICNFG register
//
//*************************************************************************************************
#define SCI_CNFG_BRD_S       0U
#define SCI_CNFG_BRD_M       0x1FFU   // Baud Rate Modulo Divisor
#define SCI_CNFG_SBS_S       13U
#define SCI_CNFG_SBS_M       (1U << SCI_CNFG_SBS_S)    // Stop Bit Select
#define SCI_CNFG_RXEDGIE_S   14U
#define SCI_CNFG_RXEDGIE_M   (1U << SCI_CNFG_RXEDGIE_S)    // RX Edge Interrupt Enable
#define SCI_CNFG_LBDIE_S     15U
#define SCI_CNFG_LBDIE_M     (1U << SCI_CNFG_LBDIE_S)    // LIN Break Detect Interrupt Enable
#define SCI_CNFG_RESYNCDIS_S 16U
#define SCI_CNFG_RESYNCDIS_M (1U << SCI_CNFG_RESYNCDIS_S)    // Resynchronization Disable 
#define SCI_CNFG_TWOEDGE_S   17U
#define SCI_CNFG_TWOEDGE_M   (1U << SCI_CNFG_TWOEDGE_S)    // Both Edge Sampling
#define SCI_CNFG_MCFG_S      18U
#define SCI_CNFG_MCFG_M      (0x3U << SCI_CNFG_MCFG_S)    // Match Configuration
#define SCI_CNFG_RESERVED1_S 20U
#define SCI_CNFG_RESERVED1_M (1U << SCI_CNFG_RESERVED1_S)    // Reserved
#define SCI_CNFG_RDMAEN_S    21U
#define SCI_CNFG_RDMAEN_M    (1U << SCI_CNFG_RDMAEN_S)    // Receiver Full DMA Enable
#define SCI_CNFG_RRESERVED2_S 22U
#define SCI_CNFG_RRESERVED2_M (1U << SCI_CNFG_RRESERVED2_S)    // Reserved
#define SCI_CNFG_TDMAEN_S    23U
#define SCI_CNFG_TDMAEN_M    (1U << SCI_CNFG_TDMAEN_S)    // Transmitter DMA Enable
#define SCI_CNFG_OSR_S       24U
#define SCI_CNFG_OSR_M       (0x1FU << SCI_CNFG_OSR_S)    // Over Sampling Ratio
#define SCI_CNFG_TMOD_S      29U
#define SCI_CNFG_TMOD_M      (1U << SCI_CNFG_TMOD_S)    // 10-bit Mode Select
#define SCI_CNFG_MAEN2_S     30U
#define SCI_CNFG_MAEN2_M     (1U << SCI_CNFG_MAEN2_S)    // Match Address Mode Enable 2
#define SCI_CNFG_MAEN1_S     31U
#define SCI_CNFG_MAEN1_M     (1U << SCI_CNFG_MAEN1_S)    // Match Address Mode Enable 1
//*************************************************************************************************
//
// The following are defines for the bit fields in the SCISTAT register
//
//*************************************************************************************************
#define SCI_STAT_M2F_S        14U
#define SCI_STAT_M2F_M        (1U << SCI_STAT_M2F_S)    // Match 2 Flag
#define SCI_STAT_M1F_S        15U
#define SCI_STAT_M1F_M        (1U << SCI_STAT_M1F_S)    // Match 1 Flag
#define SCI_STAT_PEF_S        16U
#define SCI_STAT_PEF_M        (1U << SCI_STAT_PEF_S)    // Parity Error Flag
#define SCI_STAT_FEF_S        17U
#define SCI_STAT_FEF_M        (1U << SCI_STAT_FEF_S)    // Framing Error Flag
#define SCI_STAT_NOIF_S       18U
#define SCI_STAT_NOIF_M       (1U << SCI_STAT_NOIF_S)    // Noise Flag
#define SCI_STAT_ROF_S        19U
#define SCI_STAT_ROF_M        (1U << SCI_STAT_ROF_S)    // Receiver Overrun Flag
#define SCI_STAT_IDLF_S       20U
#define SCI_STAT_IDLF_M       (1U << SCI_STAT_IDLF_S)    // Idle Line Flag
#define SCI_STAT_RDFF_S       21U
#define SCI_STAT_RDFF_M       (1U << SCI_STAT_RDFF_S)    // Receive Data Register Full Flag
#define SCI_STAT_TCF_S        22U
#define SCI_STAT_TCF_M        (1U << SCI_STAT_TCF_S)    // Transmission Complete Flag
#define SCI_STAT_TDREF_S      23U
#define SCI_STAT_TDREF_M      (1U << SCI_STAT_TDREF_S)    // Transmit Data Register Empty Flag
#define SCI_STAT_REAF_S       24U
#define SCI_STAT_REAF_M       (1U << SCI_STAT_REAF_S)    // Receiver Active Flag
#define SCI_STAT_LBDE_S       25U
#define SCI_STAT_LBDE_M       (1U << SCI_STAT_LBDE_S)    // LIN Break Detection Enable
#define SCI_STAT_BCLEN_S      26U
#define SCI_STAT_BCLEN_M      (1U << SCI_STAT_BCLEN_S)    // Break Character Generation Length
#define SCI_STAT_RWID_S       27U
#define SCI_STAT_RWID_M       (1U << SCI_STAT_RWID_S)    // Receive Wake Up Idle Detect
#define SCI_STAT_RXINV_S      28U
#define SCI_STAT_RXINV_M      (1U << SCI_STAT_RXINV_S)    // Receive Wake Up Idle Detect
#define SCI_STAT_MSB_S        29U
#define SCI_STAT_MSB_M        (1U << SCI_STAT_MSB_S)    // MSB First
#define SCI_STAT_REDGIF_S     30U
#define SCI_STAT_REDGIF_M     (1U << SCI_STAT_REDGIF_S)    // SCI_RX Pin Active Edge Interrupt Flag
#define SCI_STAT_LBDIF_S      31U
#define SCI_STAT_LBDIF_M      (1U << SCI_STAT_LBDIF_S)    // LIN Break Detect Interrupt Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCICTRL register
//
//*************************************************************************************************
#define SCI_CTRL_PSEL_S      0U
#define SCI_CTRL_PSEL_M      0x1U                         // Parity Type

#define SCI_CTRL_PEN_S       1    // Parity Enable Shift
#define SCI_CTRL_PEN_M       (0x1U << SCI_CTRL_PEN_S)    // Parity Enable

#define SCI_CTRL_ILTS_S      2    // Idle Line Type Select Shift
#define SCI_CTRL_ILTS_M      (0x1U << SCI_CTRL_ILTS_S)   // Idle Line Type Select

#define SCI_CTRL_RWMS_S      3    // Receiver Wakeup Method Select Shift
#define SCI_CTRL_RWMS_M      (0x1U << SCI_CTRL_RWMS_S)   // Receiver Wakeup Method Select

#define SCI_CTRL_BITMODE_S   4    // 9-Bit or 8-Bit Mode Select Shift
#define SCI_CTRL_BITMODE_M   (0x1U << SCI_CTRL_BITMODE_S) // 9-Bit or 8-Bit Mode Select

#define SCI_CTRL_RSRCSEL_S   5    // Receiver Source Select Shift
#define SCI_CTRL_RSRCSEL_M   (0x1U << SCI_CTRL_RSRCSEL_S) // Receiver Source Select

#define SCI_CTRL_LMOD_S      7    // Loop Mode Select Shift
#define SCI_CTRL_LMOD_M      (0x1U << SCI_CTRL_LMOD_S)    // Loop Mode Select

#define SCI_CTRL_IDLCFG_S    8    // Idle Configuration Shift
#define SCI_CTRL_IDLCFG_M    (0x7U << SCI_CTRL_IDLCFG_S)  // Idle Configuration

#define SCI_CTRL_M2IE_S      14   // Match 2 Interrupt Enable Shift
#define SCI_CTRL_M2IE_M      (0x1U << SCI_CTRL_M2IE_S)    // Match 2 Interrupt Enable

#define SCI_CTRL_M1IE_S      15   // Match 1 Interrupt Enable Shift
#define SCI_CTRL_M1IE_M      (0x1U << SCI_CTRL_M1IE_S)    // Match 1 Interrupt Enable

#define SCI_CTRL_SDBK_S      16   // Send Break Shift
#define SCI_CTRL_SDBK_M      (0x1U << SCI_CTRL_SDBK_S)    // Send Break

#define SCI_CTRL_RWC_S       17   // Receiver Wakeup Control Shift
#define SCI_CTRL_RWC_M       (0x1U << SCI_CTRL_RWC_S)     // Receiver Wakeup Control

#define SCI_CTRL_RXEN_S      18   // Receiver Enable Shift
#define SCI_CTRL_RXEN_M      (0x1U << SCI_CTRL_RXEN_S)    // Receiver Enable

#define SCI_CTRL_TXEN_S      19   // Transmitter Enable Shift
#define SCI_CTRL_TXEN_M      (0x1U << SCI_CTRL_TXEN_S)    // Transmitter Enable

#define SCI_CTRL_IDFIE_S     20   // Idle Line Interrupt Enable Shift
#define SCI_CTRL_IDFIE_M     (0x1U << SCI_CTRL_IDFIE_S)   // Idle Line Interrupt Enable

#define SCI_CTRL_RXIE_S      21   // Receiver Interrupt Enable Shift
#define SCI_CTRL_RXIE_M      (0x1U << SCI_CTRL_RXIE_S)    // Receiver Interrupt Enable

#define SCI_CTRL_TCFIE_S     22   // Transmission Complete Interrupt Enable Shift
#define SCI_CTRL_TCFIE_M     (0x1U << SCI_CTRL_TCFIE_S)   // Transmission Complete Interrupt Enable

#define SCI_CTRL_TXIE_S      23   // Transmit Interrupt Enable Shift
#define SCI_CTRL_TXIE_M      (0x1U << SCI_CTRL_TXIE_S)    // Transmit Interrupt Enable

#define SCI_CTRL_PEFIE_S     24   // Parity Error Interrupt Enable Shift
#define SCI_CTRL_PEFIE_M     (0x1U << SCI_CTRL_PEFIE_S)   // Parity Error Interrupt Enable

#define SCI_CTRL_FEFIE_S     25   // Framing Error Interrupt Enable Shift
#define SCI_CTRL_FEFIE_M     (0x1U << SCI_CTRL_FEFIE_S)   // Framing Error Interrupt Enable

#define SCI_CTRL_NFIE_S      26   // Noise Error Interrupt Enable Shift
#define SCI_CTRL_NFIE_M      (0x1U << SCI_CTRL_NFIE_S)    // Noise Error Interrupt Enable

#define SCI_CTRL_OVIE_S      27   // Overrun Interrupt Enable Shift
#define SCI_CTRL_OVIE_M      (0x1U << SCI_CTRL_OVIE_S)    // Overrun Interrupt Enable

#define SCI_CTRL_TXINV_S     28   // Transmit Data Inversion Shift
#define SCI_CTRL_TXINV_M     (0x1U << SCI_CTRL_TXINV_S)   // Transmit Data Inversion

#define SCI_CTRL_TXDIR_S     29   // LPUART_TX Pin Direction in Single-Wire Mode Shift
#define SCI_CTRL_TXDIR_M     (0x1U << SCI_CTRL_TXDIR_S)


//*************************************************************************************************
//
// The following are defines for the bit fields in the SCIDATA register
//
//*************************************************************************************************
#define SCI_DATA_DAT_S       0U
#define SCI_DATA_DAT_M       0x3FFU   // SCI Data
#define SCI_DATA_RLIDL_S     11U
#define SCI_DATA_RLIDL_M     (0x1U << SCI_DATA_RLIDL_S)   // Idle Line
#define SCI_DATA_RBEMPT_S    12U
#define SCI_DATA_RBEMPT_M    (0x1U << SCI_DATA_RBEMPT_S)    // Receive Buffer Empty
#define SCI_DATA_FETSC_S     13U
#define SCI_DATA_FETSC_M     (0x1U << SCI_DATA_FETSC_S)    // Frame Error / Transmit Special Character
#define SCI_DATA_PARERR_S    14U
#define SCI_DATA_PARERR_M    (0x1U << SCI_DATA_PARERR_S)   // The current received dataword contained in DATA[R9:R0] was received with a parity error
#define SCI_DATA_NOISE_S     15U
#define SCI_DATA_NOISE_M     (0x1U << SCI_DATA_NOISE_S)    // The current received dataword contained in DATA[R9:R0] was received with noise
//*************************************************************************************************
//
// The following are defines for the bit fields in the SCIMATCH register
//
//*************************************************************************************************
#define SCI_MATCH_M1_S       0U
#define SCI_MATCH_M1_M       0xFFU   // Match 1
#define SCI_MATCH_M2_S       16U
#define SCI_MATCH_M2_M       0xFF0000U   // Match 2
//*************************************************************************************************
//
// The following are defines for the bit fields in the SCIRSIR register
//
//*************************************************************************************************
#define SCI_RSIR_TCTSE_S      0U
#define SCI_RSIR_TCTSE_M      0x1U    // Transmitter clear-to-send enable
#define SCI_RSIR_TRTSE_S      1U
#define SCI_RSIR_TRTSE_M      (0x1U << SCI_RSIR_TRTSE_S)  // Transmitter request-to-send enable
#define SCI_RSIR_TRTSPOL_S    2U
#define SCI_RSIR_TRTSPOL_M    (0x1U << SCI_RSIR_TRTSPOL_S)   // Transmitter request-to-send polarity
#define SCI_RSIR_RTSE_S       3U
#define SCI_RSIR_RTSE_M       (0x1U << SCI_RSIR_RTSE_S)   // Receiver request-to-send enable
#define SCI_RSIR_CTSCFG_S     4U
#define SCI_RSIR_CTSCFG_M     (0x1U << SCI_RSIR_CTSCFG_S)    // Transmit CTS Configuration
#define SCI_RSIR_CTSSRC_S     5U
#define SCI_RSIR_CTSSRC_M     (0x1U << SCI_RSIR_CTSSRC_S)  // Transmit CTS Source
#define SCI_RSIR_RTSCFG_S     8U
#define SCI_RSIR_RTSCFG_M     (0xFFU << SCI_RSIR_RTSCFG_S)   // Receive RTS FIFO watermark
#define SCI_RSIR_TNP_S        16U
#define SCI_RSIR_TNP_M        (0x3U << SCI_RSIR_TNP_S)   // Transmitter narrow pulse
#define SCI_RSIR_IREN_S       18U
#define SCI_RSIR_IREN_M       (0x1U << SCI_RSIR_IREN_S)   // Infrared enable
//*************************************************************************************************
//
// The following are defines for the bit fields in the SCIFCTL register
//
//*************************************************************************************************

#define SCI_FCTL_RXFIFOSIZE_S  0U
#define SCI_FCTL_RXFIFOSIZE_M  (0x7U << SCI_FCTL_RXFIFOSIZE_S)    // Receive FIFO Buffer Depth

#define SCI_FCTL_RXFIFOEN_S    3U
#define SCI_FCTL_RXFIFOEN_M    (0x1U << SCI_FCTL_RXFIFOEN_S)    // Receive FIFO Enable

#define SCI_FCTL_TXFIFOSIZE_S  4U
#define SCI_FCTL_TXFIFOSIZE_M  (0x7U << SCI_FCTL_TXFIFOSIZE_S)    // Transmit FIFO Buffer Depth

#define SCI_FCTL_TXFIFOEN_S    7U
#define SCI_FCTL_TXFIFOEN_M    (0x1U << SCI_FCTL_TXFIFOEN_S)    // Transmit FIFO Enable

#define SCI_FCTL_RXUNIE_S      8U
#define SCI_FCTL_RXUNIE_M      (0x1U << SCI_FCTL_RXUNIE_S)    // Receive FIFO Underflow Interrupt Enable

#define SCI_FCTL_TXOVIE_S      9U
#define SCI_FCTL_TXOVIE_M      (0x1U << SCI_FCTL_TXOVIE_S)    // Transmit FIFO Overflow Interrupt Enable

#define SCI_FCTL_IRFNEE_S      10U
#define SCI_FCTL_IRFNEE_M      (0x7U << SCI_FCTL_IRFNEE_S)    // Idle Receiver FIFO Not Empty Enable

#define SCI_FCTL_RXBUFCLR_S    14U
#define SCI_FCTL_RXBUFCLR_M    (0x1U << SCI_FCTL_RXBUFCLR_S)    // Receive FIFO/Buffer Flush

#define SCI_FCTL_TXBUFCLR_S    15U
#define SCI_FCTL_TXBUFCLR_M    (0x1U << SCI_FCTL_TXBUFCLR_S)    // Transmit FIFO/Buffer Flush

#define SCI_FCTL_RBUNF_S       16U
#define SCI_FCTL_RBUNF_M       (0x1U << SCI_FCTL_RBUNF_S)    // Receiver Buffer Underflow Flag

#define SCI_FCTL_TBOVF_S       17U
#define SCI_FCTL_TBOVF_M       (0x1U << SCI_FCTL_TBOVF_S)    // Transmitter Buffer Overflow Flag

#define SCI_FCTL_RFEMPT_S      22U
#define SCI_FCTL_RFEMPT_M      (0x1U << SCI_FCTL_RFEMPT_S)    // Receive Buffer/FIFO Empty

#define SCI_FCTL_TFEMPT_S      23U
#define SCI_FCTL_TFEMPT_M      (0x1U << SCI_FCTL_TFEMPT_S)  
//*************************************************************************************************
//
// The following are defines for the bit fields in the SCIWATMK register
//
//*************************************************************************************************
#define SCI_WATMK_TXWAT_S      0U
#define SCI_WATMK_TXWAT_M      0xFFU   // Transmit Watermark
#define SCI_WATMK_TXCNT_S      8U
#define SCI_WATMK_TXCNT_M      0xFF00U   // Transmit Counter
#define SCI_WATMK_RXWAT_S      16U
#define SCI_WATMK_RXWAT_M      0xFF0000U   // Receive Watermark
#define SCI_WATMK_RXCNT_S      24U
#define SCI_WATMK_RXCNT_M      0xFF000000U   // Receive Counter
#endif
