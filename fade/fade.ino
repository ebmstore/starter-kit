const int led = 3;
const int potentiometer = A0;

void setup()
{
}

void loop()
{
  // Read value from potentiometer
  int readValue = analogRead(potentiometer);
  // Adjust value range
  int fadeValue = map(readValue,0,1024,0,255);
  // Set led brightness
  analogWrite(led,fadeValue);
  // Wait
  delay(1);
}


