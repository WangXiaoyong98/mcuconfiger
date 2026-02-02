/*
  ******************************************************************************
  * @file           : hw_ptim.h
  * @brief          : hw_ptim program body
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

#ifndef HW_PTIM_H
#define HW_PTIM_H

//*************************************************************************************************
//
// The following are defines for the PTIM register offsets
//
//*************************************************************************************************

#define PTIM_MCR          0x00U  // PTIM Module Control Register

#define PTIM_LTMR64H      0xE0U  // PTIM Upper Lifetime Timer Register
#define PTIM_LTMR64L      0xE4U  // PTIM Lower Lifetime Timer Register

#define PTIM_LDVAL0       0x100U // Timer Load Value Register (Channel 0)
#define PTIM_CVAL0        0x104U // Current Timer Value Register (Channel 0)
#define PTIM_TCTRL0       0x108U // Timer Control Register (Channel 0)
#define PTIM_TFLG0        0x10CU // Timer Flag Register (Channel 0)

#define PTIM_LDVAL1       0x110U // Timer Load Value Register (Channel 1)
#define PTIM_CVAL1        0x114U // Current Timer Value Register (Channel 1)
#define PTIM_TCTRL1       0x118U // Timer Control Register (Channel 1)
#define PTIM_TFLG1        0x11CU // Timer Flag Register (Channel 1)

#define PTIM_LDVAL2       0x120U // Timer Load Value Register (Channel 2)
#define PTIM_CVAL2        0x124U // Current Timer Value Register (Channel 2)
#define PTIM_TCTRL2       0x128U // Timer Control Register (Channel 2)
#define PTIM_TFLG2        0x12CU // Timer Flag Register (Channel 2)

#define PTIM_LDVAL3       0x130U // Timer Load Value Register (Channel 3)
#define PTIM_CVAL3        0x134U // Current Timer Value Register (Channel 3)
#define PTIM_TCTRL3       0x138U // Timer Control Register (Channel 3)
#define PTIM_TFLG3        0x13CU // Timer Flag Register (Channel 3)


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_MCR register
//
//*************************************************************************************************
#define PTIM_MCR_FRZ    0x01U  //Freeze
#define PTIM_MCR_MDIS   0x02U // The module is disabled


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_LTMR64H register
//
//*************************************************************************************************
#define PTIM_LTMR64H_LTH   0xFFFFFFFFU // Timer value



//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_LTMR64L register
//
//*************************************************************************************************
#define PTIM_LTMR64L_LTL   0xFFFFFFFFU // Timer value


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_LDVAL0 register
//
//*************************************************************************************************
#define PTIM_LDVAL0_TSV   0xFFFFFFFFU // Timer start value

//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_CVAL0 register
//
//*************************************************************************************************
#define PTIM_CVAL0_TVL   0xFFFFFFFFU // Current timer value.


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_TCTRL0 register
//
//*************************************************************************************************
#define PTIM_TCTRL0_TEN   0x01U // Timer enable.
#define PTIM_TCTRL0_TIE   0x02U //  The Timer interruption was enabled
#define PTIM_TCTRL0_CHN   0x04U //  Chain Mode


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_TFLG0 register
//
//*************************************************************************************************
#define PTIM_TFLG0_TIF   0x01U // Timer interrupt flag


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_LDVAL1 register
//
//*************************************************************************************************
#define PTIM_LDVAL1_TSV   0xFFFFFFFFU // Timer start value

//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_CVAL1 register
//
//*************************************************************************************************
#define PTIM_CVAL1_TVL   0xFFFFFFFFU // Current timer value.


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_TCTRL1 register
//
//*************************************************************************************************
#define PTIM_TCTRL1_TEN   0x01U // Timer enable.
#define PTIM_TCTRL1_TIE   0x02U //  The Timer interruption was enabled
#define PTIM_TCTRL1_CHN   0x04U //  Chain Mode


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_TFLG1 register
//
//*************************************************************************************************
#define PTIM_TFLG1_TIF   0x01U // Timer interrupt flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_LDVAL2 register
//
//*************************************************************************************************
#define PTIM_LDVAL2_TSV   0xFFFFFFFFU // Timer start value

//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_CVAL2 register
//
//*************************************************************************************************
#define PTIM_CVAL2_TVL   0xFFFFFFFFU // Current timer value.


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_TCTRL2 register
//
//*************************************************************************************************
#define PTIM_TCTRL2_TEN   0x01U // Timer enable.
#define PTIM_TCTRL2_TIE   0x02U //  The Timer interruption was enabled
#define PTIM_TCTRL2_CHN   0x04U //  Chain Mode


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_TFLG2 register
//
//*************************************************************************************************
#define PTIM_TFLG2_TIF   0x01U // Timer interrupt flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_LDVAL3 register
//
//*************************************************************************************************
#define PTIM_LDVAL3_TSV   0xFFFFFFFFU // Timer start value

//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_CVAL3 register
//
//*************************************************************************************************
#define PTIM_CVAL3_TVL   0xFFFFFFFFU // Current timer value.


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_TCTRL3 register
//
//*************************************************************************************************
#define PTIM_TCTRL3_TEN   0x01U // Timer enable.
#define PTIM_TCTRL3_TIE   0x02U //  The Timer interruption was enabled
#define PTIM_TCTRL3_CHN   0x04U //  Chain Mode


//*************************************************************************************************
//
// The following are defines for the bit fields in the PTIM_TFLG4 register
//
//*************************************************************************************************
#define PTIM_TFLG4_TIF   0x01U // Timer interrupt flag


#endif
