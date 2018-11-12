/*----------------------------------------------------------------------------
| File:
|   XCP_CFG.H
|
| Project:
|   XCP on CAN Sample
|
 ----------------------------------------------------------------------------*/

#if defined ( __XCP_CFG_H__ )
#else
#define __XCP_CFG_H__

/*----------------------------------------------------------------------------*/

/* Platform specific includes */

#define XCP_ENABLE_PARAMETER_CHECK

/* Event specific settings */
#define XCP_ENABLE_DAQ_EVENT_INFO
#define kXcpMaxEvent 3

/*----------------------------------------------------------------------------*/
/* XCP parameters */

  /* 8-Bit qualifier */
typedef unsigned char  vuint8;
typedef signed char    vsint8;   

/* 16-Bit qualifier */
typedef unsigned short vuint16;
typedef signed short   vsint16;

/* 32-Bit qualifier */
typedef unsigned long  vuint32; 
typedef signed long    vsint32;

/* Special pointer types */  
#define MTABYTEPTR unsigned char*
#define DAQBYTEPTR unsigned char*
                                   
/*----------------------------------------------------------------------------*/
/* Interrupt control */
#include <stdint.h>
#include "os.h"

/* Has to be used if XcpSendCallBack() can interrupt XcpEvent() */
#define ApplXcpInterruptDisable() taskENTER_CRITICAL()
#define ApplXcpInterruptEnable()  taskEXIT_CRITICAL()

/*----------------------------------------------------------------------------*/
/* XCP protocol parameters */

/* Byte order */
#define XCP_CPUTYPE_LITTLEENDIAN /* Intel */

/* XCP message length */
#include "mac.h"

#define kXcpMaxCTO     MacGetXcpMaxCTO()      /* Maximum CTO Message Lenght */
#define kXcpMaxDTO     MacGetXcpMaxDTO()      /* Maximum DTO Message Lenght */

/*----------------------------------------------------------------------------*/
/* Optional GET_SEED and UNLOCK */

#define XCP_DISABLE_SEED_KEY

/*----------------------------------------------------------------------------*/
/* Optional memory checksum command */

/* Note: The checksum will be calculated in XcpBackground() */
#define XCP_DISABLE_CHECKSUM
#define XcpChecksumType        vuint16
#define kXcpChecksumMethod     XCP_CHECKSUM_TYPE_ADD12

/*----------------------------------------------------------------------------*/
/* XCP Data Acquisition Parameters */
                                  
/* Enable data acquisition */
#define XCP_ENABLE_DAQ
#define XCP_ENABLE_DAQ_PRESCALER

/* Memory space reserved for DAQ */
#define kXcpDaqMemSize (2048)

/* Optional timestamped data acquisition */
#define XCP_ENABLE_DAQ_TIMESTAMP
typedef vuint16 XcpDaqTimestampType;
#define kXcpDaqTimestampSize                 2
#define kXcpDaqTimestampUnit                 DAQ_TIMESTAMP_UNIT_100US
#define kXcpDaqTimestampTicksPerUnit         1

/*----------------------------------------------------------------------------*/
/* Implement Calibration Page switching */

#define XCP_DISABLE_CALIBRATION_PAGE


/*----------------------------------------------------------------------------*/
/* disable the send queue for more optimal use of the daq memory */
#define XCP_DISABLE_SEND_QUEUE

/*----------------------------------------------------------------------------*/
/* enable XCP user command for HANcoder error handling. This also requires
 * access to the internal xcp data structure.
 */
#define XCP_ENABLE_USER_COMMAND
#define XCP_ENABLE_GET_XCP_DATA_POINTER


#endif
