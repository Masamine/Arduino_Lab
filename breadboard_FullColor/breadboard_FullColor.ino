/* --------------------------
Full color LED
-------------------------- */
#include <Adafruit_NeoPixel.h>
 
//LEDの数
#define NUMPIXELS 1

//Arduinoで使うピン
#define RGBLed_PIN_1 8
#define RGBLed_PIN_2 10
#define RGBLed_PIN_3 12
  
//ライブラリのセットアップ（こうすることでLEDを個別に制御できます。）
Adafruit_NeoPixel RGBLed_1 = Adafruit_NeoPixel(NUMPIXELS, RGBLed_PIN_1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel RGBLed_2 = Adafruit_NeoPixel(NUMPIXELS, RGBLed_PIN_2, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel RGBLed_3 = Adafruit_NeoPixel(NUMPIXELS, RGBLed_PIN_3, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel RGBLED_arr[] = {RGBLed_1, RGBLed_2, RGBLed_3};
 
void setup() {
  //LEDを消灯（こうするとLEDが消える）
  for(int i = 0; i < 3; i++){
    RGBLED_arr[i].begin();
    RGBLED_arr[i].show();
  }
}
 
void loop() {
  //RGBカラーのランダム値を生成
  int colorRnadNum1,colorRnadNum2,colorRnadNum3; 
  colorRnadNum1 = random(255);
  colorRnadNum2 = random(255);
  colorRnadNum3 = random(255);
   
  //LEDを順番にフェードインしながら点灯
  for(int i = 0; i < 3; i++) {
     
    for(int j = 0; j < 255; j++) {
      RGBLED_arr[i].setPixelColor(0, colorRnadNum1, colorRnadNum2, colorRnadNum3);
      RGBLED_arr[i].setBrightness(j);
      RGBLED_arr[i].show(); 
      delay(1);
    }

  }
}