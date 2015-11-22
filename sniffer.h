
#ifndef __SNIFFER_H
#define __SNIFFER_H

#include "config.h"

/**
 * This is the start of the data we get when sniffing.
 * Total of 96b = 12B
 */
typedef struct	{
	int8 rssi;	// Signal intensity
	unsigned rate:4;
	unsigned is_group:1;
	unsigned unused:1;
	unsigned sig_mode:2;
	unsigned legacy_length:12;
	unsigned damatch0:1;
	unsigned damatch1:1;
	unsigned bssidmatch0:1;
	unsigned bssidmatch1:1;
	unsigned MCS:7;
	unsigned CWB:1;
	unsigned HT_length:16;
	unsigned Smoothing:1;
	unsigned Not_Sounding:1;
	unsigned unused2:1;
	unsigned Aggregation:1;
	unsigned STBC:2;
	unsigned FEC_CODING:1;
	unsigned SGI:1;
	unsigned rxend_state:8;
	unsigned ampdu_cnt:8;
	unsigned channel:4;
	unsigned unused3:12;
} __attribute__((packed)) RxControl;

typedef struct	{
	uint16 len;
	uint16 seq;
	uint8 addr3[6];
} __attribute__((packed)) LenSeq;

/**
 * What we get when it is a data packet.
 */
typedef struct	{
	RxControl rx;
	uint8 buf[36];
	uint16 cnt;
	LenSeq lenseq[1];
} __attribute__((packed)) sniffer_buf;

/**
 * Management packet, name is from SDK.
 */
typedef struct	{
	RxControl rx;
	uint8 buf[112];
	uint16 cnt;
	uint16 len;
} __attribute__((packed)) sniffer_buf2;




bool sniffer_start(uint8 channel, const uint8* mac_filter);
bool sniffer_stop();



#endif	// File

