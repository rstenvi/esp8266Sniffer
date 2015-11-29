# esp8266Sniffer
First attempt at creating a sniffer with ESP8266 and outputting it to a pcap file on SD card.

Wiring
----------

ESP -> SD card
- 3V  -> 3V/VDD
- GND -> GND/VSS1
- 2   -> CS
- 14  -> (S)CLK
- 12  -> DI/MOSI
- 13  -> DO/MISO

SD Card
-------------

Card must be formatted as FAT32, must probably be reformatted, even if it came
as FAT32.

