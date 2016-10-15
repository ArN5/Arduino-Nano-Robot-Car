 // lesson 3 PWM with a for loop
  
  //that will control Speed of the motors with a for loop
  //this for the robot car with the arduino nano
  //so lets begin by giving descriptive names to
  //the pins on the nano that we will be using
int switch1A = 13; //connected on Arduino nano to pin 13 
int switch2A = 12; //connected on Arduino nano to pin 12
int enableA = 11;  //connected on Arduino nano to pin 11

  //both of these pins will control Motor A
  //and enableA is the switch that "enables" motor A to be on or off
  //it will be what will be used to vary motor speed

//just in case you finished this 
//lesson try to use the second motor
//just remove the // 

//Motor B 
//int switch1B = 8;
//int switch2B = 7;
//int enableB = 9; 

void setup() {
  // put your setup code here, to run once:
  //this piece of codes lets the arduino know
  //in what way you wish to use the pins as,
  //either inputs or outputs
  //in this case we are using the pins are 
  //switches to control the motor direction
 pinMode(switch1A, OUTPUT);
 pinMode(switch2A, OUTPUT);
//and you are done setting up  
}
void loop() {
  
//lets vary speed with a for loop!

for(int i = 170;i<256;i++)
// translation = for an integer lets call it "i" starting at 170 
//repeat the code inside of the braces {} and make "i" increase by 1 (i++) every repetition
//until "i" less than 256
{
analogWrite(enableA, i);//set the motor speed at the current "i" value
//assume its the first loop of the for loop the i value will be i = 170
//second loop 171 and so on until it reaches i = 255.
digitalWrite(switch1A, HIGH); //turn on the motor in this direction 
delay(100);//do this speed for 0.1 seconds
}
//then stop the motor
digitalWrite(switch1A, LOW);  
delay(1000);
//the delay is for the motor to stop for a good period of time
//if this delay isnt here the motor will stop for like 1 microsecond 
//basically it will stop so fast you wont see it
}
