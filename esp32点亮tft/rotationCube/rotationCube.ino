//旋转的立方体
#include <TFT_eSPI.h>
#include <math.h>

TFT_eSPI tft = TFT_eSPI();  // 创建 TFT_eSPI 实例

// 立方体的顶点坐标
float vertices[8][3] = {
  { -25, -25, -25 },  // 0
  { 25, -25, -25 },   // 1
  { 25, 25, -25 },    // 2
  { -25, 25, -25 },   // 3
  { -25, -25, 25 },   // 4
  { 25, -25, 25 },    // 5
  { 25, 25, 25 },     // 6
  { -25, 25, 25 }     // 7
};

// 连接立方体顶点的边
int edges[12][2] = {
  { 0, 1 },
  { 1, 2 },
  { 2, 3 },
  { 3, 0 },
  { 4, 5 },
  { 5, 6 },
  { 6, 7 },
  { 7, 4 },
  { 0, 4 },
  { 1, 5 },
  { 2, 6 },
  { 3, 7 }
};

// 画面中心坐标
int centerX;
int centerY;

// 旋转角度
float angle = 0.0;

void setup() {
  tft.begin();         // 初始化 TFT 显示屏
  tft.setRotation(0);  // 设置显示屏方向，根据需要进行调整

  centerX = tft.width() / 2;
  centerY = tft.height() / 2;
}

void loop() {
  tft.fillScreen(TFT_BLACK);  // 清空屏幕

  // 更新旋转角度
  angle += 1;
  // 旋转角度取模
  angle = fmod(angle, 360.0);

  // 绘制立方体的线条
  for (int i = 0; i < 12; i++) {
    int v0 = edges[i][0];
    int v1 = edges[i][1];
    float x0 = vertices[v0][0];
    float y0 = vertices[v0][1];
    float z0 = vertices[v0][2];
    float x1 = vertices[v1][0];
    float y1 = vertices[v1][1];
    float z1 = vertices[v1][2];

    // 绕Y轴旋转
    rotateY(&x0, &z0, angle);
    rotateY(&x1, &z1, angle);

    // 绕X轴旋转
    rotateX(&y0, &z0, angle);
    rotateX(&y1, &z1, angle);

    drawLine(x0, y0, x1, y1);
  }

  delay(1);  // 稍微延迟一下，调整旋转速度
}

// 绘制线条
void drawLine(float x0, float y0, float x1, float y1) {
  tft.drawLine(centerX + x0, centerY + y0, centerX + x1, centerY + y1, TFT_WHITE);
}

// 绕Y轴旋转
void rotateY(float *x, float *z, float angle) {
  float rad = angle * PI / 180.0;
  float new_x = (*x) * cos(rad) + (*z) * sin(rad);
  float new_z = (*z) * cos(rad) - (*x) * sin(rad);
  (*x) = new_x;
  (*z) = new_z;
}

// 绕X轴旋转
void rotateX(float *y, float *z, float angle) {
  float rad = angle * PI / 180.0;
  float new_y = (*y) * cos(rad) - (*z) * sin(rad);
  float new_z = (*z) * cos(rad) + (*y) * sin(rad);
  (*y) = new_y;
  (*z) = new_z;
}
