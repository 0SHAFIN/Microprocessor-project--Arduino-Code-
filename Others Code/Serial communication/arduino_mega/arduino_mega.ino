//reciver
char c;
int Speed = 100;

//declare channel for pwm Output
#define R 0
#define L 1

//PWM Pin for Controlling the speed
int enA = 2;
int enB = 3;

//motor controlling pin
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(10);
    //output pin declare
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  // // Setup PWM channels
  // ledcSetup(R, 5000, 8);  // Channel 0 for Motor A, 5 kHz frequency, 8-bit resolution
  // ledcAttachPin(enA, R);
  // ledcSetup(L, 5000, 8);  // Channel 0 for Motor A, 5 kHz frequency, 8-bit resolution
  // ledcAttachPin(enB, L);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //Intial State of Car
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void loop()
{
  
   
  if(Serial.available()>0)
  {
   c=Serial.read();
    Serial.println(c);

  }
    if (c == '0') Speed = 100;
    if (c == '1') Speed = 110;
    if (c == '2') Speed = 120;
    if (c == '3') Speed = 130;
    if (c == '4') Speed = 140;
    if (c == '5') Speed = 150;
    if (c == '6') Speed = 180;
    if (c == '7') Speed = 200;
    if (c == '8') Speed = 220;
    if (c == '9') Speed = 240;
    if (c == 'q') Speed = 255;
        if (c == 'B') {
      backward();
    }

  //forward
    else if (c == 'F') {
      forward();
    }

  //LEFT
    else if (c == 'L') {
      left();
    }

  //RIGHT
    else if (c == 'R') {
      right();
    }

  //STOP
    else if (c == 'S') {
      stop();
    }
  

}
//function for control motor
void backward() {
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  }

void forward() {
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stop() {
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}