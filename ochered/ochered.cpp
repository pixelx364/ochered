#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class Ochered
{
private:
	int * point;
	int s; 
	int l; 
	int fst; 
	int lst; 
	bool nF(); 
	bool nE(); 
public:
	Ochered(); 
	void add(); 
	void take(); 
	void print(); 
	~Ochered();
};
Ochered::Ochered() 
	:l(0)
	,fst(0)
	,lst(-1)
{
	cout<<"Vvedite razmer:";
	cin>>s;
	while (s<=0)
	{
		cout<<"\nnepravilnii razmer\n"<<std::endl;
		cout<<"Vvedite razmer:";
		cin>>s;
	}
	point=new int [s];
}
bool Ochered::nF() 
{
	if (l<s) 
		return true;
	else
		return false;
}
bool Ochered::nE() 
{
	if (l>0)
		return true;
	else
		return false;
}
void Ochered::add() 
{
	if(nF())
	{
		int num;
		cout<<"\nVvedite element: ";
		cin>>num;
		lst=(lst+1)%s;
		point[lst]=num;
		l++;
		cout<<endl;
	}
	else
		cout<<"\nzapolneno\n"<<endl;
}
void Ochered::take() 
{
	if (nE())
	{
		cout<<"\nydalit element: "<<point[fst]<<endl<<endl;
		fst=(fst+1)%s;
		l--;
	}
	else
		cout<<"\nzapolneno\n"<<endl;
}
void Ochered::print() 
{
	if (nE())
	{
		int number=0;
		cout<<"\nVvedi nomer elementa:";
		cin>>number;
		while (!((0<number)&&(number<=l)))
		{
			cout<<
				"\nNomer elementa dolzhen bit bolshe 0 "
				    <<endl;
			cout<<"\nVvedite nomer elementa:";
			cin>>number;
		}
		cout<<endl<<point[(fst+number-1)%s]<<endl<<endl;
	}
	else
		cout<<"\n\n"<<endl;
}
Ochered::~Ochered()
{
	delete [] point;
};
char ask() 
{
	cout<<"Viberite deistvie: "<<endl;
	cout<<"1)dobavit"<<endl;
	cout<<"2)ydalit"<<endl;
	cout<<"3)pokazat i element"<<endl;
	cout<<"4)vixod"<<endl;
	char ask;
	cin.clear();
	cin>>ask;
	return ask;
}
void main()
{
	Ochered Ochered1;
	char exit_=1;
	while(exit_)
	{
		switch(ask())
		{
		case '1':
			{
				Ochered1.add();
				break;
			}
		case '2':
			{
				Ochered1.take();
				break;
			}
		case '3':
			{
				Ochered1.print();
			}
			break;
		case '4':
			exit_=0;
			break;
		default:
			std::cout<<"\nnepravilnii vvod! Povtorite vvod\n\n";
			break;
		}
	}
	system("pause");
}
