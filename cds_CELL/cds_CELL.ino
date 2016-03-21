/* --------------------------
cdsセル　光センサー
暗いところにおくとセンサー自体の抵抗値が大きくなり、明るいところに置くと抵抗値が低くなる
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
