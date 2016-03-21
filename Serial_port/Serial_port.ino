#define LED_PIN  13

void setup() {
  pinMode(LED_PIN, OUTPUT);

  //Arduinoのシリアルポートを9600bpsで初期化
  Serial.begin(9600);
}

void blink10() {
  int i;
  for(i = 0; i < 10; i++){
    digitalWrite(LED_PIN, HIGH);

    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}

void loop() {
  int inputchar;

  //シリアルポートから1文字読み込む。読み込むものがなければ-1を返す
  inputchar = Serial.read();

  if(inputchar !=  -1){
    switch (inputchar) {
      case 'o':
        Serial.print("LED ON\n");
        digitalWrite(LED_PIN, HIGH);
        break;
      case 'p':
        Serial.print("LED OFF\n");
        digitalWrite(LED_PIN, LOW);
        break;
      case 'b':
        Serial.print("LED Blink10\n");
        blink10();
    }
    Serial.print("Ready\n");
  }
}