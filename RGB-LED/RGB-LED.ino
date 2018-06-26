//Picture of The code
//int prevR = 0, prevG = 0, prevB = 0; // all of the previous RGB values
int const Red = 7; //                                                                                                                                                         pin 3 
int const Blue = 5; // pin 4
int const Green = 6; // pin 5

void setup()
{
pinMode(Red,OUTPUT);
pinMode(Blue,OUTPUT);
pinMode(Green,OUTPUT);

} // sets up the program
void loop() { //main loop of the program
Serial.begin(9600);
 // RGB(255, 255, 255); // this calls the RGB function

  RGB(Red); 

  RGB(Blue); 

  RGB(Green); 

 
}


void RGB(int x) {



digitalWrite(x, HIGH);
Serial.println(x);
delay(1000);
digitalWrite(x, LOW);

}
