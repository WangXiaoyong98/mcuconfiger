//###########################################################################
//
// FILE:    hw_gpio.h
//
// TITLE:   Definitions for the GPIO registers.
//
//###########################################################################
// $Copyright:
// Copyright (C) 
// $
//###########################################################################

#ifndef HW_GPIO_H
#define HW_GPIO_H

//*************************************************************************************************
//
// The following are defines for the GPIO register offsets
//
//*************************************************************************************************
#define GPIO_O_GPAPDOR    0x0U     // GPIO A Port Data Output Register    (GPIO0 to 31)
#define GPIO_O_GPAPSOR    0x4U     // GPIO A Port Set Output Register     (GPIO0 to 31)
#define GPIO_O_GPAPCOR    0x8U     // GPIO A Port Clear Output Register   (GPIO0 to 31)
#define GPIO_O_GPAPTOR    0xCU     // GPIO A Port Toggle Output Register   (GPIO0 to 31)
#define GPIO_O_GPAPDIR    0x10U    // GPIO A Port Data Input Register     (GPIO0 to 31)
#define GPIO_O_GPAPDDR    0x14U    // GPIO A Port Data Direction Register (GPIO0 to 31)



#define GPIO_O_GPBPDOR    0x40U     // GPIO B Port Data Output Register    (GPIO0 to 31)
#define GPIO_O_GPBPSOR    0x44U     // GPIO B Port Set Output Register     (GPIO0 to 31)
#define GPIO_O_GPBPCOR    0x48U     // GPIO B Port Clear Output Register   (GPIO0 to 31)
#define GPIO_O_GPBPTOR    0x4CU     // GPIO B Port Toggle Output Register   (GPIO0 to 31)
#define GPIO_O_GPBPDIR    0x50U     // GPIO B Port Data Input Register     (GPIO0 to 31)
#define GPIO_O_GPBPDDR    0x54U     // GPIO B Port Data Direction Register (GPIO0 to 31)


#define GPIO_O_PORTAPCR0     0x0U     // GPIO A Pin Control Register   (GPIO0)
#define GPIO_O_PORTAPCR1     0x4U     // GPIO A Pin Control Register   (GPIO1)
#define GPIO_O_PORTAPCR2     0x8U     // GPIO A Pin Control Register   (GPIO2)
#define GPIO_O_PORTAPCR3     0xCU     // GPIO A Pin Control Register   (GPIO3)

#define GPIO_O_PORTAPCR4     0x10U    // GPIO A Pin Control Register   (GPIO4)
#define GPIO_O_PORTAPCR5     0x14U    //  GPIO A Pin Control Register  (GPIO5)
#define GPIO_O_PORTAPCR6     0x18U     //  GPIO A Pin Control Register (GPIO6)
#define GPIO_O_PORTAPCR7     0x1CU     //  GPIO A Pin Control Register (GPIO7)

#define GPIO_O_PORTAPCR8     0x20U     //  GPIO A Pin Control Register (GPIO8)
#define GPIO_O_PORTAPCR9     0x24U     //  GPIO A Pin Control Register (GPIO9)
#define GPIO_O_PORTAPCR10    0x28U    //  GPIO A Pin Control Register  (GPIO10)
#define GPIO_O_PORTAPCR11    0x2CU    //  GPIO A Pin Control Register  (GPIO11

#define GPIO_O_PORTAPCR12    0x30U     //  GPIO A Pin Control Register   (GPIO12)
#define GPIO_O_PORTAPCR13    0x34U     //  GPIO A Pin Control Register   (GPIO13)
#define GPIO_O_PORTAPCR14    0x38U     //  GPIO A Pin Control Register   (GPIO14)
#define GPIO_O_PORTAPCR15    0x3CU     //  GPIO A Pin Control Register   (GPIO15)

#define GPIO_O_PORTAPCR16    0x40U     //  GPIO A Pin Control Register   (GPIO16)
#define GPIO_O_PORTAPCR17    0x44U     //  GPIO A Pin Control Register   (GPIO17)
#define GPIO_O_PORTAPCR18     0x48U     //  GPIO A Pin Control Register   (GPIO18)
#define GPIO_O_PORTAPCR19     0x4CU     // GPIO A Pin Control Register    (GPIO19)

#define GPIO_O_PORTAPCR20     0x50U     //  GPIO A Pin Control Register   (GPIO20)
#define GPIO_O_PORTAPCR21     0x54U     //  GPIO A Pin Control Register   (GPIO21)
#define GPIO_O_PORTAPCR22     0x58U     //  GPIO A Pin Control Register   (GPIO22)
#define GPIO_O_PORTAPCR23     0x5CU     //  GPIO A Pin Control Register   (GPIO23)

#define GPIO_O_PORTAPCR24     0x60U     //  GPIO A Pin Control Register    (GPIO24)
#define GPIO_O_PORTAPCR25     0x64U     //  GPIO A Pin Control Register    (GPIO25)
#define GPIO_O_PORTAPCR26     0x68U     //  GPIO A Pin Control Register    (GPIO26)
#define GPIO_O_PORTAPCR27     0x6CU     //  GPIO A Pin Control Register    (GPIO27)

#define GPIO_O_PORTAPCR28     0x70U     //  GPIO A Pin Control Register    (GPIO28)
#define GPIO_O_PORTAPCR29     0x74U     //  GPIO A Pin Control Register    (GPIO29)
#define GPIO_O_PORTAPCR30     0x78U     //  GPIO A Pin Control Register    (GPIO30)
#define GPIO_O_PORTAPCR31     0x7CU     //  GPIO A Pin Control Register    (GPIO31)


#define GPIO_O_PORTAGPCLR     0x80U     // GPIO A Global Pin Control Low Register   (GPIO0 to GPIO15)
#define GPIO_O_PORTAGPCHR     0x84U     // GPIO A Global Pin Control High Register   (GPIO15 to GPIO31)
#define GPIO_O_PORTAISFR      0xA0U     // GPIO A Interrupt Status Flag Register    (GPIO0 to GPIO31)
#define GPIO_O_PORTADFER      0xC0U     // GPIO A Digital Filter Enable Register    (GPIO0 to GPIO31)
#define GPIO_O_PORTADFCR      0xC4U     // GPIO A Digital Filter Clock Register     (GPIO0 to GPIO31)
#define GPIO_O_PORTADFWR      0xC8U     // GPIO A Digital Filter Width Register     (GPIO0 to GPIO31)


#define GPIO_O_PORTBPCR0     0x0U     // GPIO B Pin Control Register   (GPIO0)
#define GPIO_O_PORTBPCR1     0x4U     // GPIO B Pin Control Register   (GPIO1)
#define GPIO_O_PORTBPCR2     0x8U     // GPIO B Pin Control Register   (GPIO2)
#define GPIO_O_PORTBPCR3     0xCU     // GPIO B Pin Control Register   (GPIO3)

#define GPIO_O_PORTBPCR4     0x10U    // GPIO B Pin Control Register   (GPIO4)
#define GPIO_O_PORTBPCR5     0x14U    //  GPIO B Pin Control Register  (GPIO5)
#define GPIO_O_PORTBPCR6     0x18U     //  GPIO B Pin Control Register (GPIO6)
#define GPIO_O_PORTBPCR7     0x1CU     //  GPIO B Pin Control Register (GPIO7)

#define GPIO_O_PORTBPCR8     0x20U     //  GPIO B Pin Control Register (GPIO8)
#define GPIO_O_PORTBPCR9     0x24U     //  GPIO B Pin Control Register (GPIO9)
#define GPIO_O_PORTBPCR10    0x28U    //  GPIO B Pin Control Register  (GPIO10)
#define GPIO_O_PORTBPCR11    0x2CU    //  GPIO B Pin Control Register  (GPIO11

#define GPIO_O_PORTBPCR12    0x30U     //  GPIO B Pin Control Register   (GPIO12)
#define GPIO_O_PORTBPCR13    0x34U     //  GPIO B Pin Control Register   (GPIO13)
#define GPIO_O_PORTBPCR14    0x38U     //  GPIO B Pin Control Register   (GPIO14)
#define GPIO_O_PORTBPCR15    0x3CU     //  GPIO B Pin Control Register   (GPIO15)

#define GPIO_O_PORTBPCR16    0x40U     //  GPIO B Pin Control Register   (GPIO16)
#define GPIO_O_PORTBPCR17    0x44U     //  GPIO B Pin Control Register   (GPIO17)
#define GPIO_O_PORTBPCR18     0x48U     //  GPIO B Pin Control Register   (GPIO18)
#define GPIO_O_PORTBPCR19     0x4CU     // GPIO B Pin Control Register    (GPIO19)

#define GPIO_O_PORTBPCR20     0x50U     //  GPIO B Pin Control Register   (GPIO20)
#define GPIO_O_PORTBPCR21     0x54U     //  GPIO B Pin Control Register   (GPIO21)
#define GPIO_O_PORTBPCR22     0x58U     //  GPIO B Pin Control Register   (GPIO22)
#define GPIO_O_PORTBPCR23     0x5CU     //  GPIO B Pin Control Register   (GPIO23)

#define GPIO_O_PORTBPCR24     0x60U     //  GPIO B Pin Control Register    (GPIO24)
#define GPIO_O_PORTBPCR25     0x64U     //  GPIO B Pin Control Register    (GPIO25)
#define GPIO_O_PORTBPCR26     0x68U     //  GPIO B Pin Control Register    (GPIO26)
#define GPIO_O_PORTBPCR27     0x6CU     //  GPIO B Pin Control Register    (GPIO27)

#define GPIO_O_PORTBPCR28     0x70U     //  GPIO B Pin Control Register    (GPIO28)
#define GPIO_O_PORTBPCR29     0x74U     //  GPIO B Pin Control Register    (GPIO29)
#define GPIO_O_PORTBPCR30     0x78U     //  GPIO B Pin Control Register    (GPIO30)
#define GPIO_O_PORTBPCR31     0x7CU     //  GPIO B Pin Control Register    (GPIO31)

#define GPIO_O_PORTBGPCLR     0x80U     // GPIO B Global Pin Control Low Register   (GPIO0 to GPIO15)
#define GPIO_O_PORTBGPCHR     0x84U     // GPIO B Global Pin Control High Register   (GPIO15 to GPIO31)
#define GPIO_O_PORTBISFR      0xA0U     // GPIO B Interrupt Status Flag Register    (GPIO0 to GPIO31)
#define GPIO_O_PORTBDFER      0xC0U     // GPIO B Digital Filter Enable Register    (GPIO0 to GPIO31)
#define GPIO_O_PORTBDFCR      0xC4U     // GPIO B Digital Filter Clock Register     (GPIO0 to GPIO31)
#define GPIO_O_PORTBDFWR      0xC8U     // GPIO B Digital Filter Width Register     (GPIO0 to GPIO31)




//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PDOR register
//
//*************************************************************************************************
#define GPIO_GPAPDOR_PDO_S          0U
#define GPIO_GPAPDOR_PDO_M          0xFFFFFFFFU         // Port Data Output Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PSOR register
//
//*************************************************************************************************
#define GPIO_GPAPSOR_PTSO_S         0U
#define GPIO_GPAPSOR_PTSO_M         0xFFFFFFFFU         // Port Set Output Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PCOR register
//
//*************************************************************************************************
#define GPIO_GPAPCOR_PTCO_S         0U
#define GPIO_GPAPCOR_PTCO_M         0xFFFFFFFFU         // Port Clear Output Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PTOR register
//
//*************************************************************************************************
#define GPIO_GPAPTOR_PTTO_S         0U
#define GPIO_GPAPTOR_PTTO_M         0xFFFFFFFFU         // Port Toggle Output Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PDIR register
//
//*************************************************************************************************
#define GPIO_GPAPDIR_PDI_S          0U
#define GPIO_GPAPDIR_PDI_M          0xFFFFFFFFU         // Port Data Input Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PDDR register
//
//*************************************************************************************************
#define GPIO_GPAPDDR_PDD_S          0U
#define GPIO_GPAPDDR_PDD_M          0xFFFFFFFFU         // Port Data Direction Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PDOR register
//
//*************************************************************************************************
#define GPIO_GPBPDOR_PDO_S          0U
#define GPIO_GPBPDOR_PDO_M          0xFFFFFFFFU         // Port Data Output Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PSOR register
//
//*************************************************************************************************
#define GPIO_GPBPSOR_PTSO_S          0U
#define GPIO_GPBPSOR_PTSO_M          0xFFFFFFFFU         // Port Set Output Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PCOR register
//
//*************************************************************************************************
#define GPIO_GPBPCOR_PTCO_S         0U
#define GPIO_GPBPCOR_PTCO_M         0xFFFFFFFFU         // Port Clear Output Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PTOR register
//
//*************************************************************************************************
#define GPIO_GPBPTOR_PTTO_S          0U
#define GPIO_GPBPTOR_PTTO_M          0xFFFFFFFFU         // Port Toggle Output Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PDIR register
//
//*************************************************************************************************
#define GPIO_GPBPDIR_PDI_S          0U
#define GPIO_GPBPDIR_PDI_M          0xFFFFFFFFU         // Port Data Input Register for GPIO0 to GPIO31


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PDDR register
//
//*************************************************************************************************
#define GPIO_GPBPDDR_PDD_S          0U
#define GPIO_GPBPDDR_PDD_M          0xFFFFFFFFU         // Port Data Direction Register for GPIO0 to GPIO31


#define GPIO_PORTA_PCRx_PU_S                            (0U)
#define GPIO_PORTA_PCRx_PU_M                            (0x1U)

#define GPIO_PORTA_PCRx_PD_S                            (1U)
#define GPIO_PORTA_PCRx_PD_M                            (0x2U)

#define GPIO_PORTA_PCRx_SRE_S                           (2U)
#define GPIO_PORTA_PCRx_SRE_M                           (0x4U)

#define GPIO_PORTA_PCRx_CSE_S                           (3U)    
#define GPIO_PORTA_PCRx_CSE_M                           (0x08U)

#define GPIO_PORTA_PCRx_IE_S                            (4U)
#define GPIO_PORTA_PCRx_IE_M                            (0x10U)

#define GPIO_PORTA_PCRx_ODE_S                           (5U)
#define GPIO_PORTA_PCRx_ODE_M                           (0x20U)

#define GPIO_PORTA_PCRx_OSE_SH                          (6U)
#define GPIO_PORTA_PCRx_OSE_M                           (0x40U)

#define GPIO_PORTA_PCRx_DRE_S                           (7U)
#define GPIO_PORTA_PCRx_DRE_M                           (0x80U)

#define GPIO_PORTA_PCRx_MUX_S                           (8U)
#define GPIO_PORTA_PCRx_MUX_M                           (0x700U)

#define GPIO_PORTA_PCRx_LK_S                            (15U)
#define GPIO_PORTA_PCRx_LK_M                            (0x8000U)

#define GPIO_PORTA_PCRx_IRQC_S                          (16U)
#define GPIO_PORTA_PCRx_IRQC_M                          (0xF0000U)

#define GPIO_PORTA_PCRx_ISF_S                           (24U)
#define GPIO_PORTA_PCRx_ISF_M                           (0x1000000U)

#define GPIO_PORTA_GPCLR_GPWD_S                         (0U)
#define GPIO_PORTA_GPCLR_GPWD_M                         (0xFFFFU)

#define GPIO_PORTA_GPCLR_GPWE_S                         (16U) 
#define GPIO_PORTA_GPCLR_GPWE_M                         (0xFFFF0000U)

#define GPIO_PORTA_GPCHR_GPWD_S                         (0U)
#define GPIO_PORTA_GPCHR_GPWD_M                         (0xFFFFU)

#define GPIO_PORTA_GPCHR_GPWE_S                         (16U)
#define GPIO_PORTA_GPCHR_GPWE_M                         (0xFFFF0000U)

#define GPIO_PORTA_ISFR_ISF_S                           (0U)
#define GPIO_PORTA_ISFR_ISF_M                           (0xFFFFFFFFU)

#define GPIO_PORTA_DFER_DFE_S                           (0U)
#define GPIO_PORTA_DFER_DFE_M                           (0xFFFFFFFFU)

#define GPIO_PORTA_DFCR_CS_S                            (0U)
#define GPIO_PORTA_DFCR_CS_M                            (0x1U)

#define GPIO_PORTA_DFWR_FILT_S                          (0U)
#define GPIO_PORTA_DFWR_FILT_M                          (0x1FU)


//*************************************************************************************************
//
// The following are defines for the bit fields in the PSOR register
//
//*************************************************************************************************
#define GPIO_GPASET_GPIO0    0x1U          // Output Set bit for this pin
#define GPIO_GPASET_GPIO1    0x2U          // Output Set bit for this pin
#define GPIO_GPASET_GPIO2    0x4U          // Output Set bit for this pin
#define GPIO_GPASET_GPIO3    0x8U          // Output Set bit for this pin
#define GPIO_GPASET_GPIO4    0x10U         // Output Set bit for this pin
#define GPIO_GPASET_GPIO5    0x20U         // Output Set bit for this pin
#define GPIO_GPASET_GPIO6    0x40U         // Output Set bit for this pin
#define GPIO_GPASET_GPIO7    0x80U         // Output Set bit for this pin
#define GPIO_GPASET_GPIO8    0x100U        // Output Set bit for this pin
#define GPIO_GPASET_GPIO9    0x200U        // Output Set bit for this pin
#define GPIO_GPASET_GPIO10   0x400U        // Output Set bit for this pin
#define GPIO_GPASET_GPIO11   0x800U        // Output Set bit for this pin
#define GPIO_GPASET_GPIO12   0x1000U       // Output Set bit for this pin
#define GPIO_GPASET_GPIO13   0x2000U       // Output Set bit for this pin
#define GPIO_GPASET_GPIO14   0x4000U       // Output Set bit for this pin
#define GPIO_GPASET_GPIO15   0x8000U       // Output Set bit for this pin
#define GPIO_GPASET_GPIO16   0x10000U      // Output Set bit for this pin
#define GPIO_GPASET_GPIO17   0x20000U      // Output Set bit for this pin
#define GPIO_GPASET_GPIO18   0x40000U      // Output Set bit for this pin
#define GPIO_GPASET_GPIO19   0x80000U      // Output Set bit for this pin
#define GPIO_GPASET_GPIO20   0x100000U     // Output Set bit for this pin
#define GPIO_GPASET_GPIO21   0x200000U     // Output Set bit for this pin
#define GPIO_GPASET_GPIO22   0x400000U     // Output Set bit for this pin
#define GPIO_GPASET_GPIO23   0x800000U     // Output Set bit for this pin
#define GPIO_GPASET_GPIO24   0x1000000U    // Output Set bit for this pin
#define GPIO_GPASET_GPIO25   0x2000000U    // Output Set bit for this pin
#define GPIO_GPASET_GPIO26   0x4000000U    // Output Set bit for this pin
#define GPIO_GPASET_GPIO27   0x8000000U    // Output Set bit for this pin
#define GPIO_GPASET_GPIO28   0x10000000U   // Output Set bit for this pin
#define GPIO_GPASET_GPIO29   0x20000000U   // Output Set bit for this pin
#define GPIO_GPASET_GPIO30   0x40000000U   // Output Set bit for this pin
#define GPIO_GPASET_GPIO31   0x80000000U   // Output Set bit for this pin 



//*************************************************************************************************
//
// The following are defines for the bit fields in the PDOR register
//
//*************************************************************************************************
#define GPIO_GPADAT_GPIO0    0x1U          // Data Register for this pin
#define GPIO_GPADAT_GPIO1    0x2U          // Data Register for this pin
#define GPIO_GPADAT_GPIO2    0x4U          // Data Register for this pin
#define GPIO_GPADAT_GPIO3    0x8U          // Data Register for this pin
#define GPIO_GPADAT_GPIO4    0x10U         // Data Register for this pin
#define GPIO_GPADAT_GPIO5    0x20U         // Data Register for this pin
#define GPIO_GPADAT_GPIO6    0x40U         // Data Register for this pin
#define GPIO_GPADAT_GPIO7    0x80U         // Data Register for this pin
#define GPIO_GPADAT_GPIO8    0x100U        // Data Register for this pin
#define GPIO_GPADAT_GPIO9    0x200U        // Data Register for this pin
#define GPIO_GPADAT_GPIO10   0x400U        // Data Register for this pin
#define GPIO_GPADAT_GPIO11   0x800U        // Data Register for this pin
#define GPIO_GPADAT_GPIO12   0x1000U       // Data Register for this pin
#define GPIO_GPADAT_GPIO13   0x2000U       // Data Register for this pin
#define GPIO_GPADAT_GPIO14   0x4000U       // Data Register for this pin
#define GPIO_GPADAT_GPIO15   0x8000U       // Data Register for this pin
#define GPIO_GPADAT_GPIO16   0x10000U      // Data Register for this pin
#define GPIO_GPADAT_GPIO17   0x20000U      // Data Register for this pin
#define GPIO_GPADAT_GPIO18   0x40000U      // Data Register for this pin
#define GPIO_GPADAT_GPIO19   0x80000U      // Data Register for this pin
#define GPIO_GPADAT_GPIO20   0x100000U     // Data Register for this pin
#define GPIO_GPADAT_GPIO21   0x200000U     // Data Register for this pin
#define GPIO_GPADAT_GPIO22   0x400000U     // Data Register for this pin
#define GPIO_GPADAT_GPIO23   0x800000U     // Data Register for this pin
#define GPIO_GPADAT_GPIO24   0x1000000U    // Data Register for this pin
#define GPIO_GPADAT_GPIO25   0x2000000U    // Data Register for this pin
#define GPIO_GPADAT_GPIO26   0x4000000U    // Data Register for this pin
#define GPIO_GPADAT_GPIO27   0x8000000U    // Data Register for this pin
#define GPIO_GPADAT_GPIO28   0x10000000U   // Data Register for this pin
#define GPIO_GPADAT_GPIO29   0x20000000U   // Data Register for this pin
#define GPIO_GPADAT_GPIO30   0x40000000U   // Data Register for this pin
#define GPIO_GPADAT_GPIO31   0x80000000U   // Data Register for this pin




//*************************************************************************************************
//
// The following are defines for the bit fields in the PCOR register
//
//*************************************************************************************************
#define GPIO_GPACLEAR_GPIO0    0x1U          // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO1    0x2U          // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO2    0x4U          // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO3    0x8U          // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO4    0x10U         // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO5    0x20U         // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO6    0x40U         // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO7    0x80U         // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO8    0x100U        // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO9    0x200U        // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO10   0x400U        // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO11   0x800U        // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO12   0x1000U       // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO13   0x2000U       // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO14   0x4000U       // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO15   0x8000U       // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO16   0x10000U      // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO17   0x20000U      // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO18   0x40000U      // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO19   0x80000U      // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO20   0x100000U     // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO21   0x200000U     // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO22   0x400000U     // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO23   0x800000U     // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO24   0x1000000U    // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO25   0x2000000U    // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO26   0x4000000U    // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO27   0x8000000U    // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO28   0x10000000U   // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO29   0x20000000U   // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO30   0x40000000U   // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO31   0x80000000U   // Output Clear bit for this pin



//*************************************************************************************************
//
// The following are defines for the bit fields in the PTOR register
//
//*************************************************************************************************
#define GPIO_GPATOGGLE_GPIO0    0x1U          // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO1    0x2U          // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO2    0x4U          // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO3    0x8U          // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO4    0x10U         // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO5    0x20U         // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO6    0x40U         // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO7    0x80U         // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO8    0x100U        // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO9    0x200U        // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO10   0x400U        // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO11   0x800U        // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO12   0x1000U       // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO13   0x2000U       // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO14   0x4000U       // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO15   0x8000U       // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO16   0x10000U      // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO17   0x20000U      // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO18   0x40000U      // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO19   0x80000U      // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO20   0x100000U     // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO21   0x200000U     // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO22   0x400000U     // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO23   0x800000U     // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO24   0x1000000U    // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO25   0x2000000U    // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO26   0x4000000U    // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO27   0x8000000U    // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO28   0x10000000U   // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO29   0x20000000U   // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO30   0x40000000U   // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO31   0x80000000U   // Output Toggle bit for this pin


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PDDR register
//
//*************************************************************************************************
#define GPIO_GPADIR_GPIO0    0x1U          // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO1    0x2U          // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO2    0x4U          // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO3    0x8U          // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO4    0x10U         // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO5    0x20U         // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO6    0x40U         // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO7    0x80U         // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO8    0x100U        // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO9    0x200U        // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO10   0x400U        // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO11   0x800U        // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO12   0x1000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO13   0x2000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO14   0x4000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO15   0x8000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO16   0x10000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO17   0x20000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO18   0x40000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO19   0x80000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO20   0x100000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO21   0x200000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO22   0x400000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO23   0x800000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO24   0x1000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO25   0x2000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO26   0x4000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO27   0x8000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO28   0x10000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO29   0x20000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO30   0x40000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO31   0x80000000U   // Defines direction for this pin in GPIO mode //OK**






//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn PU bit register
//
//*************************************************************************************************
#define GPIO_GPAPU_GPIO0    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO1    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO2    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO3    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO4    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO5    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO6    0x1U             // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO7    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO8    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO9    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO10   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO11   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO12   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO13   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO14   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO15   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO16   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO17   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO18   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO19   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO20   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO21   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO22   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO23   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO24   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO25   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO26   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO27   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO28   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO29   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO30   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPAPU_GPIO31   0x1U            // Pull-Up enable control for this pin 



//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn PD bit register
//
//*************************************************************************************************
#define GPIO_GPAPD_GPIO0    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO1    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO2    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO3    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO4    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO5    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO6    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO7    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO8    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO9    0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO10   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO11   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO12   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO13   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO14   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO15   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO16   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO17   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO18   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO19   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO20   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO21   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO22   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO23   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO24   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO25   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO26   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO27   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO28   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO29   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO30   0x2U            // Pull-down enable control for this pin
#define GPIO_GPAPD_GPIO31   0x2U            // Pull-down enable control for this pin 



//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn SRE bit register
//
//*************************************************************************************************
#define GPIO_GPASRE_GPIO0    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO1    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO2    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO3    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO4    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO5    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO6    0x4U            // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO7    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO8    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO9    0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO10   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO11   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO12   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO13   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO14   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO15   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO16   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO17   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO18   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO19   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO20   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO21   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO22   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO23   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO24   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO25   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO26   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO27   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO28   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO29   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO30   0x4U           // Slew rate enable for this pin
#define GPIO_GPASRE_GPIO31   0x4U           // Slew rate enable for this pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn CSE bit register
//
//*************************************************************************************************
#define GPIO_GPACSE_GPIO0    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO1    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO2    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO3    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO4    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO5    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO6    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO7    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO8    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO9    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO10   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO11   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO12   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO13   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO14   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO15   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO16   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO17   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO18   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO19   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO20   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO21   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO22   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO23   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO24   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO25   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO26   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO27   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO28   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO29   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO30   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPACSE_GPIO31   0x8U           // Input Schmitt trig enable for this pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn IE bit register
//
//*************************************************************************************************
#define GPIO_GPAIE_GPIO0    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO1    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO2    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO3    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO4    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO5    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO6    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO7    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO8    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO9    0x10U           // Input Enable
#define GPIO_GPAIE_GPIO10   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO11   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO12   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO13   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO14   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO15   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO16   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO17   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO18   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO19   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO20   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO21   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO22   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO23   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO24   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO25   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO26   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO27   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO28   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO29   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO30   0x10U           // Input Enable
#define GPIO_GPAIE_GPIO31   0x10U           // Input Enable 


//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTA_PCRn ODE bit register
//
//*************************************************************************************************
#define GPIO_GPAODR_GPIO0    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO1    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO2    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO3    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO4    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO5    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO6    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO7    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO8    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO9    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO10   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO11   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO12   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO13   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO14   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO15   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO16   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO17   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO18   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO19   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO20   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO21   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO22   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO23   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO24   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO25   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO26   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO27   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO28   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO29   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO30   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPAODR_GPIO31   0x20U          // Outpout Open-Drain control for this pin 




//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTA_PCRn OSE bit register
//
//*************************************************************************************************
#define GPIO_GPAOSE_GPIO0    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO1    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO2    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO3    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO4    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO5    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO6    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO7    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO8    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO9    0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO10   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO11   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO12   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO13   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO14   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO15   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO16   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO17   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO18   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO19   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO20   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO21   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO22   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO23   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO24   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO25   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO26   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO27   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO28   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO29   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO30   0x40U          // Open Source Enable for this pin
#define GPIO_GPAOSE_GPIO31   0x40U          // Open Source Enable for this pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTA_PCRn DRE bit register
//
//*************************************************************************************************
#define GPIO_GPADRE_GPIO0    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO1    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO2    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO3    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO4    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO5    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO6    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO7    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO8    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO9    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO10   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO11   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO12   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO13   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO14   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO15   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO16   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO17   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO18   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO19   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO20   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO21   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO22   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO23   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO24   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO25   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO26   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO27   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO28   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO29   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO30   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPADRE_GPIO31   0x80U          // Drive Strength Enable for this pin 

//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTA_PCRn MUX bit register
//
//*************************************************************************************************

#define GPIO_GPAMUX_GPIOx(x)   (x<<8)U             // Lock Register for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTA_PCRn LK bit register
//
//*************************************************************************************************
#define GPIO_GPALK_GPIO0    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO1    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO2    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO3    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO4    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO5    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO6    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO7    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO8    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO9    0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO10   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO11   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO12   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO13   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO14   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO15   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO16   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO17   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO18   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO19   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO20   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO21   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO22   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO23   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO24   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO25   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO26   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO27   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO28   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO29   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO30   0x8000U             // Lock Register for this pin
#define GPIO_GPALK_GPIO31   0x8000U             // Lock Register for this pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTA_PCRn IRQC bit register
//
//*************************************************************************************************

#define GPIO_GPAIRQC_GPIOx(x)   (x<<8)U             // Lock Register for this pin


//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTA_PCRn ISF bit register
//
//*************************************************************************************************

#define GPIO_GPAISF_GPIOx   0x1000000U             // Interrupt status flag




//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn GPCLR bit register
//
//*************************************************************************************************


#define GPIO_PORTAGPCLR_GPOWD_GPIO0     0x1U          // Global Pin Write Data for pin0
#define GPIO_PORTAGPCLR_GPOWD_GPIO1     0x2U          //  Global Pin Write Data for for pin1
#define GPIO_PORTAGPCLR_GPOWD_GPIO2     0x4U          //  Global Pin Write Data for for pin2
#define GPIO_PORTAGPCLR_GPOWD_GPIO3     0x8U          //  Global Pin Write Data for for pin3
#define GPIO_PORTAGPCLR_GPOWD_GPIO4     0x10U         //  Global Pin Write Data for for pin4
#define GPIO_PORTAGPCLR_GPOWD_GPIO5     0x20U         //  Global Pin Write Data for for pin5
#define GPIO_PORTAGPCLR_GPOWD_GPIO6     0x40U         //  Global Pin Write Data for for pin6
#define GPIO_PORTAGPCLR_GPOWD_GPIO7     0x80U         //  Global Pin Write Data for for pin7
#define GPIO_PORTAGPCLR_GPOWD_GPIO8     0x100U        //  Global Pin Write Data for for pin8
#define GPIO_PORTAGPCLR_GPOWD_GPIO9     0x200U        //  Global Pin Write Data for for pin9
#define GPIO_PORTAGPCLR_GPOWD_GPIO10    0x400U        //  Global Pin Write Data for for pin10
#define GPIO_PORTAGPCLR_GPOWD_GPIO11    0x800U        //  Global Pin Write Data for for pin11
#define GPIO_PORTAGPCLR_GPOWD_GPIO12    0x1000U       //  Global Pin Write Data for for pin12
#define GPIO_PORTAGPCLR_GPOWD_GPIO13    0x2000U       //  Global Pin Write Data for for pin13
#define GPIO_PORTAGPCLR_GPOWD_GPIO14    0x4000U       //  Global Pin Write Data for for pin14
#define GPIO_PORTAGPCLR_GPOWD_GPIO15    0x8000U       //  Global Pin Write Data for for pin15
#define GPIO_PORTAGPCLR_GPOWE_GPIO0     0x10000U      // Global Pin Write Enable for pin0
#define GPIO_PORTAGPCLR_GPOWE_GPIO1     0x20000U      // Global Pin Write Enable for pin1
#define GPIO_PORTAGPCLR_GPOWE_GPIO2     0x40000U      // Global Pin Write Enable for pin2
#define GPIO_PORTAGPCLR_GPOWE_GPIO3     0x80000U      // Global Pin Write Enable for pin3
#define GPIO_PORTAGPCLR_GPOWE_GPIO4     0x100000U     // Global Pin Write Enable for pin4
#define GPIO_PORTAGPCLR_GPOWE_GPIO5     0x200000U     // Global Pin Write Enable for pin5
#define GPIO_PORTAGPCLR_GPOWE_GPIO6     0x400000U     // Global Pin Write Enable for pin6
#define GPIO_PORTAGPCLR_GPOWE_GPIO7     0x800000U     // Global Pin Write Enable for pin7
#define GPIO_PORTAGPCLR_GPOWE_GPIO8     0x1000000U    // Global Pin Write Enable for pin8
#define GPIO_PORTAGPCLR_GPOWE_GPIO9     0x2000000U    // Global Pin Write Enable for pin9
#define GPIO_PORTAGPCLR_GPOWE_GPIO10    0x4000000U    // Global Pin Write Enable for pin10
#define GPIO_PORTAGPCLR_GPOWE_GPIO11    0x8000000U    // Global Pin Write Enable for pin11
#define GPIO_PORTAGPCLR_GPOWE_GPIO12    0x10000000U   // Global Pin Write Enable for pin12
#define GPIO_PORTAGPCLR_GPOWE_GPIO13    0x20000000U   // Global Pin Write Enable for pin13
#define GPIO_PORTAGPCLR_GPOWE_GPIO14    0x40000000U   // Global Pin Write Enable for pin14
#define GPIO_PORTAGPCLR_GPOWE_GPIO15    0x80000000U   // Global Pin Write Enable for pin15 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn GPCHR bit register
//
//*************************************************************************************************

#define GPIO_PORTAGPCHR_GPOWD_GPIO16    0x1U          // Global Pin Write Data for pin16
#define GPIO_PORTAGPCHR_GPOWD_GPIO17    0x2U          //  Global Pin Write Data for for pin17
#define GPIO_PORTAGPCHR_GPOWD_GPIO18    0x4U          //  Global Pin Write Data for for pin18
#define GPIO_PORTAGPCHR_GPOWD_GPIO19    0x8U          //  Global Pin Write Data for for pin19
#define GPIO_PORTAGPCHR_GPOWD_GPIO20    0x10U         //  Global Pin Write Data for for pin20
#define GPIO_PORTAGPCHR_GPOWD_GPIO21    0x20U         //  Global Pin Write Data for for pin21
#define GPIO_PORTAGPCHR_GPOWD_GPIO22    0x40U         //  Global Pin Write Data for for pin22
#define GPIO_PORTAGPCHR_GPOWD_GPIO23    0x80U         //  Global Pin Write Data for for pin23
#define GPIO_PORTAGPCHR_GPOWD_GPIO24    0x100U        //  Global Pin Write Data for for pin24
#define GPIO_PORTAGPCHR_GPOWD_GPIO25    0x200U        //  Global Pin Write Data for for pin25
#define GPIO_PORTAGPCHR_GPOWD_GPIO26    0x400U        //  Global Pin Write Data for for pin26
#define GPIO_PORTAGPCHR_GPOWD_GPIO27    0x800U        //  Global Pin Write Data for for pin27
#define GPIO_PORTAGPCHR_GPOWD_GPIO28    0x1000U       //  Global Pin Write Data for for pin28
#define GPIO_PORTAGPCHR_GPOWD_GPIO29    0x2000U       //  Global Pin Write Data for for pin29
#define GPIO_PORTAGPCHR_GPOWD_GPIO30    0x4000U       //  Global Pin Write Data for for pin30
#define GPIO_PORTAGPCHR_GPOWD_GPIO31    0x8000U       //  Global Pin Write Data for for pin31
#define GPIO_PORTAGPCHR_GPOWE_GPIO16    0x10000U      // Global Pin Write Enable for pin16
#define GPIO_PORTAGPCHR_GPOWE_GPIO17    0x20000U      // Global Pin Write Enable for pin17
#define GPIO_PORTAGPCHR_GPOWE_GPIO18    0x40000U      // Global Pin Write Enable for pin18
#define GPIO_PORTAGPCHR_GPOWE_GPIO19    0x80000U      // Global Pin Write Enable for pin19
#define GPIO_PORTAGPCHR_GPOWE_GPIO20    0x100000U     // Global Pin Write Enable for pin20
#define GPIO_PORTAGPCHR_GPOWE_GPIO21    0x200000U     // Global Pin Write Enable for pin21
#define GPIO_PORTAGPCHR_GPOWE_GPIO22    0x400000U     // Global Pin Write Enable for pin22
#define GPIO_PORTAGPCHR_GPOWE_GPIO23    0x800000U     // Global Pin Write Enable for pin23
#define GPIO_PORTAGPCHR_GPOWE_GPIO24    0x1000000U    // Global Pin Write Enable for pin24
#define GPIO_PORTAGPCHR_GPOWE_GPIO25    0x2000000U    // Global Pin Write Enable for pin25
#define GPIO_PORTAGPCHR_GPOWE_GPIO26    0x4000000U    // Global Pin Write Enable for pin26
#define GPIO_PORTAGPCHR_GPOWE_GPIO27    0x8000000U    // Global Pin Write Enable for pin27
#define GPIO_PORTAGPCHR_GPOWE_GPIO28    0x10000000U   // Global Pin Write Enable for pin28
#define GPIO_PORTAGPCHR_GPOWE_GPIO29    0x20000000U   // Global Pin Write Enable for pin29
#define GPIO_PORTAGPCHR_GPOWE_GPIO30    0x40000000U   // Global Pin Write Enable for pin30
#define GPIO_PORTAGPCHR_GPOWE_GPIO31    0x80000000U   // Global Pin Write Enable for pin31 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn ISFR bit register
//
//*************************************************************************************************

#define GPIO_PORTAISF_ISF_GPIO0    0x1U          // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO1    0x2U          // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO2    0x4U          // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO3    0x8U          // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO4    0x10U         // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO5    0x20U         // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO6    0x40U         // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO7    0x80U         // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO8    0x100U        // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO9    0x200U        // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO10   0x400U        // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO11   0x800U        // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO12   0x1000U       // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO13   0x2000U       // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO14   0x4000U       // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO15   0x8000U       // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO16   0x10000U      // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO17   0x20000U      // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO18   0x40000U      // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO19   0x80000U      // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO20   0x100000U     // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO21   0x200000U     // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO22   0x400000U     // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO23   0x800000U     // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO24   0x1000000U    // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO25   0x2000000U    // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO26   0x4000000U    // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO27   0x8000000U    // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO28   0x10000000U   // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO29   0x20000000U   // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO30   0x40000000U   // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTAISF_ISF_GPIO31   0x80000000U   // write 1 clear Interrupt Status Flag for pin //OK**


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn DFER bit register
//
//*************************************************************************************************

#define GPIO_PORTADFE_DEF_GPIO0    0x1U          // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO1    0x2U          // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO2    0x4U          // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO3    0x8U          // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO4    0x10U         // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO5    0x20U         // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO6    0x40U         // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO7    0x80U         // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO8    0x100U        // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO9    0x200U        // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO10   0x400U        // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO11   0x800U        // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO12   0x1000U       // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO13   0x2000U       // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO14   0x4000U       // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO15   0x8000U       // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO16   0x10000U      // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO17   0x20000U      // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO18   0x40000U      // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO19   0x80000U      // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO20   0x100000U     // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO21   0x200000U     // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO22   0x400000U     // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO23   0x800000U     // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO24   0x1000000U    // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO25   0x2000000U    // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO26   0x4000000U    // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO27   0x8000000U    // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO28   0x10000000U   // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO29   0x20000000U   // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO30   0x40000000U   // Digital Filter Enable for pin
#define GPIO_PORTADFE_DEF_GPIO31   0x80000000U   // Digital Filter Enable for pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn DFCR bit register
//
//*************************************************************************************************
#define GPIO_PORTADFCR_CS_GPIO    0x1U          // sclect Clock Source for PORTA((1-LOP,0-bus))

//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTA_PCRn DFWR bit register
//
//*************************************************************************************************
#define GPIO_PORTADFWR_FLIT_GPIO(x)    (x)          // sclect Filter Length for PORTA

#define GPIO_PORTB_PCRx_PU_S                            (0U)
#define GPIO_PORTB_PCRx_PU_M                            (0x1U)

#define GPIO_PORTB_PCRx_PD_S                            (1U)
#define GPIO_PORTB_PCRx_PD_M                            (0x2U)

#define GPIO_PORTB_PCRx_SRE_S                           (2U)
#define GPIO_PORTB_PCRx_SRE_M                           (0x4U)

#define GPIO_PORTB_PCRx_CSE_S                           (3U)    
#define GPIO_PORTB_PCRx_CSE_M                           (0x08U)

#define GPIO_PORTB_PCRx_IE_S                            (4U)
#define GPIO_PORTB_PCRx_IE_M                            (0x10U)

#define GPIO_PORTB_PCRx_ODE_S                           (5U)
#define GPIO_PORTB_PCRx_ODE_M                           (0x20U)

#define GPIO_PORTB_PCRx_OSE_SH                          (6U)
#define GPIO_PORTB_PCRx_OSE_M                           (0x40U)

#define GPIO_PORTB_PCRx_DRE_S                           (7U)
#define GPIO_PORTB_PCRx_DRE_M                           (0x80U)

#define GPIO_PORTB_PCRx_MUX_S                           (8U)
#define GPIO_PORTB_PCRx_MUX_M                           (0x700U)

#define GPIO_PORTB_PCRx_LK_S                            (15U)
#define GPIO_PORTB_PCRx_LK_M                            (0x8000U)

#define GPIO_PORTB_PCRx_IRQC_S                          (16U)
#define GPIO_PORTB_PCRx_IRQC_M                          (0xF0000U)

#define GPIO_PORTB_PCRx_ISF_S                           (24U)
#define GPIO_PORTB_PCRx_ISF_M                           (0x1000000U)

#define GPIO_PORTB_GPCLR_GPWD_S                         (0U)
#define GPIO_PORTB_GPCLR_GPWD_M                         (0xFFFFU)

#define GPIO_PORTB_GPCLR_GPWE_S                         (16U) 
#define GPIO_PORTB_GPCLR_GPWE_M                         (0xFFFF0000U)

#define GPIO_PORTB_GPCHR_GPWD_S                         (0U)
#define GPIO_PORTB_GPCHR_GPWD_M                         (0xFFFFU)

#define GPIO_PORTB_GPCHR_GPWE_S                         (16U)
#define GPIO_PORTB_GPCHR_GPWE_M                         (0xFFFF0000U)

#define GPIO_PORTB_ISFR_ISF_S                           (0U)
#define GPIO_PORTB_ISFR_ISF_M                           (0xFFFFFFFFU)

#define GPIO_PORTB_DFER_DFE_S                           (0U)
#define GPIO_PORTB_DFER_DFE_M                           (0xFFFFFFFFU)

#define GPIO_PORTB_DFCR_CS_S                            (0U)
#define GPIO_PORTB_DFCR_CS_M                            (0x1U)

#define GPIO_PORTB_DFWR_FILT_S                          (0U)
#define GPIO_PORTB_DFWR_FILT_M                          (0x1FU)


//*************************************************************************************************
//
// The following are defines for the bit fields in the PSOR register
//
//*************************************************************************************************
#define GPIO_GPBSET_GPIO0    0x1U          // Output Set bit for this pin
#define GPIO_GPBSET_GPIO1    0x2U          // Output Set bit for this pin
#define GPIO_GPBSET_GPIO2    0x4U          // Output Set bit for this pin
#define GPIO_GPBSET_GPIO3    0x8U          // Output Set bit for this pin
#define GPIO_GPBSET_GPIO4    0x10U         // Output Set bit for this pin
#define GPIO_GPBSET_GPIO5    0x20U         // Output Set bit for this pin
#define GPIO_GPBSET_GPIO6    0x40U         // Output Set bit for this pin
#define GPIO_GPBSET_GPIO7    0x80U         // Output Set bit for this pin
#define GPIO_GPBSET_GPIO8    0x100U        // Output Set bit for this pin
#define GPIO_GPBSET_GPIO9    0x200U        // Output Set bit for this pin
#define GPIO_GPBSET_GPIO10   0x400U        // Output Set bit for this pin
#define GPIO_GPBSET_GPIO11   0x800U        // Output Set bit for this pin
#define GPIO_GPBSET_GPIO12   0x1000U       // Output Set bit for this pin
#define GPIO_GPBSET_GPIO13   0x2000U       // Output Set bit for this pin
#define GPIO_GPBSET_GPIO14   0x4000U       // Output Set bit for this pin
#define GPIO_GPBSET_GPIO15   0x8000U       // Output Set bit for this pin
#define GPIO_GPBSET_GPIO16   0x10000U      // Output Set bit for this pin
#define GPIO_GPBSET_GPIO17   0x20000U      // Output Set bit for this pin
#define GPIO_GPBSET_GPIO18   0x40000U      // Output Set bit for this pin
#define GPIO_GPBSET_GPIO19   0x80000U      // Output Set bit for this pin
#define GPIO_GPBSET_GPIO20   0x100000U     // Output Set bit for this pin
#define GPIO_GPBSET_GPIO21   0x200000U     // Output Set bit for this pin
#define GPIO_GPBSET_GPIO22   0x400000U     // Output Set bit for this pin
#define GPIO_GPBSET_GPIO23   0x800000U     // Output Set bit for this pin
#define GPIO_GPBSET_GPIO24   0x1000000U    // Output Set bit for this pin
#define GPIO_GPBSET_GPIO25   0x2000000U    // Output Set bit for this pin
#define GPIO_GPBSET_GPIO26   0x4000000U    // Output Set bit for this pin
#define GPIO_GPBSET_GPIO27   0x8000000U    // Output Set bit for this pin
#define GPIO_GPBSET_GPIO28   0x10000000U   // Output Set bit for this pin
#define GPIO_GPBSET_GPIO29   0x20000000U   // Output Set bit for this pin
#define GPIO_GPBSET_GPIO30   0x40000000U   // Output Set bit for this pin
#define GPIO_GPBSET_GPIO31   0x80000000U   // Output Set bit for this pin 



//*************************************************************************************************
//
// The following are defines for the bit fields in the PDOR register
//
//*************************************************************************************************
#define GPIO_GPBDAT_GPIO0    0x1U          // Data Register for this pin
#define GPIO_GPBDAT_GPIO1    0x2U          // Data Register for this pin
#define GPIO_GPBDAT_GPIO2    0x4U          // Data Register for this pin
#define GPIO_GPBDAT_GPIO3    0x8U          // Data Register for this pin
#define GPIO_GPBDAT_GPIO4    0x10U         // Data Register for this pin
#define GPIO_GPBDAT_GPIO5    0x20U         // Data Register for this pin
#define GPIO_GPBDAT_GPIO6    0x40U         // Data Register for this pin
#define GPIO_GPBDAT_GPIO7    0x80U         // Data Register for this pin
#define GPIO_GPBDAT_GPIO8    0x100U        // Data Register for this pin
#define GPIO_GPBDAT_GPIO9    0x200U        // Data Register for this pin
#define GPIO_GPBDAT_GPIO10   0x400U        // Data Register for this pin
#define GPIO_GPBDAT_GPIO11   0x800U        // Data Register for this pin
#define GPIO_GPBDAT_GPIO12   0x1000U       // Data Register for this pin
#define GPIO_GPBDAT_GPIO13   0x2000U       // Data Register for this pin
#define GPIO_GPBDAT_GPIO14   0x4000U       // Data Register for this pin
#define GPIO_GPBDAT_GPIO15   0x8000U       // Data Register for this pin
#define GPIO_GPBDAT_GPIO16   0x10000U      // Data Register for this pin
#define GPIO_GPBDAT_GPIO17   0x20000U      // Data Register for this pin
#define GPIO_GPBDAT_GPIO18   0x40000U      // Data Register for this pin
#define GPIO_GPBDAT_GPIO19   0x80000U      // Data Register for this pin
#define GPIO_GPBDAT_GPIO20   0x100000U     // Data Register for this pin
#define GPIO_GPBDAT_GPIO21   0x200000U     // Data Register for this pin
#define GPIO_GPBDAT_GPIO22   0x400000U     // Data Register for this pin
#define GPIO_GPBDAT_GPIO23   0x800000U     // Data Register for this pin
#define GPIO_GPBDAT_GPIO24   0x1000000U    // Data Register for this pin
#define GPIO_GPBDAT_GPIO25   0x2000000U    // Data Register for this pin
#define GPIO_GPBDAT_GPIO26   0x4000000U    // Data Register for this pin
#define GPIO_GPBDAT_GPIO27   0x8000000U    // Data Register for this pin
#define GPIO_GPBDAT_GPIO28   0x10000000U   // Data Register for this pin
#define GPIO_GPBDAT_GPIO29   0x20000000U   // Data Register for this pin
#define GPIO_GPBDAT_GPIO30   0x40000000U   // Data Register for this pin
#define GPIO_GPBDAT_GPIO31   0x80000000U   // Data Register for this pin




//*************************************************************************************************
//
// The following are defines for the bit fields in the PCOR register
//
//*************************************************************************************************
#define GPIO_GPBCLEAR_GPIO0    0x1U          // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO1    0x2U          // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO2    0x4U          // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO3    0x8U          // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO4    0x10U         // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO5    0x20U         // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO6    0x40U         // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO7    0x80U         // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO8    0x100U        // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO9    0x200U        // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO10   0x400U        // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO11   0x800U        // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO12   0x1000U       // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO13   0x2000U       // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO14   0x4000U       // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO15   0x8000U       // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO16   0x10000U      // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO17   0x20000U      // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO18   0x40000U      // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO19   0x80000U      // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO20   0x100000U     // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO21   0x200000U     // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO22   0x400000U     // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO23   0x800000U     // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO24   0x1000000U    // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO25   0x2000000U    // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO26   0x4000000U    // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO27   0x8000000U    // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO28   0x10000000U   // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO29   0x20000000U   // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO30   0x40000000U   // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO31   0x80000000U   // Output Clear bit for this pin



//*************************************************************************************************
//
// The following are defines for the bit fields in the PTOR register
//
//*************************************************************************************************
#define GPIO_GPBTOGGLE_GPIO0    0x1U          // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO1    0x2U          // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO2    0x4U          // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO3    0x8U          // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO4    0x10U         // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO5    0x20U         // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO6    0x40U         // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO7    0x80U         // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO8    0x100U        // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO9    0x200U        // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO10   0x400U        // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO11   0x800U        // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO12   0x1000U       // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO13   0x2000U       // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO14   0x4000U       // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO15   0x8000U       // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO16   0x10000U      // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO17   0x20000U      // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO18   0x40000U      // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO19   0x80000U      // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO20   0x100000U     // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO21   0x200000U     // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO22   0x400000U     // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO23   0x800000U     // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO24   0x1000000U    // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO25   0x2000000U    // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO26   0x4000000U    // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO27   0x8000000U    // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO28   0x10000000U   // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO29   0x20000000U   // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO30   0x40000000U   // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO31   0x80000000U   // Output Toggle bit for this pin


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOA_PDDR register
//
//*************************************************************************************************
#define GPIO_GPBDIR_GPIO0    0x1U          // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO1    0x2U          // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO2    0x4U          // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO3    0x8U          // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO4    0x10U         // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO5    0x20U         // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO6    0x40U         // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO7    0x80U         // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO8    0x100U        // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO9    0x200U        // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO10   0x400U        // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO11   0x800U        // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO12   0x1000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO13   0x2000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO14   0x4000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO15   0x8000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO16   0x10000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO17   0x20000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO18   0x40000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO19   0x80000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO20   0x100000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO21   0x200000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO22   0x400000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO23   0x800000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO24   0x1000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO25   0x2000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO26   0x4000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO27   0x8000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO28   0x10000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO29   0x20000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO30   0x40000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO31   0x80000000U   // Defines direction for this pin in GPIO mode //OK**






//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn PU bit register
//
//*************************************************************************************************
#define GPIO_GPBPU_GPIO0    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO1    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO2    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO3    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO4    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO5    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO6    0x1U             // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO7    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO8    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO9    0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO10   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO11   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO12   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO13   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO14   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO15   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO16   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO17   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO18   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO19   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO20   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO21   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO22   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO23   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO24   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO25   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO26   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO27   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO28   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO29   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO30   0x1U            // Pull-Up enable control for this pin
#define GPIO_GPBPU_GPIO31   0x1U            // Pull-Up enable control for this pin 



//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn PD bit register
//
//*************************************************************************************************
#define GPIO_GPBPD_GPIO0    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO1    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO2    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO3    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO4    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO5    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO6    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO7    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO8    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO9    0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO10   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO11   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO12   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO13   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO14   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO15   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO16   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO17   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO18   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO19   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO20   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO21   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO22   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO23   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO24   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO25   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO26   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO27   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO28   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO29   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO30   0x2U            // Pull-down enable control for this pin
#define GPIO_GPBPD_GPIO31   0x2U            // Pull-down enable control for this pin 



//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn SRE bit register
//
//*************************************************************************************************
#define GPIO_GPBSRE_GPIO0    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO1    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO2    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO3    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO4    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO5    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO6    0x4U            // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO7    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO8    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO9    0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO10   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO11   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO12   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO13   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO14   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO15   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO16   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO17   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO18   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO19   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO20   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO21   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO22   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO23   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO24   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO25   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO26   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO27   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO28   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO29   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO30   0x4U           // Slew rate enable for this pin
#define GPIO_GPBSRE_GPIO31   0x4U           // Slew rate enable for this pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn CSE bit register
//
//*************************************************************************************************
#define GPIO_GPBCSE_GPIO0    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO1    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO2    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO3    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO4    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO5    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO6    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO7    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO8    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO9    0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO10   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO11   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO12   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO13   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO14   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO15   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO16   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO17   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO18   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO19   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO20   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO21   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO22   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO23   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO24   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO25   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO26   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO27   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO28   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO29   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO30   0x8U           // Input Schmitt trig enable for this pin
#define GPIO_GPBCSE_GPIO31   0x8U           // Input Schmitt trig enable for this pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn IE bit register
//
//*************************************************************************************************
#define GPIO_GPBIE_GPIO0    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO1    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO2    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO3    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO4    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO5    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO6    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO7    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO8    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO9    0x10U           // Input Enable
#define GPIO_GPBIE_GPIO10   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO11   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO12   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO13   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO14   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO15   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO16   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO17   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO18   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO19   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO20   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO21   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO22   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO23   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO24   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO25   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO26   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO27   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO28   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO29   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO30   0x10U           // Input Enable
#define GPIO_GPBIE_GPIO31   0x10U           // Input Enable 


//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTB_PCRn ODE bit register
//
//*************************************************************************************************
#define GPIO_GPBODR_GPIO0    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO1    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO2    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO3    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO4    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO5    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO6    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO7    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO8    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO9    0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO10   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO11   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO12   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO13   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO14   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO15   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO16   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO17   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO18   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO19   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO20   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO21   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO22   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO23   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO24   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO25   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO26   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO27   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO28   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO29   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO30   0x20U          // Outpout Open-Drain control for this pin
#define GPIO_GPBODR_GPIO31   0x20U          // Outpout Open-Drain control for this pin 




//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTB_PCRn OSE bit register
//
//*************************************************************************************************
#define GPIO_GPBOSE_GPIO0    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO1    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO2    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO3    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO4    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO5    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO6    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO7    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO8    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO9    0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO10   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO11   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO12   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO13   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO14   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO15   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO16   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO17   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO18   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO19   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO20   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO21   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO22   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO23   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO24   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO25   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO26   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO27   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO28   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO29   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO30   0x40U          // Open Source Enable for this pin
#define GPIO_GPBOSE_GPIO31   0x40U          // Open Source Enable for this pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTB_PCRn DRE bit register
//
//*************************************************************************************************
#define GPIO_GPBDRE_GPIO0    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO1    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO2    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO3    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO4    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO5    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO6    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO7    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO8    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO9    0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO10   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO11   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO12   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO13   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO14   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO15   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO16   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO17   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO18   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO19   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO20   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO21   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO22   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO23   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO24   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO25   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO26   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO27   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO28   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO29   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO30   0x80U          // Drive Strength Enable for this pin
#define GPIO_GPBDRE_GPIO31   0x80U          // Drive Strength Enable for this pin 

//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTB_PCRn MUX bit register
//
//*************************************************************************************************

#define GPIO_GPBMUX_GPIOx(x)   (x<<8)U             // Lock Register for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTB_PCRn LK bit register
//
//*************************************************************************************************
#define GPIO_GPBLK_GPIO0    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO1    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO2    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO3    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO4    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO5    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO6    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO7    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO8    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO9    0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO10   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO11   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO12   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO13   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO14   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO15   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO16   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO17   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO18   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO19   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO20   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO21   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO22   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO23   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO24   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO25   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO26   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO27   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO28   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO29   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO30   0x8000U             // Lock Register for this pin
#define GPIO_GPBLK_GPIO31   0x8000U             // Lock Register for this pin 


//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTB_PCRn IRQC bit register
//
//*************************************************************************************************

#define GPIO_GPBIRQC_GPIOx(x)   (x<<8)U             // Lock Register for this pin


//*************************************************************************************************
//
// The following are defines for the bit fields in the  PORTB_PCRn ISF bit register
//
//*************************************************************************************************

#define GPIO_GPBISF_GPIOx   0x1000000U             // Interrupt status flag




//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn GPCLR bit register
//
//*************************************************************************************************


#define GPIO_PORTBGPCLR_GPOWD_GPIO0     0x1U          // Global Pin Write Data for pin0
#define GPIO_PORTBGPCLR_GPOWD_GPIO1     0x2U          //  Global Pin Write Data for for pin1
#define GPIO_PORTBGPCLR_GPOWD_GPIO2     0x4U          //  Global Pin Write Data for for pin2
#define GPIO_PORTBGPCLR_GPOWD_GPIO3     0x8U          //  Global Pin Write Data for for pin3
#define GPIO_PORTBGPCLR_GPOWD_GPIO4     0x10U         //  Global Pin Write Data for for pin4
#define GPIO_PORTBGPCLR_GPOWD_GPIO5     0x20U         //  Global Pin Write Data for for pin5
#define GPIO_PORTBGPCLR_GPOWD_GPIO6     0x40U         //  Global Pin Write Data for for pin6
#define GPIO_PORTBGPCLR_GPOWD_GPIO7     0x80U         //  Global Pin Write Data for for pin7
#define GPIO_PORTBGPCLR_GPOWD_GPIO8     0x100U        //  Global Pin Write Data for for pin8
#define GPIO_PORTBGPCLR_GPOWD_GPIO9     0x200U        //  Global Pin Write Data for for pin9
#define GPIO_PORTBGPCLR_GPOWD_GPIO10    0x400U        //  Global Pin Write Data for for pin10
#define GPIO_PORTBGPCLR_GPOWD_GPIO11    0x800U        //  Global Pin Write Data for for pin11
#define GPIO_PORTBGPCLR_GPOWD_GPIO12    0x1000U       //  Global Pin Write Data for for pin12
#define GPIO_PORTBGPCLR_GPOWD_GPIO13    0x2000U       //  Global Pin Write Data for for pin13
#define GPIO_PORTBGPCLR_GPOWD_GPIO14    0x4000U       //  Global Pin Write Data for for pin14
#define GPIO_PORTBGPCLR_GPOWD_GPIO15    0x8000U       //  Global Pin Write Data for for pin15
#define GPIO_PORTBGPCLR_GPOWE_GPIO0     0x10000U      // Global Pin Write Enable for pin0
#define GPIO_PORTBGPCLR_GPOWE_GPIO1     0x20000U      // Global Pin Write Enable for pin1
#define GPIO_PORTBGPCLR_GPOWE_GPIO2     0x40000U      // Global Pin Write Enable for pin2
#define GPIO_PORTBGPCLR_GPOWE_GPIO3     0x80000U      // Global Pin Write Enable for pin3
#define GPIO_PORTBGPCLR_GPOWE_GPIO4     0x100000U     // Global Pin Write Enable for pin4
#define GPIO_PORTBGPCLR_GPOWE_GPIO5     0x200000U     // Global Pin Write Enable for pin5
#define GPIO_PORTBGPCLR_GPOWE_GPIO6     0x400000U     // Global Pin Write Enable for pin6
#define GPIO_PORTBGPCLR_GPOWE_GPIO7     0x800000U     // Global Pin Write Enable for pin7
#define GPIO_PORTBGPCLR_GPOWE_GPIO8     0x1000000U    // Global Pin Write Enable for pin8
#define GPIO_PORTBGPCLR_GPOWE_GPIO9     0x2000000U    // Global Pin Write Enable for pin9
#define GPIO_PORTBGPCLR_GPOWE_GPIO10    0x4000000U    // Global Pin Write Enable for pin10
#define GPIO_PORTBGPCLR_GPOWE_GPIO11    0x8000000U    // Global Pin Write Enable for pin11
#define GPIO_PORTBGPCLR_GPOWE_GPIO12    0x10000000U   // Global Pin Write Enable for pin12
#define GPIO_PORTBGPCLR_GPOWE_GPIO13    0x20000000U   // Global Pin Write Enable for pin13
#define GPIO_PORTBGPCLR_GPOWE_GPIO14    0x40000000U   // Global Pin Write Enable for pin14
#define GPIO_PORTBGPCLR_GPOWE_GPIO15    0x80000000U   // Global Pin Write Enable for pin15 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn GPCHR bit register
//
//*************************************************************************************************

#define GPIO_PORTBGPCHR_GPOWD_GPIO16    0x1U          // Global Pin Write Data for pin16
#define GPIO_PORTBGPCHR_GPOWD_GPIO17    0x2U          //  Global Pin Write Data for for pin17
#define GPIO_PORTBGPCHR_GPOWD_GPIO18    0x4U          //  Global Pin Write Data for for pin18
#define GPIO_PORTBGPCHR_GPOWD_GPIO19    0x8U          //  Global Pin Write Data for for pin19
#define GPIO_PORTBGPCHR_GPOWD_GPIO20    0x10U         //  Global Pin Write Data for for pin20
#define GPIO_PORTBGPCHR_GPOWD_GPIO21    0x20U         //  Global Pin Write Data for for pin21
#define GPIO_PORTBGPCHR_GPOWD_GPIO22    0x40U         //  Global Pin Write Data for for pin22
#define GPIO_PORTBGPCHR_GPOWD_GPIO23    0x80U         //  Global Pin Write Data for for pin23
#define GPIO_PORTBGPCHR_GPOWD_GPIO24    0x100U        //  Global Pin Write Data for for pin24
#define GPIO_PORTBGPCHR_GPOWD_GPIO25    0x200U        //  Global Pin Write Data for for pin25
#define GPIO_PORTBGPCHR_GPOWD_GPIO26    0x400U        //  Global Pin Write Data for for pin26
#define GPIO_PORTBGPCHR_GPOWD_GPIO27    0x800U        //  Global Pin Write Data for for pin27
#define GPIO_PORTBGPCHR_GPOWD_GPIO28    0x1000U       //  Global Pin Write Data for for pin28
#define GPIO_PORTBGPCHR_GPOWD_GPIO29    0x2000U       //  Global Pin Write Data for for pin29
#define GPIO_PORTBGPCHR_GPOWD_GPIO30    0x4000U       //  Global Pin Write Data for for pin30
#define GPIO_PORTBGPCHR_GPOWD_GPIO31    0x8000U       //  Global Pin Write Data for for pin31
#define GPIO_PORTBGPCHR_GPOWE_GPIO16    0x10000U      // Global Pin Write Enable for pin16
#define GPIO_PORTBGPCHR_GPOWE_GPIO17    0x20000U      // Global Pin Write Enable for pin17
#define GPIO_PORTBGPCHR_GPOWE_GPIO18    0x40000U      // Global Pin Write Enable for pin18
#define GPIO_PORTBGPCHR_GPOWE_GPIO19    0x80000U      // Global Pin Write Enable for pin19
#define GPIO_PORTBGPCHR_GPOWE_GPIO20    0x100000U     // Global Pin Write Enable for pin20
#define GPIO_PORTBGPCHR_GPOWE_GPIO21    0x200000U     // Global Pin Write Enable for pin21
#define GPIO_PORTBGPCHR_GPOWE_GPIO22    0x400000U     // Global Pin Write Enable for pin22
#define GPIO_PORTBGPCHR_GPOWE_GPIO23    0x800000U     // Global Pin Write Enable for pin23
#define GPIO_PORTBGPCHR_GPOWE_GPIO24    0x1000000U    // Global Pin Write Enable for pin24
#define GPIO_PORTBGPCHR_GPOWE_GPIO25    0x2000000U    // Global Pin Write Enable for pin25
#define GPIO_PORTBGPCHR_GPOWE_GPIO26    0x4000000U    // Global Pin Write Enable for pin26
#define GPIO_PORTBGPCHR_GPOWE_GPIO27    0x8000000U    // Global Pin Write Enable for pin27
#define GPIO_PORTBGPCHR_GPOWE_GPIO28    0x10000000U   // Global Pin Write Enable for pin28
#define GPIO_PORTBGPCHR_GPOWE_GPIO29    0x20000000U   // Global Pin Write Enable for pin29
#define GPIO_PORTBGPCHR_GPOWE_GPIO30    0x40000000U   // Global Pin Write Enable for pin30
#define GPIO_PORTBGPCHR_GPOWE_GPIO31    0x80000000U   // Global Pin Write Enable for pin31 


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn ISFR bit register
//
//*************************************************************************************************

#define GPIO_PORTBISF_ISF_GPIO0    0x1U          // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO1    0x2U          // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO2    0x4U          // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO3    0x8U          // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO4    0x10U         // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO5    0x20U         // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO6    0x40U         // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO7    0x80U         // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO8    0x100U        // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO9    0x200U        // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO10   0x400U        // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO11   0x800U        // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO12   0x1000U       // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO13   0x2000U       // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO14   0x4000U       // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO15   0x8000U       // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO16   0x10000U      // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO17   0x20000U      // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO18   0x40000U      // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO19   0x80000U      // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO20   0x100000U     // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO21   0x200000U     // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO22   0x400000U     // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO23   0x800000U     // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO24   0x1000000U    // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO25   0x2000000U    // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO26   0x4000000U    // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO27   0x8000000U    // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO28   0x10000000U   // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO29   0x20000000U   // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO30   0x40000000U   // write 1 clear Interrupt Status Flag for pin
#define GPIO_PORTBISF_ISF_GPIO31   0x80000000U   // write 1 clear Interrupt Status Flag for pin //OK**


//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn DFER bit register
//
//*************************************************************************************************

#define GPIO_PORTBDFE_DEF_GPIO0    0x1U          // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO1    0x2U          // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO2    0x4U          // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO3    0x8U          // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO4    0x10U         // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO5    0x20U         // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO6    0x40U         // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO7    0x80U         // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO8    0x100U        // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO9    0x200U        // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO10   0x400U        // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO11   0x800U        // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO12   0x1000U       // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO13   0x2000U       // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO14   0x4000U       // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO15   0x8000U       // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO16   0x10000U      // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO17   0x20000U      // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO18   0x40000U      // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO19   0x80000U      // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO20   0x100000U     // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO21   0x200000U     // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO22   0x400000U     // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO23   0x800000U     // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO24   0x1000000U    // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO25   0x2000000U    // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO26   0x4000000U    // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO27   0x8000000U    // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO28   0x10000000U   // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO29   0x20000000U   // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO30   0x40000000U   // Digital Filter Enable for pin
#define GPIO_PORTBDFE_DEF_GPIO31   0x80000000U   // Digital Filter Enable for pin 




//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn DFCR bit register
//
//*************************************************************************************************
#define GPIO_PORTBDFCR_CS_GPIO    0x1U          // sclect Clock Source for PORTB((1-LOP,0-bus))

//*************************************************************************************************
//
// The following are defines for the bit fields in the PORTB_PCRn DFWR bit register
//
//*************************************************************************************************
#define GPIO_PORTBDFWR_FLIT_GPIO(x)    (x)          // sclect Filter Length for PORTB







#endif
