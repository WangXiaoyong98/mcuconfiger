/*
  ******************************************************************************
  * @file           : pin_map.h
  * @brief          : Definitions of pin mux info for gpio.c.
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

#ifndef __PIN_MAP_H__
#define __PIN_MAP_H__


#define GPIO_0_GPIO0                    0x00000000U
#define GPIO_0_PA_0                     0x00000000U
#define GPIO_0_EPWM1_A                  0x00010000U
#define GPIO_0_LPTIM3                   0x00020000U

#define GPIO_1_GPIO1                    0x01000000U
#define GPIO_1_PA_1                     0x01000000U
#define GPIO_1_EPWM1_B                  0x01010000U
#define GPIO_1_LPTIM2                   0x01020000U
#define GPIO_1_COMP1OUT1                0x01030000U
#define GPIO_1_OUTPUTXBAR1              0x01040000U

#define GPIO_2_GPIO2                    0x02000000U
#define GPIO_2_PA_2                     0x02000000U
#define GPIO_2_EPWM2_A                  0x02010000U
#define GPIO_2_LPTIM1                   0x02020000U

#define GPIO_3_GPIO3                    0x03000000U
#define GPIO_3_PA_3                     0x03000000U
#define GPIO_3_EPWM2_B                  0x03010000U
#define GPIO_3_SPI1_SIN                 0x03020000U
#define GPIO_3_SPI1_SOUT                0x03030000U

#define GPIO_4_GPIO4                    0x04000000U
#define GPIO_4_PA_4                     0x04000000U
#define GPIO_4_EPWM3_A                  0x04010000U
#define GPIO_4_LPTIM1                   0x04020000U

#define GPIO_5_GPIO5                    0x05000000U
#define GPIO_5_PA_5                     0x05000000U
#define GPIO_5_EPWM3_B                  0x05010000U
#define GPIO_5_SPI1_SOUT                0x05020000U
#define GPIO_5_SPI1_SIN                 0x05030000U

#define GPIO_6_GPIO6                    0x06000000U
#define GPIO_6_PA_6                     0x06000000U
#define GPIO_6_EPWM4_A                  0x06010000U
#define GPIO_6_EPWMSYNCIN               0x06020000U
#define GPIO_6_SYNCOUT                  0x06030000U
#define GPIO_6_OUTPUTXBAR2              0x06040000U

#define GPIO_7_GPIO7                    0x07000000U
#define GPIO_7_PA_7                     0x07000000U
#define GPIO_7_EPWM4_B                  0x07010000U
#define GPIO_7_SCI1_RX                  0x07020000U

#define GPIO_8_GPIO8                    0x08000000U
#define GPIO_8_PA_8                     0x08000000U
#define GPIO_8_EPWM5_A                  0x08010000U
#define GPIO_8_ADCSOCAO                 0x08030000U

#define GPIO_9_GPIO9                    0x09000000U
#define GPIO_9_PA_9                     0x09000000U
#define GPIO_9_EPWM5_B                  0x09010000U
#define GPIO_9_SCI1_TX                  0x09020000U

#define GPIO_10_GPIO10                  0x0a000000U
#define GPIO_10_PA_10                   0x0a000000U
#define GPIO_10_EPWM6_A                 0x0a010000U
#define GPIO_10_ADCSOCBO                0x0a030000U
#define GPIO_10_CLKOUT                  0x0a040000U

#define GPIO_11_GPIO11                  0x0b000000U
#define GPIO_11_PA_11                   0x0b000000U
#define GPIO_11_EPWM6_B                 0x0b010000U
#define GPIO_11_SCI2_RX                 0x0b020000U

#define GPIO_12_GPIO12                  0x0c000000U
#define GPIO_12_PA_12                   0x0c000000U
#define GPIO_12_SCI2_TX                 0x0c020000U
#define GPIO_12_SPI2_SIN                0x0c030000U
#define GPIO_12_OUTPUTXBAR3             0x0c040000U
#define GPIO_12_SPI2_SOUT               0x0c050000U

#define GPIO_13_GPIO13                  0x0d000000U
#define GPIO_13_PA_13                   0x0d000000U
#define GPIO_13_SPI2_SOUT               0x0d030000U
#define GPIO_13_OUTPUTXBAR4             0x0d040000U
#define GPIO_13_SPI2_SIN                0x0d050000U

#define GPIO_14_GPIO14                  0x0e000000U
#define GPIO_14_PA_14                   0x0e000000U
#define GPIO_14_SCI3_TX                 0x0e020000U
#define GPIO_14_SPI2_CLK                0x0e030000U
#define GPIO_14_OUTPUTXBAR5             0x0e040000U

#define GPIO_15_GPIO15                  0x0f000000U
#define GPIO_15_PA_15                   0x0f000000U
#define GPIO_15_SCI3_RX                 0x0f020000U
#define GPIO_15_SPI2_CS0                0x0f030000U
#define GPIO_15_OUTPUTXBAR6             0x0f040000U
#define GPIO_15_SPI1_CS0                0x0f050000U

#define GPIO_16_GPIO16                  0x10000000U
#define GPIO_16_PA_16                   0x10000000U
#define GPIO_16_SPI1_SIN                0x10010000U
#define GPIO_16_SPI1_SOUT               0x10020000U
#define GPIO_16_OUTPUTXBAR7             0x10040000U
#define GPIO_16_SCI1_RX                 0x10050000U

#define GPIO_17_GPIO17                  0x11000000U
#define GPIO_17_PA_17                   0x11000000U
#define GPIO_17_SPI1_SOUT               0x11010000U
#define GPIO_17_SPI1_SIN                0x11020000U
#define GPIO_17_OUTPUTXBAR8             0x11040000U
#define GPIO_17_SCI1_TX                 0x11050000U

#define GPIO_18_GPIO18                  0x12000000U
#define GPIO_18_PA_18                   0x12000000U
#define GPIO_18_SPI1_CLK                0x12010000U
#define GPIO_18_SCI4_TX                 0x12020000U
#define GPIO_18_XCLKOUT                 0x12030000U
#define GPIO_18_SYNCOUT                 0x12050000U

#define GPIO_19_GPIO19                  0x13000000U
#define GPIO_19_PA_19                   0x13000000U
#define GPIO_19_XCLKIN                  0x13010000U
#define GPIO_19_SPI1_CS0                0x13020000U
#define GPIO_19_SCI4_RX                 0x13030000U

#define GPIO_20_GPIO20                  0x14000000U
#define GPIO_20_PA_20                   0x14000000U
#define GPIO_20_EQEP1A                  0x14010000U
#define GPIO_20_OUTPUTXBAR1             0x14040000U

#define GPIO_21_GPIO21                  0x15000000U
#define GPIO_21_PA_21                   0x15000000U
#define GPIO_21_EQEP1B                  0x15010000U
#define GPIO_21_COMP1OUT2               0x15020000U
#define GPIO_21_OUTPUTXBAR2             0x15040000U

#define GPIO_22_GPIO22                  0x16000000U
#define GPIO_22_PA_22                   0x16000000U
#define GPIO_22_EQEP1S                  0x16010000U
#define GPIO_22_SCI5_TX                 0x16030000U
#define GPIO_22_SPI1_CS1                0x16050000U

#define GPIO_23_GPIO23                  0x17000000U
#define GPIO_23_PA_23                   0x17000000U
#define GPIO_23_EQEP1I                  0x17010000U
#define GPIO_23_SCI5_RX                 0x17030000U
#define GPIO_23_SPI1_CS2                0x17050000U

#define GPIO_24_GPIO24                  0x18000000U
#define GPIO_24_PA_24                   0x18000000U
#define GPIO_24_SPI2_SOUT               0X18020000U
#define GPIO_24_SPI2_SIN                0X18030000U
#define GPIO_24_EWM_IN                  0x18050000U

#define GPIO_25_GPIO25                  0x19000000U
#define GPIO_25_PA_25                   0x19000000U
#define GPIO_25_SPI2_SIN                0X19020000U
#define GPIO_25_SPI2_SOUT               0X19030000U
#define GPIO_25_SCI1_CTS                0X19040000U
#define GPIO_25_SCI4_CTS                0X19050000U

#define GPIO_26_GPIO26                  0x1A000000U
#define GPIO_26_PA_26                   0x1A000000U
#define GPIO_26_SPI2_CLK                0X1A030000U
#define GPIO_26_SCI1_RTS                0X1A040000U
#define GPIO_26_SCI4_RTS                0X1A050000U

#define GPIO_27_GPIO27                  0x1B000000U
#define GPIO_27_PA_27                   0x1B000000U
#define GPIO_27_SPI2_CS0                0x1B030000U
#define GPIO_27_I2C1_DAT                0x1B040000U

#define GPIO_28_GPIO28                  0x1C000000U
#define GPIO_28_PA_28                   0x1C000000U
#define GPIO_28_SCI6_RX                 0x1C010000U
#define GPIO_28_I2C2_DAT                0x1C020000U
#define GPIO_28_OUTPUTXBAR3             0x1C040000U

#define GPIO_29_GPIO29                  0x1D000000U
#define GPIO_29_PA_29                   0x1D000000U
#define GPIO_29_SCI6_TX                 0x1D010000U
#define GPIO_29_I2C2_CLK                0x1D020000U
#define GPIO_29_OUTPUTXBAR4             0x1D040000U
#define GPIO_29_SPI4_SIN                0x1D050000U

#define GPIO_30_GPIO30                  0x1E000000U
#define GPIO_30_PA_30                   0x1E000000U
#define GPIO_30_MCAN1_RX                 0x1E010000U
#define GPIO_30_SD2_C4                  0x1E030000U
#define GPIO_30_SPI4_SOUT               0x1E050000U

#define GPIO_31_GPIO31                  0x1F000000U
#define GPIO_31_PA_31                   0x1F000000U
#define GPIO_31_MCAN1_TX0                 0x1F010000U
#define GPIO_31_SD2_D4                  0x1F030000U
#define GPIO_31_SPI4_CLK                0x1F050000U

#define GPIO_32_GPIO32                  0x20000000U
#define GPIO_32_PB_0                    0x20000000U
#define GPIO_32_I2C1_DAT                0x20010000U
#define GPIO_32_ADCSOCAO                0x20030000U
#define GPIO_32_OUTPUTXBAR5             0x20040000U
#define GPIO_32_SPI4_CS                 0x20050000U

#define GPIO_33_GPIO33                  0x21000000U
#define GPIO_33_PB_1                    0x21000000U
#define GPIO_33_I2C1_CLK                0x21010000U
#define GPIO_33_SYNCOUT                 0x21020000U
#define GPIO_33_ADCSOCBO                0x21030000U
#define GPIO_33_OUTPUTXBAR6             0x21040000U
#define GPIO_33_SCI2_CTS                0x21050000U

#define GPIO_34_GPIO34                  0x22000000U
#define GPIO_34_PB_2                    0x22000000U
#define GPIO_34_OUTPUTXBAR7             0x22040000U
#define GPIO_34_SCI2_RTS                0x22050000U

#define GPIO_35_TDI                     0x23000000U
#define GPIO_35_GPIO35                  0x23010000U
#define GPIO_35_PB_3                    0x23010000U
#define GPIO_35_SPI3_SOUT               0x23020000U
#define GPIO_35_SPI3_SIN                0x23030000U
#define GPIO_35_OUTPUTXBAR3             0x23040000U

#define GPIO_36_TMS                     0x24000000U
#define GPIO_36_GPIO36                  0x24010000U
#define GPIO_36_PB_4                    0x24010000U
#define GPIO_36_SPI1_CS3                0x24050000U

#define GPIO_37_TDO                     0x25000000U
#define GPIO_37_GPIO37                  0x25010000U
#define GPIO_37_PB_5                    0x25010000U
#define GPIO_37_SPI3_SIN                0x25020000U
#define GPIO_37_SPI3_SOUT               0x25030000U
#define GPIO_37_OUTPUTXBAR4             0x25040000U
#define GPIO_37_SYNCOUT                 0x25050000U

#define GPIO_38_TCK                     0x26000000U
#define GPIO_38_GPIO38                  0x26010000U
#define GPIO_38_PB_6                    0x26010000U
#define GPIO_38_OUTPUTXBAR8             0x26040000U

#define GPIO_39_GPIO39                  0x27000000U
#define GPIO_39_PB_7                    0x27000000U
#define GPIO_39_SPI3_CS0                0x27020000U
#define GPIO_39_SD2_C2                  0x27030000U
#define GPIO_39_I2C1_CLK                0x27040000U
#define GPIO_39_EWM_OUT_b               0x27050000U

#define GPIO_40_GPIO40                  0x28000000U
#define GPIO_40_PB_8                    0x28000000U
#define GPIO_40_EPWM7_A                 0x28010000U
#define GPIO_40_SD2_D2                  0x28030000U
#define GPIO_40_EQEP2S                  0x28040000U
#define GPIO_40_SPI1_SIN                0x28050000U

#define GPIO_41_GPIO41                  0x29000000U
#define GPIO_41_PB_9                    0x29000000U
#define GPIO_41_EPWM7_B                 0x29010000U
#define GPIO_41_SD2_C3                  0x29030000U
#define GPIO_41_EQEP2I                  0x29040000U
#define GPIO_41_SPI1_SOUT               0x29050000U

#define GPIO_42_GPIO42                  0x2A000000U
#define GPIO_42_PB_10                   0x2A000000U
#define GPIO_42_COMP1OUT1               0x2A010000U
#define GPIO_42_MCAN2_TX0                 0x2A020000U
#define GPIO_42_SD2_D3                  0x2A030000U
#define GPIO_42_OUTPUTXBAR1             0x2A040000U
#define GPIO_42_SPI1_CLK                0x2A050000U

#define GPIO_43_GPIO43                  0x2B000000U
#define GPIO_43_PB_11                   0x2B000000U
#define GPIO_43_MCAN2_RX                 0x2B020000U
#define GPIO_43_OUTPUTXBAR2             0x2B040000U
#define GPIO_43_SPI1_CS0                0x2B050000U

#define GPIO_44_GPIO44                  0x2C000000U
#define GPIO_44_PB_12                   0x2C000000U
#define GPIO_44_SPI3_CLK                0x2C020000U
#define GPIO_44_EQEP2B                  0x2C040000U
#define GPIO_44_SCI3_RTS                0x2C050000U

#define GPIO_45_GPIO45                  0x2D000000U
#define GPIO_45_PB_13                   0x2D000000U
#define GPIO_45_TRST                    0x2D010000U
#define GPIO_45_EQEP2A                  0x2D040000U
#define GPIO_45_SCI3_CTS                0x2D050000U



#define GPIO_46_GPIO46                  0x2E000000U
#define GPIO_46_PB_14                   0x2E000000U
#define GPIO_46_SD1_D1                  0x2E010000U
#define GPIO_46_ADCINA6                 0x2E020000U
#define GPIO_46_ADCINA14                0x2E030000U


#define GPIO_47_GPIO47                  0x2F000000U
#define GPIO_47_PB_15                   0x2F000000U
#define GPIO_47_SD1_C1                  0x2F010000U
#define GPIO_47_ADCINA5                 0x2F020000U
#define GPIO_47_ADCINA13                0x2F030000U

#define GPIO_48_GPIO48                  0x30000000U
#define GPIO_48_PB_16                   0x30000000U
#define GPIO_48_ADCINA4                 0x30200000U
#define GPIO_48_ADCINC12                0x30300000U
#define GPIO_48_COMP2A                  0x30400000U


#define GPIO_49_GPIO49                  0x31000000U
#define GPIO_49_PB_17                   0x31000000U
#define GPIO_49_SD1_D2                  0x31010000U
#define GPIO_49_ADCINA3                 0x31020000U
#define GPIO_49_ADCINA11                0x31030000U

#define GPIO_50_GPIO50                  0x32000000U
#define GPIO_50_PB_18                   0x32000000U
#define GPIO_50_ADCINA2                 0x32020000U
#define GPIO_50_ADCINC10                0x32030000U
#define GPIO_50_COMP1A                  0x32040000U

#define GPIO_51_GPIO51                  0x33000000U
#define GPIO_51_PB_19                   0x33000000U
#define GPIO_51_SD1_C2                  0x33010000U
#define GPIO_51_ADCINA1                 0x33020000U
#define GPIO_51_ADCINC9                 0x33030000U

#define GPIO_52_GPIO52                  0x34000000U
#define GPIO_52_PB_20                   0x34000000U
#define GPIO_52_SD1_D3                  0x34010000U
#define GPIO_52_ADCINA0                 0x34020000U
#define GPIO_52_ADCINA8                 0x34030000U

#define GPIO_53_GPIO53                  0x35000000U
#define GPIO_53_PB_21                   0x35000000U
#define GPIO_53_SD1_C3                  0x35010000U
#define GPIO_53_ADCINB6                 0x35020000U
#define GPIO_53_ADCINC6                 0x35030000U


#define GPIO_54_GPIO54                  0x36000000U
#define GPIO_54_PB_22                   0x36000000U
#define GPIO_54_SD1_D4                  0x36010000U
#define GPIO_54_ADCINB5                 0x36020000U
#define GPIO_54_ADCINC5                 0x36030000U


#define GPIO_55_GPIO55                  0x37000000U
#define GPIO_55_PB_23                   0x37000000U
#define GPIO_55_ADCINB4                 0x37020000U
#define GPIO_55_ADCINC4                 0x37030000U
#define GPIO_55_COMP2B                  0x37040000U


#define GPIO_56_GPIO56                  0x38000000U
#define GPIO_56_PB_24                   0x38000000U
#define GPIO_56_SD1_C4                  0x38010000U
#define GPIO_56_ADCINB3                 0x38020000U
#define GPIO_56_ADCINC3                 0x38030000U


#define GPIO_57_GPIO57                  0x39000000U
#define GPIO_57_PB_25                   0x39000000U
#define GPIO_57_ADCINB2                 0x39020000U
#define GPIO_57_ADCINC2                 0x39030000U
#define GPIO_57_COMP1B                  0x39040000U


#define GPIO_58_GPIO58                  0x3A000000U
#define GPIO_58_PB_26                   0x3A000000U
#define GPIO_58_SD2_C1                  0x3A010000U
#define GPIO_58_ADCINB1                 0x3A020000U
#define GPIO_58_ADCINC1                 0x3A030000U


#define GPIO_59_GPIO59                  0x3B000000U
#define GPIO_59_PB_27                   0x3B000000U
#define GPIO_59_SD2_D1                  0x3B010000U
#define GPIO_59_ADCINB0                 0x3B020000U
#define GPIO_59_ADCINC0                 0x3B030000U


#define GPIO_60_GPIO60                  0x3C000000U
#define GPIO_60_PB_28                   0x3C000000U

#endif // PIN_MAP_H
