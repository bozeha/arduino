#include <VirtualWire.h>


const int transmit_pin = 12;  
void setup()
{
  vw_set_tx_pin(transmit_pin);// set what pin will transmit
  vw_set_ptt_inverted(true); // Required for DR3100 Push-to-talk (PTT), also known as press-to-transmit, is a method of having conversations or talking on half-duplex communication lines, including two-way radio, using a momentary button to switch from voice reception mode to transmit mode.
  vw_setup(2000);   // Bits per sec
}

byte count = 1; //A byte stores an 8-bit unsigned number, from 0 to 255.

void loop()
{
  char msg[7] = {'h','e','l','l','o',' ','#'};

  msg[6] = count; // replace the # with current counter 
  vw_send((uint8_t *)msg, 7);//uint8_t fastest unsigned int with at least 8 bits.
  vw_wait_tx(); // Wait until the whole message is gone
  delay(1000);
  count = count + 1;
}