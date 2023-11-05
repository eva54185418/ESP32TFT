#include <TFT_eSPI.h>

TFT_eSPI tft;

int x, y;              // 爱心的位置
int vx, vy;            // 爱心的移动速度
int heartSize = 1;     // 爱心的大小
uint16_t heartColor;   // 爱心的颜色

void setup() {
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);

  x = tft.width() / 2;   // 屏幕中心的 x 坐标
  y = tft.height() / 2;  // 屏幕中心的 y 坐标
  heartColor = TFT_RED;  // 爱心的颜色

  vx = random(-3, 4);  // 随机生成水平速度
  vy = random(-3, 4);  // 随机生成垂直速度

  drawHeart(x, y, heartSize, heartColor);  // 绘制爱心
}

void loop() {
  // 清空当前位置的爱心
  drawHeart(x, y, heartSize, TFT_BLACK);

  // 更新爱心的位置
  x += vx;
  y += vy;

  // 检查碰撞边界
  if (x <= heartSize * 16 || x >= tft.width() - heartSize * 16) {
    // 水平反弹
    vx = -vx;
    // 随机生成新的垂直速度
    vy = random(-3, 4);
  }
  if (y <= heartSize * 16 || y >= tft.height() - heartSize * 16) {
    // 垂直反弹
    vy = -vy;
    // 随机生成新的水平速度
    vx = random(-3, 4);
  }

  // 绘制新位置的爱心
  drawHeart(x, y, heartSize, heartColor);

  delay(1);  // 控制移动速度
}

void drawHeart(int x, int y, int size, uint16_t color) {
  tft.setTextColor(color);
  tft.setTextSize(2);

  for (float t = 0; t <= 2 * PI; t += 0.01) {
    int px = x - 16 * size * pow(sin(t), 3);
    int py = y - (13 * size * cos(t) - 5 * size * cos(2 * t) - 2 * size * cos(3 * t) - cos(4 * t));

    tft.drawPixel(px, py, color);
  }
}
