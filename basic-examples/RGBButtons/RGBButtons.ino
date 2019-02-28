/*
Adafruit Arduino - Lesson 7. RGB Fader
*/

int blueLEDPin = 11;
int redLEDPin = 10;
int yellowLEDPin = 9;
int greenLEDPin = 6;

int blueSwitchPin = 7;
int redSwitchPin = 3;
int yellowSwitchPin = 5;
int greenSwitchPin = 4;

int red = 0;
int blue = 0;
int green = 0;
int yellow = 0;

void setup()
{
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);  
  pinMode(yellowLEDPin, OUTPUT);  
  pinMode(redSwitchPin, INPUT_PULLUP);
  pinMode(greenSwitchPin, INPUT_PULLUP);
  pinMode(blueSwitchPin, INPUT_PULLUP);
  pinMode(yellowSwitchPin, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(redSwitchPin) == LOW)
  {
    red ++;
    if (red > 255) red = 0;
  }
  if (digitalRead(greenSwitchPin) == LOW)
  {
    green ++;
    if (green > 255) green = 0;
  }
  if (digitalRead(blueSwitchPin) == LOW)
  {
    blue ++;
    if (blue > 255) blue = 0;
  }
  if (digitalRead(yellowSwitchPin) == LOW)
  {
    yellow ++;
    if (yellow > 255) yellow = 0;
  }
  analogWrite(redLEDPin, red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin, blue);  
  analogWrite(yellowLEDPin, yellow);  
  delay(10);
}
