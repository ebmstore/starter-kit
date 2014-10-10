#include <Servo.h>
#include <Encoder.h>

Servo myServo;
//Initialize encoder
Encoder myEncoder(5, 6);

int16_t last, value;

void setup()
{
  // Initialize servo
  myServo.attach(9); 
  last = -99;
}

void loop()
{
  // Read data from encoder
  value = myEncoder.read();
  // Reset if value is out of range
  if(value > 179 || value < 0)
  {
    value = 0;
    myEncoder.write(value);
  }
 
  if(value != last)
  {
   last = value;
   // Disable interrupts
   noInterrupts();
   // Write value to servo
   myServo.write(value);
   // Wait
   delay(15);
   // Enable interrupts
   interrupts();
  }
}
