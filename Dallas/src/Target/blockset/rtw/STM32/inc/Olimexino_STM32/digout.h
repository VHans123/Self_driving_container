/************************************************************************************//**
* \file         digout.h
* \brief        Digital outputs driver header file.
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
#ifndef DIGOUT_H
#define DIGOUT_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* digital output port identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define DIGOUT_PORTC_PIN0    (0)                      /* Connector 2 - D15/A0          */
#define DIGOUT_PORTC_PIN1    (1)                      /* Connector 2 - D16/A1          */
#define DIGOUT_PORTC_PIN2    (2)                      /* Connector 2 - D17/A2          */
#define DIGOUT_PORTC_PIN3    (3)                      /* Connector 2 - D18/A3          */
#define DIGOUT_PORTC_PIN4    (4)                      /* Connector 2 - D19/A4          */
#define DIGOUT_PORTC_PIN5    (5)                      /* Connector 2 - D20/A5          */
#define DIGOUT_PORTA_PIN3    (6)                      /* Connector 3 - D0/RXD2         */
#define DIGOUT_PORTA_PIN2    (7)                      /* Connector 3 - D1/TXD2         */
#define DIGOUT_PORTA_PIN0    (8)                      /* Connector 3 - D2              */
#define DIGOUT_PORTA_PIN1    (9)                      /* Connector 3 - D3/LED2         */
#define DIGOUT_PORTB_PIN5    (10)                     /* Connector 3 - D4              */
#define DIGOUT_PORTB_PIN6    (11)                     /* Connector 3 - D5              */
#define DIGOUT_PORTA_PIN8    (12)                     /* Connector 3 - D6              */
#define DIGOUT_PORTA_PIN9    (13)                     /* Connector 3 - D7/TXD1         */
#define DIGOUT_PORTA_PIN10   (14)                     /* Connector 4 - D8/RXD1         */
#define DIGOUT_PORTB_PIN7    (15)                     /* Connector 4 - D9              */
#define DIGOUT_PORTA_PIN4    (16)                     /* Connector 4 - D10/#SS1        */
#define DIGOUT_PORTA_PIN7    (17)                     /* Connector 4 - D11/MOSI1       */
#define DIGOUT_PORTA_PIN6    (18)                     /* Connector 4 - D12/MISO1       */
#define DIGOUT_PORTA_PIN5    (19)                     /* Connector 4 - D13/SCK1/LED1   */
#define DIGOUT_PORTD_PIN2    (20)                     /* Extension - D25/MMC_CS        */
#define DIGOUT_PORTC_PIN10   (21)                     /* Extension - D26               */
#define DIGOUT_PORTB_PIN12   (22)                     /* Extension - D31/#SS2          */
#define DIGOUT_PORTB_PIN13   (23)                     /* Extension - D32/SCK2          */
#define DIGOUT_PORTC_PIN6    (24)                     /* Extension - D35               */
#define DIGOUT_PORTC_PIN7    (25)                     /* Extension - D36               */
#define DIGOUT_PORTC_PIN8    (26)                     /* Extension - D37               */


/****************************************************************************************
* Type definitions
****************************************************************************************/
typedef enum
{
  DIGOUT_LOW = 0,                               /**< logical low (GND)                 */
  DIGOUT_HIGH                                   /**< logical high (VCC)                */
} tDigoutState;


/** \brief List of digital output pin configurations. */
typedef enum
{
  DIGOUT_CFG_OPENDRAIN,                         /**< floating when logical high        */
  DIGOUT_CFG_PUSHPULL                           /**< VCC when logical high             */
} tDigoutCfg;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void DigoutConfigure(uint8_t id, tDigoutCfg config);
void DigoutSet(uint8_t id, tDigoutState state);


#endif /* DIGOUT_H */
/********************************* end of digout.h *************************************/


