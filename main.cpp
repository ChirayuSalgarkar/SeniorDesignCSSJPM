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
}

void loop() {
  //each loop, array of 7 reading read from each GPIO pin 
  int reading[7];
 
  for(int i =0; i < 7; i++)
  {
    delay(100);
    switch (i) {
      case 0:
        //reading[i] = analogRead(FORCE_SENSOR_PIN0);
        Serial.write(analogRead(FORCE_SENSOR_PIN0));
        break;

      case 1:
        //reading[i] = analogRead(FORCE_SENSOR_PIN1);
        Serial.write("S1:" + analogRead(FORCE_SENSOR_PIN1));
        break;
      
      case 2:
        Serial.write("S1:" + analogRead(FORCE_SENSOR_PIN2));
        //reading[i] = analogRead(FORCE_SENSOR_PIN2);
        break;

       case 3:
        // reading[i] = analogRead(FORCE_SENSOR_PIN3);
        Serial.write("S1:" + analogRead(FORCE_SENSOR_PIN3));
        break;

      case 4:
        // reading[i] = analogRead(FORCE_SENSOR_PIN4);
        Serial.write("S1:" + analogRead(FORCE_SENSOR_PIN4));
        break;
      
      case 5:
        // reading[i] = analogRead(FORCE_SENSOR_PIN5);
        Serial.write("S1:" + analogRead(FORCE_SENSOR_PIN5));
        break;

      case 6:
        // reading[i] = analogRead(FORCE_SENSOR_PIN6);
        Serial.write("S1:" + analogRead(FORCE_SENSOR_PIN6));
        break;
    }

    
    
  }
}

// put function definitions here:
