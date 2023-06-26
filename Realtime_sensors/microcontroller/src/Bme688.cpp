/*
Collecting data from Adafruit BME688 board for temperature, pressure, humidity, gas resistance, and altitude.
Currently prints into serial monitor, needs complimentry script to write to a csv file.
*/

#include <Wire.h>
#inculde <SPI.h>
#include <Adafruit_Sensor.h>  
#include <Adafruit_BME688.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME688 bme; //I2C
//
void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}