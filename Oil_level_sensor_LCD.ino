#include <LiquidCrystal_I2C.h>
#include <Wire.h>



#define trig 2
#define echo 4
#define buzzer 3
//*******For LCD display**************
LiquidCrystal_I2C lcd(0x27, 16, 2);
int sound = 250;
void setup() {
//*****main code of setup*******
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 Serial.begin(9600);
 pinMode(buzzer, OUTPUT);
  
}

void loop() {

  lcd.init();                 // Initialize the LCD
  lcd.backlight();            // Turn on the backligh
  
  lcd.setCursor(0, 0);
  lcd.print("Oil Level: ");   // Display "Temp Sensor 1" on LCD line 1

  //****for triggering of ultrasonic sensor****
 digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);

 long t = pulseIn(echo,HIGH);

 long inches = t/74/2; //For measuring value of inch
 long cm = t/29/2;      //For measuring value of centimeter

 Serial.print(inches);
 Serial.print("in \t");
 Serial.print(cm);
 Serial.println("cm\t");
 delay(100);

 lcd.setCursor(11, 0);            // Set cursor to line 2, column 13
 lcd.print(cm);               // Print ultrasonic sensor
 lcd.setCursor(14, 0);   
 lcd.print("cm");

 if (cm == 4) {
   sound = 80;
   tone(buzzer, sound);
}
 else if ( cm > 14 || cm <= 0 ){

      noTone(buzzer);

 }

 else {
     noTone(buzzer);

}

}
