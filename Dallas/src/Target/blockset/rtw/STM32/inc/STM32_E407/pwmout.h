/************************************************************************************//**
* \file         pwmout.h
* \brief        PWM outputs driver header file.
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
#ifndef PWMOUT_H
#define PWMOUT_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* pwm module identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define PWMOUT_MODULE_TIM1     (0)              /* Timer module 1                      */
#define PWMOUT_MODULE_TIM2     (1)              /* Timer module 2                      */
#define PWMOUT_MODULE_TIM3     (2)              /* Timer module 3                      */
#define PWMOUT_MODULE_TIM4     (3)              /* Timer module 4                      */
#define PWMOUT_MODULE_TIM8     (4)              /* Timer module 8                      */
#define PWMOUT_MODULE_TIM9     (5)              /* Timer module 9                      */
#define PWMOUT_MODULE_TIM10    (6)              /* Timer module 10                     */
#define PWMOUT_MODULE_TIM11    (7)              /* Timer module 11                     */
#define PWMOUT_MODULE_TIM13    (8)              /* Timer module 13                     */
#define PWMOUT_MODULE_TIM14    (9)              /* Timer module 14                     */


/* pwm output pin identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define PWMOUT_TIM1_PIN_PE9    (0)              /* Connector PE-12 (Ch. 1) - CH1N=PE8  */
#define PWMOUT_TIM1_PIN_PE11   (1)              /* Connector PE-14 (Ch. 2) - CH2N=PE10 */
#define PWMOUT_TIM1_PIN_PE13   (2)              /* Connector PE-16 (Ch. 3) - CH3N=PE12 */
#define PWMOUT_TIM1_PIN_PE14   (3)              /* Connector PE-17 (Ch. 4)             */
#define PWMOUT_TIM2_PIN_PA5    (4)              /* Connector 4-D13 (Ch. 1)             */
#define PWMOUT_TIM3_PIN_PA6    (5)              /* Connector 4-D12 (Ch. 1)             */
#define PWMOUT_TIM3_PIN_PB5    (6)              /* Connector 4-D11 (Ch. 2)             */
#define PWMOUT_TIM4_PIN_PD12   (7)              /* Connector PD-15 (Ch. 1)             */
#define PWMOUT_TIM4_PIN_PD13   (8)              /* Connector PD-16 (Ch. 2)             */
#define PWMOUT_TIM8_PIN_PC6    (9)              /* Connector UEXT-3 (Ch. 1)            */
#define PWMOUT_TIM8_PIN_PC7    (10)             /* Connector UEXT-4 (Ch. 2)            */
#define PWMOUT_TIM9_PIN_PE5    (11)             /* Connector 3-D4  (Ch. 1)             */
#define PWMOUT_TIM9_PIN_PE6    (12)             /* Connector 3-D5  (Ch. 2)             */
#define PWMOUT_TIM10_PIN_PF6   (13)             /* Connector PF-9  (Ch. 1)             */
#define PWMOUT_TIM11_PIN_PF7   (14)             /* Connector PF-10 (Ch. 1)             */
#define PWMOUT_TIM13_PIN_PF8   (15)             /* Connector PF-11 (Ch. 1)             */
#define PWMOUT_TIM14_PIN_PF9   (16)             /* Connector PF-12 (Ch. 1)             */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief List of pwm output signal alignments. */
typedef enum
{
  PWMOUT_EDGE_ALIGNMENT,                        /**< edge aligned PWM signals          */
  PWMOUT_CENTER_ALIGNMENT                       /**< center aligned PWM signals        */
} tPwmoutAlignmentCfg;

/** \brief List of pwm output polarities. */
typedef enum
{
  PWMOUT_ACTIVE_HIGH,                           /**< PWM signal active high            */
  PWMOUT_ACTIVE_LOW                             /**< PWM signal active low             */
} tPwmoutPolarityCfg;


/** \brief List of pwm output polarities. */
typedef enum
{
  PWMOUT_INVERTED_OUTPUT_OFF,                   /**< no additional inverted signal     */
  PWMOUT_INVERTED_OUTPUT_ON                     /**< additional inverted signal enabled*/
} tPwmoutInvertedOutputCfg;

/** \brief Function type for the user specified period complete interrupt handler */
typedef void (* tPwmoutCallbackPeriodComplete)(void);


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void PwmoutInit(uint8_t module_id, uint32_t frequency, tPwmoutAlignmentCfg alignment);
void PwmoutConfigure(uint8_t pin_id, tPwmoutPolarityCfg polarity, tPwmoutInvertedOutputCfg inverted_output);
void PwmoutSet(uint8_t pin_id, uint16_t duty_cycle);
void PwmoutRegisterPeriodCompleteCallback(uint8_t module_id, tPwmoutCallbackPeriodComplete callbackPtr);
void Pwmout1UpdatePwmout10Interrupt(void);
void Pwmout2Interrupt(void);
void Pwmout3Interrupt(void);
void Pwmout4Interrupt(void);
void Pwmout8UpdatePwmout13Interrupt(void);
void Pwmout9Interrupt(void);
void Pwmout11Interrupt(void);
void Pwmout14Interrupt(void);


#endif /* PWMOUT_H */
/********************************* end of pwmout.h *************************************/


