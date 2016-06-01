const int micPin = 0;
const int baseLine = 338;
void setup ()
{
  Serial.begin (9600);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  
}

void ledOutput (int devRead)
{
  if (devRead > 5)
    digitalWrite (13, HIGH);
  else
    digitalWrite (13, LOW);
  if (devRead > 55)
    digitalWrite (12, HIGH);
  else
    digitalWrite (12, LOW);
  if (devRead > 105)
    digitalWrite (11, HIGH);
  else
    digitalWrite (11, LOW);
  if (devRead > 155)
    digitalWrite (10, HIGH);
  else
    digitalWrite (10, LOW);
}

void loop ()
{
  int reading = analogRead (micPin);
  int devRead = reading - 338;
  long time = micros ();
  long x = time;
  long y = 0;
  if (reading > 400)
  {
      if (x == 0)
        x = time;
      else
        y = time;
  }
/*  if (x > 0 && y > 0)
  {
    Serial.print ("Time deltas: ");
    Serial.println (x - y);
    x = 0;
    y = 0;
  }*/
  if(reading>310)Serial.println (reading);
  ledOutput (devRead);
  delay (10);
}
