/************************************************************************************//**
* \file         app.h
* \brief        Application header file.
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
#ifndef APP_H
#define APP_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void AppInit(void);
void AppCtrlTaskSetPeriod(uint32_t period);
void AppCtrlTaskSetStackSize(uint16_t stackSize);
void AppCtrlTask(void *pvParameters);


#endif /* APP_H */
/********************************* end of app.h ****************************************/


