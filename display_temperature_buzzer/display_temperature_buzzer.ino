#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

#define ONE_WIRE_BUS 8
#define ALARM_PIN 13
#define MAX_TEMPERATURE 30.00

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // Configure alarm pin as output
  pinMode(ALARM_PIN,OUTPUT);
  // Initialize display
  lcd.begin(16,2);
  // Initialize temperature sensor
  sensor.begin();
}

void loop()
{
  // Read temperature
  sensor.requestTemperatures();
  float temperature =  sensor.getTempCByIndex(0);
  if(temperature>=MAX_TEMPERATURE)
  {
    // Alarm on
    digitalWrite(ALARM_PIN,HIGH);
  }
  else
  {
    // Alarm off
    digitalWrite(ALARM_PIN,LOW);
  } 
  // Move cursor
  lcd.setCursor(0,0);
  // Print temperature
  lcd.print(temperature);
  // Wait
  delay(100);
}
