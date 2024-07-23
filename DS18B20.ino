//******For temperature sensor********
#include <OneWire.h>
#include <DallasTemperature.h>
//*******For LCD display**************
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//************Define pin for taking data of temperature************************
#define SENSOR 2                      // D2 pin connected to DS18B20 sensor
OneWire oneWire(SENSOR);              //Setup a onewire instance
DallasTemperature sensors(&oneWire);  //Pass onewire to DallasTemperature library

float Celsius ;                       //Temperature in Celsius
float Fahrenheit ;                    //Temperature in Fahrenheit

void setup() {
  Serial.begin(9600);   //Initialize the serial to communicate with the serial monitor
  sensors.begin();      //Initialize the sensor

  lcd.begin(16, 2);
  //*****************moving display left side*******************************
 /* for(int i=0;i<12;i++){
    lcd.scrollDisplayLeft();
    delay(300);
  }*/
  lcd.setCursor(1,0);
  lcd.print("Temperature:-"); // Display "Temperature:-" in LCD 
  
}

void loop() {
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);         //Temperature in celsius
  Fahrenheit = sensors.toFahrenheit(Celsius);   //Convert Celsius to Fahrenheit

//********************Display LCD*****************************
 lcd.setCursor(1, 1);
  lcd.print(Celsius);
  lcd.print(" Celsius");
 /*lcd.setCursor(1, 2);
  lcd.print(Fahrenheit);
  lcd.println(" Fahrenheit "); */

// **************Display values of tempreature in serial monitor***********************
  Serial.print("Temperature:");
  Serial.print("\t");
  Serial.print(Celsius);        //Print the temperature in Celsius
  Serial.print("C");
  Serial.print("\n");
  
  Serial.print(Fahrenheit);     //Print the temperature in Fahrenheit
  Serial.print("F");

 delay(100);

}
