/*
  ******************************************************************************
  * @file           : gpio.c
  * @brief          : GPIO control program body
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
#include "gpio.h"

//*****************************************************************************
//
// GPIO_setDirectionMode
//
//*****************************************************************************
void
GPIO_setDirectionMode(uint32_t pin, GPIO_Direction pinIO)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)(GPIOA_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP));
    pinMask = (uint32_t)1U << (pin % 32U);


    //
    // Set the data direction
    //
    if(pinIO == GPIO_DIR_MODE_OUT)
    {
        //
        // Output
        //
        gpioBaseAddr[GPIO_GPxPDDR_INDEX] |= pinMask;
    }
    else
    {
        //
        // Input
        //
        gpioBaseAddr[GPIO_GPxPDDR_INDEX] &= ~pinMask;
    }
}
//*****************************************************************************
//
// GPIO_getDirectionMode
//
//*****************************************************************************
GPIO_Direction
GPIO_getDirectionMode(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)(GPIOA_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP));

    return((GPIO_Direction)((gpioBaseAddr[GPIO_GPxPDDR_INDEX] >>
                             (pin % 32U)) & 1U));

}

//*****************************************************************************
//
// GPIO_setInterruptPin
//
//*****************************************************************************
void
GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum extIntNum) // incomplete
{
    XBAR_InputNum input;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    //
    // Pick the X-BAR input that corresponds to the requested XINT.
    //
    switch(extIntNum)
    {
        case GPIO_INT_XINT1:
            input = XBAR_INPUT4;
            break;

        case GPIO_INT_XINT2:
            input = XBAR_INPUT5;
            break;

        case GPIO_INT_XINT3:
            input = XBAR_INPUT6;
            break;

        case GPIO_INT_XINT4:
            input = XBAR_INPUT13;
            break;

        case GPIO_INT_XINT5:
            input = XBAR_INPUT14;
            break;

        default:
            //
            // Invalid interrupt. Shouldn't happen if enum value is used.
            // XBAR_INPUT1 isn't tied to an XINT, so we'll use it to check for
            // a bad value.
            //
            input = XBAR_INPUT1;
            break;
    }

    if(input != XBAR_INPUT1)
    {
        XBAR_setInputPin(XBAR_BASE, input, (uint16_t)pin);
    }
}
//*****************************************************************************
//
// GPIO_setPadConfig
//
//*****************************************************************************
void
GPIO_setPadConfig(uint32_t pin, uint32_t pinType)
{
    volatile uint32_t *portBaseAddr;
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));
		
  	portBaseAddr = (pin / 32U)?(uint32_t *)PORTB_BASE : (uint32_t *)PORTA_BASE;
                     

    //
    // Enable open drain if necessary
    //
		 
    if((GPIO_PIN_TYPE_OD & pinType) == GPIO_PIN_TYPE_OD)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_ODE_MASK;
    }

    //
    // Enable pull-up if necessary
    //
    if((GPIO_PIN_TYPE_PULLUP & pinType) == GPIO_PIN_TYPE_PULLUP)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_PU_MASK;			  
    }

    //
    //Enable pull-down if necessary
    //
    if((GPIO_PIN_TYPE_PULLDOWN & pinType) == GPIO_PIN_TYPE_PULLDOWN)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_PD_MASK;
			  
    }	
    //
    //Selection of drive intensity
    //
    if((GPIO_PIN_TYPE_DRE & pinType) == GPIO_PIN_TYPE_DRE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_DRE_MASK;
			  
    }		
    //
    //Enable conversion rate
    //
    if((GPIO_PIN_TYPE_SRE & pinType) == GPIO_PIN_TYPE_SRE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_SRE_MASK;
    }		
   
    //
    //Enable the input Schmidt trigger
    //
    if((GPIO_PIN_TYPE_CSE & pinType) == GPIO_PIN_TYPE_CSE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_CSE_MASK;
			  
    }		
    //
    //Enable input 
    //
    if((GPIO_PIN_TYPE_IE & pinType) == GPIO_PIN_TYPE_IE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_IE_MASK;
			  
    }		
    //
    //Enable open source output
    //
    if((GPIO_PIN_TYPE_OSE & pinType) == GPIO_PIN_TYPE_OSE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_OSE_MASK;
			  
    }	
  
}

//*****************************************************************************
//
// GPIO_clear PadConfig
//
//*****************************************************************************
void
GPIO_clearPadConfig(uint32_t pin, uint32_t pinType)
{
    volatile uint32_t *portBaseAddr;
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));
		
  	portBaseAddr = (pin / 32U)?(uint32_t *)PORTB_BASE : (uint32_t *)PORTA_BASE;
                     

    //
    // Enable open drain if necessary
    //
		 
    if((GPIO_PIN_TYPE_OD & pinType) == GPIO_PIN_TYPE_OD)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_ODE_MASK;
    }

    //
    // Enable pull-up if necessary
    //
    if((GPIO_PIN_TYPE_PULLUP & pinType) == GPIO_PIN_TYPE_PULLUP)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_PU_MASK;			  
    }

    //
    //Enable pull-down if necessary
    //
    if((GPIO_PIN_TYPE_PULLDOWN & pinType) == GPIO_PIN_TYPE_PULLDOWN)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_PD_MASK;
			  
    }   
    //
    //Selection of drive intensity
    //
    if((GPIO_PIN_TYPE_DRE & pinType) == GPIO_PIN_TYPE_DRE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_DRE_MASK;
			  
    }		
    //
    //Enable conversion rate
    //
    if((GPIO_PIN_TYPE_SRE & pinType) == GPIO_PIN_TYPE_SRE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_SRE_MASK;
			  
    }		
   
    //
    //Enable the input Schmidt trigger
    //
    if((GPIO_PIN_TYPE_CSE & pinType) == GPIO_PIN_TYPE_CSE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_CSE_MASK;
			  
    }		
    //
    //Enable input 
    //
    if((GPIO_PIN_TYPE_IE & pinType) == GPIO_PIN_TYPE_IE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_IE_MASK;
			  
    }		
    //
    //Enable open source output
    //
    if((GPIO_PIN_TYPE_OSE & pinType) == GPIO_PIN_TYPE_OSE)
    {
        portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_OSE_MASK;
			  
    }  
}

//*****************************************************************************
//
// GPIO_getPadConfig
//
//*****************************************************************************
uint32_t
GPIO_getPadConfig(uint32_t pin)
{
    volatile uint32_t *portBaseAddr;
    uint32_t pinMask;
    uint32_t pinTypeRes;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

  	portBaseAddr = (pin / 32U)?(uint32_t *)PORTB_BASE : (uint32_t *)PORTA_BASE;
	
   // pinMask = (uint32_t)1U << (pin % 32U);

    pinTypeRes = GPIO_PIN_TYPE_PULLDOWN;

    //
    // Get open drain value
    //
    if((portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] & PORT_PCR_ODE_MASK) != 0U)
    {
        pinTypeRes |= GPIO_PIN_TYPE_OD;	     
    }
    //
    // Get pull-up value
    //
    if((portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] & PORT_PCR_PU_MASK) != 0U)
    { 
         pinTypeRes |= GPIO_PIN_TYPE_PULLUP;
    }
    //
    // Get pull-down value
    //
    if((portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] & PORT_PCR_PD_MASK) == 0U)
    { 
         pinTypeRes |= GPIO_PIN_TYPE_PULLDOWN;
    }
    //
    // Get drive intensity of pin
    //
    if((portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] & PORT_PCR_DRE_MASK) == 0U)
    { 
         pinTypeRes |= GPIO_PIN_TYPE_DRE;
    }		
    //
    // Enable conversion rate
    //
    if((portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] & PORT_PCR_SRE_MASK) == 0U)
    { 
         pinTypeRes |= GPIO_PIN_TYPE_SRE;
    }
    //
    // Enable the input Schmidt trigger
    //
    if((portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] & PORT_PCR_CSE_MASK) == 0U)
    { 
         pinTypeRes |= GPIO_PIN_TYPE_CSE;
    }   
    //
    // Enable input
    //
    if((portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] & PORT_PCR_IE_MASK) == 0U)
    { 
         pinTypeRes |= GPIO_PIN_TYPE_IE;
    } 
    //
    // Enable open source output
    //
    if((portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] & PORT_PCR_OSE_MASK) == 0U)
    { 
         pinTypeRes |= GPIO_PIN_TYPE_OSE;
    }
    
    
	return(pinTypeRes);
}

//*****************************************************************************
//
// GPIO_setQualificationMode
//
//*****************************************************************************
void
GPIO_setQualificationMode(uint32_t pin, GPIO_QualificationMode qualification)
{
    volatile uint32_t *portBaseAddr;
    uint32_t qSelIndex;
    uint32_t shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));
    
    portBaseAddr = (pin / 32U)?(uint32_t *)PORTB_BASE : (uint32_t *)PORTA_BASE;	
	//
    // Select BUS CLOCK as the clock source for the digital filter
	//
    portBaseAddr[GPIO_O_PORTxDFCR_INDEX]  = PORT_DFCR_CS_SET(0);
		
    //
    // Write the input qualification mode to the register.
    //		
    if(qualification == GPIO_QUAL_SYNC)
    {
		portBaseAddr[GPIO_O_PORTxDFWR_INDEX] =   PORT_DFWR_FILT_SET(0) ;
    }
    else if(qualification == GPIO_QUAL_3SAMPLE)
    {
 		portBaseAddr[GPIO_O_PORTxDFWR_INDEX] =   PORT_DFWR_FILT_SET(3) ;
    }
    else if(qualification == GPIO_QUAL_6SAMPLE)
    {
		portBaseAddr[GPIO_O_PORTxDFWR_INDEX] =   PORT_DFWR_FILT_SET(6) ;
    }
    else if(qualification == GPIO_QUAL_ASYNC)
    {
		portBaseAddr[GPIO_O_PORTxDFWR_INDEX] =   PORT_DFWR_FILT_SET(2) ;
    }
    portBaseAddr[GPIO_O_PORTxDFER_INDEX] |= 1 << pin;	
}

//*****************************************************************************
//
// GPIO_getQualificationMode
//
//*****************************************************************************
GPIO_QualificationMode
GPIO_getQualificationMode(uint32_t pin)
{
    volatile uint32_t *portBaseAddr;
    uint32_t qualRes;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

  	portBaseAddr = (pin / 32U)?(uint32_t *)PORTB_BASE : (uint32_t *)PORTA_BASE;		
	
	
    //
    // Read the qualification mode register and shift and mask to get the
    // value for the specified pin.
    //
	if((portBaseAddr[GPIO_O_PORTxDFWR_INDEX] & PORT_DFWR_FILT_MASK) ==  PORT_DFWR_FILT_SET(0))
	{
        qualRes = GPIO_QUAL_SYNC;
	}
    else if((portBaseAddr[GPIO_O_PORTxDFWR_INDEX] & PORT_DFWR_FILT_MASK) ==  PORT_DFWR_FILT_SET(3))
    {
        qualRes = GPIO_QUAL_3SAMPLE;
    }
    else if((portBaseAddr[GPIO_O_PORTxDFWR_INDEX] & PORT_DFWR_FILT_MASK) ==  PORT_DFWR_FILT_SET(6))
    {
        qualRes = GPIO_QUAL_6SAMPLE;
    }
    else if((portBaseAddr[GPIO_O_PORTxDFWR_INDEX] & PORT_DFWR_FILT_MASK) ==  PORT_DFWR_FILT_SET(2))
    {
        qualRes = GPIO_QUAL_ASYNC;
    }
		
    return((GPIO_QualificationMode)qualRes);
}


//*****************************************************************************
//
// GPIO_configureDigitalFilters
//
//*****************************************************************************
void
GPIO_configureDigitalFilters(uint32_t pin, GPIO_DigitalFilter Filter)
{
    volatile uint32_t *portBaseAddr;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));
    
  	portBaseAddr = (pin / 32U)?(uint32_t *)PORTB_BASE : (uint32_t *)PORTA_BASE;	
	  //
    // Select BUS CLOCK ,Set filter length,Enable filtering.
	  //
    portBaseAddr[GPIO_O_PORTxDFCR_INDEX]  = Filter.CLOCK;
  	portBaseAddr[GPIO_O_PORTxDFWR_INDEX]  =   Filter.filterL ;
    portBaseAddr[GPIO_O_PORTxDFER_INDEX] |= 1 << pin;		  
}


//*****************************************************************************
//
// GPIO_configureDigitalFilters
//
//*****************************************************************************
GPIO_DigitalFilter
GPIO_getDigitalFilterConfiguration(uint32_t pin)
{
    volatile uint32_t *portBaseAddr;
	  GPIO_DigitalFilter Filter;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));
    
  	portBaseAddr = (pin / 32U)?(uint32_t *)PORTB_BASE : (uint32_t *)PORTA_BASE;	
	  //
    // get BUS CLOCK ,get filter length
	  //
    Filter.CLOCK = portBaseAddr[GPIO_O_PORTxDFCR_INDEX];
    Filter.filterL = portBaseAddr[GPIO_O_PORTxDFWR_INDEX];
		
    return Filter;
}

//*****************************************************************************
//
// GPIO_setPinConfig
//
//*****************************************************************************
void
GPIO_setPinConfig(uint32_t pinConfig)
{
    volatile uint32_t *portBaseAddr;
    uint8_t pin,mux;

    pin = pinConfig>>24;
    mux = (pinConfig>>16)&0xff;
	  

    portBaseAddr = (pin / 32U)?(uint32_t *)PORTB_BASE : (uint32_t *)PORTA_BASE;
                   
    //
    // Clear fields in MUX register first to avoid glitches
    //
    portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] &= ~PORT_PCR_MUX_MASK;
    //
    // Write value into MUX register
    // 
    portBaseAddr[GPIO_PORTxPCRx_INDEX(pin)] |= PORT_PCR_MUX_SET(mux);
}
