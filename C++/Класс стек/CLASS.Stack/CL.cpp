#include<iostream>//S-�������, X - ���������.
#include<conio.h>
#include<cstring>
#include<stack>
using namespace std;

struct E
{
	int info;
	E *next;
	E (int x=0, E*p=NULL)
		{info=x; next=p;}
};

class Stack
{
private:
	E*ptr;
public:
	Stack() {ptr=NULL;};
	void Push(int x);
	int Pop();
	bool Empty() {return ptr==NULL;}
	int Top() {return ptr->info;}
	void PushBack(int x);
	int PopBack();
	int TopBack();
};
Stack st;
//�������� �������, �������� � �����:
void Stack::Push(int x)//����� ������� � ������
{
	ptr=new E(x, ptr);
}
void Stack::PushBack(int x)//����� ������� � �����
{
	E* first=ptr;
	for (;first->next!=NULL; first=first->next)
		;
	first->next=new E(x, ptr);
}

int Stack::Pop()//�������� �������� � ������ ������-�������
{
	int x;
	x=ptr->info;
	E*q=ptr; ptr=ptr->next; delete q;
	return x;
}
int Stack::PopBack()//�������� �������� � �����-�������
{
	E *q=ptr;
	while(q->next->next!=NULL)
		q=q->next;
	delete q->next->next;
	q->next=NULL;
}

void Output(char *s, int n)
{
	for(int i=0, n2=n+n, k=1; i<n2;i++)
	{
		if (s[i]=='s') st.Push(k++);
			else cout<<st.Pop()<<"_";
	}
}

void ProverkaPoChislam(char *chislo)//�������� - ����� �� ������� �������� ����� � �������� �������. ���������� ������� ����������.
{
	int n=strlen(chislo), k=0, l=0;

	for(int i=0; i<n; i++)
	{
		st.Push(k);
		{if (st.Top()==chislo[i]) 
			{
				while (st.Top()==chislo[i]) 
				{
				cout<<st.Pop()<<" ";
				i++;
				}
				i--;
			}
		}
		k++;
	}
	if  (st.Empty()==true) cout<<"Verno!";
		else cout<<"NO!";
}

void ProverkaPoSx(char *sx)//1���������� - ����� �� ������� ����� �� ��������� ����.
{
	int n=strlen(sx), k=1, l=0;

	for(int i=0; i<n; i++)
	{
		if (sx[i]=='s') st.Push(k); 
		else 
			{
				if (st.Empty()==false) cout<<st.Pop()<<" ";
				else {cout<<"..Error"; break;}
			}
	}
}
//Project Properties -> Configuration Properties -> Linker (General) -> Enable Incremental Linking -> "No (/INCREMENTAL:NO)" 
void Commands(char *com)//2���������� - ��������� ������� ������.
{
	int n;
	n=strlen(com);
	int k=1;
	//�������� ������ ������ �����!
	
	for(int i=0; i<n ;)
	{
		{
			if (com[i] && com[i]==k)
			{
				st.Push(k); st.Pop(); cout<<"s"<<"x"; i++; k++;
			}
			else if (i<n) break;}
		}
				
		{
			if (i<n && com[i]!=k)
			{
				st.Push(k); k++; cout<<"S";
			}
		}

		if (st.Empty()==false)
		{
			if (st.Top()==com[i])
			{
				st.Pop(); i++; k++; cout<<"X";
			}
		}
	}
	if(st.Empty()==false) cout<<"Error";
}

void SkobkiSomeType (char *skobki)
{
	int	n=strlen(skobki);
	int	k1=0;
	int	k2=0;
	int k,t=0,i=0;
	if (skobki[0]=='(' || skobki[0]=='[') 
	for(; i<n; )//������� ( ��� 1, � [ ��� 2.
	{
		k=0;
		if (skobki[i]=='(' || skobki[i]=='[')
		while (skobki[i]=='(' || skobki[i]=='[')
		{
				{
					if (skobki[i]=='(') {st.Push(1); k1++; i++;} else 
														{
															if (skobki[i]=='[') {st.Push(2); k2++;i++; };
														}
				}
				k++;
		}
		else {break;}
		{if (st.Empty()==false)
		while (st.Empty()==false && (skobki[i]==')' || skobki[i]==']'))
		{
			{if (st.Empty()==false && st.Top()==1 && skobki[i]==')')	{st.Pop(); k1--;i++;}else 
				if (st.Empty()==false && st.Top()==2 && skobki[i]==']') {st.Pop(); k2--;i++;} else { t=1; break;}}
			{if (k1<0 || k2<0) { t=1; break;}}
		}
		}
		if (t==1) { break;}
	}
	else cout<<"Error in begin! ";  
	if (k1==0 && k2==0 && st.Empty()==true && i==n) cout<<"All right! "; else cout<<"Error!";
}

int main()
{
	int n; 
	int const N=100;
	char s[N], chislo[N];
	char sx[N];
	char com[N];
	char skobki[N];

	/*cout<<"Vvedite ctroku S:"<<endl;//+����� ���������� ������������������ �� ��������� ����.
		cin.getline(s,100);
		n=strlen(s);	
	Output(s,n);*/
		
	/*cout<<"Vvedite stroku chisel:"<<endl;//-�������� - ����� �� ������� �������� ����� � �������� �������. ���������� ������� ����������.
		cin.getline(chislo ,100); cout<<endl;
	ProverkaPoChislam(chislo);*/

	/*cout<<"Vvedite posledovatel'nost sx:"<<endl;//+����� �� ������� ����� �� ��������� ����. � ���������� ���������� ��� ������������.
		cin.getline(sx, 100);
	ProverkaPoSx(sx);*/

	cout<<"Vvedite posledovatel'nost chisel:"<<endl;//-����� ���� �� ��������� ���� �����.
		cin.getline(com, 100);
	Commands(com);

	/*cout<<"Vvedite stroku skobok:";//�������� �������� ������ ������.
		cin.getline(skobki,100);
	//SkobkiSomeType(skobki);*/
	


	getch();
	return 0;
}
