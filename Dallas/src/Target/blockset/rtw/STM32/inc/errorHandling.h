/************************************************************************************//**
* \file         errorHandling.h
* \brief        Error handling header file.
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
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
#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H


/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
uint8_t*  getErrorListAddress(void);
void      bufferSync(uint8_t action);
uint8_t   releaseBuffer(void);

#endif /* ERRORHANDLING_H */
/*********************************** end of errorHandling.h ****************************/

