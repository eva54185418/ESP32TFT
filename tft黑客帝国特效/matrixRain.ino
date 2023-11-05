#include <TFT_eSPI.h>
TFT_eSPI tft;  //创建对象

uint16_t evacolor = tft.color565(0, 0, 0);  //rgb
/*
int dropY = 0;                              //文字的Y
int dropX = random(0, tft.width());         //文字的X ,random(最小值，最大值)，从最小值跟最大值取一个随机数
char randomC = char(random(32, 126));       //随机打印ASCII 32-126可显示的字符内容
int dropSpeed = random(1, 5);               //随机速度1-5
*/

const int maxDrops = 300;  // 最大雨滴数量
int dropX[maxDrops];      // 雨滴的X坐标
int dropY[maxDrops];      // 雨滴的Y坐标
char randomC[maxDrops];   // 雨滴显示的字符
int dropSpeed[maxDrops];  // 雨滴的下落速度



void setup() {  //开机执行一次的代码，一般会放初始化的设定值
  // put your setup code here, to run once:
  tft.init();                       //初始化屏幕
  tft.setRotation(0);               //屏幕旋转方向
  tft.fillScreen(evacolor);         //屏幕底色
  tft.setTextSize(1);               //文本大小
  tft.setTextColor(TFT_DARKGREEN);  //文字深绿色
                                    //  tft.setCursor(10,10);//设置打印文字位置
                                    //  tft.println("TEST EVA");//打印文字
  randomSeed(analogRead(0));        // 使用模拟引脚0的值作为随机种子

  for (int i = 0; i < maxDrops; i++) {  //如果你将 for 循环放在 setup() 函数之外，即全局作用域中，会导致编译错误。
    dropX[i] = random(0, tft.width());
    dropY[i] = -random(0, tft.height());
    randomC[i] = char(random(32, 126));
    dropSpeed[i] = random(1, 5);
  }
}

//显示文字、文字掉落、随机循环掉落、随机文字、随机速度
//多个文字，同样功能

void loop() {  //执行完setup之后，循环执行loop中的指令
  // put your main code here, to run repeatedly:


  tft.fillScreen(evacolor);

  /*
  tft.setCursor(dropX, dropY);  //设定从坐标x：10开始，坐标y：dropY打印
  tft.println(randomC);         //打印randomC
  dropY = dropY + dropSpeed;    //dropY增加dropSpeed
  if (dropY > tft.height()) {  //判断Y的位置，如果到底就回到顶点，实现循环掉落
    dropY = 0;
    dropX = random(0, tft.width());
    randomC = char(random(32, 126));
  }
*/

  for (int i = 0; i < maxDrops; i++) {
    tft.setCursor(dropX[i], dropY[i]);   //设定从坐标x：10开始，坐标y：dropY打印
    tft.println(randomC[i]);             //打印randomC
    dropY[i] = dropY[i] + dropSpeed[i];  //dropY增加dropSpeed
    if (dropY[i] > tft.height()) {       //判断Y的位置，如果到底就回到顶点，实现循环掉落
      dropY[i] = -random(0, tft.height());
      dropX[i] = random(0, tft.width());
      randomC[i] = char(random(32, 126));
    }
  }


  delay(100);  //延迟100毫秒，0.1秒
}
