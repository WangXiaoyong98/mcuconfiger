/*
  ******************************************************************************
  * @file           : hw_wwdt.c
  * @brief          : hw_wwdt program body
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

#ifndef HW_WWDT_H
#define HW_WWDT_H

//*************************************************************************************************
//
// The following are defines for the wwdt register offsets
//
//*************************************************************************************************


#define WWDT_STCTRLH      0x00U  // Watchdog Status and Control Register High
#define WWDT_STCTRLL      0x02U  // Watchdog Status and Control Register Low
#define WWDT_TOVALH       0x04U  // Watchdog Time-out Value Register High
#define WWDT_TOVALL       0x06U  // Watchdog Time-out Value Register Low
#define WWDT_WINH         0x08U  // Watchdog Window Register High
#define WWDT_WINL         0x0AU  // Watchdog Window Register Low
#define WWDT_REFRESH      0x0CU  // Watchdog Refresh Register
#define WWDT_UNLOCK       0x0EU  // Watchdog Unlock Register
#define WWDT_TMROUTH      0x10U  // Watchdog Timer Output Register High
#define WWDT_TMROUTL      0x12U  // Watchdog Timer Output Register Low
#define WWDT_RSTCNT       0x14U  // Watchdog Reset Count Register
#define WWDT_PRESC        0x16U  // Watchdog Prescaler Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_STCTRLH register
//
//*************************************************************************************************

#define WWDT_STCTRLH_WWDTEN         0x01U //Enable or disable the WWDT operation
#define WWDT_STCTRLH_CLKSRC         0x02U //Select a clock source for WWDT timers and other internal timing operations.
#define WWDT_STCTRLH_IRQRSTEN       0x04U // Interrupt enable
#define WWDT_STCTRLH_WINEN          0x08U //Enable window mode.
#define WWDT_STCTRLH_ALLOWUPDATE    0x10U //Enables updates to watchdog write-once registers, after the reset-triggered initial configuration window(WCT) closes, through unlock sequence.
#define WWDT_STCTRLH_DBGEN          0x20U //Enables or disables WDOG in Debug mode.
#define WWDT_STCTRLH_STOPEN         0x40U //Enables or disables WDOG in Stop mode.
#define WWDT_STCTRLH_WAITEN         0x80U //Enables or disables WDOG in Wait mode.
#define WWDT_STCTRLH_TESTWWDT       0x400U //Puts the watchdog in the functional test mode.
#define WWDT_STCTRLH_TESTSEL        0x800U //Effective only if TESTWDOG is set.
#define WWDT_STCTRLH_BYTESEL_S      12 //This 2-bit field selects the byte to be tested when the watchdog is in the byte test mode.
#define WWDT_STCTRLH_BYTESEL_M      0x3000U //This 2-bit field selects the byte to be tested when the watchdog is in the byte test mode.
#define WWDT_STCTRLH_DISTEST_WWDT   0x4000U //Allows the WDOG’s functional test mode to be disabled permanently.


//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_STCTRLL register
//
//*************************************************************************************************

#define WWDT_STCTRLL_INTFLG     0x80U //Interrupt flag


//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_TOVALH register
//
//*************************************************************************************************

#define WWDT_TOVALH_TOVALHIGH     0xFFU //Defines the upper 16 bits of the 32-bit time-out value for the watchdog timer.

//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_TOVALL register
//
//*************************************************************************************************

#define WWDT_TOVALL_TOVALLOW     0xFFU //Defines the lower 16 bits of the 32-bit time-out value for the watchdog timer.


//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_WINH register
//
//*************************************************************************************************

#define WWDT_WINH_WINHIGH     0xFFU //Defines the upper 16 bits of the 32-bit window for the windowed mode of operation of the watchdog.

//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_WINL register
//
//*************************************************************************************************

#define WWDT_WINL_WINHIGH     0xFFU //Defines the lower 16 bits of the 32-bit window for the windowed mode of operation of the watchdog.


//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_REFRESH register
//
//*************************************************************************************************

#define WWDT_REFRESH_WDOGREFRESH     0xFFU //Watchdog refresh register



//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_UNLOCK register
//
//*************************************************************************************************

#define WWDT_UNLOCK_WDOGUNLOCK     0xFFU //Writing the unlock sequence values to this register to makes the watchdog write-once registers writable again.


//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_TMROUTH register
//
//*************************************************************************************************

#define WWDT_TMROUTH_TIMEROUTHIGH     0xFFU //Shows the value of the upper 16 bits of the watchdog timer.

//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_TMROUTL register
//
//*************************************************************************************************

#define WWDT_TMROUTL_TIMEROUTLOW     0xFFU //Shows the value of the lower 16 bits of the watchdog timer.



//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_RSTCNT register
//
//*************************************************************************************************

#define WWDT_RSTCNT_RSTCNT     0xFFU //Counts the number of times the watchdog resets the system.


//*************************************************************************************************
//
// The following are defines for the bit fields in the WWDT_PRESC register
//
//*************************************************************************************************

#define WWDT_PRESC_PRESCVAL_S     8U 
#define WWDT_PRESC_PRESCVAL_M     0x700U //3-bit prescaler for the watchdog clock source.



#endif
