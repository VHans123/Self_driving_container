/************************************************************************************//**
* \file         diag.h
* \brief        Diagnostics module header file. 
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*  Copyright (c) 2015  by HAN Automotive   http://www.han.nl        All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of the xECU Target Matlab/Simulink Blockset environment. For the
* licensing terms, please contact HAN Automotive.
*
* This software has been carefully tested, but is not guaranteed for any particular
* purpose. HAN Automotive does not offer any warranties and does not guarantee the
* accuracy, adequacy, or completeness of the software and is not responsible for any
* errors or omissions or the results obtained from use of the software.
*
* \endinternal
****************************************************************************************/
#ifndef DIAG_H
#define DIAG_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Possible diagnostic sessions. */
typedef enum
{
  DIAG_SESSION_DEFAULT = 1,            /**< default diagnostic session                 */
  DIAG_SESSION_ECU_EXTENDED = 3        /**< ECU extended session                       */
} tDiagSession;

/** \brief Function type for the get seed callback handler. */
typedef void (* tDiagCallbackGetSeed)(void);

/** \brief Function type for the verify key callback handler. */
typedef void (* tDiagCallbackVerifyKey)(void);


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void     DiagInit(uint8_t require_seedkey, uint16_t txBufferSize);
void     DiagSetSeed(uint32_t seed);
uint32_t DiagGetSeed(void);
uint32_t DiagGetKey(void);
void     DiagSetKeyVerified(uint8_t keyOkay);
void     DiagRegisterGetSeedCallback(tDiagCallbackGetSeed callbackPtr);
void     DiagRegisterVerifyKeyCallback(tDiagCallbackVerifyKey callbackPtr);


#endif /* DIAG_H */
/********************************* end of diag.h ***************************************/
