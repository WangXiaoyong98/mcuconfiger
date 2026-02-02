/*
 ******************************************************************************
 * @file           : sp28038_epwm.h
 * @brief          : Definitions for the EPWM registers.
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

#ifndef SP28038_EPWM_H
#define SP28038_EPWM_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

//---------------------------------------------------------------------------
// EPWM Individual Register Bit Definitions:

struct TBCTL_BITS {                       // bits description
    uint32_t CTRMODE:2;                   // 1:0 Counter Mode
    uint32_t PHSEN:1;                     // 2 Phase Load Enable
    uint32_t PRDLD:1;                     // 3 Active Period Load
    uint32_t rsvd1:2;                     // 5:4 Reserved
    uint32_t SWFSYNC:1;                   // 6 Software Force Sync Pulse
    uint32_t HSPCLKDIV:3;                 // 9:7 High Speed TBCLK Pre-scaler
    uint32_t CLKDIV:3;                    // 12:10 Time Base Clock Pre-scaler
    uint32_t PHSDIR:1;                    // 13 Phase Direction Bit
    uint32_t FREE_SOFT:2;                 // 15:14 Emulation Mode Bits
    uint32_t rsvd2:16;
};

union TBCTL_REG {
    uint32_t  all;
    struct  TBCTL_BITS  bit;
};

struct TBCTL2_BITS {                      // bits description
    uint32_t rsvd1:5;                     // 4:0 Reserved
    uint32_t rsvd2:1;                     // 5 Reserved
    uint32_t OSHTSYNCMODE:1;              // 6 One shot sync mode
    uint32_t OSHTSYNC:1;                  // 7 One shot sync
    uint32_t rsvd3:4;                     // 11:8 Reserved
    uint32_t rsvd4:2;                     // 13:12 Reserved
    uint32_t PRDLDSYNC:2;                 // 15:14 PRD Shadow to Active Load on SYNC Event
    uint32_t rsvd5:16;
};

union TBCTL2_REG {
    uint32_t  all;
    struct  TBCTL2_BITS  bit;
};

struct EPWMSYNCINSEL_BITS {               // bits description
    uint32_t SEL:5;                       // 4:0 EPWMxSYNCI source select
    uint32_t rsvd1:11;                    // 15:5 Reserved
    uint32_t rsvd2:16;
};

union EPWMSYNCINSEL_REG {
    uint32_t  all;
    struct  EPWMSYNCINSEL_BITS  bit;
};

struct TBSTS_BITS {                       // bits description
    uint32_t CTRDIR:1;                    // 0 Counter Direction Status
    uint32_t SYNCI:1;                     // 1 External Input Sync Status
    uint32_t CTRMAX:1;                    // 2 Counter Max Latched Status
    uint32_t rsvd1:13;                    // 15:3 Reserved
    uint32_t rsvd2:16;
};

union TBSTS_REG {
    uint32_t  all;
    struct  TBSTS_BITS  bit;
};

struct EPWMSYNCOUTEN_BITS {               // bits description
    uint32_t SWEN:1;                      // 0 EPWMxSYNCO Software Force Enable
    uint32_t ZEROEN:1;                    // 1 EPWMxSYNCO Zero Count Event Enable
    uint32_t CMPBEN:1;                    // 2 EPWMxSYNCO Compare B Event Enable
    uint32_t CMPCEN:1;                    // 3 EPWMxSYNCO Compare C Event Enable
    uint32_t CMPDEN:1;                    // 4 EPWMxSYNCO Compare D Event Enable
    uint32_t DCAEVT1EN:1;                 // 5 EPWMxSYNCO Digital Compare A Event 1 Sync Enable
    uint32_t DCBEVT1EN:1;                 // 6 EPWMxSYNCO Digital Compare B Event 1 Sync Enable
    uint32_t rsvd1:1;                     // 7 Reserved
    uint32_t rsvd2:8;                     // 15:8 Reserved
    uint32_t rsvd3:16;
};

union EPWMSYNCOUTEN_REG {
    uint32_t  all;
    struct  EPWMSYNCOUTEN_BITS  bit;
};

struct TBCTL3_BITS {                      // bits description
    uint32_t OSSFRCEN:1;                  // 0 One Shot Sync Force Enable
    uint32_t rsvd1:15;                    // 15:1 Reserved
    uint32_t rsvd2:16;
};

union TBCTL3_REG {
    uint32_t  all;
    struct  TBCTL3_BITS  bit;
};

struct CMPCTL_BITS {                      // bits description
    uint32_t LOADAMODE:2;                 // 1:0 Active Compare A Load
    uint32_t LOADBMODE:2;                 // 3:2 Active Compare B Load
    uint32_t SHDWAMODE:1;                 // 4 Compare A Register Block Operating Mode
    uint32_t rsvd1:1;                     // 5 Reserved
    uint32_t SHDWBMODE:1;                 // 6 Compare B Register Block Operating Mode
    uint32_t rsvd2:1;                     // 7 Reserved
    uint32_t SHDWAFULL:1;                 // 8 Compare A Shadow Register Full Status
    uint32_t SHDWBFULL:1;                 // 9 Compare B Shadow Register Full Status
    uint32_t LOADASYNC:2;                 // 11:10 Active Compare A Load on SYNC
    uint32_t LOADBSYNC:2;                 // 13:12 Active Compare B Load on SYNC
    uint32_t rsvd3:2;                     // 15:14 Reserved
    uint32_t rsvd4:16;
};

union CMPCTL_REG {
    uint32_t  all;
    struct  CMPCTL_BITS  bit;
};

struct CMPCTL2_BITS {                   // bits description
    uint32_t LOADCMODE:2;                 // 1:0 Active Compare C Load
    uint32_t LOADDMODE:2;                 // 3:2 Active Compare D load
    uint32_t SHDWCMODE:1;                 // 4 Compare C Block Operating Mode
    uint32_t rsvd1:1;                     // 5 Reserved
    uint32_t SHDWDMODE:1;                 // 6 Compare D Block Operating Mode
    uint32_t rsvd2:3;                     // 9:7 Reserved
    uint32_t LOADCSYNC:2;                 // 11:10 Active Compare C Load on SYNC
    uint32_t LOADDSYNC:2;                 // 13:12 Active Compare D Load on SYNC
    uint32_t rsvd3:2;                     // 15:14 Reserved
    uint32_t rsvd4:16;
};

union CMPCTL2_REG {
    uint32_t  all;
    struct  CMPCTL2_BITS  bit;
};

struct DBCTL_BITS {                     // bits description
    uint32_t OUT_MODE:2;                  // 1:0 Dead Band Output Mode Control
    uint32_t POLSEL:2;                    // 3:2 Polarity Select Control
    uint32_t IN_MODE:2;                   // 5:4 Dead Band Input Select Mode Control
    uint32_t LOADREDMODE:2;               // 7:6 Active DBRED Load Mode
    uint32_t LOADFEDMODE:2;               // 9:8 Active DBFED Load Mode
    uint32_t SHDWDBREDMODE:1;             // 10 DBRED Block Operating Mode
    uint32_t SHDWDBFEDMODE:1;             // 11 DBFED Block Operating Mode
    uint32_t OUTSWAP:2;                   // 13:12 Dead Band Output Swap Control
    uint32_t DEDB_MODE:1;                 // 14 Dead Band Dual-Edge B Mode Control
    uint32_t HALFCYCLE:1;                 // 15 Half Cycle Clocking Enable
    uint32_t rsvd1:16;
};

union DBCTL_REG {
    uint32_t  all;
    struct  DBCTL_BITS  bit;
};

struct DBCTL2_BITS {                    // bits description
    uint32_t LOADDBCTLMODE:2;             // 1:0 DBCTL Load from Shadow Mode Select
    uint32_t SHDWDBCTLMODE:1;             // 2 DBCTL Load mode Select
    uint32_t rsvd1:13;                    // 15:3 Reserved
    uint32_t rsvd2:16;
};

union DBCTL2_REG {
    uint32_t  all;
    struct  DBCTL2_BITS  bit;
};

struct AQCTL_BITS {                     // bits description
    uint32_t LDAQAMODE:2;                 // 1:0 Action Qualifier A Load Select
    uint32_t LDAQBMODE:2;                 // 3:2 Action Qualifier B Load Select
    uint32_t SHDWAQAMODE:1;               // 4 Action Qualifer A Operating Mode
    uint32_t rsvd1:1;                     // 5 Reserved
    uint32_t SHDWAQBMODE:1;               // 6 Action Qualifier B Operating Mode
    uint32_t rsvd2:1;                     // 7 Reserved
    uint32_t LDAQASYNC:2;                 // 9:8 AQCTLA Register Load on SYNC
    uint32_t LDAQBSYNC:2;                 // 11:10 AQCTLB Register Load on SYNC
    uint32_t rsvd3:4;                     // 15:12 Reserved
    uint32_t rsvd4:16;
};

union AQCTL_REG {
    uint32_t  all;
    struct  AQCTL_BITS  bit;
};

struct AQTSRCSEL_BITS {                 // bits description
    uint32_t T1SEL:4;                     // 3:0 T1 Event Source Select Bits
    uint32_t T2SEL:4;                     // 7:4 T2 Event Source Select Bits
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union AQTSRCSEL_REG {
    uint32_t  all;
    struct  AQTSRCSEL_BITS  bit;
};

struct PCCTL_BITS {                     // bits description
    uint32_t CHPEN:1;                     // 0 PWM chopping enable
    uint32_t OSHTWTH:4;                   // 4:1 One-shot pulse width
    uint32_t CHPFREQ:3;                   // 7:5 Chopping clock frequency
    uint32_t CHPDUTY:3;                   // 10:8 Chopping clock Duty cycle
    uint32_t rsvd1:5;                     // 15:11 Reserved
    uint32_t rsvd2:16;
};

union PCCTL_REG {
    uint32_t  all;
    struct  PCCTL_BITS  bit;
};

struct VCAPCTL_BITS {                   // bits description
    uint32_t VCAPE:1;                     // 0 Valley  Capture mode
    uint32_t VCAPSTART:1;                 // 1 Valley  Capture Start
    uint32_t TRIGSEL:3;                   // 4:2 Capture Trigger Select
    uint32_t rsvd1:2;                     // 6:5 Reserved
    uint32_t VDELAYDIV:3;                 // 9:7 Valley Delay Mode Divide Enable
    uint32_t EDGEFILTDLYSEL:1;            // 10 Valley Switching Mode Delay Select
    uint32_t rsvd2:5;                     // 15:11 Reserved
    uint32_t rsvd3:16;
};

union VCAPCTL_REG {
    uint32_t  all;
    struct  VCAPCTL_BITS  bit;
};

struct VCNTCFG_BITS {                   // bits description
    uint32_t STARTEDGE:4;                 // 3:0 Counter Start Edge Selection
    uint32_t rsvd1:3;                     // 6:4 Reserved
    uint32_t STARTEDGESTS:1;              // 7 Start Edge Status Bit
    uint32_t STOPEDGE:4;                  // 11:8 Counter Start Edge Selection
    uint32_t rsvd2:3;                     // 14:12 Reserved
    uint32_t STOPEDGESTS:1;               // 15 Stop Edge Status Bit
    uint32_t rsvd3:16;
};

union VCNTCFG_REG {
    uint32_t  all;
    struct  VCNTCFG_BITS  bit;
};

struct HRCNFG_BITS {                      // bits description
    uint32_t EDGMODE:2;                   // 1:0 ePWMxA Edge Mode Select Bits
    uint32_t CTLMODE:1;                   // 2 ePWMxA Control Mode Select Bits
    uint32_t HRLOAD:2;                    // 4:3 ePWMxA Shadow Mode Select Bits
    uint32_t SELOUTB:1;                   // 5 EPWMB Output Selection Bit
    uint32_t AUTOCONV:1;                  // 6 Autoconversion Bit
    uint32_t SWAPAB:1;                    // 7 Swap EPWMA and EPWMB Outputs Bit
    uint32_t EDGMODEB:2;                  // 9:8 ePWMxB Edge Mode Select Bits
    uint32_t CTLMODEB:1;                  // 10 ePWMxB Control Mode Select Bits
    uint32_t HRLOADB:2;                   // 12:11 ePWMxB Shadow Mode Select Bits
    uint32_t rsvd1:1;                     // 13 Reserved
    uint32_t rsvd2:2;                     // 15:14 Reserved
    uint32_t rsvd3:16;
};

union HRCNFG_REG {
    uint32_t  all;
    struct  HRCNFG_BITS  bit;
};

struct HRPWR_BITS {                       // bits description
    uint32_t rsvd1:2;                     // 1:0 Reserved
    uint32_t rsvd2:1;                     // 2 Reserved
    uint32_t rsvd3:1;                     // 3 Reserved
    uint32_t rsvd4:1;                     // 4 Reserved
    uint32_t rsvd5:1;                     // 5 Reserved
    uint32_t rsvd6:4;                     // 9:6 Reserved
    uint32_t rsvd7:5;                     // 14:10 Reserved
    uint32_t CALPWRON:1;                  // 15 Calibration Power On
    uint32_t rsvd8:16;
};

union HRPWR_REG {
    uint32_t  all;
    struct  HRPWR_BITS  bit;
};

struct HRMSTEP_BITS {                   // bits description
    uint32_t HRMSTEP:8;                   // 7:0 High Resolution Micro Step Value
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union HRMSTEP_REG {
    uint32_t  all;
    struct  HRMSTEP_BITS  bit;
};

struct HRCNFG2_BITS {                   // bits description
    uint32_t EDGMODEDB:2;                 // 1:0 Dead-Band Edge-Mode Select Bits
    uint32_t CTLMODEDBRED:2;              // 3:2 DBRED Control Mode Select Bits
    uint32_t CTLMODEDBFED:2;              // 5:4 DBFED Control Mode Select Bits
    uint32_t rsvd1:8;                     // 13:6 Reserved
    uint32_t rsvd2:1;                     // 14 Reserved
    uint32_t rsvd3:1;                     // 15 Reserved
    uint32_t rsvd4:16;
};

union HRCNFG2_REG {
    uint32_t  all;
    struct  HRCNFG2_BITS  bit;
};

struct HRPCTL_BITS {                    // bits description
    uint32_t HRPE:1;                      // 0 High Resolution Period Enable
    uint32_t PWMSYNCSEL:1;                // 1 EPWMSYNCPER Source Select
    uint32_t TBPHSHRLOADE:1;              // 2 TBPHSHR Load Enable
    uint32_t rsvd1:1;                     // 3 Reserved
    uint32_t PWMSYNCSELX:3;               // 6:4 EPWMSYNCPER Extended Source Select Bit:
    uint32_t rsvd2:9;                     // 15:7 Reserved
    uint32_t rsvd3:16;
};

union HRPCTL_REG {
    uint32_t  all;
    struct  HRPCTL_BITS  bit;
};

struct TRREM_BITS {                     // bits description
    uint32_t TRREM:11;                    // 10:0 HRPWM Remainder Bits
    uint32_t rsvd1:5;                     // 15:11 Reserved
    uint32_t rsvd2:16;
};

union TRREM_REG {
    uint32_t  all;
    struct  TRREM_BITS  bit;
};

struct GLDCTL_BITS {                    // bits description
    uint32_t GLD:1;                       // 0 Global Shadow to Active load event control
    uint32_t GLDMODE:4;                   // 4:1 Shadow to Active Global Load Pulse Selection
    uint32_t OSHTMODE:1;                  // 5 One Shot Load mode control bit
    uint32_t rsvd1:1;                     // 6 Reserved
    uint32_t GLDPRD:3;                    // 9:7 Global Load Strobe Period Select Register
    uint32_t GLDCNT:3;                    // 12:10 Global Load Strobe Counter Register
    uint32_t rsvd2:3;                     // 15:13 Reserved
    uint32_t rsvd3:16;
};

union GLDCTL_REG {
    uint32_t  all;
    struct  GLDCTL_BITS  bit;
};

struct GLDCFG_BITS {                    // bits description
    uint32_t TBPRD_TBPRDHR:1;             // 0 Global load event configuration for TBPRD:TBPRDHR
    uint32_t CMPA_CMPAHR:1;               // 1 Global load event configuration for CMPA:CMPAHR
    uint32_t CMPB_CMPBHR:1;               // 2 Global load event configuration for CMPB:CMPBHR
    uint32_t CMPC:1;                      // 3 Global load event configuration for CMPC
    uint32_t CMPD:1;                      // 4 Global load event configuration for CMPD
    uint32_t DBRED_DBREDHR:1;             // 5 Global load event configuration for DBRED:DBREDHR
    uint32_t DBFED_DBFEDHR:1;             // 6 Global load event configuration for DBFED:DBFEDHR
    uint32_t DBCTL:1;                     // 7 Global load event configuration for DBCTL
    uint32_t AQCTLA_AQCTLA2:1;            // 8 Global load event configuration for AQCTLA/A2
    uint32_t AQCTLB_AQCTLB2:1;            // 9 Global load event configuration for AQCTLB/B2
    uint32_t AQCSFRC:1;                   // 10 Global load event configuration for AQCSFRC
    uint32_t rsvd1:5;                     // 15:11 Reserved
    uint32_t rsvd2:16;
};

union GLDCFG_REG {
    uint32_t  all;
    struct  GLDCFG_BITS  bit;
};

struct EPWMXLINK_BITS {                 // bits description
    uint32_t TBPRDLINK:4;                 // 3:0 TBPRD:TBPRDHR  Link
    uint32_t CMPALINK:4;                  // 7:4 CMPA:CMPAHR Link
    uint32_t CMPBLINK:4;                  // 11:8 CMPB:CMPBHR Link
    uint32_t CMPCLINK:4;                  // 15:12 CMPC Link
    uint32_t CMPDLINK:4;                  // 19:16 CMPD Link
    uint32_t rsvd1:8;                     // 27:20 Reserved
    uint32_t GLDCTL2LINK:4;               // 31:28 GLDCTL2 Link
};

union EPWMXLINK_REG {
    uint32_t  all;
    struct  EPWMXLINK_BITS  bit;
};

struct AQCTLA_BITS {                    // bits description
    uint32_t ZRO:2;                       // 1:0 Action Counter = Zero
    uint32_t PRD:2;                       // 3:2 Action Counter = Period
    uint32_t CAU:2;                       // 5:4 Action Counter = Compare A Up
    uint32_t CAD:2;                       // 7:6 Action Counter = Compare A Down
    uint32_t CBU:2;                       // 9:8 Action Counter = Compare B Up
    uint32_t CBD:2;                       // 11:10 Action Counter = Compare B Down
    uint32_t rsvd1:4;                     // 15:12 Reserved
    uint32_t rsvd2:16;
};

union AQCTLA_REG {
    uint32_t  all;
    struct  AQCTLA_BITS  bit;
};

struct AQCTLA2_BITS {                   // bits description
    uint32_t T1U:2;                       // 1:0 Action when event occurs on T1 in UP-Count
    uint32_t T1D:2;                       // 3:2 Action when event occurs on T1 in DOWN-Count
    uint32_t T2U:2;                       // 5:4 Action when event occurs on T2 in UP-Count
    uint32_t T2D:2;                       // 7:6 Action when event occurs on T2 in DOWN-Count
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union AQCTLA2_REG {
    uint32_t  all;
    struct  AQCTLA2_BITS  bit;
};

struct AQCTLB_BITS {                    // bits description
    uint32_t ZRO:2;                       // 1:0 Action Counter = Zero
    uint32_t PRD:2;                       // 3:2 Action Counter = Period
    uint32_t CAU:2;                       // 5:4 Action Counter = Compare A Up
    uint32_t CAD:2;                       // 7:6 Action Counter = Compare A Down
    uint32_t CBU:2;                       // 9:8 Action Counter = Compare B Up
    uint32_t CBD:2;                       // 11:10 Action Counter = Compare B Down
    uint32_t rsvd1:4;                     // 15:12 Reserved
    uint32_t rsvd2:16;
};

union AQCTLB_REG {
    uint32_t  all;
    struct  AQCTLB_BITS  bit;
};

struct AQCTLB2_BITS {                   // bits description
    uint32_t T1U:2;                       // 1:0 Action when event occurs on T1 in UP-Count
    uint32_t T1D:2;                       // 3:2 Action when event occurs on T1 in DOWN-Count
    uint32_t T2U:2;                       // 5:4 Action when event occurs on T2 in UP-Count
    uint32_t T2D:2;                       // 7:6 Action when event occurs on T2 in DOWN-Count
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union AQCTLB2_REG {
    uint32_t  all;
    struct  AQCTLB2_BITS  bit;
};

struct AQSFRC_BITS {                    // bits description
    uint32_t ACTSFA:2;                    // 1:0 Action when One-time SW Force A Invoked
    uint32_t OTSFA:1;                     // 2 One-time SW Force A Output
    uint32_t ACTSFB:2;                    // 4:3 Action when One-time SW Force B Invoked
    uint32_t OTSFB:1;                     // 5 One-time SW Force A Output
    uint32_t RLDCSF:2;                    // 7:6 Reload from Shadow Options
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union AQSFRC_REG {
    uint32_t  all;
    struct  AQSFRC_BITS  bit;
};

struct AQCSFRC_BITS {                   // bits description
    uint32_t CSFA:2;                      // 1:0 Continuous Software Force on output A
    uint32_t CSFB:2;                      // 3:2 Continuous Software Force on output B
    uint32_t rsvd1:12;                    // 15:4 Reserved
    uint32_t rsvd2:16;
};

union AQCSFRC_REG {
    uint32_t  all;
    struct  AQCSFRC_BITS  bit;
};

struct DBREDHR_BITS {                   // bits description
    uint32_t rsvd1:1;                     // 0 Reserved
    uint32_t rsvd2:7;                     // 7:1 Reserved
    uint32_t rsvd3:1;                     // 8 Reserved
    uint32_t DBREDHR:7;                   // 15:9 DBREDHR High Resolution Bits
    uint32_t rsvd4:16;
};

union DBREDHR_REG {
    uint32_t  all;
    struct  DBREDHR_BITS  bit;
};

struct DBRED_BITS {                     // bits description
    uint32_t DBRED:14;                    // 13:0 Rising edge delay value
    uint32_t rsvd1:2;                     // 15:14 Reserved
    uint32_t rsvd2:16;
};

union DBRED_REG {
    uint32_t  all;
    struct  DBRED_BITS  bit;
};

struct DBFEDHR_BITS {                   // bits description
    uint32_t rsvd1:1;                     // 0 Reserved
    uint32_t rsvd2:7;                     // 7:1 Reserved
    uint32_t rsvd3:1;                     // 8 Reserved
    uint32_t DBFEDHR:7;                   // 15:9 DBFEDHR High Resolution Bits
    uint32_t rsvd4:16;
};

union DBFEDHR_REG {
    uint32_t  all;
    struct  DBFEDHR_BITS  bit;
};

struct DBFED_BITS {                       // bits description
    uint32_t DBFED:14;                    // 13:0 Falling edge delay value
    uint32_t rsvd1:2;                     // 15:14 Reserved
    uint32_t rsvd2:16;
};

union DBFED_REG {
    uint32_t  all;
    struct  DBFED_BITS  bit;
};

struct TBPHS_BITS {                       // bits description
    //uint32_t TBPHSHR:16;                // 15:0 Extension Register for HRPWM Phase (8-bits)
    //uint32_t TBPHS:16;                  // 31:16 Phase Offset Register
    uint32_t TBPHS:16;                    // 15:0 Phase Offset Register
    uint32_t rsvd1:16;                    // 31:16 Reserved
};

union TBPHS_REG {
    uint32_t  all;
    struct  TBPHS_BITS  bit;
};

struct CMPA_BITS {                        // bits description
    //uint32_t CMPAHR:16;                 // 15:0 Compare A HRPWM Extension Register
    //uint32_t CMPA:16;                   // 31:16 Compare A Register
    uint32_t CMPA:16;                     // 15:0 Compare A Register
    uint32_t rsvd1:16;                    // 31:16 Reserved
};

union CMPA_REG {
    uint32_t  all;
    struct  CMPA_BITS  bit;
};

struct CMPB_BITS {                        // bits description
    //uint32_t CMPBHR:16;                 // 15:0 Compare B High Resolution Bits
    //uint32_t CMPB:16;                   // 31:16 Compare B Register
    uint32_t CMPB:16;                     // 15:0 Compare B Register
    uint32_t rsvd1:16;                    // 31:16 Reserved
};

union CMPB_REG {
    uint32_t  all;
    struct  CMPB_BITS  bit;
};

struct GLDCTL2_BITS {                     // bits description
    uint32_t OSHTLD:1;                    // 0 Enable reload event in one shot mode
    uint32_t GFRCLD:1;                    // 1 Force reload event in one shot mode
    uint32_t rsvd1:14;                    // 15:2 Reserved
    uint32_t rsvd2:16;
};

union GLDCTL2_REG {
    uint32_t  all;
    struct  GLDCTL2_BITS  bit;
};

struct TZSEL_BITS {                       // bits description
    uint32_t CBC1:1;                      // 0 TZ1 CBC select
    uint32_t CBC2:1;                      // 1 TZ2 CBC select
    uint32_t CBC3:1;                      // 2 TZ3 CBC select
    uint32_t CBC4:1;                      // 3 TZ4 CBC select
    uint32_t CBC5:1;                      // 4 TZ5 CBC select
    uint32_t CBC6:1;                      // 5 TZ6 CBC select
    uint32_t DCAEVT2:1;                   // 6 DCAEVT2 CBC select
    uint32_t DCBEVT2:1;                   // 7 DCBEVT2 CBC select
    uint32_t OSHT1:1;                     // 8 One-shot TZ1 select
    uint32_t OSHT2:1;                     // 9 One-shot TZ2 select
    uint32_t OSHT3:1;                     // 10 One-shot TZ3 select
    uint32_t OSHT4:1;                     // 11 One-shot TZ4 select
    uint32_t OSHT5:1;                     // 12 One-shot TZ5 select
    uint32_t OSHT6:1;                     // 13 One-shot TZ6 select
    uint32_t DCAEVT1:1;                   // 14 One-shot DCAEVT1 select
    uint32_t DCBEVT1:1;                   // 15 One-shot DCBEVT1 select
    uint32_t rsvd1:16;
};

union TZSEL_REG {
    uint32_t  all;
    struct  TZSEL_BITS  bit;
};

struct TZDCSEL_BITS {                   // bits description
    uint32_t DCAEVT1:3;                   // 2:0 Digital Compare Output A Event 1
    uint32_t DCAEVT2:3;                   // 5:3 Digital Compare Output A Event 2
    uint32_t DCBEVT1:3;                   // 8:6 Digital Compare Output B Event 1
    uint32_t DCBEVT2:3;                   // 11:9 Digital Compare Output B Event 2
    uint32_t rsvd1:4;                     // 15:12 Reserved
    uint32_t rsvd2:16;
};

union TZDCSEL_REG {
    uint32_t  all;
    struct  TZDCSEL_BITS  bit;
};

struct TZCTL_BITS {                     // bits description
    uint32_t TZA:2;                       // 1:0 TZ1 to TZ6 Trip Action On EPWMxA
    uint32_t TZB:2;                       // 3:2 TZ1 to TZ6 Trip Action On EPWMxB
    uint32_t DCAEVT1:2;                   // 5:4 EPWMxA action on DCAEVT1
    uint32_t DCAEVT2:2;                   // 7:6 EPWMxA action on DCAEVT2
    uint32_t DCBEVT1:2;                   // 9:8 EPWMxB action on DCBEVT1
    uint32_t DCBEVT2:2;                   // 11:10 EPWMxB action on DCBEVT2
    uint32_t rsvd1:4;                     // 15:12 Reserved
    uint32_t rsvd2:16;
};

union TZCTL_REG {
    uint32_t  all;
    struct  TZCTL_BITS  bit;
};

struct TZCTL2_BITS {                    // bits description
    uint32_t TZAU:3;                      // 2:0 Trip Action On EPWMxA while Count direction is UP
    uint32_t TZAD:3;                      // 5:3 Trip Action On EPWMxA while Count direction is DOWN
    uint32_t TZBU:3;                      // 8:6 Trip Action On EPWMxB while Count direction is UP
    uint32_t TZBD:3;                      // 11:9 Trip Action On EPWMxB while Count direction is DOWN
    uint32_t rsvd1:3;                     // 14:12 Reserved
    uint32_t ETZE:1;                      // 15 TZCTL2 Enable
    uint32_t rsvd2:16;
};

union TZCTL2_REG {
    uint32_t  all;
    struct  TZCTL2_BITS  bit;
};

struct TZCTLDCA_BITS {                  // bits description
    uint32_t DCAEVT1U:3;                  // 2:0 DCAEVT1 Action On EPWMxA while Count direction is UP
    uint32_t DCAEVT1D:3;                  // 5:3 DCAEVT1 Action On EPWMxA while Count direction is DOWN
    uint32_t DCAEVT2U:3;                  // 8:6 DCAEVT2 Action On EPWMxA while Count direction is UP
    uint32_t DCAEVT2D:3;                  // 11:9 DCAEVT2 Action On EPWMxA while Count direction is DOWN
    uint32_t rsvd1:4;                     // 15:12 Reserved
    uint32_t rsvd2:16;
};

union TZCTLDCA_REG {
    uint32_t  all;
    struct  TZCTLDCA_BITS  bit;
};

struct TZCTLDCB_BITS {                  // bits description
    uint32_t DCBEVT1U:3;                  // 2:0 DCBEVT1 Action On EPWMxA while Count direction is UP
    uint32_t DCBEVT1D:3;                  // 5:3 DCBEVT1 Action On EPWMxA while Count direction is DOWN
    uint32_t DCBEVT2U:3;                  // 8:6 DCBEVT2 Action On EPWMxA while Count direction is UP
    uint32_t DCBEVT2D:3;                  // 11:9 DCBEVT2 Action On EPWMxA while Count direction is DOWN
    uint32_t rsvd1:4;                     // 15:12 Reserved
    uint32_t rsvd2:16;
};

union TZCTLDCB_REG {
    uint32_t  all;
    struct  TZCTLDCB_BITS  bit;
};

struct TZEINT_BITS {                    // bits description
    uint32_t rsvd1:1;                     // 0 Reserved
    uint32_t CBC:1;                       // 1 Trip Zones Cycle By Cycle Int Enable
    uint32_t OST:1;                       // 2 Trip Zones One Shot Int Enable
    uint32_t DCAEVT1:1;                   // 3 Digital Compare A Event 1 Int Enable
    uint32_t DCAEVT2:1;                   // 4 Digital Compare A Event 2 Int Enable
    uint32_t DCBEVT1:1;                   // 5 Digital Compare B Event 1 Int Enable
    uint32_t DCBEVT2:1;                   // 6 Digital Compare B Event 2 Int Enable
    uint32_t rsvd2:9;                     // 15:7 Reserved
    uint32_t rsvd3:16;
};

union TZEINT_REG {
    uint32_t  all;
    struct  TZEINT_BITS  bit;
};

struct TZFLG_BITS {                     // bits description
    uint32_t INT:1;                       // 0 Global Int Status Flag
    uint32_t CBC:1;                       // 1 Trip Zones Cycle By Cycle Flag
    uint32_t OST:1;                       // 2 Trip Zones One Shot Flag
    uint32_t DCAEVT1:1;                   // 3 Digital Compare A Event 1 Flag
    uint32_t DCAEVT2:1;                   // 4 Digital Compare A Event 2 Flag
    uint32_t DCBEVT1:1;                   // 5 Digital Compare B Event 1 Flag
    uint32_t DCBEVT2:1;                   // 6 Digital Compare B Event 2 Flag
    uint32_t rsvd1:9;                     // 15:7 Reserved
    uint32_t rsvd2:16;
};

union TZFLG_REG {
    uint32_t  all;
    struct  TZFLG_BITS  bit;
};

struct TZCBCFLG_BITS {                  // bits description
    uint32_t CBC1:1;                      // 0 Latched Status Flag for CBC1 Trip Latch
    uint32_t CBC2:1;                      // 1 Latched Status Flag for CBC2 Trip Latch
    uint32_t CBC3:1;                      // 2 Latched Status Flag for CBC3 Trip Latch
    uint32_t CBC4:1;                      // 3 Latched Status Flag for CBC4 Trip Latch
    uint32_t CBC5:1;                      // 4 Latched Status Flag for CBC5 Trip Latch
    uint32_t CBC6:1;                      // 5 Latched Status Flag for CBC6 Trip Latch
    uint32_t DCAEVT2:1;                   // 6 Latched Status Flag for Digital Compare Output A Event 2
    uint32_t DCBEVT2:1;                   // 7 Latched Status Flag for Digital Compare Output B Event 2
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union TZCBCFLG_REG {
    uint32_t  all;
    struct  TZCBCFLG_BITS  bit;
};

struct TZOSTFLG_BITS {                  // bits description
    uint32_t OST1:1;                      // 0 Latched Status Flag for OST1 Trip Latch
    uint32_t OST2:1;                      // 1 Latched Status Flag for OST2 Trip Latch
    uint32_t OST3:1;                      // 2 Latched Status Flag for OST3 Trip Latch
    uint32_t OST4:1;                      // 3 Latched Status Flag for OST4 Trip Latch
    uint32_t OST5:1;                      // 4 Latched Status Flag for OST5 Trip Latch
    uint32_t OST6:1;                      // 5 Latched Status Flag for OST6 Trip Latch
    uint32_t DCAEVT1:1;                   // 6 Latched Status Flag for Digital Compare Output A Event 1
    uint32_t DCBEVT1:1;                   // 7 Latched Status Flag for Digital Compare Output B Event 1
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union TZOSTFLG_REG {
    uint32_t  all;
    struct  TZOSTFLG_BITS  bit;
};

struct TZCLR_BITS {                     // bits description
    uint32_t INT:1;                       // 0 Global Interrupt Clear Flag
    uint32_t CBC:1;                       // 1 Cycle-By-Cycle Flag Clear
    uint32_t OST:1;                       // 2 One-Shot Flag Clear
    uint32_t DCAEVT1:1;                   // 3 DCAVET1 Flag Clear
    uint32_t DCAEVT2:1;                   // 4 DCAEVT2 Flag Clear
    uint32_t DCBEVT1:1;                   // 5 DCBEVT1 Flag Clear
    uint32_t DCBEVT2:1;                   // 6 DCBEVT2 Flag Clear
    uint32_t rsvd1:7;                     // 13:7 Reserved
    uint32_t CBCPULSE:2;                  // 15:14 Clear Pulse for CBC Trip Latch
    uint32_t rsvd2:16;
};

union TZCLR_REG {
    uint32_t  all;
    struct  TZCLR_BITS  bit;
};

struct TZCBCCLR_BITS {                  // bits description
    uint32_t CBC1:1;                      // 0 Clear Flag for Cycle-By-Cycle (CBC1) Trip Latch
    uint32_t CBC2:1;                      // 1 Clear Flag for Cycle-By-Cycle (CBC2) Trip Latch
    uint32_t CBC3:1;                      // 2 Clear Flag for Cycle-By-Cycle (CBC3) Trip Latch
    uint32_t CBC4:1;                      // 3 Clear Flag for Cycle-By-Cycle (CBC4) Trip Latch
    uint32_t CBC5:1;                      // 4 Clear Flag for Cycle-By-Cycle (CBC5) Trip Latch
    uint32_t CBC6:1;                      // 5 Clear Flag for Cycle-By-Cycle (CBC6) Trip Latch
    uint32_t DCAEVT2:1;                   // 6 Clear Flag forDCAEVT2 selected for CBC
    uint32_t DCBEVT2:1;                   // 7 Clear Flag for DCBEVT2 selected for CBC
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union TZCBCCLR_REG {
    uint32_t  all;
    struct  TZCBCCLR_BITS  bit;
};

struct TZOSTCLR_BITS {                  // bits description
    uint32_t OST1:1;                      // 0 Clear Flag for Oneshot (OST1) Trip Latch
    uint32_t OST2:1;                      // 1 Clear Flag for Oneshot (OST2) Trip Latch
    uint32_t OST3:1;                      // 2 Clear Flag for Oneshot (OST3) Trip Latch
    uint32_t OST4:1;                      // 3 Clear Flag for Oneshot (OST4) Trip Latch
    uint32_t OST5:1;                      // 4 Clear Flag for Oneshot (OST5) Trip Latch
    uint32_t OST6:1;                      // 5 Clear Flag for Oneshot (OST6) Trip Latch
    uint32_t DCAEVT1:1;                   // 6 Clear Flag for DCAEVT1 selected for OST
    uint32_t DCBEVT1:1;                   // 7 Clear Flag for DCBEVT1 selected for OST
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union TZOSTCLR_REG {
    uint32_t  all;
    struct  TZOSTCLR_BITS  bit;
};

struct TZFRC_BITS {                     // bits description
    uint32_t rsvd1:1;                     // 0 Reserved
    uint32_t CBC:1;                       // 1 Force Trip Zones Cycle By Cycle Event
    uint32_t OST:1;                       // 2 Force Trip Zones One Shot Event
    uint32_t DCAEVT1:1;                   // 3 Force Digital Compare A Event 1
    uint32_t DCAEVT2:1;                   // 4 Force Digital Compare A Event 2
    uint32_t DCBEVT1:1;                   // 5 Force Digital Compare B Event 1
    uint32_t DCBEVT2:1;                   // 6 Force Digital Compare B Event 2
    uint32_t rsvd2:9;                     // 15:7 Reserved
    uint32_t rsvd3:16;
};

union TZFRC_REG {
    uint32_t  all;
    struct  TZFRC_BITS  bit;
};

struct ETSEL_BITS {                     // bits description
    uint32_t INTSEL:3;                    // 2:0 EPWMxINTn Select
    uint32_t INTEN:1;                     // 3 EPWMxINTn Enable
    uint32_t SOCASELCMP:1;                // 4 EPWMxSOCA Compare Select
    uint32_t SOCBSELCMP:1;                // 5 EPWMxSOCB Compare Select
    uint32_t INTSELCMP:1;                 // 6 EPWMxINT Compare Select
    uint32_t rsvd1:1;                     // 7 Reserved
    uint32_t SOCASEL:3;                   // 10:8 Start of Conversion A Select
    uint32_t SOCAEN:1;                    // 11 Start of Conversion A Enable
    uint32_t SOCBSEL:3;                   // 14:12 Start of Conversion B Select
    uint32_t SOCBEN:1;                    // 15 Start of Conversion B Enable
    uint32_t rsvd2:16;
};

union ETSEL_REG {
    uint32_t  all;
    struct  ETSEL_BITS  bit;
};

struct ETPS_BITS {                      // bits description
    uint32_t INTPRD:2;                    // 1:0 EPWMxINTn Period Select
    uint32_t INTCNT:2;                    // 3:2 EPWMxINTn Counter Register
    uint32_t INTPSSEL:1;                  // 4 EPWMxINTn Pre-Scale Selection Bits
    uint32_t SOCPSSEL:1;                  // 5 EPWMxSOC A/B  Pre-Scale Selection Bits
    uint32_t rsvd1:2;                     // 7:6 Reserved
    uint32_t SOCAPRD:2;                   // 9:8 EPWMxSOCA Period Select
    uint32_t SOCACNT:2;                   // 11:10 EPWMxSOCA Counter Register
    uint32_t SOCBPRD:2;                   // 13:12 EPWMxSOCB Period Select
    uint32_t SOCBCNT:2;                   // 15:14 EPWMxSOCB Counter
    uint32_t rsvd2:16;
};

union ETPS_REG {
    uint32_t  all;
    struct  ETPS_BITS  bit;
};

struct ETFLG_BITS {                     // bits description
    uint32_t INT:1;                       // 0 EPWMxINTn Flag
    uint32_t rsvd1:1;                     // 1 Reserved
    uint32_t SOCA:1;                      // 2 EPWMxSOCA Flag
    uint32_t SOCB:1;                      // 3 EPWMxSOCB Flag
    uint32_t rsvd2:12;                    // 15:4 Reserved
    uint32_t rsvd3:16;
};

union ETFLG_REG {
    uint32_t  all;
    struct  ETFLG_BITS  bit;
};

struct ETCLR_BITS {                     // bits description
    uint32_t INT:1;                       // 0 EPWMxINTn Clear
    uint32_t rsvd1:1;                     // 1 Reserved
    uint32_t SOCA:1;                      // 2 EPWMxSOCA Clear
    uint32_t SOCB:1;                      // 3 EPWMxSOCB Clear
    uint32_t rsvd2:12;                    // 15:4 Reserved
    uint32_t rsvd3:16;
};

union ETCLR_REG {
    uint32_t  all;
    struct  ETCLR_BITS  bit;
};

struct ETFRC_BITS {                     // bits description
    uint32_t INT:1;                       // 0 EPWMxINTn Force
    uint32_t rsvd1:1;                     // 1 Reserved
    uint32_t SOCA:1;                      // 2 EPWMxSOCA Force
    uint32_t SOCB:1;                      // 3 EPWMxSOCB Force
    uint32_t rsvd2:12;                    // 15:4 Reserved
    uint32_t rsvd3:16;
};

union ETFRC_REG {
    uint32_t  all;
    struct  ETFRC_BITS  bit;
};

struct ETINTPS_BITS {                   // bits description
    uint32_t INTPRD2:4;                   // 3:0 EPWMxINTn Period Select
    uint32_t INTCNT2:4;                   // 7:4 EPWMxINTn Counter Register
    uint32_t rsvd1:8;                     // 15:8 Reserved
    uint32_t rsvd2:16;
};

union ETINTPS_REG {
    uint32_t  all;
    struct  ETINTPS_BITS  bit;
};

struct ETSOCPS_BITS {                   // bits description
    uint32_t SOCAPRD2:4;                  // 3:0 EPWMxSOCA Period Select
    uint32_t SOCACNT2:4;                  // 7:4 EPWMxSOCA Counter Register
    uint32_t SOCBPRD2:4;                  // 11:8 EPWMxSOCB Period Select
    uint32_t SOCBCNT2:4;                  // 15:12 EPWMxSOCB Counter Register
    uint32_t rsvd1:16;
};

union ETSOCPS_REG {
    uint32_t  all;
    struct  ETSOCPS_BITS  bit;
};

struct ETCNTINITCTL_BITS {              // bits description
    uint32_t rsvd1:10;                    // 9:0 Reserved
    uint32_t INTINITFRC:1;                // 10 EPWMxINT Counter Initialization Force
    uint32_t SOCAINITFRC:1;               // 11 EPWMxSOCA Counter Initialization Force
    uint32_t SOCBINITFRC:1;               // 12 EPWMxSOCB Counter Initialization Force
    uint32_t INTINITEN:1;                 // 13 EPWMxINT Counter Initialization Enable
    uint32_t SOCAINITEN:1;                // 14 EPWMxSOCA Counter Initialization Enable
    uint32_t SOCBINITEN:1;                // 15 EPWMxSOCB Counter Initialization Enable
    uint32_t rsvd2:16;
};

union ETCNTINITCTL_REG {
    uint32_t  all;
    struct  ETCNTINITCTL_BITS  bit;
};

struct ETCNTINIT_BITS {                 // bits description
    uint32_t INTINIT:4;                   // 3:0 EPWMxINT Counter Initialization Bits
    uint32_t SOCAINIT:4;                  // 7:4 EPWMxSOCA Counter Initialization Bits
    uint32_t SOCBINIT:4;                  // 11:8 EPWMxSOCB Counter Initialization Bits
    uint32_t rsvd1:4;                     // 15:12 Reserved
    uint32_t rsvd2:16;
};

union ETCNTINIT_REG {
    uint32_t  all;
    struct  ETCNTINIT_BITS  bit;
};

struct DCTRIPSEL_BITS {                 // bits description
    uint32_t DCAHCOMPSEL:4;               // 3:0 Digital Compare A High COMP Input Select
    uint32_t DCALCOMPSEL:4;               // 7:4 Digital Compare A Low COMP Input Select
    uint32_t DCBHCOMPSEL:4;               // 11:8 Digital Compare B High COMP Input Select
    uint32_t DCBLCOMPSEL:4;               // 15:12 Digital Compare B Low COMP Input Select
    uint32_t rsvd1:16;
};

union DCTRIPSEL_REG {
    uint32_t  all;
    struct  DCTRIPSEL_BITS  bit;
};

struct DCACTL_BITS {                    // bits description
    uint32_t EVT1SRCSEL:1;                // 0 DCAEVT1 Source Signal
    uint32_t EVT1FRCSYNCSEL:1;            // 1 DCAEVT1 Force Sync Signal
    uint32_t EVT1SOCE:1;                  // 2 DCAEVT1 SOC Enable
    uint32_t EVT1SYNCE:1;                 // 3 DCAEVT1 SYNC Enable
    uint32_t EVT1LATSEL:1;                // 4 DCAEVT1 Latched signal select
    uint32_t EVT1LATCLRSEL:2;             // 6:5 DCAEVT1 Latched clear source select
    uint32_t EVT1LAT:1;                   // 7 Indicates the status of DCAEVT1LAT signal.
    uint32_t EVT2SRCSEL:1;                // 8 DCAEVT2 Source Signal
    uint32_t EVT2FRCSYNCSEL:1;            // 9 DCAEVT2 Force Sync Signal
    uint32_t rsvd1:2;                     // 11:10 Reserved
    uint32_t EVT2LATSEL:1;                // 12 DCAEVT2 Latched signal select
    uint32_t EVT2LATCLRSEL:2;             // 14:13 DCAEVT2 Latched clear source select
    uint32_t EVT2LAT:1;                   // 15 Indicates the status of DCAEVT2LAT signal.
    uint32_t rsvd2:16;
};

union DCACTL_REG {
    uint32_t  all;
    struct  DCACTL_BITS  bit;
};

struct DCBCTL_BITS {                    // bits description
    uint32_t EVT1SRCSEL:1;                // 0 DCBEVT1 Source Signal
    uint32_t EVT1FRCSYNCSEL:1;            // 1 DCBEVT1 Force Sync Signal
    uint32_t EVT1SOCE:1;                  // 2 DCBEVT1 SOC Enable
    uint32_t EVT1SYNCE:1;                 // 3 DCBEVT1 SYNC Enable
    uint32_t EVT1LATSEL:1;                // 4 DCBEVT1 Latched signal select
    uint32_t EVT1LATCLRSEL:2;             // 6:5 DCBEVT1 Latched clear source select
    uint32_t EVT1LAT:1;                   // 7 Indicates the status of DCBEVT1LAT signal.
    uint32_t EVT2SRCSEL:1;                // 8 DCBEVT2 Source Signal
    uint32_t EVT2FRCSYNCSEL:1;            // 9 DCBEVT2 Force Sync Signal
    uint32_t rsvd1:2;                     // 11:10 Reserved
    uint32_t EVT2LATSEL:1;                // 12 DCBEVT2 Latched signal select
    uint32_t EVT2LATCLRSEL:2;             // 14:13 DCBEVT2 Latched clear source select
    uint32_t EVT2LAT:1;                   // 15 Indicates the status of DCBEVT2LAT signal.
    uint32_t rsvd2:16;
};

union DCBCTL_REG {
    uint32_t  all;
    struct  DCBCTL_BITS  bit;
};

struct DCFCTL_BITS {                    // bits description
    uint32_t SRCSEL:2;                    // 1:0 Filter Block Signal Source Select
    uint32_t BLANKE:1;                    // 2 Blanking Enable/Disable
    uint32_t BLANKINV:1;                  // 3 Blanking Window Inversion
    uint32_t PULSESEL:2;                  // 5:4 Pulse Select for Blanking & Capture Alignment
    uint32_t EDGEFILTSEL:1;               // 6 Edge Filter Select
    uint32_t rsvd1:1;                     // 7 Reserved
    uint32_t EDGEMODE:2;                  // 9:8 Edge Mode
    uint32_t EDGECOUNT:3;                 // 12:10 Edge Count
    uint32_t EDGESTATUS:3;                // 15:13 Edge Status
    uint32_t rsvd2:16;
};

union DCFCTL_REG {
    uint32_t  all;
    struct  DCFCTL_BITS  bit;
};

struct DCCAPCTL_BITS {                  // bits description
    uint32_t CAPE:1;                      // 0 Counter Capture Enable
    uint32_t SHDWMODE:1;                  // 1 Counter Capture Mode
    uint32_t rsvd1:11;                    // 12:2 Reserved
    uint32_t CAPSTS:1;                    // 13 Latched Status Flag for Capture Event
    uint32_t CAPCLR:1;                    // 14 DC Capture Latched Status Clear Flag
    uint32_t CAPMODE:1;                   // 15 Counter Capture Mode
    uint32_t rsvd2:16;
};

union DCCAPCTL_REG {
    uint32_t  all;
    struct  DCCAPCTL_BITS  bit;
};

struct BLANKPULSEMIXSEL_BITS {          // bits description
    uint32_t ZRO:1;                       // 0 Zero match enable to BLANKPULSEMIX
    uint32_t PRD:1;                       // 1 Period match enable to BLANKPULSEMIX
    uint32_t CAU:1;                       // 2 CMPA up-count match enable to BLANKPULSEMIX
    uint32_t CAD:1;                       // 3 CMPA down-count match enable to BLANKPULSEMIX
    uint32_t CBU:1;                       // 4 CMPB up-count match enable to BLANKPULSEMIX
    uint32_t CBD:1;                       // 5 CMPB down-count match enable to BLANKPULSEMIX
    uint32_t CCU:1;                       // 6 CMPC up-count match enable to BLANKPULSEMIX
    uint32_t CCD:1;                       // 7 CMPC down-count match enable to BLANKPULSEMIX
    uint32_t CDU:1;                       // 8 CMPD up-count match enable to BLANKPULSEMIX
    uint32_t CDD:1;                       // 9 CMPD down-count match enable to BLANKPULSEMIX
    uint32_t rsvd1:6;                     // 15:10 Reserved
    uint32_t rsvd2:16;
};

union BLANKPULSEMIXSEL_REG {
    uint32_t  all;
    struct  BLANKPULSEMIXSEL_BITS  bit;
};

struct DCAHTRIPSEL_BITS {               // bits description
    uint32_t TRIPINPUT1:1;                // 0 Trip Input 1 Select to DCAH Mux
    uint32_t TRIPINPUT2:1;                // 1 Trip Input 2 Select to DCAH Mux
    uint32_t TRIPINPUT3:1;                // 2 Trip Input 3 Select to DCAH Mux
    uint32_t TRIPINPUT4:1;                // 3 Trip Input 4 Select to DCAH Mux
    uint32_t TRIPINPUT5:1;                // 4 Trip Input 5 Select to DCAH Mux
    uint32_t TRIPINPUT6:1;                // 5 Trip Input 6 Select to DCAH Mux
    uint32_t TRIPINPUT7:1;                // 6 Trip Input 7 Select to DCAH Mux
    uint32_t TRIPINPUT8:1;                // 7 Trip Input 8 Select to DCAH Mux
    uint32_t TRIPINPUT9:1;                // 8 Trip Input 9 Select to DCAH Mux
    uint32_t TRIPINPUT10:1;               // 9 Trip Input 10 Select to DCAH Mux
    uint32_t TRIPINPUT11:1;               // 10 Trip Input 11 Select to DCAH Mux
    uint32_t TRIPINPUT12:1;               // 11 Trip Input 12 Select to DCAH Mux
    uint32_t rsvd1:1;                     // 12 Reserved
    uint32_t TRIPINPUT14:1;               // 13 Trip Input 14 Select to DCAH Mux
    uint32_t TRIPINPUT15:1;               // 14 Trip Input 15 Select to DCAH Mux
    uint32_t rsvd2:1;                     // 15 Reserved
    uint32_t rsvd3:16;
};

union DCAHTRIPSEL_REG {
    uint32_t  all;
    struct  DCAHTRIPSEL_BITS  bit;
};

struct DCALTRIPSEL_BITS {               // bits description
    uint32_t TRIPINPUT1:1;                // 0 Trip Input 1 Select to DCAL Mux
    uint32_t TRIPINPUT2:1;                // 1 Trip Input 2 Select to DCAL Mux
    uint32_t TRIPINPUT3:1;                // 2 Trip Input 3 Select to DCAL Mux
    uint32_t TRIPINPUT4:1;                // 3 Trip Input 4 Select to DCAL Mux
    uint32_t TRIPINPUT5:1;                // 4 Trip Input 5 Select to DCAL Mux
    uint32_t TRIPINPUT6:1;                // 5 Trip Input 6 Select to DCAL Mux
    uint32_t TRIPINPUT7:1;                // 6 Trip Input 7 Select to DCAL Mux
    uint32_t TRIPINPUT8:1;                // 7 Trip Input 8 Select to DCAL Mux
    uint32_t TRIPINPUT9:1;                // 8 Trip Input 9 Select to DCAL Mux
    uint32_t TRIPINPUT10:1;               // 9 Trip Input 10 Select to DCAL Mux
    uint32_t TRIPINPUT11:1;               // 10 Trip Input 11 Select to DCAL Mux
    uint32_t TRIPINPUT12:1;               // 11 Trip Input 12 Select to DCAL Mux
    uint32_t rsvd1:1;                     // 12 Reserved
    uint32_t TRIPINPUT14:1;               // 13 Trip Input 14 Select to DCAL Mux
    uint32_t TRIPINPUT15:1;               // 14 Trip Input 15 Select to DCAL Mux
    uint32_t rsvd2:1;                     // 15 Reserved
    uint32_t rsvd3:16;
};

union DCALTRIPSEL_REG {
    uint32_t  all;
    struct  DCALTRIPSEL_BITS  bit;
};

struct DCBHTRIPSEL_BITS {               // bits description
    uint32_t TRIPINPUT1:1;                // 0 Trip Input 1 Select to DCBH Mux
    uint32_t TRIPINPUT2:1;                // 1 Trip Input 2 Select to DCBH Mux
    uint32_t TRIPINPUT3:1;                // 2 Trip Input 3 Select to DCBH Mux
    uint32_t TRIPINPUT4:1;                // 3 Trip Input 4 Select to DCBH Mux
    uint32_t TRIPINPUT5:1;                // 4 Trip Input 5 Select to DCBH Mux
    uint32_t TRIPINPUT6:1;                // 5 Trip Input 6 Select to DCBH Mux
    uint32_t TRIPINPUT7:1;                // 6 Trip Input 7 Select to DCBH Mux
    uint32_t TRIPINPUT8:1;                // 7 Trip Input 8 Select to DCBH Mux
    uint32_t TRIPINPUT9:1;                // 8 Trip Input 9 Select to DCBH Mux
    uint32_t TRIPINPUT10:1;               // 9 Trip Input 10 Select to DCBH Mux
    uint32_t TRIPINPUT11:1;               // 10 Trip Input 11 Select to DCBH Mux
    uint32_t TRIPINPUT12:1;               // 11 Trip Input 12 Select to DCBH Mux
    uint32_t rsvd1:1;                     // 12 Reserved
    uint32_t TRIPINPUT14:1;               // 13 Trip Input 14 Select to DCBH Mux
    uint32_t TRIPINPUT15:1;               // 14 Trip Input 15 Select to DCBH Mux
    uint32_t rsvd2:1;                     // 15 Reserved
    uint32_t rsvd3:16;
};

union DCBHTRIPSEL_REG {
    uint32_t  all;
    struct  DCBHTRIPSEL_BITS  bit;
};

struct DCBLTRIPSEL_BITS {               // bits description
    uint32_t TRIPINPUT1:1;                // 0 Trip Input 1 Select to DCBL Mux
    uint32_t TRIPINPUT2:1;                // 1 Trip Input 2 Select to DCBL Mux
    uint32_t TRIPINPUT3:1;                // 2 Trip Input 3 Select to DCBL Mux
    uint32_t TRIPINPUT4:1;                // 3 Trip Input 4 Select to DCBL Mux
    uint32_t TRIPINPUT5:1;                // 4 Trip Input 5 Select to DCBL Mux
    uint32_t TRIPINPUT6:1;                // 5 Trip Input 6 Select to DCBL Mux
    uint32_t TRIPINPUT7:1;                // 6 Trip Input 7 Select to DCBL Mux
    uint32_t TRIPINPUT8:1;                // 7 Trip Input 8 Select to DCBL Mux
    uint32_t TRIPINPUT9:1;                // 8 Trip Input 9 Select to DCBL Mux
    uint32_t TRIPINPUT10:1;               // 9 Trip Input 10 Select to DCBL Mux
    uint32_t TRIPINPUT11:1;               // 10 Trip Input 11 Select to DCBL Mux
    uint32_t TRIPINPUT12:1;               // 11 Trip Input 12 Select to DCBL Mux
    uint32_t rsvd1:1;                     // 12 Reserved
    uint32_t TRIPINPUT14:1;               // 13 Trip Input 14 Select to DCBL Mux
    uint32_t TRIPINPUT15:1;               // 14 Trip Input 15 Select to DCBL Mux
    uint32_t rsvd2:1;                     // 15 Reserved
    uint32_t rsvd3:16;
};

union DCBLTRIPSEL_REG {
    uint32_t  all;
    struct  DCBLTRIPSEL_BITS  bit;
};

struct EPWMLOCK_BITS {                  // bits description
    uint32_t HRLOCK:1;                    // 0 HRPWM Register Set Lock
    uint32_t GLLOCK:1;                    // 1 Global Load Register Set Lock
    uint32_t TZCFGLOCK:1;                 // 2 TripZone Register Set Lock
    uint32_t TZCLRLOCK:1;                 // 3 TripZone Clear Register Set Lock
    uint32_t DCLOCK:1;                    // 4 Digital Compare Register Set Lock
    uint32_t rsvd1:11;                    // 15:5 Reserved
    uint32_t KEY:16;                      // 31:16 Key to write to this register
};

union EPWMLOCK_REG {
    uint32_t  all;
    struct  EPWMLOCK_BITS  bit;
};

struct EPWMOE_BITS {                    // bits description
    uint32_t OE:2;                      // 0-1 EPWM output pin enable 
    uint32_t rsvd1:30;                  // 31:2 Reserved
};

union EPWMOE_REG {
    uint32_t  all;
    struct  EPWMOE_BITS  bit;
};

struct EPWM_REGS {
    union   TBCTL_REG                        TBCTL;                        // Time Base Control Register
    union   TBCTL2_REG                       TBCTL2;                       // Time Base Control Register 2
    uint32_t                                 rsvd1;                        // Reserved
    union   EPWMSYNCINSEL_REG                EPWMSYNCINSEL;                // EPWMxSYNCIN Source Select Register
    uint32_t                                 TBCTR;                        // Time Base Counter Register
    union   TBSTS_REG                        TBSTS;                        // Time Base Status Register
    union   EPWMSYNCOUTEN_REG                EPWMSYNCOUTEN;                // EPWMxSYNCOUT Source Enable Register
    union   TBCTL3_REG                       TBCTL3;                       // Time Base Control Register 3
    union   CMPCTL_REG                       CMPCTL;                       // Counter Compare Control Register
    union   CMPCTL2_REG                      CMPCTL2;                      // Counter Compare Control Register 2
    uint32_t                                 rsvd2[2];                     // Reserved
    union   DBCTL_REG                        DBCTL;                        // Dead-Band Generator Control Register
    union   DBCTL2_REG                       DBCTL2;                       // Dead-Band Generator Control Register 2
    uint32_t                                 rsvd3[2];                     // Reserved
    union   AQCTL_REG                        AQCTL;                        // Action Qualifier Control Register
    union   AQTSRCSEL_REG                    AQTSRCSEL;                    // Action Qualifier Trigger Event Source Select Register
    uint32_t                                 rsvd4[2];                     // Reserved
    union   PCCTL_REG                        PCCTL;                        // PWM Chopper Control Register
    uint32_t                                 rsvd5[3];                     // Reserved
    union   VCAPCTL_REG                      VCAPCTL;                      // Valley Capture Control Register
    union   VCNTCFG_REG                      VCNTCFG;                      // Valley Counter Config Register
    uint32_t                                 rsvd6[6];                     // Reserved
    union   HRCNFG_REG                       HRCNFG;                       // HRPWM Configuration Register
    union   HRPWR_REG                        HRPWR;                        // HRPWM Power Register
    uint32_t                                 rsvd7[4];                     // Reserved
    union   HRMSTEP_REG                      HRMSTEP;                      // HRPWM MEP Step Register
    union   HRCNFG2_REG                      HRCNFG2;                      // HRPWM Configuration 2 Register
    uint32_t                                 rsvd8[5];                     // Reserved
    union   HRPCTL_REG                       HRPCTL;                       // High Resolution Period Control Register
    union   TRREM_REG                        TRREM;                        // HRPWM High Resolution Remainder Register
    uint32_t                                 rsvd9[5];                     // Reserved
    union   GLDCTL_REG                       GLDCTL;                       // Global PWM Load Control Register
    union   GLDCFG_REG                       GLDCFG;                       // Global PWM Load Config Register
    uint32_t                                 rsvd10[2];                    // Reserved
    union   EPWMXLINK_REG                    EPWMXLINK;                    // EPWMx Link Register
    uint32_t                                 rsvd11[7];                    // Reserved
    union   AQCTLA_REG                       AQCTLA;                       // Action Qualifier Control Register For Output A
    union   AQCTLA2_REG                      AQCTLA2;                      // Additional Action Qualifier Control Register For Output A
    union   AQCTLB_REG                       AQCTLB;                       // Action Qualifier Control Register For Output B
    union   AQCTLB2_REG                      AQCTLB2;                      // Additional Action Qualifier Control Register For Output B
    uint32_t                                 rsvd12[3];                    // Reserved
    union   AQSFRC_REG                       AQSFRC;                       // Action Qualifier Software Force Register
    uint32_t                                 rsvd13;                       // Reserved
    union   AQCSFRC_REG                      AQCSFRC;                      // Action Qualifier Continuous S/W Force Register
    uint32_t                                 rsvd14[6];                    // Reserved
    union   DBREDHR_REG                      DBREDHR;                      // Dead-Band Generator Rising Edge Delay High Resolution Mirror Register
    union   DBRED_REG                        DBRED;                        // Dead-Band Generator Rising Edge Delay High Resolution Mirror Register
    union   DBFEDHR_REG                      DBFEDHR;                      // Dead-Band Generator Falling Edge Delay High Resolution Register
    union   DBFED_REG                        DBFED;                        // Dead-Band Generator Falling Edge Delay Count Register
    uint32_t                                 rsvd15[12];                   // Reserved
    union   TBPHS_REG                        TBPHS;                        // Time Base Phase High
    uint32_t                                 rsvd16;
    uint32_t                                 TBPRDHR;                      // Time Base Period High Resolution Register
    uint32_t                                 TBPRD;                        // Time Base Period Register
    uint32_t                                 rsvd17[6];                    // Reserved
    union   CMPA_REG                         CMPA;                         // Counter Compare A Register
    uint32_t                                 rsvd18;                       // Reserved
    union   CMPB_REG                         CMPB;                         // Compare B Register
    uint32_t                                 rsvd19[2];                    // Reserved
    uint32_t                                 CMPC;                         // Counter Compare C Register
    uint32_t                                 rsvd20;                       // Reserved
    uint32_t                                 CMPD;                         // Counter Compare D Register
    uint32_t                                 rsvd21[2];                    // Reserved
    union   GLDCTL2_REG                      GLDCTL2;                      // Global PWM Load Control Register 2
    uint32_t                                 rsvd22[2];                    // Reserved
    uint32_t                                 SWVDELVAL;                    // Software Valley Mode Delay Register
    uint32_t                                 rsvd23[8];                    // Reserved
    union   TZSEL_REG                        TZSEL;                        // Trip Zone Select Register
    uint32_t                                 rsvd24;                       // Reserved
    union   TZDCSEL_REG                      TZDCSEL;                      // Trip Zone Digital Comparator Select Register
    uint32_t                                 rsvd25;                       // Reserved
    union   TZCTL_REG                        TZCTL;                        // Trip Zone Control Register
    union   TZCTL2_REG                       TZCTL2;                       // Additional Trip Zone Control Register
    union   TZCTLDCA_REG                     TZCTLDCA;                     // Trip Zone Control Register Digital Compare A
    union   TZCTLDCB_REG                     TZCTLDCB;                     // Trip Zone Control Register Digital Compare B
    uint32_t                                 rsvd26[5];                    // Reserved
    union   TZEINT_REG                       TZEINT;                       // Trip Zone Enable Interrupt Register
    uint32_t                                 rsvd27[5];                    // Reserved
    union   TZFLG_REG                        TZFLG;                        // Trip Zone Flag Register
    union   TZCBCFLG_REG                     TZCBCFLG;                     // Trip Zone CBC Flag Register
    union   TZOSTFLG_REG                     TZOSTFLG;                     // Trip Zone OST Flag Register
    uint32_t                                 rsvd28;                       // Reserved
    union   TZCLR_REG                        TZCLR;                        // Trip Zone Clear Register
    union   TZCBCCLR_REG                     TZCBCCLR;                     // Trip Zone CBC Clear Register
    union   TZOSTCLR_REG                     TZOSTCLR;                     // Trip Zone OST Clear Register
    uint32_t                                 rsvd29;                       // Reserved
    union   TZFRC_REG                        TZFRC;                        // Trip Zone Force Register
    uint32_t                                 rsvd30[8];                    // Reserved
    union   ETSEL_REG                        ETSEL;                        // Event Trigger Selection Register
    uint32_t                                 rsvd31;                       // Reserved
    union   ETPS_REG                         ETPS;                         // Event Trigger Pre-Scale Register
    uint32_t                                 rsvd32;                       // Reserved
    union   ETFLG_REG                        ETFLG;                        // Event Trigger Flag Register
    uint32_t                                 rsvd33;                       // Reserved
    union   ETCLR_REG                        ETCLR;                        // Event Trigger Clear Register
    uint32_t                                 rsvd34;                       // Reserved
    union   ETFRC_REG                        ETFRC;                        // Event Trigger Force Register
    uint32_t                                 rsvd35;                       // Reserved
    union   ETINTPS_REG                      ETINTPS;                      // Event-Trigger Interrupt Pre-Scale Register
    uint32_t                                 rsvd36;                       // Reserved
    union   ETSOCPS_REG                      ETSOCPS;                      // Event-Trigger SOC Pre-Scale Register
    uint32_t                                 rsvd37;                       // Reserved
    union   ETCNTINITCTL_REG                 ETCNTINITCTL;                 // Event-Trigger Counter Initialization Control Register
    uint32_t                                 rsvd38;                       // Reserved
    union   ETCNTINIT_REG                    ETCNTINIT;                    // Event-Trigger Counter Initialization Register
    uint32_t                                 rsvd39[11];                   // Reserved
    union   DCTRIPSEL_REG                    DCTRIPSEL;                    // Digital Compare Trip Select Register
    uint32_t                                 rsvd40[2];                    // Reserved
    union   DCACTL_REG                       DCACTL;                       // Digital Compare A Control Register
    union   DCBCTL_REG                       DCBCTL;                       // Digital Compare B Control Register
    uint32_t                                 rsvd41[2];                    // Reserved
    union   DCFCTL_REG                       DCFCTL;                       // Digital Compare Filter Control Register
    union   DCCAPCTL_REG                     DCCAPCTL;                     // Digital Compare Capture Control Register
    uint32_t                                 DCFOFFSET;                    // Digital Compare Filter Offset Register
    uint32_t                                 DCFOFFSETCNT;                 // Digital Compare Filter Offset Counter Register
    uint32_t                                 DCFWINDOW;                    // Digital Compare Filter Window Register
    uint32_t                                 DCFWINDOWCNT;                 // Digital Compare Filter Window Counter Register
    union   BLANKPULSEMIXSEL_REG             BLANKPULSEMIXSEL;             // Blanking window trigger pulse select register
    uint32_t                                 rsvd42;                       // Reserved
    uint32_t                                 DCCAP;                        // Digital Compare Counter Capture Register
    uint32_t                                 rsvd43[2];                    // Reserved
    union   DCAHTRIPSEL_REG                  DCAHTRIPSEL;                  // Digital Compare AH Trip Select
    union   DCALTRIPSEL_REG                  DCALTRIPSEL;                  // Digital Compare AL Trip Select
    union   DCBHTRIPSEL_REG                  DCBHTRIPSEL;                  // Digital Compare BH Trip Select
    union   DCBLTRIPSEL_REG                  DCBLTRIPSEL;                  // Digital Compare BL Trip Select
    uint32_t                                 rsvd44[36];                   // Reserved
    union   EPWMLOCK_REG                     EPWMLOCK;                     // EPWM Lock Register
    uint32_t                                 rsvd45[2];                    // Reserved
    uint32_t                                 HWVDELVAL;                    // Hardware Valley Mode Delay Register
    uint32_t                                 VCNTVAL;                      // Hardware Valley Counter Register
    union   EPWMOE_REG                       EPWMOE;                       // EPWM output enable
};

//---------------------------------------------------------------------------
// EPWM External References & Function Declarations:
//
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;
extern volatile struct EPWM_REGS EPwm7Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
