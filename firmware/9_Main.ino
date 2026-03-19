void loop() 
{
      StepMotor(); // плавное движение стрелки
      MyLed(); // Управление подсветкой

      if (millis() - myTimer7 >= 300000) {   // Передача показаний по Wifi
      myTimer7 = millis();
      MyWiFi();
      }

      if (millis() - myTimer1 >= 2000 ) {   //Запрос Modbus 1 раз в 4 сек  
      myTimer1 = millis();  //сброс таймера
      ModBus();
      } 

       if (millis() - myTimer2 > 1) {  //Фильтр
       if (homed==2) {  
       myTimer2 = millis();  //сброс таймера
          CO2_PV_Filter += (CO2_PV - CO2_PV_Filter) * k;
              targetPos=((CO2_PV_Filter-300)*189); //задание не сервомотор *100
              targetPos=targetPos/100;
        }
        }  // конец фильтра
                              
      if (millis() - myTimer4 > 604800000) { //переодическая калибровка
          myTimer4 = millis();  //сброс таймера
          homed=0;
     }

} // конец loop
