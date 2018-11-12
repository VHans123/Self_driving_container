/************************************************************************************//**
* \file         timein.h
* \brief        Timer inputs driver header file.
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
#ifndef TIMEIN_H
#define TIMEIN_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* timer input capture pin identifiers. note that these are used as array indexers so
 * make sure the first one has value 0 and the others are increments.
 */
#define TIMEIN_TIM1_PIN_PA8    (0)                    /* Connector 3 - D6              */
#define TIMEIN_TIM1_PIN_PA9    (1)                    /* Connector 3 - D7/TXD1         */
#define TIMEIN_TIM1_PIN_PA10   (2)                    /* Connector 3 - D8/RXD1         */
#define TIMEIN_TIM1_PIN_PA11   (3)                    /* not available on a connector  */
#define TIMEIN_TIM2_PIN_PA0    (4)                    /* Connector 3 - D2              */
#define TIMEIN_TIM2_PIN_PA1    (5)                    /* Connector 3 - D3/LED2         */
#define TIMEIN_TIM2_PIN_PA2    (6)                    /* Connector 3 - D1/TXD2         */
#define TIMEIN_TIM2_PIN_PA3    (7)                    /* Connector 3 - D0/RXD2         */
#define TIMEIN_TIM3_PIN_PC6    (8)                    /* Extension - D35               */
#define TIMEIN_TIM3_PIN_PC7    (9)                    /* Extension - D36               */
#define TIMEIN_TIM3_PIN_PC8    (10)                   /* Extension - D37               */
#define TIMEIN_TIM3_PIN_PC9    (11)                   /* not available on a connector  */
#define TIMEIN_TIM4_PIN_PB6    (12)                   /* Connector 3 - D5              */
#define TIMEIN_TIM4_PIN_PB7    (13)                   /* Connector 4 - D9              */
#define TIMEIN_TIM4_PIN_PB8    (14)                   /* Connector 4 - D14/CANRX       */
#define TIMEIN_TIM4_PIN_PB9    (15)                   /* Extension - D24/CANTX         */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Function type for the user specified edge detected interrupt handler */
typedef void (* tTimeinCallbackEdgeDetected)(void);


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     TimeinConfigure(uint8_t pin_id);
void     TimeinConfigureZeroHzTimeout(uint8_t pin_id, uint16_t zero_hz_timeout_ms);
void     TimeinRegisterEdgeDetectedCallback(uint8_t pin_id, tTimeinCallbackEdgeDetected callbackPtr);
uint32_t TimeinGetFrequency(uint8_t pin_id);
uint16_t TimeinGetDutyCycle(uint8_t pin_id);
uint32_t TimeinGetLastEdgeCount(uint8_t pin_id);
uint8_t  TimeinGetLastEdgeState(uint8_t pin_id);
uint32_t TimeinGetFreeRunningCounter(uint8_t pin_id);
uint32_t TimeinGetEdgeCounter(uint8_t pin_id);
uint8_t  TimeinIsZeroHzDetected(uint8_t pin_id);
void     Timein1UpdateInterrupt(void);
void     Timein1CaptureInterrupt(void);
void     Timein2Interrupt(void);
void     Timein3Interrupt(void);
void     Timein4Interrupt(void);


#endif /* TIMEIN_H */
/********************************* end of timein.h *************************************/


