#define STEP_PIN   D5
#define DIR_PIN   D6
#define LED_PIN   D2
#define BlueLED_PIN D4
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <SimplePortal.h>
#include <EEPROM.h>

char Myssid[32];
char Mypass[64];
const char* host = "narodmon.ru";
const int httpPort = 8283;

//uint16_t - 0..65к. uint8_t - 0..256
bool MyWiFiEnable;
int8_t i = 0;
int8_t ModBusErr = 0; //Количество НЕпринятых байт по ModBus
int32_t STEP_DELAY=200;  // микросекунды между шагами (скорость) //180 работает. 170- нет.
int32_t currentPos = 0,targetPos = 0, go_home=0, homed = 0;       // текущее и желаемая положение стрелки

float k = 0.00005;     // коэффициент фильтра: 0.0-1.0
float CO2_PV_Filter = 0;  // переменная фильтра

uint8_t ModbusReadH, ModbusReadL; //данные прочитанные с датчика
uint16_t CO2_PV;   // поменять местами и собрать обратно uint16

uint32_t myTimer1, myTimer2, myTimer3, myTimer4,myTimer5,myTimer6,myTimer7,myTimer8;// Таймера. 

SoftwareSerial mySerial(D7, D1);  // всегда в порядке (RX, TX)
byte cmd[] = { 0xFE, 0x04, 0x00, 0x03, 0x00, 0x01, 0xD5, 0xC5 };  //посылка для запроса ModBus
