#define red 4
#define blue 2
#define green 3

void setup()
{
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);

}
void loop()
{
 analogWrite(red,255);
 analogWrite(green,255);
 analogWrite(blue,255);
 delay(1000);

// analogWrite(red,0);
//  analogWrite(green,0);
//  analogWrite(blue,0);
//  delay(1000);
}