#include <VirtualWire.h>

//const int led_pin = 6;
//const int transmit_pin = 12;
const int receive_pin = 11;
//const int transmit_en_pin = 3;

void setup()
{
  delay(1000);
  Serial.begin(9600); // Debugging only
  Serial.println("start");

  vw_set_rx_pin(receive_pin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);            // Bits per sec
  vw_rx_start();             // Start the receiver PLL running
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];     // build array with the bumber of elements VW_MAX_MESSAGE_LEN max number of bits that we can be received
  uint8_t buflen = VW_MAX_MESSAGE_LEN; //build var with size of VW_MAX_MESSAGE_LEN -> max number of bits that we can be received

  if (vw_get_message(buf, &buflen)) // enter the massage we receive to the array
  {
    int i;

    for (i = 0; i < buflen; i++)
    {

      Serial.print(buf[i]);// print buf array in place i , and code as hex code
      Serial.print(' ');
    }
    Serial.println(); // start new line
  }
}