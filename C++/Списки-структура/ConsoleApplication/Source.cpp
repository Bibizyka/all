
#include <stdlib.h>
#include <iostream>

using namespace std;

/*��������� ���� ������*/
struct Node
{
	int element; //�������
	Node *Next; //����� �� ��������� �������

public:
	//����������� �� ��������� ��� ������� ���� ������
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


// ������������ ������ ��������������������� � ������
void Duble(Node**top, Node **top2, int count)
{

	Node *temp = *top;
	Node *temp2 = *top2;
	// ���� �� ������� ������ � ���� ����������
	while (temp != NULL && temp2 != NULL && temp->Next != NULL)
	{
		Node* temp3 = new Node();
		temp2 = *top2;
		int k = 0;
		// ���� ������ ����������
		while (temp->Next != NULL)
		{
			if (temp->element == temp2->element)
			{
				k++;
				temp3 = temp;
				temp = temp->Next;
				temp2 = temp2->Next;
				break;
			}

			temp = temp->Next;
		}

		// ����� ���������� - ����� ���� �� ������������ �������� - ��������� ����� ������� �� ��������� �������
		while (temp != NULL && temp2 != NULL)
		{
			if (temp->element == temp2->element)
				k++;
			temp3 = temp3->Next;
			temp = temp->Next;
			temp2 = temp2->Next;
		}

		// ���� ������� �������, ��������� ��������� - �� ��������� �������� ������� ������
		if (k == count)
		{
			temp2 = *top2;
			while (temp2 != NULL)
			{
				if (temp != NULL)
				{
					Node*t = new Node(temp2->element);
					t->Next = temp3->Next;
					temp3->Next = t;

					temp = temp->Next;
					temp2 = temp2->Next;
					temp3 = temp3->Next;
				}
				else
				{
					Node*t = new Node(temp2->element);
					t->Next = temp3->Next;
					temp3->Next = t;

					temp2 = temp2->Next;
					temp3 = temp3->Next;
				}
			}
		}
	}
}

// ������� ������������ ������� ������ ��������
void DUBLE5(Node** top)
{
	Node *temp = *top; //��������� ��������� � ���������� �� ��������� �� ������

	while (temp->Next != NULL) //���� �� ������ �� ������ ���� ���-�� ����
	{
		int i;
		for (i = 1; i < 5 && temp->Next != NULL; i++)
		{
			temp = temp->Next;
		}
		if (i == 5)
		{
			// ��������� ����� �������
			Node *temp2 = new Node(temp->element);
			temp2->Next = temp->Next;
			temp->Next = temp2;
			if (temp->Next != NULL)
				temp = temp->Next;
			if (temp->Next != NULL)
				temp = temp->Next;
		}
	}
}

/*������� ������ LIST ���������� ������ �������� � ������ � ������*/
void AddToList(Node** top, int a)
{
	//�� ������, ���� � ������ ��� �� ������ �������� ���
	if (*top == NULL)
	{
		*top = new Node(a);
		return;//��������� �������, ���� �������
	}
	else
	{
		//������� ����
		Node *newtop = *top;

		while (newtop->Next != NULL)
			newtop = newtop->Next;
		newtop->Next = new Node;
		newtop->Next->element = a;
		newtop->Next->Next = NULL;
	}
}

/*������� ������ LIST ��� ������ ������ �� �����*/
void Show(Node** top)
{
	Node *temp = *top; //��������� ��������� � ���������� �� ��������� �� ������

	while (temp != NULL) //���� �� ������ �� ������ ���� ���-�� ����
	{
		//������� ��� �������� ���������
		cout << temp->element << " ";
		temp = temp->Next; //��������� �� ��������� ����� �� ������
	}
	cout << endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");

	Node *list = NULL;//�������������� - ������� ����� ������
	Node *list2 = NULL;//�������������� - ������� ����� ������

	int n;//����������� ��� ����������
	cout << "������� ���������� ����� � ������ ������: ";
	cin >> n;
	int k;

	//���������� � ������ 
	for (int i = 0; i < n; i++)
	{
		cout << "���� " << i + 1 << " ��������: ";
		cin >> k;
		AddToList(&list, k);
	}

	// ������ ������
	Show(&list);

	// ������ ������������ ������ 5�� �������
		DUBLE5(&list);
		cout << "������������� ������ ����� �������:";
		Show(&list);

	// ������ ���������������������
	cout << "������� ���������� ����� �� ������ ������: ";
	cin >> n;

	//���������� � ������ 
	for (int i = 0; i < n; i++)
	{
		cout << "���� " << i + 1 << " ��������: ";
		cin >> k;
		AddToList(&list2,k);
	}
	Show(&list2);

	// ������ ������������ ��� �������� ������� ������ � ������ ������(���� ��� ��� ���� �� �������
	Duble(&list, &list2,n);
	cout << "��������� ������������ ��������� ������� ������ � ������: ";
	Show(&list);

	system("pause");//��� �������� ������
	return 0;
}




