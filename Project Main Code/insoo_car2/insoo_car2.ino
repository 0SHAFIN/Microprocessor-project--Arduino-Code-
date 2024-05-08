#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>
#include <MQ2.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
//#define MQ2_PIN A0
#define MQ2_PIN 34
int analogInput =A0;
MQ2 mq2 (analogInput);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
Adafruit_BME280 bmp;
#define SEALEVELPRESSURE_HPA (1013.25)
float voltage ;
float temp,pre,alti,humidity,CO ,LPG ,smoke;
long previousMillis = 0;



//ultrasonic
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;




int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; //1 for the electronic braking system, 0 for normal.

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  Serial.begin(115200);
  mq2 .begin();
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 if (!bmp.begin(0x76)) {
 Serial.println("Could not find a valid BMP085 sensor, check wiring!");
 while (1) {}
 }  //Set the baud rate to your Bluetooth module.
}

void loop() {

    sensorRead();
  
}


void sensorRead()
{
   temp=bmp.readTemperature();
 pre=bmp.readPressure();
 alti=bmp.readAltitude(1013.25);
 humidity=bmp.readHumidity();
 int sensorValue = analogRead(MQ2_PIN);
 voltage = sensorValue * (5.0 / 1023.0);
 CO= voltage * 50.0;
 LPG=mq2.readLPG();
 smoke= voltage * 20.0;
  Serial.println(bmp.readTemperature());
  Serial.println(pre/100.0F);
  Serial.println(alti);
  Serial.println(humidity);
  Serial.println(CO);
  Serial.println(LPG);
  Serial.println(smoke);



 display.clearDisplay();
 display.setTextSize(.1);
 display.setTextColor(SSD1306_WHITE);

 
 display.setCursor(0,5);
 display.print("Microprocessor");
 display.setCursor(0,19);
 display.print("T=");
 display.print(bmp.readTemperature());
 display.println("*C");
 /*prints BME180 pressure in Hectopascal Pressure Unit*/
 display.setCursor(0,30);
 display.print("P=");
 display.print(bmp.readPressure()/100.0F,1);
 display.println("hPa"); 
 
 /*prints BME180 altitude in meters*/
 display.setCursor(0,40);
 display.print("A=");
 display.print(bmp.readAltitude(SEALEVELPRESSURE_HPA),1);
 display.println("m");

  /*prints BME180 altitude in meters*/
 display.setCursor(0,50);
 display.print("H=");
 display.print(humidity);
 display.println("%");

 //smoke sensor

//LPG
  display.setCursor(52,19);
 display.print(" LPG=");
 display.print(LPG);

 //CO
  display.setCursor(50,40);
 display.print("CO=");
 display.print(CO);

  //Smoke
  display.setCursor(54,50);
 display.print("Smk=");
 display.print(smoke);
 
 display.display();

}
// void ultraSonic()
// {
//     digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   // Sets the trigPin on HIGH state for 10 micro seconds
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   // Reads the echoPin, returns the sound wave travel time in microseconds
//   duration = pulseIn(echoPin, HIGH);
//   // Calculating the distance
//   distance = duration * 0.034 / 2;
//   // Prints the distance on the Serial Monitor
//   Serial.print("Distance: ");
//   Serial.println(distance);
// }