// #define lpwm 2
// #define rpwm 3
// #define lmf 41
// #define lmb 39
// #define rmf 37
// #define rmb 35
#define enA 4
#define enB 5
#define in1 41 //L298n Motor Driver pins.
#define in2 39
#define in3 37
#define in4 35
int Speed=200;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 // pinMode(LED, OUTPUT);
}

void loop() {
 analogWrite(enA,Speed);
 analogWrite(enB,Speed);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);


}
