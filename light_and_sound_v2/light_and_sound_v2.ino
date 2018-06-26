int LDR_Pin = A0; //analog pin 0
int ledPin2= 9;
int statePin = LOW;
void setup(){
  Serial.begin(9600);
   pinMode(ledPin2, OUTPUT); 
}

void loop(){
  int v = analogRead(LDR_Pin); 

  Serial.println(v);
  delay(550); //just here to slow down the output for easier reading
	digitalWrite(ledPin2,LOW);
  if (v<20)
		{
		tone(8, 1190,550);


      statePin = !statePin;
    digitalWrite(ledPin2, statePin);  
		
              }
}
