#include <Servo.h>
#include <SoftwareSerial.h>

int joyY = A9;
int joyX = A8;
int servo1 = 50;
int servo2 = 48;

int servoValX;
int servoValY;

Servo myservo1;
Servo myservo2;

SoftwareSerial mySerial(46, 44);

void setup() {
  // put your setup code here, to run once:
  myservo1.attach(servo1);
  myservo2.attach(servo2);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    servoValY = analogRead(joyY);          
    servoValY = map(servoValY, 0, 1023, 0, 180); 
    myservo2.write(servoValY);
    
    servoValX = analogRead(joyX);           
    servoValX = map(servoValX, 0, 1023, 0, 180);
    myservo1.write(servoValX);
    
   
    String message = "{";
    message+=servoValX;
    message+=',';
    message+=servoValY;
    message+='}';
    Serial.println(message);
    mySerial.println(message);
    
  {
//    if (mySerial.available())
//      Serial.write(mySerial.read());
//    if (Serial.available())
//      mySerial.write(Serial.read());
  }
}
