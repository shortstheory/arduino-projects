const int stp = 500;
const int ledPin = 13;
const int micPin = 0;
const int ambient = 338;
bool lighton = true;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int currentMode=0;
int buttonState=0;
int lastButtonState=0;
int buttonPin=2;
int buttonPushCounter=0;
void setup ()
{
  pinMode(ledPin, OUTPUT);
}

int switchOn(int val=255)
{
  analogWrite(ledPin, val);
}

int strobe(int t=50, int pwmValue=255)
{
 // pwm(pwmValue);
  digitalWrite(ledPin, HIGH);
  delay(t);
  digitalWrite(ledPin, LOW);
  delay(t);
}

void fade()
{
    // set the brightness of pin 9:
  analogWrite(ledPin, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(15);   
}

void clapper()
{
  int reading = analogRead(micPin);
  int delta = reading - ambient;
  delta = (delta>0) ? delta : delta*-1;
  if (delta > 162)
  {
    Serial.println(millis());
    Serial.println (reading);
    lighton = !(lighton);
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  if(lighton)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  } 
}

void partymode()
{
  int reading = analogRead(micPin);
  int delta = reading - ambient;
  delta = (delta>0) ? delta : delta*-1;
  if (delta > 70)
  {
    Serial.println(millis());
    Serial.println (reading);
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}  

int pushState()
{
  buttonState = digitalRead(buttonPin);
  if(buttonState != lastButtonState)
  {
    if(buttonState == HIGH)
    {
      buttonPushCounter++;
      delay(50);
    }
  }
  lastButtonState = buttonState;
  return buttonPushCounter % 4;
}

void modeSelector(int x)
{
  switch(x)
  {
    case 0:
      digitalWrite(13, HIGH);
      break;
    case 1:
      partymode();
      break;
    case 2:
      fade();
      break;
    case 3:
      strobe(100);
      break;
  }
}
 
void loop()  
{ 
  modeSelector(pushState());
}


