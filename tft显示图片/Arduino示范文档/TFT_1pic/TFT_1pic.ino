
#include <TFT_eSPI.h> 
#include "img.h"

TFT_eSPI tft = TFT_eSPI();
void setup() {
  // put your setup code here, to run once:
  tft.init();  //初始化显示寄存器
               
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);//屏幕颜色
  tft.setSwapBytes(true);  // RGB->BGR 加上这句才能正确显示颜色。
  tft.pushImage(0, 0, 128, 128, img);
}

void loop() {

}
