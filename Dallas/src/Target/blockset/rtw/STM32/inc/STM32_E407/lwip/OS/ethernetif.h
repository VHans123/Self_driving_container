#ifndef __ETHERNETIF_H__
#define __ETHERNETIF_H__


#include "lwip/err.h"
#include "lwip/netif.h"

/* MAC ADDRESS: MAC_ADDR0:MAC_ADDR1:MAC_ADDR2:MAC_ADDR3:MAC_ADDR4:MAC_ADDR5 */
#define MAC_ADDR0   0x00
#define MAC_ADDR1   0xbd
#define MAC_ADDR2   0x33
#define MAC_ADDR3   0x06
#define MAC_ADDR4   0x68
#define MAC_ADDR5   0x22



err_t ethernetif_init(struct netif *netif);



#endif 
