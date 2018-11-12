/************************************************************************************//**
* \file         errorList.h
* \brief        List with internal system error codes.
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
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
#ifndef ERRORLIST_H
#define ERRORLIST_H


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/** \brief Minor severity level. */
#define ER_PARAM_SEVERITY_MINOR                  (10)
/** \brief Standby severity level. */
#define ER_PARAM_SEVERITY_STANDBY                (15)
/** \brief Critical severity level. */
#define ER_PARAM_SEVERITY_CRITICAL               (20)

/** \brief Generic system error. */
#define ER_CODE_GENERIC_SYSTEM_ERROR            (0x1000)
/** \brief Invalid analog input pin. */
#define ER_CODE_ANIN_INVALID_PIN                 (0x2000)
/** \brief No more free analag input channels. */
#define ER_CODE_ANIN_NO_FREE_CHANNELS            (0x2001)
/** \brief Cannot allocate memory for analog input channels. */
#define ER_CODE_ANIN_ALLOC_ERROR	             (0x2002)
/** \brief Pointer points out of range of allocated memory */
#define ER_CODE_ANIN_POINTER_OUT_RANGE			 (0x2003)
/** \brief Pointer for analog input filtering invalid */
#define ER_CODE_ANIN_INVALID_POINTER		 	 (0x2004)
/** \brief Pin not found in aninGet() */
#define ER_CODE_ANIN_POINTER_NOT_FOUND			 (0x2005)
/** \brief Invalid analog output pin. */
#define ER_CODE_ANOUT_INVALID_PIN                (0x2010)
/** \brief CAN event queue is invalid. */
#define ER_CODE_CAN_EVENT_QUEUE_INVALID          (0x2100)
/** \brief CAN transmit queue is invalid. */
#define ER_CODE_CAN_TRANSMIT_QUEUE_INVALID       (0x2101)
/** \brief CAN event task is invalid. */
#define ER_CODE_CAN_EVENT_TASK_INVALID           (0x2102)
/** \brief CAN transmit task is invalid. */
#define ER_CODE_CAN_TRANSMIT_TASK_INVALID        (0x2103)
/** \brief CAN transmit queue is full. */
#define ER_CODE_CAN_TRANSMIT_QUEUE_FULL          (0x2104)
/** \brief Invalid CAN counter parameter. */
#define ER_CODE_CAN_INVALID_COUNTER              (0x2105)
/** \brief CAN event queue is full. */
#define ER_CODE_CAN_EVENT_QUEUE_FULL             (0x2106)
/** \brief CAN transmit queue error. */
#define ER_CODE_CAN_TRANSMIT_QUEUE_ERROR         (0x2107)
/** \brief CAN event queue error. */
#define ER_CODE_CAN_EVENT_QUEUE_ERROR            (0x2108)
/** \brief Unsupported CAN event. */
#define ER_CODE_CAN_UNEXPECTED_EVENT             (0x2109)
/** \brief Invalid CAN queue handle. */
#define ER_CODE_CAN_INVALID_QUEUE_HANDLE         (0x210A)
/** \brief Invalid CAN interrupt configuration. */
#define ER_CODE_CAN_INVALID_INTERRUPT_IRQ        (0x210B)
/** \brief Invalid CAN channel specific. */
#define ER_CODE_CAN_INVALID_CHANNEL              (0x210C)
/** \brief Cannot allocate RX storage on heap. */
#define ER_CODE_CANIO_RX_STORAGE_ALLOCATION      (0x2200)
/** \brief Cannot allocate TX callback on heap. */
#define ER_CODE_CANIO_TX_CALLBACK_ALLOCATION     (0x2201)
/** \brief Cannot allocate RX callback on heap. */
#define ER_CODE_CANIO_RX_CALLBACK_ALLOCATION     (0x2202)
/** \brief Invalid digital input pin. */
#define ER_CODE_DIGIN_INVALID_PIN                (0x2300)
/** \brief Invalid digital output pin. */
#define ER_CODE_DIGOUT_INVALID_PIN               (0x2400)
/** \brief Invalid error related parameters. */
#define ER_CODE_ERRCODES_INVALID_PARAMS          (0x2500)
/** \brief Could not create or start event channel timer. */
#define ER_CODE_MAC_EVENT_CHANNEL_TIMER_ERROR    (0x2600)
/** \brief Invalid module id. */
#define ER_CODE_PWMOUT_INVALID_MODULE            (0x2700)
/** \brief Invalid pwm output pin. */
#define ER_CODE_PWMOUT_INVALID_PIN               (0x2701)
/** \brief Invalid module id. */
#define ER_CODE_QUADENC_INVALID_MODULE           (0x2800)
/** \brief Invalid channel id. */
#define ER_CODE_UART_INVALID_CHANNEL             (0x2900)
/** \brief Transmit buffer queue is full. */
#define ER_CODE_UART_TRANSMIT_QUEUE_FULL         (0x2901)
/** \brief Reception buffer queue is full. */
#define ER_CODE_UART_RECEPTION_QUEUE_FULL        (0x2902)
/** \brief Cannot initialize eeprom emulation library. */
#define ER_CODE_EEPROM_INIT                      (0x2A00)
/** \brief Cannot write to EEPROM. */
#define ER_CODE_EEPROM_WRITE                     (0x2A01)
/** \brief Cannot erase EEPROM. */
#define ER_CODE_EEPROM_ERASE                     (0x2A02)
/** \brief Invalid channel id. */
#define ER_CODE_SPI_INVALID_CHANNEL              (0x2B00)
/** \brief Timeout occurred during an SPI transfer. */
#define ER_CODE_SPI_TRANSFER_TIMEOUT             (0x2B01)
/** \brief Invalid module id. */
#define ER_CODE_TIMEIN_INVALID_MODULE            (0x2C00)
/** \brief Invalid pwm output pin. */
#define ER_CODE_TIMEIN_INVALID_PIN               (0x2C01)
/** \brief Cannot allocated table on heap. */
#define ER_CODE_LOGGER_TABLE_ALLOCATION_ERROR    (0x2D00)
/** \brief Invalid table element specified. */
#define ER_CODE_LOGGER_TABLE_INVALID_ELEMENT     (0x2D01)
/** \brief Cannot create logger task. */
#define ER_CODE_LOGGER_TASK_INVALID              (0x2D02)
/** \brief Cannot create file the SD-card. */
#define ER_CODE_LOGGER_FILE_CREATION_ERROR       (0x2D03)
/** \brief Invalid module id. */
#define ER_CODE_TIMEOUT_INVALID_MODULE           (0x2E00)
/** \brief Invalid timer output pin. */
#define ER_CODE_TIMEOUT_INVALID_PIN              (0x2E01)
/** \brief Could not create or start the task timer */
#define ER_CODE_TP_TASK_TIMER_ERROR              (0x2F00)
/** \brief Could not allocate reception buffer on the heap. */
#define ER_CODE_TP_RX_ALLOC_ERROR                (0x2F01)
/** \brief Could not create or start the task timer */
#define ER_CODE_DIAG_TASK_TIMER_ERROR            (0x3000)
/** \brief Could not allocate transmission buffer on the heap. */
#define ER_CODE_DIAG_TX_ALLOC_ERROR              (0x3001)
/** \brief Could not add more data to the transmit buffer. */
#define ER_CODE_DIAG_TX_BUFFER_FULL              (0x3002)
/** \brief Could not create or start the PDO timer */
#define ER_CODE_CONODE_PDO_TIMER_ERROR           (0x3100)
/** \brief Could not allocated rxBuffer on heap */
#define ER_CODE_UDPSERVER_RXBUF_ALLOC_ERROR      (0x3200)
/** \brief Could not allocated connection object on heap */
#define ER_CODE_UDPSERVER_CONN_ALLOC_ERROR       (0x3201)
/** \brief Could not bind connection object */
#define ER_CODE_UDPSERVER_CONN_BIND_ERROR        (0x3202)


#endif /* ERRORLIST_H */
/*********************************** end of errorList.h ********************************/

    
