const int sensorPin = 0;

void setup ()
{
  Serial.begin (9600);
  pinMode (0, OUTPUT);
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
}

void ledon (int x)
{
  int i;
  int val = x - 21;
  if (val % 2 == 0);
    val++;
  for (i = 1; i <= val; i++)
  {
    digitalWrite (i, HIGH);
  }
  for (i = val; i <= 13; i++)
  {
    digitalWrite (i, LOW);
  }
  
}  

void loop ()
{
  int reading = analogRead (sensorPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
 
  Serial.print (voltage * 1024); Serial.println (" mV");
  
  float tempC = (voltage - 0.5) * 100;
  Serial.print (tempC); Serial.println (" C");
  float lss;
  lss = (331.3 + 0.606 * tempC);
  Serial.print ("LSS: "); Serial.print (lss); Serial.println (" m/s");
  analogWrite (3, 255); 
  ledon (tempC);
  delay (750);
}
