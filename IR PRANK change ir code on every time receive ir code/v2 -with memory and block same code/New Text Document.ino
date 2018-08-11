#include <IRremote.h>  
#include <EEPROM.h>


IRsend irsend;
int flag=0;
int ledPin = 8;
int buttonPin = 6; // pin for button control
int RECV_PIN = 2;// pin for receive ir code 
long getTempCode; // save the ir code on long var
long getTempCode2; // if pressing on the same button that the prank set to ignor
IRrecv irrecv(RECV_PIN);// pin for receive ir code
decode_results results;  //for receiving ir code 
decode_results results2;  //for receiving ir code 

void setup()
{
  if(EEPROMReadlong(0)!=NULL)getTempCode = EEPROMReadlong(0);
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
          EEPROMWritelong(0,getTempCode);
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
 //Serial.println("startThePrank");
  
 if(irrecv.decode(&results2)) 
 {
              
      delay(250);//// must have delay for geting the right code 
      
      getTempCode2 =results2.value;              
      if(getTempCode!=getTempCode2)
      {
        Serial.println("not same like main code -> run ir transmitter");
        irsend.sendNEC(getTempCode, 32); //use the transmitter led to send the code we received 
      }
     
    irrecv.resume(); // Receive the next value
    irrecv.enableIRIn();
 }
   
}




    long EEPROMReadlong(long address)
        {
        //Read the 4 bytes from the eeprom memory.
        long four = EEPROM.read(address);//read the first part of the number 
        long three = EEPROM.read(address + 1);//read the second part of the number 
        long two = EEPROM.read(address + 2);//read the thred part of the number 
        long one = EEPROM.read(address + 3);//read the firth part of the number 
        //Return the recomposed long by using bitshift.
        return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
        }


        void EEPROMWritelong(int address, long value)
      {
      //Decomposition from a long to 4 bytes by using bitshift.
      //One = Most significant -> Four = Least significant byte
      byte four = (value & 0xFF);//create byte var and enter part of the number and null the rest bits 
      byte three = ((value >> 8) & 0xFF);//create byte var and enter part of the number and null the rest bits 
      byte two = ((value >> 16) & 0xFF);//create byte var and enter part of the number and null the rest bits 
      byte one = ((value >> 24) & 0xFF);//create byte var and enter last part of the number and null the rest bits 

      //Write the 4 bytes into the eeprom memory.
      EEPROM.write(address, four);//write part of the number to memory 
      EEPROM.write(address + 1, three);//write part of the number to memory 
      EEPROM.write(address + 2, two);//write part of the number to memory 
      EEPROM.write(address + 3, one);//write part of the number to memory 
      }
