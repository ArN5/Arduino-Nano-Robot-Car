//this piece of code will allow you to control
//a servo using timers and as well control an Ultrasonic Sensor
//AND using the arduino to send information to the computer for you to see
//that it is actually doing what you told it to do.

//first include this library
#include <Servo.h> 

//these two pins are for the ultrasonic sensor
#define trigPin 6 //this activates the trigger Speaker
#define echoPin 5 //this is for the echo speaker

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
                // the servos require a pwm pin
//PWM pins are pins 3,5,6,9,10,11
 
int pos = 0;    // global variable to store the servo position 
unsigned long oldTime = 0;//this variable is for the timer
bool latch = 1;//this statement can either be 1 or 0 only 2 allowed states
 
void setup() 
{ 

  //This is for sending information to the computer
  Serial.begin (115200);

  //assign the pin states to each pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //instead of using pinMode() you use the servo libraries function 
  //in which you put in the format servoName.attach(PWMpin#)
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object 

} 
 
 
void loop() 
{ 
  //create a number variable of size "long"
  //to hold the current distance [in centimeters]
  //and grab it from the function getUltrasonicDistance()
long currentDistance = getUltrasonicDistance(); 
//https://www.arduino.cc/en/Reference/Long

  //now display this value on the serial monitor
Serial.println (currentDistance);
  //https://www.arduino.cc/en/Serial/Print

  //this function checks if its time for the servo to move position 
checkToSweepServo(5);
  //for delay time try to use a small number like 20~5 milliseconds

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
      pos++;//add by one
        
        if(pos>180)
        //if once above 180 degrees
        //reset the latch
        {
         latch=0;
        }
     }
      
      else
      {
        pos--;
        
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


//and you are done! simple
