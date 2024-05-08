#include "BluetoothSerial.h"
BluetoothSerial serialBT;
//Bluetooth signal Store in this variable
char btSignal;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //Bluetooth Name
  serialBT.begin("Inso Car");
}

void loop() {
  // put your main code here, to run repeatedly:
    while (serialBT.available()) {
    btSignal = serialBT.read();
    //Serial.println(btSignal);

//to see the incoming signal in serial monitor   
      Serial.println(btSignal);
     
    
    }

}
