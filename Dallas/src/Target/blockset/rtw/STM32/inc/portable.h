/*
    FreeRTOS V7.6.0 - Copyright (C) 2013 Real Time Engineers Ltd. 
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that has become a de facto standard.             *
     *                                                                       *
     *    Help yourself get started quickly and support the FreeRTOS         *
     *    project by purchasing a FreeRTOS tutorial book, reference          *
     *    manual, or both from: http://www.FreeRTOS.org/Documentation        *
     *                                                                       *
     *    Thank you!                                                         *
     *                                                                       *
    ***************************************************************************

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>!AND MODIFIED BY!<< the FreeRTOS exception.

    >>! NOTE: The modification to the GPL is included to allow you to distribute
    >>! a combined work that includes FreeRTOS without being obliged to provide
    >>! the source code for proprietary components outside of the FreeRTOS
    >>! kernel.

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available from the following
    link: http://www.freertos.org/a00114.html

    1 tab == 4 spaces!

    ***************************************************************************
     *                                                                       *
     *    Having a problem?  Start by reading the FAQ "My application does   *
     *    not run, what could be wrong?"                                     *
     *                                                                       *
     *    http://www.FreeRTOS.org/FAQHelp.html                               *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org - Documentation, books, training, latest versions,
    license and Real Time Engineers Ltd. contact details.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.OpenRTOS.com - Real Time Engineers ltd license FreeRTOS to High
    Integrity Systems to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

/*-----------------------------------------------------------
 * Portable layer API.  Each function must be defined for each port.
 *----------------------------------------------------------*/

#ifndef PORTABLE_H
#define PORTABLE_H

/* Include the macro file relevant to the port being used. */

#ifdef OPEN_WATCOM_INDUSTRIAL_PC_PORT
	#include "portmacro.h"
	typedef void ( __interrupt __far *pxISR )();
#endif

#ifdef OPEN_WATCOM_FLASH_LITE_186_PORT
	#include "portmacro.h"
	typedef void ( __interrupt __far *pxISR )();
#endif

#ifdef GCC_MEGA_AVR
	#include "portmacro.h"
#endif

#ifdef IAR_MEGA_AVR
	#include "portmacro.h"
#endif

#ifdef MPLAB_PIC24_PORT
	#include "portmacro.h"
#endif

#ifdef MPLAB_DSPIC_PORT
	#include "portmacro.h"
#endif

#ifdef MPLAB_PIC18F_PORT
	#include "portmacro.h"
#endif

#ifdef MPLAB_PIC32MX_PORT
	#include "portmacro.h"
#endif

#ifdef _FEDPICC
	#include "portmacro.h"
#endif

#ifdef SDCC_CYGNAL
	#include "portmacro.h"
#endif

#ifdef GCC_ARM7
	#include "portmacro.h"
#endif

#ifdef GCC_ARM7_ECLIPSE
	#include "portmacro.h"
#endif

#ifdef ROWLEY_LPC23xx
	#include "portmacro.h"
#endif

#ifdef IAR_MSP430
	#include "portmacro.h"
#endif

#ifdef GCC_MSP430
	#include "portmacro.h"
#endif

#ifdef ROWLEY_MSP430
	#include "portmacro.h"
#endif

#ifdef ARM7_LPC21xx_KEIL_RVDS
	#include "portmacro.h"
#endif

#ifdef SAM7_GCC
	#include "portmacro.h"
#endif

#ifdef SAM7_IAR
	#include "portmacro.h"
#endif

#ifdef SAM9XE_IAR
	#include "portmacro.h"
#endif

#ifdef LPC2000_IAR
	#include "portmacro.h"
#endif

#ifdef STR71X_IAR
	#include "portmacro.h"
#endif

#ifdef STR75X_IAR
	#include "portmacro.h"
#endif

#ifdef STR75X_GCC
	#include "portmacro.h"
#endif

#ifdef STR91X_IAR
	#include "portmacro.h"
#endif

#ifdef GCC_H8S
	#include "portmacro.h"
#endif

#ifdef GCC_AT91FR40008
	#include "portmacro.h"
#endif

#ifdef RVDS_ARMCM3_LM3S102
	#include "portmacro.h"
#endif

#ifdef GCC_ARMCM3_LM3S102
	#include "portmacro.h"
#endif

#ifdef GCC_ARMCM3
	#include "portmacro.h"
#endif

#ifdef IAR_ARM_CM3
	#include "portmacro.h"
#endif

#ifdef IAR_ARMCM3_LM
	#include "portmacro.h"
#endif

#ifdef HCS12_CODE_WARRIOR
	#include "portmacro.h"
#endif

#ifdef MICROBLAZE_GCC
	#include "portmacro.h"
#endif

#ifdef TERN_EE
	#include "portmacro.h"
#endif

#ifdef GCC_HCS12
	#include "portmacro.h"
#endif

#ifdef GCC_MCF5235
    #include "portmacro.h"
#endif

#ifdef COLDFIRE_V2_GCC
	#include "portmacro.h"
#endif

#ifdef COLDFIRE_V2_CODEWARRIOR
	#include "portmacro.h"
#endif

#ifdef GCC_PPC405
	#include "portmacro.h"
#endif

#ifdef GCC_PPC440
	#include "portmacro.h"
#endif

#ifdef _16FX_SOFTUNE
	#include "portmacro.h"
#endif

#ifdef BCC_INDUSTRIAL_PC_PORT
	/* A short file name has to be used in place of the normal
	FreeRTOSConfig.h when using the Borland compiler. */
	#include "frconfig.h"
	#include "prtmacro.h"
    typedef void ( __interrupt __far *pxISR )();
#endif

#ifdef BCC_FLASH_LITE_186_PORT
	/* A short file name has to be used in place of the normal
	FreeRTOSConfig.h when using the Borland compiler. */
	#include "frconfig.h"
	#include "prtmacro.h"
    typedef void ( __interrupt __far *pxISR )();
#endif

#ifdef __GNUC__
   #ifdef __AVR32_AVR32A__
	   #include "portmacro.h"
   #endif
#endif

#ifdef __ICCAVR32__
   #ifdef __CORE__
      #if __CORE__ == __AVR32A__
	      #include "portmacro.h"
      #endif
   #endif
#endif

#ifdef __91467D
	#include "portmacro.h"
#endif

#ifdef __96340
	#include "portmacro.h"
#endif


#ifdef __IAR_V850ES_Fx3__
	#include "portmacro.h"
#endif

#ifdef __IAR_V850ES_Jx3__
	#include "portmacro.h"
#endif

#ifdef __IAR_V850ES_Jx3_L__
	#include "portmacro.h"
#endif

#ifdef __IAR_V850ES_Jx2__
	#include "portmacro.h"
#endif

#ifdef __IAR_V850ES_Hx2__
	#include "portmacro.h"
#endif

#ifdef __IAR_78K0R_Kx3__
	#include "portmacro.h"
#endif

#ifdef __IAR_78K0R_Kx3L__
	#include "portmacro.h"
#endif

/* Catch all to ensure portmacro.h is included in the build.  Newer demos
have the path as part of the project options, rather than as relative from
the project location.  If portENTER_CRITICAL() has not been defined then
portmacro.h has not yet been included - as every portmacro.h provides a
portENTER_CRITICAL() definition.  Check the demo application for your demo
to find the path to the correct portmacro.h file. */
#ifndef portENTER_CRITICAL
	#include "portmacro.h"
#endif

#if portBYTE_ALIGNMENT == 8
	#define portBYTE_ALIGNMENT_MASK ( 0x0007 )
#endif

#if portBYTE_ALIGNMENT == 4
	#define portBYTE_ALIGNMENT_MASK	( 0x0003 )
#endif

#if portBYTE_ALIGNMENT == 2
	#define portBYTE_ALIGNMENT_MASK	( 0x0001 )
#endif

#if portBYTE_ALIGNMENT == 1
	#define portBYTE_ALIGNMENT_MASK	( 0x0000 )
#endif

#ifndef portBYTE_ALIGNMENT_MASK
	#error "Invalid portBYTE_ALIGNMENT definition"
#endif

#ifndef portNUM_CONFIGURABLE_REGIONS
	#define portNUM_CONFIGURABLE_REGIONS 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "mpu_wrappers.h"

/*
 * Setup the stack of a new task so it is ready to be placed under the
 * scheduler control.  The registers have to be placed on the stack in
 * the order that the port expects to find them.
 *
 */
#if( portUSING_MPU_WRAPPERS == 1 )
	portSTACK_TYPE *pxPortInitialiseStack( portSTACK_TYPE *pxTopOfStack, pdTASK_CODE pxCode, void *pvParameters, portBASE_TYPE xRunPrivileged ) PRIVILEGED_FUNCTION;
#else
	portSTACK_TYPE *pxPortInitialiseStack( portSTACK_TYPE *pxTopOfStack, pdTASK_CODE pxCode, void *pvParameters ) PRIVILEGED_FUNCTION;
#endif

/*
 * Map to the memory management routines required for the port.
 */
void *pvPortMalloc( size_t xSize ) PRIVILEGED_FUNCTION;
void vPortFree( void *pv ) PRIVILEGED_FUNCTION;
void vPortInitialiseBlocks( void ) PRIVILEGED_FUNCTION;
size_t xPortGetFreeHeapSize( void ) PRIVILEGED_FUNCTION;

/*
 * Setup the hardware ready for the scheduler to take control.  This generally
 * sets up a tick interrupt and sets timers for the correct tick frequency.
 */
portBASE_TYPE xPortStartScheduler( void ) PRIVILEGED_FUNCTION;

/*
 * Undo any hardware/ISR setup that was performed by xPortStartScheduler() so
 * the hardware is left in its original condition after the scheduler stops
 * executing.
 */
void vPortEndScheduler( void ) PRIVILEGED_FUNCTION;

/*
 * The structures and methods of manipulating the MPU are contained within the
 * port layer.
 *
 * Fills the xMPUSettings structure with the memory region information
 * contained in xRegions.
 */
#if( portUSING_MPU_WRAPPERS == 1 )
	struct xMEMORY_REGION;
	void vPortStoreTaskMPUSettings( xMPU_SETTINGS *xMPUSettings, const struct xMEMORY_REGION * const xRegions, portSTACK_TYPE *pxBottomOfStack, unsigned short usStackDepth ) PRIVILEGED_FUNCTION;
#endif

#ifdef __cplusplus
}
#endif

#endif /* PORTABLE_H */

