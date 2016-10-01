const int analogInPin = A0;
float sensorValue = 0;


void setup()
{
    Serial.begin(9600);


}

void loop()
{
    sensorValue = analogRead(analogInPin);
    Serial.print("voltage Output = ");
    Serial.println(sensorValue*5/1023);
    Serial.println(" ");
    delay(100);
}