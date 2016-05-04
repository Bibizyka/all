#include<iostream>//������ - � �������� ������� ������ ��� ����������, ������� �� � ������� �������� ���������, ��� ��������� ��������. 
#include<conio.h>//�������� ��� ��������� �������� ��������, ������������� � �.�. ������ �������������� ��������, �������,
using namespace std;//������� �� ���� ������ �������� ���.�������. ��������, ���� �������� � ������� �������.
//����� ������� � ������������� ���������. ���������:)

//������:
//�������� ��������� ���������� � ������ ������������� � ��������.
struct E
{
	int exp, coef;
	E *next;
	E (int y=0, int x=0, E*p=NULL)
		{coef=y; exp=x; next=p;}
};

//���������� ��������� � ������ ���������. ���������� ��� ������� InputP.
void AddEndP (E *first, int y, int x) //��� ��� � - ��������.
{
	for (;first->next!=NULL; first=first->next)
		;
	first->next=new E(y, x);
}
//������� ����� ������ ��� ������� ����������.
void InputP (E*&p,int MaxExpP)//������� ������� ����� 1�� ����������.
{
	int k=MaxExpP;
	p=new E;
	cin>>p->coef>>p->exp;
	p->next=NULL;

	int x,y;
	for (int i=1;i<k;i++)
	{
		cin>>y>>x;
		AddEndP(p,y,x);
	}
}

//���������� ��������� �� ������ ���������. ���������� ��� ������� InputQ.
void AddEndQ (E *second, int y, int x)
{
	for (;second->next!=NULL; second=second->next)
		;
	second->next=new E(y, x);
}
//������� ����� ������ ��� ������� ����������.
void InputQ (E*&q, int MaxExpQ)//������� ������� ����� 1�� ����������.
{
	int k=MaxExpQ;
	q=new E;
	cin>>q->coef>>q->exp;
	q->next=NULL;

	int x,y;
	for (int i=1;i<k;i++)
	{
		cin>>y>>x;
		AddEndQ(q,y,x);
	}
}

//���������� ���������� ������� ��� �������� ������(������ ������� ������)
void Plus(int k)
{
	if (k!=0)
		cout<<"+";
}
//������� ������� ������ ������.
void Print (E*p)
{
	int k=0;
	for (E*w=p; w!=NULL; w=w->next)
	{
		if (w->coef==1 && w->exp==1)
		{	Plus(k);cout<<"x"; }
		else
			if (w->coef==1 )
			{	Plus(k); cout<<"x^"<<w->exp; }
			else
				if (w->coef!=0 && w->exp==1)
				{	Plus(k);cout<<w->coef<<"*x"; }
				else 
					if (w->coef!=0 && w->coef!=1 && w->exp!=0)
					{	Plus(k);cout<<w->coef<<"*x^"<<w->exp; }
					else 
						if (w->coef!=0 && w->coef==1 && w->exp!=0)
						{	Plus(k);cout<<"x^"<<w->exp; }
						else 
							if (w->coef!=0 && w->exp==0)
							{	Plus(k);cout<<w->coef; }
		k++;
	}
}

void SortP (E*&p)
 {
	 int const N=100;
	 int nomer=0, expB[N], coefB[N];
	 int i=0;
	 for (E*n=p ;	n!=NULL;	i++,nomer++, n=n->next)
	 {
		 expB[i]=n->exp;
		 coefB[i]=n->coef;
	 }
	 //���������� �������������.
	 int bob;
	 for(int y=0;y<nomer;y++ )
	 {
		 for(int j=0;j<(nomer-1);j++)
			 if (expB[j]>expB[j+1])
				bob=expB[j], expB[j]=expB[j+1],expB[j+1]=bob,bob=coefB[j], coefB[j]=coefB[j+1],coefB[j+1]=bob;
	 }
	 E*m=p;
	 for (int j=0;m!=NULL;j++,m=m->next)
	 {
		 m->exp=expB[j];
		 m->coef=coefB[j];
	 }
 }
void PlusMinusP(E *&p)
{
	SortP(p);
	int coefM, expM;
	for(E *i=p; i!=NULL; i=i->next)//�� �������������� ���������� ����������
	{
		coefM=i->coef;
		expM=i->exp;
		E *jok=i;
		for(E *j=i->next; j!=NULL;  j=j->next, jok=jok->next)// �� ���������� ���������� ����������
		{
			if ((j->next != NULL) && (j->exp==expM))
			{
				coefM=coefM+j->coef;

				E *g=j->next;
				jok->next=g;
				delete j;
				j=g;
			}
			else
			{
				if((j->next==NULL) && (expM==j->exp))
				{
					coefM=coefM+(j->coef);

					E* b;
					b=j;
					jok->next=NULL;
					j=jok;
					delete b;
				}
			}
		}
		i->coef=coefM;
	}
	E*i=p, *j=p->next;
	for (;i->next->next!=NULL;i=i->next, j=j->next)
		;
	if (i->exp==j->exp) {i->coef=i->coef+j->coef; i->next=NULL; delete j;}
}

void SortQ (E*&q)
 {
	 int const N=100;
	 int nomer=0, expB[N], coefB[N];
	 int i=0;
	 for (E*n=q ;	n!=NULL;	i++,nomer++, n=n->next)
	 {
		 expB[i]=n->exp;
		 coefB[i]=n->coef;
	 }
	 //���������� �������������.
	 int bob;
	 for(int y=0;y<nomer;y++ )
	 {
		 for(int j=0;j<(nomer-1);j++)
			 if (expB[j]>expB[j+1])
				bob=expB[j], expB[j]=expB[j+1],expB[j+1]=bob,bob=coefB[j], coefB[j]=coefB[j+1],coefB[j+1]=bob;
	 }
	 E*m=q;
	 for (int j=0;m!=NULL;j++,m=m->next)
	 {
		 m->exp=expB[j];
		 m->coef=coefB[j];
	 }
 }
void PlusMinusQ(E *&q)
{
	SortP(q);
	int coefM, expM;
	for(E *i=q; i!=NULL; i=i->next)//�� �������������� ���������� ����������
	{
		coefM=i->coef;
		expM=i->exp;
		E *jok=i;
		for(E *j=i->next; j!=NULL;  j=j->next, jok=jok->next)// �� ���������� ���������� ����������
		{
			if ((j->next != NULL) && (j->exp==expM))
			{
				coefM=coefM+j->coef;

				E *g=j->next;
				jok->next=g;
				delete j;
				j=g;
			}
			else
			{
				if((j->next==NULL) && (expM==j->exp))
				{
					coefM=coefM+(j->coef);

					E* b;
					b=j;
					jok->next=NULL;
					j=jok;
					delete b;
				}
			}
		}
		i->coef=coefM;
	}
	E*i=q, *j=q->next;
	for (;i->next->next!=NULL;i=i->next, j=j->next)
		;
	if (i->exp==j->exp) {i->coef=i->coef+j->coef; i->next=NULL; delete j;}
}
//���������� ��� ������������ ����� �����������
void AddEndB (E *trololo, int y, int x)
{
	for (;trololo->next!=NULL; trololo=trololo->next)
		;
	trololo->next=new E(y, x);
}
//���������� ��� ���������� ������������� ����������.
//��������� ���� ������ b.��� ������� � �� ������ ������.
void Sort (E*&b)
 {
	 int const N=100;
	 int nomer=0, expB[N], coefB[N];
	 int i=0;
	 for (E*n=b ;	n!=NULL;	i++,nomer++, n=n->next)
	 {
		 expB[i]=n->exp;
		 coefB[i]=n->coef;
	 }
	 //���������� �������������.
	 int bob;
	 for(int y=0;y<nomer;y++ )
	 {
		 for(int j=0;j<(nomer-1);j++)
			 if (expB[j]>expB[j+1])
				bob=expB[j], expB[j]=expB[j+1],expB[j+1]=bob,bob=coefB[j], coefB[j]=coefB[j+1],coefB[j+1]=bob;
	 }
	 E*m=b;
	 for (int j=0;m!=NULL;j++,m=m->next)
	 {
		 m->exp=expB[j];
		 m->coef=coefB[j];
	 }
 }
//������� �������� ����� ���� ����������� � ������������ ������ ��������� ������.
void Summa (E*&p,E*&q,E*&b)
{
	int expB;
	int coefB;
	int k=1;
	for(E*first=p;  first!=NULL;  first=first->next)
	{
		{if (k==1) b=new E,	b->coef=0,	b->exp=0,	b->next=NULL;}
		k++;
		expB=first->exp;
		coefB=first->coef;
		for(E*second=q;  second!=NULL;  second=second->next)
		{
			{if (first->exp == second->exp) {coefB=coefB+second->coef;}}
			//�������� ���� ������ ���������, �� �������� � ���� �� �����������
		}
		if (coefB!=0)
			AddEndB(b,coefB,expB);
	}

	int coefA;
	int expA;
	for(E*second=q;  second!=NULL;  second=second->next)//���������� ��������� �� ������� ����������, ���� 
	//��� ��������� ����������� � ������.
	{
		expA=second->exp;
		coefA=second->coef;
		E*third=b;
		for(;  third!=NULL;  third=third->next)
		{
			if(second->exp==third->exp)
				break;
		}
		if (third==NULL && coefA!=0)
			AddEndB(b,coefA,expA);
	}
	Sort (b);
}


int main()
{
	E *p=NULL, *q=NULL, *b=NULL;//�������������� ������, ������ � �������� ����������.
	int MaxExpP,MaxExpQ;
	cout<<"Vvedite Max exp 1:";//������������ ������� ������� ����������.
		cin>>MaxExpP;
	cout<<"Vvedite Max exp 2:";//������������ ������� ������� ����������.
		cin>>MaxExpQ;

	cout<<endl<<"LinSpisok 1 : vvodite koefficient & stepen' cherez probel & Enter "<<endl;//���� ������� ��������� ������-������� ����������.
		InputP(p,MaxExpP);
	cout<<endl<<endl<<"LinSpisok 2: vvodite koefficient & stepen' cherez probel & Enter "<<endl;//���� ������� ��������� ������ - ������� ����������.
		InputQ(q,MaxExpQ);
	
	cout<<endl<<"Mnogochleni: "<<endl;//����� ����� ������������ ����������� - ���������� ���.
	cout<<"P(x)= ",Print(p);
	cout<<endl, 
	cout<<"Q(x)= ",Print(q);

	cout<<endl<<endl<<"Privedennie: "<<endl;//�������� ���������� � ����������� �����. ���� ���� ����� ���� ������������.
	PlusMinusP(p);//���������� 1�� ���������� � ����� ����������.
	PlusMinusP(p);
	PlusMinusQ(q);
	PlusMinusQ(q);
	cout<<endl<<"P(x)= ",Print(p);
	cout<<endl<<"Q(x)= ",Print(q);

	cout<<endl<<endl<<"Summa f(x)= ";//������ ������� �������� ���� � ������ ������������� ����������.
	Summa(p,q,b);
	Print(b);

	_getch();
	return 0;
}