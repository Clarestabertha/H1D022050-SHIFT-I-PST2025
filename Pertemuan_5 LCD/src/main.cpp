#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D4;
int SCL_pin = D2;
LiquidCrystal_I2C LCD(0x27,16,2);

void setup() {
 Wire.begin(SDA_pin, SCL_pin);
 LCD.init(); 
 LCD.backlight();
 LCD.setCursor(0,0);
 LCD.print("HEY MANIEZZZ");
 LCD.setCursor(0,1);
 LCD.print("08 berapaa say?");
}

void loop() {
  LCD.scrollDisplayLeft();
  delay(200);
}

