void MyLed() {

 static int led_mode=1;
 static bool led_button=0, led_button_old=0;

if (millis() - myTimer5 > 50) {   //myTimer5 
    myTimer5 = millis();  //сброс таймера
    
    if  (analogRead(A0)<500 ) {led_button=1; } else {led_button=0; };
    if  ( led_button_old==0 && led_button==1) {led_mode++;}
            led_button_old = led_button;

    if (led_mode==0) {digitalWrite(LED_PIN, LOW);}
    if (led_mode==1) {analogWrite(LED_PIN,15);}
    if (led_mode==2) {analogWrite(LED_PIN,80);}
    if (led_mode==3) {digitalWrite(LED_PIN, HIGH);}
    if (led_mode>3) {led_mode=0;}
  }
}
