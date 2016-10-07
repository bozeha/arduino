
#include <IRremote.h>


int RECV_PIN = 6;//global vareable for pin 11 ->used for get ir_code
IRrecv irrecv(RECV_PIN);
decode_results results;
long firsB;//global vareable for save first ir_remute code
long secondB;//global vareable for save second ir_remute code
void setup()
{
  pinMode(9, OUTPUT); //set pin 8 for  sending signal to open relay
  //pinMode(9, OUTPUT);//set pin 9 for  sending signal to torn on light red
  pinMode(4, INPUT_PULLUP);//set pin 12 for  recive signal from yello button
  pinMode(5, INPUT_PULLUP);//set pin 13 for  recive signal from red button
  
  Serial.begin(9600);//deturm print code line
 irrecv.enableIRIn(); // Start the receiver
}

void loop()//start loop
{
    int sensorVal = digitalRead(5);// get value from button red *if button pressed get value 0
    int sensorVal2 = digitalRead(4);// get value from button yello *if button pressed get value 0
 
    
    
    
         
         if (sensorVal2 == LOW) //if we press on button 1
         {
             getCode("sensorVal");
         }

          if(irrecv.decode(&results)) //if pressing on remut controll button we set
               {   
                Serial.println("kkk");
                Serial.println(results.value );
                 if(results.value == firsB)
                 {
                     Serial.println(digitalRead(2));
                    Serial.println("xxxxxxxxxxxxxxxxxxxx");
                    if (digitalRead(9)== LOW)
                        {
                          Serial.println("low to high");
                          digitalWrite(9, HIGH);
                        }
                    else if (digitalRead(9)== HIGH)
                        {
                          Serial.println("high to low");
                          digitalWrite(9, LOW);
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
                    irrecv.resume();
                    break;
                  }
                if(current_string == "sensorVal2")
                  {
                    secondB = results.value;
                    irrecv.resume();
                    break;
                  }
                
                }
             }


                  

              }

    
