

int isObstaclePin = 2;  // input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() {
  // declar port 2 as input
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //isObstacle gets the value from pin 2  -> HIGHT no obstacle LOW there is obstacle
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
      Serial.println("there is obstacle");
  }
  else
  {
     Serial.println("no obstacle ");
  }
  delay(200);
}
