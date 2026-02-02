/*
  ******************************************************************************
  * @file           : sp28038_examples.h
  * @brief          : sp28038_examples header file, contains clock global defination
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

#ifndef SP28038_EXAMPLES_H
#define SP28038_EXAMPLES_H

#ifdef __cplusplus
extern "C" {
#endif

//
// Defines
//

//
// The following are values that can be passed to the
// InitSysPll() & InitAuxPll() to select SYSPLL/AUXPLL integer multiplier
//

#define   IMULT_2         2
#define   IMULT_3         3
#define   IMULT_4         4
#define   IMULT_5         5
#define   IMULT_6         6
#define   IMULT_7         7
#define   IMULT_8         8
#define   IMULT_9         9
#define   IMULT_10        10
#define   IMULT_11        11
#define   IMULT_12        12
#define   IMULT_13        13
#define   IMULT_14        14
#define   IMULT_15        15
#define   IMULT_16        16
#define   IMULT_17        17
#define   IMULT_18        18
#define   IMULT_19        19
#define   IMULT_20        20
#define   IMULT_21        21
#define   IMULT_22        22
#define   IMULT_23        23
#define   IMULT_24        24
#define   IMULT_25        25
#define   IMULT_26        26
#define   IMULT_27        27
#define   IMULT_28        28
#define   IMULT_29        29
#define   IMULT_30        30
#define   IMULT_31        31
#define   IMULT_32        32
#define   IMULT_33        33
#define   IMULT_34        34
#define   IMULT_35        35
#define   IMULT_36        36
#define   IMULT_37        37
#define   IMULT_38        38
#define   IMULT_39        39
#define   IMULT_40        40
#define   IMULT_41        41
#define   IMULT_42        42
#define   IMULT_43        43
#define   IMULT_44        44
#define   IMULT_45        45
#define   IMULT_46        46
#define   IMULT_47        47
#define   IMULT_48        48
#define   IMULT_49        49
#define   IMULT_50        50
#define   IMULT_51        51
#define   IMULT_52        52
#define   IMULT_53        53
#define   IMULT_54        54
#define   IMULT_55        55
#define   IMULT_56        56
#define   IMULT_57        57
#define   IMULT_58        58
#define   IMULT_59        59
#define   IMULT_60        60
#define   IMULT_61        61
#define   IMULT_62        62
#define   IMULT_63        63
#define   IMULT_64        64
#define   IMULT_65        65
#define   IMULT_66        66
#define   IMULT_67        67
#define   IMULT_68        68
#define   IMULT_69        69
#define   IMULT_70        70
#define   IMULT_71        71
#define   IMULT_72        72
#define   IMULT_73        73
#define   IMULT_74        74
#define   IMULT_75        75
#define   IMULT_76        76
#define   IMULT_77        77
#define   IMULT_78        78
#define   IMULT_79        79
#define   IMULT_80        80
#define   IMULT_81        81
#define   IMULT_82        82
#define   IMULT_83        83
#define   IMULT_84        84
#define   IMULT_85        85
#define   IMULT_86        86
#define   IMULT_87        87
#define   IMULT_88        88
#define   IMULT_89        89
#define   IMULT_90        90
#define   IMULT_91        91
#define   IMULT_92        92
#define   IMULT_93        93
#define   IMULT_94        94
#define   IMULT_95        95
#define   IMULT_96        96
#define   IMULT_97        97
#define   IMULT_98        98
#define   IMULT_99        99
#define   IMULT_100       100
#define   IMULT_101       101
#define   IMULT_102       102
#define   IMULT_103       103
#define   IMULT_104       104
#define   IMULT_105       105
#define   IMULT_106       106
#define   IMULT_107       107
#define   IMULT_108       108
#define   IMULT_109       109
#define   IMULT_110       110
#define   IMULT_111       111
#define   IMULT_112       112
#define   IMULT_113       113
#define   IMULT_114       114
#define   IMULT_115       115
#define   IMULT_116       116
#define   IMULT_117       117
#define   IMULT_118       118
#define   IMULT_119       119
#define   IMULT_120       120
#define   IMULT_121       121
#define   IMULT_122       122
#define   IMULT_123       123
#define   IMULT_124       124
#define   IMULT_125       125
#define   IMULT_126       126
#define   IMULT_127       127
#define   IMULT_128       128
#define   IMULT_129       129
#define   IMULT_130       130
#define   IMULT_131       131
#define   IMULT_132       132
#define   IMULT_133       133
#define   IMULT_134       134
#define   IMULT_135       135
#define   IMULT_136       136
#define   IMULT_137       137
#define   IMULT_138       138
#define   IMULT_139       139
#define   IMULT_140       140
#define   IMULT_141       141
#define   IMULT_142       142
#define   IMULT_143       143
#define   IMULT_144       144
#define   IMULT_145       145
#define   IMULT_146       146
#define   IMULT_147       147
#define   IMULT_148       148
#define   IMULT_149       149
#define   IMULT_150       150
#define   IMULT_151       151
#define   IMULT_152       152
#define   IMULT_153       153
#define   IMULT_154       154
#define   IMULT_155       155
#define   IMULT_156       156
#define   IMULT_157       157
#define   IMULT_158       158
#define   IMULT_159       159
#define   IMULT_160       160
#define   IMULT_161       161
#define   IMULT_162       162
#define   IMULT_163       163
#define   IMULT_164       164
#define   IMULT_165       165
#define   IMULT_166       166
#define   IMULT_167       167
#define   IMULT_168       168
#define   IMULT_169       169
#define   IMULT_170       170
#define   IMULT_171       171
#define   IMULT_172       172
#define   IMULT_173       173
#define   IMULT_174       174
#define   IMULT_175       175
#define   IMULT_176       176
#define   IMULT_177       177
#define   IMULT_178       178
#define   IMULT_179       179
#define   IMULT_180       180
#define   IMULT_181       181
#define   IMULT_182       182
#define   IMULT_183       183
#define   IMULT_184       184
#define   IMULT_185       185
#define   IMULT_186       186
#define   IMULT_187       187
#define   IMULT_188       188
#define   IMULT_189       189
#define   IMULT_190       190
#define   IMULT_191       191
#define   IMULT_192       192
#define   IMULT_193       193
#define   IMULT_194       194
#define   IMULT_195       195
#define   IMULT_196       196
#define   IMULT_197       197
#define   IMULT_198       198
#define   IMULT_199       199
#define   IMULT_200       200
#define   IMULT_201       201
#define   IMULT_202       202
#define   IMULT_203       203
#define   IMULT_204       204
#define   IMULT_205       205
#define   IMULT_206       206
#define   IMULT_207       207
#define   IMULT_208       208
#define   IMULT_209       209
#define   IMULT_210       210
#define   IMULT_211       211
#define   IMULT_212       212
#define   IMULT_213       213
#define   IMULT_214       214
#define   IMULT_215       215
#define   IMULT_216       216
#define   IMULT_217       217
#define   IMULT_218       218
#define   IMULT_219       219
#define   IMULT_220       220
#define   IMULT_221       221
#define   IMULT_222       222
#define   IMULT_223       223
#define   IMULT_224       224
#define   IMULT_225       225
#define   IMULT_226       226
#define   IMULT_227       227
#define   IMULT_228       228
#define   IMULT_229       229
#define   IMULT_230       230
#define   IMULT_231       231
#define   IMULT_232       232
#define   IMULT_233       233
#define   IMULT_234       234
#define   IMULT_235       235
#define   IMULT_236       236
#define   IMULT_237       237
#define   IMULT_238       238
#define   IMULT_239       239
#define   IMULT_240       240
#define   IMULT_241       241
#define   IMULT_242       242
#define   IMULT_243       243
#define   IMULT_244       244
#define   IMULT_245       245
#define   IMULT_246       246
#define   IMULT_247       247
#define   IMULT_248       248
#define   IMULT_249       249
#define   IMULT_250       250
#define   IMULT_251       251
#define   IMULT_252       252
#define   IMULT_253       253
#define   IMULT_254       254
#define   IMULT_255       255

//
// The following are values that can be passed to the
// InitSysPll() & InitAuxPll() to select SYSPLL/AUXPLL Reference
// clock dividers
//
#define   REFDIV_1         1            //n instead
#define   REFDIV_2         2
#define   REFDIV_3         3
#define   REFDIV_4         4
#define   REFDIV_5         5
#define   REFDIV_6         6
#define   REFDIV_7         7
#define   REFDIV_8         8
#define   REFDIV_9         9
#define   REFDIV_10        10
#define   REFDIV_11        11
#define   REFDIV_12        12
#define   REFDIV_13        13
#define   REFDIV_14        14
#define   REFDIV_15        15
#define   REFDIV_16        16
#define   REFDIV_17        17
#define   REFDIV_18        18
#define   REFDIV_19        19
#define   REFDIV_20        20
#define   REFDIV_21        21
#define   REFDIV_22        22
#define   REFDIV_23        23
#define   REFDIV_24        24
#define   REFDIV_25        25
#define   REFDIV_26        26
#define   REFDIV_27        27
#define   REFDIV_28        28
#define   REFDIV_29        29
#define   REFDIV_30        30
#define   REFDIV_31        31
#define   REFDIV_32        32
#define   REFDIV_33        33
#define   REFDIV_34        34
#define   REFDIV_35        35
#define   REFDIV_36        36
#define   REFDIV_37        37
#define   REFDIV_38        38
#define   REFDIV_39        39
#define   REFDIV_40        40
#define   REFDIV_41        41
#define   REFDIV_42        42
#define   REFDIV_43        43
#define   REFDIV_44        44
#define   REFDIV_45        45
#define   REFDIV_46        46
#define   REFDIV_47        47
#define   REFDIV_48        48
#define   REFDIV_49        49
#define   REFDIV_50        50
#define   REFDIV_51        51
#define   REFDIV_52        52
#define   REFDIV_53        53
#define   REFDIV_54        54
#define   REFDIV_55        55
#define   REFDIV_56        56
#define   REFDIV_57        57
#define   REFDIV_58        58
#define   REFDIV_59        59
#define   REFDIV_60        60
#define   REFDIV_61        61
#define   REFDIV_62        62
#define   REFDIV_63        63

//
// The following are values that can be passed to the
// InitSysPll() & InitAuxPll() to select SYSPLL/AUXPLL Output
// clock dividers
//

#define   ODIV_1         0
#define   ODIV_2         1
#define   ODIV_4         2
#define   ODIV_8         3


//
// The following are values that can be passed to the
// InitSysPll() to select divsel for SYSPLL
//
#define   PLLCLK_BY_1      0
#define   PLLCLK_BY_2      1
#define   PLLCLK_BY_4      2
#define   PLLCLK_BY_6      3
#define   PLLCLK_BY_8      4
#define   PLLCLK_BY_10     5
#define   PLLCLK_BY_12     6
#define   PLLCLK_BY_14     7
#define   PLLCLK_BY_16     8
#define   PLLCLK_BY_18     9
#define   PLLCLK_BY_20     10
#define   PLLCLK_BY_22     11
#define   PLLCLK_BY_24     12
#define   PLLCLK_BY_26     13
#define   PLLCLK_BY_28     14
#define   PLLCLK_BY_30     15
#define   PLLCLK_BY_32     16
#define   PLLCLK_BY_34     17
#define   PLLCLK_BY_36     18
#define   PLLCLK_BY_38     19
#define   PLLCLK_BY_40     20
#define   PLLCLK_BY_42     21
#define   PLLCLK_BY_44     22
#define   PLLCLK_BY_46     23
#define   PLLCLK_BY_48     24
#define   PLLCLK_BY_50     25
#define   PLLCLK_BY_52     26
#define   PLLCLK_BY_54     27
#define   PLLCLK_BY_56     28
#define   PLLCLK_BY_58     29
#define   PLLCLK_BY_60     30
#define   PLLCLK_BY_62     31
#define   PLLCLK_BY_64     32
#define   PLLCLK_BY_66     33
#define   PLLCLK_BY_68     34
#define   PLLCLK_BY_70     35
#define   PLLCLK_BY_72     36
#define   PLLCLK_BY_74     37
#define   PLLCLK_BY_76     38
#define   PLLCLK_BY_78     39
#define   PLLCLK_BY_80     40
#define   PLLCLK_BY_82     41
#define   PLLCLK_BY_84     42
#define   PLLCLK_BY_86     43
#define   PLLCLK_BY_88     44
#define   PLLCLK_BY_90     45
#define   PLLCLK_BY_92     46
#define   PLLCLK_BY_94     47
#define   PLLCLK_BY_96     48
#define   PLLCLK_BY_98     49
#define   PLLCLK_BY_100    50
#define   PLLCLK_BY_102    51
#define   PLLCLK_BY_104    52
#define   PLLCLK_BY_106    53
#define   PLLCLK_BY_108    54
#define   PLLCLK_BY_110    55
#define   PLLCLK_BY_112    56
#define   PLLCLK_BY_114    57
#define   PLLCLK_BY_116    58
#define   PLLCLK_BY_118    59
#define   PLLCLK_BY_120    60
#define   PLLCLK_BY_122    61
#define   PLLCLK_BY_124    62
#define   PLLCLK_BY_126    63

//
// The following are values that can be passed to the
// InitAuxPll() to select divsel for AUXPLL
//
//#define   AUXPLLRAWCLK_BY_1    0
//#define   AUXPLLRAWCLK_BY_2    1
//#define   AUXPLLRAWCLK_BY_4    2
//#define   AUXPLLRAWCLK_BY_8    3
//#define   AUXPLLRAWCLK_BY_3    4
//#define   AUXPLLRAWCLK_BY_5    5
//#define   AUXPLLRAWCLK_BY_6    6
//#define   AUXPLLRAWCLK_BY_7    7
//
// The following are values that can be passed to the
// IntOsc2Sel() , XtalOscSel() to select system PLL (or) AUX PLL
//
#define   SYSTEM_PLL    (Uint16) 0
//#define   AUX_PLL       (Uint16) 1

//
// The following are values that can be passed to the
// InitSysPll() , InitAuxPll() & IsPLLValid() to select clock source
//
#define   INT_OSC1     0
#define   XTAL_OSC     1
//#define   XTAL_OSC_SE    5  // External oscillator, single-ended mode
#define   INT_PLL_SYSPLL    0

//
// The following are values that can be passed to the
// IsPLLValid() to select DCC for PLL validation
//
#define   SYSCTL_DCC_BASE0              0
#define   SYSCTL_DCC_BASE1              1

/*-----------------------------------------------------------------------------
    Specify the clock rate of the CPU (SYSCLKOUT) in nS.

    Take into account the input clock frequency and the PLL multiplier
    selected in step 1.

    Use one of the values provided, or define your own.
    The trailing L is required tells the compiler to treat
    the number as a 64-bit value.

    Only one statement should be uncommented.

    Example:   100 MHz devices:
             CLKIN is a 10 MHz crystal or internal 10 MHz oscillator

             In step 1 the user specified the PLL multiplier = 0x20 for a
             100 MHz CPU clock (SYSCLKOUT = 100 MHz).

             In this case, the CPU_RATE will be 10.000L
             Uncomment the line: #define CPU_RATE 10.000L

-----------------------------------------------------------------------------*/

#define CPU_RATE   20.0       //for 150MHz CPU clock and 8M IRC 
//#define CPU_RATE   25.004L    // for a 120MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   30.00L    // for a 100MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   33.338L   // for a 90MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   37.506L   // for a 80MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   50.008L   // for a 60MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   60.01L   // for a 50MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   75.012L   // for a 40MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   100.016L   // for a 30MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   125.02L   // for a 24MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   150.025L   // for a 20MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   200.033L   // for a 15MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE  300L   // for a 10MHz CPU clock speed  (SYSCLKOUT)

//
// The following pointer to a function call calibrates the ADC reference,
// DAC offset, and internal oscillators
//
//#define Device_cal ((void (*)(void))((uintptr_t)0x003fce6c))


//
// Includes
//
//#include "sp28038_globalprototypes.h"       // Prototypes for global functions
                                           // within the .c files.
//#include "sp28038_adc_defines.h"
//#include "sp28038_gpio_defines.h"           // Macros used for GPIO support code
//#include "sp28038_sysctrl_defines.h"        // Macros used for LPM support code
//#include "sp28038_dma_defines.h"        // Macros used for DMA support code
//#include "sp28038_epwm_defines.h"           // Macros used for PWM examples.
//#define CPU_FRQ_160MHZ 160000000
//#include "sp28038_defines.h"
#define EXTERNAL_CLOCK   16000000

//
// Include files not used with F/BIOS
//

//#include "sp28038_defaultisr.h"
//should use assembly code to write it again
extern void delaynus(uint32_t loops);
#define DELAY_US(A)  delaynus(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 6.0L)


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of SP28038_EXAMPLES_H definition

//
// End of file
//
