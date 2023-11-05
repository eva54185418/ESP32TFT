//黑客帝国画面特效
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();  // 初始化 TFT_eSPI 对象



const int dropDelay = 100;  // 每个雨滴的延迟时间（毫秒）
const int maxDrops = 30;    // 最大雨滴数量

int dropX[maxDrops];      // 雨滴的X坐标
int dropY[maxDrops];      // 雨滴的Y坐标
char dropChar[maxDrops];  // 雨滴显示的字符
int dropSpeed[maxDrops];  // 雨滴的下落速度

void setup() {
  tft.init();                 // 初始化 TFT_eSPI
  tft.setRotation(0);         // 旋转屏幕以适应不同的连接方式
  tft.fillScreen(TFT_BLACK);  // 清空屏幕为黑色

  randomSeed(analogRead(0));  // 使用模拟引脚0的值作为随机种子

  // 初始化每个雨滴的初始值
  for (int i = 0; i < maxDrops; i++) {
    dropX[i] = random(0, tft.width());
    dropY[i] = -random(0, tft.height());
    dropChar[i] = randomChar(2);
    dropSpeed[i] = random(1, 5);
  }

  tft.setTextColor(TFT_GREEN);  // 设置字符颜色
  tft.setTextSize(1);           // 设置字符大小
}

void loop() {
  // 更新每个雨滴的位置
  for (int i = 0; i < maxDrops; i++) {
    dropY[i] += dropSpeed[i];

    // 如果雨滴超出屏幕底部，将其重置到屏幕顶部
    if (dropY[i] > tft.height() + 8) {
      dropY[i] = -8;
      dropX[i] = random(0, tft.width());
      dropChar[i] = randomChar(2);
    }
  }

  // 清空屏幕
  tft.fillScreen(TFT_BLACK);

  // 绘制雨滴
  for (int i = 0; i < maxDrops; i++) {
    tft.setCursor(dropX[i], dropY[i]);
    tft.print(dropChar[i]);
  }

  delay(dropDelay);  // 等待一段时间，控制雨滴的下落速度
}

// 随机生成可显示的字符
char randomChar(int i) {
  if (i == 1) {
    int charIndex = random(0, 95);  // ASCII 32-126 可显示的字符范围
    return char(charIndex + 32);
  } else if (i == 2) {
    int charIndex = random(0, 2);  // 生成随机数 0 或 1
    return char(charIndex + '0');  // 将数字转换为对应的字符
  }
}
