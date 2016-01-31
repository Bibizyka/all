#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>

using namespace std;

	typedef struct Zajavka
	{
		string punkt_nazn;
		int  numbe_reys;
		char FIO[100];
		char date[100];
	};
	//��������� - ������(��������, ������� "���������" ���� �� ����� �������� next)
	typedef struct Node {
		Zajavka value;
		struct Node *next;
	} Node;


//������� � ����� ������
void push_back(Node* &first, Zajavka int1) 
{
	//���� �� ����
if (first==NULL) 
{
   first=new Node;
   first->next=NULL;
   first->value=int1;
   return;
}
else
{
	Node* last=first;

	while (last->next!=NULL) 
		last=last->next;
;
	last->next=new Node;


	last->next->value=int1;
	last->next->next=NULL;
	return;
}
}

//������ ���� ������
void print(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->value.FIO<<endl;
		head=head->next;
	}
}

//����� �� ����-������ ������ ������
void print_data_number(Node* head,char* date, int n)
{
	//���� ������ �� ���� - ������� ������
	while(head!=NULL)
	{
		if( strcmp(date,head->value.date)==0 && n==head->value.numbe_reys) cout<<head->value.FIO<<" "<<head->value.numbe_reys<<endl
			; else ;
		head=head->next;
	}


}


	int Choice()//����� ��������:
        {
            cout<<"������� ����� ��� ��������:"<<endl;
            cout<<"1 - ������� ������;"<<endl;
            cout<<"2 - ������� ������ �� ��������� ������ ����� � ���� �����"<<endl;
            cout<<"3 - ����� ���� ������;"<<endl;
            cout<<"4 - �����."<<endl;
			int t;

			cin>>t;
			//������������ �����
			if(t>0 && t<5)
            return t;
			else return 4;
        };

	//�������� ������
 Node* delete_spisok(Node *&car)
 {
  Node *p=car;
    while (p->next)
  {
    Node *tmp;
       tmp = p;
        p = p->next;
        delete tmp;
  }
  p=p->next;
  delete []p;

  car=NULL;
   cout << endl;
 return car;
  }
	
int main()
{
	setlocale(LC_ALL, "Russian");//����� ������������� ������� �����
	cout<<"������� ���������� ������:"<<endl;
	int kol;
	cin>>kol;
	
	Node *node=NULL;

	//��������� � ������ ������
	//�� ������� ��������� ������
	for(int i=0; i< kol; i++)
	{
		cout<<"������� ������ ����� "<<i+1<<endl;
		string punkt_nazn;
		int  numbe_reys;
		char FIO[100];
		char date[100];
		
		cout<<"����� ����������:"<<endl;
		cin>>punkt_nazn;
		cout<<"����� �����:"<<endl;
		cin>>numbe_reys;
		cout<<"�������:"<<endl;
		cin>>FIO;
		cout<<"����:"<<endl;
		cin>>date;

		Zajavka z;
		z.punkt_nazn=punkt_nazn;
			strcpy(z.FIO,FIO);
			strcpy(z.date,date);
			z.numbe_reys=numbe_reys;

		//��������� � c�����
		push_back(node, z);
	}

            int n = 0;
            while (n != 4)
            {
                n = Choice();//�������� ����������� ��������
                if (n != 4)//���� �� ������� �����
                {
					switch(n)//��������� ��������� ��������
                    {
                        case 1:
                        {
							cout<<"��� ������ �������."<<endl;
							delete_spisok(node);
                        }
                        break;
                        case 2:
                        {
							char date[1000];
							int n;
							cout<<"�����: ������� ���� ����� � ����� ����� ����� Enter: "<<endl;
							cin>>date;
							cin>>n;
							print_data_number(node,date,n);
                        }
                        break;
                        case 3:
                        {
							print(node);  
                        }
                        break;
                    }
                }
            }
	return 0;
}
