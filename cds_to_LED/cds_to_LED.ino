/* --------------------------
光センサー LED　ON / OFF
暗いところにおくとセンサー自体の抵抗値が大きくなり、明るいところに置くと抵抗値が低くなる。

アナログピン0で光センサーの値を受け取る。
その値がアナログ1の数値より小さければ光る。
-------------------------- */

//LED
#define LED 10

//光センサー
#define CDS 0

//設定値（半固定抵抗の値）
#define SET_POT 1

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {

  int brightness, setVal;
  int upper, lower;

  //アナログピン0番から読み込み
  brightness = analogRead(CDS);

  //アナログピン1番から読み込み
  setVal     = analogRead(SET_POT);

  //明るい側の値を入力+10
  //上限を1023に。
  upper = setVal + 10;
  if(upper > 1023) upper = 1023;

  //暗い側の値を入力-10
  //下限を0に。
  lower = setVal - 10;
  if(lower > 1023) lower = 0;

  //下限値より暗ければ光る
  if(brightness < lower) {
    digitalWrite(LED, HIGH);
  }

  //上限値より明るければ消える
  if(brightness > upper){
    digitalWrite(LED, LOW);
  }

  //delay(1000);
}
