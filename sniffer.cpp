


#include "sniffer.h"
#include "pcap.h"

static void ICACHE_FLASH_ATTR promisc_cb(uint8 *buf, uint16 len);

bool sniffer_start(uint8 channel, const uint8* mac_filter)	{
	wifi_station_disconnect();
	wifi_set_promiscuous_rx_cb(promisc_cb);
	wifi_promiscuous_enable(1);
	wifi_set_channel(channel);

	// Must also check and maybe set mac filter here
	return true;
}

inline bool sniffer_stop()	{
	wifi_promiscuous_enable(0);
	return true;
}


static void ICACHE_FLASH_ATTR promisc_cb(uint8 *buf, uint16 len)	{
	// Not reliable and doesn't show MAC addresses, so unusable
	if(len == 12)	return;

	if(len == 128)  {
    	pcap_write_pkt(buf, 128, true);
	}

	if( (len % 10) == 0)	{
		// Data packet
	}
}


void channel_hop(void* arg)	{

}

