#define send;

#define pinEcho A1
#define pinTrig A0

#define light_FR  14    //LED Front Right   pin A0 for Arduino Uno
#define light_FL  15    //LED Front Left    pin A1 for Arduino Uno

#define pinLed 13 // Use the onboard Uno LED

#define pinMotorA1 9
#define pinMotorA2 8
#define pinMotorB3 7
#define pinMotorB4 6
/*define channel enable output pins*/
#define pinEnableMotorA 10
#define pinEnableMotorB 5

#define buzzerPin 2

const int ABS = 180;
const int TURN_SPEED = 150;
const int FWD_SPEED = 255;

int rightDistance = 0, leftDistance = 0, middleDistance = 0 ;
const int distancelimit = 30; //distance limit for obstacles in front
const int sideDistanceLimit = 20; //minimum distance in cm to obstacles at both sides (the car will allow a shorter distance sideways)
const int turntime = 800; //Time the robot spends turning (miliseconds)
