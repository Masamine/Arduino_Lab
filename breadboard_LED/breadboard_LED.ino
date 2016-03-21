/* --------------------------
LED 1
-------------------------- */
/*
#define LED_PIN  10

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(150);
  digitalWrite(LED_PIN, LOW);
  delay(150);
}
*/

/* --------------------------
LED 2
-------------------------- */
// #define LED_PIN1 9
// #define LED_PIN2 10
// #define SPEED 300

// void setup() {
//   pinMode(LED_PIN1, OUTPUT);
//   pinMode(LED_PIN2, OUTPUT);
// }

// void loop() {
//   digitalWrite(LED_PIN1, LOW);
//   digitalWrite(LED_PIN2, HIGH);
//   delay(SPEED);
//   digitalWrite(LED_PIN2, LOW);
//   digitalWrite(LED_PIN1, HIGH);
//   delay(SPEED);
// }

/* --------------------------
LED 3
-------------------------- */
#define LED_PIN1 9
#define LED_PIN2 10

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  delay(1);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN1, HIGH);
  delay(20);
}