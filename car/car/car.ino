// motor one
int enA = 11;
int in1 = 13;
int in2 = 12;
// motor two
int enB = 10;
int in3 = 9;
int in4 = 8;

bool x;
void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  x = true;
}

void forward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void reverse()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
}

void right()
{
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void left()
{
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}

void brake()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
}

void neutralSteering()
{
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop()
{
  /*digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  delay(1000);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  delay(1000);*/
  //reverse();
  left();
  delay(1000);
  neutralSteering();
  delay(1000);
  right();
  delay(1000);
  reverse();
  delay(1000);
  forward();
  delay(1000);
  brake();
  delay(1000);
  //digitalWrite(in2, HIGH);
  //digitalWrite(in1, LOW);
  //delay(300);  
  //digitalWrite(in2, LOW);
}

