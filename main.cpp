/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram)\n visit https://esp32io.com/tutorials/esp32-force-sensor
 */
#include <Arduino.h>


//***************************SENSOR READING PINS*********************************
#define FORCE_SENSOR_PIN_X1 36 // ESP32 pin GPIO36 (ADC0): the FSR and 10K pulldown are connected to A0
#define FORCE_SENSOR_PIN_Y1 39
#define FORCE_SENSOR_PIN_Z1 34
#define FORCE_SENSOR_PIN_X2 35
#define FORCE_SENSOR_PIN_Y2 32
#define FORCE_SENSOR_PIN_Z2 33
#define FORCE_SENSOR_PIN_X3 25
#define FORCE_SENSOR_PIN_Y3 26
#define FORCE_SENSOR_PIN_Z3 27
#define FORCE_SENSOR_PIN_X4 14
#define FORCE_SENSOR_PIN_Y4 12
#define FORCE_SENSOR_PIN_Z4 13
#define FORCE_SENSOR_PIN_X5 15
#define FORCE_SENSOR_PIN_Y5 2
#define FORCE_SENSOR_PIN_Z5 4

//***************************CONTROL PINS*********************************
#define OUTPUT_PIN_ALL1 16

#define OUTPUT_PIN_A2 17
#define OUTPUT_PIN_B2 19
#define OUTPUT_PIN_C2 22

#define OUTPUT_PIN_A3 5
#define OUTPUT_PIN_B3 21
#define OUTPUT_PIN_C3 23

void readCascadedMUXs();

void readFirstFourMUX();
void readU8();
void readU1();
void readU2();
void readU3();

void setup() {

  //CONFIGURING DIGITAL OUTPUT PINS
  pinMode(OUTPUT_PIN_ALL1, OUTPUT);

  pinMode(OUTPUT_PIN_A2, OUTPUT);
  pinMode(OUTPUT_PIN_B2, OUTPUT);
  pinMode(OUTPUT_PIN_C2, OUTPUT);
  pinMode(OUTPUT_PIN_A3, OUTPUT);
  pinMode(OUTPUT_PIN_B3, OUTPUT);
  pinMode(OUTPUT_PIN_C3, OUTPUT);

  
  //STARTING SERIAL COMMUNICATION
  Serial.begin(9600);

  while(!Serial);
   
}

void loop() {
  readFirstFourMUX();
  readCascadedMUXs();
}

void readFirstFourMUX() {
  readU8();
  readU1();
  readU2();
  readU3();
}

//reading X5, Y5 Z5 for ALL 11 channels
void readCascadedMUXs() {
  int reading;

  delay(10);

  //configure to read sensors connected to U5
  Serial.print("U5 \n");

  digitalWrite(OUTPUT_PIN_A3, LOW);
  digitalWrite(OUTPUT_PIN_B3, LOW);
  digitalWrite(OUTPUT_PIN_C3, LOW);

  digitalWrite(OUTPUT_PIN_A2, LOW);
  digitalWrite(OUTPUT_PIN_B2, LOW);
  digitalWrite(OUTPUT_PIN_C2, LOW);

  //READING XO-5, Y0-5, Z0-5
  reading = analogRead(FORCE_SENSOR_PIN_X5);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y5);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z5);
  Serial.print(reading);
  Serial.print(":\n");

  delay(10);

  digitalWrite(OUTPUT_PIN_A2, HIGH);
  digitalWrite(OUTPUT_PIN_B2, HIGH);
  digitalWrite(OUTPUT_PIN_C2, HIGH);

  //READING X1-5, Y1-5, Z1-5
  reading = analogRead(FORCE_SENSOR_PIN_X5);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y5);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z5);
  Serial.print(reading);
  Serial.print(":\n");

  //configure to read sensors connected to U6
  Serial.print("U6 \n");
  
  digitalWrite(OUTPUT_PIN_A3, HIGH);
  digitalWrite(OUTPUT_PIN_B3, HIGH);
  digitalWrite(OUTPUT_PIN_C3, HIGH);

  digitalWrite(OUTPUT_PIN_A2, LOW);
  digitalWrite(OUTPUT_PIN_B2, LOW);
  digitalWrite(OUTPUT_PIN_C2, LOW);

  //READING XO-6, Y0-6, Z0-6
  reading = analogRead(FORCE_SENSOR_PIN_X5);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y5);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z5);
  Serial.print(reading);
  Serial.print(":\n");

  delay(10);

  digitalWrite(OUTPUT_PIN_A2, HIGH);
  digitalWrite(OUTPUT_PIN_B2, HIGH);
  digitalWrite(OUTPUT_PIN_C2, HIGH);

  //READING X1-6, Y1-6
  reading = analogRead(FORCE_SENSOR_PIN_X5);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y5);
  Serial.print(reading);
  Serial.print(":\n");
}


//reading X1, Y1 Z1 for both channels
void readU8() {
  int reading;
  
  delay(10);

  digitalWrite(OUTPUT_PIN_ALL1, LOW);

  Serial.print("U8 - 1 \n");
  reading = analogRead(FORCE_SENSOR_PIN_X1);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y1);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z1);
  Serial.print(reading);
  Serial.print(":\n--------------\n");

  delay(10);

  digitalWrite(OUTPUT_PIN_ALL1, HIGH);

  Serial.print("U8 - 2 \n");
  reading = analogRead(FORCE_SENSOR_PIN_X1);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y1);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z1);
  Serial.print(reading);
  Serial.print(":\n--------------\n");

}

//reading X2, Y2 Z2 for both channels
void readU1() {
  int reading;
  
  delay(10);

  digitalWrite(OUTPUT_PIN_ALL1, LOW);

  Serial.print("U1 - 1 \n");
  reading = analogRead(FORCE_SENSOR_PIN_X2);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y2);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z2);
  Serial.print(reading);
  Serial.print(":\n--------------\n");

  delay(10);

  digitalWrite(OUTPUT_PIN_ALL1, HIGH);

  Serial.print("U1 - 2 \n");
  reading = analogRead(FORCE_SENSOR_PIN_X2);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y2);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z2);
  Serial.print(reading);
  Serial.print(":\n--------------\n");
  
}

//reading X3, Y3 Z3 for both channels
void readU2() {
  int reading;
  
  delay(10);

  digitalWrite(OUTPUT_PIN_ALL1, LOW);

  Serial.print("U2 - 1 \n");
  reading = analogRead(FORCE_SENSOR_PIN_X3);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y3);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z3);
  Serial.print(reading);
  Serial.print(":\n--------------\n");

  delay(10);

  digitalWrite(OUTPUT_PIN_ALL1, HIGH);

  Serial.print("U2 - 2 \n");
  reading = analogRead(FORCE_SENSOR_PIN_X3);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y3);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z3);
  Serial.print(reading);
  Serial.print(":\n--------------\n");
  
}

//reading X4, Y4 Z4 for both channels
void readU3() {
  int reading;
  
  delay(10);

  digitalWrite(OUTPUT_PIN_ALL1, LOW);

  Serial.print("U3 - 1 \n");
  reading = analogRead(FORCE_SENSOR_PIN_X4);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y4);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z4);
  Serial.print(reading);
  Serial.print(":\n--------------\n");

  delay(10);

  digitalWrite(OUTPUT_PIN_ALL1, HIGH);

  Serial.print("U3 - 2 \n");
  reading = analogRead(FORCE_SENSOR_PIN_X4);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Y4);
  Serial.print(reading);
  Serial.print(":\n");
  reading = analogRead(FORCE_SENSOR_PIN_Z4);
  Serial.print(reading);
  Serial.print(":\n--------------\n");
  
}