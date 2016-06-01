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
void oscilloscope (int reading)
{
  int x = reading + 175;
  Serial.write( 0xff );
  Serial.write( (x >> 8) & 0xff );
  Serial.write( x & 0xff );
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
  double time = micros ();
  if (reading > 340)
  {
    Serial.print (time);
    Serial.print (": ");
    Serial.println (reading);
  }
  oscilloscope (reading);
  ledOutput (devRead);
  delay (0);
}
