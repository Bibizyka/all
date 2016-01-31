#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

//��������� - ������(��������, ������� "���������" ���� �� ����� �������� next)
struct E
{
	int info;//�����, ������� � �������� ������ �����������
	E *next;//������ �� ��������� �������
	//E (int x=0, E*p=NULL)//����������� �� ��������� ��� �������� ������
		///{info=x; next=p;}
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

//������� ����� � ����� ��������� ������.
void AddEnd (E *q, int x) //��� ��� � - ��������.
{
		for (;q->next!=NULL; q=q->next)//���� �� ������ �� �����
			;
		q->next=new E;//��������� �������
}

//������� � ����� ������
void push_back(E* &first, int int1) 
{
	//���� �� ����
if (first==NULL) 
{
   first=new E;
   first->next=NULL;
   first->info=int1;
   return;
}
else
{
	E* last=first;

	while (last->next!=NULL) 
		last=last->next;
;
	last->next=new E;


	last->next->info=int1;
	last->next->next=NULL;
	return;
}
}


//������� �������� �������� �� ��������� ������.
void DeleteUnit(E*&p,int n)//n-�����,p-������ �� ������
{
	if (n!=1)
		{
		E*q=p;
		int i=0;
		for (;i<n-2 && q!=NULL;q=q->next,i++)//���� �� �������
		{
		}

		if (q->next!=NULL)//�������, ���� ����� ������� �������� - ���-�� ���������� ������
		{
			E *r=q->next;
			q->next=q->next->next;
			delete r;
		}
		else//����� - ������� ���������
			if (q->next==NULL)
				q=NULL;
		}
	else
		if (n==1)
		{
			E *q=p;
			p=p->next;
			delete q;
		}
}

int main()
{
	
	ifstream f("data.txt");
	//�������� �� ������������� ����
	if (f.fail())
	{
		cout<"data.txt is not exist!(ne sushestvuet!)";
		getch();
		return 0;//�������� ������
	}
	else;

	E *p=NULL;//�������������� - ������� ����� ������
	
	int k;//����������� ��� ����������
	//���������� � ������ - ��������� �� �����.
	f>>k;
	//p=new E(k);

	while(!f.eof())
	{
		f>>k;
		push_back(p,k);
	}
	
	//�������� ������
	cout<<"Old List: ";
	Print(p);
	
	//������� ������ ������� �� ������
	DeleteUnit(p,2);

	//�������� ����� ������
	cout<<endl<<"New list without second element: ";
	Print(p);


	f.close();
	_getch();//��� �������� ������
	return 0;
}