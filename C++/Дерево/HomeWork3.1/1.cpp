#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;
typedef pair <int,int> Pair;
/*
��������, ��� ������ ������� �� �����. ��� ��� ������� � ��������� �������.
1) ������������� - ��������� ������������ �������. ����� � ������������ �������� � ���� ������ ������! ���� - ������������� �����. ������� � �������� ������.
2) ������������ ���� � ���������� ���. 
������ �������� �����-��������. ��� ���������

*/
//�������� ������
struct Node
{
	int info;
	Node *left, *right;
	Node (int x)
	{
		info=x; left=NULL; right=NULL;
	}
};

//������ ��������� ������.
void PrintR(Node *r)
{
	if (r==NULL) return;
	else 
	{
		cout<<r->info<<" ";
		PrintR(r->left);
		PrintR(r->right);
	}
}

//���������� ��������. �������� ������ ���������.
void Add (Node *&p, int x)
{
	for(;p!=NULL;p=p->left)
		;
	p=new Node(x);
}

void DeleteInTree(Node* &p)
{
	Node *q=p;
	for(;p!=NULL;)
	{
		q=p;
		p=p->left;
		delete q;
	}
	delete p;
}
/*
void Delete(stack <Node*> &p,int chislo)
{
	for(stack <Node*> q=p; q!=NULL;q=q->next)
	{
		if(q->next->info==chislo && q->next->next!=NULL)
		{
			Node *g=q->next->next;
			delete q->next;
			q->next=g;
		}
		else 
		{
			Node *g=NULL;
			delete q->next;
			q->next=g;
		}
	}
}
*/
int main()
{
	int const N=100;
	Pair a[N];
	int kol, ut[N];
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>kol;
	kol=kol;
	cout<<kol<<endl;
	for(int i=0;i<kol; i++)
	{
		cin>>a[i].first; cin>>a[i].second;
		cout<<a[i].first<<"_"<<a[i].second<<endl;
	}
	//������ ������.
	//����� �������� �������.
	/*�������� ��� ������� �������, ��� �������� ������� �� �������� �������� ������-����! ������ - �� �� ������ ����������� �� ������
	�������.
	*/
	int podschet;
	for (int i=0; i<kol; i++)
	{
		podschet=0;
		for (int j=0; j<kol; j++)
		{
			if (a[i].first==a[j].second) podschet++;
		}
		if (podschet==0) {podschet=a[i].first; break;}
	}

	//������� �������� "����" ��������.
	stack <Node*>tree;
	Node* inTree=NULL;
	int kolTrees=0, b;//������� ���������� �����������.
	for(int i=0;i<kol;i++)
	{
		if (a[i].first!=NULL && a[i].second!=NULL)
		{	
			Add(inTree, a[i].first);//���������� ������������ �����-���������
			Add(inTree, a[i].second);
			b=a[i].first;
			a[i].first=NULL;
			for(int j=0; j<kol; j++)
			{
				if (a[j].first!=NULL && a[j].first==b)
				{
					cout<<"a";
					Add(inTree, a[j].second);
					a[j].first=NULL;
				}
			}
			//������� ��������� � ����������� ����, � ������� ����������� ������ ����������-���������
			ut[kolTrees]=a[i].first;
			kolTrees++;
		}
	}
	for(int i=0; i<kolTrees; i++)
	{
		cout<<ut[i]<<" ";
	}
	/*
	//���������� �������� ������� ������.
	//���� ��������� � ������� ������. ���������� ��� � �������!
	/*
	Node *root=NULL;
	root=new Node(3);
	*//*
	stack <Node*>q=tree;
	Node *root=NULL, *p=NULL;
	for(int i=0; i<kolTrees; i++)
	{
		p=q.top();
		if (p->info==podschet) break; else q.pop();
	}
	root=p;//���������.
	Delete(tree,p->info);//������� p �� �����.
	//������ �������
	*/
	

	Node *z=tree.top();
	PrintR(z);
	getch();
	return 0;
}