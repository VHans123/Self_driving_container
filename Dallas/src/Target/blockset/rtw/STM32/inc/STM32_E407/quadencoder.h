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
 * sure the first one has value 0 and the others are increments. Note that the channel 1
 * and 2 pins for TIM1, TIM3, TIM4, TIM8 and TIM9 are 5V tolerant.
 */
#define QUADENC_TIM1_PE9_PE11    (0)  /* Con. PE-pin 12 (PE9)  / Con. PE-pin 14 (PE11) */
#define QUADENC_TIM3_PA6_PB5     (1)  /* Con. 4-D12 (PA6)      / Con. 4-D11 (PB5)      */
#define QUADENC_TIM4_PD12_PD13   (2)  /* Con. PD-pin 15 (PD12) / Con. PD-pin 16 (PD13) */
#define QUADENC_TIM8_PC6_PC7     (3)  /* Con. UEXT-3 (PC6)     / Con. UEXT-4 (PC7)     */


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


