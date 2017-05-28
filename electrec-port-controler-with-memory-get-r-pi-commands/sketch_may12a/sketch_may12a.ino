#include <EEPROM.h>

int address = 0;
byte value;
String command ;
  
  int pins_array[10];
void setup()
{

  
  
  Serial.begin(9600);//deturm print code line
  pinMode(2, INPUT_PULLUP);//set pin 3 for  recive signal from yello button
  pinMode(3, INPUT_PULLUP);//set pin 3 for  recive signal from yello button
  pinMode(4, INPUT_PULLUP);//set pin 3 for  recive signal from yello button
  pinMode(5, INPUT_PULLUP);//set pin 3 for  recive signal from yello button
  pinMode(6, INPUT_PULLUP);//set pin 3 for  recive signal from yello button
  pinMode(7, INPUT_PULLUP);//set pin 3 for  recive signal from yello button

  pinMode(8, OUTPUT); //set pin 8 for  sending signal to open relay
  pinMode(9, OUTPUT); //set pin 8 for  sending signal to open relay
  pinMode(10, OUTPUT); //set pin 8 for  sending signal to open relay
  pinMode(11, OUTPUT); //set pin 8 for  sending signal to open relay
  pinMode(12, OUTPUT); //set pin 8 for  sending signal to open relay
  pinMode(13, OUTPUT); //set pin 8 for  sending signal to open relay


  for (int i = 2; i < 8; i++)
  {
    value = EEPROM.read(i);
    if ((value !=0 )&&(value !=1))
    {
      Serial.println("null");
      Serial.println(i);
       EEPROM.write(i, 0);
       pins_array[i] = 0 ;
    }
    else
    {
      Serial.println("not null");
      Serial.println(i);
       if(value==1)
        {
          
          Serial.println("val 1");
          pins_array[i]= value;
            digitalWrite(i+6, HIGH);     
           
        }
        else if(value==0)
        {
          Serial.println("val 0");
          pins_array[i]= value;
            digitalWrite(i+6, LOW);     
           
        }
    }  
  }
  




}

void loop()//start loop
{
  int buttonNum1 = digitalRead(2);// get value from button  *if button pressed get value 0 light button
  int buttonNum2 = digitalRead(3);// get value from button  *if button pressed get value 0 fan button
  int buttonNum3 = digitalRead(4);// get value from button  *if button pressed get value 0 skimmer button
  int buttonNum4 = digitalRead(5);// get value from button  *if button pressed get value 0 wave button
  int buttonNum5 = digitalRead(6);// get value from button  *if button pressed get value 0 upload water button
  int buttonNum6 = digitalRead(7);// get value from button  *if button pressed get value 0
  
  if(Serial.available()) // only if i receve string from r pi inter the if
  {
    command = Serial.readString();   // get command from r pi      
  }      
          if ((buttonNum1 == LOW)||(command == "last")) //if we press on button 1
         {
           Serial.println("yyyyyyyyyyy");
          Serial.println("555555555555");
             pins_array[2] = (pins_array[2] == 0) ? 1 : 0;
             EEPROM.write(2, pins_array[2]);
             replaceRelay(8,pins_array[2]);
         command= "";           
             
         }
          if ((buttonNum2 == LOW)||(command == "upload")) //if we press on button 1
         {
          Serial.println("6666666666");
             pins_array[3] = (pins_array[3] == 0) ? 1 : 0;
             EEPROM.write(3, pins_array[3]);
             replaceRelay(9,pins_array[3]);
             command= "";
         }
          if ((buttonNum3 == LOW)||(command == "wave")) //if we press on button 1
         {
          Serial.println("777777777");
             pins_array[4] = (pins_array[4] == 0) ? 1 : 0;
             EEPROM.write(4, pins_array[4]);
             replaceRelay(10,pins_array[4]);
             command= "";
             
         }
          if ((buttonNum4 == LOW)||(command == "skimmer")) //if we press on button 1
         {
             pins_array[5] = (pins_array[5] == 0) ? 1 : 0;
             EEPROM.write(5, pins_array[5]);
             replaceRelay(11,pins_array[5]);
             command= "";
         }
          if ((buttonNum5 == LOW)||(command == "fan")) //if we press on button 1
         {
             pins_array[6] = (pins_array[6] == 0) ? 1 : 0;
             EEPROM.write(6, pins_array[6]);
             replaceRelay(12,pins_array[6]);
             command= "";
         }
          if ((buttonNum6 == LOW)||(command == "light")) //if we press on button 1
         {
             pins_array[7] = (pins_array[7] == 0) ? 1 : 0;
             EEPROM.write(7, pins_array[7]);
             replaceRelay(13,pins_array[7]);
             command= ""; // null the command variable
         }

}

void replaceRelay(int port,int value)
{

    if (value == 1)
      {
            Serial.println(port);
          digitalWrite(port, HIGH);    
        
      }
    else if (value==0)
    {
          Serial.println(port);
        digitalWrite(port, LOW);    
        
    }
    delay(200);
}



