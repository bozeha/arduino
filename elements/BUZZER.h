int pinOut = 8;
int freq = 110;
int duration = 1000;
void setup() {
  pinMode(pinOut, OUTPUT);
  /*
  //for(int i=0; i<4 ; i++) {
   tone(pinOut, freq, duration);
   //int pauseBetweenNotes = duration * 1.30;
   //delay(pauseBetweenNotes);
   delay(1500);
   noTone(8);
   //}
   */
}

void loop() {  

  for(int x=0;x!=1000;x++)//1000 cycles for one beep
  {
    digitalWrite(pinOut,HIGH);
    delayMicroseconds(1428);// calculate 350hz -> 1000000/350=2857 (2587 cycles in one second)  2857/2 =1428 (cycle = high low (on-off))
	digitalWrite(pinOut,LOW);
    delayMicroseconds(1428);// 1 cycle -> 2857 microsecond  -> 1/2 *1microsecond for HIGH and 1/2 *1microsecond for LOW

  }
  delay(500);
  for(int x=0;x!=1000;x++)
  {
    digitalWrite(pinOut,HIGH);
    delayMicroseconds(902);
    digitalWrite(pinOut,LOW);
    delayMicroseconds(902);

  }
  delay(500);
  for(int x=0;x!=1000;x++)
  {
    digitalWrite(pinOut,HIGH);
    delayMicroseconds(851);
    digitalWrite(pinOut,LOW);
    delayMicroseconds(851);

  }
  
  
  
  
  delay(500);
  for(int x=0;x!=1000;x++)
  {
    digitalWrite(pinOut,HIGH);
    delayMicroseconds(803);
    digitalWrite(pinOut,LOW);
    delayMicroseconds(803);

  }
  delay(1500);

   tone(pinOut, 714/4, 1000);//calculate 350hz -> 1000000/350=2857 (2587 cycles in one second)  2857/4 =714 
  

 //tone(pinOut, 2272, 100);

//for(int i=0; i<4 ; i++) {
  
   //int pauseBetweenNotes = duration * 1.30;
   //delay(pauseBetweenNotes);
     //delay(1500);
   //noTone(8);
//}
for(;;);

}
