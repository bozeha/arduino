//PRIN


int x =0;
char* y[]={"hello world"};
void setup()
{
/*
bytes x bits_per_character / bits_per_second
So in your case:

32000 x 10 / 9600 = 33.333(recurring) seconds.
Traditionally however 32Kb refers to 32 x 1024 bytes, so in that case:

32 x 1024 x 10 / 9600 = 34.1333(recurring) seconds.

*/
Serial.begin(9600);//Bit rate
  Serial3.begin(4800);
}

void loop()
{



			Serial.println(x);//write in new  line
			Serial.println(x);//write in new  line
         		Serial.println(x);//write in new  line
			Serial.println(x);//write in new  line
			Serial.println(x);//write in new  line
                        delay(500);
			
		Serial.println(y[0]);//write string

                        delay(500);
                			Serial.print(x);//write in the same row 
                        		Serial.print(x);//write in the same row 
                        		Serial.print(x);//write in the same row 
                        		Serial.print(x);//write in the same row 
                        delay(500);

}
