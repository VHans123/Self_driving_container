/************************************************************************************//**
* \file         filelogger.h
* \brief        SD-card file logger header file.
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
#ifndef FILELOGGER_H
#define FILELOGGER_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */

/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Element data types. */
typedef enum
{
  FILELOGGER_8BIT_SIGNED,                                        /**< int8_t type      */
  FILELOGGER_8BIT_UNSIGNED,                                      /**< uint8_t type     */
  FILELOGGER_16BIT_SIGNED,                                       /**< int16_t type     */
  FILELOGGER_16BIT_UNSIGNED,                                     /**< uint16_t type    */
  FILELOGGER_32BIT_SIGNED,                                       /**< int32_t type     */
  FILELOGGER_32BIT_UNSIGNED,                                     /**< uint32_t type    */
  FILELOGGER_FLOAT_SINGLE,                                       /**< float type       */
  FILELOGGER_FLOAT_DOUBLE                                        /**< double type      */
} tFileLoggerElementType;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void FileLoggerInit(const char *filenameStr, const char *tableHeaderStr,
                    uint8_t maxElements, uint16_t loggingIntervalTimeMs, 
                    uint8_t autoIncrementFilename, uint8_t dotDecimalSeparator,
                    uint8_t autoStart);
void FileLoggerInitElement(uint8_t elementIdx, void *elementPtr, 
                           tFileLoggerElementType elementType);
void FileLoggerStart(void);
void FileLoggerStop(void);


#endif /* FILELOGGER_H */
/********************************* end of filelogger.h *********************************/


