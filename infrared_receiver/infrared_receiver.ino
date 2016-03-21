#define COUNT_NUM 68

const int pin = 11;              /* 赤外線センサの出力を接続するデジタルピン */
unsigned long time[COUNT_NUM];  /* 時刻を格納する配列 */

void setup () {
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop () {
  int repeat = 0;
  int mode; /* 読み取るデータを決める */
  char str[64];
 
  /* 68回データを読み取る */
  mode = HIGH; /* 最初はHIGH */
  for (int i = 0; i < COUNT_NUM; i++) {
    while(digitalRead(pin) == mode) { /* 状態が変わるまで待つ */
        ;
    }
    time[i] = micros(); /* 時刻を記録する */
   
    if (mode == HIGH) { /* onとoffが交互に来るので，待つべき状態を変える */
      mode = LOW;
    } else {
      mode = HIGH;
    }
   
    /* リーダコードのoffが2.25msだと次にストップビットが来て終了 */
    /* 3000ms以下かどうかで判定 */
    if ((i == 3) && ((time[2] - time[1])) < 3000)  {
      repeat = 1;
      break;
    }
  }
 
  /* データの出力 */
  Serial.print("--------- BEGIN ---------\n");
 
  sprintf(str, "Leader:\n  HIGH %dms\n", (time[1] - time[0]));
  Serial.print(str);
  sprintf(str, "  LOW  %4dms\n\n", (time[2] - time[1]));
  Serial.print(str);
 
  if(repeat) {
    Serial.println("Repeat");
  } else {
    Serial.println("Custom Code:");
    print_data(2);
    print_data(18);

    Serial.println("");
 
    Serial.println("Data:");
    print_data(34);
    print_data(50);
   
    Serial.print("---------  END  ---------\n\n");
  }
}

void print_data(int start) {
  int code = 0;
  char str[32];
 
  sprintf(str, "  ");
  for (int i = 0; i < 8; i++) {
    if ((time[2 * i + start + 2] - time[2 * i + start]) > 1500) {
      code |= 1 << i;
      sprintf(&str[2 * (i + 1)], "1 ");
    } else {
      sprintf(&str[2 * (i + 1)], "0 ");
    }
  }
 
  sprintf(&str[17], ", %02x", code);
  Serial.println(str);
}