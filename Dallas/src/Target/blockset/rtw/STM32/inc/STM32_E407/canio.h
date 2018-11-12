/************************************************************************************//**
* \file         canio.h
* \brief        CAN message input/output header file. This module is an optional add-on
*               to the CAN driver, which enables message specific event callbacks and
*               storage of newly received message data.
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
#ifndef CANIO_H
#define CANIO_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */
#include "can.h"


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Function type for the id specific message received callback handler. */
typedef void (* tCanIoCallbackMessageReceived)(uint8_t dlc, uint8_t *data, uint32_t timestamp);

/** \brief Function type for the message unmatched callback handler. */
typedef void (* tCanIoCallbackUnmatchedMessageReceived)(uint32_t id, uint8_t dlc, uint8_t *data, uint32_t timestamp);

/** \brief Function type for the id specific message transmitted callback handler. */
typedef void (* tCanIoCallbackMessageTransmitted)(void);

/** \brief CAN message structure type. */
typedef struct
{
  uint32_t id;                                        /**< message identifier          */
  uint8_t  len;                                       /**< message data length code    */
  uint8_t  data[CAN_MAX_DATA_LEN];                    /**< message data byte array     */
  uint32_t timestamp;                                 /**< message timestamp [ms]      */
} tCanIoMessage;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void    CanIoInit(uint8_t channel);
void    CanIoCreateMessageReceivedStorage(uint8_t channel, uint32_t id);
int8_t  CanIoGetMessage(uint8_t channel, uint32_t id, uint8_t *dlc, uint8_t *data, uint32_t *timestamp);
void    CanIoRegisterMessageTransmittedCallback(uint8_t channel, uint32_t id, tCanIoCallbackMessageTransmitted callbackPtr);
void    CanIoRegisterMessageReceivedCallback(uint8_t channel, uint32_t id, tCanIoCallbackMessageReceived callbackPtr);
void    CanIoRegisterUnmatchedMessageReceivedCallback(uint8_t channel, tCanIoCallbackUnmatchedMessageReceived callbackPtr);


#endif /* CANIO_H */
/********************************* end of canio.h **************************************/


