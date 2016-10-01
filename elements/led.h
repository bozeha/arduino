//led 

int ledPin = 9;//build a variable for the port number 

void setup()
{
pinMode(ledPin,OUTPUT);//determine the number of pin for input 
}

void loop{}
{
digitalWrite(ledPin,HIGH);
analogWrite(speakerOut,500);
delay(500);
digitalWrite(ledPin,LOW);
delay(500);


}
