/************************************************************************************//**
* \file         co_node.h
* \brief        CANopen node header file.
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*  Copyright (c) 2015  by Feaser           http://www.feaser.com    All rights reserved
*  Copyright (c) 2015  by HAN Automotive   http://www.han.nl        All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of the HANcoder Target Matlab/Simulink Blockset environment. For the
* licensing terms, please contact HAN Automotive.
*
* This software has been carefully tested, but is not guaranteed for any particular
* purpose. HAN Automotive does not offer any warranties and does not guarantee the
* accuracy, adequacy, or completeness of the software and is not responsible for any
* errors or omissions or the results obtained from use of the software.
*
* \endinternal
****************************************************************************************/
#ifndef CO_NODE_H
#define CO_NODE_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */
#include "CANopen.h"                                  /* CANopen stack header          */
#include "CO_eeprom.h"                                /* CANopen EEPROM support        */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     CoNodeInit(uint8_t canChannel);
uint8_t  CoNodeGetChannel(void);
uint8_t  CoNodeODReadUINT8(uint16_t index, uint8_t subindex);
int8_t   CoNodeODReadSINT8(uint16_t index, uint8_t subindex);
uint16_t CoNodeODReadUINT16(uint16_t index, uint8_t subindex);
int16_t  CoNodeODReadSINT16(uint16_t index, uint8_t subindex);
uint32_t CoNodeODReadUINT32(uint16_t index, uint8_t subindex);
int32_t  CoNodeODReadSINT32(uint16_t index, uint8_t subindex);
void     CoNodeODWriteUINT8(uint16_t index, uint8_t subindex, uint8_t data);
void     CoNodeODWriteSINT8(uint16_t index, uint8_t subindex, int8_t data);
void     CoNodeODWriteUINT16(uint16_t index, uint8_t subindex, uint16_t data);
void     CoNodeODWriteSINT16(uint16_t index, uint8_t subindex, int16_t data);
void     CoNodeODWriteUINT32(uint16_t index, uint8_t subindex, uint32_t data);
void     CoNodeODWriteSINT32(uint16_t index, uint8_t subindex, int32_t data);



#endif /* CO_NODE_H */
/********************************* end of co_node.h ************************************/


