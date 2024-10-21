#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//******For temperature sensor********
#include <OneWire.h>
#include <DallasTemperature.h>

//*******For LCD display**************
LiquidCrystal_I2C lcd(0x27, 16, 2);

//************Define pin for taking data of temperature************************
#define SENSOR_PIN 2                   // D2 pin connected to DS18B20 sensors
OneWire oneWire(SENSOR_PIN);           // Setup a OneWire instance
DallasTemperature sensors(&oneWire);   // Pass OneWire to DallasTemperature library

float tempC1, tempC2;                  // Temperatures for two sensors
float tempF1, tempF2;                  // Temperatures for two sensors in Fahrenheit

//******************get icon of degree*****************************************
byte degree[]={
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup() {
  Serial.begin(9600);         // Initialize the serial monitor
  sensors.begin();            // Initialize the temperature sensors

  lcd.init();                 // Initialize the LCD
  lcd.backlight();            // Turn on the backlight
  lcd.createChar(0,degree);
  lcd.home();

  lcd.setCursor(0, 0);
  lcd.print("Temperature Sensor_1:");   // Display "Temp Sensor 1" on LCD line 1
  lcd.setCursor(0, 1);
  lcd.print("Temperature Sensor_2:");   // Display "Temp Sensor 2" on LCD line 2

   
}

void loop() {
  sensors.requestTemperatures();       // Request temperature from all sensors

  // Get temperature for first sensor (index 0)
  tempC1 = sensors.getTempCByIndex(0);     
  tempF1 = sensors.toFahrenheit(tempC1); 

  // Get temperature for second sensor (index 1)
  tempC2 = sensors.getTempCByIndex(1);    
  tempF2 = sensors.toFahrenheit(tempC2); 

  //********************Display on LCD*****************************
  
  lcd.setCursor(22, 0);            // Set cursor to line 1, column 13
  lcd.print(tempC1);               // Print temperature for sensor 1
  lcd.write(0);
  lcd.print("C");

  lcd.setCursor(22, 1);            // Set cursor to line 2, column 13
  lcd.print(tempC2);               // Print temperature for sensor 2
  lcd.write(0);
  lcd.print("C");

  // **************Display values of temperature in serial monitor***********************
  Serial.print("Sensor 1: ");
  Serial.print(tempC1);        // Print the temperature in Celsius for sensor 1
  Serial.println("C");
  Serial.print(tempF1);        // Print the temperature in Fahrenheit for sensor 1
  Serial.println("F");

  Serial.print("Sensor 2: ");
  Serial.print(tempC2);        // Print the temperature in Celsius for sensor 2
  Serial.println("C");
  Serial.print(tempF2);        // Print the temperature in Fahrenheit for sensor 2
  Serial.println("F");
//*****************moving display left side*******************************
  for(int i=0;i<10;i++){
    lcd.scrollDisplayLeft();
    delay(200);
  }

  delay(300);  // Delay between readings
}


