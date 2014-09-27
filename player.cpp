/*****************************************************************************/
/*****************************************************************************
		Player Management Database System
  			For use in the project
*******************************************************************************/
//HEADER FILES
#include<fstream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<graphics.h>
#include<iostream.h>
#include<time.h>
/*********************************************************************************/
int gdriver = DETECT, gmode;
int ranc(void)			//generating random numbers
{
   int i;
   time_t t;

   srand((unsigned) time(&t));
   i=(rand()%1000);
   return i;
}
class team_player 		//player class
{
	private:
	struct person
	{
	   char name[25],nation[25],reput[25],pob[25],lang[100],descp[100],foot[25],flag;
		int age,pcode;
	}p;
	fstream file;
	public:
		  team_player();

	void addrec();
	void listrec();
	void modirec();
	void delrec();
	void recallrec();
	void end();
	void getd();
	void pdisp();
};
void team_player::pdisp()			//displaying data
{
	closegraph();
	clrscr();
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	cout<<"Player Information";
	cout<<"\n\n\n\tCode: "<<p.pcode;
	cout<<"\n\n\tName: ";
	puts(p.name);
	cout<<"\n\tAge: "<<p.age;
	cout<<"\n\n\tPlace of birth: ";
	puts(p.pob);
	cout<<"\n\n\tNation: ";
	puts(p.nation);
	cout<<"\n\tReputation: ";
	puts(p.reput);
	cout<<"\n\tDescription: ";
	puts(p.descp);
	cout<<"\n\tLanguages known: ";
	puts(p.lang);
	cout<<"\n\tFoot: "<<p.foot;}
void team_player::getd()			//getting data
{
	cout<<"PLAYER DETAILS";
	cout<<"\n\n\n\n\tEnter Player Name: ";
	gets(p.name);
	cout<<"\n\tEnter Nation: ";
	gets(p.nation);
	cout<<"\n\tEnter Reputation: ";
	gets(p.reput);
	cout<<"\n\tEnter Place of birth: ";
	gets(p.pob);
	cout<<"\n\tEnter Languages known: ";
	gets(p.lang);
	cout<<"\n\tEnter Position: ";
	gets(p.descp);
	cout<<"\n\tEnter Foot(L/R): ";
	gets(p.foot);
	cout<<"\n\tEnter Age(More than 14): ";
	cin>>p.age;
	while(p.age<14)
	{
		cout<<"\n\tEnter Age: ";
		cin>>p.age;
	}
	p.pcode=ranc();
}
team_player::team_player()			//default constructor
{
}

void team_player::addrec()			//adding records
{
	file.open("team_player.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<endl<<"Unable to open file";
		end();
	}
	char ch;
	file.seekp(0L,ios::end);
	do
	{
		 team_player::getd();
		 file.write((char*)&p,sizeof(p));
		 cout<<"Add another record ?(y/n) :";
		 cin>>ch;
		 clrscr();
	}while(ch=='y'||ch=='Y');
	file.close();
}
void team_player::listrec()			//displaying records
{
	file.open("team_player.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<endl<<"Unable to open file";
		end();
	}
	int j=0,a;
	file.seekg(0L,ios::beg);
	cout<<"List of records present are as under>>>"<<endl<<endl;
	cout<<"             "<<"|CODE|"<<"           "<<"|NAME|"<<" "<<"|AGE|"<<" "<<"|POSITION|"<<" "<<"|RATING|"<<endl;
	while(file.read((char*)&p,sizeof(p)))
	{
	cout<<endl<<"Record#"<<"\t"<<++j<<setw(10)<<p.pcode<<setw(16)<<p.name<<setw(5)<<p.age<<setw(9)<<p.descp<<setw(10)<<p.reput<<endl;
	}
	file.clear();
	if(j==0)
	{
		 gotoxy(10,10);
		 cout<<"No record exit";
		 gotoxy(10,13);
		 cout<<"Press any key...";
		 getch();
	}
	else
	{
		 cout<<endl<<"Press any key...";
		 getch();
	}
	file.close();
}
void team_player::modirec()				//modifying records
{
	file.open("team_player.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<endl<<"Unable to open file";
		end();	}
	int code;
	int count=0;
	long int pos;
	int che=0;
	char ch;
	fstream f1;
	f1.open("team_player.dat",ios::binary|ios::in|ios::out);
	if(!f1)
	{
		cout<<endl<<"Unable to open file";
		end();
	}	
	cout<<"Do you want to know the team code for any team?";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		file.close();
		team_player::listrec();
		file.open("team_player.dat",ios::binary|ios::in|ios::out);
		if(!file)
		{
			cout<<endl<<"Unable to open file";
			end();
		}
	}
	cout<<"\n\nEnter player code whose record is to be modified :";
	cin>>code;
	file.seekg(0L,ios::beg);
	while(file.read((char*)&p,sizeof(p)))
	{
		 if(p.pcode==code)
		 {
			 cout<<endl<<"\n\nEnter new record "<<endl;
			 team_player::pdisp();
			 char name[25],nation[25],reput[25],pob[25],lang[100],descp[100],foot[25];
			 cout<<"\n\n\tNew name:(Enter '.'to retain old one) ";
			 gets(name);
			 cout<<"\n\tNew nation:(Enter '.'to retain old one) ";
			 gets(nation);
			 cout<<"\n\tNew reputation:(Enter '.'to retain old one) ";
			 gets(reput);
			 cout<<"\n\tNew place of birth:(Enter '.'to retain old one) ";
			 gets(pob);
			 cout<<"\n\tNew language:(Enter '.'to retain old one) ";
			 gets(lang);
			 cout<<"\n\tNew foot:(Enter '.'to retain old one) ";
			 gets(foot);
			 cout<<"\n\tNew position:(Enter '.'to retain old one) ";
			 gets(descp);
			 if(strcmp(name,".")!=0)
					strcpy(p.name,name);
			 if(strcmp(nation,".")!=0)
					strcpy(p.nation,nation);
			 if(strcmp(reput,".")!=0)
					strcpy(p.reput,reput);
			 if(strcmp(pob,".")!=0)
					strcpy(p.pob,pob);
			 if(strcmp(lang,".")!=0)
					strcpy(p.lang,lang);
			 if(strcmp(foot,".")!=0)
					strcpy(p.foot,foot);
			 if(strcmp(descp,".")!=0)
					strcpy(p.descp,descp);
			 pos=count*sizeof(p);
			 file.seekp(pos,ios::beg);
			 file.write((char*)&p,sizeof(p));
			 break;
		 } count++;}
	if(count==0)
	{
		cout<<endl<<"\n\nNo player in file with code= "<<code;
		getch();
	}
	file.close();
	f1.close();
}
void team_player::delrec()				//deleting records
{
	char ch;
	file.open("team_player.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<endl<<"Unable to open file";
		end();
	}
	int code;
	long int pos;
	char conf,fnd='f';
int che=0;
	fstream f1;
	f1.open("team_player.dat",ios::binary|ios::in|ios::out);
	if(!f1)
	{
		cout<<endl<<"Unable to open file";
		end();
	}	
	cout<<"Do you want to know the team code for any team?";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		file.close();
		team_player::listrec();
		file.open("team_player.dat",ios::binary|ios::in|ios::out);
		if(!file)
		{
			cout<<endl<<"Unable to open file";
			end();
		}
	}
	fstream file2("temp.dat",ios::binary|ios::in|ios::out);
	cout<<"\n\nEnter player's code to be deleted :";
	cin>>code;
	file.seekg(0L,ios::beg);
	file.read((char *)&p,sizeof(p));
	while(!file.eof())
	{
		 if(p.pcode==code)
		 {
				fnd='t';

		cout<<"\n\n\tAre you sure you want to delete this record?(y/n): ";			cin>>conf;
		if(conf=='n')
		file2.write((char *)&p,sizeof(p));
		 }
		 else
			file2.write((char *)&p,sizeof(p));
		 file.read((char *)&p,sizeof(p));
	}
	if(fnd=='f')
		 cout<<endl<<"\n\nNo player in file with code="<<code;
	file.close();
	file2.close();
	remove("team_player.dat");
	rename("temp.dat","team_player.dat");
	cout<<endl<<"\n\nPress any key...";
	f1.close();
	getch();
}
void team_player::recallrec()				//searching records
{
	file.open("team_player.dat",ios::binary|ios::in|ios::out);
	char ch;
	if(!file)
	{
		cout<<endl<<"Unable to open file";
		end();
	}
	int code,count=0;
	long int pos;
	char fnd='f';
int che=0;
	fstream f1;
	f1.open("team_player.dat",ios::binary|ios::in|ios::out);
	if(!f1)
	{
		cout<<endl<<"Unable to open file";
		end();
	}	
	cout<<"Do you want to know the team code for any team?";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		file.close();
		team_player::listrec();
		file.open("team_player.dat",ios::binary|ios::in|ios::out);
		if(!file)
		{
			cout<<endl<<"Unable to open file";
			end();
		}
	}
	cout<<"\n\nEnter player's code to be searched:";
	cin>>code;
	file.seekg(0L,ios::beg);
	file.read((char *)&p,sizeof(p));
	while(!file.eof())
	{
			if(p.pcode==code)
			{
				fnd='t';
				pos=count*sizeof(p);
				file.seekp(pos,ios::beg);
				team_player::pdisp();
				file.write((char*)&p,sizeof(p));
			}
			count++;
			file.read((char *)&p,sizeof(p));
	}
	if(fnd=='f')
			cout<<endl<<"\n\nNo player in the file with code="<<code;

	cout<<endl<<"\n\nPress any key...";
	getch();
	file.close();
	f1.close();
}
void team_player::end()					//exit function
{
	for(int i=0;i<16;i++)
	{
		setcolor(i+5);
		settextstyle(1, HORIZ_DIR, 9);
		outtextxy(60,120,"THANK YOU");
		delay(100);
	}
	exit(0);
}
