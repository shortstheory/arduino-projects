//#define ANALOG_IN 0

void setup() {
  pinMode (13, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int val = analogRead(0);
  if (val > 345)
    digitalWrite (13, HIGH);
  else
    digitalWrite (13, LOW);  
  Serial.print( 0xff);
  Serial.print( (val >> 8) & 0xff);
  Serial.print( val & 0xff);
}


