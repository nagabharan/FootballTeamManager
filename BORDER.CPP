#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>

	/* request auto detection */
	int n,m,gdriver = DETECT, gmode;

void bodr(int p,int q)							//BORDER FUNCTION
{
	int g,h,f=0;

	for(g=315;g>=5;g-=10)
	{
		++f;
		if(f%2==0)
			setfillstyle(SOLID_FILL,LIGHTGRAY);
		else
			setfillstyle(SOLID_FILL,RED);
		setcolor(p);
		fillellipse(g,5,10,10);
		setcolor(q);
		fillellipse(640-g,5,10,10);
		delay(50);
		p=p+q;
		q=p-q;
		p=p-q;
	}
	for(h=5;h<=475;h+=10)
	{
		++f;
		if(f%2==0)
			setfillstyle(SOLID_FILL,LIGHTGRAY);
		else
			setfillstyle(SOLID_FILL,RED);
		setcolor(q);
		fillellipse(5,h,10,10);
		setcolor(p);
		fillellipse(635,h,10,10);
		delay(50);
		p=p+q;
		q=p-q;
		p=p-q;
	}
	for(g=5,h=645;g<=305,h>=325;g+=10,h-=10)
	{
		++f;
		if(f%2==0)
			setfillstyle(SOLID_FILL,LIGHTGRAY);
		else
			setfillstyle(SOLID_FILL,RED);
		setcolor(q);
		fillellipse(g,475,10,10);
		setcolor(p);
		fillellipse(h,475,10,10);
		delay(50);
		p=p+q;
		q=p-q;
		p=p-q;
	}
}
void welcome()											//WELCOME FUNCTION
{
	bodr(7,4);
	for(;!kbhit();)
	{
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 9);
	outtextxy(100,160,"WELCOME");
	delay(300);
	}
	getch();

}
void main()
{
	/* initialize graphics mode */
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	welcome();
}