#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>

#define ONE_WIRE_BUS 8
#define ALARM_PIN 13
#define MAX_TEMPERATURE 30.00

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

Servo myServo;

void setup()
{
  // Initialize servo
  myServo.attach(9);
  // Initialize temperature sensor
  sensor.begin();
}

void loop()
{
  // Read temperature from servo
  sensor.requestTemperatures();
  // (int) is used to get only the integer part of value
  int temperature =  (int) sensor.getTempCByIndex(0);
  // Adjust value, from temperature range to servo angle
  int angle = map(temperature, -55, 120, 0, 179);
  // Write value to servo
  myServo.write(angle);
  // Wait
  delay(100);
}

