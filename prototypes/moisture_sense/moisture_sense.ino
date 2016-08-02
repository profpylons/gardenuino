#define LED_PIN 13
#define MSENSE_1_PIN 0

void setup() {
  Serial.begin (9600);

}

void loop() {
  int moisture1 = analogRead(MSENSE_1_PIN);
  Serial.println(moisture1);

  delay(2000);
}
