

#include "pcap.h"

#include <SPI.h>
#include <SD.h>

File pcapFile;


// The entire global header
#define PCAP_GLOBAL_HEADER "\xd4\xc3\xb2\xa1\x02\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\x00\x00\x69\x00\x00\x00"


void pcap_init(const char* fname)	{
  if (!SD.begin(2)) {
    uart0_sendStr("SD card initialization failed!\n");
    return;
  }
	pcapFile = SD.open(fname, FILE_WRITE);
  if(!pcapFile) {
    uart0_sendStr("Unable to open PCAP file\n");
    return;
  }
	uint16 written = pcapFile.write(PCAP_GLOBAL_HEADER, 24);
  if(written != 24) {
    os_printf("Wrote %d bytes instead of 24\n", written);
  }
	pcapFile.flush();
}

void pcap_close()	{
	// This will also flush
	pcapFile.close();
}



// Write a single packet
void pcap_write_pkt(const uint8* data, uint16 len, bool flush)	{
  pcap_pkt_header header;

  // system_get_time() can be used here
  header.epoch = 0;
  header.micro = 0;
  if(len == 128)  {
    sniffer_buf2* pkt = (sniffer_buf2*)data;
    header.lenData = pkt->len;
    header.lenWire = len;
    pcapFile.write((uint8*)&header, sizeof(pcap_pkt_header));
    pcapFile.write(pkt->buf, pkt->len);
  	if(flush)	pcapFile.flush();
  }
}



