#include <VirtualWire.h>


int dis_in=10;
int dis_out=11;
long xxx;
long sendvar;

const int transmit_pin = 12;  
void setup()
{
   Serial.begin(9600); //FOR SIREAL.PRINT OUTPUT
  vw_set_tx_pin(transmit_pin);// set what pin will transmit
  vw_set_ptt_inverted(true); // Required for DR3100 Push-to-talk (PTT), also known as press-to-transmit, is a method of having conversations or talking on half-duplex communication lines, including two-way radio, using a momentary button to switch from voice reception mode to transmit mode.
  vw_setup(2000);   // Bits per sec
}

byte count = 1; //A byte stores an 8-bit unsigned number, from 0 to 255.

void loop()
{
  Serial.println('kkkk');
    sendvar = getulta();
  char msg[7] = {'1','1','1','1','1','1',sendvar};

  //msg[6] = count; // replace the # with current counter 
  vw_send((uint8_t *)msg, 7);//uint8_t fastest unsigned int with at least 8 bits.
  vw_wait_tx(); // Wait until the whole message is gone
  delay(1000);
  count = count + 1;
}

float getulta()
{
pinMode(dis_in,INPUT);//determine the dis_in (pin 11) as the input from the sensor 
pinMode(dis_out,OUTPUT);// determin the dis_out (pin 10) as the output to the sensor 
  digitalWrite(dis_out,LOW);//send low ping to sensor /for start the sensor (cycle for turn on sensor = low high low )
  delayMicroseconds(2);
  digitalWrite(dis_out,HIGH);//send heigh ping to sensor /for start the sensor (cycle for turn on sensor = low high low )
  delayMicroseconds(10);
   digitalWrite(dis_out,LOW);//send low ping to sensor /for start the sensor (cycle for turn on sensor = low high low )
   
xxx=  pulseIn(dis_in,HIGH);// get the sensor pulse (get the destination from sensor to object ->back and forth in feet)
xxx=xxx/2;//cancel back and forth -> convert to only one way 
xxx=xxx/30.1;//convert from feet to cm  (1 feet = 30.1 cm )



Serial.println(xxx);//print to echo the destination in cm 
  return xxx;
  
  delay(50); //just here to slow down the output for easier reading



}