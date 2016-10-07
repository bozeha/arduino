/////////////////////////////////////////////////////////////////
// Created by Kevin Elsenberger                                //
// June 2, 2013                                                //
// elsenberger.k at gmail.com                                   //
/////////////////////////////////////////////////////////////////


#include <EEPROM.h> //Needed to access the eeprom read write functions

long number1 = 123456789;
long number2 = 987654321;

//This function will write a 4 byte (32bit) long to the eeprom at
//the specified address to address + 3.
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

//This function will return a 4 byte (32bit) long from the eeprom
//at the specified address to address + 3.
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

void setup()
      {
      Serial.begin(9600);
      }

void loop()
      {
      //Adding a delay in order to have the time to open the
      //Arduino serial monitor.
      delay(5000);

      
      long address=0;//Starting at the first byte on the eeprom.

      //Writing first long.
      EEPROMWritelong(address, number1);//sending first place in memory 0 and the number to functoin :EEPROMWritelong
      address+=4;// every number saved in 4 bits ...so jumping 4 bits to second place
      EEPROMWritelong(address, number2);//sending second place in memory 4 and the number2 to functoin :EEPROMWritelong
      address+=4;


      Serial.println("If numbers are equals, it's working !");
      Serial.print(number1);
      Serial.print(" and ");
      //Readind and sending first long.
      Serial.println(EEPROMReadlong(0));

      Serial.print(number2);
      Serial.print(" and ");
      //Readind and sending second long.
      Serial.println(EEPROMReadlong(4));
      }
 