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
#define PWMOUT_MODULE_TIM1    (0)                     /* Timer module 1                */
#define PWMOUT_MODULE_TIM2    (1)                     /* Timer module 2                */
#define PWMOUT_MODULE_TIM3    (2)                     /* Timer module 3                */
#define PWMOUT_MODULE_TIM4    (3)                     /* Timer module 4                */


/* pwm output pin identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define PWMOUT_TIM1_PIN_PA8    (0)                    /* Connector 3 - D6 (+D32)       */
#define PWMOUT_TIM1_PIN_PA9    (1)                    /* Connector 3 - D7/TXD1 (+D33)  */
#define PWMOUT_TIM1_PIN_PA10   (2)                    /* Connector 3 - D8/RXD1 (+D34)  */
#define PWMOUT_TIM1_PIN_PA11   (3)                    /* not available on a connector  */
#define PWMOUT_TIM2_PIN_PA0    (4)                    /* Connector 3 - D2              */
#define PWMOUT_TIM2_PIN_PA1    (5)                    /* Connector 3 - D3/LED2         */
#define PWMOUT_TIM2_PIN_PA2    (6)                    /* Connector 3 - D1/TXD2         */
#define PWMOUT_TIM2_PIN_PA3    (7)                    /* Connector 3 - D0/RXD2         */
#define PWMOUT_TIM3_PIN_PC6    (8)                    /* Extension - D35               */
#define PWMOUT_TIM3_PIN_PC7    (9)                    /* Extension - D36               */
#define PWMOUT_TIM3_PIN_PC8    (10)                   /* Extension - D37               */
#define PWMOUT_TIM3_PIN_PC9    (11)                   /* not available on a connector  */
#define PWMOUT_TIM4_PIN_PB6    (12)                   /* Connector 3 - D5              */
#define PWMOUT_TIM4_PIN_PB7    (13)                   /* Connector 4 - D9              */
#define PWMOUT_TIM4_PIN_PB8    (14)                   /* Connector 4 - D14/CANRX       */
#define PWMOUT_TIM4_PIN_PB9    (15)                   /* Extension - D24/CANTX         */


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
void Pwmout1UpdateInterrupt(void);
void Pwmout2Interrupt(void);
void Pwmout3Interrupt(void);
void Pwmout4Interrupt(void);


#endif /* PWMOUT_H */
/********************************* end of pwmout.h *************************************/


