void ModBus() {
 static int8_t step;

switch (step) {
      case 0:
        mySerial.write(cmd, 8); 
        break;

      case 1:
          ModbusReadH=0;  ModbusReadL=0;
          if (mySerial.available()) {               //Если приняты данные по
                for ( i=0; i < 10; i++){
                if (i<=2) {mySerial.read();};
                if (i==3) {ModbusReadH=mySerial.read();};
                if (i==4) {ModbusReadL=mySerial.read();};
                if (i>=5) {mySerial.read();};
                }    
               }
          CO2_PV = (uint16_t)(ModbusReadH << 8) + ModbusReadL; 

           if (CO2_PV==0) {ModBusErr++;} else {ModBusErr=0;} //если не получил данные от датчика, то инкремент счетчика ошибок. 
           if (ModBusErr>5){ModBusErr=5;CO2_PV=2230;}

            Serial.print("Значение CO2: "); 
            Serial.print(CO2_PV);
            Serial.print("ppm   ||   Отфильтрованное значение CO2: "); 
            Serial.print(CO2_PV_Filter);
            Serial.print("ppm   ||   Ошибок опроса датчика: ");
            Serial.println(ModBusErr);
        break;
    }

    step++;
    if (step > 1) {step = 0;}  // зацикливание 0→1→2→0

}