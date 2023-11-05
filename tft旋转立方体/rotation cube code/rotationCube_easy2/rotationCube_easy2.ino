#include <TFT_eSPI.h>
#include <math.h>

TFT_eSPI tft = TFT_eSPI();  // 创建 TFT_eSPI 实例

float length = 35;

// 立方体的顶点坐标
float vertices[8][3] = {
  { -length, -length, -length },  // 0
  { length, -length, -length },   // 1
  { length, length, -length },    // 2
  { -length, length, -length },   // 3
  { -length, -length, length },   // 4
  { length, -length, length },    // 5
  { length, length, length },     // 6
  { -length, length, length }     // 7
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
float angleX = 0.0;
float angleY = 0.0;
float angleZ = 0.0;

void setup() {
  tft.begin();         // 初始化 TFT 显示屏
  tft.setRotation(0);  // 设置显示屏方向，根据需要进行调整
  tft.setTextSize(1);  // 文本大小

  centerX = tft.width() / 2;
  centerY = tft.height() / 2;
}

void loop() {
  tft.fillScreen(TFT_BLACK);  // 清空屏幕
  tft.setCursor(0, 0);
  tft.println("x: " + String(angleX));
  tft.println("y: " + String(angleY));
  tft.println("z: " + String(angleZ));
  tft.println("l: " + String(length));

  // 更新顶点坐标
  float verticesTemp[8][3] = {
    { -length, -length, -length },  // 0
    { length, -length, -length },   // 1
    { length, length, -length },    // 2
    { -length, length, -length },   // 3
    { -length, -length, length },   // 4
    { length, -length, length },    // 5
    { length, length, length },     // 6
    { -length, length, length }     // 7
  };


  angleX = fmod(angleX, 360.0);
  angleY = fmod(angleY, 360.0);
  angleZ = fmod(angleZ, 360.0);

  //autoRotate();
  controlRotate();

  // 绘制立方体的线条
  for (int i = 0; i < 12; i++) {
    int v0 = edges[i][0];
    int v1 = edges[i][1];

    float x0 = verticesTemp[v0][0];
    float y0 = verticesTemp[v0][1];
    float z0 = verticesTemp[v0][2];
    float x1 = verticesTemp[v1][0];
    float y1 = verticesTemp[v1][1];
    float z1 = verticesTemp[v1][2];

    // 绕X轴旋转
    rotateX(y0, z0, angleX);
    rotateX(y1, z1, angleX);

    // 绕Y轴旋转
    rotateY(x0, z0, angleY);
    rotateY(x1, z1, angleY);

    // 绕Z轴旋转
    rotateZ(x0, y0, angleZ);
    rotateZ(x1, y1, angleZ);

    drawLine(x0, y0, x1, y1);
  }

  delay(1);  // 稍微延迟一下，调整旋转速度
}

// 绘制线条,简化代码
void drawLine(float x0, float y0, float x1, float y1) {
  tft.drawLine(centerX + x0, centerY + y0, centerX + x1, centerY + y1, TFT_WHITE);
}

// 绕X轴旋转，x不变
void rotateX(float& y, float& z, float angle) {
  float rad = angle * PI / 180.0;
  float new_y = y * cos(rad) - z * sin(rad);
  float new_z = z * cos(rad) + y * sin(rad);
  y = new_y;
  z = new_z;
}

// 绕Y轴旋转，y不变
void rotateY(float& x, float& z, float angle) {
  float rad = angle * PI / 180.0;
  float new_x = x * cos(rad) + z * sin(rad);
  float new_z = z * cos(rad) - x * sin(rad);
  x = new_x;
  z = new_z;
}

// 绕Z轴旋转，z不变
void rotateZ(float& x, float& y, float angle) {
  float rad = angle * PI / 180.0;
  float new_x = x * cos(rad) - y * sin(rad);
  float new_y = y * cos(rad) + x * sin(rad);
  x = new_x;
  y = new_y;
}

void controlRotate() {
  // 更新旋转角度
  if (analogRead(13) == 0) {  // X
    angleX++;
  } else if (analogRead(13) == 4095) {
    angleX--;
  }
  if (analogRead(12) == 0) {  // Y
    angleY--;
  } else if (analogRead(12) == 4095) {
    angleY++;
  }
  if (analogRead(14) == 0) {  // Z
    angleZ++;
  } else if (analogRead(14) == 4095) {
    angleZ--;
  }
  if (analogRead(27) == 0) {  // Z
    length++;
  } else if (analogRead(14) == 4095) {
    length--;
  }
}

void autoRotate() {
  angleX++;
  angleY++;
  angleZ++;
}
