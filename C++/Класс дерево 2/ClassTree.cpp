#include<iostream>
#include<conio.h>
#include<stack>
#include<queue>
using namespace std;
/*
* ������� ������: �������� ����� ������. ����������� ��� �������, ����� �����. 
*
*
**/
struct Node//���� ������
{
	int info;
	Node *left, *right;
	Node (int x=0, Node*leftL=NULL, Node* rightR=NULL)//�����������. ����� ���� �� ���������, ���� �� ������ ������������.
	{
		info=x; left=leftL; right=rightR;
	}
};

class Tree//����� ��� �������� ������ ������������� ����.
{
private:
	Node* root;//������. �������� �������.
public:
	Node* uzel;
	Tree() {root=NULL;};//�����������. ����������� ��������� ������.
	void Push();//���������� � ������ ��������, ������� ����� �� ����������.
	bool Empty() {return root==NULL;}//�������� ������ �� �������.
	void Print();// ������ ������.
	void SravnTrees(Tree tr2);//��������� ���� �������� �� �� ���������. ����� ���������� � �� ����������, �� ��� ����������, � ���.����������.
	void Delete ();//�������� ������. ������ ����������� ���� �����. ���������� �������.
	void Delete (Node * uzel);//�������� ����. ������������ ������ ����������� ���� ���������� �����. ��� ��� ������ ���������� ��������� �������:
	void Delete (int x);//�������� ��������� �������� �� ����� ��� ������������.
	queue <Node*> Ochered();//�������, ������� ��������� �������, ���������� � ���� ��-��������� ������ ���� ������-����� ������, 
	//����������� �������.
	int Pop();//������� �� ������ �������� ����. �� ����� ��� ������������.
	~Tree();//����������. ������� ������ ���������.
	void NewNode (int x);//��� ���� ������� ���������� � ������ ���������. �������� ��������� ������� ������������.
};

Tree::~Tree()//����������. ���� root �� ������ � ����������� ������ - �� ����� ��� ������ ��������� �� ������?
{
	cout<<endl<<"������ �������. "<<endl;
	if (root==NULL)
		{cout<<"..���� �������� ��� ������ ������!"; return;}
	else
	{
    Delete (root);
	root=NULL;
	}
}

void Tree::Delete ()
{
   Delete (root);
   root = NULL;
}

void Tree::Delete (Node * uzel)//�������� ����(���������)
{
	if ( (uzel) != NULL )
	{
		Delete ((uzel)->left);
		Delete ((uzel)->right);
		delete (uzel);
	}
}

void Tree::Delete (int x)
{
	Node * * res = &root;
    while ( (* res)->info!=x )
       if ( x < (* res)->info )
          res = &((* res)->left);
       else
          res = &((* res)->right);
    Delete(*res);
	//cout<<(*res)->info;
	*res=NULL;	
}

//C������ ���� �������� ���������� � ������ � ������:*/
void Tree::Push ()//���������� � ������ ���������. ������ - �������� �������������� ������.
{
	int kol, x;
	cout<<endl<<"������� ���������� �����: "; cin>>kol;
	for (int i=0; i<kol; i++)
	{
		cout<<endl<<"������� "<<i+1<<") ";
			cin>>x;
		Node* *res=&root;
		//���� ����� �����. ����� �������� ��������� ������������ ������ ��� ��������� ��������� ��������.
		while(*res!=NULL)//���� ����� ��� ������������� ����� �����.
		{
			if (x==(*res)->info)
				{cout<<"������! ���� ������� ��� ��� ��������! "; return;}
			else if (x<(*res)->info)
				{res=&((*res)->left);}
			else if (x>(*res)->info)
				{res=&((*res)->right);}
		}
		*res=new Node(x); //-������� ����.
	}
}

//����� ������.
void Tree::Print()
{
	cout<<endl<<"������ � ������(�� �������): "<<endl;//������ � ������, ��� ��.

	if ( root == NULL )
		{ cout<<"������ ������! "; return; }

	Node *&b=root;//������ ����� ������� �� �������-������! ���������� ��� ����������� ����������.
	queue <Node *> q;
    q.push (root);
    while ( ! q.empty () )
	{
        Node * curr = q.front (); 
		q.pop ();
        cout << curr->info << " ";//����� ������ � ������� ����� �����������. � ���� ���� ������������ �������� �����������!
        if ( curr->left != NULL )
            q.push (curr->left);
        if ( curr->right != NULL )
            q.push (curr->right);
    }
}

void Tree::NewNode (int x)//���� ������� ���������� ��������� � ������.
{
   Node * * r = &root;
   while ( * r != NULL )
      if ( x == (* r)->info )
         return;
      else if ( x < (* r)->info )
         r = &((* r)->left);
      else
         r = &((* r)->right);
   * r = new Node (x);
}

queue <Node*> Tree::Ochered()//��������� ������� ��� ���������� ������� ����������� ������ �� ������(���� ��� �����, ���������� � �������!).
{
	queue <Node*> q2,p2;
    q2.push(root);
    while (!q2.empty()) 
	{
        Node* curr = q2.front(); 
		p2.push(q2.front());
		q2.pop();
        if (curr->left!=NULL)
            q2.push(curr->left);;
        if (curr->right!=NULL)
            q2.push(curr->right);;
	}
	return p2;
}

void Tree::SravnTrees(Tree tr2)
{
	// � ����������, ���� ������� ���, ����� ����������� ��������� �������� �� ���������� � ��� ����������(� �� ������ �� ���������).
	//������� ������� ��� ����� ��������� ������ � ������� p. 
	queue <Node*> q1,p1;
    q1.push(root);
    while (!q1.empty()) 
	{
        Node* curr = q1.front(); 
		p1.push(q1.front());
		q1.pop();
        if ((curr)->left!=NULL)
            q1.push((curr)->left);;
        if ((curr)->right!=NULL)
            q1.push((curr)->right);;
	}
	queue <Node*> p2;
	p2=tr2.Ochered();
	int a=0;
	for(; p1.empty()!=true && p2.empty()!=true;p1.pop(), p2.pop())//������������� ������� ��������� ���� ��������. ���� ��� ������� �� ������.
	{
		if (p1.front()==NULL && p2.front()==NULL)
			a++;
		else if ((p1.front()!=NULL && p2.front()==NULL) || (p1.front()==NULL && p2.front()!=NULL))
			{cout<<endl<<"������ ������� �� ���������!"<<endl; return;}
		else
		{
			int l1=0, l2=0, r1=0, r2=0;
			/*if (p1.front()->left && p2.front()->left)
			{
				if (p1.front()->right && p2.front()->right)
				a++;
				else {cout<<endl<<"Raznie derevja2!"<<endl; return;}
			}
			else if (p1.front()->right && p2.front()->right)
			{
				if (p1.front()->left && p2.front()->left)
					a++;
				else {cout<<endl<<"Raznie derevja4!"<<endl; return;}
			}
			else {cout<<endl<<"Raznie derevja5!"<<endl; return;}*/
			if (p1.front()->left) l1++;;
			if (p2.front()->left) l2++;;
			if (p1.front()->right) r1++;;
			if (p2.front()->right) r2++;;
			if (l1!=l2 && r1!=r2) {cout<<endl<<"���������� �������!"<<endl; return;}
		}
	}		

	if (p2.empty()==false || p1.empty()==false)//���� �����-�� ������ ������� ������� �� ����.
			{cout<<"��� ������ ������� �� ���������!"<<endl; return;}
	else {cout<<endl<<"���������� �������!"<<endl; return;}
}

int main()
{
	Tree tr, tr2;
	int x;
	setlocale (LC_ALL, "Russian");
	//������ � ����� �������:
	cout<<"������� 1�� ������: ";
    /*tr.NewNode (5);
	tr.Print();
    tr.NewNode (3);
	tr.Print();
    tr.NewNode (1);
	tr.Print();
    tr.NewNode (9);*/
	tr.Push();//��������� ������.
	tr.Print(); //�������� ���.

	if ( tr.Empty () )
       cout << "������ ������!" << endl;
    else
       cout << endl << "���� �������� � ������! �� ������ ������." << endl;  //��������� ������� ������

	//������ �������� ������� �� ����� ��� �������������.
	cout<<endl<<"������� ��������, ��� �������� �� ����� ������ �������������: ";
		cin>>x;
	tr.Delete(x);
	tr.Print();//��� ����������� ������� ���������.


	tr.~Tree();//����������!
    //���� (������ �����������): tr.Delete ();
	tr.Print();//��������. ��� �������� �����������.

	/*cout<<endl<<endl<<"������� 2�� ������ "<<endl;
	tr2.Push();//������ ��� ���� ������. ��� ������������ ���������.
	tr2.Print();
	cout<<endl; tr.SravnTrees(tr2);//���������� ��� ������.*/

	getch();
	return 0;
}