/************************************************************************************//**
* \file         stackOverflowHook.h
* \brief        Header file for the function to be called if stack overflow occurs.
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
#ifndef STACKOVERFLOWHOOK_H
#define STACKOVERFLOWHOOK_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */
#include "task.h"									  /* For the xTaskHandle		   */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void vApplicationStackOverflowHook( xTaskHandle xTask, signed char *pcTaskName );

#endif
/************************************ end of stackOverflowHook.h ***********************************/