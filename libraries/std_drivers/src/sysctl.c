/*
  ******************************************************************************
  * @file           : sysctrl.c
  * @brief          : System control driver
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
#include <math.h>
#include "sysctl.h"

//
// Define to isolate inline assembly
//
void SysCtl_delay(unsigned int step) __attribute__((optnone))
{
    while(step--);
}



//*****************************************************************************
//
// SysCtl_pollX1Counter()
//
//*****************************************************************************
#if 0
static bool
SysCtl_pollX1Counter(void)
{
    uint16_t loopCount = 0U;
    uint32_t localCounter = 0U;
    bool status = false;

    //
    // Delay for 1 ms while the XTAL powers up
    //
    // 2000 loops, 7 cycles per loop + 9 cycles overhead = 14009 cycles
    //
    SysCtl_delay(2000);

    //
    // Clear and saturate X1CNT 4 times to guarantee operation
    //
    do
    {
        //
        // Keep clearing the counter until it is no longer saturated
        //
        while(HWREG(CLKCFG_BASE + SYSCTL_O_X1CNT) > 0x1FFU)
        {
            HWREG(CLKCFG_BASE + SYSCTL_O_X1CNT) |= SYSCTL_X1CNT_CLR;
        }

        //
        // Wait for the X1 clock to saturate
        //
        while(HWREGH(CLKCFG_BASE + SYSCTL_O_X1CNT) != SYSCTL_X1CNT_X1CNT_M)
        {
            //
            // If your application is stuck in this loop, please check if the
            // input clock source is valid.
            //
            localCounter++;
            if(localCounter>2500000U)
            {
                if(loopCount == 3U)
                {
                    status = false;
                }
                break;
            }
        }

        if(loopCount == 3U &&
           (HWREGH(CLKCFG_BASE + SYSCTL_O_X1CNT) == SYSCTL_X1CNT_X1CNT_M))
        {
            status = true;
        }
        //
        // Increment the counter
        //
        loopCount++;
        localCounter = 0U;
    }while(loopCount < 4U);

    return status;
}
#endif
//*****************************************************************************
//
// SysCtl_getClock()
//
//*****************************************************************************
uint32_t
SysCtl_getClock(uint32_t clockInHz)
{
    uint32_t temp;
    uint32_t oscSource;
    uint32_t clockOut;

    if(SYSCTRL->CLKSW&SYSCTRL_CLKSW_SCGCLKSEL_MASK)
    {
        clockOut = 30000;
    }
    else
    {
        temp = clockInHz/((SYSCTRL->PREPLLDIV&0x3f)+1);
        if(SYSCTRL->CLKSW & SYSCTRL_CLKSW_PLLCLKSEL_MASK)
        {
            clockOut = temp * (SYSCTRL->PLLCFG & SYSCTRL_PLLCFG_IMULT_MASK)   \
                       / ((SYSCTRL->PLLCFG & SYSCTRL_PLLCFG_REFDIV_MASK)>>SYSCTRL_PLLCFG_REFDIV_SHIFT)   \
                       / pow((((SYSCTRL->PLLCFG & SYSCTRL_PLLCFG_ODIV_MASK)>>SYSCTRL_PLLCFG_ODIV_SHIFT)+1),2);
        }
        else
            clockOut = temp;
    }
    return(clockOut);
}

//*****************************************************************************
//
// SysCtl_setClock()
//
//*****************************************************************************
bool
SysCtl_setClock(uint32_t config)
{
    uint16_t divSel, pllen, pllLockStatus, xtalval;
    uint32_t oscSource, oscclksrcsel, imult, odiv, refdiv, plldiv, busdiv, ftfdiv;
    uint32_t timeout, freq, temp_syspllmult;
    bool status = false;

    //
    // Check the arguments.
    //
    ASSERT((config & SYSCTL_OSCSRC_M) <= SYSCTL_OSCSRC_M);
    ASSERT(((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_ENABLE) ||
           ((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_BYPASS) ||
           ((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_DISABLE));


    //
    // Bypass PLL
    //
    SYSCTRL->PLLCFG |= SYSCTRL_PLLCFG_PLLLOCKBYPASS_MASK;
    
    if((config & SYSCTL_PLL_ENABLE) == 0)
        return true;
    
    //
    // Delay of at least 120 OSCCLK cycles required post PLL bypass
    //
    SysCtl_delay(23U);

    //
    // Derive the current and previous oscillator clock source values
    //

    if((config & SYSCTL_OSCSRC_M) == SYSCTL_OSCSRC_OSC1)
        oscSource = 8000000;
    else
        oscSource = CPU_XTAL_CLK_HZ;

    imult = config & SYSCTL_IMULT_M;
    odiv = (config & SYSCTL_ODIV_M)>>SYSCTL_ODIV_S;
    refdiv = (config & SYSCTL_REFDIV_M)>>SYSCTL_REFDIV_S;
    plldiv = (config & SYSCTL_SYSDIV_M)>>SYSCTL_SYSDIV_S;   //connect to core and system
    oscclksrcsel = (config & SYSCTL_OSCSRC_M);
        
    if((imult < 2) || (refdiv == 0) || (refdiv > 63))   //imult can't less than 2 and refdiv can't be zero
        return FALSE;
		
        
	freq = oscSource*imult/(refdiv*(1<<odiv)*(plldiv+1));
    //MPW only
    if(freq>140000000)
        return FALSE;
    if(freq*plldiv>140000000*2)
        return FALSE;
        
    //MPW, clock divider can't reduce the frequency division ratio
    if(plldiv < ((SYSCTRL->CLKDIV & SYSCTRL_CLKDIV_SYSDIV_MASK) >> SYSCTRL_CLKDIV_SYSDIV_SHIFT))
        ASSERT(1);
        
       
    //
    // First modify the PLL multipliers if the multipliers need an update or PLL needs
    // to be powered on / enabled
    //
    if((imult != ((SYSCTRL->PLLCFG & SYSCTRL_PLLCFG_IMULT_MASK)>>SYSCTRL_PLLCFG_IMULT_SHIFT)) ||
       (refdiv != ((SYSCTRL->PLLCFG & SYSCTRL_PLLCFG_REFDIV_MASK)>>SYSCTRL_PLLCFG_REFDIV_SHIFT))||
       (odiv != ((SYSCTRL->PLLCFG & SYSCTRL_PLLCFG_ODIV_MASK)>>SYSCTRL_PLLCFG_ODIV_SHIFT)) ||
       (1U != (SYSCTRL->CLKSW & SYSCTRL_CLKSW_PLLCLKSEL_MASK)))
    {
        // Unlock clock register
        SYSCTRL->UNLOCK = 0x5a5a;   
        //
        // Bypass PLL and set dividers to /1
        //
        SYSCTRL->CLKSW &= ~SYSCTRL_CLKSW_PLLCLKSEL_MASK;

        //
        // Delay of at least 120 OSCCLK cycles required post PLL bypass
        //
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        
        //MPW CLKDIV default SYSCLK divide 2, BUSCLK divide 2, FTFCLK divide 3.
        //BUS clock should less than 80MHz
        //freq*2 is pll output clock
        if((((freq*2)/(((SYSCTRL->CLKDIV & SYSCTRL_CLKDIV_SYSDIV_MASK) >> SYSCTRL_CLKDIV_SYSDIV_SHIFT)+1))>66000000)   \
            || (plldiv!=((SYSCTRL->CLKDIV & SYSCTRL_CLKDIV_SYSDIV_MASK) >> SYSCTRL_CLKDIV_SYSDIV_SHIFT)))
        {
            busdiv = (plldiv+1)*2-1;
            ftfdiv = (plldiv+1)*2-1;
            temp_syspllmult = SYSCTRL_CLKDIV_SYSDIV_SET(plldiv)     \
                              + SYSCTRL_CLKDIV_BUSDIV_SET(busdiv)   \
                              + SYSCTRL_CLKDIV_FTFDIV_SET(ftfdiv)   \
                              + SYSCTRL_CLKDIV_FTFDIV2_SET(ftfdiv);

            SYSCTRL->CLKDIV = temp_syspllmult;
        }
        
        
        //
        // Evaluate PLL multipliers and dividers
        //
        temp_syspllmult = ((refdiv << SYSCTRL_PLLCFG_REFDIV_SHIFT) | (odiv << SYSCTRL_PLLCFG_ODIV_SHIFT)| (imult << SYSCTRL_PLLCFG_IMULT_SHIFT));

        //
        // Turnoff the PLL
        //
        
        //EDIS;

        //
        // Delay of at least 66 OSCCLK cycles
        //
        
        if((oscclksrcsel == SYSCTL_OSCSRC_XTAL) || (oscclksrcsel == SYSCTL_OSCSRC_XTAL_SE))
        {
                SYSCTRL->CLKSW |= SYSCTRL_CLKSW_CLKSRCSEL_MASK;
        }
        else if(oscclksrcsel == SYSCTL_OSCSRC_OSC1)
        {
                SYSCTRL->CLKSW &= ~SYSCTRL_CLKSW_CLKSRCSEL_MASK;
        }
        
        //
        // Program PLL multipliers
        //
        SYSCTRL->PLLCFG = temp_syspllmult;
        SYSCTRL->POWERCFG &= ~(SYSCTRL_POWERCFG_PLL_LDO_PD_MASK + SYSCTRL_POWERCFG_PLL_PD_MASK);
        
        //
        // Lock time is 1024 OSCCLK * (REFDIV+1)
        //
        timeout = (1024U * (refdiv + 1U));
        pllLockStatus = (SYSCTRL->PLLCFG & SYSCTRL_PLLCFG_PLLLOCK_MASK)>>SYSCTRL_PLLCFG_PLLLOCK_SHIFT;
        
        //
        // Wait for the SYSPLL lock
        //
        while((pllLockStatus != 1) && (timeout != 0U))
        {
            pllLockStatus = (SYSCTRL->PLLCFG & SYSCTRL_PLLCFG_PLLLOCK_MASK)>>SYSCTRL_PLLCFG_PLLLOCK_SHIFT;
            timeout--;
        }

        //
        // Set Flash rdcycle
        //
        FLASH->RDCYCLE = 3*(oscSource*imult/(refdiv*(1<<odiv)*(ftfdiv+1)))/100000000+1;
        
        // Enable SYSPLL
        //
        if(config & SYSCTL_PLL_ENABLE)
            SYSCTRL->CLKSW |= SYSCTRL_CLKSW_PLLCLKSEL_MASK;
        //
        // Check PLL Frequency using DCC
        //
        //status = IsPLLValid(dccbase, clock_source, INT_PLL_SYSPLL,
        //                    imult, odiv , refdiv);
				status = true;

    }
    else
    {
        //
        // Re-Lock of PLL not needed since the multipliers
        // are not updated
        //
        status = true;
    }

    return(status);
}

//*****************************************************************************
//
// SysCtl_selectXTAL()
//
//*****************************************************************************
void
SysCtl_selectXTAL(void)
{
    bool status = false;
    uint16_t loopCount = 0U;

    //
    // Turn on XTAL and select crystal mode
    //
    if(SYSCTRL->POWERCFG&SYSCTRL_POWERCFG_XOSC_PD_MASK)
        SYSCTRL->POWERCFG &= ~SYSCTRL_POWERCFG_XOSC_PD_MASK;
    //
    // Wait for the X1 clock to saturate
    //
    //status = SysCtl_pollX1Counter();

    //
    // Select XTAL as the oscillator source
    //
     SYSCTRL->CLKSW |= SYSCTRL_CLKSW_CLKSRCSEL_MASK;

//    while(status == FALSE)
//    {         
        // If code is stuck here, it means crystal has not started.  
        //Replace crystal or update code below to take necessary actions if 
        //crystal is bad         
//        ESTOP0;     
//    }
}

//*****************************************************************************
//
// SysCtl_selectXTALSingleEnded()
//
//*****************************************************************************
void
SysCtl_selectXTALSingleEnded(void)
{

}

//*****************************************************************************
//
// SysCtl_selectOscSource()
//
//*****************************************************************************
void
SysCtl_selectOscSource(uint32_t oscSource)
{
    ASSERT((oscSource == SYSCTL_OSCSRC_OSC1) ||
           (oscSource == SYSCTL_OSCSRC_XTAL) ||
           (oscSource == SYSCTL_OSCSRC_30K));

    //
    // Select the specified source.
    //
    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC1:
            //
            // Clk Src = INTOSC1
            //
            SYSCTRL->CLKSW &= ~SYSCTRL_CLKSW_CLKSRCSEL_MASK;
            break;

        case SYSCTL_OSCSRC_XTAL:
            //
            // Turn on INTOSC1
            //
            SYSCTRL->POWERCFG &= ~SYSCTRL_POWERCFG_XOSC_PD_MASK;
            SYSCTL_CLKSRCCTL_DELAY;
            //
            // Select XTAL in crystal mode and wait for it to power up
            //
            SYSCTRL->CLKSW |= SYSCTRL_CLKSW_CLKSRCSEL_MASK;
            SYSCTRL->CLKSW &= ~SYSCTRL_CLKSW_SCGCLKSEL_MASK;        
            break;
/*
        case SYSCTL_OSCSRC_XTAL_SE:
            //
            // Select XTAL in single-ended mode and wait for it to power up
            //
            SysCtl_selectXTALSingleEnded();
            break;
*/
        case SYSCTL_OSCSRC_30K:
            //
            // Clk Src = INTOSC1
            //
            if(SYSCTRL->POWERCFG & SYSCTRL_POWERCFG_IOSC32K_PD_MASK)
            {
                SYSCTRL->POWERCFG &= ~SYSCTRL_POWERCFG_IOSC32K_PD_MASK;
                SysCtl_delay(100);
            }
            SYSCTRL->CLKSW |= SYSCTRL_CLKSW_SCGCLKSEL_MASK;
            
            break;

        default:
            //
            // Do nothing. Not a valid oscSource value.
            //
            break;
    }

}

//*****************************************************************************
//
// SysCtl_getLowSpeedClock()
//
//*****************************************************************************
uint32_t
SysCtl_getLowSpeedClock(uint32_t clockInHz)
{
    uint32_t clockOut;

    //
    // Get the main system clock
    //
    clockOut = SysCtl_getClock(clockInHz);

    //
    // Apply the divider to the main clock
    //
    clockOut =clockOut / ((SYSCTRL->CLKDIV & SYSCTRL_CLKDIV_BUSDIV_MASK)>>SYSCTRL_CLKDIV_BUSDIV_SHIFT);
    return(clockOut);
}

//*****************************************************************************
//
// SysCtl_isPLLValid()
//
// not support by sp2401_v1
//*****************************************************************************
#if 0
bool
SysCtl_isPLLValid(uint32_t base, uint32_t oscSource,
                  uint32_t pllMultDiv)
{
    uint32_t imult, odiv, refdiv;
    float  fclk1_0ratio, fclk0_1ratio;
    float32_t total_error, window;

    ASSERT((base == SYSCTL_DCC_BASE_0) || (base == SYSCTL_DCC_BASE_1));

    DCC_Count0ClockSource dccClkSrc0;
    DCC_Count1ClockSource dccClkSrc1;
    uint32_t dccCounterSeed0, dccCounterSeed1, dccValidSeed0;

    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC2:
            //
            // Select DCC Clk Src0 as INTOSC2
            //
            dccClkSrc0 = DCC_COUNT0SRC_INTOSC2;
            break;
        case SYSCTL_OSCSRC_XTAL:
        case SYSCTL_OSCSRC_XTAL_SE:
            //
            // Select DCC Clk Src0 as XTAL
            //
            dccClkSrc0 = DCC_COUNT0SRC_XTAL;
            break;
        case SYSCTL_OSCSRC_OSC1:
            //
            // Select DCC Clk Src0 as INTOSC1
            //
            dccClkSrc0 = DCC_COUNT0SRC_INTOSC1;
            break;
        default:
            //
            // Select DCC Clk Src0 as INTOSC1
            //
            dccClkSrc0 = DCC_COUNT0SRC_INTOSC1;
            break;
    }

    //
    // Select DCC Clk Src1 as SYSPLL
    //
    dccClkSrc1 = DCC_COUNT1SRC_PLL;

    //
    // Assigning DCC for PLL validation
    //
    if(base == SYSCTL_DCC_BASE_0)
    {
        base = DCC0_BASE;
    }
    else
    {
        base = DCC1_BASE;
    }


    //
    // Retrieving PLL parameters
    //
    imult = pllMultDiv & SYSCTL_IMULT_M;
    odiv = (pllMultDiv & SYSCTL_ODIV_M) >> SYSCTL_ODIV_S;
    refdiv = (pllMultDiv & SYSCTL_REFDIV_M) >> SYSCTL_REFDIV_S;

    fclk1_0ratio = (float)imult / (((float)odiv + 1.0F) *
                   ((float)refdiv + 1.0F));
    fclk0_1ratio = (((float)refdiv + 1.0F) *
                   ((float)odiv + 1.0F)) / (float)imult;

    if(fclk1_0ratio >= 1.0F)
    {
        //
        // Setting Counter0 & Valid Seed Value with +/-1% tolerance
        // Total error is 12
        //
        window = (12U * 100U) / ((uint32_t)SYSCTL_DCC_COUNTER0_TOLERANCE);
        dccCounterSeed0 = (uint32_t)window - 12U;
        dccValidSeed0 = 24U;
    }
    else
    {
        total_error = ((2.0F * fclk0_1ratio) + 10.0F);
        window = (total_error * 100.0F) /
                 ((float32_t)SYSCTL_DCC_COUNTER0_TOLERANCE);

        //
        // Setting Counter0 & Valid Seed Value with +/-1% tolerance
        //
        dccCounterSeed0 = window - total_error;
        dccValidSeed0 = 2U * (uint32_t)total_error;
    }

    //
    // Multiplying Counter-0 window with PLL Integer Multiplier
    //
    dccCounterSeed1 = (window * fclk1_0ratio);

    //
    // Enable peripheral clock to DCC
    //
    if(base == DCC0_BASE)
    {
        SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC0);
    }
    else
    {
        SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC1);
    }

    //
    // Clear Error & Done Flag
    //
    DCC_clearErrorFlag(base);
    DCC_clearDoneFlag(base);

    //
    // Disable DCC
    //
    DCC_disableModule(base);

    //
    // Disable Error Signal
    //
    DCC_disableErrorSignal(base);

    //
    // Disable Done Signal
    //
    DCC_disableDoneSignal(base);

    //
    // Configure Clock Source0 to whatever set as a clock source for PLL
    //
    DCC_setCounter0ClkSource(base, dccClkSrc0);

    //
    // Configure Clock Source1 to PLL
    //
    DCC_setCounter1ClkSource(base, dccClkSrc1);

    //
    // Configure COUNTER-0, COUNTER-1 & Valid Window
    //
    DCC_setCounterSeeds(base, dccCounterSeed0, dccValidSeed0,
                        dccCounterSeed1);

    //
    // Enable Single Shot mode
    //
    DCC_enableSingleShotMode(base, DCC_MODE_COUNTER_ZERO);


    //
    // Enable DCC to start counting
    //
    DCC_enableModule(base);

    //
    // Wait until Error or Done Flag is generated
    //
    while((HWREGH(base + DCC_O_STATUS) &
           (DCC_STATUS_ERR | DCC_STATUS_DONE)) == 0U)
    {
    }

    //
    // Returns true if DCC completes without error
    //
    return((HWREGH(base + DCC_O_STATUS) &
            (DCC_STATUS_ERR | DCC_STATUS_DONE)) == DCC_STATUS_DONE);
}
#endif


