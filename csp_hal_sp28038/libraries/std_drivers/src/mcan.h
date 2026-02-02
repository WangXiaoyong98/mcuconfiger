/*
  ******************************************************************************
  * @file           : mcan.h
  * @brief          : mcan program body
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
#ifndef _MCAN_H_
#define _MCAN_H_

#include "driver_common.h"


/*!
 * @addtogroup mcan_driver
 * @{
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

#define CAN_WORD1_COUNT   8

#define SINGLE_SAMPLING (0U)
#define THREE_SAMPLING  (1U)
 

/*! @brief MCAN Rx Message Buffer Acceptance Code  helper macro. */ 
#define MCAN_RX_FILTER_STD_S_CODE(id, rtr, data1,data2)                                   \
    (((uint32_t)((uint32_t)(id&0x7FF) << 21) |(uint32_t)((uint32_t)(rtr&0x01) << 20) | (uint32_t)((uint32_t)(data1) << 8)| (uint32_t)((uint32_t)(data2) << 0)) & 0xFFF0FFFF) /*!< Standard Rx Message Buffer Mask helper macro. */
        
#define MCAN_RX_FILTER_EXT_S_CODE(id, rtr)                               \
    (((uint32_t)((uint32_t)(id&0x1FFFFFFF) << 3) | (uint32_t)((uint32_t)(rtr&0x01) << 2) ) & 0xFFFFFFFC) /*!< Extend Rx Message Buffer Mask helper macro. */      
    

#define MCAN_RX_FILTER_STD_D_CODE(id1,id2,rtr1,rtr2,data1)                                     \
    ((uint32_t)((uint32_t)(id1&0x7FF) << 21)|(uint32_t)((uint32_t)(rtr1&0x01) << 20)|(uint32_t)((uint32_t)(data1&0xf0)<<12)|(uint32_t)((uint32_t)(id2 & 0x7FF)<<5)|(uint32_t)((uint32_t)((rtr2&0x01)<< 4))|((uint32_t)(data1&0x0F))) /*!< Standard Rx Message Buffer Mask helper macro. */
        
    
#define MCAN_RX_FILTER_EXT_D_CODE(id1_28_13,id2_28_13)                                \
    ((uint32_t)((uint32_t)((id1_28_13&0xFFFF)) << 16) | (uint32_t)((uint32_t)(id2_28_13&0xFFFF))) /*!< Extend Rx Message Buffer Mask helper macro. */    


/*! @brief MCAN Rx Message Buffer Acceptance Mask helper macro. */  
#define MCAN_RX_FILTER_STD_S_MASK(M_id, M_rtr, M_data1,M_data2)                                   \
    (((uint32_t)((uint32_t)(M_id&0x7FF) << 21) |(uint32_t)((uint32_t)(M_rtr&0x01) << 20) | (uint32_t)((uint32_t)(M_data1) << 8)| (uint32_t)((uint32_t)(M_data2) << 0)) & 0xFFF0FFFF) /*!< Standard Rx Message Buffer Mask helper macro. */
        
#define MCAN_RX_FILTER_EXT_S_MASK(M_id, M_rtr)                               \
    (((uint32_t)((uint32_t)(M_id&0x1FFFFFFF) << 3) | (uint32_t)((uint32_t)(M_rtr&0x01) << 2) ) & 0xFFFFFFFC) /*!< Extend Rx Message Buffer Mask helper macro. */     
    

#define MCAN_RX_FILTER_STD_D_MASK(M_id1,M_id2,M_rtr1,M_rtr2,M_data1)                                     \
    ((uint32_t)((uint32_t)(M_id1&0x7FF) << 21)|(uint32_t)((uint32_t)(M_rtr1&0x01) << 20)|(uint32_t)((uint32_t)(M_data1&0xF0)<<12)|(uint32_t)((uint32_t)(M_id2 & 0x7FF)<<5)|(uint32_t)((uint32_t)((M_rtr2&0x01)<< 4))|((uint32_t)(M_data1&0x0F))) /*!< Standard Rx Message Buffer Mask helper macro. */
        
    
#define MCAN_RX_FILTER_EXT_D_MASK(M_id1_28_13,M_id2_28_13)                                \
    ((uint32_t)((uint32_t)((M_id1_28_13&0xFFFF)) << 16) | (uint32_t)((uint32_t)(M_id2_28_13&0xFFFF))) /*!< Extend Rx Message Buffer Mask helper macro. */  

 
 
#define MCAN_INIT_FLAG                                                                          \
    ((uint8_t)MCAN_Receive_Interrupt_Flag | (uint8_t)MCAN_Transmit_Interrupt_Flag | (uint8_t)MCAN_Error_Warning_Interrupt_Flag | \
     (uint8_t)MCAN_Data_Overrun_Interrupt_Flag | (uint8_t)MCAN_Wake_Up_Interrupt_Flag|(uint8_t)MCAN_Error_Passive_Interrupt_Flag |  \
     (uint8_t)MCAN_Arbitration_Loss_Interrupt_Flag | (uint8_t)MCAN_Bus_Error_Interrupt_Flag)  
     
     
#define MCAN_WAKE_UP_FLAG    ((uint8_t)MCAN_Wake_Up_Interrupt_Flag)  


/*! @brief MCAN transfer status. */
enum
{
    sStatus_MCAN_TxBusy          = MAKE_STATUS(sStatusGroup_MCAN, 0), /*!< Tx Message Buffer is Busy. */
    sStatus_MCAN_TxIdle          = MAKE_STATUS(sStatusGroup_MCAN, 1), /*!< Tx Message Buffer is Idle. */
    sStatus_MCAN_TxSwitchToRx    = MAKE_STATUS(sStatusGroup_MCAN, 2), /*!< Remote Message is send out and Message buffer changed to Receive one. */
    
    sStatus_MCAN_RxBusy         = MAKE_STATUS(sStatusGroup_MCAN, 3), /*!< Rx Message Buffer is Busy. */
    sStatus_MCAN_RxIdle         = MAKE_STATUS(sStatusGroup_MCAN, 4), /*!< Rx Message Buffer is Idle. */
    sStatus_MCAN_RxOverflow     = MAKE_STATUS(sStatusGroup_MCAN, 5), /*!< Rx Message Buffer is Overflowed. */
    sStatus_MCAN_ErrorStatus    = MAKE_STATUS(sStatusGroup_MCAN, 6), /*!< MCAN Module Error and Status. */
    sStatus_MCAN_WakeUp         = MAKE_STATUS(sStatusGroup_MCAN, 7), /*!< MCAN is waken up from STOP mode. */
    sStatus_MCAN_UnHandled      = MAKE_STATUS(sStatusGroup_MCAN, 8), /*!< UnHadled Interrupt asserted. */
    sStatus_MCAN_RxRemote       = MAKE_STATUS(sStatusGroup_MCAN, 9), /*!< Rx Remote Message Received in Mail box. */
}; 

/*! @brief MCAN frame format. */
typedef enum _mcan_frame_format
{
    MCAN_FrameFormatStandard = 0x0U, /*!< Standard frame format attribute. */
    MCAN_FrameFormatExtend   = 0x1U, /*!< Extend frame format attribute. */
} mcan_frame_format_t;   

/*! @brief MCAN frame type. */
typedef enum _mcan_frame_type
{
    MCAN_FrameTypeData   = 0x0U, /*!< Data frame type attribute. */
    MCAN_FrameTypeRemote = 0x1U, /*!< Remote frame type attribute. */
} mcan_frame_type_t; 


/*! @brief MCAN Rx Fifo Filter type. */
typedef enum _mcan_rx_fifo_filter_type
{
    MCAN_RxFifoFilterTypeA = 0x0U, /*!< standard frame,Single Filter.*/
    MCAN_RxFifoFilterTypeB = 0x1U, /*!<standard frame,Dual Filters.*/
    MCAN_RxFifoFilterTypeC = 0x2U, /*!<extended frame,Single Filter.*/
    MCAN_RxFifoFilterTypeD = 0x3U  /*!<extended frame.Dual Filters.*/
} mcan_rx_fifo_filter_type_t;   

/*!
 * @brief MCAN interrupt enable enumerations.
 *
 * This provides constants for the MCAN interrupt enable enumerations for use in the MCAN functions.
 * 
 */
enum _mcan_interrupt_enable
{
    MCAN_RIE_InterruptEnable          = MCAN_IER_RIE_MASK,/*!< Receive Interrupt Enable */
    MCAN_TIE_InterruptEnable          = MCAN_IER_TIE_MASK,/*!< Transmit Interrupt Enable */    
    MCAN_EIE_InterruptEnable          = MCAN_IER_EIE_MASK,/*!< Error Warning InterruptEnable */    
    MCAN_DOIE_InterruptEnable         = MCAN_IER_DOIE_MASK,/*!< Data Overrun Interrupt Enable */
    MCAN_WUIE_InterruptEnable         = MCAN_IER_WUIE_MASK,/*!< Wake-Up Interrupt Enable */    
    MCAN_EPIE_InterruptEnable         = MCAN_IER_EPIE_MASK,/*!< Error Passive Interrupt Enable */ 
    MCAN_ALIE_InterruptEnable         = MCAN_IER_ALIE_MASK,/*!< Arbitration Lost Interrupt Enable */       
    MCAN_BEIE_InterruptEnable         = MCAN_IER_BEIE_MASK,/*!< Bus Error Interrupt Enable */     
}; 

/*!
 * @brief MCAN status flags.
 *
 * This provides constants for the MCAN status flags for use in the MCAN functions.
 * @note The CPU read action clears the bits corresponding to the FlEXCAN_ErrorFlag macro, therefore user need to
 * read status flags and distinguish which error is occur using @ref _mcan_error_flags enumerations.
 */
enum _mcan_Int_flags
{
    MCAN_Receive_Interrupt_Flag                 = MCAN_IR_RI_MASK, /*!< Receive Interrupt Flag. */
    MCAN_Transmit_Interrupt_Flag                = MCAN_IR_TI_MASK, /*!< Transmit Interrupt Flag. */   
    MCAN_Error_Warning_Interrupt_Flag           = MCAN_IR_EI_MASK, /*!< Error Warning Interrupt Flag. */   
    MCAN_Data_Overrun_Interrupt_Flag            = MCAN_IR_DOI_MASK, /*!< Data Overrun Interrupt Flag. */
    MCAN_Wake_Up_Interrupt_Flag                 = MCAN_IR_WUI_MASK, /*!< Wake-Up Interrupt Flag. */   
    MCAN_Error_Passive_Interrupt_Flag           = MCAN_IR_EPI_MASK, /*!< Error Passive Interrupt Interrupt Flag. */     
    MCAN_Arbitration_Loss_Interrupt_Flag        = MCAN_IR_ALI_MASK, /*!< Arbitration Lost Interrupt Flag. */   
    MCAN_Bus_Error_Interrupt_Flag               = MCAN_IR_BEI_MASK  /*!< Bus Error Interrupt Flag. */
}; 

/*!
 * @brief MCAN error code status flags.
 *
 * The MCAN Error Status enumerations is used to report detailed information about the type and location of bus errors.
 */
enum _mcan_error_flags
{
    MCAN_Bit_error              = 0x00,   /*!< Bit error Status. */
    MCAN_Form_error             = 0x01,   /*!< Form error. */
    MCAN_Stuff_error            = 0x02,   /*!< Stuff error. */ 
    MCAN_other_type_error       = 0x03,   /*!< Some other type of error. */     
};

/*!
 * @brief MCAN error code status flags.
 *
 * The MCAN Error Status enumerations is used to report detailed information about the type and location of bus errors.
 */
enum _mcan_direction_flags
{
    MCAN_TRANSMISSION           = 0x00,   /*!< the error occurred during reception. */     
    MCAN_RECEPTION              = 0x01,   /*!< the error occurred during transmission. */   
};

/*!
 * @brief MCAN segment code status flags.
 *
 * The MCAN Error Status enumerations is used to report detailed information about the type and location of bus errors.
 */
enum _mcan_segment_flags
{
    MCAN_SOF              = 0x03,  /*!< Start of frame. */
    MCAN_ID28_ID21        = 0x02,   /*!< ID.28 to ID.21. */
    MCAN_ID20_ID18        = 0x06,   /*!< ID.20 to ID.18 */ 
    MCAN_SRTR_BIT         = 0x04,   /*!< SRTR bit */    
    MCAN_IDE_BIT          = 0x05,  /*!< IDE bit */
    MCAN_ID17_ID13        = 0x07,   /*!< ID.17 to ID.13. */
    MCAN_ID12_ID5         = 0x0F,   /*!< ID.12 to ID.5. */ 
    MCAN_ID4_ID0          = 0x0E,   /*!< ID.4 to ID.0. */      
    MCAN_RTR_BIT          = 0x0C,  /*!< RTR bit */
    MCAN_RES_BIT1         = 0x0D,   /*!< Reserved bit 1. */
    MCAN_RES_BIT0         = 0x09,   /*!< Reserved bit 0. */ 
    MCAN_DLC              = 0x0B,   /*!< Data Length Code. */     
    MCAN_DF               = 0x0A,  /*!< Data Field */
    MCAN_CRC_SEQ          = 0x08,   /*!< CRC sequence. */
    MCAN_CRC_DE           = 0x18,   /*!< CRC delimiter. */ 
    MCAN_ACK              = 0x19,   /*!< Acknowledge. */     
    MCAN_ACK_DE           = 0x1B,  /*!< Acknowledge delimiter */
    MCAN_EOF              = 0x1A,   /*!< End of frame. */
    MCAN_INT              = 0x12,   /*!< Intermission. */ 
    MCAN_AEF              = 0x11,   /*!< Active error flag. */  
    MCAN_PEF              = 0x16,  /*!< Passive error flag */
    MCAN_TDB              = 0x13,  /*!< Tolerate dominant bits */     
    MCAN_ED               = 0x17,   /*!< Error delimiter. */
    MCAN_OF               = 0x1C,   /*!< Overload flag. */ 
};


/*!
 * @brief MCAN Legacy Rx FIFO status flags.
 *
 * The MCAN Legacy Rx FIFO Status enumerations are used to determine the status of the
 * Rx FIFO. Because Rx FIFO occupy the MB0 ~ MB7 (Rx Fifo filter also occupies
 * more Message Buffer space), Rx FIFO status flags are mapped to the corresponding
 * Message Buffer status flags.
 */
enum
{
    MCAN_RBS_Flag       = MCAN_SR_RBS_MASK,   /*!< Receive FIFO Full flag. */  
    MCAN_DOS_Flag       = MCAN_SR_DOS_MASK,   /*!< Rx FIFO overflow flag. */ 
    MCAN_TBS_Flag       = MCAN_SR_TBS_MASK,   /*!< Transmit Buffer Release flag. */   
    MCAN_TCS_Flag       = MCAN_SR_TCS_MASK,   /*!< The last requested transmission has been successfully completed. */ 
    MCAN_RS_Flag        = MCAN_SR_RS_MASK,   /*!< The MCAN2 is in the process of receiving a message. */    
    MCAN_TS_Flag        = MCAN_SR_TS_MASK,   /*!< The MCAN2 is in the process of transmitting a message. */  
    MCAN_ES_Flag        = MCAN_SR_ES_MASK,   /*!< At least one of the error counters has reached or exceeded the CPU warning limit defined by the Error Warning Limit Register (EWL). */ 
    MCAN_BS_Flag        = MCAN_SR_BS_MASK,   /*!< The MCAN2 is in ¡®Bus Off¡¯ state and is not involved in bus activities.. */    
    
};


/*!
 * @brief MCAN Arbitration Lost Capture status flags.
 *
 * The MCAN alc Status enumerations is used to report current Arbitration Lost bit.
 */
enum _mcan_alc_flags
{
    MCAN_ID28              = 0x00,   /*!< Arbitration lost in 1st bit of identifier (ID.28).. */
    MCAN_ID27              = 0x01,   /*!< Arbitration lost in 2st bit of identifier (ID.27).. */  
    MCAN_ID26              = 0x02,   /*!< Arbitration lost in 3st bit of identifier (ID.26).. */
    MCAN_ID25              = 0x03,   /*!< Arbitration lost in 4st bit of identifier (ID.25).. */         
    MCAN_ID24              = 0x04,   /*!< Arbitration lost in 5st bit of identifier (ID.24).. */
    MCAN_ID23              = 0x05,   /*!< Arbitration lost in 6st bit of identifier (ID.23).. */  
    MCAN_ID22              = 0x06,   /*!< Arbitration lost in 7st bit of identifier (ID.22).. */
    MCAN_ID21              = 0x07,   /*!< Arbitration lost in 8st bit of identifier (ID.21).. */           
    MCAN_ID20              = 0x08,   /*!< Arbitration lost in 9st bit of identifier (ID.20).. */
    MCAN_ID19              = 0x09,   /*!< Arbitration lost in 10st bit of identifier (ID.19).. */  
    MCAN_ID18              = 0x0A,   /*!< Arbitration lost in 11st bit of identifier (ID.18).. */
    MCAN_SRTR              = 0x0B,   /*!< Arbitration lost in  SRTR bit..  */  
    MCAN_IDE               = 0x0C,   /*!< Arbitration lost in   IDE bit..  */    
    MCAN_ID17              = 0x0D,   /*!< Arbitration lost in 12st bit of identifier (ID.17).. */
    MCAN_ID16              = 0x0E,   /*!< Arbitration lost in 13st bit of identifier (ID.16).. */  
    MCAN_ID15              = 0x0F,   /*!< Arbitration lost in 14st bit of identifier (ID.15).. */
    MCAN_ID14              = 0x10,   /*!< Arbitration lost in 15st bit of identifier (ID.14).. */        
    MCAN_ID13              = 0x11,   /*!< Arbitration lost in 16st bit of identifier (ID.13).. */    
    MCAN_ID12              = 0x12,   /*!< Arbitration lost in 17st bit of identifier (ID.12).. */  
    MCAN_ID11              = 0x13,   /*!< Arbitration lost in 18st bit of identifier (ID.11).. */  
    MCAN_ID10              = 0x14,   /*!< Arbitration lost in 19st bit of identifier (ID.10).. */  
    MCAN_ID9               = 0x15,   /*!< Arbitration lost in 20st bit of identifier (ID.9).. */ 
    MCAN_ID8               = 0x16,   /*!< Arbitration lost in 21st bit of identifier (ID.8).. */ 
    MCAN_ID7               = 0x17,   /*!< Arbitration lost in 22st bit of identifier (ID.7).. */         
    MCAN_ID6               = 0x18,   /*!< Arbitration lost in 23st bit of identifier (ID.6).. */    
    MCAN_ID5               = 0x19,   /*!< Arbitration lost in 24st bit of identifier (ID.5).. */  
    MCAN_ID4               = 0x1A,   /*!< Arbitration lost in 25st bit of identifier (ID.4).. */  
    MCAN_ID3               = 0x1B,   /*!< Arbitration lost in 26st bit of identifier (ID.3).. */  
    MCAN_ID2               = 0x1C,   /*!< Arbitration lost in 27st bit of identifier (ID.2).. */ 
    MCAN_ID1               = 0x1D,   /*!< Arbitration lost in 28st bit of identifier (ID.1).. */ 
    MCAN_ID0               = 0x1E,   /*!< Arbitration lost in 29st bit of identifier (ID.0).. */     
    MCAN_RTR               = 0x1F,   /*!< Arbitration lost in RTR bit.. */     
};


/*! @brief MCAN message frame structure. */
typedef struct _mcan_frame
{
    struct
    {
        uint8_t length : 4;     /*!< CAN frame data length in bytes (Range: 0~8). */
        uint8_t Reserved: 2;            /*!< Reserved. */
        uint8_t type : 1;       /*!< CAN Frame Type(DATA or REMOTE). */
        uint8_t format : 1;     /*!< CAN Frame Identifier(STD or EXT format). */
    };
    struct
    {
        uint32_t id : 29; /*!< CAN Frame Identifier. */
        uint32_t : 3;     /*!< Reserved. */
    };
    union
    {
        struct
        {
            uint32_t dataWord0; /*!< CAN Frame payload word0. */
            uint32_t dataWord1; /*!< CAN Frame payload word1. */
        };
        struct
        {
            uint8_t dataByte0; /*!< CAN Frame payload byte0. */
            uint8_t dataByte1; /*!< CAN Frame payload byte1. */
            uint8_t dataByte2; /*!< CAN Frame payload byte2. */
            uint8_t dataByte3; /*!< CAN Frame payload byte3. */
            uint8_t dataByte4; /*!< CAN Frame payload byte4. */
            uint8_t dataByte5; /*!< CAN Frame payload byte5. */
            uint8_t dataByte6; /*!< CAN Frame payload byte6. */
            uint8_t dataByte7; /*!< CAN Frame payload byte7. */
        };
    };
} mcan_frame_t; 



/*! @brief MCAN protocol timing characteristic configuration structure. */
typedef struct _mcan_timing_config 
{
    int brp;  				/*!< Classic CAN or CAN FD nominal phase bit rate prescaler. */
	uint8_t rJumpwidth;  	/*!< Classic CAN or CAN FD nominal phase Re-sync Jump Width. */
    uint8_t tseg1; 			/*!< Classic CAN or CAN FD nominal phase Segment 1. */
    uint8_t tseg2; 			/*!< Classic CAN or CAN FD nominal phase Segment 2. */
	uint8_t sam;  			/*!<1:The bus will be sampled three times.0:The bus will be sampled once.*/   
    double bitrate_error;
    double sample_point;  
} mcan_timing_config_t; 

/*! @brief MCAN module configuration structure.
 *  @deprecated Do not use the baudRate. It has been superceded bitRate
 */
typedef struct _mcan_config 
{
    union
    {
        struct
        {
            uint32_t baudRate; /*!< MCAN bit rate in bps, for classical CAN. */
        };
        struct
        {
            uint32_t bitRate; /*!< MCAN bit rate in bps, for classical CAN. */
        };
    };
    bool enableSelfTestMode;          /*!< Enable or Disable Self Test Mode. */
    bool enableListenOnlyMode;          /*!< Enable or Disable Listen Only Mode. */
    bool enableFilterdMode;             /*!< select double or single Acceptance Filter Mode. 0 :double,1:single*/
    mcan_timing_config_t timingConfig; /* Protocol timing . */
} mcan_config_t; 


/*! @brief MCAN Legacy Rx FIFO configuration structure.M_xx is the mask,"1" marks the 
 * corresponding bit as not caring ,"0" marks the corresponding bit as a must match.
 */
typedef struct _mcan_rx_filter_config
{
    mcan_rx_fifo_filter_type_t FilterType; /*!< The MCAN Legacy Rx FIFO Filter type. */
    union {
         struct {
            uint16_t id; 
            uint8_t rtr;
            uint8_t DByte1; 
            uint8_t DByte2; 
            uint16_t M_id;  
            uint8_t M_rtr;
            uint8_t M_DByte1; 
            uint8_t M_DByte2;               
        }typeA_t;

         struct {
            uint16_t id1; 
            uint16_t id2;
            uint8_t rtr1;
            uint8_t rtr2;
            uint8_t DByte1;              
            uint16_t M_id1; 
            uint16_t M_id2;
            uint8_t M_rtr1;
            uint8_t M_rtr2;
            uint8_t M_DByte1;             
        }typeB_t;    

         struct {
            uint32_t id; 
            uint8_t rtr;
            uint32_t M_id; 
            uint8_t M_rtr;
        }typeC_t;  
         
         struct {
            uint16_t id1_28_13; 
            uint16_t id2_28_13;
            uint16_t M_id1_28_13; 
            uint16_t M_id2_28_13;
        }typeD_t;               
    }filter;
         
} mcan_rx_filter_config_t;  


/******************************************************************************
 * API
 *****************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */


/*!
 * @brief Get the MCAN instance from peripheral base address.
 *
 * @param base MCAN peripheral base address.
 * @return MCAN instance.
 */
uint8_t MCAN_GetInstance(MCAN_Type *base); 

/*!
 * @brief Calculates the segment values for a single bit time for classical CAN.
 *
 * This function use to calculates the Classical CAN segment values which will be set in BTR0/BTR1 register.
 *
 * @param base MCAN peripheral base address.
 * @param tqNum Number of time quantas per bit, range in 8 ~ 25 when use CTRL1.
 */
void MCAN_GetSegments(MCAN_Type *base,
                                uint32_t bitRate,
                                uint8_t tqNum,
                                mcan_timing_config_t *pTimingConfig);


/*!
 * @brief Calculates the improved timing values by specific bit Rates for classical CAN.
 *
 * This function use to calculates the Classical CAN timing values according to the given bit rate. The Calculated
 * timing values will be set in BTR0/BTR1 register.
 *
 * @param base MCAN peripheral base address.
 * @param fxtal1 The Source clock frequency in Hz. 
 * @param desired_bitrate  The classical CAN speed in bps defined by user, should be less than or equal to 1Mbps.
 * @param optimal Pointer to the MCAN timing configuration structure.
 *
 * @return TRUE if timing configuration found, FALSE if failed to find configuration.
 */
bool MCAN_CalculateImprovedTimingValues(   uint32_t fxtal1,
                                           uint32_t desired_bitrate,
                                           mcan_timing_config_t *optimal);

/*!
 * brief Initializes a MCAN instance.
 *
 * This function initializes the MCAN module with user-defined settings.
 * This example shows how to set up the mcan_config_t parameters and how
 * to call the MCAN_Init function by passing in these parameters.
 *  code
 *   mcan_config_t mcanConfig;
 *   mcanConfig.bitRate              = 250000U;
 *   mcanConfig.enableListenOnlyMode       = false;
 *   mcanConfig.enableSelfReception    = false;
 *   mcanConfig.timingConfig         = timingConfig;
 *   MCAN_Init(CAN0, &mcanConfig);
 *   endcode
 *
 * param base MCAN peripheral base address.
 * param pConfig Pointer to the user-defined configuration structure.
 */
void MCAN_Init(MCAN_Type *base, const mcan_config_t *pConfig); 


/*!
 * brief De-initializes a MCAN instance.
 *
 * This function disables the MCAN module clock and sets all register values
 * to the reset value.
 *
 * param base MCAN peripheral base address.
 */
void MCAN_Deinit(MCAN_Type *base); 

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the MCAN configuration structure to default values. The default
 * values are as follows.
 *   MCAN_ClkSrc0;//75MHZ
 *   mcanConfig->bitRate                              = 250000U;
 *   mcanConfig->enableSelfTestMode                  = false;
 *   mcanConfig->enableListenOnlyMode                 = false;
 *   mcanConfig->enableFilterdMode                    = true;
 *   mcanConfig.timingConfig                          = timingConfig;
 *
 * param pConfig Pointer to the MCAN configuration structure.
 */
void MCAN_GetDefaultConfig(mcan_config_t *pConfig); 

/* @} */

/*!
 * @name Configuration.
 * @{
 */

/*!
 * brief Sets the MCAN classical protocol timing characteristic.
 *
 * This function gives user settings to classical CAN nominal phase timing characteristic.
 * The function is for an experienced user. For less experienced users, call the MCAN_GetDefaultConfig()
 * and get the default timing characteristicsthe, then call MCAN_Init() and fill the
 * bit rate field.
 *
 * note Calling MCAN_SetTimingConfig() overrides the bit rate set
 * in MCAN_Init().
 *
 * param base MCAN peripheral base address.
 * param pConfig Pointer to the timing configuration structure.
 */
void MCAN_SetTimingConfig(MCAN_Type *base, const mcan_timing_config_t *pConfig); 


/*!
 * brief Configures the MCAN Rx FIFO.
 *
 * This function configures the MCAN Rx with given configuration.
 * note  Rx FIFO only can receive classic CAN message.
 *
 * param base MCAN peripheral base address.
 * param pRxFifoConfig Pointer to the MCAN Legacy Rx FIFO configuration structure. Can be NULL when enable parameter
 *                      is false.
 * param enable Enable.
 *              - true: Configures Legacy Rx FIFO.
 *              - false: Disable Configures Legacy Rx FIFO.
 */
void MCAN_SetRxFifoConfig(MCAN_Type *base, const mcan_rx_filter_config_t *pRxFifoConfig);


/*!
 * brief Performs a polling receive transaction on the CAN bus.
 *
 * note  A transfer handle does not need to be created  before calling this API.
 *
 * param base MCAN peripheral base pointer.
 * param mbIdx The MCAN Message Buffer index.
 * param pRxFrame Pointer to CAN message frame structure for reception.
 * retval sStatus_Success            - Rx Message Buffer is full and has been read successfully.
 * retval sStatus_MCAN_RxOverflow    - Rx Message Buffer is already overflowed and has been read successfully.
 * retval sStatus_Fail               - Rx Message Buffer is empty.
 */
sstat_t MCAN_TransferReceiveBlocking(MCAN_Type *base,mcan_frame_t *pRxFrame);
/*!
 * brief get the value of the SR status register.
 *
 * param base MCAN peripheral base pointer.
 * retval base->SR - Status value.
 */
static inline uint8_t MCAN_GetStatusFlags(MCAN_Type *base) 
{
    return base->SR;
}
/*!
 * brief get the interrupt source.
 *
 * param base MCAN peripheral base pointer.
 * retval base->IR  - interrupt source.
 */
static inline uint8_t MCAN_GetItStatusFlags(MCAN_Type *base) 
{
    return base->IR;
}

/*!
 * @brief Clears status flags with the provided mask.
 *
 * This function clears the MCAN status flags with a provided mask. An automatically cleared flag
 * can't be cleared by this function.
 *
 * @param base MCAN peripheral base address.
 * @param mask The status flags to be cleared, it is logical OR value of @ref _mcan_flags.
 */

static inline void MCAN_ClearStatusFlags(MCAN_Type *base, uint8_t mask)  
{
    /* Write 1 to clear status flag. */
   // base->SR = mask;
}

/*!
 * @brief Gets the MCAN Bus Error Counter value.
 *
 * This function gets the MCAN Bus Error Counter value for both Tx and
 * Rx direction. These values may be needed in the upper layer error handling.
 *
 * @param base MCAN peripheral base address.
 * @param txErrBuf Buffer to store Tx Error Counter value.
 * @param rxErrBuf Buffer to store Rx Error Counter value.
 */
static inline void MCAN_GetBusErrCount(MCAN_Type *base, uint8_t *txErrBuf, uint8_t *rxErrBuf)
{
    if (NULL != txErrBuf)
    {
        *txErrBuf = (uint8_t)(base->RXERR & MCAN_TXERR_COUNTER_MASK);
    }

    if (NULL != rxErrBuf)
    {
        *rxErrBuf = (uint8_t)(base->TXERR & MCAN_RXERR_COUNTER_MASK);
    }
} 

/*!
 * @brief Gets the completion status of the last requested transmission.
 *
 * @param base MCAN peripheral base address.
 * @return The status of last requested transmission.
 */

static inline uint8_t MCAN_GetTxStatusFlags(MCAN_Type *base)
{
    return (base->SR & MCAN_SR_TCS_MASK);
} 

/*!
 * @brief Gets the the status of the receiving buffer flags.
 *
 * @param base MCAN peripheral base address.
 * @return The status of the receiving buffer.
 */
static inline uint8_t MCAN_GetRBStatusFlags(MCAN_Type *base)
{
    return (base->SR & MCAN_SR_RBS_MASK);
}  

/*!
 * @brief Enables MCAN interrupts according to the provided mask.
 *
 * This function enables the MCAN interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members, see @ref _mcan_interrupt_enable.
 *
 * @param base MCAN peripheral base address.
 * @param mask The interrupts to enable. Logical OR of @ref _mcan_interrupt_enable.
 */

static inline void MCAN_EnableInterrupts(MCAN_Type *base, uint8_t mask)
{

    base->IER |=
        (uint8_t)(mask & ( (uint8_t)MCAN_RIE_InterruptEnable | (uint8_t) MCAN_TIE_InterruptEnable |
                           (uint8_t)MCAN_EIE_InterruptEnable | (uint8_t)MCAN_DOIE_InterruptEnable |
                           (uint8_t)MCAN_WUIE_InterruptEnable| (uint8_t)MCAN_EPIE_InterruptEnable |
                           (uint8_t)MCAN_ALIE_InterruptEnable| (uint8_t)MCAN_BEIE_InterruptEnable));
} 

/*!
 * @brief Disables MCAN interrupts according to the provided mask.
 *
 * This function disables the MCAN interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members, see @ref _mcan_interrupt_enable.
 *
 * @param base MCAN peripheral base address.
 * @param mask The interrupts to disable. Logical OR of @ref _mcan_interrupt_enable.
 */

static inline void MCAN_DisableInterrupts(MCAN_Type *base, uint32_t mask)
{
    /* Solve interrupt enable bits in CTRL1 register. */
    base->IER &=
        (~(uint8_t)(mask & ( (uint8_t)MCAN_RIE_InterruptEnable | (uint8_t) MCAN_TIE_InterruptEnable |
                           (uint8_t)MCAN_EIE_InterruptEnable | (uint8_t)MCAN_DOIE_InterruptEnable |
                           (uint8_t)MCAN_WUIE_InterruptEnable| (uint8_t)MCAN_EPIE_InterruptEnable |
                           (uint8_t)MCAN_ALIE_InterruptEnable| (uint8_t)MCAN_BEIE_InterruptEnable)));
}


/*!
 * brief MCAN enter reset mode,.
 * Set the bus timing parameters and the message receiving filter in Reset mode.
 * param base MCAN peripheral base pointer.
 */
static inline void MCAN_Enter_Reset_Mode(MCAN_Type *base)
{
    base->MOD |= MCAN_MOD_RM_MASK;
} 

/*!
 * brief MCAN enter operation mode,.
 * Data can be transmitted and received in operating mode.
 * param base MCAN peripheral base pointer.
 */
static inline void MCAN_Enter_Operating_Mode(MCAN_Type *base)
{
    base->MOD &= ~MCAN_MOD_RM_MASK;
} 


/*!
 * brief Writes a MCAN Message to the Transmit Message Buffer.
 *
 * This function writes a CAN Message to the specified Transmit Message Buffer
 * and Transmission Request to start CAN Message transmit. After
 * that the function returns immediately.
 *
 * param base MCAN peripheral base address.
 * param pTxFrame Pointer to CAN message frame to be sent.
 * retval sStatus_Success - Write Tx Message Buffer Successfully.
 * retval sStatus_Fail    - Tx Message Buffer is currently in use.
 */
sstat_t MCAN_WriteTxMb(MCAN_Type *base, const mcan_frame_t *pTxFrame);

/*!
 * brief Reads a MCAN Message from Receive Message Buffer.
 *
 * This function reads a CAN message from a specified Receive Message Buffer.
 * The function fills a receive CAN message frame structure with
 * just received data and activates the Message Buffer again.
 * The function returns immediately.
 *
 * param base MCAN peripheral base address.
 * param pRxFrame Pointer to CAN message frame structure for reception.
 * retval sStatus_Success            - Rx Message Buffer is full and has been read successfully.
 * retval sStatus_MCAN_RxOverflow    - Rx Message Buffer is already overflowed and has been read successfully.
 * retval sStatus_Fail               - Rx Message Buffer is empty.
 */
sstat_t MCAN_ReadRxBuffer(MCAN_Type *base,mcan_frame_t *pRxFrame);


/* @} */

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Performs a polling send transaction on the CAN bus.
 *
 * @note  A transfer handle does not need to be created  before calling this API.
 *
 * @param base MCAN peripheral base pointer.
 * @param mbIdx The MCAN Message Buffer index.
 * @param pTxFrame Pointer to CAN message frame to be sent.
 * @param SelfReception  disable or enable Self Reception Request.
 * @retval sStatus_Success - Write Tx Message Buffer Successfully.
 * @retval sStatus_Fail    - Tx Message Buffer is currently in use.
 */
sstat_t MCAN_TransferSendBlocking(MCAN_Type *base,mcan_frame_t *pTxFrame,bool SelfReception);


/*!
 * @brief Aborts the interrupt driven message send process.
 *
 * This function aborts the interrupt driven message send process.
 *
 * @param base MCAN peripheral base address.
 * @param handle MCAN handle pointer.
 * @param mbIdx The MCAN Message Buffer index.
 */
void MCAN_TransferAbortSend(MCAN_Type *base);

/*!
 * @brief Aborts the interrupt driven message receive process.
 *
 * This function aborts the interrupt driven message receive process.
 *
 * @param base MCAN peripheral base address.
 * @param handle MCAN handle pointer.
 * @param mbIdx The MCAN Message Buffer index.
 */
void MCAN_TransferAbortReceive(MCAN_Type *base);


/*!
 * brief Check unhandle interrupt events
 *
 * param base MCAN peripheral base address.
 * return TRUE if unhandled interrupt action exist, FALSE if no unhandlered interrupt action exist.
 */
 bool MCAN_CheckUnhandleInterruptEvents(MCAN_Type *base);
 
 
/*!
 * brief get the tx rx error count 
 *
 * param base MCAN peripheral base address.
 * param RxErrCount,Store the receive error count values
 * param TxErrCount,Store the send error count values
 */
void MCAN_Get_Rx_Tx_Counter(MCAN_Type *base,uint8_t*RxErrCount,uint8_t*TxErrCount);

/*!
 * brief  Arbitration Lost Capture 
 * note   The position of the lost arbitration bit can be found in  @ref _mcan_alc_flags.
 *
 * param base MCAN peripheral base address.
 * param alc,Store the Arbitration Lost Capture values
 */
void MCAN_Get_Arbitration_Lost_Capture(MCAN_Type *base,uint8_t*alc);

/*!
 * brief get Error Code Capture Register 
 * param base MCAN peripheral base address.
 * param EC,Error Code
 * param D,Direction
 * param SC,Segment Code
 * note   EC See  @ref _mcan_error_flags,D See @ref _mcan_direction_flagsSC,See  @ref _mcan_segment_flags.
 */
void MCAN_Get_Error_Code_Capture(MCAN_Type *base,uint8_t*EC,uint8_t*D,uint8_t*SC);

/*!
 * brief Set the error warning limit value 
 *
 * param base MCAN peripheral base address.
 * param errWValue,error warning limit value
 */
void MCAN_Set_Error_Warning_Value(MCAN_Type *base,uint8_t errWValue);


/*!
 * brief Set Mcan enter sleep Mode. 
 *
 * param base MCAN peripheral base address.
 * param enable  enable or diaable MCAN sleep mode
 */
sstat_t MCAN_Enter_sleep_Mode(MCAN_Type *base,bool enable);

/* @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif  /*_MCAN_H_*/


