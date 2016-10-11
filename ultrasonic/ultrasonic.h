

int ledPin2= 2;
int ledPin3= 3;
int ledPin4= 4;
int ledPin5= 5;
int ledPin6= 6;
int ledPin7= 7;
int ledPin8= 8;
int ledPin9= 9;
int dis_in=11;
int dis_out=10;
long xxx;

void setup(){
  Serial.begin(9600); //FOR SIREAL.PRINT OUTPUT
pinMode(ledPin2, OUTPUT); 
pinMode(ledPin3, OUTPUT); 
pinMode(ledPin4, OUTPUT); 
pinMode(ledPin5, OUTPUT); 
pinMode(ledPin6, OUTPUT); 
pinMode(ledPin7, OUTPUT); 
pinMode(ledPin8, OUTPUT); 
 pinMode(ledPin9, OUTPUT); 

}

void loop(){
pinMode(dis_in,INPUT);//determine the dis_in (pin 11) as the input from the sensor 
pinMode(dis_out,OUTPUT);// determin the dis_out (pin 10) as the output to the sensor 
  digitalWrite(dis_out,LOW);//send low ping to sensor /for start the sensor (cycle for turn on sensor = low high low )
  delayMicroseconds(2);
  digitalWrite(dis_out,HIGH);//send heigh ping to sensor /for start the sensor (cycle for turn on sensor = low high low )
  delayMicroseconds(10);
   digitalWrite(dis_out,LOW);//send low ping to sensor /for start the sensor (cycle for turn on sensor = low high low )
   
xxx=  pulseIn(dis_in,HIGH);// get the sensor pulse (get the destination from sensor to object ->back and forth in feet)

xxx=xxx/2;//cancel back and forth -> convert to only one way 
xxx=xxx/30.1;//convert from feet to cm  (1 feet = 30.1 cm )



Serial.println(xxx);//print to echo the destination in cm 
  
  
  delay(50); //just here to slow down the output for easier reading
int my_leds[8]={ledPin2,ledPin3,ledPin4,ledPin5,ledPin6,ledPin7,ledPin8,ledPin9};


if (xxx>100)xxx =100;
int lop_end=xxx/10;


for(int re_set=10;re_set!=lop_end;re_set--)digitalWrite(my_leds[re_set], LOW);
                for(int lop=0;lop!=lop_end;lop++)
                {
                  
              digitalWrite(my_leds[lop], HIGH);
            delay(50);  
                          
		}
              
}