/************************************************************************************//**
* \file         timeout.h
* \brief        Timer outputs (output compare) driver header file.
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
#ifndef TIMEOUT_H
#define TIMEOUT_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* timer module identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define TIMEOUT_MODULE_TIM1   (0)                     /* Timer module 1                */
#define TIMEOUT_MODULE_TIM2   (1)                     /* Timer module 2                */
#define TIMEOUT_MODULE_TIM3   (2)                     /* Timer module 3                */
#define TIMEOUT_MODULE_TIM4   (3)                     /* Timer module 4                */
#define TIMEOUT_MODULE_TIM8   (4)                     /* Timer module 8                */
#define TIMEOUT_MODULE_TIM9   (5)                     /* Timer module 9                */
#define TIMEOUT_MODULE_TIM10  (6)                     /* Timer module 10               */
#define TIMEOUT_MODULE_TIM11  (7)                     /* Timer module 11               */
#define TIMEOUT_MODULE_TIM13  (8)                     /* Timer module 13               */
#define TIMEOUT_MODULE_TIM14  (9)                     /* Timer module 14               */

/* timer input capture pin identifiers. note that these are used as array indexers so
 * make sure the first one has value 0 and the others are increments.
 */
#define TIMEOUT_TIM1_PIN_PE9    (0)             /* Connector PE-12 (Ch. 1)             */
#define TIMEOUT_TIM1_PIN_PE11   (1)             /* Connector PE-14 (Ch. 2)             */
#define TIMEOUT_TIM1_PIN_PE13   (2)             /* Connector PE-16 (Ch. 3)             */
#define TIMEOUT_TIM1_PIN_PE14   (3)             /* Connector PE-17 (Ch. 4)             */
#define TIMEOUT_TIM2_PIN_PA5    (4)             /* Connector 4-D13 (Ch. 1)             */
#define TIMEOUT_TIM3_PIN_PA6    (5)             /* Connector 4-D12 (Ch. 1)             */
#define TIMEOUT_TIM3_PIN_PB5    (6)             /* Connector 4-D11 (Ch. 2)             */
#define TIMEOUT_TIM4_PIN_PD12   (7)             /* Connector PD-15 (Ch. 1)             */
#define TIMEOUT_TIM4_PIN_PD13   (8)             /* Connector PD-16 (Ch. 2)             */
#define TIMEOUT_TIM8_PIN_PC6    (9)             /* Connector UEXT-3 (Ch. 1)            */
#define TIMEOUT_TIM8_PIN_PC7    (10)            /* Connector UEXT-4 (Ch. 2)            */
#define TIMEOUT_TIM9_PIN_PE5    (11)            /* Connector 3-D4  (Ch. 1)             */
#define TIMEOUT_TIM9_PIN_PE6    (12)            /* Connector 3-D5  (Ch. 2)             */
#define TIMEOUT_TIM10_PIN_PF6   (13)            /* Connector PF-9  (Ch. 1)             */
#define TIMEOUT_TIM11_PIN_PF7   (14)            /* Connector PF-10 (Ch. 1)             */
#define TIMEOUT_TIM13_PIN_PF8   (15)            /* Connector PF-11 (Ch. 1)             */
#define TIMEOUT_TIM14_PIN_PF9   (16)            /* Connector PF-12 (Ch. 1)             */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Function type for the user specified free running counter overflow interrupt 
 *         handler.
 */
typedef void (* tTimeoutCallbackOverflow)(void);

/** \brief Function type for the user specified output compare event interrupt handler.*/
typedef void (* tTimeoutCallbackCompareEvent)(void);

/** \brief Configuration values for the output compare event action. */
typedef enum
{
  SETLOW  = 0,                                  /**< Set the channel pin low           */
  SETHIGH = 1,                                  /**< Set the channel pin high          */
  INVERT  = 2,                                  /**< Invert the channel pin's state    */
  NONE    = 3                                   /**< Do nothing (pure software timer   */
} tTimeoutAction;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     TimeoutInitModule(uint8_t module_id, uint32_t frequency);
void     TimeoutScheduleCompareEvent(uint8_t pin_id, uint16_t eventCounter, tTimeoutAction action);
uint16_t TimeoutGetFreeRunningCounter(uint8_t module_id);
void     TimeoutResetFreeRunningCounter(uint8_t module_id);
uint16_t TimeoutGetLastEventCounter(uint8_t pin_id);
void     TimeoutRegisterOverflowCallback(uint8_t module_id, tTimeoutCallbackOverflow callbackPtr);
void     TimeoutRegisterCompareEventCallback(uint8_t pin_id, tTimeoutCallbackCompareEvent callbackPtr);
void     Timeout1UpdateTimeout10Interrupt(void);
void     Timeout1CaptureInterrupt(void);
void     Timeout2Interrupt(void);
void     Timeout3Interrupt(void);
void     Timeout4Interrupt(void);
void     Timeout8UpdateTimeout13Interrupt(void);
void     Timeout8CaptureInterrupt(void);
void     Timeout9Interrupt(void);
void     Timeout11Interrupt(void);
void     Timeout14Interrupt(void);


#endif /* TIMEOUT_H */
/********************************* end of timeout.h ************************************/


