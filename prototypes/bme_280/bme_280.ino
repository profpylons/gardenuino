#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11 
#define BME_CS 10
 
Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

void setup() {
  Serial.begin(9600);
  
  if(!bme.begin()){
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while(1);
  }
  Serial.println("BME280 sensor started");

}

void loop() {
  
  float temp = bme.readTemperature();
  float pres = bme.readPressure();
  float humid = bme.readHumidity();
  
  Serial.print("Temperature= ");
  Serial.print(temp);
  Serial.print("*C  ");  
  
  Serial.print("Pressure= ");
  Serial.print(pres / 100.0);
  Serial.print("hPa  ");
  
  Serial.print("Humidity= ");
  Serial.print(humid);
  Serial.println("%");

  delay(2000);

}
