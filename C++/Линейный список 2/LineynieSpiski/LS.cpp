#include<iostream>
#include<conio.h>
using namespace std;

struct E
{
	int info;
	E *next;
	E (int x=0, E*p=NULL)
		{info=x; next=p;}
};

int Print (E*p)//������� ������� ������ ������.
{
	int k=0;
	for (E*q=p; q!=NULL; q=q->next,k++)
	{
		cout<<q->info<<" ";
	}
	return k;
}

int PrintR(E*p)//����������� ������� ������ ������ �� �������.
{
	if (p==NULL) return 0;
	else
	{
		cout<<p->info<<" ";
		return (1+ Print(p->next));
	}
}

int PrintRR(E*p)//����������� ������� ������ ������ �� ��������� �������.
{
	if (p==NULL) return 0;
		else
		{
			int k=1+ PrintRR(p->next);
			cout<<p->info<<" ";
			return k;//k-����������.
		}
}

//������� ����� � ������ ��������� ������.
void AddBegin (E *&p, int x) //��� ��� � - ��������.
{
	p=new E(x,p);
};

//������� ����� � ����� ��������� ������.
void AddEnd (E *q, int x) //��� ��� � - ��������.
{
	for (;q->next!=NULL; q=q->next)
		;
	q->next=new E(x);
}

//������� �������� ��������� ��������� ������ � ������.
void Delete(E*&p)
{
	for (E*q=p,*r;q!=NULL;q=r)
	{
		r=q->next;
		delete q;
	}
	p=NULL;
}

//������� �������� �������� � �������� ���������.
void DeleteUnit(E*&p,int x)
{
	E*q=p, *r;
	for (;q->info!=x;q=q->next)
	{
		;
	}
	if (q->next!=NULL)
	{
		q->next=q->next->next;
		delete q;
	}
}
/*void Insert( , int x, int pos)// pos - �������, � - �������.
{
}
*/

int main()
{
	E *p=NULL;

	p=new E;
	p->info=3;
	p->next=NULL;

	p->next=new E;
	p->next->info=7;
	p->next->next=NULL;

	E *q=p;
	p=new E;
	p->info=1;
	p->next=q;
	cout<<endl<<"LinSpisok: "<<endl;
	cout<<"Kol= "<<Print(p)<<endl;
	cout<<endl;

	//���������� � ������ ������.
	int x;
	cout<<"Vvod v nachalo !=0:"<<endl;
	cin>>x;
	for ( ; x!=0; )
	{
		AddBegin(p,x);
		cin>>x;
	}
	cout<<endl<<"LinSpisok: "<<endl;
	cout<<"Kol= "<<Print(p)<<endl;

	//���������� � ����� ������.
	cout<<endl<<"Vvod v konec !=0 :"<<endl;
	cin>>x;
	for ( ; x!=0; )
	{
		AddEnd(p,x);
		cin>>x;
	}
	cout<<endl<<"LinSpisok: "<<endl;
	cout<<"Kol= "<<Print(p)<<endl;

	cout<<endl<<"Delete:";
	//�������� �������� ���.������ � �������� ���������:
	cout<<endl<<"Vvedite element s zadannim znaheniem: ";
		cin>>x;
	DeleteUnit(p,x);

	//�������� ��������� ������:
	Delete(p);
	cout<<endl<<"LinSpisok: "<<endl;
	cout<<"Kol= "<<Print(p)<<endl;
	cout<<"Kol= "<<PrintR(p)<<endl<<"Rekursia - naoborot: "<<endl;
	cout<<"Kol= "<<PrintRR(p);

	_getch();
	return 0;
}