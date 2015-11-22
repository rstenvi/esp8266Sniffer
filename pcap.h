
#ifndef __PCAP_H
#define __PCAP_H

#include "sniffer.h"


typedef struct	{
	uint32 epoch;
	uint32 micro;
	uint32 lenData;
	uint32 lenWire;
} __attribute__((packed)) pcap_pkt_header;

void pcap_init(const char* fname);
void pcap_close();
void pcap_write_pkt(const uint8* data, uint16 len, bool flush);


#endif

