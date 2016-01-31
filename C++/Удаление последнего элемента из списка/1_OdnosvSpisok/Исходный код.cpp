#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

//��������� - ������(��������, ������� "���������" ���� �� ����� �������� next)
struct List
{
	int info;//�����, ������� � �������� ������ �����������
	List *next;//������ �� ��������� �������
	List (int x=0, List*p=NULL)//����������� �� ��������� ��� �������� ������
		{info=x; next=p;}
};

void Print(List*p)//������� ������� ������ ������.
{
	for (List*q=p; q!=NULL; q=q->next)
	{
		cout<<q->info<<" ";
	}
}

//������� ����� � ����� ��������� ������.
void AddEnd(List *q, int x) //��� ��� � - ��������.
{
		for (;q->next!=NULL; q=q->next)//���� �� ������ �� �����
			;
		q->next=new List(x);//��������� �������
}

//������� �������� ���������� ��������
void DeleteEnd(List*&p)//p-������ �� ������
{
	if (p!=NULL && p->next!=NULL)
	{
		List*q=p;//����� �� "���������" ����� ������� ��������
	
		while(q->next->next!=NULL)
			q=q->next;

		List*r=q->next;

		delete r;
		
		q->next=NULL;
	}
	else//������ - ����� ������ ������ ��� ������� �� ������ ��������
		{
			List*q=p;

			delete q;

			p=NULL;
		}
	

}

int main()
{
	
    setlocale(LC_ALL, "Russian");//����� ������������� ������� �����

	int n=5;//���������� ��������� ��� ������

	List *p=NULL;//�������������� - ������� ����� ������
	
	int k;//����������� ��� ����������
	
	cout<<"������� 5 ��������� �� �������:"<<endl;
	cout<<1<<" = ";
	cin>>k;
	p=new List(k);
	for(int i=0; i<n-1; i++)
	{
		cout<<i+2<<" = ";
		cin>>k;
		AddEnd(p,k);
	}
	
	//�������� ������
	cout<<"����� ��������� ������: ";
	Print(p);
	
	//������� ��������� ������� �� ������
	DeleteEnd(p);

	//�������� ����� ������
	cout<<endl<<"������ ��� ���������� ��������: ";
	Print(p);

	_getch();//��� �������� ������
	return 0;
}