//###########################################################################
//
// FILE:    hw_spi.h
//
// TITLE:   Definitions for the SPI registers.
//
//###########################################################################

#ifndef HW_SPI_H
#define HW_SPI_H

//*************************************************************************************************
//
// The following are defines for the SPI register offsets
//
//*************************************************************************************************
#define SPI_O_MCFGR             0x0U   // SPI Module Configuration Register
#define SPI_O_TCNTR             0x8U   // SPI Transmit Counter Register
#define SPI_O_CLKTAR0           0xCU   // SPI Clock and Transmit Attribution Register(Master Mode) 
#define SPI_O_CLKTAR0_SLAVE     0xCU   // SPI Clock and Transmit Attribution Register(Slave Mode) 
#define SPI_O_CLKTAR1           0x10U  // SPI Clock and Transmit Attribution Register(Master Mode) 
#define SPI_O_STATR             0x2CU  // SPI Status Register
#define SPI_O_IRSER             0x30U  // SPI DMA/Interrupt Request Select and Enable Register
#define SPI_O_PUSHTFR           0x34U  // SPI Push TX FIFO Register(Master Mode)
#define SPI_O_PUSHTFR_SLV       0x34U  // SPI Push TX FIFO Register(Slave Mode)
#define SPI_O_POPRFR            0x38U  // SPI Pop RX FIFO Register(Slave Mode)
#define SPI_O_TFR0              0x3CU  // SPI Transmit FIFO Register 0
#define SPI_O_TFR1              0x40U  // SPI Transmit FIFO Register 1
#define SPI_O_TFR2              0x44U  // SPI Transmit FIFO Register 2
#define SPI_O_TFR3              0x48U  // SPI Transmit FIFO Register 3
#define SPI_O_RFR0              0x7CU  // SPI Receive FIFO Register 0
#define SPI_O_RFR1              0x80U  // SPI Receive FIFO Register 1
#define SPI_O_RFR2              0x84U  // SPI Receive FIFO Register 2
#define SPI_O_RFR3              0x88U  // SPI Receive FIFO Register 3


/*! @name MCFGR - Module Configuration Register */
#define SPI_MCFGR_HT_MASK                          (0x1U)
#define SPI_MCFGR_HT_SHIFT                         (0U)
#define SPI_MCFGR_HT(x)                            (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_HT_SHIFT)) & SPI_MCFGR_HT_MASK)
#define SPI_MCFGR_SMPPT_MASK                       (0x300U)
#define SPI_MCFGR_SMPPT_SHIFT                      (8U)
#define SPI_MCFGR_SMPPT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_SMPPT_SHIFT)) & SPI_MCFGR_SMPPT_MASK)
#define SPI_MCFGR_RXFC_MASK                        (0x400U)
#define SPI_MCFGR_RXFC_SHIFT                       (10U)
#define SPI_MCFGR_RXFC(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_RXFC_SHIFT)) & SPI_MCFGR_RXFC_MASK)
#define SPI_MCFGR_TXFC_MASK                        (0x800U)
#define SPI_MCFGR_TXFC_SHIFT                       (11U)
#define SPI_MCFGR_TXFC(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_TXFC_SHIFT)) & SPI_MCFGR_TXFC_MASK)
#define SPI_MCFGR_RXFD_MASK                        (0x1000U)
#define SPI_MCFGR_RXFD_SHIFT                       (12U)
#define SPI_MCFGR_RXFD(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_RXFD_SHIFT)) & SPI_MCFGR_RXFD_MASK)
#define SPI_MCFGR_TXFD_MASK                        (0x2000U)
#define SPI_MCFGR_TXFD_SHIFT                       (13U)
#define SPI_MCFGR_TXFD(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_TXFD_SHIFT)) & SPI_MCFGR_TXFD_MASK)
#define SPI_MCFGR_MD_MASK                          (0x4000U)
#define SPI_MCFGR_MD_SHIFT                         (14U)
#define SPI_MCFGR_MD(x)                            (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_MD_SHIFT)) & SPI_MCFGR_MD_MASK)
#define SPI_MCFGR_DZE_MASK                         (0x8000U)
#define SPI_MCFGR_DZE_SHIFT                        (15U)
#define SPI_MCFGR_DZE(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_DZE_SHIFT)) & SPI_MCFGR_DZE_MASK)
#define SPI_MCFGR_PCSIS_MASK                       (0xFC0000U)
#define SPI_MCFGR_PCSIS_SHIFT                      (16U)
#define SPI_MCFGR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_PCSIS_SHIFT)) & SPI_MCFGR_PCSIS_MASK)
#define SPI_MCFGR_RFOOE_MASK                       (0x1000000U)
#define SPI_MCFGR_RFOOE_SHIFT                      (24U)
#define SPI_MCFGR_RFOOE(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_RFOOE_SHIFT)) & SPI_MCFGR_RFOOE_MASK)
#define SPI_MCFGR_PCSSTBE_MASK                     (0x2000000U)
#define SPI_MCFGR_PCSSTBE_SHIFT                    (25U)
#define SPI_MCFGR_PCSSTBE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_PCSSTBE_SHIFT)) & SPI_MCFGR_PCSSTBE_MASK)
#define SPI_MCFGR_MTXFE_MASK                       (0x4000000U)
#define SPI_MCFGR_MTXFE_SHIFT                      (26U)
#define SPI_MCFGR_MTXFE(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_MTXFE_SHIFT)) & SPI_MCFGR_MTXFE_MASK)
#define SPI_MCFGR_FRZ_MASK                         (0x8000000U)
#define SPI_MCFGR_FRZ_SHIFT                        (27U)
#define SPI_MCFGR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_FRZ_SHIFT)) & SPI_MCFGR_FRZ_MASK)
#define SPI_MCFGR_CFG_MASK                         (0x30000000U)
#define SPI_MCFGR_CFG_SHIFT                        (28U)
#define SPI_MCFGR_CFG(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_CFG_SHIFT)) & SPI_MCFGR_CFG_MASK)
#define SPI_MCFGR_CSCKE_MASK                       (0x40000000U)
#define SPI_MCFGR_CSCKE_SHIFT                      (30U)
#define SPI_MCFGR_CSCKE(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_CSCKE_SHIFT)) & SPI_MCFGR_CSCKE_MASK)
#define SPI_MCFGR_MS_MASK                          (0x80000000U)
#define SPI_MCFGR_MS_SHIFT                         (31U)
#define SPI_MCFGR_MS(x)                            (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_MS_SHIFT)) & SPI_MCFGR_MS_MASK)

/*! @name TCNTR - Transfer Count Register */
#define SPI_TCNTR_SPI_TCNTR_MASK                   (0xFFFFU)
#define SPI_TCNTR_SPI_TCNTR_SHIFT                  (0U)
#define SPI_TCNTR_SPI_TCNTR(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_TCNTR_SPI_TCNTR_SHIFT)) & SPI_TCNTR_SPI_TCNTR_MASK)

/*! @name CLKTAR - Clock and Transfer Attributes Register (In Master Mode) */
#define SPI_CLKTAR_BRS_MASK                        (0xFU)
#define SPI_CLKTAR_BRS_SHIFT                       (0U)
#define SPI_CLKTAR_BRS(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_BRS_SHIFT)) & SPI_CLKTAR_BRS_MASK)
#define SPI_CLKTAR_DATS_MASK                       (0xF0U)
#define SPI_CLKTAR_DATS_SHIFT                      (4U)
#define SPI_CLKTAR_DATS(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_DATS_SHIFT)) & SPI_CLKTAR_DATS_MASK)
#define SPI_CLKTAR_ASDS_MASK                       (0xF00U)
#define SPI_CLKTAR_ASDS_SHIFT                      (8U)
#define SPI_CLKTAR_ASDS(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_ASDS_SHIFT)) & SPI_CLKTAR_ASDS_MASK)
#define SPI_CLKTAR_PCSSCKDS_MASK                   (0xF000U)
#define SPI_CLKTAR_PCSSCKDS_SHIFT                  (12U)
#define SPI_CLKTAR_PCSSCKDS(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_PCSSCKDS_SHIFT)) & SPI_CLKTAR_PCSSCKDS_MASK)
#define SPI_CLKTAR_BRP_MASK                        (0x30000U)
#define SPI_CLKTAR_BRP_SHIFT                       (16U)
#define SPI_CLKTAR_BRP(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_BRP_SHIFT)) & SPI_CLKTAR_BRP_MASK)
#define SPI_CLKTAR_DATXP_MASK                      (0xC0000U)
#define SPI_CLKTAR_DATXP_SHIFT                     (18U)
#define SPI_CLKTAR_DATXP(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_DATXP_SHIFT)) & SPI_CLKTAR_DATXP_MASK)
#define SPI_CLKTAR_ASDP_MASK                       (0x300000U)
#define SPI_CLKTAR_ASDP_SHIFT                      (20U)
#define SPI_CLKTAR_ASDP(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_ASDP_SHIFT)) & SPI_CLKTAR_ASDP_MASK)
#define SPI_CLKTAR_PCSSDP_MASK                     (0xC00000U)
#define SPI_CLKTAR_PCSSDP_SHIFT                    (22U)
#define SPI_CLKTAR_PCSSDP(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_PCSSDP_SHIFT)) & SPI_CLKTAR_PCSSDP_MASK)
#define SPI_CLKTAR_LSBFST_MASK                     (0x1000000U)
#define SPI_CLKTAR_LSBFST_SHIFT                    (24U)
#define SPI_CLKTAR_LSBFST(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_LSBFST_SHIFT)) & SPI_CLKTAR_LSBFST_MASK)
#define SPI_CLKTAR_CLKPHS_MASK                     (0x2000000U)
#define SPI_CLKTAR_CLKPHS_SHIFT                    (25U)
#define SPI_CLKTAR_CLKPHS(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_CLKPHS_SHIFT)) & SPI_CLKTAR_CLKPHS_MASK)
#define SPI_CLKTAR_CLKPOL_MASK                     (0x4000000U)
#define SPI_CLKTAR_CLKPOL_SHIFT                    (26U)
#define SPI_CLKTAR_CLKPOL(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_CLKPOL_SHIFT)) & SPI_CLKTAR_CLKPOL_MASK)
#define SPI_CLKTAR_FSZ_MASK                        (0x78000000U)
#define SPI_CLKTAR_FSZ_SHIFT                       (27U)
#define SPI_CLKTAR_FSZ(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_FSZ_SHIFT)) & SPI_CLKTAR_FSZ_MASK)
#define SPI_CLKTAR_DBRT_MASK                       (0x80000000U)
#define SPI_CLKTAR_DBRT_SHIFT                      (31U)
#define SPI_CLKTAR_DBRT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_DBRT_SHIFT)) & SPI_CLKTAR_DBRT_MASK)

/* The count of SPI_CTAR */
#define SPI_CLKTAR_COUNT                           (2U)

/*! @name CTAR_SLAVE - Clock and Transfer Attributes Register (In Slave Mode) */
#define SPI_CLKTAR_SLAVE_CLKPHS_MASK               (0x2000000U)
#define SPI_CLKTAR_SLAVE_CLKPHS_SHIFT              (25U)
#define SPI_CLKTAR_SLAVE_CLKPHS(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_SLAVE_CLKPHS_SHIFT)) & SPI_CLKTAR_SLAVE_CLKPHS_MASK)
#define SPI_CLKTAR_SLAVE_CLKPOL_MASK               (0x4000000U)
#define SPI_CLKTAR_SLAVE_CLKPOL_SHIFT              (26U)
#define SPI_CLKTAR_SLAVE_CLKPOL(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_SLAVE_CLKPOL_SHIFT)) & SPI_CLKTAR_SLAVE_CLKPOL_MASK)
#define SPI_CLKTAR_SLAVE_FSZ_MASK                  (0x78000000U)
#define SPI_CLKTAR_SLAVE_FSZ_SHIFT                 (27U)
#define SPI_CLKTAR_SLAVE_FSZ(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_SLAVE_FSZ_SHIFT)) & SPI_CLKTAR_SLAVE_FSZ_MASK)

/* The count of SPI_CTAR_SLAVE */
#define SPI_CLKTAR_SLAVE_COUNT                     (1U)

/*! @name STATR - Status Register */
#define SPI_STATR_POPNPTR_MASK                     (0xFU)
#define SPI_STATR_POPNPTR_SHIFT                    (0U)
#define SPI_STATR_POPNPTR(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_STATR_POPNPTR_SHIFT)) & SPI_STATR_POPNPTR_MASK)
#define SPI_STATR_RXFCTR_MASK                      (0xF0U)
#define SPI_STATR_RXFCTR_SHIFT                     (4U)
#define SPI_STATR_RXFCTR(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_STATR_RXFCTR_SHIFT)) & SPI_STATR_RXFCTR_MASK)
#define SPI_STATR_TXNPTR_MASK                      (0xF00U)
#define SPI_STATR_TXNPTR_SHIFT                     (8U)
#define SPI_STATR_TXNPTR(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXNPTR_SHIFT)) & SPI_STATR_TXNPTR_MASK)
#define SPI_STATR_TXFCTR_MASK                      (0xF000U)
#define SPI_STATR_TXFCTR_SHIFT                     (12U)
#define SPI_STATR_TXFCTR(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXFCTR_SHIFT)) & SPI_STATR_TXFCTR_MASK)
#define SPI_STATR_RXFDF_MASK                       (0x20000U)
#define SPI_STATR_RXFDF_SHIFT                      (17U)
#define SPI_STATR_RXFDF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_STATR_RXFDF_SHIFT)) & SPI_STATR_RXFDF_MASK)
#define SPI_STATR_RXFOF_MASK                       (0x80000U)
#define SPI_STATR_RXFOF_SHIFT                      (19U)
#define SPI_STATR_RXFOF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_STATR_RXFOF_SHIFT)) & SPI_STATR_RXFOF_MASK)
#define SPI_STATR_TXFFF_MASK                       (0x2000000U)
#define SPI_STATR_TXFFF_SHIFT                      (25U)
#define SPI_STATR_TXFFF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXFFF_SHIFT)) & SPI_STATR_TXFFF_MASK)
#define SPI_STATR_TXFUF_MASK                       (0x8000000U)
#define SPI_STATR_TXFUF_SHIFT                      (27U)
#define SPI_STATR_TXFUF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXFUF_SHIFT)) & SPI_STATR_TXFUF_MASK)
#define SPI_STATR_EQF_MASK                         (0x10000000U)
#define SPI_STATR_EQF_SHIFT                        (28U)
#define SPI_STATR_EQF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_STATR_EQF_SHIFT)) & SPI_STATR_EQF_MASK)
#define SPI_STATR_TRSTAT_MASK                      (0x40000000U)
#define SPI_STATR_TRSTAT_SHIFT                     (30U)
#define SPI_STATR_TRSTAT(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TRSTAT_SHIFT)) & SPI_STATR_TRSTAT_MASK)
#define SPI_STATR_TXCF_MASK                        (0x80000000U)
#define SPI_STATR_TXCF_SHIFT                       (31U)
#define SPI_STATR_TXCF(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXCF_SHIFT)) & SPI_STATR_TXCF_MASK)

/*! @name IRSER - DMA/Interrupt Request Select and Enable Register */
#define SPI_IRSER_RXF_DIRS_MASK                    (0x10000U)
#define SPI_IRSER_RXF_DIRS_SHIFT                   (16U)
#define SPI_IRSER_RXF_DIRS(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_RXF_DIRS_SHIFT)) & SPI_IRSER_RXF_DIRS_MASK)
#define SPI_IRSER_RXFD_RE_MASK                     (0x20000U)
#define SPI_IRSER_RXFD_RE_SHIFT                    (17U)
#define SPI_IRSER_RXFD_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_RXFD_RE_SHIFT)) & SPI_IRSER_RXFD_RE_MASK)
#define SPI_IRSER_RXFO_RE_MASK                     (0x80000U)
#define SPI_IRSER_RXFO_RE_SHIFT                    (19U)
#define SPI_IRSER_RXFO_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_RXFO_RE_SHIFT)) & SPI_IRSER_RXFO_RE_MASK)
#define SPI_IRSER_TXFF_IRS_MASK                    (0x1000000U)
#define SPI_IRSER_TXFF_IRS_SHIFT                   (24U)
#define SPI_IRSER_TXFF_IRS(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_TXFF_IRS_SHIFT)) & SPI_IRSER_TXFF_IRS_MASK)
#define SPI_IRSER_TXFF_RE_MASK                     (0x2000000U)
#define SPI_IRSER_TXFF_RE_SHIFT                    (25U)
#define SPI_IRSER_TXFF_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_TXFF_RE_SHIFT)) & SPI_IRSER_TXFF_RE_MASK)
#define SPI_IRSER_TXFU_RE_MASK                     (0x8000000U)
#define SPI_IRSER_TXFU_RE_SHIFT                    (27U)
#define SPI_IRSER_TXFU_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_TXFU_RE_SHIFT)) & SPI_IRSER_TXFU_RE_MASK)
#define SPI_IRSER_EQ_RE_MASK                       (0x10000000U)
#define SPI_IRSER_EQ_RE_SHIFT                      (28U)
#define SPI_IRSER_EQ_RE(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_EQ_RE_SHIFT)) & SPI_IRSER_EQ_RE_MASK)
#define SPI_IRSER_TXC_RE_MASK                      (0x80000000U)
#define SPI_IRSER_TXC_RE_SHIFT                     (31U)
#define SPI_IRSER_TXC_RE(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_TXC_RE_SHIFT)) & SPI_IRSER_TXC_RE_MASK)

/*! @name PUSHTFR - PUSH TX FIFO Register In Master Mode */
#define SPI_PUSHTFR_TXDAT_MASK                     (0xFFFFU)
#define SPI_PUSHTFR_TXDAT_SHIFT                    (0U)
#define SPI_PUSHTFR_TXDAT(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_TXDAT_SHIFT)) & SPI_PUSHTFR_TXDAT_MASK)
#define SPI_PUSHTFR_SPCS_MASK                      (0x3F0000U)
#define SPI_PUSHTFR_SPCS_SHIFT                     (16U)
#define SPI_PUSHTFR_SPCS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_SPCS_SHIFT)) & SPI_PUSHTFR_SPCS_MASK)
#define SPI_PUSHTFR_CTXCTR_MASK                    (0x4000000U)
#define SPI_PUSHTFR_CTXCTR_SHIFT                   (26U)
#define SPI_PUSHTFR_CTXCTR(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_CTXCTR_SHIFT)) & SPI_PUSHTFR_CTXCTR_MASK)
#define SPI_PUSHTFR_EQ_MASK                        (0x8000000U)
#define SPI_PUSHTFR_EQ_SHIFT                       (27U)
#define SPI_PUSHTFR_EQ(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_EQ_SHIFT)) & SPI_PUSHTFR_EQ_MASK)
#define SPI_PUSHTFR_CLKTXAS_MASK                   (0x70000000U)
#define SPI_PUSHTFR_CLKTXAS_SHIFT                  (28U)
#define SPI_PUSHTFR_CLKTXAS(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_CLKTXAS_SHIFT)) & SPI_PUSHTFR_CLKTXAS_MASK)
#define SPI_PUSHTFR_CPCSE_MASK                     (0x80000000U)
#define SPI_PUSHTFR_CPCSE_SHIFT                    (31U)
#define SPI_PUSHTFR_CPCSE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_CPCSE_SHIFT)) & SPI_PUSHTFR_CPCSE_MASK)

/*! @name PUSHR_SLAVE - PUSH TX FIFO Register In Slave Mode */
#define SPI_PUSHTFR_SLAVE_TXDAT_MASK               (0xFFFFFFFFU)
#define SPI_PUSHTFR_SLAVE_TXDAT_SHIFT              (0U)
#define SPI_PUSHTFR_SLAVE_TXDAT(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_SLAVE_TXDAT_SHIFT)) & SPI_PUSHTFR_SLAVE_TXDAT_MASK)

/*! @name POPR - POP RX FIFO Register */
#define SPI_POPRFR_RXDAT_MASK                      (0xFFFFFFFFU)
#define SPI_POPRFR_RXDAT_SHIFT                     (0U)
#define SPI_POPRFR_RXDAT(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_POPRFR_RXDAT_SHIFT)) & SPI_POPRFR_RXDAT_MASK)

/*! @name TFR0 - Transmit FIFO Registers */
#define SPI_TFR0_TXCMD_TXDAT_MASK                  (0xFFFFU)
#define SPI_TFR0_TXCMD_TXDAT_SHIFT                 (0U)
#define SPI_TFR0_TXCMD_TXDAT(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_TFR0_TXCMD_TXDAT_SHIFT)) & SPI_TFR0_TXCMD_TXDAT_MASK)
#define SPI_TFR0_TXDAT_MASK                        (0xFFFF0000U)
#define SPI_TFR0_TXDAT_SHIFT                       (16U)
#define SPI_TFR0_TXDAT(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_TFR0_TXDAT_SHIFT)) & SPI_TFR0_TXDAT_MASK)

/*! @name TFR1 - Transmit FIFO Registers */
#define SPI_TFR1_TXDAT_MASK                       (0xFFFFU)
#define SPI_TFR1_TXDAT_SHIFT                      (0U)
#define SPI_TFR1_TXDAT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_TFR1_TXDAT_SHIFT)) & SPI_TFR1_TXDAT_MASK)
#define SPI_TFR1_TXCMD_TXDAT_MASK                 (0xFFFF0000U)
#define SPI_TFR1_TXCMD_TXDAT_SHIFT                (16U)
#define SPI_TFR1_TXCMD_TXDAT(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_TFR1_TXCMD_TXDAT_SHIFT)) & SPI_TFR1_TXCMD_TXDAT_MASK)

/*! @name TFR2 - Transmit FIFO Registers */
#define SPI_TFR2_TXDAT_MASK                       (0xFFFFU)
#define SPI_TFR2_TXDAT_SHIFT                      (0U)
#define SPI_TFR2_TXDAT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_TXFR2_TXDATA_SHIFT)) & SPI_TXFR2_TXDATA_MASK)
#define SPI_TFR2_TXCMD_TXDAT_MASK                 (0xFFFF0000U)
#define SPI_TFR2_TXCMD_TXDAT_SHIFT                (16U)
#define SPI_TFR2_TXCMD_TXDAT(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_TXFR2_TXCMD_TXDATA_SHIFT)) & SPI_TXFR2_TXCMD_TXDATA_MASK)

/*! @name TFR3 - Transmit FIFO Registers */
#define SPI_TFR3_TXDAT_MASK                       (0xFFFFU)
#define SPI_TFR3_TXDAT_SHIFT                      (0U)
#define SPI_TFR3_TXDAT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_TFR3_TXDAT_SHIFT)) & SPI_TFR3_TXDAT_MASK)
#define SPI_TFR3_TXCMD_TXDAT_MASK                 (0xFFFF0000U)
#define SPI_TFR3_TXCMD_TXDAT_SHIFT                (16U)
#define SPI_TFR3_TXCMD_TXDAT(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_TFR3_TXCMD_TXDAT_SHIFT)) & SPI_TFR3_TXCMD_TXDAT_MASK)

/*! @name RFR0 - Receive FIFO Registers */
#define SPI_RFR0_RXDAT_MASK                       (0xFFFFFFFFU)
#define SPI_RFR0_RXDAT_SHIFT                      (0U)
#define SPI_RFR0_RXDAT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_RFR0_RXDAT_SHIFT)) & SPI_RFR0_RXDAT_MASK)

/*! @name RFR1 - Receive FIFO Registers */
#define SPI_RFR1_RXDAT_MASK                       (0xFFFFFFFFU)
#define SPI_RFR1_RXDAT_SHIFT                      (0U)
#define SPI_RFR1_RXDAT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_RFR1_RXDAT_SHIFT)) & SPI_RFR1_RXDAT_MASK)

/*! @name RFR2 - Receive FIFO Registers */
#define SPI_RFR2_RXDAT_MASK                       (0xFFFFFFFFU)
#define SPI_RFR2_RXDAT_SHIFT                      (0U)
#define SPI_RFR2_RXDAT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_RFR2_RXDAT_SHIFT)) & SPI_RFR2_RXDAT_MASK)

/*! @name RFR3 - Receive FIFO Registers */
#define SPI_RFR3_RXDAT_MASK                       (0xFFFFFFFFU)
#define SPI_RFR3_RXDAT_SHIFT                      (0U)
#define SPI_RFR3_RXDAT(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_RFR3_RXDAT_SHIFT)) & SPI_RFR3_RXDAT_MASK)

#endif
