#include<iostream>//� ������ - ����� ���������� ��� ���� ���� �� �������� �������. � ��������� - ����� ���� �������� �� �������� �������.
#include<conio.h>
#include<iomanip>
using namespace std;
/*
� �������� ������� ����������, ���
1) ���� ����� �������� �� ���� ������� �� ������� 3�3 � ����� (���������������� 5�5).
2) � �������� ������� ���� ����� ��������� ������ � ������� 6�6 � �����
��� �� �������� � ����� ������ ���������.
� ������� ������-�� ��������� ��������. � � ����������� �� ���������� ����������� ���������� ������� � �������� �������.
*/
int const N=100, M=10001;
int mat[N][N], prov[M];
int n=7;
int kol=1;
void Print(int mat[N][N])
{
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<endl;
		for(int j=0; j<n; j++)
			cout<<setw(3)<<mat[i][j];
	}
	cout<<endl;
}

void BoolOk(int A, int B, int poz1, int poz2, int n)
{
	bool yes1=true, yes2=false;
	for (int s=0;s<n;s++)//�������� �� ����������� ���� �������.
		for(int d=0;d<n;d++)
			{if (mat[s][d]==0) yes1=false;}

		if (poz1-2>=0 && poz2+1<n && poz1-2==A && poz2+1==B) yes2=true;
		else if (poz1-1>=0 && poz2+2<n && poz1-1==A && poz2+2==B) yes2=true;
		else if (poz1+1<n && poz2+2<n && poz1+1==A && poz2+2==B) yes2=true;
		else if (poz1+2<n && poz2+1<n && poz1+2==A && poz2+1==B) yes2=true;
		else if (poz1+2<n && poz2-1>=0 && poz1+2==A && poz2-1==B) yes2=true;
		else if (poz1+1<n && poz2-2>=0 && poz1+1==A && poz2-2==B) yes2=true;
		else if (poz1-1>=0 && poz2-2>=0 && poz1-1==A && poz2-2==B) yes2=true;
		else if (poz1-2>=0 && poz2-1>=0 && poz1-2==A && poz2-1==B) yes2=true;
		else yes2=false;//���������� ����� ��� �� �������� ������� ��� ���� ��� ����.
		if (yes1==true && yes2==true) {cout<<kol; kol++; Print(mat);};
	}


int main()
{
	cout<<"Vvedite N-razmernost' = ";
		cin>>n;
	int m=n*n;/* pred=m+1, predel=m+2;*/
	bool ok=false;
	int q,w,mistake, t;
		int pozI=0, pozJ=0;
	/*cout<<"Vvedite pozicii kon'a: "<<endl;
		cin>>pozI;
		cin>>pozJ;*/
		//�������� ��������� �������
		int pozISave=pozI, pozJSave=pozJ;
	
	/*
	for (int a=0; a<n; a++)//��� ���������, ������������ ��� ��������� �������� ���������� ���� 1� ����.
	{
		for (int b=0; b<n; b++)
		{
			pozI=a; pozJ=b;
			//������ ������� ��� ����.
			for(int i=0; i<n ; i++)
				for(int j=0; j<n; j++)
				{
					mat[i][j]=0;
				}
			for(int y=0; y<=m+2; y++)
				prov[y]=0;

			mat[pozI][pozJ]=1;
			prov[1]=1;
			for(int i=1; i<m && i>=1 && prov[1]<=8; )//��� ��� ������ ���� ����, ��� ������� �� ������� � �������� �������.
			{
				if (prov[i]<1 && pozI-2>=0 && pozJ+1<n && mat[pozI-2][pozJ+1]==0) q=pozI-2, w=pozJ+1, ok=true, t=1;
				else if (prov[i]<2 && pozI-1>=0 && pozJ+2<n && mat[pozI-1][pozJ+2]==0) q=pozI-1, w=pozJ+2, ok=true, t=2;
				else if (prov[i]<3 && pozI+1<n && pozJ+2<n && mat[pozI+1][pozJ+2]==0) q=pozI+1, w=pozJ+2, ok=true, t=3;
				else if (prov[i]<4 && pozI+2<n && pozJ+1<n && mat[pozI+2][pozJ+1]==0) q=pozI+2, w=pozJ+1, ok=true, t=4;
				else if (prov[i]<5 && pozI+2<n && pozJ-1>=0 && mat[pozI+2][pozJ-1]==0) q=pozI+2, w=pozJ-1, ok=true, t=5;
				else if (prov[i]<6 && pozI+1<n && pozJ-2>=0 && mat[pozI+1][pozJ-2]==0) q=pozI+1, w=pozJ-2, ok=true, t=6;
				else if (prov[i]<7 && pozI-1>=0 && pozJ-2>=0 && mat[pozI-1][pozJ-2]==0) q=pozI-1, w=pozJ-2, ok=true, t=7;
				else if (prov[i]<8 && pozI-2>=0 && pozJ-1>=0 && mat[pozI-2][pozJ-1]==0) q=pozI-2, w=pozJ-1, ok=true, t=8;
				else ok=false;//���������� ����� ��� ��� ����.

				if (ok==true)//���� ��� �������� � �� ������.
				{
					pozI=q;//����� ������� ����.
					pozJ=w;//
					prov[i]=t;
						i++;
						mat[pozI][pozJ]=i;//����� �������� ����.
				}
				else //���� ��� ���������� - ����� �� ���������� �������. � ����� ����� ���������.
				{
					L1:
					mistake=i;
					prov[i]=0;
					i--;
					for(int e=0; e<n; e++)
						for(int r=0; r<n; r++)
						{
							{if (mat[e][r]==mistake) mat[e][r]=0;}//�������� ��������� �������.
							{if (mat[e][r]==i) pozI=e, pozJ=r;}//���� ������ �������
						}
				}
				ok=true;
				for (int s=0;s<n;s++)
					for(int d=0;d<n;d++)
						{if (mat[s][d]==0) ok=false;}
				if (i==m && ok==true) {cout<<kol; kol++; Print(mat); goto L1;}
			}
		}
	}*/

		
	for (int a=0; a<n; a++)//��� ���������, ������������ ��� ��������� �������� ���������� ���� 1� ����
		//��� ���� ���� ������ ��������� �� �������� �������.
	{
		for (int b=0; b<n; b++)
		{
			pozI=a; pozJ=b;
			//������ ������� ��� ����.
			for(int i=0; i<n ; i++)
				for(int j=0; j<n; j++)
				{
					mat[i][j]=0;
				}
			for(int y=0; y<=m+2; y++)
				prov[y]=0;

			mat[pozI][pozJ]=1;
			prov[1]=1;
			for(int i=1; i<m && i>=1 && prov[1]<=8; )//��� ��� ������ ���� ����, ��� ������� �� ������� � �������� �������.
			{
				if (prov[i]<1 && pozI-2>=0 && pozJ+1<n && mat[pozI-2][pozJ+1]==0) q=pozI-2, w=pozJ+1, ok=true, t=1;
				else if (prov[i]<2 && pozI-1>=0 && pozJ+2<n && mat[pozI-1][pozJ+2]==0) q=pozI-1, w=pozJ+2, ok=true, t=2;
				else if (prov[i]<3 && pozI+1<n && pozJ+2<n && mat[pozI+1][pozJ+2]==0) q=pozI+1, w=pozJ+2, ok=true, t=3;
				else if (prov[i]<4 && pozI+2<n && pozJ+1<n && mat[pozI+2][pozJ+1]==0) q=pozI+2, w=pozJ+1, ok=true, t=4;
				else if (prov[i]<5 && pozI+2<n && pozJ-1>=0 && mat[pozI+2][pozJ-1]==0) q=pozI+2, w=pozJ-1, ok=true, t=5;
				else if (prov[i]<6 && pozI+1<n && pozJ-2>=0 && mat[pozI+1][pozJ-2]==0) q=pozI+1, w=pozJ-2, ok=true, t=6;
				else if (prov[i]<7 && pozI-1>=0 && pozJ-2>=0 && mat[pozI-1][pozJ-2]==0) q=pozI-1, w=pozJ-2, ok=true, t=7;
				else if (prov[i]<8 && pozI-2>=0 && pozJ-1>=0 && mat[pozI-2][pozJ-1]==0) q=pozI-2, w=pozJ-1, ok=true, t=8;
				else ok=false;//���������� ����� ��� ��� ����.

				if (ok==true)//���� ��� �������� � �� ������.
				{
					pozI=q;//����� ������� ����.
					pozJ=w;//
					prov[i]=t;
						i++;
						mat[pozI][pozJ]=i;//����� �������� ����.
				}
				else //���� ��� ���������� - ����� �� ���������� �������. � ����� ����� ���������.
				{
					L1:
					mistake=i;
					prov[i]=0;
					i--;
					for(int e=0; e<n; e++)
						for(int r=0; r<n; r++)
						{
							{if (mat[e][r]==mistake) mat[e][r]=0;}//�������� ��������� �������.
							{if (mat[e][r]==i) pozI=e, pozJ=r;}//���� ������ �������
						}
				}	
				if (i==m) {BoolOk(a, b, pozI, pozJ, n); goto L1;}
			}
		}
	}

	for(int i=0; i<m+2; i++)
		cout<<prov[i]<<" ";
	_getch();
	return 0;
}