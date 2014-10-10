#include <LiquidCrystal.h>

#define RELAY 8
#define LDR A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // Configure relay pin as outpu
  pinMode(RELAY,OUTPUT);
  // Initialize LCD  
  lcd.begin(16,2);
}

void loop()
{
  // Read value from LDR
  int readValue = analogRead(LDR);
  // Change value range
  int adjustedValue = map(readValue,0,1023,0,100);
  // Clear LCD screen
  lcd.clear();
  // Move cursor
  lcd.setCursor(0,1);
  // Print value
  lcd.print(adjustedValue);
  lcd.print("%");
  if(adjustedValue<=10)
  {
    // Turn on relay
    digitalWrite(RELAY,HIGH);
  }
  else
  {
    // Turn off relay
    digitalWrite(RELAY,LOW);
  }
  // Wait
  delay(300);
}

