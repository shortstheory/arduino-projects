
void ledTest ()
{
  digitalWrite (0, HIGH);
  delay (100);
  digitalWrite (1, HIGH);
  delay (100);
  digitalWrite (2, HIGH);
  delay (100);  
  digitalWrite (3, HIGH);
  delay (100);
  digitalWrite (8, HIGH);
  delay (100);
  digitalWrite (9, HIGH);
  delay (100);  
  digitalWrite (10, HIGH);
  digitalWrite (0, LOW);
  delay (100);
  digitalWrite (1, LOW);
  delay (100);
  digitalWrite (2, LOW);
  delay (100);  
  digitalWrite (3, LOW);
  delay (100);
  digitalWrite (8, LOW);
  delay (100);
  digitalWrite (9, LOW);
  delay (100);  
  digitalWrite (10, LOW);
}

int getTemp ()
{
  int reading = analogRead (A0);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float tempC = (voltage - 0.5) * 100;
  //Serial.print (tempC); Serial.println (" C");
  Serial.println (tempC);
  return tempC;
}

void convertBinary (int x)
{
  int e0, e1, exp = 2, write;
	
  e0 = x % 10;
  e1 = x / 10;
        	
  write = 3;
  do
  {
    if ((e0 % 2) == 0)
    {
      digitalWrite (write, LOW);
    }
    else
    {
      digitalWrite (write, HIGH);
      //Serial.println (e0);
    }
    e0 /= 2;
    write--;

    delay (1000);
  }while (e0 != 1);
  
  write = 8;
  
  do
  {
    if ((e1 % 2) == 0)
      digitalWrite (write, LOW);
    else
      digitalWrite (write, HIGH);
      e1 /= 2;
      write++;
  }while (e1 != 1);
}

int binaryLookup (int x)
{
  int e0, e1;
  e0 = x % 10;
  e1 = x / 10;
  switch (e0)
  {
    case 0:
      digitalWrite (0, LOW);
      digitalWrite (1, LOW);
      digitalWrite (2, LOW);
      digitalWrite (3, LOW);
      break;
    case 1:
      digitalWrite (0, HIGH);
      digitalWrite (1, LOW);
      digitalWrite (2, LOW);
      digitalWrite (3, LOW);
      break;
    case 2:
      digitalWrite (0, LOW);
      digitalWrite (1, HIGH);
      digitalWrite (2, LOW);
      digitalWrite (3, LOW);
      break;
    case 3:
      digitalWrite (0, HIGH);
      digitalWrite (1, HIGH);
      digitalWrite (2, LOW);
      digitalWrite (3, LOW);
      break;
    case 4:
      digitalWrite (0, LOW);
      digitalWrite (1, LOW);
      digitalWrite (2, HIGH);
      digitalWrite (3, LOW);
      break;
    case 5:
      digitalWrite (0, HIGH);
      digitalWrite (1, LOW);
      digitalWrite (2, HIGH);
      digitalWrite (3, LOW);
      break;
    case 6:
      digitalWrite (0, LOW);
      digitalWrite (1, HIGH);
      digitalWrite (2, HIGH);
      digitalWrite (3, LOW);
      break;
    case 7:
      digitalWrite (0, HIGH);
      digitalWrite (1, HIGH);
      digitalWrite (2, HIGH);
      digitalWrite (3, LOW);
      break;
    case 8:
      digitalWrite (0, LOW);
      digitalWrite (1, LOW);
      digitalWrite (2, LOW);
      digitalWrite (3, HIGH);
      break;
    case 9:
      digitalWrite (0, HIGH);
      digitalWrite (1, LOW);
      digitalWrite (2, LOW);
      digitalWrite (3, HIGH); 
  }     
  switch (e1)
  {
    case 0:
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (10, LOW);
      break;
    case 1:
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      digitalWrite (10, LOW);
      break;
    case 2:
      digitalWrite (8, LOW);
      digitalWrite (9, HIGH);
      digitalWrite (10, LOW);  
      break;
    case 3:
      digitalWrite (8, HIGH);
      digitalWrite (9, HIGH);
      digitalWrite (10, LOW);
      break;
    case 4:
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (10, HIGH);
      break;
    case 5:
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      digitalWrite (10, HIGH);
      break;
    case 6:
      digitalWrite (8, LOW);
      digitalWrite (9, HIGH);
      digitalWrite (10, HIGH);
      break;
    case 7:
      digitalWrite (8, HIGH);
      digitalWrite (9, HIGH);
      digitalWrite (10, HIGH);
      break;
    case 8:
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (10, LOW);
      break;
    case 9:
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (10, LOW);
      break;
  }
}

void setup ()
{
  Serial.begin (9600); 
  pinMode (0, OUTPUT);
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (13, INPUT);
  ledTest ();
}


void loop ()
{
  /*
  float avgTemp;
  int i;
  for (i = 0, avgTemp = 0; i < 100; i++)
  {
    avgTemp += getTemp ();
  }
  avgTemp /= 100;*/
  getTemp();
  binaryLookup (getTemp());
  //delay (10000);
}
