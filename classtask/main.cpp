#include "graphics.h"		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<cmath>
const int width = 1920/3;
const int hight = 1080/3;
auto bgcolor = WHITE;
struct myclock{
	float x;
	float y;
	float r;
	COLORREF bgcolor = WHITE;
	COLORREF clockcolor = BROWN;
	COLORREF clockBordercolor = BLUE;
	
	
}mc;
void drawboard(){
	setfillcolor(mc.clockcolor);
	setlinecolor(mc.clockBordercolor);
	setlinestyle(PS_SOLID, 3);
	fillcircle(mc.x,mc.y,mc.r);
	

}
int main() {
	initgraph(width,hight);	// ������ͼ���ڣ���СΪ 640x480 ����
//	int cnt = 0;
	mc.x = width/2;
	mc.y = hight/2;
	mc.r = 100;
	setbkcolor(mc.bgcolor);
	cleardevice();
	drawboard();
//	BeginBatchDraw();
//	while(cnt<100){
//		
//	}
//	EndBatchDraw();
	
	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}
