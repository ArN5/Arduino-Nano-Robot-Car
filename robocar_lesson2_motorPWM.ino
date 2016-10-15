 // lesson 2 PWM
  
  //this is a simple piece of code
  //that will control the motors
  //this for the robot car with the arduino nano

  //so lets begin by giving descriptive names to
  //the pins on the nano that we will be using

int switch1A = 13; //connected on Arduino nano to pin 13 
int switch2A = 12; //connected on Arduino nano to pin 12
int enableA = 11;  //connected on Arduino nano to pin 11

//just in case you finished this 
//lesson try to use the second motor
//just remove the // 

//Motor B 
//int switch1B = 8;
//int switch2B = 7;
//int enableB = 9; 
  
  //both of these pins will control Motor A
  //and enableA is the switch that "enables" motor A to be on or off
  //it will be what will be used to vary motor speed


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

//this following piece of the code repeats as fast as possible

void loop() {
  // put your main code here, to run repeatedly:



//analogwrite(pin, 0-255) https://www.arduino.cc/en/Reference/AnalogWrite
  //this command below will control the percentage 
  //of voltage the motor will "receive"
  //100% is 255 as that the max value we may send; 2^8-1=255
  //and 0 is 0%, and 150/255 = 0.39 = 39%
  
  //here we will write 170/255 = 0.66 = 66% of max voltage from batteries
analogWrite(enableA, 170);//roughly 3.3v
//so in this case this commands can control each motors speed!
//but this analogWrite command can be used for other things such as controlling a servo!

//in my experiences these motors will not move at around 3 volts so if
//batteries are 5v min is around 150/255 anything below that and the motor wont move.
//but make sure that if you choose another battery say a 11.1v supply (150/255*11.1v) = 6.52 volts
//this may be WAY TO fast. these motors should be kept under 6v.

//turn one motor in one direction
  digitalWrite(switch1A, HIGH);  
  delay(1000);              // wait for a second
  digitalWrite(switch1A, LOW);   
  delay(1000);              // wait for a second

  analogWrite(enableA, 220);//220/255 = 0.86 = 86% roughly 4.3v

  //turn one motor in one direction
  digitalWrite(switch1A, HIGH);  
  delay(1000);              // wait for a second
  digitalWrite(switch1A, LOW);   
  delay(1000);              // wait for a second
  
  

}
