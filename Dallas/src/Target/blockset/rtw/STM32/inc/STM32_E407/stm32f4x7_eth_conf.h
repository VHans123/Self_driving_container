/**
  ******************************************************************************
  * @file    stm32f4x7_eth_conf_template.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    31-July-2013
  * @brief   Configuration file for the STM32F4x7xx Ethernet driver.
  *          This file should be copied to the application folder and renamed to
  *          stm32f4x7_eth_conf.h    
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4x7_ETH_CONF_H
#define __STM32F4x7_ETH_CONF_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

#define SMSC_LAN8710A_PHY

/* Uncomment the line below when using time stamping and/or IPv4 checksum offload */
#define USE_ENHANCED_DMA_DESCRIPTORS

/* Uncomment the line below if you want to use user defined Delay function
   (for precise timing), otherwise default _eth_delay_ function defined within
   the Ethernet driver is used (less precise timing) */
//#define USE_Delay

#ifdef USE_Delay
  #define _eth_delay_    Delay     /* User can provide more timing precise _eth_delay_ function
                                      ex. use Systick with time base of 10 ms (as done in the provided 
                                      STM32F4x7xx demonstrations) */
#else
  extern void ETH_Delay(__IO uint32_t nCount);
  #define _eth_delay_    ETH_Delay /* Default _eth_delay_ function with less precise timing */
#endif

/* Uncomment the line below to allow custom configuration of the Ethernet driver buffers */    
//#define CUSTOM_DRIVER_BUFFERS_CONFIG   

#ifdef  CUSTOM_DRIVER_BUFFERS_CONFIG
/* Redefinition of the Ethernet driver buffers size and count */   
 #define ETH_RX_BUF_SIZE    ETH_MAX_PACKET_SIZE /* buffer size for receive */
 #define ETH_TX_BUF_SIZE    ETH_MAX_PACKET_SIZE /* buffer size for transmit */
 #define ETH_RXBUFNB        20                  /* 20 Rx buffers of size ETH_RX_BUF_SIZE */
 #define ETH_TXBUFNB        5                   /* 5  Tx buffers of size ETH_TX_BUF_SIZE */
#endif


/* PHY configuration section **************************************************/
#ifdef USE_Delay
/* PHY Reset delay */ 
#define PHY_RESET_DELAY    ((uint32_t)0x000000FF)
/* PHY Configuration delay */
#define PHY_CONFIG_DELAY   ((uint32_t)0x00000FFF)
/* Delay when writing to Ethernet registers*/
#define ETH_REG_WRITE_DELAY ((uint32_t)0x00000001)
#else
/* PHY Reset delay */ 
#define PHY_RESET_DELAY    ((uint32_t)0x000FFFFF)
/* PHY Configuration delay */ 
#define PHY_CONFIG_DELAY   ((uint32_t)0x00FFFFFF)
/* Delay when writing to Ethernet registers*/
#define ETH_REG_WRITE_DELAY ((uint32_t)0x0000FFFF)
#endif

/*******************  PHY Extended Registers section : ************************/

/* These values are relatives to DP83848 PHY and change from PHY to another,
   so the user have to update this value depending on the used external PHY */   


#if defined(SMSC_LAN8710A_PHY)
    /* The LAN8710A PHY status register  */
    #define PHY_SR                 ((uint16_t)0x0001) /* PHY status register Offset */
    #define PHY_SPEED_100          ((uint16_t)0x6000) /* PHY Speed mask : Bits 13 and 14 indicate 10 Mbit*/
    #define PHY_FULL_DUPLEX        ((uint16_t)0x5000) /* PHY Duplex mask: Bits 14 or 12 indicate Full d. */
    
   /* The LAN8710A PHY: MII Interrupt Control Register  */
    #define PHY_MIFR               ((uint16_t)0x1d) /* MII Interrupt Source Flag Register */
    #define PHY_MIFR_LINK_FLAG     ((uint16_t)0x0010) /* Interrupt flag on change of link status */
    #define PHY_MIFR_AUTON_FLAG    ((uint16_t)0x0040) /* Interrupt flag when Auto-Negotiate complete */
    #define PHY_MIFR_ENERGY_FLAG   ((uint16_t)0x0080) /* Interrupt lfag on change of Energy status */

   /* The LAN8710A PHY: Mode Control & Status Register  */
    #define PHY_MCSR               ((uint16_t)0x11) /* Mode Control & Status register Register */
    #define PHY_MCSR_ALTINT        ((uint16_t)0x20) /* Alternate Interrupt Mode : Bit 6 */
    
    /* The LAN8710A PHY: MII Interrupt Status and Misc. Control Register */
    #define PHY_MIMR               ((uint16_t)0x1e) /* MII Interrupt Status and Misc. Control Register */
    #define PHY_MIMR_LINK_INT_EN   ((uint16_t)0x0010) /* Enable Interrupt on change of link status */
    #define PHY_MIMR_AUTON_INT_EN  ((uint16_t)0x0040) /* Enable Interrupt when Auto-negotiate complete */
    #define PHY_MIMR_ENERGY_INT_EN ((uint16_t)0x0080) /* Enable Interrupt on change of Energy status */

#else
    #error "Undefined Ethernet PHY device"
#endif

   /* Note : Common PHY registers are defined in stm32f4x7_eth.h file */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4x7_ETH_CONF_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
