/************************************************************************************//**
* \file         Source\ARMCM3_STM32\flash.c
* \brief        Bootloader flash driver source file.
* \ingroup      Target_ARMCM3_STM32
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*   Copyright (c) 2011  by Feaser    http://www.feaser.com    All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of OpenBLT. OpenBLT is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option) any later
* version.
*
* OpenBLT is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with OpenBLT.
* If not, see <http://www.gnu.org/licenses/>.
*
* A special exception to the GPL is included to allow you to distribute a combined work 
* that includes OpenBLT without being obliged to provide the source code for any 
* proprietary components. The exception text is included at the bottom of the license
* file <license.html>.
* 
* \endinternal
****************************************************************************************/
#ifndef FLASH_H
#define FLASH_H

/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     FlashInit(void);
blt_bool FlashWrite(blt_addr addr, blt_int32u len, blt_int8u *data);
blt_bool FlashErase(blt_addr addr, blt_int32u len);
blt_bool FlashWriteChecksum(void);
blt_bool FlashVerifyChecksum(void);
blt_bool FlashDone(void);
blt_addr FlashGetUserProgBaseAddress(void);


#endif /* FLASH_H */
/*********************************** end of flash.h ************************************/
