#include <TFT_eSPI.h>  // 引入 TFT_eSPI 库

TFT_eSPI tft;  // 创建 TFT_eSPI 对象

void setup() {
  tft.init();  // 初始化 TFT 屏幕
  tft.setRotation(0));           // 调整屏幕方向，根据需要选择合适的值（0、1、2、3）
  tft.fillScreen(TFT_BLACK);    // 设置屏幕背景颜色为黑色
  tft.setTextSize(1);           // 设置文本大小
  tft.setTextColor(TFT_WHITE);  // 设置文本颜色为白色
}

void loop() {
  tft.fillScreen(TFT_BLACK);  // 清空屏幕，将屏幕填充为黑色

  // 绘制不同图形

  // 绘制一个像素点，参数：x 坐标，y 坐标，颜色
  tft.drawPixel(5, 5, TFT_RED);

  // 绘制一条直线，参数：起点的 x 坐标，起点的 y 坐标，终点的 x 坐标，终点的 y 坐标，颜色
  tft.drawLine(10, 20, 60, 20, TFT_GREEN);

  // 第一行：矩形
  // 绘制一个矩形边框，参数：左上角的 x 坐标，左上角的 y 坐标，矩形的宽度，矩形的高度，颜色
  tft.drawRect(10, 40, 15, 10, TFT_BLUE);
  // 绘制一个矩形填充，参数：左上角的 x 坐标，左上角的 y 坐标，矩形的宽度，矩形的高度，颜色
  tft.fillRect(10, 40, 15, 10, TFT_YELLOW);

  // 第二行：圆形
  // 绘制一个圆形边框，参数：圆心的 x 坐标，圆心的 y 坐标，圆的半径，颜色
  tft.drawCircle(65, 35, 7, TFT_MAGENTA);
  // 绘制一个圆形填充，参数：圆心的 x 坐标，圆心的 y 坐标，圆的半径，颜色
  tft.fillCircle(85, 35, 7, TFT_CYAN);

  // 第三行：三角形
  // 绘制一个三角形边框，参数：三个顶点的 x 坐标，三个顶点的 y 坐标，颜色
  tft.drawTriangle(75, 80, 85, 70, 85, 80, TFT_ORANGE);
  // 绘制一个三角形填充，参数：三个顶点的 x 坐标，三个顶点的 y 坐标，颜色
  tft.fillTriangle(105, 80, 115, 70, 115, 80, TFT_PURPLE);

  // 第四行：圆角矩形
  // 绘制一个圆角矩形边框，参数：左上角的 x 坐标，左上角的 y 坐标，矩形的宽度，矩形的高度，圆角的半径，颜色
  tft.drawRoundRect(10, 75, 20, 20, 5, TFT_PINK);
  // 绘制一个圆角矩形填充，参数：左上角的 x 坐标，左上角的 y 坐标，矩形的宽度，矩形的高度，圆角的半径，颜色
  tft.fillRoundRect(35, 75, 20, 20, 5, TFT_BLUE);

  // 显示文本
  tft.setCursor(10, 10);            // 设置文本光标位置，参数：x 坐标，y 坐标
  tft.println("Hello, I am Eva!");  // 打印文本，参数：文本内容

  delay(2000);  // 等待2秒钟
}
