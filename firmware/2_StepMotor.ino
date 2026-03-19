void StepMotor() {  // функция пошагового движения стрелки

 if (micros() - myTimer3 >= STEP_DELAY) {   //myTimer3 
   myTimer3 = micros();
  
   if (homed==2 ){   //Если калибровка пройдена
    if ((currentPos < targetPos)&& (currentPos<3680)) {
      digitalWrite(DIR_PIN, HIGH);
      digitalWrite(STEP_PIN, HIGH);
      digitalWrite(STEP_PIN, LOW);
      currentPos++;
    } 
    else if ((currentPos > targetPos)&& (currentPos>1)) {
      digitalWrite(DIR_PIN, LOW);
      digitalWrite(STEP_PIN, HIGH);
      digitalWrite(STEP_PIN, LOW);
      currentPos--;
    }
 }

     if  (homed==0) {        //если калибровки дома не было
    STEP_DELAY=200;
       digitalWrite(DIR_PIN, HIGH);
      digitalWrite(STEP_PIN, HIGH);
      digitalWrite(STEP_PIN, LOW);
      go_home++;
    if  (go_home>4000) {homed=1; go_home=0;}
 }  //конец если калибровки дома не было

 if  (homed==1) {        //если калибровки дома не было
    STEP_DELAY=250;
      digitalWrite(DIR_PIN, LOW);
      digitalWrite(STEP_PIN, HIGH);
      digitalWrite(STEP_PIN, LOW);
       go_home++;
     if  (go_home>3000)  {STEP_DELAY=1000;}
    if  (go_home>4100) {homed=2;  go_home=0; currentPos=0; targetPos=0; STEP_DELAY=2000;  Serial.println(">>Завершение калибровки стрелки");  }
 }  //конец если калибровки дома не было

  }//коенц таймера
}