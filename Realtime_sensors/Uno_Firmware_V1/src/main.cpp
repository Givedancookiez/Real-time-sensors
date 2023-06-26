#include <Arduino.h>
#include "bme68xLibrary.h"
#include "Adafruit_BME680.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_I2CDevice.h"

#define BME_SDA A4
#define BME_SCK A5
#define Serial_Speed 19200 //double check this later

Adafruit_BME680 bme; //I2C


float altitude(const float Sea_Level_Pressure= 1013.25)
{
}
float Calculated_Altitude(float pressure, bool metric = true, float Sea_Level_Pressure = 101325)
{
  float altitude = NAN;
  if (!isnan(pressure) && !isnan(Sea_Level_Pressure)){
    altitude = 1000 * (Sea_Level_Pressure - pressure) / 3386.3752577878;
  }
  return metric ? altitude * 0.3048 : altitude;
}

float temperatureCompensatedAltitude(int32_t pressure, float temp=21.0 /*Celsius*/, float seaLevel=1013.25)
{

}

void setup() {

}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}