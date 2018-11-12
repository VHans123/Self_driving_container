/************************************************************************************//**
* \file         os.h
* \brief        Operating system header file.
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
#ifndef OS_H
#define OS_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "list.h"
#include "timers.h"


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/** \brief Configures the frequency of the timer used for run-time measurements. It is
 *         used to scale the timer used for the system tick. Note that some changes for
 *         this where made in the FreeRTOS port.
 */
#define OS_RUNTIME_COUNTER_FREQUENCY   (configTICK_RATE_HZ * 10)


/****************************************************************************************
* Function prototypes
****************************************************************************************/
int      main(void);
void     OsIrqEnter(void);
void     OsIrqExit(void);
uint32_t OsEnterCriticalSection(void);
void     OsLeaveCriticalSection(uint32_t old_cs_state);
void     OsSystemReset(void);
uint8_t  OsGetCpuLoad(void);
uint8_t  OsGetCpuLoadMax(void);
uint32_t OsGetFreeHeapSize(void);
uint32_t OsGetTaskFreeStackSize(char *name);
uint32_t OsGetSystemTime(void);
void     OsRunTimeMeasurementTickEvent(void);



#endif /* OS_H */
/********************************* end of os.h *****************************************/


