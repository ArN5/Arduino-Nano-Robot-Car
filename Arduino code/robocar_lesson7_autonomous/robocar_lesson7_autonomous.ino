//this piece of code will allow you to control
//a servo using timers and as well control an Ultrasonic Sensor
//AND using the arduino to send information to the computer for you to see
//that it is actually doing what you told it to do.

//Quick note for right now the pwm on the L293D 
//module is not working on ENB so just set it to 255
//analogWrite(enableB,255)

//first include this library
#include <Servo.h> 


//PING SENSOR STUFF
//these two pins are for the ultrasonic sensor
#define trigPin 4 
#define echoPin 5 


//SERVO STUFF
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
                // the servos require a pwm pin
//PWM pins are pins 3,5,6,9,10,11

//MOTOR STUFF
  #define MAXSPEED 250 //225/255
  #define MINSPEED 100 //100/255
  #define OFFSET 20 //this offset will be used to
  //compensate for one motor being stronger
  //it will be subtracted from the faster motor
  //you gotta figure that part out

//Motor A
int switch1A = 13;  
int switch2A = 12; 
int enableA = 11;  

  
//Motor B 
int switch1B = 8;
int switch2B = 7;
int enableB = 9;

 
int pos = 0;    // global variable to store the servo position 
unsigned long oldTime = 0;//this variable is for the timer
bool latch = 0;//this statement can either be 1 or 0 only 2 allowed states
 
void setup() 
{ 

  //This is for sending information to the computer
  Serial.begin (9600);

  //assign the pin states to each pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //motor pin setup
  pinMode(switch1A, OUTPUT);
  pinMode(switch2A, OUTPUT);
  pinMode(switch1B, OUTPUT);
  pinMode(switch2B, OUTPUT);
    pinMode(enableB, OUTPUT);
  pinMode(enableA, OUTPUT);

  //instead of using pinMode() you use the servo libraries function 
  //in which you put in the format servoName.attach(PWMpin#)
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object 

analogWrite(enableA,255);
analogWrite(enableB,255);

} 
 
 
void loop() 
{ 

getUltrasonicDistance();

if(getUltrasonicDistance()<20)
{
 while(getUltrasonicDistance()<30)
 {

  digitalWrite(switch1A, LOW);
  digitalWrite(switch2A, HIGH);
  digitalWrite(switch1B, LOW);
  digitalWrite(switch2B, HIGH);
 }
  digitalWrite(switch1A, LOW);
  digitalWrite(switch2A, LOW);
  digitalWrite(switch1B, LOW);
  digitalWrite(switch2B, LOW);
 delay(200);
 
  digitalWrite(switch1A, HIGH);
  digitalWrite(switch2A, LOW);
  digitalWrite(switch1B, LOW);
  digitalWrite(switch2B, HIGH);
 delay(500);
}
else


  digitalWrite(switch1A, HIGH);
  digitalWrite(switch2A, LOW);
  digitalWrite(switch1B, HIGH);
  digitalWrite(switch2B, LOW);

//  //this function checks if its time for the servo to move position 
//checkToSweepServo(10);
//  //for delay time try to use a small number like 20~5 milliseconds

} 



long getUltrasonicDistance()
{
  //create number variables for both duration and distance
long duration, distance;
 
digitalWrite(trigPin, LOW);  
delayMicroseconds(2);
  //Turn off the trigger ultrasonic speaker for 2 us.
  
  
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
 //  Turn on the sensor circuit
 //via the tigger pin.
 //The sensor circuit emits
 //a 40khz sound pulse
 //for 10 microseconds  
 //_______|__|__|__|__|__|__|__________
 //this creates 8 pulses in 10 microseconds
digitalWrite(trigPin, LOW);
 //then turn off the trigger pin so it shuts of the 40khz pulses

 //During this time the 
 //sound has been shot out
 //and is flying through air
 //and it will maybe bounce 
 //off a wall or something big enough
 //if it does, it will echo off some object 
 //then it will begin to return to the echo speaker

 //Now listen from the echo ultrasonic speaker.
  
 //pulseIn() measures the amount of time (in microseconds)
 //it takes the pin desired to change state
 //in this case its LOW and we are waiting till it hits HIGH.
duration = pulseIn(echoPin, HIGH); 
 //if you want more info on pulseIn();
 //https://www.arduino.cc/en/Reference/PulseIn

  
distance = (duration/2) / 29.1;
  //from wikipedia  "In dry air at 20 °C (68 °F), the speed of sound is 343.2 metres per second"
  //(? us / 2)*(1 s / 1,000,000 us)*(100cm/1m)*(343.2m/s)
  //which turns into (? us / 2)*(1/29.1) [centimeters/second] 

  //(1 second is 1,000,000 microseconds)
  //(100 centimeters is 1 meter)

  //Assuming you had a temperature sensor and want 
  //a better reading a good practical equation that takes in temperature
  //is this one from wikipedia
  //331.3 + 0.606*(temperature In Celsius);

Serial.println(distance);
  //but anyways
  //to return the "distance" 
return distance;
}



void checkToSweepServo(int delayTime)
{
  //millis() grabs the current time in milliseconds
  //and this current time is with respect to the 
  //start of the arduino program, not absolute time
  //like a watch
  
  if(millis()-oldTime > delayTime)//subtract the current time with the old time
  //has the amount of delay time passed?
  {                            
    if(latch)
     {
      pos = pos +10;//add by one
        
        if(pos>180)
        //if once above 180 degrees
        //reset the latch
        {
         latch=0;
        }
     }
      
      else
      {
        pos = pos -10;
        
        if(pos<0)
        {
         latch=1;
        }
      }
       
  myservo.write(pos); 
  //now finally write the position
  
  oldTime = millis();
  //and now update the old time
  //by grabbing the current time
  } 
    
  
}


//and you are done
