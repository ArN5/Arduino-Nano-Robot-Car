//this piece of code will allow you to control
//a servo

//  a servo is a motor with a gear box
//that has a circuit inside that allows it to
//know its exact position.

//  for our class we will use it to control the position of
//our ultrasonic sensor that measure distance
//that will be mounted on the top of the servo to act as crude sonar.

//  the key difference between a servo and a normal motor
//is that you can tell a servo where to go with higher torque (force)
//than a normal motor.

//first include this library
#include <Servo.h> 

//now we create the servo "object" you can call it "myservo" or "leftservo" 
//to be honest you can give it any name that makes it unique

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // global variable to store the servo position 
 
void setup() 
{ 
  
  //instead of using pinMode() you use the servo libraries function 
  //in which you put in the format servoName.attach(PWMpin#)
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  
} 
 
 
void loop() 
{ 
//now you will be introduced to for loops
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  // quick note on the part where the code says pos+=1
  // there are more than one way to write
  // this command and its important to recognize all three of them
  // pos += 1
  // pos++
  // pos= pos+1
} 

//and you are done! simple
//now try to make the servo move faster.

