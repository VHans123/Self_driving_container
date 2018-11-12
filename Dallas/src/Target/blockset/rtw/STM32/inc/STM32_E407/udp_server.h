/************************************************************************************//**
* \file         udp_server.h
* \brief        UDP server for the lwIP stack header file.
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*  Copyright (c) 2016  by HAN Automotive   http://www.han.nl        All rights reserved
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

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void UdpServerInit(uint16_t port, uint16_t rxBufLen);
uint16_t UdpServerGetRxCount(void);
uint8_t UdpServerIsRxNewData(void);
uint8_t UdpServerGetRxData(uint16_t count, uint16_t startIdx, uint8_t *data);


/************************************ end of udp_server.h ******************************/


