
/*****************************************************************************/
/* Version: GCC for ARM Embedded Processors                                  */
/*****************************************************************************/
    .syntax unified
    .arch armv7-m

    .section .isr_vector, "a"
    .align 2
    .globl __isr_vector
__isr_vector:
    .long   __StackTop                                      /* Top of Stack */
    .long   Reset_Handler                                   /* Reset Handler */
    .long   NMI_Handler                                     /* NMI Handler*/
    .long   HardFault_Handler                               /* Hard Fault Handler*/
    .long   MemManage_Handler                               /* MPU Fault Handler*/
    .long   BusFault_Handler                                /* Bus Fault Handler*/
    .long   UsageFault_Handler                              /* Usage Fault Handler*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   SVC_Handler                                     /* SVCall Handler*/
    .long   DebugMon_Handler                                /* Debug Monitor Handler*/
    .long   0                                               /* Reserved*/
    .long   PendSV_Handler                                  /* PendSV Handler*/
    .long   SysTick_Handler                                 /* SysTick Handler*/

                                                            /* External Interrupts*/
    .long   DMA0_IRQHandler                                 /* DMA Channel 0 Transfer Complete*/
    .long   DMA1_IRQHandler                                 /* DMA Channel 1 Transfer Complete*/
    .long   DMA2_IRQHandler                                 /* DMA Channel 2 Transfer Complete*/
    .long   DMA3_IRQHandler                                 /* DMA Channel 3 Transfer Complete*/
    .long   DMA4_IRQHandler                                 /* DMA Channel 4 Transfer Complete*/
    .long   DMA5_IRQHandler                                 /* DMA Channel 5 Transfer Complete*/
    .long   DMA6_IRQHandler                                 /* DMA Channel 6 Transfer Complete*/
    .long   DMA7_IRQHandler                                 /* DMA Channel 7 Transfer Complete*/
    .long   DMA8_IRQHandler                                 /* DMA Channel 8 Transfer Complete*/
    .long   DMA9_IRQHandler                                 /* DMA Channel 9 Transfer Complete*/
    .long   DMA10_IRQHandler                                /* DMA Channel 10 Transfer Complete*/
    .long   DMA11_IRQHandler                                /* DMA Channel 11 Transfer Complete*/
    .long   DMA12_IRQHandler                                /* DMA Channel 12 Transfer Complete*/
    .long   DMA13_IRQHandler                                /* DMA Channel 13 Transfer Complete*/
    .long   DMA14_IRQHandler                                /* DMA Channel 14 Transfer Complete*/
    .long   DMA15_IRQHandler                                /* DMA Channel 15 Transfer Complete*/
    .long   DMA1_Error_IRQHandler             /* 32: DMA Error Interrupt*/
    .long     MCM_IRQHandler                    /* 33: Normal Interrupt*/
    .long     FLASH_IRQHandler                  /* 34: FLASH*/
    .long     0                                 /* 35: FLASH*/
    .long     LVD_IRQHandler                    /* 36: low voltage detector */
    .long     LLW_IRQHandler                    /* 37: low leakage wakeup*/
    .long     WDOG_IRQHandler                   /* 38: WWDOG and EWM share the interrupt*/
    .long     0                                 /* 39: Reserved*/
    .long     I2C1_IRQHandler                   /* 40: I2C1 Error*/
    .long     I2C2_IRQHandler                   /* 41: I2C2 Event*/
    .long     SPI1_IRQHandler                   /* 42: SPI1*/
    .long     SPI2_IRQHandler                   /* 43: SPI2*/
    .long     SPI3_IRQHandler                   /* 44: SPI1*/
    .long     SPI4_IRQHandler                   /* 45: SPI2*/
    .long     USART1_IRQHandler                 /* 46: USART1*/
    .long     USART2_IRQHandler                 /* 47: USART2*/
    .long     USART3_IRQHandler                 /* 48: USART1*/
    .long     USART4_IRQHandler                 /* 49: USART2*/
    .long     USART5_IRQHandler                 /* 50: USART1*/
    .long     USART6_IRQHandler                 /* 51: USART2*/
    .long     ADCA_INT1_IRQHandler              /* 52: ADC1*/
    .long     ADCA_INT2_IRQHandler              /* 53: ADC1*/
    .long     ADCA_INT3_IRQHandler              /* 54: ADC1*/
    .long     ADCA_INT4_IRQHandler              /* 55: ADC1*/
    .long     ADCA_EVT_IRQHandler               /* 56: ADC1 EVT*/
    .long     ADCB_INT1_IRQHandler              /* 57: ADC2*/
    .long     ADCB_INT2_IRQHandler              /* 58: ADC2*/
    .long     ADCB_INT3_IRQHandler              /* 59: ADC2*/
    .long     ADCB_INT4_IRQHandler              /* 60: ADC2*/
    .long     ADCB_EVT_IRQHandler               /* 61: ADC2 EVT*/
    .long     ADCC_INT1_IRQHandler              /* 62: ADC3*/
    .long     ADCC_INT2_IRQHandler              /* 63: ADC3*/
    .long     ADCC_INT3_IRQHandler              /* 64: ADC3*/
    .long     ADCC_INT4_IRQHandler              /* 65: ADC3*/
    .long     ADCC_EVT_IRQHandler               /* 66: ADC3 EVT*/
    .long     CMP1_IRQHandler                   /* 67: CMP1 Interrupt*/
    .long     CMP2_IRQHandler                   /* 68: CMP2 Interrupt*/
    .long     CMP3_IRQHandler                   /* 69: CMP3 Interrupt*/
    .long     CMP4_IRQHandler                   /* 70: CMP4 Interrupt*/
    .long     CMP5_IRQHandler                   /* 71: CMP5 Interrupt*/
    .long     CMP6_IRQHandler                   /* 72: CMP6 Interrupt*/
    .long     EPWM1_IRQHandler                  /* 73: EPWM1 Interrupt*/
    .long     EPWM2_IRQHandler                  /* 74: EPWM2 Interrupt*/
    .long     EPWM3_IRQHandler                  /* 75: EPWM3 Interrupt*/
    .long     EPWM4_IRQHandler                  /* 76: EPWM4 Interrupt*/
    .long     EPWM5_IRQHandler                  /* 77: EPWM5 Interrupt*/
    .long     EPWM6_IRQHandler                  /* 78: EPWM6 Interrupt*/
    .long     EPWM7_IRQHandler                  /* 79: EPWM7 Interrupt*/
    .long     0                                 /* 80: Reserved*/
    .long     EPWM1_TZ_IRQHandler               /* 81: EPWM1 Tripzone Interrupt*/
    .long     EPWM2_TZ_IRQHandler               /* 82: EPWM2 Tripzone Interrupt*/
    .long     EPWM3_TZ_IRQHandler               /* 83: EPWM3 Tripzone Interrupt*/
    .long     EPWM4_TZ_IRQHandler               /* 94: EPWM4 Tripzone Interrupt*/
    .long     EPWM5_TZ_IRQHandler               /* 85: EPWM5 Tripzone Interrupt*/
    .long     EPWM6_TZ_IRQHandler               /* 86: EPWM6 Tripzone Interrupt*/
    .long     EPWM7_TZ_IRQHandler               /* 87: EPWM7 Tripzone Interrupt*/
    .long     0                                 /* 88: Reserved*/
    .long     XINT1_IRQHandler                  /* 89:*/
    .long     XINT2_IRQHandler                  /* 90:*/
    .long     XINT3_IRQHandler                  /* 91:*/
    .long     XINT4_IRQHandler                  /* 92:*/
    .long     XINT5_IRQHandler                  /* 93:*/
    .long     0                                 /* 94: Reserved*/
    .long     0                                 /* 95: Reserved*/
    .long     0                                 /* 96: Reserved*/
    .long     ECAP1_IRQHandler                  /* 97:*/
    .long     ECAP2_IRQHandler                  /* 98:*/
    .long     ECAP3_IRQHandler                  /* 99:*/
    .long     CAN1_TX_IRQHandler                /* 100: CAN1 TX*/
    .long     CAN1_RX0_IRQHandler               /* 101: CAN1 RX0*/
    .long     CAN1_RX1_IRQHandler               /* 102: CAN1 RX1*/
    .long     CAN1_SCE_IRQHandler               /* 103: CAN1 SCE*/
    .long     0                                 /* 104: Reserved*/
    .long     0                                 /* 105: Reserved*/
    .long     EQEP1_IRQHandler                  /* 106:*/
    .long     EQEP2_IRQHandler                  /* 107:*/
    .long     PTMR1_IRQHandler                  /* 108:TIM1*/
    .long     PTMR2_IRQHandler                  /* 109:TIM2*/
    .long     PTMR3_IRQHandler                  /* 110:TIM3*/
    .long     PTMR4_IRQHandler                  /* 111:TIM4*/
    .long     SDFM1_IRQHandler                  /* 112: */
    .long     SDFM1_DR0_IRQHandler              /* 113: */
    .long     SDFM1_DR1_IRQHandler              /* 114: */
    .long     SDFM1_DR2_IRQHandler              /* 115: */
    .long     SDFM1_DR3_IRQHandler              /* 116: */
    .long     SDFM2_IRQHandler                  /* 117: */
    .long     SDFM2_DR0_IRQHandler              /* 118: */
    .long     SDFM2_DR1_IRQHandler              /* 119: */
    .long     SDFM2_DR2_IRQHandler              /* 120: */
    .long     SDFM2_DR3_IRQHandler              /* 121: */
    .long     DCC1_IRQHandler                   /* 122:*/
    .long     DCC2_IRQHandler                   /* 123:*/
    .long     FLASHECC_IRQHandler               /* 124: */
    .long   DefaultISR                                      /* 140*/
    .long   DefaultISR                                      /* 141*/
    .long   DefaultISR                                      /* 142*/
    .long   DefaultISR                                      /* 143*/
    .long   DefaultISR                                      /* 144*/
    .long   DefaultISR                                      /* 145*/
    .long   DefaultISR                                      /* 146*/
    .long   DefaultISR                                      /* 147*/
    .long   DefaultISR                                      /* 148*/
    .long   DefaultISR                                      /* 149*/
    .long   DefaultISR                                      /* 150*/
    .long   DefaultISR                                      /* 151*/
    .long   DefaultISR                                      /* 152*/
    .long   DefaultISR                                      /* 153*/
    .long   DefaultISR                                      /* 154*/
    .long   DefaultISR                                      /* 155*/
    .long   DefaultISR                                      /* 156*/
    .long   DefaultISR                                      /* 157*/
    .long   DefaultISR                                      /* 158*/
    .long   DefaultISR                                      /* 159*/
    .long   DefaultISR                                      /* 160*/
    .long   DefaultISR                                      /* 161*/
    .long   DefaultISR                                      /* 162*/
    .long   DefaultISR                                      /* 163*/
    .long   DefaultISR                                      /* 164*/
    .long   DefaultISR                                      /* 165*/
    .long   DefaultISR                                      /* 166*/
    .long   DefaultISR                                      /* 167*/
    .long   DefaultISR                                      /* 168*/
    .long   DefaultISR                                      /* 169*/
    .long   DefaultISR                                      /* 170*/
    .long   DefaultISR                                      /* 171*/
    .long   DefaultISR                                      /* 172*/
    .long   DefaultISR                                      /* 173*/
    .long   DefaultISR                                      /* 174*/
    .long   DefaultISR                                      /* 175*/
    .long   DefaultISR                                      /* 176*/
    .long   DefaultISR                                      /* 177*/
    .long   DefaultISR                                      /* 178*/
    .long   DefaultISR                                      /* 179*/
    .long   DefaultISR                                      /* 180*/
    .long   DefaultISR                                      /* 181*/
    .long   DefaultISR                                      /* 182*/
    .long   DefaultISR                                      /* 183*/
    .long   DefaultISR                                      /* 184*/
    .long   DefaultISR                                      /* 185*/
    .long   DefaultISR                                      /* 186*/
    .long   DefaultISR                                      /* 187*/
    .long   DefaultISR                                      /* 188*/
    .long   DefaultISR                                      /* 189*/
    .long   DefaultISR                                      /* 190*/
    .long   DefaultISR                                      /* 191*/
    .long   DefaultISR                                      /* 192*/
    .long   DefaultISR                                      /* 193*/
    .long   DefaultISR                                      /* 194*/
    .long   DefaultISR                                      /* 195*/
    .long   DefaultISR                                      /* 196*/
    .long   DefaultISR                                      /* 197*/
    .long   DefaultISR                                      /* 198*/
    .long   DefaultISR                                      /* 199*/
    .long   DefaultISR                                      /* 200*/
    .long   DefaultISR                                      /* 201*/
    .long   DefaultISR                                      /* 202*/
    .long   DefaultISR                                      /* 203*/
    .long   DefaultISR                                      /* 204*/
    .long   DefaultISR                                      /* 205*/
    .long   DefaultISR                                      /* 206*/
    .long   DefaultISR                                      /* 207*/
    .long   DefaultISR                                      /* 208*/
    .long   DefaultISR                                      /* 209*/
    .long   DefaultISR                                      /* 210*/
    .long   DefaultISR                                      /* 211*/
    .long   DefaultISR                                      /* 212*/
    .long   DefaultISR                                      /* 213*/
    .long   DefaultISR                                      /* 214*/
    .long   DefaultISR                                      /* 215*/
    .long   DefaultISR                                      /* 216*/
    .long   DefaultISR                                      /* 217*/
    .long   DefaultISR                                      /* 218*/
    .long   DefaultISR                                      /* 219*/
    .long   DefaultISR                                      /* 220*/
    .long   DefaultISR                                      /* 221*/
    .long   DefaultISR                                      /* 222*/
    .long   DefaultISR                                      /* 223*/
    .long   DefaultISR                                      /* 224*/
    .long   DefaultISR                                      /* 225*/
    .long   DefaultISR                                      /* 226*/
    .long   DefaultISR                                      /* 227*/
    .long   DefaultISR                                      /* 228*/
    .long   DefaultISR                                      /* 229*/
    .long   DefaultISR                                      /* 230*/
    .long   DefaultISR                                      /* 231*/
    .long   DefaultISR                                      /* 232*/
    .long   DefaultISR                                      /* 233*/
    .long   DefaultISR                                      /* 234*/
    .long   DefaultISR                                      /* 235*/
    .long   DefaultISR                                      /* 236*/
    .long   DefaultISR                                      /* 237*/
    .long   DefaultISR                                      /* 238*/
    .long   DefaultISR                                      /* 239*/
    .long   DefaultISR                                      /* 240*/
    .long   DefaultISR                                      /* 241*/
    .long   DefaultISR                                      /* 242*/
    .long   DefaultISR                                      /* 243*/
    .long   DefaultISR                                      /* 244*/
    .long   DefaultISR                                      /* 245*/
    .long   DefaultISR                                      /* 246*/
    .long   DefaultISR                                      /* 247*/
    .long   DefaultISR                                      /* 248*/
    .long   DefaultISR                                      /* 249*/
    .long   DefaultISR                                      /* 250*/
    .long   DefaultISR                                      /* 251*/
    .long   DefaultISR                                      /* 252*/
    .long   DefaultISR                                      /* 253*/
    .long   DefaultISR                                      /* 254*/
    .long   0xFFFFFFFF                                      /*  Reserved for user TRIM value*/

    .size    __isr_vector, . - __isr_vector

    .text
    .thumb

/* Reset Handler */

    .thumb_func
    .align 2
    .globl   Reset_Handler
    .weak    Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:
    cpsid   i               /* Mask interrupts */
#ifndef __NO_SYSTEM_INIT
    bl SystemInit
#endif
/*    bl init_data_bss  jpan*/
    cpsie   i               /* Unmask interrupts */

/* from m3 project  */
    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

    subs    r3, r2
    ble    .LC1
.LC0:
    subs    r3, #4
    ldr    r0, [r1, r3]
    str    r0, [r2, r3]
    bgt    .LC0
.LC1:

#ifdef __STARTUP_CLEAR_BSS
/*     This part of work usually is done in C library startup code. Otherwise,
 *     define this macro to enable it in this startup.
 *
 *     Loop to zero out BSS section, which uses following symbols
 *     in linker script:
 *      __bss_start__: start of BSS section. Must align to 4
 *      __bss_end__: end of BSS section. Must align to 4
 */
    ldr r1, =__bss_start__
    ldr r2, =__bss_end__

    movs    r0, 0
.LC2:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .LC2
#endif /* __STARTUP_CLEAR_BSS */


    bl    main
    .pool
    .size Reset_Handler, . - Reset_Handler

    .align	1
    .thumb_func
    .weak DefaultISR
    .type DefaultISR, %function
DefaultISR:
    b	DefaultISR
    .size DefaultISR, . - DefaultISR

/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro def_irq_handler	handler_name
    .weak \handler_name
    .set  \handler_name, DefaultISR
    .endm

/* Exception Handlers */
    def_irq_handler    NMI_Handler
    def_irq_handler    HardFault_Handler
    def_irq_handler    MemManage_Handler
    def_irq_handler    BusFault_Handler
    def_irq_handler    UsageFault_Handler
    def_irq_handler    SVC_Handler
    def_irq_handler    DebugMon_Handler
    def_irq_handler    PendSV_Handler
    def_irq_handler    SysTick_Handler
    def_irq_handler    DMA0_IRQHandler
    def_irq_handler    DMA1_IRQHandler
    def_irq_handler    DMA2_IRQHandler
    def_irq_handler    DMA3_IRQHandler
    def_irq_handler    DMA4_IRQHandler
    def_irq_handler    DMA5_IRQHandler
    def_irq_handler    DMA6_IRQHandler
    def_irq_handler    DMA7_IRQHandler
    def_irq_handler    DMA8_IRQHandler
    def_irq_handler    DMA9_IRQHandler
    def_irq_handler    DMA10_IRQHandler
    def_irq_handler    DMA11_IRQHandler
    def_irq_handler    DMA12_IRQHandler
    def_irq_handler    DMA13_IRQHandler
    def_irq_handler    DMA14_IRQHandler
    def_irq_handler    DMA15_IRQHandler
    def_irq_handler    DMA1_Error_IRQHandler
    def_irq_handler    MCM_IRQHandler                
    def_irq_handler    FLASH_IRQHandler              
;    def_irq_handler    Read_Collision_IRQHandler     
    def_irq_handler    LVD_IRQHandler                
    def_irq_handler    LLW_IRQHandler                
    def_irq_handler    WDOG_IRQHandler               
    def_irq_handler    I2C1_IRQHandler               
    def_irq_handler    I2C2_IRQHandler               
    def_irq_handler    SPI1_IRQHandler               
    def_irq_handler    SPI2_IRQHandler               
    def_irq_handler    SPI3_IRQHandler               
    def_irq_handler    SPI4_IRQHandler               
    def_irq_handler    USART1_IRQHandler             
    def_irq_handler    USART2_IRQHandler             
    def_irq_handler    USART3_IRQHandler             
    def_irq_handler    USART4_IRQHandler             
    def_irq_handler    USART5_IRQHandler             
    def_irq_handler    USART6_IRQHandler             
    def_irq_handler    ADCA_INT1_IRQHandler          
    def_irq_handler    ADCA_INT2_IRQHandler          
    def_irq_handler    ADCA_INT3_IRQHandler          
    def_irq_handler    ADCA_INT4_IRQHandler          
    def_irq_handler    ADCA_EVT_IRQHandler           
    def_irq_handler    ADCB_INT1_IRQHandler          
    def_irq_handler    ADCB_INT2_IRQHandler          
    def_irq_handler    ADCB_INT3_IRQHandler          
    def_irq_handler    ADCB_INT4_IRQHandler          
    def_irq_handler    ADCB_EVT_IRQHandler           
    def_irq_handler    ADCC_INT1_IRQHandler          
    def_irq_handler    ADCC_INT2_IRQHandler          
    def_irq_handler    ADCC_INT3_IRQHandler          
    def_irq_handler    ADCC_INT4_IRQHandler          
    def_irq_handler    ADCC_EVT_IRQHandler           
    def_irq_handler    CMP1_IRQHandler               
    def_irq_handler    CMP2_IRQHandler               
    def_irq_handler    CMP3_IRQHandler               
    def_irq_handler    CMP4_IRQHandler               
    def_irq_handler    CMP5_IRQHandler               
    def_irq_handler    CMP6_IRQHandler               
    def_irq_handler    EPWM1_IRQHandler              
    def_irq_handler    EPWM2_IRQHandler              
    def_irq_handler    EPWM3_IRQHandler              
    def_irq_handler    EPWM4_IRQHandler              
    def_irq_handler    EPWM5_IRQHandler              
    def_irq_handler    EPWM6_IRQHandler              
    def_irq_handler    EPWM7_IRQHandler              
    def_irq_handler    EPWM1_TZ_IRQHandler           
    def_irq_handler    EPWM2_TZ_IRQHandler           
    def_irq_handler    EPWM3_TZ_IRQHandler           
    def_irq_handler    EPWM4_TZ_IRQHandler           
    def_irq_handler    EPWM5_TZ_IRQHandler           
    def_irq_handler    EPWM6_TZ_IRQHandler           
    def_irq_handler    EPWM7_TZ_IRQHandler           
    def_irq_handler    XINT1_IRQHandler             
    def_irq_handler    XINT2_IRQHandler             
    def_irq_handler    XINT3_IRQHandler             
    def_irq_handler    XINT4_IRQHandler             
    def_irq_handler    XINT5_IRQHandler             
    def_irq_handler    ECAP1_IRQHandler             
    def_irq_handler    ECAP2_IRQHandler             
    def_irq_handler    ECAP3_IRQHandler             
    def_irq_handler    CAN1_TX_IRQHandler           
    def_irq_handler    CAN1_RX0_IRQHandler          
    def_irq_handler    CAN1_RX1_IRQHandler          
    def_irq_handler    CAN1_SCE_IRQHandler          
    def_irq_handler    EQEP1_IRQHandler             
    def_irq_handler    EQEP2_IRQHandler             
    def_irq_handler    PTMR1_IRQHandler             
    def_irq_handler    PTMR2_IRQHandler             
    def_irq_handler    PTMR3_IRQHandler             
    def_irq_handler    PTMR4_IRQHandler             
    def_irq_handler    SDFM1_IRQHandler              
    def_irq_handler    SDFM1_DR0_IRQHandler          
    def_irq_handler    SDFM1_DR1_IRQHandler          
    def_irq_handler    SDFM1_DR2_IRQHandler          
    def_irq_handler    SDFM1_DR3_IRQHandler          
    def_irq_handler    SDFM2_IRQHandler              
    def_irq_handler    SDFM2_DR0_IRQHandler          
    def_irq_handler    SDFM2_DR1_IRQHandler          
    def_irq_handler    SDFM2_DR2_IRQHandler          
    def_irq_handler    SDFM2_DR3_IRQHandler          
    def_irq_handler    DCC1_IRQHandler               
    def_irq_handler    DCC2_IRQHandler               
    def_irq_handler    FLASHECC_IRQHandler  

    .end
