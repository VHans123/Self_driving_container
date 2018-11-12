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
#define TIMEIN_TIM1_PIN_PE9    (0)              /* Connector PE-12 (Ch. 1)             */
#define TIMEIN_TIM1_PIN_PE11   (1)              /* Connector PE-14 (Ch. 2)             */
#define TIMEIN_TIM1_PIN_PE13   (2)              /* Connector PE-16 (Ch. 3)             */
#define TIMEIN_TIM1_PIN_PE14   (3)              /* Connector PE-17 (Ch. 4)             */
#define TIMEIN_TIM2_PIN_PA5    (4)              /* Connector 4-D13 (Ch. 1)             */
#define TIMEIN_TIM3_PIN_PA6    (5)              /* Connector 4-D12 (Ch. 1)             */
#define TIMEIN_TIM3_PIN_PB5    (6)              /* Connector 4-D11 (Ch. 2)             */
#define TIMEIN_TIM4_PIN_PD12   (7)              /* Connector PD-15 (Ch. 1)             */
#define TIMEIN_TIM4_PIN_PD13   (8)              /* Connector PD-16 (Ch. 2)             */
#define TIMEIN_TIM8_PIN_PC6    (9)              /* Connector UEXT-3 (Ch. 1)            */
#define TIMEIN_TIM8_PIN_PC7    (10)             /* Connector UEXT-4 (Ch. 2)            */
#define TIMEIN_TIM9_PIN_PE5    (11)             /* Connector 3-D4  (Ch. 1)             */
#define TIMEIN_TIM9_PIN_PE6    (12)             /* Connector 3-D5  (Ch. 2)             */
#define TIMEIN_TIM10_PIN_PF6   (13)             /* Connector PF-9  (Ch. 1)             */
#define TIMEIN_TIM11_PIN_PF7   (14)             /* Connector PF-10 (Ch. 1)             */
#define TIMEIN_TIM13_PIN_PF8   (15)             /* Connector PF-11 (Ch. 1)             */
#define TIMEIN_TIM14_PIN_PF9   (16)             /* Connector PF-12 (Ch. 1)             */


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
void     Timein1UpdateTimein10Interrupt(void);
void     Timein1CaptureInterrupt(void);
void     Timein2Interrupt(void);
void     Timein3Interrupt(void);
void     Timein4Interrupt(void);
void     Timein8UpdateTimein13Interrupt(void);
void     Timein8CaptureInterrupt(void);
void     Timein9Interrupt(void);
void     Timein11Interrupt(void);
void     Timein14Interrupt(void);


#endif /* TIMEIN_H */
/********************************* end of timein.h *************************************/


