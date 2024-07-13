#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
//main code of setup
  LCD.begin(16,2);
  LCD.backlight();
  
}

void loop() {
  //Display words
  LCD.setCursor(3,0);
  LCD.print("Loading...");
  delay(1000);

// Blinking dispaly
 LCD.noDisplay();
  delay(500);
  LCD.display();
  delay(500);
}
