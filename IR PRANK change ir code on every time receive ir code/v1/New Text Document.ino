#include <IRremote.h>  
IRsend irsend;
int flag=0;
int ledPin = 8;
int buttonPin = 6; // pin for button control
int RECV_PIN = 2;// pin for receive ir code 
long getTempCode; // save the ir code on long var
IRrecv irrecv(RECV_PIN);// pin for receive ir code
decode_results results;  //for receiving ir code 

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buttonPin, LOW);
  digitalWrite(ledPin, LOW);
}


void loop() {


   if (digitalRead(buttonPin)== HIGH) { // if button pressed start receiving code loop
    // !!!! becuse we use ir receiver and ir transmitter we need to restart the ir receiver every time ir trnsmitter is used
  digitalWrite(buttonPin, LOW);
    delay (250);
    irrecv.enableIRIn();  
    while(flag !=1)
    {
           digitalWrite(ledPin, HIGH); 
           Serial.println("white for flag !!");
           if(irrecv.decode(&results)) { /// receive ir code 
          Serial.println(results.value);    
          Serial.println(results.value, HEX);       
          getTempCode=results.value;        
          irrecv.resume(); // Receive the next value
          flag =1; // exit loop
          digitalWrite(ledPin, LOW);
          delay (250);
        }     
    }
       
       flag= 0;
   }

   
  startThePrank();

}


void startThePrank()
{
 Serial.println("startThePrank");
   
 if(irrecv.decode(&results)) 
 {
          
       // Serial.println(getTempCode);
      Serial.println(getTempCode,HEX); //Volume Down Code
     irsend.sendNEC(getTempCode, 32); //use the transmitter led to send the code we received 
    irrecv.resume(); // Receive the next value
    irrecv.enableIRIn();
 }
}

