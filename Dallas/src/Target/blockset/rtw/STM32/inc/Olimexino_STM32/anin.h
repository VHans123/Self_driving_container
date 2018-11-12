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


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* analog input port identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define ANIN_PORTC_PIN0     (0)                 /* Connector 2 - D15/A0        (ADC10) */
#define ANIN_PORTC_PIN1     (1)                 /* Connector 2 - D16/A1        (ADC11) */
#define ANIN_PORTC_PIN2     (2)                 /* Connector 2 - D17/A2        (ADC12) */
#define ANIN_PORTC_PIN3     (3)                 /* Connector 2 - D18/A3        (ADC13) */
#define ANIN_PORTC_PIN4     (4)                 /* Connector 2 - D19/A4        (ADC14) */
#define ANIN_PORTC_PIN5     (5)                 /* Connector 2 - D20/A5        (ADC15) */
#define ANIN_PORTA_PIN3     (6)                 /* Connector 3 - D0/RXD2       (ADC3)  */
#define ANIN_PORTA_PIN2     (7)                 /* Connector 3 - D1/TXD2       (ADC2)  */
#define ANIN_PORTA_PIN0     (8)                 /* Connector 3 - D2            (ADC0)  */
#define ANIN_PORTA_PIN1     (9)                 /* Connector 3 - D3/LED2       (ADC1)  */
#define ANIN_PORTA_PIN4     (10)                /* Connector 4 - D10/#SS1      (ADC4)  */
#define ANIN_PORTA_PIN7     (11)                /* Connector 4 - D11/MOSI1     (ADC7)  */
#define ANIN_PORTA_PIN6     (12)                /* Connector 4 - D12/MISO1     (ADC6)  */
#define ANIN_PORTA_PIN5     (13)                /* Connector 4 - D13/SCK1/LED1 (ADC5)  */
#define ANIN_PORTB_PIN0     (14)                /* Extension   - D27           (ADC8)  */
#define ANIN_PORTB_PIN1     (15)                /* Extension   - D28           (ADC9)  */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     AninConfigure(uint8_t id, uint8_t filtered);
uint16_t AninGet(uint8_t id, uint8_t filtered);
void     AninConvert(void);
void ADCconversionTask(void *pvParameters);
void ADCconversionTaskFunction(void);
void ADCconversionTaskSetPeriod(uint32_t period);



#endif /* ANIN_H */
/********************************* end of anin.h ***************************************/


