#include <Servo.h> 
Servo my_servo;
void setup()
{
    Serial.begin(9600); 
    my_servo.attach(12);  
  
}
void loop()
{
    for(int pos = 0; pos < 90; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    my_servo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(60);                       // waits 15ms for the servo to reach the position 
  } 
  for(int pos = 90; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    my_servo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(60);                       // waits 15ms for the servo to reach the position 
  } 
}

