/************************************************************************************//**
* \file         can.h
* \brief        CAN driver header file.
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
#ifndef CAN_H
#define CAN_H


/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/** \brief Whenever this bit is set in a can identifier, it means it is an 29-bit extended
 *         message identifier.
 */
#define CAN_EXTID_MASK      ((uint32_t)0x80000000)
/** \brief Whenever this bit is set in a can identifier, it means it is an remote frame*/
#define CAN_RTR_FRAME_MASK  ((uint32_t)0x40000000)
/** \brief Maximum number of bytes in a CAN message */
#define CAN_MAX_DATA_LEN    ((uint8_t)8)
/** \brief Total number of supported CAN controllers by this driver. */
#define CAN_CHANNELS_MAX                (2)


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief CAN error status values. */
typedef enum
{
  CAN_ERR_STAT_RX_OVERFLOW = 0,              /**< reception buffer overflow occurred   */
  CAN_ERR_STAT_BUS_OFF                       /**< bus off event occurred               */
} tCanErrStatus;

/** \brief CAN error counters values. */
typedef enum
{
  CAN_ERR_COUNT_RECEPTION = 0,               /**< receive error counter                */
  CAN_ERR_COUNT_TRANSMISSION                 /**< transmit error counter               */
} tCanErrCounter;

/** \brief CAN acceptance filter mode. */
typedef enum 
{                     
  CAN_FILTER_MODE_STDID_ONLY = 0,            /**< receive only 11-bit CAN id's         */
  CAN_FILTER_MODE_EXTID_ONLY,                /**< receive only 29-bit CAN id's         */
  CAN_FILTER_MODE_MIXED_ID                   /**< receive both 11- and 29-bit CAN id's */
} tCanFilterMode;

/** \brief CAN acceptance filter configuration.
 *  \details The mask part of the filter determines which bits in the received message
 *           identifiers should be matched to the corresponding bits in the code part.
 *           A mask bit value of 0 means don't care. The code part of the filter
 *           determines what bit values to match in the received message identifier.
 *    Example 1 - receive all 11-bit and 29-bit message identifiers.
 *       filter = %X XXXX XXXX XXXX XXXX XXXX XXXX XXXX
 *       .mask = 0x00000000   
 *       .code = 0x00000000 (irrelevant in this case)
 *       .mode = CAN_FILTER_MODE_MIXED_ID
 *
 *    Example 2 - receive only 11-bit message identifiers where bits 0..3 are 0.
 *       filter = %X XXXX XXXX XXXX XXXX XXXX XXXX 0000
 *       .mask = 0x0000000f   
 *       .code = 0x00000000
 *       .mode = CAN_FILTER_MODE_STDID_ONLY
 *
 *    Example 3 - receive only the 29-bit message with identifier 0x0000400e
 *       filter = %0 0000 0000 0000 0100 0000 0000 1110
 *       .mask = 0x1fffffff   
 *       .code = 0x0000400e
 *       .mode = CAN_FILTER_MODE_EXTID_ONLY
 */
typedef struct
{
  uint32_t       mask;                       /**< filter mask setting                  */
  uint32_t       code;                       /**< filter code setting                  */
  tCanFilterMode mode;                       /**< filter mode setting STD/EXT/mixed    */
} tCanFilter;

/** \brief Function type for the generic message transmitted callback handler. */
typedef void (* tCanCallbackGenericTransmitted)(uint32_t id);

/** \brief Function type for the generic message received callback handler. */
typedef void (* tCanCallbackGenericReceived)(uint32_t id, uint8_t dlc, uint8_t *data, uint32_t timestamp);

/** \brief Function type for the error callback handler. */
typedef void (* tCanCallbackError)(tCanErrStatus error);


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void    CanInit(uint16_t transmitBufferSize, uint16_t eventBufferSize);
uint8_t CanConnect(uint8_t channel, uint32_t baud, tCanFilter *filter);
uint8_t CanIsConnected(uint8_t channel);
void    CanDisconnect(uint8_t channel);
uint8_t CanTransmit(uint8_t channel, uint32_t id, uint8_t dlc, uint8_t *data);
void    CanCancelTransmit(uint8_t channel);
uint8_t CanGetErrorCount(uint8_t channel, tCanErrCounter counter);
void    CanRegisterGenericTransmittedCallback(uint8_t channel, tCanCallbackGenericTransmitted callbackPtr);
void    CanRegisterGenericReceivedCallback(uint8_t channel, tCanCallbackGenericReceived callbackPtr);
void    CanRegisterErrorCallback(uint8_t channel, tCanCallbackError callbackPtr);
void    Can1Rx0Interrupt(void);
void    Can1Rx1Interrupt(void);
void    Can1TxInterrupt(void);
void    Can1ErrorInterrupt(void);
void    Can2Rx0Interrupt(void);
void    Can2Rx1Interrupt(void);
void    Can2TxInterrupt(void);
void    Can2ErrorInterrupt(void);


#endif /* CAN_H */
/********************************* end of can.h ****************************************/


