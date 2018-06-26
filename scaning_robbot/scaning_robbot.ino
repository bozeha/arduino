#include <Servo.h> 
Servo my_servo;
int mov_s;

int tilt=13;     //connect tilt to D2
int dis_in=11;
int dis_out=10;
int LED=2 ;
int LED2=3;
int const alert_pin =8; //                
int const Red = 7; //                                                                                                                                                         pin 3 
int const Blue = 5; // pin 4
int const Green = 6; // pin 5

long ultra=0;
void setup()
{
    pinMode(LED2,OUTPUT);
   pinMode(LED, OUTPUT);
pinMode(Red,OUTPUT);
pinMode(Blue,OUTPUT);
pinMode(Green,OUTPUT);
   pinMode(tilt, INPUT);  
    Serial.begin(9600); 
    my_servo.attach(12);  
  pinMode(dis_in,INPUT);//determine the dis_in (pin 11) as the input from the sensor 
pinMode(dis_out,OUTPUT);// determin the dis_out (pin 10) as the output to the sensor 
pinMode(alert_pin,OUTPUT);

}
void loop()
{

if (digitalRead(tilt)==HIGH) //when the digital output value of tilt is high, turn on the LED.
   {
     
         for(int pos = 0; pos <180; pos += 1)  // goes from 0 degrees to 180 degrees 
		  {                                  // in steps of 1 degree 
                      digitalWrite(LED, HIGH);   
			my_servo.write(pos);    			// tell servo to go to position in variable 'pos' 
			delay(200);                       // waits 15ms for the servo to reach the position 
                    digitalWrite(LED, LOW);
                    test_movment();
					
		  } 
	

   }

   /*
  for(int pos = 90; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    my_servo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(60);                       // waits 15ms for the servo to reach the position 
  } 
    
   if (digitalRead(tilt)==LOW)  //when the digital output value of tilt is low, turn off the LED.
   {
     digitalWrite(LED, LOW);
   } 
*/

}


void start_ultra()
{
 digitalWrite(dis_out,LOW);//send low ping to sensor /for start the sensor (cycle for turn on sensor = low high low )
  delayMicroseconds(2);
  digitalWrite(dis_out,HIGH);//send heigh ping to sensor /for start the sensor (cycle for turn on sensor = low high low )
  delayMicroseconds(10);
   digitalWrite(dis_out,LOW);//send low ping to sensor /for start the sensor (cycle for turn on sensor = low high low )

}



bool test_movment()
{
 long xxx;
 xxx=get_ultra_var();

Serial.println(xxx);

             if(xxx<30)
             {
                       for(int test_if_mov=lop_move_fix();test_if_mov==1; test_if_mov=lop_move_fix())
                     {      
                       Serial.println("ultra=");
                       Serial.println(xxx);
                         RGB(Red); 
                          alert_alert();
                          RGB(Blue); 
                          RGB(Green); 

                     }
            
             }

}

void RGB(int x) 

              {

            digitalWrite(x, HIGH);
            Serial.println(x);
            delay(500);
            digitalWrite(x, LOW);

      }
              
     void alert_alert()
     {
       
       tone(alert_pin, 714/4, 1000);//calculate 350hz -> 1000000/350=2857 (2587 cycles in one second)  2857/4 =714 

       
     }
              
              
     long get_ultra_var()
     {
       long xxx;
 start_ultra();
 xxx=  pulseIn(dis_in,HIGH);
 xxx=xxx/2;//back and forth
xxx=xxx/30.1;//from feet to cm
return xxx;      
       
     }


bool lop_move_fix()
    {
       long xxx;
      int yes_mov=0 ,no_mov=0;
        for(int lop2=0;lop2<5;lop2++) 
            {
                xxx=get_ultra_var();
                if (xxx<=30)yes_mov++;
                else no_mov++;
              }    
        if (yes_mov>no_mov)return true;
        else return false;
      
    }


