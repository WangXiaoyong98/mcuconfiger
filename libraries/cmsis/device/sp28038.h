#ifndef _SP28038_H_
#define _SP28038_H_                              /**< Symbol preventing repeated inclusion */

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 125                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  Unused_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M4 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M4 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M4 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M4 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M4 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M4 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M4 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M4 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0,                /**< DMA Channel 0 Transfer Complete */
  DMA1_IRQn                    = 1,                /**< DMA Channel 1 Transfer Complete */
  DMA2_IRQn                    = 2,                /**< DMA Channel 2 Transfer Complete */
  DMA3_IRQn                    = 3,                /**< DMA Channel 3 Transfer Complete */
  DMA4_IRQn                    = 4,                /**< DMA Channel 4 Transfer Complete */
  DMA5_IRQn                    = 5,                /**< DMA Channel 5 Transfer Complete */
  DMA6_IRQn                    = 6,                /**< DMA Channel 6 Transfer Complete */
  DMA7_IRQn                    = 7,                /**< DMA Channel 7 Transfer Complete */
  DMA8_IRQn                    = 8,                /**< DMA Channel 8 Transfer Complete */
  DMA9_IRQn                    = 9,                /**< DMA Channel 9 Transfer Complete */
  DMA10_IRQn                   = 10,               /**< DMA Channel 10 Transfer Complete */
  DMA11_IRQn                   = 11,               /**< DMA Channel 11 Transfer Complete */
  DMA12_IRQn                   = 12,               /**< DMA Channel 12 Transfer Complete */
  DMA13_IRQn                   = 13,               /**< DMA Channel 13 Transfer Complete */
  DMA14_IRQn                   = 14,               /**< DMA Channel 14 Transfer Complete */
  DMA15_IRQn                   = 15,               /**< DMA Channel 15 Transfer Complete */
  DMA_Error_IRQn               = 16,               /**< DMA Error Interrupt */
  RESERVED1_IRQn               = 17,               /**< RESERVED */
  RESERVED2_IRQn               = 18,               /**< RESERVED */
  RESERVED3_IRQn               = 19,               /**< RESERVED */
  RESERVED4_IRQn               = 20,               /**< RESERVED */
  WWDT_EWM_IRQn                = 21,               /**< WWDT, EWM Interrupt*/
  RESERVED5_IRQn               = 22,               /**< RESERVED */
  RESERVED6_IRQn               = 23,               /**< RESERVED */
  I2C1_IRQn                    = 24,               /**< I2C 1 interrupt */
  I2C2_IRQn                    = 25,               /**< I2C 2 interrupt */
  SPI1_IRQn                    = 26,               /**< SPI 1 interrupt */
  SPI2_IRQn                    = 27,               /**< SPI 2 interrupt */
  SPI3_IRQn                    = 28,               /**< SPI 3 interrupt */
  SPI4_IRQn                    = 29,               /**< SPI 4 interrupt */
  SCI1_IRQn                    = 30,               /**< SCI 1 interrupt */
  SCI2_IRQn                    = 31,               /**< SCI 2 interrupt */
  SCI3_IRQn                    = 32,               /**< SCI 3 interrupt */
  SCI4_IRQn                    = 33,               /**< SCI 4 interrupt */
  SCI5_IRQn                    = 34,               /**< SCI 5 interrupt */
  SCI6_IRQn                    = 35,               /**< SCI 6 interrupt */
  ADCA_INT1_IRQn               = 36,               /**< ADC 1 interrupt 1 */
  ADCA_INT2_IRQn               = 37,               /**< ADC 1 interrupt 2 */
  ADCA_INT3_IRQn               = 38,               /**< ADC 1 interrupt 3 */
  ADCA_INT4_IRQn               = 39,               /**< ADC 1 interrupt 4 */
  ADCA_EVT_IRQn                = 40,               /**< ADC 1 event interrupt */
  ADCB_INT1_IRQn               = 41,               /**< ADC 2 interrupt 1 */
  ADCB_INT2_IRQn               = 42,               /**< ADC 2 interrupt 2 */
  ADCB_INT3_IRQn               = 43,               /**< ADC 2 interrupt 3 */
  ADCB_INT4_IRQn               = 44,               /**< ADC 2 interrupt 4 */
  ADCB_EVT_IRQn                = 45,               /**< ADC 2 event interrupt */
  ADCC_INT1_IRQn               = 46,               /**< ADC 3 interrupt 1*/
  ADCC_INT2_IRQn               = 47,               /**< ADC 3 interrupt 2*/
  ADCC_INT3_IRQn               = 48,               /**< ADC 3 interrupt 3*/
  ADCC_INT4_IRQn               = 49,               /**< ADC 3 interrupt 4*/
  ADCC_EVT_IRQn                = 50,               /**< ADC 3 event interrupt */
  CMP1_IRQn                    = 51,               /**< Comparator interrupt 1 */
  CMP2_IRQn                    = 52,               /**< Comparator interrupt 2 */
  VDT1_IRQn                    = 53,               /**< Voltage Detect 1 interrupt */
  VDT2_IRQn                    = 54,               /**< Voltage Detect 2 interrupt */
  MCAN1_IRQn                   = 55,               /**< CAN 1 interrupt */
  MCAN2_IRQn                   = 56,               /**< CAN 2 interrupt */
  EPWM1_IRQn                   = 57,               /**< EPWM 1 interrupt */
  EPWM2_IRQn                   = 58,               /**< EPWM 2 interrupt */
  EPWM3_IRQn                   = 59,               /**< EPWM 3 interrupt */
  EPWM4_IRQn                   = 60,               /**< EPWM 4 interrupt */
  EPWM5_IRQn                   = 61,               /**< EPWM 5 interrupt */
  EPWM6_IRQn                   = 62,               /**< EPWM 6 interrupt */
  EPWM7_IRQn                   = 63,               /**< EPWM 7 interrupt */
  RESERVED7_IRQn               = 64,               /**< RESERVED */
  EPWM1_TZ_IRQn                = 65,               /**< EPWM 1 Trip Zone interrupt */
  EPWM2_TZ_IRQn                = 66,               /**< EPWM 2 Trip Zone interrupt */
  EPWM3_TZ_IRQn                = 67,               /**< EPWM 3 Trip Zone interrupt */
  EPWM4_TZ_IRQn                = 68,               /**< EPWM 4 Trip Zone interrupt */
  EPWM5_TZ_IRQn                = 69,               /**< EPWM 5 Trip Zone interrupt */
  EPWM6_TZ_IRQn                = 70,               /**< EPWM 6 Trip Zone interrupt */
  EPWM7_TZ_IRQn                = 71,               /**< EPWM 7 Trip Zone interrupt */
  RESERVED8_IRQn               = 72,               /**< RESERVED */
  XINT1_IRQn                   = 73,               /**< XINT 1 interrupt */
  XINT2_IRQn                   = 74,               /**< XINT 2 interrupt */
  XINT3_IRQn                   = 75,               /**< XINT 3 interrupt */
  XINT4_IRQn                   = 76,               /**< XINT 4 interrupt */
  XINT5_IRQn                   = 77,               /**< XINT 5 interrupt */
  GPIOA_IRQn                   = 78,               /**< GPIOA interrupt */
  GPIOB_IRQn                   = 79,               /**< GPIOB interrupt */
  RESERVED9_IRQn               = 80,               /**< RESERVED */
  ECAP1_IRQn                   = 81,               /**< ECAP 1 interrupt */
  ECAP2_IRQn                   = 82,               /**< ECAP 2 interrupt */
  ECAP3_IRQn                   = 83,               /**< ECAP 3 interrupt */
  RESERVED10_IRQn              = 84,               /**< RESERVED */
  TDTLT_IRQn                   = 85,               /**< TDT low temprature interrupt */
  TDTHT_IRQn                   = 86,               /**< TDT high temprature interrupt */
  FLASH_ECCERR_IRQn            = 87,               /**< Flash ECC error interrupt*/
  RESERVED13_IRQn              = 88,               /**< RESERVED */
  RESERVED14_IRQn              = 89,               /**< RESERVED */
  EQEP1_IRQn                   = 90,               /**< EQEP 1 interrupt */
  EQEP2_IRQn                   = 91,               /**< EQEP 2 interrupt */
  PTIM_CH0_IRQn                = 92,               /**< PTIM channel 0 interrupt*/
  PTIM_CH1_IRQn                = 93,               /**< PTIM channel 1 interrupt*/
  PTIM_CH2_IRQn                = 94,               /**< PTIM channel 2 interrupt*/
  PTIM_CH3_IRQn                = 95,               /**< PTIM channel 3 interrupt*/
  RESERVED15_IRQn              = 96,               /**< RESERVED */
  SDFM1_DR0_IRQn               = 97,
  SDFM1_DR1_IRQn               = 98,
  SDFM1_DR2_IRQn               = 99,
  SDFM1_DR3_IRQn               = 100,
  RESERVED16_IRQn              = 101,
  SDFM2_DR0_IRQn               = 102,
  SDFM2_DR1_IRQn               = 103,
  SDFM2_DR2_IRQn               = 104,
  SDFM2_DR3_IRQn               = 105,
  SDFM1_IRQn                   = 106,
  SDFM2_IRQn                   = 107,
  LPTIM_IRQn                   = 108,              /**< Low power timer interrupt*/
  DCC1_INTR_IRQn               = 109,
  DCC2_INTR_IRQn               = 110,
  DCC1_ERR_IRQn                = 111,
  DCC2_ERR_IRQn                = 112,
  CORDIC_IRQn                  = 113
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M4 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M4 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */

#include "core_cm4.h"                  /* Core Peripheral Access Layer */
#include "system_sp28038.h"            /* Device specific configuration file */
#include "hw_memmap.h"
/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma_request_source
{
    sDmaRequestMuxDisable          = 0|0x100U,    /**< DMAMUX TriggerDisabled */
    sDmaRequestMuxSCI1SCI4Rx       = 1|0x100U,    /**< SCI1 or SCI4 RX */
    sDmaRequestMuxSCI1SCI4Tx       = 2|0x100U,    /**< SCI1 or SCI4 TX */
    sDmaRequestMuxSCI2SCI5Rx       = 3|0x100U,    /**< SCI2 or SCI5 RX */
    sDmaRequestMuxSCI2SCI5Tx       = 4|0x100U,    /**< SCI2 or SCI5 TX */
    sDmaRequestMuxSCI3SCI6Rx       = 5|0x100U,    /**< SCI3 or SCI6 RX */
    sDmaRequestMuxSCI4SCI6Tx       = 6|0x100U,    /**< SCI3 or SCI6 TX */
    sDmaRequestMuxSPI1Rx           = 7|0x100U,    /**< SPI1 RX */
    sDmaRequestMuxSPI1Tx           = 8|0x100U,    /**< SPI1 TX */
    sDmaRequestMuxSPI2Rx           = 9|0x100U,    /**< SPI2 RX */
    sDmaRequestMuxSPI2Tx           = 10|0x100U,   /**< SPI2 TX */
    sDmaRequestMuxSPI3Rx           = 11|0x100U,   /**< SPI3 RX */
    sDmaRequestMuxSPI3Tx           = 12|0x100U,   /**< SPI3 TX */
    sDmaRequestMuxXINT1            = 15|0x100U,   /**< XINT1 */
    sDmaRequestMuxXINT2            = 16|0x100U,   /**< XINT2 */
    sDmaRequestMuxXINT3            = 17|0x100U,   /**< XINT3 */
    sDmaRequestMuxXINT4            = 18|0x100U,   /**< XINT4 */
    sDmaRequestMuxXINT5            = 19|0x100U,   /**< XINT5 */
    sDmaRequestMuxADCAINT1         = 20|0x100U,   /**< ADC1 INT1 */
    sDmaRequestMuxADCAINT2         = 21|0x100U,   /**< ADC1 INT2 */
    sDmaRequestMuxADCAINT3         = 22|0x100U,   /**< ADC1 INT3 */
    sDmaRequestMuxADCAINT4         = 23|0x100U,   /**< ADC1 INT4 */
    sDmaRequestMuxADCAEVT          = 24|0x100U,   /**< ADC1 Event */
    sDmaRequestMuxADCBINT1         = 25|0x100U,   /**< ADC2 INT1 */
    sDmaRequestMuxADCBINT2         = 26|0x100U,   /**< ADC2 INT2 */
    sDmaRequestMuxADCBINT3         = 27|0x100U,   /**< ADC2 INT3 */
    sDmaRequestMuxADCBINT4         = 28|0x100U,   /**< ADC2 INT4 */
    sDmaRequestMuxADCBEVT          = 29|0x100U,   /**< ADC2 Event */
    sDmaRequestMuxADCCINT1         = 30|0x100U,   /**< ADC3 INT1 */
    sDmaRequestMuxADCCINT2         = 31|0x100U,   /**< ADC3 INT2 */
    sDmaRequestMuxADCCINT3         = 32|0x100U,   /**< ADC3 INT3 */
    sDmaRequestMuxADCCINT4         = 33|0x100U,   /**< ADC3 INT4 */
    sDmaRequestMuxADCCEVT          = 34|0x100U,   /**< ADC3 Event */
    sDmaRequestMuxPORTA            = 35|0x100U,   /**< PORTA */
    sDmaRequestMuxPORTB            = 36|0x100U,   /**< PORTB */
    sDmaRequestMuxSPI4Rx           = 38|0x100U,   /**< SPI4 RX */
    sDmaRequestMuxSPI4Tx           = 39|0x100U,   /**< SPI4 TX */
    sDmaRequestMuxAlwaysOn62       = 62|0x100U,   /**< DMAMUX Always Enabled slot */
    sDmaRequestMuxAlwaysOn63       = 63|0x100U,   /**< DMAMUX Always Enabled slot */
} dma_request_source_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
 *    -- EQEP Peripheral Access Layer
 *       ---------------------------------------------------------------------------- */

/*!
 *  * @addtogroup EQEP_Peripheral_Access_Layer EQEP Peripheral Access Layer
 *   * @{
 *    */
typedef struct {
  __IO  uint32_t QPOSCNT;         /* eQEP position counter Register, offset: 0 */
        uint32_t Reserved1;
  __IO  uint32_t QPOSINIT;        /* eQEP position init Register, offset: 8 */
        uint32_t Reserved2;
  __IO  uint32_t QPOSMAX;         /* eQEP MAX position count Register, offset: 0x10 */
        uint32_t Reserved3;
  __IO  uint32_t QPOSCMP;         /* eQEP position compare Register, offset: 0x18 */
        uint32_t Reserved4;
  __IO  uint32_t QPOSILAT;        /* eQEP index position latch Register, offset: 0x20 */
        uint32_t Reserved5;
  __IO  uint32_t QPOSSLAT;        /* eQEP position counter Register, offset: 0x28 */
        uint32_t Reserved6;
  __IO  uint32_t QPOSLAT;         /* eQEP position counter Register, offset: 0x30 */
        uint32_t Reserved7;
  __IO  uint32_t QUTMR;           /* eQEP unit timer Register, offset: 0x38 */
        uint32_t Reserved8;
  __IO  uint32_t QUPRD;           /* eQEP unit period Register, offset: 0x40 */
        uint32_t Reserved9;
  __IO  uint32_t QWDTMR;          /* eQEP watchdog timer Register, offset: 0x48 */
  __IO  uint32_t QWDPRD;          /* eQEP watchdog period Register, offset: 0x4C */
  __IO  uint32_t QDECCTL;         /* eQEP Decoder Control Register , offset: 0x50 */
  __IO  uint32_t QEPCTL;          /* eQEP Control Register, offset: 0x54 */
  __IO  uint32_t QCAPCTL;         /* eQEP Capture Control Register, offset: 0x58 */
  __IO  uint32_t QPOSCTL;         /* eQEP Position-Compare Control Register, offset: 0x5C */
  __IO  uint32_t QEINT;           /* eQEP Interrupt Enable Control Register, offset: 0x60 */
  __IO  uint32_t QFLG;            /* eQEP Interrupt Flag Register, offset: 0x64 */
  __IO  uint32_t QCLR;            /* eQEP Interrupt Clear Register, offset: 0x68 */
  __IO  uint32_t QFRC;            /* eQEP Interrupt Force Register, offset: 0x6C */
  __IO  uint32_t QEPSTS;          /* eQEP Status Register, offset: 0x70 */
  __IO  uint32_t QCTMR;           /* eQEP Capture Timer Register, offset: 0x74 */
  __IO  uint32_t QCPRD;           /* eQEP Capture Period Register, offset: 0x78 */
  __IO  uint32_t QCTMRLAT;        /* eQEP Capture Timer Latch Register, offset: 0x7C */
  __IO  uint32_t QCPRDLAT;        /* eQEP Capture Period Latch Register, offset: 0x80 */
  __IO  uint32_t QEPSRCSEL;       /* eQEP Source Select Register, offset: 0x84 */
}EQEP_TypeDef;

/* ----------------------------------------------------------------------------
 *    -- EQEP Register Masks
 *       ---------------------------------------------------------------------------- */

/*!
 *  * @addtogroup EQEP_Register_Masks EQEP Register Masks
 *   * @{
 *    */

/*! @name QDECCTL - Control Register */
/*! @{ */
#define EQEP_QDECCTL_QIDIRE_MASK               (0x1U)
#define EQEP_QDECCTL_QIDIRE_SHIFT              (0)
#define EQEP_QDECCTL_QIDIRE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_QIDIRE_SHIFT)) & EQEP_QDECCTL_QIDIRE_MASK)

#define EQEP_QDECCTL_QSP_MASK               (0x20U)
#define EQEP_QDECCTL_QSP_SHIFT              (5)
#define EQEP_QDECCTL_QSP_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_QSP_SHIFT)) & EQEP_QDECCTL_QSP_MASK)

#define EQEP_QDECCTL_QIP_MASK               (0x40U)
#define EQEP_QDECCTL_QIP_SHIFT              (6)
#define EQEP_QDECCTL_QIP_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_QIP_SHIFT)) & EQEP_QDECCTL_QIP_MASK)

#define EQEP_QDECCTL_QBP_MASK               (0x80U)
#define EQEP_QDECCTL_QBP_SHIFT              (7)
#define EQEP_QDECCTL_QBP_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_QBP_SHIFT)) & EQEP_QDECCTL_QBP_MASK)

#define EQEP_QDECCTL_QAP_MASK               (0x100U)
#define EQEP_QDECCTL_QAP_SHIFT              (8)
#define EQEP_QDECCTL_QAP_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_QAP_SHIFT)) & EQEP_QDECCTL_QAP_MASK)

#define EQEP_QDECCTL_IGATE_MASK               (0x200U)
#define EQEP_QDECCTL_IGATE_SHIFT              (9)
#define EQEP_QDECCTL_IGATE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_IGATE_SHIFT)) & EQEP_QDECCTL_IGATE_MASK)

#define EQEP_QDECCTL_SWAP_MASK               (0x400U)
#define EQEP_QDECCTL_SWAP_SHIFT              (10)
#define EQEP_QDECCTL_SWAP_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_SWAP_SHIFT)) & EQEP_QDECCTL_SWAP_MASK)

#define EQEP_QDECCTL_XCR_MASK               (0x800U)
#define EQEP_QDECCTL_XCR_SHIFT              (11)
#define EQEP_QDECCTL_XCR_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_XCR_SHIFT)) & EQEP_QDECCTL_XCR_MASK)

#define EQEP_QDECCTL_SPSEL_MASK               (0x1000U)
#define EQEP_QDECCTL_SPSEL_SHIFT              (12)
#define EQEP_QDECCTL_SPSEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_SPSEL_SHIFT)) & EQEP_QDECCTL_SPSEL_MASK)

#define EQEP_QDECCTL_SOEN_MASK               (0x2000U)
#define EQEP_QDECCTL_SOEN_SHIFT              (13)
#define EQEP_QDECCTL_SOEN_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_SOEN_SHIFT)) & EQEP_QDECCTL_SOEN_MASK)

#define EQEP_QDECCTL_QSRC_MASK               (0xc000U)
#define EQEP_QDECCTL_QSRC_SHIFT              (14)
#define EQEP_QDECCTL_QSRC_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QDECCTL_QSRC_SHIFT)) & EQEP_QDECCTL_QSRC_MASK)
/*! @} */
/*! @name QEPCTL - eQEP Control Register  */
/*! @{ */
#define EQEP_QEPCTL_WDE_MASK               (0x1U)
#define EQEP_QEPCTL_WDE_SHIFT              (0)
#define EQEP_QEPCTL_WDE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_WDE_SHIFT)) & EQEP_QEPCTL_WDE_MASK)

#define EQEP_QEPCTL_UTE_MASK               (0x2U)
#define EQEP_QEPCTL_UTE_SHIFT              (1)
#define EQEP_QEPCTL_UTE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_UTE_SHIFT)) & EQEP_QEPCTL_UTE_MASK)

#define EQEP_QEPCTL_QCLM_MASK               (0x4U)
#define EQEP_QEPCTL_QCLM_SHIFT              (2)
#define EQEP_QEPCTL_QCLM_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_QCLM_SHIFT)) & EQEP_QEPCTL_QCLM_MASK)

#define EQEP_QEPCTL_QPEN_MASK               (0x8U)
#define EQEP_QEPCTL_QPEN_SHIFT              (3)
#define EQEP_QEPCTL_QPEN_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_QPEN_SHIFT)) & EQEP_QEPCTL_QPEN_MASK)

#define EQEP_QEPCTL_IEL_MASK               (0x30U)
#define EQEP_QEPCTL_IEL_SHIFT              (4)
#define EQEP_QEPCTL_IEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_IEL_SHIFT)) & EQEP_QEPCTL_IEL_MASK)

#define EQEP_QEPCTL_SEL_MASK               (0x40U)
#define EQEP_QEPCTL_SEL_SHIFT              (6)
#define EQEP_QEPCTL_SEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_SEL_SHIFT)) & EQEP_QEPCTL_SEL_MASK)

#define EQEP_QEPCTL_SWI_MASK               (0x80U)
#define EQEP_QEPCTL_SWI_SHIFT              (7)
#define EQEP_QEPCTL_SWI_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_SWI_SHIFT)) & EQEP_QEPCTL_SWI_MASK)

#define EQEP_QEPCTL_IEI_MASK               (0x300U)
#define EQEP_QEPCTL_IEI_SHIFT              (8)
#define EQEP_QEPCTL_IEI_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_IEI_SHIFT)) & EQEP_QEPCTL_IEI_MASK)

#define EQEP_QEPCTL_SEI_MASK               (0xc00U)
#define EQEP_QEPCTL_SEI_SHIFT              (10)
#define EQEP_QEPCTL_SEI_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_SEI_SHIFT)) & EQEP_QEPCTL_SEI_MASK)

#define EQEP_QEPCTL_PCRM_MASK               (0x3000U)
#define EQEP_QEPCTL_PCRM_SHIFT              (12)
#define EQEP_QEPCTL_PCRM_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_PCRM_SHIFT)) & EQEP_QEPCTL_PCRM_MASK)

#define EQEP_QEPCTL_FREE_SOFT_MASK               (0xc000U)
#define EQEP_QEPCTL_FREE_SOFT_SHIFT              (14)
#define EQEP_QEPCTL_FREE_SOFT_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPCTL_FREE_SOFT_SHIFT)) & EQEP_QEPCTL_FREE_SOFT_MASK)

/*! @} */
/*! @name QCAPCTL - eQEP Capture Control Register  */
/*! @{ */
#define EQEP_QCAPCTL_UPPS_MASK               (0xfU)
#define EQEP_QCAPCTL_UPPS_SHIFT              (0)
#define EQEP_QCAPCTL_UPPS_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QCAPCTL_UPPS_SHIFT)) & EQEP_QCAPCTL_UPPS_MASK)

#define EQEP_QCAPCTL_CCPS_MASK               (0x70U)
#define EQEP_QCAPCTL_CCPS_SHIFT              (4)
#define EQEP_QCAPCTL_CCPS_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QCAPCTL_CCPS_SHIFT)) & EQEP_QCAPCTL_CCPS_MASK)

#define EQEP_QCAPCTL_CEN_MASK               (0x8000U)
#define EQEP_QCAPCTL_CEN_SHIFT              (15)
#define EQEP_QCAPCTL_CEN_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QCAPCTL_CEN_SHIFT)) & EQEP_QCAPCTL_CEN_MASK)


/*! @} */
/*! @name QPOSCTL - eQEP Position Compare Control Register  */
/*! @{ */
#define EQEP_QPOSCTL_PCSPW_MASK                  (0xfffU)
#define EQEP_QPOSCTL_PCSPW_SHIFT                 (0)
#define EQEP_QPOSCTL_PCSPW_SET(x)                    (((uint32_t)(((uint32_t)(x)) << EQEP_QPOSCTL_PCSPW_SHIFT)) & EQEP_QPOSCTL_PCSPW_MASK)

#define EQEP_QPOSCTL_PCE_MASK                    (0x1000U)
#define EQEP_QPOSCTL_PCE_SHIFT                   (12)
#define EQEP_QPOSCTL_PCE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << EQEP_QPOSCTL_PCE_SHIFT)) & EQEP_QPOSCTL_PCE_MASK)

#define EQEP_QPOSCTL_PCPOL_MASK                  (0x2000U)
#define EQEP_QPOSCTL_PCPOL_SHIFT                 (13)
#define EQEP_QPOSCTL_PCPOL_SET(x)                    (((uint32_t)(((uint32_t)(x)) << EQEP_QPOSCTL_PCPOL_SHIFT)) & EQEP_QPOSCTL_PCPOL_MASK)

#define EQEP_QPOSCTL_PCLOAD_MASK                 (0x4000U)
#define EQEP_QPOSCTL_PCLOAD_SHIFT                (14)
#define EQEP_QPOSCTL_PCLOAD_SET(x)                   (((uint32_t)(((uint32_t)(x)) << EQEP_QPOSCTL_PCLOAD_SHIFT)) & EQEP_QPOSCTL_PCLOAD_MASK)

#define EQEP_QPOSCTL_PCSHDW_MASK                 (0x8000U)
#define EQEP_QPOSCTL_PCSHDW_SHIFT                (15)
#define EQEP_QPOSCTL_PCSHDW_SET(x)                   (((uint32_t)(((uint32_t)(x)) << EQEP_QPOSCTL_PCSHDW_SHIFT)) & EQEP_QPOSCTL_PCSHDW_MASK)

/*! @} */
/*! @name QEINT - eQEP Interrupt Control Register  */
/*! @{ */
#define EQEP_QEINT_PCE_MASK               (0x2U)
#define EQEP_QEINT_PCE_SHIFT              (1)
#define EQEP_QEINT_PCE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_PCE_SHIFT)) & EQEP_QEINT_PCE_MASK)

#define EQEP_QEINT_QPE_MASK               (0x4U)
#define EQEP_QEINT_QPE_SHIFT              (2)
#define EQEP_QEINT_QPE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_QPE_SHIFT)) & EQEP_QEINT_QPE_MASK)

#define EQEP_QEINT_QDC_MASK               (0x8U)
#define EQEP_QEINT_QDC_SHIFT              (3)
#define EQEP_QEINT_QDC_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_QDC_SHIFT)) & EQEP_QEINT_QDC_MASK)

#define EQEP_QEINT_WTO_MASK               (0x10U)
#define EQEP_QEINT_WTO_SHIFT              (4)
#define EQEP_QEINT_WTO_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_WTO_SHIFT)) & EQEP_QEINT_WTO_MASK)

#define EQEP_QEINT_PCU_MASK               (0x20U)
#define EQEP_QEINT_PCU_SHIFT              (5)
#define EQEP_QEINT_PCU_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_PCU_SHIFT)) & EQEP_QEINT_PCU_MASK)

#define EQEP_QEINT_PCO_MASK               (0x40U)
#define EQEP_QEINT_PCO_SHIFT              (6)
#define EQEP_QEINT_PCO_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_PCO_SHIFT)) & EQEP_QEINT_PCO_MASK)

#define EQEP_QEINT_PCR_MASK               (0x80U)
#define EQEP_QEINT_PCR_SHIFT              (7)
#define EQEP_QEINT_PCR_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_PCR_SHIFT)) & EQEP_QEINT_PCR_MASK)

#define EQEP_QEINT_PCM_MASK               (0x100U)
#define EQEP_QEINT_PCM_SHIFT              (8)
#define EQEP_QEINT_PCM_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_PCM_SHIFT)) & EQEP_QEINT_PCM_MASK)

#define EQEP_QEINT_SEL_MASK               (0x200U)
#define EQEP_QEINT_SEL_SHIFT              (9)
#define EQEP_QEINT_SEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_SEL_SHIFT)) & EQEP_QEINT_SEL_MASK)

#define EQEP_QEINT_IEL_MASK               (0x400U)
#define EQEP_QEINT_IEL_SHIFT              (10)
#define EQEP_QEINT_IEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_IEL_SHIFT)) & EQEP_QEINT_IEL_MASK)

#define EQEP_QEINT_UTO_MASK               (0x800U)
#define EQEP_QEINT_UTO_SHIFT              (11)
#define EQEP_QEINT_UTO_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_UTO_SHIFT)) & EQEP_QEINT_UTO_MASK)

#define EQEP_QEINT_QMAE_MASK               (0x1000U)
#define EQEP_QEINT_QMAE_SHIFT              (12)
#define EQEP_QEINT_QMAE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEINT_QMAE_SHIFT)) & EQEP_QEINT_QMAE_MASK)


/*! @} */
/*! @name QFLG - eQEP Interrupt Flag Register  */
/*! @{ */
#define EQEP_QFLG_INT_MASK                       (0x1U)
#define EQEP_QFLG_INT_SHIFT                      (1)
#define EQEP_QFLG_INT_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_INT_SHIFT)) & EQEP_QFLG_INT_MASK)

#define EQEP_QFLG_PCE_MASK                       (0x2U)
#define EQEP_QFLG_PCE_SHIFT                      (1)
#define EQEP_QFLG_PCE_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_PCE_SHIFT)) & EQEP_QFLG_PCE_MASK)

#define EQEP_QFLG_PHE_MASK                       (0x4U)
#define EQEP_QFLG_PHE_SHIFT                      (2)
#define EQEP_QFLG_PHE_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_QPE_SHIFT)) & EQEP_QFLG_QPE_MASK)

#define EQEP_QFLG_QDC_MASK                       (0x8U)
#define EQEP_QFLG_QDC_SHIFT                      (3)
#define EQEP_QFLG_QDC_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_QDC_SHIFT)) & EQEP_QFLG_QDC_MASK)

#define EQEP_QFLG_WTO_MASK                       (0x10U)
#define EQEP_QFLG_WTO_SHIFT                      (4)
#define EQEP_QFLG_WTO_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_WTO_SHIFT)) & EQEP_QFLG_WTO_MASK)

#define EQEP_QFLG_PCU_MASK                       (0x20U)
#define EQEP_QFLG_PCU_SHIFT                      (5)
#define EQEP_QFLG_PCU_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_PCU_SHIFT)) & EQEP_QFLG_PCU_MASK)

#define EQEP_QFLG_PCO_MASK                       (0x40U)
#define EQEP_QFLG_PCO_SHIFT                      (6)
#define EQEP_QFLG_PCO_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_PCO_SHIFT)) & EQEP_QFLG_PCO_MASK)

#define EQEP_QFLG_PCR_MASK                       (0x80U)
#define EQEP_QFLG_PCR_SHIFT                      (7)
#define EQEP_QFLG_PCR_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_PCR_SHIFT)) & EQEP_QFLG_PCR_MASK)

#define EQEP_QFLG_PCM_MASK                       (0x100U)
#define EQEP_QFLG_PCM_SHIFT                      (8)
#define EQEP_QFLG_PCM_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_PCM_SHIFT)) & EQEP_QFLG_PCM_MASK)

#define EQEP_QFLG_SEL_MASK                       (0x200U)
#define EQEP_QFLG_SEL_SHIFT                      (9)
#define EQEP_QFLG_SEL_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_SEL_SHIFT)) & EQEP_QFLG_SEL_MASK)

#define EQEP_QFLG_IEL_MASK                       (0x400U)
#define EQEP_QFLG_IEL_SHIFT                      (10)
#define EQEP_QFLG_IEL_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_IEL_SHIFT)) & EQEP_QFLG_IEL_MASK)

#define EQEP_QFLG_UTO_MASK                       (0x800U)
#define EQEP_QFLG_UTO_SHIFT                      (11)
#define EQEP_QFLG_UTO_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_UTO_SHIFT)) & EQEP_QFLG_UTO_MASK)

#define EQEP_QFLG_QMAE_MASK                      (0x1000U)
#define EQEP_QFLG_QMAE_SHIFT                     (12)
#define EQEP_QFLG_QMAE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << EQEP_QFLG_QMAE_SHIFT)) & EQEP_QFLG_QMAE_MASK)

/*! @} */
/*! @name QCLR - eQEP Interrupt Clear Register  */
/*! @{ */
#define EQEP_QCLR_INT_MASK                       (0x1U)
#define EQEP_QCLR_INT_SHIFT                      (1)
#define EQEP_QCLR_INT_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_INT_SHIFT)) & EQEP_QCLR_INT_MASK)

#define EQEP_QCLR_PCE_MASK                       (0x2U)
#define EQEP_QCLR_PCE_SHIFT                      (1)
#define EQEP_QCLR_PCE_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_PCE_SHIFT)) & EQEP_QCLR_PCE_MASK)

#define EQEP_QCLR_PHE_MASK                       (0x4U)
#define EQEP_QCLR_PHE_SHIFT                      (2)
#define EQEP_QCLR_PHE_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_QPE_SHIFT)) & EQEP_QCLR_QPE_MASK)

#define EQEP_QCLR_QDC_MASK                       (0x8U)
#define EQEP_QCLR_QDC_SHIFT                      (3)
#define EQEP_QCLR_QDC_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_QDC_SHIFT)) & EQEP_QCLR_QDC_MASK)

#define EQEP_QCLR_WTO_MASK                       (0x10U)
#define EQEP_QCLR_WTO_SHIFT                      (4)
#define EQEP_QCLR_WTO_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_WTO_SHIFT)) & EQEP_QCLR_WTO_MASK)

#define EQEP_QCLR_PCU_MASK                       (0x20U)
#define EQEP_QCLR_PCU_SHIFT                      (5)
#define EQEP_QCLR_PCU_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_PCU_SHIFT)) & EQEP_QCLR_PCU_MASK)

#define EQEP_QCLR_PCO_MASK                       (0x40U)
#define EQEP_QCLR_PCO_SHIFT                      (6)
#define EQEP_QCLR_PCO_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_PCO_SHIFT)) & EQEP_QCLR_PCO_MASK)

#define EQEP_QCLR_PCR_MASK                       (0x80U)
#define EQEP_QCLR_PCR_SHIFT                      (7)
#define EQEP_QCLR_PCR_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_PCR_SHIFT)) & EQEP_QCLR_PCR_MASK)

#define EQEP_QCLR_PCM_MASK                       (0x100U)
#define EQEP_QCLR_PCM_SHIFT                      (8)
#define EQEP_QCLR_PCM_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_PCM_SHIFT)) & EQEP_QCLR_PCM_MASK)

#define EQEP_QCLR_SEL_MASK                       (0x200U)
#define EQEP_QCLR_SEL_SHIFT                      (9)
#define EQEP_QCLR_SEL_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_SEL_SHIFT)) & EQEP_QCLR_SEL_MASK)

#define EQEP_QCLR_IEL_MASK                       (0x400U)
#define EQEP_QCLR_IEL_SHIFT                      (10)
#define EQEP_QCLR_IEL_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_IEL_SHIFT)) & EQEP_QCLR_IEL_MASK)

#define EQEP_QCLR_UTO_MASK                       (0x800U)
#define EQEP_QCLR_UTO_SHIFT                      (11)
#define EQEP_QCLR_UTO_SET(x)                         (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_UTO_SHIFT)) & EQEP_QCLR_UTO_MASK)

#define EQEP_QCLR_QMAE_MASK                      (0x1000U)
#define EQEP_QCLR_QMAE_SHIFT                     (12)
#define EQEP_QCLR_QMAE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << EQEP_QCLR_QMAE_SHIFT)) & EQEP_QCLR_QMAE_MASK)

/*! @} */
/*! @name QFRC - eQEP Interrupt Force Register  */
/*! @{ */
#define EQEP_QFRC_PCE_MASK               (0x2U)
#define EQEP_QFRC_PCE_SHIFT              (1)
#define EQEP_QFRC_PCE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_PCE_SHIFT)) & EQEP_QFRC_PCE_MASK)

#define EQEP_QFRC_PHE_MASK               (0x4U)
#define EQEP_QFRC_PHE_SHIFT              (2)
#define EQEP_QFRC_PHE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_PHE_SHIFT)) & EQEP_QFRC_PHE_MASK)

#define EQEP_QFRC_QDC_MASK               (0x8U)
#define EQEP_QFRC_QDC_SHIFT              (3)
#define EQEP_QFRC_QDC_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_QDC_SHIFT)) & EQEP_QFRC_QDC_MASK)

#define EQEP_QFRC_WTO_MASK               (0x10U)
#define EQEP_QFRC_WTO_SHIFT              (4)
#define EQEP_QFRC_WTO_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_WTO_SHIFT)) & EQEP_QFRC_WTO_MASK)

#define EQEP_QFRC_PCU_MASK               (0x20U)
#define EQEP_QFRC_PCU_SHIFT              (5)
#define EQEP_QFRC_PCU_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_PCU_SHIFT)) & EQEP_QFRC_PCU_MASK)

#define EQEP_QFRC_PCO_MASK               (0x40U)
#define EQEP_QFRC_PCO_SHIFT              (6)
#define EQEP_QFRC_PCO_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_PCO_SHIFT)) & EQEP_QFRC_PCO_MASK)

#define EQEP_QFRC_PCR_MASK               (0x80U)
#define EQEP_QFRC_PCR_SHIFT              (7)
#define EQEP_QFRC_PCR_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_PCR_SHIFT)) & EQEP_QFRC_PCR_MASK)

#define EQEP_QFRC_PCM_MASK               (0x100U)
#define EQEP_QFRC_PCM_SHIFT              (8)
#define EQEP_QFRC_PCM_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_PCM_SHIFT)) & EQEP_QFRC_PCM_MASK)

#define EQEP_QFRC_SEL_MASK               (0x200U)
#define EQEP_QFRC_SEL_SHIFT              (9)
#define EQEP_QFRC_SEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_SEL_SHIFT)) & EQEP_QFRC_SEL_MASK)

#define EQEP_QFRC_IEL_MASK               (0x400U)
#define EQEP_QFRC_IEL_SHIFT              (10)
#define EQEP_QFRC_IEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_IEL_SHIFT)) & EQEP_QFRC_IEL_MASK)

#define EQEP_QFRC_UTO_MASK               (0x800U)
#define EQEP_QFRC_UTO_SHIFT              (11)
#define EQEP_QFRC_UTO_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_UTO_SHIFT)) & EQEP_QFRC_UTO_MASK)

#define EQEP_QFRC_QMAE_MASK               (0x1000U)
#define EQEP_QFRC_QMAE_SHIFT              (12)
#define EQEP_QFRC_QMAE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QFRC_QMAE_SHIFT)) & EQEP_QFRC_QMAE_MASK)

/*! @} */
/*! @name QEPSTS - eQEP Status Register  */
/*! @{ */
#define EQEP_QEPSTS_PCEF_MASK               (0x1U)
#define EQEP_QEPSTS_PCEF_SHIFT              (0)
#define EQEP_QEPSTS_PCEF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSTS_PCEF_SHIFT)) & EQEP_QEPSTS_PCEF_MASK)

#define EQEP_QEPSTS_FIMF_MASK               (0x2U)
#define EQEP_QEPSTS_FIMF_SHIFT              (1)
#define EQEP_QEPSTS_FIMF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSTS_FIMF_SHIFT)) & EQEP_QEPSTS_FIMF_MASK)

#define EQEP_QEPSTS_CDEF_MASK               (0x4U)
#define EQEP_QEPSTS_CDEF_SHIFT              (2)
#define EQEP_QEPSTS_CDEF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSTS_CDEF_SHIFT)) & EQEP_QEPSTS_CDEF_MASK)

#define EQEP_QEPSTS_COEF_MASK               (0x8U)
#define EQEP_QEPSTS_COEF_SHIFT              (3)
#define EQEP_QEPSTS_COEF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSTS_COEF_SHIFT)) & EQEP_QEPSTS_COEF_MASK)

#define EQEP_QEPSTS_QDLF_MASK               (0x10U)
#define EQEP_QEPSTS_QDLF_SHIFT              (4)
#define EQEP_QEPSTS_QDLF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSTS_QDLF_SHIFT)) & EQEP_QEPSTS_QDLF_MASK)

#define EQEP_QEPSTS_QDF_MASK               (0x20U)
#define EQEP_QEPSTS_QDF_SHIFT              (5)
#define EQEP_QEPSTS_QDF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSTS_QDF_SHIFT)) & EQEP_QEPSTS_QDF_MASK)

#define EQEP_QEPSTS_FIDF_MASK               (0x40U)
#define EQEP_QEPSTS_FIDF_SHIFT              (6)
#define EQEP_QEPSTS_FIDF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSTS_FIDF_SHIFT)) & EQEP_QEPSTS_FIDF_MASK)

#define EQEP_QEPSTS_UPEVNT_MASK               (0x80U)
#define EQEP_QEPSTS_UPEVNT_SHIFT              (7)
#define EQEP_QEPSTS_UPEVNT_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSTS_UPEVNT_SHIFT)) & EQEP_QEPSTS_UPEVNT_MASK)

/*! @} */
/*! @name QEPSRCSEL - eQEP Source Select Register  */
/*! @{ */
#define EQEP_QEPSRCSEL_QEPASEL_MASK               (0xfU)
#define EQEP_QEPSRCSEL_QEPASEL_SHIFT              (0)
#define EQEP_QEPSRCSEL_QEPASEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSRCSEL_QEPASEL_SHIFT)) & EQEP_QEPSRCSEL_QEPASEL_MASK)

#define EQEP_QEPSRCSEL_QEPBSEL_MASK               (0xf0U)
#define EQEP_QEPSRCSEL_QEPBSEL_SHIFT              (4)
#define EQEP_QEPSRCSEL_QEPBSEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSRCSEL_QEPBSEL_SHIFT)) & EQEP_QEPSRCSEL_QEPBSEL_MASK)

#define EQEP_QEPSRCSEL_QEPISEL_MASK               (0xf00U)
#define EQEP_QEPSRCSEL_QEPISEL_SHIFT              (8)
#define EQEP_QEPSRCSEL_QEPISEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSRCSEL_QEPISEL_SHIFT)) & EQEP_QEPSRCSEL_QEPISEL_MASK)

#define EQEP_QEPSRCSEL_QEPSSEL_MASK               (0xf000U)
#define EQEP_QEPSRCSEL_QEPSSEL_SHIFT              (12)
#define EQEP_QEPSRCSEL_QEPSSEL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << EQEP_QEPSRCSEL_QEPSSEL_SHIFT)) & EQEP_QEPSRCSEL_QEPSSEL_MASK)

/*!
 * @}
 */ /* end of group EQEP_Register_Masks */


/* EQEP - Peripheral instance base addresses */
/** Peripheral EQEP1 base address */
#define EQEP1_BASE                                (0x40040000u)
/** Peripheral EQEP1 base pointer */
#define EQEP1                                     ((EQEP_TypeDef *)EQEP1_BASE)
/** Peripheral EQEP2 base address */
#define EQEP2_BASE                                (0x400a6000u)
/** Peripheral EQEP2 base pointer */
#define EQEP2                                     ((EQEP_TypeDef *)EQEP2_BASE)
/** Array initializer of EQEP peripheral base addresses */
#define EQEP_BASE_ADDRS                           { EQEP1_BASE, EQEP2_BASE }
/** Array initializer of EQEP peripheral base pointers */
#define EQEP_BASE_PTRS                            { EQEP1, EQEP2 }
/** Interrupt vectors for the ADC peripheral type */
#define EQEP_IRQS                                 { EQEP1_IRQn, EQEP2_IRQn }

/*!
 *  * @}
 *   */ /* end of group EQEP_Peripheral_Access_Layer */





/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */
typedef struct {
        __IO uint32_t ADCPPBCONFIG;                     /**< ADC PPB Config Register  */
        __IO uint32_t ADCPPBSTAMP;                      /**< ADC PPB STAMP Register  */
        __IO uint32_t ADCPPBOFFCAL;                     /**< ADC PPB Offset Calibration Register  */
        __IO uint32_t ADCPPBOFFREF;                     /**< ADC PPB Offset Reference Register  */
        __IO uint32_t ADCPPBTRIPHI;                     /**< ADC PPB Trip High Register  */
        __IO uint32_t ADCPPBTRIPLO;                     /**< ADC PPB Trip Low Register  */
} ADCPPB_Type;
/** ADC - Result Register Layout Typedef */
typedef struct {
        __IO uint32_t ADCRESULT[16];                    /**< ADC Result Register, offset: 0x0 */
        __IO uint32_t ADCPPB1RESULT;                    /**< ADC PPB1 Register, offset: 0x40 */
        __IO uint32_t ADCPPB2RESULT;                    /**< ADC PPB2 Register, offset: 0x44 */
        __IO uint32_t ADCPPB3RESULT;                    /**< ADC PPB3 Register, offset: 0x48 */
        __IO uint32_t ADCPPB4RESULT;                    /**< ADC PPB4 Register, offset: 0x4C */
}ADCRESULT_TypeDef;
/** ADC - Register Layout Typedef */
typedef struct {
        __IO uint32_t ADCCTL1;                          /**< Control 1 Register, offset: 0x50 */
        __IO uint32_t ADCCTL2;                          /**< Control 2 Register, offset: 0x54 */
        __IO uint32_t ADCBURSTCTL;                      /**< Burst Control Register, offset: 0x58 */
        __I  uint32_t ADCINTFLG;                        /**< Interrupt Flag Register, offset: 0x5C */
        __IO uint32_t ADCINTFLGCLR;                     /**< Interrupt Flag Clear Register, offset: 0x60 */
        __I  uint32_t ADCINTOVF;                        /**< Interrupt Flag Register, offset: 0x64 */
        __IO uint32_t ADCINTOVFCLR;                     /**< Interrupt Overflow Flag Register, offset: 0x68 */
        __IO uint32_t ADCINTSEL1N2;                     /**< Interrupt 1 and 2 Selection Register, offset: 0x6C */
        __IO uint32_t ADCINTSEL3N4;                     /**< Interrupt 3 and 4 Selection Register, offset: 0x70 */
        __IO uint32_t ADCSOCPRICTL;                     /**< SOC Priority Control Register, offset: 0x74 */
        __IO uint32_t ADCINTSOCSEL1;                    /**< Interrupt SOC Selection 1 Register, offset: 0x78 */
        __IO uint32_t ADCINTSOCSEL2;                    /**< Interrupt SOC Selection 1 Register, offset: 0x7C */
        __IO uint32_t ADCSOCFLG1;                       /**< SOC Flag 1 Register, offset: 0x80 */
        __IO uint32_t ADCSOCFRC1;                       /**< SOC Force 1 Register, offset: 0x84 */
        __IO uint32_t ADCSOCOVF1;                       /**< SOC Overflow 1 Register, offset: 0x88 */
        __IO uint32_t ADCSOCOVFCLR1;                    /**< SOC Overflow Clear 1 Register, offset: 0x8C */
        __IO uint32_t ADCSOCCTL[16];                    /**< SOC Control Register, offset: 0x90 */
        __I  uint32_t ADCEVTSTAT;                       /**< Event Status Register, offset: 0xD0 */
        __IO uint32_t ADCEVTCLR;                        /**< Event Status Clear Register, offset: 0xD4 */
        __IO uint32_t ADCEVTSEL;                        /**< Event Select Register, offset: 0xD8 */
        __IO uint32_t ADCEVTINTSEL;                     /**< Event Interrupt Selection Register, offset: 0xDC */
        __IO uint32_t RESERVED1[4];
        ADCPPB_Type ADCPPB[4];                     /**< ADC PPB Register, offset: 0xF0 */
        __IO uint32_t ADCINTCYCLE;                      /**< ADC INT Cycle Register, offset: 0x150 */
} ADC_TypeDef;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */
/*! @name ADCRESULT - ADC RESULT Registers  */
/*! @{ */
#define ADC_RESULT_MASK                            (0xFFFFU)
#define ADC_RESULT_SHIFT                           (0)
/*! @} */

/*! @name ADCPPBRESULT - ADC PPB RESULT Registers  */
/*! @{ */
#define ADC_PPBRESULT_PPBRESULT_MASK               (0xFFFFU)
#define ADC_PPBRESULT_PPBRESULT_SHIFT              (0)
#define ADC_PPBRESULT_PPBRESULT_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_PPBRESULT_PPBRESULT_SHIFT)) & ADC_PPBRESULT_PPBRESULT_MASK)

#define ADC_PPBRESULT_SIGN_MASK                    (0xFFFF0000U)
#define ADC_PPBRESULT_SIGN_SHIFT                   (0)
#define ADC_PPBRESULT_SIGN_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PPBRESULT_SIGN_SHIFT)) & ADC_PPBRESULT_SIGN_MASK)
/*! @} */

/*! @name ADCCTL1 - ADC Control Registers  */
/*! @{ */
#define ADC_CTL1_INTPULSEPOS_MASK                  (0x4U)
#define ADC_CTL1_INTPULSEPOS_SHIFT                 (2)
#define ADC_CTL1_INTPULSEPOS_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_INTPULSEPOS_SHIFT)) & ADC_CTL1_INTPULSEPOS_MASK)

#define ADC_CTL1_RSTCLR_MASK                       (0x40U)
#define ADC_CTL1_RSTCLR_SHIFT                      (6)
#define ADC_CTL1_RSTCLR_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_RSTCLR_SHIFT)) & ADC_CTL1_RSTCLR_MASK)

#define ADC_CTL1_ADCPWDNZ_MASK                     (0x80U)
#define ADC_CTL1_ADCPWDNZ_SHIFT                    (7)
#define ADC_CTL1_ADCPWDNZ_SET(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_ADCPWDNZ_SHIFT)) & ADC_CTL1_ADCPWDNZ_MASK)

#define ADC_CTL1_ADCBSYCHN_MASK                    (0xF00U)
#define ADC_CTL1_ADCBSYCHN_SHIFT                   (8)
#define ADC_CTL1_ADCBSYCHN_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_ADCBSYCHN_SHIFT)) & ADC_CTL1_ADCBSYCHN_MASK)

#define ADC_CTL1_ADCBSY_MASK                       (0x2000U)
#define ADC_CTL1_ADCBSY_SHIFT                      (13)
#define ADC_CTL1_ADCBSY_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_ADCBSY_SHIFT)) & ADC_CTL1_ADCBSY_MASK)

#define ADC_CTL1_ADCINT1_MASK                      (0x10000U)
#define ADC_CTL1_ADCINT1_SHIFT                     (16)
#define ADC_CTL1_ADCINT1_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_ADCINT1_SHIFT)) & ADC_CTL1_ADCINT1_MASK)

#define ADC_CTL1_ADCINT2_MASK                      (0x20000U)
#define ADC_CTL1_ADCINT2_SHIFT                     (17)
#define ADC_CTL1_ADCINT2_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_ADCINT2_SHIFT)) & ADC_CTL1_ADCINT2_MASK)

#define ADC_CTL1_ADCINT3_MASK                      (0x40000U)
#define ADC_CTL1_ADCINT3_SHIFT                     (18)
#define ADC_CTL1_ADCINT3_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_ADCINT3_SHIFT)) & ADC_CTL1_ADCINT3_MASK)

#define ADC_CTL1_ADCINT4_MASK                      (0x80000U)
#define ADC_CTL1_ADCINT4_SHIFT                     (19)
#define ADC_CTL1_ADCINT4_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_ADCINT4_SHIFT)) & ADC_CTL1_ADCINT4_MASK)

#define ADC_CTL1_EVTINT_MASK                       (0x100000U)
#define ADC_CTL1_EVTINT_SHIFT                      (20)
#define ADC_CTL1_EVTINT_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CTL1_ECTINT_SHIFT)) & ADC_CTL1_EVTINT_MASK)
 
/*! @} */

/*! @name ADCCTL2 - ADC Control2 Registers  */
/*! @{ */

#define ADC_CTL2_PRESCALE_MASK                     (0xFU)
#define ADC_CTL2_PRESCALE_SHIFT                    (0)
#define ADC_CTL2_PRESCALE_SET(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CTL2_PRESCALE_SHIFT)) & ADC_CTL1_PRESCALE_MASK)

/*! @} */

/*! @name ADCBURSTCTL - ADC BURST Control Registers  */
/*! @{ */
#define ADC_BURSTCTL_BURSTTRIGSEL_MASK             (0x3FU)
#define ADC_BURSTCTL_BURSTTRIGSEL_SHIFT            (0)
#define ADC_BURSTCTL_BURSTTRIGSEL_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_BURSTCTL_BURSTTRIGSEL_SHIFT)) & ADC_BURSTCTL_BURSTTRIGSEL_MASK)

#define ADC_BURSTCTL_BURSTSIZE_MASK                (0xF00U)
#define ADC_BURSTCTL_BURSTSIZE_SHIFT               (8)
#define ADC_BURSTCTL_BURSTSIZE_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_BURSTCTL_BURSTSIZE_SHIFT)) & ADC_BURSTCTL_BURSTSIZE_MASK)

#define ADC_BURSTCTL_BURSTEN_MASK                  (0x8000U)
#define ADC_BURSTCTL_BURSTEN_SHIFT                 (15)
#define ADC_BURSTCTL_BURSTEN_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_BURSTCTL_BURSTEN_SHIFT)) & ADC_BURSTCTL_BURSTEN_MASK)

/*! @} */

/*! @name ADCINTFLG - ADC Interrupt Flag Registers  */
/*! @{ */

#define ADC_INTFLG_ADCINT1_MASK                    (0x1U)
#define ADC_INTFLG_ADCINT1_SHIFT                   (0)
#define ADC_INTFLG_ADCINT1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTFLG_ADCINT1_SHIFT)) & ADC_INTFLG_ADCINT1_MASK)

#define ADC_INTFLG_ADCINT2_MASK                    (0x2U)
#define ADC_INTFLG_ADCINT2_SHIFT                   (1)
#define ADC_INTFLG_ADCINT2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTFLG_ADCINT2_SHIFT)) & ADC_INTFLG_ADCINT2_MASK)

#define ADC_INTFLG_ADCINT3_MASK                    (0x4U)
#define ADC_INTFLG_ADCINT3_SHIFT                   (2)
#define ADC_INTFLG_ADCINT3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTFLG_ADCINT3_SHIFT)) & ADC_INTFLG_ADCINT3_MASK)

#define ADC_INTFLG_ADCINT4_MASK                    (0x8U)
#define ADC_INTFLG_ADCINT4_SHIFT                   (3)
#define ADC_INTFLG_ADCINT4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTFLG_ADCINT4_SHIFT)) & ADC_INTFLG_ADCINT4_MASK)
/*! @} */

/*! @name ADCINTFLGCLR - ADC Interrupt Flag Clear Registers  */
/*! @{ */

#define ADC_INTFLGCLR_ADCINT1_MASK                    (0x1U)
#define ADC_INTFLGCLR_ADCINT1_SHIFT                   (0)
#define ADC_INTFLGCLR_ADCINT1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTFLGCLR_ADCINT1_SHIFT)) & ADC_INTFLGCLR_ADCINT1_MASK)

#define ADC_INTFLGCLR_ADCINT2_MASK                    (0x2U)
#define ADC_INTFLGCLR_ADCINT2_SHIFT                   (1)
#define ADC_INTFLGCLR_ADCINT2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTFLGCLR_ADCINT2_SHIFT)) & ADC_INTFLGCLR_ADCINT2_MASK)

#define ADC_INTFLGCLR_ADCINT3_MASK                    (0x4U)
#define ADC_INTFLGCLR_ADCINT3_SHIFT                   (2)
#define ADC_INTFLGCLR_ADCINT3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTFLGCLR_ADCINT3_SHIFT)) & ADC_INTFLGCLR_ADCINT3_MASK)

#define ADC_INTFLGCLR_ADCINT4_MASK                    (0x8U)
#define ADC_INTFLGCLR_ADCINT4_SHIFT                   (3)
#define ADC_INTFLGCLR_ADCINT4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTFLGCLR_ADCINT4_SHIFT)) & ADC_INTFLGCLR_ADCINT4_MASK)

/*! @} */

/*! @name ADCINTOVF - ADC Interrupt Overflow Registers  */
/*! @{ */

#define ADC_INTOVF_ADCINT1_MASK                    (0x1U)
#define ADC_INTOVF_ADCINT1_SHIFT                   (0)
#define ADC_INTOVF_ADCINT1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTOVF_ADCINT1_SHIFT)) & ADC_INTOVF_ADCINT1_MASK)

#define ADC_INTOVF_ADCINT2_MASK                    (0x2U)
#define ADC_INTOVF_ADCINT2_SHIFT                   (1)
#define ADC_INTOVF_ADCINT2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTOVF_ADCINT2_SHIFT)) & ADC_INTOVF_ADCINT2_MASK)

#define ADC_INTOVF_ADCINT3_MASK                    (0x4U)
#define ADC_INTOVF_ADCINT3_SHIFT                   (2)
#define ADC_INTOVF_ADCINT3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTOVF_ADCINT3_SHIFT)) & ADC_INTOVF_ADCINT3_MASK)

#define ADC_INTOVF_ADCINT4_MASK                    (0x8U)
#define ADC_INTOVF_ADCINT4_SHIFT                   (3)
#define ADC_INTOVF_ADCINT4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTOVF_ADCINT4_SHIFT)) & ADC_INTOVF_ADCINT4_MASK)
/*! @} */

/*! @name ADCINTOVF - ADC Interrupt Overflow Registers  */
/*! @{ */

#define ADC_INTOVFCLR_ADCINT1_MASK                    (0x1U)
#define ADC_INTOVFCLR_ADCINT1_SHIFT                   (0)
#define ADC_INTOVFCLR_ADCINT1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTOVFCLR_ADCINT1_SHIFT)) & ADC_INTOVFCLR_ADCINT1_MASK)

#define ADC_INTOVFCLR_ADCINT2_MASK                    (0x2U)
#define ADC_INTOVFCLR_ADCINT2_SHIFT                   (1)
#define ADC_INTOVFCLR_ADCINT2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTOVFCLR_ADCINT2_SHIFT)) & ADC_INTOVFCLR_ADCINT2_MASK)

#define ADC_INTOVFCLR_ADCINT3_MASK                    (0x4U)
#define ADC_INTOVFCLR_ADCINT3_SHIFT                   (2)
#define ADC_INTOVFCLR_ADCINT3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTOVFCLR_ADCINT3_SHIFT)) & ADC_INTOVFCLR_ADCINT3_MASK)

#define ADC_INTOVFCLR_ADCINT4_MASK                    (0x8U)
#define ADC_INTOVFCLR_ADCINT4_SHIFT                   (3)
#define ADC_INTOVFCLR_ADCINT4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTOVFCLR_ADCINT4_SHIFT)) & ADC_INTOVFCLR_ADCINT4_MASK)

/*! @} */

/*! @name ADCINTSEL1N2 - ADC Interrupt 1and 2 selection Registers  */
/*! @{ */

#define ADC_INTSEL1N2_INT1SEL_MASK                    (0xFU)
#define ADC_INTSEL1N2_INT1SEL_SHIFT                   (0)
#define ADC_INTSEL1N2_INT1SEL_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL1N2_INT1SEL_SHIFT)) & ADC_INTSEL1N2_INT1SEL_MASK)

#define ADC_INTSEL1N2_INT1E_MASK                      (0x20U)
#define ADC_INTSEL1N2_INT1E_SHIFT                     (5)
#define ADC_INTSEL1N2_INT1E_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL1N2_INT1E_SHIFT)) & ADC_INTSEL1N2_INT1E_MASK)

#define ADC_INTSEL1N2_INT1CONT_MASK                   (0x40U)
#define ADC_INTSEL1N2_INT1CONT_SHIFT                  (6)
#define ADC_INTSEL1N2_INT1CONT_SET(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL1N2_INT1CONT_SHIFT)) & ADC_INTSEL1N2_INT1CONT_MASK)

#define ADC_INTSEL1N2_INT2SEL_MASK                    (0xF00U)
#define ADC_INTSEL1N2_INT2SEL_SHIFT                   (8)
#define ADC_INTSEL1N2_INT2SEL_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL1N2_INT2SEL_SHIFT)) & ADC_INTSEL1N2_INT2SEL_MASK)

#define ADC_INTSEL1N2_INT2E_MASK                      (0x2000U)
#define ADC_INTSEL1N2_INT2E_SHIFT                     (13)
#define ADC_INTSEL1N2_INT2E_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL1N2_INT2E_SHIFT)) & ADC_INTSEL1N2_INT2E_MASK)

#define ADC_INTSEL1N2_INT2CONT_MASK                   (0x4000U)
#define ADC_INTSEL1N2_INT2CONT_SHIFT                  (14)
#define ADC_INTSEL1N2_INT2CONT_SET(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL1N2_INT2CONT_SHIFT)) & ADC_INTSEL1N2_INT2CONT_MASK)
/*! @} */

/*! @name ADCINTSEL3N4 - ADC Interrupt 3 and 4 selection Registers  */
/*! @{ */

#define ADC_INTSEL3N4_INT3SEL_MASK                    (0xFU)
#define ADC_INTSEL3N4_INT3SEL_SHIFT                   (0)
#define ADC_INTSEL3N4_INT3SEL_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL3N4_INT3SEL_SHIFT)) & ADC_INTSEL3N4_INT3SEL_MASK)

#define ADC_INTSEL3N4_INT3E_MASK                      (0x20U)
#define ADC_INTSEL3N4_INT3E_SHIFT                     (5)
#define ADC_INTSEL3N4_INT3E_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL3N4_INT3E_SHIFT)) & ADC_INTSEL3N4_INT3E_MASK)

#define ADC_INTSEL3N4_INT3CONT_MASK                   (0x40U)
#define ADC_INTSEL3N4_INT3CONT_SHIFT                  (6)
#define ADC_INTSEL3N4_INT3CONT_SET(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL3N4_INT3CONT_SHIFT)) & ADC_INTSEL3N4_INT3CONT_MASK)

#define ADC_INTSEL3N4_INT4SEL_MASK                    (0xF00U)
#define ADC_INTSEL3N4_INT4SEL_SHIFT                   (8)
#define ADC_INTSEL3N4_INT4SEL_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL3N4_INT4SEL_SHIFT)) & ADC_INTSEL3N4_INT4SEL_MASK)

#define ADC_INTSEL3N4_INT4E_MASK                      (0x2000U)
#define ADC_INTSEL3N4_INT4E_SHIFT                     (13)
#define ADC_INTSEL3N4_INT4E_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL3N4_INT4E_SHIFT)) & ADC_INTSEL3N4_INT4E_MASK)

#define ADC_INTSEL3N4_INT4CONT_MASK                   (0x4000U)
#define ADC_INTSEL3N4_INT4CONT_SHIFT                  (14)
#define ADC_INTSEL3N4_INT4CONT_SET(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_INTSEL3N4_INT4CONT_SHIFT)) & ADC_INTSEL3N4_INT4CONT_MASK)

/*! @} */

/*! @name ADCSOCPRICTL - ADC SOC Priority Control Registers  */
/*! @{ */

#define ADC_SOCPRICTL_SOCPRIORITY_MASK             (0x1FU)
#define ADC_SOCPRICTL_SOCPRIORITY_SHIFT            (0)
#define ADC_SOCPRICTL_SOCPRIORITY_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SOCPRICTL_SOCPRIORITY_SHIFT)) & ADC_SOCPRICTL_SOCPRIORITY_MASK)

#define ADC_SOCPRICTL_RRPOINTER_MASK               (0x3E0U)
#define ADC_SOCPRICTL_RRPOINTER_SHIFT              (5)
#define ADC_SOCPRICTL_RRPOINTER_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_SOCPRICTL_RRPOINTER_SHIFT)) & ADC_SOCPRICTL_RRPOINTER_MASK)
/*! @} */

/*! @name ADCINTSOCSEL1 - ADC Interrupt SOC Selection1 Registers  */
/*! @{ */

#define ADC_INTSOCSEL1_SOC0_MASK             (0x3U)
#define ADC_INTSOCSEL1_SOC0_SHIFT            (0)
#define ADC_INTSOCSEL1_SOC0_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL1_SOC0_SHIFT)) & ADC_INTSOCSEL1_SOC0_MASK)

#define ADC_INTSOCSEL1_SOC1_MASK             (0xCU)
#define ADC_INTSOCSEL1_SOC1_SHIFT            (2)
#define ADC_INTSOCSEL1_SOC1_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL1_SOC1_SHIFT)) & ADC_INTSOCSEL1_SOC1_MASK)

#define ADC_INTSOCSEL1_SOC2_MASK             (0x30U)
#define ADC_INTSOCSEL1_SOC2_SHIFT            (4)
#define ADC_INTSOCSEL1_SOC2_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL1_SOC2_SHIFT)) & ADC_INTSOCSEL1_SOC2_MASK)

#define ADC_INTSOCSEL1_SOC3_MASK             (0xC0U)
#define ADC_INTSOCSEL1_SOC3_SHIFT            (6)
#define ADC_INTSOCSEL1_SOC3_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL1_SOC3_SHIFT)) & ADC_INTSOCSEL1_SOC3_MASK)

#define ADC_INTSOCSEL1_SOC4_MASK             (0x300U)
#define ADC_INTSOCSEL1_SOC4_SHIFT            (8)
#define ADC_INTSOCSEL1_SOC4_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL1_SOC4_SHIFT)) & ADC_INTSOCSEL1_SOC4_MASK)

#define ADC_INTSOCSEL1_SOC5_MASK             (0xC00U)
#define ADC_INTSOCSEL1_SOC5_SHIFT            (10)
#define ADC_INTSOCSEL1_SOC5_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL1_SOC5_SHIFT)) & ADC_INTSOCSEL1_SOC5_MASK)

#define ADC_INTSOCSEL1_SOC6_MASK             (0x3000U)
#define ADC_INTSOCSEL1_SOC6_SHIFT            (12)
#define ADC_INTSOCSEL1_SOC6_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL1_SOC6_SHIFT)) & ADC_INTSOCSEL1_SOC6_MASK)

#define ADC_INTSOCSEL1_SOC7_MASK             (0xC000U)
#define ADC_INTSOCSEL1_SOC7_SHIFT            (14)
#define ADC_INTSOCSEL1_SOC7_SET(x)               (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL1_SOC7_SHIFT)) & ADC_INTSOCSEL1_SOC7_MASK)
/*! @} */

/*! @name ADCINTSOCSEL2 - ADC Interrupt SOC Selection2 Registers  */
/*! @{ */

#define ADC_INTSOCSEL2_SOC8_MASK                 (0x3U)
#define ADC_INTSOCSEL2_SOC8_SHIFT                (0)
#define ADC_INTSOCSEL2_SOC8_SET(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL2_SOC8_SHIFT)) & ADC_INTSOCSEL2_SOC8_MASK)

#define ADC_INTSOCSEL2_SOC9_MASK                 (0xCU)
#define ADC_INTSOCSEL2_SOC9_SHIFT                (2)
#define ADC_INTSOCSEL2_SOC9_SET(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL2_SOC9_SHIFT)) & ADC_INTSOCSEL2_SOC9_MASK)

#define ADC_INTSOCSEL2_SOC10_MASK                (0x30U)
#define ADC_INTSOCSEL2_SOC10_SHIFT               (4)
#define ADC_INTSOCSEL2_SOC10_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL2_SOC10_SHIFT)) & ADC_INTSOCSEL2_SOC10_MASK)

#define ADC_INTSOCSEL2_SOC11_MASK                (0xC0U)
#define ADC_INTSOCSEL2_SOC11_SHIFT               (6)
#define ADC_INTSOCSEL2_SOC11_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL2_SOC11_SHIFT)) & ADC_INTSOCSEL2_SOC11_MASK)

#define ADC_INTSOCSEL2_SOC12_MASK                (0x300U)
#define ADC_INTSOCSEL2_SOC12_SHIFT               (8)
#define ADC_INTSOCSEL2_SOC12_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL2_SOC12_SHIFT)) & ADC_INTSOCSEL2_SOC12_MASK)

#define ADC_INTSOCSEL2_SOC13_MASK                (0xC00U)
#define ADC_INTSOCSEL2_SOC13_SHIFT               (10)
#define ADC_INTSOCSEL2_SOC13_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL2_SOC13_SHIFT)) & ADC_INTSOCSEL2_SOC13_MASK)

#define ADC_INTSOCSEL2_SOC14_MASK                (0x3000U)
#define ADC_INTSOCSEL2_SOC14_SHIFT               (12)
#define ADC_INTSOCSEL2_SOC14_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL2_SOC14_SHIFT)) & ADC_INTSOCSEL2_SOC14_MASK)

#define ADC_INTSOCSEL2_SOC15_MASK                (0xC000U)
#define ADC_INTSOCSEL2_SOC15_SHIFT               (14)
#define ADC_INTSOCSEL2_SOC15_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTSOCSEL2_SOC15_SHIFT)) & ADC_INTSOCSEL2_SOC15_MASK)
/*! @} */

/*! @name ADCSOCFLG1 - ADC SOC Flag1 Registers  */
/*! @{ */

#define ADC_SOCFLG1_SOC0_MASK                    (1)
#define ADC_SOCFLG1_SOC0_SHIFT                   (0)
#define ADC_SOCFLG1_SOC0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC0_SHIFT)) & ADC_SOCFLG1_SOC0_MASK)

#define ADC_SOCFLG1_SOC1_MASK                    (2)
#define ADC_SOCFLG1_SOC1_SHIFT                   (1)
#define ADC_SOCFLG1_SOC1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC1_SHIFT)) & ADC_SOCFLG1_SOC1_MASK)

#define ADC_SOCFLG1_SOC2_MASK                    (0x4U)
#define ADC_SOCFLG1_SOC2_SHIFT                   (2)
#define ADC_SOCFLG1_SOC2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC2_SHIFT)) & ADC_SOCFLG1_SOC2_MASK)

#define ADC_SOCFLG1_SOC3_MASK                    (0x8U)
#define ADC_SOCFLG1_SOC3_SHIFT                   (3)
#define ADC_SOCFLG1_SOC3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC3_SHIFT)) & ADC_SOCFLG1_SOC3_MASK)

#define ADC_SOCFLG1_SOC4_MASK                    (0x10U)
#define ADC_SOCFLG1_SOC4_SHIFT                   (4)
#define ADC_SOCFLG1_SOC4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC4_SHIFT)) & ADC_SOCFLG1_SOC4_MASK)

#define ADC_SOCFLG1_SOC5_MASK                    (0x20U)
#define ADC_SOCFLG1_SOC5_SHIFT                   (5)
#define ADC_SOCFLG1_SOC5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC5_SHIFT)) & ADC_SOCFLG1_SOC5_MASK)

#define ADC_SOCFLG1_SOC6_MASK                    (0x40U)
#define ADC_SOCFLG1_SOC6_SHIFT                   (6)
#define ADC_SOCFLG1_SOC6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC6_SHIFT)) & ADC_SOCFLG1_SOC6_MASK)

#define ADC_SOCFLG1_SOC7_MASK                    (0x80U)
#define ADC_SOCFLG1_SOC7_SHIFT                   (7)
#define ADC_SOCFLG1_SOC7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC7_SHIFT)) & ADC_SOCFLG1_SOC7_MASK)

#define ADC_SOCFLG1_SOC8_MASK                    (0x100U)
#define ADC_SOCFLG1_SOC8_SHIFT                   (8)
#define ADC_SOCFLG1_SOC8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC8_SHIFT)) & ADC_SOCFLG1_SOC8_MASK)

#define ADC_SOCFLG1_SOC9_MASK                    (0x200U)
#define ADC_SOCFLG1_SOC9_SHIFT                   (9)
#define ADC_SOCFLG1_SOC9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC9_SHIFT)) & ADC_SOCFLG1_SOC9_MASK)

#define ADC_SOCFLG1_SOC10_MASK                    (0x400U)
#define ADC_SOCFLG1_SOC10_SHIFT                   (10)
#define ADC_SOCFLG1_SOC10_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC10_SHIFT)) & ADC_SOCFLG1_SOC10_MASK)

#define ADC_SOCFLG1_SOC11_MASK                    (0x800U)
#define ADC_SOCFLG1_SOC11_SHIFT                   (11)
#define ADC_SOCFLG1_SOC11_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC11_SHIFT)) & ADC_SOCFLG1_SOC11_MASK)

#define ADC_SOCFLG1_SOC12_MASK                    (0x1000U)
#define ADC_SOCFLG1_SOC12_SHIFT                   (12)
#define ADC_SOCFLG1_SOC12_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC12_SHIFT)) & ADC_SOCFLG1_SOC12_MASK)

#define ADC_SOCFLG1_SOC13_MASK                    (0x2000U)
#define ADC_SOCFLG1_SOC13_SHIFT                   (13)
#define ADC_SOCFLG1_SOC13_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC13_SHIFT)) & ADC_SOCFLG1_SOC13_MASK)

#define ADC_SOCFLG1_SOC14_MASK                    (0x4000U)
#define ADC_SOCFLG1_SOC14_SHIFT                   (14)
#define ADC_SOCFLG1_SOC14_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC14_SHIFT)) & ADC_SOCFLG1_SOC14_MASK)

#define ADC_SOCFLG1_SOC15_MASK                    (0x8000U)
#define ADC_SOCFLG1_SOC15_SHIFT                   (15)
#define ADC_SOCFLG1_SOC15_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFLG1_SOC15_SHIFT)) & ADC_SOCFLG1_SOC15_MASK)
/*! @} */

/*! @name ADCSOCFRC1 - ADC SOC Force1 Registers  */
/*! @{ */

#define ADC_SOCFRC1_SOC0_MASK                    (1)
#define ADC_SOCFRC1_SOC0_SHIFT                   (0)
#define ADC_SOCFRC1_SOC0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC0_SHIFT)) & ADC_SOCFRC1_SOC0_MASK)

#define ADC_SOCFRC1_SOC1_MASK                    (2)
#define ADC_SOCFRC1_SOC1_SHIFT                   (1)
#define ADC_SOCFRC1_SOC1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC1_SHIFT)) & ADC_SOCFRC1_SOC1_MASK)

#define ADC_SOCFRC1_SOC2_MASK                    (0x4U)
#define ADC_SOCFRC1_SOC2_SHIFT                   (2)
#define ADC_SOCFRC1_SOC2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC2_SHIFT)) & ADC_SOCFRC1_SOC2_MASK)

#define ADC_SOCFRC1_SOC3_MASK                    (0x8U)
#define ADC_SOCFRC1_SOC3_SHIFT                   (3)
#define ADC_SOCFRC1_SOC3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC3_SHIFT)) & ADC_SOCFRC1_SOC3_MASK)

#define ADC_SOCFRC1_SOC4_MASK                    (0x10U)
#define ADC_SOCFRC1_SOC4_SHIFT                   (4)
#define ADC_SOCFRC1_SOC4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC4_SHIFT)) & ADC_SOCFRC1_SOC4_MASK)

#define ADC_SOCFRC1_SOC5_MASK                    (0x20U)
#define ADC_SOCFRC1_SOC5_SHIFT                   (5)
#define ADC_SOCFRC1_SOC5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC5_SHIFT)) & ADC_SOCFRC1_SOC5_MASK)

#define ADC_SOCFRC1_SOC6_MASK                    (0x40U)
#define ADC_SOCFRC1_SOC6_SHIFT                   (6)
#define ADC_SOCFRC1_SOC6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC6_SHIFT)) & ADC_SOCFRC1_SOC6_MASK)

#define ADC_SOCFRC1_SOC7_MASK                    (0x80U)
#define ADC_SOCFRC1_SOC7_SHIFT                   (7)
#define ADC_SOCFRC1_SOC7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC7_SHIFT)) & ADC_SOCFRC1_SOC7_MASK)

#define ADC_SOCFRC1_SOC8_MASK                    (0x100U)
#define ADC_SOCFRC1_SOC8_SHIFT                   (8)
#define ADC_SOCFRC1_SOC8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC8_SHIFT)) & ADC_SOCFRC1_SOC8_MASK)

#define ADC_SOCFRC1_SOC9_MASK                    (0x200U)
#define ADC_SOCFRC1_SOC9_SHIFT                   (9)
#define ADC_SOCFRC1_SOC9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC9_SHIFT)) & ADC_SOCFRC1_SOC9_MASK)

#define ADC_SOCFRC1_SOC10_MASK                    (0x400U)
#define ADC_SOCFRC1_SOC10_SHIFT                   (10)
#define ADC_SOCFRC1_SOC10_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC10_SHIFT)) & ADC_SOCFRC1_SOC10_MASK)

#define ADC_SOCFRC1_SOC11_MASK                    (0x800U)
#define ADC_SOCFRC1_SOC11_SHIFT                   (11)
#define ADC_SOCFRC1_SOC11_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC11_SHIFT)) & ADC_SOCFRC1_SOC11_MASK)

#define ADC_SOCFRC1_SOC12_MASK                    (0x1000U)
#define ADC_SOCFRC1_SOC12_SHIFT                   (12)
#define ADC_SOCFRC1_SOC12_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC12_SHIFT)) & ADC_SOCFRC1_SOC12_MASK)

#define ADC_SOCFRC1_SOC13_MASK                    (0x2000U)
#define ADC_SOCFRC1_SOC13_SHIFT                   (13)
#define ADC_SOCFRC1_SOC13_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC13_SHIFT)) & ADC_SOCFRC1_SOC13_MASK)

#define ADC_SOCFRC1_SOC14_MASK                    (0x4000U)
#define ADC_SOCFRC1_SOC14_SHIFT                   (14)
#define ADC_SOCFRC1_SOC14_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC14_SHIFT)) & ADC_SOCFRC1_SOC14_MASK)

#define ADC_SOCFRC1_SOC15_MASK                    (0x8000U)
#define ADC_SOCFRC1_SOC15_SHIFT                   (15)
#define ADC_SOCFRC1_SOC15_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_SOC15_SHIFT)) & ADC_SOCFRC1_SOC15_MASK)

#define ADC_SOCFRC1_BURST_MASK                    (0x10000U)
#define ADC_SOCFRC1_BURST_SHIFT                   (16)
#define ADC_SOCFRC1_BURST_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SOCFRC1_BURST_SHIFT)) & ADC_SOCFRC1_BURST_MASK)

/*! @} */

/*! @name ADCSOCOVF1 - ADC SOC Overflow1 Registers  */
/*! @{ */                                                                                                                                    

#define ADC_SOCOVF1_SOC0_MASK                    (1)
#define ADC_SOCOVF1_SOC0_SHIFT                   (0)
#define ADC_SOCOVF1_SOC0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC0_SHIFT)) & ADC_SOCOVF1_SOC0_MASK)

#define ADC_SOCOVF1_SOC1_MASK                    (2)
#define ADC_SOCOVF1_SOC1_SHIFT                   (1)
#define ADC_SOCOVF1_SOC1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC1_SHIFT)) & ADC_SOCOVF1_SOC1_MASK)

#define ADC_SOCOVF1_SOC2_MASK                    (0x4U)
#define ADC_SOCOVF1_SOC2_SHIFT                   (2)
#define ADC_SOCOVF1_SOC2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC2_SHIFT)) & ADC_SOCOVF1_SOC2_MASK)

#define ADC_SOCOVF1_SOC3_MASK                    (0x8U)
#define ADC_SOCOVF1_SOC3_SHIFT                   (3)
#define ADC_SOCOVF1_SOC3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC3_SHIFT)) & ADC_SOCOVF1_SOC3_MASK)

#define ADC_SOCOVF1_SOC4_MASK                    (0x10U)
#define ADC_SOCOVF1_SOC4_SHIFT                   (4)
#define ADC_SOCOVF1_SOC4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC4_SHIFT)) & ADC_SOCOVF1_SOC4_MASK)

#define ADC_SOCOVF1_SOC5_MASK                    (0x20U)
#define ADC_SOCOVF1_SOC5_SHIFT                   (5)
#define ADC_SOCOVF1_SOC5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC5_SHIFT)) & ADC_SOCOVF1_SOC5_MASK)

#define ADC_SOCOVF1_SOC6_MASK                    (0x40U)
#define ADC_SOCOVF1_SOC6_SHIFT                   (6)
#define ADC_SOCOVF1_SOC6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC6_SHIFT)) & ADC_SOCOVF1_SOC6_MASK)

#define ADC_SOCOVF1_SOC7_MASK                    (0x80U)
#define ADC_SOCOVF1_SOC7_SHIFT                   (7)
#define ADC_SOCOVF1_SOC7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC7_SHIFT)) & ADC_SOCOVF1_SOC7_MASK)

#define ADC_SOCOVF1_SOC8_MASK                    (0x100U)
#define ADC_SOCOVF1_SOC8_SHIFT                   (8)
#define ADC_SOCOVF1_SOC8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC8_SHIFT)) & ADC_SOCOVF1_SOC8_MASK)

#define ADC_SOCOVF1_SOC9_MASK                    (0x200U)
#define ADC_SOCOVF1_SOC9_SHIFT                   (9)
#define ADC_SOCOVF1_SOC9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC9_SHIFT)) & ADC_SOCOVF1_SOC9_MASK)

#define ADC_SOCOVF1_SOC10_MASK                    (0x400U)
#define ADC_SOCOVF1_SOC10_SHIFT                   (10)
#define ADC_SOCOVF1_SOC10_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC10_SHIFT)) & ADC_SOCOVF1_SOC10_MASK)

#define ADC_SOCOVF1_SOC11_MASK                    (0x800U)
#define ADC_SOCOVF1_SOC11_SHIFT                   (11)
#define ADC_SOCOVF1_SOC11_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC11_SHIFT)) & ADC_SOCOVF1_SOC11_MASK)

#define ADC_SOCOVF1_SOC12_MASK                    (0x1000U)
#define ADC_SOCOVF1_SOC12_SHIFT                   (12)
#define ADC_SOCOVF1_SOC12_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC12_SHIFT)) & ADC_SOCOVF1_SOC12_MASK)

#define ADC_SOCOVF1_SOC13_MASK                    (0x2000U)
#define ADC_SOCOVF1_SOC13_SHIFT                   (13)
#define ADC_SOCOVF1_SOC13_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC13_SHIFT)) & ADC_SOCOVF1_SOC13_MASK)

#define ADC_SOCOVF1_SOC14_MASK                    (0x4000U)
#define ADC_SOCOVF1_SOC14_SHIFT                   (14)
#define ADC_SOCOVF1_SOC14_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC14_SHIFT)) & ADC_SOCOVF1_SOC14_MASK)

#define ADC_SOCOVF1_SOC15_MASK                    (0x8000U)
#define ADC_SOCOVF1_SOC15_SHIFT                   (15)
#define ADC_SOCOVF1_SOC15_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVF1_SOC15_SHIFT)) & ADC_SOCOVF1_SOC15_MASK)

/*! @} */

/*! @name ADCSOCOVFCLR - ADC SOC Overflow Clear Registers  */
/*! @{ */

#define ADC_SOCOVFCLR1_SOC0_MASK                    (1)
#define ADC_SOCOVFCLR1_SOC0_SHIFT                   (0)
#define ADC_SOCOVFCLR1_SOC0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC0_SHIFT)) & ADC_SOCOVFCLR1_SOC0_MASK)

#define ADC_SOCOVFCLR1_SOC1_MASK                    (2)
#define ADC_SOCOVFCLR1_SOC1_SHIFT                   (1)
#define ADC_SOCOVFCLR1_SOC1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC1_SHIFT)) & ADC_SOCOVFCLR1_SOC1_MASK)

#define ADC_SOCOVFCLR1_SOC2_MASK                    (0x4U)
#define ADC_SOCOVFCLR1_SOC2_SHIFT                   (2)
#define ADC_SOCOVFCLR1_SOC2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC2_SHIFT)) & ADC_SOCOVFCLR1_SOC2_MASK)

#define ADC_SOCOVFCLR1_SOC3_MASK                    (0x8U)
#define ADC_SOCOVFCLR1_SOC3_SHIFT                   (3)
#define ADC_SOCOVFCLR1_SOC3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC3_SHIFT)) & ADC_SOCOVFCLR1_SOC3_MASK)

#define ADC_SOCOVFCLR1_SOC4_MASK                    (0x10U)
#define ADC_SOCOVFCLR1_SOC4_SHIFT                   (4)
#define ADC_SOCOVFCLR1_SOC4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC4_SHIFT)) & ADC_SOCOVFCLR1_SOC4_MASK)

#define ADC_SOCOVFCLR1_SOC5_MASK                    (0x20U)
#define ADC_SOCOVFCLR1_SOC5_SHIFT                   (5)
#define ADC_SOCOVFCLR1_SOC5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC5_SHIFT)) & ADC_SOCOVFCLR1_SOC5_MASK)

#define ADC_SOCOVFCLR1_SOC6_MASK                    (0x40U)
#define ADC_SOCOVFCLR1_SOC6_SHIFT                   (6)
#define ADC_SOCOVFCLR1_SOC6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC6_SHIFT)) & ADC_SOCOVFCLR1_SOC6_MASK)

#define ADC_SOCOVFCLR1_SOC7_MASK                    (0x80U)
#define ADC_SOCOVFCLR1_SOC7_SHIFT                   (7)
#define ADC_SOCOVFCLR1_SOC7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC7_SHIFT)) & ADC_SOCOVFCLR1_SOC7_MASK)

#define ADC_SOCOVFCLR1_SOC8_MASK                    (0x100U)
#define ADC_SOCOVFCLR1_SOC8_SHIFT                   (8)
#define ADC_SOCOVFCLR1_SOC8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC8_SHIFT)) & ADC_SOCOVFCLR1_SOC8_MASK)

#define ADC_SOCOVFCLR1_SOC9_MASK                    (0x200U)
#define ADC_SOCOVFCLR1_SOC9_SHIFT                   (9)
#define ADC_SOCOVFCLR1_SOC9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC9_SHIFT)) & ADC_SOCOVFCLR1_SOC9_MASK)

#define ADC_SOCOVFCLR1_SOC10_MASK                    (0x400U)
#define ADC_SOCOVFCLR1_SOC10_SHIFT                   (10)
#define ADC_SOCOVFCLR1_SOC10_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC10_SHIFT)) & ADC_SOCOVFCLR1_SOC10_MASK)

#define ADC_SOCOVFCLR1_SOC11_MASK                    (0x800U)
#define ADC_SOCOVFCLR1_SOC11_SHIFT                   (11)
#define ADC_SOCOVFCLR1_SOC11_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC11_SHIFT)) & ADC_SOCOVFCLR1_SOC11_MASK)

#define ADC_SOCOVFCLR1_SOC12_MASK                    (0x1000U)
#define ADC_SOCOVFCLR1_SOC12_SHIFT                   (12)
#define ADC_SOCOVFCLR1_SOC12_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC12_SHIFT)) & ADC_SOCOVFCLR1_SOC12_MASK)

#define ADC_SOCOVFCLR1_SOC13_MASK                    (0x2000U)
#define ADC_SOCOVFCLR1_SOC13_SHIFT                   (13)
#define ADC_SOCOVFCLR1_SOC13_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC13_SHIFT)) & ADC_SOCOVFCLR1_SOC13_MASK)

#define ADC_SOCOVFCLR1_SOC14_MASK                    (0x4000U)
#define ADC_SOCOVFCLR1_SOC14_SHIFT                   (14)
#define ADC_SOCOVFCLR1_SOC14_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC14_SHIFT)) & ADC_SOCOVFCLR1_SOC14_MASK)

#define ADC_SOCOVFCLR1_SOC15_MASK                    (0x8000U)
#define ADC_SOCOVFCLR1_SOC15_SHIFT                   (15)
#define ADC_SOCOVFCLR1_SOC15_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SOCOVFCLR1_SOC15_SHIFT)) & ADC_SOCOVFCLR1_SOC15_MASK)

/*! @} */

/*! @name ADCSOCCTL - ADC SOC Control Registers  */
/*! @{ */

#define ADC_SOCCTL_ACQPS_MASK                      (0x1FFU)
#define ADC_SOCCTL_ACQPS_SHIFT                     (0U)
#define ADC_SOCCTL_ACQPS_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SOCCTL_ACQPS_SHIFT)) & ADC_SOCCTL_ACQPS_MASK)

#define ADC_SOCCTL_CHSEL_MASK                      (0x78000U)
#define ADC_SOCCTL_CHSEL_SHIFT                     (15U)
#define ADC_SOCCTL_CHSEL_SET(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SOCCTL_CHSEL_SHIFT)) & ADC_SOCCTL_CHSEL_MASK)

#define ADC_SOCCTL_TRIGSEL_MASK                  (0x1F00000U)
#define ADC_SOCCTL_TRIGSEL_SHIFT                 (20U)
#define ADC_SOCCTL_TRIGSEL_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_SOCCTL_TRIGSEL_SHIFT)) & ADC_SOCCTL_TRIGSEL_MASK)

/*! @} */

/*! @name ADCEVTSTAT, ADCEVTCLR, ADCEVTSEL, ADCEVTINTSEL - ADC EVENT Registers  */
/*! @{ */

#define ADC_EVT_PPB1TRIPHI_MASK                  (0x1U)
#define ADC_EVT_PPB1TRIPHI_SHIFT                 (0U)
#define ADC_EVT_PPB1TRIPHI_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB1TRIPHI_SHIFT)) & ADC_EVT_PPB1TRIPHI_MASK)

#define ADC_EVT_PPB1TRIPLO_MASK                  (0x2U)
#define ADC_EVT_PPB1TRIPLO_SHIFT                 (1U)
#define ADC_EVT_PPB1TRIPLO_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB1TRIPLO_SHIFT)) & ADC_EVT_PPB1TRIPLO_MASK)

#define ADC_EVT_PPB1ZERO_MASK                 (0x4U)
#define ADC_EVT_PPB1ZERO_SHIFT                (2U)
#define ADC_EVT_PPB1ZERO_SET(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB1ZERO_SHIFT)) & ADC_EVT_PPB1ZERO_MASK)

#define ADC_EVT_PPB2TRIPHI_MASK                  (0x10U)
#define ADC_EVT_PPB2TRIPHI_SHIFT                 (4U)
#define ADC_EVT_PPB2TRIPHI_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB2TRIPHI_SHIFT)) & ADC_EVT_PPB2TRIPHI_MASK)

#define ADC_EVT_PPB2TRIPLO_MASK                  (0x20U)
#define ADC_EVT_PPB2TRIPLO_SHIFT                 (5U)
#define ADC_EVT_PPB2TRIPLO_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB2TRIPLO_SHIFT)) & ADC_EVT_PPB2TRIPLO_MASK)

#define ADC_EVT_PPB2ZERO_MASK                 (0x40U)
#define ADC_EVT_PPB2ZERO_SHIFT                (6U)
#define ADC_EVT_PPB2ZERO_SET(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB2ZERO_SHIFT)) & ADC_EVT_PPB2ZERO_MASK)

#define ADC_EVT_PPB3TRIPHI_MASK                  (0x100U)
#define ADC_EVT_PPB3TRIPHI_SHIFT                 (8U)
#define ADC_EVT_PPB3TRIPHI_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB3TRIPHI_SHIFT)) & ADC_EVT_PPB3TRIPHI_MASK)

#define ADC_EVT_PPB3TRIPLO_MASK                  (0x200U)
#define ADC_EVT_PPB3TRIPLO_SHIFT                 (9U)
#define ADC_EVT_PPB3TRIPLO_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB3TRIPLO_SHIFT)) & ADC_EVT_PPB3TRIPLO_MASK)

#define ADC_EVT_PPB3ZERO_MASK                 (0x400U)
#define ADC_EVT_PPB3ZERO_SHIFT                (10U)
#define ADC_EVT_PPB3ZERO_SET(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB3ZERO_SHIFT)) & ADC_EVT_PPB3ZERO_MASK)

#define ADC_EVT_PPB4TRIPHI_MASK                  (0x1000U)
#define ADC_EVT_PPB4TRIPHI_SHIFT                 (12U)
#define ADC_EVT_PPB4TRIPHI_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB4TRIPHI_SHIFT)) & ADC_EVT_PPB4TRIPHI_MASK)

#define ADC_EVT_PPB4TRIPLO_MASK                  (0x2000U)
#define ADC_EVT_PPB4TRIPLO_SHIFT                 (13U)
#define ADC_EVT_PPB4TRIPLO_SET(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB4TRIPLO_SHIFT)) & ADC_EVT_PPB4TRIPLO_MASK)

#define ADC_EVT_PPB4ZERO_MASK                 (0x4000U)
#define ADC_EVT_PPB4ZERO_SHIFT                (14U)
#define ADC_EVT_PPB4ZERO_SET(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_EVT_PPB4ZERO_SHIFT)) & ADC_EVT_PPB4ZERO_MASK)

/*! @} */

/*! @name ADCOSDETECT - ADC Open-short Detect Registers  */
/*! @{ */

#define ADC_OSDETECT_DETECTCFG_MASK              (0x7U)
#define ADC_OSDETECT_DETECTCFG_SHIFT             (0U)
#define ADC_OSDETECT_DETECTCFG_SET(x)                (((uint32_t)(((uint32_t)(x)) << ADC_OSDETECT_DETECTCFG_SHIFT)) & ADC_OSDETECT_DETECTCFG_MASK)

/*! @} */

/*! @name ADCCOUNTER - ADC Free Running Counter Registers  */
/*! @{ */

#define ADC_COUNTER_FREECOUNT_MASK               (0xfffU)
#define ADC_COUNTER_FREECOUNT_SHIFT              (0U)
#define ADC_COUNTER_FREECOUNT_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_COUNTER_FREECOUNT_SHIFT)) & ADC_COUNTER_FREECOUNT_MASK)

/*! @} */

/*! @name ADCPPBCONFIG - ADC PPB Config Registers  */
/*! @{ */

#define ADC_PPBCONFIG_CONFIG_MASK                (0xFU)
#define ADC_PPBCONFIG_CONFIG_SHIFT               (0U)
#define ADC_PPBCONFIG_CONFIG_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_PPBCONFIG_CONFIG_SHIFT)) & ADC_PPBCONFIG_CONFIG_MASK)

#define ADC_PPBCONFIG_TWOSCOMPEN_MASK            (0x10U)
#define ADC_PPBCONFIG_TWOSCOMPEN_SHIFT           (4U)
#define ADC_PPBCONFIG_TWOSCOMPEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << ADC_PPBCONFIG_TWOSCOMPEN_SHIFT)) & ADC_PPBCONFIG_TWOSCOMPEN_MASK)

#define ADC_PPBCONFIG_CBCEN_MASK                 (0x20U)
#define ADC_PPBCONFIG_CBCEN_SHIFT                (5U)
#define ADC_PPBCONFIG_CBCEN_SET(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_PPBCONFIG_CBCEN_SHIFT)) & ADC_PPBCONFIG_CBCEN_MASK)

/*! @} */

/*! @name ADCPPBSTAMP - ADC PPB Delay Stamp Registers  */
/*! @{ */

#define ADC_PPBSTAMP_DLYSTAMP_MASK               (0xFFFU)
#define ADC_PPBSTAMP_DLYSTAMP_SHIFT              (0U)
#define ADC_PPBSTAMP_DLYSTAMP_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_PPBSTAMP_DLYSTAMP_SHIFT)) & ADC_PPBSTAMP_DLYSTAMP_MASK)

/*! @} */

/*! @name ADCPPBOFFCAL - ADC PPB OFFSET CALIBRATE Registers  */
/*! @{ */

#define ADC_PPBOFFCAL_OFFCAL_MASK               (0x3FFU)
#define ADC_PPBOFFCAL_OFFCAL_SHIFT              (0U)
#define ADC_PPBOFFCAL_OFFCAL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_PPBOFFCAL_OFFCAL_SHIFT)) & ADC_PPBOFFCAL_OFFCAL_MASK)

/*! @} */

/*! @name ADCPPBOFFREF - ADC PPB OFFSET REFERENCE Registers  */
/*! @{ */

#define ADC_PPBOFFREF_OFFREF_MASK               (0xFFFU)
#define ADC_PPBOFFREF_OFFREF_SHIFT              (0U)
#define ADC_PPBOFFREF_OFFREF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_PPBOFFREF_OFFREF_SHIFT)) & ADC_PPBOFFREF_OFFREF_MASK)

/*! @} */

/*! @name ADCPPBTRIPHI - ADC PPB Trip Higher Registers  */
/*! @{ */

#define ADC_PPBTRIPHI_LIMITHI_MASK              (0xFFFFU)
#define ADC_PPBTRIPHI_LIMITHI_SHIFT             (0U)
#define ADC_PPBTRIPHI_LIMITHI_SET(x)                (((uint32_t)(((uint32_t)(x)) << ADC_PPBTRIPHI_LIMITHI_SHIFT)) & ADC_PPBTRIPHI_LIMITHI_MASK)

#define ADC_PPBTRIPHI_HSIGN_MASK                (0x10000U)
#define ADC_PPBTRIPHI_HSIGN_SHIFT               (16U)
#define ADC_PPBTRIPHI_HSIGN_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_PPBTRIPHI_HSIGN_SHIFT)) & ADC_PPBTRIPHI_HSIGN_MASK)

/*! @} */

/*! @name ADCPPBTRIPLO - ADC PPB Trip Lower Registers  */
/*! @{ */

#define ADC_PPBTRIPLO_LIMITLO_MASK              (0xFFFFU)
#define ADC_PPBTRIPLO_LIMITLO_SHIFT             (0U)
#define ADC_PPBTRIPLO_LIMITLO_SET(x)                (((uint32_t)(((uint32_t)(x)) << ADC_PPBTRIPLO_LIMITLO_SHIFT)) & ADC_PPBTRIPLO_LIMITLO_MASK)

#define ADC_PPBTRIPLO_LSIGN_MASK                (0x10000U)
#define ADC_PPBTRIPLO_LSIGN_SHIFT               (16U)
#define ADC_PPBTRIPLO_LSIGN_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_PPBTRIPLO_LSIGN_SHIFT)) & ADC_PPBTRIPLO_LSIGN_MASK)

#define ADC_PPBTRIPLO_REQSTAMP_MASK                (0xFFF00000U)
#define ADC_PPBTRIPLO_REQSTAMP_SHIFT               (20U)
#define ADC_PPBTRIPLO_REQSTAMP_SET(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_PPBTRIPLO_REQSTAMP_SHIFT)) & ADC_PPBTRIPLO_REQSTAMP_MASK)

/*! @} */

/*! @name ADCINTCYCLE - ADC int cycle Registers  */
/*! @{ */

#define ADC_INTCYCLE_DELAY_MASK              (0xFFFFU)
#define ADC_INTCYCLE_DELAY_SHIFT             (0U)
#define ADC_INTCYCLE_DELAY_SET(x)                (((uint32_t)(((uint32_t)(x)) << ADC_INTCYCLE_DELAY_SHIFT)) & ADC_INTCYCLE_DELAY_MASK)

/*! @} */

/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC1RESULT_BASE                          (0x4003B000u)
#define ADC1_BASE                                (0x4003B050u)
#define ADCA_BASE                                ADC1_BASE
#define ADCARESULT_BASE                          ADC1RESULT_BASE
/** Peripheral ADC0 base pointer */
#define ADC1RESULT                               ((ADCRESULT_TypeDef *)ADC1RESULT_BASE)
#define ADCARESULT                               ADC1RESULT
#define ADC1                                     ((ADC_TypeDef *)ADC1_BASE)
#define ADCA                                     ADC1
/** Peripheral ADC1 base address */
#define ADC2RESULT_BASE                          (0x4003C000u)
#define ADC2_BASE                                (0x4003C050u)
#define ADCB_BASE                                ADC2_BASE
#define ADCBRESULT_BASE                          ADC2RESULT_BASE
/** Peripheral ADC1 base pointer */
#define ADC2RESULT                               ((ADCRESULT_TypeDef *)ADC2RESULT_BASE)
#define ADCBRESULT                               ADC2RESULT
#define ADC2                                     ((ADC_TypeDef *)ADC2_BASE)
#define ADCB                                     ADC2
/** Peripheral ADC3 base address */
#define ADC3RESULT_BASE                          (0x400BB000u)
#define ADC3_BASE                                (0x400BB050u)
#define ADCC_BASE                                ADC3_BASE
#define ADCCRESULT_BASE                          ADC3RESULT_BASE
/** Peripheral ADC3 base pointer */
#define ADC3RESULT                               ((ADCRESULT_TypeDef *)ADC3RESULT_BASE)
#define ADCCRESULT                               ADC3RESULT
#define ADC3                                     ((ADC_TypeDef *)ADC3_BASE)
#define ADCC                                     ADC3         
/** Array initializer of ADC peripheral base addresses */
#define ADCRESULT_BASE_ADDRS                     { ADCARESULT_BASE, ADCBRESULT_BASE, ADCCRESULT_BASE }
#define ADC_BASE_ADDRS                           { ADCA_BASE, ADCB_BASE, ADCC_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADCA, ADCB, ADCC }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADCA_IRQn, ADCB_IRQn, ADCC_IRQn }

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Peripheral_Access_Layer CMP Peripheral Access Layer
 * @{
 */

/** CMP - Register Layout Typedef */
typedef struct {
  __IO uint32_t ACMPCON1;                         /**< Control 1 Register, offset: 0x0 >**/
  __IO uint32_t ACMPCON2;                         /**< Control 2 Register, offset: 0x4 >**/
  __IO uint32_t ACMPCFG;                          /**< Config Register, offset: 0x8 >**/
       uint32_t Reserved; 
  __IO uint32_t ACMPIMSC;                         /**< Interrupt Enable Register, offset: 0x10 >**/ 
  __IO uint32_t ACMPRIS;                          /**< Primary Status Register, offset: 0x14 >**/ 
  __I  uint32_t ACMPMIS;                          /**< Status Register, offset: 0x18 >**/ 

} CMP_Type;

/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Masks CMP Register Masks
 * @{
 */

/*! @name CON1 - CMP Control Register 1 */
/*! @{ */
#define ACMP_CON1_INTMODE_MASK                         (0x3U)
#define ACMP_CON1_INTMODE_SHIFT                        (0U)
#define ACMP_CON1_INTMODE_SET(x)                           (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_INTMODE_SHIFT)) & ACMP_CON1_INTMODE_MASK)

#define ACMP_CON1_SPEED_MASK                           (0x8U)
#define ACMP_CON1_SPEED_SHIFT                          (3U)
#define ACMP_CON1_SPEED_SET(x)                             (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_SPEED_SHIFT)) & ACMP_CON1_SPEED_MASK)

#define ACMP_CON1_PROG_MASK                            (0x30U)
#define ACMP_CON1_PROG_SHIFT                           (4U)
#define ACMP_CON1_PROG_SET(x)                              (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_PROG_SHIFT)) & ACMP_CON1_PROG_MASK)

#define ACMP_CON1_PWD_MASK                             (0x400U)
#define ACMP_CON1_PWD_SHIFT                            (10U)
#define ACMP_CON1_PWD_SET(x)                               (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_PWD_SHIFT)) & ACMP_CON1_PWD_MASK)

#define ACMP_CON1_FLTEN_MASK                           (0x800U)
#define ACMP_CON1_FLTEN_SHIFT                          (11U)
#define ACMP_CON1_FLTEN_SET(x)                             (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_FLTEN_SHIFT)) & ACMP_CON1_FLTEN_MASK)

#define ACMP_CON1_FILTER_MASK                          (0xFF000U)
#define ACMP_CON1_FILTER_SHIFT                         (12U)
#define ACMP_CON1_FILTER_SET(x)                            (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_FILTER_SHIFT)) & ACMP_CON1_FILTER_MASK)

#define ACMP_CON1_BLANKW_MASK                          (0xFF00000U)
#define ACMP_CON1_BLANKW_SHIFT                         (20U)
#define ACMP_CON1_BLANKW_SET(x)                            (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_BLANKW_SHIFT)) & ACMP_CON1_BLANKW_MASK)
 
#define ACMP_CON1_BLANKSEL_MASK                        (0x70000000U)
#define ACMP_CON1_BLANKSEL_SHIFT                       (28U)
#define ACMP_CON1_BLANKSEL_SET(x)                          (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_BLANKSEL_SHIFT)) & ACMP_CON1_BLANKSEL_MASK)

#define ACMP_CON1_BLANKEN_MASK                         (0x80000000U)
#define ACMP_CON1_BLANKEN_SHIFT                        (31U)
#define ACMP_CON1_BLANKEN_SET(x)                           (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_BLANKEN_SHIFT)) & ACMP_CON1_BLANKEN_MASK)

/*! @} */
/*! @name CON2 - ACMP Control Register 2 */
/*! @{ */
#define ACMP_CON2_INTMODE_MASK                         (0x3U)
#define ACMP_CON2_INTMODE_SHIFT                        (0U)
#define ACMP_CON2_INTMODE_SET(x)                           (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_INTMODE_SHIFT)) & ACMP_CON1_INTMODE_MASK)

#define ACMP_CON2_SPEED_MASK                           (0x8U)
#define ACMP_CON2_SPEED_SHIFT                          (3U)
#define ACMP_CON2_SPEED_SET(x)                             (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_SPEED_SHIFT)) & ACMP_CON1_SPEED_MASK)

#define ACMP_CON2_PROG_MASK                            (0x30U)
#define ACMP_CON2_PROG_SHIFT                           (4U)
#define ACMP_CON2_PROG_SET(x)                              (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_PROG_SHIFT)) & ACMP_CON1_PROG_MASK)

#define ACMP_CON2_PWD_MASK                             (0x400U)
#define ACMP_CON2_PWD_SHIFT                            (10U)
#define ACMP_CON2_PWD_SET(x)                               (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_PWD_SHIFT)) & ACMP_CON1_PWD_MASK)

#define ACMP_CON2_FLTEN_MASK                           (0x800U)
#define ACMP_CON2_FLTEN_SHIFT                          (11U)
#define ACMP_CON2_FLTEN_SET(x)                             (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_FLTEN_SHIFT)) & ACMP_CON1_FLTEN_MASK)

#define ACMP_CON2_FILTER_MASK                          (0xFF000U)
#define ACMP_CON2_FILTER_SHIFT                         (12U)
#define ACMP_CON2_FILTER_SET(x)                            (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_FILTER_SHIFT)) & ACMP_CON1_FILTER_MASK)

#define ACMP_CON2_BLANKW_MASK                          (0xFF00000U)
#define ACMP_CON2_BLANKW_SHIFT                         (20U)
#define ACMP_CON2_BLANKW_SET(x)                            (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_BLANKW_SHIFT)) & ACMP_CON1_BLANKW_MASK)

#define ACMP_CON2_BLANKSEL_MASK                        (0x70000000U)
#define ACMP_CON2_BLANKSEL_SHIFT                       (28U)
#define ACMP_CON2_BLANKSEL_SET(x)                          (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_BLANKSEL_SHIFT)) & ACMP_CON1_BLANKSEL_MASK)

#define ACMP_CON2_BLANKEN_MASK                         (0x80000000U)
#define ACMP_CON2_BLANKEN_SHIFT                        (31U)
#define ACMP_CON2_BLANKEN_SET(x)                           (((uint32_t)(((uint32_t)(x)) << ACMP_CON1_BLANKEN_SHIFT)) & ACMP_CON1_BLANKEN_MASK)

/*! @} */
/*! @name CFG - ACMP Config Register */
/*! @{ */
#define ACMP_CFG_WINMODEEN_MASK                        (0x1U)
#define ACMP_CFG_WINMODEEN_SHIFT                       (0U)
#define ACMP_CFG_WINMODEEN_SET(x)                          (((uint32_t)(((uint32_t)(x)) << ACMP_CFG_WINMODEEN_SHIFT)) & ACMP_CFG_WINMODEEN_MASK)

#define ACMP_CFG_ACMP1POLAR_MASK                        (0x2U)
#define ACMP_CFG_ACMP1POLAR_SHIFT                       (1U)
#define ACMP_CFG_ACMP1POLAR_SET(x)                          (((uint32_t)(((uint32_t)(x)) << ACMP_CFG_ACMP1POLAR_SHIFT)) & ACMP_CFG_ACMP1POLAR_MASK)

#define ACMP_CFG_ACMP2POLAR_MASK                        (0x4U)
#define ACMP_CFG_ACMP2POLAR_SHIFT                       (2U)
#define ACMP_CFG_ACMP2POLAR_SET(x)                          (((uint32_t)(((uint32_t)(x)) << ACMP_CFG_ACMP2POLAR_SHIFT)) & ACMP_CFG_ACMP2POLAR_MASK) 

#define ACMP_CFG_WINOUTEN_MASK                         (0x8U)
#define ACMP_CFG_WINOUTEN_SHIFT                        (3U)
#define ACMP_CFG_WINOUTEN_SET(x)                           (((uint32_t)(((uint32_t)(x)) << ACMP_CFG_WINOUTEN_SHIFT)) & ACMP_CFG_WINOUTEN_MASK) 

#define ACMP_CFG_ACMP1EN_MASK                           (0x10U)
#define ACMP_CFG_ACMP1EN_SHIFT                          (4U)
#define ACMP_CFG_ACMP1EN_SET(x)                             (((uint32_t)(((uint32_t)(x)) << ACMP_CFG_ACMP1EN_SHIFT)) & ACMP_CFG_ACMP1EN_MASK) 

#define ACMP_CFG_ACMP2EN_MASK                           (0x20U)
#define ACMP_CFG_ACMP2EN_SHIFT                          (5U)
#define ACMP_CFG_ACMP2EN_SET(x)                             (((uint32_t)(((uint32_t)(x)) << ACMP_CFG_ACMP2EN_SHIFT)) & ACMP_CFG_ACMP2EN_MASK) 

#define ACMP_CFG_ACMP1PREBLANK_MASK                     (0x40U)
#define ACMP_CFG_ACMP1PREBLANK_SHIFT                    (6U)
#define ACMP_CFG_ACMP1PREBLANK_SET(x)                       (((uint32_t)(((uint32_t)(x)) << ACMP_CFG_ACMP1PREBLANK_SHIFT)) & ACMP_CFG_ACMP1PREBLANK_MASK) 

#define ACMP_CFG_ACMP2PREBLANK_MASK                     (0x80U)
#define ACMP_CFG_ACMP2PREBLANK_SHIFT                    (7U)
#define ACMP_CFG_ACMP2PREBLANK_SET(x)                       (((uint32_t)(((uint32_t)(x)) << ACMP_CFG_ACMP2PREBLANK_SHIFT)) & ACMP_CFG_ACMP2PREBLANK_MASK) 
/*! @} */
/*! @name IMSC - ACMP Interrupt Enable Register */
/*! @{ */

#define ACMP_IMSC_ACMP1IMSC_MASK                       (0x1U)
#define ACMP_IMSC_ACMP1IMSC_SHIFT                      (0U)
#define ACMP_IMSC_ACMP1IMSC_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ACMP_IMSC_ACMP1IMSC_SHIFT)) & ACMP_IMSC_ACMP1IMSC_MASK) 

#define ACMP_IMSC_ACMP2IMSC_MASK                       (0x2U)
#define ACMP_IMSC_ACMP2IMSC_SHIFT                      (1U)
#define ACMP_IMSC_ACMP2IMSC_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ACMP_IMSC_ACMP2IMSC_SHIFT)) & ACMP_IMSC_ACMP2IMSC_MASK) 

/*! @} */
/*! @name RIS - ACMP Primary Interrupt Status Register */
/*! @{ */
#define ACMP_RIS_ACMP1RIS_MASK                       (0x1U)
#define ACMP_RIS_ACMP1RIS_SHIFT                      (0U)
#define ACMP_RIS_ACMP1RIS_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ACMP_RIS_ACMP1RIS_SHIFT)) & ACMP_RIS_ACMP1RIS_MASK) 

#define ACMP_RIS_ACMP2RIS_MASK                       (0x2U)
#define ACMP_RIS_ACMP2RIS_SHIFT                      (1U)
#define ACMP_RIS_ACMP2RIS_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ACMP_RIS_ACMP2RIS_SHIFT)) & ACMP_RIS_ACMP2RIS_MASK) 


/*! @} */
/*! @name MIS - ACMP Interrupt Status Register */
/*! @{ */

#define ACMP_MIS_ACMP1MIS_MASK                       (0x1U)
#define ACMP_MIS_ACMP1MIS_SHIFT                      (0U)
#define ACMP_MIS_ACMP1MIS_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ACMP_MIS_ACMP1MIS_SHIFT)) & ACMP_MIS_ACMP1MIS_MASK) 

#define ACMP_MIS_ACMP2MIS_MASK                       (0x2U)
#define ACMP_MIS_ACMP2MIS_SHIFT                      (1U)
#define ACMP_MIS_ACMP2MIS_SET(x)                         (((uint32_t)(((uint32_t)(x)) << ACMP_MIS_ACMP2MIS_SHIFT)) & ACMP_MIS_ACMP2MIS_MASK) 

/*! @} */

/*!
 * @}
 */ /* end of group ACMP_Register_Masks */


/* ACMP - Peripheral instance base addresses */
/** Peripheral CMP1 base address */
#define CMP_BASE                                (0x400BA000u)
/** Peripheral CMP1 base pointer */
#define CMP                                     ((CMP_Type *)CMP_BASE)

/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { CMP_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP }
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { CMP_IRQn }

/*!
 * @}
 */ /* end of group CMP_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */

/** CRC - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint8_t DATALL;                             /**< CRC_DATALL register., offset: 0x0 */
      __IO uint8_t DATALU;                             /**< CRC_DATALU register., offset: 0x1 */
      __IO uint8_t DATAHL;                             /**< CRC_DATAHL register., offset: 0x2 */
      __IO uint8_t DATAHU;                             /**< CRC_DATAHU register., offset: 0x3 */
    } ACCESS8BIT;
    struct {                                         /* offset: 0x0 */
      __IO uint16_t DATAL;                             /**< CRC_DATAL register., offset: 0x0 */
      __IO uint16_t DATAH;                             /**< CRC_DATAH register., offset: 0x2 */
    } ACCESS16BIT;
    __IO uint32_t DATA;                              /**< CRC Data register, offset: 0x0 */
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint8_t GPOLYLL;                            /**< CRC_GPOLYLL register., offset: 0x4 */
      __IO uint8_t GPOLYLU;                            /**< CRC_GPOLYLU register., offset: 0x5 */
      __IO uint8_t GPOLYHL;                            /**< CRC_GPOLYHL register., offset: 0x6 */
      __IO uint8_t GPOLYHU;                            /**< CRC_GPOLYHU register., offset: 0x7 */
    } GPOLY_ACCESS8BIT;
    struct {                                         /* offset: 0x4 */
      __IO uint16_t GPOLYL;                            /**< CRC_GPOLYL register., offset: 0x4 */
      __IO uint16_t GPOLYH;                            /**< CRC_GPOLYH register., offset: 0x6 */
    } GPOLY_ACCESS16BIT;
    __IO uint32_t GPOLY;                             /**< CRC Polynomial register, offset: 0x4 */
  };
  union {                                          /* offset: 0x8 */
    struct {                                         /* offset: 0x8 */
           uint8_t RESERVED_0[3];
      __IO uint8_t CTRLHU;                             /**< CRC_CTRLHU register., offset: 0xB */
    } CTRL_ACCESS8BIT;
    __IO uint32_t CTRL;                              /**< CRC Control register, offset: 0x8 */
  };
} CRC_Type;

/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/*! @name DATALL - CRC_DATALL register. */
/*! @{ */

#define CRC_DATALL_DATALL_MASK                   (0xFFU)
#define CRC_DATALL_DATALL_SHIFT                  (0U)
/*! DATALL - CRCLL stores the first 8 bits of the 32 bit DATA
 */
#define CRC_DATALL_DATALL_SET(x)                     (((uint8_t)(((uint8_t)(x)) << CRC_DATALL_DATALL_SHIFT)) & CRC_DATALL_DATALL_MASK)
/*! @} */

/*! @name DATALU - CRC_DATALU register. */
/*! @{ */

#define CRC_DATALU_DATALU_MASK                   (0xFFU)
#define CRC_DATALU_DATALU_SHIFT                  (0U)
/*! DATALU - DATALL stores the second 8 bits of the 32 bit CRC
 */
#define CRC_DATALU_DATALU_SET(x)                     (((uint8_t)(((uint8_t)(x)) << CRC_DATALU_DATALU_SHIFT)) & CRC_DATALU_DATALU_MASK)
/*! @} */

/*! @name DATAHL - CRC_DATAHL register. */
/*! @{ */

#define CRC_DATAHL_DATAHL_MASK                   (0xFFU)
#define CRC_DATAHL_DATAHL_SHIFT                  (0U)
/*! DATAHL - DATAHL stores the third 8 bits of the 32 bit CRC
 */
#define CRC_DATAHL_DATAHL_SET(x)                     (((uint8_t)(((uint8_t)(x)) << CRC_DATAHL_DATAHL_SHIFT)) & CRC_DATAHL_DATAHL_MASK)
/*! @} */

/*! @name DATAHU - CRC_DATAHU register. */
/*! @{ */

#define CRC_DATAHU_DATAHU_MASK                   (0xFFU)
#define CRC_DATAHU_DATAHU_SHIFT                  (0U)
/*! DATAHU - DATAHU stores the fourth 8 bits of the 32 bit CRC
 */
#define CRC_DATAHU_DATAHU_SET(x)                     (((uint8_t)(((uint8_t)(x)) << CRC_DATAHU_DATAHU_SHIFT)) & CRC_DATAHU_DATAHU_MASK)
/*! @} */

/*! @name DATAL - CRC_DATAL register. */
/*! @{ */

#define CRC_DATAL_DATAL_MASK                     (0xFFFFU)
#define CRC_DATAL_DATAL_SHIFT                    (0U)
/*! DATAL - DATAL stores the lower 16 bits of the 16/32 bit CRC
 */
#define CRC_DATAL_DATAL_SET(x)                       (((uint16_t)(((uint16_t)(x)) << CRC_DATAL_DATAL_SHIFT)) & CRC_DATAL_DATAL_MASK)
/*! @} */

/*! @name DATAH - CRC_DATAH register. */
/*! @{ */

#define CRC_DATAH_DATAH_MASK                     (0xFFFFU)
#define CRC_DATAH_DATAH_SHIFT                    (0U)
/*! DATAH - DATAH stores the high 16 bits of the 16/32 bit CRC
 */
#define CRC_DATAH_DATAH_SET(x)                       (((uint16_t)(((uint16_t)(x)) << CRC_DATAH_DATAH_SHIFT)) & CRC_DATAH_DATAH_MASK)
/*! @} */

/*! @name DATA - CRC Data register */
/*! @{ */

#define CRC_DATA_LL_MASK                         (0xFFU)
#define CRC_DATA_LL_SHIFT                        (0U)
/*! LL - CRC Low Lower Byte
 */
#define CRC_DATA_LL_SET(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_DATA_LL_SHIFT)) & CRC_DATA_LL_MASK)

#define CRC_DATA_LU_MASK                         (0xFF00U)
#define CRC_DATA_LU_SHIFT                        (8U)
/*! LU - CRC Low Upper Byte
 */
#define CRC_DATA_LU_SET(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_DATA_LU_SHIFT)) & CRC_DATA_LU_MASK)

#define CRC_DATA_HL_MASK                         (0xFF0000U)
#define CRC_DATA_HL_SHIFT                        (16U)
/*! HL - CRC High Lower Byte
 */
#define CRC_DATA_HL_SET(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_DATA_HL_SHIFT)) & CRC_DATA_HL_MASK)

#define CRC_DATA_HU_MASK                         (0xFF000000U)
#define CRC_DATA_HU_SHIFT                        (24U)
/*! HU - CRC High Upper Byte
 */
#define CRC_DATA_HU_SET(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_DATA_HU_SHIFT)) & CRC_DATA_HU_MASK)
/*! @} */

/*! @name GPOLYLL - CRC_GPOLYLL register. */
/*! @{ */

#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFU)
#define CRC_GPOLYLL_GPOLYLL_SHIFT                (0U)
/*! GPOLYLL - POLYLL stores the first 8 bits of the 32 bit CRC
 */
#define CRC_GPOLYLL_GPOLYLL_SET(x)                   (((uint8_t)(((uint8_t)(x)) << CRC_GPOLYLL_GPOLYLL_SHIFT)) & CRC_GPOLYLL_GPOLYLL_MASK)
/*! @} */

/*! @name GPOLYLU - CRC_GPOLYLU register. */
/*! @{ */

#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFU)
#define CRC_GPOLYLU_GPOLYLU_SHIFT                (0U)
/*! GPOLYLU - POLYLL stores the second 8 bits of the 32 bit CRC
 */
#define CRC_GPOLYLU_GPOLYLU_SET(x)                   (((uint8_t)(((uint8_t)(x)) << CRC_GPOLYLU_GPOLYLU_SHIFT)) & CRC_GPOLYLU_GPOLYLU_MASK)
/*! @} */

/*! @name GPOLYHL - CRC_GPOLYHL register. */
/*! @{ */

#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFU)
#define CRC_GPOLYHL_GPOLYHL_SHIFT                (0U)
/*! GPOLYHL - POLYHL stores the third 8 bits of the 32 bit CRC
 */
#define CRC_GPOLYHL_GPOLYHL_SET(x)                   (((uint8_t)(((uint8_t)(x)) << CRC_GPOLYHL_GPOLYHL_SHIFT)) & CRC_GPOLYHL_GPOLYHL_MASK)
/*! @} */

/*! @name GPOLYHU - CRC_GPOLYHU register. */
/*! @{ */

#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFU)
#define CRC_GPOLYHU_GPOLYHU_SHIFT                (0U)
/*! GPOLYHU - POLYHU stores the fourth 8 bits of the 32 bit CRC
 */
#define CRC_GPOLYHU_GPOLYHU_SET(x)                   (((uint8_t)(((uint8_t)(x)) << CRC_GPOLYHU_GPOLYHU_SHIFT)) & CRC_GPOLYHU_GPOLYHU_MASK)
/*! @} */

/*! @name GPOLYL - CRC_GPOLYL register. */
/*! @{ */

#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFU)
#define CRC_GPOLYL_GPOLYL_SHIFT                  (0U)
/*! GPOLYL - POLYL stores the lower 16 bits of the 16/32 bit CRC polynomial value
 */
#define CRC_GPOLYL_GPOLYL_SET(x)                     (((uint16_t)(((uint16_t)(x)) << CRC_GPOLYL_GPOLYL_SHIFT)) & CRC_GPOLYL_GPOLYL_MASK)
/*! @} */

/*! @name GPOLYH - CRC_GPOLYH register. */
/*! @{ */

#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFU)
#define CRC_GPOLYH_GPOLYH_SHIFT                  (0U)
/*! GPOLYH - POLYH stores the high 16 bits of the 16/32 bit CRC polynomial value
 */
#define CRC_GPOLYH_GPOLYH_SET(x)                     (((uint16_t)(((uint16_t)(x)) << CRC_GPOLYH_GPOLYH_SHIFT)) & CRC_GPOLYH_GPOLYH_MASK)
/*! @} */

/*! @name GPOLY - CRC Polynomial register */
/*! @{ */

#define CRC_GPOLY_LOW_MASK                       (0xFFFFU)
#define CRC_GPOLY_LOW_SHIFT                      (0U)
/*! LOW - Low Polynominal Half-word
 */
#define CRC_GPOLY_LOW_SET(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_GPOLY_LOW_SHIFT)) & CRC_GPOLY_LOW_MASK)

#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000U)
#define CRC_GPOLY_HIGH_SHIFT                     (16U)
/*! HIGH - High Polynominal Half-word
 */
#define CRC_GPOLY_HIGH_SET(x)                        (((uint32_t)(((uint32_t)(x)) << CRC_GPOLY_HIGH_SHIFT)) & CRC_GPOLY_HIGH_MASK)
/*! @} */

/*! @name CTRLHU - CRC_CTRLHU register. */
/*! @{ */

#define CRC_CTRLHU_TCRC_MASK                     (0x1U)
#define CRC_CTRLHU_TCRC_SHIFT                    (0U)
/*! TCRC
 *  0b0..16-bit CRC protocol.
 *  0b1..32-bit CRC protocol.
 */
#define CRC_CTRLHU_TCRC_SET(x)                       (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_TCRC_SHIFT)) & CRC_CTRLHU_TCRC_MASK)

#define CRC_CTRLHU_WAS_MASK                      (0x2U)
#define CRC_CTRLHU_WAS_SHIFT                     (1U)
/*! WAS
 *  0b0..Writes to CRC data register are data values.
 *  0b1..Writes to CRC data reguster are seed values.
 */
#define CRC_CTRLHU_WAS_SET(x)                        (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_WAS_SHIFT)) & CRC_CTRLHU_WAS_MASK)

#define CRC_CTRLHU_FXOR_MASK                     (0x4U)
#define CRC_CTRLHU_FXOR_SHIFT                    (2U)
/*! FXOR
 *  0b0..No XOR on reading.
 *  0b1..Invert or complement the read value of CRC data register.
 */
#define CRC_CTRLHU_FXOR_SET(x)                       (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_FXOR_SHIFT)) & CRC_CTRLHU_FXOR_MASK)

#define CRC_CTRLHU_TOTR_MASK                     (0x30U)
#define CRC_CTRLHU_TOTR_SHIFT                    (4U)
/*! TOTR
 *  0b00..No Transposition.
 *  0b01..Bits in bytes are transposed, bytes are not transposed.
 *  0b10..Both bits in bytes and bytes are transposed.
 *  0b11..Only bytes are transposed; no bits in a byte are transposed.
 */
#define CRC_CTRLHU_TOTR_SET(x)                       (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_TOTR_SHIFT)) & CRC_CTRLHU_TOTR_MASK)

#define CRC_CTRLHU_TOT_MASK                      (0xC0U)
#define CRC_CTRLHU_TOT_SHIFT                     (6U)
/*! TOT
 *  0b00..No Transposition.
 *  0b01..Bits in bytes are transposed, bytes are not transposed.
 *  0b10..Both bits in bytes and bytes are transposed.
 *  0b11..Only bytes are transposed; no bits in a byte are transposed.
 */
#define CRC_CTRLHU_TOT_SET(x)                        (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_TOT_SHIFT)) & CRC_CTRLHU_TOT_MASK)
/*! @} */

/*! @name CTRL - CRC Control register */
/*! @{ */

#define CRC_CTRL_TCRC_MASK                       (0x1000000U)
#define CRC_CTRL_TCRC_SHIFT                      (24U)
/*! TCRC
 *  0b0..16-bit CRC protocol.
 *  0b1..32-bit CRC protocol.
 */
#define CRC_CTRL_TCRC_SET(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TCRC_SHIFT)) & CRC_CTRL_TCRC_MASK)

#define CRC_CTRL_WAS_MASK                        (0x2000000U)
#define CRC_CTRL_WAS_SHIFT                       (25U)
/*! WAS - Write CRC Data Register As Seed
 *  0b0..Writes to the CRC data register are data values.
 *  0b1..Writes to the CRC data register are seed values.
 */
#define CRC_CTRL_WAS_SET(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_WAS_SHIFT)) & CRC_CTRL_WAS_MASK)

#define CRC_CTRL_FXOR_MASK                       (0x4000000U)
#define CRC_CTRL_FXOR_SHIFT                      (26U)
/*! FXOR - Complement Read Of CRC Data Register
 *  0b0..No XOR on reading.
 *  0b1..Invert or complement the read value of the CRC Data register.
 */
#define CRC_CTRL_FXOR_SET(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_FXOR_SHIFT)) & CRC_CTRL_FXOR_MASK)

#define CRC_CTRL_TOTR_MASK                       (0x30000000U)
#define CRC_CTRL_TOTR_SHIFT                      (28U)
/*! TOTR - Type Of Transpose For Read
 *  0b00..No transposition.
 *  0b01..Bits in bytes are transposed; bytes are not transposed.
 *  0b10..Both bits in bytes and bytes are transposed.
 *  0b11..Only bytes are transposed; no bits in a byte are transposed.
 */
#define CRC_CTRL_TOTR_SET(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TOTR_SHIFT)) & CRC_CTRL_TOTR_MASK)

#define CRC_CTRL_TOT_MASK                        (0xC0000000U)
#define CRC_CTRL_TOT_SHIFT                       (30U)
/*! TOT - Type Of Transpose For Writes
 *  0b00..No transposition.
 *  0b01..Bits in bytes are transposed; bytes are not transposed.
 *  0b10..Both bits in bytes and bytes are transposed.
 *  0b11..Only bytes are transposed; no bits in a byte are transposed.
 */
#define CRC_CTRL_TOT_SET(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TOT_SHIFT)) & CRC_CTRL_TOT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40032000u)
/** Peripheral CRC base pointer */
#define CRC                                     ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC }

/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control Register, offset: 0x0 */
  __I  uint32_t ES;                                /**< Error Status Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ERQ;                               /**< Enable Request Register, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t EEI;                               /**< Enable Error Interrupt Register, offset: 0x14 */
  __O  uint8_t CEEI;                               /**< Clear Enable Error Interrupt Register, offset: 0x18 */
  __O  uint8_t SEEI;                               /**< Set Enable Error Interrupt Register, offset: 0x19 */
  __O  uint8_t CERQ;                               /**< Clear Enable Request Register, offset: 0x1A */
  __O  uint8_t SERQ;                               /**< Set Enable Request Register, offset: 0x1B */
  __O  uint8_t CDNE;                               /**< Clear DONE Status Bit Register, offset: 0x1C */
  __O  uint8_t SSRT;                               /**< Set START Bit Register, offset: 0x1D */
  __O  uint8_t CERR;                               /**< Clear Error Register, offset: 0x1E */
  __O  uint8_t CINT;                               /**< Clear Interrupt Request Register, offset: 0x1F */
       uint8_t RESERVED_2[4];
  __IO uint32_t INT;                               /**< Interrupt Request Register, offset: 0x24 */
       uint8_t RESERVED_3[4];
  __IO uint32_t ERR;                               /**< Error Register, offset: 0x2C */
       uint8_t RESERVED_4[4];
  __I  uint32_t HRS;                               /**< Hardware Request Status Register, offset: 0x34 */
       uint8_t RESERVED_5[12];
  __IO uint32_t EARS;                              /**< Enable Asynchronous Request in Stop Register, offset: 0x44 */
       uint8_t RESERVED_6[184];
  __IO uint8_t DCHPRI3;                            /**< Channel n Priority Register, offset: 0x100 */
  __IO uint8_t DCHPRI2;                            /**< Channel n Priority Register, offset: 0x101 */
  __IO uint8_t DCHPRI1;                            /**< Channel n Priority Register, offset: 0x102 */
  __IO uint8_t DCHPRI0;                            /**< Channel n Priority Register, offset: 0x103 */
  __IO uint8_t DCHPRI7;                            /**< Channel n Priority Register, offset: 0x104 */
  __IO uint8_t DCHPRI6;                            /**< Channel n Priority Register, offset: 0x105 */
  __IO uint8_t DCHPRI5;                            /**< Channel n Priority Register, offset: 0x106 */
  __IO uint8_t DCHPRI4;                            /**< Channel n Priority Register, offset: 0x107 */
  __IO uint8_t DCHPRI11;                           /**< Channel n Priority Register, offset: 0x108 */
  __IO uint8_t DCHPRI10;                           /**< Channel n Priority Register, offset: 0x109 */
  __IO uint8_t DCHPRI9;                            /**< Channel n Priority Register, offset: 0x10A */
  __IO uint8_t DCHPRI8;                            /**< Channel n Priority Register, offset: 0x10B */
  __IO uint8_t DCHPRI15;                           /**< Channel n Priority Register, offset: 0x10C */
  __IO uint8_t DCHPRI14;                           /**< Channel n Priority Register, offset: 0x10D */
  __IO uint8_t DCHPRI13;                           /**< Channel n Priority Register, offset: 0x10E */
  __IO uint8_t DCHPRI12;                           /**< Channel n Priority Register, offset: 0x10F */
       uint8_t RESERVED_7[3824];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    __IO uint32_t SADDR;                             /**< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLNO;                       /**< TCD Minor Byte Count (Minor Loop Mapping Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    __IO int32_t SLAST;                              /**< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    __IO uint32_t DADDR;                             /**< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
    };
    __IO int32_t DLAST_SGA;                          /**< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    __IO uint16_t CSR;                               /**< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[16];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name CR - Control Register */
/*! @{ */

#define DMA_CR_EDBG_MASK                         (0x2U)
#define DMA_CR_EDBG_SHIFT                        (1U)
/*! EDBG - Enable Debug
 *  0b0..When in debug mode, the DMA continues to operate.
 *  0b1..When in debug mode, the DMA stalls the start of a new channel. Executing channels are allowed to
 *       complete. Channel execution resumes when the system exits debug mode or the EDBG bit is cleared.
 */
#define DMA_CR_EDBG_SET(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CR_EDBG_SHIFT)) & DMA_CR_EDBG_MASK)

#define DMA_CR_ERCA_MASK                         (0x4U)
#define DMA_CR_ERCA_SHIFT                        (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Fixed priority arbitration is used for channel selection within each group.
 *  0b1..Round robin arbitration is used for channel selection within each group.
 */
#define DMA_CR_ERCA_SET(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CR_ERCA_SHIFT)) & DMA_CR_ERCA_MASK)

#define DMA_CR_ERGA_MASK                         (0x8U)
#define DMA_CR_ERGA_SHIFT                        (3U)
/*! ERGA - Enable Round Robin Group Arbitration
 *  0b0..Fixed priority arbitration is used for selection among the groups.
 *  0b1..Round robin arbitration is used for selection among the groups.
 */
#define DMA_CR_ERGA_SET(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CR_ERGA_SHIFT)) & DMA_CR_ERGA_MASK)

#define DMA_CR_HOE_MASK                          (0x10U)
#define DMA_CR_HOE_SHIFT                         (4U)
/*! HOE - Halt On Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT bit to set. Subsequently, all service requests are ignored until the HALT bit is cleared.
 */
#define DMA_CR_HOE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CR_HOE_SHIFT)) & DMA_CR_HOE_MASK)

#define DMA_CR_HALT_MASK                         (0x20U)
#define DMA_CR_HALT_SHIFT                        (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels. Executing channels are allowed to complete. Channel execution resumes when this bit is cleared.
 */
#define DMA_CR_HALT_SET(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CR_HALT_SHIFT)) & DMA_CR_HALT_MASK)

#define DMA_CR_CLM_MASK                          (0x40U)
#define DMA_CR_CLM_SHIFT                         (6U)
/*! CLM - Continuous Link Mode
 *  0b0..A minor loop channel link made to itself goes through channel arbitration before being activated again.
 *  0b1..A minor loop channel link made to itself does not go through channel arbitration before being activated
 *       again. Upon minor loop completion, the channel activates again if that channel has a minor loop channel
 *       link enabled and the link channel is itself. This effectively applies the minor loop offsets and restarts the
 *       next minor loop.
 */
#define DMA_CR_CLM_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CR_CLM_SHIFT)) & DMA_CR_CLM_MASK)

#define DMA_CR_EMLM_MASK                         (0x80U)
#define DMA_CR_EMLM_SHIFT                        (7U)
/*! EMLM - Enable Minor Loop Mapping
 *  0b0..Disabled. TCDn.word2 is defined as a 32-bit NBYTES field.
 *  0b1..Enabled. TCDn.word2 is redefined to include individual enable fields, an offset field, and the NBYTES
 *       field. The individual enable fields allow the minor loop offset to be applied to the source address, the
 *       destination address, or both. The NBYTES field is reduced when either offset is enabled.
 */
#define DMA_CR_EMLM_SET(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CR_EMLM_SHIFT)) & DMA_CR_EMLM_MASK)

#define DMA_CR_GRP0PRI_MASK                      (0x100U)
#define DMA_CR_GRP0PRI_SHIFT                     (8U)
/*! GRP0PRI - Channel Group 0 Priority
 */
#define DMA_CR_GRP0PRI_SET(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CR_GRP0PRI_SHIFT)) & DMA_CR_GRP0PRI_MASK)

#define DMA_CR_GRP1PRI_MASK                      (0x400U)
#define DMA_CR_GRP1PRI_SHIFT                     (10U)
/*! GRP1PRI - Channel Group 1 Priority
 */
#define DMA_CR_GRP1PRI_SET(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CR_GRP1PRI_SHIFT)) & DMA_CR_GRP1PRI_MASK)

#define DMA_CR_ECX_MASK                          (0x10000U)
#define DMA_CR_ECX_SHIFT                         (16U)
/*! ECX - Error Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer in the same fashion as the CX bit. Stop the executing channel and
 *       force the minor loop to finish. The cancel takes effect after the last write of the current read/write
 *       sequence. The ECX bit clears itself after the cancel is honored. In addition to cancelling the transfer, ECX
 *       treats the cancel as an error condition, thus updating the Error Status register (DMAx_ES) and generating an
 *       optional error interrupt.
 */
#define DMA_CR_ECX_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CR_ECX_SHIFT)) & DMA_CR_ECX_MASK)

#define DMA_CR_CX_MASK                           (0x20000U)
#define DMA_CR_CX_SHIFT                          (17U)
/*! CX - Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer. Stop the executing channel and force the minor loop to finish. The
 *       cancel takes effect after the last write of the current read/write sequence. The CX bit clears itself after
 *       the cancel has been honored. This cancel retires the channel normally as if the minor loop was completed.
 */
#define DMA_CR_CX_SET(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CR_CX_SHIFT)) & DMA_CR_CX_MASK)
/*! @} */

/*! @name ES - Error Status Register */
/*! @{ */

#define DMA_ES_DBE_MASK                          (0x1U)
#define DMA_ES_DBE_SHIFT                         (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..The last recorded error was a bus error on a destination write
 */
#define DMA_ES_DBE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_DBE_SHIFT)) & DMA_ES_DBE_MASK)

#define DMA_ES_SBE_MASK                          (0x2U)
#define DMA_ES_SBE_SHIFT                         (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..The last recorded error was a bus error on a source read
 */
#define DMA_ES_SBE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_SBE_SHIFT)) & DMA_ES_SBE_MASK)

#define DMA_ES_SGE_MASK                          (0x4U)
#define DMA_ES_SGE_SHIFT                         (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DLASTSGA field. This field is
 *       checked at the beginning of a scatter/gather operation after major loop completion if TCDn_CSR[ESG] is
 *       enabled. TCDn_DLASTSGA is not on a 32 byte boundary.
 */
#define DMA_ES_SGE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_SGE_SHIFT)) & DMA_ES_SGE_MASK)

#define DMA_ES_NCE_MASK                          (0x8U)
#define DMA_ES_NCE_SHIFT                         (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields.
 *       TCDn_NBYTES is not a multiple of TCDn_ATTR[SSIZE] and TCDn_ATTR[DSIZE], or TCDn_CITER[CITER] is equal to zero,
 *       or TCDn_CITER[ELINK] is not equal to TCDn_BITER[ELINK]
 */
#define DMA_ES_NCE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_NCE_SHIFT)) & DMA_ES_NCE_MASK)

#define DMA_ES_DOE_MASK                          (0x10U)
#define DMA_ES_DOE_SHIFT                         (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DOFF field. TCDn_DOFF is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA_ES_DOE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_DOE_SHIFT)) & DMA_ES_DOE_MASK)

#define DMA_ES_DAE_MASK                          (0x20U)
#define DMA_ES_DAE_SHIFT                         (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DADDR field. TCDn_DADDR is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA_ES_DAE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_DAE_SHIFT)) & DMA_ES_DAE_MASK)

#define DMA_ES_SOE_MASK                          (0x40U)
#define DMA_ES_SOE_SHIFT                         (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SOFF field. TCDn_SOFF is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA_ES_SOE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_SOE_SHIFT)) & DMA_ES_SOE_MASK)

#define DMA_ES_SAE_MASK                          (0x80U)
#define DMA_ES_SAE_SHIFT                         (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error.
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SADDR field. TCDn_SADDR is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA_ES_SAE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_SAE_SHIFT)) & DMA_ES_SAE_MASK)

#define DMA_ES_ERRCHN_MASK                       (0x1F00U)
#define DMA_ES_ERRCHN_SHIFT                      (8U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number
 */
#define DMA_ES_ERRCHN_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ES_ERRCHN_SHIFT)) & DMA_ES_ERRCHN_MASK)

#define DMA_ES_CPE_MASK                          (0x4000U)
#define DMA_ES_CPE_SHIFT                         (14U)
/*! CPE - Channel Priority Error
 *  0b0..No channel priority error
 *  0b1..The last recorded error was a configuration error in the channel priorities within a group. Channel
 *       priorities within a group are not unique.
 */
#define DMA_ES_CPE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_CPE_SHIFT)) & DMA_ES_CPE_MASK)

#define DMA_ES_GPE_MASK                          (0x8000U)
#define DMA_ES_GPE_SHIFT                         (15U)
/*! GPE - Group Priority Error
 *  0b0..No group priority error
 *  0b1..The last recorded error was a configuration error among the group priorities. All group priorities are not unique.
 */
#define DMA_ES_GPE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_GPE_SHIFT)) & DMA_ES_GPE_MASK)

#define DMA_ES_ECX_MASK                          (0x10000U)
#define DMA_ES_ECX_SHIFT                         (16U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..The last recorded entry was a canceled transfer by the error cancel transfer input
 */
#define DMA_ES_ECX_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_ECX_SHIFT)) & DMA_ES_ECX_MASK)

#define DMA_ES_VLD_MASK                          (0x80000000U)
#define DMA_ES_VLD_SHIFT                         (31U)
/*! VLD
 *  0b0..No ERR bits are set.
 *  0b1..At least one ERR bit is set indicating a valid error exists that has not been cleared.
 */
#define DMA_ES_VLD_SET(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ES_VLD_SHIFT)) & DMA_ES_VLD_MASK)
/*! @} */

/*! @name ERQ - Enable Request Register */
/*! @{ */

#define DMA_ERQ_ERQ0_MASK                        (0x1U)
#define DMA_ERQ_ERQ0_SHIFT                       (0U)
/*! ERQ0 - Enable DMA Request 0
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ0_SHIFT)) & DMA_ERQ_ERQ0_MASK)

#define DMA_ERQ_ERQ1_MASK                        (0x2U)
#define DMA_ERQ_ERQ1_SHIFT                       (1U)
/*! ERQ1 - Enable DMA Request 1
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ1_SHIFT)) & DMA_ERQ_ERQ1_MASK)

#define DMA_ERQ_ERQ2_MASK                        (0x4U)
#define DMA_ERQ_ERQ2_SHIFT                       (2U)
/*! ERQ2 - Enable DMA Request 2
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ2_SHIFT)) & DMA_ERQ_ERQ2_MASK)

#define DMA_ERQ_ERQ3_MASK                        (0x8U)
#define DMA_ERQ_ERQ3_SHIFT                       (3U)
/*! ERQ3 - Enable DMA Request 3
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ3_SHIFT)) & DMA_ERQ_ERQ3_MASK)

#define DMA_ERQ_ERQ4_MASK                        (0x10U)
#define DMA_ERQ_ERQ4_SHIFT                       (4U)
/*! ERQ4 - Enable DMA Request 4
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ4_SHIFT)) & DMA_ERQ_ERQ4_MASK)

#define DMA_ERQ_ERQ5_MASK                        (0x20U)
#define DMA_ERQ_ERQ5_SHIFT                       (5U)
/*! ERQ5 - Enable DMA Request 5
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ5_SHIFT)) & DMA_ERQ_ERQ5_MASK)

#define DMA_ERQ_ERQ6_MASK                        (0x40U)
#define DMA_ERQ_ERQ6_SHIFT                       (6U)
/*! ERQ6 - Enable DMA Request 6
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ6_SHIFT)) & DMA_ERQ_ERQ6_MASK)

#define DMA_ERQ_ERQ7_MASK                        (0x80U)
#define DMA_ERQ_ERQ7_SHIFT                       (7U)
/*! ERQ7 - Enable DMA Request 7
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ7_SHIFT)) & DMA_ERQ_ERQ7_MASK)

#define DMA_ERQ_ERQ8_MASK                        (0x100U)
#define DMA_ERQ_ERQ8_SHIFT                       (8U)
/*! ERQ8 - Enable DMA Request 8
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ8_SHIFT)) & DMA_ERQ_ERQ8_MASK)

#define DMA_ERQ_ERQ9_MASK                        (0x200U)
#define DMA_ERQ_ERQ9_SHIFT                       (9U)
/*! ERQ9 - Enable DMA Request 9
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ9_SHIFT)) & DMA_ERQ_ERQ9_MASK)

#define DMA_ERQ_ERQ10_MASK                       (0x400U)
#define DMA_ERQ_ERQ10_SHIFT                      (10U)
/*! ERQ10 - Enable DMA Request 10
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ10_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ10_SHIFT)) & DMA_ERQ_ERQ10_MASK)

#define DMA_ERQ_ERQ11_MASK                       (0x800U)
#define DMA_ERQ_ERQ11_SHIFT                      (11U)
/*! ERQ11 - Enable DMA Request 11
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ11_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ11_SHIFT)) & DMA_ERQ_ERQ11_MASK)

#define DMA_ERQ_ERQ12_MASK                       (0x1000U)
#define DMA_ERQ_ERQ12_SHIFT                      (12U)
/*! ERQ12 - Enable DMA Request 12
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ12_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ12_SHIFT)) & DMA_ERQ_ERQ12_MASK)

#define DMA_ERQ_ERQ13_MASK                       (0x2000U)
#define DMA_ERQ_ERQ13_SHIFT                      (13U)
/*! ERQ13 - Enable DMA Request 13
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ13_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ13_SHIFT)) & DMA_ERQ_ERQ13_MASK)

#define DMA_ERQ_ERQ14_MASK                       (0x4000U)
#define DMA_ERQ_ERQ14_SHIFT                      (14U)
/*! ERQ14 - Enable DMA Request 14
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ14_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ14_SHIFT)) & DMA_ERQ_ERQ14_MASK)

#define DMA_ERQ_ERQ15_MASK                       (0x8000U)
#define DMA_ERQ_ERQ15_SHIFT                      (15U)
/*! ERQ15 - Enable DMA Request 15
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ15_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ15_SHIFT)) & DMA_ERQ_ERQ15_MASK)

#define DMA_ERQ_ERQ16_MASK                       (0x10000U)
#define DMA_ERQ_ERQ16_SHIFT                      (16U)
/*! ERQ16 - Enable DMA Request 16
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ16_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ16_SHIFT)) & DMA_ERQ_ERQ16_MASK)

#define DMA_ERQ_ERQ17_MASK                       (0x20000U)
#define DMA_ERQ_ERQ17_SHIFT                      (17U)
/*! ERQ17 - Enable DMA Request 17
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ17_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ17_SHIFT)) & DMA_ERQ_ERQ17_MASK)

#define DMA_ERQ_ERQ18_MASK                       (0x40000U)
#define DMA_ERQ_ERQ18_SHIFT                      (18U)
/*! ERQ18 - Enable DMA Request 18
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ18_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ18_SHIFT)) & DMA_ERQ_ERQ18_MASK)

#define DMA_ERQ_ERQ19_MASK                       (0x80000U)
#define DMA_ERQ_ERQ19_SHIFT                      (19U)
/*! ERQ19 - Enable DMA Request 19
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ19_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ19_SHIFT)) & DMA_ERQ_ERQ19_MASK)

#define DMA_ERQ_ERQ20_MASK                       (0x100000U)
#define DMA_ERQ_ERQ20_SHIFT                      (20U)
/*! ERQ20 - Enable DMA Request 20
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ20_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ20_SHIFT)) & DMA_ERQ_ERQ20_MASK)

#define DMA_ERQ_ERQ21_MASK                       (0x200000U)
#define DMA_ERQ_ERQ21_SHIFT                      (21U)
/*! ERQ21 - Enable DMA Request 21
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ21_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ21_SHIFT)) & DMA_ERQ_ERQ21_MASK)

#define DMA_ERQ_ERQ22_MASK                       (0x400000U)
#define DMA_ERQ_ERQ22_SHIFT                      (22U)
/*! ERQ22 - Enable DMA Request 22
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ22_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ22_SHIFT)) & DMA_ERQ_ERQ22_MASK)

#define DMA_ERQ_ERQ23_MASK                       (0x800000U)
#define DMA_ERQ_ERQ23_SHIFT                      (23U)
/*! ERQ23 - Enable DMA Request 23
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ23_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ23_SHIFT)) & DMA_ERQ_ERQ23_MASK)

#define DMA_ERQ_ERQ24_MASK                       (0x1000000U)
#define DMA_ERQ_ERQ24_SHIFT                      (24U)
/*! ERQ24 - Enable DMA Request 24
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ24_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ24_SHIFT)) & DMA_ERQ_ERQ24_MASK)

#define DMA_ERQ_ERQ25_MASK                       (0x2000000U)
#define DMA_ERQ_ERQ25_SHIFT                      (25U)
/*! ERQ25 - Enable DMA Request 25
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ25_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ25_SHIFT)) & DMA_ERQ_ERQ25_MASK)

#define DMA_ERQ_ERQ26_MASK                       (0x4000000U)
#define DMA_ERQ_ERQ26_SHIFT                      (26U)
/*! ERQ26 - Enable DMA Request 26
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ26_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ26_SHIFT)) & DMA_ERQ_ERQ26_MASK)

#define DMA_ERQ_ERQ27_MASK                       (0x8000000U)
#define DMA_ERQ_ERQ27_SHIFT                      (27U)
/*! ERQ27 - Enable DMA Request 27
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ27_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ27_SHIFT)) & DMA_ERQ_ERQ27_MASK)

#define DMA_ERQ_ERQ28_MASK                       (0x10000000U)
#define DMA_ERQ_ERQ28_SHIFT                      (28U)
/*! ERQ28 - Enable DMA Request 28
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ28_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ28_SHIFT)) & DMA_ERQ_ERQ28_MASK)

#define DMA_ERQ_ERQ29_MASK                       (0x20000000U)
#define DMA_ERQ_ERQ29_SHIFT                      (29U)
/*! ERQ29 - Enable DMA Request 29
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ29_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ29_SHIFT)) & DMA_ERQ_ERQ29_MASK)

#define DMA_ERQ_ERQ30_MASK                       (0x40000000U)
#define DMA_ERQ_ERQ30_SHIFT                      (30U)
/*! ERQ30 - Enable DMA Request 30
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ30_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ30_SHIFT)) & DMA_ERQ_ERQ30_MASK)

#define DMA_ERQ_ERQ31_MASK                       (0x80000000U)
#define DMA_ERQ_ERQ31_SHIFT                      (31U)
/*! ERQ31 - Enable DMA Request 31
 *  0b0..The DMA request signal for the corresponding channel is disabled
 *  0b1..The DMA request signal for the corresponding channel is enabled
 */
#define DMA_ERQ_ERQ31_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ31_SHIFT)) & DMA_ERQ_ERQ31_MASK)
/*! @} */

/*! @name EEI - Enable Error Interrupt Register */
/*! @{ */

#define DMA_EEI_EEI0_MASK                        (0x1U)
#define DMA_EEI_EEI0_SHIFT                       (0U)
/*! EEI0 - Enable Error Interrupt 0
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI0_SHIFT)) & DMA_EEI_EEI0_MASK)

#define DMA_EEI_EEI1_MASK                        (0x2U)
#define DMA_EEI_EEI1_SHIFT                       (1U)
/*! EEI1 - Enable Error Interrupt 1
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI1_SHIFT)) & DMA_EEI_EEI1_MASK)

#define DMA_EEI_EEI2_MASK                        (0x4U)
#define DMA_EEI_EEI2_SHIFT                       (2U)
/*! EEI2 - Enable Error Interrupt 2
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI2_SHIFT)) & DMA_EEI_EEI2_MASK)

#define DMA_EEI_EEI3_MASK                        (0x8U)
#define DMA_EEI_EEI3_SHIFT                       (3U)
/*! EEI3 - Enable Error Interrupt 3
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI3_SHIFT)) & DMA_EEI_EEI3_MASK)

#define DMA_EEI_EEI4_MASK                        (0x10U)
#define DMA_EEI_EEI4_SHIFT                       (4U)
/*! EEI4 - Enable Error Interrupt 4
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI4_SHIFT)) & DMA_EEI_EEI4_MASK)

#define DMA_EEI_EEI5_MASK                        (0x20U)
#define DMA_EEI_EEI5_SHIFT                       (5U)
/*! EEI5 - Enable Error Interrupt 5
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI5_SHIFT)) & DMA_EEI_EEI5_MASK)

#define DMA_EEI_EEI6_MASK                        (0x40U)
#define DMA_EEI_EEI6_SHIFT                       (6U)
/*! EEI6 - Enable Error Interrupt 6
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI6_SHIFT)) & DMA_EEI_EEI6_MASK)

#define DMA_EEI_EEI7_MASK                        (0x80U)
#define DMA_EEI_EEI7_SHIFT                       (7U)
/*! EEI7 - Enable Error Interrupt 7
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI7_SHIFT)) & DMA_EEI_EEI7_MASK)

#define DMA_EEI_EEI8_MASK                        (0x100U)
#define DMA_EEI_EEI8_SHIFT                       (8U)
/*! EEI8 - Enable Error Interrupt 8
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI8_SHIFT)) & DMA_EEI_EEI8_MASK)

#define DMA_EEI_EEI9_MASK                        (0x200U)
#define DMA_EEI_EEI9_SHIFT                       (9U)
/*! EEI9 - Enable Error Interrupt 9
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI9_SHIFT)) & DMA_EEI_EEI9_MASK)

#define DMA_EEI_EEI10_MASK                       (0x400U)
#define DMA_EEI_EEI10_SHIFT                      (10U)
/*! EEI10 - Enable Error Interrupt 10
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI10_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI10_SHIFT)) & DMA_EEI_EEI10_MASK)

#define DMA_EEI_EEI11_MASK                       (0x800U)
#define DMA_EEI_EEI11_SHIFT                      (11U)
/*! EEI11 - Enable Error Interrupt 11
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI11_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI11_SHIFT)) & DMA_EEI_EEI11_MASK)

#define DMA_EEI_EEI12_MASK                       (0x1000U)
#define DMA_EEI_EEI12_SHIFT                      (12U)
/*! EEI12 - Enable Error Interrupt 12
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI12_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI12_SHIFT)) & DMA_EEI_EEI12_MASK)

#define DMA_EEI_EEI13_MASK                       (0x2000U)
#define DMA_EEI_EEI13_SHIFT                      (13U)
/*! EEI13 - Enable Error Interrupt 13
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI13_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI13_SHIFT)) & DMA_EEI_EEI13_MASK)

#define DMA_EEI_EEI14_MASK                       (0x4000U)
#define DMA_EEI_EEI14_SHIFT                      (14U)
/*! EEI14 - Enable Error Interrupt 14
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI14_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI14_SHIFT)) & DMA_EEI_EEI14_MASK)

#define DMA_EEI_EEI15_MASK                       (0x8000U)
#define DMA_EEI_EEI15_SHIFT                      (15U)
/*! EEI15 - Enable Error Interrupt 15
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI15_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI15_SHIFT)) & DMA_EEI_EEI15_MASK)

#define DMA_EEI_EEI16_MASK                       (0x10000U)
#define DMA_EEI_EEI16_SHIFT                      (16U)
/*! EEI16 - Enable Error Interrupt 16
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI16_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI16_SHIFT)) & DMA_EEI_EEI16_MASK)

#define DMA_EEI_EEI17_MASK                       (0x20000U)
#define DMA_EEI_EEI17_SHIFT                      (17U)
/*! EEI17 - Enable Error Interrupt 17
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI17_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI17_SHIFT)) & DMA_EEI_EEI17_MASK)

#define DMA_EEI_EEI18_MASK                       (0x40000U)
#define DMA_EEI_EEI18_SHIFT                      (18U)
/*! EEI18 - Enable Error Interrupt 18
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI18_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI18_SHIFT)) & DMA_EEI_EEI18_MASK)

#define DMA_EEI_EEI19_MASK                       (0x80000U)
#define DMA_EEI_EEI19_SHIFT                      (19U)
/*! EEI19 - Enable Error Interrupt 19
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI19_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI19_SHIFT)) & DMA_EEI_EEI19_MASK)

#define DMA_EEI_EEI20_MASK                       (0x100000U)
#define DMA_EEI_EEI20_SHIFT                      (20U)
/*! EEI20 - Enable Error Interrupt 20
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI20_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI20_SHIFT)) & DMA_EEI_EEI20_MASK)

#define DMA_EEI_EEI21_MASK                       (0x200000U)
#define DMA_EEI_EEI21_SHIFT                      (21U)
/*! EEI21 - Enable Error Interrupt 21
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI21_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI21_SHIFT)) & DMA_EEI_EEI21_MASK)

#define DMA_EEI_EEI22_MASK                       (0x400000U)
#define DMA_EEI_EEI22_SHIFT                      (22U)
/*! EEI22 - Enable Error Interrupt 22
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI22_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI22_SHIFT)) & DMA_EEI_EEI22_MASK)

#define DMA_EEI_EEI23_MASK                       (0x800000U)
#define DMA_EEI_EEI23_SHIFT                      (23U)
/*! EEI23 - Enable Error Interrupt 23
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI23_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI23_SHIFT)) & DMA_EEI_EEI23_MASK)

#define DMA_EEI_EEI24_MASK                       (0x1000000U)
#define DMA_EEI_EEI24_SHIFT                      (24U)
/*! EEI24 - Enable Error Interrupt 24
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI24_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI24_SHIFT)) & DMA_EEI_EEI24_MASK)

#define DMA_EEI_EEI25_MASK                       (0x2000000U)
#define DMA_EEI_EEI25_SHIFT                      (25U)
/*! EEI25 - Enable Error Interrupt 25
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI25_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI25_SHIFT)) & DMA_EEI_EEI25_MASK)

#define DMA_EEI_EEI26_MASK                       (0x4000000U)
#define DMA_EEI_EEI26_SHIFT                      (26U)
/*! EEI26 - Enable Error Interrupt 26
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI26_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI26_SHIFT)) & DMA_EEI_EEI26_MASK)

#define DMA_EEI_EEI27_MASK                       (0x8000000U)
#define DMA_EEI_EEI27_SHIFT                      (27U)
/*! EEI27 - Enable Error Interrupt 27
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI27_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI27_SHIFT)) & DMA_EEI_EEI27_MASK)

#define DMA_EEI_EEI28_MASK                       (0x10000000U)
#define DMA_EEI_EEI28_SHIFT                      (28U)
/*! EEI28 - Enable Error Interrupt 28
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI28_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI28_SHIFT)) & DMA_EEI_EEI28_MASK)

#define DMA_EEI_EEI29_MASK                       (0x20000000U)
#define DMA_EEI_EEI29_SHIFT                      (29U)
/*! EEI29 - Enable Error Interrupt 29
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI29_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI29_SHIFT)) & DMA_EEI_EEI29_MASK)

#define DMA_EEI_EEI30_MASK                       (0x40000000U)
#define DMA_EEI_EEI30_SHIFT                      (30U)
/*! EEI30 - Enable Error Interrupt 30
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI30_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI30_SHIFT)) & DMA_EEI_EEI30_MASK)

#define DMA_EEI_EEI31_MASK                       (0x80000000U)
#define DMA_EEI_EEI31_SHIFT                      (31U)
/*! EEI31 - Enable Error Interrupt 31
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA_EEI_EEI31_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI31_SHIFT)) & DMA_EEI_EEI31_MASK)
/*! @} */

/*! @name CEEI - Clear Enable Error Interrupt Register */
/*! @{ */

#define DMA_CEEI_CEEI_MASK                       (0x1FU)
#define DMA_CEEI_CEEI_SHIFT                      (0U)
/*! CEEI - Clear Enable Error Interrupt
 */
#define DMA_CEEI_CEEI_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CEEI_CEEI_SHIFT)) & DMA_CEEI_CEEI_MASK)

#define DMA_CEEI_CAEE_MASK                       (0x40U)
#define DMA_CEEI_CAEE_SHIFT                      (6U)
/*! CAEE - Clear All Enable Error Interrupts
 *  0b0..Clear only the EEI bit specified in the CEEI field
 *  0b1..Clear all bits in EEI
 */
#define DMA_CEEI_CAEE_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CEEI_CAEE_SHIFT)) & DMA_CEEI_CAEE_MASK)

#define DMA_CEEI_NOP_MASK                        (0x80U)
#define DMA_CEEI_NOP_SHIFT                       (7U)
/*! NOP - No Op enable
 *  0b0..Normal operation
 *  0b1..No operation, ignore the other bits in this register
 */
#define DMA_CEEI_NOP_SET(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_CEEI_NOP_SHIFT)) & DMA_CEEI_NOP_MASK)
/*! @} */

/*! @name SEEI - Set Enable Error Interrupt Register */
/*! @{ */

#define DMA_SEEI_SEEI_MASK                       (0x1FU)
#define DMA_SEEI_SEEI_SHIFT                      (0U)
/*! SEEI - Set Enable Error Interrupt
 */
#define DMA_SEEI_SEEI_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_SEEI_SEEI_SHIFT)) & DMA_SEEI_SEEI_MASK)

#define DMA_SEEI_SAEE_MASK                       (0x40U)
#define DMA_SEEI_SAEE_SHIFT                      (6U)
/*! SAEE - Sets All Enable Error Interrupts
 *  0b0..Set only the EEI bit specified in the SEEI field.
 *  0b1..Sets all bits in EEI
 */
#define DMA_SEEI_SAEE_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_SEEI_SAEE_SHIFT)) & DMA_SEEI_SAEE_MASK)

#define DMA_SEEI_NOP_MASK                        (0x80U)
#define DMA_SEEI_NOP_SHIFT                       (7U)
/*! NOP - No Op enable
 *  0b0..Normal operation
 *  0b1..No operation, ignore the other bits in this register
 */
#define DMA_SEEI_NOP_SET(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_SEEI_NOP_SHIFT)) & DMA_SEEI_NOP_MASK)
/*! @} */

/*! @name CERQ - Clear Enable Request Register */
/*! @{ */

#define DMA_CERQ_CERQ_MASK                       (0x1FU)
#define DMA_CERQ_CERQ_SHIFT                      (0U)
/*! CERQ - Clear Enable Request
 */
#define DMA_CERQ_CERQ_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CERQ_CERQ_SHIFT)) & DMA_CERQ_CERQ_MASK)

#define DMA_CERQ_CAER_MASK                       (0x40U)
#define DMA_CERQ_CAER_SHIFT                      (6U)
/*! CAER - Clear All Enable Requests
 *  0b0..Clear only the ERQ bit specified in the CERQ field
 *  0b1..Clear all bits in ERQ
 */
#define DMA_CERQ_CAER_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CERQ_CAER_SHIFT)) & DMA_CERQ_CAER_MASK)

#define DMA_CERQ_NOP_MASK                        (0x80U)
#define DMA_CERQ_NOP_SHIFT                       (7U)
/*! NOP - No Op enable
 *  0b0..Normal operation
 *  0b1..No operation, ignore the other bits in this register
 */
#define DMA_CERQ_NOP_SET(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_CERQ_NOP_SHIFT)) & DMA_CERQ_NOP_MASK)
/*! @} */

/*! @name SERQ - Set Enable Request Register */
/*! @{ */

#define DMA_SERQ_SERQ_MASK                       (0x1FU)
#define DMA_SERQ_SERQ_SHIFT                      (0U)
/*! SERQ - Set Enable Request
 */
#define DMA_SERQ_SERQ_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_SERQ_SERQ_SHIFT)) & DMA_SERQ_SERQ_MASK)

#define DMA_SERQ_SAER_MASK                       (0x40U)
#define DMA_SERQ_SAER_SHIFT                      (6U)
/*! SAER - Set All Enable Requests
 *  0b0..Set only the ERQ bit specified in the SERQ field
 *  0b1..Set all bits in ERQ
 */
#define DMA_SERQ_SAER_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_SERQ_SAER_SHIFT)) & DMA_SERQ_SAER_MASK)

#define DMA_SERQ_NOP_MASK                        (0x80U)
#define DMA_SERQ_NOP_SHIFT                       (7U)
/*! NOP - No Op enable
 *  0b0..Normal operation
 *  0b1..No operation, ignore the other bits in this register
 */
#define DMA_SERQ_NOP_SET(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_SERQ_NOP_SHIFT)) & DMA_SERQ_NOP_MASK)
/*! @} */

/*! @name CDNE - Clear DONE Status Bit Register */
/*! @{ */

#define DMA_CDNE_CDNE_MASK                       (0x1FU)
#define DMA_CDNE_CDNE_SHIFT                      (0U)
/*! CDNE - Clear DONE Bit
 */
#define DMA_CDNE_CDNE_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CDNE_CDNE_SHIFT)) & DMA_CDNE_CDNE_MASK)

#define DMA_CDNE_CADN_MASK                       (0x40U)
#define DMA_CDNE_CADN_SHIFT                      (6U)
/*! CADN - Clears All DONE Bits
 *  0b0..Clears only the TCDn_CSR[DONE] bit specified in the CDNE field
 *  0b1..Clears all bits in TCDn_CSR[DONE]
 */
#define DMA_CDNE_CADN_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CDNE_CADN_SHIFT)) & DMA_CDNE_CADN_MASK)

#define DMA_CDNE_NOP_MASK                        (0x80U)
#define DMA_CDNE_NOP_SHIFT                       (7U)
/*! NOP - No Op enable
 *  0b0..Normal operation
 *  0b1..No operation, ignore the other bits in this register
 */
#define DMA_CDNE_NOP_SET(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_CDNE_NOP_SHIFT)) & DMA_CDNE_NOP_MASK)
/*! @} */

/*! @name SSRT - Set START Bit Register */
/*! @{ */

#define DMA_SSRT_SSRT_MASK                       (0x1FU)
#define DMA_SSRT_SSRT_SHIFT                      (0U)
/*! SSRT - Set START Bit
 */
#define DMA_SSRT_SSRT_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_SSRT_SSRT_SHIFT)) & DMA_SSRT_SSRT_MASK)

#define DMA_SSRT_SAST_MASK                       (0x40U)
#define DMA_SSRT_SAST_SHIFT                      (6U)
/*! SAST - Set All START Bits (activates all channels)
 *  0b0..Set only the TCDn_CSR[START] bit specified in the SSRT field
 *  0b1..Set all bits in TCDn_CSR[START]
 */
#define DMA_SSRT_SAST_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_SSRT_SAST_SHIFT)) & DMA_SSRT_SAST_MASK)

#define DMA_SSRT_NOP_MASK                        (0x80U)
#define DMA_SSRT_NOP_SHIFT                       (7U)
/*! NOP - No Op enable
 *  0b0..Normal operation
 *  0b1..No operation, ignore the other bits in this register
 */
#define DMA_SSRT_NOP_SET(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_SSRT_NOP_SHIFT)) & DMA_SSRT_NOP_MASK)
/*! @} */

/*! @name CERR - Clear Error Register */
/*! @{ */

#define DMA_CERR_CERR_MASK                       (0x1FU)
#define DMA_CERR_CERR_SHIFT                      (0U)
/*! CERR - Clear Error Indicator
 */
#define DMA_CERR_CERR_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CERR_CERR_SHIFT)) & DMA_CERR_CERR_MASK)

#define DMA_CERR_CAEI_MASK                       (0x40U)
#define DMA_CERR_CAEI_SHIFT                      (6U)
/*! CAEI - Clear All Error Indicators
 *  0b0..Clear only the ERR bit specified in the CERR field
 *  0b1..Clear all bits in ERR
 */
#define DMA_CERR_CAEI_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CERR_CAEI_SHIFT)) & DMA_CERR_CAEI_MASK)

#define DMA_CERR_NOP_MASK                        (0x80U)
#define DMA_CERR_NOP_SHIFT                       (7U)
/*! NOP - No Op enable
 *  0b0..Normal operation
 *  0b1..No operation, ignore the other bits in this register
 */
#define DMA_CERR_NOP_SET(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_CERR_NOP_SHIFT)) & DMA_CERR_NOP_MASK)
/*! @} */

/*! @name CINT - Clear Interrupt Request Register */
/*! @{ */

#define DMA_CINT_CINT_MASK                       (0x1FU)
#define DMA_CINT_CINT_SHIFT                      (0U)
/*! CINT - Clear Interrupt Request
 */
#define DMA_CINT_CINT_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CINT_CINT_SHIFT)) & DMA_CINT_CINT_MASK)

#define DMA_CINT_CAIR_MASK                       (0x40U)
#define DMA_CINT_CAIR_SHIFT                      (6U)
/*! CAIR - Clear All Interrupt Requests
 *  0b0..Clear only the INT bit specified in the CINT field
 *  0b1..Clear all bits in INT
 */
#define DMA_CINT_CAIR_SET(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_CINT_CAIR_SHIFT)) & DMA_CINT_CAIR_MASK)

#define DMA_CINT_NOP_MASK                        (0x80U)
#define DMA_CINT_NOP_SHIFT                       (7U)
/*! NOP - No Op enable
 *  0b0..Normal operation
 *  0b1..No operation, ignore the other bits in this register
 */
#define DMA_CINT_NOP_SET(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_CINT_NOP_SHIFT)) & DMA_CINT_NOP_MASK)
/*! @} */

/*! @name INT - Interrupt Request Register */
/*! @{ */

#define DMA_INT_INT0_MASK                        (0x1U)
#define DMA_INT_INT0_SHIFT                       (0U)
/*! INT0 - Interrupt Request 0
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT0_SHIFT)) & DMA_INT_INT0_MASK)

#define DMA_INT_INT1_MASK                        (0x2U)
#define DMA_INT_INT1_SHIFT                       (1U)
/*! INT1 - Interrupt Request 1
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT1_SHIFT)) & DMA_INT_INT1_MASK)

#define DMA_INT_INT2_MASK                        (0x4U)
#define DMA_INT_INT2_SHIFT                       (2U)
/*! INT2 - Interrupt Request 2
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT2_SHIFT)) & DMA_INT_INT2_MASK)

#define DMA_INT_INT3_MASK                        (0x8U)
#define DMA_INT_INT3_SHIFT                       (3U)
/*! INT3 - Interrupt Request 3
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT3_SHIFT)) & DMA_INT_INT3_MASK)

#define DMA_INT_INT4_MASK                        (0x10U)
#define DMA_INT_INT4_SHIFT                       (4U)
/*! INT4 - Interrupt Request 4
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT4_SHIFT)) & DMA_INT_INT4_MASK)

#define DMA_INT_INT5_MASK                        (0x20U)
#define DMA_INT_INT5_SHIFT                       (5U)
/*! INT5 - Interrupt Request 5
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT5_SHIFT)) & DMA_INT_INT5_MASK)

#define DMA_INT_INT6_MASK                        (0x40U)
#define DMA_INT_INT6_SHIFT                       (6U)
/*! INT6 - Interrupt Request 6
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT6_SHIFT)) & DMA_INT_INT6_MASK)

#define DMA_INT_INT7_MASK                        (0x80U)
#define DMA_INT_INT7_SHIFT                       (7U)
/*! INT7 - Interrupt Request 7
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT7_SHIFT)) & DMA_INT_INT7_MASK)

#define DMA_INT_INT8_MASK                        (0x100U)
#define DMA_INT_INT8_SHIFT                       (8U)
/*! INT8 - Interrupt Request 8
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT8_SHIFT)) & DMA_INT_INT8_MASK)

#define DMA_INT_INT9_MASK                        (0x200U)
#define DMA_INT_INT9_SHIFT                       (9U)
/*! INT9 - Interrupt Request 9
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT9_SHIFT)) & DMA_INT_INT9_MASK)

#define DMA_INT_INT10_MASK                       (0x400U)
#define DMA_INT_INT10_SHIFT                      (10U)
/*! INT10 - Interrupt Request 10
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT10_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT10_SHIFT)) & DMA_INT_INT10_MASK)

#define DMA_INT_INT11_MASK                       (0x800U)
#define DMA_INT_INT11_SHIFT                      (11U)
/*! INT11 - Interrupt Request 11
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT11_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT11_SHIFT)) & DMA_INT_INT11_MASK)

#define DMA_INT_INT12_MASK                       (0x1000U)
#define DMA_INT_INT12_SHIFT                      (12U)
/*! INT12 - Interrupt Request 12
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT12_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT12_SHIFT)) & DMA_INT_INT12_MASK)

#define DMA_INT_INT13_MASK                       (0x2000U)
#define DMA_INT_INT13_SHIFT                      (13U)
/*! INT13 - Interrupt Request 13
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT13_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT13_SHIFT)) & DMA_INT_INT13_MASK)

#define DMA_INT_INT14_MASK                       (0x4000U)
#define DMA_INT_INT14_SHIFT                      (14U)
/*! INT14 - Interrupt Request 14
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT14_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT14_SHIFT)) & DMA_INT_INT14_MASK)

#define DMA_INT_INT15_MASK                       (0x8000U)
#define DMA_INT_INT15_SHIFT                      (15U)
/*! INT15 - Interrupt Request 15
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT15_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT15_SHIFT)) & DMA_INT_INT15_MASK)

#define DMA_INT_INT16_MASK                       (0x10000U)
#define DMA_INT_INT16_SHIFT                      (16U)
/*! INT16 - Interrupt Request 16
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT16_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT16_SHIFT)) & DMA_INT_INT16_MASK)

#define DMA_INT_INT17_MASK                       (0x20000U)
#define DMA_INT_INT17_SHIFT                      (17U)
/*! INT17 - Interrupt Request 17
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT17_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT17_SHIFT)) & DMA_INT_INT17_MASK)

#define DMA_INT_INT18_MASK                       (0x40000U)
#define DMA_INT_INT18_SHIFT                      (18U)
/*! INT18 - Interrupt Request 18
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT18_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT18_SHIFT)) & DMA_INT_INT18_MASK)

#define DMA_INT_INT19_MASK                       (0x80000U)
#define DMA_INT_INT19_SHIFT                      (19U)
/*! INT19 - Interrupt Request 19
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT19_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT19_SHIFT)) & DMA_INT_INT19_MASK)

#define DMA_INT_INT20_MASK                       (0x100000U)
#define DMA_INT_INT20_SHIFT                      (20U)
/*! INT20 - Interrupt Request 20
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT20_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT20_SHIFT)) & DMA_INT_INT20_MASK)

#define DMA_INT_INT21_MASK                       (0x200000U)
#define DMA_INT_INT21_SHIFT                      (21U)
/*! INT21 - Interrupt Request 21
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT21_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT21_SHIFT)) & DMA_INT_INT21_MASK)

#define DMA_INT_INT22_MASK                       (0x400000U)
#define DMA_INT_INT22_SHIFT                      (22U)
/*! INT22 - Interrupt Request 22
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT22_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT22_SHIFT)) & DMA_INT_INT22_MASK)

#define DMA_INT_INT23_MASK                       (0x800000U)
#define DMA_INT_INT23_SHIFT                      (23U)
/*! INT23 - Interrupt Request 23
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT23_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT23_SHIFT)) & DMA_INT_INT23_MASK)

#define DMA_INT_INT24_MASK                       (0x1000000U)
#define DMA_INT_INT24_SHIFT                      (24U)
/*! INT24 - Interrupt Request 24
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT24_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT24_SHIFT)) & DMA_INT_INT24_MASK)

#define DMA_INT_INT25_MASK                       (0x2000000U)
#define DMA_INT_INT25_SHIFT                      (25U)
/*! INT25 - Interrupt Request 25
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT25_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT25_SHIFT)) & DMA_INT_INT25_MASK)

#define DMA_INT_INT26_MASK                       (0x4000000U)
#define DMA_INT_INT26_SHIFT                      (26U)
/*! INT26 - Interrupt Request 26
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT26_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT26_SHIFT)) & DMA_INT_INT26_MASK)

#define DMA_INT_INT27_MASK                       (0x8000000U)
#define DMA_INT_INT27_SHIFT                      (27U)
/*! INT27 - Interrupt Request 27
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT27_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT27_SHIFT)) & DMA_INT_INT27_MASK)

#define DMA_INT_INT28_MASK                       (0x10000000U)
#define DMA_INT_INT28_SHIFT                      (28U)
/*! INT28 - Interrupt Request 28
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT28_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT28_SHIFT)) & DMA_INT_INT28_MASK)

#define DMA_INT_INT29_MASK                       (0x20000000U)
#define DMA_INT_INT29_SHIFT                      (29U)
/*! INT29 - Interrupt Request 29
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT29_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT29_SHIFT)) & DMA_INT_INT29_MASK)

#define DMA_INT_INT30_MASK                       (0x40000000U)
#define DMA_INT_INT30_SHIFT                      (30U)
/*! INT30 - Interrupt Request 30
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT30_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT30_SHIFT)) & DMA_INT_INT30_MASK)

#define DMA_INT_INT31_MASK                       (0x80000000U)
#define DMA_INT_INT31_SHIFT                      (31U)
/*! INT31 - Interrupt Request 31
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA_INT_INT31_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT31_SHIFT)) & DMA_INT_INT31_MASK)
/*! @} */

/*! @name ERR - Error Register */
/*! @{ */

#define DMA_ERR_ERR0_MASK                        (0x1U)
#define DMA_ERR_ERR0_SHIFT                       (0U)
/*! ERR0 - Error In Channel 0
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR0_SHIFT)) & DMA_ERR_ERR0_MASK)

#define DMA_ERR_ERR1_MASK                        (0x2U)
#define DMA_ERR_ERR1_SHIFT                       (1U)
/*! ERR1 - Error In Channel 1
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR1_SHIFT)) & DMA_ERR_ERR1_MASK)

#define DMA_ERR_ERR2_MASK                        (0x4U)
#define DMA_ERR_ERR2_SHIFT                       (2U)
/*! ERR2 - Error In Channel 2
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR2_SHIFT)) & DMA_ERR_ERR2_MASK)

#define DMA_ERR_ERR3_MASK                        (0x8U)
#define DMA_ERR_ERR3_SHIFT                       (3U)
/*! ERR3 - Error In Channel 3
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR3_SHIFT)) & DMA_ERR_ERR3_MASK)

#define DMA_ERR_ERR4_MASK                        (0x10U)
#define DMA_ERR_ERR4_SHIFT                       (4U)
/*! ERR4 - Error In Channel 4
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR4_SHIFT)) & DMA_ERR_ERR4_MASK)

#define DMA_ERR_ERR5_MASK                        (0x20U)
#define DMA_ERR_ERR5_SHIFT                       (5U)
/*! ERR5 - Error In Channel 5
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR5_SHIFT)) & DMA_ERR_ERR5_MASK)

#define DMA_ERR_ERR6_MASK                        (0x40U)
#define DMA_ERR_ERR6_SHIFT                       (6U)
/*! ERR6 - Error In Channel 6
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR6_SHIFT)) & DMA_ERR_ERR6_MASK)

#define DMA_ERR_ERR7_MASK                        (0x80U)
#define DMA_ERR_ERR7_SHIFT                       (7U)
/*! ERR7 - Error In Channel 7
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR7_SHIFT)) & DMA_ERR_ERR7_MASK)

#define DMA_ERR_ERR8_MASK                        (0x100U)
#define DMA_ERR_ERR8_SHIFT                       (8U)
/*! ERR8 - Error In Channel 8
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR8_SHIFT)) & DMA_ERR_ERR8_MASK)

#define DMA_ERR_ERR9_MASK                        (0x200U)
#define DMA_ERR_ERR9_SHIFT                       (9U)
/*! ERR9 - Error In Channel 9
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR9_SHIFT)) & DMA_ERR_ERR9_MASK)

#define DMA_ERR_ERR10_MASK                       (0x400U)
#define DMA_ERR_ERR10_SHIFT                      (10U)
/*! ERR10 - Error In Channel 10
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR10_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR10_SHIFT)) & DMA_ERR_ERR10_MASK)

#define DMA_ERR_ERR11_MASK                       (0x800U)
#define DMA_ERR_ERR11_SHIFT                      (11U)
/*! ERR11 - Error In Channel 11
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR11_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR11_SHIFT)) & DMA_ERR_ERR11_MASK)

#define DMA_ERR_ERR12_MASK                       (0x1000U)
#define DMA_ERR_ERR12_SHIFT                      (12U)
/*! ERR12 - Error In Channel 12
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR12_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR12_SHIFT)) & DMA_ERR_ERR12_MASK)

#define DMA_ERR_ERR13_MASK                       (0x2000U)
#define DMA_ERR_ERR13_SHIFT                      (13U)
/*! ERR13 - Error In Channel 13
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR13_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR13_SHIFT)) & DMA_ERR_ERR13_MASK)

#define DMA_ERR_ERR14_MASK                       (0x4000U)
#define DMA_ERR_ERR14_SHIFT                      (14U)
/*! ERR14 - Error In Channel 14
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR14_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR14_SHIFT)) & DMA_ERR_ERR14_MASK)

#define DMA_ERR_ERR15_MASK                       (0x8000U)
#define DMA_ERR_ERR15_SHIFT                      (15U)
/*! ERR15 - Error In Channel 15
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR15_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR15_SHIFT)) & DMA_ERR_ERR15_MASK)

#define DMA_ERR_ERR16_MASK                       (0x10000U)
#define DMA_ERR_ERR16_SHIFT                      (16U)
/*! ERR16 - Error In Channel 16
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR16_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR16_SHIFT)) & DMA_ERR_ERR16_MASK)

#define DMA_ERR_ERR17_MASK                       (0x20000U)
#define DMA_ERR_ERR17_SHIFT                      (17U)
/*! ERR17 - Error In Channel 17
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR17_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR17_SHIFT)) & DMA_ERR_ERR17_MASK)

#define DMA_ERR_ERR18_MASK                       (0x40000U)
#define DMA_ERR_ERR18_SHIFT                      (18U)
/*! ERR18 - Error In Channel 18
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR18_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR18_SHIFT)) & DMA_ERR_ERR18_MASK)

#define DMA_ERR_ERR19_MASK                       (0x80000U)
#define DMA_ERR_ERR19_SHIFT                      (19U)
/*! ERR19 - Error In Channel 19
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR19_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR19_SHIFT)) & DMA_ERR_ERR19_MASK)

#define DMA_ERR_ERR20_MASK                       (0x100000U)
#define DMA_ERR_ERR20_SHIFT                      (20U)
/*! ERR20 - Error In Channel 20
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR20_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR20_SHIFT)) & DMA_ERR_ERR20_MASK)

#define DMA_ERR_ERR21_MASK                       (0x200000U)
#define DMA_ERR_ERR21_SHIFT                      (21U)
/*! ERR21 - Error In Channel 21
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR21_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR21_SHIFT)) & DMA_ERR_ERR21_MASK)

#define DMA_ERR_ERR22_MASK                       (0x400000U)
#define DMA_ERR_ERR22_SHIFT                      (22U)
/*! ERR22 - Error In Channel 22
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR22_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR22_SHIFT)) & DMA_ERR_ERR22_MASK)

#define DMA_ERR_ERR23_MASK                       (0x800000U)
#define DMA_ERR_ERR23_SHIFT                      (23U)
/*! ERR23 - Error In Channel 23
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR23_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR23_SHIFT)) & DMA_ERR_ERR23_MASK)

#define DMA_ERR_ERR24_MASK                       (0x1000000U)
#define DMA_ERR_ERR24_SHIFT                      (24U)
/*! ERR24 - Error In Channel 24
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR24_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR24_SHIFT)) & DMA_ERR_ERR24_MASK)

#define DMA_ERR_ERR25_MASK                       (0x2000000U)
#define DMA_ERR_ERR25_SHIFT                      (25U)
/*! ERR25 - Error In Channel 25
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR25_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR25_SHIFT)) & DMA_ERR_ERR25_MASK)

#define DMA_ERR_ERR26_MASK                       (0x4000000U)
#define DMA_ERR_ERR26_SHIFT                      (26U)
/*! ERR26 - Error In Channel 26
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR26_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR26_SHIFT)) & DMA_ERR_ERR26_MASK)

#define DMA_ERR_ERR27_MASK                       (0x8000000U)
#define DMA_ERR_ERR27_SHIFT                      (27U)
/*! ERR27 - Error In Channel 27
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR27_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR27_SHIFT)) & DMA_ERR_ERR27_MASK)

#define DMA_ERR_ERR28_MASK                       (0x10000000U)
#define DMA_ERR_ERR28_SHIFT                      (28U)
/*! ERR28 - Error In Channel 28
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR28_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR28_SHIFT)) & DMA_ERR_ERR28_MASK)

#define DMA_ERR_ERR29_MASK                       (0x20000000U)
#define DMA_ERR_ERR29_SHIFT                      (29U)
/*! ERR29 - Error In Channel 29
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR29_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR29_SHIFT)) & DMA_ERR_ERR29_MASK)

#define DMA_ERR_ERR30_MASK                       (0x40000000U)
#define DMA_ERR_ERR30_SHIFT                      (30U)
/*! ERR30 - Error In Channel 30
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR30_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR30_SHIFT)) & DMA_ERR_ERR30_MASK)

#define DMA_ERR_ERR31_MASK                       (0x80000000U)
#define DMA_ERR_ERR31_SHIFT                      (31U)
/*! ERR31 - Error In Channel 31
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_ERR_ERR31_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR31_SHIFT)) & DMA_ERR_ERR31_MASK)
/*! @} */

/*! @name HRS - Hardware Request Status Register */
/*! @{ */

#define DMA_HRS_HRS0_MASK                        (0x1U)
#define DMA_HRS_HRS0_SHIFT                       (0U)
/*! HRS0 - Hardware Request Status Channel 0
 *  0b0..A hardware service request for channel 0 is not present
 *  0b1..A hardware service request for channel 0 is present
 */
#define DMA_HRS_HRS0_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS0_SHIFT)) & DMA_HRS_HRS0_MASK)

#define DMA_HRS_HRS1_MASK                        (0x2U)
#define DMA_HRS_HRS1_SHIFT                       (1U)
/*! HRS1 - Hardware Request Status Channel 1
 *  0b0..A hardware service request for channel 1 is not present
 *  0b1..A hardware service request for channel 1 is present
 */
#define DMA_HRS_HRS1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS1_SHIFT)) & DMA_HRS_HRS1_MASK)

#define DMA_HRS_HRS2_MASK                        (0x4U)
#define DMA_HRS_HRS2_SHIFT                       (2U)
/*! HRS2 - Hardware Request Status Channel 2
 *  0b0..A hardware service request for channel 2 is not present
 *  0b1..A hardware service request for channel 2 is present
 */
#define DMA_HRS_HRS2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS2_SHIFT)) & DMA_HRS_HRS2_MASK)

#define DMA_HRS_HRS3_MASK                        (0x8U)
#define DMA_HRS_HRS3_SHIFT                       (3U)
/*! HRS3 - Hardware Request Status Channel 3
 *  0b0..A hardware service request for channel 3 is not present
 *  0b1..A hardware service request for channel 3 is present
 */
#define DMA_HRS_HRS3_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS3_SHIFT)) & DMA_HRS_HRS3_MASK)

#define DMA_HRS_HRS4_MASK                        (0x10U)
#define DMA_HRS_HRS4_SHIFT                       (4U)
/*! HRS4 - Hardware Request Status Channel 4
 *  0b0..A hardware service request for channel 4 is not present
 *  0b1..A hardware service request for channel 4 is present
 */
#define DMA_HRS_HRS4_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS4_SHIFT)) & DMA_HRS_HRS4_MASK)

#define DMA_HRS_HRS5_MASK                        (0x20U)
#define DMA_HRS_HRS5_SHIFT                       (5U)
/*! HRS5 - Hardware Request Status Channel 5
 *  0b0..A hardware service request for channel 5 is not present
 *  0b1..A hardware service request for channel 5 is present
 */
#define DMA_HRS_HRS5_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS5_SHIFT)) & DMA_HRS_HRS5_MASK)

#define DMA_HRS_HRS6_MASK                        (0x40U)
#define DMA_HRS_HRS6_SHIFT                       (6U)
/*! HRS6 - Hardware Request Status Channel 6
 *  0b0..A hardware service request for channel 6 is not present
 *  0b1..A hardware service request for channel 6 is present
 */
#define DMA_HRS_HRS6_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS6_SHIFT)) & DMA_HRS_HRS6_MASK)

#define DMA_HRS_HRS7_MASK                        (0x80U)
#define DMA_HRS_HRS7_SHIFT                       (7U)
/*! HRS7 - Hardware Request Status Channel 7
 *  0b0..A hardware service request for channel 7 is not present
 *  0b1..A hardware service request for channel 7 is present
 */
#define DMA_HRS_HRS7_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS7_SHIFT)) & DMA_HRS_HRS7_MASK)

#define DMA_HRS_HRS8_MASK                        (0x100U)
#define DMA_HRS_HRS8_SHIFT                       (8U)
/*! HRS8 - Hardware Request Status Channel 8
 *  0b0..A hardware service request for channel 8 is not present
 *  0b1..A hardware service request for channel 8 is present
 */
#define DMA_HRS_HRS8_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS8_SHIFT)) & DMA_HRS_HRS8_MASK)

#define DMA_HRS_HRS9_MASK                        (0x200U)
#define DMA_HRS_HRS9_SHIFT                       (9U)
/*! HRS9 - Hardware Request Status Channel 9
 *  0b0..A hardware service request for channel 9 is not present
 *  0b1..A hardware service request for channel 9 is present
 */
#define DMA_HRS_HRS9_SET(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS9_SHIFT)) & DMA_HRS_HRS9_MASK)

#define DMA_HRS_HRS10_MASK                       (0x400U)
#define DMA_HRS_HRS10_SHIFT                      (10U)
/*! HRS10 - Hardware Request Status Channel 10
 *  0b0..A hardware service request for channel 10 is not present
 *  0b1..A hardware service request for channel 10 is present
 */
#define DMA_HRS_HRS10_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS10_SHIFT)) & DMA_HRS_HRS10_MASK)

#define DMA_HRS_HRS11_MASK                       (0x800U)
#define DMA_HRS_HRS11_SHIFT                      (11U)
/*! HRS11 - Hardware Request Status Channel 11
 *  0b0..A hardware service request for channel 11 is not present
 *  0b1..A hardware service request for channel 11 is present
 */
#define DMA_HRS_HRS11_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS11_SHIFT)) & DMA_HRS_HRS11_MASK)

#define DMA_HRS_HRS12_MASK                       (0x1000U)
#define DMA_HRS_HRS12_SHIFT                      (12U)
/*! HRS12 - Hardware Request Status Channel 12
 *  0b0..A hardware service request for channel 12 is not present
 *  0b1..A hardware service request for channel 12 is present
 */
#define DMA_HRS_HRS12_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS12_SHIFT)) & DMA_HRS_HRS12_MASK)

#define DMA_HRS_HRS13_MASK                       (0x2000U)
#define DMA_HRS_HRS13_SHIFT                      (13U)
/*! HRS13 - Hardware Request Status Channel 13
 *  0b0..A hardware service request for channel 13 is not present
 *  0b1..A hardware service request for channel 13 is present
 */
#define DMA_HRS_HRS13_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS13_SHIFT)) & DMA_HRS_HRS13_MASK)

#define DMA_HRS_HRS14_MASK                       (0x4000U)
#define DMA_HRS_HRS14_SHIFT                      (14U)
/*! HRS14 - Hardware Request Status Channel 14
 *  0b0..A hardware service request for channel 14 is not present
 *  0b1..A hardware service request for channel 14 is present
 */
#define DMA_HRS_HRS14_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS14_SHIFT)) & DMA_HRS_HRS14_MASK)

#define DMA_HRS_HRS15_MASK                       (0x8000U)
#define DMA_HRS_HRS15_SHIFT                      (15U)
/*! HRS15 - Hardware Request Status Channel 15
 *  0b0..A hardware service request for channel 15 is not present
 *  0b1..A hardware service request for channel 15 is present
 */
#define DMA_HRS_HRS15_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS15_SHIFT)) & DMA_HRS_HRS15_MASK)

#define DMA_HRS_HRS16_MASK                       (0x10000U)
#define DMA_HRS_HRS16_SHIFT                      (16U)
/*! HRS16 - Hardware Request Status Channel 16
 *  0b0..A hardware service request for channel 16 is not present
 *  0b1..A hardware service request for channel 16 is present
 */
#define DMA_HRS_HRS16_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS16_SHIFT)) & DMA_HRS_HRS16_MASK)

#define DMA_HRS_HRS17_MASK                       (0x20000U)
#define DMA_HRS_HRS17_SHIFT                      (17U)
/*! HRS17 - Hardware Request Status Channel 17
 *  0b0..A hardware service request for channel 17 is not present
 *  0b1..A hardware service request for channel 17 is present
 */
#define DMA_HRS_HRS17_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS17_SHIFT)) & DMA_HRS_HRS17_MASK)

#define DMA_HRS_HRS18_MASK                       (0x40000U)
#define DMA_HRS_HRS18_SHIFT                      (18U)
/*! HRS18 - Hardware Request Status Channel 18
 *  0b0..A hardware service request for channel 18 is not present
 *  0b1..A hardware service request for channel 18 is present
 */
#define DMA_HRS_HRS18_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS18_SHIFT)) & DMA_HRS_HRS18_MASK)

#define DMA_HRS_HRS19_MASK                       (0x80000U)
#define DMA_HRS_HRS19_SHIFT                      (19U)
/*! HRS19 - Hardware Request Status Channel 19
 *  0b0..A hardware service request for channel 19 is not present
 *  0b1..A hardware service request for channel 19 is present
 */
#define DMA_HRS_HRS19_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS19_SHIFT)) & DMA_HRS_HRS19_MASK)

#define DMA_HRS_HRS20_MASK                       (0x100000U)
#define DMA_HRS_HRS20_SHIFT                      (20U)
/*! HRS20 - Hardware Request Status Channel 20
 *  0b0..A hardware service request for channel 20 is not present
 *  0b1..A hardware service request for channel 20 is present
 */
#define DMA_HRS_HRS20_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS20_SHIFT)) & DMA_HRS_HRS20_MASK)

#define DMA_HRS_HRS21_MASK                       (0x200000U)
#define DMA_HRS_HRS21_SHIFT                      (21U)
/*! HRS21 - Hardware Request Status Channel 21
 *  0b0..A hardware service request for channel 21 is not present
 *  0b1..A hardware service request for channel 21 is present
 */
#define DMA_HRS_HRS21_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS21_SHIFT)) & DMA_HRS_HRS21_MASK)

#define DMA_HRS_HRS22_MASK                       (0x400000U)
#define DMA_HRS_HRS22_SHIFT                      (22U)
/*! HRS22 - Hardware Request Status Channel 22
 *  0b0..A hardware service request for channel 22 is not present
 *  0b1..A hardware service request for channel 22 is present
 */
#define DMA_HRS_HRS22_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS22_SHIFT)) & DMA_HRS_HRS22_MASK)

#define DMA_HRS_HRS23_MASK                       (0x800000U)
#define DMA_HRS_HRS23_SHIFT                      (23U)
/*! HRS23 - Hardware Request Status Channel 23
 *  0b0..A hardware service request for channel 23 is not present
 *  0b1..A hardware service request for channel 23 is present
 */
#define DMA_HRS_HRS23_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS23_SHIFT)) & DMA_HRS_HRS23_MASK)

#define DMA_HRS_HRS24_MASK                       (0x1000000U)
#define DMA_HRS_HRS24_SHIFT                      (24U)
/*! HRS24 - Hardware Request Status Channel 24
 *  0b0..A hardware service request for channel 24 is not present
 *  0b1..A hardware service request for channel 24 is present
 */
#define DMA_HRS_HRS24_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS24_SHIFT)) & DMA_HRS_HRS24_MASK)

#define DMA_HRS_HRS25_MASK                       (0x2000000U)
#define DMA_HRS_HRS25_SHIFT                      (25U)
/*! HRS25 - Hardware Request Status Channel 25
 *  0b0..A hardware service request for channel 25 is not present
 *  0b1..A hardware service request for channel 25 is present
 */
#define DMA_HRS_HRS25_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS25_SHIFT)) & DMA_HRS_HRS25_MASK)

#define DMA_HRS_HRS26_MASK                       (0x4000000U)
#define DMA_HRS_HRS26_SHIFT                      (26U)
/*! HRS26 - Hardware Request Status Channel 26
 *  0b0..A hardware service request for channel 26 is not present
 *  0b1..A hardware service request for channel 26 is present
 */
#define DMA_HRS_HRS26_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS26_SHIFT)) & DMA_HRS_HRS26_MASK)

#define DMA_HRS_HRS27_MASK                       (0x8000000U)
#define DMA_HRS_HRS27_SHIFT                      (27U)
/*! HRS27 - Hardware Request Status Channel 27
 *  0b0..A hardware service request for channel 27 is not present
 *  0b1..A hardware service request for channel 27 is present
 */
#define DMA_HRS_HRS27_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS27_SHIFT)) & DMA_HRS_HRS27_MASK)

#define DMA_HRS_HRS28_MASK                       (0x10000000U)
#define DMA_HRS_HRS28_SHIFT                      (28U)
/*! HRS28 - Hardware Request Status Channel 28
 *  0b0..A hardware service request for channel 28 is not present
 *  0b1..A hardware service request for channel 28 is present
 */
#define DMA_HRS_HRS28_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS28_SHIFT)) & DMA_HRS_HRS28_MASK)

#define DMA_HRS_HRS29_MASK                       (0x20000000U)
#define DMA_HRS_HRS29_SHIFT                      (29U)
/*! HRS29 - Hardware Request Status Channel 29
 *  0b0..A hardware service request for channel 29 is not preset
 *  0b1..A hardware service request for channel 29 is present
 */
#define DMA_HRS_HRS29_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS29_SHIFT)) & DMA_HRS_HRS29_MASK)

#define DMA_HRS_HRS30_MASK                       (0x40000000U)
#define DMA_HRS_HRS30_SHIFT                      (30U)
/*! HRS30 - Hardware Request Status Channel 30
 *  0b0..A hardware service request for channel 30 is not present
 *  0b1..A hardware service request for for channel 30 is present
 */
#define DMA_HRS_HRS30_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS30_SHIFT)) & DMA_HRS_HRS30_MASK)

#define DMA_HRS_HRS31_MASK                       (0x80000000U)
#define DMA_HRS_HRS31_SHIFT                      (31U)
/*! HRS31 - Hardware Request Status Channel 31
 *  0b0..A hardware service request for channel 31 is not present
 *  0b1..A hardware service request for channel 31 is present
 */
#define DMA_HRS_HRS31_SET(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS31_SHIFT)) & DMA_HRS_HRS31_MASK)
/*! @} */

/*! @name EARS - Enable Asynchronous Request in Stop Register */
/*! @{ */

#define DMA_EARS_EDREQ_0_MASK                    (0x1U)
#define DMA_EARS_EDREQ_0_SHIFT                   (0U)
/*! EDREQ_0 - Enable asynchronous DMA request in stop mode for channel 0.
 *  0b0..Disable asynchronous DMA request for channel 0.
 *  0b1..Enable asynchronous DMA request for channel 0.
 */
#define DMA_EARS_EDREQ_0_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_0_SHIFT)) & DMA_EARS_EDREQ_0_MASK)

#define DMA_EARS_EDREQ_1_MASK                    (0x2U)
#define DMA_EARS_EDREQ_1_SHIFT                   (1U)
/*! EDREQ_1 - Enable asynchronous DMA request in stop mode for channel 1.
 *  0b0..Disable asynchronous DMA request for channel 1
 *  0b1..Enable asynchronous DMA request for channel 1.
 */
#define DMA_EARS_EDREQ_1_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_1_SHIFT)) & DMA_EARS_EDREQ_1_MASK)

#define DMA_EARS_EDREQ_2_MASK                    (0x4U)
#define DMA_EARS_EDREQ_2_SHIFT                   (2U)
/*! EDREQ_2 - Enable asynchronous DMA request in stop mode for channel 2.
 *  0b0..Disable asynchronous DMA request for channel 2.
 *  0b1..Enable asynchronous DMA request for channel 2.
 */
#define DMA_EARS_EDREQ_2_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_2_SHIFT)) & DMA_EARS_EDREQ_2_MASK)

#define DMA_EARS_EDREQ_3_MASK                    (0x8U)
#define DMA_EARS_EDREQ_3_SHIFT                   (3U)
/*! EDREQ_3 - Enable asynchronous DMA request in stop mode for channel 3.
 *  0b0..Disable asynchronous DMA request for channel 3.
 *  0b1..Enable asynchronous DMA request for channel 3.
 */
#define DMA_EARS_EDREQ_3_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_3_SHIFT)) & DMA_EARS_EDREQ_3_MASK)

#define DMA_EARS_EDREQ_4_MASK                    (0x10U)
#define DMA_EARS_EDREQ_4_SHIFT                   (4U)
/*! EDREQ_4 - Enable asynchronous DMA request in stop mode for channel 4
 *  0b0..Disable asynchronous DMA request for channel 4.
 *  0b1..Enable asynchronous DMA request for channel 4.
 */
#define DMA_EARS_EDREQ_4_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_4_SHIFT)) & DMA_EARS_EDREQ_4_MASK)

#define DMA_EARS_EDREQ_5_MASK                    (0x20U)
#define DMA_EARS_EDREQ_5_SHIFT                   (5U)
/*! EDREQ_5 - Enable asynchronous DMA request in stop mode for channel 5
 *  0b0..Disable asynchronous DMA request for channel 5.
 *  0b1..Enable asynchronous DMA request for channel 5.
 */
#define DMA_EARS_EDREQ_5_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_5_SHIFT)) & DMA_EARS_EDREQ_5_MASK)

#define DMA_EARS_EDREQ_6_MASK                    (0x40U)
#define DMA_EARS_EDREQ_6_SHIFT                   (6U)
/*! EDREQ_6 - Enable asynchronous DMA request in stop mode for channel 6
 *  0b0..Disable asynchronous DMA request for channel 6.
 *  0b1..Enable asynchronous DMA request for channel 6.
 */
#define DMA_EARS_EDREQ_6_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_6_SHIFT)) & DMA_EARS_EDREQ_6_MASK)

#define DMA_EARS_EDREQ_7_MASK                    (0x80U)
#define DMA_EARS_EDREQ_7_SHIFT                   (7U)
/*! EDREQ_7 - Enable asynchronous DMA request in stop mode for channel 7
 *  0b0..Disable asynchronous DMA request for channel 7.
 *  0b1..Enable asynchronous DMA request for channel 7.
 */
#define DMA_EARS_EDREQ_7_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_7_SHIFT)) & DMA_EARS_EDREQ_7_MASK)

#define DMA_EARS_EDREQ_8_MASK                    (0x100U)
#define DMA_EARS_EDREQ_8_SHIFT                   (8U)
/*! EDREQ_8 - Enable asynchronous DMA request in stop mode for channel 8
 *  0b0..Disable asynchronous DMA request for channel 8.
 *  0b1..Enable asynchronous DMA request for channel 8.
 */
#define DMA_EARS_EDREQ_8_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_8_SHIFT)) & DMA_EARS_EDREQ_8_MASK)

#define DMA_EARS_EDREQ_9_MASK                    (0x200U)
#define DMA_EARS_EDREQ_9_SHIFT                   (9U)
/*! EDREQ_9 - Enable asynchronous DMA request in stop mode for channel 9
 *  0b0..Disable asynchronous DMA request for channel 9.
 *  0b1..Enable asynchronous DMA request for channel 9.
 */
#define DMA_EARS_EDREQ_9_SET(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_9_SHIFT)) & DMA_EARS_EDREQ_9_MASK)

#define DMA_EARS_EDREQ_10_MASK                   (0x400U)
#define DMA_EARS_EDREQ_10_SHIFT                  (10U)
/*! EDREQ_10 - Enable asynchronous DMA request in stop mode for channel 10
 *  0b0..Disable asynchronous DMA request for channel 10.
 *  0b1..Enable asynchronous DMA request for channel 10.
 */
#define DMA_EARS_EDREQ_10_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_10_SHIFT)) & DMA_EARS_EDREQ_10_MASK)

#define DMA_EARS_EDREQ_11_MASK                   (0x800U)
#define DMA_EARS_EDREQ_11_SHIFT                  (11U)
/*! EDREQ_11 - Enable asynchronous DMA request in stop mode for channel 11
 *  0b0..Disable asynchronous DMA request for channel 11.
 *  0b1..Enable asynchronous DMA request for channel 11.
 */
#define DMA_EARS_EDREQ_11_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_11_SHIFT)) & DMA_EARS_EDREQ_11_MASK)

#define DMA_EARS_EDREQ_12_MASK                   (0x1000U)
#define DMA_EARS_EDREQ_12_SHIFT                  (12U)
/*! EDREQ_12 - Enable asynchronous DMA request in stop mode for channel 12
 *  0b0..Disable asynchronous DMA request for channel 12.
 *  0b1..Enable asynchronous DMA request for channel 12.
 */
#define DMA_EARS_EDREQ_12_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_12_SHIFT)) & DMA_EARS_EDREQ_12_MASK)

#define DMA_EARS_EDREQ_13_MASK                   (0x2000U)
#define DMA_EARS_EDREQ_13_SHIFT                  (13U)
/*! EDREQ_13 - Enable asynchronous DMA request in stop mode for channel 13
 *  0b0..Disable asynchronous DMA request for channel 13.
 *  0b1..Enable asynchronous DMA request for channel 13.
 */
#define DMA_EARS_EDREQ_13_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_13_SHIFT)) & DMA_EARS_EDREQ_13_MASK)

#define DMA_EARS_EDREQ_14_MASK                   (0x4000U)
#define DMA_EARS_EDREQ_14_SHIFT                  (14U)
/*! EDREQ_14 - Enable asynchronous DMA request in stop mode for channel 14
 *  0b0..Disable asynchronous DMA request for channel 14.
 *  0b1..Enable asynchronous DMA request for channel 14.
 */
#define DMA_EARS_EDREQ_14_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_14_SHIFT)) & DMA_EARS_EDREQ_14_MASK)

#define DMA_EARS_EDREQ_15_MASK                   (0x8000U)
#define DMA_EARS_EDREQ_15_SHIFT                  (15U)
/*! EDREQ_15 - Enable asynchronous DMA request in stop mode for channel 15
 *  0b0..Disable asynchronous DMA request for channel 15.
 *  0b1..Enable asynchronous DMA request for channel 15.
 */
#define DMA_EARS_EDREQ_15_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_15_SHIFT)) & DMA_EARS_EDREQ_15_MASK)

#define DMA_EARS_EDREQ_16_MASK                   (0x10000U)
#define DMA_EARS_EDREQ_16_SHIFT                  (16U)
/*! EDREQ_16 - Enable asynchronous DMA request in stop mode for channel 16
 *  0b0..Disable asynchronous DMA request for channel 16
 *  0b1..Enable asynchronous DMA request for channel 16
 */
#define DMA_EARS_EDREQ_16_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_16_SHIFT)) & DMA_EARS_EDREQ_16_MASK)

#define DMA_EARS_EDREQ_17_MASK                   (0x20000U)
#define DMA_EARS_EDREQ_17_SHIFT                  (17U)
/*! EDREQ_17 - Enable asynchronous DMA request in stop mode for channel 17
 *  0b0..Disable asynchronous DMA request for channel 17
 *  0b1..Enable asynchronous DMA request for channel 17
 */
#define DMA_EARS_EDREQ_17_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_17_SHIFT)) & DMA_EARS_EDREQ_17_MASK)

#define DMA_EARS_EDREQ_18_MASK                   (0x40000U)
#define DMA_EARS_EDREQ_18_SHIFT                  (18U)
/*! EDREQ_18 - Enable asynchronous DMA request in stop mode for channel 18
 *  0b0..Disable asynchronous DMA request for channel 18
 *  0b1..Enable asynchronous DMA request for channel 18
 */
#define DMA_EARS_EDREQ_18_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_18_SHIFT)) & DMA_EARS_EDREQ_18_MASK)

#define DMA_EARS_EDREQ_19_MASK                   (0x80000U)
#define DMA_EARS_EDREQ_19_SHIFT                  (19U)
/*! EDREQ_19 - Enable asynchronous DMA request in stop mode for channel 19
 *  0b0..Disable asynchronous DMA request for channel 19
 *  0b1..Enable asynchronous DMA request for channel 19
 */
#define DMA_EARS_EDREQ_19_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_19_SHIFT)) & DMA_EARS_EDREQ_19_MASK)

#define DMA_EARS_EDREQ_20_MASK                   (0x100000U)
#define DMA_EARS_EDREQ_20_SHIFT                  (20U)
/*! EDREQ_20 - Enable asynchronous DMA request in stop mode for channel 20
 *  0b0..Disable asynchronous DMA request for channel 20
 *  0b1..Enable asynchronous DMA request for channel 20
 */
#define DMA_EARS_EDREQ_20_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_20_SHIFT)) & DMA_EARS_EDREQ_20_MASK)

#define DMA_EARS_EDREQ_21_MASK                   (0x200000U)
#define DMA_EARS_EDREQ_21_SHIFT                  (21U)
/*! EDREQ_21 - Enable asynchronous DMA request in stop mode for channel 21
 *  0b0..Disable asynchronous DMA request for channel 21
 *  0b1..Enable asynchronous DMA request for channel 21
 */
#define DMA_EARS_EDREQ_21_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_21_SHIFT)) & DMA_EARS_EDREQ_21_MASK)

#define DMA_EARS_EDREQ_22_MASK                   (0x400000U)
#define DMA_EARS_EDREQ_22_SHIFT                  (22U)
/*! EDREQ_22 - Enable asynchronous DMA request in stop mode for channel 22
 *  0b0..Disable asynchronous DMA request for channel 22
 *  0b1..Enable asynchronous DMA request for channel 22
 */
#define DMA_EARS_EDREQ_22_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_22_SHIFT)) & DMA_EARS_EDREQ_22_MASK)

#define DMA_EARS_EDREQ_23_MASK                   (0x800000U)
#define DMA_EARS_EDREQ_23_SHIFT                  (23U)
/*! EDREQ_23 - Enable asynchronous DMA request in stop mode for channel 23
 *  0b0..Disable asynchronous DMA request for channel 23
 *  0b1..Enable asynchronous DMA request for channel 23
 */
#define DMA_EARS_EDREQ_23_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_23_SHIFT)) & DMA_EARS_EDREQ_23_MASK)

#define DMA_EARS_EDREQ_24_MASK                   (0x1000000U)
#define DMA_EARS_EDREQ_24_SHIFT                  (24U)
/*! EDREQ_24 - Enable asynchronous DMA request in stop mode for channel 24
 *  0b0..Disable asynchronous DMA request for channel 24
 *  0b1..Enable asynchronous DMA request for channel 24
 */
#define DMA_EARS_EDREQ_24_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_24_SHIFT)) & DMA_EARS_EDREQ_24_MASK)

#define DMA_EARS_EDREQ_25_MASK                   (0x2000000U)
#define DMA_EARS_EDREQ_25_SHIFT                  (25U)
/*! EDREQ_25 - Enable asynchronous DMA request in stop mode for channel 25
 *  0b0..Disable asynchronous DMA request for channel 25
 *  0b1..Enable asynchronous DMA request for channel 25
 */
#define DMA_EARS_EDREQ_25_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_25_SHIFT)) & DMA_EARS_EDREQ_25_MASK)

#define DMA_EARS_EDREQ_26_MASK                   (0x4000000U)
#define DMA_EARS_EDREQ_26_SHIFT                  (26U)
/*! EDREQ_26 - Enable asynchronous DMA request in stop mode for channel 26
 *  0b0..Disable asynchronous DMA request for channel 26
 *  0b1..Enable asynchronous DMA request for channel 26
 */
#define DMA_EARS_EDREQ_26_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_26_SHIFT)) & DMA_EARS_EDREQ_26_MASK)

#define DMA_EARS_EDREQ_27_MASK                   (0x8000000U)
#define DMA_EARS_EDREQ_27_SHIFT                  (27U)
/*! EDREQ_27 - Enable asynchronous DMA request in stop mode for channel 27
 *  0b0..Disable asynchronous DMA request for channel 27
 *  0b1..Enable asynchronous DMA request for channel 27
 */
#define DMA_EARS_EDREQ_27_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_27_SHIFT)) & DMA_EARS_EDREQ_27_MASK)

#define DMA_EARS_EDREQ_28_MASK                   (0x10000000U)
#define DMA_EARS_EDREQ_28_SHIFT                  (28U)
/*! EDREQ_28 - Enable asynchronous DMA request in stop mode for channel 28
 *  0b0..Disable asynchronous DMA request for channel 28
 *  0b1..Enable asynchronous DMA request for channel 28
 */
#define DMA_EARS_EDREQ_28_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_28_SHIFT)) & DMA_EARS_EDREQ_28_MASK)

#define DMA_EARS_EDREQ_29_MASK                   (0x20000000U)
#define DMA_EARS_EDREQ_29_SHIFT                  (29U)
/*! EDREQ_29 - Enable asynchronous DMA request in stop mode for channel 29
 *  0b0..Disable asynchronous DMA request for channel 29
 *  0b1..Enable asynchronous DMA request for channel 29
 */
#define DMA_EARS_EDREQ_29_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_29_SHIFT)) & DMA_EARS_EDREQ_29_MASK)

#define DMA_EARS_EDREQ_30_MASK                   (0x40000000U)
#define DMA_EARS_EDREQ_30_SHIFT                  (30U)
/*! EDREQ_30 - Enable asynchronous DMA request in stop mode for channel 30
 *  0b0..Disable asynchronous DMA request for channel 30
 *  0b1..Enable asynchronous DMA request for channel 30
 */
#define DMA_EARS_EDREQ_30_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_30_SHIFT)) & DMA_EARS_EDREQ_30_MASK)

#define DMA_EARS_EDREQ_31_MASK                   (0x80000000U)
#define DMA_EARS_EDREQ_31_SHIFT                  (31U)
/*! EDREQ_31 - Enable asynchronous DMA request in stop mode for channel 31
 *  0b0..Disable asynchronous DMA request for channel 31
 *  0b1..Enable asynchronous DMA request for channel 31
 */
#define DMA_EARS_EDREQ_31_SET(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_31_SHIFT)) & DMA_EARS_EDREQ_31_MASK)
/*! @} */

/*! @name DCHPRI3 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI3_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI3_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI3_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI3_CHPRI_SHIFT)) & DMA_DCHPRI3_CHPRI_MASK)

#define DMA_DCHPRI3_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI3_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI3_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI3_GRPPRI_SHIFT)) & DMA_DCHPRI3_GRPPRI_MASK)

#define DMA_DCHPRI3_DPA_MASK                     (0x40U)
#define DMA_DCHPRI3_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI3_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI3_DPA_SHIFT)) & DMA_DCHPRI3_DPA_MASK)

#define DMA_DCHPRI3_ECP_MASK                     (0x80U)
#define DMA_DCHPRI3_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI3_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI3_ECP_SHIFT)) & DMA_DCHPRI3_ECP_MASK)
/*! @} */

/*! @name DCHPRI2 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI2_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI2_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI2_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI2_CHPRI_SHIFT)) & DMA_DCHPRI2_CHPRI_MASK)

#define DMA_DCHPRI2_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI2_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI2_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI2_GRPPRI_SHIFT)) & DMA_DCHPRI2_GRPPRI_MASK)

#define DMA_DCHPRI2_DPA_MASK                     (0x40U)
#define DMA_DCHPRI2_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI2_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI2_DPA_SHIFT)) & DMA_DCHPRI2_DPA_MASK)

#define DMA_DCHPRI2_ECP_MASK                     (0x80U)
#define DMA_DCHPRI2_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI2_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI2_ECP_SHIFT)) & DMA_DCHPRI2_ECP_MASK)
/*! @} */

/*! @name DCHPRI1 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI1_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI1_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI1_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI1_CHPRI_SHIFT)) & DMA_DCHPRI1_CHPRI_MASK)

#define DMA_DCHPRI1_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI1_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI1_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI1_GRPPRI_SHIFT)) & DMA_DCHPRI1_GRPPRI_MASK)

#define DMA_DCHPRI1_DPA_MASK                     (0x40U)
#define DMA_DCHPRI1_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI1_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI1_DPA_SHIFT)) & DMA_DCHPRI1_DPA_MASK)

#define DMA_DCHPRI1_ECP_MASK                     (0x80U)
#define DMA_DCHPRI1_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI1_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI1_ECP_SHIFT)) & DMA_DCHPRI1_ECP_MASK)
/*! @} */

/*! @name DCHPRI0 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI0_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI0_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI0_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI0_CHPRI_SHIFT)) & DMA_DCHPRI0_CHPRI_MASK)

#define DMA_DCHPRI0_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI0_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI0_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI0_GRPPRI_SHIFT)) & DMA_DCHPRI0_GRPPRI_MASK)

#define DMA_DCHPRI0_DPA_MASK                     (0x40U)
#define DMA_DCHPRI0_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI0_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI0_DPA_SHIFT)) & DMA_DCHPRI0_DPA_MASK)

#define DMA_DCHPRI0_ECP_MASK                     (0x80U)
#define DMA_DCHPRI0_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI0_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI0_ECP_SHIFT)) & DMA_DCHPRI0_ECP_MASK)
/*! @} */

/*! @name DCHPRI7 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI7_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI7_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI7_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI7_CHPRI_SHIFT)) & DMA_DCHPRI7_CHPRI_MASK)

#define DMA_DCHPRI7_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI7_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI7_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI7_GRPPRI_SHIFT)) & DMA_DCHPRI7_GRPPRI_MASK)

#define DMA_DCHPRI7_DPA_MASK                     (0x40U)
#define DMA_DCHPRI7_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI7_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI7_DPA_SHIFT)) & DMA_DCHPRI7_DPA_MASK)

#define DMA_DCHPRI7_ECP_MASK                     (0x80U)
#define DMA_DCHPRI7_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI7_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI7_ECP_SHIFT)) & DMA_DCHPRI7_ECP_MASK)
/*! @} */

/*! @name DCHPRI6 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI6_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI6_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI6_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI6_CHPRI_SHIFT)) & DMA_DCHPRI6_CHPRI_MASK)

#define DMA_DCHPRI6_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI6_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI6_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI6_GRPPRI_SHIFT)) & DMA_DCHPRI6_GRPPRI_MASK)

#define DMA_DCHPRI6_DPA_MASK                     (0x40U)
#define DMA_DCHPRI6_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI6_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI6_DPA_SHIFT)) & DMA_DCHPRI6_DPA_MASK)

#define DMA_DCHPRI6_ECP_MASK                     (0x80U)
#define DMA_DCHPRI6_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI6_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI6_ECP_SHIFT)) & DMA_DCHPRI6_ECP_MASK)
/*! @} */

/*! @name DCHPRI5 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI5_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI5_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI5_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI5_CHPRI_SHIFT)) & DMA_DCHPRI5_CHPRI_MASK)

#define DMA_DCHPRI5_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI5_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI5_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI5_GRPPRI_SHIFT)) & DMA_DCHPRI5_GRPPRI_MASK)

#define DMA_DCHPRI5_DPA_MASK                     (0x40U)
#define DMA_DCHPRI5_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI5_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI5_DPA_SHIFT)) & DMA_DCHPRI5_DPA_MASK)

#define DMA_DCHPRI5_ECP_MASK                     (0x80U)
#define DMA_DCHPRI5_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI5_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI5_ECP_SHIFT)) & DMA_DCHPRI5_ECP_MASK)
/*! @} */

/*! @name DCHPRI4 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI4_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI4_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI4_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI4_CHPRI_SHIFT)) & DMA_DCHPRI4_CHPRI_MASK)

#define DMA_DCHPRI4_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI4_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI4_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI4_GRPPRI_SHIFT)) & DMA_DCHPRI4_GRPPRI_MASK)

#define DMA_DCHPRI4_DPA_MASK                     (0x40U)
#define DMA_DCHPRI4_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI4_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI4_DPA_SHIFT)) & DMA_DCHPRI4_DPA_MASK)

#define DMA_DCHPRI4_ECP_MASK                     (0x80U)
#define DMA_DCHPRI4_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI4_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI4_ECP_SHIFT)) & DMA_DCHPRI4_ECP_MASK)
/*! @} */

/*! @name DCHPRI11 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI11_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI11_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI11_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI11_CHPRI_SHIFT)) & DMA_DCHPRI11_CHPRI_MASK)

#define DMA_DCHPRI11_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI11_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI11_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI11_GRPPRI_SHIFT)) & DMA_DCHPRI11_GRPPRI_MASK)

#define DMA_DCHPRI11_DPA_MASK                    (0x40U)
#define DMA_DCHPRI11_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI11_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI11_DPA_SHIFT)) & DMA_DCHPRI11_DPA_MASK)

#define DMA_DCHPRI11_ECP_MASK                    (0x80U)
#define DMA_DCHPRI11_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI11_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI11_ECP_SHIFT)) & DMA_DCHPRI11_ECP_MASK)
/*! @} */

/*! @name DCHPRI10 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI10_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI10_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI10_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI10_CHPRI_SHIFT)) & DMA_DCHPRI10_CHPRI_MASK)

#define DMA_DCHPRI10_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI10_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI10_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI10_GRPPRI_SHIFT)) & DMA_DCHPRI10_GRPPRI_MASK)

#define DMA_DCHPRI10_DPA_MASK                    (0x40U)
#define DMA_DCHPRI10_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI10_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI10_DPA_SHIFT)) & DMA_DCHPRI10_DPA_MASK)

#define DMA_DCHPRI10_ECP_MASK                    (0x80U)
#define DMA_DCHPRI10_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI10_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI10_ECP_SHIFT)) & DMA_DCHPRI10_ECP_MASK)
/*! @} */

/*! @name DCHPRI9 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI9_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI9_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI9_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI9_CHPRI_SHIFT)) & DMA_DCHPRI9_CHPRI_MASK)

#define DMA_DCHPRI9_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI9_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI9_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI9_GRPPRI_SHIFT)) & DMA_DCHPRI9_GRPPRI_MASK)

#define DMA_DCHPRI9_DPA_MASK                     (0x40U)
#define DMA_DCHPRI9_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI9_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI9_DPA_SHIFT)) & DMA_DCHPRI9_DPA_MASK)

#define DMA_DCHPRI9_ECP_MASK                     (0x80U)
#define DMA_DCHPRI9_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI9_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI9_ECP_SHIFT)) & DMA_DCHPRI9_ECP_MASK)
/*! @} */

/*! @name DCHPRI8 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI8_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI8_CHPRI_SHIFT                  (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI8_CHPRI_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI8_CHPRI_SHIFT)) & DMA_DCHPRI8_CHPRI_MASK)

#define DMA_DCHPRI8_GRPPRI_MASK                  (0x30U)
#define DMA_DCHPRI8_GRPPRI_SHIFT                 (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI8_GRPPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI8_GRPPRI_SHIFT)) & DMA_DCHPRI8_GRPPRI_MASK)

#define DMA_DCHPRI8_DPA_MASK                     (0x40U)
#define DMA_DCHPRI8_DPA_SHIFT                    (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI8_DPA_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI8_DPA_SHIFT)) & DMA_DCHPRI8_DPA_MASK)

#define DMA_DCHPRI8_ECP_MASK                     (0x80U)
#define DMA_DCHPRI8_ECP_SHIFT                    (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI8_ECP_SET(x)                   (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI8_ECP_SHIFT)) & DMA_DCHPRI8_ECP_MASK)
/*! @} */

/*! @name DCHPRI15 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI15_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI15_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI15_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI15_CHPRI_SHIFT)) & DMA_DCHPRI15_CHPRI_MASK)

#define DMA_DCHPRI15_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI15_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI15_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI15_GRPPRI_SHIFT)) & DMA_DCHPRI15_GRPPRI_MASK)

#define DMA_DCHPRI15_DPA_MASK                    (0x40U)
#define DMA_DCHPRI15_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI15_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI15_DPA_SHIFT)) & DMA_DCHPRI15_DPA_MASK)

#define DMA_DCHPRI15_ECP_MASK                    (0x80U)
#define DMA_DCHPRI15_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI15_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI15_ECP_SHIFT)) & DMA_DCHPRI15_ECP_MASK)
/*! @} */

/*! @name DCHPRI14 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI14_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI14_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI14_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI14_CHPRI_SHIFT)) & DMA_DCHPRI14_CHPRI_MASK)

#define DMA_DCHPRI14_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI14_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI14_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI14_GRPPRI_SHIFT)) & DMA_DCHPRI14_GRPPRI_MASK)

#define DMA_DCHPRI14_DPA_MASK                    (0x40U)
#define DMA_DCHPRI14_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI14_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI14_DPA_SHIFT)) & DMA_DCHPRI14_DPA_MASK)

#define DMA_DCHPRI14_ECP_MASK                    (0x80U)
#define DMA_DCHPRI14_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI14_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI14_ECP_SHIFT)) & DMA_DCHPRI14_ECP_MASK)
/*! @} */

/*! @name DCHPRI13 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI13_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI13_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI13_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI13_CHPRI_SHIFT)) & DMA_DCHPRI13_CHPRI_MASK)

#define DMA_DCHPRI13_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI13_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI13_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI13_GRPPRI_SHIFT)) & DMA_DCHPRI13_GRPPRI_MASK)

#define DMA_DCHPRI13_DPA_MASK                    (0x40U)
#define DMA_DCHPRI13_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI13_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI13_DPA_SHIFT)) & DMA_DCHPRI13_DPA_MASK)

#define DMA_DCHPRI13_ECP_MASK                    (0x80U)
#define DMA_DCHPRI13_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI13_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI13_ECP_SHIFT)) & DMA_DCHPRI13_ECP_MASK)
/*! @} */

/*! @name DCHPRI12 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI12_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI12_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI12_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI12_CHPRI_SHIFT)) & DMA_DCHPRI12_CHPRI_MASK)

#define DMA_DCHPRI12_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI12_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI12_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI12_GRPPRI_SHIFT)) & DMA_DCHPRI12_GRPPRI_MASK)

#define DMA_DCHPRI12_DPA_MASK                    (0x40U)
#define DMA_DCHPRI12_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI12_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI12_DPA_SHIFT)) & DMA_DCHPRI12_DPA_MASK)

#define DMA_DCHPRI12_ECP_MASK                    (0x80U)
#define DMA_DCHPRI12_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI12_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI12_ECP_SHIFT)) & DMA_DCHPRI12_ECP_MASK)
/*! @} */

/*! @name DCHPRI19 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI19_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI19_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI19_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI19_CHPRI_SHIFT)) & DMA_DCHPRI19_CHPRI_MASK)

#define DMA_DCHPRI19_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI19_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI19_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI19_GRPPRI_SHIFT)) & DMA_DCHPRI19_GRPPRI_MASK)

#define DMA_DCHPRI19_DPA_MASK                    (0x40U)
#define DMA_DCHPRI19_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI19_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI19_DPA_SHIFT)) & DMA_DCHPRI19_DPA_MASK)

#define DMA_DCHPRI19_ECP_MASK                    (0x80U)
#define DMA_DCHPRI19_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI19_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI19_ECP_SHIFT)) & DMA_DCHPRI19_ECP_MASK)
/*! @} */

/*! @name DCHPRI18 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI18_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI18_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI18_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI18_CHPRI_SHIFT)) & DMA_DCHPRI18_CHPRI_MASK)

#define DMA_DCHPRI18_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI18_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI18_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI18_GRPPRI_SHIFT)) & DMA_DCHPRI18_GRPPRI_MASK)

#define DMA_DCHPRI18_DPA_MASK                    (0x40U)
#define DMA_DCHPRI18_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI18_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI18_DPA_SHIFT)) & DMA_DCHPRI18_DPA_MASK)

#define DMA_DCHPRI18_ECP_MASK                    (0x80U)
#define DMA_DCHPRI18_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI18_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI18_ECP_SHIFT)) & DMA_DCHPRI18_ECP_MASK)
/*! @} */

/*! @name DCHPRI17 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI17_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI17_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI17_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI17_CHPRI_SHIFT)) & DMA_DCHPRI17_CHPRI_MASK)

#define DMA_DCHPRI17_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI17_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI17_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI17_GRPPRI_SHIFT)) & DMA_DCHPRI17_GRPPRI_MASK)

#define DMA_DCHPRI17_DPA_MASK                    (0x40U)
#define DMA_DCHPRI17_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI17_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI17_DPA_SHIFT)) & DMA_DCHPRI17_DPA_MASK)

#define DMA_DCHPRI17_ECP_MASK                    (0x80U)
#define DMA_DCHPRI17_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI17_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI17_ECP_SHIFT)) & DMA_DCHPRI17_ECP_MASK)
/*! @} */

/*! @name DCHPRI16 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI16_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI16_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI16_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI16_CHPRI_SHIFT)) & DMA_DCHPRI16_CHPRI_MASK)

#define DMA_DCHPRI16_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI16_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI16_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI16_GRPPRI_SHIFT)) & DMA_DCHPRI16_GRPPRI_MASK)

#define DMA_DCHPRI16_DPA_MASK                    (0x40U)
#define DMA_DCHPRI16_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI16_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI16_DPA_SHIFT)) & DMA_DCHPRI16_DPA_MASK)

#define DMA_DCHPRI16_ECP_MASK                    (0x80U)
#define DMA_DCHPRI16_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI16_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI16_ECP_SHIFT)) & DMA_DCHPRI16_ECP_MASK)
/*! @} */

/*! @name DCHPRI23 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI23_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI23_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI23_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI23_CHPRI_SHIFT)) & DMA_DCHPRI23_CHPRI_MASK)

#define DMA_DCHPRI23_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI23_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI23_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI23_GRPPRI_SHIFT)) & DMA_DCHPRI23_GRPPRI_MASK)

#define DMA_DCHPRI23_DPA_MASK                    (0x40U)
#define DMA_DCHPRI23_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI23_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI23_DPA_SHIFT)) & DMA_DCHPRI23_DPA_MASK)

#define DMA_DCHPRI23_ECP_MASK                    (0x80U)
#define DMA_DCHPRI23_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI23_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI23_ECP_SHIFT)) & DMA_DCHPRI23_ECP_MASK)
/*! @} */

/*! @name DCHPRI22 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI22_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI22_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI22_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI22_CHPRI_SHIFT)) & DMA_DCHPRI22_CHPRI_MASK)

#define DMA_DCHPRI22_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI22_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI22_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI22_GRPPRI_SHIFT)) & DMA_DCHPRI22_GRPPRI_MASK)

#define DMA_DCHPRI22_DPA_MASK                    (0x40U)
#define DMA_DCHPRI22_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI22_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI22_DPA_SHIFT)) & DMA_DCHPRI22_DPA_MASK)

#define DMA_DCHPRI22_ECP_MASK                    (0x80U)
#define DMA_DCHPRI22_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI22_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI22_ECP_SHIFT)) & DMA_DCHPRI22_ECP_MASK)
/*! @} */

/*! @name DCHPRI21 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI21_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI21_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI21_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI21_CHPRI_SHIFT)) & DMA_DCHPRI21_CHPRI_MASK)

#define DMA_DCHPRI21_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI21_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI21_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI21_GRPPRI_SHIFT)) & DMA_DCHPRI21_GRPPRI_MASK)

#define DMA_DCHPRI21_DPA_MASK                    (0x40U)
#define DMA_DCHPRI21_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI21_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI21_DPA_SHIFT)) & DMA_DCHPRI21_DPA_MASK)

#define DMA_DCHPRI21_ECP_MASK                    (0x80U)
#define DMA_DCHPRI21_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI21_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI21_ECP_SHIFT)) & DMA_DCHPRI21_ECP_MASK)
/*! @} */

/*! @name DCHPRI20 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI20_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI20_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI20_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI20_CHPRI_SHIFT)) & DMA_DCHPRI20_CHPRI_MASK)

#define DMA_DCHPRI20_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI20_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI20_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI20_GRPPRI_SHIFT)) & DMA_DCHPRI20_GRPPRI_MASK)

#define DMA_DCHPRI20_DPA_MASK                    (0x40U)
#define DMA_DCHPRI20_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI20_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI20_DPA_SHIFT)) & DMA_DCHPRI20_DPA_MASK)

#define DMA_DCHPRI20_ECP_MASK                    (0x80U)
#define DMA_DCHPRI20_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI20_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI20_ECP_SHIFT)) & DMA_DCHPRI20_ECP_MASK)
/*! @} */

/*! @name DCHPRI27 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI27_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI27_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI27_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI27_CHPRI_SHIFT)) & DMA_DCHPRI27_CHPRI_MASK)

#define DMA_DCHPRI27_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI27_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI27_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI27_GRPPRI_SHIFT)) & DMA_DCHPRI27_GRPPRI_MASK)

#define DMA_DCHPRI27_DPA_MASK                    (0x40U)
#define DMA_DCHPRI27_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI27_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI27_DPA_SHIFT)) & DMA_DCHPRI27_DPA_MASK)

#define DMA_DCHPRI27_ECP_MASK                    (0x80U)
#define DMA_DCHPRI27_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI27_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI27_ECP_SHIFT)) & DMA_DCHPRI27_ECP_MASK)
/*! @} */

/*! @name DCHPRI26 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI26_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI26_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI26_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI26_CHPRI_SHIFT)) & DMA_DCHPRI26_CHPRI_MASK)

#define DMA_DCHPRI26_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI26_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI26_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI26_GRPPRI_SHIFT)) & DMA_DCHPRI26_GRPPRI_MASK)

#define DMA_DCHPRI26_DPA_MASK                    (0x40U)
#define DMA_DCHPRI26_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI26_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI26_DPA_SHIFT)) & DMA_DCHPRI26_DPA_MASK)

#define DMA_DCHPRI26_ECP_MASK                    (0x80U)
#define DMA_DCHPRI26_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI26_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI26_ECP_SHIFT)) & DMA_DCHPRI26_ECP_MASK)
/*! @} */

/*! @name DCHPRI25 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI25_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI25_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI25_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI25_CHPRI_SHIFT)) & DMA_DCHPRI25_CHPRI_MASK)

#define DMA_DCHPRI25_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI25_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI25_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI25_GRPPRI_SHIFT)) & DMA_DCHPRI25_GRPPRI_MASK)

#define DMA_DCHPRI25_DPA_MASK                    (0x40U)
#define DMA_DCHPRI25_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI25_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI25_DPA_SHIFT)) & DMA_DCHPRI25_DPA_MASK)

#define DMA_DCHPRI25_ECP_MASK                    (0x80U)
#define DMA_DCHPRI25_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI25_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI25_ECP_SHIFT)) & DMA_DCHPRI25_ECP_MASK)
/*! @} */

/*! @name DCHPRI24 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI24_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI24_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI24_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI24_CHPRI_SHIFT)) & DMA_DCHPRI24_CHPRI_MASK)

#define DMA_DCHPRI24_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI24_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI24_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI24_GRPPRI_SHIFT)) & DMA_DCHPRI24_GRPPRI_MASK)

#define DMA_DCHPRI24_DPA_MASK                    (0x40U)
#define DMA_DCHPRI24_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI24_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI24_DPA_SHIFT)) & DMA_DCHPRI24_DPA_MASK)

#define DMA_DCHPRI24_ECP_MASK                    (0x80U)
#define DMA_DCHPRI24_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI24_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI24_ECP_SHIFT)) & DMA_DCHPRI24_ECP_MASK)
/*! @} */

/*! @name DCHPRI31 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI31_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI31_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI31_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI31_CHPRI_SHIFT)) & DMA_DCHPRI31_CHPRI_MASK)

#define DMA_DCHPRI31_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI31_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI31_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI31_GRPPRI_SHIFT)) & DMA_DCHPRI31_GRPPRI_MASK)

#define DMA_DCHPRI31_DPA_MASK                    (0x40U)
#define DMA_DCHPRI31_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI31_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI31_DPA_SHIFT)) & DMA_DCHPRI31_DPA_MASK)

#define DMA_DCHPRI31_ECP_MASK                    (0x80U)
#define DMA_DCHPRI31_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI31_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI31_ECP_SHIFT)) & DMA_DCHPRI31_ECP_MASK)
/*! @} */

/*! @name DCHPRI30 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI30_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI30_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI30_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI30_CHPRI_SHIFT)) & DMA_DCHPRI30_CHPRI_MASK)

#define DMA_DCHPRI30_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI30_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI30_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI30_GRPPRI_SHIFT)) & DMA_DCHPRI30_GRPPRI_MASK)

#define DMA_DCHPRI30_DPA_MASK                    (0x40U)
#define DMA_DCHPRI30_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI30_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI30_DPA_SHIFT)) & DMA_DCHPRI30_DPA_MASK)

#define DMA_DCHPRI30_ECP_MASK                    (0x80U)
#define DMA_DCHPRI30_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI30_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI30_ECP_SHIFT)) & DMA_DCHPRI30_ECP_MASK)
/*! @} */

/*! @name DCHPRI29 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI29_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI29_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI29_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI29_CHPRI_SHIFT)) & DMA_DCHPRI29_CHPRI_MASK)

#define DMA_DCHPRI29_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI29_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI29_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI29_GRPPRI_SHIFT)) & DMA_DCHPRI29_GRPPRI_MASK)

#define DMA_DCHPRI29_DPA_MASK                    (0x40U)
#define DMA_DCHPRI29_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI29_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI29_DPA_SHIFT)) & DMA_DCHPRI29_DPA_MASK)

#define DMA_DCHPRI29_ECP_MASK                    (0x80U)
#define DMA_DCHPRI29_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI29_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI29_ECP_SHIFT)) & DMA_DCHPRI29_ECP_MASK)
/*! @} */

/*! @name DCHPRI28 - Channel n Priority Register */
/*! @{ */

#define DMA_DCHPRI28_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI28_CHPRI_SHIFT                 (0U)
/*! CHPRI - Channel n Arbitration Priority
 */
#define DMA_DCHPRI28_CHPRI_SET(x)                (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI28_CHPRI_SHIFT)) & DMA_DCHPRI28_CHPRI_MASK)

#define DMA_DCHPRI28_GRPPRI_MASK                 (0x30U)
#define DMA_DCHPRI28_GRPPRI_SHIFT                (4U)
/*! GRPPRI - Channel n Current Group Priority
 */
#define DMA_DCHPRI28_GRPPRI_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI28_GRPPRI_SHIFT)) & DMA_DCHPRI28_GRPPRI_MASK)

#define DMA_DCHPRI28_DPA_MASK                    (0x40U)
#define DMA_DCHPRI28_DPA_SHIFT                   (6U)
/*! DPA - Disable Preempt Ability.
 *  0b0..Channel n can suspend a lower priority channel.
 *  0b1..Channel n cannot suspend any channel, regardless of channel priority.
 */
#define DMA_DCHPRI28_DPA_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI28_DPA_SHIFT)) & DMA_DCHPRI28_DPA_MASK)

#define DMA_DCHPRI28_ECP_MASK                    (0x80U)
#define DMA_DCHPRI28_ECP_SHIFT                   (7U)
/*! ECP - Enable Channel Preemption.
 *  0b0..Channel n cannot be suspended by a higher priority channel's service request.
 *  0b1..Channel n can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA_DCHPRI28_ECP_SET(x)                  (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI28_ECP_SHIFT)) & DMA_DCHPRI28_ECP_MASK)
/*! @} */

/*! @name SADDR - TCD Source Address */
/*! @{ */

#define DMA_SADDR_SADDR_MASK                     (0xFFFFFFFFU)
#define DMA_SADDR_SADDR_SHIFT                    (0U)
/*! SADDR - Source Address
 */
#define DMA_SADDR_SADDR_SET(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_SADDR_SADDR_SHIFT)) & DMA_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA_SADDR */
#define DMA_SADDR_COUNT                          (32U)

/*! @name SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_SOFF_SOFF_MASK                       (0xFFFFU)
#define DMA_SOFF_SOFF_SHIFT                      (0U)
/*! SOFF - Source address signed offset
 */
#define DMA_SOFF_SOFF_SET(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_SOFF_SOFF_SHIFT)) & DMA_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA_SOFF */
#define DMA_SOFF_COUNT                           (32U)

/*! @name ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_ATTR_DSIZE_MASK                      (0x7U)
#define DMA_ATTR_DSIZE_SHIFT                     (0U)
/*! DSIZE - Destination data transfer size
 */
#define DMA_ATTR_DSIZE_SET(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_ATTR_DSIZE_SHIFT)) & DMA_ATTR_DSIZE_MASK)

#define DMA_ATTR_DMOD_MASK                       (0xF8U)
#define DMA_ATTR_DMOD_SHIFT                      (3U)
/*! DMOD - Destination Address Modulo
 */
#define DMA_ATTR_DMOD_SET(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_ATTR_DMOD_SHIFT)) & DMA_ATTR_DMOD_MASK)

#define DMA_ATTR_SSIZE_MASK                      (0x700U)
#define DMA_ATTR_SSIZE_SHIFT                     (8U)
/*! SSIZE - Source data transfer size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..Reserved
 *  0b100..16-byte burst
 *  0b101..32-byte burst
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define DMA_ATTR_SSIZE_SET(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_ATTR_SSIZE_SHIFT)) & DMA_ATTR_SSIZE_MASK)

#define DMA_ATTR_SMOD_MASK                       (0xF800U)
#define DMA_ATTR_SMOD_SHIFT                      (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature is disabled
 */
#define DMA_ATTR_SMOD_SET(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_ATTR_SMOD_SHIFT)) & DMA_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA_ATTR */
#define DMA_ATTR_COUNT                           (32U)

/*! @name NBYTES_MLNO - TCD Minor Byte Count (Minor Loop Mapping Disabled) */
/*! @{ */

#define DMA_NBYTES_MLNO_NBYTES_MASK              (0xFFFFFFFFU)
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             (0U)
/*! NBYTES - Minor Byte Transfer Count
 */
#define DMA_NBYTES_MLNO_NBYTES_SET(x)            (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLNO_NBYTES_SHIFT)) & DMA_NBYTES_MLNO_NBYTES_MASK)
/*! @} */

/* The count of DMA_NBYTES_MLNO */
#define DMA_NBYTES_MLNO_COUNT                    (32U)

/*! @name NBYTES_MLOFFNO - TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled) */
/*! @{ */

#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           (0x3FFFFFFFU)
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          (0U)
/*! NBYTES - Minor Byte Transfer Count
 */
#define DMA_NBYTES_MLOFFNO_NBYTES_SET(x)         (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            (0x40000000U)
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           (30U)
/*! DMLOE - Destination Minor Loop Offset enable
 *  0b0..The minor loop offset is not applied to the DADDR
 *  0b1..The minor loop offset is applied to the DADDR
 */
#define DMA_NBYTES_MLOFFNO_DMLOE_SET(x)          (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            (0x80000000U)
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the SADDR
 *  0b1..The minor loop offset is applied to the SADDR
 */
#define DMA_NBYTES_MLOFFNO_SMLOE_SET(x)          (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA_NBYTES_MLOFFNO */
#define DMA_NBYTES_MLOFFNO_COUNT                 (32U)

/*! @name NBYTES_MLOFFYES - TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled) */
/*! @{ */

#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          (0x3FFU)
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         (0U)
/*! NBYTES - Minor Byte Transfer Count
 */
#define DMA_NBYTES_MLOFFYES_NBYTES_SET(x)        (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           (0x3FFFFC00U)
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          (10U)
/*! MLOFF - If SMLOE or DMLOE is set, this field represents a sign-extended offset applied to the
 *    source or destination address to form the next-state value after the minor loop completes.
 */
#define DMA_NBYTES_MLOFFYES_MLOFF_SET(x)         (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           (0x40000000U)
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          (30U)
/*! DMLOE - Destination Minor Loop Offset enable
 *  0b0..The minor loop offset is not applied to the DADDR
 *  0b1..The minor loop offset is applied to the DADDR
 */
#define DMA_NBYTES_MLOFFYES_DMLOE_SET(x)         (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           (0x80000000U)
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the SADDR
 *  0b1..The minor loop offset is applied to the SADDR
 */
#define DMA_NBYTES_MLOFFYES_SMLOE_SET(x)         (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA_NBYTES_MLOFFYES */
#define DMA_NBYTES_MLOFFYES_COUNT                (32U)

/*! @name SLAST - TCD Last Source Address Adjustment */
/*! @{ */

#define DMA_SLAST_SLAST_MASK                     (0xFFFFFFFFU)
#define DMA_SLAST_SLAST_SHIFT                    (0U)
/*! SLAST - Last Source Address Adjustment
 */
#define DMA_SLAST_SLAST_SET(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_SLAST_SLAST_SHIFT)) & DMA_SLAST_SLAST_MASK)
/*! @} */

/* The count of DMA_SLAST */
#define DMA_SLAST_COUNT                          (32U)

/*! @name DADDR - TCD Destination Address */
/*! @{ */

#define DMA_DADDR_DADDR_MASK                     (0xFFFFFFFFU)
#define DMA_DADDR_DADDR_SHIFT                    (0U)
/*! DADDR - Destination Address
 */
#define DMA_DADDR_DADDR_SET(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_DADDR_DADDR_SHIFT)) & DMA_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA_DADDR */
#define DMA_DADDR_COUNT                          (32U)

/*! @name DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_DOFF_DOFF_MASK                       (0xFFFFU)
#define DMA_DOFF_DOFF_SHIFT                      (0U)
/*! DOFF - Destination Address Signed Offset
 */
#define DMA_DOFF_DOFF_SET(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_DOFF_DOFF_SHIFT)) & DMA_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA_DOFF */
#define DMA_DOFF_COUNT                           (32U)

/*! @name CITER_ELINKNO - TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
/*! @{ */

#define DMA_CITER_ELINKNO_CITER_MASK             (0x7FFFU)
#define DMA_CITER_ELINKNO_CITER_SHIFT            (0U)
/*! CITER - Current Major Iteration Count
 */
#define DMA_CITER_ELINKNO_CITER_SET(x)           (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKNO_CITER_SHIFT)) & DMA_CITER_ELINKNO_CITER_MASK)

#define DMA_CITER_ELINKNO_ELINK_MASK             (0x8000U)
#define DMA_CITER_ELINKNO_ELINK_SHIFT            (15U)
/*! ELINK - Enable channel-to-channel linking on minor-loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA_CITER_ELINKNO_ELINK_SET(x)           (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKNO_ELINK_SHIFT)) & DMA_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_CITER_ELINKNO */
#define DMA_CITER_ELINKNO_COUNT                  (32U)

/*! @name CITER_ELINKYES - TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
/*! @{ */

#define DMA_CITER_ELINKYES_CITER_MASK            (0x1FFU)
#define DMA_CITER_ELINKYES_CITER_SHIFT           (0U)
/*! CITER - Current Major Iteration Count
 */
#define DMA_CITER_ELINKYES_CITER_SET(x)          (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKYES_CITER_SHIFT)) & DMA_CITER_ELINKYES_CITER_MASK)

#define DMA_CITER_ELINKYES_LINKCH_MASK           (0x3E00U)
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          (9U)
/*! LINKCH - Minor Loop Link Channel Number
 */
#define DMA_CITER_ELINKYES_LINKCH_SET(x)         (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_CITER_ELINKYES_LINKCH_MASK)

#define DMA_CITER_ELINKYES_ELINK_MASK            (0x8000U)
#define DMA_CITER_ELINKYES_ELINK_SHIFT           (15U)
/*! ELINK - Enable channel-to-channel linking on minor-loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA_CITER_ELINKYES_ELINK_SET(x)          (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKYES_ELINK_SHIFT)) & DMA_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_CITER_ELINKYES */
#define DMA_CITER_ELINKYES_COUNT                 (32U)

/*! @name DLAST_SGA - TCD Last Destination Address Adjustment/Scatter Gather Address */
/*! @{ */

#define DMA_DLAST_SGA_DLASTSGA_MASK              (0xFFFFFFFFU)
#define DMA_DLAST_SGA_DLASTSGA_SHIFT             (0U)
#define DMA_DLAST_SGA_DLASTSGA_SET(x)            (((uint32_t)(((uint32_t)(x)) << DMA_DLAST_SGA_DLASTSGA_SHIFT)) & DMA_DLAST_SGA_DLASTSGA_MASK)
/*! @} */

/* The count of DMA_DLAST_SGA */
#define DMA_DLAST_SGA_COUNT                      (32U)

/*! @name CSR - TCD Control and Status */
/*! @{ */

#define DMA_CSR_START_MASK                       (0x1U)
#define DMA_CSR_START_SHIFT                      (0U)
/*! START - Channel Start
 *  0b0..The channel is not explicitly started.
 *  0b1..The channel is explicitly started via a software initiated service request.
 */
#define DMA_CSR_START_SET(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_CSR_START_SHIFT)) & DMA_CSR_START_MASK)

#define DMA_CSR_INTMAJOR_MASK                    (0x2U)
#define DMA_CSR_INTMAJOR_SHIFT                   (1U)
/*! INTMAJOR - Enable an interrupt when major iteration count completes.
 *  0b0..The end-of-major loop interrupt is disabled.
 *  0b1..The end-of-major loop interrupt is enabled.
 */
#define DMA_CSR_INTMAJOR_SET(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_CSR_INTMAJOR_SHIFT)) & DMA_CSR_INTMAJOR_MASK)

#define DMA_CSR_INTHALF_MASK                     (0x4U)
#define DMA_CSR_INTHALF_SHIFT                    (2U)
/*! INTHALF - Enable an interrupt when major counter is half complete.
 *  0b0..The half-point interrupt is disabled.
 *  0b1..The half-point interrupt is enabled.
 */
#define DMA_CSR_INTHALF_SET(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_CSR_INTHALF_SHIFT)) & DMA_CSR_INTHALF_MASK)

#define DMA_CSR_DREQ_MASK                        (0x8U)
#define DMA_CSR_DREQ_SHIFT                       (3U)
/*! DREQ - Disable Request
 *  0b0..The channel's ERQ bit is not affected.
 *  0b1..The channel's ERQ bit is cleared when the major loop is complete.
 */
#define DMA_CSR_DREQ_SET(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_CSR_DREQ_SHIFT)) & DMA_CSR_DREQ_MASK)

#define DMA_CSR_ESG_MASK                         (0x10U)
#define DMA_CSR_ESG_SHIFT                        (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..The current channel's TCD is normal format.
 *  0b1..The current channel's TCD specifies a scatter gather format. The DLASTSGA field provides a memory pointer
 *       to the next TCD to be loaded into this channel after the major loop completes its execution.
 */
#define DMA_CSR_ESG_SET(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_CSR_ESG_SHIFT)) & DMA_CSR_ESG_MASK)

#define DMA_CSR_MAJORELINK_MASK                  (0x20U)
#define DMA_CSR_MAJORELINK_SHIFT                 (5U)
/*! MAJORELINK - Enable channel-to-channel linking on major loop complete
 *  0b0..The channel-to-channel linking is disabled.
 *  0b1..The channel-to-channel linking is enabled.
 */
#define DMA_CSR_MAJORELINK_SET(x)                (((uint16_t)(((uint16_t)(x)) << DMA_CSR_MAJORELINK_SHIFT)) & DMA_CSR_MAJORELINK_MASK)

#define DMA_CSR_ACTIVE_MASK                      (0x40U)
#define DMA_CSR_ACTIVE_SHIFT                     (6U)
/*! ACTIVE - Channel Active
 */
#define DMA_CSR_ACTIVE_SET(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_CSR_ACTIVE_SHIFT)) & DMA_CSR_ACTIVE_MASK)

#define DMA_CSR_DONE_MASK                        (0x80U)
#define DMA_CSR_DONE_SHIFT                       (7U)
/*! DONE - Channel Done
 */
#define DMA_CSR_DONE_SET(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_CSR_DONE_SHIFT)) & DMA_CSR_DONE_MASK)

#define DMA_CSR_MAJORLINKCH_MASK                 (0x1F00U)
#define DMA_CSR_MAJORLINKCH_SHIFT                (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number
 */
#define DMA_CSR_MAJORLINKCH_SET(x)               (((uint16_t)(((uint16_t)(x)) << DMA_CSR_MAJORLINKCH_SHIFT)) & DMA_CSR_MAJORLINKCH_MASK)

#define DMA_CSR_BWC_MASK                         (0xC000U)
#define DMA_CSR_BWC_SHIFT                        (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Reserved
 *  0b10..eDMA engine stalls for 4 cycles after each R/W.
 *  0b11..eDMA engine stalls for 8 cycles after each R/W.
 */
#define DMA_CSR_BWC_SET(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_CSR_BWC_SHIFT)) & DMA_CSR_BWC_MASK)
/*! @} */

/* The count of DMA_CSR */
#define DMA_CSR_COUNT                            (32U)

/*! @name BITER_ELINKNO - TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
/*! @{ */

#define DMA_BITER_ELINKNO_BITER_MASK             (0x7FFFU)
#define DMA_BITER_ELINKNO_BITER_SHIFT            (0U)
/*! BITER - Starting Major Iteration Count
 */
#define DMA_BITER_ELINKNO_BITER_SET(x)           (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKNO_BITER_SHIFT)) & DMA_BITER_ELINKNO_BITER_MASK)

#define DMA_BITER_ELINKNO_ELINK_MASK             (0x8000U)
#define DMA_BITER_ELINKNO_ELINK_SHIFT            (15U)
/*! ELINK - Enables channel-to-channel linking on minor loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA_BITER_ELINKNO_ELINK_SET(x)           (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKNO_ELINK_SHIFT)) & DMA_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_BITER_ELINKNO */
#define DMA_BITER_ELINKNO_COUNT                  (32U)

/*! @name BITER_ELINKYES - TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
/*! @{ */

#define DMA_BITER_ELINKYES_BITER_MASK            (0x1FFU)
#define DMA_BITER_ELINKYES_BITER_SHIFT           (0U)
/*! BITER - Starting major iteration count
 */
#define DMA_BITER_ELINKYES_BITER_SET(x)          (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKYES_BITER_SHIFT)) & DMA_BITER_ELINKYES_BITER_MASK)

#define DMA_BITER_ELINKYES_LINKCH_MASK           (0x3E00U)
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          (9U)
/*! LINKCH - Link Channel Number
 */
#define DMA_BITER_ELINKYES_LINKCH_SET(x)         (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_BITER_ELINKYES_LINKCH_MASK)

#define DMA_BITER_ELINKYES_ELINK_MASK            (0x8000U)
#define DMA_BITER_ELINKYES_ELINK_SHIFT           (15U)
/*! ELINK - Enables channel-to-channel linking on minor loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA_BITER_ELINKYES_ELINK_SET(x)          (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKYES_ELINK_SHIFT)) & DMA_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_BITER_ELINKYES */
#define DMA_BITER_ELINKYES_COUNT                 (32U)


/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/** Peripheral DMA base address */
#define DMA_BASE                                 (0x40008000u)
/** Peripheral DMA base pointer */
#define DMA                                     ((DMA_Type *)DMA_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_CHN_IRQS                             { DMA0_IRQn, DMA1_IRQn, DMA2_IRQn, DMA3_IRQn, DMA4_IRQn, DMA5_IRQn, DMA6_IRQn, DMA7_IRQn, DMA8_IRQn, DMA9_IRQn, DMA10_IRQn, DMA11_IRQn, DMA12_IRQn, DMA13_IRQn, DMA14_IRQn, DMA15_IRQn }
#define DMA_ERROR_IRQS                           { DMA_Error_IRQn }

/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint8_t CHCFG[16];                          /**< Channel Configuration register, array offset: 0x0, array step: 0x1 */
} DMAMUX_Type;

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/*! @name CHCFG - Channel Configuration register */
/*! @{ */

#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)
/*! SOURCE - DMA Channel Source (Slot)
 *  0b000000..Disable_Signal
 *  0b000001..UART1_OR_UART4_RX_Signal
 *  0b000010..UART1_OR_UART4_TX_Signal
 *  0b000011..UART2_OR_UART5_RX_Signal
 *  0b000100..UART2_OR_UART5_TX_Signal
 *  0b000101..UART3_OR_UART6_RX_Signal
 *  0b000110..UART3_OR_UART6_TX_Signal
 *  0b000111..
 *  0b001000..
 *  0b001001..
 *  0b001010..
 *  0b001100..
 *  0b001101..
 *  0b001110..
 *  0b001111..
 *  0b010000..
 *  0b010001..
 *  0b010010..
 *  0b010011..
 *  0b010100..
 *  0b010101..
 *  0b010110..
 *  0b010111..
 *  0b011000..
 *  0b011001..
 *  0b011010..
 *  0b011011..
 *  0b011100..
 *  0b011101..
 *  0b011110..
 *  0b011111..
 *  0b100000..
 *  0b100001..
 *  0b100010..
 *  0b100011..
 *  0b100100..
 *  0b100101..
 *  0b100110..
 *  0b100111..
 *  0b101000..
 *  0b101001..
 *  0b101010..
 *  0b101011..
 *  0b101100..
 *  0b101101..
 *  0b101110..
 *  0b101111..
 *  0b110000..
 *  0b110001..
 *  0b110010..
 *  0b110011..
 *  0b110100..
 *  0b110101..
 *  0b110110..
 *  0b110111..
 *  0b111000..
 *  0b111001..
 *  0b111010..
 *  0b111011..
 *  0b111100..
 *  0b111101..
 *  0b111110..AlwaysOn62_Signal
 *  0b111111..AlwaysOn63_Signal
 */
#define DMAMUX_CHCFG_SOURCE_SET(x)               (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_SOURCE_SHIFT)) & DMAMUX_CHCFG_SOURCE_MASK)

#define DMAMUX_CHCFG_TRIG_MASK                   (0x40U)
#define DMAMUX_CHCFG_TRIG_SHIFT                  (6U)
/*! TRIG - DMA Channel Trigger Enable
 *  0b0..Triggering is disabled. If triggering is disabled and ENBL is set, the DMA Channel will simply route the
 *       specified source to the DMA channel. (Normal mode)
 *  0b1..Triggering is enabled. If triggering is enabled and ENBL is set, the DMAMUX is in Periodic Trigger mode.
 */
#define DMAMUX_CHCFG_TRIG_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_TRIG_SHIFT)) & DMAMUX_CHCFG_TRIG_MASK)

#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)
/*! ENBL - DMA Channel Enable
 *  0b0..DMA channel is disabled. This mode is primarily used during configuration of the DMAMux. The DMA has
 *       separate channel enables/disables, which should be used to disable or reconfigure a DMA channel.
 *  0b1..DMA channel is enabled
 */
#define DMAMUX_CHCFG_ENBL_SET(x)                 (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_ENBL_SHIFT)) & DMAMUX_CHCFG_ENBL_MASK)
/*! @} */

/* The count of DMAMUX_CHCFG */
#define DMAMUX_CHCFG_COUNT                       (32U)


/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX base address */
#define DMAMUX_BASE                              (0x40021000u)
/** Peripheral DMAMUX base pointer */
#define DMAMUX                                   ((DMAMUX_Type *)DMAMUX_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMAMUX_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX }

/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- ECAP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ECAP_Peripheral_Access_Layer ECAP Peripheral Access Layer
 * @{
 */

/** ECAP - Register Layout Typedef */
typedef struct {
  __IO uint32_t TSCTR;                               /**< Time-Stamp Counter */
  __IO uint32_t RESERVED_0;                           
  __IO uint32_t CTRPHS;                              /**< Counter Phase Offset Value Register */
  __IO uint32_t RESERVED_1;                           
  __IO uint32_t CAP1;                                /**< Capture 1 Register */
  __IO uint32_t RESERVED_2;                           
  __IO uint32_t CAP2;                                /**< Capture 2 Register */
  __IO uint32_t RESERVED_3;                           
  __IO uint32_t CAP3;                                /**< Capture 3 Register */
  __IO uint32_t RESERVED_4;                           
  __IO uint32_t CAP4;                                /**< Capture 4 Register */
  __IO uint32_t RESERVED_5[7];                           
  __IO uint32_t ECCTL0;                              /**< Capture Control Register 0 */
  __IO uint32_t RESERVED_6;                           
  __IO uint32_t ECCTL1;                              /**< Capture Control Register 1 */
  __IO uint32_t ECCTL2;                              /**< Capture Control Register 2 */
  __IO uint32_t ECEINT;                              /**< Capture Interrupt Enable Register */
  __IO uint32_t ECFLG;                               /**< Capture Interrupt Flag Register */
  __IO uint32_t ECCLR;                               /**< Capture Interrupt Clear Register */
  __IO uint32_t ECFRC;                               /**< Capture Interrupt Force Register */
  __IO uint32_t RESERVED_7[4];                           
  __IO uint32_t SYNCINSEL;                           /**< SYNC source select register */
} ECAP_Type;

/* ----------------------------------------------------------------------------
   -- ECAP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ECAP_Register_Masks ECAP Register Masks
 * @{
 */

/*! @name ECCTL0- Capture Control Register 0 */
/*! @{ */
#define ECAP_ECCTL0_INPUTSEL_MASK               (0x7FU)
#define ECAP_ECCTL0_INPUTSEL_SHIFT              (0)
#define ECAP_ECCTL0_INPUTSEL_SET(x)             (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL0_INPUTSEL_SHIFT)) & ECAP_ECCTL0_INPUTSEL_MASK)

/*! @name ECCTL1- Capture Control Register 1 */
/*! @{ */
#define ECAP_ECCTL1_CAP1POL_MASK                (1)
#define ECAP_ECCTL1_CAP1POL_SHIFT               (0)
#define ECAP_ECCTL1_CAP1POL_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CAP1POL_SHIFT)) & ECAP_ECCTL1_CAP1POL_MASK)
#define ECAP_ECCTL1_CTRRST1_MASK                (2)
#define ECAP_ECCTL1_CTRRST1_SHIFT               (1)
#define ECAP_ECCTL1_CTRRST1_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CTRRST1_SHIFT)) & ECAP_ECCTL1_CTRRST1_MASK)
#define ECAP_ECCTL1_CAP2POL_MASK                (4)
#define ECAP_ECCTL1_CAP2POL_SHIFT               (2)
#define ECAP_ECCTL1_CAP2POL_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CAP2POL_SHIFT)) & ECAP_ECCTL1_CAP2POL_MASK)
#define ECAP_ECCTL1_CTRRST2_MASK                (8)
#define ECAP_ECCTL1_CTRRST2_SHIFT               (3)
#define ECAP_ECCTL1_CTRRST2_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CTRRST2_SHIFT)) & ECAP_ECCTL1_CTRRST2_MASK)
#define ECAP_ECCTL1_CAP3POL_MASK                (16)
#define ECAP_ECCTL1_CAP3POL_SHIFT               (4)
#define ECAP_ECCTL1_CAP3POL_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CAP3POL_SHIFT)) & ECAP_ECCTL1_CAP3POL_MASK)
#define ECAP_ECCTL1_CTRRST3_MASK                (32)
#define ECAP_ECCTL1_CTRRST3_SHIFT               (5)
#define ECAP_ECCTL1_CTRRST3_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CTRRST3_SHIFT)) & ECAP_ECCTL1_CTRRST3_MASK)
#define ECAP_ECCTL1_CAP4POL_MASK                (64)
#define ECAP_ECCTL1_CAP4POL_SHIFT               (6)
#define ECAP_ECCTL1_CAP4POL_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CAP4POL_SHIFT)) & ECAP_ECCTL1_CAP4POL_MASK)
#define ECAP_ECCTL1_CTRRST4_MASK                (128)
#define ECAP_ECCTL1_CTRRST4_SHIFT               (7)
#define ECAP_ECCTL1_CTRRST4_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CTRRST4_SHIFT)) & ECAP_ECCTL1_CTRRST4_MASK)
#define ECAP_ECCTL1_CAPLDEN_MASK                (256)
#define ECAP_ECCTL1_CAPLDEN_SHIFT               (8)
#define ECAP_ECCTL1_CAPLDEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_CAPLDEN_SHIFT)) & ECAP_ECCTL1_CAPLDEN_MASK)
#define ECAP_ECCTL1_PRESCALE_MASK               (0x3E00U)
#define ECAP_ECCTL1_PRESCALE_SHIFT              (9)
#define ECAP_ECCTL1_PRESCALE_SET(x)             (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_PRESCALE_SHIFT)) & ECAP_ECCTL1_PRESCALE_MASK)
#define ECAP_ECCTL1_FREE_SOFT_MASK              (0xC000U)
#define ECAP_ECCTL1_FREE_SOFT_SHIFT             (14)
#define ECAP_ECCTL1_FREE_SOFT_SET(x)            (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL1_FREE_SOFT_SHIFT)) & ECAP_ECCTL1_FREE_SOFT_MASK)

/*! @name ECCTL2- Capture Control Register 2 */
/*! @{ */
#define ECAP_ECCTL2_CONT_ONESHT_MASK            (1)
#define ECAP_ECCTL2_CONT_ONESHT_SHIFT           (0)
#define ECAP_ECCTL2_CONT_ONESHT_SET(x)          (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_CONT_ONESHT_SHIFT)) & ECAP_ECCTL2_CONT_ONESHT_MASK)
#define ECAP_ECCTL2_STOP_WRAP_MASK              (6)
#define ECAP_ECCTL2_STOP_WRAP_SHIFT             (1)
#define ECAP_ECCTL2_STOP_WRAP_SET(x)            (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_STOP_WRAP_SHIFT)) & ECAP_ECCTL2_STOP_WRAP_MASK)
#define ECAP_ECCTL2_REARM_MASK                  (8)
#define ECAP_ECCTL2_REARM_SHIFT                 (3)
#define ECAP_ECCTL2_REARM_SET(x)                (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_REARM_SHIFT)) & ECAP_ECCTL2_REARM_MASK)
#define ECAP_ECCTL2_TSCTRSTOP_MASK              (16)
#define ECAP_ECCTL2_TSCTRSTOP_SHIFT             (4)
#define ECAP_ECCTL2_TSCTRSTOP_SET(x)            (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_TSCTRSTOP_SHIFT)) & ECAP_ECCTL2_TSCTRSTOP_MASK)
#define ECAP_ECCTL2_SYNCI_EN_MASK               (32)
#define ECAP_ECCTL2_SYNCI_EN_SHIFT              (5)
#define ECAP_ECCTL2_SYNCI_EN_SET(x)             (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_SYNCI_EN_SHIFT)) & ECAP_ECCTL2_SYNCI_EN_MASK)
#define ECAP_ECCTL2_SYNCO_SEL_MASK              (0xC0)
#define ECAP_ECCTL2_SYNCO_SEL_SHIFT             (6)
#define ECAP_ECCTL2_SYNCO_SEL_SET(x)            (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_SYNCO_SEL_SHIFT)) & ECAP_ECCTL2_SYNCO_SEL_MASK)
#define ECAP_ECCTL2_SWSYNC_MASK                 (0x100)
#define ECAP_ECCTL2_SWSYNC_SHIFT                (8)
#define ECAP_ECCTL2_SWSYNC_SET(x)               (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_SWSYNC_SHIFT)) & ECAP_ECCTL2_SWSYNC_MASK)
#define ECAP_ECCTL2_CAP_APWM_MASK               (0x200)
#define ECAP_ECCTL2_CAP_APWM_SHIFT              (9)
#define ECAP_ECCTL2_CAP_APWM_SET(x)             (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_CAP_APWM_SHIFT)) & ECAP_ECCTL2_CAP_APWM_MASK)
#define ECAP_ECCTL2_APWMPOL_MASK                (0x400)
#define ECAP_ECCTL2_APWMPOL_SHIFT               (10)
#define ECAP_ECCTL2_APWMPOL_SET(x)              (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_APWMPOL_SHIFT)) & ECAP_ECCTL2_APWMPOL_MASK)
#define ECAP_ECCTL2_CTRFILTRESET_MASK           (0x800)
#define ECAP_ECCTL2_CTRFILTRESET_SHIFT          (11)
#define ECAP_ECCTL2_CTRFILTRESET_SET(x)         (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_CTRFILTRESET_SHIFT)) & ECAP_ECCTL2_CTRFILTRESET_MASK)
#define ECAP_ECCTL2_DMAEVTSEL_MASK              (0x3000)
#define ECAP_ECCTL2_DMAEVTSEL_SHIFT             (12)
#define ECAP_ECCTL2_DMAEVTSEL_SET(x)            (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_DMAEVTSEL_SHIFT)) & ECAP_ECCTL2_DMAEVTSEL_MASK)
#define ECAP_ECCTL2_MODCNTRSTS_MASK             (0xC000)
#define ECAP_ECCTL2_MODCNTRSTS_SHIFT            (14)
#define ECAP_ECCTL2_MODCNTRSTS_SET(x)           (((uint32_t)(((uint32_t)(x)) << ECAP_ECCTL2_MODCNTRSTS_SHIFT)) & ECAP_ECCTL2_MODCNTRSTS_MASK)

/*! @name ECEINT- Capture Interrupt Enable Register */
/*! @{ */
#define ECAP_ECEINT_CEVT1_MASK                  (2)
#define ECAP_ECEINT_CEVT1_SHIFT                 (1)
#define ECAP_ECEINT_CEVT1_SET(x)                (((uint32_t)(((uint32_t)(x)) << ECAP_ECEINT_CEVT1_SHIFT)) & ECAP_ECEINT_CEVT1_MASK)
#define ECAP_ECEINT_CEVT2_MASK                  (4)
#define ECAP_ECEINT_CEVT2_SHIFT                 (2)
#define ECAP_ECEINT_CEVT2_SET(x)                (((uint32_t)(((uint32_t)(x)) << ECAP_ECEINT_CEVT2_SHIFT)) & ECAP_ECEINT_CEVT2_MASK)
#define ECAP_ECEINT_CEVT3_MASK                  (8)
#define ECAP_ECEINT_CEVT3_SHIFT                 (3)
#define ECAP_ECEINT_CEVT3_SET(x)                (((uint32_t)(((uint32_t)(x)) << ECAP_ECEINT_CEVT3_SHIFT)) & ECAP_ECEINT_CEVT3_MASK)
#define ECAP_ECEINT_CEVT4_MASK                  (16)
#define ECAP_ECEINT_CEVT4_SHIFT                 (4)
#define ECAP_ECEINT_CEVT4_SET(x)                (((uint32_t)(((uint32_t)(x)) << ECAP_ECEINT_CEVT4_SHIFT)) & ECAP_ECEINT_CEVT4_MASK)
#define ECAP_ECEINT_CTROVF_MASK                 (32)
#define ECAP_ECEINT_CTROVF_SHIFT                (5)
#define ECAP_ECEINT_CTROVF_SET(x)               (((uint32_t)(((uint32_t)(x)) << ECAP_ECEINT_CTROVF_SHIFT)) & ECAP_ECEINT_CTROVF_MASK)
#define ECAP_ECEINT_CTR_EQ_PRD_MASK             (64)
#define ECAP_ECEINT_CTR_EQ_PRD_SHIFT            (6)
#define ECAP_ECEINT_CTR_EQ_PRD_SET(x)           (((uint32_t)(((uint32_t)(x)) << ECAP_ECEINT_CTR_EQ_PRD_SHIFT)) & ECAP_ECEINT_CTR_EQ_PRD_MASK)
#define ECAP_ECEINT_CTR_EQ_CMP_MASK             (128)
#define ECAP_ECEINT_CTR_EQ_CMP_SHIFT            (7)
#define ECAP_ECEINT_CTR_EQ_CMP_SET(x)           (((uint32_t)(((uint32_t)(x)) << ECAP_ECEINT_CTR_EQ_CMP_SHIFT)) & ECAP_ECEINT_CTR_EQ_CMP_MASK)


/*! @name ECCLR- Capture Interrupt Clear Register */
/*! @{ */
#define ECAP_ECCLR_INT_MASK                     (1)
#define ECAP_ECCLR_INT_SHIFT                    (0)
#define ECAP_ECCLR_INT_SET(x)                   (((uint32_t)(((uint32_t)(x)) << ECAP_ECCLR_INT_SHIFT)) & ECAP_ECCLR_INT_MASK)
#define ECAP_ECCLR_CEVT1_MASK                   (2)
#define ECAP_ECCLR_CEVT1_SHIFT                  (1)
#define ECAP_ECCLR_CEVT1_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ECAP_ECCLR_CEVT1_SHIFT)) & ECAP_ECCLR_CEVT1_MASK)
#define ECAP_ECCLR_CEVT2_MASK                   (4)
#define ECAP_ECCLR_CEVT2_SHIFT                  (2)
#define ECAP_ECCLR_CEVT2_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ECAP_ECCLR_CEVT2_SHIFT)) & ECAP_ECCLR_CEVT2_MASK)
#define ECAP_ECCLR_CEVT3_MASK                   (8)
#define ECAP_ECCLR_CEVT3_SHIFT                  (3)
#define ECAP_ECCLR_CEVT3_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ECAP_ECCLR_CEVT3_SHIFT)) & ECAP_ECCLR_CEVT3_MASK)
#define ECAP_ECCLR_CEVT4_MASK                   (16)
#define ECAP_ECCLR_CEVT4_SHIFT                  (4)
#define ECAP_ECCLR_CEVT4_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ECAP_ECCLR_CEVT4_SHIFT)) & ECAP_ECCLR_CEVT4_MASK)
#define ECAP_ECCLR_CTROVF_MASK                  (32)
#define ECAP_ECCLR_CTROVF_SHIFT                 (5)
#define ECAP_ECCLR_CTROVF_SET(x)                (((uint32_t)(((uint32_t)(x)) << ECAP_ECCLR_CTROVF_SHIFT)) & ECAP_ECCLR_CTROVF_MASK)
#define ECAP_ECCLR_CTR_PRD_MASK                 (64)
#define ECAP_ECCLR_CTR_PRD_SHIFT                (6)
#define ECAP_ECCLR_CTR_PRD_SET(x)               (((uint32_t)(((uint32_t)(x)) << ECAP_ECCLR_CTR_PRD_SHIFT)) & ECAP_ECCLR_CTR_PRD_MASK)
#define ECAP_ECCLR_CTR_CMP_MASK                 (128)
#define ECAP_ECCLR_CTR_CMP_SHIFT                (7)
#define ECAP_ECCLR_CTR_CMP_SET(x)               (((uint32_t)(((uint32_t)(x)) << ECAP_ECCLR_CTR_CMP_SHIFT)) & ECAP_ECCLR_CTR_CMP_MASK)

/*! @name ECFRC- Capture Interrupt Force Register */
/*! @{ */
#define ECAP_ECFRC_CEVT1_MASK                   (2)
#define ECAP_ECFRC_CEVT1_SHIFT                  (1)
#define ECAP_ECFRC_CEVT1_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ECAP_ECFRC_CEVT1_SHIFT)) & ECAP_ECFRC_CEVT1_MASK)
#define ECAP_ECFRC_CEVT2_MASK                   (4)
#define ECAP_ECFRC_CEVT2_SHIFT                  (2)
#define ECAP_ECFRC_CEVT2_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ECAP_ECFRC_CEVT2_SHIFT)) & ECAP_ECFRC_CEVT2_MASK)
#define ECAP_ECFRC_CEVT3_MASK                   (8)
#define ECAP_ECFRC_CEVT3_SHIFT                  (3)
#define ECAP_ECFRC_CEVT3_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ECAP_ECFRC_CEVT3_SHIFT)) & ECAP_ECFRC_CEVT3_MASK)
#define ECAP_ECFRC_CEVT4_MASK                   (16)
#define ECAP_ECFRC_CEVT4_SHIFT                  (4)
#define ECAP_ECFRC_CEVT4_SET(x)                 (((uint32_t)(((uint32_t)(x)) << ECAP_ECFRC_CEVT4_SHIFT)) & ECAP_ECFRC_CEVT4_MASK)
#define ECAP_ECFRC_CTROVF_MASK                  (32)
#define ECAP_ECFRC_CTROVF_SHIFT                 (5)
#define ECAP_ECFRC_CTROVF_SET(x)                (((uint32_t)(((uint32_t)(x)) << ECAP_ECFRC_CTROVF_SHIFT)) & ECAP_ECFRC_CTROVF_MASK)
#define ECAP_ECFRC_CTR_PRD_MASK                 (64)
#define ECAP_ECFRC_CTR_PRD_SHIFT                (6)
#define ECAP_ECFRC_CTR_PRD_SET(x)               (((uint32_t)(((uint32_t)(x)) << ECAP_ECFRC_CTR_PRD_SHIFT)) & ECAP_ECFRC_CTR_PRD_MASK)
#define ECAP_ECFRC_CTR_CMP_MASK                 (128)
#define ECAP_ECFRC_CTR_CMP_SHIFT                (7)
#define ECAP_ECFRC_CTR_CMP_SET(x)               (((uint32_t)(((uint32_t)(x)) << ECAP_ECFRC_CTR_CMP_SHIFT)) & ECAP_ECFRC_CTR_CMP_MASK)

/*! @name ECAPSYNCINSEL- SYNC Source Select Register */
/*! @{ */
#define ECAP_SYNCINSEL_SEL_MASK                 (31)
#define ECAP_SYNCINSEL_SEL_SHIFT                (0)
#define ECAP_SYNCINSEL_SEL_SET(x)               (((uint32_t)(((uint32_t)(x)) << ECAP_SYNCINSEL_SEL_SHIFT)) & ECAP_SYNCINSEL_SEL_MASK)

/*!
 * @}
 */ /* end of group ECAP_Register_Masks */

/* ECAP - Peripheral instance base addresses */
/** Peripheral ECAP1 base address */
#define ECAP1_BASE                                (0x40058000u)
/** Peripheral ECAP1 base pointer */
#define ECAP1                                     ((ECAP_Type *)ECAP1_BASE)
/** Peripheral ECAP2 base address */
#define ECAP2_BASE                                (0x40059000u)
/** Peripheral ECAP2 base pointer */
#define ECAP2                                     ((ECAP_Type *)ECAP2_BASE)
/** Peripheral ECAP3 base address */
#define ECAP3_BASE                                (0x400C9000u)
/** Peripheral ECAP3 base pointer */
#define ECAP3                                     ((ECAP_Type *)ECAP3_BASE)

/*!
 * @}
 */ /* end of group ECAP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- EPWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EPWM_Peripheral_Access_Layer EPWM Peripheral Access Layer
 * @{
 */

/** EPWM - Register Layout Typedef */
typedef struct {
  __IO uint32_t TBCTL;                               /**< Time Base Control Register */
  __IO uint32_t TBCTL2;                              /**< Time Base Control Register 2 */
  __IO uint32_t RESERVED_0;
  __IO uint32_t SYNCINSEL;                           /**< EPWMxSYNCIN Source Select Register */
  __IO uint32_t TBCTR;                               /**< Time Base Counter Register */
  __IO uint32_t TBSTS;                               /**< Time Base Status Register */
  __IO uint32_t SYNCOUTEN;                           /**< EPWMxSYNCIN Source Enable Register */
  __IO uint32_t TBCTL3;                              /**< Time Base Control Register 3 */
  __IO uint32_t CMPCTL;                              /**< Counter Compare Control Register*/
  __IO uint32_t CMPCTL2;                             /**< Counter Compare Control Register 2 */
  __IO uint32_t RESERVED_1[2];
  __IO uint32_t DBCTL;                               /**< Dead-Band Generator Control Register */
  __IO uint32_t DBCTL2;                              /**< Dead-Band Generator Control Register 2 */
  __IO uint32_t RESERVED_2[2];
  __IO uint32_t AQCTL;                               /**< Action Qualifier Control Register */
  __IO uint32_t AQTSRCSEL;                           /**< Action Qualifier Trigger Event Source Select Register */
  __IO uint32_t RESERVED_3[2];
  __IO uint32_t PCCTL;                               /**< PWM Chopper Control Register */
  __IO uint32_t RESERVED_4[3];
  __IO uint32_t VCAPCTL;                             /**< Valley Capture Control Register */
  __IO uint32_t VCNTCFG;                             /**< Valley Counter Config Register */
  __IO uint32_t RESERVED_5[6];
  __IO uint32_t HRCNFG;                              /**< HRPWM Configuration Register */
  __IO uint32_t HRPWR;                               /**< HRPWM Power Register */
  __IO uint32_t RESERVED_6[4];
  __IO uint32_t HRMSTEP;                             /**< HRPWM MEP Step Register */
  __IO uint32_t HRCNFG2;                             /**< HRPWM Configuration Register 2 */
  __IO uint32_t RESERVED_7[5];
  __IO uint32_t HRPCTL;                              /**< High Resolution Period Control Register */
  __IO uint32_t TRREM;                               /**< HRPWM High Resolution Remainder Register */
  __IO uint32_t RESERVED_8[5];
  __IO uint32_t GLDCTL;                              /**< Global PWM Load Control Register */
  __IO uint32_t GLDCFG;                              /**< Global PWM Load Config Register */
  __IO uint32_t RESERVED_9[2];
  __IO uint32_t XLINK;                               /**< EPWMx Link Register */
  __IO uint32_t RESERVED_10[7];
  __IO uint32_t AQCTLA;                              /**< Action Qualifier Control Register For Output A */
  __IO uint32_t AQCTLA2;                             /**< Additional Action Qualifier Control Register For Output A */
  __IO uint32_t AQCTLB;                              /**< Action Qualifier Control Register For Output B */
  __IO uint32_t AQCTLB2;                             /**< Additional Action Qualifier Control Register For Output B */
  __IO uint32_t RESERVED_11[3];
  __IO uint32_t AQSFRC;                              /**< Action Qualifier Software Force Register */
  __IO uint32_t RESERVED_12;
  __IO uint32_t AQCSFRC;                             /**< Action Qualifier Continuous S/W Force Register */
  __IO uint32_t RESERVED_13[6];
  __IO uint32_t DBREDHR;                             /**< Dead-Band Generator Rising Edge Delay High Resolution Mirror Register */
  __IO uint32_t DBRED;                               /**< Dead-Band Generator Rising Edge Delay High Resolution Mirror Register */
  __IO uint32_t DBFEDHR;                             /**< Dead-Band Generator Falling Edge Delay High Resolution Mirror Register */
  __IO uint32_t DBFED;                               /**< Dead-Band Generator Falling Edge Delay Count Register */
  __IO uint32_t RESERVED_14[12];
  __IO uint32_t TBPHS;                               /**< Time Base Phase High */
  __IO uint32_t RESERVED_15;
  __IO uint32_t TBPRDHR;                             /**< Time Base Period High Resolution Register */
  __IO uint32_t TBPRD;                               /**< Time Base Period Register */
  __IO uint32_t RESERVED_16[6];
  __IO uint32_t CMPA;                                /**< Counter Compare A Register */
  __IO uint32_t RESERVED_17;
  __IO uint32_t CMPB;                                /**< Compare B Register */
  __IO uint32_t RESERVED_18[2];
  __IO uint32_t CMPC;                                /**< Counter Compare C Register */
  __IO uint32_t RESERVED_19;
  __IO uint32_t CMPD;                                /**< Counter Compare D Register */
  __IO uint32_t RESERVED_20[2];
  __IO uint32_t GLDCTL2;                             /**< Global PWM Load Control Register */
  __IO uint32_t RESERVED_21[2];
  __IO uint32_t SWVDELVAL;                           /**< Software Valley Mode Delay Register */
  __IO uint32_t RESERVED_22[8];
  __IO uint32_t TZSEL;                               /**< Trip Zone Select Register */
  __IO uint32_t RESERVED_23;
  __IO uint32_t TZDCSEL;                             /**< Trip Zone Digital Comparator Select Register */
  __IO uint32_t RESERVED_24;
  __IO uint32_t TZCTL;                               /**< Trip Zone Control Register */
  __IO uint32_t TZCTL2;                              /**< Additional Trip Zone Control Register */
  __IO uint32_t TZCTLDCA;                            /**< Trip Zone Control Register Digital Compare A */
  __IO uint32_t TZCTLDCB;                            /**< Trip Zone Control Register Digital Compare B */
  __IO uint32_t RESERVED_25[5];
  __IO uint32_t TZEINT;                              /**< Trip Zone Enable Interrupt Register */
  __IO uint32_t RESERVED_26[5];
  __IO uint32_t TZFLG;                               /**< Trip Zone Flag Register */
  __IO uint32_t TZCBCFLG;                            /**< Trip Zone CBC Flag Register */
  __IO uint32_t TZOSTFLG;                            /**< Trip Zone OST Flag Register */
  __IO uint32_t RESERVED_27;
  __IO uint32_t TZCLR;                               /**< Trip Zone Clear Register */
  __IO uint32_t TZCBCCLR;                            /**< Trip Zone CBC CLear Register */
  __IO uint32_t TZOSTCLR;                            /**< Trip Zone OST CLear Register */
  __IO uint32_t RESERVED_28;
  __IO uint32_t TZFRC;                               /**< Trip Zone Force Register */
  __IO uint32_t RESERVED_29[8];
  __IO uint32_t ETSEL;                               /**< Event Trigger Selection Register */
  __IO uint32_t RESERVED_30;
  __IO uint32_t ETPS;                                /**< Event Trigger Pre-Scale Register */
  __IO uint32_t RESERVED_31;
  __IO uint32_t ETFLG;                               /**< Event Trigger Flag Register */
  __IO uint32_t RESERVED_32;
  __IO uint32_t ETCLR;                               /**< Event Trigger Clear Register */
  __IO uint32_t RESERVED_33;
  __IO uint32_t ETFRC;                               /**< Event Trigger Force Register */
  __IO uint32_t RESERVED_34;
  __IO uint32_t ETINTPS;                             /**< Event-Trigger Interrupt Pre-Scale Register */
  __IO uint32_t RESERVED_35;
  __IO uint32_t ETSOCPS;                             /**< Event-Trigger SOC Pre-Scale Register */
  __IO uint32_t RESERVED_36;
  __IO uint32_t ETCNTINITCTL;                        /**< Event-Trigger Counter Initialization Control Register */
  __IO uint32_t RESERVED_37;
  __IO uint32_t ETCNTINIT;                           /**< Event-Trigger Counter Initialization Register */
  __IO uint32_t RESERVED_38[11];
  __IO uint32_t DCTRIPSEL;                           /**< Digital Compare Trip Select Register */
  __IO uint32_t RESERVED_39[2];
  __IO uint32_t DCACTL;                              /**< Digital Compare A Control Register */
  __IO uint32_t DCBCTL;                              /**< Digital Compare B Control Register */
  __IO uint32_t RESERVED_40[2];
  __IO uint32_t DCFCTL;                              /**< Digital Compare Filter Control Register */
  __IO uint32_t DCCAPCTL;                            /**< Digital Compare Capture Control Register */
  __IO uint32_t DCFOFFSET;                           /**< Digital Compare Filter Offset Register */
  __IO uint32_t DCFOFFSETCNT;                        /**< Digital Compare Filter Offset Counter Register */
  __IO uint32_t DCFWINDOW;                           /**< Digital Compare Filter Window Register */
  __IO uint32_t DCFWINDOWCNT;                        /**< Digital Compare Filter Window Counter Register */
  __IO uint32_t BLANKPULSEMIXSEL;                    /**< Blanking window trigger pulse select Register */
  __IO uint32_t RESERVED_41;
  __IO uint32_t DCCAP;                               /**< Digital Compare Counter Capture Register */
  __IO uint32_t RESERVED_42[2];
  __IO uint32_t DCAHTRIPSEL;                         /**< Digital Compare AH Trip Select */
  __IO uint32_t DCALTRIPSEL;                         /**< Digital Compare AL Trip Select */
  __IO uint32_t DCBHTRIPSEL;                         /**< Digital Compare BH Trip Select */
  __IO uint32_t DCBLTRIPSEL;                         /**< Digital Compare BL Trip Select */
  __IO uint32_t RESERVED_43[36];
  __IO uint32_t LOCK;                                /**< EPWM Lock Register */
  __IO uint32_t RESERVED_44[2];
  __IO uint32_t HWVDELVAL;                           /**< Hardware Valley Mode Delay Register */
  __IO uint32_t VCNTVAL;                             /**< Hardware Valley Counter Register */
	__IO uint32_t EPWMOE;                              /**< EPWM Output Enable Register */
} EPWM_Type;

/* ----------------------------------------------------------------------------
   -- EPWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EPWM_Register_Masks EPWM Register Masks
 * @{
 */

/* EPWM - Peripheral instance base addresses */
/** Peripheral EPWM base address */
#define EPWM1_BASE                                 (0x40038000u)
#define EPWM2_BASE                                 (0x40039000u)
#define EPWM3_BASE                                 (0x4003A000u)
#define EPWM4_BASE                                 (0x400B0000u)
#define EPWM5_BASE                                 (0x400B1000u)
#define EPWM6_BASE                                 (0x400B2000u)
#define EPWM7_BASE                                 (0x400B3000u)
/** Peripheral DMA base pointer */
#define EPWM1                                      ((EPWM_Type *)EPWM1_BASE)
#define EPWM2                                      ((EPWM_Type *)EPWM2_BASE)
#define EPWM3                                      ((EPWM_Type *)EPWM3_BASE)
#define EPWM4                                      ((EPWM_Type *)EPWM4_BASE)
#define EPWM5                                      ((EPWM_Type *)EPWM5_BASE)
#define EPWM6                                      ((EPWM_Type *)EPWM6_BASE)
#define EPWM7                                      ((EPWM_Type *)EPWM7_BASE)

/*!
 * @}
 */ /* end of group EPWM_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
 *    -- SDFM Peripheral Access Layer
 *       ---------------------------------------------------------------------------- */

/*!
 *  * @addtogroup EWM_Peripheral_Access_Layer EWM Peripheral Access Layer
 *   * @{
 *    */

/** EWM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SDIFLG;                             /**< Register, offset: 0x0 */
       uint32_t Reserved1;
  __O  uint32_t SDIFLGCLR;                          /**< Register, offset: 0x8 */
       uint32_t Reserved2;
  __IO uint32_t SDCTL;                              /**< Register, offset: 0x10 */
       uint32_t Reserved3;
  __IO uint32_t SDMFILEN;                           /**< Register, offset: 0x18 */
  __IO uint32_t SDSTATUS;                           /**< Register, offset: 0x1c */
       uint32_t Reserved4[8];

  __O  uint32_t SDCTLPARM1;                         /**< Register, offset: 0x40 */
  __IO uint32_t SDDFPARM1;                          /**< Register, offset: 0x44 */
  __IO uint32_t SDDPARM1;                           /**< Register, offset: 0x48 */
  __IO uint32_t SDFLT1CMPH1;                        /**< Register, offset: 0x4c */
  __IO uint32_t SDFLT1CMPL1;                        /**< Register, offset: 0x50 */
  __IO uint32_t SDCPARM1;                           /**< Register, offset: 0x54 */
  __IO uint32_t SDDATA1;                            /**< Register, offset: 0x58 */
       uint32_t Reserved5;
  __IO uint32_t SDDATFIFO1;                         /**< Register, offset: 0x60 */
       uint32_t Reserved6;
  __IO uint32_t SDCDATA1;                           /**< Register, offset: 0x68 */
  __IO uint32_t SDFLT1CMPH2;                        /**< Register, offset: 0x6c */
  __IO uint32_t SDFLT1CMPHZ;                        /**< Register, offset: 0x70 */
  __IO uint32_t SDFIFOCTL1;                         /**< Register, offset: 0x74 */
  __IO uint32_t SDSYNC1;                            /**< Register, offset: 0x78 */
  __IO uint32_t SDFLT1CMPL2;                        /**< Register, offset: 0x7c */

  __IO uint32_t SDCTLPARM2;                         /**< Register, offset: 0x80 */
  __IO uint32_t SDDFPARM2;                          /**< Register, offset: 0x84 */
  __IO uint32_t SDDPARM2;                           /**< Register, offset: 0x88 */
  __IO uint32_t SDFLT2CMPH1;                        /**< Register, offset: 0x8c */
  __IO uint32_t SDFLT2CMPL1;                        /**< Register, offset: 0x90 */
  __IO uint32_t SDCPARM2;                           /**< Register, offset: 0x94 */
  __IO uint32_t SDDATA2;                            /**< Register, offset: 0x98 */
       uint32_t Reserved7;
  __IO uint32_t SDDATFIFO2;                         /**< Register, offset: 0xa0 */
       uint32_t Reserved8;
  __IO uint32_t SDCDATA2;                           /**< Register, offset: 0xa8 */
  __IO uint32_t SDFLT2CMPH2;                        /**< Register, offset: 0xac */
  __IO uint32_t SDFLT2CMPHZ;                        /**< Register, offset: 0xb0 */
  __IO uint32_t SDFIFOCTL2;                         /**< Register, offset: 0xb4 */
  __IO uint32_t SDSYNC2;                            /**< Register, offset: 0xb8 */
  __IO uint32_t SDFLT2CMPL2;                        /**< Register, offset: 0xbc */

  __IO uint32_t SDCTLPARM3;                         /**< Register, offset: 0xc0 */
  __IO uint32_t SDDFPARM3;                          /**< Register, offset: 0xc4 */
  __IO uint32_t SDDPARM3;                           /**< Register, offset: 0xc8 */
  __IO uint32_t SDFLT3CMPH1;                        /**< Register, offset: 0xcc */
  __IO uint32_t SDFLT3CMPL1;                        /**< Register, offset: 0xd0 */
  __IO uint32_t SDCPARM3;                           /**< Register, offset: 0xd4 */
  __IO uint32_t SDDATA3;                            /**< Register, offset: 0xd8 */
       uint32_t Reserved9;
  __IO uint32_t SDDATFIFO3;                         /**< Register, offset: 0xe0 */
       uint32_t Reserved10;
  __IO uint32_t SDCDATA3;                           /**< Register, offset: 0xe8 */
  __IO uint32_t SDFLT3CMPH2;                        /**< Register, offset: 0xec */
  __IO uint32_t SDFLT3CMPHZ;                        /**< Register, offset: 0xf0 */
  __IO uint32_t SDFIFOCTL3;                         /**< Register, offset: 0xf4 */
  __IO uint32_t SDSYNC3;                            /**< Register, offset: 0xf8 */
  __IO uint32_t SDFLT3CMPL2;                        /**< Register, offset: 0xfc */

  __IO uint32_t SDCTLPARM4;                         /**< Register, offset: 0x100 */
  __IO uint32_t SDDFPARM4;                          /**< Register, offset: 0x104 */
  __IO uint32_t SDDPARM4;                           /**< Register, offset: 0x108 */
  __IO uint32_t SDFLT4CMPH1;                        /**< Register, offset: 0x10c */
  __IO uint32_t SDFLT4CMPL1;                        /**< Register, offset: 0x110 */
  __IO uint32_t SDCPARM4;                           /**< Register, offset: 0x114 */
  __IO uint32_t SDDATA4;                            /**< Register, offset: 0x118 */
       uint32_t Reserved11;
  __IO uint32_t SDDATFIFO4;                         /**< Register, offset: 0x120 */
       uint32_t Reserved12;
  __IO uint32_t SDCDATA4;                           /**< Register, offset: 0x128 */
  __IO uint32_t SDFLT4CMPH2;                        /**< Register, offset: 0x12c */
  __IO uint32_t SDFLT4CMPHZ;                        /**< Register, offset: 0x130 */
  __IO uint32_t SDFIFOCTL4;                         /**< Register, offset: 0x134 */
  __IO uint32_t SDSYNC4;                            /**< Register, offset: 0x138 */
  __IO uint32_t SDFLT4CMPL2;                        /**< Register, offset: 0x13c */
       uint32_t Reserved13[16];
  __IO uint32_t SDCOMP1CTL;                         /**< Register, offset: 0x180 */
  __IO uint32_t SDCOMP1EVT2FLTCTL;                  /**< Register, offset: 0x184 */
  __IO uint32_t SDCOMP1EVT2FLTCLKCTL;               /**< Register, offset: 0x188 */
  __IO uint32_t SDCOMP1EVT1FLTCTL;                  /**< Register, offset: 0x18c */
  __IO uint32_t SDCOMP1EVT1FLTCLKCTL;               /**< Register, offset: 0x190 */
       uint32_t Reserved14[2];
  __IO uint32_t SDCOMP1LOCK;                        /**< Register, offset: 0x19c */
  __IO uint32_t SDCOMP2CTL;                         /**< Register, offset: 0x1a0 */
  __IO uint32_t SDCOMP2EVT2FLTCTL;                  /**< Register, offset: 0x1a4 */
  __IO uint32_t SDCOMP2EVT2FLTCLKCTL;               /**< Register, offset: 0x1a8 */
  __IO uint32_t SDCOMP2EVT1FLTCTL;                  /**< Register, offset: 0x1ac */
  __IO uint32_t SDCOMP2EVT1FLTCLKCTL;               /**< Register, offset: 0x1b0 */
       uint32_t Reserved15[2];
  __IO uint32_t SDCOMP2LOCK;                        /**< Register, offset: 0x1bc */
  __IO uint32_t SDCOMP3CTL;                         /**< Register, offset: 0x1c0 */
  __IO uint32_t SDCOMP3EVT2FLTCTL;                  /**< Register, offset: 0x1c4 */
  __IO uint32_t SDCOMP3EVT2FLTCLKCTL;               /**< Register, offset: 0x1c8 */
  __IO uint32_t SDCOMP3EVT1FLTCTL;                  /**< Register, offset: 0x1cc */
  __IO uint32_t SDCOMP3EVT1FLTCLKCTL;               /**< Register, offset: 0x1d0 */
       uint32_t Reserved16[2];
  __IO uint32_t SDCOMP3LOCK;                        /**< Register, offset: 0x1dc */
  __IO uint32_t SDCOMP4CTL;                         /**< Register, offset: 0x1e0 */
  __IO uint32_t SDCOMP4EVT2FLTCTL;                  /**< Register, offset: 0x1e4 */
  __IO uint32_t SDCOMP4EVT2FLTCLKCTL;               /**< Register, offset: 0x1e8 */
  __IO uint32_t SDCOMP4EVT1FLTCTL;                  /**< Register, offset: 0x1ec */
  __IO uint32_t SDCOMP4EVT1FLTCLKCTL;               /**< Register, offset: 0x1f0 */
       uint32_t Reserved17[2];
  __IO uint32_t SDCOMP4LOCK;                        /**< Register, offset: 0x1fc */

} SDFM_Type;

/* ----------------------------------------------------------------------------
 *  -- SDFM Register Masks
 * ---------------------------------------------------------------------------- */




/*!
 *  * @}
 *   */ /* end of group DMAMUX_Register_Masks */


/* SDFM - Peripheral instance base addresses */
/** Peripheral SDFM1 base address */
#define SDFM1_BASE                              (0x40030000u)
/** Peripheral DMAMUX base pointer */
#define SDFM1                                  ((SDFM_Type *)SDFM1_BASE)
/** Peripheral SDFM2 base address */
#define SDFM2_BASE                              (0x400A0000u)
/** Peripheral DMAMUX base pointer */
#define SDFM2                                  ((SDFM_Type *)SDFM2_BASE)

/** Array initializer of DMAMUX peripheral base addresses */
#define SDFM_BASE_ADDRS                        { SDFM1_BASE, SDFM2_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define SDFM_BASE_PTRS                         { SDFM1, SDFM2 }

/*!
 *  * @}
 *   */ /* end of group DMAMUX_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- EWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Peripheral_Access_Layer EWM Peripheral Access Layer
 * @{
 */

/** EWM - Register Layout Typedef */
typedef struct {
  __IO uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
  __O  uint8_t SERV;                               /**< Service Register, offset: 0x1 */
  __IO uint8_t CMPL;                               /**< Compare Low Register, offset: 0x2 */
  __IO uint8_t CMPH;                               /**< Compare High Register, offset: 0x3 */
    uint8_t Reserved1;                             /**< Compare High Register, offset: 0x4 */
  __IO uint8_t PSR;                             /**< Compare High Register, offset: 0x4 */
} EWM_Type;

/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Register_Masks EWM Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define EWM_CTRL_EWMEN_MASK                      (0x1U)
#define EWM_CTRL_EWMEN_SHIFT                     (0U)
/*! EWMEN - EWM enable.
 */
#define EWM_CTRL_EWMEN_SET(x)                    (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_EWMEN_SHIFT)) & EWM_CTRL_EWMEN_MASK)

#define EWM_CTRL_ASSIN_MASK                      (0x2U)
#define EWM_CTRL_ASSIN_SHIFT                     (1U)
/*! ASSIN - EWM_in's Assertion State Select.
 */
#define EWM_CTRL_ASSIN_SET(x)                    (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_ASSIN_SHIFT)) & EWM_CTRL_ASSIN_MASK)

#define EWM_CTRL_INEN_MASK                       (0x4U)
#define EWM_CTRL_INEN_SHIFT                      (2U)
/*! INEN - Input Enable.
 */
#define EWM_CTRL_INEN_SET(x)                     (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_INEN_SHIFT)) & EWM_CTRL_INEN_MASK)

#define EWM_CTRL_INTEN_MASK                      (0x8U)
#define EWM_CTRL_INTEN_SHIFT                     (3U)
/*! INTEN - Interrupt Enable.
 */
#define EWM_CTRL_INTEN_SET(x)                    (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_INTEN_SHIFT)) & EWM_CTRL_INTEN_MASK)
/*! @} */

/*! @name SERV - Service Register */
/*! @{ */

#define EWM_SERV_SERVICE_MASK                    (0xFFU)
#define EWM_SERV_SERVICE_SHIFT                   (0U)
#define EWM_SERV_SERVICE_SET(x)                  (((uint8_t)(((uint8_t)(x)) << EWM_SERV_SERVICE_SHIFT)) & EWM_SERV_SERVICE_MASK)
/*! @} */

/*! @name CMPL - Compare Low Register */
/*! @{ */

#define EWM_CMPL_COMPAREL_MASK                   (0xFFU)
#define EWM_CMPL_COMPAREL_SHIFT                  (0U)
#define EWM_CMPL_COMPAREL_SET(x)                 (((uint8_t)(((uint8_t)(x)) << EWM_CMPL_COMPAREL_SHIFT)) & EWM_CMPL_COMPAREL_MASK)
/*! @} */

/*! @name CMPH - Compare High Register */
/*! @{ */

#define EWM_CMPH_COMPAREH_MASK                   (0xFFU)
#define EWM_CMPH_COMPAREH_SHIFT                  (0U)
#define EWM_CMPH_COMPAREH_SET(x)                 (((uint8_t)(((uint8_t)(x)) << EWM_CMPH_COMPAREH_SHIFT)) & EWM_CMPH_COMPAREH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EWM_Register_Masks */


/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x40061000u)
/** Peripheral EWM base pointer */
#define EWM                                      ((EWM_Type *)EWM_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM }
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { WWDT_EWM_IRQn }

/*!
 * @}
 */ /* end of group EWM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MCAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCAN_Peripheral_Access_Layer 
 * @{
 */

/** MCAN - Register Layout Typedef */
typedef struct { 
  __IO  uint8_t MOD;                                 /**< Mode Register, offset: 0x0 */
  __O   uint8_t CMR;                                 /**< Command Register, offset: 0x1 */
  __I   uint8_t SR;                                  /**< Status Register, offset: 0x2 */
  __I   uint8_t IR;                                  /**< Interrupt Register, offset: 0x3 */
  __IO  uint8_t IER;                                 /**< Interrupt Enable Register, offset: 0x4 */
        uint8_t Reserved1;
  __IO  uint8_t BTR0;                                /**< Bus Timing0 Register, offset: 0x6 */
  __IO  uint8_t BTR1;                                /**< Bus Timing1 Register, offset: 0x7 */
  __IO  uint8_t OCR;                                 /**< output Control Register, offset: 0x8 */
        uint8_t Reserved2;
        uint8_t Reserved3;
  __I   uint8_t ALC;                                 /**< Arbitration lost Capture Register, offset: 0xB */
  __I   uint8_t ECC;                                 /**< Error Code Capture Register, offset: 0xC */
  __IO  uint8_t EWLR;                                /**< Error Warning Limit Register, offset: 0xD */
  __IO  uint8_t RXERR;                               /**< Receive Error Counter Register, offset: 0xE */
  __IO  uint8_t TXERR;                               /**< Transmit Error Counter Register, offset: 0xF */
  union {
    struct {
     __O  uint8_t TXFRMINFO;                         /**< Transmit Buffer Information Register, offset: 0x10 */
     __O  uint8_t TXDATAINFO[12];                    /**< Transmit Data Information Register, offset: 0x11 */
    }TXBUF_W;
    struct {
     __I  uint8_t RXFRMINFO;                         /**< Receive Frame Information Register, offset: 0x10 */
     __I  uint8_t RXDATAINFO[12];                    /**< Receive Data information Register, offset: 0x11 */
    } RXWINDOW;
    struct {
     __IO uint8_t ACR[4];                            /**< Acceptance Code Register, offset: 0x10 */
     __IO uint8_t AMR[4];                            /**< Acceptance Mask Register, offset: 0x14 */
          uint8_t Reserved[5];
    } ACCEPT;
  };
  __I  uint8_t RMC;                                  /**< Receive Message Counter Register, offset: 0x1D */
  __IO uint8_t RBSA;                                 /**< Receive Buffer Start Address Register, offset: 0x1E */
  __IO uint8_t CDR;                                  /**< Clock Divider Register, offset: 0x1F */
  __IO uint8_t RXFIFO[80];                           /**< Receive FIFO Register, offset: 0x20 */
  __I  uint8_t TXBUF_R[13];                          /**< Transmit BUFFER Register, offset: 0x60 */
} MCAN_Type;


/*!
 * @addtogroup MCAN_Register_Masks 
 * @{
 */
/*! @name MODE - mode Register */
/*! @{ */
// MOD.0: Reset Mode (RM)
#define MCAN_MOD_RM_MASK                       (0x01U)
#define MCAN_MOD_RM_SHIFT                      (0)
#define MCAN_MOD_RM_SET(x)                     (((uint8_t)(x) << MCAN_MOD_RM_SHIFT) & MCAN_MOD_RM_MASK)

// MOD.1: Listen Only Mode (LOM)
#define MCAN_MOD_LOM_MASK                      (0x02U)
#define MCAN_MOD_LOM_SHIFT                     (1)
#define MCAN_MOD_LOM_SET(x)                    (((uint8_t)(x) << MCAN_MOD_LOM_SHIFT) & MCAN_MOD_LOM_MASK)

// MOD.2: Self Test Mode (STM)
#define MCAN_MOD_STM_MASK                      (0x04U)
#define MCAN_MOD_STM_SHIFT                     (2)
#define MCAN_MOD_STM_SET(x)                    (((uint8_t)(x) << MCAN_MOD_STM_SHIFT) & MCAN_MOD_STM_MASK)

// MOD.3: Acceptance Filter Mode (AFM)
#define MCAN_MOD_AFM_MASK                      (0x08U)
#define MCAN_MOD_AFM_SHIFT                     (3)
#define MCAN_MOD_AFM_SET(x)                    (((uint8_t)(x) << MCAN_MOD_AFM_SHIFT) & MCAN_MOD_AFM_MASK)

// MOD.4: Sleep Mode (SM)
#define MCAN_MOD_SM_MASK                       (0x10U)
#define MCAN_MOD_SM_SHIFT                      (4)
#define MCAN_MOD_SM_SET(x)                     (((uint8_t)(x) << MCAN_MOD_SM_SHIFT) & MCAN_MOD_SM_MASK)
/*! @} */


/*! @name CMR - COMMAND Register */
/*! @{ */
#define MCAN_CMR_TR_MASK                         (0x01U)
#define MCAN_CMR_TR_SHIFT                        (0)
#define MCAN_CMR_TR_SET(x)                       (((uint8_t)(((uint8_t)(x)) << MCAN_CMR_TR_SHIFT)) & MCAN_CMR_TR_MASK)

#define MCAN_CMR_AT_MASK                         (0x02U)
#define MCAN_CMR_AT_SHIFT                        (1)
#define MCAN_CMR_AT_SET(x)                       (((uint8_t)(((uint8_t)(x)) << MCAN_CMR_AT_SHIFT)) & MCAN_CMR_AT_MASK)

#define MCAN_CMR_RRB_MASK                        (0x04U)
#define MCAN_CMR_RRB_SHIFT                       (2)
#define MCAN_CMR_RRB_SET(x)                      (((uint8_t)(((uint8_t)(x)) << MCAN_CMR_RRB_SHIFT)) & MCAN_CMR_RRB_MASK)

#define MCAN_CMR_CDO_MASK                        (0x08U)
#define MCAN_CMR_CDO_SHIFT                       (3)
#define MCAN_CMR_CDO_SET(x)                      (((uint8_t)(((uint8_t)(x)) << MCAN_CMR_CDO_SHIFT)) & MCAN_CMR_CDO_MASK)

#define MCAN_CMR_SRR_MASK                        (0x10U)
#define MCAN_CMR_SRR_SHIFT                       (4)
#define MCAN_CMR_SRR_SET(x)                      (((uint8_t)(((uint8_t)(x)) << MCAN_CMR_SRR_SHIFT)) & MCAN_CMR_SRR_MASK)

/*! @} */



/*! @name SR - STATUS Register */
/*! @{ */
#define MCAN_SR_RBS_MASK                         (0x01U)
#define MCAN_SR_RBS_SHIFT                        (0)
#define MCAN_SR_RBS_GET(x)                       (((uint8_t)(x) & MCAN_SR_RBS_MASK) >> MCAN_SR_RBS_SHIFT)

#define MCAN_SR_DOS_MASK                         (0x02U)
#define MCAN_SR_DOS_SHIFT                        (1)
#define MCAN_SR_DOS_GET(x)                       (((uint8_t)(x) & MCAN_SR_DOS_MASK) >> MCAN_SR_DOS_SHIFT)

#define MCAN_SR_TBS_MASK                         (0x04U)
#define MCAN_SR_TBS_SHIFT                        (2)
#define MCAN_SR_TBS_GET(x)                       (((uint8_t)(x) & MCAN_SR_TBS_MASK) >> MCAN_SR_TBS_SHIFT)

#define MCAN_SR_TCS_MASK                         (0x08U)
#define MCAN_SR_TCS_SHIFT                        (3)
#define MCAN_SR_TCS_GET(x)                       (((uint8_t)(x) & MCAN_SR_TCS_MASK) >> MCAN_SR_TCS_SHIFT)

#define MCAN_SR_RS_MASK                          (0x10U)
#define MCAN_SR_RS_SHIFT                         (4)
#define MCAN_SR_RS_GET(x)                        (((uint8_t)(x) & MCAN_SR_RS_MASK) >> MCAN_SR_RS_SHIFT)

#define MCAN_SR_TS_MASK                          (0x20U)
#define MCAN_SR_TS_SHIFT                         (5)
#define MCAN_SR_TS_GET(x)                        (((uint8_t)(x) & MCAN_SR_TS_MASK) >> MCAN_SR_TS_SHIFT)

#define MCAN_SR_ES_MASK                          (0x40U)
#define MCAN_SR_ES_SHIFT                         (6)
#define MCAN_SR_ES_GET(x)                        (((uint8_t)(x) & MCAN_SR_ES_MASK) >> MCAN_SR_ES_SHIFT)

#define MCAN_SR_BS_MASK                          (0x80U)
#define MCAN_SR_BS_SHIFT                         (7)
#define MCAN_SR_BS_GET(x)                        (((uint8_t)(x) & MCAN_SR_BS_MASK) >> MCAN_SR_BS_SHIFT)
/*! @} */

/*! @name IR - INTERRUPT Register */
/*! @{ */
#define MCAN_IR_RI_MASK                          (0x01U)
#define MCAN_IR_RI_SHIFT                         (0)
#define MCAN_IR_RI_GET(x)                        (((uint8_t)(x) & MCAN_IR_RI_MASK) >> MCAN_IR_RI_SHIFT)

#define MCAN_IR_TI_MASK                          (0x02U)
#define MCAN_IR_TI_SHIFT                         (1)
#define MCAN_IR_TI_GET(x)                        (((uint8_t)(x) & MCAN_IR_TI_MASK) >> MCAN_IR_TI_SHIFT)

#define MCAN_IR_EI_MASK                          (0x04U)
#define MCAN_IR_EI_SHIFT                         (2)
#define MCAN_IR_EI_GET(x)                        (((uint8_t)(x) & MCAN_IR_EI_MASK) >> MCAN_IR_EI_SHIFT)

#define MCAN_IR_DOI_MASK                         (0x08U)
#define MCAN_IR_DOI_SHIFT                        (3)
#define MCAN_IR_DOI_GET(x)                       (((uint8_t)(x) & MCAN_IR_DOI_MASK) >> MCAN_IR_DOI_SHIFT)

#define MCAN_IR_WUI_MASK                         (0x10U)
#define MCAN_IR_WUI_SHIFT                        (4)
#define MCAN_IR_WUI_GET(x)                       (((uint8_t)(x) & MCAN_IR_WUI_MASK) >> MCAN_IR_WUI_SHIFT)

#define MCAN_IR_EPI_MASK                         (0x20U)
#define MCAN_IR_EPI_SHIFT                        (5)
#define MCAN_IR_EPI_GET(x)                       (((uint8_t)(x) & MCAN_IR_EPI_MASK) >> MCAN_IR_EPI_SHIFT)

#define MCAN_IR_ALI_MASK                         (0x40U)
#define MCAN_IR_ALI_SHIFT                        (6)
#define MCAN_IR_ALI_GET(x)                       (((uint8_t)(x) & MCAN_IR_ALI_MASK) >> MCAN_IR_ALI_SHIFT)

#define MCAN_IR_BEI_MASK                         (0x80U)
#define MCAN_IR_BEI_SHIFT                        (7)
#define MCAN_IR_BEI_GET(x)                       (((uint8_t)(x) & MCAN_IR_BEI_MASK) >> MCAN_IR_BEI_SHIFT)

/*! @} */


/*! @name IER - INTERRUPT ENABLE Register */
/*! @{ */

#define MCAN_IER_RIE_MASK                        (0x01U)
#define MCAN_IER_RIE_SHIFT                       (0)
#define MCAN_IER_RIE_SET(x)                      (((uint8_t)(((uint8_t)(x)) << MCAN_IER_RIE_SHIFT)) & MCAN_IER_RIE_MASK)

#define MCAN_IER_TIE_MASK                        (0x02U)
#define MCAN_IER_TIE_SHIFT                       (1)
#define MCAN_IER_TIE_SET(x)                      (((uint8_t)(((uint8_t)(x)) << MCAN_IER_TIE_SHIFT)) & MCAN_IER_TIE_MASK)

#define MCAN_IER_EIE_MASK                        (0x04U)
#define MCAN_IER_EIE_SHIFT                       (2)
#define MCAN_IER_EIE_SET(x)                      (((uint8_t)(((uint8_t)(x)) << MCAN_IER_EIE_SHIFT)) & MCAN_IER_EIE_MASK)

#define MCAN_IER_DOIE_MASK                       (0x08U)
#define MCAN_IER_DOIE_SHIFT                      (3)
#define MCAN_IER_DOIE_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_IER_DOIE_SHIFT)) & MCAN_IER_DOIE_MASK)

#define MCAN_IER_WUIE_MASK                       (0x10U)
#define MCAN_IER_WUIE_SHIFT                      (4)
#define MCAN_IER_WUIE_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_IER_WUIE_SHIFT)) & MCAN_IER_WUIE_MASK)

#define MCAN_IER_EPIE_MASK                       (0x20U)
#define MCAN_IER_EPIE_SHIFT                      (5)
#define MCAN_IER_EPIE_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_IER_EPIE_SHIFT)) & MCAN_IER_EPIE_MASK)

#define MCAN_IER_ALIE_MASK                       (0x40U)
#define MCAN_IER_ALIE_SHIFT                      (6)
#define MCAN_IER_ALIE_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_IER_ALIE_SHIFT)) & MCAN_IER_ALIE_MASK)

#define MCAN_IER_BEIE_MASK                       (0x80U)
#define MCAN_IER_BEIE_SHIFT                      (7)
#define MCAN_IER_BEIE_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_IER_BEIE_SHIFT)) & MCAN_IER_BEIE_MASK)
/*! @} */

/*! @name BTR0 - BUS TIMING Register0 */
/*! @{ */

#define MCAN_BTR0_BRP_MASK                       (0x3FU)  // BTR0.5-0: BRP[5:0]
#define MCAN_BTR0_BRP_SHIFT                      (0)
#define MCAN_BTR0_BRP_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_BTR0_BRP_SHIFT) & MCAN_BTR0_BRP_MASK)

#define MCAN_BTR0_SJW_MASK                       (0xC0U)  // BTR0.7-6: SJW[1:0]
#define MCAN_BTR0_SJW_SHIFT                      (6)
#define MCAN_BTR0_SJW_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_BTR0_SJW_SHIFT)) & MCAN_BTR0_SJW_MASK)

/*! @} */


/*! @name BTR1 - BUS TIMING Register1 */
/*! @{ */

#define MCAN_BTR1_TSEG1_MASK                     (0x0FU)  // BTR1.3-0: TSEG1[3:0]
#define MCAN_BTR1_TSEG1_SHIFT                    (0)
#define MCAN_BTR1_TSEG1_SET(x)                   (((uint8_t)(((uint8_t)(x)) << MCAN_BTR1_TSEG1_SHIFT) & MCAN_BTR1_TSEG1_MASK)

#define MCAN_BTR1_TSEG2_MASK                     (0x70U)  // BTR1.6-4: TSEG2[2:0]
#define MCAN_BTR1_TSEG2_SHIFT                    (4)
#define MCAN_BTR1_TSEG2_SET(x)                   (((uint8_t)(((uint8_t)(x)) << MCAN_BTR1_TSEG2_SHIFT) & MCAN_BTR1_TSEG2_MASK)

#define MCAN_BTR1_SAM_MASK                       (0x80U)  // BTR1.7: SAM (Sample Mode)
#define MCAN_BTR1_SAM_SHIFT                      (7)
#define MCAN_BTR1_SAM_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_BTR1_SAM_SHIFT) & MCAN_BTR1_SAM_MASK)

/*! @} */



/*! @name OCR - OUTPUT CONTROL Register */
/*! @{ */

#define MCAN_OCR_OCMODE_MASK                     (0x03U)  // OCR.1-0: OCMODE[1:0]
#define MCAN_OCR_OCMODE_SHIFT                    (0)
#define MCAN_OCR_OCMODE_SET(x)                   (((uint8_t)(((uint8_t)(x)) << MCAN_OCR_OCMODE_SHIFT)) & MCAN_OCR_OCMODE_MASK)

/*! @} */


/*! @name ALC - ARBITRATION LOST CAPTURE Register */
/*! @{ */
#define MCAN_ALC_FIELD_MASK                      (0x1FU)  // ALC.4-0: Valid field (specific usage depends on table below)
#define MCAN_ALC_FIELD_SHIFT                     (0)
#define MCAN_ALC_FIELD_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_ALC_FIELD_SHIFT) & MCAN_ALC_FIELD_MASK)
/*! @} */


/*! @name ECC - ERROR CODE CAPTURE Register */
#define MCAN_ECC_ERROR_CODE_MASK                 (0xC0U)  // ECC[7:6]: Error Code
#define MCAN_ECC_ERROR_CODE_SHIFT                (6)
#define MCAN_ECC_ERROR_CODE_SET(x)               (((uint8_t)(((uint8_t)(x)) << MCAN_ECC_ERROR_CODE_SHIFT) & MCAN_ECC_ERROR_CODE_MASK)

#define MCAN_ECC_DIRECTION_MASK                  (0x20U)  // ECC.5: Direction
#define MCAN_ECC_DIRECTION_SHIFT                 (5)
#define MCAN_ECC_DIRECTION_SET(x)                (((uint8_t)(((uint8_t)(x)) << MCAN_ECC_DIRECTION_SHIFT) & MCAN_ECC_DIRECTION_MASK)

#define MCAN_ECC_SEGMENT_CODE_MASK               (0x1FU)  // ECC[4:0]: Segment Code
#define MCAN_ECC_SEGMENT_CODE_SHIFT              (0)
#define MCAN_ECC_SEGMENT_CODE_SET(x)             (((uint8_t)(((uint8_t)(x)) << MCAN_ECC_SEGMENT_CODE_SHIFT) & MCAN_ECC_SEGMENT_CODE_MASK)
/*! @} */

/*! @name EWLR -  ERROR WARNING LIMIT Register */
/*! @{ */
#define MCAN_EWLR_EWL_MASK                       (0xFFU)  // EWLR[7:0]: EWL[7:0] (8-bit Error Warning Limit)
#define MCAN_EWLR_EWL_SHIFT                      (0)
#define MCAN_EWLR_EWL_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_EWLR_EWL_SHIFT)) & MCAN_EWLR_EWL_MASK)

/*! @} */



/*! @name RXERR - RECEIVE ERROR COUNTER Register */
/*! @{ */
#define MCAN_RXERR_COUNTER_MASK                       (0xFFU)  
#define MCAN_RXERR_COUNTER_SHIFT                      (0)
#define MCAN_RXERR_COUNTER_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_RXERR_COUNTER_SHIFT)) & MCAN_RXERR_COUNTER)

/*! @} */


/*! @name TXERR - TRANSMIT ERROR COUNTER Register */
/*! @{ */
#define MCAN_TXERR_COUNTER_MASK                       (0xFFU)  
#define MCAN_TXERR_COUNTER_SHIFT                      (0)
#define MCAN_TXERR_COUNTER_SET(x)                     (((uint8_t)(((uint8_t)(x)) << MCAN_TXERR_COUNTER_SHIFT)) & MCAN_TXERR_COUNTER)

/*! @} */


/*! @name TXFRMINFO - TX Frame Information Register */
/*! @{ */

#define MCAN_TXFRMINFO_DLC_MASK                         (0x0FU)   
#define MCAN_TXFRMINFO_DLC_SHIFT                        (0)
#define MCAN_TXFRMINFO_DLC_SET(x)                       (((uint8_t)(((uint8_t)(x)) << MCAN_TXFRMINFO_DLC_SHIFT)) & MCAN_TXFRMINFO_DLC_MASK)

#define MCAN_TXFRMINFO_RTR_MASK                         (0x40U)  
#define MCAN_TXFRMINFO_RTR_SHIFT                        (6)
#define MCAN_TXFRMINFO_RTR_SET(x)                       (((uint8_t)(((uint8_t)(x)) << MCAN_TXFRMINFO_RTR_SHIFT)) & MCAN_TXFRMINFO_RTR_MASK)

#define MCAN_TXFRMINFO_FF_MASK                          (0x80U)   
#define MCAN_TXFRMINFO_FF_SHIFT                         (7)
#define MCAN_TXFRMINFO_FF_SET(x)                        (((uint8_t)(((uint8_t)(x)) << MCAN_TXFRMINFO_FF_SHIFT)) & MCAN_TXFRMINFO_FF_MASK)
/*! @} */


/*! @name TXDATAINFO - TX Identifier & TX Data Byte Register */
/*! @{ */

#define MCAN_TXDATAINFO_S_ID28_21_MASK                          (0x7ffU)   
#define MCAN_TXDATAINFO_S_ID28_21_SHIFT                         (3)
#define MCAN_TXDATAINFO_S_ID28_21_SET(x)                        ((uint8_t)((((uint32_t)(x)) & MCAN_TXDATAINFO_S_ID28_21_MASK)>>MCAN_TXDATAINFO_S_ID28_21_SHIFT))


#define MCAN_TXDATAINFO_S_ID20_18_MASK                          (0x7U)   
#define MCAN_TXDATAINFO_S_ID20_18_SHIFT                         (5)
#define MCAN_TXDATAINFO_S_ID20_18_SET(x)                        ((uint8_t)((((uint32_t)(x)) & MCAN_TXDATAINFO_S_ID20_18_MASK)<<MCAN_TXDATAINFO_S_ID20_18_SHIFT))


#define MCAN_TXDATAINFO_E_ID28_21_MASK                          (0x1fffffffU)   
#define MCAN_TXDATAINFO_E_ID28_21_SHIFT                         (21)
#define MCAN_TXDATAINFO_E_ID28_21_SET(x)                        ((uint8_t)((((uint32_t)(x)) & MCAN_TXDATAINFO_E_ID28_21_MASK)>>MCAN_TXDATAINFO_E_ID28_21_SHIFT))



#define MCAN_TXDATAINFO_E_ID20_13_MASK                          (0x1fffffffU)   
#define MCAN_TXDATAINFO_E_ID20_13_SHIFT                         (13)
#define MCAN_TXDATAINFO_E_ID20_13_SET(x)                        ((uint8_t)((((uint32_t)(x)) & MCAN_TXDATAINFO_E_ID20_13_MASK)>>MCAN_TXDATAINFO_E_ID20_13_SHIFT))


#define MCAN_TXDATAINFO_E_ID12_5_MASK                           (0x1fffffffU)   
#define MCAN_TXDATAINFO_E_ID12_5_SHIFT                          (5)
#define MCAN_TXDATAINFO_E_ID12_5_SET(x)                         ((uint8_t)((((uint32_t)(x)) & MCAN_TXDATAINFO_E_ID12_5_MASK)>>MCAN_TXDATAINFO_E_ID12_5_SHIFT))


#define MCAN_TXDATAINFO_E_ID4_0_MASK                            (0x1fU)   
#define MCAN_TXDATAINFO_E_ID4_0_SHIFT                           (3)
#define MCAN_TXDATAINFO_E_ID4_0_SET(x)                          ((uint8_t)((((uint32_t)(x)) & MCAN_TXDATAINFO_E_ID4_0_MASK)<<MCAN_TXDATAINFO_E_ID4_0_SHIFT))


#define MCAN_TXDATAINFO_DATAx_MASK                              (0xffU)   
#define MCAN_TXDATAINFO_DATAx_SHIFT                             (0)
#define MCAN_TXDATAINFO_DATAx_SET(x)                            ((uint8_t)((((uint32_t)(x)) & MCAN_TXDATAINFO_DATAx_MASK)<<MCAN_TXDATAINFO_DATAx_SHIFT))

/*! @} */


/*! @name RXFRMINFO - RX Frame Information Register */
/*! @{ */

#define MCAN_RXFRMINFO_DLC_MASK                         (0x0FU)   
#define MCAN_RXFRMINFO_DLC_SHIFT                        (0)
#define MCAN_RXFRMINFO_DLC_GET(x)                       (((uint8_t)(((uint8_t)(x))  & MCAN_RXFRMINFO_DLC_MASK))>>MCAN_RXFRMINFO_DLC_SHIFT)

#define MCAN_RXFRMINFO_RTR_MASK                         (0x40U)  
#define MCAN_RXFRMINFO_RTR_SHIFT                        (6)
#define MCAN_RXFRMINFO_RTR_GET(x)                       (((uint8_t)(((uint8_t)(x))  & MCAN_RXFRMINFO_RTR_MASK))>>MCAN_RXFRMINFO_RTR_SHIFT)

#define MCAN_RXFRMINFO_FF_MASK                          (0x80U)   
#define MCAN_RXFRMINFO_FF_SHIFT                         (7)
#define MCAN_RXFRMINFO_FF_GET(x)                        (((uint8_t)(((uint8_t)(x)) & MCAN_RXFRMINFO_FF_MASK))>> MCAN_RXFRMINFO_FF_SHIFT )

/*! @} */


/*! @name RXDATAINFO - RX Identifier & RX Data Byte Register */
/*! @{ */

#define MCAN_RXDATAINFO_S_ID_GET(x,y)                           (((uint32_t)(x)<<3) | ((uint32_t)(y & 0xE0)>>5))
#define MCAN_RXDATAINFO_E_ID_GET(x,y,k,j)                       ((((uint32_t)(x)<<24) | ((uint32_t)(y)<<16) | ((uint32_t)(k)<<8) | ((uint32_t)(j) & 0xF8))>>3)
#define MCAN_RXDATAINFO_DATAx_GET(x)                            ((uint8_t)(x & 0xFF)) 

/*! @} */


/*! @name ACR - ACCEPTANCE CODE Register */
/*! @{ */
#define MCAN_ACR_ACR0_MASK                      (0xFFU)   
#define MCAN_ACR_ACR0_SHIFT                     (0)
#define MCAN_ACR_ACR0_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_ACR_ACR0_SHIFT)) & MCAN_ACR_ACR0_MASK)

#define MCAN_ACR_ACR1_MASK                      (0xFFU)  
#define MCAN_ACR_ACR1_SHIFT                     (0)
#define MCAN_ACR_ACR1_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_ACR_ACR1_SHIFT)) & MCAN_ACR_ACR1_MASK)

#define MCAN_ACR_ACR2_MASK                      (0xFFU)   
#define MCAN_ACR_ACR2_SHIFT                     (0)
#define MCAN_ACR_ACR2_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_ACR_ACR2_SHIFT)) & MCAN_ACR_ACR2_MASK)

#define MCAN_ACR_ACR3_MASK                      (0xFFU)  
#define MCAN_ACR_ACR3_SHIFT                     (0)
#define MCAN_ACR_ACR3_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_ACR_ACR3_SHIFT)) & MCAN_ACR_ACR3_MASK)

/*! @} */

/*! @name AMR - ACCEPTANCE MASK Register */
/*! @{ */
#define MCAN_AMR_AMR0_MASK                      (0xFFU)   
#define MCAN_AMR_AMR0_SHIFT                     (0)
#define MCAN_AMR_AMR0_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_AMR_AMR0_SHIFT)) & MCAN_AMR_AMR0_MASK)

#define MCAN_AMR_AMR1_MASK                      (0xFFU)  
#define MCAN_AMR_AMR1_SHIFT                     (0)
#define MCAN_AMR_AMR1_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_AMR_AMR1_SHIFT)) & MCAN_AMR_AMR1_MASK)

#define MCAN_AMR_AMR2_MASK                      (0xFFU)   
#define MCAN_AMR_AMR2_SHIFT                     (0)
#define MCAN_AMR_AMR2_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_AMR_AMR2_SHIFT)) & MCAN_AMR_AMR2_MASK)

#define MCAN_AMR_AMR3_MASK                      (0xFFU)  
#define MCAN_AMR_AMR3_SHIFT                     (0)
#define MCAN_AMR_AMR3_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_AMR_AMR3_SHIFT)) & MCAN_AMR_AMR3_MASK)
/*! @} */


/*! @name RMC - RECEIVE MESSAGE COUNTER Register */
/*! @{ */
#define MCAN_RMC_FIELD_MASK                      (0x1FU)  // RMC.4-0: Configurable field (5-bit)
#define MCAN_RMC_FIELD_SHIFT                     (0)
#define MCAN_RMC_FIELD_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_RMC_FIELD_SHIFT)) & MCAN_RMC_FIELD_MASK)

/*! @} */


/*! @name RBSA - RECEIVE BUFFER START ADDRESS Register */
/*! @{ */
#define MCAN_RBSA_FIELD_MASK                     (0x3FU)  // RBSA.5-0: Valid field (6-bit)
#define MCAN_RBSA_FIELD_SHIFT                    (0)
#define MCAN_RBSA_FIELD_SET(x)                   (((uint8_t)(((uint8_t)(x)) << MCAN_RBSA_FIELD_SHIFT) & MCAN_RBSA_FIELD_MASK)
/*! @} */


/*! @name CDR - CLOCK DIVIDER Register */
/*! @{ */

#define MCAN_CDR_FIELD_MASK                      (0x07U)  // CDR.2-0: Configurable field (3-bit)
#define MCAN_CDR_FIELD_SHIFT                     (0)
#define MCAN_CDR_FIELD_SET(x)                    (((uint8_t)(((uint8_t)(x)) << MCAN_CDR_FIELD_SHIFT) & MCAN_CDR_FIELD_MASK)

#define MCAN_CDR_CLKOFF_MASK                     (0x08U)  // CDR.3: Clock Off
#define MCAN_CDR_CLKOFF_SHIFT                    (3)
#define MCAN_CDR_CLKOFF_SET(x)                   (((uint8_t)(((uint8_t)(x)) << MCAN_CDR_CLKOFF_SHIFT)) & MCAN_CDR_CLKOFF_MASK)

/*! @} */

/*!
 * @}
 */ /* end of group MCAN_Register_Masks */



/* MCAN - Peripheral instance base addresses */
/** Peripheral MCAN1 base address */
#define MCAN1_BASE                                 (0x40024000u)
/** Peripheral MCAN1 base pointer */
#define MCAN1                                      ((MCAN_Type *)MCAN1_BASE)
/** Peripheral MCAN1 base address */
#define MCAN2_BASE                                 (0x400A4000u)
/** Peripheral MCAN1 base pointer */
#define MCAN2                                      ((MCAN_Type *)MCAN2_BASE)
/** Array initializer of MCAN peripheral base addresses */
#define MCAN_BASE_ADDRS                           { MCAN1_BASE, MCAN2_BASE }
/** Array initializer of MCAN peripheral base pointers */
#define MCAN_BASE_PTRS                            { MCAN1, MCAN2 }
/** Interrupt vectors for the MCAN peripheral type */
#define MCAN_IRQS                                 { MCAN1_IRQn, MCAN2_IRQn }

/** FLASH_CTRL - Register Layout Typedef */
/* ----------------------------------------------------------------------------
   -- FLASH CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_CTRL_Peripheral_Access_Layer FLASH Control Peripheral Access Layer
 * @{
 */

/** FLASH_CTRL - Register Layout Typedef */
typedef struct {
       uint32_t reserved;
  __IO uint32_t CMD;                             /**< Flash Command Register, offset: 0x4 */
  __IO uint32_t ADDR;                            /**< Flash Address Register, offset: 0x8 */
  struct {                                       
    __IO uint32_t DATA_UM;                         /**< Data Storage (uppermost word), offset: 0x0C */
    __IO uint32_t DATA_MU;                         /**< Data Storage (mid-upper word), offset: 0x10 */
    __IO uint32_t DATA_ML;                         /**< Data Storage (mid-lower word), offset: 0x14 */
    __IO uint32_t DATA_LM;                         /**< Data Storage (lowermost word), offset: 0x18 */
  } DATALINE;
  __IO uint32_t RDCYCLE;                           /**< Flash Bank 2-3 Control Register, offset: 0x1C */
  __IO uint32_t PROTECT;                     /**< Cache Tag Storage, array offset: 0x100, array step: 0x20 */
  __IO uint32_t STAT;                       /**< Cache Tag Storage, array offset: 0x110, array step: 0x24 */
  __IO uint32_t CCTL;                       /**< Cache Tag Storage, array offset: 0x110, array step: 0x28 */
} FLASH_Type;

/* ----------------------------------------------------------------------------
   -- FLASH Control Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_Register_Masks FLASH Control Register Masks
 * @{
 */

/*! @name CMD - FLASH_CTRL Command Register */
/*! @{ */
#define FLASH_CMD_NVR_MASK                         (0x80U)
#define FLASH_CMD_NVR_SHIFT                        (7)
#define FLASH_CMD_NVR_SET(x)                   (((uint8_t)(((uint8_t)(x)) << FLASH_CMD_NVR_SHIFT)) & FLASH_CMD_NVR_MASK)
/*! @} */


/*! @name STAT - FLASH_CTRL STATUS Register */
/*! @{ */
#define FLASH_STATUS_BUSY_MASK                     (0x01U)
#define FLASH_STATUS_BUSY_SHIFT                    (0)
#define FLASH_STATUS_BUSY_SET(x)               (((uint8_t)(((uint8_t)(x)) << FLASH_STATUS_BUSY_SHIFT)) & FLASH_STATUS_BUSY_MASK)
/*! @} */


/*! @name CCTL - CACHE Control Register */
/*! @{ */
#define FLASH_CCTL_CACHE_CLR_MASK                  (0x01U)
#define FLASH_CCTL_CACHE_CLR_SHIFT                 (0)
#define FLASH_CCTL_CACHE_CLR_SET(x)            (((uint8_t)(((uint8_t)(x)) << FLASH_CCTL_CACHE_CLR_SHIFT)) & FLASH_CCTL_CACHE_CLR_MASK)

#define FLASH_CCTL_CACHE_DISABLE_MASK              (0x02U)
#define FLASH_CCTL_CACHE_DISABLE_SHIFT             (1)
#define FLASH_CCTL_CACHE_DISABLE_SET(x)        (((uint8_t)(((uint8_t)(x)) << FLASH_CCTL_CACHE_DISABLE_SHIFT)) & FLASH_CCTL_CACHE_DISABLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_CTRL_Register_Masks */


/* FLASH_CTRL - Peripheral instance base addresses */
/** Peripheral FLASH_CTRL base address */
#define FLASH_BASE                                 (0x40020000u)
/** Peripheral FLASH_CTRL base pointer */
#define FLASH                                      ((FLASH_Type *)FLASH_BASE)
/** Array initializer of FLASH_CTRL peripheral base addresses */
#define FLASH_BASE_ADDRS                           { FLASH_BASE }
/** Array initializer of FLASH_CTRL peripheral base pointers */
#define FLASH_BASE_PTRS                            { FLASH }

/*!
 * @}
 */ /* end of group FLASH_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __O  uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __O  uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __O  uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
} GPIO_TypeDef;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name PDOR - Port Data Output Register */
/*! @{ */

#define GPIO_PDOR_PDO_MASK                       (0xFFFFFFFFU)
#define GPIO_PDOR_PDO_SHIFT                      (0U)
/*! PDO - Port Data Output
 *  0b00000000000000000000000000000000..Logic level 0 is driven on pin, provided pin is configured for general-purpose output.
 *  0b00000000000000000000000000000001..Logic level 1 is driven on pin, provided pin is configured for general-purpose output.
 */
#define GPIO_PDOR_PDO_SET(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO_SHIFT)) & GPIO_PDOR_PDO_MASK)
/*! @} */

/*! @name PSOR - Port Set Output Register */
/*! @{ */

#define GPIO_PSOR_PTSO_MASK                      (0xFFFFFFFFU)
#define GPIO_PSOR_PTSO_SHIFT                     (0U)
/*! PTSO - Port Set Output
 *  0b00000000000000000000000000000000..Corresponding bit in PDORn does not change.
 *  0b00000000000000000000000000000001..Corresponding bit in PDORn is set to logic 1.
 */
#define GPIO_PSOR_PTSO_SET(x)                    (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO_SHIFT)) & GPIO_PSOR_PTSO_MASK)
/*! @} */

/*! @name PCOR - Port Clear Output Register */
/*! @{ */

#define GPIO_PCOR_PTCO_MASK                      (0xFFFFFFFFU)
#define GPIO_PCOR_PTCO_SHIFT                     (0U)
/*! PTCO - Port Clear Output
 *  0b00000000000000000000000000000000..Corresponding bit in PDORn does not change.
 *  0b00000000000000000000000000000001..Corresponding bit in PDORn is cleared to logic 0.
 */
#define GPIO_PCOR_PTCO_SET(x)                    (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO_SHIFT)) & GPIO_PCOR_PTCO_MASK)
/*! @} */

/*! @name PTOR - Port Toggle Output Register */
/*! @{ */

#define GPIO_PTOR_PTTO_MASK                      (0xFFFFFFFFU)
#define GPIO_PTOR_PTTO_SHIFT                     (0U)
/*! PTTO - Port Toggle Output
 *  0b00000000000000000000000000000000..Corresponding bit in PDORn does not change.
 *  0b00000000000000000000000000000001..Corresponding bit in PDORn is set to the inverse of its existing logic state.
 */
#define GPIO_PTOR_PTTO_SET(x)                    (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO_SHIFT)) & GPIO_PTOR_PTTO_MASK)
/*! @} */

/*! @name PDIR - Port Data Input Register */
/*! @{ */

#define GPIO_PDIR_PDI_MASK                       (0xFFFFFFFFU)
#define GPIO_PDIR_PDI_SHIFT                      (0U)
/*! PDI - Port Data Input
 *  0b00000000000000000000000000000000..Pin logic level is logic 0, or is not configured for use by digital function.
 *  0b00000000000000000000000000000001..Pin logic level is logic 1.
 */
#define GPIO_PDIR_PDI_SET(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI_SHIFT)) & GPIO_PDIR_PDI_MASK)
/*! @} */

/*! @name PDDR - Port Data Direction Register */
/*! @{ */

#define GPIO_PDDR_PDD_MASK                       (0xFFFFFFFFU)
#define GPIO_PDDR_PDD_SHIFT                      (0U)
/*! PDD - Port Data Direction
 *  0b00000000000000000000000000000000..Pin is configured as general-purpose input, for the GPIO function.
 *  0b00000000000000000000000000000001..Pin is configured as general-purpose output, for the GPIO function.
 */
#define GPIO_PDDR_PDD_SET(x)                     (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD_SHIFT)) & GPIO_PDDR_PDD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x400FF000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_TypeDef *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x400FF040u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_TypeDef *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x400FF080u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((GPIO_TypeDef *)GPIOC_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC }

/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- I2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Peripheral_Access_Layer I2C Peripheral Access Layer
 * @{
 */

/** I2C - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONSET;
  __IO uint32_t CONCLR;
  __I  uint32_t STAT;
  __IO uint32_t DAT;
  __IO uint32_t CLK;
  __IO uint32_t ADR0;
  __IO uint32_t ADRMASK0;
  __IO uint32_t XADR0;
  __IO uint32_t XADRMASK0;
  __IO uint32_t RST;
  __IO uint32_t ADR1;
  __IO uint32_t ADRMASK1;
  __IO uint32_t ADR2;
  __IO uint32_t ADRMASK2;
  __IO uint32_t ADR3;
  __IO uint32_t ADRMASK3;

} I2C_TypeDef;

/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */
/*!
 *  * @addtogroup I2C_Register_Masks I2C Register Masks
 *   * @{
 *    */

/*! @name I2CxCONSET - I2Cx Configuration Register */
/*! @{ */
#define I2C_CONSET_ADRF_MASK                      (1)
#define I2C_CONSET_ADRF_SHIFT                     (0)
#define I2C_CONSET_ADRF_SET(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_ADRF_SHIFT)) & I2C_CONSET_ADRF_MASK)

#define I2C_CONSET_XADRF_MASK                     (2)
#define I2C_CONSET_XADRF_SHIFT                    (1)
#define I2C_CONSET_XADRF_SET(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_XADRF_SHIFT)) & I2C_CONSET_XADRF_MASK)

#define I2C_CONSET_AA_MASK                        (4)
#define I2C_CONSET_AA_SHIFT                       (2)
#define I2C_CONSET_AA_SET(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_AA_SHIFT)) & I2C_CONSET_AA_MASK)

#define I2C_CONSET_SI_MASK                        (8)
#define I2C_CONSET_SI_SHIFT                       (3)
#define I2C_CONSET_SI_SET(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_SI_SHIFT)) & I2C_CONSET_SI_MASK)

#define I2C_CONSET_STO_MASK                       (0x10)
#define I2C_CONSET_STO_SHIFT                      (4)
#define I2C_CONSET_STO_SET(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_STO_SHIFT)) & I2C_CONSET_STO_MASK)

#define I2C_CONSET_STA_MASK                       (0x20)
#define I2C_CONSET_STA_SHIFT                      (5)
#define I2C_CONSET_STA_SET(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_STA_SHIFT)) & I2C_CONSET_STA_MASK)

#define I2C_CONSET_I2CEN_MASK                     (0x40)
#define I2C_CONSET_I2CEN_SHIFT                    (6)
#define I2C_CONSET_I2CEN_SET(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_I2CEN_SHIFT)) & I2C_CONSET_I2CEN_MASK)

#define I2C_CONSET_I2CIE_MASK                     (0x80)
#define I2C_CONSET_I2CIE_SHIFT                    (7)
#define I2C_CONSET_I2CIE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_I2CIE_SHIFT)) & I2C_CONSET_I2CIE_MASK)

#define I2C_CONSET_GCF_MASK                       (0x100)
#define I2C_CONSET_GCF_SHIFT                      (8)
#define I2C_CONSET_GCF_SET(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_GCF_SHIFT)) & I2C_CONSET_GCF_MASK)

#define I2C_CONSET_SSTAEN_MASK                    (0x200)
#define I2C_CONSET_SSTAEN_SHIFT                   (9)
#define I2C_CONSET_SSTAEN_SET(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_CONSET_SSTAEN_SHIFT)) & I2C_CONSET_SSTAEN_MASK)
/*! @} */

/*! @name I2CxCONCLR - I2Cx Configuration Register */
/*! @{ */
#define I2C_CONCLR_AAC_MASK                       (0x04)
#define I2C_CONCLR_AAC_SHIFT                      (2)
#define I2C_CONCLR_AAC_SET(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_CONCLR_AAC_SHIFT)) & I2C_CONCLR_AAC_MASK)

#define I2C_CONCLR_SIC_MASK                       (0x08)
#define I2C_CONCLR_SIC_SHIFT                      (3)
#define I2C_CONCLR_SIC_SET(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_CONCLR_SIC_SHIFT)) & I2C_CONCLR_SIC_MASK)

#define I2C_CONCLR_STOC_MASK                      (0x10)
#define I2C_CONCLR_STOC_SHIFT                     (4)
#define I2C_CONCLR_STOC_SET(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_CONCLR_STOC_SHIFT)) & I2C_CONCLR_STOC_MASK)

#define I2C_CONCLR_STAC_MASK                      (0x20)
#define I2C_CONCLR_STAC_SHIFT                     (5)
#define I2C_CONCLR_STAC_SET(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_CONCLR_STAC_SHIFT)) & I2C_CONCLR_STAC_MASK)

#define I2C_CONCLR_I2ENC_MASK                     (0x40)
#define I2C_CONCLR_I2ENC_SHIFT                    (6)
#define I2C_CONCLR_I2ENC_SET(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_CONCLR_I2ENC_SHIFT)) & I2C_CONCLR_I2ENC_MASK)

#define I2C_CONCLR_I2CIEC_MASK                    (0x80)
#define I2C_CONCLR_I2CIEC_SHIFT                   (7)
#define I2C_CONCLR_I2CIEC_SET(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_CONCLR_I2CIEC_SHIFT)) & I2C_CONCLR_I2CIEC_MASK)

/*! @} */

/*! @name I2CxSTAT - I2Cx Status Register */
/*! @{ */
#define I2C_STAT_STATUS_MASK                (0xF8)
#define I2C_STAT_STATUS_SHIFT               (3)
#define I2C_STAT_STATUS_SET(x)             (((uint32_t)(((uint32_t)(x)) << I2C_STAT_STATUS_SHIFT)) & I2C_STAT_STATUS_MASK)
/*! @} */

/*! @name I2CxDAT - I2Cx Data Register */
/*! @{ */
#define I2C_DAT_DATA_MASK                   (0xFF)
#define I2C_DAT_DATA_SHIFT                  (0)
#define I2C_DAT_DATA_SET(x)                (((uint32_t)(((uint32_t)(x)) << I2C_DAT_DATA_SHIFT)) & I2C_DAT_DATA_MASK)
/*! @} */

/*! @name I2CxCLK - I2Cx Clock Register */
/*! @{ */
#define I2C_CLK_N_MASK                   (0xF)
#define I2C_CLK_N_SHIFT                  (0)
#define I2C_CLK_N_SET(x)                (((uint32_t)(((uint32_t)(x)) << I2C_CLK_N_SHIFT)) & I2C_CLK_N_MASK)

#define I2C_CLK_M_MASK                  (0x70)
#define I2C_CLK_M_SHIFT                 (4)
#define I2C_CLK_M_SET(x)               (((uint32_t)(((uint32_t)(x)) << I2C_CLK_M_SHIFT)) & I2C_CLK_M_MASK)
/*! @} */

/*! @name I2CxADR0 - I2Cx Address Register */
/*! @{ */
#define I2C_ADR0_GC_MASK                (0x1)
#define I2C_ADR0_GC_SHIFT               (0)
#define I2C_ADR0_GC_SET(x)             (((uint32_t)(((uint32_t)(x)) << I2C_ADR0_GC_SHIFT)) & I2C_ADR0_GC_MASK)

#define I2C_ADR0_ADDR_MASK              (0xFE)
#define I2C_ADR0_ADDR_SHIFT             (1)
#define I2C_ADR0_ADDR_SET(x)            (((uint32_t)(((uint32_t)(x)) << I2C_ADR0_ADDR_SHIFT)) & I2C_ADR0_ADDR_MASK)

/*! @} */

/*! @name I2CxADRMASK0 - I2Cx Address Mask Register */
/*! @{ */
#define I2C_ADRMASK0_MASK_MASK        (0xFE)
#define I2C_ADRMASK0_MASK_SHIFT       (1)
#define I2C_ADRMASK0_MASK_SET(x)      (((uint32_t)(((uint32_t)(x)) << I2C_ADRMASK0_MASK_SHIFT)) & I2C_ADRMASK0_MASK_MASK)

/*! @} */

/*! @name I2CxXADR0 - I2Cx Extended Address Register */
/*! @{ */
#define I2C_XADR0_XADDR_MASK        (0xFE)
#define I2C_XADR0_XADDR_SHIFT       (1)
#define I2C_XADR0_XADDR_SET(x)      (((uint32_t)(((uint32_t)(x)) << I2C_XADR0_XADDR_SHIFT)) & I2C_XADR0_XADDR_MASK)

/*! @} */

/*! @name I2CxXADRMASK0 - I2Cx Extended Address Mask Register */
/*! @{ */
#define I2C_XADRMASK0_XADDR_MASK        (0xFE)
#define I2C_XADRMASK0_XADDR_SHIFT       (1)
#define I2C_XADRMASK0_XADDR_SET(x)      (((uint32_t)(((uint32_t)(x)) << I2C_XADRMASK0_XADDR_SHIFT)) & I2C_XADRMASK0_XADDR_MASK)

/*! @} */
/*! @name I2CxRST - I2Cx Reset Register */
/*! @{ */
#define I2C_RST_RST_MASK               (0xFF)
#define I2C_RST_RST_SHIFT              (0)
#define I2C_RST_RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << I2C_RST_RST_SHIFT)) & I2C_RST_RST_MASK

/*! @} */
/*! @name I2CxADR1 - I2Cx Address Register */
/*! @{ */
#define I2C_ADR1_GC_MASK                (0x1)
#define I2C_ADR1_GC_SHIFT               (0)
#define I2C_ADR1_GC_SET(x)             (((uint32_t)(((uint32_t)(x)) << I2C_ADR1_GC_SHIFT)) & I2C_ADR1_GC_MASK)

#define I2C_ADR1_ADDR_MASK              (0xFE)
#define I2C_ADR1_ADDR_SHIFT             (1)
#define I2C_ADR1_ADDR_SET(x)            (((uint32_t)(((uint32_t)(x)) << I2C_ADR1_ADDR_SHIFT)) & I2C_ADR1_ADDR_MASK)

/*! @} */

/*! @name I2CxADRMASK1 - I2Cx Address Mask Register */
/*! @{ */
#define I2C_ADRMASK1_MASK_MASK             (0xFE)
#define I2C_ADRMASK1_MASK_SHIFT            (1)
#define I2C_ADRMASK1_MASK_SET(x)           (((uint32_t)(((uint32_t)(x)) << I2C_ADRMASK1_MASK_SHIFT)) & I2C_ADRMASK1_MASK_MASK)

/*! @} */

/*! @name I2CxADR2 - I2Cx Address Register */
/*! @{ */
#define I2C_ADR2_GC_MASK                (0x1)
#define I2C_ADR2_GC_SHIFT               (0)
#define I2C_ADR2_GC_SET(x)             (((uint32_t)(((uint32_t)(x)) << I2C_ADR2_GC_SHIFT)) & I2C_ADR2_GC_MASK)

#define I2C_ADR2_ADDR_MASK              (0xFE)
#define I2C_ADR2_ADDR_SHIFT             (1)
#define I2C_ADR2_ADDR_SET(x)            (((uint32_t)(((uint32_t)(x)) << I2C_ADR2_ADDR_SHIFT)) & I2C_ADR2_ADDR_MASK)

/*! @} */
/*! @name I2CxADRMASK2 - I2Cx Address Mask Register */
/*! @{ */
#define I2C_ADRMASK2_MASK_MASK             (0xFE)
#define I2C_ADRMASK2_MASK_SHIFT            (1)
#define I2C_ADRMASK2_MASK_SET(x)           (((uint32_t)(((uint32_t)(x)) << I2C_ADRMASK2_MASK_SHIFT)) & I2C_ADRMASK2_MASK_MASK)

/*! @} */
/*! @name I2CxADR3 - I2Cx Address Register */
/*! @{ */
#define I2C_ADR3_GC_MASK                (0x1)
#define I2C_ADR3_GC_SHIFT               (0)
#define I2C_ADR3_GC_SET(x)             (((uint32_t)(((uint32_t)(x)) << I2C_ADR3_GC_SHIFT)) & I2C_ADR3_GC_MASK)

#define I2C_ADR3_ADDR_MASK              (0xFE)
#define I2C_ADR3_ADDR_SHIFT             (1)
#define I2C_ADR3_ADDR_SET(x)            (((uint32_t)(((uint32_t)(x)) << I2C_ADR3_ADDR_SHIFT)) & I2C_ADR3_ADDR_MASK)

/*! @} */
/*! @name I2CxADRMASK3 - I2Cx Address Mask Register */
/*! @{ */
#define I2C_ADRMASK3_MASK_MASK             (0xFE)
#define I2C_ADRMASK3_MASK_SHIFT            (1)
#define I2C_ADRMASK3_MASK_SET(x)           (((uint32_t)(((uint32_t)(x)) << I2C_ADRMASK3_MASK_SHIFT)) & I2C_ADRMASK3_MASK_MASK)

/*! @} */
/*!
 *  * @}
 *   */ /* end of group I2C_Register_Masks */

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C1 base address */
#define I2C1_BASE                                (0x40066000u)
/** Peripheral I2C1 base pointer */
#define I2C1                                     ((I2C_TypeDef *)I2C1_BASE)
/** Peripheral I2C2 base address */
#define I2C2_BASE                                (0x40067000u)
/** Peripheral I2C2 base pointer */
#define I2C2                                     ((I2C_TypeDef *)I2C2_BASE)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C1_BASE, I2C2_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C1, I2C2 }
/** Interrupt vectors for the I2C peripheral type */
#define I2C_IRQS                                 { I2C1_IRQn, I2C2_IRQn }


/*!
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
 *    -- XINT Peripheral Access Layer
 *       ---------------------------------------------------------------------------- */

/*!
 *  * @addtogroup XINT_Peripheral_Access_Layer XINT Peripheral Access Layer
 *   * @{
 *    */

/** XINT - Register Layout Typedef */
typedef struct {
  __IO uint32_t XINT1CR;
  __IO uint32_t XINT2CR;
  __IO uint32_t XINT3CR;
  __IO uint32_t XINT4CR;
  __IO uint32_t XINT5CR;
       uint32_t Reserved[3];
  __IO uint32_t XINT1CTR;
  __IO uint32_t XINT2CTR;
  __IO uint32_t XINT3CTR;
}XINT_TypeDef;

/* ----------------------------------------------------------------------------
 *    -- XINT Register Masks
 *       ---------------------------------------------------------------------------- */

/*!
 *  * @addtogroup XINT_Register_Masks XINT Register Masks
 *   * @{
 *    */

/*! @name XINTxCR - XINTx Configuration Register */
/*! @{ */
#define XINT_CR_ENABLE_MASK                      (1)
#define XINT_CR_ENABLE_SHIFT                     (0)
#define XINT_CR_ENABLE_SET(x)                        (((uint32_t)(((uint32_t)(x)) << XINT_CR_ENABLE_SHIFT)) & XINT_CR_ENABLE_MASK)

#define XINT_CR_POLARITY_MASK                    (0xc)
#define XINT_CR_POLARITY_SHIFT                   (2)
#define XINT_CR_POLARITY_SET(x)                      (((uint32_t)(((uint32_t)(x)) << XINT_CR_POLARITY_SHIFT)) & XINT_CR_POLARITY_MASK)

/*! @} */

/*!
 *  * @}
 *   */ /* end of group XINT_Register_Masks */


/* XINT - Peripheral instance base addresses */
/** Peripheral XINT base address */
#define XINT_BASE                                (0x4002E000u)
/** Peripheral XINT base pointer */
#define XINT                                     ((XINT_TypeDef *)XINT_BASE)
/** Array initializer of XINT peripheral base addresses */
#define XINT_BASE_ADDRS                          { XINT_BASE }
/** Array initializer of XINT peripheral base pointers */
#define XINT_BASE_PTRS                           { XINT }

/*!
 *  * @}
 *   */ /* end of group LMEM_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- XBAR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_Peripheral_Access_Layer XBAR Peripheral Access Layer
 * @{
 */

/** XBAR - Register Layout Typedef */
typedef struct {
  __IO uint32_t INPUT1SELECT; 
  __IO uint32_t INPUT2SELECT;
  __IO uint32_t INPUT3SELECT;
  __IO uint32_t INPUT4SELECT;
  __IO uint32_t INPUT5SELECT;
  __IO uint32_t INPUT6SELECT;
  __IO uint32_t INPUT7SELECT;
  __IO uint32_t INPUT8SELECT;
  __IO uint32_t INPUT9SELECT;
  __IO uint32_t INPUT10SELECT;
  __IO uint32_t INPUT11SELECT;
  __IO uint32_t INPUT12SELECT;
  __IO uint32_t INPUT13SELECT;
  __IO uint32_t INPUT14SELECT;
  __IO uint32_t INPUT15SELECT;
  __IO uint32_t INPUT16SELECT;
  __IO uint32_t INPUTSELECTLOCK;
  __IO uint32_t XBARFLG1;
  __IO uint32_t XBARFLG2;
  __IO uint32_t XBARFLG3;
  __IO uint32_t XBARFLG4;
  __IO uint32_t XBARCLR1;
  __IO uint32_t XBARCLR2;
  __IO uint32_t XBARCLR3;
  __IO uint32_t XBARCLR4;
  __IO uint32_t TRIP4MUX0TO15CFG;
  __IO uint32_t TRIP4MUX16TO31CFG;
  __IO uint32_t TRIP5MUX0TO15CFG;
  __IO uint32_t TRIP5MUX16TO31CFG;
  __IO uint32_t TRIP7MUX0TO15CFG;
  __IO uint32_t TRIP7MUX16TO31CFG;
  __IO uint32_t TRIP8MUX0TO15CFG;
  __IO uint32_t TRIP8MUX16TO31CFG;
  __IO uint32_t TRIP9MUX0TO15CFG;
  __IO uint32_t TRIP9MUX16TO31CFG;
  __IO uint32_t TRIP10MUX0TO15CFG;
  __IO uint32_t TRIP10MUX16TO31CFG;
  __IO uint32_t TRIP11MUX0TO15CFG;
  __IO uint32_t TRIP11MUX16TO31CFG;
  __IO uint32_t TRIP12MUX0TO15CFG;
  __IO uint32_t TRIP12MUX16TO31CFG;
  __IO uint32_t TRIP4MUXENABLE;
  __IO uint32_t TRIP5MUXENABLE;
  __IO uint32_t TRIP7MUXENABLE;
  __IO uint32_t TRIP8MUXENABLE;
  __IO uint32_t TRIP9MUXENABLE;
  __IO uint32_t TRIP10MUXENABLE;
  __IO uint32_t TRIP11MUXENABLE;
  __IO uint32_t TRIP12MUXENABLE;
  __IO uint32_t TRIPOUTINV; 
  __IO uint32_t TRIPLOCK;
  __IO uint32_t OUTPUT1MUX0TO15CFG;
  __IO uint32_t OUTPUT1MUX16TO32CFG;
  __IO uint32_t OUTPUT2MUX0TO15CFG;
  __IO uint32_t OUTPUT2MUX16TO32CFG;
  __IO uint32_t OUTPUT3MUX0TO15CFG;
  __IO uint32_t OUTPUT3MUX16TO32CFG;
  __IO uint32_t OUTPUT4MUX0TO15CFG;
  __IO uint32_t OUTPUT4MUX16TO32CFG;
  __IO uint32_t OUTPUT5MUX0TO15CFG;
  __IO uint32_t OUTPUT5MUX16TO32CFG;
  __IO uint32_t OUTPUT6MUX0TO15CFG;
  __IO uint32_t OUTPUT6MUX16TO32CFG;
  __IO uint32_t OUTPUT7MUX0TO15CFG;
  __IO uint32_t OUTPUT7MUX16TO32CFG;
  __IO uint32_t OUTPUT8MUX0TO15CFG;
  __IO uint32_t OUTPUT8MUX16TO32CFG;
  __IO uint32_t OUTPUT1MUXENABLE;
  __IO uint32_t OUTPUT2MUXENABLE;
  __IO uint32_t OUTPUT3MUXENABLE;
  __IO uint32_t OUTPUT4MUXENABLE;
  __IO uint32_t OUTPUT5MUXENABLE;
  __IO uint32_t OUTPUT6MUXENABLE;
  __IO uint32_t OUTPUT7MUXENABLE;
  __IO uint32_t OUTPUT8MUXENABLE;
  __IO uint32_t OUTPUTLATCH;
  __IO uint32_t OUTPUTLATCHCLR;
  __IO uint32_t OUTPUTLATCHFRC;
  __IO uint32_t OUTPUTLATCHENABLE;
  __IO uint32_t OUTPUTINV;
  __IO uint32_t OUTPUTLOCK;
} XBAR_TypeDef;

/* ----------------------------------------------------------------------------
   -- XBAR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_Register_Masks XBAR Register Masks
 * @{
 */

/*! @name INPUTxSELECT - Input Select Register */
/*! @{ */
#define XBAR_INPUTxSELECT_SELECT_MASK    0xFFFF
/*! @} */

/*! @name INPUTSELECTLOCK - Input Select Lock Register */
/*! @{ */
#define XBAR_INPUTSELECTLOCK_INPUT1SELECT_MASK  (0x0001)

#define XBAR_INPUTSELECTLOCK_INPUT2SELECT_MASK  (0x0002)

#define XBAR_INPUTSELECTLOCK_INPUT3SELECT_MASK  (0x0004)

#define XBAR_INPUTSELECTLOCK_INPUT4SELECT_MASK  (0x0008)

#define XBAR_INPUTSELECTLOCK_INPUT5SELECT_MASK  (0x0010)

#define XBAR_INPUTSELECTLOCK_INPUT6SELECT_MASK  (0x0020)

#define XBAR_INPUTSELECTLOCK_INPUT7SELECT_MASK  (0x0040)

#define XBAR_INPUTSELECTLOCK_INPUT8SELECT_MASK  (0x0080)

#define XBAR_INPUTSELECTLOCK_INPUT9SELECT_MASK  (0x0100)

#define XBAR_INPUTSELECTLOCK_INPUT10SELECT_MASK (0x0200)

#define XBAR_INPUTSELECTLOCK_INPUT11SELECT_MASK (0x0400)

#define XBAR_INPUTSELECTLOCK_INPUT12SELECT_MASK (0x0800)

#define XBAR_INPUTSELECTLOCK_INPUT13SELECT_MASK (0x1000)

#define XBAR_INPUTSELECTLOCK_INPUT14SELECT_MASK (0x2000)

#define XBAR_INPUTSELECTLOCK_INPUT15SELECT_MASK (0x4000)

#define XBAR_INPUTSELECTLOCK_INPUT16SELECT_MASK (0x8000)

/*! @} */

/*! @name XBARFLG1 - XBAR Input Flag Register 1 */
/*! @{ */

/*! @} */

/*! @name XBARFLG2 - XBAR Input Flag Register 2 */
/*! @{ */
#define XBAR_XBARFLG2_INPUT1_MASK  (0x1)

#define XBAR_XBARFLG2_INPUT2_MASK  (0x2)

#define XBAR_XBARFLG3_INPUT1_MASK  (0x4)

#define XBAR_XBARFLG4_INPUT1_MASK  (0x8)

#define XBAR_XBARFLG5_INPUT1_MASK  (0x10)

#define XBAR_XBARFLG6_INPUT1_MASK  (0x20)

#define XBAR_XBARFLG7_INPUT1_MASK  (0x40)

#define XBAR_XBARFLG8_INPUT1_MASK  (0x80)

#define XBAR_XBARFLG9_INPUT1_MASK  (0x100)

#define XBAR_XBARFLG10_INPUT1_MASK  (0x200)

#define XBAR_XBARFLG11_INPUT1_MASK  (0x400)

#define XBAR_XBARFLG12_INPUT1_MASK  (0x800)

#define XBAR_XBARFLG13_INPUT1_MASK  (0x1000)

#define XBAR_XBARFLG14_INPUT1_MASK  (0x2000)

#define XBAR_XBARFLG15_INPUT1_MASK  (0x4000)

#define XBAR_XBARFLG16_INPUT1_MASK  (0x8000)

#define XBAR_XBARFLG2__ECAP1OUT_MASK  (0x10000)

#define XBAR_XBARFLG2__ECAP2OUT_MASK  (0x20000)

#define XBAR_XBARFLG2__ECAP3OUT_MASK  (0x30000)

#define XBAR_XBARFLG2_EXTSYNCOUT__MASK  (0x400000)

#define XBAR_XBARFLG2_ADCAEVT1_MASK  (0x800000)

#define XBAR_XBARFLG2_ADCAEVT2_MASK  (0x1000000)

#define XBAR_XBARFLG2_ADCAEVT3_MASK  (0x2000000)

#define XBAR_XBARFLG2_ADCAEVT4_MASK  (0x4000000)

#define XBAR_XBARFLG2_ADCBEVT1_MASK  (0x8000000)

#define XBAR_XBARFLG2_ADCBEVT2_MASK  (0x10000000)

#define XBAR_XBARFLG2_ADCBEVT3_MASK  (0x20000000)

#define XBAR_XBARFLG2_ADCBEVT4_MASK  (0x40000000)

#define XBAR_XBARFLG2_ADCCEVT1_MASK  (0x80000000)


/*! @} */

/*! @name XBARFLG3 - XBAR Input Flag Register 3 */
/*! @{ */

#define XBAR_XBARFLG3_ADCCEVT2_MASK       (0x1)

#define XBAR_XBARFLG3_ADCCEVT3_MASK       (0x2)

#define XBAR_XBARFLG3_ADCCEVT4_MASK       (0x4)

#define XBAR_XBARFLG3_SD1FLT1_COMPL_MASK  (0x80)

#define XBAR_XBARFLG3_SD1FLT1_COMPH_MASK  (0x100)

#define XBAR_XBARFLG3_SD1FLT2_COMPL_MASK  (0x200)

#define XBAR_XBARFLG3_SD1FLT2_COMPH_MASK  (0x400)

#define XBAR_XBARFLG3_SD1FLT3_COMPL_MASK  (0x800)

#define XBAR_XBARFLG3_SD1FLT3_COMPH_MASK  (0x1000)

#define XBAR_XBARFLG3_SD1FLT4_COMPL_MASK  (0x2000)

#define XBAR_XBARFLG3_SD1FLT4_COMPH_MASK  (0x4000)

#define XBAR_XBARFLG3_SD2FLT1_COMPL_MASK  (0x8000)

#define XBAR_XBARFLG3_SD2FLT1_COMPH_MASK  (0x10000)

#define XBAR_XBARFLG3_SD2FLT2_COMPL_MASK  (0x20000)

#define XBAR_XBARFLG3_SD2FLT2_COMPH_MASK  (0x40000)

#define XBAR_XBARFLG3_SD2FLT3_COMPL_MASK  (0x80000)

#define XBAR_XBARFLG3_SD2FLT3_COMPH_MASK  (0x100000)

#define XBAR_XBARFLG3_SD2FLT4_COMPL_MASK  (0x200000)

#define XBAR_XBARFLG3_SD2FLT4_COMPH_MASK  (0x400000)

#define XBAR_XBARFLG3_SD1FLT1_COMPZ_MASK  (0x1000000)

#define XBAR_XBARFLG3_SD1FLT1_DRINT_MASK  (0x2000000)

#define XBAR_XBARFLG3_SD1FLT2_COMPZ_MASK  (0x4000000)

#define XBAR_XBARFLG3_SD1FLT2_DRINT_MASK  (0x8000000)

#define XBAR_XBARFLG3_SD1FLT3_COMPZ_MASK  (0x10000000)

#define XBAR_XBARFLG3_SD1FLT3_DRINT_MASK  (0x20000000)

#define XBAR_XBARFLG3_SD1FLT4_COMPZ_MASK  (0x40000000)

#define XBAR_XBARFLG3_SD1FLT4_DRINT_MASK  (0x80000000)

/*! @} */

/*! @name XBARFLG4 - XBAR Input Flag Register 4 */
/*! @{ */
#define XBAR_XBARFLG3_SD2FLT1_COMPZ_MASK  (0x1)

#define XBAR_XBARFLG3_SD2FLT1_DRINT_MASK  (0x2)

#define XBAR_XBARFLG3_SD2FLT2_COMPZ_MASK  (0x4)

#define XBAR_XBARFLG3_SD2FLT2_DRINT_MASK  (0x8)

#define XBAR_XBARFLG3_SD2FLT3_COMPZ_MASK  (0x10)

#define XBAR_XBARFLG3_SD2FLT3_DRINT_MASK  (0x20)

#define XBAR_XBARFLG3_SD2FLT4_COMPZ_MASK  (0x40)

#define XBAR_XBARFLG3_SD2FLT4_DRINT_MASK  (0x80)

#define XBAR_XBARFLG3_CAN_FEVT_MASK       (0x200)

#define XBAR_XBARFLG3_ERRORSTS_MASK       (0x10000000)
/*! @} */

/*! @name XBARCLR1 - XBAR Input Flag Clear Register 1 */
/*! @{ */

/*! @} */

/*! @name XBARCLR2 - XBAR Input Flag Clear Register 2 */
/*! @{ */

/*! @} */

/*! @name XBARCLR3 - XBAR Input Flag Clear Register 3 */
/*! @{ */

/*! @} */

/*! @name XBARCLR4 - XBAR Input Flag Clear Register 4 */
/*! @{ */

/*! @} */

/*! @name TRIPxMUX0TO15CFG - ePWM XBAR Mux Configration for TRIP4 Register */
/*! @{ */
#define XBAR_TRIPMUXCFG_MUX0_MASK  (0x3)
#define XBAR_TRIPMUXCFG_MUX0_SHIFT (0)
 
#define XBAR_TRIPMUXCFG_MUX1_MASK  (0xC)
#define XBAR_TRIPMUXCFG_MUX1_SHIFT (2) 

#define XBAR_TRIPMUXCFG_MUX2_MASK  (0x30)
#define XBAR_TRIPMUXCFG_MUX2_SHIFT (4) 

#define XBAR_TRIPMUXCFG_MUX3_MASK  (0xC0)
#define XBAR_TRIPMUXCFG_MUX3_SHIFT (6) 

#define XBAR_TRIPMUXCFG_MUX4_MASK  (0x300)
#define XBAR_TRIPMUXCFG_MUX4_SHIFT (8) 

#define XBAR_TRIPMUXCFG_MUX5_MASK  (0xC00)
#define XBAR_TRIPMUXCFG_MUX5_SHIFT (10) 

#define XBAR_TRIPMUXCFG_MUX6_MASK  (0x3000)
#define XBAR_TRIPMUXCFG_MUX6_SHIFT (12) 

#define XBAR_TRIPMUXCFG_MUX7_MASK  (0xC000)
#define XBAR_TRIPMUXCFG_MUX7_SHIFT (14) 

#define XBAR_TRIPMUXCFG_MUX8_MASK  (0x30000)
#define XBAR_TRIPMUXCFG_MUX8_SHIFT (16) 

#define XBAR_TRIPMUXCFG_MUX9_MASK  (0xC0000)
#define XBAR_TRIPMUXCFG_MUX9_SHIFT (18) 

#define XBAR_TRIPMUXCFG_MUX10_MASK  (0x300000)
#define XBAR_TRIPMUXCFG_MUX10_SHIFT (20) 

#define XBAR_TRIPMUXCFG_MUX11_MASK  (0xC00000)
#define XBAR_TRIPMUXCFG_MUX11_SHIFT (22) 

#define XBAR_TRIPMUXCFG_MUX12_MASK  (0x3000000)
#define XBAR_TRIPMUXCFG_MUX12_SHIFT (24) 

#define XBAR_TRIPMUXCFG_MUX13_MASK  (0xC000000)
#define XBAR_TRIPMUXCFG_MUX13_SHIFT (26) 

#define XBAR_TRIPMUXCFG_MUX14_MASK  (0x30000000)
#define XBAR_TRIPMUXCFG_MUX14_SHIFT (28) 

#define XBAR_TRIPMUXCFG_MUX15_MASK  (0xC0000000)
#define XBAR_TRIPMUXCFG_MUX15_SHIFT (30)


/*! @} */

/*! @name TRIPxMUX16TO31CFG - ePWM XBAR Mux Configration for TRIP4 Register */
/*! @{ */
#define XBAR_TRIPMUXCFG_MUX16_MASK  (0x3)
#define XBAR_TRIPMUXCFG_MUX16_SHIFT (0)
 
#define XBAR_TRIPMUXCFG_MUX17_MASK  (0xC)
#define XBAR_TRIPMUXCFG_MUX17_SHIFT (2) 

#define XBAR_TRIPMUXCFG_MUX18_MASK  (0x30)
#define XBAR_TRIPMUXCFG_MUX18_SHIFT (4) 

#define XBAR_TRIPMUXCFG_MUX19_MASK  (0xC0)
#define XBAR_TRIPMUXCFG_MUX19_SHIFT (6) 

#define XBAR_TRIPMUXCFG_MUX20_MASK  (0x300)
#define XBAR_TRIPMUXCFG_MUX20_SHIFT (8) 

#define XBAR_TRIPMUXCFG_MUX21_MASK  (0xC00)
#define XBAR_TRIPMUXCFG_MUX21_SHIFT (10) 

#define XBAR_TRIPMUXCFG_MUX22_MASK  (0x3000)
#define XBAR_TRIPMUXCFG_MUX22_SHIFT (12) 

#define XBAR_TRIPMUXCFG_MUX23_MASK  (0xC000)
#define XBAR_TRIPMUXCFG_MUX23_SHIFT (14) 

#define XBAR_TRIPMUXCFG_MUX24_MASK  (0x30000)
#define XBAR_TRIPMUXCFG_MUX24_SHIFT (16) 

#define XBAR_TRIPMUXCFG_MUX25_MASK  (0xC0000)
#define XBAR_TRIPMUXCFG_MUX25_SHIFT (18) 

#define XBAR_TRIPMUXCFG_MUX26_MASK  (0x300000)
#define XBAR_TRIPMUXCFG_MUX26_SHIFT (20) 

#define XBAR_TRIPMUXCFG_MUX27_MASK  (0xC00000)
#define XBAR_TRIPMUXCFG_MUX27_SHIFT (22) 

#define XBAR_TRIPMUXCFG_MUX28_MASK  (0x3000000)
#define XBAR_TRIPMUXCFG_MUX28_SHIFT (24) 

#define XBAR_TRIPMUXCFG_MUX29_MASK  (0xC000000)
#define XBAR_TRIPMUXCFG_MUX29_SHIFT (26) 

#define XBAR_TRIPMUXCFG_MUX30_MASK  (0x30000000)
#define XBAR_TRIPMUXCFG_MUX30_SHIFT (28) 

#define XBAR_TRIPMUXCFG_MUX31_MASK  (0xC0000000)
#define XBAR_TRIPMUXCFG_MUX31_SHIFT (30)


/*! @} */

/*! @name TRIPMUXENABLE - ePWM XBAR Mux Enable for Trip Register */
/*! @{ */
#define XBAR_TRIPMUXENABLE_MUX0_MASK  (0x1)
                                             
#define XBAR_TRIPMUXENABLE_MUX1_MASK  (0x2)   
                                             
#define XBAR_TRIPMUXENABLE_MUX2_MASK  (0x4)   
                                             
#define XBAR_TRIPMUXENABLE_MUX3_MASK  (0x8)  

#define XBAR_TRIPMUXENABLE_MUX4_MASK  (0x10) 

#define XBAR_TRIPMUXENABLE_MUX5_MASK  (0x20)

#define XBAR_TRIPMUXENABLE_MUX6_MASK  (0x40)

#define XBAR_TRIPMUXENABLE_MUX7_MASK  (0x80) 

#define XBAR_TRIPMUXENABLE_MUX8_MASK  (0x100)       
                                                   
#define XBAR_TRIPMUXENABLE_MUX9_MASK  (0x200)       
                                                   
#define XBAR_TRIPMUXENABLE_MUX10_MASK (0x400)        
                                                   
#define XBAR_TRIPMUXENABLE_MUX11_MASK (0x800)        
                                                   
#define XBAR_TRIPMUXENABLE_MUX12_MASK (0x1000)       
                                                   
#define XBAR_TRIPMUXENABLE_MUX13_MASK (0x2000)       
                                                   
#define XBAR_TRIPMUXENABLE_MUX14_MASK (0x4000)       
                                                   
#define XBAR_TRIPMUXENABLE_MUX15_MASK (0x8000)       
                                                   
#define XBAR_TRIPMUXENABLE_MUX16_MASK (0x10000)      
                                                   
#define XBAR_TRIPMUXENABLE_MUX17_MASK (0x20000)      
                                                   
#define XBAR_TRIPMUXENABLE_MUX18_MASK (0x40000)      
                                                   
#define XBAR_TRIPMUXENABLE_MUX19_MASK (0x80000)      
                                                   
#define XBAR_TRIPMUXENABLE_MUX20_MASK (0x100000)     
                                                   
#define XBAR_TRIPMUXENABLE_MUX21_MASK (0x200000)     
                                                   
#define XBAR_TRIPMUXENABLE_MUX22_MASK (0x400000)     
                                                   
#define XBAR_TRIPMUXENABLE_MUX23_MASK (0x800000)  
                                      
#define XBAR_TRIPMUXENABLE_MUX24_MASK (0x1000000)   
                                                   
#define XBAR_TRIPMUXENABLE_MUX25_MASK (0x2000000)    
                                                   
#define XBAR_TRIPMUXENABLE_MUX26_MASK (0x4000000)    
                                                   
#define XBAR_TRIPMUXENABLE_MUX27_MASK (0x8000000)    
                                                   
#define XBAR_TRIPMUXENABLE_MUX28_MASK (0x10000000)   
                                                   
#define XBAR_TRIPMUXENABLE_MUX29_MASK (0x20000000)   
                                                   
#define XBAR_TRIPMUXENABLE_MUX30_MASK (0x40000000)   
                                                   
#define XBAR_TRIPMUXENABLE_MUX31_MASK (0x80000000)  

/*! @} */

/*! @name TRIPOUTINV - ePWM XBAR Output Inversion Register */
/*! @{ */

#define XBAR_TRIPOUTINV_TRIP4_MASK  (0x1)

#define XBAR_TRIPOUTINV_TRIP5_MASK  (0x2)

#define XBAR_TRIPOUTINV_TRIP7_MASK  (0x4)

#define XBAR_TRIPOUTINV_TRIP8_MASK  (0x8)

#define XBAR_TRIPOUTINV_TRIP9_MASK  (0x10)

#define XBAR_TRIPOUTINV_TRIP10_MASK  (0x20)

#define XBAR_TRIPOUTINV_TRIP11_MASK  (0x40)

#define XBAR_TRIPOUTINV_TRIP12_MASK  (0x80)

/*! @} */

/*! @name TRIPLOCK - ePWM XBAR Configuration Register */
/*! @{ */
#define XBAR_TRIPLOCK_LOCK_MASK   (0x1)

#define XBAR_TRIPLOCK_KEY_MASK    (0xFFFF0000)
/*! @} */

/*! @name OUTPUTxMUX0TO15CFG - Output XBAR Configuration Register */
/*! @{ */
#define XBAR_OUTPUTMUXCFG_MUX0_MASK  (0x3)
#define XBAR_OUTPUTMUXCFG_MUX0_SHIFT (0)

#define XBAR_OUTPUTMUXCFG_MUX1_MASK  (0xC)
#define XBAR_OUTPUTMUXCFG_MUX1_SHIFT (2)

#define XBAR_OUTPUTMUXCFG_MUX2_MASK  (0x30)
#define XBAR_OUTPUTMUXCFG_MUX2_SHIFT (4)

#define XBAR_OUTPUTMUXCFG_MUX3_MASK  (0xC0)
#define XBAR_OUTPUTMUXCFG_MUX3_SHIFT (6)

#define XBAR_OUTPUTMUXCFG_MUX4_MASK  (0x300)
#define XBAR_OUTPUTMUXCFG_MUX4_SHIFT (8)

#define XBAR_OUTPUTMUXCFG_MUX5_MASK  (0xC00)
#define XBAR_OUTPUTMUXCFG_MUX5_SHIFT (10)

#define XBAR_OUTPUTMUXCFG_MUX6_MASK  (0x3000)
#define XBAR_OUTPUTMUXCFG_MUX6_SHIFT (12)

#define XBAR_OUTPUTMUXCFG_MUX7_MASK  (0xC000)
#define XBAR_OUTPUTMUXCFG_MUX7_SHIFT (14)

#define XBAR_OUTPUTMUXCFG_MUX8_MASK  (0x30000)
#define XBAR_OUTPUTMUXCFG_MUX8_SHIFT (16)

#define XBAR_OUTPUTMUXCFG_MUX9_MASK  (0xC0000)
#define XBAR_OUTPUTMUXCFG_MUX9_SHIFT (18)

#define XBAR_OUTPUTMUXCFG_MUX10_MASK  (0x300000)
#define XBAR_OUTPUTMUXCFG_MUX10_SHIFT (20)

#define XBAR_OUTPUTMUXCFG_MUX11_MASK  (0xC00000)
#define XBAR_OUTPUTMUXCFG_MUX11_SHIFT (22)

#define XBAR_OUTPUTMUXCFG_MUX12_MASK  (0x3000000)
#define XBAR_OUTPUTMUXCFG_MUX12_SHIFT (24)

#define XBAR_OUTPUTMUXCFG_MUX13_MASK  (0xC000000)
#define XBAR_OUTPUTMUXCFG_MUX13_SHIFT (26)

#define XBAR_OUTPUTMUXCFG_MUX14_MASK  (0x30000000)
#define XBAR_OUTPUTMUXCFG_MUX14_SHIFT (28)

#define XBAR_OUTPUTMUXCFG_MUX15_MASK  (0xC0000000)
#define XBAR_OUTPUTMUXCFG_MUX15_SHIFT (30)

/*! @} */

/*! @name OUTPUTxMUX16TO31CFG - Output XBAR Configuration Register */
/*! @{ */
#define XBAR_OUTPUTMUXCFG_MUX16_MASK  (0x3)
#define XBAR_OUTPUTMUXCFG_MUX16_SHIFT (0)

#define XBAR_OUTPUTMUXCFG_MUX17_MASK  (0xC)
#define XBAR_OUTPUTMUXCFG_MUX17_SHIFT (2)

#define XBAR_OUTPUTMUXCFG_MUX18_MASK  (0x30)
#define XBAR_OUTPUTMUXCFG_MUX18_SHIFT (4)

#define XBAR_OUTPUTMUXCFG_MUX19_MASK  (0xC0)
#define XBAR_OUTPUTMUXCFG_MUX19_SHIFT (6)

#define XBAR_OUTPUTMUXCFG_MUX20_MASK  (0x300)
#define XBAR_OUTPUTMUXCFG_MUX20_SHIFT (8)

#define XBAR_OUTPUTMUXCFG_MUX21_MASK  (0xC00)
#define XBAR_OUTPUTMUXCFG_MUX21_SHIFT (10)

#define XBAR_OUTPUTMUXCFG_MUX22_MASK  (0x3000)
#define XBAR_OUTPUTMUXCFG_MUX22_SHIFT (12)

#define XBAR_OUTPUTMUXCFG_MUX23_MASK  (0xC000)
#define XBAR_OUTPUTMUXCFG_MUX23_SHIFT (14)

#define XBAR_OUTPUTMUXCFG_MUX24_MASK  (0x30000)
#define XBAR_OUTPUTMUXCFG_MUX24_SHIFT (16)

#define XBAR_OUTPUTMUXCFG_MUX25_MASK  (0xC0000)
#define XBAR_OUTPUTMUXCFG_MUX25_SHIFT (18)

#define XBAR_OUTPUTMUXCFG_MUX26_MASK  (0x300000)
#define XBAR_OUTPUTMUXCFG_MUX26_SHIFT (20)

#define XBAR_OUTPUTMUXCFG_MUX27_MASK  (0xC00000)
#define XBAR_OUTPUTMUXCFG_MUX27_SHIFT (22)

#define XBAR_OUTPUTMUXCFG_MUX28_MASK  (0x3000000)
#define XBAR_OUTPUTMUXCFG_MUX28_SHIFT (24)

#define XBAR_OUTPUTMUXCFG_MUX29_MASK  (0xC000000)
#define XBAR_OUTPUTMUXCFG_MUX29_SHIFT (26)

#define XBAR_OUTPUTMUXCFG_MUX30_MASK  (0x30000000)
#define XBAR_OUTPUTMUXCFG_MUX30_SHIFT (28)

#define XBAR_OUTPUTMUXCFG_MUX31_MASK  (0xC0000000)
#define XBAR_OUTPUTMUXCFG_MUX31_SHIFT (30)
/*! @} */

/*! @name OUTPUTxMUXENABLE - Output XBAR Mux Enable Register */
/*! @{ */
#define XBAR_OUTPUTMUXENABLE_MUX0_MASK  (0x1)

#define XBAR_OUTPUTMUXENABLE_MUX1_MASK  (0x2)

#define XBAR_OUTPUTMUXENABLE_MUX2_MASK  (0x4)

#define XBAR_OUTPUTMUXENABLE_MUX3_MASK  (0x8)

#define XBAR_OUTPUTMUXENABLE_MUX4_MASK  (0x10)

#define XBAR_OUTPUTMUXENABLE_MUX5_MASK  (0x20)

#define XBAR_OUTPUTMUXENABLE_MUX6_MASK  (0x40)

#define XBAR_OUTPUTMUXENABLE_MUX7_MASK  (0x80)

#define XBAR_OUTPUTMUXENABLE_MUX8_MASK  (0x100)

#define XBAR_OUTPUTMUXENABLE_MUX9_MASK  (0x200)

#define XBAR_OUTPUTMUXENABLE_MUX10_MASK (0x400)

#define XBAR_OUTPUTMUXENABLE_MUX11_MASK (0x800)

#define XBAR_OUTPUTMUXENABLE_MUX12_MASK (0x1000)

#define XBAR_OUTPUTMUXENABLE_MUX13_MASK (0x2000)

#define XBAR_OUTPUTMUXENABLE_MUX14_MASK (0x4000)

#define XBAR_OUTPUTMUXENABLE_MUX15_MASK (0x8000)

#define XBAR_OUTPUTMUXENABLE_MUX16_MASK (0x10000)

#define XBAR_OUTPUTMUXENABLE_MUX17_MASK (0x20000)

#define XBAR_OUTPUTMUXENABLE_MUX18_MASK (0x40000)

#define XBAR_OUTPUTMUXENABLE_MUX19_MASK (0x80000)

#define XBAR_OUTPUTMUXENABLE_MUX20_MASK (0x100000)

#define XBAR_OUTPUTMUXENABLE_MUX21_MASK (0x200000)

#define XBAR_OUTPUTMUXENABLE_MUX22_MASK (0x400000)

#define XBAR_OUTPUTMUXENABLE_MUX23_MASK (0x800000)

#define XBAR_OUTPUTMUXENABLE_MUX24_MASK (0x1000000)

#define XBAR_OUTPUTMUXENABLE_MUX25_MASK (0x2000000)

#define XBAR_OUTPUTMUXENABLE_MUX26_MASK (0x4000000)

#define XBAR_OUTPUTMUXENABLE_MUX27_MASK (0x8000000)

#define XBAR_OUTPUTMUXENABLE_MUX28_MASK (0x10000000)

#define XBAR_OUTPUTMUXENABLE_MUX29_MASK (0x20000000)

#define XBAR_OUTPUTMUXENABLE_MUX30_MASK (0x40000000)

#define XBAR_OUTPUTMUXENABLE_MUX31_MASK (0x80000000)

/*! @} */

/*! @name OUTPUTLATCH/OUTPUTLATCHCLR/OUTPUTLATCHFRC/OUTPUTLATCHENABLE - OUTPUT XBAR LATCH Register */
/*! @{ */
#define XBAR_OUTPUTLATCH_OUTPUT1_MASK  (1)

#define XBAR_OUTPUTLATCH_OUTPUT2_MASK  (2)

#define XBAR_OUTPUTLATCH_OUTPUT3_MASK  (4)

#define XBAR_OUTPUTLATCH_OUTPUT4_MASK  (8)

#define XBAR_OUTPUTLATCH_OUTPUT5_MASK  (0x10)

#define XBAR_OUTPUTLATCH_OUTPUT6_MASK  (0x20)

#define XBAR_OUTPUTLATCH_OUTPUT7_MASK  (0x30)

#define XBAR_OUTPUTLATCH_OUTPUT8_MASK  (0x40)

/*! @} */

/*! @name OUTPUTINV - OUTPUT XBAR Inversion Register */
/*! @{ */
#define XBAR_OUTPUTINV_OUTPUT1_MASK  (1)

#define XBAR_OUTPUTINV_OUTPUT2_MASK  (2)

#define XBAR_OUTPUTINV_OUTPUT3_MASK  (4)

#define XBAR_OUTPUTINV_OUTPUT4_MASK  (8)

#define XBAR_OUTPUTINV_OUTPUT5_MASK  (0x10)

#define XBAR_OUTPUTINV_OUTPUT6_MASK  (0x20)

#define XBAR_OUTPUTINV_OUTPUT7_MASK  (0x30)

#define XBAR_OUTPUTINV_OUTPUT8_MASK  (0x40)
/*! @} */

/*! @name OUTPUTLOCK - OUTPUT XBAR LOCK Register */
/*! @{ */
#define XBAR_OUTPUTLOCK_LOCK_MASK   (0x1)

#define XBAR_OUTPUTLOCK_KEY_MASK    (0xFFFF0000)

/*! @} */

/*!
 * @}
 */ /* end of group XBAR_Register_Masks */


/* XBAR - Peripheral instance base addresses */
#define XBAR_BASE                             (0x40028000u)
#define INPUTXBAR_BASE                        (0x40028000u)
#define EPWMXBAR_BASE                         (0x40028064u)  
#define OUTPUTXBAR_BASE                       (0x400280ccu)
/** Peripheral XBAR base pointer */
#define XBAR                                  ((XBAR_TypeDef *)XBAR_BASE)

/** Array initializer of XBAR peripheral base addresses */
#define XBAR_BASE_ADDRS                        { XBAR_BASE }
/** Array initializer of XBAR peripheral base pointers */
#define XBAR_BASE_PTRS                         { XBAR }
/** Interrupt vectors for the XBAR peripheral type */
#define XBAR_IRQS                              { XINT1_IRQn, XINT2_IRQn, XINT3_IRQn, XINT4_IRQn, XINT5_IRQn }



/* ----------------------------------------------------------------------------
   -- SCI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCI_Peripheral_Access_Layer SCI Peripheral Access Layer
 * @{
 */

/** SCI - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCICNFG;                              /**< SCI Baud Rate Register, offset: 0x0 */
  __IO uint32_t SCISTATUS;                            /**< SCI Status Register, offset: 0x4 */
  __IO uint32_t SCICTRL;                              /**< SCI Control Register, offset: 0x8 */
  __IO uint32_t SCIDATA;                              /**< SCI Data Register, offset: 0xC */
  __IO uint32_t SCIMATCH;                             /**< SCI Match Address Register, offset: 0x10 */
  __IO uint32_t SCIRSIR;                              /**< SCI Modem IrDA Register, offset: 0x14 */
  __IO uint32_t SCIFCTL;                              /**< SCI FIFO Register, 0ffset: 0x18 */
  __IO uint32_t SCIWATMK;                             /**< SCI WATER Register, 0ffset: 0x1C */
} SCI_TypeDef;

/* ----------------------------------------------------------------------------
   -- SCI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCI_Register_Masks SCI Register Masks
 * @{
 */

/*! @name CNFG - SCI Baud Rate Register */
/*! @{ */

#define SCI_CNFG_BRD_MASK                     (0x1FFFU)
#define SCI_CNFG_BRD_SHIFT                    (0U)
/*! SBR - Baud Rate Modulo Divisor.
 */
#define SCI_CNFG_BRD_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_BRD_SHIFT)) & SCI_CNFG_BRD_MASK)

#define SCI_CNFG_SBS_MASK                     (0x2000U)
#define SCI_CNFG_SBS_SHIFT                    (13U)
/*! SBS - Stop Bit Number Select
 *  0b0..One stop bit.
 *  0b1..Two stop bits.
 */
#define SCI_CNFG_SBS_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_SBS_SHIFT)) & SCI_CNFG_SBS_MASK)

#define SCI_CNFG_RXEDGIE_MASK                 (0x4000U)
#define SCI_CNFG_RXEDGIE_SHIFT                (14U)
/*! RXEDGIE - RX Input Active Edge Interrupt Enable
 *  0b0..Hardware interrupts from SCI_STATUS[RXEDGIF] disabled (use polling).
 *  0b1..Hardware interrupt requested when SCI_STATUS[RXEDGIF] flag is 1.
 */
#define SCI_CNFG_RXEDGIE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_RXEDGIE_SHIFT)) & SCI_CNFG_RXEDGIE_MASK)

#define SCI_CNFG_LBDIE_MASK                  (0x8000U)
#define SCI_CNFG_LBDIE_SHIFT                 (15U)
/*! LBDIE - LIN Break Detect Interrupt Enable
 *  0b0..Hardware interrupts from SCI_STATUS[LBKDIF] disabled (use polling).
 *  0b1..Hardware interrupt requested when SCI_STATUS[LBKDIF] flag is 1.
 */
#define SCI_CNFG_LBDIE_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_LBDIE_SHIFT)) & SCI_CNFG_LBDIE_MASK)

#define SCI_CNFG_TWOEDGE_MASK                (0x20000U)
#define SCI_CNFG_TWOEDGE_SHIFT               (17U)
/*! TWOEDGE - Both Edge Sampling
 *  0b0..Receiver samples input data using the rising edge of the baud rate clock.
 *  0b1..Receiver samples input data using the rising and falling edge of the baud rate clock.
 */
#define SCI_CNFG_TWOEDGE_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_TWOEDGE_SHIFT)) & SCI_CNFG_TWOEDGE_MASK)

#define SCI_CNFG_MCFG_MASK                  (0xC0000U)
#define SCI_CNFG_MCFG_SHIFT                 (18U)
/*! MCFG - Match Configuration
 *  0b00..Address Match Wakeup
 *  0b01..Idle Match Wakeup
 *  0b10..Match On and Match Off
 *  0b11..Enables RWU on Data Match and Match On/Off for transmitter CTS input
 */
#define SCI_CNFG_MCFG_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_MCFG_SHIFT)) & SCI_CNFG_MCFG_MASK)

#define SCI_CNFG_RDMAEN_MASK                   (0x200000U)
#define SCI_CNFG_RDMAEN_SHIFT                  (21U)
/*! RDMAEN - Receiver Full DMA Enable
 *  0b0..DMA request disabled.
 *  0b1..DMA request enabled.
 */
#define SCI_CNFG_RDMAEN_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_RDMAEN_SHIFT)) & SCI_CNFG_RDMAEN_MASK)

#define SCI_CNFG_TDMAEN_MASK                   (0x800000U)
#define SCI_CNFG_TDMAEN_SHIFT                  (23U)
/*! TDMAEN - Transmitter DMA Enable
 *  0b0..DMA request disabled.
 *  0b1..DMA request enabled.
 */
#define SCI_CNFG_TDMAEN_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_TDMAEN_SHIFT)) & SCI_CNFG_TDMAEN_MASK)

#define SCI_CNFG_OSR_MASK                     (0x1F000000U)
#define SCI_CNFG_OSR_SHIFT                    (24U)
/*! OSR - Over Sampling Ratio
 */
#define SCI_CNFG_OSR_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_OSR_SHIFT)) & SCI_CNFG_OSR_MASK)

#define SCI_CNFG_TMOD_MASK                     (0x20000000U)
#define SCI_CNFG_TMOD_SHIFT                    (29U)
/*! TMOD - 10-bit Mode select
 *  0b0..Receiver and transmitter use 8-bit or 9-bit data characters.
 *  0b1..Receiver and transmitter use 10-bit data characters.
 */
#define SCI_CNFG_TMOD_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_TMOD_SHIFT)) & SCI_CNFG_TMOD_MASK)

#define SCI_CNFG_MAE2_MASK                   (0x40000000U)
#define SCI_CNFG_MAE2_SHIFT                  (30U)
/*! MAE2 - Match Address Mode Enable 2
 *  0b0..Normal operation.
 *  0b1..Enables automatic address matching or data matching mode for MATCH[MA2].
 */
#define SCI_CNFG_MAE2_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_MAE2_SHIFT)) & SCI_CNFG_MAE2_MASK)

#define SCI_CNFG_MAE1_MASK                   (0x80000000U)
#define SCI_CNFG_MAE1_SHIFT                  (31U)
/*! MAE1 - Match Address Mode Enable 1
 *  0b0..Normal operation.
 *  0b1..Enables automatic address matching or data matching mode for MATCH[MA1].
 */
#define SCI_CNFG_MAE1_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CNFG_MAE1_SHIFT)) & SCI_CNFG_MAE1_MASK)
/*! @} */

/*! @name STATUS - SCI Status Register */
/*! @{ */

#define SCI_STATUS_M2F_MASK                    (0x4000U)
#define SCI_STATUS_M2F_SHIFT                   (14U)
/*! M2F - Match 2 Flag
 *  0b0..Received data is not equal to MA2
 *  0b1..Received data is equal to MA2
 */
#define SCI_STATUS_M2F_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_M2F_SHIFT)) & SCI_STATUS_M2F_MASK)

#define SCI_STATUS_M1F_MASK                    (0x8000U)
#define SCI_STATUS_M1F_SHIFT                   (15U)
/*! M1F - Match 1 Flag
 *  0b0..Received data is not equal to MA1
 *  0b1..Received data is equal to MA1
 */
#define SCI_STATUS_M1F_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_M1F_SHIFT)) & SCI_STATUS_M1F_MASK)

#define SCI_STATUS_PEF_MASK                      (0x10000U)
#define SCI_STATUS_PEF_SHIFT                     (16U)
/*! PEF - Parity Error Flag
 *  0b0..No parity error.
 *  0b1..Parity error.
 */
#define SCI_STATUS_PEF_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_PEF_SHIFT)) & SCI_STATUS_PEF_MASK)

#define SCI_STATUS_FEF_MASK                      (0x20000U)
#define SCI_STATUS_FEF_SHIFT                     (17U)
/*! FEF - Framing Error Flag
 *  0b0..No framing error detected. This does not guarantee the framing is correct.
 *  0b1..Framing error.
 */
#define SCI_STATUS_FEF_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_FEF_SHIFT)) & SCI_STATUS_FEF_MASK)

#define SCI_STATUS_NOIF_MASK                      (0x40000U)
#define SCI_STATUS_NOIF_SHIFT                     (18U)
/*! NOIF - Noise Flag
 *  0b0..No noise detected.
 *  0b1..Noise detected in the received character in SCI_DATA.
 */
#define SCI_STATUS_NOIF_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_NOIF_SHIFT)) & SCI_STATUS_NOIF_MASK)

#define SCI_STATUS_ROF_MASK                      (0x80000U)
#define SCI_STATUS_ROF_SHIFT                     (19U)
/*! ROF - Receiver Overrun Flag
 *  0b0..No overrun.
 *  0b1..Receive overrun (new SCI data lost).
 */
#define SCI_STATUS_ROF_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_ROF_SHIFT)) & SCI_STATUS_ROF_MASK)

#define SCI_STATUS_IDLF_MASK                    (0x100000U)
#define SCI_STATUS_IDLF_SHIFT                   (20U)
/*! IDLF - Idle Line Flag
 *  0b0..No idle line detected.
 *  0b1..Idle line was detected.
 */
#define SCI_STATUS_IDLF_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_IDLF_SHIFT)) & SCI_STATUS_IDLF_MASK)

#define SCI_STATUS_RDFF_MASK                    (0x200000U)
#define SCI_STATUS_RDFF_SHIFT                   (21U)
/*! RDFF - Receive Data Register Full Flag
 *  0b0..Receive data buffer empty.
 *  0b1..Receive data buffer full.
 */
#define SCI_STATUS_RDFF_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_RDFF_SHIFT)) & SCI_STATUS_RDFF_MASK)

#define SCI_STATUS_TCF_MASK                      (0x400000U)
#define SCI_STATUS_TCF_SHIFT                     (22U)
/*! TCF - Transmission Complete Flag
 *  0b0..Transmitter active (sending data, a preamble, or a break).
 *  0b1..Transmitter idle (transmission activity complete).
 */
#define SCI_STATUS_TCF_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_TCF_SHIFT)) & SCI_STATUS_TCF_MASK)

#define SCI_STATUS_TDREF_MASK                    (0x800000U)
#define SCI_STATUS_TDREF_SHIFT                   (23U)
/*! TDREF - Transmit Data Register Empty Flag
 *  0b0..Transmit data buffer full.
 *  0b1..Transmit data buffer empty.
 */
#define SCI_STATUS_TDREF_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_TDREF_SHIFT)) & SCI_STATUS_TDREF_MASK)

#define SCI_STATUS_REAF_MASK                     (0x1000000U)
#define SCI_STATUS_REAF_SHIFT                    (24U)
/*! REAF - Receiver Active Flag
 *  0b0..SCI receiver idle waiting for a start bit.
 *  0b1..SCI receiver active (SCI_RX input not idle).
 */
#define SCI_STATUS_REAF_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_REAF_SHIFT)) & SCI_STATUS_REAF_MASK)

#define SCI_STATUS_LBDE_MASK                   (0x2000000U)
#define SCI_STATUS_LBDE_SHIFT                  (25U)
/*! LBDE - LIN Break Detection Enable
 *  0b0..Break character is detected at length 10 bit times (if M = 0, SBNS = 0) or 11 (if M = 1, SBNS = 0 or M =
 *       0, SBNS = 1) or 12 (if M = 1, SBNS = 1 or M10 = 1, SNBS = 0) or 13 (if M10 = 1, SNBS = 1).
 *  0b1..Break character is detected at length of 11 bit times (if M = 0, SBNS = 0) or 12 (if M = 1, SBNS = 0 or M
 *       = 0, SBNS = 1) or 14 (if M = 1, SBNS = 1 or M10 = 1, SNBS = 0) or 15 (if M10 = 1, SNBS = 1).
 */
#define SCI_STATUS_LBDE_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_LBDE_SHIFT)) & SCI_STATUS_LBDE_MASK)

#define SCI_STATUS_BCLEN_MASK                   (0x4000000U)
#define SCI_STATUS_BCLEN_SHIFT                  (26U)
/*! BCLEN - Break Character Generation Length
 *  0b0..Break character is transmitted with length of 10 bit times (if M = 0, SBNS = 0) or 11 (if M = 1, SBNS = 0
 *       or M = 0, SBNS = 1) or 12 (if M = 1, SBNS = 1 or M10 = 1, SNBS = 0) or 13 (if M10 = 1, SNBS = 1).
 *  0b1..Break character is transmitted with length of 13 bit times (if M = 0, SBNS = 0) or 14 (if M = 1, SBNS = 0
 *       or M = 0, SBNS = 1) or 15 (if M = 1, SBNS = 1 or M10 = 1, SNBS = 0) or 16 (if M10 = 1, SNBS = 1).
 */
#define SCI_STATUS_BCLEN_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_BCLEN_SHIFT)) & SCI_STATUS_BCLEN_MASK)

#define SCI_STATUS_RWID_MASK                   (0x8000000U)
#define SCI_STATUS_RWID_SHIFT                  (27U)
/*! RWID - Receive Wake Up Idle Detect
 *  0b0..During receive standby state (RWU = 1), the IDLE bit does not get set upon detection of an idle
 *       character. During address match wakeup, the IDLE bit does not get set when an address does not match.
 *  0b1..During receive standby state (RWU = 1), the IDLE bit gets set upon detection of an idle character. During
 *       address match wakeup, the IDLE bit does get set when an address does not match.
 */
#define SCI_STATUS_RWID_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_RWID_SHIFT)) & SCI_STATUS_RWID_MASK)

#define SCI_STATUS_RXINV_MASK                   (0x10000000U)
#define SCI_STATUS_RXINV_SHIFT                  (28U)
/*! RXINV - Receive Data Inversion
 *  0b0..Receive data not inverted.
 *  0b1..Receive data inverted.
 */
#define SCI_STATUS_RXINV_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_RXINV_SHIFT)) & SCI_STATUS_RXINV_MASK)

#define SCI_STATUS_MSB_MASK                    (0x20000000U)
#define SCI_STATUS_MSB_SHIFT                   (29U)
/*! MSB - MSB First
 *  0b0..LSB (bit0) is the first bit that is transmitted following the start bit. Further, the first bit received
 *       after the start bit is identified as bit0.
 *  0b1..MSB (bit9, bit8, bit7 or bit6) is the first bit that is transmitted following the start bit depending on
 *       the setting of CTRL[M], CTRL[PE] and BAUD[M10]. Further, the first bit received after the start bit is
 *       identified as bit9, bit8, bit7 or bit6 depending on the setting of CTRL[M] and CTRL[PE].
 */
#define SCI_STATUS_MSB_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_MSB_SHIFT)) & SCI_STATUS_MSB_MASK)

#define SCI_STATUS_RXEDGIF_MASK                 (0x40000000U)
#define SCI_STATUS_RXEDGIF_SHIFT                (30U)
/*! RXEDGIF - SCI_RX Pin Active Edge Interrupt Flag
 *  0b0..No active edge on the receive pin has occurred.
 *  0b1..An active edge on the receive pin has occurred.
 */
#define SCI_STATUS_RXEDGIF_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_RXEDGIF_SHIFT)) & SCI_STATUS_RXEDGIF_MASK)

#define SCI_STATUS_LBDIF_MASK                  (0x80000000U)
#define SCI_STATUS_LBDIF_SHIFT                 (31U)
/*! LBDIF - LIN Break Detect Interrupt Flag
 *  0b0..No LIN break character has been detected.
 *  0b1..LIN break character has been detected.
 */
#define SCI_STATUS_LBDIF_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_STATUS_LBDIF_SHIFT)) & SCI_STATUS_LBDIF_MASK)
/*! @} */

/*! @name CTRL - SCI Control Register */
/*! @{ */

#define SCI_CTRL_PSEL_MASK                      (0x1U)
#define SCI_CTRL_PSEL_SHIFT                     (0U)
/*! PSEL - Parity Type
 *  0b0..Even parity.
 *  0b1..Odd parity.
 */
#define SCI_CTRL_PSEL_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_PSEL_SHIFT)) & SCI_CTRL_PSEL_MASK)

#define SCI_CTRL_PEN_MASK                      (0x2U)
#define SCI_CTRL_PEN_SHIFT                     (1U)
/*! PEN - Parity Enable
 *  0b0..No hardware parity generation or checking.
 *  0b1..Parity enabled.
 */
#define SCI_CTRL_PEN_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_PEN_SHIFT)) & SCI_CTRL_PEN_MASK)

#define SCI_CTRL_ILTS_MASK                     (0x4U)
#define SCI_CTRL_ILTS_SHIFT                    (2U)
/*! ILTS - Idle Line Type Select
 *  0b0..Idle character bit count starts after start bit.
 *  0b1..Idle character bit count starts after stop bit.
 */
#define SCI_CTRL_ILTS_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_ILTS_SHIFT)) & SCI_CTRL_ILTS_MASK)

#define SCI_CTRL_RWMS_MASK                    (0x8U)
#define SCI_CTRL_RWMS_SHIFT                   (3U)
/*! RWMS - Receiver Wakeup Method Select
 *  0b0..Configures RWU for idle-line wakeup.
 *  0b1..Configures RWU with address-mark wakeup.
 */
#define SCI_CTRL_RWMS_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_RWMS_SHIFT)) & SCI_CTRL_RWMS_MASK)

#define SCI_CTRL_BITMOD_MASK                       (0x10U)
#define SCI_CTRL_BITMOD_SHIFT                      (4U)
/*! BITMOD - 9-Bit or 8-Bit Mode Select
 *  0b0..Receiver and transmitter use 8-bit data characters.
 *  0b1..Receiver and transmitter use 9-bit data characters.
 */
#define SCI_CTRL_BITMOD_SET(x)                         (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_BITMOD_SHIFT)) & SCI_CTRL_BITMOD_MASK)

#define SCI_CTRL_RSRCSEL_MASK                    (0x20U)
#define SCI_CTRL_RSRCSEL_SHIFT                   (5U)
/*! RSRCSEL - Receiver Source Select
 *  0b0..Provided LOOPS is set, RSRC is cleared, selects internal loop back mode and the SCI does not use the SCI_RX pin.
 *  0b1..Single-wire SCI mode where the SCI_TX pin is connected to the transmitter output and receiver input.
 */
#define SCI_CTRL_RSRCSEL_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_RSRCSEL_SHIFT)) & SCI_CTRL_RSRCSEL_MASK)

#define SCI_CTRL_DOZEN_MASK                  (0x40U)
#define SCI_CTRL_DOZEN_SHIFT                 (6U)
/*! DOZEN - Doze Enable
 *  0b0..SCI is enabled in Doze mode.
 *  0b1..SCI is disabled in Doze mode.
 */
#define SCI_CTRL_DOZEN_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_DOZEN_SHIFT)) & SCI_CTRL_DOZEN_MASK)

#define SCI_CTRL_LMOD_MASK                   (0x80U)
#define SCI_CTRL_LMOD_SHIFT                  (7U)
/*! LMOD - Loop Mode Select
 *  0b0..Normal operation - SCI_RX and SCI_TX use separate pins.
 *  0b1..Loop mode or single-wire mode where transmitter outputs are internally connected to receiver input (see RSRC bit).
 */
#define SCI_CTRL_LMOD_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_LMOD_SHIFT)) & SCI_CTRL_LMOD_MASK)

#define SCI_CTRL_IDLCFG_MASK                 (0x700U)
#define SCI_CTRL_IDLCFG_SHIFT                (8U)
/*! IDLCFG - Idle Configuration
 *  0b000..1 idle character
 *  0b001..2 idle characters
 *  0b010..4 idle characters
 *  0b011..8 idle characters
 *  0b100..16 idle characters
 *  0b101..32 idle characters
 *  0b110..64 idle characters
 *  0b111..128 idle characters
 */
#define SCI_CTRL_IDLCFG_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_IDLCFG_SHIFT)) & SCI_CTRL_IDLCFG_MASK)

#define SCI_CTRL_M2IE_MASK                   (0x4000U)
#define SCI_CTRL_M2IE_SHIFT                  (14U)
/*! M2IE - Match 2 Interrupt Enable
 *  0b0..MA2F interrupt disabled
 *  0b1..MA2F interrupt enabled
 */
#define SCI_CTRL_M2IE_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_M2IE_SHIFT)) & SCI_CTRL_M2IE_MASK)

#define SCI_CTRL_M1IE_MASK                   (0x8000U)
#define SCI_CTRL_M1IE_SHIFT                  (15U)
/*! M1IE - Match 1 Interrupt Enable
 *  0b0..MA1F interrupt disabled
 *  0b1..MA1F interrupt enabled
 */
#define SCI_CTRL_M1IE_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_M1IE_SHIFT)) & SCI_CTRL_M1IE_MASK)

#define SCI_CTRL_SDBK_MASK                     (0x10000U)
#define SCI_CTRL_SDBK_SHIFT                    (16U)
/*! SDBK - Send Break
 *  0b0..Normal transmitter operation.
 *  0b1..Queue break character(s) to be sent.
 */
#define SCI_CTRL_SDBK_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_SDBK_SHIFT)) & SCI_CTRL_SDBK_MASK)

#define SCI_CTRL_RWC_MASK                     (0x20000U)
#define SCI_CTRL_RWC_SHIFT                    (17U)
/*! RWC - Receiver Wakeup Control
 *  0b0..Normal receiver operation.
 *  0b1..SCI receiver in standby waiting for wakeup condition.
 */
#define SCI_CTRL_RWC_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_RWC_SHIFT)) & SCI_CTRL_RWC_MASK)

#define SCI_CTRL_RXEN_MASK                      (0x40000U)
#define SCI_CTRL_RXEN_SHIFT                     (18U)
/*! RXEN - Receiver Enable
 *  0b0..Receiver disabled.
 *  0b1..Receiver enabled.
 */
#define SCI_CTRL_RXEN_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_RXEN_SHIFT)) & SCI_CTRL_RXEN_MASK)

#define SCI_CTRL_TXEN_MASK                      (0x80000U)
#define SCI_CTRL_TXEN_SHIFT                     (19U)
/*! TXEN - Transmitter Enable
 *  0b0..Transmitter disabled.
 *  0b1..Transmitter enabled.
 */
#define SCI_CTRL_TXEN_SET(x)                        (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_TXEN_SHIFT)) & SCI_CTRL_TXEN_MASK)

#define SCI_CTRL_IDFIE_MASK                    (0x100000U)
#define SCI_CTRL_IDFIE_SHIFT                   (20U)
/*! IDFIE - Idle Line Interrupt Enable
 *  0b0..Hardware interrupts from IDLE disabled; use polling.
 *  0b1..Hardware interrupt requested when IDLE flag is 1.
 */
#define SCI_CTRL_IDFIE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_IDFIE_SHIFT)) & SCI_CTRL_IDFIE_MASK)

#define SCI_CTRL_RXIE_MASK                     (0x200000U)
#define SCI_CTRL_RXIE_SHIFT                    (21U)
/*! RXIE - Receiver Interrupt Enable
 *  0b0..Hardware interrupts from RDRF disabled; use polling.
 *  0b1..Hardware interrupt requested when RDRF flag is 1.
 */
#define SCI_CTRL_RXIE_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_RXIE_SHIFT)) & SCI_CTRL_RXIE_MASK)

#define SCI_CTRL_TCFIE_MASK                    (0x400000U)
#define SCI_CTRL_TCFIE_SHIFT                   (22U)
/*! TCFIE - Transmission Complete Interrupt Enable for
 *  0b0..Hardware interrupts from TC disabled; use polling.
 *  0b1..Hardware interrupt requested when TC flag is 1.
 */
#define SCI_CTRL_TCFIE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_TCFIE_SHIFT)) & SCI_CTRL_TCFIE_MASK)

#define SCI_CTRL_TXIE_MASK                     (0x800000U)
#define SCI_CTRL_TXIE_SHIFT                    (23U)
/*! TXIE - Transmit Interrupt Enable
 *  0b0..Hardware interrupts from TDRE disabled; use polling.
 *  0b1..Hardware interrupt requested when TDRE flag is 1.
 */
#define SCI_CTRL_TXIE_SET(x)                       (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_TXIE_SHIFT)) & SCI_CTRL_TXIE_MASK)

#define SCI_CTRL_PEFIE_MASK                    (0x1000000U)
#define SCI_CTRL_PEFIE_SHIFT                   (24U)
/*! PEFIE - Parity Error Interrupt Enable
 *  0b0..PF interrupts disabled; use polling).
 *  0b1..Hardware interrupt requested when PF is set.
 */
#define SCI_CTRL_PEFIE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_PEFIE_SHIFT)) & SCI_CTRL_PEFIE_MASK)

#define SCI_CTRL_FEFIE_MASK                    (0x2000000U)
#define SCI_CTRL_FEFIE_SHIFT                   (25U)
/*! FEFIE - Framing Error Interrupt Enable
 *  0b0..FE interrupts disabled; use polling.
 *  0b1..Hardware interrupt requested when FE is set.
 */
#define SCI_CTRL_FEFIE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_FEFIE_SHIFT)) & SCI_CTRL_FEFIE_MASK)

#define SCI_CTRL_NFIE_MASK                    (0x4000000U)
#define SCI_CTRL_NFIE_SHIFT                   (26U)
/*! NFIE - Noise Error Interrupt Enable
 *  0b0..NF interrupts disabled; use polling.
 *  0b1..Hardware interrupt requested when NF is set.
 */
#define SCI_CTRL_NFIE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_NFIE_SHIFT)) & SCI_CTRL_NFIE_MASK)

#define SCI_CTRL_OVIE_MASK                    (0x8000000U)
#define SCI_CTRL_OVIE_SHIFT                   (27U)
/*! OVIE - Overrun Interrupt Enable
 *  0b0..OVERFLOW interrupts disabled; use polling.
 *  0b1..Hardware interrupt requested when OVERFLOW is set.
 */
#define SCI_CTRL_OVIE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_OVIE_SHIFT)) & SCI_CTRL_OVIE_MASK)

#define SCI_CTRL_TXINV_MASK                   (0x10000000U)
#define SCI_CTRL_TXINV_SHIFT                  (28U)
/*! TXINV - Transmit Data Inversion
 *  0b0..Transmit data not inverted.
 *  0b1..Transmit data inverted.
 */
#define SCI_CTRL_TXINV_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_TXINV_SHIFT)) & SCI_CTRL_TXINV_MASK)

#define SCI_CTRL_TXDIR_MASK                   (0x20000000U)
#define SCI_CTRL_TXDIR_SHIFT                  (29U)
/*! TXDIR - SCI_TX Pin Direction in Single-Wire Mode
 *  0b0..SCI_TX pin is an input in single-wire mode.
 *  0b1..SCI_TX pin is an output in single-wire mode.
 */
#define SCI_CTRL_TXDIR_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_CTRL_TXDIR_SHIFT)) & SCI_CTRL_TXDIR_MASK)

/*! @} */

/*! @name DATA - SCI Data Register */
/*! @{ */
#define SCI_DATA_DAT_MASK                    (0x200U)
#define SCI_DATA_DAT_SHIFT                   (9U)
#define SCI_DATA_DAT_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_DATA_DAT_SHIFT)) & SCI_DATA_DAT_MASK)

#define SCI_DATA_RLIDL_MASK                  (0x800U)
#define SCI_DATA_RLIDL_SHIFT                 (11U)
/*! RLIDL - Idle Line
 *  0b0..Receiver was not idle before receiving this character.
 *  0b1..Receiver was idle before receiving this character.
 */
#define SCI_DATA_RLIDL_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_DATA_RLIDL_SHIFT)) & SCI_DATA_RLIDL_MASK)

#define SCI_DATA_RBEMPT_MASK                  (0x1000U)
#define SCI_DATA_RBEMPT_SHIFT                 (12U)
/*! RBEMPT - Receive Buffer Empty
 *  0b0..Receive buffer contains valid data.
 *  0b1..Receive buffer is empty, data returned on read is not valid.
 */
#define SCI_DATA_RBEMPT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_DATA_RBEMPT_SHIFT)) & SCI_DATA_RBEMPT_MASK)

#define SCI_DATA_FETSC_MASK                  (0x2000U)
#define SCI_DATA_FETSC_SHIFT                 (13U)
/*! FETSC - Frame Error / Transmit Special Character
 *  0b0..The dataword was received without a frame error on read, transmit a normal character on write.
 *  0b1..The dataword was received with a frame error, transmit an idle or break character on transmit.
 */
#define SCI_DATA_FETSC_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_DATA_FETSC_SHIFT)) & SCI_DATA_FETSC_MASK)

#define SCI_DATA_PARERR_MASK                 (0x4000U)
#define SCI_DATA_PARERR_SHIFT                (14U)
/*! PARITYE
 *  0b0..The dataword was received without a parity error.
 *  0b1..The dataword was received with a parity error.
 */
#define SCI_DATA_PARERR_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_DATA_PARERR_SHIFT)) & SCI_DATA_PARERR_MASK)

#define SCI_DATA_NOISE_MASK                   (0x8000U)
#define SCI_DATA_NOISE_SHIFT                  (15U)
/*! NOISE
 *  0b0..The dataword was received without noise.
 *  0b1..The data was received with noise.
 */
#define SCI_DATA_NOISE_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_DATA_NOISE_SHIFT)) & SCI_DATA_NOISE_MASK)
/*! @} */

/*! @name MATCH - SCI Match Address Register */
/*! @{ */

#define SCI_MATCH_M1_MASK                    (0x3FFU)
#define SCI_MATCH_M1_SHIFT                   (0U)
/*! M1 - Match Address 1
 */
#define SCI_MATCH_M1_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_MATCH_M1_SHIFT)) & SCI_MATCH_M1_MASK)

#define SCI_MATCH_M2_MASK                    (0x3FF0000U)
#define SCI_MATCH_M2_SHIFT                   (16U)
/*! M2 - Match Address 2
 */
#define SCI_MATCH_M2_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_MATCH_M2_SHIFT)) & SCI_MATCH_M2_MASK)
/*! @} */

/*! @name RSIR - SCI RS485 & IrDA Register */
/*! @{ */

#define SCI_RSIR_TCTSE_MASK                 (0x1U)
#define SCI_RSIR_TCTSE_SHIFT                (0U)
/*! TCTSE - Transmitter clear-to-send enable
 *  0b0..CTS has no effect on the transmitter.
 *  0b1..Enables clear-to-send operation. The transmitter checks the state of CTS each time it is ready to send a
 *       character. If CTS is asserted, the character is sent. If CTS is deasserted, the signal TXD remains in the
 *       mark state and transmission is delayed until CTS is asserted. Changes in CTS as a character is being sent
 *       do not affect its transmission.
 */
#define SCI_RSIR_TCTSE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_TCTSE_SHIFT)) & SCI_RSIR_TCTSE_MASK)

#define SCI_RSIR_TRTSE_MASK                 (0x2U)
#define SCI_RSIR_TRTSE_SHIFT                (1U)
/*! TRTSE - Transmitter request-to-send enable
 *  0b0..The transmitter has no effect on RTS.
 *  0b1..When a character is placed into an empty transmitter data buffer , RTS asserts one bit time before the
 *       start bit is transmitted. RTS deasserts one bit time after all characters in the transmitter data buffer and
 *       shift register are completely sent, including the last stop bit.
 */
#define SCI_RSIR_TRTSE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_TRTSE_SHIFT)) & SCI_RSIR_TRTSE_MASK)

#define SCI_RSIR_TRTSPOL_MASK               (0x4U)
#define SCI_RSIR_TRTSPOL_SHIFT              (2U)
/*! TRTSPOL - Transmitter request-to-send polarity
 *  0b0..Transmitter RTS is active low.
 *  0b1..Transmitter RTS is active high.
 */
#define SCI_RSIR_TRTSPOL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_TRTSPOL_SHIFT)) & SCI_RSIR_TRTSPOL_MASK)

#define SCI_RSIR_RTSE_MASK                 (0x8U)
#define SCI_RSIR_RTSE_SHIFT                (3U)
/*! RTSE - Receiver request-to-send enable
 *  0b0..The receiver has no effect on RTS.
 *  0b1..RTS is deasserted if the receiver data register is full or a start bit has been detected that would cause
 *       the receiver data register to become full. RTS is asserted if the receiver data register is not full and
 *       has not detected a start bit that would cause the receiver data register to become full.
 */
#define SCI_RSIR_RTSE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_RTSE_SHIFT)) & SCI_RSIR_RTSE_MASK)

#define SCI_RSIR_CTSCFG_MASK                 (0x10U)
#define SCI_RSIR_CTSCFG_SHIFT                (4U)
/*! CTSCFG - Transmit CTS Configuration
 *  0b0..CTS input is sampled at the start of each character.
 *  0b1..CTS input is sampled when the transmitter is idle.
 */
#define SCI_RSIR_CTSCFG_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_CTSCFG_SHIFT)) & SCI_RSIR_CTSCFG_MASK)

#define SCI_RSIR_CTSSRC_MASK               (0x20U)
#define SCI_RSIR_CTSSRC_SHIFT              (5U)
/*! CTSSRC - Transmit CTS Source
 *  0b0..CTS input is the SCI_CTS pin.
 *  0b1..CTS input is the inverted Receiver Match result.
 */
#define SCI_RSIR_CTSSRC_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_CTSSRC_SHIFT)) & SCI_RSIR_CTSSRC_MASK)

#define SCI_RSIR_RTSCFG_MASK                 (0x10U)
#define SCI_RSIR_RTSCFG_SHIFT                (4U)
/*! RTSCFG - Receive RTS Configuration
 *  RTS watermark setting.
 */
#define SCI_RSIR_RTSCFG_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_RTSCFG_SHIFT)) & SCI_RSIR_RTSCFG_MASK)

#define SCI_RSIR_TNP_MASK                    (0x30000U)
#define SCI_RSIR_TNP_SHIFT                   (16U)
/*! TNP - Transmitter narrow pulse
 *  0b00..1/OSR.
 *  0b01..2/OSR.
 *  0b10..3/OSR.
 *  0b11..4/OSR.
 */
#define SCI_RSIR_TNP_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_TNP_SHIFT)) & SCI_RSIR_TNP_MASK)

#define SCI_RSIR_IREN_MASK                   (0x40000U)
#define SCI_RSIR_IREN_SHIFT                  (18U)
/*! IREN - Infrared enable
 *  0b0..IR disabled.
 *  0b1..IR enabled.
 */
#define SCI_RSIR_IREN_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_RSIR_IREN_SHIFT)) & SCI_RSIR_IREN_MASK)
/*! @} */
/*! @name FCTL - SCI FIFO Register */
/*! @{ */
#define SCI_FCTL_RXFIFOSIZE_MASK              (0x7U)
#define SCI_FCTL_RXFIFOSIZE_SHIFT             (0U)
/*! RXFIFOSIZE - Receive FIFO. Buffer Depth
 *  0b000..Receive FIFO/Buffer depth = 1 dataword.
 *  0b001..Receive FIFO/Buffer depth = 4 datawords.
 *  0b010..Receive FIFO/Buffer depth = 8 datawords.
 *  0b011..Receive FIFO/Buffer depth = 16 datawords.
 *  0b100..Receive FIFO/Buffer depth = 32 datawords.
 *  0b101..Receive FIFO/Buffer depth = 64 datawords.
 *  0b110..Receive FIFO/Buffer depth = 128 datawords.
 *  0b111..Receive FIFO/Buffer depth = 256 datawords.
 */
#define SCI_FCTL_RXFIFOSIZE_SET(x)                (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_RXFIFOSIZE_SHIFT)) & SCI_FCTL_RXFIFOSIZE_MASK)
#define SCI_FCTL_RXFIFOEN_MASK                    (0x8U)
#define SCI_FCTL_RXFIFOEN_SHIFT                   (3U)
/*! RXFIFOEN - Receive FIFO Enable
 *  0b0..Receive FIFO is not enabled. Buffer is depth 1. (Legacy support)
 *  0b1..Receive FIFO is enabled. Buffer is depth indicted by RXFIFOSIZE.
 */
#define SCI_FCTL_RXFIFOEN_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_RXFIFOEN_SHIFT)) & SCI_FCTL_RXFIFOEN_MASK)
#define SCI_FCTL_TXFIFOSIZE_MASK              (0x70U)
#define SCI_FCTL_TXFIFOSIZE_SHIFT             (4U)
/*! TXFIFOSIZE - Transmit FIFO. Buffer Depth
 *  0b000..Transmit FIFO/Buffer depth = 1 dataword.
 *  0b001..Transmit FIFO/Buffer depth = 4 datawords.
 *  0b010..Transmit FIFO/Buffer depth = 8 datawords.
 *  0b011..Transmit FIFO/Buffer depth = 16 datawords.
 *  0b100..Transmit FIFO/Buffer depth = 32 datawords.
 *  0b101..Transmit FIFO/Buffer depth = 64 datawords.
 *  0b110..Transmit FIFO/Buffer depth = 128 datawords.
 *  0b111..Transmit FIFO/Buffer depth = 256 datawords
 */
#define SCI_FCTL_TXFIFOSIZE_SET(x)                (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_TXFIFOSIZE_SHIFT)) & SCI_FCTL_TXFIFOSIZE_MASK)
#define SCI_FCTL_TXFIFOEN_MASK                    (0x80U)
#define SCI_FCTL_TXFIFOEN_SHIFT                   (7U)
/*! TXFIFOEN - Transmit FIFO Enable
 *  0b0..Transmit FIFO is not enabled. Buffer is depth 1. (Legacy support).
 *  0b1..Transmit FIFO is enabled. Buffer is depth indicated by TXFIFOSIZE.
 */
#define SCI_FCTL_TXFIFOEN_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_TXFIFOEN_SHIFT)) & SCI_FCTL_TXFIFOEN_MASK)
#define SCI_FCTL_RXUNIE_MASK                   (0x100U)
#define SCI_FCTL_RXUNIE_SHIFT                  (8U)
/*! RXUNIE - Receive FIFO Underflow Interrupt Enable
 *  0b0..RXUF flag does not generate an interrupt to the host.
 *  0b1..RXUF flag generates an interrupt to the host.
 */
#define SCI_FCTL_RXUNIE_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_RXUNIE_SHIFT)) & SCI_FCTL_RXUNIE_MASK)
#define SCI_FCTL_TXOVIE_MASK                   (0x200U)
#define SCI_FCTL_TXOVIE_SHIFT                  (9U)
/*! TXOVIE - Transmit FIFO Overflow Interrupt Enable
 *  0b0..TXOF flag does not generate an interrupt to the host.
 *  0b1..TXOF flag generates an interrupt to the host.
 */
#define SCI_FCTL_TXOVIE_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_TXOVIE_SHIFT)) & SCI_FCTL_TXOVIE_MASK)
#define SCI_FCTL_IRFNEE_MASK                  (0x1C00U)
#define SCI_FCTL_IRFNEE_SHIFT                 (10U)
/*! IRFNEE - Idle Receiver FIFO Not Empty Enable
 *  0b000..Disable RDFF assertion due to partially filled FIFO when receiver is idle.
 *  0b001..Enable RDFF assertion due to partially filled FIFO when receiver is idle for 1 character.
 *  0b010..Enable RDFF assertion due to partially filled FIFO when receiver is idle for 2 characters.
 *  0b011..Enable RDFF assertion due to partially filled FIFO when receiver is idle for 4 characters.
 *  0b100..Enable RDFF assertion due to partially filled FIFO when receiver is idle for 8 characters.
 *  0b101..Enable RDFF assertion due to partially filled FIFO when receiver is idle for 16 characters.
 *  0b110..Enable RDFF assertion due to partially filled FIFO when receiver is idle for 32 characters.
 *  0b111..Enable RDFF assertion due to partially filled FIFO when receiver is idle for 64 characters.
 */
#define SCI_FCTL_IRFNEE_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_IRFNEE_SHIFT)) & SCI_FCTL_IRFNEE_MASK)
#define SCI_FCTL_RXBUFCLR_MASK                 (0x4000U)
#define SCI_FCTL_RXBUFCLR_SHIFT                (14U)
/*! RXBUFCLR - Receive FIFO/Buffer Flush
 *  *  0b0..No flush operation occurs.
 *   *  0b1..All data in the receive FIFO/buffer is cleared out.
 *    */
#define SCI_FCTL_RXBUFCLR_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_RXBUFCLR_SHIFT)) & SCI_FCTL_RXBUFCLR_MASK)
#define SCI_FCTL_TXBUFCLR_MASK                 (0x8000U)
#define SCI_FCTL_TXBUFCLR_SHIFT                (15U)
/*! TXBUFCLR - Transmit FIFO/Buffer Flush
 *  *  0b0..No flush operation occurs.
 *   *  0b1..All data in the transmit FIFO/Buffer is cleared out.
 *    */
#define SCI_FCTL_TXBUFCLR_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_TXBUFCLR_SHIFT)) & SCI_FCTL_TXBUFCLR_MASK)
#define SCI_FCTL_RBUNF_MASK                    (0x10000U)
#define SCI_FCTL_RBUNF_SHIFT                   (16U)
/*! RBUNF - Receiver Buffer Underflow Flag
 *  *  0b0..No receive buffer underflow has occurred since the last time the flag was cleared.
 *   *  0b1..At least one receive buffer underflow has occurred since the last time the flag was cleared.
 *    */
#define SCI_FCTL_RBUNF_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_RBUNF_SHIFT)) & SCI_FCTL_RBUNF_MASK)
#define SCI_FCTL_TBOVF_MASK                    (0x20000U)
#define SCI_FCTL_TBOVF_SHIFT                   (17U)
/*! TBOVF - Transmitter Buffer Overflow Flag
 *  *  0b0..No transmit buffer overflow has occurred since the last time the flag was cleared.
 *   *  0b1..At least one transmit buffer overflow has occurred since the last time the flag was cleared.
 *    */
#define SCI_FCTL_TBOVF_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_TBOVF_SHIFT)) & SCI_FCTL_TBOVF_MASK)
#define SCI_FCTL_RFEMPT_MASK                  (0x400000U)
#define SCI_FCTL_RFEMPT_SHIFT                 (22U)
/*! RFEMPT - Receive Buffer/FIFO Empty
 *  *  0b0..Receive buffer is not empty.
 *   *  0b1..Receive buffer is empty.
 *    */
#define SCI_FCTL_RFEMPT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_RFEMPT_SHIFT)) & SCI_FCTL_RFEMPT_MASK)
#define SCI_FCTL_TFEMPT_MASK                  (0x800000U)
#define SCI_FCTL_TFEMPT_SHIFT                 (23U)
/*! TFEMPT - Transmit Buffer/FIFO Empty
 *  *  0b0..Transmit buffer is not empty.
 *   *  0b1..Transmit buffer is empty.
 *    */
#define SCI_FCTL_TFEMPT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SCI_FCTL_TFEMPT_SHIFT)) & SCI_FCTL_TFEMPT_MASK)
/*! @} */

/*! @name WATER - SCI Watermark Register */
/*! @{ */
#define SCI_WATMK_TXWAT_MASK                (0xFFU)
#define SCI_WATMK_TXWAT_SHIFT               (0U)
#define SCI_WATMK_TXWAT_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SCI_WATMK_TXWAT_SHIFT)) & SCI_WATMK_TXWAT_MASK)
#define SCI_WATMK_TXCNT_MASK                (0xFF00U)
#define SCI_WATMK_TXCNT_SHIFT               (8U)
#define SCI_WATMK_TXCNT_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SCI_WATMK_TXCNT_SHIFT)) & SCI_WATMK_TXCNT_MASK)
#define SCI_WATMK_RXWAT_MASK                (0xFF0000U)
#define SCI_WATMK_RXWAT_SHIFT               (16U)
#define SCI_WATMK_RXWAT_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SCI_WATMK_RXWAT_SHIFT)) & SCI_WATMK_RXWAT_MASK)
#define SCI_WATMK_RXCNT_MASK                (0xFF000000U)
#define SCI_WATMK_RXCNT_SHIFT               (24U)
#define SCI_WATMK_RXCNT_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SCI_WATMK_RXCNT_SHIFT)) & SCI_WATMK_RXCNT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SCI_Register_Masks */


/* SCI - Peripheral instance base addresses */
/** Peripheral SCI0 base address */
#define SCI1_BASE                             (0x400C4000u)
/** Peripheral SCI0 base pointer */
#define SCI1                                  ((SCI_TypeDef *)SCI1_BASE)
/** Peripheral SCI0 base address */
#define SCI2_BASE                             (0x400C5000u)
/** Peripheral SCI0 base pointer */
#define SCI2                                  ((SCI_TypeDef *)SCI2_BASE)
/** Peripheral SCI0 base address */
#define SCI3_BASE                             (0x400C6000u)
/** Peripheral SCI0 base pointer */
#define SCI3                                  ((SCI_TypeDef *)SCI3_BASE)
/** Peripheral SCI0 base address */
#define SCI4_BASE                             (0x4006A000u)
/** Peripheral SCI0 base pointer */
#define SCI4                                  ((SCI_TypeDef *)SCI4_BASE)
/** Peripheral SCI0 base address */
#define SCI5_BASE                             (0x4006B000u)
/** Peripheral SCI0 base pointer */
#define SCI5                                  ((SCI_TypeDef *)SCI5_BASE)
/** Peripheral SCI0 base address */
#define SCI6_BASE                             (0x4006C000u)
/** Peripheral SCI0 base pointer */
#define SCI6                                  ((SCI_TypeDef *)SCI6_BASE)

/** Array initializer of SCI peripheral base addresses */
#define SCI_BASE_ADDRS                        { SCI1_BASE, SCI2_BASE, SCI3_BASE, SCI4_BASE, SCI5_BASE, SCI6_BASE}
/** Array initializer of SCI peripheral base pointers */
#define SCI_BASE_PTRS                         { SCI1, SCI2, SCI3, SCI4, SCI5, SCI6 }
/** Interrupt vectors for the SCI peripheral type */
#define SCI_RX_TX_IRQS                        { SCI1_IRQn, SCI2_IRQn, SCI3_IRQn, SCI4_IRQn, SCI5_IRQn, SCI6_IRQn }
#define SCI_ERR_IRQS                          { SCI1_IRQn, SCI2_IRQn, SCI3_IRQn, SCI4_IRQn, SCI5_IRQn, SCI6_IRQn }

/*!
 * @}
 */ /* end of group SCI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SYSCTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup System Control Access Layer
 * @{
 */

/** SYSCTRL - Register Layout Typedef */
typedef struct {
       uint32_t  RESERVED1;
  __IO uint32_t  CLKDIV;                            /**< Clock divider register, offset: 0x4 */
  __IO uint32_t  PLLCFG;                            /**< PLL configration register, offset: 0x8 */
  __IO uint32_t  CLKSW;                             /**< Clock switch register, offset: 0xC */
  __IO uint32_t  SYSREMAP;                          /**< System remap register , offset: 0x10 */
  __IO uint32_t  POWERCFG;                          /**< Power configuration register, offset: 0x14 */
  __IO uint32_t  UNLOCK;                            /**< Unlock register, offset: 0x18 */
  __IO uint32_t  ISP1CGC1;                          /**< ISP1 clock gate register 1, offset: 0x1C */
  __IO uint32_t  ISP1CGC2;                          /**< ISP1 clock gate register 2, offset: 0x20 */
  __IO uint32_t  ISP1CGC3;                          /**< ISP1 clock gate register 3, offset: 0x24 */
  __IO uint32_t  ISP2CGC1;                          /**< ISP2 clock gate register 1, offset: 0x28 */
  __IO uint32_t  ISP2CGC2;                          /**< ISP2 clock gate register 2, offset: 0x2C */
  __IO uint32_t  ISP2CGC3;                          /**< ISP2 clock gate register 3, offset: 0x30 */
  __IO uint32_t  ONPLATCGC;                         /**< Plate clock gate register, offset: 0x34 */
  __IO uint32_t  SCICLKSEL;                         /**< SCI clock select register, offset: 0x38 */
  __IO uint32_t  CLKOUTSEL;                         /**< Clock out source select register, offset: 0x3C */
  __IO uint32_t  PREPLLDIV;                            /**< PLL divider register, offset: 0x40 */
  __IO uint32_t  IOSC8MTRIM;                        /**< Internal 8M osc trim register, offset: 0x44 */
  __IO uint32_t  IOSC30KTRIM;                       /**< Internal 30K osc trim register, offset: 0x48 */
  __IO uint32_t  LDOCFG;                            /**< LDO configuration register, offset: 0x4C */
  __IO uint32_t  RESERVED2;
  __IO uint32_t  VDT1TRIM;                          /**< VDT1 trim value register, offset: 0x54 */
  __IO uint32_t  VDT2TRIM;                          /**< VDT2 trim value register, offset: 0x58 */
  __IO uint32_t  VDT1CON;                           /**< VDT1 configuration register, offset: 0x5C */
  __IO uint32_t  VDT2CON;                           /**< VDT2 configuration register, offset: 0x60 */
  __IO uint32_t  TDTTRIM;                           /**< Temperature detect trim register, offset: 0x64 */
  __IO uint32_t  XOSCPYPASS;                        /**< External oscillator bypass register, offset: 0x68 */
  __IO uint32_t  CANCTR;                            /**< CAN control register, offset: 0x6C */
  __IO uint32_t  SOFTRST1;                          /**< Soft reset register 1, offset: 0x70 */
  __IO uint32_t  SOFTRST2;                          /**< Soft reset register 2, offset: 0x74 */
  __IO uint32_t  DEVICEID1;                         /**< Device ID register 1, offset: 0x78 */
  __IO uint32_t  DEVICEID2;                         /**< Device ID register 2, offset: 0x7C */
  __IO uint32_t  TDTALARM;                          /**< Not open to customer */
  __IO uint32_t  LDOTBR;                            /**< Not open to customer */
  __IO uint32_t  LDOTCBR;                           /**< Not open to customer */
  __IO uint32_t  LDOVDDOPT;                         /**< Temperature alarm register, offset: 0x80 */
  __IO uint32_t  ADCSOCOUTSEL;                      /**< ADC SOC out register, offset: 0x90 */
       uint32_t  RESERVED3;
  __IO uint32_t  FLSFASTWKUP;                       /**< Flash fast wakup register, offset: 0x98 */
  __IO uint32_t  FESR;                              /**< Flash ECC status register, offset: 0x9C */
  __IO uint32_t  FECR;                              /**< Flash ECC control register, offset: 0xA0 */
  __IO uint32_t  FEER;                              /**< Flash ECC enable register, offset: 0xA4 */
  __IO uint32_t  PORBREG1;                          /**< POR profile register 1, offset: 0xA8 */
  __IO uint32_t  PORBREG2;                          /**< POR profile register 2, offset: 0xAC */
       uint32_t  RESERVED4[4];
  __IO uint32_t  TBCLKSYNC;                         /**< TBCLK syncronize register, offset: 0xC0 */
	
}SYSCTRL_Type;
/* ----------------------------------------------------------------------------
 *    -- SYSCTRL Register Masks
 *       ---------------------------------------------------------------------------- */

/*!
 *  * @addtogroup SYSCTRL_Register_Masks SYSCTRL Register Masks
 *  * @{
 *  */
/*!
 *! @name SIMCLKDIV - System Integration Module Clock Divider Configuration Register */
/*! @{ */

#define SYSCTRL_CLKDIV_FTFDIV_MASK                   (0xF0000U)
#define SYSCTRL_CLKDIV_FTFDIV_SHIFT                  (16)
#define SYSCTRL_CLKDIV_FTFDIV_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTRL_CLKDIV_FTFDIV_SHIFT)) & SYSCTRL_CLKDIV_FTFDIV_MASK)

#define SYSCTRL_CLKDIV_FTFDIV2_MASK                  (0xF00000U)
#define SYSCTRL_CLKDIV_FTFDIV2_SHIFT                 (20)
#define SYSCTRL_CLKDIV_FTFDIV2_SET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTRL_CLKDIV_FTFDIV2_SHIFT)) & SYSCTRL_CLKDIV_FTFDIV2_MASK)

#define SYSCTRL_CLKDIV_BUSDIV_MASK                   (0xF000000U)
#define SYSCTRL_CLKDIV_BUSDIV_SHIFT                  (24)
#define SYSCTRL_CLKDIV_BUSDIV_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTRL_CLKDIV_BUSDIV_SHIFT)) & SYSCTRL_CLKDIV_BUSDIV_MASK)

#define SYSCTRL_CLKDIV_SYSDIV_MASK                   (0xF0000000U)
#define SYSCTRL_CLKDIV_SYSDIV_SHIFT                  (28)
#define SYSCTRL_CLKDIV_SYSDIV_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTRL_CLKDIV_SYSDIV_SHIFT)) & SYSCTRL_CLKDIV_SYSDIV_MASK)

/*! @} */
/*! @name PLLCFG - PLL Configuration Register */
/*! @{ */

#define SYSCTRL_PLLCFG_IMULT_MASK                    (0xFFU)
#define SYSCTRL_PLLCFG_IMULT_SHIFT                   (0U)
#define SYSCTRL_PLLCFG_IMULT_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_PLLCFG_IMULT_SHIFT)) & SYSCTRL_PLLCFG_IMULT_MASK)

#define SYSCTRL_PLLCFG_REFDIV_MASK                   (0x3F00U)
#define SYSCTRL_PLLCFG_REFDIV_SHIFT                  (8U)
#define SYSCTRL_PLLCFG_REFDIV_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTRL_PLLCFG_REFDIV_SHIFT)) & SYSCTRL_PLLCFG_REFDIV_MASK)

#define SYSCTRL_PLLCFG_ODIV_MASK                     (0xC000U)
#define SYSCTRL_PLLCFG_ODIV_SHIFT                    (14U)
#define SYSCTRL_PLLCFG_ODIV_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCTRL_PLLCFG_ODIV_SHIFT)) & SYSCTRL_PLLCFG_ODIV_MASK)

#define SYSCTRL_PLLCFG_PLLLOCKBYPASS_MASK            (0x10000U)
#define SYSCTRL_PLLCFG_PLLLOCKBYPASS_SHIFT           (16U)
#define SYSCTRL_PLLCFG_PLLLOCKBYPASS_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTRL_PLLCFG_PLLLOCKBYPASS_SHIFT)) & SYSCTRL_PLLCFG_PLLLOCKBYPASS_MASK)

#define SYSCTRL_PLLCFG_PLLLOCK_MASK                  (0x20000U)
#define SYSCTRL_PLLCFG_PLLLOCK_SHIFT                 (17U)
#define SYSCTRL_PLLCFG_PLLLOCK_SET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTRL_PLLCFG_PLLLOCK_SHIFT)) & SYSCTRL_PLLCFG_PLLLOCK_MASK)

/*! @} */
/*! @name CLKSW - Clock Switch Register */
/*! @{ */

#define SYSCTRL_CLKSW_CLKSRCSEL_MASK                 (0x1U)
#define SYSCTRL_CLKSW_CLKSRCSEL_SHIFT                (0U)
#define SYSCTRL_CLKSW_CLKSRCSEL_SET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTRL_CLKSW_CLKSRCSEL_SHIFT)) & SYSCTRL_CLKSW_CLKSRCSEL_MASK)

#define SYSCTRL_CLKSW_PLLCLKSEL_MASK                 (0x2U)
#define SYSCTRL_CLKSW_PLLCLKSEL_SHIFT                (1U)
#define SYSCTRL_CLKSW_PLLCLKSEL_SET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTRL_CLKSW_PLLCLKSEL_SHIFT)) & SYSCTRL_CLKSW_PLLCLKSEL_MASK)

#define SYSCTRL_CLKSW_SCGCLKSEL_MASK                 (0x4U)
#define SYSCTRL_CLKSW_SCGCLKSEL_SHIFT                (2U)
#define SYSCTRL_CLKSW_SCGCLKSEL_SET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTRL_CLKSW_SCGCLKSEL_SHIFT)) & SYSCTRL_CLKSW_SCGCLKSEL_MASK)


/*! @} */
/*! @name SYSREMAP - System Remap Register */
/*! @{ */

#define SYSCTRL_SYSREMAP_REMAP_MASK                (0x3U)
#define SYSCTRL_SYSREMAP_REMAP_SHIFT               (0U)
#define SYSCTRL_SYSREMAP_REMAP_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SYSREMAP_REMAP_SHIFT)) & SYSCTRL_SYSREMAP_REMAP_MASK)

/*! @} */
/*! @name POWERCFG - Power Configuration Register */
/*! @{ */

#define SYSCTRL_POWERCFG_FLASH0_PD_MASK            (0x1U)
#define SYSCTRL_POWERCFG_FLASH0_PD_SHIFT           (0U)
#define SYSCTRL_POWERCFG_FLASH0_PD_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTRL_POWERCFG_FLASH0_PD_SHIFT)) & SYSCTRL_POWERCFG_FLASH0_PD_MASK)

#define SYSCTRL_POWERCFG_FLASH1_PD_MASK            (0x2U)
#define SYSCTRL_POWERCFG_FLASH1_PD_SHIFT           (1U)
#define SYSCTRL_POWERCFG_FLASH1_PD_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTRL_POWERCFG_FLASH1_PD_SHIFT)) & SYSCTRL_POWERCFG_FLASH1_PD_MASK)

#define SYSCTRL_POWERCFG_IOSC8M_PD_MASK            (0x4U)
#define SYSCTRL_POWERCFG_IOSC8M_PD_SHIFT           (2U)
#define SYSCTRL_POWERCFG_IOSC8M_PD_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SYSREMAP_IOSC8M_PD_SHIFT)) & SYSCTRL_SYSREMAP_IOSC8M_PD_MASK)

#define SYSCTRL_POWERCFG_IOSC32K_PD_MASK           (0x8U)
#define SYSCTRL_POWERCFG_IOSC32K_PD_SHIFT          (3U)
#define SYSCTRL_POWERCFG_IOSC32K_PD_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SYSREMAP_IOSC32K_PD_SHIFT)) & SYSCTRL_SYSREMAP_IOSC32K_PD_MASK)

#define SYSCTRL_POWERCFG_XOSC_PD_MASK              (0x10U)
#define SYSCTRL_POWERCFG_XOSC_PD_SHIFT             (4U)
#define SYSCTRL_POWERCFG_XOSC_PD_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SYSREMAP_XOSC_PD_SHIFT)) & SYSCTRL_SYSREMAP_XOSC_PD_MASK)

#define SYSCTRL_POWERCFG_PLL_PD_MASK               (0x20U)
#define SYSCTRL_POWERCFG_PLL_PD_SHIFT              (5U)
#define SYSCTRL_POWERCFG_PLL_PD_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SYSREMAP_PLL_PD_SHIFT)) & SYSCTRL_SYSREMAP_PLL_PD_MASK)

#define SYSCTRL_POWERCFG_PLL_LDO_PD_MASK           (0x40U)
#define SYSCTRL_POWERCFG_PLL_LDO_PD_SHIFT          (6U)
#define SYSCTRL_POWERCFG_PLL_LDO_PD_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SYSREMAP_PLL_LDO_PD_SHIFT)) & SYSCTRL_SYSREMAP_PLL_LDO_PD_MASK)

#define SYSCTRL_POWERCFG_LDO_SLEEP_MASK            (0x4000U)
#define SYSCTRL_POWERCFG_LDO_SLEEP_SHIFT           (14U)
#define SYSCTRL_POWERCFG_LDO_SLEEP_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SYSREMAP_LDO_SLEEP_SHIFT)) & SYSCTRL_SYSREMAP_LDO_SLEEP_MASK)

#define SYSCTRL_POWERCFG_LDO_PD_MASK               (0x8000U)
#define SYSCTRL_POWERCFG_LDO_PD_SHIFT              (15U)
#define SYSCTRL_POWERCFG_LDO_PD_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SYSREMAP_LDO_PD_SHIFT)) & SYSCTRL_SYSREMAP_LDO_PD_MASK)

/*! @} */
/*! @name UNLOCK - UNLOCK Register */
/*! @{ */

#define SYSCTRL_UNLOCK_KEY_MASK                    (0xFFFFU)
#define SYSCTRL_UNLOCK_KEY_SHIFT                   (0U)
#define SYSCTRL_UNLOCK_KEY_SET(x)                  (((uint16_t)(((uint16_t)(x)) << SYSCTRL_UNLOCK_KEY_SHIFT)) & SYSCTRL_UNLOCK_KEY_MASK)

/*! @} */

/*! @name ISP1CGC1 - Clock Gate Register */
/*! @{ */
#define SYSCTRL_ISP1CGC1_FMCCG_MASK              (1)
#define SYSCTRL_ISP1CGC1_FMCCG_SHIFT             (0)
#define SYSCTRL_ISP1CGC1_FMCCG_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_FMCCG_SHIFT)) & SYSCTRL_ISPC1CGC1_FMCCG_MASK)

#define SYSCTRL_ISP1CGC1_DMAMUX_MASK             (2)
#define SYSCTRL_ISP1CGC1_DMAMUX_SHIFT            (1)
#define SYSCTRL_ISP1CGC1_DMAMUX_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_DMAMUX_SHIFT)) & SYSCTRL_ISP1CGC1_DMAMUX_MASK)

#define SYSCTRL_ISP1CGC1_LPTIM_MASK              (4)
#define SYSCTRL_ISP1CGC1_LPTIM_SHIFT             (3)
#define SYSCTRL_ISP1CGC1_LPTIM_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_LPTIM_SHIFT)) & SYSCTRL_ISP1CGC1_LPTIM_MASK)

#define SYSCTRL_ISP1CGC1_CAN1_MASK               (0x10)
#define SYSCTRL_ISP1CGC1_CAN1_SHIFT              (4)
#define SYSCTRL_ISP1CGC1_CAN1_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_SHIFT)) & SYSCTRL_ISP1CGC1_CAN1_MASK)

#define SYSCTRL_ISP1CGC1_XBAR_MASK               (0x100)
#define SYSCTRL_ISP1CGC1_XBAR_SHIFT              (8)
#define SYSCTRL_ISP1CGC1_XBAR_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_XBAR_SHIFT)) & SYSCTRL_ISP1CGC1_XBAR_MASK)

#define SYSCTRL_ISP1CGC1_SPI1_MASK               (0x1000)
#define SYSCTRL_ISP1CGC1_SPI1_SHIFT              (12)
#define SYSCTRL_ISP1CGC1_SPI1_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_SPI1_SHIFT)) & SYSCTRL_ISP1CGC1_SPI1_MASK)

#define SYSCTRL_ISP1CGC1_SPI2_MASK               (0x2000)
#define SYSCTRL_ISP1CGC1_SPI2_SHIFT              (13)
#define SYSCTRL_ISP1CGC1_SPI2_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_SPI2_SHIFT)) & SYSCTRL_ISP1CGC1_SPI2_MASK)

#define SYSCTRL_ISP1CGC1_XINT_MASK               (0x4000)
#define SYSCTRL_ISP1CGC1_XINT_SHIFT              (14)
#define SYSCTRL_ISP1CGC1_XINT_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_XINT_SHIFT)) & SYSCTRL_ISP1CGC1_XINT_MASK)

#define SYSCTRL_ISP1CGC1_PTIM_MASK               (0x800000)
#define SYSCTRL_ISP1CGC1_PTIM_SHIFT              (23)
#define SYSCTRL_ISP1CGC1_PTIM_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_PTIM_SHIFT)) & SYSCTRL_ISP1CGC1_PTIM_MASK)

#define SYSCTRL_ISP1CGC1_EPWM1_MASK              (0x1000000)
#define SYSCTRL_ISP1CGC1_EPWM1_SHIFT             (24)
#define SYSCTRL_ISP1CGC1_EPWM1_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_EPWM1_SHIFT)) & SYSCTRL_ISP1CGC1_EPWM1_MASK)

#define SYSCTRL_ISP1CGC1_EPWM2_MASK              (0x2000000)
#define SYSCTRL_ISP1CGC1_EPWM2_SHIFT             (25)
#define SYSCTRL_ISP1CGC1_EPWM2_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_EPWM2_SHIFT)) & SYSCTRL_ISP1CGC1_EPWM2_MASK)

#define SYSCTRL_ISP1CGC1_EPWM3_MASK              (0x4000000)
#define SYSCTRL_ISP1CGC1_EPWM3_SHIFT             (26)
#define SYSCTRL_ISP1CGC1_EPWM3_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_EPWM3_SHIFT)) & SYSCTRL_ISP1CGC1_EPWM3_MASK)

#define SYSCTRL_ISP1CGC1_ADC1_MASK               (0x8000000)
#define SYSCTRL_ISP1CGC1_ADC1_SHIFT              (27)
#define SYSCTRL_ISP1CGC1_ADC1_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_ADC1_SHIFT)) & SYSCTRL_ISP1CGC1_ADC1_MASK)

#define SYSCTRL_ISP1CGC1_ADC2_MASK               (0x10000000)
#define SYSCTRL_ISP1CGC1_ADC2_SHIFT              (28)
#define SYSCTRL_ISP1CGC1_ADC2_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC1_ADC2_SHIFT)) & SYSCTRL_ISP1CGC1_ADC2_MASK)

/*! @} */

/*! @name ISP1CGC2 - Clock Gate Register */
/*! @{ */

#define SYSCTRL_ISP1CGC2_EQEP1_MASK              (1)            
#define SYSCTRL_ISP1CGC2_EQEP1_SHIFT             (0)
#define SYSCTRL_ISP1CGC2_EQEP1_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC2_EQEP1_SHIFT)) & SYSCTRL_ISP1CGC2_EQEP1_MASK)

#define SYSCTRL_ISP1CGC2_GPIOA_MASK              (0x200)
#define SYSCTRL_ISP1CGC2_GPIOA_SHIFT             (9)
#define SYSCTRL_ISP1CGC2_GPIOA_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC2_GPIOA_SHIFT)) & SYSCTRL_ISP1CGC2_GPIOA_MASK)

#define SYSCTRL_ISP1CGC2_GPIOB_MASK              (0x400)
#define SYSCTRL_ISP1CGC2_GPIOB_SHIFT             (10)
#define SYSCTRL_ISP1CGC2_GPIOB_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC2_GPIOB_SHIFT)) & SYSCTRL_ISP1CGC2_GPIOB_MASK)

#define SYSCTRL_ISP1CGC2_ECAP1_MASK              (0x1000000)
#define SYSCTRL_ISP1CGC2_ECAP1_SHIFT             (24)
#define SYSCTRL_ISP1CGC2_ECAP1_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC2_ECAP1_SHIFT)) & SYSCTRL_ISP1CGC2_ECAP1_MASK)

#define SYSCTRL_ISP1CGC2_ECAP2_MASK              (0x2000000)
#define SYSCTRL_ISP1CGC2_ECAP2_SHIFT             (25)
#define SYSCTRL_ISP1CGC2_ECAP2_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC2_ECAP2_SHIFT)) & SYSCTRL_ISP1CGC2_ECAP2_MASK)

/*! @} */

/*! @name ISP1CGC3 - Clock Gate Register */
/*! @{ */

#define SYSCTRL_ISP1CGC3_EWM_MASK                (1)
#define SYSCTRL_ISP1CGC3_EWM_SHIFT               (0)
#define SYSCTRL_ISP1CGC3_EWM_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC3_EWM_SHIFT)) & SYSCTRL_ISP1CGC3_EWM_MASK)

#define SYSCTRL_ISP1CGC3_I2C1_MASK               (0x20)
#define SYSCTRL_ISP1CGC3_I2C1_SHIFT              (5)
#define SYSCTRL_ISP1CGC3_I2C1_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC3_I2C1_SHIFT)) & SYSCTRL_ISP1CGC3_I2C1_MASK)

#define SYSCTRL_ISP1CGC3_I2C2_MASK               (0x40)
#define SYSCTRL_ISP1CGC3_I2C2_SHIFT              (6)
#define SYSCTRL_ISP1CGC3_I2C2_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC2_I2C3_SHIFT)) & SYSCTRL_ISP1CGC3_I2C2_MASK)

#define SYSCTRL_ISP1CGC3_SCI4_MASK               (0x200)
#define SYSCTRL_ISP1CGC3_SCI4_SHIFT              (9)
#define SYSCTRL_ISP1CGC3_SCI4_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC3_SCI4_SHIFT)) & SYSCTRL_ISP1CGC3_SCI4_MASK)

#define SYSCTRL_ISP1CGC3_SCI5_MASK               (0x400)
#define SYSCTRL_ISP1CGC3_SCI5_SHIFT              (10)
#define SYSCTRL_ISP1CGC3_SCI5_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC3_SCI5_SHIFT)) & SYSCTRL_ISP1CGC3_SCI5_MASK)

#define SYSCTRL_ISP1CGC3_SCI6_MASK               (0x800)
#define SYSCTRL_ISP1CGC3_SCI6_SHIFT              (11)
#define SYSCTRL_ISP1CGC3_SCI6_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC3_SCI6_SHIFT)) & SYSCTRL_ISP1CGC3_SCI6_MASK)

#define SYSCTRL_ISP1CGC3_COMP1_MASK              (0x40000)          
#define SYSCTRL_ISP1CGC3_COMP1_SHIFT             (18)
#define SYSCTRL_ISP1CGC3_COMP1_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC3_COMP1_SHIFT)) & SYSCTRL_ISP1CGC3_COMP1_MASK)

#define SYSCTRL_ISP1CGC3_COMP2_MASK              (0x80000)          
#define SYSCTRL_ISP1CGC3_COMP2_SHIFT             (19)
#define SYSCTRL_ISP1CGC3_COMP2_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP1CGC3_COMP2_SHIFT)) & SYSCTRL_ISP1CGC3_COMP2_MASK)

/*! @} */

/*! @name ISP2CGC1 - Clock Gate Register */
/*! @{ */

#define SYSCTRL_ISP2CGC1_MCAN2_MASK              (0x10)
#define SYSCTRL_ISP2CGC1_MCAN2_SHIFT             (4)
#define SYSCTRL_ISP2CGC1_MCAN2_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_MCAN2_SHIFT)) & SYSCTRL_ISP2CGC1_MCAN2_MASK)

#define SYSCTRL_ISP2CGC1_EQEP2_MASK              (0x40)
#define SYSCTRL_ISP2CGC1_EQEP2_SHIFT             (6)
#define SYSCTRL_ISP2CGC1_EQEP2_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_EQEP2_SHIFT)) & SYSCTRL_ISP2CGC1_EQEP2_MASK)

#define SYSCTRL_ISP2CGC1_SPI3_MASK               (0x1000)
#define SYSCTRL_ISP2CGC1_SPI3_SHIFT              (12)
#define SYSCTRL_ISP2CGC1_SPI3_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_SPI3_SHIFT)) & SYSCTRL_ISP2CGC1_SPI3_MASK)

#define SYSCTRL_ISP2CGC1_SPI4_MASK               (0x2000)
#define SYSCTRL_ISP2CGC1_SPI4_SHIFT              (13)
#define SYSCTRL_ISP2CGC1_SPI4_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_SPI4_SHIFT)) & SYSCTRL_ISP2CGC1_SPI4_MASK)

#define SYSCTRL_ISP2CGC1_EPWM4_MASK              (0x10000)
#define SYSCTRL_ISP2CGC1_EPWM4_SHIFT             (16)
#define SYSCTRL_ISP2CGC1_EPWM4_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_EPWM4_SHIFT)) & SYSCTRL_ISP2CGC1_EPWM4_MASK)

#define SYSCTRL_ISP2CGC1_EPWM5_MASK              (0x20000)
#define SYSCTRL_ISP2CGC1_EPWM5_SHIFT             (17)
#define SYSCTRL_ISP2CGC1_EPWM5_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_EPWM5_SHIFT)) & SYSCTRL_ISP2CGC1_EPWM5_MASK)

#define SYSCTRL_ISP2CGC1_EPWM6_MASK              (0x40000)
#define SYSCTRL_ISP2CGC1_EPWM6_SHIFT             (18)
#define SYSCTRL_ISP2CGC1_EPWM6_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_EPWM6_SHIFT)) & SYSCTRL_ISP2CGC1_EPWM6_MASK)

#define SYSCTRL_ISP2CGC1_EPWM7_MASK              (0x80000)
#define SYSCTRL_ISP2CGC1_EPWM7_SHIFT             (19)
#define SYSCTRL_ISP2CGC1_EPWM7_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_EPWM7_SHIFT)) & SYSCTRL_ISP2CGC1_EPWM7_MASK)

#define SYSCTRL_ISP2CGC1_ADC3_MASK               (0x8000000)
#define SYSCTRL_ISP2CGC1_ADC3_SHIFT              (27)
#define SYSCTRL_ISP2CGC1_ADC3_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC1_ADC3_SHIFT)) & SYSCTRL_ISP2CGC1_ADC3_MASK)

/*! @} */

/*! @name ISP2CGC2 - Clock Gate Register */
/*! @{ */

#define SYSCTRL_ISP2CGC2_SCI1_MASK               (0x10)
#define SYSCTRL_ISP2CGC2_SCI1_SHIFT              (4)
#define SYSCTRL_ISP2CGC2_SCI1_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC2_SCI1_SHIFT)) & SYSCTRL_ISP2CGC2_SCI1_MASK)

#define SYSCTRL_ISP2CGC2_SCI2_MASK               (0x20)
#define SYSCTRL_ISP2CGC2_SCI2_SHIFT              (5)
#define SYSCTRL_ISP2CGC2_SCI2_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC2_SCI2_SHIFT)) & SYSCTRL_ISP2CGC2_SCI2_MASK)

#define SYSCTRL_ISP2CGC2_SCI3_MASK               (0x40)
#define SYSCTRL_ISP2CGC2_SCI3_SHIFT              (6)
#define SYSCTRL_ISP2CGC2_SCI3_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC2_SCI3_SHIFT)) & SYSCTRL_ISP2CGC2_SCI3_MASK)

#define SYSCTRL_ISP2CGC2_ECAP3_MASK               (0x200)
#define SYSCTRL_ISP2CGC2_ECAP3_SHIFT              (9)
#define SYSCTRL_ISP2CGC2_ECAP3_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ISP2CGC2_ECAP3_SHIFT)) & SYSCTRL_ISP2CGC2_ECAP3_MASK)

/*! @} */

/*! @name ONPLATCGC - Platefrom Device Clock Gate Register */
/*! @{ */

#define SYSCTRL_ONPLATCGC_DMA_MASK               (2)
#define SYSCTRL_ONPLATCGC_DMA_SHIFT              (1)
#define SYSCTRL_ONPLATCGC_DMA_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ONPLATCGC_DMA_SHIFT)) & SYSCTRL_ONPLATCGC_DMA_MASK)

/*! @} */

/*! @name SCICLKSEL - SCI Clock Select Register */
/*! @{ */
#define SYSCTRL_SCICLKSEL_SCI1CLKSRC_MASK               (0x3)
#define SYSCTRL_SCICLKSEL_SCI1CLKSRC_SHIFT              (0)
#define SYSCTRL_SCICLKSEL_SCI1CLKSRC_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI1CLKSRC_SHIFT)) & SYSCTRL_SCICLKSEL_SCI1CLKSRC_MASK)

#define SYSCTRL_SCICLKSEL_SCI2CLKSRC_MASK               (0xc)
#define SYSCTRL_SCICLKSEL_SCI2CLKSRC_SHIFT              (2)
#define SYSCTRL_SCICLKSEL_SCI2CLKSRC_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI2CLKSRC_SHIFT)) & SYSCTRL_SCICLKSEL_SCI2CLKSRC_MASK)

#define SYSCTRL_SCICLKSEL_SCI3CLKSRC_MASK               (0x30)
#define SYSCTRL_SCICLKSEL_SCI3CLKSRC_SHIFT              (4)
#define SYSCTRL_SCICLKSEL_SCI3CLKSRC_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI3CLKSRC_SHIFT)) & SYSCTRL_SCICLKSEL_SCI3CLKSRC_MASK)

#define SYSCTRL_SCICLKSEL_SCI4CLKSRC_MASK               (0xc0)
#define SYSCTRL_SCICLKSEL_SCI4CLKSRC_SHIFT              (6)
#define SYSCTRL_SCICLKSEL_SCI4CLKSRC_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI4CLKSRC_SHIFT)) & SYSCTRL_SCICLKSEL_SCI4CLKSRC_MASK)

#define SYSCTRL_SCICLKSEL_SCI5CLKSRC_MASK               (0x300)
#define SYSCTRL_SCICLKSEL_SCI5CLKSRC_SHIFT              (8)
#define SYSCTRL_SCICLKSEL_SCI5CLKSRC_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI5CLKSRC_SHIFT)) & SYSCTRL_SCICLKSEL_SCI5CLKSRC_MASK)

#define SYSCTRL_SCICLKSEL_SCI6CLKSRC_MASK               (0xc00)
#define SYSCTRL_SCICLKSEL_SCI6CLKSRC_SHIFT              (10)
#define SYSCTRL_SCICLKSEL_SCI6CLKSRC_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI6CLKSRC_SHIFT)) & SYSCTRL_SCICLKSEL_SCI6CLKSRC_MASK)

#define SYSCTRL_SCICLKSEL_SCI1CLKEN_MASK                (0x1000)
#define SYSCTRL_SCICLKSEL_SCI1CLKEN_SHIFT               (12)
#define SYSCTRL_SCICLKSEL_SCI1CLKEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI1CLKEN_SHIFT)) & SYSCTRL_SCICLKSEL_SCI1CLKEN_MASK)

#define SYSCTRL_SCICLKSEL_SCI2CLKEN_MASK                (0x2000)
#define SYSCTRL_SCICLKSEL_SCI2CLKEN_SHIFT               (13)
#define SYSCTRL_SCICLKSEL_SCI2CLKEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI2CLKEN_SHIFT)) & SYSCTRL_SCICLKSEL_SCI2CLKEN_MASK)

#define SYSCTRL_SCICLKSEL_SCI3CLKEN_MASK                (0x4000)
#define SYSCTRL_SCICLKSEL_SCI3CLKEN_SHIFT               (14)
#define SYSCTRL_SCICLKSEL_SCI3CLKEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI3CLKEN_SHIFT)) & SYSCTRL_SCICLKSEL_SCI3CLKEN_MASK)

#define SYSCTRL_SCICLKSEL_SCI4CLKEN_MASK                (0x8000)
#define SYSCTRL_SCICLKSEL_SCI4CLKEN_SHIFT               (15)
#define SYSCTRL_SCICLKSEL_SCI4CLKEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI4CLKEN_SHIFT)) & SYSCTRL_SCICLKSEL_SCI4CLKEN_MASK)

#define SYSCTRL_SCICLKSEL_SCI5CLKEN_MASK                (0x10000)
#define SYSCTRL_SCICLKSEL_SCI5CLKEN_SHIFT               (16)
#define SYSCTRL_SCICLKSEL_SCI5CLKEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI5CLKEN_SHIFT)) & SYSCTRL_SCICLKSEL_SCI5CLKEN_MASK)

#define SYSCTRL_SCICLKSEL_SCI6CLKEN_MASK                (0x20000)
#define SYSCTRL_SCICLKSEL_SCI6CLKEN_SHIFT               (17)
#define SYSCTRL_SCICLKSEL_SCI6CLKEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SCICLKSEL_SCI6CLKEN_SHIFT)) & SYSCTRL_SCICLKSEL_SCI6CLKEN_MASK)

/*! @} */

/*! @name VDT1/2CON - VDT 1/2 Config Register */
/*! @{ */

#define SYSCTRL_VDTCON_EN_MASK                   (0x1U)
#define SYSCTRL_VDTCON_EN_SHIFT                  (0U)
#define SYSCTRL_VDTCON_EN_SET(x)                     (((uint16_t)(((uint16_t)(x)) << SYSCTRL_VDT1CON_EN_SHIFT)) & SYSCTRL_VDT1CON_EN_MASK)

#define SYSCTRL_VDTCON_RSTEN_MASK                (0x2u)
#define SYSCTRL_VDTCON_RSTEN_SHIFT               (1U)
#define SYSCTRL_VDTCON_RSTEN_SET(x)                  (((uint16_t)(((uint16_t)(x)) <<SYSCTRL_VDT1CON_RSTEN_SHIFT)) & SYSCTRL_VDT1CON_RSTEN_MASK)

#define SYSCTRL_VDTCON_HSYTEN_MASK               (0x4U)
#define SYSCTRL_VDTCON_HSYTEN_SHIFT              (2U)
#define SYSCTRL_VDTCON_HSYTEN_SET(x)                 (((uint16_t)(((uint16_t)(x)) << SYSCTRL_VDT1CON_HSYTEN_SHIFT)) & SYSCTRL_VDT1CON_HSYTEN_MASK)

#define SYSCTRL_VDTCON_EIE_MASK                  (0x20U)
#define SYSCTRL_VDTCON_EIE_SHIFT                 (5U)
#define SYSCTRL_VDTCON_EIE_SET(x)                    (((uint16_t)(((uint16_t)(x)) << SYSCTRL_VDT1CON_EIE_SHIFT)) & SYSCTRL_VDT1CON_EIE_MASK)

#define SYSCTRL_VDTCON_NIE_MASK                  (0x40U)
#define SYSCTRL_VDTCON_NIE_SHIFT                 (6U)
#define SYSCTRL_VDTCON_NIE_SET(x)                    (((uint16_t)(((uint16_t)(x)) << SYSCTRL_VDT1CON_NIE_SHIFT)) & SYSCTRL_VDT1CON_NIE_MASK)

#define SYSCTRL_VDTCON_PIE_MASK                  (0x80U)
#define SYSCTRL_VDTCON_PIE_SHIFT                 (7U)
#define SYSCTRL_VDTCON_PIE_SET(x)                    (((uint16_t)(((uint16_t)(x)) << SYSCTRL_VDT1CON_PIE_SHIFT)) & SYSCTRL_VDT1CON_PIE_MASK)

#define SYSCTRL_VDTCON_EIF_MASK                  (0x100U)
#define SYSCTRL_VDTCON_EIF_SHIFT                 (8U)
#define SYSCTRL_VDTCON_EIF_SET(x)                    (((uint16_t)(((uint16_t)(x)) << SYSCTRL_VDT1CON_EIF_SHIFT)) & SYSCTRL_VDT1CON_EIF_MASK)

#define SYSCTRL_VDTCON_NIF_MASK                  (0x200U)
#define SYSCTRL_VDTCON_NIF_SHIFT                 (9U)
#define SYSCTRL_VDTCON_NIF_SET(x)                    (((uint16_t)(((uint16_t)(x)) << SYSCTRL_VDT1CON_NIF_SHIFT)) & SYSCTRL_VDT1CON_NIF_MASK)

#define SYSCTRL_VDTCON_PIF_MASK                  (0x400U)
#define SYSCTRL_VDTCON_PIF_SHIFT                 (10U)
#define SYSCTRL_VDTCON_PIF_SET(x)                    (((uint16_t)(((uint16_t)(x)) << SYSCTRL_VDT1CON_PIF_SHIFT)) & SYSCTRL_VDT1CON_PIF_MASK)

/*! @} */
/*! @name  -  Register */
/*! @{ */

#define SYSCTRL_SOFTRST1_ADC1RST_MASK             (0x1U)
#define SYSCTRL_SOFTRST1_ADC1RST_SHIFT            (0U)
#define SYSCTRL_SOFTRST1_ADC1RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_ADC1RST_SHIFT)) & SYSCTRL_SOFTRST1_ADC1RST_MASK)

#define SYSCTRL_SOFTRST1_ADC2RST_MASK             (0x2U)
#define SYSCTRL_SOFTRST1_ADC2RST_SHIFT            (1U)
#define SYSCTRL_SOFTRST1_ADC2RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_ADC2RST_SHIFT)) & SYSCTRL_SOFTRST1_ADC2RST_MASK)

#define SYSCTRL_SOFTRST1_ADC3RST_MASK             (0x4U)
#define SYSCTRL_SOFTRST1_ADC3RST_SHIFT            (2U)
#define SYSCTRL_SOFTRST1_ADC3RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_ADC3RST_SHIFT)) & SYSCTRL_SOFTRST1_ADC3RST_MASK)

#define SYSCTRL_SOFTRST1_COMP1RST_MASK             (0x8U)
#define SYSCTRL_SOFTRST1_COMP1RST_SHIFT            (3U)
#define SYSCTRL_SOFTRST1_COMP1RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_COMP1RST_SHIFT)) & SYSCTRL_SOFTRST1_COMP1RST_MASK)

#define SYSCTRL_SOFTRST1_CRCRST_MASK               (0x10U)
#define SYSCTRL_SOFTRST1_CRCRST_SHIFT              (4U)
#define SYSCTRL_SOFTRST1_CRCRST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_CRCRST_SHIFT)) & SYSCTRL_SOFTRST1_CRCRST_MASK)

#define SYSCTRL_SOFTRST1_SPI1RST_MASK             (0x20U)
#define SYSCTRL_SOFTRST1_SPI1RST_SHIFT            (5U)
#define SYSCTRL_SOFTRST1_SPI1RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_SPI1RST_SHIFT)) & SYSCTRL_SOFTRST1_SPI1RST_MASK)

#define SYSCTRL_SOFTRST1_SPI2RST_MASK             (0x40U)
#define SYSCTRL_SOFTRST1_SPI2RST_SHIFT            (6U)
#define SYSCTRL_SOFTRST1_SPI2RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_SPI2RST_SHIFT)) & SYSCTRL_SOFTRST1_SPI2RST_MASK)

#define SYSCTRL_SOFTRST1_SPI3RST_MASK             (0x80U)
#define SYSCTRL_SOFTRST1_SPI3RST_SHIFT            (7U)
#define SYSCTRL_SOFTRST1_SPI3RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_SPI3RST_SHIFT)) & SYSCTRL_SOFTRST1_SPI3RST_MASK)

#define SYSCTRL_SOFTRST1_SPI4RST_MASK             (0x100U)
#define SYSCTRL_SOFTRST1_SPI4RST_SHIFT            (8U)
#define SYSCTRL_SOFTRST1_SPI4RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_SPI4RST_SHIFT)) & SYSCTRL_SOFTRST1_SPI4RST_MASK)

#define SYSCTRL_SOFTRST1_ECAP1RST_MASK             (0x200U)
#define SYSCTRL_SOFTRST1_ECAP1RST_SHIFT            (9U)
#define SYSCTRL_SOFTRST1_ECAP1RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_ECAP1RST_SHIFT)) & SYSCTRL_SOFTRST1_ECAP1RST_MASK)

#define SYSCTRL_SOFTRST1_ECAP2RST_MASK             (0x400U)
#define SYSCTRL_SOFTRST1_ECAP2RST_SHIFT            (10U)
#define SYSCTRL_SOFTRST1_ECAP2RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_ECAP2RST_SHIFT)) & SYSCTRL_SOFTRST1_ECAP2RST_MASK)

#define SYSCTRL_SOFTRST1_ECAP3RST_MASK             (0x800U)
#define SYSCTRL_SOFTRST1_ECAP3RST_SHIFT            (11U)
#define SYSCTRL_SOFTRST1_ECAP3RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_ECAP3RST_SHIFT)) & SYSCTRL_SOFTRST1_ECAP3RST_MASK)

#define SYSCTRL_SOFTRST1_EPWM1RST_MASK             (0x1000U)
#define SYSCTRL_SOFTRST1_EPWM1RST_SHIFT            (12U)
#define SYSCTRL_SOFTRST1_EPWM1RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EPWM1RST_SHIFT)) & SYSCTRL_SOFTRST1_EPWM1RST_MASK)

#define SYSCTRL_SOFTRST1_EPWM2RST_MASK             (0x2000U)
#define SYSCTRL_SOFTRST1_EPWM2RST_SHIFT            (13U)
#define SYSCTRL_SOFTRST1_EPWM2RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EPWM2RST_SHIFT)) & SYSCTRL_SOFTRST1_EPWM2RST_MASK)

#define SYSCTRL_SOFTRST1_EPWM3RST_MASK             (0x4000U)
#define SYSCTRL_SOFTRST1_EPWM3RST_SHIFT            (14U)
#define SYSCTRL_SOFTRST1_EPWM3RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EPWM3RST_SHIFT)) & SYSCTRL_SOFTRST1_EPWM3RST_MASK)

#define SYSCTRL_SOFTRST1_EPWM4RST_MASK             (0x8000U)
#define SYSCTRL_SOFTRST1_EPWM4RST_SHIFT            (15U)
#define SYSCTRL_SOFTRST1_EPWM4RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EPWM4RST_SHIFT)) & SYSCTRL_SOFTRST1_EPWM4RST_MASK)

#define SYSCTRL_SOFTRST1_EPWM5RST_MASK             (0x10000U)
#define SYSCTRL_SOFTRST1_EPWM5RST_SHIFT            (16U)
#define SYSCTRL_SOFTRST1_EPWM5RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EPWM5RST_SHIFT)) & SYSCTRL_SOFTRST1_EPWM5RST_MASK)

#define SYSCTRL_SOFTRST1_EPWM6RST_MASK             (0x20000U)
#define SYSCTRL_SOFTRST1_EPWM6RST_SHIFT            (17U)
#define SYSCTRL_SOFTRST1_EPWM6RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EPWM6RST_SHIFT)) & SYSCTRL_SOFTRST1_EPWM6RST_MASK)

#define SYSCTRL_SOFTRST1_EPWM7RST_MASK             (0x40000U)
#define SYSCTRL_SOFTRST1_EPWM7RST_SHIFT            (18U)
#define SYSCTRL_SOFTRST1_EPWM7RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EPWM7RST_SHIFT)) & SYSCTRL_SOFTRST1_EPWM7RST_MASK)

#define SYSCTRL_SOFTRST_EQEP1RST_MASK             (0x80000U)
#define SYSCTRL_SOFTRST_EQEP1RST_SHIFT            (19U)
#define SYSCTRL_SOFTRST_EQEP1RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_EQEP1RST_SHIFT)) & SYSCTRL_SOFTRST_EQEP1RST_MASK)

#define SYSCTRL_SOFTRST1_EQEP2RST_MASK             (0x100000U)
#define SYSCTRL_SOFTRST1_EQEP2RST_SHIFT            (20U)
#define SYSCTRL_SOFTRST1_EQEP2RST_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EQEP2RST_SHIFT)) & SYSCTRL_SOFTRST1_EQEP2RST_MASK)

#define SYSCTRL_SOFTRST1_EWMRST_MASK               (0x200000U)
#define SYSCTRL_SOFTRST1_EWMRST_SHIFT              (21U)
#define SYSCTRL_SOFTRST1_EWMRST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST1_EWMRST_SHIFT)) & SYSCTRL_SOFTRST1_EWMRST_MASK)

#define SYSCTRL_SOFTRST1_I2C1RST_MASK               (0x800000U)
#define SYSCTRL_SOFTRST1_I2C1RST_SHIFT              (23U)
#define SYSCTRL_SOFTRST1_I2C1RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_I2C1RST_SHIFT)) & SYSCTRL_SOFTRST_I2C1RST_MASK)

#define SYSCTRL_SOFTRST1_I2C2RST_MASK               (0x1000000U)
#define SYSCTRL_SOFTRST1_I2C2RST_SHIFT              (24U)
#define SYSCTRL_SOFTRST1_I2C2RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_I2C2RST_SHIFT)) & SYSCTRL_SOFTRST_I2C2RST_MASK)

#define SYSCTRL_SOFTRST1_SCI1RST_MASK               (0x2000000U)
#define SYSCTRL_SOFTRST1_SCI1RST_SHIFT              (25U)
#define SYSCTRL_SOFTRST1_SCI1RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_SCI1RST_SHIFT)) & SYSCTRL_SOFTRST_SCI1RST_MASK)

#define SYSCTRL_SOFTRST1_SCI2RST_MASK               (0x4000000U)
#define SYSCTRL_SOFTRST1_SCI2RST_SHIFT              (26U)
#define SYSCTRL_SOFTRST1_SCI2RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_SCI2RST_SHIFT)) & SYSCTRL_SOFTRST_SCI2RST_MASK)

#define SYSCTRL_SOFTRST1_SCI3RST_MASK               (0x8000000U)
#define SYSCTRL_SOFTRST1_SCI3RST_SHIFT              (27U)
#define SYSCTRL_SOFTRST1_SCI3RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_SCI3RST_SHIFT)) & SYSCTRL_SOFTRST_SCI3RST_MASK)

#define SYSCTRL_SOFTRST1_SCI4RST_MASK               (0x10000000U)
#define SYSCTRL_SOFTRST1_SCI4RST_SHIFT              (28U)
#define SYSCTRL_SOFTRST1_SCI4RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_SCI4RST_SHIFT)) & SYSCTRL_SOFTRST_SCI4RST_MASK)

#define SYSCTRL_SOFTRST1_SCI5RST_MASK               (0x20000000U)
#define SYSCTRL_SOFTRST1_SCI5RST_SHIFT              (29U)
#define SYSCTRL_SOFTRST1_SCI5RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_SCI5RST_SHIFT)) & SYSCTRL_SOFTRST_SCI5RST_MASK)

#define SYSCTRL_SOFTRST1_SCI6RST_MASK               (0x40000000U)
#define SYSCTRL_SOFTRST1_SCI6RST_SHIFT              (30U)
#define SYSCTRL_SOFTRST1_SCI6RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_SCI6RST_SHIFT)) & SYSCTRL_SOFTRST_SCI6RST_MASK)

#define SYSCTRL_SOFTRST1_MCAN1RST_MASK               (0x80000000U)
#define SYSCTRL_SOFTRST1_MCAN1RST_SHIFT              (31U)
#define SYSCTRL_SOFTRST1_MCAN1RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST_MCAN1RST_SHIFT)) & SYSCTRL_SOFTRST_MCAN1RST_MASK)

/* @} */
/*! @name SOFTRST2 - Software Reset 2 Register */
/*! @{ */
#define SYSCTRL_SOFTRST2_MCAN2RST_MASK               (0x1U)
#define SYSCTRL_SOFTRST2_MCAN2RST_SHIFT              (0U)
#define SYSCTRL_SOFTRST2_MCAN2RST_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_MCAN2RST_SHIFT)) & SYSCTRL_SOFTRST2_MCAN2RST_MASK)

#define SYSCTRL_SOFTRST2_PTIMRST_MASK                (0x2U)
#define SYSCTRL_SOFTRST2_PTIMRST_SHIFT               (1U)
#define SYSCTRL_SOFTRST2_PTIMRST_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_PTIMRST_SHIFT)) & SYSCTRL_SOFTRST2_PTIMRST_MASK)

#define SYSCTRL_SOFTRST2_RCMRST_MASK                (0x4U)
#define SYSCTRL_SOFTRST2_RCMRST_SHIFT               (2U)
#define SYSCTRL_SOFTRST2_RCMRST_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_RCMRST_SHIFT)) & SYSCTRL_SOFTRST2_RCMRST_MASK)

#define SYSCTRL_SOFTRST2_SDFM1RST_MASK                (0x8U)
#define SYSCTRL_SOFTRST2_SDFM1RST_SHIFT               (3U)
#define SYSCTRL_SOFTRST2_SDFM1RST_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_SDFM1RST_SHIFT)) & SYSCTRL_SOFTRST2_SDFM1RST_MASK)

#define SYSCTRL_SOFTRST2_SDFM2RST_MASK                (0x10U)
#define SYSCTRL_SOFTRST2_SDFM2RST_SHIFT               (4U)
#define SYSCTRL_SOFTRST2_SDFM2RST_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_SDFM2RST_SHIFT)) & SYSCTRL_SOFTRST2_SDFM2RST_MASK)

#define SYSCTRL_SOFTRST2_XBARRST_MASK                (0x20U)
#define SYSCTRL_SOFTRST2_XBARRST_SHIFT               (5U)
#define SYSCTRL_SOFTRST2_XBARRST_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_XBARRST_SHIFT)) & SYSCTRL_SOFTRST2_XBARRST_MASK)

#define SYSCTRL_SOFTRST2_XINTRST_MASK                (0x40U)
#define SYSCTRL_SOFTRST2_XINTRST_SHIFT               (6U)
#define SYSCTRL_SOFTRST2_XINTRST_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_XINTRST_SHIFT)) & SYSCTRL_SOFTRST2_XINTRST_MASK)

#define SYSCTRL_SOFTRST2_GPIOA_MASK                  (0x100U)
#define SYSCTRL_SOFTRST2_GPIOA_SHIFT                 (8U)
#define SYSCTRL_SOFTRST2_GPIOA_SET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_GPIOA_SHIFT)) & SYSCTRL_SOFTRST2_GPIOA_MASK)

#define SYSCTRL_SOFTRST2_GPIOB_MASK                  (0x200U)
#define SYSCTRL_SOFTRST2_GPIOB_SHIFT                 (9U)
#define SYSCTRL_SOFTRST2_GPIOB_SET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_GPIOB_SHIFT)) & SYSCTRL_SOFTRST2_GPIOB_MASK)

#define SYSCTRL_SOFTRST2_GPIOC_MASK                  (0x400U)
#define SYSCTRL_SOFTRST2_GPIOC_SHIFT                 (10U)
#define SYSCTRL_SOFTRST2_GPIOC_SET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_GPIOC_SHIFT)) & SYSCTRL_SOFTRST2_GPIOC_MASK)

#define SYSCTRL_SOFTRST2_LPTIMRST_MASK               (0x800U)
#define SYSCTRL_SOFTRST2_LPTIMRST_SHIFT                 (11U)
#define SYSCTRL_SOFTRST2_LPTIMRST_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_SOFTRST2_LPTIMRST_SHIFT)) & SYSCTRL_SOFTRST2_LPTIMRST_MASK)


/* @} */
/*! @name TDTALARM - Temperature Detect Alarm Register*/
/*! @{ */
#define SYSCTRL_TDTALARM_TDEN_MASK                (0x1)
#define SYSCTRL_TDTALARM_TDEN_SHIFT               (0U)
#define SYSCTRL_TDTALARM_TDEN_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_TDEN_SHIFT)) & SYSCTRL_TDTALARM_TDEN_MASK)

#define SYSCTRL_TDTALARM_TSTEN_MASK               (0x4)
#define SYSCTRL_TDTALARM_TSTEN_SHIFT              (2U)
#define SYSCTRL_TDTALARM_TSTEN_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_TSTEN_SHIFT)) & SYSCTRL_TDTALARM_TSTEN_MASK)

#define SYSCTRL_TDTALARM_TSTIN_MASK               (0x8)
#define SYSCTRL_TDTALARM_TSTIN_SHIFT              (3U)
#define SYSCTRL_TDTALARM_TSTIN_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_TSTIN_SHIFT)) & SYSCTRL_TDTALARM_TSTIN_MASK)

#define SYSCTRL_TDTALARM_HTREIE_MASK              (0x10)
#define SYSCTRL_TDTALARM_HTREIE_SHIFT             (4U)
#define SYSCTRL_TDTALARM_HTREIE_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_HTREIE_SHIFT)) & SYSCTRL_TDTALARM_HTREIE_MASK)

#define SYSCTRL_TDTALARM_HTFEIE_MASK              (0x20)
#define SYSCTRL_TDTALARM_HTFEIE_SHIFT             (5U)
#define SYSCTRL_TDTALARM_HTFEIE_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_HTFEIE_SHIFT)) & SYSCTRL_TDTALARM_HTFEIE_MASK)

#define SYSCTRL_TDTALARM_LTREIE_MASK              (0x40)
#define SYSCTRL_TDTALARM_LTREIE_SHIFT             (6U)
#define SYSCTRL_TDTALARM_LTREIE_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_LTREIE_SHIFT)) & SYSCTRL_TDTALARM_LTREIE_MASK)

#define SYSCTRL_TDTALARM_LTFEIE_MASK              (0x80)
#define SYSCTRL_TDTALARM_LTFEIE_SHIFT             (7U)
#define SYSCTRL_TDTALARM_LTFEIE_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_LTFEIE_SHIFT)) & SYSCTRL_TDTALARM_LTFEIE_MASK)

#define SYSCTRL_TDTALARM_ASLTIE_MASK              (0x100)
#define SYSCTRL_TDTALARM_ASLTIE_SHIFT             (8U)
#define SYSCTRL_TDTALARM_ASLTIE_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_ASLTIE_SHIFT)) & SYSCTRL_TDTALARM_ASLTIE_MASK)

#define SYSCTRL_TDTALARM_ASHTIE_MASK              (0x200)
#define SYSCTRL_TDTALARM_ASHTIE_SHIFT             (9U)
#define SYSCTRL_TDTALARM_ASHTIE_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_ASHTIE_SHIFT)) & SYSCTRL_TDTALARM_ASHTIE_MASK)

#define SYSCTRL_TDTALARM_ALARML_STS_MASK          (0x400)
#define SYSCTRL_TDTALARM_ALARML_STS_SHIFT         (10U)
#define SYSCTRL_TDTALARM_ALARML_STS_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_ALARML_STS_SHIFT)) & SYSCTRL_TDTALARM_ALARML_STS_MASK)

#define SYSCTRL_TDTALARM_ALARMH_STS_MASK          (0x800)
#define SYSCTRL_TDTALARM_ALARMH_STS_SHIFT         (11U)
#define SYSCTRL_TDTALARM_ALARMH_STS_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTRL_TDTALARM_ALARMH_STS_SHIFT)) & SYSCTRL_TDTALARM_ALARMH_STS_MASK)

/*! @} */
/*! @name ADCSOCOUTSEL - ADCSOC Out Select Register */
/*! @{ */
#define SYSCTRL_ADCSOCOUTSEL_PWM1SOCAEN_MASK    (1)
#define SYSCTRL_ADCSOCOUTSEL_PWM1SOCAEN_SHIFT   (0)
#define SYSCTRL_ADCSOCOUTSEL_PWM1SOCAEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM1SOCAEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM1SOCAEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM2SOCAEN_MASK    (2)
#define SYSCTRL_ADCSOCOUTSEL_PWM2SOCAEN_SHIFT   (1)
#define SYSCTRL_ADCSOCOUTSEL_PWM2SOCAEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM2SOCAEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM2SOCAEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM3SOCAEN_MASK    (4)
#define SYSCTRL_ADCSOCOUTSEL_PWM3SOCAEN_SHIFT   (2)
#define SYSCTRL_ADCSOCOUTSEL_PWM3SOCAEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM3SOCAEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM3SOCAEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM4SOCAEN_MASK    (8)
#define SYSCTRL_ADCSOCOUTSEL_PWM4SOCAEN_SHIFT   (3)
#define SYSCTRL_ADCSOCOUTSEL_PWM4SOCAEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM4SOCAEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM4SOCAEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM5SOCAEN_MASK    (0x10)
#define SYSCTRL_ADCSOCOUTSEL_PWM5SOCAEN_SHIFT   (4)
#define SYSCTRL_ADCSOCOUTSEL_PWM5SOCAEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM5SOCAEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM5SOCAEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM6SOCAEN_MASK    (0x20)
#define SYSCTRL_ADCSOCOUTSEL_PWM6SOCAEN_SHIFT   (5)
#define SYSCTRL_ADCSOCOUTSEL_PWM6SOCAEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM6SOCAEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM6SOCAEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM7SOCAEN_MASK    (0x40)
#define SYSCTRL_ADCSOCOUTSEL_PWM7SOCAEN_SHIFT   (6)
#define SYSCTRL_ADCSOCOUTSEL_PWM7SOCAEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM7SOCAEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM7SOCAEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM1SOCBEN_MASK    (0x100)
#define SYSCTRL_ADCSOCOUTSEL_PWM1SOCBEN_SHIFT   (8)
#define SYSCTRL_ADCSOCOUTSEL_PWM1SOCBEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM1SOCBEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM1SOCBEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM2SOCBEN_MASK    (0x200)
#define SYSCTRL_ADCSOCOUTSEL_PWM2SOCBEN_SHIFT   (9)
#define SYSCTRL_ADCSOCOUTSEL_PWM2SOCBEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM2SOCBEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM2SOCBEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM3SOCBEN_MASK    (0x400)
#define SYSCTRL_ADCSOCOUTSEL_PWM3SOCBEN_SHIFT   (10)
#define SYSCTRL_ADCSOCOUTSEL_PWM3SOCBEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM3SOCBEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM3SOCBEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM4SOCBEN_MASK    (0x800)
#define SYSCTRL_ADCSOCOUTSEL_PWM4SOCBEN_SHIFT   (11)
#define SYSCTRL_ADCSOCOUTSEL_PWM4SOCBEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM4SOCBEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM4SOCBEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM5SOCBEN_MASK    (0x1000)
#define SYSCTRL_ADCSOCOUTSEL_PWM5SOCBEN_SHIFT   (12)
#define SYSCTRL_ADCSOCOUTSEL_PWM5SOCBEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM5SOCBEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM5SOCBEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM6SOCBEN_MASK    (0x2000)
#define SYSCTRL_ADCSOCOUTSEL_PWM6SOCBEN_SHIFT   (13)
#define SYSCTRL_ADCSOCOUTSEL_PWM6SOCBEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM6SOCBEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM6SOCBEN_MASK)

#define SYSCTRL_ADCSOCOUTSEL_PWM7SOCBEN_MASK    (0x4000)
#define SYSCTRL_ADCSOCOUTSEL_PWM7SOCBEN_SHIFT   (14)
#define SYSCTRL_ADCSOCOUTSEL_PWM7SOCBEN_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_ADCSOCOUTSEL_PWM7SOCBEN_SHIFT)) & SYSCTRL_ADCSOCOUTSEL_PWM7SOCBEN_MASK)

/*! @} */
/*! @name FESR - Flash ECC Status Register */
/*! @{ */

#define SYSCTRL_FESR_DFDIF_MASK                   (2U)
#define SYSCTRL_FESR_DFDIF_SHIFT                  (1U)
#define SYSCTRL_FESR_DFDIF_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTRL_FESR_DFDIF_SHIFT)) & SYSCTRL_FESR_DFDIF_MASK)

/*! @} */

/*! @name FESR - Flash ECC Config Register */
/*! @{ */

#define SYSCTRL_FECR_DFDIE_MASK                   (2U)
#define SYSCTRL_FECR_DFDIE_SHIFT                  (1U)
#define SYSCTRL_FECR_DFDIE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTRL_FECR_DFDIE_SHIFT)) & SYSCTRL_FECR_DFDIE_MASK)

#define SYSCTRL_FECR_FDFD_MASK                    (0x80)
#define SYSCTRL_FECR_FDFD_SHIFT                   (7U)
#define SYSCTRL_FECR_FDFD_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTRL_FECR_FDFD_SHIFT)) & SYSCTRL_FECR_FDFD_MASK)

/*! @} */

/*! @name FESR - Flash ECC Enable Register */
/*! @{ */

#define SYSCTRL_FEER_ECC_ENABLE_MASK              (2U)
#define SYSCTRL_FEER_ECC_ENABLE_SHIFT             (1U)
#define SYSCTRL_FEER_ECC_ENABLE_SET(x)                (((uint16_t)(((uint16_t)(x)) << SYSCTRL_FEER_ECC_ENABLE_SHIFT)) & SYSCTRL_FEER_ECC_ENABLE_MASK)

/*! @} */
/*!
 * @}
 */ /* end of group SYSCTRL_Register_Masks */


/* SYSCTRL - Peripheral instance base addresses */
/** Peripheral SYSCTRL base address */
#define SYSCTRL_BASE                                 (0x40048000u)
/** Peripheral SYSCTRL base pointer */
#define SYSCTRL                                      ((SYSCTRL_Type *)SYSCTRL_BASE)
/** Array initializer of SYSCTRL peripheral base addresses */
#define SYSCTRL_BASE_ADDRS                           { SYSCTRL_BASE }
/** Array initializer of SYSCTRL peripheral base pointers */
#define SYSCTRL_BASE_PTRS                            { SYSCTRL }


/*!
 * @}
 */ /* end of group SYSCTRL_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- PTIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PTIM_Peripheral_Access_Layer PTIM Peripheral Access Layer
 * @{
 */

/** PTIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< PTIM Module Control Register, offset: 0x0 */
       uint8_t RESERVED_0[220];
  __I  uint32_t LTMR64H;                           /**< PTIM Upper Lifetime Timer Register, offset: 0xE0 */
  __I  uint32_t LTMR64L;                           /**< PTIM Lower Lifetime Timer Register, offset: 0xE4 */
       uint8_t RESERVED_1[24];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t LDVAL;                             /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    __IO uint32_t TFLG;                              /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[4];
} PTIM_Type;



/* ----------------------------------------------------------------------------
   -- PTIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PTIM_Register_Masks PTIM Register Masks
 * @{
 */

/*! @name TCTRL - Timer Control Register */
/*! @{ */

#define PTIM_TCTRL_TEN_MASK                       (0x1U)
#define PTIM_TCTRL_TEN_SHIFT                      (0U)
/*! TEN - Timer Enable
 *  0b0..Timer n is disabled.

 *  0b1..Timer n is enabled.
 */
#define PTIM_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x)) << PTIM_TCTRL_TEN_SHIFT)) & PTIM_TCTRL_TEN_MASK)

#define PTIM_TCTRL_TIE_MASK                       (0x2U)
#define PTIM_TCTRL_TIE_SHIFT                      (1U)
/*! TIE - Timer Interrupt Enable
 *  0b0..Interrupt requests from Timer n are disabled.
 *  0b1..Interrupt will be requested whenever TIF is set.
 */
#define PTIM_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x)) << PTIM_TCTRL_TIE_SHIFT)) & PTIM_TCTRL_TIE_MASK)

#define PTIM_TCTRL_CHN_MASK                       (0x4U)
#define PTIM_TCTRL_CHN_SHIFT                      (2U)
/*! CHN - Chain Mode
 *  0b0..Timer is not chained.
 *  0b1..Timer is chained to previous timer. For example, for Channel 2, if this field is set, Timer 2 is chained to Timer 1.
 */
#define PTIM_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x)) << PTIM_TCTRL_CHN_SHIFT)) & PTIM_TCTRL_CHN_MASK)


/* The count of PTIM_TCTRL */
#define PTIM_TCTRL_COUNT                          (4U)

/*! @name CVAL - Current Timer Value Register */
/*! @{ */

#define PTIM_CVAL_TVL_MASK                        (0xFFFFFFFFU)
#define PTIM_CVAL_TVL_SHIFT                       (0U)
/*! TVL - Current Timer Value

 */
#define PTIM_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x)) << PTIM_CVAL_TVL_SHIFT)) & PTIM_CVAL_TVL_MASK)
/*! @} */

/* The count of PTIM_CVAL */
#define PTIM_CVAL_COUNT                           (4U)

/*! @name LDVAL - Timer Load Value Register */
/*! @{ */

#define PTIM_LDVAL_TSV_MASK                       (0xFFFFFFFFU)
#define PTIM_LDVAL_TSV_SHIFT                      (0U)
/*! TSV - Timer Start Value
 */
#define PTIM_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x)) << PTIM_LDVAL_TSV_SHIFT)) & PTIM_LDVAL_TSV_MASK)
/*! @} */

/* The count of PTIM_LDVAL */
#define PTIM_LDVAL_COUNT                          (4U)

/*! @name TFLG - Timer Flag Register */
/*! @{ */

#define PTIM_TFLG_TIF_MASK                        (0x1U)
#define PTIM_TFLG_TIF_SHIFT                       (0U)
/*! TIF - Timer Interrupt Flag
 *  0b0..Timeout has not yet occurred.
 *  0b1..Timeout has occurred.

 */
#define PTIM_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << PTIM_TFLG_TIF_SHIFT)) & PTIM_TFLG_TIF_MASK)
/*! @} */

/* The count of PTIM_TFLG */
#define PTIM_TFLG_COUNT                           (4U)
/*! @} */



/*! @name MCR - PTIM Module Control Register */
/*! @{ */

#define PTIM_MCR_FRZ_MASK                         (0x1U)
#define PTIM_MCR_FRZ_SHIFT                        (0U)
/*! FRZ - Freeze
 *  0b0..Timers continue to run in Debug mode.
 *  0b1..Timers are stopped in Debug mode.
 */
#define PTIM_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << PTIM_MCR_FRZ_SHIFT)) & PTIM_MCR_FRZ_MASK)

#define PTIM_MCR_MDIS_MASK                        (0x2U)
#define PTIM_MCR_MDIS_SHIFT                       (1U)
/*! MDIS - Module Disable - (PTIM section)
 *  0b0..Clock for standard PTIM timers is enabled.
 *  0b1..Clock for standard PTIM timers is disabled.
 */
#define PTIM_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << PTIM_MCR_MDIS_SHIFT)) & PTIM_MCR_MDIS_MASK)
/*! @} */

/*! @name LTMR64H - PTIM Upper Lifetime Timer Register */
/*! @{ */

#define PTIM_LTMR64H_LTH_MASK                     (0xFFFFFFFFU)
#define PTIM_LTMR64H_LTH_SHIFT                    (0U)
/*! LTH - Life Timer value
 */
#define PTIM_LTMR64H_LTH(x)                       (((uint32_t)(((uint32_t)(x)) << PTIM_LTMR64H_LTH_SHIFT)) & PTIM_LTMR64H_LTH_MASK)
/*! @} */

/*! @name LTMR64L - PTIM Lower Lifetime Timer Register */
/*! @{ */

#define PTIM_LTMR64L_LTL_MASK                     (0xFFFFFFFFU)
#define PTIM_LTMR64L_LTL_SHIFT                    (0U)
/*! LTL - Life Timer value
 */
#define PTIM_LTMR64L_LTL(x)                       (((uint32_t)(((uint32_t)(x)) << PTIM_LTMR64L_LTL_SHIFT)) & PTIM_LTMR64L_LTL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PTIM_Register_Masks */


/* PTIM - Peripheral instance base addresses */
/** Peripheral PTIM base address */
#define PTIM_BASE                                 (0x40037000u)
/** Peripheral PTIM base pointer */
#define PTIM                                      ((PTIM_Type *)PTIM_BASE)
/** Array initializer of PTIM peripheral base addresses */
#define PTIM_BASE_ADDRS                           { PTIM_BASE }
/** Array initializer of PTIM peripheral base pointers */
#define PTIM_BASE_PTRS                            { PTIM }
/** Interrupt vectors for the PTIM peripheral type */
#define PTIM_IRQS                                 { { PTIM0_IRQn, PTIM1_IRQn, PTIM2_IRQn, PTIM3_IRQn } }

/*!
 * @}
 */ /* end of group PTIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPTIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTIM_Peripheral_Access_Layer LPTIM Peripheral Access Layer
 * @{
 */

/** LPTIM - Register Layout Typedef */
typedef struct {
  __IO  uint32_t CSR;                               /**< LPTIM Module Low Power Timer Control Status Register, offset: 0x0 */
  __IO  uint32_t PSR;                               /**< Low Power Timer Prescale Register, offset: 0x04 */
  __IO  uint32_t CMR;                               /**< Low Power Timer Compare Register, offset: 0x08 */
  __IO  uint32_t CNR;                               /**< Low Power Timer Counter Register, offset: 0x0C */
} LPTIM_Type;

/* ----------------------------------------------------------------------------
   -- LPTIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTIM_Register_Masks LPTIM Register Masks
 * @{
 */

/*! @name CSR - LPTIM Module Control Status Register */
/*! @{ */

#define LPTIM_CSR_TEN_MASK                         (0x1U)
#define LPTIM_CSR_TEN_SHIFT                        (0U)
/*! TEN - timer Enable 
 *  0b0..LPTIM is disabled and internal logic is reset.
 *  0b1..LPTIM is enabled.
 */
#define LPTIM_CSR_TEN_SET(x)                           (((uint32_t)(((uint32_t)(x)) << LPTIM_CSR_TEN_SHIFT)) & LPTIM_CSR_TEN_MASK)


#define LPTIM_CSR_TMS_MASK                        (0x2U)
#define LPTIM_CSR_TMS_SHIFT                       (1U)
/*! TMS - Timer Mode Select
 *  0b0..Time Counter mode.
 *  0b1..Pulse Counter mode.
 */
#define LPTIM_CSR_TMS_SET(x)                          (((uint32_t)(((uint32_t)(x)) << LPTIM_CSR_TMS_SHIFT)) & LPTIM_CSR_TMS_MASK)


#define LPTIM_CSR_TFC_MASK                        (0x4U)
#define LPTIM_CSR_TFC_SHIFT                       (2U)
/*! TFC - Timer Free-Running Counter
 *  0b0..CNR is reset whenever TCF is set.
 *  0b1..CNR is reset on overflow.
 */
#define LPTIM_CSR_TFC_SET(x)                          (((uint32_t)(((uint32_t)(x)) << LPTIM_CSR_TFC_SHIFT)) & LPTIM_CSR_TFC_MASK)


#define LPTIM_CSR_TPP_MASK                        (0x8U)
#define LPTIM_CSR_TPP_SHIFT                       (3U)
/*! TPP - Timer Pin Polarity
 *  0b0..Pulse Counter input source is active-high, and the CNR will increment on the rising-edge.
 *  0b1..Pulse Counter input source is active-low, and the CNR will increment on the falling-edge.
 */
#define LPTIM_CSR_TPP_SET(x)                          (((uint32_t)(((uint32_t)(x)) << LPTIM_CSR_TPP_SHIFT)) & LPTIM_CSR_TPP_MASK)




#define LPTIM_CSR_TPS_MASK                        (0x30U)
#define LPTIM_CSR_TPS_SHIFT                       (4U)
/*! TPS - Timer Pin Select
 *  0b00..Pulse counter input 0 is selected.
 *  0b01..Pulse counter input 1 is selected.
 *  0b10..Pulse counter input 2 is selected.
 *  0b11..Pulse counter input 3 is selected.
 */
#define LPTIM_CSR_TPS_SET(x)                          (((uint32_t)(((uint32_t)(x)) << LPTIM_CSR_TPS_SHIFT)) & LPTIM_CSR_TPS_MASK)


#define LPTIM_CSR_TIE_MASK                        (0x40U)
#define LPTIM_CSR_TIE_SHIFT                       (6U)
/*! TIE - Timer Interrupt Enable
 *  0b0..Timer interrupt disabled.
 *  0b1..Timer interrupt enabled.
 */
#define LPTIM_CSR_TIE_SET(x)                          (((uint32_t)(((uint32_t)(x)) << LPTIM_CSR_TIE_SHIFT)) & LPTIM_CSR_TIE_MASK)

#define LPTIM_CSR_TCF_MASK                        (0x80U)
#define LPTIM_CSR_TCF_SHIFT                       (7U)
/*! TCF - Timer Compare Flag
 *  0b0..The value of CNR is not equal to CMR and increments.
 *  0b1..The value of CNR is equal to CMR and increments.
 */
#define LPTIM_CSR_TCF_SET(x)                          (((uint32_t)(((uint32_t)(x)) << LPTIM_CSR_TCF_SHIFT)) & LPTIM_CSR_TCF_MASK)

/*! @} */

/*! @name PSR - LPTIM Module Low Power Timer Prescale Register  */
/*! @{ */

#define LPTIM_PSR_PCS_MASK                     (0x03U)
#define LPTIM_PSR_PCS_SHIFT                    (0U)
/*! PCS - Prescaler Clock Select
 *  0b00..Prescaler/glitch filter clock 0 selected.
 *  0b01..Prescaler/glitch filter clock 1 selected.
 *  0b10..Prescaler/glitch filter clock 2 selected.
 *  0b11..Prescaler/glitch filter clock 3 selected.
 */
#define LPTIM_PSR_PCS_SET(x)                       (((uint32_t)(((uint32_t)(x)) << LPTIM_PSR_PCS_SHIFT)) & LPTIM_PSR_PCS_MASK)

#define LPTIM_PSR_PBYP_MASK                     (0x04U)
#define LPTIM_PSR_PBYP_SHIFT                    (2U)
/*! PBYP - Prescaler Bypass
 *  0b0..Prescaler/glitch filter is enabled.
 *  0b1..Prescaler/glitch filter is bypassed.
 */
#define LPTIM_PSR_PBYP_SET(x)                       (((uint32_t)(((uint32_t)(x)) << LPTIM_PSR_PBYP_SHIFT)) & LPTIM_PSR_PBYP_MASK)

#define LPTIM_PSR_PRESCALE_MASK                     (0x78U)
#define LPTIM_PSR_PRESCALE_SHIFT                    (3U)
/*! PBYP - Prescale Value
 *  0b0000..Prescaler divides the prescaler clock by 2; glitch filter does not support this configuration.
 *  0b0001..Prescaler divides the prescaler clock by 4; glitch filter recognizes change on input pin after 2 rising clock edges.
 *  0b0010..Prescaler divides the prescaler clock by 8; glitch filter recognizes change on input pin after 4 rising clock edges.
 *  0b0011..Prescaler divides the prescaler clock by 16; glitch filter recognizes change on input pin after 8 rising clock edges.
 *  0b0100..Prescaler divides the prescaler clock by 32; glitch filter recognizes change on input pin after 16 rising clock edges.
 *  0b0101..Prescaler divides the prescaler clock by 64; glitch filter recognizes change on input pin after 32 rising clock edges.
 *  0b0110..Prescaler divides the prescaler clock by 128; glitch filter recognizes change on input pin after 64 rising clock edges.
 *  0b0111..Prescaler divides the prescaler clock by 256; glitch filter recognizes change on input pin after 128 rising clock edges.
 *  0b1000..Prescaler divides the prescaler clock by 512; glitch filter recognizes change on input pin after 256 rising clock edges.
 *  0b1001..Prescaler divides the prescaler clock by 1024; glitch filter recognizes change on input pin after 512 rising clock edges.
 *  0b1010..Prescaler divides the prescaler clock by 2048; glitch filter recognizes change on input pin after 1024 rising clock edges.
 *  0b1011..Prescaler divides the prescaler clock by 4096; glitch filter recognizes change on input pin after 2048 rising clock edges.
 *  0b1100..Prescaler divides the prescaler clock by 8192; glitch filter recognizes change on input pin after 4096 rising clock edges.
 *  0b1101..Prescaler divides the prescaler clock by 16,384; glitch filter recognizes change on input pin after 8192 rising clock edges.
 *  0b1110..Prescaler divides the prescaler clock by 32,768; glitch filter recognizes change on input pin after 16384 rising clock edges.
 *  0b1111..Prescaler divides the prescaler clock by 65,536; glitch filter recognizes change on input pin after 32768 rising clock edges.
 */
#define LPTIM_PSR_PRESCALE_SET(x)                       (((uint32_t)(((uint32_t)(x)) << LPTIM_PSR_PRESCALE_SHIFT)) & LPTIM_PSR_PRESCALE_MASK)

/*! @} */

/*! @name CMR - LPTIM Module Low Power Timer Compare Register*/ 
/*! @{ */

#define LPTIM_CMR_COMPARE_MASK                     (0x0000FFFFU)
#define LPTIM_CMR_COMPARE_SHIFT                    (0U)
/*! COMPARE - Compare Value
 */
#define LPTIM_CMR_COMPARE_SET(x)                       (((uint32_t)(((uint32_t)(x)) << LPTIM_CMR_COMPARE_SHIFT)) & LPTIM_CMR_COMPARE_MASK)
/*! @} */


/*! @} */

/*! @name CNR - LPTIM Module Low Power Timer Counter Register*/ 
/*! @{ */

#define LPTIM_CNR_COUNTER_MASK                     (0x0000FFFFU)
#define LPTIM_CNR_COUNTER_SHIFT                    (0U)
/*! COUNTER - Counter Value
 */
#define LPTIM_CNR_COUNTER_SET(x)                       (((uint32_t)(((uint32_t)(x)) << LPTIM_CNR_COUNTER_SHIFT)) & LPTIM_CNR_COUNTER_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LPTIM_Register_Masks */


/* LPTIM - Peripheral instance base addresses */
/** Peripheral LPTIM base address */
#define LPTIM_BASE                                 (0x40022000u)
/** Peripheral LPTIM base pointer */
#define LPTIM                                      ((LPTIM_Type *)LPTIM_BASE)
/** Array initializer of LPTIM peripheral base addresses */
#define LPTIM_BASE_ADDRS                           { LPTIM_BASE }
/** Array initializer of LPTIM peripheral base pointers */
#define LPTIM_BASE_PTRS                            { LPTIM }
/** Interrupt vectors for the LPTIM peripheral type */
#define LPTIM_IRQS                                 { LPTIM_IRQn }

/*!
 * @}
 */ /* end of group LPTIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCR[32];                           /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  __O  uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __O  uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
       uint8_t RESERVED_0[24];
  __IO uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
       uint8_t RESERVED_1[28];
  __IO uint32_t DFER;                              /**< Digital Filter Enable Register, offset: 0xC0 */
  __IO uint32_t DFCR;                              /**< Digital Filter Clock Register, offset: 0xC4 */
  __IO uint32_t DFWR;                              /**< Digital Filter Width Register, offset: 0xC8 */
} PORT_Type;

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/*! @name PCR - Pin Control Register n */
/*! @{ */

#define PORT_PCR_PU_MASK                         (0x1U)
#define PORT_PCR_PU_SHIFT                        (0U)
/*! PU - Pull Up
 *  0b0..Internal pullup resistor is not enable on the corresponding pin.
 *  0b1..Internal pullup resistor is enabled on the corresponding pin.
 */
#define PORT_PCR_PU_SET(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PU_SHIFT)) & PORT_PCR_PU_MASK)

#define PORT_PCR_PD_MASK                         (0x2U)
#define PORT_PCR_PD_SHIFT                        (1U)
/*! PD - Pull Down
 *  0b0..Internal pulldown resistor is not enabled on the corresponding pin.
 *  0b0..Internal pulldown resistor is enabled on the corresponding pin.
 */
#define PORT_PCR_PD_SET(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PD_SHIFT)) & PORT_PCR_PD_MASK)

#define PORT_PCR_SRE_MASK                        (0x4U)
#define PORT_PCR_SRE_SHIFT                       (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output.
 *  0b1..Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output.
 */
#define PORT_PCR_SRE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PCR_SRE_SHIFT)) & PORT_PCR_SRE_MASK)

#define PORT_PCR_CSE_MASK                        (0x08U)
#define PORT_PCR_CSE_SHIFT                       (3U)
/*! CSE - Input Schmitt trig enable
 *  0b0..Input Schmitt trig diaable
 *  0b1..Input Schmitt trig enable
 *       Refer to the device data sheet for filter characteristics.
 */
#define PORT_PCR_CSE_SET(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_PCR_CSE_SHIFT)) & PORT_PCR_CSE_MASK)

#define PORT_PCR_IE_MASK                        (0x10U)
#define PORT_PCR_IE_SHIFT                       (4U)
/*! IE - Input Enable
 *  0b0..
 *  0b1..
 */
#define PORT_PCR_IE_SET(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IE_SHIFT)) & PORT_PCR_IE_MASK)

#define PORT_PCR_ODE_MASK                        (0x20U)
#define PORT_PCR_ODE_SHIFT                       (5U)
/*! ODE - Open Drain Enable
 *  0b0...
 *  0b1...
 */
#define PORT_PCR_ODE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ODE_SHIFT)) & PORT_PCR_ODE_MASK)

#define PORT_PCR_OSE_MASK                        (0x40U)
#define PORT_PCR_OSE_SHIFT                       (6U)
/*! OSE - Open Source Enable
 *  0b0...
 *  0b1...
 */
#define PORT_PCR_OSE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PCR_OSE_SHIFT)) & PORT_PCR_OSE_MASK)

#define PORT_PCR_DRE_MASK                        (0x80U)
#define PORT_PCR_DRE_SHIFT                       (7U)
/*! DRE - Drive Strength Enable
 *  0b0...
 *  0b1...
 */
#define PORT_PCR_DRE_SET(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PCR_DRE_SHIFT)) & PORT_PCR_DRE_MASK)



#define PORT_PCR_MUX_MASK                        (0x700U)
#define PORT_PCR_MUX_SHIFT                       (8U)
/*! MUX - Pin Mux Control
 *  0b000..Pin disabled (analog).
 *  0b001..Alternative 1 (GPIO).
 *  0b010..Alternative 2 (chip-specific).
 *  0b011..Alternative 3 (chip-specific).
 *  0b100..Alternative 4 (chip-specific).
 *  0b101..Alternative 5 (chip-specific).
 *  0b110..Alternative 6 (chip-specific).
 *  0b111..Alternative 7 (chip-specific).
 */
#define PORT_PCR_MUX_SET(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)

#define PORT_PCR_LK_MASK                         (0x8000U)
#define PORT_PCR_LK_SHIFT                        (15U)
/*! LK - Lock Register
 *  0b0..Pin Control Register fields [15:0] are not locked.
 *  0b1..Pin Control Register fields [15:0] are locked and cannot be updated until the next system reset.
 */
#define PORT_PCR_LK_SET(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_LK_SHIFT)) & PORT_PCR_LK_MASK)


#define PORT_PCR_IRQC_MASK                       (0xF0000U)
#define PORT_PCR_IRQC_SHIFT                      (16U)
/*! IRQC - Interrupt Configuration
 *  0b0000..Interrupt Status Flag (ISF) is disabled.
 *  0b0001..ISF flag and DMA request on rising edge.
 *  0b0010..ISF flag and DMA request on falling edge.
 *  0b0011..ISF flag and DMA request on either edge.
 *  0b0100..Reserved.
 *  0b0101..Reserved.
 *  0b0110..Reserved.
 *  0b0111..Reserved.
 *  0b1000..ISF flag and Interrupt when logic 0.
 *  0b1001..ISF flag and Interrupt on rising-edge.
 *  0b1010..ISF flag and Interrupt on falling-edge.
 *  0b1011..ISF flag and Interrupt on either edge.
 *  0b1100..ISF flag and Interrupt when logic 1.
 *  0b1101..Reserved.
 *  0b1110..Reserved.
 *  0b1111..Reserved.
 */
#define PORT_PCR_IRQC_SET(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IRQC_SHIFT)) & PORT_PCR_IRQC_MASK)

#define PORT_PCR_ISF_MASK                        (0x1000000U)
#define PORT_PCR_ISF_SHIFT                       (24U)
/*! ISF - Interrupt Status Flag
 *  0b0..Configured interrupt is not detected.
 *  0b1..Configured interrupt is detected. If the pin is configured to generate a DMA request, then the
 *       corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the
 *       flag remains set until a logic 1 is written to the flag. If the pin is configured for a level sensitive
 *       interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.
 */
#define PORT_PCR_ISF_SET(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ISF_SHIFT)) & PORT_PCR_ISF_MASK)
/*! @} */


/* The count of PORT_PCR */
#define PORT_PCR_COUNT                           (32U)

/*! @name GPCLR - Global Pin Control Low Register */
/*! @{ */

#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCLR_GPWD_SHIFT                    (0U)
/*! GPWD - Global Pin Write Data
 */
#define PORT_GPCLR_GPWD_SET(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWD_SHIFT)) & PORT_GPCLR_GPWD_MASK)

#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)
#define PORT_GPCLR_GPWE_SHIFT                    (16U)
/*! GPWE - Global Pin Write Enable
 *  0b0000000000000000..Corresponding Pin Control Register is not updated with the value in GPWD.
 *  0b0000000000000001..Corresponding Pin Control Register is updated with the value in GPWD.
 */
#define PORT_GPCLR_GPWE_SET(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE_SHIFT)) & PORT_GPCLR_GPWE_MASK)
/*! @} */

/*! @name GPCHR - Global Pin Control High Register */
/*! @{ */

#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCHR_GPWD_SHIFT                    (0U)
/*! GPWD - Global Pin Write Data
 */
#define PORT_GPCHR_GPWD_SET(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWD_SHIFT)) & PORT_GPCHR_GPWD_MASK)

#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)
#define PORT_GPCHR_GPWE_SHIFT                    (16U)
/*! GPWE - Global Pin Write Enable
 *  0b0000000000000000..Corresponding Pin Control Register is not updated with the value in GPWD.
 *  0b0000000000000001..Corresponding Pin Control Register is updated with the value in GPWD.
 */
#define PORT_GPCHR_GPWE_SET(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE_SHIFT)) & PORT_GPCHR_GPWE_MASK)
/*! @} */

/*! @name ISFR - Interrupt Status Flag Register */
/*! @{ */

#define PORT_ISFR_ISF_MASK                       (0xFFFFFFFFU)
#define PORT_ISFR_ISF_SHIFT                      (0U)
/*! ISF - Interrupt Status Flag
 *  0b00000000000000000000000000000000..Configured interrupt is not detected.
 *  0b00000000000000000000000000000001..Configured interrupt is detected. If the pin is configured to generate a
 *                                      DMA request, then the corresponding flag will be cleared automatically at
 *                                      the completion of the requested DMA transfer. Otherwise, the flag remains set
 *                                      until a logic 1 is written to the flag. If the pin is configured for a
 *                                      level sensitive interrupt and the pin remains asserted, then the flag is set
 *                                      again immediately after it is cleared.
 */
#define PORT_ISFR_ISF_SET(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_ISFR_ISF_SHIFT)) & PORT_ISFR_ISF_MASK)
/*! @} */

/*! @name DFER - Digital Filter Enable Register */
/*! @{ */

#define PORT_DFER_DFE_MASK                       (0xFFFFFFFFU)
#define PORT_DFER_DFE_SHIFT                      (0U)
/*! DFE - Digital Filter Enable
 *  0b00000000000000000000000000000000..Digital filter is disabled on the corresponding pin and output of the digital filter is reset to zero.
 *  0b00000000000000000000000000000001..Digital filter is enabled on the corresponding pin, if the pin is configured as a digital input.
 */
#define PORT_DFER_DFE_SET(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_DFER_DFE_SHIFT)) & PORT_DFER_DFE_MASK)
/*! @} */

/*! @name DFCR - Digital Filter Clock Register */
/*! @{ */

#define PORT_DFCR_CS_MASK                        (0x1U)
#define PORT_DFCR_CS_SHIFT                       (0U)
/*! CS - Clock Source
 *  0b0..Digital filters are clocked by the bus clock.
 *  0b1..Digital filters are clocked by the LPO clock.
 */
#define PORT_DFCR_CS_SET(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_DFCR_CS_SHIFT)) & PORT_DFCR_CS_MASK)
/*! @} */

/*! @name DFWR - Digital Filter Width Register */
/*! @{ */

#define PORT_DFWR_FILT_MASK                      (0x1FU)
#define PORT_DFWR_FILT_SHIFT                     (0U)
/*! FILT - Filter Length
 */
#define PORT_DFWR_FILT_SET(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_DFWR_FILT_SHIFT)) & PORT_DFWR_FILT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40049000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, }
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_IRQn, PORTB_IRQn, PORTC_IRQn }

/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Peripheral_Access_Layer RCM Peripheral Access Layer
 * @{
 */

/** RCM - Register Layout Typedef */
typedef struct {
  __I  uint8_t SRS0;                               /**< System Reset Status Register 0, offset: 0x0 */
  __I  uint8_t SRS1;                               /**< System Reset Status Register 1, offset: 0x1 */
       uint8_t RESERVED_0[2];
  __IO uint8_t RPFC;                               /**< Reset Pin Filter Control register, offset: 0x4 */
  __IO uint8_t RPFW;                               /**< Reset Pin Filter Width register, offset: 0x5 */
       uint8_t RESERVED_1[2];
  __IO uint8_t SSRS0;                              /**< Sticky System Reset Status Register 0, offset: 0x8 */
  __IO uint8_t SSRS1;                              /**< Sticky System Reset Status Register 1, offset: 0x9 */
} RCM_Type;

/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/*! @name SRS0 - System Reset Status Register 0 */
/*! @{ */

#define RCM_SRS0_VDT_MASK                        (0x2U)
#define RCM_SRS0_VDT_SHIFT                       (1U)
/*! LVD - Low-Voltage Detect Reset
 *  0b0..Reset not caused by LVD trip or POR
 *  0b1..Reset caused by LVD trip or POR
 */
#define RCM_SRS0_VDT_SET(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_VDT_SHIFT)) & RCM_SRS0_VDT_MASK)

#define RCM_SRS0_WWDT_MASK                       (0x20U)
#define RCM_SRS0_WWDT_SHIFT                      (5U)
/*! WWDT - Watchdog
 *  0b0..Reset not caused by watchdog timeout
 *  0b1..Reset caused by watchdog timeout
 */
#define RCM_SRS0_WWDT_SET(x)                         (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_WWDT_SHIFT)) & RCM_SRS0_WWDT_MASK)

#define RCM_SRS0_RSTPIN_MASK                        (0x40U)
#define RCM_SRS0_RSTPIN_SHIFT                       (6U)
/*! PIN - External Reset Pin
 *  0b0..Reset not caused by external reset pin
 *  0b1..Reset caused by external reset pin
 */
#define RCM_SRS0_RSTPIN_SET(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_RSTPIN_SHIFT)) & RCM_SRS0_RSTPIN_MASK)

#define RCM_SRS0_POR_MASK                        (0x80U)
#define RCM_SRS0_POR_SHIFT                       (7U)
/*! POR - Power-On Reset
 *  0b0..Reset not caused by POR
 *  0b1..Reset caused by POR
 */
#define RCM_SRS0_POR_SET(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_POR_SHIFT)) & RCM_SRS0_POR_MASK)
/*! @} */

/*! @name SRS1 - System Reset Status Register 1 */
/*! @{ */

#define RCM_SRS1_JTAG_MASK                       (0x1U)
#define RCM_SRS1_JTAG_SHIFT                      (0U)
/*! JTAG - JTAG Generated Reset
 *  0b0..Reset not caused by JTAG
 *  0b1..Reset caused by JTAG
 */
#define RCM_SRS1_JTAG_SET(x)                         (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_JTAG_SHIFT)) & RCM_SRS1_JTAG_MASK)

#define RCM_SRS1_LOCKUP_MASK                     (0x2U)
#define RCM_SRS1_LOCKUP_SHIFT                    (1U)
/*! LOCKUP - Core Lockup
 *  0b0..Reset not caused by core LOCKUP event
 *  0b1..Reset caused by core LOCKUP event
 */
#define RCM_SRS1_LOCKUP_SET(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_LOCKUP_SHIFT)) & RCM_SRS1_LOCKUP_MASK)

#define RCM_SRS1_SW_MASK                         (0x4U)
#define RCM_SRS1_SW_SHIFT                        (2U)
/*! SW - Software
 *  0b0..Reset not caused by software setting of SYSRESETREQ bit
 *  0b1..Reset caused by software setting of SYSRESETREQ bit
 */
#define RCM_SRS1_SW_SET(x)                           (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_SW_SHIFT)) & RCM_SRS1_SW_MASK)

/*! @} */

/*! @name RPFC - Reset Pin Filter Control register */
/*! @{ */

#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)
/*! RSTFLTSRW - Reset Pin Filter Select in Run and Wait Modes
 *  0b00..All filtering disabled
 *  0b01..Bus clock filter enabled for normal operation
 *  0b10..LPO clock filter enabled for normal operation
 *  0b11..Reserved
 */
#define RCM_RPFC_RSTFLTSRW_SET(x)                    (((uint8_t)(((uint8_t)(x)) << RCM_RPFC_RSTFLTSRW_SHIFT)) & RCM_RPFC_RSTFLTSRW_MASK)

#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)
/*! RSTFLTSS - Reset Pin Filter Select in Stop Mode
 *  0b0..All filtering disabled
 *  0b1..LPO clock filter enabled
 */
#define RCM_RPFC_RSTFLTSS_SET(x)                     (((uint8_t)(((uint8_t)(x)) << RCM_RPFC_RSTFLTSS_SHIFT)) & RCM_RPFC_RSTFLTSS_MASK)
/*! @} */

/*! @name RPFW - Reset Pin Filter Width register */
/*! @{ */

#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FU)
#define RCM_RPFW_RSTFLTSEL_SHIFT                 (0U)
/*! RSTFLTSEL - Reset Pin Filter Bus Clock Select
 *  0b00000..Bus clock filter count is 1
 *  0b00001..Bus clock filter count is 2
 *  0b00010..Bus clock filter count is 3
 *  0b00011..Bus clock filter count is 4
 *  0b00100..Bus clock filter count is 5
 *  0b00101..Bus clock filter count is 6
 *  0b00110..Bus clock filter count is 7
 *  0b00111..Bus clock filter count is 8
 *  0b01000..Bus clock filter count is 9
 *  0b01001..Bus clock filter count is 10
 *  0b01010..Bus clock filter count is 11
 *  0b01011..Bus clock filter count is 12
 *  0b01100..Bus clock filter count is 13
 *  0b01101..Bus clock filter count is 14
 *  0b01110..Bus clock filter count is 15
 *  0b01111..Bus clock filter count is 16
 *  0b10000..Bus clock filter count is 17
 *  0b10001..Bus clock filter count is 18
 *  0b10010..Bus clock filter count is 19
 *  0b10011..Bus clock filter count is 20
 *  0b10100..Bus clock filter count is 21
 *  0b10101..Bus clock filter count is 22
 *  0b10110..Bus clock filter count is 23
 *  0b10111..Bus clock filter count is 24
 *  0b11000..Bus clock filter count is 25
 *  0b11001..Bus clock filter count is 26
 *  0b11010..Bus clock filter count is 27
 *  0b11011..Bus clock filter count is 28
 *  0b11100..Bus clock filter count is 29
 *  0b11101..Bus clock filter count is 30
 *  0b11110..Bus clock filter count is 31
 *  0b11111..Bus clock filter count is 32
 */
#define RCM_RPFW_RSTFLTSEL_SET(x)                    (((uint8_t)(((uint8_t)(x)) << RCM_RPFW_RSTFLTSEL_SHIFT)) & RCM_RPFW_RSTFLTSEL_MASK)
/*! @} */

#define RCM_SSRS0_VDT_MASK                      (0x2U)
#define RCM_SSRS0_VDT_SHIFT                     (1U)
/*! SLVD - Sticky Low-Voltage Detect Reset
 *  0b0..Reset not caused by LVD trip or POR
 *  0b1..Reset caused by LVD trip or POR
 */
#define RCM_SSRS0_VDT_SET(x)                        (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_VDT_SHIFT)) & RCM_SSRS0_VDT_MASK)

#define RCM_SSRS0_SWWDT_MASK                     (0x20U)
#define RCM_SSRS0_SWWDT_SHIFT                    (5U)
/*! SWWDT - Sticky Watchdog
 *  0b0..Reset not caused by watchdog timeout
 *  0b1..Reset caused by watchdog timeout
 */
#define RCM_SSRS0_SWWDT_SET(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SWWDT_SHIFT)) & RCM_SSRS0_SWWDT_MASK)

#define RCM_SSRS0_SPIN_MASK                      (0x40U)
#define RCM_SSRS0_SPIN_SHIFT                     (6U)
/*! SPIN - Sticky External Reset Pin
 *  0b0..Reset not caused by external reset pin
 *  0b1..Reset caused by external reset pin
 */
#define RCM_SSRS0_SPIN_SET(x)                        (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SPIN_SHIFT)) & RCM_SSRS0_SPIN_MASK)

#define RCM_SSRS0_SPOR_MASK                      (0x80U)
#define RCM_SSRS0_SPOR_SHIFT                     (7U)
/*! SPOR - Sticky Power-On Reset
 *  0b0..Reset not caused by POR
 *  0b1..Reset caused by POR
 */
#define RCM_SSRS0_SPOR_SET(x)                        (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SPOR_SHIFT)) & RCM_SSRS0_SPOR_MASK)
/*! @} */

/*! @name SSRS1 - Sticky System Reset Status Register 1 */
/*! @{ */

#define RCM_SSRS1_SJTAG_MASK                     (0x1U)
#define RCM_SSRS1_SJTAG_SHIFT                    (0U)
/*! SJTAG - Sticky JTAG Generated Reset
 *  0b0..Reset not caused by JTAG
 *  0b1..Reset caused by JTAG
 */
#define RCM_SSRS1_SJTAG_SET(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SSRS1_SJTAG_SHIFT)) & RCM_SSRS1_SJTAG_MASK)

#define RCM_SSRS1_SLOCKUP_MASK                   (0x2U)
#define RCM_SSRS1_SLOCKUP_SHIFT                  (1U)
/*! SLOCKUP - Sticky Core Lockup
 *  0b0..Reset not caused by core LOCKUP event
 *  0b1..Reset caused by core LOCKUP event
 */
#define RCM_SSRS1_SLOCKUP_SET(x)                     (((uint8_t)(((uint8_t)(x)) << RCM_SSRS1_SLOCKUP_SHIFT)) & RCM_SSRS1_SLOCKUP_MASK)

#define RCM_SSRS1_SSW_MASK                       (0x4U)
#define RCM_SSRS1_SSW_SHIFT                      (2U)
/*! SSW - Sticky Software
 *  0b0..Reset not caused by software setting of SYSRESETREQ bit
 *  0b1..Reset caused by software setting of SYSRESETREQ bit
 */
#define RCM_SSRS1_SSW_SET(x)                         (((uint8_t)(((uint8_t)(x)) << RCM_SSRS1_SSW_SHIFT)) & RCM_SSRS1_SSW_MASK)


/*!
 * @}
 */ /* end of group RCM_Register_Masks */


/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base address */
#define RCM_BASE                                 (0x4007F000u)
/** Peripheral RCM base pointer */
#define RCM                                      ((RCM_Type *)RCM_BASE)
/** Array initializer of RCM peripheral base addresses */
#define RCM_BASE_ADDRS                           { RCM_BASE }
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASE_PTRS                            { RCM }

/*!
 * @}
 */ /* end of group RCM_Peripheral_Access_Layer */




/* ----------------------------------------------------------------------------
   -- SPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 * @{
 */

/** SPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCFGR;                               /**< Module Configuration Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t TCNTR;                               /**< Transfer Count Register, offset: 0x8 */
  union {                                            /* offset: 0xC */
    __IO uint32_t CLKTAR[2];                         /**< Clock and Transfer Attributes Register (In Master Mode), array offset: 0xC, array step: 0x4 */
    __IO uint32_t CLKTAR_SLV[1];                     /**< Clock and Transfer Attributes Register (In Slave Mode), array offset: 0xC, array step: 0x4 */
  };
       uint8_t RESERVED_1[24];
  __IO uint32_t STATR;                               /**< Status Register, offset: 0x2C */
  __IO uint32_t IRSER;                               /**< DMA/Interrupt Request Select and Enable Register, offset: 0x30 */
  union {                                            /* offset: 0x34 */
    __IO uint32_t PUSHTFR;                           /**< PUSH TX FIFO Register In Master Mode, offset: 0x34 */
    __IO uint32_t PUSHTFR_SLV;                       /**< PUSH TX FIFO Register In Slave Mode, offset: 0x34 */
  };
  __I  uint32_t POPRFR;                              /**< POP RX FIFO Register, offset: 0x38 */
  __I  uint32_t TFR0;                                /**< Transmit FIFO Registers, offset: 0x3C */
  __I  uint32_t TFR1;                                /**< Transmit FIFO Registers, offset: 0x40 */
  __I  uint32_t TFR2;                                /**< Transmit FIFO Registers, offset: 0x44 */
  __I  uint32_t TFR3;                                /**< Transmit FIFO Registers, offset: 0x48 */
       uint8_t RESERVED_2[48];
  __I  uint32_t RFR0;                                /**< Receive FIFO Registers, offset: 0x7C */
  __I  uint32_t RFR1;                                /**< Receive FIFO Registers, offset: 0x80 */
  __I  uint32_t RFR2;                                /**< Receive FIFO Registers, offset: 0x84 */
  __I  uint32_t RFR3;                                /**< Receive FIFO Registers, offset: 0x88 */
} SPI_Type;

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define SPI_MCFGR_HT_MASK                        (0x1U)
#define SPI_MCFGR_HT_SHIFT                       (0U)
/*! HALT - Halt
 *  0b0..Start transfers.
 *  0b1..Stop transfers.
 */
#define SPI_MCFGR_HT_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_HT_SHIFT)) & SPI_MCFGR_HT_MASK)

#define SPI_MCFGR_SMPPT_MASK                     (0x300U)
#define SPI_MCFGR_SMPPT_SHIFT                    (8U)
/*! SMPL_PT - Sample Point
 *  0b00..0 protocol clock cycles between SCK edge and SIN sample
 *  0b01..1 protocol clock cycle between SCK edge and SIN sample
 *  0b10..2 protocol clock cycles between SCK edge and SIN sample
 *  0b11..Reserved
 */
#define SPI_MCFGR_SMPPT_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_SMPPT_SHIFT)) & SPI_MCFGR_SMPPT_MASK)

#define SPI_MCFGR_RXFC_MASK                      (0x400U)
#define SPI_MCFGR_RXFC_SHIFT                     (10U)
/*! CLR_RXF - CLR_RXF
 *  0b0..Do not clear the RX FIFO counter.
 *  0b1..Clear the RX FIFO counter.
 */
#define SPI_MCFGR_RXFC_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_RXFC_SHIFT)) & SPI_MCFGR_RXFC_MASK)

#define SPI_MCFGR_TXFC_MASK                      (0x800U)
#define SPI_MCFGR_TXFC_SHIFT                     (11U)
/*! CLR_TXF - Clear TX FIFO
 *  0b0..Do not clear the TX FIFO counter.
 *  0b1..Clear the TX FIFO counter.
 */
#define SPI_MCFGR_TXFC_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_TXFC_SHIFT)) & SPI_MCFGR_TXFC_MASK)

#define SPI_MCFGR_RXFD_MASK                      (0x1000U)
#define SPI_MCFGR_RXFD_SHIFT                     (12U)
/*! DIS_RXF - Disable Receive FIFO
 *  0b0..RX FIFO is enabled.
 *  0b1..RX FIFO is disabled.
 */
#define SPI_MCFGR_RXFD_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_RXFD_SHIFT)) & SPI_MCFGR_RXFD_MASK)

#define SPI_MCFGR_TXFD_MASK                      (0x2000U)
#define SPI_MCFGR_TXFD_SHIFT                     (13U)
/*! DIS_TXF - Disable Transmit FIFO
 *  0b0..TX FIFO is enabled.
 *  0b1..TX FIFO is disabled.
 */
#define SPI_MCFGR_TXFD_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_TXFD_SHIFT)) & SPI_MCFGR_TXFD_MASK)

#define SPI_MCFGR_MD_MASK                        (0x4000U)
#define SPI_MCFGR_MD_SHIFT                       (14U)
/*! MDIS - Module Disable
 *  0b0..Enables the module clocks.
 *  0b1..Allows external logic to disable the module clocks.
 */
#define SPI_MCFGR_MD_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_MD_SHIFT)) & SPI_MCFGR_MD_MASK)

#define SPI_MCFGR_DZE_MASK                       (0x8000U)
#define SPI_MCFGR_DZE_SHIFT                      (15U)
/*! DOZE - Doze Enable
 *  0b0..Doze mode has no effect on the module.
 *  0b1..Doze mode disables the module.
 */
#define SPI_MCFGR_DZE_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_DZE_SHIFT)) & SPI_MCFGR_DZE_MASK)

#define SPI_MCFGR_PCSIS_MASK                     (0x3F0000U)
#define SPI_MCFGR_PCSIS_SHIFT                    (16U)
/*! PCSIS - Peripheral Chip Select x Inactive State
 *  0b000000..The inactive state of PCSx is low.
 *  0b000001..The inactive state of PCSx is high.
 */
#define SPI_MCFGR_PCSIS_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_PCSIS_SHIFT)) & SPI_MCFGR_PCSIS_MASK)

#define SPI_MCFGR_RFOOE_MASK                     (0x1000000U)
#define SPI_MCFGR_RFOOE_SHIFT                    (24U)
/*! ROOE - Receive FIFO Overflow Overwrite Enable
 *  0b0..Incoming data is ignored.
 *  0b1..Incoming data is shifted into the shift register.
 */
#define SPI_MCFGR_RFOOE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_RFOOE_SHIFT)) & SPI_MCFGR_RFOOE_MASK)

#define SPI_MCFGR_PCSSTBE_MASK                   (0x2000000U)
#define SPI_MCFGR_PCSSTBE_SHIFT                  (25U)
/*! PCSSE - Peripheral Chip Select Strobe Enable
 *  0b0..PCS5/ PCSS is used as the Peripheral Chip Select[5] signal.
 *  0b1..PCS5/ PCSS is used as an active-low PCS Strobe signal.
 */
#define SPI_MCFGR_PCSSTBE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_PCSSTBE_SHIFT)) & SPI_MCFGR_PCSSTBE_MASK)

#define SPI_MCFGR_MTXFE_MASK                     (0x4000000U)
#define SPI_MCFGR_MTXFE_SHIFT                    (26U)
/*! MTFE - Modified Transfer Format Enable
 *  0b0..Modified SPI transfer format disabled.
 *  0b1..Modified SPI transfer format enabled.
 */
#define SPI_MCFGR_MTXFE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_MTXFE_SHIFT)) & SPI_MCFGR_MTXFE_MASK)

#define SPI_MCFGR_FRZ_MASK                       (0x8000000U)
#define SPI_MCFGR_FRZ_SHIFT                      (27U)
/*! FRZ - Freeze
 *  0b0..Do not halt serial transfers in Debug mode.
 *  0b1..Halt serial transfers in Debug mode.
 */
#define SPI_MCFGR_FRZ_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_FRZ_SHIFT)) & SPI_MCFGR_FRZ_MASK)

#define SPI_MCFGR_CFG_MASK                       (0x30000000U)
#define SPI_MCFGR_CFG_SHIFT                      (28U)
/*! DCONF - SPI Configuration.
 *  0b00..SPI
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SPI_MCFGR_CFG_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_CFG_SHIFT)) & SPI_MCFGR_CFG_MASK)

#define SPI_MCFGR_CSCKE_MASK                     (0x40000000U)
#define SPI_MCFGR_CSCKE_SHIFT                    (30U)
/*! CONT_SCKE - Continuous SCK Enable
 *  0b0..Continuous SCK disabled.
 *  0b1..Continuous SCK enabled.
 */
#define SPI_MCFGR_CSCKE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_CSCKE_SHIFT)) & SPI_MCFGR_CSCKE_MASK)

#define SPI_MCFGR_MS_MASK                        (0x80000000U)
#define SPI_MCFGR_MS_SHIFT                       (31U)
/*! MSTR - Master/Slave Mode Select
 *  0b0..Enables Slave mode
 *  0b1..Enables Master mode
 */
#define SPI_MCFGR_MS_SET(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_MCFGR_MS_SHIFT)) & SPI_MCFGR_MS_MASK)
/*! @} */

/*! @name TCR - Transfer Count Register */
/*! @{ */

#define SPI_TCNTR_TCNT_MASK                      (0xFFFF0000U)
#define SPI_TCNTR_TCNT_SHIFT                     (16U)
/*! SPI_TCNT - SPI Transfer Counter
 */
#define SPI_TCNTR_TCNT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_TCNTR_TCNT_SHIFT)) & SPI_TCNTR_TCNT_MASK)
/*! @} */

/*! @name CTAR - Clock and Transfer Attributes Register (In Master Mode) */
/*! @{ */

#define SPI_CLKTAR_BRS_MASK                      (0xFU)
#define SPI_CLKTAR_BRS_SHIFT                     (0U)
/*! BR - Baud Rate Scaler
 */
#define SPI_CLKTAR_BRS_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_BRS_SHIFT)) & SPI_CLKTAR_BRS_MASK)

#define SPI_CLKTAR_DATS_MASK                     (0xF0U)
#define SPI_CLKTAR_DATS_SHIFT                    (4U)
/*! DT - Delay After Transfer Scaler
 */
#define SPI_CLKTAR_DATS_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_DATS_SHIFT)) & SPI_CLKTAR_DATS_MASK)

#define SPI_CLKTAR_ASDS_MASK                     (0xF00U)
#define SPI_CLKTAR_ASDS_SHIFT                    (8U)
/*! ASC - After SCK Delay Scaler
 */
#define SPI_CLKTAR_ASDS_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_ASDS_SHIFT)) & SPI_CLKTAR_ASDS_MASK)

#define SPI_CLKTAR_PCSSCKDS_MASK                 (0xF000U)
#define SPI_CLKTAR_PCSSCKDS_SHIFT                (12U)
/*! CSSCK - PCS to SCK Delay Scaler
 */
#define SPI_CLKTAR_PCSSCKDS_SET(x)               (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_PCSSCKDS_SHIFT)) & SPI_CLKTAR_PCSSCKDS_MASK)

#define SPI_CLKTAR_BRP_MASK                      (0x30000U)
#define SPI_CLKTAR_BRP_SHIFT                     (16U)
/*! PBR - Baud Rate Prescaler
 *  0b00..Baud Rate Prescaler value is 2.
 *  0b01..Baud Rate Prescaler value is 3.
 *  0b10..Baud Rate Prescaler value is 5.
 *  0b11..Baud Rate Prescaler value is 7.
 */
#define SPI_CLKTAR_BRP_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_BRP_SHIFT)) & SPI_CLKTAR_BRP_MASK)

#define SPI_CLKTAR_DATXP_MASK                    (0xC0000U)
#define SPI_CLKTAR_DATXP_SHIFT                   (18U)
/*! PDT - Delay after Transfer Prescaler
 *  0b00..Delay after Transfer Prescaler value is 1.
 *  0b01..Delay after Transfer Prescaler value is 3.
 *  0b10..Delay after Transfer Prescaler value is 5.
 *  0b11..Delay after Transfer Prescaler value is 7.
 */
#define SPI_CLKTAR_DATXP_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_DATXP_SHIFT)) & SPI_CLKTAR_DATXP_MASK)

#define SPI_CLKTAR_ASDP_MASK                     (0x300000U)
#define SPI_CLKTAR_ASDP_SHIFT                    (20U)
/*! PASC - After SCK Delay Prescaler
 *  0b00..Delay after Transfer Prescaler value is 1.
 *  0b01..Delay after Transfer Prescaler value is 3.
 *  0b10..Delay after Transfer Prescaler value is 5.
 *  0b11..Delay after Transfer Prescaler value is 7.
 */
#define SPI_CLKTAR_ASDP_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_ASDP_SHIFT)) & SPI_CLKTAR_ASDP_MASK)

#define SPI_CLKTAR_PCSSDP_MASK                   (0xC00000U)
#define SPI_CLKTAR_PCSSDP_SHIFT                  (22U)
/*! PCSSCK - PCS to SCK Delay Prescaler
 *  0b00..PCS to SCK Prescaler value is 1.
 *  0b01..PCS to SCK Prescaler value is 3.
 *  0b10..PCS to SCK Prescaler value is 5.
 *  0b11..PCS to SCK Prescaler value is 7.
 */
#define SPI_CLKTAR_PCSSDP_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_PCSSDP_SHIFT)) & SPI_CLKTAR_PCSSDP_MASK)

#define SPI_CLKTAR_LSBFST_MASK                   (0x1000000U)
#define SPI_CLKTAR_LSBFST_SHIFT                  (24U)
/*! LSBFE - LSB First
 *  0b0..Data is transferred MSB first.
 *  0b1..Data is transferred LSB first.
 */
#define SPI_CLKTAR_LSBFST_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_LSBFST_SHIFT)) & SPI_CLKTAR_LSBFST_MASK)

#define SPI_CLKTAR_CLKPHS_MASK                   (0x2000000U)
#define SPI_CLKTAR_CLKPHS_SHIFT                  (25U)
/*! CPHA - Clock Phase
 *  0b0..Data is captured on the leading edge of SCK and changed on the following edge.
 *  0b1..Data is changed on the leading edge of SCK and captured on the following edge.
 */
#define SPI_CLKTAR_CLKPHS_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_CLKPHS_SHIFT)) & SPI_CLKTAR_CLKPHS_MASK)

#define SPI_CLKTAR_CLKPOL_MASK                   (0x4000000U)
#define SPI_CLKTAR_CLKPOL_SHIFT                  (26U)
/*! CPOL - Clock Polarity
 *  0b0..The inactive state value of SCK is low.
 *  0b1..The inactive state value of SCK is high.
 */
#define SPI_CLKTAR_CLKPOL_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_CLKPOL_SHIFT)) & SPI_CLKTAR_CLKPOL_MASK)

#define SPI_CLKTAR_FSZ_MASK                      (0x78000000U)
#define SPI_CLKTAR_FSZ_SHIFT                     (27U)
/*! FMSZ - Frame Size
 */
#define SPI_CLKTAR_FSZ_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_FSZ_SHIFT)) & SPI_CLKTAR_FSZ_MASK)

#define SPI_CLKTAR_DBRT_MASK                     (0x80000000U)
#define SPI_CLKTAR_DBRT_SHIFT                    (31U)
/*! DBR - Double Baud Rate
 *  0b0..The baud rate is computed normally with a 50/50 duty cycle.
 *  0b1..The baud rate is doubled with the duty cycle depending on the Baud Rate Prescaler.
 */
#define SPI_CLKTAR_DBRT_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_DBRT_SHIFT)) & SPI_CLKTAR_DBRT_MASK)
/*! @} */

/* The count of SPI_CLKTAR */
#define SPI_CLKTAR_COUNT                         (2U)

/*! @name CTAR_SLAVE - Clock and Transfer Attributes Register (In Slave Mode) */
/*! @{ */

#define SPI_CLKTAR_SLV_CLKPHS_MASK               (0x2000000U)
#define SPI_CLKTAR_SLV_CLKPHS_SHIFT              (25U)
/*! CPHA - Clock Phase
 *  0b0..Data is captured on the leading edge of SCK and changed on the following edge.
 *  0b1..Data is changed on the leading edge of SCK and captured on the following edge.
 */
#define SPI_CLKTAR_SLV_CLKPHS_SET(x)             (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_SLV_CLKPHS_SHIFT)) & SPI_CLKTAR_SLV_CLKPHS_MASK)

#define SPI_CLKTAR_SLV_CLKPOL_MASK               (0x4000000U)
#define SPI_CLKTAR_SLV_CLKPOL_SHIFT              (26U)
/*! CPOL - Clock Polarity
 *  0b0..The inactive state value of SCK is low.
 *  0b1..The inactive state value of SCK is high.
 */
#define SPI_CLKTAR_SLV_CLKPOL_SET(x)             (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_SLV_CLKPOL_SHIFT)) & SPI_CLKTAR_SLV_CLKPOL_MASK)

#define SPI_CLKTAR_SLV_FSZ_MASK                  (0x78000000U)
#define SPI_CLKTAR_SLV_FSZ_SHIFT                 (27U)
/*! FMSZ - Frame Size
 */
#define SPI_CLKTAR_SLV_FSZ_SET(x)                (((uint32_t)(((uint32_t)(x)) << SPI_CLKTAR_SLV_FSZ_SHIFT)) & SPI_CLKTAR_SLV_FSZ_MASK)
/*! @} */

/* The count of SPI_CLKTAR_SLAVE */
#define SPI_CLKTAR_SLV_COUNT                     (1U)

/*! @name SR - Status Register */
/*! @{ */

#define SPI_STATR_POPNPTR_MASK                   (0xFU)
#define SPI_STATR_POPNPTR_SHIFT                  (0U)
/*! POPNXTPTR - Pop Next Pointer
 */
#define SPI_STATR_POPNPTR_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_STATR_POPNPTR_SHIFT)) & SPI_STATR_POPNPTR_MASK)

#define SPI_STATR_RXFCTR_MASK                    (0xF0U)
#define SPI_STATR_RXFCTR_SHIFT                   (4U)
/*! RXCTR - RX FIFO Counter
 */
#define SPI_STATR_RXFCTR_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_STATR_RXFCTR_SHIFT)) & SPI_STATR_RXFCTR_MASK)

#define SPI_STATR_TXNPTR_MASK                    (0xF00U)
#define SPI_STATR_TXNPTR_SHIFT                   (8U)
/*! TXNXTPTR - Transmit Next Pointer
 */
#define SPI_STATR_TXNPTR_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXNPTR_SHIFT)) & SPI_STATR_TXNPTR_MASK)

#define SPI_STATR_TXFCTR_MASK                    (0xF000U)
#define SPI_STATR_TXFCTR_SHIFT                   (12U)
/*! TXCTR - TX FIFO Counter
 */
#define SPI_STATR_TXFCTR_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXFCTR_SHIFT)) & SPI_STATR_TXFCTR_MASK)

#define SPI_STATR_RXFDF_MASK                     (0x20000U)
#define SPI_STATR_RXFDF_SHIFT                    (17U)
/*! RFDF - Receive FIFO Drain Flag
 *  0b0..RX FIFO is empty.
 *  0b1..RX FIFO is not empty.
 */
#define SPI_STATR_RXFDF_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_STATR_RXFDF_SHIFT)) & SPI_STATR_RXFDF_MASK)

#define SPI_STATR_RXFOF_MASK                     (0x80000U)
#define SPI_STATR_RXFOF_SHIFT                    (19U)
/*! RFOF - Receive FIFO Overflow Flag
 *  0b0..No Rx FIFO overflow.
 *  0b1..Rx FIFO overflow has occurred.
 */
#define SPI_STATR_RXFOF_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_STATR_RXFOF_SHIFT)) & SPI_STATR_RXFOF_MASK)

#define SPI_STATR_TXFFF_MASK                     (0x2000000U)
#define SPI_STATR_TXFFF_SHIFT                    (25U)
/*! TFFF - Transmit FIFO Fill Flag
 *  0b0..TX FIFO is full.
 *  0b1..TX FIFO is not full.
 */
#define SPI_STATR_TXFFF_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXFFF_SHIFT)) & SPI_STATR_TXFFF_MASK)

#define SPI_STATR_TXFUF_MASK                     (0x8000000U)
#define SPI_STATR_TXFUF_SHIFT                    (27U)
/*! TFUF - Transmit FIFO Underflow Flag
 *  0b0..No TX FIFO underflow.
 *  0b1..TX FIFO underflow has occurred.
 */
#define SPI_STATR_TXFUF_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXFUF_SHIFT)) & SPI_STATR_TXFUF_MASK)

#define SPI_STATR_EQF_MASK                       (0x10000000U)
#define SPI_STATR_EQF_SHIFT                      (28U)
/*! EOQF - End of Queue Flag
 *  0b0..EOQ is not set in the executing command.
 *  0b1..EOQ is set in the executing SPI command.
 */
#define SPI_STATR_EQF_SET(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_STATR_EQF_SHIFT)) & SPI_STATR_EQF_MASK)

#define SPI_STATR_TRSTAT_MASK                    (0x40000000U)
#define SPI_STATR_TRSTAT_SHIFT                   (30U)
/*! TXRXS - TX and RX Status
 *  0b0..Transmit and receive operations are disabled (The module is in Stopped state).
 *  0b1..Transmit and receive operations are enabled (The module is in Running state).
 */
#define SPI_STATR_TRSTAT_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TRSTAT_SHIFT)) & SPI_STATR_TRSTAT_MASK)

#define SPI_STATR_TXCF_MASK                      (0x80000000U)
#define SPI_STATR_TXCF_SHIFT                     (31U)
/*! TCF - Transfer Complete Flag
 *  0b0..Transfer not complete.
 *  0b1..Transfer complete.
 */
#define SPI_STATR_TXCF_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_STATR_TXCF_SHIFT)) & SPI_STATR_TXCF_MASK)
/*! @} */

/*! @name RSER - DMA/Interrupt Request Select and Enable Register */
/*! @{ */

#define SPI_IRSER_RXFDIRS_MASK                   (0x10000U)
#define SPI_IRSER_RXFDIRS_SHIFT                  (16U)
/*! RFDF_DIRS - Receive FIFO Drain DMA or Interrupt Request Select
 *  0b0..Interrupt request.
 *  0b1..DMA request.
 */
#define SPI_IRSER_RXFDIRS_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_RXFDIRS_SHIFT)) & SPI_IRSER_RXFDIRS_MASK)

#define SPI_IRSER_RXFDRE_MASK                    (0x20000U)
#define SPI_IRSER_RXFDRE_SHIFT                   (17U)
/*! RFDF_RE - Receive FIFO Drain Request Enable
 *  0b0..RFDF interrupt or DMA requests are disabled.
 *  0b1..RFDF interrupt or DMA requests are enabled.
 */
#define SPI_IRSER_RXFDRE_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_RXFDRE_SHIFT)) & SPI_IRSER_RXFDRE_MASK)

#define SPI_IRSER_RXFORE_MASK                    (0x80000U)
#define SPI_IRSER_RXFORE_SHIFT                   (19U)
/*! RFOF_RE - Receive FIFO Overflow Request Enable
 *  0b0..RFOF interrupt requests are disabled.
 *  0b1..RFOF interrupt requests are enabled.
 */
#define SPI_IRSER_RXFORE_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_RXFORE_SHIFT)) & SPI_IRSER_RXFORE_MASK)

#define SPI_IRSER_TXFFIRS_MASK                   (0x1000000U)
#define SPI_IRSER_TXFFIRS_SHIFT                  (24U)
/*! TFFF_DIRS - Transmit FIFO Fill DMA or Interrupt Request Select
 *  0b0..TFFF flag generates interrupt requests.
 *  0b1..TFFF flag generates DMA requests.
 */
#define SPI_IRSER_TXFFIRS_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_TXFFIRS_SHIFT)) & SPI_IRSER_TXFFIRS_MASK)

#define SPI_IRSER_TXFFRE_MASK                    (0x2000000U)
#define SPI_IRSER_TXFFRE_SHIFT                   (25U)
/*! TFFF_RE - Transmit FIFO Fill Request Enable
 *  0b0..TFFF interrupts or DMA requests are disabled.
 *  0b1..TFFF interrupts or DMA requests are enabled.
 */
#define SPI_IRSER_TXFFRE_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_TXFFRE_SHIFT)) & SPI_IRSER_TXFFRE_MASK)

#define SPI_IRSER_TXFURE_MASK                    (0x8000000U)
#define SPI_IRSER_TXFURE_SHIFT                   (27U)
/*! TFUF_RE - Transmit FIFO Underflow Request Enable
 *  0b0..TFUF interrupt requests are disabled.
 *  0b1..TFUF interrupt requests are enabled.
 */
#define SPI_IRSER_TXFURE_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_TXFURE_SHIFT)) & SPI_IRSER_TXFURE_MASK)

#define SPI_IRSER_EQRE_MASK                      (0x10000000U)
#define SPI_IRSER_EQRE_SHIFT                     (28U)
/*! EOQF_RE - Finished Request Enable
 *  0b0..EOQF interrupt requests are disabled.
 *  0b1..EOQF interrupt requests are enabled.
 */
#define SPI_IRSER_EQRE_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_EQRE_SHIFT)) & SPI_IRSER_EQRE_MASK)

#define SPI_IRSER_TXCRE_MASK                     (0x80000000U)
#define SPI_IRSER_TXCRE_SHIFT                    (31U)
/*! TCF_RE - Transmission Complete Request Enable
 *  0b0..TCF interrupt requests are disabled.
 *  0b1..TCF interrupt requests are enabled.
 */
#define SPI_IRSER_TXCRE_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_IRSER_TXCRE_SHIFT)) & SPI_IRSER_TXCRE_MASK)
/*! @} */

/*! @name PUSHR - PUSH TX FIFO Register In Master Mode */
/*! @{ */

#define SPI_PUSHTFR_TXDAT_MASK                   (0xFFFFU)
#define SPI_PUSHTFR_TXDAT_SHIFT                  (0U)
/*! TXDATA - Transmit Data
 */
#define SPI_PUSHTFR_TXDAT_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_TXDAT_SHIFT)) & SPI_PUSHTFR_TXDAT_MASK)

#define SPI_PUSHTFR_SPCS_MASK                    (0x3F0000U)
#define SPI_PUSHTFR_SPCS_SHIFT                   (16U)
/*! PCS
 *  0b000000..Negate the PCS[x] signal.
 *  0b000001..Assert the PCS[x] signal.
 */
#define SPI_PUSHTFR_SPCS_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_SPCS_SHIFT)) & SPI_PUSHTFR_SPCS_MASK)

#define SPI_PUSHTFR_CTXCTR_MASK                  (0x4000000U)
#define SPI_PUSHTFR_CTXCTR_SHIFT                 (26U)
/*! CTCNT - Clear Transfer Counter
 *  0b0..Do not clear the TCR[TCNT] field.
 *  0b1..Clear the TCR[TCNT] field.
 */
#define SPI_PUSHTFR_CTXCTR_SET(x)                (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_CTXCTR_SHIFT)) & SPI_PUSHTFR_CTXCTR_MASK)

#define SPI_PUSHTFR_EQ_MASK                      (0x8000000U)
#define SPI_PUSHTFR_EQ_SHIFT                     (27U)
/*! EOQ - End Of Queue
 *  0b0..The SPI data is not the last data to transfer.
 *  0b1..The SPI data is the last data to transfer.
 */
#define SPI_PUSHTFR_EQ_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_EQ_SHIFT)) & SPI_PUSHTFR_EQ_MASK)

#define SPI_PUSHTFR_CLKTXAS_MASK                 (0x70000000U)
#define SPI_PUSHTFR_CLKTXAS_SHIFT                (28U)
/*! CLKTXAS - Clock and Transfer Attributes Select
 *  0b000..CTAR0
 *  0b001..CTAR1
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define SPI_PUSHTFR_CLKTXAS_SET(x)               (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_CLKTXAS_SHIFT)) & SPI_PUSHTFR_CLKTXAS_MASK)

#define SPI_PUSHTFR_CPCSE_MASK                   (0x80000000U)
#define SPI_PUSHTFR_CPCSE_SHIFT                  (31U)
/*! CONT - Continuous Peripheral Chip Select Enable
 *  0b0..Return PCSn signals to their inactive state between transfers.
 *  0b1..Keep PCSn signals asserted between transfers.
 */
#define SPI_PUSHTFR_CPCSE_SET(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_CPCSE_SHIFT)) & SPI_PUSHTFR_CPCSE_MASK)
/*! @} */

/*! @name PUSHR_SLAVE - PUSH TX FIFO Register In Slave Mode */
/*! @{ */

#define SPI_PUSHTFR_SLV_TXDAT_MASK               (0xFFFFFFFFU)
#define SPI_PUSHTFR_SLV_TXDAT_SHIFT              (0U)
/*! TXDATA - Transmit Data
 */
#define SPI_PUSHTFR_SLV_TXDAT_SET(x)             (((uint32_t)(((uint32_t)(x)) << SPI_PUSHTFR_SLV_TXDAT_SHIFT)) & SPI_PUSHTFR_SLV_TXDAT_MASK)
/*! @} */

/*! @name POPR - POP RX FIFO Register */
/*! @{ */

#define SPI_POPRFR_RXDAT_MASK                    (0xFFFFFFFFU)
#define SPI_POPRFR_RXDAT_SHIFT                   (0U)
/*! RXDATA - Received Data
 */
#define SPI_POPRFR_RXDAT_SET(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_POPRFR_RXDAT_SHIFT)) & SPI_POPRFR_RXDAT_MASK)
/*! @} */

/*! @name TFR0 - Transmit FIFO Registers */
/*! @{ */

#define SPI_TFR0_TXDAT_MASK                      (0xFFFFU)
#define SPI_TFR0_TXDAT_SHIFT                     (0U)
/*! TXDATA - Transmit Data
 */
#define SPI_TFR0_TXDAT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_TFR0_TXDAT_SHIFT)) & SPI_TFR0_TXDAT_MASK)

#define SPI_TFR0_TXCMD_TXDAT_MASK                (0xFFFF0000U)
#define SPI_TFR0_TXCMD_TXDAT_SHIFT               (16U)
/*! TXCMD_TXDATA - Transmit Command or Transmit Data
 */
#define SPI_TFR0_TXCMD_TXDAT_SET(x)              (((uint32_t)(((uint32_t)(x)) << SPI_TFR0_TXCMD_TXDAT_SHIFT)) & SPI_TFR0_TXCMD_TXDAT_MASK)
/*! @} */

/*! @name TXFR1 - Transmit FIFO Registers */
/*! @{ */

#define SPI_TFR1_TXDAT_MASK                      (0xFFFFU)
#define SPI_TFR1_TXDAT_SHIFT                     (0U)
/*! TXDATA - Transmit Data
 */
#define SPI_TFR1_TXDATA_SET(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_TFR1_TXDAT_SHIFT)) & SPI_TFR1_TXDAT_MASK)

#define SPI_TFR1_TXCMD_TXDAT_MASK                (0xFFFF0000U)
#define SPI_TFR1_TXCMD_TXDAT_SHIFT               (16U)
/*! TXCMD_TXDATA - Transmit Command or Transmit Data
 */
#define SPI_TFR1_TXCMD_TXDAT_SET(x)              (((uint32_t)(((uint32_t)(x)) << SPI_TFR1_TXCMD_TXDAT_SHIFT)) & SPI_TFR1_TXCMD_TXDAT_MASK)
/*! @} */

/*! @name TXFR2 - Transmit FIFO Registers */
/*! @{ */

#define SPI_TFR2_TXDAT_MASK                      (0xFFFFU)
#define SPI_TFR2_TXDAT_SHIFT                     (0U)
/*! TXDATA - Transmit Data
 */
#define SPI_TFR2_TXDAT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_TFR2_TXDAT_SHIFT)) & SPI_TFR2_TXDAT_MASK)

#define SPI_TFR2_TXCMD_TXDAT_MASK                (0xFFFF0000U)
#define SPI_TFR2_TXCMD_TXDAT_SHIFT               (16U)
/*! TXCMD_TXDATA - Transmit Command or Transmit Data
 */
#define SPI_TFR2_TXCMD_TXDAT_SET(x)              (((uint32_t)(((uint32_t)(x)) << SPI_TFR2_TXCMD_TXDAT_SHIFT)) & SPI_TFR2_TXCMD_TXDAT_MASK)
/*! @} */

/*! @name TXFR3 - Transmit FIFO Registers */
/*! @{ */

#define SPI_TFR3_TXDAT_MASK                      (0xFFFFU)
#define SPI_TFR3_TXDAT_SHIFT                     (0U)
/*! TXDATA - Transmit Data
 */
#define SPI_TFR3_TXDAT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_TFR3_TXDAT_SHIFT)) & SPI_TFR3_TXDAT_MASK)

#define SPI_TFR3_TXCMD_TXDAT_MASK                (0xFFFF0000U)
#define SPI_TFR3_TXCMD_TXDAT_SHIFT               (16U)
/*! TXCMD_TXDATA - Transmit Command or Transmit Data
 */
#define SPI_TFR3_TXCMD_TXDAT_SET(x)              (((uint32_t)(((uint32_t)(x)) << SPI_TFR3_TXCMD_TXDAT_SHIFT)) & SPI_TFR3_TXCMD_TXDAT_MASK)
/*! @} */

/*! @name RXFR0 - Receive FIFO Registers */
/*! @{ */

#define SPI_RFR0_RXDAT_MASK                      (0xFFFFFFFFU)
#define SPI_RFR0_RXDAT_SHIFT                     (0U)
/*! RXDATA - Receive Data
 */
#define SPI_RFR0_RXDAT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RFR0_RXDAT_SHIFT)) & SPI_RFR0_RXDAT_MASK)
/*! @} */

/*! @name RXFR1 - Receive FIFO Registers */
/*! @{ */

#define SPI_RFR1_RXDAT_MASK                      (0xFFFFFFFFU)
#define SPI_RFR1_RXDAT_SHIFT                     (0U)
/*! RXDATA - Receive Data
 */
#define SPI_RFR1_RXDAT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RFR1_RXDAT_SHIFT)) & SPI_RFR1_RXDAT_MASK)
/*! @} */

/*! @name RXFR2 - Receive FIFO Registers */
/*! @{ */

#define SPI_RFR2_RXDAT_MASK                      (0xFFFFFFFFU)
#define SPI_RFR2_RXDAT_SHIFT                     (0U)
/*! RXDATA - Receive Data
 */
#define SPI_RFR2_RXDAT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RFR2_RXDAT_SHIFT)) & SPI_RFR2_RXDAT_MASK)
/*! @} */

/*! @name RXFR3 - Receive FIFO Registers */
/*! @{ */

#define SPI_RFR3_RXDAT_MASK                      (0xFFFFFFFFU)
#define SPI_RFR3_RXDAT_SHIFT                     (0U)
/*! RXDATA - Receive Data
 */
#define SPI_RFR3_RXDAT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RFR3_RXDAT_SHIFT)) & SPI_RFR3_RXDAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/** Peripheral SPI1 base address */
#define SPI1_BASE                                (0x4002C000u)
/** Peripheral SPI1 base pointer */
#define SPI1                                     ((SPI_Type *)SPI1_BASE)
/** Peripheral SPI2 base address */
#define SPI2_BASE                                (0x4002D000u)
/** Peripheral SPI2 base pointer */
#define SPI2                                     ((SPI_Type *)SPI2_BASE)
/** Peripheral SPI3 base address */
#define SPI3_BASE                                (0x400AC000u)
/** Peripheral SPI3 base pointer */
#define SPI3                                     ((SPI_Type *)SPI3_BASE)
/** Peripheral SPI4 base address */
#define SPI4_BASE                                (0x400AD000u)
/** Peripheral SPI4 base pointer */
#define SPI4                                     ((SPI_Type *)SPI4_BASE)
/** Array initializer of SPI peripheral base addresses */
#define SPI_BASE_ADDRS                           { SPI1_BASE, SPI2_BASE, SPI3_BASE, SPI4_BASE }
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                            { SPI1, SPI2, SPI3, SPI4}
/** Interrupt vectors for the SPI peripheral type */
#define SPI_IRQS                                 { SPI1_IRQn, SPI2_IRQn, SPI3_IRQn, SPI4_IRQn }

/*!
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */





/* ----------------------------------------------------------------------------
   -- WWDT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WWDT_Peripheral_Access_Layer WWDT Peripheral Access Layer
 * @{
 */

/** WWDT - Register Layout Typedef */
typedef struct {
  __IO uint16_t STCTRLH;                           /**< Watchdog Status and Control Register High, offset: 0x0 */
  __IO uint16_t STCTRLL;                           /**< Watchdog Status and Control Register Low, offset: 0x2 */
  __IO uint16_t TOVALH;                            /**< Watchdog Time-out Value Register High, offset: 0x4 */
  __IO uint16_t TOVALL;                            /**< Watchdog Time-out Value Register Low, offset: 0x6 */
  __IO uint16_t WINH;                              /**< Watchdog Window Register High, offset: 0x8 */
  __IO uint16_t WINL;                              /**< Watchdog Window Register Low, offset: 0xA */
  __IO uint16_t REFRESH;                           /**< Watchdog Refresh register, offset: 0xC */
  __IO uint16_t UNLOCK;                            /**< Watchdog Unlock register, offset: 0xE */
  __IO uint16_t TMROUTH;                           /**< Watchdog Timer Output Register High, offset: 0x10 */
  __IO uint16_t TMROUTL;                           /**< Watchdog Timer Output Register Low, offset: 0x12 */
  __IO uint16_t RSTCNT;                            /**< Watchdog Reset Count register, offset: 0x14 */
  __IO uint16_t PRESC;                             /**< Watchdog Prescaler register, offset: 0x16 */
} WWDT_Type;

/* ----------------------------------------------------------------------------
   -- WWDT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WWDT_Register_Masks WWDT Register Masks
 * @{
 */

/*! @name STCTRLH - Watchdog Status and Control Register High */
/*! @{ */

#define WWDT_STCTRLH_WWDTEN_MASK                 (0x1U)
#define WWDT_STCTRLH_WWDTEN_SHIFT                (0U)
/*! WWDTEN
 *  0b0..WWDT is disabled.
 *  0b1..WWDT is enabled.
 */
#define WWDT_STCTRLH_WWDTEN_SET(x)                   (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_WWDTEN_SHIFT)) & WWDT_STCTRLH_WWDTEN_MASK)

#define WWDT_STCTRLH_CLKSRC_MASK                 (0x2U)
#define WWDT_STCTRLH_CLKSRC_SHIFT                (1U)
/*! CLKSRC
 *  0b0..WWDT clock sourced from LPO .
 *  0b1..WWDT clock sourced from alternate clock source.
 */
#define WWDT_STCTRLH_CLKSRC_SET(x)                   (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_CLKSRC_SHIFT)) & WWDT_STCTRLH_CLKSRC_MASK)

#define WWDT_STCTRLH_IRQRSTEN_MASK               (0x4U)
#define WWDT_STCTRLH_IRQRSTEN_SHIFT              (2U)
/*! IRQRSTEN
 *  0b0..WWDT time-out generates reset only.
 *  0b1..WWDT time-out initially generates an interrupt. After WCT, it generates a reset.
 */
#define WWDT_STCTRLH_IRQRSTEN_SET(x)                 (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_IRQRSTEN_SHIFT)) & WWDT_STCTRLH_IRQRSTEN_MASK)

#define WWDT_STCTRLH_WINEN_MASK                  (0x8U)
#define WWDT_STCTRLH_WINEN_SHIFT                 (3U)
/*! WINEN
 *  0b0..Windowing mode is disabled.
 *  0b1..Windowing mode is enabled.
 */
#define WWDT_STCTRLH_WINEN_SET(x)                    (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_WINEN_SHIFT)) & WWDT_STCTRLH_WINEN_MASK)

#define WWDT_STCTRLH_ALLOWUPDATE_MASK            (0x10U)
#define WWDT_STCTRLH_ALLOWUPDATE_SHIFT           (4U)
/*! ALLOWUPDATE
 *  0b0..No further updates allowed to WWDT write-once registers.
 *  0b1..WWDT write-once registers can be unlocked for updating.
 */
#define WWDT_STCTRLH_ALLOWUPDATE_SET(x)              (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_ALLOWUPDATE_SHIFT)) & WWDT_STCTRLH_ALLOWUPDATE_MASK)

#define WWDT_STCTRLH_DBGEN_MASK                  (0x20U)
#define WWDT_STCTRLH_DBGEN_SHIFT                 (5U)
/*! DBGEN
 *  0b0..WWDT is disabled in CPU Debug mode.
 *  0b1..WWDT is enabled in CPU Debug mode.
 */
#define WWDT_STCTRLH_DBGEN_SET(x)                    (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_DBGEN_SHIFT)) & WWDT_STCTRLH_DBGEN_MASK)

#define WWDT_STCTRLH_STOPEN_MASK                 (0x40U)
#define WWDT_STCTRLH_STOPEN_SHIFT                (6U)
/*! STOPEN
 *  0b0..WWDT is disabled in CPU Stop mode.
 *  0b1..WWDT is enabled in CPU Stop mode.
 */
#define WWDT_STCTRLH_STOPEN_SET(x)                   (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_STOPEN_SHIFT)) & WWDT_STCTRLH_STOPEN_MASK)

#define WWDT_STCTRLH_WAITEN_MASK                 (0x80U)
#define WWDT_STCTRLH_WAITEN_SHIFT                (7U)
/*! WAITEN
 *  0b0..WWDT is disabled in CPU Wait mode.
 *  0b1..WWDT is enabled in CPU Wait mode.
 */
#define WWDT_STCTRLH_WAITEN_SET(x)                   (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_WAITEN_SHIFT)) & WWDT_STCTRLH_WAITEN_MASK)

#define WWDT_STCTRLH_TESTWWDT_MASK               (0x400U)
#define WWDT_STCTRLH_TESTWWDT_SHIFT              (10U)
#define WWDT_STCTRLH_TESTWWDT_SET(x)                 (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_TESTWWDT_SHIFT)) & WWDT_STCTRLH_TESTWWDT_MASK)

#define WWDT_STCTRLH_TESTSEL_MASK                (0x800U)
#define WWDT_STCTRLH_TESTSEL_SHIFT               (11U)
/*! TESTSEL
 *  0b0..Quick test. The timer runs in normal operation. You can load a small time-out value to do a quick test.
 *  0b1..Byte test. Puts the timer in the byte test mode where individual bytes of the timer are enabled for
 *       operation and are compared for time-out against the corresponding byte of the programmed time-out value. Select
 *       the byte through BYTESEL[1:0] for testing.
 */
#define WWDT_STCTRLH_TESTSEL_SET(x)                  (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_TESTSEL_SHIFT)) & WWDT_STCTRLH_TESTSEL_MASK)

#define WWDT_STCTRLH_BYTESEL_MASK                (0x3000U)
#define WWDT_STCTRLH_BYTESEL_SHIFT               (12U)
/*! BYTESEL
 *  0b00..Byte 0 selected
 *  0b01..Byte 1 selected
 *  0b10..Byte 2 selected
 *  0b11..Byte 3 selected
 */
#define WWDT_STCTRLH_BYTESEL_SET(x)                  (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_BYTESEL_SHIFT)) & WWDT_STCTRLH_BYTESEL_MASK)

#define WWDT_STCTRLH_DISTESTWWDT_MASK            (0x4000U)
#define WWDT_STCTRLH_DISTESTWWDT_SHIFT           (14U)
/*! DISTESTWWDT
 *  0b0..WWDT functional test mode is not disabled.
 *  0b1..WWDT functional test mode is disabled permanently until reset.
 */
#define WWDT_STCTRLH_DISTESTWWDT_SET(x)              (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLH_DISTESTWWDT_SHIFT)) & WWDT_STCTRLH_DISTESTWWDT_MASK)
/*! @} */

/*! @name STCTRLL - Watchdog Status and Control Register Low */
/*! @{ */

#define WWDT_STCTRLL_INTFLG_MASK                 (0x8000U)
#define WWDT_STCTRLL_INTFLG_SHIFT                (15U)
#define WWDT_STCTRLL_INTFLG_SET(x)                   (((uint32_t)(((uint32_t)(x)) << WWDT_STCTRLL_INTFLG_SHIFT)) & WWDT_STCTRLL_INTFLG_MASK)
/*! @} */

/*! @name TOVALH - Watchdog Time-out Value Register High */
/*! @{ */

#define WWDT_TOVALH_TOVALHIGH_MASK               (0xFFFFU)
#define WWDT_TOVALH_TOVALHIGH_SHIFT              (0U)
#define WWDT_TOVALH_TOVALHIGH_SET(x)                 (((uint32_t)(((uint32_t)(x)) << WWDT_TOVALH_TOVALHIGH_SHIFT)) & WWDT_TOVALH_TOVALHIGH_MASK)
/*! @} */

/*! @name TOVALL - Watchdog Time-out Value Register Low */
/*! @{ */

#define WWDT_TOVALL_TOVALLOW_MASK                (0xFFFFU)
#define WWDT_TOVALL_TOVALLOW_SHIFT               (0U)
#define WWDT_TOVALL_TOVALLOW_SET(x)                  (((uint32_t)(((uint32_t)(x)) << WWDT_TOVALL_TOVALLOW_SHIFT)) & WWDT_TOVALL_TOVALLOW_MASK)
/*! @} */

/*! @name WINH - Watchdog Window Register High */
/*! @{ */

#define WWDT_WINH_WINHIGH_MASK                   (0xFFFFU)
#define WWDT_WINH_WINHIGH_SHIFT                  (0U)
#define WWDT_WINH_WINHIGH_SET(x)                     (((uint32_t)(((uint32_t)(x)) << WWDT_WINH_WINHIGH_SHIFT)) & WWDT_WINH_WINHIGH_MASK)
/*! @} */

/*! @name WINL - Watchdog Window Register Low */
/*! @{ */

#define WWDT_WINL_WINLOW_MASK                    (0xFFFFU)
#define WWDT_WINL_WINLOW_SHIFT                   (0U)
#define WWDT_WINL_WINLOW_SET(x)                      (((uint32_t)(((uint32_t)(x)) << WWDT_WINL_WINLOW_SHIFT)) & WWDT_WINL_WINLOW_MASK)
/*! @} */

/*! @name REFRESH - Watchdog Refresh register */
/*! @{ */

#define WWDT_REFRESH_WWDTREFRESH_MASK            (0xFFFFU)
#define WWDT_REFRESH_WWDTREFRESH_SHIFT           (0U)
#define WWDT_REFRESH_WWDTREFRESH_SET(x)              (((uint32_t)(((uint32_t)(x)) << WWDT_REFRESH_WWDTREFRESH_SHIFT)) & WWDT_REFRESH_WWDTREFRESH_MASK)
/*! @} */

/*! @name UNLOCK - Watchdog Unlock register */
/*! @{ */

#define WWDT_UNLOCK_WWDTUNLOCK_MASK              (0xFFFFU)
#define WWDT_UNLOCK_WWDTUNLOCK_SHIFT             (0U)
#define WWDT_UNLOCK_WWDTUNLOCK_SET(x)                (((uint32_t)(((uint32_t)(x)) << WWDT_UNLOCK_WWDTUNLOCK_SHIFT)) & WWDT_UNLOCK_WWDTUNLOCK_MASK)
/*! @} */

/*! @name TMROUTH - Watchdog Timer Output Register High */
/*! @{ */

#define WWDT_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFU)
#define WWDT_TMROUTH_TIMEROUTHIGH_SHIFT          (0U)
#define WWDT_TMROUTH_TIMEROUTHIGH_SET(x)             (((uint32_t)(((uint32_t)(x)) << WWDT_TMROUTH_TIMEROUTHIGH_SHIFT)) & WWDT_TMROUTH_TIMEROUTHIGH_MASK)
/*! @} */

/*! @name TMROUTL - Watchdog Timer Output Register Low */
/*! @{ */

#define WWDT_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFU)
#define WWDT_TMROUTL_TIMEROUTLOW_SHIFT           (0U)
#define WWDT_TMROUTL_TIMEROUTLOW_SET(x)              (((uint32_t)(((uint32_t)(x)) << WWDT_TMROUTL_TIMEROUTLOW_SHIFT)) & WWDT_TMROUTL_TIMEROUTLOW_MASK)
/*! @} */

/*! @name RSTCNT - Watchdog Reset Count register */
/*! @{ */

#define WWDT_RSTCNT_RSTCNT_MASK                  (0xFFFFU)
#define WWDT_RSTCNT_RSTCNT_SHIFT                 (0U)
#define WWDT_RSTCNT_RSTCNT_SET(x)                    (((uint32_t)(((uint32_t)(x)) << WWDT_RSTCNT_RSTCNT_SHIFT)) & WWDT_RSTCNT_RSTCNT_MASK)
/*! @} */

/*! @name PRESC - Watchdog Prescaler register */
/*! @{ */

#define WWDT_PRESC_PRESCVAL_MASK                 (0x700U)
#define WWDT_PRESC_PRESCVAL_SHIFT                (8U)
#define WWDT_PRESC_PRESCVAL_SET(x)                   (((uint32_t)(((uint32_t)(x)) << WWDT_PRESC_PRESCVAL_SHIFT)) & WWDT_PRESC_PRESCVAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WWDT_Register_Masks */


/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT base address */
#define WWDT_BASE                                (0x40052000u)
/** Peripheral WWDT base pointer */
#define WWDT                                     ((WWDT_Type *)WWDT_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT }
/** Interrupt vectors for the WWDT peripheral type */
#define WWDT_IRQS                                { WWDT_EWM_IRQn }

/*!
 * @}
 */ /* end of group WWDT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCC_Peripheral_Access_Layer DCC Peripheral Access Layer
 * @{
 */

/** DCC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GCTRL;                           /**< start/stops the counters. Clears the error signal,offset: 0x0 */
       uint8_t  RESERVED_0[4];
  __IO uint32_t CNTSEED0;                        /**< seed value for the counter attached to Clock Source 0,offset: 0x8 */
  __IO uint32_t VALIDSEED0;                      /**< seed value for the timeout counter attached to clock source 0 offset: 0xC*/
  __IO uint32_t CNTSEED1;                        /**< seed value for the counter attached to Clock Source 1, offset: 0x10 */
  __IO uint32_t STATUS;                          /**< Specifies the status of the DCC Module, offset: 0x14 */
  __IO uint32_t CNT0;                            /**< Value of the counter attached to clock source 0 offset: 0x18 */
  __IO uint32_t VALID0;                          /**< Value of the valid counter oattached to clock sources offset: 0x1C */
  __IO uint32_t CNT1;                           /**< Value of the counter attached to clock sources1 offset: 0x20 */
  __IO uint32_t CLKSRC1;                         /**< select  clock sources1 for counter1,offset: 0x24 */
  __IO uint32_t CLKSRC0;                         /**< select  clock sources0 for counter0,offset: 0x28 */
} DCC_Type;

/* ----------------------------------------------------------------------------
   -- DCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCC_Register_Masks DCC Register Masks
 * @{
 */

/*! @name DCCGCTRL -  start/stops the counters. Clears the error signal */
/*! @{ */
 /*! DCCENA
 *  0b0101..counter is stop.
 *  other..counter is run.
 */
#define DCC_GCTRL_ENA_MASK                 (0xFU)
#define DCC_GCTRL_ENA_SHIFT                (0U)
 /*! ERRENA
 *  0b0101..the error signal is disable.
 *  other..the error signal is enabled.
 */
#define DCC_GCTRL_ENA(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_GCTRL_ENA_SHIFT)) & DCC_GCTRL_ENA_MASK)


#define DCC_GCTRL_ERRENA_MASK                 (0xFU)
#define DCC_GCTRL_ERRENA_SHIFT                (4U)
 /*! SINGLESHOT 
 *  0b0101..Stop counting when COUNTER0 and VALID0 both reach zero.
 *  0b1011..Reserved
 *  other ..Continuously reapeat
 */
#define DCC_GCTRL_ERRENA(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_GCTRL_ERRENA_SHIFT)) & DCC_GCTRL_ERRENA_MASK)

#define DCC_GCTRL_SINGLESHOT_MASK                 (0xFU)
#define DCC_GCTRL_SINGLESHOT_SHIFT                (8U)
 /*! DONEENA 
 *  0b0101..The done signal is disabled.
 *  other..other the done signal is enable.
 */
#define DCC_GCTRL_SINGLESHOT(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_GCTRL_SINGLESHOT_SHIFT)) & DCC_GCTRL_SINGLESHOT_MASK)

#define DCC_GCTRL_DONEENA_MASK                 (0xFU)
#define DCC_GCTRL_DONEENA_SHIFT                (12U)

/*! @name DCCCNTSEED0  -  seed value for the counter attached to Clock Source 0  */
/*! @{ */
#define DCC_CNTSEED0_COUNTSEED0_MASK                 (0xFFFFFU)
#define DCC_CNTSEED0_COUNTSEED0_SHIFT                (0U)

#define DCC_CNTSEED0_COUNTSEED0(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_CNTSEED0_COUNTSEED0_SHIFT)) & DCC_CNTSEED0_COUNTSEED0_MASK)

/*! @name DCCVALIDSEED0  - seed value for the timeout counter attached to clock source 0 */
/*! @{ */
#define DCC_VALIDSEED0_VALIDSEED_MASK                 (0xFFFFU)
#define DCC_VALIDSEED0_VALIDSEED_SHIFT                (0U)

#define DCC_VALIDSEED0_VALIDSEED(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_VALIDSEED0_VALIDSEED_SHIFT)) & DCC_VALIDSEED0_VALIDSEED_MASK)


/*! @name DCCCNTSEED1  - seed value for the counter attached to Clock Source 1 */
/*! @{ */
#define DCC_CNTSEED1_COUNTSEED1_MASK                 (0xFFFFFU)
#define DCC_CNTSEED1_COUNTSEED1_SHIFT                (0U)

#define DCC_CNTSEED1_COUNTSEED1(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_CNTSEED1_COUNTSEED1_SHIFT)) & DCC_CNTSEED1_COUNTSEED1_MASK)


/*! @name DCCSTATUS  - Specifies the status of the DCC Module */
/*! @{ */
 /*! ERR
 *  0b1..AN errors has occurred.
 *  0b0..NO errors have occurred.
 */
#define DCC_STATUS_ERR_MASK                 (0x1)
#define DCC_STATUS_ERR_SHIFT                (0U)

#define DCC_STATUS_ERROR(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_STATUS_ERR_SHIFT)) & DCC_DSTATUS_ERR_MASK)

 /*! DONE
 *  0b1..single-shot mode has completed.
 *  0b0..single-shot mode has no completed
 */
#define DCC_STATUS_DONE_MASK                 (0x2)
#define DCC_STATUS_DONE_SHIFT                (1U)

#define DCC_STATUS_SDONE(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_STATUS_DONE_SHIFT)) & DCC_STATUS_DONE_MASK)

/*! @name DCCCNT0  - Value of the counter attached to clock source 0 */
/*! @{ */
#define DCC_CNT0_COUNT0_MASK                 (0xFFFFFU)
#define DCC_CNT0_COUNT0_SHIFT                (0U)

#define DCC_CNT0_COUNT0(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_CNT0_COUNT0_SHIFT)) & DCC_CNT0_COUNT0_MASK)

/*! @name DCCVALIDO  - Value of the valid counter attached to clock sources 0 */
/*! @{ */
#define DCC_VALIDO_VALID0_MASK                 (0xFFFFU)
#define DCC_VALIDO_VALID0_SHIFT                (0U)

#define DCC_VALIDO_VALID0(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_VALIDO_VALID0_SHIFT)) & DCC_VALIDO_VALID0_MASK)

/*! @name DCCCNT1  - Value of the counter attached to clock source 1 */
/*! @{ */
#define DCC_CNT1_COUNT1_MASK                 (0xFFFFFU)
#define DCC_CNT1_COUNT1_SHIFT                (0U)

#define DCC_CNT1_COUNT1(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_CNT1_COUNT1_SHIFT)) & DCC_CNT1_COUNT1_MASK)


/*! @name DCCCLKSRC1  - select  clock sources1 for counter1 */
/*! @{ */
 /*! CLKSR1
 *  
 *  
 */
#define DCC_CLKSRC1_CLKSRC1_MASK                 (0x1FU)
#define DCC_CLKSRC1_CLKSRC1_SHIFT                (0U)

#define DCC_CLKSRC1_CLKSRC1(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_CLKSRC1_CLKSRC1_SHIFT)) & DCC_CLKSRC1_CLKSRC1_MASK)
/*! kEY
 *  0b1010.. 
 *  0b0..
 */
#define DCC_CLKSRC1_KEY_MASK                 (0xFU)
#define DCC_CLKSRC1_KEY_SHIFT                (12U)

#define DCC_CLKSRC1_KEY(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_CLKSRC1_KEY_SHIFT)) & DCC_CLKSRC1_KEY_MASK)

/*! @name DCCCLKSRC0  - select clock sources0 for counter0 */
/*! @{ */
 /*! CLKSR0
 *  
 *  
 */
#define DCC_CLKSRC0_CLKSRC0_MASK                 (0x1FU)
#define DCC_CLKSRC0_CLKSRC0_SHIFT                (0U)

#define DCC_CLKSRC0_CLKSRC0(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_CLKSRC0_CLKSRC0_SHIFT)) & DCC_CLKSRC0_CLKSRC0_MASK)

/*! kEY
 *  0b1010.. 
 *  0b0..
 */
#define DCC_CLKSRC0_KEY_MASK                 (0xFU)
#define DCC_CLKSRC0_KEY_SHIFT                (12U)

#define DCC_CLKSRC0_KEY(x)                    (((uint32_t)(((uint32_t)(x)) << DCC_CLKSRC0_KEY_SHIFT)) & DCC_CLKSRC0_KEY_MASK)

/*!
 * @}

 */ /* end of group WWDT_Register_Masks */


/* DCC1 - Peripheral instance base addresses */
/** Peripheral DCC base address */
#define DCC1_BASE                                (0x40023000u)
/** Peripheral DCC base pointer */
#define DCC1                                     ((DCC_Type *)DCC1_BASE)

/* DCC2 - Peripheral instance base addresses */
/** Peripheral DCC base address */
#define DCC2_BASE                                (0x400a3000u)
/** Peripheral DCC base pointer */
#define DCC2                                     ((DCC_Type *)DCC2_BASE)
/** Array initializer of DCC peripheral base addresses */
#define DCC_BASE_ADDRS                          { DCC1_BASE, DCC2_BASE}
/** Array initializer of DCC peripheral base pointers */
#define DCC_BASE_PTRS                           { DCC1,DCC2}
/** Interrupt vectors for the DCC peripheral type */
#define DCC_IRQS                                {DCC1_INTR_IRQn,DCC2_INTR_IRQn,DCC1_ERR_IRQn,DCC2_ERR_IRQn}

/*!
 * @}
 */ /* end of group DCC_Peripheral_Access_Layer */




/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */

/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0U,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0U,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))



/**
  * @}
  */


/** @addtogroup Exported_macro
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))

/* Use of CMSIS compiler intrinsics for register exclusive access */
/* Atomic 32-bit register access macro to set one or several bits */
#define ATOMIC_SET_BIT(REG, BIT)                             \
  do {                                                       \
    uint32_t val;                                            \
    do {                                                     \
      val = __LDREXW((__IO uint32_t *)&(REG)) | (BIT);       \
    } while ((__STREXW(val,(__IO uint32_t *)&(REG))) != 0U); \
  } while(0)

/* Atomic 32-bit register access macro to clear one or several bits */
#define ATOMIC_CLEAR_BIT(REG, BIT)                           \
  do {                                                       \
    uint32_t val;                                            \
    do {                                                     \
      val = __LDREXW((__IO uint32_t *)&(REG)) & ~(BIT);      \
    } while ((__STREXW(val,(__IO uint32_t *)&(REG))) != 0U); \
  } while(0)

/* Atomic 32-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK)                          \
  do {                                                                     \
    uint32_t val;                                                          \
    do {                                                                   \
      val = (__LDREXW((__IO uint32_t *)&(REG)) & ~(CLEARMSK)) | (SETMASK); \
    } while ((__STREXW(val,(__IO uint32_t *)&(REG))) != 0U);               \
  } while(0)

/* Atomic 16-bit register access macro to set one or several bits */
#define ATOMIC_SETH_BIT(REG, BIT)                            \
  do {                                                       \
    uint16_t val;                                            \
    do {                                                     \
      val = __LDREXH((__IO uint16_t *)&(REG)) | (BIT);       \
    } while ((__STREXH(val,(__IO uint16_t *)&(REG))) != 0U); \
  } while(0)

/* Atomic 16-bit register access macro to clear one or several bits */
#define ATOMIC_CLEARH_BIT(REG, BIT)                          \
  do {                                                       \
    uint16_t val;                                            \
    do {                                                     \
      val = __LDREXH((__IO uint16_t *)&(REG)) & ~(BIT);      \
    } while ((__STREXH(val,(__IO uint16_t *)&(REG))) != 0U); \
  } while(0)

/* Atomic 16-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFYH_REG(REG, CLEARMSK, SETMASK)                         \
  do {                                                                     \
    uint16_t val;                                                          \
    do {                                                                   \
      val = (__LDREXH((__IO uint16_t *)&(REG)) & ~(CLEARMSK)) | (SETMASK); \
    } while ((__STREXH(val,(__IO uint16_t *)&(REG))) != 0U);               \
  } while(0)



#endif  /* _SP28038_H_ */

