/*************************************************************
		Team Management Database System

  			For use in the project

*************************************************************/
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
#include<math.h>
#include<time.h>
#include<ctype.h>
/************************************************************/
int gd=DETECT,gm;
class soccer					//statistics class
{
	  public:
		void setinfo();
		void display();
	  private:

		int played;
		int won;
		int draw;
		int lost;
		int scored;
		int conceded;
		int points;
		int gd;
};
class team					//team class
{
	private:
		struct teamp
		{
			char name[25],nation[25],flag,riv[100];
			int tcode,rat,year;
			soccer s;

		}t;
	fstream file;
	public:
		  team();

	void addrec();
	void listrec();
	void modirec();
	void delrec();
	void recallrec();
	void end();
	void getd();
	void tdisp();
};

void soccer::setinfo()					//getting stats
{
	again:
	won=draw=lost=scored=conceded=points=gd=0;
	cout<<"\n\n\tEnter the number of matches played: ";
	cin>>played;
	if(played!=0)
	{
		cout<<"\n\n\tEnter the number of matches won: ";
		cin>>won;
		if(won!=played)
		{
			cout<<"\n\n\tEnter the number of matches drawn: ";
			cin>>draw;
			cout<<"\n\n\tEnter the number of matches lost: ";
			cin>>lost;
			if(played>(won+draw+lost)||played<(won+draw+lost))
			{
			cout<<"\n\n\tNo. of matches played not equal";
			goto again;
			}
		}
		cout<<"\n\n\tEnter the number of goals scored: ";
		cin>>scored;
		cout<<"\n\n\tEnter the number of goals conceded : ";
		cin>>conceded;
		points=won*3+draw;
		gd=scored-conceded;
	}
}
void soccer::display()					//stats display
{
	cout<<"\n\t\tTeam statistics\n";
	cout << "\n\n\tNumber of games played: " << played << endl;
	cout << "\n\n\tNumber of games won: " << won << endl;
	cout << "\n\n\tNumber of games drawn: " << draw << endl;
	cout << "\n\n\tNumber of games lost: " << lost << endl;
	cout << "\n\n\tNumber of goals scored: " << scored << endl;
	cout << "\n\n\tNumber of goals conceded: " << conceded << endl;
	cout << "\n\n\tNumber of points collected: " << points << endl;
	cout << "\n\n\tGoal difference:  " << gd << endl;
}
void team::tdisp()					//displaying data
{
	closegraph();
	clrscr();
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	cout<<"\n\t***Team Information***";
	cout<<"\n\n\tName: ";
	puts(t.name);
	cout<<"\n\n\tNation: ";
	puts(t.nation);
	cout<<"\n\n\tReputation: "<<t.rat;
	cout<<"\n\n\tYear founded: "<<t.year;
	cout<<"\n\n\tFierce Rivals: ";
	puts(t.riv);
	cout<<"\n\nDo you want to see team stats for this season??(y/n)";
	char c;

	cin>>c;
	if(c=='y')
		t.s.display();
	else
		getch();
}
void team::getd()					//getting data
{
	cout<<"\n\n\n\n\tEnter Team Name: ";
	gets(t.name);
	t.tcode=ranc();
	cout<<"\n\tEnter Nation: ";
	gets(t.nation);
	agn:
	cout<<"\n\tEnter Reputation(0-10): ";
	cin>>t.rat;
	while(t.rat>10||t.rat<0)
	{
		cout<<"\n\n\tInvalid entry!! Please enter again";
		cout<<"\n\n\tEnter Reputation: ";
		cin>>t.rat;
	}
	cout<<"\n\tEnter Year founded(More than 1800): ";
	cin>>t.year;
	while(t.year<1800)
	{
		cout<<"\n\n\tInvalid entry!! Please enter again";
		cout<<"\n\n\tEnter Year founded: ";
		cin>>t.year;
	}

	cout<<"\n\tEnter fierce rivals: ";
	gets(t.riv);
	t.s.soccer::setinfo();
}
team::team()						//default constructor
{
	file.open("team.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
			cout<<endl<<"Unable to open file";
			end();
	}
	file.close();
}
void team::addrec()					//adding records
{
	file.open("team.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
			cout<<endl<<"Unable to open file";
			end();
	}
	char ch;
	file.seekp(0L,ios::end);
	cout<<"\n\nTEAM DETAILS"<<endl;
	do
	{
		 team::getd();

		 file.write((char*)&t,sizeof(t));
		 cout<<"\n\nAdd another record ?(y/n) :";
		 cin>>ch;
	}while(ch=='y'||ch=='Y');
	file.close();
}
void team::listrec()					//displaying records
{
	file.open("team.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<endl<<"Unable to open file";
		end();
	}
	int j=0,a;
	file.seekg(0L,ios::beg);
	cout<<"\n\nNames of teams present in the database:\n\n"<<endl<<endl;
	cout<<"             "<<"CODE"<<"           "<<"NAME"<<"     "<<"COUNTRY"<<"\t"<<"RATING"<<endl;
	while(file.read((char*)&t,sizeof(t)))
	{
   cout<<endl<<"Record#"<<"\t"<<++j<<setw(7)<<t.tcode<<setw(16)<<t.name<<setw(10)<<t.nation<<setw(107)<<setw(10)<<t.rat<<endl;
	}
	if(j==0)
	{
			gotoxy(12,10);
			cout<<"\n\nNo record exit";
			gotoxy(12,13);
			cout<<"\n\nPress any key...";
		getch();
	}
	else
	{
			cout<<endl<<"Press any key...";
			getch();
	}
	file.close();
}
void team::modirec()					//modifying records
{
	int che=0;
	fstream f1;
	f1.open("team1.dat",ios::binary|ios::in|ios::out);
	if(!f1)
	{
		cout<<endl<<"Unable to open file";
		end();
	}
	file.open("team.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<endl<<"Unable to open file";
		end();
	}
	int code;
	int count=0;
	long int pos;
	char ch;

	cout<<"Do you want to know the team code for any team?";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		file.close();
		team::listrec();
		file.open("team.dat",ios::binary|ios::in|ios::out);
		if(!file)
		{
			cout<<endl<<"Unable to open file";
			end();
		}
	}
	cout<<"\n\nEnter team code whose record is to be modified :";
	cin>>code;
	file.read((char*)&t,sizeof(t));
	while(!file.eof())
	{
		  if(t.tcode!=code)
		  {
			  f1.write((char*)&t,sizeof(t));
		  }
		  else
		  {
			 che=1;
			 cout<<"\n";
			 team::tdisp();
			 cout<<"\nEnter the new team details ";
			 team::getd();
		 f1.write((char*)&t,sizeof(t));	   }
	  file.read((char*)&t,sizeof(t));	}
	if(che==0)
			cout<<"\n\nCode number does not exist\n";
	remove("team.dat");
	rename("team1.dat","team.dat");
	cout<<endl<<"Press any key...";
	getch();
	f1.close();
	file.close();
}
void team::delrec()					//deleting records
{
	int che=0;
	file.open("team.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<endl<<"Unable to open file";
		end();
	}
	int code,count=0;
	long int pos;
	char conf,fnd='f';
	char ch;
	cout<<"Do you want to know the team code for any team?";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
			file.close();
			team::listrec();
			file.open("team.dat",ios::binary|ios::in|ios::out);
		if(!file)
			{
					cout<<endl<<"Unable to open file";
					end();
			}
	}
	cout<<"\n\nEnter team code to be deleted :";
	cin>>code;
	fstream f1;
	f1.open("team1.dat",ios::binary|ios::in|ios::out);
	if(!f1)
	{
			cout<<endl<<"Unable to open file";
			end();
	}
	file.read((char*)&t,sizeof(t));
	while(!file.eof())
	{
		  if(t.tcode!=code)
					  f1.write((char*)&t,sizeof(t));
		  else
					che=1;
		  file.read((char*)&t,sizeof(t));
	}
	if(che==0)
			 cout<<"\n\nCode number does not exist\n";

	remove("team.dat");
	rename("team1.dat","team.dat");
	cout<<endl<<"Press any key...";
getch();
	f1.close();
	file.close();
}
void team::recallrec()					//searching records
{
	 file.open("team.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
			cout<<endl<<"Unable to open file";
			end();
	}
	int code,count=0;
	long int pos;
	char fnd='f';
	char ch;
	cout<<"Do you want to know the team code for any team?";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
			file.close();
			team::listrec();
			file.open("team.dat",ios::binary|ios::in|ios::out);
			if(!file)
			{
			cout<<endl<<"Unable to open file";
			end();
			}
		 }
		 cout<<"\n\n\tEnter team code to be recalled :";
		 cin>>code;
		 file.seekg(0L,ios::beg);
		 while(!file.eof())
		 {
			file.read((char *)&t,sizeof(t));
			if(t.tcode==code)
			{
				fnd='t';
				pos=count*sizeof(t);
				file.seekp(pos,ios::beg);
				team::tdisp();
				file.write((char*)&t,sizeof(t));
			}
			count++;
		}
		if(fnd=='f')
			cout<<endl<<"No such team in the file with code="<<code;
		cout<<endl<<"Press any key...";
		getch();
		file.close();
 }
void team::end()				//exit function
{
	for(int i=0;i<16;i++)
	{
		outtextxy(60,120,"THANK YOU");
		delay(100);
	}
	exit(0);
}
