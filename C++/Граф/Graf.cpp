#include<iostream>
#include<conio.h>
#define __RRR__
/*
*	������� ������:
*		����� ����� � �����. ���� ���������� ����� - ��� ���� (� ����� ��������).
*	���� ������-������ ����� � ������� �� ���� �����. ���� � ����� ������� ��������� ���������� ������ ->�� ����. ��� ����:)
*	��� �������� - ���������� �� �������� �����. 
*   1�� ������ - ����������и��� � ����������������. ��������� ������ - �����, ����������� ����� �����.
*	���� ����������������� �� ������� ������.
*
*	�������: �������������. ���� ��� �������-����� �����. ��� ������ �� ���� ����� - �� �������.������� ���������. � ����������, ���� ����� ������������
*	������ ����� �����-�� ������� � ������� ���������� ���������(� �����!), �� ������ �������, ��� ����� ����� ��� �� ����. ����� - ���� ������� ������ �
*	�������� visitedA � visitedB �� �������� - �� ����� �������� ������!
*	//����������� ������� ���������� ��� � �������� ������������ ������ - ��������� ���� �������� ��� � ��������! ��� ��������� ���������� ������������
*	������ � �����.
*/
using namespace std;

class Graph
{
private:
	int n;
	int **e;//������ ����. � ���� ������ ����.
public:
	Graph();
	Graph(int);
	Graph(int, int**);
	Graph(Graph&);
	void addEdge(int i, int j);
	void printMatrica();
	void clearMatrica();//�������� ������� ��� ������ �����.
	void Brightes(int a, int b);
	void recSearchA(int i, int *visited);
	void recSearchB(int i, int *visited);
};
void Graph::clearMatrica()//������ ������� �����. � ������ �� ������������, ��� ��������.
{
	for(int i=0; i<n; i++)
		/*for(int j=0; j<n; j++)
			e[i][j]=0;*/
			delete e[i];

}

void Graph::Brightes(int a, int b)
{
	//����� ������� - ������ �� ���� ������ ������ ����. � ����� - �� �� ���������/���������.
	//������ ������� �������� ������.
	int *visitedA;//������ �������� ��� ����� A
		visitedA=new int[n];
	int *visitedB;//������ �������� ��� ����� �
		visitedB=new int[n];

	for(int i=0; i<n; i++)
	{
		visitedA[i]=0; visitedB[i]=0;
	}

	visitedA[a]=1;//������� ��� ����� ��� ��� ����������.
	visitedB[b]=1;

	//���������� � ����� �� ������� �.
	for(int i=0; i<n; i++)
	{
		if (e[a][i]==1 && i!=b && visitedA[i]==0)//����� �� ����� ������� � �� ������� �������� �� ������� �
		{
			visitedA[i]=1;
			recSearchA(i, visitedA);
		}
	}

	//���������� � ����� �� ������� �.
	for(int i=0; i<n; i++)
	{
		if (e[b][i]==1 && i!=a && visitedB[i]==0)//����� �� ����� ������� � �� ������� �������� �� ������� �
		{
			visitedB[i]=1;
			recSearchB(i, visitedB);
		}
	}
	//���������� � �������� ���������.
	bool ok=true;
	for(int i=0; i<n; i++)
	{
		if (visitedA[i]==1 && visitedB[i]==1) {ok=false; break;} //���� ==1 ���, �� - ������� ������� ����������, ������, ���� ��� ���� ���� � ����.
	}
	if (ok) 
	{cout<<"������� � ��������� "<<a<<" � "<<b<<" -����;"<<endl;
	/*
	//���� �������� ���������� ��� ������������ �������
	for (int i=0; i<n; i++)
		cout<<visitedA[i]<<" ";
	cout<<endl;
	for (int i=0; i<n; i++)
		cout<<visitedA[i]<<" ";
	cout<<endl<<endl;*/
	}
	else /*cout<<a<<" "<<b<<" -������;"<<endl*/;
	delete []visitedA;//������� ��������� �������.
	delete []visitedB;
}

//����������� ������� ������ ����� ��� ��������. ����� �����.
void Graph::recSearchA(int j, int *visitedA)
{
	for(int i=0; i<n; i++)//���������� �������� �������.
	{
		if (e[j][i]==1 && visitedA[i]==0)//����� �������� �����. 
		{	
			visitedA[i]=1;
			recSearchA(i, visitedA);
		}

	}
}

void Graph::recSearchB(int j, int *visitedB)
{
	for(int i=0; i<n; i++)//���������� �������� �������.
	{
		if (e[j][i]==1 && visitedB[i]==0)//����� �������� �����. 
		{	
			visitedB[i]=1;
			recSearchB(i, visitedB);
		}
	}
}

Graph::Graph(int n)
{
	//������ ������� �����.
	this->n=n;
	e=new int*[n];
	for(int i=0; i<n; i++)
	{
		e[i]=new int[n];
		for(int j=0; j<n; j++)
			e[i][j]=0;
	}
};

void Graph::addEdge(int i, int j)
{
		e[i][j]=1;
		e[j][i]=1;
}

void Graph::printMatrica()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<e[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	#ifdef __RRR__
	setlocale (LC_ALL, "Russian");
	freopen("Musor.txt","r",stdin);//������� � �������.
	//freopen("Output for Sample Input.txt","w",stdout);
	#endif

	int kolReber, kolVershin, i, j;
	cin>>kolReber;	cin>>kolVershin;//��������� �������������� ���������� ���� � ������ � �����.
	Graph gr(kolVershin);//������ ����.
	typedef pair <int, int> Pair;//����� ��� ��� ������� �������� ����.
	Pair *ver;//������ ������������ ������� ��� �������� ����.

	//������� ��� ������������ ������� ��� �������� ����.
	ver=new Pair[kolReber];
	for(int t=0; t<kolReber; t++)//������������ ������� ����.
	{
		cin>>i; cin>>j;//��������� �����
		ver[t].first=i; ver[t].second=j; // ���������� ��������� �����.
		gr.addEdge(i,j);
	}
	//gr.printMatrica(); //������ �������. ��� �������� ������������ �����.
	//��������� ���� �� ������� ������.
	for(int t=0; t<kolReber; t++)
	{
		//������� � ������� ����� ��� ����������� - ���� �� ���?
		gr.Brightes(ver[t].first, ver[t].second);
	}

	//� �� ������ ������� ��������� ��������:
	delete []ver;

	getch();
	return 0;
}