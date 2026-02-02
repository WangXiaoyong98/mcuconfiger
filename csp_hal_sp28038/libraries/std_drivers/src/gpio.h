/*
  ******************************************************************************
  * @file           : gpio.h
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

#ifndef GPIO_H
#define GPIO_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup gpio_api GPIO
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_xint.h"
#include "xbar.h"
#include "debug.h"
extern uint32_t testVal2;
//*****************************************************************************
//
// Useful defines used within the driver functions to access gpio registers.
// Not intended for use by application code.
//
// Divide by 2 is for C28x which has word access
//
//*****************************************************************************
#define GPIO_CTRL_REGS_STEP     (GPIO_O_GPBPDOR - GPIO_O_GPAPDOR)

#define GPIO_GPxPDOR_INDEX       (GPIO_O_GPAPDOR / 4U)
#define GPIO_GPxPSOR_INDEX       (GPIO_O_GPAPSOR / 4U)
#define GPIO_GPxPCOR_INDEX       (GPIO_O_GPAPCOR / 4U)
#define GPIO_GPxPTOR_INDEX       (GPIO_O_GPAPTOR / 4U)
#define GPIO_GPxPDIR_INDEX       (GPIO_O_GPAPDIR / 4U) 
#define GPIO_GPxPDDR_INDEX       (GPIO_O_GPAPDDR / 4U)

#define GPIO_PORTxPCRx_INDEX(x)            (x%32U)
#define GPIO_O_PORTxGPCLR_INDEX           (GPIO_O_PORTAGPCLR / 4U)
#define GPIO_O_PORTxGPCHR_INDEX           (GPIO_O_PORTAGPCHR / 4U)
#define GPIO_O_PORTxISFR_INDEX            (GPIO_O_PORTAISFR / 4U)
#define GPIO_O_PORTxDFER_INDEX            (GPIO_O_PORTADFER / 4U)
#define GPIO_O_PORTxDFCR_INDEX            (GPIO_O_PORTADFCR / 4U)
#define GPIO_O_PORTxDFWR_INDEX            (GPIO_O_PORTADFWR / 4U)


#ifndef DOXYGEN_PDF_IGNORE
//*****************************************************************************
//
// Values that can be passed to GPIO_setPadConfig() as the pinType parameter
// and returned by GPIO_getPadConfig().
//
//*****************************************************************************
#define GPIO_PIN_TYPE_PULLUP        0x0001U //!< Pull-up enable for input
#define GPIO_PIN_TYPE_PULLDOWN      0x0002U //!< Pull-down enable for input
#define GPIO_PIN_TYPE_SRE           0x0004U //!< Enable conversion rate
#define GPIO_PIN_TYPE_CSE           0x0008U //!< Enable the input Schmidt trigger
#define GPIO_PIN_TYPE_IE            0x0010U //!< Enable input 
#define GPIO_PIN_TYPE_OD            0x0020U //!< Open-drain on output
#define GPIO_PIN_TYPE_OSE           0x0040U //!< Enable open source output
#define GPIO_PIN_TYPE_DRE           0x0080U //!< Selection of drive intensity,0:Low driving intensity.1:High driving strength.

#endif

//*****************************************************************************
//
//! Values that can be passed to GPIO_setDirectionMode() as the \e pinIO
//! parameter and returned from GPIO_getDirectionMode().
//
//*****************************************************************************
typedef enum
{
    GPIO_DIR_MODE_IN,                   //!< Pin is a GPIO input
    GPIO_DIR_MODE_OUT                   //!< Pin is a GPIO output
} GPIO_Direction; //OK

//*****************************************************************************
//
//! Values that can be passed to GPIO_setInterruptType() as the \e intType
//! parameter and returned from GPIO_getInterruptType().
//
//*****************************************************************************

typedef enum
{
    GPIO_INT_TYPE_FALLING_EDGE = 0x00,   //!< Interrupt on falling edge
    GPIO_INT_TYPE_RISING_EDGE  = 0x04,   //!< Interrupt on rising edge
    GPIO_INT_TYPE_BOTH_EDGES   = 0x0C    //!< Interrupt on both edges
} GPIO_IntType;


//*****************************************************************************
//
//! Values that can be passed to GPIO_setQualificationMode() as the
//! \e qualification parameter and returned by GPIO_getQualificationMode().
//
//*****************************************************************************
typedef enum
{
    GPIO_QUAL_SYNC,                     //!< Synchronization to SYSCLK
    GPIO_QUAL_3SAMPLE,                  //!< Qualified with 3 samples
    GPIO_QUAL_6SAMPLE,                  //!< Qualified with 6 samples
    GPIO_QUAL_ASYNC                     //!< No synchronization
} GPIO_QualificationMode;

//*****************************************************************************
//
//! CPIO_FilterSource
//! 
//
//*****************************************************************************
typedef enum 
{
	GPIO_BUS_CLOCK,
	GPIO_LPO_CLOCK
}GPIO_FilterSource;

//*****************************************************************************
//
//! Values that can be passed toGPIO_configureDigitalFilters() as the
//! \e DigitalFilters parameter and returned by GPIO_configureDigitalFilters().
//
//*****************************************************************************
typedef struct
{
    GPIO_FilterSource CLOCK;                       //!< select clock source for filter
    uint8_t filterL;                     //!< set filter length 
} GPIO_DigitalFilter;

typedef enum
{
    GPIO_PORT_A = 0,                    //!< GPIO port A
    GPIO_PORT_B = 1,                    //!< GPIO port B
    GPIO_PORT_H = 7                     //!< GPIO port H
} GPIO_Port;

//*****************************************************************************
//
//! Values that can be passed to GPIO_setInterruptPin(),
//! GPIO_setInterruptType(), GPIO_getInterruptType(), GPIO_enableInterrupt(),
//! GPIO_disableInterrupt(), as the \e extIntNum parameter.
//
//*****************************************************************************
typedef enum
{
    GPIO_INT_XINT1,                     //!< External Interrupt 1
    GPIO_INT_XINT2,                     //!< External Interrupt 2
    GPIO_INT_XINT3,                     //!< External Interrupt 3
    GPIO_INT_XINT4,                     //!< External Interrupt 4
    GPIO_INT_XINT5                      //!< External Interrupt 5
} GPIO_ExternalIntNum;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! \internal
//! Checks that a pin number is valid for a device.
//!
//! Note that this function reflects the highest possible GPIO number of a
//! device on its biggest package. Check the datasheet to see what the actual
//! range of valid pin numbers is for a specific package.
//!
//! \return None.
//
//*****************************************************************************
#ifdef DEBUG
static inline bool
GPIO_isPinValid(uint32_t pin)
{
    return((pin <= 61U) || ((pin >= 224U) && (pin <= 253U)));
}
#endif

//*****************************************************************************
//
//! Sets the interrupt type for the specified pin.
//!
//! \param extIntNum specifies the external interrupt.
//! \param intType specifies the type of interrupt trigger mechanism.
//!
//! This function sets up the various interrupt trigger mechanisms for the
//! specified pin on the selected GPIO port.
//!
//! The following defines can be used to specify the external interrupt for the
//! \e extIntNum parameter:
//!
//! - \b GPIO_INT_XINT1
//! - \b GPIO_INT_XINT2
//! - \b GPIO_INT_XINT3
//! - \b GPIO_INT_XINT4
//! - \b GPIO_INT_XINT5
//!
//! One of the following flags can be used to define the \e intType
//! parameter:
//!
//! - \b GPIO_INT_TYPE_FALLING_EDGE sets detection to edge and trigger to
//!   falling
//! - \b GPIO_INT_TYPE_RISING_EDGE sets detection to edge and trigger to rising
//! - \b GPIO_INT_TYPE_BOTH_EDGES sets detection to both edges
//!
//! \return None.
//
//*****************************************************************************

static inline void
GPIO_setInterruptType(GPIO_ExternalIntNum extIntNum, GPIO_IntType intType)
{  
    //
    // Write the selected polarity to the appropriate register.
    //
    HWREG(XINT_BASE + (uint16_t)(extIntNum*4)) =
        (HWREG(XINT_BASE + (uint16_t)(extIntNum*4)) & ~XINT_1CR_POLARITY_M) |
        (uint16_t)intType;
}
//*****************************************************************************
//
//! Gets the interrupt type for a pin.
//!
//! \param extIntNum specifies the external interrupt.
//!
//! This function gets the interrupt type for a interrupt. The interrupt can be
//! configured as a falling-edge, rising-edge, or both-edges detected
//! interrupt.
//!
//! The following defines can be used to specify the external interrupt for the
//! \e extIntNum parameter:
//!
//! - \b GPIO_INT_XINT1
//! - \b GPIO_INT_XINT2
//! - \b GPIO_INT_XINT3
//! - \b GPIO_INT_XINT4
//! - \b GPIO_INT_XINT5
//!
//! \return Returns one of the flags described for GPIO_setInterruptType().
//
//*****************************************************************************

static inline GPIO_IntType
GPIO_getInterruptType(GPIO_ExternalIntNum extIntNum)
{
    //
    // Read the selected polarity from the appropriate register.
    //
    //
    // Read the selected polarity from the appropriate register.
    //
    return((GPIO_IntType)(HWREG(XINT_BASE + (uint16_t)(extIntNum*4)) &
                          XINT_1CR_POLARITY_M));
}

//*****************************************************************************
//
//! Enables the specified external interrupt.
//!
//! \param extIntNum specifies the external interrupt.
//!
//! This function enables the indicated external interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt.
//! Disabled sources have no effect on the processor.
//!
//! The following defines can be used to specify the external interrupt for the
//! \e extIntNum parameter:
//!
//! - \b GPIO_INT_XINT1
//! - \b GPIO_INT_XINT2
//! - \b GPIO_INT_XINT3
//! - \b GPIO_INT_XINT4
//! - \b GPIO_INT_XINT5
//!
//! \return None.
//
//*****************************************************************************

static inline void
GPIO_enableInterrupt(GPIO_ExternalIntNum extIntNum)
{
    //
    // Set the enable bit for the specified interrupt.
    //
    HWREG(XINT_BASE + (uint16_t)(extIntNum*4)) |= XINT_1CR_ENABLE;
}

//*****************************************************************************
//
//! Disables the specified external interrupt.
//!
//! \param extIntNum specifies the external interrupt.
//!
//! This function disables the indicated external interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt.
//! Disabled sources have no effect on the processor.
//!
//! The following defines can be used to specify the external interrupt for the
//! \e extIntNum parameter:
//!
//! - \b GPIO_INT_XINT1
//! - \b GPIO_INT_XINT2
//! - \b GPIO_INT_XINT3
//! - \b GPIO_INT_XINT4
//! - \b GPIO_INT_XINT5
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_disableInterrupt(GPIO_ExternalIntNum extIntNum)
{
    //
    // Clear the enable bit for the specified interrupt
    //
    HWREG(XINT_BASE + (uint16_t)(extIntNum*4)) &= ~XINT_1CR_ENABLE;
}

//*****************************************************************************
//
//! Gets the value of the external interrupt counter.
//!
//! \param extIntNum specifies the external interrupt.
//!
//! The following defines can be used to specify the external interrupt for the
//! \e extIntNum parameter:
//!
//! - \b GPIO_INT_XINT1
//! - \b GPIO_INT_XINT2
//! - \b GPIO_INT_XINT3
//!
//! \b Note: The counter is clocked at the SYSCLKOUT rate.
//!
//! \return Returns external interrupt counter value.
//
//*****************************************************************************
static inline uint16_t
GPIO_getInterruptCounter(GPIO_ExternalIntNum extIntNum)
{

    ASSERT(extIntNum <= GPIO_INT_XINT3);

    //
    // Read the counter value from the appropriate register.
    //

    return((HWREG(XINT_BASE + 0x10 + (uint16_t)(extIntNum*4))));

}

//*****************************************************************************
//
//! Reads the value present on the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! The value at the specified pin are read, as specified by \e pin. The value
//! is returned for both input and output pins.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return Returns the value in the data register for the specified pin.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPin(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    //uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));


    gpioBaseAddr = (uint32_t *)(GPIOA_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP));	
	
    return((gpioBaseAddr[GPIO_GPxPDOR_INDEX] >> (pin % 32U)) & (uint32_t)0x1U);
}

//*****************************************************************************
//
//! Reads the data register value for specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! The value available at the data register for the specified pin is read, as
//! specified by \e pin. The value is returned for both input and output pins.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \sa GPIO_readPin()
//!
//! \return Returns the value in the data register for the specified pin.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPinDataRegister(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    //uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));


    gpioBaseAddr = (uint32_t *)(GPIOA_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP));	
	
    return((gpioBaseAddr[GPIO_GPxPDIR_INDEX] >> (pin % 32U)) & (uint32_t)0x1U);
}

//*****************************************************************************
//
//! Writes a value to the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param outVal is the value to write to the pin.
//!
//! Writes the corresponding bit values to the output pin specified by
//! \e pin.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_writePin(uint32_t pin, uint32_t outVal)
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
	 
    if(outVal !=0)
    {
        gpioBaseAddr[GPIO_GPxPDOR_INDEX] |= pinMask;

    }else{
        gpioBaseAddr[GPIO_GPxPDOR_INDEX] &= ~pinMask;	 
    }		
}

//*****************************************************************************
//
//! Toggles the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! Writes the corresponding bit values to the output pin specified by
//! \e pin.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_togglePin(uint32_t pin)
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
	 
    gpioBaseAddr[GPIO_GPxPTOR_INDEX] |= pinMask;
	 
	
}

//*****************************************************************************
//
//! Reads the data on the specified port.
//!
//! \param port is the GPIO port being accessed in the form of \b GPIO_PORT_X
//! where X is the port letter.
//!
//! \return Returns the value available on pin for the specified port. Each
//! bit of the the return value represents a pin on the port, where bit 0
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPortData(GPIO_Port port)
{
	  volatile uint32_t *gpioBaseAddr;
    //
    // Get the starting address of the port's registers and return DATA.
    //
    if(port == GPIO_PORT_A){
        gpioBaseAddr = (uint32_t *)GPIOA_BASE;
    }
    else  if(port == GPIO_PORT_B){
        gpioBaseAddr = (uint32_t *)GPIOB_BASE;
    }else{
        ASSERT(0);
    }	
    return(gpioBaseAddr[GPIO_GPxPDOR_INDEX]);
}

//*****************************************************************************
//
//! Reads the data written in GPIO Data Register.
//!
//! \param port is the GPIO port being accessed in the form of \b GPIO_PORT_X
//! where X is the port letter.
//!
//! Reads the data written in GPIO Data Register for the specified port. In
//! previous devices, read of GPIO data registers resulted in read of
//! corespoinding pins. The function \b GPIO_readPortData() returns the value
//! on pin.
//!
//! \sa GPIO_readPortData()
//!
//! \return Returns the value in the data register for the specified port. Each
//! bit of the the return value represents a pin on the port, where bit 0
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPortDataRegister(GPIO_Port port)
{
    volatile uint32_t *gpioBaseAddr;

    //
    // Get the starting address of the port's registers and return DATA.
    //
    if(port == GPIO_PORT_A){
        gpioBaseAddr = (uint32_t *)GPIOA_BASE;
    }
    else if(port == GPIO_PORT_B){
        gpioBaseAddr = (uint32_t *)GPIOB_BASE;
    }else{
        ASSERT(0);
    }
    return(gpioBaseAddr[GPIO_GPxPDIR_INDEX]);
}

//*****************************************************************************
//
//! Writes a value to the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param outVal is the value to write to the port.
//!
//! This function writes the value \e outVal to the port specified by the
//! \e port parameter which takes a value in the form of \b GPIO_PORT_X where X
//! is the port letter. For example, use \b GPIO_PORT_A to affect port A
//! (GPIOs 0-31).
//!
//! The \e outVal is a bit-packed value, where each bit represents a bit on a
//! GPIO port. Bit 0 represents GPIO port pin 0, bit 1 represents GPIO port
//! pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_writePortData(GPIO_Port port, uint32_t outVal)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    if(port == GPIO_PORT_A){
        gpioBaseAddr = (uint32_t *)GPIOA_BASE;
    }
    else  if(port == GPIO_PORT_B){
        gpioBaseAddr = (uint32_t *)GPIOB_BASE;
    }else{
        ASSERT(0);
    }	
   gpioBaseAddr[GPIO_GPxPDOR_INDEX] = outVal;		
}

//*****************************************************************************
//
//! Sets all of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function sets all of the pins specified by the \e pinMask parameter on
//! the port specified by the \e port parameter which takes a value in the
//! form of \b GPIO_PORT_X where X is the port letter. For example, use
//! \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is set identifies
//! the pin to be set. Bit 0 represents GPIO port pin 0, bit 1 represents GPIO
//! port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_setPortPins(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioBaseAddr;

    if(port == GPIO_PORT_A){
        gpioBaseAddr = (uint32_t *)GPIOA_BASE;
    }
    else  if(port == GPIO_PORT_B){
        gpioBaseAddr = (uint32_t *)GPIOB_BASE;
    }else{
        ASSERT(0);
    }	
   gpioBaseAddr[GPIO_GPxPSOR_INDEX] |= pinMask;			
}

//*****************************************************************************
//
//! Clears all of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function clears all of the pins specified by the \e pinMask parameter
//! on the port specified by the \e port parameter which takes a value in the
//! form of \b GPIO_PORT_X where X is the port letter. For example, use
//! \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is \b set
//! identifies the pin to be cleared. Bit 0 represents GPIO port pin 0, bit 1
//! represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_clearPortPins(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioBaseAddr;

    if(port == GPIO_PORT_A){
        gpioBaseAddr = (uint32_t *)GPIOA_BASE;
    }
    else if(port == GPIO_PORT_B){
        gpioBaseAddr = (uint32_t *)GPIOB_BASE;
    }else{
        ASSERT(0);
    }	
   gpioBaseAddr[GPIO_GPxPCOR_INDEX] |= pinMask;			
}

//*****************************************************************************
//
//! Toggles all of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function toggles all of the pins specified by the \e pinMask parameter
//! on the port specified by the \e port parameter which takes a value in the
//! form of \b GPIO_PORT_X where X is the port letter. For example, use
//! \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is set identifies
//! the pin to be toggled. Bit 0 represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_togglePortPins(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioBaseAddr;

    if(port == GPIO_PORT_A){
        gpioBaseAddr = (uint32_t *)GPIOA_BASE;
    }
    else if(port == GPIO_PORT_B){
        gpioBaseAddr = (uint32_t *)GPIOB_BASE;
    }else{
        ASSERT(0);
    }	
 
   gpioBaseAddr[GPIO_GPxPTOR_INDEX] |= pinMask;		
	
}

//*****************************************************************************
//
//! Locks the configuration of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function locks the configuration registers of the pins specified by
//! the \e pinMask parameter on the port specified by the \e port parameter
//! which takes a value in the form of \b GPIO_PORT_X where X is the port
//! letter. For example, use \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is set identifies
//! the pin to be locked. Bit 0 represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, 0xFFFFFFFF represents all pins on that port, and so on.
//!
//! Note that this function is for locking the configuration of a pin such as
//! the pin muxing, direction, open drain mode, and other settings. It does not
//! affect the ability to change the value of the pin.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_lockPortConfig(GPIO_Port port, uint32_t pinMask)
{	
    volatile uint32_t *portBaseAddr;
    uint16_t i;
    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

	if(port == GPIO_PORT_A){
		portBaseAddr = (uint32_t *)PORTA_BASE;
	}
	else if(port == GPIO_PORT_B){
		portBaseAddr = (uint32_t *)PORTB_BASE;
	}else{
        ASSERT(0);
	}	
    
    for(i=0;i<32;i++)
    {
        if(pinMask&(1<<i))
            portBaseAddr[4*i]  |= PORT_PCR_LK_MASK;	
    }
}


//*****************************************************************************
//
//! Sets the direction and mode of the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param pinIO is the pin direction mode.
//!
//! This function configures the specified pin on the selected GPIO port as
//! either input or output.
//!
//! The parameter \e pinIO is an enumerated data type that can be one of the
//! following values:
//!
//! - \b GPIO_DIR_MODE_IN
//! - \b GPIO_DIR_MODE_OUT
//!
//! where \b GPIO_DIR_MODE_IN specifies that the pin is programmed as an input
//! and \b GPIO_DIR_MODE_OUT specifies that the pin is programmed as an output.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setDirectionMode(uint32_t pin, GPIO_Direction pinIO);

//*****************************************************************************
//
//! Gets the direction mode of a pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! This function gets the direction mode for a specified pin.  The pin can be
//! configured as either an input or output The type of direction is returned
//! as an enumerated data type.
//!
//! \return Returns one of the enumerated data types described for
//! GPIO_setDirectionMode().
//
//*****************************************************************************
extern GPIO_Direction
GPIO_getDirectionMode(uint32_t pin);

//*****************************************************************************
//
//! Sets the pin for the specified external interrupt.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param extIntNum specifies the external interrupt.
//!
//! This function sets which pin triggers the selected external interrupt.
//!
//! The following defines can be used to specify the external interrupt for the
//! \e extIntNum parameter:
//!
//! - \b GPIO_INT_XINT1
//! - \b GPIO_INT_XINT2
//! - \b GPIO_INT_XINT3
//! - \b GPIO_INT_XINT4
//! - \b GPIO_INT_XINT5
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \sa XBAR_setInputPin()
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum extIntNum);

//*****************************************************************************
//
//! Sets the pad configuration for the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param pinType specifies the pin type.
//!
//! This function sets the pin type for the specified pin. The parameter
//! \e pinType can be the following values:
//!
//! - \b GPIO_PIN_TYPE_STD specifies a push-pull output or a floating input
//! - \b GPIO_PIN_TYPE_PULLUP specifies the pull-up is enabled for an input
//! - \b GPIO_PIN_TYPE_OD specifies an open-drain output pin
//! - \b GPIO_PIN_TYPE_INVERT specifies inverted polarity on an input
//!
//! \b GPIO_PIN_TYPE_INVERT may be OR-ed with \b GPIO_PIN_TYPE_STD or
//! \b GPIO_PIN_TYPE_PULLUP.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setPadConfig(uint32_t pin, uint32_t pinType);

//*****************************************************************************
//
//! Clear the pad configuration of the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param pinType specifies the pin type.
//!
//! This function sets the pin type for the specified pin. The parameter
//! \e pinType can be the following values:
//!
//! - \b GPIO_PIN_TYPE_STD specifies a push-pull output or a floating input
//! - \b GPIO_PIN_TYPE_PULLUP specifies the pull-up is enabled for an input
//! - \b GPIO_PIN_TYPE_OD specifies an open-drain output pin
//! - \b GPIO_PIN_TYPE_INVERT specifies inverted polarity on an input
//!
//! \b GPIO_PIN_TYPE_INVERT may be OR-ed with \b GPIO_PIN_TYPE_STD or
//! \b GPIO_PIN_TYPE_PULLUP.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_clearPadConfig(uint32_t pin, uint32_t pinType);
//*****************************************************************************
//
//! Gets the pad configuration for a pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! This function returns the pin type for the specified pin.  The value
//! returned corresponds to the values used in GPIO_setPadConfig().
//!
//! \return Returns a bit field of the values \b GPIO_PIN_TYPE_STD,
//! \b GPIO_PIN_TYPE_PULLUP, \b GPIO_PIN_TYPE_OD, and \b GPIO_PIN_TYPE_INVERT.
//
//*****************************************************************************
extern uint32_t
GPIO_getPadConfig(uint32_t pin);

//*****************************************************************************
//
//! Sets the qualification mode for the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param qualification specifies the qualification mode of the pin.
//!
//! This function sets the qualification mode for the specified pin. The
//! parameter \e qualification can be one of the following values:
//! - \b GPIO_QUAL_SYNC
//! - \b GPIO_QUAL_3SAMPLE
//! - \b GPIO_QUAL_6SAMPLE
//! - \b GPIO_QUAL_ASYNC
//!
//! To set the qualification sampling period, use
//! GPIO_setQualificationPeriod().
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setQualificationMode(uint32_t pin, GPIO_QualificationMode qualification);

//*****************************************************************************
//
//! Gets the qualification type for the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! \return Returns the qualification mode in the form of one of the values
//! \b GPIO_QUAL_SYNC, \b GPIO_QUAL_3SAMPLE, \b GPIO_QUAL_6SAMPLE, or
//! \b GPIO_QUAL_ASYNC.
//
//*****************************************************************************
extern GPIO_QualificationMode
GPIO_getQualificationMode(uint32_t pin);


//*****************************************************************************
//
//! configure Digital Filters parameter for the pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param Filters specifies the Filters parameter of the pin.
//!
//! This function sets the Filters parameter for the  pin. The
//! parameter \e qualification can be one of the following values:
//! - \b clock source:LPO_CLOCK or LPO_CLOCK
//! - \b filter length :0~31
//!
//! \return None.
//
//*****************************************************************************
void
GPIO_configureDigitalFilters(uint32_t pin, GPIO_DigitalFilter Filter);

//*****************************************************************************
//
//! get configure Digital Filters parameter of the pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param Filters specifies the Filters parameter of the pin.
//!
//! This function sets the Filters parameter for the  pin. The
//! parameter \e qualification can be one of the following values:
//! - \b clock source:LPO_CLOCK or LPO_CLOCK
//! - \b filter length :0~31
//!
//! \return None.
//
//*****************************************************************************
GPIO_DigitalFilter
GPIO_getDigitalFilterConfiguration(uint32_t pin);

//*****************************************************************************
//
//! Configures the alternate function of a GPIO pin.
//!
//! \param pinConfig is the pin configuration value, specified as only one
//! of the \b GPIO_#_???? values.
//!
//! This function configures the pin mux that selects the peripheral function
//! associated with a particular GPIO pin.  Only one peripheral function at a
//! time can be associated with a GPIO pin, and each peripheral function should
//! only be associated with a single GPIO pin at a time (despite the fact that
//! many of them can be associated with more than one GPIO pin).
//!
//! The available mappings are supplied in <tt>pin_map.h</tt>.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setPinConfig(uint32_t pinConfig);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  GPIO_H
