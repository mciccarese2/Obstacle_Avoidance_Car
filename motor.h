/*define forward function*/
void go_Forward(int speed)
{
  digitalWrite(pinEnableMotorA, ABS);
  digitalWrite(pinEnableMotorB, ABS);
  digitalWrite(pinMotorA1, LOW); //digital output
  digitalWrite(pinMotorA2, speed);
  digitalWrite(pinMotorB3, LOW);
  digitalWrite(pinMotorB4, speed);
  Serial.println("Forward");
}
/*define back function*/
void go_Back(int speed)
{
  digitalWrite(pinEnableMotorA, ABS);
  digitalWrite(pinEnableMotorB, ABS);
  digitalWrite(pinMotorA1, speed);
  digitalWrite(pinMotorA2, LOW);
  digitalWrite(pinMotorB3, speed);
  digitalWrite(pinMotorB4, LOW);
  Serial.println("Back");
}
void stop_Stop()
{
  digitalWrite(pinEnableMotorA, LOW);
  digitalWrite(pinEnableMotorB, LOW);
  Serial.println("Stop");
}

/*define left function*/
void go_Left(int speed)
{
  digitalWrite(pinEnableMotorA, ABS);
  digitalWrite(pinEnableMotorB, ABS);
  digitalWrite(pinMotorA1, LOW);
  digitalWrite(pinMotorA2, speed);
  digitalWrite(pinMotorB3, speed);
  digitalWrite(pinMotorB4, LOW);
  Serial.println("Left");
}
/*define right function*/
void go_Right(int speed)
{
  digitalWrite(pinEnableMotorA, ABS);
  digitalWrite(pinEnableMotorB, ABS);
  digitalWrite(pinMotorA1, speed);
  digitalWrite(pinMotorA2, LOW);
  digitalWrite(pinMotorB3, LOW);
  digitalWrite(pinMotorB4, speed);
  Serial.println("Right");
}

/*set motor speed */
void set_Motorspeed(int speed_L,int speed_R)
{
  analogWrite(pinEnableMotorA,speed_L); 
  analogWrite(pinEnableMotorB,speed_R);   
}


