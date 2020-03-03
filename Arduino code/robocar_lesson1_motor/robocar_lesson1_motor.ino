

  //lesson 1 
  
  //basic switching of motor direction
  //This is a simple piece of code
  //that will control the motors
  //this for the robot car with the arduino nano 
  //and uno if connected properly
  // anything behind "//" is a comment!!!
  //which MEANS IT IS NOT CODE!!!
  
  //you can type whatever you want!!!!
  //so lets begin by giving descriptive names to
  //the pins on the nano that we will be using
//these two switches control only one motor well call it Motor A

//Motor A
int switch1A = 13; //connected on Arduino nano to pin 13 
int switch2A = 12; //connected on Arduino nano to pin 12
//int https://www.arduino.cc/en/Reference/Int

//just in case you finished this 
//lesson try to use the second motor
//just remove the // 

//Motor B 
//int switch1B = 8;
//int switch2B = 7;


void setup() {
  // put your setup code here inside the {} curly braces, to run once:
//https://www.arduino.cc/en/Reference/Setup
  //this following piece of codes lets the arduino know
  //in what way you wish to use the pins as,
  //either inputs or outputs
  //either listening for a signal 
  //or sending a signal, as a switch "off or on"
  
  //in this case we are using the pins are 
  //switches to control the motor direction
 pinMode(switch1A, OUTPUT);
 pinMode(switch2A, OUTPUT);
 //https://www.arduino.cc/en/Reference/PinMode
//and you are done setting up  
}


//this following piece of the code repeats as fast as possible
//this is the main loop or the main program the arduino runs
void loop() {
  
  // put your main code here, to run repeatedly:
  //https://www.arduino.cc/en/Reference/Loop
  
//turn one motor in one direction 
//https://www.arduino.cc/en/Reference/DigitalWrite

  digitalWrite(switch1A, HIGH); //1 0
  delay(1000);              // wait for a second
//now you should type what direction it goes into
//______
  
  //https://www.arduino.cc/en/Reference/Delay
  //Quick note on delay it stops completely the arduino
  //that means the arduino will not continue from the code until the
  //delay time period is over so if I said delay(100000);
  //the arduino would not do anyhting for a long long time
  
  digitalWrite(switch1A, LOW); // 0 0  
  delay(1000);              // wait for a second
  
//now you should type what direction it goes into
//______

//now turn the opposite direction
  digitalWrite(switch2A, HIGH); //0 1  
  delay(1000);              // wait for a second 
  digitalWrite(switch2A, LOW); //0 0    
  delay(1000);              // wait for a second
//type what direction it goes into
//______
//Basically with 2 switches you have 4 possible scenarios
//1 0 one rotation
//0 1 opposite rotation
//1 1 stop
//0 0 stop
  
  
//end code!
}
