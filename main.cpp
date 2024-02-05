#include <Arduino.h>

#define FORCE_SENSOR_PIN0 0 
#define FORCE_SENSOR_PIN1 1 
#define FORCE_SENSOR_PIN2 2 
#define FORCE_SENSOR_PIN3 3 
#define FORCE_SENSOR_PIN4 4 
#define FORCE_SENSOR_PIN5 5 
#define FORCE_SENSOR_PIN6 6 
// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  //each loop, take 7 readings read from each GPIO pin 

  Serial.write(":S0" + analogRead(FORCE_SENSOR_PIN0) );
  delay(10);

  Serial.write( ":S1" + analogRead(FORCE_SENSOR_PIN1) );
  delay(10);

  Serial.write( ":S2" + analogRead(FORCE_SENSOR_PIN2) );
  delay(10);

  Serial.write( ":S3" + analogRead(FORCE_SENSOR_PIN3) );
  delay(10);

  Serial.write( ":S4" + analogRead(FORCE_SENSOR_PIN4) );
  delay(10);

  Serial.write( ":S5" + analogRead(FORCE_SENSOR_PIN5) );
  delay(10);

  Serial.write( ":S6" + analogRead(FORCE_SENSOR_PIN6) );
  delay(10);

}

// put function definitions here:
