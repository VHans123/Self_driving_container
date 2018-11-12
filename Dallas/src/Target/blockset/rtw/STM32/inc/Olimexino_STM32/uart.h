/************************************************************************************//**
* \file         uart.h
* \brief        UART driver header file.
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
#ifndef UART_H
#define UART_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* uart peripheral identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define UART_CHANNEL1_PA9_PA10    (0)                 /* UART channel 1 - D7/D8        */
#define UART_CHANNEL2_PA2_PA3     (1)                 /* UART channel 2 - D1/D0        */
#define UART_CHANNEL3_PB10_PB11   (2)                 /* UART channel 3 - D29/D30      */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Configuration values for the data bits. */
typedef enum
{
  DATA_BITS_8,                                  /**< 8 data bits                       */
  DATA_BITS_9                                   /**< 9 data bits                       */
} tUartDataBitsCfg;

/** \brief Configuration values for the stop bits. */
typedef enum
{
  STOP_BITS_1,                                  /**< 1 stop bit                        */
  STOP_BITS_2                                   /**< 2 stop bits                       */
} tUartStopBitsCfg;

/** \brief Configuration values for the parity. */
typedef enum
{
  PARITY_NONE,                                  /**< no parity                         */
  PARITY_EVEN,                                  /**< even parity                       */
  PARITY_ODD                                    /**< odd parity                        */
} tUartParityCfg;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
uint8_t  UartInit(uint8_t channel, uint32_t baudrate, tUartDataBitsCfg databits,
		          tUartParityCfg parity, tUartStopBitsCfg stopbits, uint16_t txBufferSize,
		          uint16_t rxBufferSize);
uint8_t  UartPutByte(uint8_t channel, uint8_t c);
void     UartPutString(uint8_t channel, char *text);
uint8_t  UartGetByte(uint8_t channel, uint8_t *rxByte);
uint16_t UartGetNumReceivedBytes(uint8_t channel);
void     Uart1Interrupt(void);
void     Uart2Interrupt(void);
void     Uart3Interrupt(void);


#endif /* UART_H */
/********************************* end of uart.h ***************************************/


