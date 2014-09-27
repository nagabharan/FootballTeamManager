/*************************************************************
	                SOCCER MANAGER
			 VERSION 1.0
		BY Arvind and Nagabharan

*************************************************************/
//HEADER FILES
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#include <iostream.h>
#include <bios.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include "passw.cpp"
#include "plp.cpp"
#include "tmp.cpp"
/************************************************************/
//GLOBAL DECLARATIONS
FILE *f;
char str[50];
int ch;
team_player tmp;
team t;
col[3]={15,4,2};
/***********************************************************/
void clear()
{
	closegraph();
	clrscr();
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
}
void end()
{
	clear();
	for(int i=0;i<16;i++)
	{
		setcolor(i+5);
		settextstyle(1, HORIZ_DIR, 9);
		outtextxy(60,120,"THANK YOU");
		delay(100);
	}
	exit(0);
}
void menu1(int x,int n,int y,int z=200)
{
	settextstyle(1,0,4);
	char str[50];
	if(n==4)
		strcpy(str,"MAIN MENU");
	else
		strcpy(str,"MENU");
	outtextxy(x+10,50,str);
	settextstyle(1,0,4);
	for(int i=0;i<n;i++)
	{
		rectangle(x,y,x+z,y+40);
		y=y+40;
	}
}
void img(char str[],int x,int y,int z)
{
	int p=x;
	unsigned char bit;
	f=fopen(str,"r");
	fseek(f,0x76,1);
	while(!feof(f))
	{
		bit=fgetc(f);
		putpixel(x++,y,bit);
		putpixel(x++,y,bit);
		if (x>z)
		{
			x=p;
			y--;
		}	}}
void bodr(int p,int q)							
{
	int g,h,f=0;
	for(g=315;g>=5;g-=10)
	{
		++f;
		if(f%2==0)
			setfillstyle(SOLID_FILL,LIGHTGRAY);
		else if(f%3==0)
			setfillstyle(SOLID_FILL,BLUE);
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
		else if(f%3==0)
			setfillstyle(SOLID_FILL,BLUE);
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
		else if(f%3==0)
			setfillstyle(SOLID_FILL,BLUE);
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
void welcome()											
{
	bodr(7,4);
	for(int i=0;!kbhit();i++)
	{
	setcolor(col[i]);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 9);
	outtextxy(100,160,"WELCOME");
	setcolor(col[i+1]);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 9);
	outtextxy(103,160,"WELCOME");
	setcolor(col[i+2]);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 9);
	outtextxy(106,160,"WELCOME");
	delay(300);
	if(i>3)i=0;
	}
	getch();

}
void options1()
{
	outtextxy(360,110,"DATABASE");
	outtextxy(360,150,"HELP");
	outtextxy(360,190,"CREDITS");
	outtextxy(360,230,"EXIT");
	outtextxy(60,400,"PRESS [Esc] TO GO EXIT");
}
void options2()
{
	outtextxy(60,110,"ADD");
	outtextxy(60,150,"MODIFY");
	outtextxy(60,190,"DELETE");
	outtextxy(60,230,"SEARCH");
	outtextxy(60,270,"DISPLAY");
	outtextxy(60,310,"EXIT");
	outtextxy(60,400,"PRESS [<-] TO GO BACK");
}
void player()
{
	int key,x=50,y=80;
	strcpy(str,"imagef.bmp");
	img(str,300,300,530);
	menu1(50,6,110);
	options2();
	while((key=bioskey(0))!=3592)
	{
		setcolor(0);
		options2();
		setfillstyle(1,0);
		floodfill(x+50,y,WHITE);
		setcolor(15);
		menu1(50,6,110);
		switch(key)
		{
			case 20480:if(y>=320) y=80;
				   y+=40;
				   break;
			case 18432:if(y<=120) y=360;
				   y-=40;
				   break;
			case 7181:switch(y)
				  {
					case 120:cleardevice();
						 tmp.addrec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;
					case 160:cleardevice();
						 tmp.modirec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;
					case 200:cleardevice();
						 tmp.delrec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;

					case 240:cleardevice();
						 tmp.recallrec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;
					case 280:cleardevice();
						 tmp.listrec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;
					case 320:end();
						 break;
				  }
				  break;
		}
		setfillstyle(1,1);
		floodfill(x+50,y,WHITE);
		options2();
	}
	clear();
	strcpy(str,"field.bmp");
	img(str,200,450,511);
	menu1(50,3,110,300);
}
void tmdet()
{
	int key,x=50,y=80;
	strcpy(str,"imagef.bmp");
	img(str,300,300,530);
	menu1(50,6,110);
	options2();
	while((key=bioskey(0))!=3592)
	{
		setcolor(0);
		options2();
		setfillstyle(1,0);
		floodfill(x+50,y,WHITE);
		setcolor(15);
		menu1(50,6,110);
		switch(key)
		{
			case 20480:if(y>=320) y=80;
				   y+=40;
				   break;
			case 18432:if(y<=120) y=360;
				   y-=40;
				   break;
			case 7181:switch(y)
				  {
					case 120:cleardevice();
						 t.addrec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;
					case 160:cleardevice();
						 t.modirec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;
					case 200:cleardevice();
						 t.delrec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;

					case 240:cleardevice();
						 t.recallrec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;
					case 280:cleardevice();
						 t.listrec();
						 clear();
						 strcpy(str,"imagef.bmp");
						 img(str,300,300,530);
						 menu1(50,6,110);
						 break;
					case 320:end();
						 break;
				  }
				  break;
		}
		setfillstyle(1,1);
		floodfill(x+50,y,WHITE);
		options2();
	}
	clear();
	strcpy(str,"field.bmp");
	img(str,200,450,511);
	menu1(50,3,110,300);
}
void options3()
{
	outtextxy(60,110,"TEAM DETAILS");
	outtextxy(60,150,"PLAYER DETAILS");
	outtextxy(60,190,"EXIT");
	outtextxy(60,10,"PRESS [<-] TO GO BACK");}
void database()
{
	int key,x=50,y=80;
	strcpy(str,"field.bmp");
	img(str,200,450,511);
	menu1(50,3,110,300);
	options3();
	while((key=bioskey(0))!=3592)
	{
		setcolor(0);
		options3();
		setfillstyle(1,0);
		floodfill(x+50,y,WHITE);
		setcolor(15);
		menu1(50,3,110,300);
		switch(key)
		{
			case 20480:if(y>=200) y=80;
				   y+=40;
				   break;
			case 18432:if(y<=120) y=240;
				   y-=40;
				   break;
			case 7181:switch(y)
				  {
					case 120:cleardevice();
						 tmdet();
						 break;
					case 160:cleardevice();
						 player();
						 break;
					case 200:end();
						 break;
				  }
				  break;
		}
		setfillstyle(1,1);
		floodfill(x+50,y,WHITE);
		options3();

	}
	clear();
	strcpy(str,"imag21.bmp");
	img(str,20,300,323);
	menu1(350,4,110);
}
void help()
{
	int chh;
	s:
	clear();
	setcolor(14);
	settextstyle(5, HORIZ_DIR,6);
	outtextxy(175,40,"HELP");
	cout<<"\n\n\n\n\n\n\n\n";
	cout<<"\n	  Type the respective numbers to take you to the screen";
	cout<<"\n	  of your choice.The screens have information and options based on";
	cout<<"\n	  		the selection made.";
	cout<<"\n	  Your suggestions and ideas will be of great assistance";
	cout<<"\n	  	for us to do our project better in future.";
	cout<<"\nIn the main menu ";
	cout<<"\nPress 1st option to database";
	cout<<"\nPress 2nd option to get help";
	cout<<"\nPress 3rd option to view credits";
	cout<<"\nPress 4th option to exit";
	cout<<"\nIn database menu: ";
	cout<<"\nPress 1st option to go to player database";
	cout<<"\nPress 2nd option to go to team database";
	cout<<"\nIn each database: ";
	cout<<"\nPress 1st option to enter details";
	cout<<"\nPress 2nd option to list the records";
	cout<<"\nPress 3rd option to modify details";
	cout<<"\nPress 4th option to delete records";
	cout<<"\nPress 5th option to search and view details";
	cout<<"\nPress 6th option to exit from the program";
	cout<<"\nPress backspace key to navigate back to previous menu";
	getch();
	d:
	cout<<"\n\n\n\n\n\n\n\n\n\n\n Do you want to do again??(0-exit/1-continue)";
	chh=bioskey(0);
	if(chh==20273||chh==561)
			goto s;
	else if(chh==21040||chh==2864)
	{
		clear();
		strcpy(str,"imag21.bmp");
		img(str,20,300,323);
		menu1(350,4,110);
	}
	else
	goto d;
}
void credits()                             			
	for(int z=480;!kbhit();z--)
	{
		if(z==-500)z=480;
		cleardevice();
		setcolor(4);
		settextstyle(3,0,3);
		outtextxy(100,z-10,"~~~~~~~~COMPUTER PROJECT~~~");
		outtextxy(100,z+10,"~~~~~~~~BY~~~~~~~~");
		outtextxy(200,z+30,"*NAGABHARAN N");
		outtextxy(200,z+60,"*ARVIND P");
		outtextxy(100,z+90,"~~~~~~~~DATABASE DEVELOPER~~");
		outtextxy(200,z+120,"*NAGABHARAN N");
		outtextxy(100,z+150,"~~~~~~~~GRAPHICS DEVELOPER~~");
		outtextxy(200,z+180,"*ARVIND P");
		outtextxy(100,z+210,"~~~~~~~~SUPPORT~~~~~~~~~~~");
		outtextxy(200,z+240,"*KAVITHA MA'AM");
		outtextxy(200,z+270,"*FRIENDS");
		outtextxy(100,z+300,"~~~~~~~~THANK YOU!!!~~~~~~~~");
		delay(10);
	}
	getch();
}
void main()
{
	int key,x=350,y=80,j,p;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	welcome();
	a:
	j=pass();
	if(j==0)
	{
		setcolor(9);
		rectangle(180,180,460,270);
		setfillstyle(SOLID_FILL,RED);
		floodfill(185,235,9);
		setcolor(15);
		settextstyle(4,0,4);
		outtextxy(227,200,"\naccess granted");
		getch();
	cleardevice();
	strcpy(str,"imag21.bmp");
	img(str,20,300,323);
	menu1(350,4,110);
	options1();
	while((key=bioskey(0))!=0)
	{
		setcolor(0);
		options1();
		setfillstyle(1,0);
		floodfill(x+50,y,WHITE);
		setcolor(15);
		menu1(350,4,110);
		switch(key)
		{
			case 20480:if(y>=240) y=80;
				   y+=40;
				   break;
			case 18432:if(y<=120) y=280;
				   y-=40;
				   break;
			case 7181:switch(y)
				  {
					case 120:clearviewport();
						 database();
						 break;
					case 160:cleardevice();
						 help();
						 break;
					case 200:cleardevice();
						 credits() ;
						 clear();
						 strcpy(str,"imag21.bmp");
						 img(str,20,300,323);
						 menu1(350,4,110);
						 break;
					case 240:end();
						 break;
				  }
				  break;
			case  283:end();
		}
		setfillstyle(1,1);
		floodfill(x+50,y,WHITE);
		options1();

	}	}
	else
	{
		setcolor(9);
		rectangle(180,180,460,270);
		setfillstyle(SOLID_FILL,RED);
		floodfill(185,235,9);
		setcolor(15);
		settextstyle(4,0,4);
		outtextxy(215,200,"\ninvalid password");
		getch();
		e:
		cleardevice();
		setcolor(9);
		rectangle(100,180,550,270);
		setfillstyle(SOLID_FILL,RED);
		floodfill(185,235,9);
		setcolor(15);
		settextstyle(4,0,4);
		outtextxy(120,200,"\npress 1 to re-try,0 to exit");
		p=bioskey(0);
		if(p==20273||p==561) goto a;
		else if(p==21040||p==2864) end();
		else goto e;
	}
}
