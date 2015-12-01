
#include <ESP8266WiFi.h>

#include <SPI.h>
#include <SD.h>

#include "sniffer.h"
#include "pcap.h"
#include "config.h"


#define BAUD_RATE BIT_RATE_9600


void setup() {
  uart_init(BAUD_RATE, BAUD_RATE);
	delay(100);
	uart0_sendStr("Serial connection is up");


	// Can set os_install_putc1 to change which function os_printf calls

	pcap_init("pcap2.txt");
	sniffer_start(6, NULL);
}



void loop() {
  return;
}


