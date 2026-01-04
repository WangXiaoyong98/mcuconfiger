/*
  ******************************************************************************
  * @file           : hw_dma.h
  * @brief          : dma register map
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
#ifndef HW_DMA_H
#define HW_DMA_H



//*************************************************************************************************
//
// The following are defines for the ECAP register offsets
//
//*************************************************************************************************
#define DMA_O_CR	           0x0000
#define DMA_O_ES             0x0004
#define DMA_O_ERQ            0x000C
#define DMA_O_EEI            0x0014

#define DMA_O_SERQ          0x001B
#define DMA_O_CERQ          0x001A
#define DMA_O_SEEI          0x0019
#define DMA_O_CEEI          0x0018
#define DMA_O_CINT          0x001F
#define DMA_O_CERR          0x001E
#define DMA_O_SSRT          0x001D
#define DMA_O_CDNE          0x001C

#define DMA_O_INT            0x0024
#define DMA_O_ERR            0x002C
#define DMA_O_HRS            0x0034
#define DMA_O_GPOR           0x0038

#define DMA_O_DCHPRI0       0x0103
#define DMA_O_DCHPRI1       0x0102
#define DMA_O_DCHPRI2       0x0101
#define DMA_O_DCHPRI3       0x0100
#define DMA_O_DCHPRI4       0x0107
#define DMA_O_DCHPRI5       0x0106
#define DMA_O_DCHPRI6       0x0105
#define DMA_O_DCHPRI7       0x0104
#define DMA_O_DCHPRI8       0x010B
#define DMA_O_DCHPRI9       0x010A
#define DMA_O_DCHPRI10      0x0109
#define DMA_O_DCHPRI11      0x0108
#define DMA_O_DCHPRI12      0x010F
#define DMA_O_DCHPRI13      0x010E
#define DMA_O_DCHPRI14      0x010D
#define DMA_O_DCHPRI15      0x010C
#define DMA_DCHPRI(x)  	  (*(uint8_t*)((DMA_BASEADDR + 0x0103) + ((x)*0x001)))

#define DMA_O_TCD0_SADDR    0x1000
#define DMA_O_TCD1_SADDR    0x1020
#define DMA_O_TCD2_SADDR    0x1040
#define DMA_O_TCD3_SADDR    0x1060
#define DMA_O_TCD4_SADDR    0x1080
#define DMA_O_TCD5_SADDR    0x10A0
#define DMA_O_TCD6_SADDR    0x10C0
#define DMA_O_TCD7_SADDR    0x10E0
#define DMA_O_TCD8_SADDR    0x1100
#define DMA_O_TCD9_SADDR    0x1120
#define DMA_O_TCD10_SADDR   0x1140
#define DMA_O_TCD11_SADDR   0x1160
#define DMA_O_TCD12_SADDR   0x1180
#define DMA_O_TCD13_SADDR   0x11A0
#define DMA_O_TCD14_SADDR   0x11C0
#define DMA_O_TCD15_SADDR   0x11E0
#define DMA_TCD_SADDR(x)  (*(uint32_t*)((DMA_BASEADDR + 0x1000) + ((x)*0x020)))

#define DMA_O_TCD0_SOFF     0x1004
#define DMA_O_TCD1_SOFF     0x1024
#define DMA_O_TCD2_SOFF     0x1044
#define DMA_O_TCD3_SOFF     0x1064
#define DMA_O_TCD4_SOFF     0x1084
#define DMA_O_TCD5_SOFF     0x10A4
#define DMA_O_TCD6_SOFF     0x10C4
#define DMA_O_TCD7_SOFF     0x10E4
#define DMA_O_TCD8_SOFF     0x1104
#define DMA_O_TCD9_SOFF     0x1124
#define DMA_O_TCD10_SOFF    0x1144
#define DMA_O_TCD11_SOFF    0x1164
#define DMA_O_TCD12_SOFF    0x1184
#define DMA_O_TCD13_SOFF    0x11A4
#define DMA_O_TCD14_SOFF    0x11C4
#define DMA_O_TCD15_SOFF    0x11E4
#define DMA_TCD_SOFF(x)   (*(uint16_t*)((DMA_BASEADDR + 0x1004) + ((x)*0x020)))

#define DMA_O_TCD0_ATTR     0x1006
#define DMA_O_TCD1_ATTR     0x1026
#define DMA_O_TCD2_ATTR     0x1046
#define DMA_O_TCD3_ATTR     0x1066
#define DMA_O_TCD4_ATTR     0x1086
#define DMA_O_TCD5_ATTR     0x10A6
#define DMA_O_TCD6_ATTR     0x10C6
#define DMA_O_TCD7_ATTR     0x10E6
#define DMA_O_TCD8_ATTR     0x1106
#define DMA_O_TCD9_ATTR     0x1126
#define DMA_O_TCD10_ATTR    0x1146
#define DMA_O_TCD11_ATTR    0x1166
#define DMA_O_TCD12_ATTR    0x1186
#define DMA_O_TCD13_ATTR    0x11A6
#define DMA_O_TCD14_ATTR    0x11C6
#define DMA_O_TCD15_ATTR    0x11E6
#define DMA_TCD_ATTR(x)   (*(uint16_t*)((DMA_BASEADDR + 0x1006) + ((x)*0x020)))

#define DMA_O_TCD0_NBYTES   0x1008
#define DMA_O_TCD1_NBYTES   0x1028
#define DMA_O_TCD2_NBYTES   0x1048
#define DMA_O_TCD3_NBYTES   0x1068
#define DMA_O_TCD4_NBYTES   0x1088
#define DMA_O_TCD5_NBYTES   0x10A8
#define DMA_O_TCD6_NBYTES   0x10C8
#define DMA_O_TCD7_NBYTES   0x10E8
#define DMA_O_TCD8_NBYTES   0x1108
#define DMA_O_TCD9_NBYTES   0x1128
#define DMA_O_TCD10_NBYTES  0x1148
#define DMA_O_TCD11_NBYTES  0x1168
#define DMA_O_TCD12_NBYTES  0x1188
#define DMA_O_TCD13_NBYTES  0x11A8
#define DMA_O_TCD14_NBYTES  0x11C8
#define DMA_O_TCD15_NBYTES  0x11E8
#define DMA_TCD_NBYTES(x) (*(uint32_t*)((DMA_BASEADDR + 0x1008) + ((x)*0x020)))

#define DMA_O_TCD0_SLAST    0x100C
#define DMA_O_TCD1_SLAST    0x102C
#define DMA_O_TCD2_SLAST    0x104C
#define DMA_O_TCD3_SLAST    0x106C
#define DMA_O_TCD4_SLAST    0x108C
#define DMA_O_TCD5_SLAST    0x10AC
#define DMA_O_TCD6_SLAST    0x10CC
#define DMA_O_TCD7_SLAST    0x10EC
#define DMA_O_TCD8_SLAST    0x110C
#define DMA_O_TCD9_SLAST    0x112C
#define DMA_O_TCD10_SLAST   0x114C
#define DMA_O_TCD11_SLAST   0x116C
#define DMA_O_TCD12_SLAST   0x118C
#define DMA_O_TCD13_SLAST   0x11AC
#define DMA_O_TCD14_SLAST   0x11CC
#define DMA_O_TCD15_SLAST   0x11EC
#define DMA_TCD_SLAST(x)   (*(uint32_t*)((DMA_BASEADDR + 0x100C) + ((x)*0x020)))

#define DMA_O_TCD0_DADDR    0x1010
#define DMA_O_TCD1_DADDR    0x1030
#define DMA_O_TCD2_DADDR    0x1050
#define DMA_O_TCD3_DADDR    0x1070
#define DMA_O_TCD4_DADDR    0x1090
#define DMA_O_TCD5_DADDR    0x10B0
#define DMA_O_TCD6_DADDR    0x10D0
#define DMA_O_TCD7_DADDR    0x10F0
#define DMA_O_TCD8_DADDR    0x1110
#define DMA_O_TCD9_DADDR    0x1130
#define DMA_O_TCD10_DADDR   0x1150
#define DMA_O_TCD11_DADDR   0x1170
#define DMA_O_TCD12_DADDR   0x1190
#define DMA_O_TCD13_DADDR   0x11B0
#define DMA_O_TCD14_DADDR   0x11D0
#define DMA_O_TCD15_DADDR   0x11F0
#define DMA_TCD_DADDR(x)  (*(uint32_t*)((DMA_BASEADDR + 0x1010) + ((x)*0x020)))

#define DMA_O_TCD0_DOFF    0x1014
#define DMA_O_TCD1_DOFF    0x1034
#define DMA_O_TCD2_DOFF    0x1054
#define DMA_O_TCD3_DOFF    0x1074
#define DMA_O_TCD4_DOFF    0x1094
#define DMA_O_TCD5_DOFF    0x10B4
#define DMA_O_TCD6_DOFF    0x10D4
#define DMA_O_TCD7_DOFF    0x10F4
#define DMA_O_TCD8_DOFF    0x1114
#define DMA_O_TCD9_DOFF    0x1134
#define DMA_O_TCD10_DOFF   0x1154
#define DMA_O_TCD11_DOFF   0x1174
#define DMA_O_TCD12_DOFF   0x1194
#define DMA_O_TCD13_DOFF   0x11B4
#define DMA_O_TCD14_DOFF   0x11D4
#define DMA_O_TCD15_DOFF   0x11F4
#define DMA_TCD_DOFF(x)  (*(uint16_t*)((DMA_BASEADDR + 0x1014) + ((x)*0x020)))

#define DMA_O_TCD0_CITER    0x1016
#define DMA_O_TCD1_CITER    0x1036
#define DMA_O_TCD2_CITER    0x1056
#define DMA_O_TCD3_CITER    0x1076
#define DMA_O_TCD4_CITER    0x1096
#define DMA_O_TCD5_CITER    0x10B6
#define DMA_O_TCD6_CITER    0x10D6
#define DMA_O_TCD7_CITER    0x10F6
#define DMA_O_TCD8_CITER    0x1116
#define DMA_O_TCD9_CITER    0x1136
#define DMA_O_TCD10_CITER   0x1156
#define DMA_O_TCD11_CITER   0x1176
#define DMA_O_TCD12_CITER   0x1196
#define DMA_O_TCD13_CITER   0x11B6
#define DMA_O_TCD14_CITER   0x11D6
#define DMA_O_TCD15_CITER   0x11F6
#define DMA_TCD_CITER(x)  (*(uint16_t*)((DMA_BASEADDR + 0x1016) + ((x)*0x020)))

#define DMA_O_TCD0_CITER_ELINK    0x1016
#define DMA_O_TCD1_CITER_ELINK    0x1036
#define DMA_O_TCD2_CITER_ELINK    0x1056
#define DMA_O_TCD3_CITER_ELINK    0x1076
#define DMA_O_TCD4_CITER_ELINK    0x1096
#define DMA_O_TCD5_CITER_ELINK    0x10B6
#define DMA_O_TCD6_CITER_ELINK    0x10D6
#define DMA_O_TCD7_CITER_ELINK    0x10F6
#define DMA_O_TCD8_CITER_ELINK    0x1116
#define DMA_O_TCD9_CITER_ELINK    0x1136
#define DMA_O_TCD10_CITER_ELINK   0x1156
#define DMA_O_TCD11_CITER_ELINK   0x1176
#define DMA_O_TCD12_CITER_ELINK   0x1196
#define DMA_O_TCD13_CITER_ELINK   0x11B6
#define DMA_O_TCD14_CITER_ELINK   0x11D6
#define DMA_O_TCD15_CITER_ELINK   0x11F6
#define DMA_TCD_CITER_ELINK(x)  (*(uint16_t*)((DMA_BASEADDR + 0x1016) + ((x)*0x020)))

#define DMA_O_TCD0_DLAST_SGA    0x1018
#define DMA_O_TCD1_DLAST_SGA    0x1038
#define DMA_O_TCD2_DLAST_SGA    0x1058
#define DMA_O_TCD3_DLAST_SGA    0x1078
#define DMA_O_TCD4_DLAST_SGA    0x1098
#define DMA_O_TCD5_DLAST_SGA    0x10B8
#define DMA_O_TCD6_DLAST_SGA    0x10D8
#define DMA_O_TCD7_DLAST_SGA    0x10F8
#define DMA_O_TCD8_DLAST_SGA    0x1118
#define DMA_O_TCD9_DLAST_SGA    0x1138
#define DMA_O_TCD10_DLAST_SGA   0x1158
#define DMA_O_TCD11_DLAST_SGA   0x1178
#define DMA_O_TCD12_DLAST_SGA   0x1198
#define DMA_O_TCD13_DLAST_SGA   0x11B8
#define DMA_O_TCD14_DLAST_SGA   0x11D8
#define DMA_O_TCD15_DLAST_SGA   0x11F8
#define DMA_TCD_DLAST_SGA(x)  (*(uint32_t*)((DMA_BASEADDR + 0x1018) + ((x)*0x020)))

#define DMA_O_TCD0_CSR    0x101C
#define DMA_O_TCD1_CSR    0x103C
#define DMA_O_TCD2_CSR    0x105C
#define DMA_O_TCD3_CSR    0x107C
#define DMA_O_TCD4_CSR    0x109C
#define DMA_O_TCD5_CSR    0x10BC
#define DMA_O_TCD6_CSR    0x10DC
#define DMA_O_TCD7_CSR    0x10FC
#define DMA_O_TCD8_CSR    0x111C
#define DMA_O_TCD9_CSR    0x113C
#define DMA_O_TCD10_CSR   0x115C
#define DMA_O_TCD11_CSR   0x117C
#define DMA_O_TCD12_CSR   0x119C
#define DMA_O_TCD13_CSR   0x11BC
#define DMA_O_TCD14_CSR   0x11DC
#define DMA_O_TCD15_CSR   0x11FC
#define DMA_TCD_CSR(x)  (*(uint16_t*)((DMA_BASEADDR + 0x101C) + ((x)*0x020)))

#define DMA_O_TCD0_BITER    0x101E
#define DMA_O_TCD1_BITER    0x103E
#define DMA_O_TCD2_BITER    0x105E
#define DMA_O_TCD3_BITER    0x107E
#define DMA_O_TCD4_BITER    0x109E
#define DMA_O_TCD5_BITER    0x10BE
#define DMA_O_TCD6_BITER    0x10DE
#define DMA_O_TCD7_BITER    0x10FE
#define DMA_O_TCD8_BITER    0x111E
#define DMA_O_TCD9_BITER    0x113E
#define DMA_O_TCD10_BITER   0x115E
#define DMA_O_TCD11_BITER   0x117E
#define DMA_O_TCD12_BITER   0x119E
#define DMA_O_TCD13_BITER   0x11BE
#define DMA_O_TCD14_BITER   0x11DE
#define DMA_O_TCD15_BITER   0x11FE
#define DMA_TCD_BITER(x)  (*(uint16_t*)((DMA_BASEADDR + 0x101E) + ((x)*0x020)))

#define DMA_O_TCD0_BITER_ELINK    0x101E
#define DMA_O_TCD1_BITER_ELINK    0x103E
#define DMA_O_TCD2_BITER_ELINK    0x105E
#define DMA_O_TCD3_BITER_ELINK    0x107E
#define DMA_O_TCD4_BITER_ELINK    0x109E
#define DMA_O_TCD5_BITER_ELINK    0x10BE
#define DMA_O_TCD6_BITER_ELINK    0x10DE
#define DMA_O_TCD7_BITER_ELINK    0x10FE
#define DMA_O_TCD8_BITER_ELINK    0x111E
#define DMA_O_TCD9_BITER_ELINK    0x113E
#define DMA_O_TCD10_BITER_ELINK   0x115E
#define DMA_O_TCD11_BITER_ELINK   0x117E
#define DMA_O_TCD12_BITER_ELINK   0x119E
#define DMA_O_TCD13_BITER_ELINK   0x11BE
#define DMA_O_TCD14_BITER_ELINK   0x11DE
#define DMA_O_TCD15_BITER_ELINK   0x11FE
#define DMA_TCD_BITER_ELINK(x)  (*(uint16_t*)((DMA_BASEADDR + 0x101E) + ((x)*0x020)))

/***********************************************************************/
//*************************************************************************************************
//
// Bit definitions and macros for DMA_CR register
//
//*************************************************************************************************
#define DMA_CR_EDBG                     (0x00000002)
#define DMA_CR_ERCA                     (0x00000004)
#define DMA_CR_ERGA                     (0x00000008)
#define DMA_CR_HOE                      (0x00000010)
#define DMA_CR_HALT                     (0x00000020)
#define DMA_CR_CLM                      (0x00000040)
#define DMA_CR_CMLM                     (0x00000080)
#define DMA_CR_ECX                      (0x00010000)
#define DMA_CR_CX                       (0x00020000)

//*************************************************************************************************
//
// Bit definitions and macros for DMA_ES register
//
//*************************************************************************************************
#define DMA_ES_DBE                      (0x00000001)
#define DMA_ES_SBE                      (0x00000002)
#define DMA_ES_SGE                      (0x00000004)
#define DMA_ES_NCE                      (0x00000008)
#define DMA_ES_DOE                      (0x00000010)
#define DMA_ES_DAE                      (0x00000020)
#define DMA_ES_SOE                      (0x00000040)
#define DMA_ES_SAE                      (0x00000080)
#define DMA_ES_ERRCHN(x)                (((x)&0x0000003F)<<8)
#define DMA_ES_CPE                      (0x00004000)
#define DMA_ES_ECX                      (0x00010000)
#define DMA_ES_VLD                      (0x80000000)

//*************************************************************************************************
//
// Bit definitions and macros for DMA_ERQ register
//
//*************************************************************************************************
#define DMA_ERQ_ERQ0                  (0x00000001)
#define DMA_ERQ_ERQ1                  (0x00000002)
#define DMA_ERQ_ERQ2                  (0x00000004)
#define DMA_ERQ_ERQ3                  (0x00000008)
#define DMA_ERQ_ERQ4                  (0x00000010)
#define DMA_ERQ_ERQ5                  (0x00000020)
#define DMA_ERQ_ERQ6                  (0x00000040)
#define DMA_ERQ_ERQ7                  (0x00000080)
#define DMA_ERQ_ERQ8                  (0x00000100)
#define DMA_ERQ_ERQ9                  (0x00000200)
#define DMA_ERQ_ERQ10                 (0x00000400)
#define DMA_ERQ_ERQ11                 (0x00000800)
#define DMA_ERQ_ERQ12                 (0x00001000)
#define DMA_ERQ_ERQ13                 (0x00002000)
#define DMA_ERQ_ERQ14                 (0x00004000)
#define DMA_ERQ_ERQ15                 (0x00008000)

//*************************************************************************************************
//
// Bit definitions and macros for DMA_EEI register
//
//*************************************************************************************************
#define DMA_EEI_EEI0                  (0x00000001)
#define DMA_EEI_EEI1                  (0x00000002)
#define DMA_EEI_EEI2                  (0x00000004)
#define DMA_EEI_EEI3                  (0x00000008)
#define DMA_EEI_EEI4                  (0x00000010)
#define DMA_EEI_EEI5                  (0x00000020)
#define DMA_EEI_EEI6                  (0x00000040)
#define DMA_EEI_EEI7                  (0x00000080)
#define DMA_EEI_EEI8                  (0x00000100)
#define DMA_EEI_EEI9                  (0x00000200)
#define DMA_EEI_EEI10                 (0x00000400)
#define DMA_EEI_EEI11                 (0x00000800)
#define DMA_EEI_EEI12                 (0x00001000)
#define DMA_EEI_EEI13                 (0x00002000)
#define DMA_EEI_EEI14                 (0x00004000)
#define DMA_EEI_EEI15                 (0x00008000)

//*************************************************************************************************
//
// Bit definitions and macros for DMA_SERQ register
//
//*************************************************************************************************
#define DMA_SERQ_SERQ(x)                (((x)&0x7F)<<0)
#define DMA_SERQ_SAER                   (0x40)
#define DMA_SERQ_NOP                    (0x80)

//*************************************************************************************************
//
// Bit definitions and macros for DMA_CERQ register
//
//*************************************************************************************************
#define DMA_CERQ_CERQ(x)                (((x)&0x7F)<<0)
#define DMA_CERQ_CAER                   (0x40)
#define DMA_CERQ_NOP                    (0x80)

//*************************************************************************************************
//
// Bit definitions and macros for DMA_SEEI register
//
//*************************************************************************************************
#define DMA_SEEI_SEEI(x)                (((x)&0x7F)<<0)
#define DMA_SEEI_SAEE                   (0x40)
#define DMA_SEEI_NOP                    (0x80)

//*************************************************************************************************
//
// Bit definitions and macros for DMA_CEEI register
//
//*************************************************************************************************
#define DMA_CEEI_CEEI(x)                (((x)&0x7F)<<0)
#define DMA_CEEI_CAEE                   (0x40)
#define DMA_CEEI_NOP                    (0x80)

//*************************************************************************************************
//
// Bit definitions and macros for DMA_CINT register
//
//*************************************************************************************************
#define DMA_CINT_CINT(x)                (((x)&0x7F)<<0)
#define DMA_CINT_CAIR                   (0x40)
#define DMA_CINT_NOP                    (0x80)

//*************************************************************************************************
// Bit definitions and macros for DMA_CERR register
//**************************************************************************************************
#define DMA_CERR_CERR(x)                (((x)&0x7F)<<0)
#define DMA_CERR_CAER                   (0x40)
#define DMA_CERR_NOP                    (0x80)

//*************************************************************************************************
// Bit definitions and macros for DMA_SSRT register
//**************************************************************************************************
#define DMA_SSRT_SSRT(x)                (((x)&0x7F)<<0)
#define DMA_SSRT_SAST                   (0x40)
#define DMA_SSRT_NOP                    (0x80)

//*************************************************************************************************
// Bit definitions and macros for DMA_CDNE register
//*************************************************************************************************
#define DMA_CDNE_CDNE(x)                (((x)&0x7F)<<0)
#define DMA_CDNE_CADN                   (0x40)
#define DMA_CDNE_NOP                    (0x80)

//*************************************************************************************************
// Bit definitions and macros for DMA_INT register
//*************************************************************************************************
#define DMA_INT_INT0                  (0x00000001)
#define DMA_INT_INT1                  (0x00000002)
#define DMA_INT_INT2                  (0x00000004)
#define DMA_INT_INT3                  (0x00000008)
#define DMA_INT_INT4                  (0x00000010)
#define DMA_INT_INT5                  (0x00000020)
#define DMA_INT_INT6                  (0x00000040)
#define DMA_INT_INT7                  (0x00000080)
#define DMA_INT_INT8                  (0x00000100)
#define DMA_INT_INT9                  (0x00000200)
#define DMA_INT_INT10                 (0x00000400)
#define DMA_INT_INT11                 (0x00000800)
#define DMA_INT_INT12                 (0x00001000)
#define DMA_INT_INT13                 (0x00002000)
#define DMA_INT_INT14                 (0x00004000)
#define DMA_INT_INT15                 (0x00008000)

//*************************************************************************************************
// Bit definitions and macros for DMA_ERR register
//*************************************************************************************************
#define DMA_ERR_ERR0                  (0x00000001)
#define DMA_ERR_ERR1                  (0x00000002)
#define DMA_ERR_ERR2                  (0x00000004)
#define DMA_ERR_ERR3                  (0x00000008)
#define DMA_ERR_ERR4                  (0x00000010)
#define DMA_ERR_ERR5                  (0x00000020)
#define DMA_ERR_ERR6                  (0x00000040)
#define DMA_ERR_ERR7                  (0x00000080)
#define DMA_ERR_ERR8                  (0x00000100)
#define DMA_ERR_ERR9                  (0x00000200)
#define DMA_ERR_ERR10                 (0x00000400)
#define DMA_ERR_ERR11                 (0x00000800)
#define DMA_ERR_ERR12                 (0x00001000)
#define DMA_ERR_ERR13                 (0x00002000)
#define DMA_ERR_ERR14                 (0x00004000)
#define DMA_ERR_ERR15                 (0x00008000)

//*************************************************************************************************
// Bit definitions and macros for DMA_HRS register
//*************************************************************************************************
#define DMA_HRS_HRS0                  (0x00000001)
#define DMA_HRS_HRS1                  (0x00000002)
#define DMA_HRS_HRS2                  (0x00000004)
#define DMA_HRS_HRS3                  (0x00000008)
#define DMA_HRS_HRS4                  (0x00000010)
#define DMA_HRS_HRS5                  (0x00000020)
#define DMA_HRS_HRS6                  (0x00000040)
#define DMA_HRS_HRS7                  (0x00000080)
#define DMA_HRS_HRS8                  (0x00000100)
#define DMA_HRS_HRS9                  (0x00000200)
#define DMA_HRS_HRS10                 (0x00000400)
#define DMA_HRS_HRS11                 (0x00000800)
#define DMA_HRS_HRS12                 (0x00001000)
#define DMA_HRS_HRS13                 (0x00002000)
#define DMA_HRS_HRS14                 (0x00004000)
#define DMA_HRS_HRS15                 (0x00008000)

//*************************************************************************************************
// Bit definitions and macros for DMA_DCHPRI register
//*************************************************************************************************
#define DMA_DCHPRI_CHPRI(x)             (((x)&0x0F)<<0)
#define DMA_DCHPRI_DPA                  (0x40)
#define DMA_DCHPRI_ECP                  (0x80)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_SADDR register
//*************************************************************************************************
#define DMA_TCD_SADDR_SADDR(x)          (((x)&0xFFFFFFFF)<<0)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_ATTR register
//*************************************************************************************************
#define DMA_TCD_ATTR_DSIZE(x)           (((x)&0x0007)<<0)
#define DMA_TCD_ATTR_DMOD(x)            (((x)&0x001F)<<3)
#define DMA_TCD_ATTR_SSIZE(x)           (((x)&0x0007)<<8)
#define DMA_TCD_ATTR_SMOD(x)            (((x)&0x001F)<<11)
#define DMA_TCD_ATTR_SSIZE_8BIT         (0x0000)
#define DMA_TCD_ATTR_SSIZE_16BIT        (0x0100)
#define DMA_TCD_ATTR_SSIZE_32BIT        (0x0200)
#define DMA_TCD_ATTR_SSIZE_64BIT        (0x0300)
#define DMA_TCD_ATTR_SSIZE_16BYTE       (0x0400)
#define DMA_TCD_ATTR_SSIZE_32BYTE       (0x0500)
#define DMA_TCD_ATTR_DSIZE_8BIT         (0x0000)
#define DMA_TCD_ATTR_DSIZE_16BIT        (0x0001)
#define DMA_TCD_ATTR_DSIZE_32BIT        (0x0002)
#define DMA_TCD_ATTR_DSIZE_64BIT        (0x0003)
#define DMA_TCD_ATTR_DSIZE_16BYTE       (0x0004)
#define DMA_TCD_ATTR_DSIZE_32BYTE       (0x0005)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_SOFF register
//*************************************************************************************************
#define DMA_TCD_SOFF_SOFF(x)            (((x)&0xFFFF)<<0)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_NBYTES_MLNO register
//*************************************************************************************************
#define DMA_TCD_NBYTES_MLNO_NBYTES(x)        (((x)&0xFFFFFFFF)<<0)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_NBYTES_MLOFFNO register
//*************************************************************************************************
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)        (((x)&0x3FFFFFFF)<<0)
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE            (0x40000000)
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE            (0x80000000)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_NBYTES_MLOFFYES register
//*************************************************************************************************
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)        (((x)&0x3FF)<<0)
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)         (((x)&0xFFFFF)<<10)
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE            (0x40000000)
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE            (0x80000000)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_SLAST register
//*************************************************************************************************
#define  DMA_TCD_SLAST_SLAST(x)          (((x)&0xFFFFFFFF)<<0)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_DADDR register
//*************************************************************************************************
#define DMA_TCD_DADDR_DADDR(x)          (((x)&0xFFFFFFFF)<<0)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_CITER_ELINKNO register
//*************************************************************************************************
#define DMA_TCD_CITER_ELINKNO_CITER(x)          (((x)&0x7FFF)<<0)
#define DMA_TCD_CITER_ELINKNO_ELINK            (0x8000)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_CITER_ELINKYES register
//*************************************************************************************************
#define DMA_TCD_CITER_ELINKYES_CITER(x)    (((x)&0x01FF)<<0)
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)   (((x)&0x003F)<<9)
#define DMA_TCD_CITER_ELINKYES_ELINK      (0x8000)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_DOFF register
//*************************************************************************************************
#define DMA_TCD_DOFF_DOFF(x)            (((x)&0xFFFF)<<0)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_DLAST_SGA register
//*************************************************************************************************
#define DMA_TCD_DLAST_SGA_DLAST_SGA(x)  (((x)&0xFFFFFFFF)<<0)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_BITER_ELINKNO register
//*************************************************************************************************
#define DMA_TCD_BITER_ELINKNO_BITER(x)          (((x)&0x7FFF)<<0)
#define DMA_TCD_BITER_ELINKNO_ELINK            (0x8000)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_BITER_ELINKYES register
//*************************************************************************************************
#define DMA_TCD_BITER_ELINKYES_BITER(x)    (((x)&0x01FF)<<0)
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)   (((x)&0x003F)<<9)
#define DMA_TCD_BITER_ELINKYES_ELINK      (0x8000)

//*************************************************************************************************
// Bit definitions and macros for DMA_TCD_CSR register
//*************************************************************************************************
#define DMA_TCD_CSR_START               (0x0001)
#define DMA_TCD_CSR_INT_MAJOR           (0x0002)
#define DMA_TCD_CSR_INT_HALF            (0x0004)
#define DMA_TCD_CSR_D_REQ               (0x0008)
#define DMA_TCD_CSR_E_SG                (0x0010)
#define DMA_TCD_CSR_E_LINK              (0x0020)
#define DMA_TCD_CSR_ACTIVE              (0x0040)
#define DMA_TCD_CSR_DONE                (0x0080)
#define DMA_TCD_CSR_LINKCH(x)           (((x)&0x003F)<<8)
#define DMA_TCD_CSR_BWC(x)              (((x)&0x0003)<<14)
#define DMA_TCD_CSR_BWC_NO_STALL        (0x0000)
#define DMA_TCD_CSR_BWC_4CYC_STALL      (0x8000)
#define DMA_TCD_CSR_BWC_8CYC_STALL      (0xC000)

/********************************************************************/
/* DMA MUX definition */

/* Mux 0 */
#define DMA_MUX_BASEADDR           0x40021000
#define DMA_MUX_CHCONFIG0          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00000)) 
#define DMA_MUX_CHCONFIG1          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00001)) 
#define DMA_MUX_CHCONFIG2          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00002)) 
#define DMA_MUX_CHCONFIG3          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00003))
#define DMA_MUX_CHCONFIG4          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00004))
#define DMA_MUX_CHCONFIG5          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00005))
#define DMA_MUX_CHCONFIG6          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00006))
#define DMA_MUX_CHCONFIG7          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00007))
#define DMA_MUX_CHCONFIG8          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00008))
#define DMA_MUX_CHCONFIG9          (*(uint8_t*)(DMA_MUX_BASEADDR + 0x00009))
#define DMA_MUX_CHCONFIG10         (*(uint8_t*)(DMA_MUX_BASEADDR + 0x0000A))
#define DMA_MUX_CHCONFIG11         (*(uint8_t*)(DMA_MUX_BASEADDR + 0x0000B))
#define DMA_MUX_CHCONFIG12         (*(uint8_t*)(DMA_MUX_BASEADDR + 0x0000C)) 
#define DMA_MUX_CHCONFIG13         (*(uint8_t*)(DMA_MUX_BASEADDR + 0x0000D)) 
#define DMA_MUX_CHCONFIG14         (*(uint8_t*)(DMA_MUX_BASEADDR + 0x0000E)) 
#define DMA_MUX_CHCONFIG15         (*(uint8_t*)(DMA_MUX_BASEADDR + 0x0000F)) 



#endif /* __PIONEER3_DMA_H__ */
