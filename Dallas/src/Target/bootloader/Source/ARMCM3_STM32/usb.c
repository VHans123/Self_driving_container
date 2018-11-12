/************************************************************************************//**
* \file         Source\ARMCM3_STM32\usb.c
* \brief        Bootloader USB communication interface source file.
* \ingroup      Target_ARMCM3_STM32
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*   Copyright (c) 2011  by Feaser    http://www.feaser.com    All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of OpenBLT. OpenBLT is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option) any later
* version.
*
* OpenBLT is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with OpenBLT.
* If not, see <http://www.gnu.org/licenses/>.
*
* A special exception to the GPL is included to allow you to distribute a combined work 
* that includes OpenBLT without being obliged to provide the source code for any 
* proprietary components. The exception text is included at the bottom of the license
* file <license.html>.
* 
* \endinternal
****************************************************************************************/

/****************************************************************************************
* Include files
****************************************************************************************/
#include "boot.h"                                /* bootloader generic header          */
#if (BOOT_COM_USB_ENABLE > 0)
#include "usb_lib.h"                             /* USB library driver header          */
#include "usb_desc.h"                            /* USB descriptor header              */
#include "usb_pwr.h"                             /* USB power management header        */
#include "usb_istr.h"                            /* USB interrupt routine header       */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/** \brief Total number of fifo buffers. */
#define FIFO_MAX_BUFFERS         (2)
/** \brief Invalid value for a fifo buffer handle. */
#define FIFO_ERR_INVALID_HANDLE  (255)
/** \brief Number of bytes that fit in the fifo pipe. */
#define FIFO_PIPE_SIZE           (64)


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Structure type for fifo control. */
typedef struct t_fifo_ctrl
{
  blt_int8u          *startptr;                    /**< pointer to start of buffer     */
  blt_int8u          *endptr;                      /**< pointer to end of buffer       */
  blt_int8u          *readptr;                     /**< pointer to next read location  */
  blt_int8u          *writeptr;                    /**< pointer to next free location  */
  blt_int8u           length;                      /**< number of buffer elements      */
  blt_int8u           entries;                     /**< # of full buffer elements      */
  blt_int8u           handle;                      /**< handle of the buffer           */ 
  struct t_fifo_ctrl *fifoctrlptr;                 /**< pointer to free buffer control */
} tFifoCtrl;

/** \brief Structure type for a fifo pipe. */
typedef struct
{
  blt_int8u handle;                                /**< fifo handle                    */
  blt_int8u data[FIFO_PIPE_SIZE];                  /**< fifo data buffer               */
} tFifoPipe;                                       /**< USB pipe fifo type             */


/****************************************************************************************
* Hook functions
****************************************************************************************/
extern void UsbEnterLowPowerModeHook(void);
extern void UsbLeaveLowPowerModeHook(void);
extern void UsbConnectHook(blt_bool connect);


/****************************************************************************************
* Function prototypes
****************************************************************************************/
static blt_bool  UsbReceiveByte(blt_int8u *data);
static blt_bool  UsbTransmitByte(blt_int8u data);
static void      UsbFifoMgrInit(void);
static blt_int8u UsbFifoMgrCreate(blt_int8u *buffer, blt_int8u length);
static blt_bool  UsbFifoMgrWrite(blt_int8u handle, blt_int8u data);
static blt_bool  UsbFifoMgrRead(blt_int8u handle, blt_int8u *data);
static blt_int8u UsbFifoMgrScan(blt_int8u handle);


/****************************************************************************************
* Local data declarations
****************************************************************************************/
/** \brief Local variable that holds the fifo control structures. */
static tFifoCtrl  fifoCtrl[FIFO_MAX_BUFFERS];
/** \brief Local pointer that points to the next free fifo control structure. */
static tFifoCtrl *fifoCtrlFree;
/** \brief Fifo pipe used for the bulk in endpoint. */
static tFifoPipe  fifoPipeBulkIN;
/** \brief Fifo pipe used for the bulk out endpoint. */
static tFifoPipe  fifoPipeBulkOUT;


/************************************************************************************//**
** \brief     Initializes the USB communication interface.
** \return    none.
**
****************************************************************************************/
void UsbInit(void)
{
  /* initialize the FIFO manager */
  UsbFifoMgrInit();
  /* place 2 buffers under FIFO management */
  fifoPipeBulkIN.handle  = UsbFifoMgrCreate(fifoPipeBulkIN.data,  FIFO_PIPE_SIZE);
  fifoPipeBulkOUT.handle = UsbFifoMgrCreate(fifoPipeBulkOUT.data, FIFO_PIPE_SIZE);
  /* validate fifo handles */
  ASSERT_RT( (fifoPipeBulkIN.handle  != FIFO_ERR_INVALID_HANDLE) && \
             (fifoPipeBulkOUT.handle != FIFO_ERR_INVALID_HANDLE) );
  /* initialize the low level USB driver */
  USB_Init();
} /*** end of UsbInit ***/


/************************************************************************************//**
** \brief     Releases the USB communication interface. 
** \return    none.
**
****************************************************************************************/
void UsbFree(void)
{
  /* disconnect the USB device from the USB host */
  UsbConnectHook(BLT_FALSE);
} /*** end of UsbFree ***/


/************************************************************************************//**
** \brief     Transmits a packet formatted for the communication interface.
** \param     data Pointer to byte array with data that it to be transmitted.
** \param     len  Number of bytes that are to be transmitted.
** \return    none.
**
****************************************************************************************/
void UsbTransmitPacket(blt_int8u *data, blt_int8u len)
{
  blt_int16u data_index;
  blt_bool result;

  /* verify validity of the len-paramenter */
  ASSERT_RT(len <= BOOT_COM_USB_TX_MAX_DATA);  

  /* first transmit the length of the packet */  
  result = UsbTransmitByte(len);
  ASSERT_RT(result == BLT_TRUE);  
  
  /* transmit all the packet bytes one-by-one */
  for (data_index = 0; data_index < len; data_index++)
  {
    /* keep the watchdog happy */
    CopService();
    /* write byte */
    result = UsbTransmitByte(data[data_index]);
    ASSERT_RT(result == BLT_TRUE);  
  }
} /*** end of UsbTransmitPacket ***/


/************************************************************************************//**
** \brief     Receives a communication interface packet if one is present.
** \param     data Pointer to byte array where the data is to be stored.
** \return    BLT_TRUE if a packet was received, BLT_FALSE otherwise.
**
****************************************************************************************/
blt_bool UsbReceivePacket(blt_int8u *data)
{
  static blt_int8u xcpCtoReqPacket[BOOT_COM_USB_RX_MAX_DATA+1];  /* one extra for length */
  static blt_int8u xcpCtoRxLength;
  static blt_bool  xcpCtoRxInProgress = BLT_FALSE;

  /* poll USB interrupt flags to process USB related events */
  USB_Istr();

  /* start of cto packet received? */
  if (xcpCtoRxInProgress == BLT_FALSE)
  {
    /* store the message length when received */
    if (UsbReceiveByte(&xcpCtoReqPacket[0]) == BLT_TRUE)
    {
      if (xcpCtoReqPacket[0] > 0)
      {
        /* indicate that a cto packet is being received */
        xcpCtoRxInProgress = BLT_TRUE;
        /* reset packet data count */
        xcpCtoRxLength = 0;
      }
    }
  }
  else
  {
    /* store the next packet byte */
    if (UsbReceiveByte(&xcpCtoReqPacket[xcpCtoRxLength+1]) == BLT_TRUE)
    {
      /* increment the packet data count */
      xcpCtoRxLength++;

      /* check to see if the entire packet was received */
      if (xcpCtoRxLength == xcpCtoReqPacket[0])
      {
        /* copy the packet data */
        CpuMemCopy((blt_int32u)data, (blt_int32u)&xcpCtoReqPacket[1], xcpCtoRxLength);        
        /* done with cto packet reception */
        xcpCtoRxInProgress = BLT_FALSE;

        /* packet reception complete */
        return BLT_TRUE;
      }
    }
  }
  /* packet reception not yet complete */
  return BLT_FALSE;
} /*** end of UsbReceivePacket ***/


/************************************************************************************//**
** \brief     Receives a communication interface byte if one is present.
** \param     data Pointer to byte where the data is to be stored.
** \return    BLT_TRUE if a byte was received, BLT_FALSE otherwise.
**
****************************************************************************************/
static blt_bool UsbReceiveByte(blt_int8u *data)
{
  blt_bool result;
 
  /* obtain data from the fifo */
  result = UsbFifoMgrRead(fifoPipeBulkOUT.handle, data);
  return result;
} /*** end of UsbReceiveByte ***/


/************************************************************************************//**
** \brief     Transmits a communication interface byte.
** \param     data Value of byte that is to be transmitted.
** \return    BLT_TRUE if the byte was transmitted, BLT_FALSE otherwise.
**
****************************************************************************************/
static blt_bool UsbTransmitByte(blt_int8u data)
{
  blt_bool result;
 
  /* write data from to fifo */
  result = UsbFifoMgrWrite(fifoPipeBulkIN.handle, data);
  return result;
} /*** end of UsbTransmitByte ***/


/************************************************************************************//**
** \brief     Power-off system clocks and power while entering suspend mode.
** \return    none.
**
****************************************************************************************/
void UsbEnterLowPowerMode(void)
{
  /* Set the device state to suspend */
  bDeviceState = SUSPENDED;
  /* power-off system clocks and power */
  UsbEnterLowPowerModeHook();
} /*** end of UsbEnterLowPowerMode ***/


/************************************************************************************//**
** \brief     Restores system clocks and power while exiting suspend mode.
** \return    none.
**
****************************************************************************************/
void UsbLeaveLowPowerMode(void)
{
  DEVICE_INFO *pInfo = &Device_Info;

  /* restore power and system clocks */
  UsbLeaveLowPowerModeHook();
  /* Set the device state to the correct state */
  if (pInfo->Current_Configuration != 0)
  {
    /* Device configured */
    bDeviceState = CONFIGURED;
  }
  else
  {
    bDeviceState = ATTACHED;
  }
} /*** end of UsbLeaveLowPowerMode ***/


/************************************************************************************//**
** \brief     Checks if there is still data left to transmit and if so submits it
**            for transmission with the USB endpoint.
** \return    none.
**
****************************************************************************************/
void UsbTransmitPipeBulkIN(void)
{
  /* USB_Tx_Buffer is static for run-time optimalization */
  static uint8_t USB_Tx_Buffer[BULK_DATA_SIZE];
  blt_int8u nr_of_bytes_for_tx_endpoint;
  blt_int8u byte_counter;
  blt_int8u byte_value;
  blt_bool  result;

  /* read how many bytes should be transmitted */
  nr_of_bytes_for_tx_endpoint = UsbFifoMgrScan(fifoPipeBulkIN.handle);
  /* only continue if there is actually data left to transmit */
  if (nr_of_bytes_for_tx_endpoint == 0)
  {
    return;
  }
  /* make sure to not transmit more than the USB endpoint can handle */
  if (nr_of_bytes_for_tx_endpoint > BULK_DATA_SIZE)
  {
    nr_of_bytes_for_tx_endpoint = BULK_DATA_SIZE;
  }
  /* copy the transmit data to the transmit buffer */
  for (byte_counter=0; byte_counter < nr_of_bytes_for_tx_endpoint; byte_counter++)
  {
    /* obtain data from the fifo */
    result = UsbFifoMgrRead(fifoPipeBulkIN.handle, &byte_value);
    ASSERT_RT(result == BLT_TRUE);
    /* store it in the endpoint's RAM */
    USB_Tx_Buffer[byte_counter] = byte_value; 
  }
  /* store it in the endpoint's RAM */
  UserToPMABufferCopy(&USB_Tx_Buffer[0], ENDP1_TXADDR, nr_of_bytes_for_tx_endpoint);
  /* set the number of bytes that need to be transmitted from this endpoint */
  SetEPTxCount(ENDP1, nr_of_bytes_for_tx_endpoint);
  /* inform the endpoint that it can start its transmission because the data is valid */
  SetEPTxValid(ENDP1); 
} /*** end of UsbTransmitPipeBulkIN ***/


/************************************************************************************//**
** \brief     Stores data that was received on the Bulk OUT pipe in the fifo.
** \return    none.
**
****************************************************************************************/
void UsbReceivePipeBulkOUT(void)
{
  /* USB_Rx_Buffer is static for run-time optimalization */
  static uint8_t USB_Rx_Buffer[BULK_DATA_SIZE];
  uint16_t USB_Rx_Cnt;
  uint16_t byte_counter;
  blt_bool result;
  
  /* Get the received data buffer and update the counter */
  USB_Rx_Cnt = USB_SIL_Read(EP1_OUT, USB_Rx_Buffer);
  
  /* USB data will be immediately processed, this allow next USB traffic being 
   * NAKed till the end of the USART Xfer 
   */
  for (byte_counter=0; byte_counter<USB_Rx_Cnt; byte_counter++)
  {
    /* add the data to the fifo */
    result = UsbFifoMgrWrite(fifoPipeBulkOUT.handle, USB_Rx_Buffer[byte_counter]);
    /* verify that the fifo wasn't full */
    ASSERT_RT(result == BLT_TRUE);
  }
  /* Enable the reception of data on EP1 */
  SetEPRxValid(ENDP1);
} /*** end of UsbReceivePipeBulkOUT ***/


/************************************************************************************//**
** \brief     Converts Hex 32Bits value into char.
** \param     value The hexadecimal value to convert.
** \param     pbuf  Pointer to where the resulting string should be stored.
** \param     len   Number of characters to convert.
** \return    none.
**
****************************************************************************************/
static void IntToUnicode (blt_int32u value , blt_int8u *pbuf , blt_int8u len)
{
  blt_int8u idx = 0;
  
  for( idx = 0 ; idx < len ; idx ++)
  {
    if( ((value >> 28)) < 0xA )
    {
      pbuf[ 2* idx] = (value >> 28) + '0';
    }
    else
    {
      pbuf[2* idx] = (value >> 28) + 'A' - 10; 
    }
    
    value = value << 4;
    
    pbuf[ 2* idx + 1] = 0;
  }
} /*** end of IntToUnicode ***/


/************************************************************************************//**
** \brief     Creates the serial number string descriptor.
** \return    none.
**
****************************************************************************************/
void UsbGetSerialNum(void)
{
  blt_int32u Device_Serial0, Device_Serial1, Device_Serial2;

  Device_Serial0 = *(volatile blt_int32u*)(0x1FFFF7E8);
  Device_Serial1 = *(volatile blt_int32u*)(0x1FFFF7EC);
  Device_Serial2 = *(volatile blt_int32u*)(0x1FFFF7F0);

  Device_Serial0 += Device_Serial2;

  if (Device_Serial0 != 0)
  {
    IntToUnicode(Device_Serial0, &Bulk_StringSerial[2] , 8);
    IntToUnicode(Device_Serial1, &Bulk_StringSerial[18], 4);
  }
} /*** end of UsbGetSerialNum ***/


/************************************************************************************//**
** \brief     Initializes the fifo manager. Each controlled fifo is assigned a
**            unique handle, which is the same as its index into fifoCtrl[]. Each
**            controlled fifo holds a pointer to the next free fifo control.
**            For the last fifo in fifoCtrl[] this one is set to a null-pointer as
**            an out of fifo control indicator. Function should be called once
**            before any of the other fifo management functions are called.
** \return    none.
**
****************************************************************************************/
static void UsbFifoMgrInit(void)
{
  blt_int8u i;
  tFifoCtrl *pbc1, *pbc2;

  pbc1 = &fifoCtrl[0];
  pbc2 = &fifoCtrl[1];
  /* assign fifo handles and pointer to next free fifo */
  for (i = 0; i < (FIFO_MAX_BUFFERS - 1); i++)
  {
    pbc1->handle = i;
    pbc1->fifoctrlptr = pbc2;
    pbc1++;
    pbc2++;
  }
  /* initialize handle for the last one and use null-pointer for the next free fifo  */
  pbc1->handle = i;
  pbc1->fifoctrlptr = (tFifoCtrl *)0;
  fifoCtrlFree = &fifoCtrl[0];
} /*** end of UsbFifoMgrInit ***/


/************************************************************************************//**
** \brief     Places a data storage array under fifo management control. A handle
**            for identifying the fifo in subsequent fifo management function
**            calls is returned, if successful.
** \param     buffer Pointer to the first element in the data storage fifo.
** \param     length Maximum number of data elements that can be stored in the fifo.
** \return    Fifo handle if successfull, or FIFO_ERR_INVALID_HANDLE.
**
****************************************************************************************/
static blt_int8u UsbFifoMgrCreate(blt_int8u *buffer, blt_int8u length)
{
  tFifoCtrl *pbc;

  /* first determine if these is still a free fifo control available */
  if (fifoCtrlFree == (tFifoCtrl *)0)
  {
    return FIFO_ERR_INVALID_HANDLE;
  }
  /* store pointer to free fifo and update pointer to next free one */
  pbc = fifoCtrlFree;
  fifoCtrlFree = pbc->fifoctrlptr;

  /* initialize the buffer control */
  pbc->length = length;
  pbc->readptr = buffer;
  pbc->writeptr = buffer;
  pbc->entries = 0;
  pbc->startptr = buffer;
  pbc->endptr = (blt_int8u*)(buffer + length - 1);

  /* return the handle to the successfully created fifo control */
  return pbc->handle;
} /*** end of UsbFifoMgrCreate ***/


/************************************************************************************//**
** \brief     Stores data in the fifo.
** \param     handle Identifies the fifo to write data to.
** \param     data   Pointer to the data that is to be written to the fifo.
** \return    BLT_TRUE if the data was successfully stored in the fifo, BLT_FALSE
**            otherwise.
**
****************************************************************************************/
static blt_bool UsbFifoMgrWrite(blt_int8u handle, blt_int8u data)
{
  /* check the validity of the handle parameter */
  ASSERT_RT(handle < FIFO_MAX_BUFFERS);
  /* check if fifo is full */
  if (fifoCtrl[handle].entries == fifoCtrl[handle].length)
  {
    return BLT_FALSE;
  }
  /* copy data to fifo */
  *fifoCtrl[handle].writeptr = data;
  /* data written so update number of entries */
  fifoCtrl[handle].entries++;
  /* update write pointer */
  fifoCtrl[handle].writeptr++;
  /* check end of fifo */
  if (fifoCtrl[handle].writeptr > fifoCtrl[handle].endptr)
  {
    /* set write pointer to start of the cyclic fifo */
    fifoCtrl[handle].writeptr = fifoCtrl[handle].startptr;
  }
  /* still here so all is okay */	
  return BLT_TRUE;
} /*** end of UsbFifoMgrWrite ***/


/************************************************************************************//**
** \brief     Retrieves data from the fifo.
** \param     handle Identifies the fifo to read data from.
** \param     data   Pointer to where the read data is to be stored.
** \return    BLT_TRUE if the data was successfully read from the fifo, BLT_FALSE
**            otherwise.
**
****************************************************************************************/
static blt_bool UsbFifoMgrRead(blt_int8u handle, blt_int8u *data)
{
  /* check the validity of the handle parameter */
  ASSERT_RT(handle < FIFO_MAX_BUFFERS);
  /* check if fifo is empty */
  if (fifoCtrl[handle].entries == 0)
  {
    return BLT_FALSE;
  }
  /* read the data */
  *data = *fifoCtrl[handle].readptr;
  /* data read so update number of entries */
  fifoCtrl[handle].entries--;
  /* update read pointer */
  fifoCtrl[handle].readptr++;
  /* check end of fifo */
  if (fifoCtrl[handle].readptr > fifoCtrl[handle].endptr)
  {
    /* set read pointer to start of the cyclic fifo */
    fifoCtrl[handle].readptr = fifoCtrl[handle].startptr;
  }
  /* still here so all is good */
  return BLT_TRUE;
} /*** end of UsbFifoMgrRead ***/


/************************************************************************************//**
** \brief     Returns the number of data entries currently present in the fifo.
** \param     handle Identifies the fifo that is to be scanned.
** \return    Number of data entries in the fifo if successful, otherwise 0.
**
****************************************************************************************/
static blt_int8u UsbFifoMgrScan(blt_int8u handle)
{
  /* check the validity of the handle parameter */
  ASSERT_RT(handle < FIFO_MAX_BUFFERS);
  /* read and return the number of data entries */
  return fifoCtrl[handle].entries;
} /*** end of UsbFifoMgrScan ***/
#endif /* BOOT_COM_USB_ENABLE > 0 */


/*********************************** end of usb.c **************************************/
