#define del 1

void setup ()
{
  Serial.begin (9600);
  pinMode (13, OUTPUT);
}

void oscilloscope ()
{
  int x = analogRead (0); 
  Serial.write( 0xff );
  Serial.write( (x >> 8) & 0xff );
  Serial.write( x & 0xff );
}


void loop ()
{
  oscilloscope ();
  digitalWrite (13, HIGH);
  oscilloscope ();
  delay (del);
  oscilloscope ();
  digitalWrite (13, LOW);
  oscilloscope ();
  delay (del);
  oscilloscope ();
}
