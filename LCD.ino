#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init(); // initialize LCD
  // print a message on the LCD

  lcd.backlight();
  
}

void loop() {
  lcd.setCursor(0,0);  //sets the position of the cursor on lcd screen before printing text or numbers
  lcd.print("Hello Rinchen");
  lcd.setCursor(1,1);
  lcd.print("Mobile Robotics");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Bye Rinchen");
  lcd.setCursor(1,1);
  lcd.print("digital");
  delay(2000);
  lcd.clear();
  // put your main code here, to run repeatedly:

}
