//sender

void setup()
{
Serial.begin(9600);
}
void loop()
{
  int a= 21;
  int b= 43;
  String c="shafin";
  float d=30.21;
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(d);
  delay(1000);
}