
#include <ESP32Firebase.h>
#define _SSID "ACTFIBERNET"          
#define _PASSWORD "shafin112"      
#define REFERENCE_URL "https://microporcessor-default-rtdb.firebaseio.com/"  
Firebase firebase(REFERENCE_URL);
float temp,pre,alti,humidity,CO,LPG,smoke;
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  // Connect to WiFi
 // Serial.println();
 // Serial.println();
 // Serial.print("Connecting to: ");
 // Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print("-");
  }

  //Serial.println("");
  //Serial.println("WiFi Connected");

}

void loop() {
   temp=Serial.parseFloat();
    pre=Serial.parseFloat();
    alti=Serial.parseFloat();
    humidity=Serial.parseFloat();
    CO=Serial.parseFloat();
    LPG=Serial.parseFloat();
    smoke=Serial.parseFloat();
  firebase.setFloat("Sensor/Temperature", temp);
  firebase.setFloat("Sensor/Pressure", pre);
  firebase.setFloat("Sensor/Altimeter", alti);
  firebase.setFloat("Sensor/Humidity", humidity);
  firebase.setFloat("Sensor/CO", CO);
  firebase.setFloat("Sensor/LPG", LPG);
  firebase.setFloat("Sensor/Smoke", smoke);
   Serial.print("temp: ");
    Serial.println(temp);
    Serial.print("pre: ");
    Serial.println(pre);
    Serial.print("alti: ");
    Serial.println(alti);
    Serial.print("humidity: ");
    Serial.println(humidity);
 }
