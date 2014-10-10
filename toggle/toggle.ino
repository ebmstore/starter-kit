boolean ledStatus = false;
const int led = 4;
const int button = 3;

void setup()
{
  // Configure button pin as input
  pinMode(button, INPUT);
  // Configure led pin as output
  pinMode(led, OUTPUT);
  // Turn off led
  digitalWrite(led, LOW);
}

void loop()
{
  // If button is pressed
  if(digitalRead(button) == HIGH)
  {
    // If led is on
    if(ledStatus)
    {
      // Mark led as off
      ledStatus = false;
      // Turn off led
      digitalWrite(led, LOW);
    }
    // If led is off
    else
    {
      // Mark led as on
      ledStatus = true;
      // Turn on led
      digitalWrite(led, HIGH);
    }
    // Wait
    delay(200);
  }
}
