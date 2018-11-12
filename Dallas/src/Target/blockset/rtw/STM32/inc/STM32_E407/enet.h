/************************************************************************************//**
* \file         enet.h
* \brief        Ethernet module header file.
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
#ifndef ENET_H
#define ENET_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/tcpip.h"


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void EnetInit(void);
void EnetSetIpAddress(uint8_t ip1, uint8_t ip2, uint8_t ip3, uint8_t ip4);
void EnetSetNetMask(uint8_t nm1, uint8_t nm2, uint8_t nm3, uint8_t nm4);
void EnetSetGateway(uint8_t gw1, uint8_t gw2, uint8_t gw3, uint8_t gw4);
void EnetGetIpAddress(uint8_t *ip1, uint8_t *ip2, uint8_t *ip3, uint8_t *ip4);
void EnetGetNetMask(uint8_t *nm1, uint8_t *nm2, uint8_t *nm3, uint8_t *nm4);
void EnetGetGateway(uint8_t *gw1, uint8_t *gw2, uint8_t *gw3, uint8_t *gw4);


/****************************************************************************************
* Hook function prototypes
****************************************************************************************/
void EnetLinkUpHook(void);
void EnetLinkDownHook(void);


#endif /* ENET_H */
/********************************* end of enet.h ***************************************/


