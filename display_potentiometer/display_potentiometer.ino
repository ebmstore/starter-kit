#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // Initialize display
  lcd.begin(16,2);
}

void loop()
{
  // Read value from potentiometer
  int readValue = analogRead(A0);
  // Adjust value range
  int adjustedValue = map(readValue,0,1023,0,100);
  // Clear display
  lcd.clear();
  // Move cursor
  lcd.setCursor(0,0);
  // Print potentiometer value
  lcd.print(readValue);
  lcd.setCursor(13,0);
  lcd.print(adjustedValue);
  lcd.print("%");
  // Wait
  delay(100);
}


