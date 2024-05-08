#define enA 6
#define enB 7
#define in1 8 //L298n Motor Driver pins.
#define in2 9
#define in3 10
#define in4 11
char command; //Int to store app command state.
int Speed = 100; // 0 - 255.
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
   pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    Stop(); 
    switch (command) {
      case 'F':
        forward();
        break;
       
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 140;
        break;
      case '2':
        Speed = 153;
        break;
      case '3':
        Speed = 165;
        break;
      case '4':
        Speed = 178;
        break;
      case '5':
        Speed = 191;
        break;
      case '6':
        Speed = 204;
        break;
      case '7':
        Speed = 216;
        break;
      case '8':
        Speed = 229;
        break;
      case '9':
        Speed = 242;
        break;
      case 'q':
        Speed = 255;
        break;
    }
  }
}
void forward() {
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void back() {
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void right() {
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Stop() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
