#include <Servo.h> //servo library
#include "configuration.h"
#include "motor.h"
#include "alarm.h"
Servo myservo; // create servo object to control servo
/*Ultrasonic distance measurement Sub function*/
int watchingAround() {
  long howfar;
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(5);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(15);
  digitalWrite(pinTrig, LOW);
  howfar = pulseIn(pinEcho, HIGH);
  howfar = howfar * 0.01657; //how far away is the object in cm
  return round(howfar);
}

void setup()
{
  myservo.attach(3);// attach servo on pin 3 to servo object
  Serial.begin(9600);
  pinMode(pinEcho, INPUT);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinMotorA1, OUTPUT);
  pinMode(pinMotorA2, OUTPUT);
  pinMode(pinMotorB3, OUTPUT);
  pinMode(pinMotorB4, OUTPUT);
  pinMode(pinEnableMotorA, OUTPUT);
  pinMode(pinEnableMotorB, OUTPUT);
  pinMode(pinLed, OUTPUT);
  stop_Stop();

  // set up the LCD's number of columns and rows:
  //lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
}
void loop()
{
  myservo.write(90);//setservo position according to scaled value
  delay(100);
  middleDistance = watchingAround();
#ifdef send
  Serial.print("middleDistance=");
  Serial.println(middleDistance);
#endif
  if (middleDistance <= distancelimit)
  {
    stop_Stop();
    alarm();
    myservo.write(10);//10°-180°
    delay(100);
    rightDistance = watchingAround();
#ifdef send
    Serial.print("rightDistance=");
    Serial.println(rightDistance);
#endif
    myservo.write(90);
    myservo.write(180);
    delay(500);
    leftDistance = watchingAround();
#ifdef send
    Serial.print("leftDistance=");
    Serial.println(leftDistance);
#endif
    delay(500);
    myservo.write(90);
    delay(500);
    // if (rightDistance > leftDistance) {
    if ((rightDistance > sideDistanceLimit || leftDistance < sideDistanceLimit) || rightDistance > leftDistance)
    {
      alarm();
      go_Right(TURN_SPEED);
      delay(turntime);
    }
    // else if (rightDistance < leftDistance)
    if ((leftDistance > sideDistanceLimit || rightDistance < sideDistanceLimit) || rightDistance < leftDistance)
    {
      alarm();
      go_Left(TURN_SPEED);
      delay(turntime);
    }
    //else if ((rightDistance <= sideDistanceLimit) || (leftDistance <= sideDistanceLimit))
    if ((rightDistance <= sideDistanceLimit) || (leftDistance <= sideDistanceLimit))
    {
      alarm();
      go_Back(TURN_SPEED);
      delay(turntime);
    }
    else
    {
      go_Forward(FWD_SPEED);
    }
  }
  else {
    go_Forward(FWD_SPEED);
  }
}
