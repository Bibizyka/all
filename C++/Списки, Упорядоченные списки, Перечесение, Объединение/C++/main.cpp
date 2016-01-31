#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

/*��������� ���� ������*/
struct Node
{
	int element; //�������
	Node *Next; //����� �� ��������� �������

	//����������� �� ��������� ��� ������� ���� ������
public:
	Node()
	{
		element = 0;
		Next = NULL;
	}
	Node(int a)
	{
		element = a;
		Next = NULL;
	}
};

//��� ������
class List
{
protected:
	Node *top; //��������� �� ������ ������
	Node *marker; //��������� �� ������� ������� �����
	Node *pred;//��������� �� ���������� ������� ������. ��������� � top, ���� � ������ 1� �������
public:
	List() :top(NULL){}; //����������� �� ��������� (top=NULL) - ������� ������ ������
	void Reset();//���������� ������ �� ������
	void Move();//����� �� ������ �� ���� ���
	bool EoList();//�������� - �� ��������� �� ������ �� ����� ������.����� ������ - ��� ����� ��������� ������������ �������
	void AddToList(int a);//���������� � ������ ����� ������� ����� �����������
	void Show();//�������� ������
	void Del();
	Node * TakeTop()//��������� ������ �� �������� ������
	{
		Node *temp=this->top;
		return temp;
	}
	
};

//����������� ����� ������������� ������ UporList �� List
class UporList : List
{
public:
	UporList()
	{
		top = NULL;
		marker=NULL;
		pred=NULL;
	}; //����������� �� ��������� (top=NULL) - ������� ������ ������

	//����������� - ��������� ������ - ������ �� ������
	UporList(List *new_list)
	{
		this->top = new_list->TakeTop();

		//��������� "���������"
		Node * list = top; // ��������� ������
		Node * node, * node2;
 
		for( node = list; node; node = node->Next )
			for( node2 = list; node2; node2 = node2->Next )
				if( node->element < node2->element ){ // ���� ����� �� node ������ ����� �� node2 �� ������������ ��
					int i = node->element;
				    node->element = node2->element;
					node2->element = i;
            }
	}
	//������� ����������� ���� ������������� ������� - ����� �������, ������������� ��������.
	//������������ ������ ������ �� ������
	void Union(UporList *t,UporList *list)
	{
		//������� ����� ����� ������ ����� �������(������, ����������� �� �����)
		Node * asda = t->TakeTop(), *qwe = top;
		//list.AddToList(12);
		//���� �� ������� ����� �������, ���� ��� �� ������
		for (; qwe || asda;)
		{
			if (qwe && asda)
			{
				if (qwe->element > asda->element)
				{
					list->AddToList(asda->element);
					asda = asda->Next;
				}
				else //if int go for
				{
					list->AddToList(qwe->element);
					qwe = qwe->Next;
				}
			}
			else
				if (asda)
				{
					list->AddToList(asda->element);
					asda = asda->Next;
				}
				;
					if (qwe)
					{
						list->AddToList(qwe->element);
						qwe = qwe->Next;
					}
				
		}
		//UporList list2(&list);
		//list2.UporListShow();
		//list.Show();
		//list2.UporListShow();
		//return (list2);
	}

	UporList& operator + ( UporList d) 
	{
		//void Union(UporList *t,UporList *list)
		static UporList ul;
	//������� ����� ����� ������ ����� �������(������, ����������� �� �����)
		Node * asda = d.TakeTop(), *qwe = top;
		//list.AddToList(12);
		//���� �� ������� ����� �������, ���� ��� �� ������
		for (; qwe || asda;)
		{
			if (qwe && asda)
			{
				if (qwe->element > asda->element)
				{
					ul.AddToUporList(asda->element);
					asda = asda->Next;
				}
				else //if int go for
				{
					ul.AddToUporList(qwe->element);
					qwe = qwe->Next;
				}
			}
			else
				if (asda)
				{
					ul.AddToUporList(asda->element);
					asda = asda->Next;
				}
				;
					if (qwe)
					{
						ul.AddToUporList(qwe->element);
						qwe = qwe->Next;
					}
				
		}
		return ul;

	}


	UporList& operator - ( UporList d) 
	{
		static UporList inters;
		
		//������� ����� ����� ������ ����� �������(������, ����������� �� �����)
		Node * asda = d.TakeTop(), *qwe = top;
		
		//���� �� ������� ����� �������, ���� ��� �� ������
		for (; qwe && asda;)
		{
			if (qwe->element==asda->element)
			{
				inters.AddToUporList(qwe->element);
				qwe=qwe->Next;
				asda=asda->Next;
			}
			else
			{
				if(qwe->element>asda->element)
				{
					asda=asda->Next;
				}
				else
				{
					qwe=qwe->Next;
				}
			}
		}
		return inters;
	}


	//������� ����������� ���� ������������� �������, ������������� ��������
	void Intersection(UporList *t,UporList *list)
	{
		//������� ����� ����� ������ ����� �������(������, ����������� �� �����)
		Node * asda = t->TakeTop(), *qwe = top;

		//���� �� ������� ����� �������, ���� ��� �� ������
		for (; qwe && asda;)
		{
			if (qwe->element==asda->element)
			{
				list->AddToList(qwe->element);
				qwe=qwe->Next;
				asda=asda->Next;
			}
			else
			{
				if(qwe->element>asda->element)
				{
					asda=asda->Next;
				}
				else
				{
					qwe=qwe->Next;
				}
			}
		}
	}

	//������ � ����
	void ToFile()
	{
		//������� � ����
		ofstream file("result.txt");
		file.clear();//������� ��� ����� ������
		if (file.fail())
		{
			cout<<"���� rezult.txt �� ����������!";
			getch();
			return;//�������� ������
		}
		else;

		Node * temp = top; //��������� ��������� � ���������� �� ��������� �� ������

		while (temp != NULL) //���� �� ������ �� ������ ���� ���-�� ����
		{
			//������� ��� �������� ���������
			cout<<" "<<temp->element;
			file<<temp->element<<endl;
			temp = temp->Next; //��������� �� ��������� ����� �� ������
		}

		file.close();
	}

	//���������� - �������� �� ������������� �����
	~UporList()
	{
		//while (top != NULL) //���� �� ������ ���� ���� ���-��
		//{
		//	Node *temp = top->Next; //����� ���������� ��������� �� ����� ���������� �������� ���������
		//	delete top; //����������� ������ �� ����� ������ ������
		//	top = temp; //������ ����� ������ ������
		//}
		while (top != NULL)
		 {
			Node *next = top->Next;
			delete top;
			top = next;
		}
	}
	
	void  UporListShow()
	{
		Node *temp = top; //��������� ��������� � ���������� �� ��������� �� ������

		while (temp != NULL) //���� �� ������ �� ������ ���� ���-�� ����
		{
			//������� ��� �������� ���������
			cout<<temp->element<<" ";
			temp = temp->Next; //��������� �� ��������� ����� �� ������
		}
		cout<<endl;
	}

	//���������� � ������������� ������
	void AddToUporList(int a)
	{
		Node* temp3=top;
		if(temp3)//�������� - � �� ������ �� � ��� ������ ������?
		{
		//���� ���������� ����
		while(temp3->Next && temp3->element<a)
		{
			temp3=temp3->Next;
		}
		
		//������ ��������� - c ������ - ����� � ��� ��������� �������
		if (temp3->element>=a)
		{
			Node* temp2=temp3->Next;//C�������� ������� ���������� ���� ������
			temp3->Next=new Node;
			temp3->Next->element=temp3->element;//������ �������(�� ������� ����� ����)
			temp3->element=a;

			temp3=temp3->Next;
			//��������� 
			temp3->Next=temp2;
		}
		else
		{
			temp3->Next= new Node(a);
		}
		}
		else
			top=new Node(a);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream f("data1.txt");
	ifstream f2("data2.txt");
	ifstream f3("data3.txt");
	//�������� �� ������������� ����
	if (f.fail() || f2.fail() || f3.fail())
	{
		cout<<"���� �� ������ �� ����������! ��������� �� �������";
		getch();
		return 0;//�������� ������
	}
	else;

	List list;//�������������� - ������� ����� ������
	List list2;//�������������� - ������� ����� ������
	List list3;//�������������� - ������� ����� ������

	int k;//����������� ��� ����������
	//���������� � ������ - ��������� �� �����.
	//��������� �� ������
	while (!f.eof())
	{
		f>>k;
		list.AddToList(k);
		;
	}
	while (!f2.eof())
	{
		f2>>k;
		list2.AddToList(k);
		;
	}
	while (!f3.eof())
	{
		f3>>k;
		list3.AddToList(k);
		;
	}

	//������� ������������� ������ �� ����������� �������
	UporList l(&list);
	UporList l2(&list2);
	UporList l3(&list3);

	//�������� � ����
	UporList union_list;//��� ��������� ����������� �������
	UporList intersection;
	
	//����������� ���� �����������

	union_list=l+l2;
	intersection=union_list-l3;

	//�������� ������
	cout<<"��������� ����������� 3�� ������ � ����������� 1�� � 2�� ������� - � ����� result.txt � � �������: "<<endl;
	intersection.UporListShow();
	//���������� ����� ��������� � ��� ������������� ������ � �������� ����������
	/*intersection.AddToUporList(12);
	cout<<endl<<"�������� ����� 12:"<<endl;
	intersection.UporListShow();

	intersection.AddToUporList(10);
	cout<<endl<<"�������� ����� 10:"<<endl;
	intersection.UporListShow();
*/

	//intersection.ToFile();
	f.close();//��������� ��� ����
	f2.close();//��������� ��� ����
	f3.close();//��������� ��� ����

	system("pause");//��� �������� ������
	return 0;
}



/*������� ������ LIST ���������� ������ �������� � ������ � ������*/
void List::AddToList(int a)
{
	
	//�� ������, ���� � ������ ��� �� ������ �������� ���
	if (top == NULL)
	{
		top = new Node;
		top->element = a;

		//������������� ������ �� ������� ������� - �.�. �� ��������� �����������
		marker = top->Next;

		//���������� ������� - ������������� �� top
		pred = top;
		return;//��������� �������, ���� �������

	}
	else
	{
		//������� ����
		pred->Next = new Node;
		pred->Next->element = a;

		//����������� ��������� � ������ �������� �� �������(��������� ������)
			pred->Next->Next = marker;

		//����� ������ - ����������� ���������� ������� �� +1
		pred = pred->Next;
	}
}

/*������� ������ LIST ��������� ������� �� ������ ������*/
void List::Reset()
{
	marker = top;
}

/*������� ������ LIST ��� ������ ������ �� �����*/
void List::Show()
{
	Node *temp = top; //��������� ��������� � ���������� �� ��������� �� ������

	while (temp != NULL) //���� �� ������ �� ������ ���� ���-�� ����
	{
		//������� ��� �������� ���������
		cout<<temp->element<<" ";
		temp = temp->Next; //��������� �� ��������� ����� �� ������
	}
	cout<<endl;
	
}

/*������� ������ LIST �������� ����� ������*/
bool List::EoList()
{
	if (marker->Next == NULL)
		return 1;
	else return 0;
}

/*������� ������ LIST ��� ������ ������ �� 1 ���*/
void List::Move()
{
	marker = marker->Next;
}

/*������� ������ LIST �������� �������� ��������*/
void List::Del()
{
	Node *temp=marker;

	marker=marker->Next;
	pred->Next=marker;

	//������� �������������� �������
	delete temp;
}
