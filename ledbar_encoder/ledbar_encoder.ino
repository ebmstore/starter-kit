#include <ClickEncoder.h>
#include <TimerOne.h>

ClickEncoder *encoder;
int16_t last, value;

void timerIsr()
{
  encoder->service();
}

void setup()
{
  // Repeat for 8 times
  for(int pin=2;pin<10;pin++)
  {
    // Configure pin as output
    pinMode(pin,OUTPUT);
    // Set pin LOW
    digitalWrite(pin,LOW);
  }
  // Initialize encoder
  encoder = new ClickEncoder(A1, A0, A2);
  // Initialize Timer1
  Timer1.initialize(1000);
  // Attach timerIsr to Timer1
  Timer1.attachInterrupt(timerIsr);
  last = -1;
}

void loop()
{
  // Get value from encoder
  value += encoder->getValue();
  // Reset if value is over 11
  if(value > 11)
  {
    value = 0;
  }
  
  if(value != last)
  {
    last = value;
    for(int pin=2;pin<10;pin++)
    {
      if(pin<value)
      {
        digitalWrite(pin,HIGH);
      }
      else
      {
        digitalWrite(pin,LOW);
      }
    }
  }
}

