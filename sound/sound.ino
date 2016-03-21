/* --------------------------
SOUND
-------------------------- */
#define PIEZO 13
#define DELAY1 400
#define DELAY2 500

void setup() {
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  int i;
  for(i = 0; i < 400; i++){
    digitalWrite(PIEZO, HIGH);
    delayMicroseconds(DELAY1);
    digitalWrite(PIEZO, LOW);
    delayMicroseconds(DELAY1);
  }
  for(i = 0; i < 500; i++){
    digitalWrite(PIEZO, HIGH);
    delayMicroseconds(DELAY2);
    digitalWrite(PIEZO, LOW);
    delayMicroseconds(DELAY2);
  }
  
}
