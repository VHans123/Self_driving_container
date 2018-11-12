/************************************************************************************//**
* \file         digout.h
* \brief        Digital outputs driver header file.
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
#define DIGOUT_PORTA_PIN1    (0)                       /* PA1                          */
#define DIGOUT_PORTA_PIN8    (1)                       /* PA8                          */
#define DIGOUT_PORTB_PIN0    (2)                       /* PB0                          */
#define DIGOUT_PORTB_PIN1    (3)                       /* PB1                          */
#define DIGOUT_PORTB_PIN2    (4)                       /* PB2                          */
#define DIGOUT_PORTB_PIN5    (5)                       /* PB5                          */
#define DIGOUT_PORTB_PIN8    (6)                       /* PB8                          */
#define DIGOUT_PORTB_PIN9    (7)                       /* PB9                          */
#define DIGOUT_PORTB_PIN10   (8)                       /* PB10                         */
#define DIGOUT_PORTB_PIN11   (9)                       /* PB11                         */
#define DIGOUT_PORTB_PIN12   (10)                      /* PB12                         */
#define DIGOUT_PORTB_PIN13   (11)                      /* PB13                         */
#define DIGOUT_PORTB_PIN14   (12)                      /* PB14                         */
#define DIGOUT_PORTB_PIN15   (13)                      /* PB15                         */
#define DIGOUT_PORTC_PIN0    (14)                      /* PC0                          */
#define DIGOUT_PORTC_PIN1    (15)                      /* PC1                          */
#define DIGOUT_PORTC_PIN2    (16)                      /* PC2                          */
#define DIGOUT_PORTC_PIN3    (17)                      /* PC3                          */
#define DIGOUT_PORTC_PIN4    (18)                      /* PC4                          */
#define DIGOUT_PORTC_PIN5    (19)                      /* PC5                          */
#define DIGOUT_PORTC_PIN6    (20)                      /* PC6                          */
#define DIGOUT_PORTC_PIN7    (21)                      /* PC7                          */
#define DIGOUT_PORTC_PIN8    (22)                      /* PC8                          */
#define DIGOUT_PORTC_PIN9    (23)                      /* PC9                          */
#define DIGOUT_PORTC_PIN10   (24)                      /* PC10                         */
#define DIGOUT_PORTC_PIN11   (25)                      /* PC11                         */
#define DIGOUT_PORTC_PIN12   (26)                      /* PC12/LED                     */
#define DIGOUT_PORTC_PIN13   (27)                      /* PC13                         */
#define DIGOUT_PORTD_PIN2    (28)                      /* PD2                          */


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


