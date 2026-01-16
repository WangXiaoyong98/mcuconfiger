//###########################################################################
//
// FILE:    sp28038_flash.h
//
// TITLE:   Definitions for the FLASH registers.
//
//###########################################################################
// $Copyright:
// $
//###########################################################################

#ifndef SP28038_FLASH_H
#define SP28038_FLASH_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// FLASH Individual Register Bit Definitions:

struct CMD_BITS {             // bits description
    uint32_t CMD:4;                   // 3:0 Flash Command
    uint32_t rsvd1:3;                 // 6:4 Reserved
    uint32_t AREASEL:1;               // 7 Area Select
    uint32_t rsvd2:8;                 // 15:8 Reserved
    uint32_t KEYWORD:16;              // 31:16 Flash Operation Key Word
};

union CMD_REG {
    uint32_t  all;
    struct  CMD_BITS  bit;
};

struct PROTECT_BITS {             // bits description
    uint32_t PROCODE:16;              // 15:0 Protect Code
    uint32_t rsvd1:16;                // 31:16 Reserved
};

union PROTECT_REG {
    uint32_t  all;
    struct  PROTECT_BITS  bit;
};

struct STAT_BITS {             // bits description
    uint32_t STATUS:1;               // 0 Status bit
    uint32_t rsvd1:31;               // 31:1 Reserved
};

union STAT_REG {
    uint32_t  all;
    struct  STAT_BITS  bit;
};

struct CCTL_BITS {             // bits description
    uint32_t ICACHE_DISABLE:1;       // 0 Instruction CACHE Disable
    uint32_t CCACHE_DISABLE:1;        // 1 Code CACHE Disable
    uint32_t rsvd1:31;              // 31:1 Reserved
};

union CCTL_REG {
    uint32_t  all;
    struct  CCTL_BITS  bit;
};

struct FLASH_REGS {
    uint32_t                         RESERVED;
    union           CMD_REG          CMD;
    uint32_t                         ADDR;
    uint32_t                         DATA_UM;
    uint32_t                         DATA_MU;
    uint32_t                         DATA_ML;
    uint32_t                         DATA_LM;
    uint32_t                         RDCYCLE;
    uint32_t                         PROTECT;
    union           STAT_REG         STAT;
    union           CCTL_REG         CCTL;

};

//---------------------------------------------------------------------------
// FLASH External References & Function Declarations:
//
extern volatile struct FLASH_REGS FlashRegs;

#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
