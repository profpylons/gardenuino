
#define RELAY_4_PIN 4
#define LED_PIN 13

void setup() {
  
  Serial.begin (9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELAY_4_PIN, OUTPUT);
  
}

void loop() {
  digitalWrite(LED_PIN, LOW);
  digitalWrite(RELAY_4_PIN, LOW); // Closed!! Relay 70mA
  
  delay(2000); // Valve 300mA

  digitalWrite(LED_PIN, HIGH);
  digitalWrite(RELAY_4_PIN, HIGH);

  delay(5000);

  
}
