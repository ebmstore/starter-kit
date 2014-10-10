#include <ClickEncoder.h>
#include <TimerOne.h>

#define RED_PIN   3
#define GREEN_PIN 5
#define BLUE_PIN  6

#define RED    8
#define GREEN  9
#define BLUE  10

int currentLed = RED;

ClickEncoder *encoder;
int16_t last, value;

void timerIsr()
{
  encoder->service();
}

void setup()
{
  // Initialize encoder
  encoder = new ClickEncoder(A1, A0, A2);
  // Initialize Timer1
  Timer1.initialize(1000);
  // Attach timerIsr to Timer1
  Timer1.attachInterrupt(timerIsr);
  last = -1;
  // Set led pins as output
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  // Turn on first led
  digitalWrite(currentLed, HIGH);
}

void loop()
{
  // Get value from encoder
  value += encoder->getValue();
  // Reset if value is out of range
  if(value > 255 || value < 0)
    {
      value = 0;
    }
  if(value != last)
  {
    last = value;
    // Set brightness on right RGB led channel
    switch(currentLed)
      {
      case RED:
	analogWrite(RED_PIN, value);
	break;
      case GREEN:
	analogWrite(GREEN_PIN, value);
	break;
      case BLUE:
	analogWrite(BLUE_PIN, value);
	break;
      }
  }
  
  // Get encoder button state
  ClickEncoder::Button b = encoder->getButton();
  if(b != ClickEncoder::Open)
    {
      // If button is clicked
      if(b == ClickEncoder::Clicked)
      {
	
        if(currentLed < BLUE)
        {
           currentLed++;
	}
        else
        {
	   currentLed = RED;
	}
	// Reset all leds
	for(int i = RED; i <= BLUE; i++)
	{
	  digitalWrite(i, LOW);
	}
	// Reset value and last read
	value = 0;
	last = 0;
	// Turn on current led
	digitalWrite(currentLed, HIGH);
      }
    }
}
