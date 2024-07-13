#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
//main code of setup
  LCD.begin(16,2);
 // LCD.backlight();
  
}

void loop() {
  //Display words
  LCD.setCursor(12,0);
  LCD.print("Loading...");
  
//moving display left side
  for(int i=0;i<22;i++){
    LCD.scrollDisplayLeft();
    delay(300);
  }

//moving display right side
  for(int i=0;i<27;i++){
    LCD.scrollDisplayRight();
    delay(300);
  }
}
