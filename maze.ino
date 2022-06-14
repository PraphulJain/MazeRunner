//Maze solving bot
#include"TimerOne.h"
#define leftNearSensor     4
#define leftFarSensor      5
#define centerSensor       2
#define rightNearSensor    1
#define rightFarSensor     0
#define distanceSensor     6
#define leftMotor1  7
#define leftMotor2  9
#define rightMotor1 5
#define rightMotor2 8
int work = 0;
int  leftNearReading , leftFarReading , centerReading , rightNearReading , rightFarReading ;
char mark = 'p';
int a[500][500] = {0};
int i = 250 , j = 250;
void setup() {
  pinMode(leftNearSensor, INPUT);
  pinMode(leftFarSensor, INPUT);
  pinMode(centerSensor, INPUT);
  pinMode(rightNearSensor, INPUT);
  pinMode(rightFarSensor, INPUT);
  pinMode(distanceSensor, INPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  Timer1.initialize(1000000);
}

void loop() {
  controlSystem();
}

void readSensors() {
  leftNearReading    = analogRead(leftNearSensor);
  leftFarReading     = analogRead(leftFarSensor);
  centerReading = analogRead(centerSensor);
  rightNearReading   = analogRead(rightNearSensor);
  rightFarReading    = analogRead(rightFarSensor);
}

void controlSystem()
{
  while ()
  {
    straight();
    Timer1.detachInterrupt();
    readSensors();
    digitalWrite(leftMotor1, HIGH);//               dekhne k liye ki aage raasta hai ya ni
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(100);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    centerReading = analogRead(centerSensor);
    if (leftFarReading > 200 && rightFarReading > 200 && centerReading > 200) //        checking for square
    {
      square();
    }
    else if (leftFarReading > 200 && rightFarReading < 200 && centerReading > 200) //        checking for left triangle
    {
      leftTriangle();
    }
    else if (leftFarReading < 200 && rightFarReading > 200 && centerReading > 200) //        checking for right triangle
    {
      rightTriangle();
    }
    else if (leftFarReading > 200 && rightFarReading > 200 && centerReading < 200) //        checking for left right triangle
    {
      lrTriangle();
    }
    else if (leftFarReading > 200 && rightFarReading < 200 && centerReading < 200) //        checking for left turn
    {
      left();
    }
    else if (leftFarReading < 200 && rightFarReading > 200 && centerReading < 200) //        checking for right turn
    {
      right();
    }
    else if (leftFarReading < 200 && rightFarReading > 200 && centerReading < 200) {} //        checking for glti se bhi straight to ni aa gya
    else if (leftFarReading < 200 && rightFarReading < 200 && centerReading < 200)
    {
      deadEnd();
    }
    else
    {
      End();
      break;
    }
  }
  arraySolve();
}
void straight()
{
  if (mark == 'p')
    mark = 's';
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  while (leftFarSensor < 200 && rightFarSensor < 200 && centerSensor > 200)
  {
    Timer1.attachInterrupt(marking(mark), 100000);
    if (leftNearSensor > 200)
    {
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      while (leftNearSensor < 200 && centerSensor > 200) {}
    }
    if (rightNearSensor > 200)
    {
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
      while (leftNearSensor < 200 && centerSensor > 200) {}
    }
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
  }
}


void leftTriangle()
{
  marking(mark);
  if(a[i][j])
}

