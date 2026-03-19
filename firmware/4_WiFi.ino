void MyWiFi() {

if (MyWiFiEnable==1) {
digitalWrite(BlueLED_PIN, HIGH);

 myTimer8 = millis();
Serial.println();
  Serial.print("Connecting to WiFi: ");
    WiFi.begin(Myssid, Mypass);
    while (WiFi.status() != WL_CONNECTED && millis() - myTimer8 < 15000) {
    delay(1000);
    Serial.print("♥");
  }

  Serial.println();                       // отправляем в Serial данные о подключении
  Serial.print("IP address: ");  
  Serial.print(WiFi.localIP());
  Serial.print("    ||   MAC address: ");
  Serial.println(WiFi.macAddress());
    WiFiClient client;   // Use WiFiClient class to create TCP connections
  
  if (!client.connect(host, httpPort)) {
    Serial.println("Connection failed");
     return;
  }
  
  client.print("#");   // отправляем данные  
  client.print(WiFi.macAddress()); // отправляем МАС нашей ESP8266
  client.print("#VimoreneLumi"); // название устройства
  client.println();
        
    client.print("#CO2#");  //Значение СО2
    client.println(CO2_PV); 
    client.println("##");
    client.stop();
  Serial.println("Closing connection");
  WiFi.disconnect(); // отключаемся от сети
 Serial.println("Disconnect WiFi.\r\n");
}

}





