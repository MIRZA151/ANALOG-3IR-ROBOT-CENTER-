#define LeftMotorForward 2
#define LeftMotorBackward 3
#define RightMotorForward 4
#define RightMotorBackward 5
#define centerMotorForward 6
#define centerMotorBackward 7

#define leftIR A0
#define rightIR A1
#define centerIR A2

void setup() {
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(RightMotorForward, OUTPUT) ;
  pinMode(centerMotorForward, OUTPUT) ;
  pinMode(LeftMotorBackward, OUTPUT) ;
  pinMode(RightMotorBackward, OUTPUT) ;
  pinMode(centerMotorBackward, OUTPUT) ;

  pinMode(leftIR, INPUT) ;
  pinMode(rightIR, INPUT) ;
  pinMode(centerIR, INPUT) ;

  Serial.begin(9600) ;

}

void loop() {
  if (analogRead(centerIR) >= 500 && analogRead(leftIR) < 500 && analogRead(rightIR) < 500) //Forward
  {
    analogWrite(LeftMotorForward, 150) ;
    analogWrite(RightMotorForward, 150);
    analogWrite(centerMotorForward, HIGH);
  }
  else if (analogRead(centerIR) >= 500 && analogRead(leftIR) < 500 && analogRead(rightIR) >= 500) //Right
  {
    analogWrite(LeftMotorForward, 130) ;
    analogWrite(RightMotorForward, LOW) ;
    analogWrite(centerMotorForward, HIGH);
  }
  else if (analogRead(centerIR) >= 500 && analogRead(leftIR) >= 500 && analogRead(rightIR) >= 500) //Left
  {
    analogWrite(LeftMotorForward, LOW) ;
    analogWrite(RightMotorForward, 130);
    analogWrite(centerMotorForward, HIGH);
  }

  else if (analogRead(centerIR) >= 500 && analogRead(leftIR) >= 500 && analogRead(rightIR) >= 500) //Stop
  {
    analogWrite(LeftMotorForward, LOW) ;
    analogWrite(RightMotorForward, LOW);
    analogWrite(centerMotorForward, HIGH);
  }
    
  else if (analogRead(centerIR) >= 500 && analogRead(rightIR) >= 500 && analogRead(leftIR) >= 500) //Stop
    {
      analogWrite(LeftMotorForward, LOW) ;
      analogWrite(RightMotorForward, LOW);
      analogWrite(centerMotorForward, HIGH);
    }
  delay(12);
}
