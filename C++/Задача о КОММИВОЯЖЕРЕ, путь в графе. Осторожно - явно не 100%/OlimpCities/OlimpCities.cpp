#include <iostream>
#include <fstream>
#include <math.h>
#include <conio.h>

using namespace std;
const int N = 256;

//��������� - ���� �� � ������� ������������ ������ ������������
bool Proverka(int* TF, int n)
{
	for(int i=0; i<n; i++)
	{
		if (TF[i]==-1) return 0;
	}
	return 1;//������ - ��� ������� ��� ��������
}

int MIN_path;//���������� ���������� ��� ��������� �������� ����������� ����

//�������� ���������
void Obrabotka(int* a, int* b, int* c, int* TF, int vershina, int rebra, int sum, int next)
{
	//������������ ������ ��� �� ����� ���������� ������. ��� "�������" �������������� ������, �� ��� �� ��� �� �������� :)
	int n;
	n = (1 + sqrt(1.0 + 8 * rebra)) / 2;
	next++;
	//���� �� �[]
	for(int i=0; i<rebra; i++)
	{//���� ����� � �������� ������������ ���� �������
		if(a[i]==vershina && TF[b[i]-1]<0)//���� ���� ���� ���������� � �����-�� ��� ����� ��� �� �������- ���� �� ��� ������
		{
			//�.�. ���������� ������ ������ - ����� ������ ������� ������ ��������� � ��� ����������
			int* tf=new int[n];
			for(int i=0; i<n; i++)
				tf[i]=TF[i];

			if (tf[b[i]-1]==1 && !Proverka(tf,n))//���� �� ����� ��������, ��� �������� ������� - ��������, � ��������� ������� - ��� �� ��������, �� ��� ���� ��������� �������. ����� �������� -> �������� ����� �� ���� �����
				continue;
			else
				tf[b[i]-1]=next;//����� - �������� ������� ��� ��� ����������
			//���� ������ �� �������
			
			Obrabotka(a,b,c,tf,b[i],rebra,sum+c[i],next);

			delete[] tf;
		}
	}
	//���� �� b[]
	for(int i=0; i<rebra; i++)
	{//���� ����� � �������� ������������ ���� �������
		if(b[i]==vershina && TF[a[i]-1]<0)
		{
			int* tf=new int[n+1];
			for(int i=0; i<n+1; i++)
				tf[i]=TF[i];

			if (tf[a[i]-1]==1 && !Proverka(tf,n))
				continue;
			else
				tf[a[i]-1]=next;
			//���� ������ �� �������
			
			Obrabotka(a,b,c,tf,a[i],rebra,sum+c[i],next);
			
			delete[] tf;
		}
	}	

	//�������� - � ���� ��� ������� ����� �������� ��� ��������?
	if(Proverka(TF,n))
	{
		//cout<<"!!!";
		for(int i=0; i<n; i++)
		{
			if(a[i]==vershina && TF[b[i]-1]==1)
			{/*
				for(int i=0;i<n;i++)
					cout<<TF[i];
				cout<<endl;
				cout<<"c[i]="<<c[i]<<endl;
				cout<<"end "<<sum+c[i]<<endl;;
				*/
				if (MIN_path>sum+c[i])
					MIN_path=sum+c[i];
			}
		}
		for(int i=0; i<n; i++)
		{
			if(b[i]==vershina && TF[a[i]-1]==1)
			{/*
				for(int i=0;i<n;i++)
					cout<<TF[i];
				cout<<endl;
				cout<<"c[i]="<<c[i]<<endl;
				cout<<"end "<<sum+c[i]<<endl<<endl;;
				*/
				if (sum+c[i]<MIN_path)
					MIN_path=sum+c[i];
			}
		}
	}
}



int main()
{
    setlocale(LC_ALL, "Russian");

	int rebra;
	//���������
	ifstream f("Sample Input.txt");
	f>>rebra;
	int* a = new int[rebra];
	int* b = new int[rebra];
	int* c = new int[rebra];
	for (int i = 0; i < rebra; i++)
		f >> a[i] >> b[i] >> c[i];
	f.close();
	
	cout << "����� � ����� = " << rebra << endl;
	int n;
	n = (1 + sqrt(1.0 + 8 * rebra)) / 2;
	cout << "������������ ����� ������ = " << n << endl;
	
	//����������-�������
	int i;
	ofstream f1("Output for Sample Input.txt");

	//����� ������ ��� ��������
	//for(int i=0; i<rebra; i++)
	//	f1<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;

	ofstream f2("Output for Sample Input.txt");
	for(int q=1; q<=n; q++)
	{
		//�������������� ���� ������� ���������� �������������� ���� ������������ ���������.
		MIN_path=10000;
		//������� ������� ������ ��������� �����
		int* TF=new int[n];
		for(int i=0; i<n; i++)
			TF[i]=-1;

		TF[q-1]=1;//�������� �������� ������� 
			
		Obrabotka(a,b,c,TF,q,rebra,0,1);//q-�������� �������
			cout<<endl;

		//cout<<"���������� ���� ��� ������� �"<<q<<" = "<<MIN_path<<endl;
		f2<<"���������� ���� ��� ������� �"<<q<<" = "<<MIN_path;
		delete[] TF;
	}
	f2.close();
	cout<<endl<<"END";

	//������� �����
	delete[] a;
	delete[] b;
	delete[] c;
	f1.close();
	getch();
	return 0;
}