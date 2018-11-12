/************************************************************************************//**
* \file         quadencoder.h
* \brief        Quadrature encoder inputs driver header file.
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
#ifndef QUADENC_H
#define QUADENC_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* quadrature module identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments. Note that the pins
 * are 5V tolerant.
 */
#define QUADENC_TIM1_PA8_PA9     (0)             /* Connector PA8 / UEXT-3             */
#define QUADENC_TIM3_PC6_PC7     (1)             /* Connector PC6 / PC7                */
#define QUADENC_TIM4_PB6_PB7     (2)             /* Connector UEXT-5 / UEXT-6         */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief List of quad encoder input pin configurations. */
typedef enum
{
  QUADENC_CFG_FLOATING,                         /**< floating pin configuration        */
  QUADENC_CFG_PULLUP,                           /**< enable internal pullup resistor   */
  QUADENC_CFG_PULLDOWN                          /**< enable internal pulldown resistor */
} tQuadEncCfg;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void    QuadEncConfigure(uint8_t id, tQuadEncCfg config);
int32_t QuadEncGetCounter(uint8_t id);
void    QuadEncResetCounter(uint8_t id);
void    QuadEncUpdate(void);


#endif /* QUADENC_H */
/********************************* end of quadencoder.h ********************************/


