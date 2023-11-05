#include <TFT_eSPI.h>       // 引入 TFT_eSPI 库
#include <math.h>           // 引入 math.h 库
TFT_eSPI tft = TFT_eSPI();  // 创建 TFT_eSPI 实例

int centerX;
int centerY;
float length;

void setup() {
  // 初始设定
  tft.begin();         // 初始化 TFT 显示屏
  tft.setRotation(0);  // 设置显示屏方向，根据需要进行调整

  centerX = tft.width() / 2;   // 计算屏幕中心的 x 坐标
  centerY = tft.height() / 2;  // 计算屏幕中心的 y 坐标
  length=20; //正方形长度
}

void loop() {
  tft.fillScreen(TFT_BLACK);  // 清空屏幕

  tft.drawLine(centerX -length/2, centerY - length/2, centerX + length/2, centerY - length/2, TFT_WHITE);  
  tft.drawLine(centerX + length/2, centerY - length/2, centerX + length/2, centerY + length/2, TFT_WHITE);
  tft.drawLine(centerX + length/2, centerY + length/2, centerX - length/2, centerY + length/2, TFT_WHITE);
  tft.drawLine(centerX - length/2, centerY + length/2, centerX - length/2, centerY - length/2, TFT_WHITE);
}
