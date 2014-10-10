#include <Servo.h>

Servo myServo;

void setup()
{
  // Initialize servo
  myServo.attach(9); 
}

void loop()
{
  // Read value from potentiometer
  int value = analogRead(A0);
  // Adjust value range
  int adjustedValue = map(value, 0, 1023, 0, 179);
  // Write value to servo
  myServo.write(adjustedValue);
  // Wait
  delay(15);
}
