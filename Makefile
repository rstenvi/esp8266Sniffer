
PORT=/dev/ttyACM4
BOARD=esp8266:esp8266:huzzah

INO=esp8266Sniffer.ino

verify: ${INO}
	arduino --verify ${INO} --board ${BOARD}
