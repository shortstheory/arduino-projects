void setup ()
{
  pinMode (13, OUTPUT);
}
void freqgen (int x)
{
  delay (1000 / x);
}
void loop ()
{
  digitalWrite (13, HIGH);
  freqgen (200);
  digitalWrite (13, LOW);
}
