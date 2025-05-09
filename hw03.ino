#include <Arduino.h>

const int ledPin = 23;
const int sensorPin = 34;

void setup() {
  Serial.begin(115200);
  ledcAttach(ledPin, 5000, 8);
}

void loop() {
  int sensorVal = analogRead(sensorPin);           
  int pwmVal = map(sensorVal, 0, 4095, 0, 255);   
  int inverted = 255 - pwmVal;                      

  ledcWrite(ledPin, inverted);                    
  
  Serial.printf("Sensor: %d → Brightness: %d (inverted %d)\n", sensorVal, pwmVal, inverted);
  delay(200);
}
