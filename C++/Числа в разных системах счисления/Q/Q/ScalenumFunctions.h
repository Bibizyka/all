#include<fstream>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

//��������� - ������(��������, ������� "���������" ���� �� ����� �������� next)
typedef struct Node {
    int value;
    struct Node *next;
} Node;


//������� � ����� ������
void push_back(Node* &first, int int1) 
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

int size(Node* head)
{
	int s=0;
	Node*temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		
		s++;
	}

	return s;
}
//���������� ������� ������� �������
int element(Node* head, int n)
{
	int nomer=0;
	Node*temp=head;

	while(nomer<n)
	{
		temp=temp->next;
		nomer++;
	}

	return temp->value;
}
//�������� ������� ������� ������
void change(Node*&head, int n)
{
	int nomer=0;
	Node*temp=head;

	while(temp!=NULL && nomer<n)
	{
		temp=temp->next;
		nomer++;
	}

	temp->value=temp->value+1;

}

class Scalenum//����� ��� ������ � q-����� �������� ���������
    {
	public: int q;//��������� ������� ���������
	public: Node* digits;//������ ��������� ���� � q-����� ������������� �����
	public: Node* degrees;//������ �������� ��������������� ����

	public: Scalenum(int q = 10)//����������� ������ � �������� ���������� ������� ���������:
        {//q - ��������� ������� ���������
            this->q = q;
			digits=NULL;
			degrees=NULL;
        }
			
	public: string ToString()//�������������� � ������(��������������� object.ToString())
        {
            string s;//������-���������
			Node *temp=digits;
            for (int i = 0; i < size(digits); i++)
			{
				char buffer1[20];
				itoa(element(digits,i),buffer1,10);

				s.append(buffer1);
				s.append(" ");

				char buffer2[20];
				itoa(element(degrees,i),buffer2,10);

				s.append(buffer2);

				s.append("\r\n");

				temp=temp->next;
			}
			return s;
		}
	/*
	public: void Insert(Scalenum s)//������� ������ ����� � ����������� ����� ������� �����:
        {//s - �����, ������� ���������
            if (s.q != q)
                cout<<"����� ������ ����� ���������� ��������� ������� ���������."<<endl;
            Node* digits1;//������ ��������� ���� ����������
            Node* degrees1;//������ ��������������� �������� ����������

            for (int i = 0; i < size(digits); i++)//���������� ��� ����� ��������� �����
            {
                if (element(degrees,i) <= element(degrees,(size(digits) - 1)) / 2)// ���� ����� � ������ ��������
                {
					push_back(digits1,element(digits,i));//��������� ��
                    push_back(degrees1,element(degrees,i));
                    if (element(degrees,i + 1) > element(degrees,(size(degrees) - 1)) / 2)//���� ��� ��������� ����� � ������ ��������
                    {
						for (int j = 0; j < size(s.degrees); j++)//��������� ����� s
                        {
                            push_back(digits1, element(s.digits,j));
                            push_back(degrees1,element(s.degrees,j) + element(degrees,(size(degrees) - 1)) / 2 + 1);//��� ��� ������� ������������� �� degrees[degrees.Count - 1] / 2 + 1
                        }
                    }
                }
                else//���� ����� �� ������ ��������
                {
                    push_back(digits1,element(digits,i));//��������� ��
                    push_back(degrees1,element(degrees,i) + element(s.degrees,size(s.degrees) - 1) + 1);//��� ��� ������� �� s.degrees[s.degrees.Count - 1] + 1
                }
				
            }
            digits=NULL;
            digits = digits1;//���������� � ��������
            degrees=NULL;
            degrees = degrees1;//���������� � ��������
        }
		*/
};
	

	Scalenum Coding(int n, int q = 10)//���������� ����� � q-����� ������� ��������� �� ��������� ����� � 10-������ �������:
        {//n - ������������� �����;q - ��������� ������� ���������
            Scalenum s(q);//���������� ��� ����������
            for (int i = 0; n != 0; i++, n /= q)
            {
                if (n % q != 0)
                {
					push_back(s.digits,n % q);
                    push_back(s.degrees,i);
                }
            }
            return s;
        }

	int Decoding(Scalenum &sc)//���������� ����� � 10-����� ������� ��������� �� ��������� ����� � q -����� �������:
        {//sc - ������������� �����
            int n = 0;//���������� ��� ����������
			for (int i = 0, j = 0, q = 1; i < size(sc.degrees); i++)
            {
                for (; j < element(sc.degrees,i); j++, q *= sc.q) ;
                n += element(sc.digits,i) * q;
            }
            return n;
        }

	void Delete(Scalenum &sc)//����������� �������:
        {//sc - ������������� �����
			sc.digits=NULL;
            sc.degrees=NULL;

        }

	void QMult(Scalenum &sc)//��������� ����� �� q:
        {//sc - ����� ������� ��������
            for (int i = 0; i < size(sc.degrees); i++)
                change(sc.degrees,i);
        }

	void Sum(  Scalenum &sc, int n)//���������� ����� �� �� ��������� 
        {//sc - �����;n - ���������
            int m = Decoding(sc) + n;
            sc = Coding(m, sc.q);
        }

	int MED(Scalenum &sc)//���������� �����, ������� ����������� � ������������� ����� ������������ ����� ���:
        {//sc - �����
            int* a = new int[sc.q];//���������� ���������� ���� � �����
			for (int i = 0; i < size(sc.digits); i++)
                a[element(sc.digits,i)]++;
            a[0] = element(sc.degrees,size(sc.degrees) - 1);
            for(int i = 1;i < sc.q;i++)
                a[0]-= a[i];
            int max = -1, imax = -1;
            for(int i = 0;i < sc.q;i++)
                if (a[i] > max)
                {
                    max = a[i];
                    imax = i;
                }
            return imax;
        }

;

	Scalenum operator *(Scalenum s1, Scalenum s2)//������������ ���� ����� � q-����� ������� ���������:
        {//s1, s2 - ����� � q-����� ������� ���������
            if (s1.q != s2.q)
            {
                cout<<"����� ������ ����� ���������� ��������� ������� ���������."<<endl;
                return NULL;
            }
            Scalenum s(s1.q);//���������� ��� ����������
            Scalenum q(s1.q);//���������� ��� ������� q
            Sum(q, Decoding(s1));
			for (int i = 0, j = 0; i < size(s2.degrees); i++)//���������� ��� �������� ����� �� ������ �����
            {
                for (; j < element(s2.degrees,i); j++, QMult(q)) ;//������� �� ������ �������
                Sum(s, Decoding(q) * element(s2.digits,i));//����������� � ���������� s1 * q^s2.degrees[i] * s2.digits[i]
            }
            return s;
        }
	;
	Scalenum operator +( Scalenum s1,  Scalenum s2)//����� ���� ����� � q-����� ������� ���������:
        {//s1, s2 - ����� � q-����� ������� ���������
            if (s1.q != s2.q)
            {
				cout<<"����� ������ ����� ���������� ��������� ������� ���������."<<endl;
                return NULL;
            }
            Scalenum s(s1.q);//���������� ��� ����������
            Sum(s, Decoding(s1));
            Sum(s, Decoding(s2));
            return s;
        }
	;
	Scalenum operator %(Scalenum s1, Scalenum s2)//������� ���� ����� � q-����� ������� ���������:
        {//s1, s2 - ����� � q-����� ������� ���������
            if (s1.q != s2.q)
            {
                cout<<"����� ������ ����� ���������� ��������� ������� ���������."<<endl;
                return NULL;
            }
            Scalenum s; s=Coding(Decoding(s1) % Decoding(s2), s1.q);//���������� ��� ����������
            return s;
        }
	;