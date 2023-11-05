#include <TFT_eSPI.h>
#include "eva2.h"  //加载自定义字体

TFT_eSPI tft;

void setup() {
  tft.begin();                  //初始化TFT屏幕
  tft.fillScreen(TFT_BLACK);    //刷屏底色为黑色
  tft.setTextColor(TFT_WHITE);  //设置字体颜色
  tft.loadFont(eva2);            //设定h文件中的字体
}

void loop() {
  tft.fillScreen(TFT_BLACK);  //刷屏底色为黑色
  tft.setCursor(0, 10);       //设置光标位置
  tft.println("B站关注");     //打印文字（字体有设置才有用）
  tft.println("伊娃老师");    //打印文字
  delay(1000);
  tft.fillScreen(TFT_BLACK);  //刷屏底色为黑色
  tft.setCursor(0, 10);       //设置光标位置
  tft.println("一键三连");    //打印文字（字体有设置才有用）
  delay(1000);
  //tft.unloadFont();  //释放字库,节省RAM
}
