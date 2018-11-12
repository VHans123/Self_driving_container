/************************************************************************************//**
* \file         mac.h
* \brief        Measurement and calibration header file.
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*  Copyright (c) 2013  by Feaser           http://www.feaser.com    All rights reserved
*  Copyright (c) 2013  by HAN Automotive   http://www.han.nl        All rights reserved
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
#ifndef MAC_H
#define MAC_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void    MacCanInit(uint8_t channel, uint32_t croID, uint32_t dtoID);
void    MacUsbComInit(void);
void    MacInit(void);
uint8_t MacGetXcpMaxCTO(void);
uint8_t MacGetXcpMaxDTO(void);


#endif /* MAC_H */
/********************************* end of mac.h ****************************************/


