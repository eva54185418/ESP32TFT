
#include <TFT_eSPI.h>

#include "a.h"

TFT_eSPI tft = TFT_eSPI();
void setup() {
  // put your setup code here, to run once:
  tft.init();                 //初始化显示寄存器
  tft.setRotation(0);
  tft.fillScreen(TFT_WHITE);  //屏幕颜色
  tft.setSwapBytes(true);     // RGB->BGR 加上这句才能正确显示颜色。
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < frames; i++) {
    tft.pushImage(0, 0, 128, 128, a[i]);
    delay(50);
  }
}