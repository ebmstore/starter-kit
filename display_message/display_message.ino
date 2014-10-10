#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // Initialize LCD
  lcd.begin(16,2);
  // Move cursor
  lcd.setCursor(2,0);
  // Print message
  lcd.print("E.B.M. STORE");
  // Move cursor (next row)
  lcd.setCursor(2,1);
  lcd.print("NEGOZIO EBAY");
}

void loop()
{
  // Do nothing
}
