/*
  ******************************************************************************
  * @file           : flash.h
  * @brief          : This file should be included in any project that uses any of
  *                   the SP28038 flash APIs.
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

#ifndef Flash_H
#define Flash_H


#ifdef __cplusplus
extern "C" {
#endif

//
// Device support included files
//
//#include "sp28038_project.h"

//
// Defines
//

//
// Operation passed, no errors were flagged
//
#define STATUS_SUCCESS                        0   

//
// The CSM is preventing the function from performing its operation
//
#define STATUS_FAIL_CSM_LOCKED               10

//
// Device REVID does not match that required by the API
//
#define STATUS_FAIL_REVID_INVALID            11
 
// 
// Invalid address passed to the API
//
#define STATUS_FAIL_ADDR_INVALID             12

//
// Incorrect PARTID
// For example the F2806 API was used on a F2808 device. 
//
#define STATUS_FAIL_INCORRECT_PARTID         13

//
// API/Silicon missmatch.  An old version of the API is being used on silicon
// it is not valid for. Please update to the latest API. 
//
#define STATUS_FAIL_API_SILICON_MISMATCH     14

//
// ---- Erase Specific errors ---- 
//
#define STATUS_FAIL_NO_SECTOR_SPECIFIED      20
#define STATUS_FAIL_PRECONDITION             21
#define STATUS_FAIL_ERASE                    22
#define STATUS_FAIL_COMPACT                  23
#define STATUS_FAIL_PRECOMPACT               24

//
// ---- Program Specific errors ----  
//
#define STATUS_FAIL_PROGRAM                  30
#define STATUS_FAIL_ZERO_BIT_ERROR           31

//
// ---- Verify Specific errors ----
//
#define STATUS_FAIL_VERIFY                   40

//
// Busy is set by each API function before it determines
// a pass or fail condition for that operation.  
// The calling function will will not receive this 
// status condition back from the API
//
#define STATUS_BUSY                999    

//
// Flash sector mask definitions
//
// The following macros can be used to form a mask specifying which sectors
// will be erased by the erase API function.
// 
//
#define SECTORA   (Uint16)0x0001
#define SECTORB   (Uint16)0x0002
#define SECTORC   (Uint16)0x0004
#define SECTORD   (Uint16)0x0008
#define SECTORE   (Uint16)0x0010
#define SECTORF   (Uint16)0x0020
#define SECTORG   (Uint16)0x0040
#define SECTORH   (Uint16)0x0080
#define SECTORI   (Uint16)0x0100
#define SECTORJ   (Uint16)0x0200
#define SECTORK   (Uint16)0x0400
#define SECTORL   (Uint16)0x0800
#define SECTORM   (Uint16)0x1000
#define SECTORN   (Uint16)0x2000
#define SECTORO   (Uint16)0x4000
#define SECTORP   (Uint16)0x8000

#define SECTOR_GROUP_SIZE 16384
/*The 28035/34 devices contain 64K x 16 of embedded flash memory, segregated into eight 8K x 16 sectors*/
/*The SP9038 devices contain 32K x 64 of embedded flash memory, segregated into sixteen 2K x 64 sectors*/
#define HW_SECTOR_SIZE  1024        /*Flash hardware has 1024 byte per sector*/
#define VERSIONHEX 0x100
#define VERSIONFLOAT 1.00

#define FLASH_NORMAL_PROGRAM      2
#define FLASH_REF_PROGRAM         3
#define FLASH_SECTOR_ERASE        4
#define FLASH_REF_ERASE           5
#define FLASH_CHIP_ERASE          6

#define FLASH_MAIN_KEY            0x5a5a0000
#define FLASH_BOOT_KEY            0xbd390000
#define FLASH_DATA_KEY            0xda580000

#define FLASH_NVR_FLAG            0x80

#define MAIN_FLASH_START_ADDR     0x08000000
#define MAIN_FLASH_END_ADDR       0x08040000

#define BOOT_FLASH_START_ADDR     0x0a000000
#define BOOT_FLASH_END_ADDR       0x0a002400

#define DATA_FLASH_START_ADDR     0x0c000000
#define DATA_FLASH_END_ADDR       0x0c000800

#define TRIM_FLASH_START_ADDR     0x0e000000
#define TRIM_FLASH_END_ADDR       0x0e000400

#define FLASH_INTERFACE_WIDTH     16     //byte
//
// API Status Structure
// 
// This structure is used to pass debug data back to the calling routine.
// Note that the Erase API function has 3 parts: precondition, erase and
// and compaction. Erase and compaction failures will not populate 
// the expected and actual data fields.  
//
typedef struct {
    Uint32  FirstFailAddr;
    Uint32  ExpectedData;
    Uint32  ActualData;
}FLASH_ST;

//
// Interface Function prototypes
//
extern int Flash_EraseSector (unsigned long addr);
extern int Flash_EraseChip (unsigned long addr);
extern int Flash_ProgramPage (unsigned long addr, unsigned long sz, unsigned char *buf);
Uint16 Flash_Verify(Uint16 *StartAddr, Uint16 *BufAddr, Uint32 Length, FLASH_ST *FVerifyStat);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif 

//
// End of Files
//

