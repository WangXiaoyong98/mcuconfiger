/*
  ******************************************************************************
  * @file           : mcan.c
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

#include "math.h"
#include "mcan.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/* According to CiA doc 301 v4.2.0 and previous version. */
#define IDEAL_SP_LOW  (750U)
#define IDEAL_SP_MID  (800U)
#define IDEAL_SP_HIGH (875U)

#define IDEAL_SP_FACTOR (1000U)

/* Define the max value of bit timing segments when use different timing register. */
#define MAX_TSEG1             (16U) 
#define MAX_TSEG2             (8U) 
#define MAX_TQ_NUM            (25U) 
#define MIN_TQ_NUM            (8U) 
#define MAX_RJW               (MCAN_BTR0_SJW_MASK >> MCAN_BTR0_SJW_SHIFT)
#define MAX_PRESDIV           (128U) 

/* TSEG1 corresponds to the sum of xPROPSEG and xPSEG1, TSEG2 corresponds to the xPSEG2 value. */
#define MIN_TIME_SEGMENT1 (5U) 
#define MIN_TIME_SEGMENT2 (2U) 

/* Define maximum MCAN  bit rate supported by MCAN. */
#define MAX_MCAN_BITRATE   (1000000U) 
#define MIN_MCAN_BITRATE   (30000U) 



/*! @brief MCAN Internal State. */
enum _mcan_state
{
    MCAN_StateIdle     = 0x0, /*!< RxFIFO idle.*/
    MCAN_StateRxData   = 0x1, /*!< receiving.*/
    MCAN_StateRxRemote = 0x2, /*!< receiving remote reply.*/
    MCAN_StateTxData   = 0x3, /*!< transmitting.*/
    MCAN_StateTxRemote = 0x4, /*!< transmitting remote request.*/
    MCAN_StateRxFifo   = 0x5, /*!< RxFIFO receiving.*/
}; 

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*!
 * @brief Set bit rate of MCAN classical CAN frame or CAN FD frame nominal phase.
 *
 * This function set the bit rate of classical CAN frame base on the value of the
 * parameter passed in. Users need to ensure that the timing segment values (phaseSeg1, phaseSeg2 and propSeg) match the
 * clock and bit rate, if not match, the final output bit rate may not equal the bitRate_Bps value. Suggest use
 * MCAN_CalculateImprovedTimingValues() to get timing configuration.
 *
 * @param base MCAN peripheral base address.
 * @param bitRate_Bps Bit rate in Bps.
 * @param timingConfig MCAN timingConfig.
 */
static void MCAN_SetBitRate(MCAN_Type *base,
                               uint32_t bitRate_Bps,
                               mcan_timing_config_t timingConfig);



/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Array of MCAN peripheral base address. */
static MCAN_Type *const s_mcanBases[] = MCAN_BASE_PTRS; 
///* Array of MCAN IRQ number. */
static const IRQn_Type McanIRQ[] = MCAN_IRQS;


/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Get the MCAN instance from peripheral base address.
 *
 * param base MCAN peripheral base address.
 * return MCAN instance.
 */
uint8_t MCAN_GetInstance(MCAN_Type *base)  
{
    uint8_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_mcanBases); instance++)
    {
        if (s_mcanBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_mcanBases));

    return instance;
}

/*!
 * brief Set bit rate of MCAN classical CAN frame nominal phase.
 *
 * This function set the bit rate of classical CAN frame nominal phase base on the value of the
 * parameter passed in. Users need to ensure that the timing segment values (phaseSeg1, phaseSeg2 and propSeg) match the
 * clock and bit rate, if not match, the final output bit rate may not equal the bitRate_Bps value. Suggest use
 * MCAN_CalculateImprovedTimingValues() to get timing configuration.
 *
 * param base MCAN peripheral base address.
 * param bitRate_Bps Bit rate in Bps.
 * param timingConfig MCAN timingConfig.
 */
static void MCAN_SetBitRate(MCAN_Type *base,
                               uint32_t bitRate_Bps,
                               mcan_timing_config_t timingConfig)
{
    /* MCAN classical CAN frame nominal phase timing setting formula:
     * quantum = 1 + (phaseSeg1 + 1) + (phaseSeg2 + 1) + (propSeg + 1);
     */
    uint8_t quantum = (1U + ((uint32_t)timingConfig.tseg1 + 1U) + ((uint32_t)timingConfig.tseg2 + 1U));

    /* Assertion: Desired bit rate is too high. */
    assert(bitRate_Bps <= MAX_MCAN_BITRATE);
    /* Assertion: Desired bit rate is too low. */
    assert(MIN_MCAN_BITRATE <= bitRate_Bps);
    
    if ((MAX_TQ_NUM < quantum)&&(MIN_TQ_NUM > quantum))
    {
        /* No valid timing configuration. */
        return;
    }

    if ((timingConfig.tseg1+1) >= MAX_TSEG1)
    {
        /* No valid timing configuration. */
        return;
    }

    if ((timingConfig.tseg2+1) >= MAX_TSEG2)
    {
        /* No valid timing configuration. */
        return;
    }

    /* Update actual timing characteristic. */
    MCAN_SetTimingConfig(base, (const mcan_timing_config_t *)(uint32_t)&timingConfig);
} 


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
 * param sourceClock_Hz MCAN Protocol Engine clock source frequency in Hz.
 */
void MCAN_Init(MCAN_Type *base, const mcan_config_t *pConfig)
{
    /* Assertion. */
    assert(NULL != pConfig);
    assert(pConfig->bitRate > 0U);

    uint8_t ctrl1Temp;

    /* Enable MCAN Module enter reset mode. */
    MCAN_Enter_Reset_Mode(base);
    /* Save current MODE value and enable to enter Reset mode(enabled by default). */
    ctrl1Temp = base->MOD;

    /* select filter Mode */
    ctrl1Temp = (pConfig->enableFilterdMode) ? ctrl1Temp | MCAN_MOD_AFM_MASK : ctrl1Temp & (~MCAN_MOD_AFM_MASK);


    /* enable only listen mode */
    ctrl1Temp = (pConfig->enableListenOnlyMode) ? ctrl1Temp | MCAN_MOD_LOM_MASK : ctrl1Temp & (~MCAN_MOD_LOM_MASK);

    /* enable Self Test Mode */
    ctrl1Temp = (pConfig->enableSelfTestMode) ? ctrl1Temp | MCAN_MOD_STM_MASK : ctrl1Temp & (~MCAN_MOD_STM_MASK);
       
    base->MOD = ctrl1Temp;
    MCAN_Enter_Operating_Mode(base);

    /* Bit Rate Configuration.*/
    MCAN_SetBitRate(base,pConfig->bitRate, pConfig->timingConfig);
}


/*!
 * brief De-initializes a MCAN instance.
 *
 * This function disables the MCAN module clock and sets all register values
 * to the reset value.
 *
 * param base MCAN peripheral base address.
 */
void MCAN_Deinit(MCAN_Type *base)
{ 
    /* Disable MCAN clock. */
//    if(MCAN1 == base)
//       MCAN1_DisableClock;   
//    if( MCAN2 == base)
//        MCAN2_DisableClock;    
}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the MCAN configuration structure to default values. The default
 * values are as follows.
 *   MCAN_ClkSrc0;//70MHZ
 *   mcanConfig->bitRate                              = 250000U;
 *   mcanConfig->enableSelfTestMode                  = false;
 *   mcanConfig->enableListenOnlyMode                 = false;
 *   mcanConfig->enableFilterdMode                    = true;
 *   mcanConfig.timingConfig                          = timingConfig;
 *
 * param pConfig Pointer to the MCAN configuration structure.
 */
void MCAN_GetDefaultConfig(mcan_config_t *pConfig)
{
    /* Assertion. */
    assert(NULL != pConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(pConfig, 0, sizeof(*pConfig));

    /* Initialize MCAN Module config struct with default value. */
    pConfig->bitRate = 250000U;
    
    pConfig->enableSelfTestMode = false;
    pConfig->enableListenOnlyMode = false;
    pConfig->enableFilterdMode = true;

    /* Default protocol timing configuration, nominal bit time quantum is 10 (80% SP).
     * Suggest use MCAN_CalculateImprovedTimingValues to get the
     * improved timing configuration.*/
    pConfig->timingConfig.tseg1  = 0x06;
    pConfig->timingConfig.tseg2  = 0x01;
    pConfig->timingConfig.sam    = SINGLE_SAMPLING;
    pConfig->timingConfig.brp    = 0xD;
    pConfig->timingConfig.rJumpwidth = 1;

}  


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
void MCAN_SetTimingConfig(MCAN_Type *base, const mcan_timing_config_t *pConfig)
{
    /* Assertion. */
    assert(NULL != pConfig);

    /* Enter Reset Mode. */
    MCAN_Enter_Reset_Mode(base);

    /* Cleaning previous Timing Setting. */
    base->BTR0 &= ~(MCAN_BTR0_BRP_MASK | MCAN_BTR0_SJW_MASK);
    /* Updating Timing Setting according to configuration structure. */
    base->BTR0 |= ((pConfig->rJumpwidth << MCAN_BTR0_SJW_SHIFT) | (pConfig->brp << MCAN_BTR0_BRP_SHIFT));    
    
    /* Cleaning previous Timing Setting. */
    base->BTR1 &= ~(MCAN_BTR1_TSEG1_MASK | MCAN_BTR1_TSEG2_MASK | MCAN_BTR1_SAM_MASK);
     /* Updating Timing Setting according to configuration structure. */
    base->BTR1 |= ((pConfig->sam << MCAN_BTR1_SAM_SHIFT)|(pConfig->tseg2 << MCAN_BTR1_TSEG2_SHIFT)|(pConfig->tseg1<< MCAN_BTR1_TSEG1_SHIFT));
    
    /* Exit Freeze Mode. */
    MCAN_Enter_Operating_Mode(base);
} 

/*!
 * brief Calculates the segment values for a single bit time for classical CAN.
 *
 * This function use to calculates the Classical CAN segment values which will be set in BTR0/BTR1 register.
 *
 * param bitRate The classical CAN bit rate in bps.
 * param base MCAN peripheral base address.
 * param tqNum Number of time quantas per bit, range in 8 ~ 25. param pTimingConfig Pointer to the MCAN timing configuration structure.
 */
void MCAN_GetSegments(MCAN_Type *base,
                                uint32_t bitRate,
                                uint8_t tqNum,
                                mcan_timing_config_t *pTimingConfig)
{
    uint32_t ideal_sp;
    uint8_t seg1Max, seg2Max,seg1Min, seg2Min,sjwMAX;

    /* Maximum value allowed in CTRL1 register. */
    seg1Max   = MAX_TSEG1 ;
    seg2Max   = MAX_TSEG2;
    seg1Min   = MIN_TIME_SEGMENT1;
    seg2Min   = MIN_TIME_SEGMENT2;
    sjwMAX    = MAX_RJW+1;

    /* Try to find the ideal sample point, according to CiA 301 doc.*/
    if (bitRate == 1000000U)
    {
        ideal_sp = IDEAL_SP_LOW;
    }
    else if (bitRate >= 800000U)
    {
        ideal_sp = IDEAL_SP_MID;
    }
    else
    {
        ideal_sp = IDEAL_SP_HIGH;
    }
    /* Calculates tseg2. */
    pTimingConfig->tseg2 = (uint8_t)(tqNum - (tqNum * ideal_sp) / (uint32_t)IDEAL_SP_FACTOR);
    if (pTimingConfig->tseg2 < seg2Min)
    {
        pTimingConfig->tseg2 = seg2Min;
    }
    else if (pTimingConfig->tseg2 > seg2Max)
    {
        pTimingConfig->tseg2 = (uint8_t)seg2Max;
    }
    else
    {
        ; /* Intentional empty */
    }

    /* Calculates tseg1. */    
    pTimingConfig->tseg1 = tqNum - pTimingConfig->tseg2 - 1U;
    if( pTimingConfig->tseg1 > seg1Max)
        return;
    
    /* rJumpwidth (sjw) is the minimum value of phaseSeg1 and phaseSeg2. */ 
    pTimingConfig->rJumpwidth =
        (pTimingConfig->tseg1 > pTimingConfig->tseg2) ? pTimingConfig->tseg2 : pTimingConfig->tseg1;
    if (pTimingConfig->rJumpwidth > sjwMAX)
    {
        pTimingConfig->rJumpwidth = (uint8_t)sjwMAX;
    }

    pTimingConfig->tseg1 -= 1U;
    pTimingConfig->tseg2 -= 1U;
    pTimingConfig->rJumpwidth -= 1U;
} 

/*!
 * brief Calculates the improved timing values by specific bit Rates for classical CAN.
 *
 * This function use to calculates the Classical CAN timing values according to the given bit rate. The Calculated
 * timing values will be set in BTR0/BTR1 register. The calculation is based on the recommendation of the CiA 301
 * v4.2.0 and previous version document.
 *
 * param base MCAN peripheral base address.
 * param fxtal1 The Source clock frequency in Hz.
 * param desired_bitrate  The classical CAN speed in bps defined by user, should be less than or equal to 1Mbps.
 * param optimal Pointer to the MCAN timing configuration structure.
 *
 * return TRUE if timing configuration found, FALSE if failed to find configuration.
 */
bool MCAN_CalculateImprovedTimingValues(uint32_t fxtal1,
                                           uint32_t desired_bitrate,
                                           mcan_timing_config_t *optimal)
{
    /* Observe bit rate maximums. */
    assert(desired_bitrate <= MAX_MCAN_BITRATE);
    assert(MIN_MCAN_BITRATE <= desired_bitrate);


    double min_error = 1e9;
    double best_sample_point = 0.75;  // 初始采样点目标为75%
    optimal->brp = -1;

    // Calculate the total number of all possible TQs (Bosch standard: 8-25)
    for (int total_TQ = 8; total_TQ <= 25; total_TQ++) {
        int sum = total_TQ - 3;
        
        // Enumerate all possible decomposition combinations of TSEG1 and TSEG2
        for (int tseg1_reg = 0; tseg1_reg <= 15; tseg1_reg++) {   // TSEG1 register value range: 0 to 15 (corresponding to 1-16 TQ)
            int tseg2_reg = sum - tseg1_reg;
            if (tseg2_reg < 0 || tseg2_reg > 7) continue;        // The value range of the TSEG2 register is 0 to 7 (corresponding to 1 to 8 TQ).

            // Calculate the actual number of TQ (Time Quanta).
            int tseg1_TQ = tseg1_reg + 1;
            int tseg2_TQ = tseg2_reg + 1;
            
            // Calculate the positions of the sampling points
            double sample_point = (1.0 + tseg1_TQ) / (1.0 + tseg1_TQ + tseg2_TQ);
            if (sample_point < 0.75 || sample_point > 0.90) continue; // The sampling points should be between 75% and 90%

            // Calculate the theoretical BRP+1 value
            double brp_plus_1_exact = fxtal1 / (2 * desired_bitrate * total_TQ);
            
            // Traverse all possible BRP+1 candidate values (covering 1-64)
            for (int brp_plus_1 = (int)floor(brp_plus_1_exact - 2); 
                 brp_plus_1 <= (int)ceil(brp_plus_1_exact + 2); 
                 brp_plus_1++) 
            {
                if (brp_plus_1 < 1 || brp_plus_1 > 64) continue;

                // Calculate the actual bit rate and error
                double actual_bitrate = fxtal1 / (2 * brp_plus_1 * total_TQ);
                double error = fabs(actual_bitrate - desired_bitrate) / desired_bitrate;

                // Optimization priority: Minimize composite error and align sampling point close to 80% (lower error & closer to 80% is better)
                double weighted_error = error * 0.7 + fabs(sample_point - 0.80) * 0.3;

                // Update the optimal solution
                if (weighted_error < min_error) {
                    min_error = weighted_error;
                    optimal->brp = brp_plus_1;
                    optimal->tseg1 = tseg1_reg;
                    optimal->tseg2 = tseg2_reg;
                    optimal->bitrate_error = error * 100; 
                    optimal->sample_point = sample_point * 100;
                }
            }
        }
    }
    optimal->brp = optimal->brp-1;
    /* rJumpwidth (sjw) is the minimum value of phaseSeg1 and phaseSeg2. */ 
    optimal->rJumpwidth =
        (optimal->tseg1>optimal->tseg2)?optimal->tseg2:optimal->tseg1;
    if (optimal->rJumpwidth > MAX_RJW)
    {
        optimal->rJumpwidth = (uint8_t)MAX_RJW;
    }    
    
    
    return true;

} 

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
void MCAN_SetRxFifoConfig(MCAN_Type *base, const mcan_rx_filter_config_t *pRxFifoConfig)
{
    /* Assertion. */
    assert(NULL != pRxFifoConfig);

    uint32_t ACRx =0;
    uint32_t AMRx =0;

    
    /* Enter Reset Mode. */
    MCAN_Enter_Reset_Mode(base);

    /* Setup ID Fitlter Type. */
    switch (pRxFifoConfig->FilterType)
    {
        case MCAN_RxFifoFilterTypeA:
             base->MOD |= MCAN_MOD_AFM_MASK;
             ACRx = MCAN_RX_FILTER_STD_S_CODE(pRxFifoConfig->filter.typeA_t.id, pRxFifoConfig->filter.typeA_t.rtr, pRxFifoConfig->filter.typeA_t.DByte1,pRxFifoConfig->filter.typeA_t.DByte2);
             AMRx = MCAN_RX_FILTER_STD_S_MASK(pRxFifoConfig->filter.typeA_t.M_id, pRxFifoConfig->filter.typeA_t.M_rtr, pRxFifoConfig->filter.typeA_t.M_DByte1,pRxFifoConfig->filter.typeA_t.M_DByte2);
            break;
        case MCAN_RxFifoFilterTypeB:
             base->MOD &= ~MCAN_MOD_AFM_MASK;
             ACRx = MCAN_RX_FILTER_STD_D_CODE(pRxFifoConfig->filter.typeB_t.id1,pRxFifoConfig->filter.typeB_t.id2, pRxFifoConfig->filter.typeB_t.rtr1, pRxFifoConfig->filter.typeB_t.rtr2, pRxFifoConfig->filter.typeB_t.DByte1);
             AMRx = MCAN_RX_FILTER_STD_D_MASK(pRxFifoConfig->filter.typeB_t.M_id1,pRxFifoConfig->filter.typeB_t.M_id2, pRxFifoConfig->filter.typeB_t.M_rtr1, pRxFifoConfig->filter.typeB_t.M_rtr2, pRxFifoConfig->filter.typeB_t.M_DByte1);            
            break;
        case MCAN_RxFifoFilterTypeC:
             base->MOD |= MCAN_MOD_AFM_MASK;
             ACRx = MCAN_RX_FILTER_EXT_S_CODE(pRxFifoConfig->filter.typeC_t.id, pRxFifoConfig->filter.typeC_t.rtr) ;
             AMRx = MCAN_RX_FILTER_EXT_S_MASK(pRxFifoConfig->filter.typeC_t.M_id, pRxFifoConfig->filter.typeC_t.M_rtr) ;
            break;
        case MCAN_RxFifoFilterTypeD:
            base->MOD &= ~MCAN_MOD_AFM_MASK;
            ACRx = MCAN_RX_FILTER_EXT_D_CODE(pRxFifoConfig->filter.typeD_t.id1_28_13,pRxFifoConfig->filter.typeD_t.id2_28_13) ;
            AMRx = MCAN_RX_FILTER_EXT_D_MASK(pRxFifoConfig->filter.typeD_t.M_id1_28_13,pRxFifoConfig->filter.typeD_t.M_id2_28_13) ;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
    
    base->ACCEPT.ACR[0] = (uint8_t)((ACRx & 0xFF000000)>>24);
    base->ACCEPT.AMR[0] = (uint8_t)((AMRx & 0xFF000000)>>24);
    base->ACCEPT.ACR[1] = (uint8_t)((ACRx & 0x00FF0000)>>16);
    base->ACCEPT.AMR[1] = (uint8_t)((AMRx & 0x00FF0000)>>16);
    base->ACCEPT.ACR[2] = (uint8_t)((ACRx & 0x0000FF00)>>8);
    base->ACCEPT.AMR[2] = (uint8_t)((AMRx & 0x0000FF00)>>8); 
    base->ACCEPT.ACR[3] = (uint8_t)(ACRx & 0x000000FF);
    base->ACCEPT.AMR[3] = (uint8_t)(AMRx & 0x000000FF);  

    /* enter operation Mode. */
    MCAN_Enter_Operating_Mode(base);
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
sstat_t MCAN_WriteTxMb(MCAN_Type *base,const mcan_frame_t *pTxFrame)
{
    /* Assertion. */
    assert(NULL != pTxFrame);
    assert(pTxFrame->length <= 8U);

    sstat_t status;

    /* Check if Message Buffer is available. */
    if (base->SR & MCAN_SR_TBS_MASK)
    {
        base->TXBUF_W.TXFRMINFO = ((pTxFrame->format&0x01)<<MCAN_TXFRMINFO_FF_SHIFT)| ((pTxFrame->type&0x01)<<MCAN_TXFRMINFO_RTR_SHIFT)|(pTxFrame->length&0x0F);
        
        if(pTxFrame->format == MCAN_FrameFormatStandard){
            base->TXBUF_W.TXDATAINFO[0] =  MCAN_TXDATAINFO_S_ID28_21_SET(pTxFrame->id);
            base->TXBUF_W.TXDATAINFO[1] =  MCAN_TXDATAINFO_S_ID20_18_SET(pTxFrame->id);          
            base->TXBUF_W.TXDATAINFO[2] =  pTxFrame->dataByte0;
            base->TXBUF_W.TXDATAINFO[3] =  pTxFrame->dataByte1;            
            base->TXBUF_W.TXDATAINFO[4] =  pTxFrame->dataByte2;
            base->TXBUF_W.TXDATAINFO[5] =  pTxFrame->dataByte3; 
            base->TXBUF_W.TXDATAINFO[6] =  pTxFrame->dataByte4;
            base->TXBUF_W.TXDATAINFO[7] =  pTxFrame->dataByte5;  
            base->TXBUF_W.TXDATAINFO[8] =  pTxFrame->dataByte6; 
            base->TXBUF_W.TXDATAINFO[9] =  pTxFrame->dataByte7;                   
        }else if(pTxFrame->format == MCAN_FrameFormatExtend){
            base->TXBUF_W.TXDATAINFO[0]  =  MCAN_TXDATAINFO_E_ID28_21_SET(pTxFrame->id) ;
            base->TXBUF_W.TXDATAINFO[1]  =  MCAN_TXDATAINFO_E_ID20_13_SET(pTxFrame->id);          
            base->TXBUF_W.TXDATAINFO[2]  =  MCAN_TXDATAINFO_E_ID12_5_SET(pTxFrame->id);
            base->TXBUF_W.TXDATAINFO[3]  =  MCAN_TXDATAINFO_E_ID4_0_SET(pTxFrame->id);            
            base->TXBUF_W.TXDATAINFO[4]  =  pTxFrame->dataByte0;
            base->TXBUF_W.TXDATAINFO[5]  =  pTxFrame->dataByte1; 
            base->TXBUF_W.TXDATAINFO[6]  =  pTxFrame->dataByte2;
            base->TXBUF_W.TXDATAINFO[7]  =  pTxFrame->dataByte3;  
            base->TXBUF_W.TXDATAINFO[8]  =  pTxFrame->dataByte4; 
            base->TXBUF_W.TXDATAINFO[9]  =  pTxFrame->dataByte5;
            base->TXBUF_W.TXDATAINFO[10] =  pTxFrame->dataByte6;  
            base->TXBUF_W.TXDATAINFO[11] =  pTxFrame->dataByte7;             
        }        
        status = sStatus_Success;
    }
    else
    {
        /* The Tx Message Buffer is is occupied，return immediately. */
        status = sStatus_Fail;
    }

    return status;
}

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
sstat_t MCAN_ReadRxBuffer(MCAN_Type *base, mcan_frame_t *pRxFrame)
{
    /* Assertion. */
    assert(NULL != pRxFrame);

    uint8_t cs_temp,SR;
    sstat_t status;
    SR = base->SR;
    /* Check to see if Rx Message Buffer is full. */
    if(SR & (MCAN_SR_RBS_MASK|MCAN_SR_DOS_MASK))
    {
        cs_temp = base->RXWINDOW.RXFRMINFO;
        /* Get the message ID and format. */
        pRxFrame->format = (MCAN_RXFRMINFO_FF_GET(cs_temp) != 0U )? (uint8_t)MCAN_FrameFormatExtend :(uint8_t)MCAN_FrameFormatStandard;

        /* Get the message type. */
        pRxFrame->type = MCAN_RXFRMINFO_RTR_GET(cs_temp);

        /* Get the message length. */
        pRxFrame->length = MCAN_RXFRMINFO_DLC_GET(cs_temp);
        
        if(pRxFrame->format){ //Extended frame
            /* Store Message ID. */   
            pRxFrame->id = MCAN_RXDATAINFO_E_ID_GET(base->RXWINDOW.RXDATAINFO[0],base->RXWINDOW.RXDATAINFO[1],base->RXWINDOW.RXDATAINFO[2],base->RXWINDOW.RXDATAINFO[3]);
            pRxFrame->dataByte0 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[4]);
            pRxFrame->dataByte1 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[5]);
            pRxFrame->dataByte2 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[6]);
            pRxFrame->dataByte3 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[7]);
            pRxFrame->dataByte4 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[8]);
            pRxFrame->dataByte5 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[9]);
            pRxFrame->dataByte6 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[10]);
            pRxFrame->dataByte7 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[11]);        
        }else{ //Standard frame
            /* Store Message ID. */   
            pRxFrame->id = MCAN_RXDATAINFO_S_ID_GET(base->RXWINDOW.RXDATAINFO[0],base->RXWINDOW.RXDATAINFO[1]);
            pRxFrame->dataByte0 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[2]);
            pRxFrame->dataByte1 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[3]);
            pRxFrame->dataByte2 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[4]);
            pRxFrame->dataByte3 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[5]);
            pRxFrame->dataByte4 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[6]);
            pRxFrame->dataByte5 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[7]);
            pRxFrame->dataByte6 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[8]);
            pRxFrame->dataByte7 = MCAN_RXDATAINFO_DATAx_GET(base->RXWINDOW.RXDATAINFO[9]);             
        } 
        if(SR & MCAN_SR_DOS_MASK)
        {
            status = sStatus_MCAN_RxOverflow;
        }
        else
        {
            status = sStatus_Success;
        }
        /* Release the received buffer. */  
        base->CMR |= MCAN_CMR_RRB_MASK;
    }
    else
    {
        status = sStatus_Fail;
    }
       
    return status;
}


/*!
 * brief Performs a polling send transaction on the CAN bus.
 *
 * note  A transfer handle does not need to be created  before calling this API.
 *
 * param base MCAN peripheral base pointer.
 * param mbIdx The MCAN Message Buffer index.
 * param pTxFrame Pointer to CAN message frame to be sent.
 * param SelfReception  disable or enable Self Reception Request.
 * retval sStatus_Success - Write Tx Message Buffer Successfully.
 * retval sStatus_Fail    - Tx Message Buffer is currently in use.
 */
sstat_t MCAN_TransferSendBlocking(MCAN_Type *base,mcan_frame_t *pTxFrame,bool SelfReception)
{
    sstat_t status;
    uint16_t TimeoutCount=0xFFFF; 

    /* Write Tx Message Buffer to initiate a data sending. */
    if (sStatus_Success == MCAN_WriteTxMb(base, (const mcan_frame_t *)(uint32_t)pTxFrame))
    {
        if(SelfReception == true)
             base->CMR |= MCAN_CMR_SRR_SET(1);             
        base->CMR |= MCAN_CMR_TR_SET(1);
        status = sStatus_Success;
        /* Wait until CAN Message send out. */
        while (0U == MCAN_GetTxStatusFlags(base))
        {
            TimeoutCount--;
            if(TimeoutCount<2)
            {
                status = sStatus_Fail; 
                break;
            }
        }        
    }
    else
    {
        status = sStatus_Fail;
    }
    return status;
} 

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
sstat_t MCAN_TransferReceiveBlocking(MCAN_Type *base, mcan_frame_t *pRxFrame)
{
/* Wait until Rx Message Buffer non-empty. */

    while(0U == MCAN_GetRBStatusFlags(base))
    {
        
    }

    /* Read Received CAN Message. */
    return MCAN_ReadRxBuffer(base,pRxFrame);
} 


/*!
 * brief Aborts the interrupt driven message send process.
 *
 * This function aborts the interrupt driven message send process.
 *
 * param base MCAN peripheral base address.
 * param handle MCAN handle pointer.
 */
void MCAN_TransferAbortSend(MCAN_Type *base)
{
    base->CMR |= MCAN_CMR_AT_MASK;
}


/*!
 * brief Aborts the interrupt driven message receive process.
 *
 * This function aborts the interrupt driven message receive process.
 *
 * param base MCAN peripheral base address.
 * param handle MCAN handle pointer.
 */
void MCAN_TransferAbortReceive(MCAN_Type *base)
{

    
    
}


/*!
 * brief Check unhandle interrupt events
 *
 * param base MCAN peripheral base address.
 * return TRUE if unhandled interrupt action exist, FALSE if no unhandlered interrupt action exist.
 */
 bool MCAN_CheckUnhandleInterruptEvents(MCAN_Type *base)
{
    bool fgRet = false;

    /* Checking exist error or status flag. */
    if (0U != MCAN_GetItStatusFlags(base))
    {
        fgRet = true;
    }
    else
    {
        fgRet = false;
    }
    return fgRet;
}

/*!
 * brief Set Mcan enter sleep Mode. 
 *
 * param base MCAN peripheral base address.
 * param enable  enable or diaable MCAN sleep mode
 */
sstat_t MCAN_Enter_sleep_Mode(MCAN_Type *base,bool enable)
{
    uint16_t TimeoutCount=0xFFFF;    
    if(enable)
    {
        base->MOD |= MCAN_MOD_SM_MASK;                
        while((base->MOD & MCAN_MOD_SM_MASK) != MCAN_MOD_SM_MASK)
        {
            TimeoutCount--;
            if(TimeoutCount<2)
            {
                base->MOD |= MCAN_MOD_SM_MASK; 
                break;
            }                
        }
        if((base->MOD & MCAN_MOD_SM_MASK))
            return sStatus_Success;
        return sStatus_Fail;     
    }
    else
    {
        base->MOD &= ~MCAN_MOD_SM_MASK;
    }    
    return sStatus_Success;
}




/*!
 * brief get the tx rx error count 
 *
 * param base MCAN peripheral base address.
 * param RxErrCount,Store the receive error count values
 * param TxErrCount,Store the send error count values
 */
void MCAN_Get_Rx_Tx_Counter(MCAN_Type *base,uint8_t*RxErrCount,uint8_t*TxErrCount)
{
   *RxErrCount =  base->RXERR;
   *TxErrCount =  base->TXERR;        
}

/*!
 * brief get Arbitration Lost Capture 
 * note  The position of the lost arbitration bit can be found in @ref _mcan_alc_flags.
 * param base MCAN peripheral base address.
 * param alc,Store the Arbitration Lost Capture values
 */
void MCAN_Get_Arbitration_Lost_Capture(MCAN_Type *base,uint8_t*alc)
{
   *alc =  base->ALC & MCAN_ALC_FIELD_MASK;    
}

/*!
 * brief get Error Code Capture Register 
 *
 * param base MCAN peripheral base address.
 * param EC,Error Code
 * param D,Direction
 * param SC,Segment Code
 * note   EC See  @ref _mcan_error_flags,D See @ref _mcan_direction_flagsSC,See  @ref _mcan_segment_flags.
 */
void MCAN_Get_Error_Code_Capture(MCAN_Type *base,uint8_t*EC,uint8_t*D,uint8_t*SC)
{
    uint8_t ECC;
    ECC =  base->ECC;
    *EC =  ECC & MCAN_ECC_ERROR_CODE_MASK;    
    *D  =  ECC & MCAN_ECC_DIRECTION_MASK;
    *SC =  ECC & MCAN_ECC_SEGMENT_CODE_MASK;
}

/*!
 * brief Set the error warning limit value 
 *
 * param base MCAN peripheral base address.
 * param errWValue,error warning limit value
 */
void MCAN_Set_Error_Warning_Value(MCAN_Type *base,uint8_t errWValue)
{
    MCAN_Enter_Reset_Mode(base);    
    base->EWLR = errWValue;
    MCAN_Enter_Operating_Mode(base);
}
























