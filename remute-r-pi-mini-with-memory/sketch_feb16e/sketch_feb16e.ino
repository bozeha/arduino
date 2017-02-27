
#include <IRremote.h>
#include <EEPROM.h>



int RECV_PIN = 6;//global vareable for pin 2 ->used for get ir_code
IRrecv irrecv(RECV_PIN);
decode_results results;
long firsB;//global vareable for save first ir_remute code
long secondB;//global vareable for save second ir_remute code
void setup()
{

   if(EEPROMReadlong(0)!=NULL)firsB = EEPROMReadlong(0);
  

  
  pinMode(8, OUTPUT); //set pin 8 for  sending signal to open relay
  pinMode(3, INPUT_PULLUP);//set pin 3 for  recive signal from yello button
  
  
  Serial.begin(9600);//deturm print code line
 irrecv.enableIRIn(); // Start the receiver
}

void loop()//start loop
{
  //  int val = analogRead(0) / 3;
    int sensorVal = digitalRead(3);// get value from button  *if button pressed get value 0

         if (sensorVal == LOW) //if we press on button 1
         {
             getCode("sensorVal");
         }

          if(irrecv.decode(&results)) //if pressing on remute controll button we set
               {   
                Serial.println("kkk");
                Serial.println(results.value );
                 if(results.value == firsB)
                 {
                     Serial.println(digitalRead(8));
                    Serial.println("xxxxxxxxxxxxxxxxxxxx");
                    if (digitalRead(8)== LOW)
                        {
                          Serial.println("low to high");
                          digitalWrite(8, HIGH);
                        }
                    else if (digitalRead(8)== HIGH)
                        {
                          Serial.println("high to low");
                          digitalWrite(8, LOW);
                        }
                 }
                 
                irrecv.resume(); //reset the irrecv for get new var from remote control
               }

         
       
    
    
    
       
  }
void getCode(String current_string)
       { 
          irrecv.resume(); //reset the ir-current code
          Serial.println(current_string);
          Serial.println(results.value);
          Serial.println("aa");
          
          //irrecv.decode(&results);// not need to decoded


       
            for(;;) 
            {    
               if(irrecv.decode(&results))
               {        
                Serial.println(results.value);
                if(current_string == "sensorVal")
                  {
                    firsB = results.value;
                    EEPROMWritelong(0,firsB);
                    irrecv.resume();
                    break;
                  }

                
                }
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


