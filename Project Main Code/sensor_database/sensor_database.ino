#include <ESP32Firebase.h>

#include <ESP32Firebase.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define _SSID "Anik"          
#define _PASSWORD "anik5454"      
#define REFERENCE_URL "https://microporcessor-default-rtdb.firebaseio.com/"  
Firebase firebase(REFERENCE_URL);
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <MQ2.h>
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
#define MQ2_PIN 34

MQ2 mq2 (MQ2_PIN);
#define SEALEVELPRESSURE_HPA (1013.25)
float voltage ;
float temp,pre,alti,humidity,CO ,LPG ,smoke;
Adafruit_BME280 bme; // I2C


unsigned long delayTime;

void setup() {
    WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.begin(9600);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.println(F("BME280 test"));
    WiFi.begin(_SSID, _PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print("-");
  }
 mq2 .begin();
  bool status;

  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

}


void loop() { 
  printValues();

}

void printValues() {
   temp=bme.readTemperature();
 pre=bme.readPressure()/100.0F;
 alti=bme.readAltitude(1013.25);
 humidity=bme.readHumidity();
 int sensorValue = analogRead(MQ2_PIN);
 voltage = sensorValue * (5.0 / 1023.0);
 CO= voltage * 5;
 LPG=voltage * 100.0;
 smoke= voltage * 20.0;
  firebase.setFloat("Sensor/Temperature", temp);
  firebase.setFloat("Sensor/Pressure", pre);
  firebase.setFloat("Sensor/Altimeter", alti);
  firebase.setFloat("Sensor/Humidity", humidity);
  firebase.setFloat("Sensor/CO", CO);
  firebase.setFloat("Sensor/LPG", LPG);
  firebase.setFloat("Sensor/Smoke", smoke);
  Serial.println(bme.readTemperature());
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
 display.print(bme.readTemperature());
 display.println("*C");
 /*prints BME180 pressure in Hectopascal Pressure Unit*/
 display.setCursor(0,30);
 display.print("P=");
 display.print(bme.readPressure()/100.0F,1);
 display.println("hPa"); 
 
 /*prints BME180 altitude in meters*/
 display.setCursor(0,40);
 display.print("A=");
 display.print(bme.readAltitude(SEALEVELPRESSURE_HPA),1);
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

  Serial.println();
}