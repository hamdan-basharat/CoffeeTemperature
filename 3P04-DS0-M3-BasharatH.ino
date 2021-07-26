//Hamdan Basharat - 3P04 - coffeetemp_ESP32
  int inputPin = 37; //initializing variables
  float ADCValue;
  float R;
  float T;
  float To = 298.15;
  int Ro = 10000;
  int B = 3892;
  
void setup() {
  Serial.begin(115200);
}

void loop() {
  ADCValue = analogRead(inputPin); //reads the input pin
  R = Ro/(4095.0/ADCValue-1.0); //converts read value to a resistance
  T = (1/((1.0/To)+(1.0/B)*log(R/Ro)))-282.15; //Steinhart-Hart equation to calc temperature
  Serial.println(T); //outputs temperature to screen
  delay(500);
}
