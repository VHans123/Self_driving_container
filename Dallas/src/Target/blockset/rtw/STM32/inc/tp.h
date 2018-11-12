/************************************************************************************//**
* \file         tp.h
* \brief        Transport protocol header file. 
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*  Copyright (c) 2015  by HAN Automotive   http://www.han.nl        All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of the xECU Target Matlab/Simulink Blockset environment. For the
* licensing terms, please contact HAN Automotive.
*
* This software has been carefully tested, but is not guaranteed for any particular
* purpose. HAN Automotive does not offer any warranties and does not guarantee the
* accuracy, adequacy, or completeness of the software and is not responsible for any
* errors or omissions or the results obtained from use of the software.
*
* \endinternal
****************************************************************************************/
#ifndef TP_H
#define TP_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Possible result values for data transfers. */
typedef enum
{
  TP_RESULT_OK,                    /**< service execution successfully completed       */
  TP_RESULT_TIMEOUT_A,             /**< timer N_Ar/N_As timed out (N_Ar_max/N_As_max)  */
  TP_RESULT_TIMEOUT_BS,            /**< timer N_Bs timed out (N_Bs_max)                */
  TP_RESULT_TIMEOUT_CR,            /**< timer N_Cr timed out (N_Cr_max)                */
  TP_RESULT_WRONG_SN,              /**< unexpected sequence number received            */
  TP_RESULT_INVALID_FS,            /**< invalid or unknown FlowStatus received         */
  TP_RESULT_UNEXP_PDU,             /**< unexpected protocol data unit received         */
  TP_RESULT_WFT_OVRN,              /**< too many FlowStatus = WAIT received            */
  TP_RESULT_BUFFER_OVFLW,          /**< FlowStatus = OVFLW received                    */
  TP_RESULT_ERROR                  /**< generic error                                  */
} tTpResult;

/** \brief Possible parameter identifier values */
typedef enum
{
  TP_PARAM_ID_BLOCKSIZE,           /**< blocksize parameter ID                         */
  TP_PARAM_ID_STMIN                /**< min. seperation time parameter ID              */
} tTpParamId;

/** \brief Possible result values for parameter change requests */
typedef enum
{
  TP_PARAM_CHANGE_OK,              /**< parameter succesfully changed                  */
  TP_PARAM_CHANGE_RX_ON,           /**< not changed because reception in progress      */
  TP_PARAM_CHANGE_WRONG_PARAMETER, /**< not changed due to invalid parameter specified */
  TP_PARAM_CHANGE_WRONG_VALUE      /**< not change due to invalid parameter value      */
} tTpParamChangeResult;

/** \brief Function type for the first frame received callback handler. */
typedef void (* tTpCallbackFirstFrameReceived)(uint16_t len);

/** \brief Function type for the data received callback handler. */
typedef void (* tTpCallbackDataReceived)(uint8_t *data, uint16_t len, tTpResult result);

/** \brief Function type for the transfer complete callback handler. */
typedef void (* tTpCallbackTransferComplete)(tTpResult result);


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void TpInit(uint8_t channel, uint32_t transmit_id, uint32_t receive_id,
            uint8_t blockSize, uint8_t STmin, uint16_t receiveBufferSize);
uint8_t TpTransfer(uint8_t *data, uint16_t len);
void TpRegisterFirstFrameReceivedCallback(tTpCallbackFirstFrameReceived callbackPtr);
void TpRegisterDataReceivedCallback(tTpCallbackDataReceived callbackPtr);
void TpRegisterTransferCompleteCallback(tTpCallbackTransferComplete callbackPtr);
tTpParamChangeResult TpChangeParameter(tTpParamId id, uint8_t value);

#endif /* TP_H */
/********************************* end of tp.h *****************************************/
