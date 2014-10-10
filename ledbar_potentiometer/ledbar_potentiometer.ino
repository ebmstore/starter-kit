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
  // Read value from potentiometer
  int readValue = analogRead(A0);
  // Adjust value range
  int adjustedValue = map(readValue,0,1023,1,11);
  for(int pin=2;pin<10;pin++)
  {
    if(pin<adjustedValue)
    {
      digitalWrite(pin,HIGH);
    }
    else
    {
      digitalWrite(pin,LOW);
    }
  }
}

