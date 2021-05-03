#include<Servo.h>
Servo myServo;
int trig = 4;
int echo = 5;
float t, d;
int distance=200;


void setup() {
 Serial.begin(9600);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 Serial.begin(9600);
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 digitalWrite(trig, LOW);
 delay(500);
 myServo.attach(6);

 
 }

void moveForward() 
{
 digitalWrite(2, HIGH);
 digitalWrite(8, HIGH);
 digitalWrite(3, LOW);
 digitalWrite(9, LOW);
}

void moveStop()
{
 digitalWrite(2, LOW);
 digitalWrite(8, LOW);
 digitalWrite(3, LOW);
 digitalWrite(9, LOW);
 delay(1000);
}

void moveBackward()
{
  
  digitalWrite(3, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(8, LOW);
}


void moveRight()
{
  digitalWrite(2, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(3, LOW);
  digitalWrite(9, LOW);
  delay(1000);


 digitalWrite(2, HIGH);
 digitalWrite(8, HIGH);
 digitalWrite(3, LOW);
 digitalWrite(9, LOW);
}

void moveLeft()
{
 digitalWrite(2, LOW);
 digitalWrite(8, HIGH);
 digitalWrite(3, LOW);
 digitalWrite(9, LOW);
 delay(1000);


 digitalWrite(2, HIGH);
 digitalWrite(8, HIGH);
 digitalWrite(3, LOW);
 digitalWrite(9, LOW);
 }

int readDistance()
 {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = 0.01715 * t;
 return d;
 }
 
int lookLeft()
{
  myServo.write(45);
  delay(500);
  int d = readDistance();
  myServo.write(90);
  delay(500);
  return d;
  delay(100);
}

int lookRight()
{
  myServo.write(135);
  delay(500);
  int d = readDistance();
  myServo.write(90);
  delay(500);
  return d;
  delay(100);
}

void loop(){

 moveForward();
 int v=readDistance();
 if(v<=100)
 { moveStop();
   delay(300);
   moveBackward();
   delay(300);

   int r= lookRight();
   int l= lookLeft();
   if(r>1)
   {
     moveRight();
     moveStop();
   }
   else
   { 
     moveLeft(); 
     moveStop();
   }
 }
 else
 {moveForward();
 }
 v=readDistance();
}
   
   
 


    
