#ifndef SBDEF
  #define SBDEF
  #include <stdio.h>
  #include "config.h"
  #include "AVR035.h"

#define EEPROM_VERSION 5
#define SBNG_VERSION_MAJOR 2
#define SBNG_VERSION_MINOR 21

//BUILD TARGET
//REV 3 - S3S Atmega1284P, ingen ekstern eeprom
//REV 50 - Vandbot R1 - 1284P, MCP23008, HW watchdog
#define SBNG_TARGET 3

//#define WEB_DEBUG
//#define HTTPD_DEBUG
//#define OW_DEBUG     //Enable printf debugs from onewire

#define BUFFER_SIZE 1600

#define MAXSENSORS 50 
#define SENSORSIZE 11
#define NUMALARMS 8

//Sensor array
enum SensorData { FAMILY, ID1, ID2, ID3, ID4, ID5, ID6, CRC, VALUE1, VALUE2, SIGN };

uint8_t sensorValues[MAXSENSORS*SENSORSIZE];
uint8_t *sensorScan; //peger p� tempbuf
char tempbuf[4096]; //Used for various string manipulation

//8ADC+4digital for at der er plads til de digitale hvis de er input
volatile uint32_t simpleSensorValues[100];
uint8_t simpleSensorTypes[100];
uint8_t simpleSensorDebounce[100];

//extern uint16_t tick; //1tick=1ms
//extern uint16_t tickS; //1tick=1s

#define TYPE_DIGOUT 0
#define TYPE_ADC 1
#define TYPE_DIGIN 2
#define TYPE_COUNTER 3
#define TYPE_DHT22 4
#define TYPE_DHT11 5

#endif
