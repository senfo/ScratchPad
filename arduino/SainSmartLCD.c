/*
  Temperature sensor with SainSmart LCD
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 // I2C address of PCF8574A
#define TEMP_PIN A0

// Set the LCD address to 0x27 for a 16 chars and 4 line display
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 4);

void setup() {  
  lcd.begin();
  lcd.backlight();
}

void loop() {
  int value = analogRead(TEMP_PIN);
  float celsius = ((value * 5.0) / 1024.0 - 0.5) * 100;
  float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  String temperatureCelsius = String(celsius);
  String temperatureFahrenheit = String(fahrenheit);

  lcd.clear();
  lcd.print(temperatureCelsius);
  lcd.print(" degrees C");
  lcd.setCursor(0, 1);
  lcd.print(temperatureFahrenheit);
  lcd.print(" degrees F");

  delay(5000);
}
