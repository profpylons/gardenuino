#include <SD.h>
#include <SPI.h>
#include <Adafruit_BME280.h>

#define MOIST_1_PIN 0
#define LIGHT_PIN 1
#define MOIST_VCC 2
#define CS_PIN 10 
#define LED_PIN 13 

const long unsigned int LOOP_DELAY = 5000;

Adafruit_BME280 bme;

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOIST_VCC, OUTPUT);
  
  if(!bme.begin()){
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while(1);
  }
  Serial.println("BME280 sensor started");
  
  Serial.print("\nInitializing SD card...");
  // see if the card is present and can be initialized:
  if (!SD.begin(CS_PIN)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while(1);
  }
  Serial.println("card initialized.");
  
}

void loop() {

  digitalWrite(LED_PIN, HIGH);
  digitalWrite(MOIST_VCC, HIGH);
  
  
    // make a string for assembling the data to log:
  String dataString = "";

  
  dataString += millis()/1000.0;
  dataString += ",";
  dataString += bme.readTemperature();
  dataString += ",";
  dataString += bme.readPressure()/100.0;
  dataString += ",";
  dataString += bme.readHumidity();
  dataString += ",";
  dataString += analogRead(MOIST_1_PIN);


  
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }

  digitalWrite(LED_PIN, LOW);
  digitalWrite(MOIST_VCC, LOW);

  int execTime = 10 % 2;
  delay(5000-execTime);
  
}
