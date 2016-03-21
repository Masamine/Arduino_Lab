/* --------------------------
ANALOG INPUT OUTPUT
-------------------------- */

void setup() {
  Serial.begin(9600);
}

void loop() {
  int i;

  i = analogRead(0);

  Serial.print(i, DEC);
  Serial.print("\n");

  delay(1000);
}
