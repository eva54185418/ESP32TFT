#include <TFT_eSPI.h>  // 引入 TFT_eSPI 库
#include <math.h>      // 引入 math.h 库
TFT_eSPI tft = TFT_eSPI();  // 创建 TFT_eSPI 实例



void setup() {
  // 初始设定
  tft.begin();         // 初始化 TFT 显示屏
  tft.setRotation(0);  // 设置显示屏方向，根据需要进行调整
}

void loop() {
  tft.fillScreen(TFT_BLACK);  // 清空屏幕
  tft.drawLine(10, 10, 20, 10, TFT_WHITE);  // 在屏幕上绘制一个起点（10，10）、终点（20，10）的直线
  tft.drawLine(20, 10, 20, 20, TFT_WHITE);  // 在屏幕上绘制一个起点（20，10）、终点（20，10）的直线
  tft.drawLine(20, 20, 10, 20, TFT_WHITE);  // 在屏幕上绘制一个起点（20，20）、终点（10，20）的直线
  tft.drawLine(10, 20, 10, 10, TFT_WHITE);  // 在屏幕上绘制一个起点（10，20）、终点（10，10）的直线

  tft.drawLine(P1X,p1Y,p2x,p2y,color)
}


