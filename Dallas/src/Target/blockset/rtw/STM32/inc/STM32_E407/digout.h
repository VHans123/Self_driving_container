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
#define DIGOUT_PORTC_PIN0    (0)                       /* Connector 2 - PC0/A0          */
#define DIGOUT_PORTF_PIN6    (1)                       /* Connector 2 - PF6/A1          */
#define DIGOUT_PORTF_PIN7    (2)                       /* Connector 2 - PF7/A2          */
#define DIGOUT_PORTF_PIN8    (3)                       /* Connector 2 - PF8/A3          */
#define DIGOUT_PORTF_PIN9    (4)                       /* Connector 2 - PF9/A4          */
#define DIGOUT_PORTF_PIN10   (5)                       /* Connector 2 - PF10/A5         */
#define DIGOUT_PORTB_PIN7    (6)                       /* Connector 3 - PB7/D0          */
#define DIGOUT_PORTB_PIN6    (7)                       /* Connector 3 - PB6/D1          */
#define DIGOUT_PORTE_PIN2    (8)                       /* Connector 3 - PE2/D2          */
#define DIGOUT_PORTE_PIN4    (9)                       /* Connector 3 - PE4/D3          */
#define DIGOUT_PORTE_PIN5    (10)                      /* Connector 3 - PE5/D4          */
#define DIGOUT_PORTE_PIN6    (11)                      /* Connector 3 - PE6/D5          */
#define DIGOUT_PORTG_PIN7    (12)                      /* Connector 3 - PG7/D6          */
#define DIGOUT_PORTG_PIN8    (13)                      /* Connector 3 - PG8/D7          */
#define DIGOUT_PORTG_PIN12   (14)                      /* Connector 4 - PG12/D8         */
#define DIGOUT_PORTG_PIN15   (15)                      /* Connector 4 - PG15/D9         */
#define DIGOUT_PORTA_PIN4    (16)                      /* Connector 4 - PA4/D10         */
#define DIGOUT_PORTB_PIN5    (17)                      /* Connector 4 - PB5/D11         */
#define DIGOUT_PORTA_PIN6    (18)                      /* Connector 4 - PA6/D12         */
#define DIGOUT_PORTA_PIN5    (19)                      /* Connector 4 - PA5/D13         */
#define DIGOUT_PORTD_PIN0    (20)                      /* Connector PD - pin 3  / PD0    */
#define DIGOUT_PORTD_PIN1    (21)                      /* Connector PD - pin 4  / PD1    */
#define DIGOUT_PORTD_PIN2    (22)                      /* Connector PD - pin 5  / PD2    */
#define DIGOUT_PORTD_PIN3    (23)                      /* Connector PD - pin 6  / PD3    */
#define DIGOUT_PORTD_PIN4    (24)                      /* Connector PD - pin 7  / PD4    */
#define DIGOUT_PORTD_PIN5    (25)                      /* Connector PD - pin 8  / PD5    */
#define DIGOUT_PORTD_PIN6    (26)                      /* Connector PD - pin 9  / PD6    */
#define DIGOUT_PORTD_PIN7    (27)                      /* Connector PD - pin 10 / PD7    */
#define DIGOUT_PORTD_PIN8    (28)                      /* Connector PD - pin 11 / PD8    */
#define DIGOUT_PORTD_PIN9    (29)                      /* Connector PD - pin 12 / PD9    */
#define DIGOUT_PORTD_PIN10   (30)                      /* Connector PD - pin 13 / PD10   */
#define DIGOUT_PORTD_PIN11   (31)                      /* Connector PD - pin 14 / PD11   */
#define DIGOUT_PORTD_PIN12   (32)                      /* Connector PD - pin 15 / PD12   */
#define DIGOUT_PORTD_PIN13   (33)                      /* Connector PD - pin 16 / PD13   */
#define DIGOUT_PORTD_PIN14   (34)                      /* Connector PD - pin 17 / PD14   */
#define DIGOUT_PORTD_PIN15   (35)                      /* Connector PD - pin 18 / PD15   */
#define DIGOUT_PORTE_PIN0    (36)                      /* Connector PE - pin 3  / PE0    */
#define DIGOUT_PORTE_PIN1    (37)                      /* Connector PE - pin 4  / PE1    */
#define DIGOUT_PORTE_PIN3    (38)                      /* Connector PE - pin 6  / PE3    */
#define DIGOUT_PORTE_PIN7    (39)                      /* Connector PE - pin 10 / PE7    */
#define DIGOUT_PORTE_PIN8    (40)                      /* Connector PE - pin 11 / PE8    */
#define DIGOUT_PORTE_PIN9    (41)                      /* Connector PE - pin 12 / PE9    */
#define DIGOUT_PORTE_PIN10   (42)                      /* Connector PE - pin 13 / PE10   */
#define DIGOUT_PORTE_PIN11   (43)                      /* Connector PE - pin 14 / PE11   */
#define DIGOUT_PORTE_PIN12   (44)                      /* Connector PE - pin 15 / PE12   */
#define DIGOUT_PORTE_PIN13   (45)                      /* Connector PE - pin 16 / PE13   */
#define DIGOUT_PORTE_PIN14   (46)                      /* Connector PE - pin 17 / PE14   */
#define DIGOUT_PORTE_PIN15   (47)                      /* Connector PE - pin 18 / PE15   */
#define DIGOUT_PORTF_PIN0    (48)                      /* Connector PF - pin 3  / PF0    */
#define DIGOUT_PORTF_PIN1    (49)                      /* Connector PF - pin 4  / PF1    */
#define DIGOUT_PORTF_PIN2    (50)                      /* Connector PF - pin 5  / PF2    */
#define DIGOUT_PORTF_PIN3    (51)                      /* Connector PF - pin 6  / PF3    */
#define DIGOUT_PORTF_PIN4    (52)                      /* Connector PF - pin 7  / PF4    */
#define DIGOUT_PORTF_PIN5    (53)                      /* Connector PF - pin 8  / PF5    */
#define DIGOUT_PORTF_PIN11   (54)                      /* Connector PF - pin 14 / PF11   */
#define DIGOUT_PORTF_PIN12   (55)                      /* Connector PF - pin 15 / PF12   */
#define DIGOUT_PORTF_PIN13   (56)                      /* Connector PF - pin 16 / PF13   */
#define DIGOUT_PORTF_PIN14   (57)                      /* Connector PF - pin 17 / PF14   */
#define DIGOUT_PORTF_PIN15   (58)                      /* Connector PF - pin 18 / PF15   */
#define DIGOUT_PORTG_PIN0    (59)                      /* Connector PG - pin 3  / PG0    */
#define DIGOUT_PORTG_PIN1    (60)                      /* Connector PG - pin 4  / PG1    */
#define DIGOUT_PORTG_PIN2    (61)                      /* Connector PG - pin 5  / PG2    */
#define DIGOUT_PORTG_PIN3    (62)                      /* Connector PG - pin 6  / PG3    */
#define DIGOUT_PORTG_PIN4    (63)                      /* Connector PG - pin 7  / PG4    */
#define DIGOUT_PORTG_PIN5    (64)                      /* Connector PG - pin 8  / PG5    */
#define DIGOUT_PORTG_PIN6    (65)                      /* Connector PG - pin 9  / PG6    */
#define DIGOUT_PORTG_PIN9    (66)                      /* Connector PG - pin 12 / PG9    */
#define DIGOUT_PORTG_PIN10   (67)                      /* Connector PG - pin 13 / PG10   */
#define DIGOUT_PORTG_PIN11   (68)                      /* Connector PG - pin 14 / PG11   */
#define DIGOUT_PORTG_PIN13   (69)                      /* Connector PG - pin 16 / PG13   */
#define DIGOUT_PORTG_PIN14   (70)                      /* Connector PG - pin 17 / PG14   */
#define DIGOUT_PORTC_PIN13   (71)                      /* LED / PC13                     */


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


