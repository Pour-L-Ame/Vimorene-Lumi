void setup() {

pinMode(STEP_PIN,  OUTPUT);
pinMode(DIR_PIN,  OUTPUT);
pinMode(LED_PIN,  OUTPUT);
pinMode(BlueLED_PIN,  OUTPUT);

Serial.begin(9600);
mySerial.begin(9600);   // программный UART на пинах 2 и 3
mySerial.setTimeout(200);
EEPROM.begin(128);
delay(2000);  //Задержка перед включением
  Serial.println(" "); 
  Serial.println("======================== Start ESP8266 ======================="); 

if  (analogRead(A0)<500 ){ //режим настройки WiFi
for (int8_t i2 = 0; i2 < 4; i2++) {
  digitalWrite(LED_PIN, LOW);
  delay(400);  //Задержка перед включением
  digitalWrite(LED_PIN, HIGH);
  delay(80);  //Задержка перед включением
}

Serial.println(">>Вход в режим настроек WiFi"); 
portalRun(180000);  // запустить с таймаутом 180с
  if (portalStatus() == SP_SUBMIT) {
    writeString(0,(portalCfg.SSID));
    writeString(32, (portalCfg.pass));
    Serial.println(">>Успешное сохранение настроек WiFi"); 
    // забираем логин-пароль и пишем в eeeprom
  }
}  //конец настройки WiFi

  readString(0, Myssid, sizeof(Myssid));
  readString(32, Mypass, sizeof(Mypass));
  
 Serial.print("Myssid: ");  
Serial.print(Myssid);
 Serial.print("    Mypass: ");  
Serial.println(Mypass);

if (strlen(Mypass)<8) {
      MyWiFiEnable=0;
    Serial.println(">> WiFi Disable ");
    digitalWrite(BlueLED_PIN, HIGH);
     } else {
  MyWiFiEnable=1; 
  Serial.println(">> WiFi Enable "); 
  digitalWrite(BlueLED_PIN, LOW);
    }


}