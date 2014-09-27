/*********************************************************************************
passw.cpp
For use in our project
**********************************************************************************/
//HEADER FILES
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
/*********************************************************************************/
int pass()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver,&gmode,"C:\\tc\\bgi");
	int i=0,left,top,right,bottom;
	setcolor(RED); 					//background
	setfillstyle(1,RED);
	rectangle(0,0,getmaxx(),getmaxy());
	floodfill(1,1,RED);
	setcolor(15);					//password box[outer]
	rectangle(170,150,470,300);
	setfillstyle(9,BLUE);
	floodfill(175,180,WHITE);			//password box[inner]
	rectangle(180,230,460,270);
	setfillstyle(1,WHITE);
	floodfill(185,235,WHITE);
	char pass[20],pass1[20];
	int ch;
	strcpy(pass,"hell");
	settextstyle(4,0,4);
	outtextxy(215, 180, "Enter password");
	do
	{
		ch=getch();
		if(ch==13)
		{
			pass1[i]=NULL;
			break;
		}
		if(ch==8)
		{
			if(i==0)
				i++;
			setcolor(15);
			i--;
			outtextxy(215+(15*(i)),220,"*");
			pass1[i]=NULL;
		}
		else
		{
			if(i>12)
			{
				outtextxy(15,20,"password exceeding word limit");
				outtextxy(15,60,"type from beginning");
				getch();
				setcolor(4);
				outtextxy(15,20,"password exceeding word limit");
				outtextxy(15,60,"type from beginnin");
				while(i>=0)
				{
					setcolor(15);
					outtextxy(215+(15*(i)),220,"*");
					pass1[i]='\0';
					i--;
				}
				i=0;
			}
			pass1[i]=ch;
			setcolor(1);
			outtextxy(215+(15*i),220,"*");
			i++;
		}
	}while(ch);
	int j=strcmp(pass1,pass);
	return j;
}
