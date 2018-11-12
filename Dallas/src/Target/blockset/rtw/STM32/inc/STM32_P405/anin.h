/************************************************************************************//**
* \file         anin.h
* \brief        Analog inputs driver header file.
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
#ifndef ANIN_H
#define ANIN_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */
#include "model.h"									  /* Variables changes by Simulink */
#include "stm32f4xx.h"                                /* STM32 registers               */
#include "stm32f4xx_conf.h"                           /* STM32 peripheral drivers      */
#include "SYS_config.h"								  /* For defines from Simulink	   */

/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* analog input port identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define ANIN_PORTA_PIN1     (0)                /* PA1 (ADC123_IN1)                     */
#define ANIN_PORTB_PIN0     (1)                /* PB0 (ADC12_IN8)                      */
#define ANIN_PORTB_PIN1     (2)                /* PB1 (ADC12_IN9)                      */
#define ANIN_PORTC_PIN0     (3)                /* PC0 (ADC123_IN10)                    */
#define ANIN_PORTC_PIN1     (4)                /* PC1 (ADC123_IN11)                    */
#define ANIN_PORTC_PIN2     (5)                /* PC2 (ADC123_IN12)                    */
#define ANIN_PORTC_PIN3     (6)                /* PC3 (ADC123_IN13)                    */
#define ANIN_PORTC_PIN4     (7)                /* PC4 (ADC12_IN14)                     */
#define ANIN_PORTC_PIN5     (8)                /* PC5 (ADC12_IN15)                     */

/** \brief Total number of analog input channels */
#define ANIN_MAX_CHANNELS         (10)

/** \brief Invalid index value for array aninChannelCfgInfo */
#define ANIN_INVALID_CHANNEL_IDX  (ANIN_MAX_CHANNELS)

/** \brief Total number of samples in the median filter */
#define FILTERSIZE 16

/** \brief Number of samples for averaging in the filter */
#define LOWPASSFILTERSIZE 8

/** \brief Constant for deviding the final result */
#define LOWPASSFILTERSHIFT 3 /* divide by 8 */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Structure type with pin mapping information. */
typedef struct
{
  uint32_t peripheral;
  GPIO_TypeDef* port;
  uint16_t pin;
  uint8_t adcChannel;
} tAninPinMapping;

/** \brief Structure type to keep track of a channel configuration. */
typedef struct
{
  uint8_t pinIdx;
  uint8_t configuredFlg;
  uint8_t filterFlg;
} tAninChannelCfgInfo;

/** \brief Struct that holds all information for filtering the analog inputs
 */
typedef struct
{
  uint8_t pinId;
  uint32_t Samples[FILTERSIZE];
  uint32_t FilterResult;
  uint32_t SampleAgeIndex;	
}AninFilterStruct;

/****************************************************************************************
* Global data declarations
****************************************************************************************/
/** \brief Variable that holds the numder of analog channels with filtering */
extern uint8_t nrFilteredADCchannels;

/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     AninConfigure(uint8_t id, uint8_t filtered);
uint16_t AninGet(uint8_t id, uint8_t filtered);
void ADCconversionTaskSetPeriod(uint32_t period);
void ADCconversionTask(void *pvParameters);
void ADCconversionTaskFunction(void);


#endif /* ANIN_H */
/********************************* end of anin.h ***************************************/


