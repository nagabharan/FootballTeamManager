#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode;
	int i, x, y,n=0;
	int poly[16];
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	//********************* legs *********************************
	x = 10;
	y =300;
	n = 0;
	poly[n++] = x+20;        /* 1st vertex */
	poly[n++] = y+102;
	poly[n++] = x+5;
	poly[n++] = y-50;
	poly[n++] = x+45;
	poly[n++] = y-50;
	poly[n++] = x+60;
	poly[n++] = y+102;
	setfillstyle(SOLID_FILL,YELLOW);
	fillpoly(4, poly);
	x = 7;
	y =300;
	n = 0;
	poly[n++] = x+115;        /* 1st vertex */
	poly[n++] = y+102;
	poly[n++] = x+137;
	poly[n++] = y-50;
	poly[n++] = x+172;
	poly[n++] = y-50;
	poly[n++] = x+152;
	poly[n++] = y+102;
	setfillstyle(SOLID_FILL,YELLOW);
	fillpoly(4, poly);
	//*************      mane         **********
	x = 50;
	y = 10;
	n=0;
	poly[n++] = x+10; //1
	poly[n++] = y+60;
	poly[n++] = x+60; //2
	poly[n++] = y+60;
	poly[n++] = x+140;//6
	poly[n++] = y+140;
	poly[n++] = x+140;//7
	poly[n++] = y+250;
	poly[n++] = x+50; //8
	poly[n++] = y+350;
	poly[n++] = x-50;  //9
	poly[n++] = y+250;
	poly[n++] = x-50; //10
	poly[n++] = y+140;
	setfillstyle(SOLID_FILL, BROWN);
	fillpoly(7, poly);
	//*************      mane         **********
	x = 50;
	n=0;
	y = 20;
	poly[n++] = x; //1
	poly[n++] = y+40;
	poly[n++] = x+30; //2
	poly[n++] = y+40;
	poly[n++] = x+45; //3
	poly[n++] = y+60;
	poly[n++] = x+60; //4
	poly[n++] = y+40;
	poly[n++] = x+90; //5
	poly[n++] = y+40;
	poly[n++] = x+130;//6
	poly[n++] = y+90;
	poly[n++] = x+130;//7
	poly[n++] = y+180;
	poly[n++] = x+50; //8
	poly[n++] = y+250;
	poly[n++] = x-40;  //9
	poly[n++] = y+190;
	poly[n++] = x-40; //10
	poly[n++] = y+100;
	setfillstyle(SOLID_FILL, BROWN);
	fillpoly(10, poly);
	//**************************** face ********************
	x = 50;
	y = 60;
	n = 0;
	poly[n++] = x+10;        /* 1st vertex */
	poly[n++] = y+30;
	poly[n++] = x+80; /* 2nd */
	poly[n++] = y+30;
	poly[n++] = x+105; /* 3rd */
	poly[n++] = y+70;
	poly[n++] = x+105; //4
	poly[n++] = y+130;
	poly[n++] = x+60; //5
	poly[n++] = y+170;
	poly[n++] = x+40;     //6
	poly[n++] = y+170;
	poly[n++] = x-15;     //72
	poly[n++] = y+130;
	poly[n++] = x-15;     //8
	poly[n++] = y+70;
	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(8, poly);
	//********************** mouth ****************************
	setcolor(BROWN);
	x = 60;
	y = 60;
	n = 0;
	poly[n++] = x+20;
	poly[n++] = y+120;
	poly[n++] = x+55;
	poly[n++] = y+120;
	poly[n++] = x+65;
	poly[n++] = y+130;
	poly[n++] = x+65; //4
	poly[n++] = y+160;
	poly[n++] = x+55; //5
	poly[n++] = y+170;
	poly[n++] = x+20;     //6
	poly[n++] = y+170;
	poly[n++] = x+10;     //7
	poly[n++] = y+160;
	poly[n++] = x+10;     //8
	poly[n++] = y+130;
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(8, poly);
	//************************ nose *****************************
	setcolor(BROWN);
	x = 60;
	y = 50;
	n = 0;
	poly[n++] = x+20;        /* 1st vertex */
	poly[n++] = y+130;
	poly[n++] = x+25;
	poly[n++] = y+120;
	poly[n++] = x+50;
	poly[n++] = y+120;
	poly[n++] = x+55; /* 2nd */
	poly[n++] = y+130;
	poly[n++] = x+38; /* 3rd */
	poly[n++] = y+145;
	setfillstyle(SOLID_FILL, RED);
	fillpoly(5, poly);
	line(110,170,112,160);
	line(108,140,112,160);
	line(85,170,83,160);
	line(87,140,83,160);
	/*line(83,175,85,190);
	line(135,175,110,180);
	line(110,180,117,205);
	line(115,220,117,205);
	line(100,215,100,245);
	line(100,275,75,300);
	line(100,235,125,250);  */
	//***************************** eyes ***********************
	//left
	x = 80;
	y =60;
	n = 0;
	poly[n++] = x+30;        /* 1st vertex */
	poly[n++] = y+82;
	poly[n++] = x+50;
	poly[n++] = y+77;
	poly[n++] = x+70;
	poly[n++] = y+82;
	poly[n++] = x+50;
	poly[n++] = y+87;
	setfillstyle(SOLID_FILL,RED);
	fillpoly(4, poly);
	//right
	x = 15;
	y =60;
	n = 0;
	poly[n++] = x+30;        /* 1st vertex */
	poly[n++] = y+82;
	poly[n++] = x+50;
	poly[n++] = y+77;
	poly[n++] = x+70;
	poly[n++] = y+82;
	poly[n++] = x+50;
	poly[n++] = y+87;
	setfillstyle(SOLID_FILL,RED);
	/* draw a filled polygon */
	fillpoly(4, poly);
	//**************************** paw ***************************
	x = 87;
	y =320;
	n = 0;
	poly[n++] = x+30;        /* 1st vertex */
	poly[n++] = y+82;
	poly[n++] = x+40;
	poly[n++] = y+67;
	poly[n++] = x+70;
	poly[n++] = y+67;
	poly[n++] = x+80;
	poly[n++] = y+82;
	poly[n++] = x+70;
	poly[n++] = y+92;
	poly[n++] = x+40;
	poly[n++] = y+92;
	setfillstyle(SOLID_FILL,YELLOW);
	fillpoly(6, poly);
	//right
	x = -5;
	y =320;
	n = 0;
	poly[n++] = x+30;        /* 1st vertex */
	poly[n++] = y+82;
	poly[n++] = x+40;
	poly[n++] = y+67;
	poly[n++] = x+70;
	poly[n++] = y+67;
	poly[n++] = x+80;
	poly[n++] = y+82;
	poly[n++] = x+70;
	poly[n++] = y+92;
	poly[n++] = x+40;
	poly[n++] = y+92;
	setfillstyle(SOLID_FILL,YELLOW);
	fillpoly(6, poly);
	getch();
	/* clean up */
	closegraph();
	return 0;
}