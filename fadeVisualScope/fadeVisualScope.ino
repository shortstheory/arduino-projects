void setup ()
{
  Serial.begin (9600);
  pinMode (9, OUTPUT);
}

void oscilloscope (int reading)
{
  int x = reading + 0;
  Serial.write( 0xff );
  Serial.write( (x >> 8) & 0xff );
  Serial.write( x & 0xff );
}

void loop ()
{
  int reading = analogRead (0);
  oscilloscope (reading);
  analogWrite (9, 185);
}
