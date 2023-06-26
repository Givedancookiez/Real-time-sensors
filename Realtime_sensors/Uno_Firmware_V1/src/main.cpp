#include <Arduino.h>
#include "bme68xLibrary.h"
#include "Adafruit_BME680.h"
#include "Adafruit_Sensor.h"

#define BME_SDA A4
#define BME_SCK A5
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; //I2C


void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.print(F("BME688 async test"));
  
   if (!bme.begin()) {
    Serial.println(F("Could not find a valid BME688 sensor, check wiring!"));
    while (1);
  }

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void loop() {
unsigned long endtime = bme.beginReading();

if (endtime == 0) {
  Serial.println(F("Failed to begin reading :("));
  return;
}

Serial.print(F("Reading started at"));
Serial.print(millis());
Serial.print(F(" and will finish at "));
Serial.println(endtime);

delay(50);

if (!bme.endReading()) {
  Serial.println(F("Failed to complete reading :("));
  return;
}
Serial.print(F("Reading completed at "));
  Serial.println(millis());

  Serial.print(F("Temperature = "));
  Serial.print(bme.temperature);
  Serial.println(F(" *C"));

  Serial.print(F("Pressure = "));
  Serial.print(bme.pressure / 100.0);
  Serial.println(F(" hPa"));

  Serial.print(F("Humidity = "));
  Serial.print(bme.humidity);
  Serial.println(F(" %"));

  Serial.print(F("Gas = "));
  Serial.print(bme.gas_resistance / 1000.0);
  Serial.println(F(" KOhms"));

  Serial.print(F("Approx. Altitude = "));
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(F(" m"));

  Serial.println();
  delay(2000);
}
