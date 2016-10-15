//this piece of code will allow you to control
//a servo using timers

//first include this library
#include <Servo.h> 

//now we create the servo "object" you can call it "myservo" or "leftservo" 
//to be honest you can give it any name that make it unique

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // global variable to store the servo position 
unsigned long oldTime = 0;
bool latch = 1;//this statement can either be 1 or 0 only 2 allowed states
 
void setup() 
{ 
  //instead of using pinMode() you use the servo libraries function 
  //in which you put in the format servoName.attach(PWMpin#)
  
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
//now you will be introduced to for loops
  
checkToSweepServo(10);
//for delay time try to use a small number like 20~5 milliseconds

} 



//if you dont understand the following code its ok just for now know
//that function allows you send an amount of time inside the ()
//this amount time is compared to timer the arduino has running and when it reaches the timer
//it sets the next position of the servo
//why would you want this as opposed to the other function
//well this one allows it "run in the back ground" so instead of stopping the whole program
//and moving the servos from one position to another, it instead allows the loop to continue uninterrupted.

void checkToSweepServo(int delayTime)
{
  //millis() grabs the current time in milliseconds
  //and this current time is with respect to the 
  //start of the arduino program, not absolute time
  //like a watch
  
  if(millis()-oldTime>delayTime)
  //has the amount of delay time passed?
  { 
    //once the amount of time passes the position of the servo increases
    //once it maxes out at 180 we need to reset the servo position variable "pos"
    //which is why the "latch" exist I should have named it "isPosMax" 
    //and once latch is true then it starts to subtract from 180. 
                            
      if(latch)
      {
        pos++;//add by one
        
        if(pos>180)//once above reset the latch
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
  } 
    
  
}


//and you are done! simple
//now try to make the servo move faster.
//hint: checkToSweepServo(10); 
