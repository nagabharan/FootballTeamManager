#include<iostream.h>
#include<bios.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
void menu()
{
	settextstyle(1,0,4);
	outtextxy(210,50,"MAIN MENU");
	settextstyle(1,0,4);
	rectangle(200,100,400,140);
	rectangle(200,140,400,180);
	rectangle(200,180,400,220);
	rectangle(200,220,400,260);
}
void options()
{
	outtextxy(210,100,"MENU 1");
	outtextxy(210,140,"MENU 2");
	outtextxy(210,180,"MENU 3");
	outtextxy(210,220,"MENU 4");
}
void rect(int x,int y)
{
	rectangle(0,0,x,y);
}
void main()
{
	clrscr();
	int key,x=200,y=80;
	int gdriver = DETECT, gmode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	menu();
	options();
	while((key=bioskey(0))!=283)
	{
		setcolor(0);
		options();
		setfillstyle(1,0);
		floodfill(x+50,y,WHITE);
		setcolor(15);
		//clearviewport();
		menu();
		switch(key)
		{
			case 20480:if(y>=240) y=80;
				   y+=40;
				   break;
			case 18432:if(y<=120) y=280;
				   y-=40;
				   break;
			case 7181:while((key=bioskey(0))!=3592)
				  {
					switch(y)
					{
					case 120:clearviewport();
						 rect(x,y);break;
					case 160:cleardevice();
						 rect(x,y);break;
					case 200:cleardevice();
						 rect(x,y);break;
					case 240:cleardevice();
						 rect(x,y);break;
					}
				  }
		}

		setfillstyle(1,1);
		floodfill(x+50,y,WHITE);
		options();

	}
}