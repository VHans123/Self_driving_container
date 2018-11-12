/************************************************************************************//**
* \file         usbcom.h
* \brief        USB virtual COM-port header file.
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
#ifndef USBCOM_H
#define USBCOM_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Function type for the data received callback handler. Note that when this
 *         callback is used, it is called from ISR level.
 */
typedef void (* tUsbComCallbackDataReceived)(uint8_t *data, uint32_t len);


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void UsbComInit(void);
void UsbComTransmit(uint8_t *data, uint32_t len);
void UsbComRegisterDataReceivedCallback(tUsbComCallbackDataReceived callbackPtr);
void UsbComHandleReception(uint8_t *data, uint32_t len);
void UsbComHandleAsynchXfer(void);
void UsbComGetSerialNum(void);
void UsbComConnect(uint8_t connect);
void UsbComEnterLowPowerMode(void);
void UsbComLeaveLowPowerMode(void);
void UsbComIRQHandler(void);


#endif /* USBCOM_H */
/********************************* end of usbcom.h *************************************/


