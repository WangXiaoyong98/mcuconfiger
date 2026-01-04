/*
  ******************************************************************************
  * @file           :  flash.c
  * @brief          :  SP28038 Flash Initialization & Support Functions.
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
// $
//###########################################################################
//
// Included Files
//
#include "sp28038_device.h"      // sp28038 Headerfile Include File
#include "sp28038_examples.h"    // sp28038 Examples Include File

#include "flash.h"

int Flash_EraseSector (unsigned long addr) {
	FlashRegs.ADDR = addr;
	if(addr < 0xa000000)
        FlashRegs.CMD.all = FLASH_MAIN_KEY + FLASH_SECTOR_ERASE;   
	else if(addr >= 0xc000000)
		FlashRegs.CMD.all = FLASH_DATA_KEY + FLASH_SECTOR_ERASE + FLASH_NVR_FLAG;
	else
		FlashRegs.CMD.all = FLASH_BOOT_KEY + FLASH_SECTOR_ERASE + FLASH_NVR_FLAG;
	while(FlashRegs.STAT.all == 0x1)
	{
	}
    return (0);
}

int Flash_EraseChip (unsigned long addr) {
	FlashRegs.ADDR = addr;
	if(addr < 0xa000000)
        FlashRegs.CMD.all = FLASH_MAIN_KEY + FLASH_CHIP_ERASE;   
	else if(addr >= 0xc000000)
		FlashRegs.CMD.all = FLASH_DATA_KEY + FLASH_CHIP_ERASE + FLASH_NVR_FLAG;
	else
		FlashRegs.CMD.all = FLASH_BOOT_KEY + FLASH_CHIP_ERASE + FLASH_NVR_FLAG;
	while(FlashRegs.STAT.all == 0x1)
	{
	}
    return (0);
}

int Flash_ProgramPage (unsigned long addr, unsigned long sz, unsigned char *buf) {
    int i,j = 0;
    unsigned int temp[4] = {0xffffffff};
    unsigned char *pt;
    
    if(addr % 16)
        return 1;
    
    FlashRegs.CCTL.all = 3;
    while ((j < sz) && ((sz-j)>=16)) {
		try_again:
		FlashRegs.ADDR = addr;
		FlashRegs.DATA_LM = *buf+(*(buf+1)<<8)+(*(buf+2)<<16)+(*(buf+3)<<24);
		buf += 4;
		FlashRegs.DATA_ML = *buf+(*(buf+1)<<8)+(*(buf+2)<<16)+(*(buf+3)<<24);
		buf += 4;
		FlashRegs.DATA_MU = *buf+(*(buf+1)<<8)+(*(buf+2)<<16)+(*(buf+3)<<24);
		buf += 4;
		FlashRegs.DATA_UM = *buf+(*(buf+1)<<8)+(*(buf+2)<<16)+(*(buf+3)<<24);
		buf += 4;

		if(addr < 0xa000000)
            FlashRegs.CMD.all = FLASH_MAIN_KEY + FLASH_NORMAL_PROGRAM; 
	    else if(addr >= 0xc000000)
		    FlashRegs.CMD.all = FLASH_DATA_KEY + FLASH_NORMAL_PROGRAM + FLASH_NVR_FLAG;
	    else
            FlashRegs.CMD.all = FLASH_BOOT_KEY + FLASH_NORMAL_PROGRAM + FLASH_NVR_FLAG;

		while(FlashRegs.STAT.all == 0x1)
        {
        }

		j += 16;
		addr += 16;
    }
	if(sz-j)
	{
		pt = (unsigned char *)temp;
		for(i=0; i<sz-j; i++)
		{
			*pt++ = *buf++;
		}
    try_again2:
		FlashRegs.ADDR = addr;
		FlashRegs.DATA_LM = temp[0];
		FlashRegs.DATA_ML = temp[1];
		FlashRegs.DATA_MU = temp[2];
		FlashRegs.DATA_UM = temp[3];

		if(addr < 0xa000000)
            FlashRegs.CMD.all = FLASH_MAIN_KEY + FLASH_NORMAL_PROGRAM;
        else if(addr >= 0xc000000)
            FlashRegs.CMD.all = FLASH_DATA_KEY + FLASH_NORMAL_PROGRAM + FLASH_NVR_FLAG;
        else
            FlashRegs.CMD.all = FLASH_BOOT_KEY + FLASH_NORMAL_PROGRAM + FLASH_NVR_FLAG;

		while(FlashRegs.STAT.all == 0x1)
	    {
	    }
	}
	FlashRegs.CCTL.all = 0;
	FlashRegs.DATA_LM = 0x08000200;          //dummy read to flush something into flash cache
    return (0);                                  // Finished without Errors
}


uint16_t Flash_Verify(uint16_t *StartAddr, uint16_t *BufAddr, uint32_t Length, FLASH_ST *FVerifyStat)
{
    uint32_t i;
    for( i = 0; i < Length; i += 4)
    {
        if(*(StartAddr+i) != *(BufAddr+i))
        {
            FVerifyStat->ActualData = *(StartAddr+i);
            FVerifyStat->ExpectedData = *(BufAddr+i);
            FVerifyStat->FirstFailAddr = (uint32_t)(StartAddr+i);
            return STATUS_FAIL_VERIFY;
        }
    }   
    return STATUS_SUCCESS;
}