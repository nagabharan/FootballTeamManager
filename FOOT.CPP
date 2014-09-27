#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	int gdriver = DETECT, gmode;
	int i, x, y,n=0;
	int poly[16];
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	setcolor(1);
	setfillstyle(SOLID_FILL,WHITE);
	circle(300,200,100);
	floodfill(300,250,1);
	line(202,210,230,200);  //1/
	line(230,200,250,240);  //2\
	line(250,240,237,277);  //3/
	line(245,160,285,145);
	line(285,145,300,105);
	line(300,105,297,100);
	line(300,105,317,101);
	line(285,145,310,183);
	line(350,170,365,130);
	line(350,170,370,205);
	line(370,205,400,195);
	line(370,205,352,250);
	line(352,250,313,265);
	line(352,250,364,277);
	line(365,130,360,120);
	line(365,130,370,129);
	line(310,183,293,227);
	line(310,183,350,170);
	line(293,227,250,240);
	line(293,227,313,265);
	line(313,265,299,301);
	line(230,200,245,160);
	line(245,160,230,129);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(215,170,1);
	floodfill(265,270,1);
	floodfill(315,110,1);
	getch();
}