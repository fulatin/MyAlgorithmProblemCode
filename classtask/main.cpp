#include "graphics.h" // 引用图形库头文件
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;
const double PI = acos(-1);
const int width = 1920;
const int hight = 1080;
auto bgcolor = WHITE;

struct {
  float x;
  float y;
  float r;
  COLORREF bgcolor = WHITE;
  COLORREF textColor = WHITE;
  COLORREF clockcolor = BROWN;
  COLORREF clockBordercolor = BLUE;
  int lineLen1 = 6;
  int lineLen2 = 20;
  int textwide;
  int textOffset;
  int secLen;
  int minLen;
  int hourLen;
  COLORREF secPinColor = RED;
  COLORREF minPinColor = WHITE;
  COLORREF hourPinColor = WHITE;
} mc;

float mcos(float x) { return cos(x - PI / 2); }

float msin(float x) { return sin(x - PI / 2); }

void int2str(int x, char *s) {
  int pos = 0;
  while (x > 0) {
    s[pos] = '0' + x % 10;
    x /= 10;
    pos++;
  }
  for (int i = 0; i < pos / 2; ++i) {
    char tmp = s[i];
    s[i] = s[pos - i - 1];
    s[pos - i - 1] = tmp;
  }
  s[pos] = '\0';
}

void getNowTime(int &hour, int &min, int &sec) {
  std::time_t now = std::time(nullptr);
  std::tm *localTime = std::localtime(&now);

  // 获取时分秒
  hour = localTime->tm_hour;
  min = localTime->tm_min;
  sec = localTime->tm_sec;
}

void drawboard() {
  setfillcolor(mc.clockcolor);
  setlinecolor(mc.clockBordercolor);
  setlinestyle(PS_SOLID, 3);
  fillcircle(0, 0, mc.r);

  //   绘制刻度与数字
  for (int i = 1; i <= 60; ++i) {
    float lineLen = i % 5 == 0 ? mc.lineLen2 : mc.lineLen1;
    line(mc.r * cos(2 * PI * i / 60), mc.r * sin(2 * PI * i / 60),
         (mc.r - lineLen) * cos(2 * PI * i / 60),
         (mc.r - lineLen) * sin(2 * PI * i / 60));
    if (i % 5 == 0) {
      settextcolor(mc.textColor);
      setbkmode(TRANSPARENT);
      char outstr[3];
      int2str(i / 5, outstr);
      outtextxy(
          (mc.r - mc.textOffset) * mcos(2 * PI * i / 60) - mc.textOffset / 2,
          (mc.r - mc.textOffset) * msin(2 * PI * i / 60) - mc.textOffset / 2,
          _T(outstr));
    }
  }
}

void drawPins() {

  int hour, sec, min;
  getNowTime(hour, min, sec);
  float totalMin = min + (float)sec / 60;
  float totalHour = totalMin / 60 + hour;

  // 时针与分针
  setlinecolor(mc.hourPinColor);
  setfillcolor(mc.minPinColor);
  fillcircle(0, 0, mc.r / 20);
  setlinecolor(mc.hourPinColor);
  line(0, 0, mc.hourLen * mcos(2 * PI * totalHour / 12),
       mc.hourLen * msin(2 * PI * totalHour / 12));
  line(0, 0, mc.minLen * mcos(2 * PI * totalMin / 60),
       mc.minLen * msin(2 * PI * totalMin / 60));

  // 秒针
  setfillcolor(mc.secPinColor);
  setlinecolor(mc.secPinColor);
  fillcircle(0, 0, mc.r / 40);
  setlinecolor(mc.secPinColor);
  line(0, 0, mc.secLen * mcos(2 * PI * sec / 60),
       mc.secLen * msin(2 * PI * sec / 60));
}

void configText() {
  LOGFONT f;
  gettextstyle(&f); // 获取当前字体设置
  f.lfHeight = 48;  // 设置字体高度为 48
  settextstyle(&f); // 设置字体样式
}

void configLine(int w) { setlinestyle(PS_SOLID | PS_JOIN_BEVEL, w); }

void init() {
  initgraph(width, hight);
  configText();
  configLine(4);
  mc.x = width / 2;
  mc.y = hight / 2;
  mc.r = min(width, hight) / 2 - 3;
  mc.textOffset = mc.r / 10;
  mc.textwide = mc.textOffset;
  mc.secLen = mc.r * 8 / 10;
  mc.minLen = mc.r * 7 / 10;
  mc.hourLen = mc.r * 5 / 10;
  setbkcolor(mc.bgcolor);
  setorigin(mc.x, mc.y);
}

int main() {
  init();

  BeginBatchDraw();
  while (true) {
    cleardevice();
    drawboard();
    drawPins();
    FlushBatchDraw();
    Sleep(10);
  }
  EndBatchDraw();

  closegraph(); // 关闭绘图窗口
  return 0;
}
