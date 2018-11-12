/************************************************************************************//**
* \file         errorcodes.h
* \brief        Error codes module header file.
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
#ifndef ERRORCODES_H
#define ERRORCODES_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/** \brief Maximum number of errors that can be stored by this module. */
#define ERRCODES_NUM_OF_MAX_ERRORS    (48)


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Structure type for grouping the data the belongs to an error code. */
typedef struct
{
  uint16_t code;
  uint8_t  param;
  uint8_t  occurrence;
  uint32_t timestamp;
} __attribute__((packed)) tErrCodeData;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void    ErrCodesInit(void);
void    ErrCodesSetError(uint16_t errCode, uint8_t errParam, uint8_t errSaveEeprom);
void    ErrCodesDelSavedErrors(void);
void    ErrCodesDelActiveErrors(void);
void    ErrCodesDelActiveError(uint16_t errCode, uint16_t errParam);
uint8_t ErrCodesGetNumSavedErrors(void);
uint8_t ErrCodesGetNumActiveErrors(void);
uint8_t ErrCodesGetSavedErrors(tErrCodeData *errData, uint8_t startIndexErrors, uint8_t MaxNumErrors);
uint8_t ErrCodesGetActiveErrors(tErrCodeData *errData, uint8_t startIndexErrors, uint8_t MaxNumErrors);
uint8_t ErrCodesSearchSavedError(uint16_t errCode, uint8_t errParam, tErrCodeData *errData);
uint8_t ErrCodesSearchActiveError(uint16_t errCode, uint8_t errParam, tErrCodeData *errData);
uint8_t ErrCodesTestError(uint16_t errCode, uint16_t errParam);



#endif /* ERRORCODES_H */
/********************************* end of errorcodes.h *********************************/


