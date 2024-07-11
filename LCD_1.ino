#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27,16,2);

void setup() {

  LCD.begin(16,2);
  LCD.noBacklight();
  
}

void loop() {
  LCD.setCursor(3,0);
  LCD.print("Loading...");
  delay(1000);

  /*LCD.setCursor(6,1);
  LCD.print("Shirodhara");
  delay(1000);*/

}
