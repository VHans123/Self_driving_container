/************************************************************************************//**
* \file         Demo\ARMCM4_STM32_Olimex_STM32P405_GCC\Boot\main.c
* \brief        Bootloader application source file.
* \ingroup      Boot_ARMCM4_STM32_Olimex_STM32P405_GCC
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*   Copyright (c) 2013  by Feaser    http://www.feaser.com    All rights reserved
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

/****************************************************************************************
* Include files
****************************************************************************************/
#include "boot.h"                                /* bootloader generic header          */
#include "stm32f4xx.h"                           /* STM32 registers                    */
#include "stm32f4xx_conf.h"                      /* STM32 peripheral drivers           */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
static void Init(void);


/************************************************************************************//**
** \brief     This is the entry point for the bootloader application and is called 
**            by the reset interrupt vector after the C-startup routines executed.
** \return    none.
**
****************************************************************************************/
void main(void)
{
  /* initialize the microcontroller */
  Init();
  /* initialize the bootloader */
  BootInit();
  
  /* start the infinite program loop */
  while (1)
  {
    /* run the bootloader task */
    BootTask();
  }
} /*** end of main ***/


/************************************************************************************//**
** \brief     Initializes the microcontroller. 
** \return    none.
**
****************************************************************************************/
static void Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* initialize the system and its clocks */
  SystemInit();
  
  /* initialize the button as a digital input. is used to override the starting of
   * the user program.
   */
  /* enable the GPIO Clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  /* configure the GPIO pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
#if (BOOT_COM_CAN_ENABLE > 0)
  /* enable clocks for CAN2 transmitter and receiver pins */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  /* select alternate function for the CAN2 pins */
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_CAN1);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_CAN1); 
  /* configure CAN2 RX and TX pins */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  /* enable CAN1 clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
#endif  
  /* enable the GPIO_LED Clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  /* configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  /* turn LED on to indicate that the bootloader is running */
  GPIO_ResetBits(GPIOC, GPIO_Pin_12);
} /*** end of Init ***/


/*********************************** end of main.c *************************************/
