/************************************************************************************//**
* \file         eeprom_sim.h
* \brief        Simulated EEPROM driver header file.
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*  Copyright (c) 2014  by Feaser           http://www.feaser.com    All rights reserved
*  Copyright (c) 2014  by HAN Automotive   http://www.han.nl        All rights reserved
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
#ifndef EEPROM_SIM_H
#define EEPROM_SIM_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     EepromSimInit(void);
void     EepromSimSynchronize(void);
void     EepromSimBulkErase(void);
void     EepromSimErase(uint16_t address, uint16_t len);
uint8_t *EepromSimGetPtr(uint16_t address);
uint8_t  EepromSimUINT8Get(uint16_t address);
int8_t   EepromSimSINT8Get(uint16_t address);
uint16_t EepromSimUINT16Get(uint16_t address);
int16_t  EepromSimSINT16Get(uint16_t address);
uint32_t EepromSimUINT32Get(uint16_t address);
int32_t  EepromSimSINT32Get(uint16_t address);
void     EepromSimUINT8Set(uint16_t address, uint8_t value);
void     EepromSimSINT8Set(uint16_t address, int8_t value);
void     EepromSimUINT16Set(uint16_t address, uint16_t value);
void     EepromSimSINT16Set(uint16_t address, int16_t value);
void     EepromSimUINT32Set(uint16_t address, uint32_t value);
void     EepromSimSINT32Set(uint16_t address, int32_t value);


#endif /* EEPROM_SIM_H */
/********************************* end of eeprom_sim.h *********************************/


