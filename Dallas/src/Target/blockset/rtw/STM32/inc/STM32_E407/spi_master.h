/************************************************************************************//**
* \file         spi_master.h
* \brief        SPI master driver header file.
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
#ifndef SPI_MASTER_H
#define SPI_MASTER_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include <stdint.h>                                   /* ANSI C types                  */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* SPI peripheral identifiers. note that these are used as array indexers so make
 * sure the first one has value 0 and the others are increments.
 */
#define SPI_MASTER_CHANNEL1_PA5_PA6_PB5    (0)        /* SPI channel 1 - D13/D12/D11   */
#define SPI_MASTER_CHANNEL2_PB10_PC2_PC3   (1)        /* SPI channel 2 - UEXT 9/7/8    */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Configuration values for the communication speed. It's basically a prescaler
 *         value that is scaled of the APB1 (PCLK1) clock, which is 42Mhz for this system.
 */
typedef enum
{
  COM_SPEED_21000_KHZ,
  COM_SPEED_10500_KHZ,
  COM_SPEED_5250_KHZ,
  COM_SPEED_2625_KHZ,
  COM_SPEED_1313_KHZ,
  COM_SPEED_656_KHZ,
  COM_SPEED_328_KHZ,
  COM_SPEED_164_KHZ
} tSpiComSpeedCfg;


/** \brief Configuration values for the clock polarity. */
typedef enum
{
  POLARITY_LOW,                                 /**< CLK idles low                     */
  POLARITY_HIGH,                                /**< CLK idles high                    */
} tSpiClkPolarityCfg;

/** \brief Configuration values for the clock phase. This determines when a bit is
 *         sampled. A clock period has 2 edges, a rising and a falling one. The order
 *         of the edges depends on the configuration of the clock polatiry. With thi
 *         configurable it is defined on which edge a bit is sampled, either the first
 *         one or the second.
 */
typedef enum
{
  PHASE_1ST_EDGE,                               /**< Sample bit on first CLK edge      */
  PHASE_2ND_EDGE,                               /**< Sample bit on the second CLK edge */
} tSpiClkPhaseCfg;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void    SpiMasterInit(uint8_t channel, tSpiComSpeedCfg speed, tSpiClkPolarityCfg polarity, tSpiClkPhaseCfg phase);
void    SpiMasterTransmit(uint8_t channel, uint8_t data);
uint8_t SpiMasterReceive(uint8_t channel);
void    SpiMasterSetSlaveSelect(uint8_t digout_pinID, uint8_t enable);
void    SpiMasterWait(uint32_t cycles);


#endif /* SPI_MASTER_H */
/********************************* end of spi_master.h *********************************/


