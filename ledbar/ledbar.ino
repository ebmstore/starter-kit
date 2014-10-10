boolean state = LOW;

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
}

void loop()
{
  if(state == HIGH)
  {
    state = LOW;
  }
  else
  {
    state = HIGH;
  }
  // Repeat for 8 times
  for(int pin=2;pin<10;pin++)
  {
    // Set pin to state
    digitalWrite(pin,state);
    // Wait
    delay(100);
  }
}

