#include<iostream>//� ������ - ����� ��������� ������� N-����������� ������. ���������� ��� ��������� ��������.
#include<conio.h>
#include<iomanip>
using namespace std;

int const N=100;
int mat[N][N], n;

int Mozhno(int i, int m)//i - ������, j - �������.
{
	for(int j=m; j<n; j++)
		{if (mat[i][j]==-2) return j;}
	return	100;
}
 
void Print()
{
	cout<<endl;
	for(int a=0;a<n;a++)
	{
		for(int b=0; b<n; b++)
		{
			if (mat[a][b]==-1) cout<<setw(3)<<"F"; 
			else if (mat[a][b]==-2) cout<<setw(3)<<"-";//����������� ������. ���� ������� ��������.
			else cout<<setw(3)<<mat[a][b];
		}
		cout<<endl;
	}
}

void Stavit(int i, int p)//��������� ������� ���������� i-����� �� i-������ � p-�������.
{
	mat[i][p]=(-1);
	for (int j=i, l=p-1; l>=0; l--)//������ �����
	{
		{if (mat[j][l]==-2) mat[j][l]=i;}
	}
	for (int j=i, r=p+1;r<n; r++)//������ ������
	{
		{if (mat[j][r]==-2) mat[j][r]=i;}
	}
	for (int j=i+1; j<n ;j++)//������� ����
	{
		{if (mat[j][p]==-2) mat[j][p]=i;}
	}
	for (int j=i+1, pl=p-1; pl>=0 ;pl--, j++)//����� ����
	{
		{if (mat[j][pl]==-2) mat[j][pl]=i;}
	}
	for (int j=i+1, pr=p+1; pr<n; pr++, j++)//������ ����
	{
		{if (mat[j][pr]==-2) mat[j][pr]=i;}
	}

}

int Snyat(int i)
{
	int t=0;
	for(int j=0; j<n; j++)
	{
		if (mat[i][j]==-1)
		{
			mat[i][j]=-2;
			{
			for(int q=i; q<n; q++)//������ �� �����.
				for(int k=0; k<n; k++)
					{if (mat[q][k]==i) mat[q][k]=-2;}
			}
			t=j;
		}
	}
	return t;
}


int main()
{
	cout<<"Vvedite N(razmernost)=";
		cin>>n;

	//��������� -2.
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			mat[i][j]=-2;
	
	int p,m=0;
	int schet=0;
	//������� ������.
	for(int i=0; i<n && i>=0;)
	{

		if (Mozhno(i,m)!=100) 
		{
			p=Mozhno(i,m); 
				Stavit(i,p);
				i++;
				m=0;
		}
		else
		{
		L1:	i--;
			m=Snyat(i)+1;
		}

		if (i==n) 
		{
			schet++;
			cout<<endl<<schet;
			Print();
			goto L1;
		}
	}

	getch();
	return 0;
}