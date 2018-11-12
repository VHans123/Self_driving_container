/*----------------------------------------------------------------------------
| File:
|   XCP_PAR.H
|
| Project:
|   XCP on CAN Sample
|
 ----------------------------------------------------------------------------*/
#if defined ( __XCP_PAR_H__ )
#else
#define __XCP_PAR_H__


/* XCP default settings */
#include "xcp_def.h"
#include "SYS_config.h"
/* XCP slave device identification (optional) */
V_MEMROM0 extern vuint8 MEMORY_ROM kXcpStationId[];
V_MEMROM0 extern vuint32 MEMORY_ROM kXcpStationIdLengthConfig;
V_MEMROM0 extern vuint8 MEMORY_ROM kXcpStationIdStringConfig[];
extern vuint32 AppCtrlTaskTiming;

/* Event information */
V_MEMROM0 extern MEMORY_ROM vuint8* MEMORY_ROM kXcpEventName[];
V_MEMROM0 extern vuint8 MEMORY_ROM kXcpEventNameLength[];
V_MEMROM0 extern vuint8 MEMORY_ROM kXcpEventCycle[];
V_MEMROM0 extern vuint8 MEMORY_ROM kXcpEventDirection[];
V_MEMROM0 extern vuint8 MEMORY_ROM kXcpEventUnit[];

#endif

