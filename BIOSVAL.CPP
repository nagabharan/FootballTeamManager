#include<iostream.h>
#include<bios.h>
#include<conio.h>
void main()
{
	int ch;
	while((ch=bioskey(0))!=283)
	{
		cout<<ch<<endl;
	}
};
