/************************************************************************************//**
* \file         model.c
* \brief        Interface to Simulink generated model source file
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


/****************************************************************************************
* Include files
****************************************************************************************/
#include "model.h"
#include "rtwtypes.h"
#include "xcp_cfg.h"
#include "xcp_par.h"
#include "SYS_config.h"
#include "anin.h"
#if (HANcoder_BOOTLOADER > 0)
#include "can.h"
#include "canio.h"
#include "os.h"
#endif

/****************************************************************************************
* Global data declarations
****************************************************************************************/
/** \brief Variable that holds the numder of analog channels with filtering */
uint8_t nrFilteredADCchannels = NUMFILTEREDCHANNELS;

/***************************************************************************************
* Pieces of code from xcp_par.c to be able to precompile the rest of the file
****************************************************************************************/
/* Slave device id */
#if defined ( kXcpStationIdLength )
	/* Ticket #51 changed a define to a variable to make sure the value */
	/* is not fixed when compiling the library */
	short kXcpStationIdLengthVariable = kXcpStationIdLength;
	V_MEMROM0 MEMORY_ROM vuint8 kXcpStationId[kXcpStationIdLength] = kXcpStationIdString;
#endif

#if defined ( XCP_ENABLE_DAQ_EVENT_INFO )
	V_MEMROM0 vuint8 MEMORY_ROM kXcpEventCycle[] =
	{
		(vuint8)(APP_CTRL_TASK_TIMING_US/100), (vuint8)(APP_CTRL_TASK_TIMING_US/100), (vuint8)(APP_CTRL_TASK_TIMING_US/100)																
	};
#endif


/****************************************************************************************
* Plausibility checks
****************************************************************************************/
#if ONESTEPFCN==0
#error Separate output and update functions are not supported.
#endif

#if MT==1
#error Only single tasking is supported.
#endif


/****************************************************************************************
* External function prototypes
****************************************************************************************/
#if defined(INCLUDE_FIRST_TIME_ARG) && INCLUDE_FIRST_TIME_ARG==0
extern void MODEL_INITIALIZE();
#else
extern void MODEL_INITIALIZE(boolean_T firstTime);
#endif
extern void MODEL_TERMINATE(void);
#if NUMST == 1
extern void MODEL_STEP(void);                      /* single instance                  */
#else
extern void MODEL_STEP(int_T tid);                 /* multiple instance                */
#endif

/****************************************************************************************
* Function prototypes
****************************************************************************************/
#if (HANcoder_BOOTLOADER > 0)
static void ModelBootCroMsgReceived(uint8_t dlc, uint8_t *data, uint32_t timestamp);
#endif


/************************************************************************************//**
** \brief     Initializes the Simulink model.
** \return    none.
**
****************************************************************************************/
void ModelInit(void)
{
  /* initialize the model */
#if defined(INCLUDE_FIRST_TIME_ARG) && INCLUDE_FIRST_TIME_ARG==0
  MODEL_INITIALIZE();
#else
  MODEL_INITIALIZE(1);
#endif

#if (HANcoder_BOOTLOADER > 0)
  /* register function that can re-activate the bootloader. note that this assumes the
   * model itself contains a CAN Config block, otherwise the CAN can CANIO modules
   * should be initialized here as well. If the bootloader's XCP CRO message identifier
   * is changed, it should be changed here as well.
   */
  CanIoRegisterMessageReceivedCallback(0, 0x667, ModelBootCroMsgReceived);
#endif
} /*** end of ModelInit ***/


/************************************************************************************//**
** \brief     Runs the Simulink model. It is important that this function is called
**            with the same period time as the fixed steptime configuration in the
**            Simulink model itself.
** \return    none.
**
****************************************************************************************/
void ModelStep(void)
{
  #if NUMST > 1
  /* perform a step of the model */
  MODEL_STEP(0);
#else
  /* perform a step of the model */
  MODEL_STEP();
#endif
} /*** end of ModelStep ***/


/************************************************************************************//**
** \brief     Callback function that gets called each time the bootloader's XCP CRO
**            message was received. If the contents are the CONNECT command, then the
**            bootloader is started.
** \param     dlc Number of bytes in the message.
** \param     data Byte array with message data
** \param     timestamp Message timestamp in ms.
** \return    none.
**
****************************************************************************************/
#if (HANcoder_BOOTLOADER > 0)
static void ModelBootCroMsgReceived(uint8_t dlc, uint8_t *data, uint32_t timestamp)
{
  /* check if this was an XCP CONNECT command */
  if ((data[0] == 0xff) && (data[1] == 0x00))
  {
    /* perform software reset to activate the bootoader again */
    OsSystemReset();
  }
} /*** end of ModelBootCroMsgReceived ***/
#endif


/*********************************** end of model.c ************************************/

