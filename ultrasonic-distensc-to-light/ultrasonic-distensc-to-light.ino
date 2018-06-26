
//int LDR_Pin = A0; //analog pin 0
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
//int statePin = HIGH;
void setup(){
  Serial.begin(9600); 
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
pinMode(dis_in,INPUT);
pinMode(dis_out,OUTPUT);  
  digitalWrite(dis_out,LOW);
  delayMicroseconds(2);
  digitalWrite(dis_out,HIGH);
  delayMicroseconds(10);
   digitalWrite(dis_out,LOW);
   
xxx=  pulseIn(dis_in,HIGH);

xxx=xxx/2;//back and forth
xxx=xxx/30.1;//from feet to cm


//  xxx=xxx/29;
Serial.println(xxx);
  
  
//  int v = analogRead(LDR_Pin); 

// Serial.println(v);
  delay(50); //just here to slow down the output for easier reading
int my_leds[8]={ledPin2,ledPin3,ledPin4,ledPin5,ledPin6,ledPin7,ledPin8,ledPin9};
//int my_leds[9]={"ledPin0","ledPin1","ledPin2","ledPin3","ledPin4","ledPin5","ledPin6","ledPin7","ledPin8"};

if (xxx>100)xxx =100;
int lop_end=xxx/10;


for(int re_set=10;re_set!=lop_end;re_set--)digitalWrite(my_leds[re_set], LOW);
                for(int lop=0;lop!=lop_end;lop++)
                {
                  
              digitalWrite(my_leds[lop], HIGH);
         //     Serial.println(lop);
            delay(50);  
                          
		}
              
}
