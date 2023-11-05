#include <TFT_eSPI.h>
#include "nanshen10.h"  //加载自定义字体
#include "shou14.h"
#include "deyihei20.h"
#include "yuan24.h"

TFT_eSPI tft;

void setup() {
  tft.begin();                //初始化TFT屏幕
  tft.fillScreen(TFT_BLACK);  //刷屏底色为黑色
}

void loop() {

  tft.setCursor(0, 10);  //设置光标位置

  tft.setTextColor(TFT_WHITE);       //设置字体颜色
  tft.loadFont(nanshen10);           //设定读取字体
  tft.println("伊娃老师  大小:10");  //打印文字

  tft.setTextColor(TFT_YELLOW);      //设置字体颜色
  tft.loadFont(shou14);              //设定读取字体
  tft.println("伊娃老师  大小:14");  //打印文字

  tft.setTextColor(TFT_GREEN);       //设置字体颜色
  tft.loadFont(deyihei20);           //设定读取字体
  tft.println("伊娃老师  大小:20");  //打印文字

  tft.setTextColor(TFT_BLUE);        //设置字体颜色
  tft.loadFont(yuan24);              //设定读取字体
  tft.println("伊娃老师  大小:24");  //打印文字
  //tft.unloadFont();  //释放字库,节省RAM
}
