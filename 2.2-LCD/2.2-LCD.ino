#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

const int LCD_COLUMNS = 16; 
const int LCD_ROWS = 2; 
const int LCD_ADDRESS = 0x27; 

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  Serial.begin(9600);

  Wire.begin();

  lcd.init();

  lcd.backlight();
}

void loop() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Hello,");
  lcd.setCursor(0, 1);
  lcd.print("World!");

  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("LiquidCrystal");
  lcd.setCursor(0, 1);
  lcd.print("Display mit I2C");

  delay(2000);
}