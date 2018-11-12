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


/* timer input capture pin identifiers. note that these are used as array indexers so
 * make sure the first one has value 0 and the others are increments.
 */
#define TIMEOUT_TIM1_PIN_PA8    (0)                   /* Connector 3 - D6              */
#define TIMEOUT_TIM1_PIN_PA9    (1)                   /* Connector 3 - D7/TXD1         */
#define TIMEOUT_TIM1_PIN_PA10   (2)                   /* Connector 3 - D8/RXD1         */
#define TIMEOUT_TIM2_PIN_PA0    (3)                   /* Connector 3 - D2              */
#define TIMEOUT_TIM2_PIN_PA1    (4)                   /* Connector 3 - D3/LED2         */
#define TIMEOUT_TIM2_PIN_PA2    (5)                   /* Connector 3 - D1/TXD2         */
#define TIMEOUT_TIM2_PIN_PA3    (6)                   /* Connector 3 - D0/RXD2         */
#define TIMEOUT_TIM3_PIN_PC6    (7)                   /* Extension - D35               */
#define TIMEOUT_TIM3_PIN_PC7    (8)                   /* Extension - D36               */
#define TIMEOUT_TIM3_PIN_PC8    (9)                   /* Extension - D37               */
#define TIMEOUT_TIM4_PIN_PB6    (10)                  /* Connector 3 - D5              */
#define TIMEOUT_TIM4_PIN_PB7    (11)                  /* Connector 4 - D9              */
#define TIMEOUT_TIM4_PIN_PB8    (12)                  /* Connector 4 - D14/CANRX       */
#define TIMEOUT_TIM4_PIN_PB9    (13)                  /* Extension - D24/CANTX         */



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
void     Timeout1UpdateInterrupt(void);
void     Timeout1CaptureInterrupt(void);
void     Timeout2Interrupt(void);
void     Timeout3Interrupt(void);
void     Timeout4Interrupt(void);


#endif /* TIMEOUT_H */
/********************************* end of timeout.h ************************************/


