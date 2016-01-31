#include<iostream>//������� ����� ��� ������ "�������������� ������������".
#include<conio.h>
#include<string>
using namespace std;
/*
* ������ �1. ��������� ��������� �������. �������� ������� �� ���������� ���� � ���. (��."�������������� ������������")
*
* ������ �2. ������� ������ ����. �� ���� �������� - ����������� ������, ���������� � �� ���� ������ � ������� n-���������� ��������� � ����� ������
* �������� ������ ���� ����.
* ���������� ���������� ���������� - 8(���=��������). � ������� ����������������� ��������������� ������� ���������� ����������.
*
*/
int const N=1000;
int mass[N][N];//������������� ������ ��� ��� ����������, ��� � ��� ����� ������ ������.
char stroka[N];
//������� ��� ������ "���������":
bool ProvPustota(int n, int m)//��������� ������� ����������,a - ���, x-�����.
{
	bool ok=false;
	for(int y=0; y<n; y++)
		for(int b=0; b<m; b++)
		{
			if (mass[y][b]==0) {ok=true; return ok;};
		}
	return ok;
}
void Prov(int a, int x, int m)//�������� ����������� ������������ ����. ���� �������������. a-���,x-���������� ����,m-������ ����(����������).
{
	//���� ������ ������ �����.
	bool ok=false;
	int mesto1, schet=0, mesto2;
	for(int q=0; q<m; q++)
	{
		if (q==m-1) {cout<<"NO places!"<<endl; return;}//���� ���� ��� ��� ����� - �� ������.
		else if (mass[a][q]==0) {mesto1=q; break;}
	}
	//������ ��������� �� ����������� ����������.
	for(int q=mesto1; q<m; q++)
	{
		//����� �� ���������?
		if (mass[a][q]==0) schet++; else {cout<<"NO places!"<<endl; return;}
		if (schet==x) mesto2=q;
	}
	//���������
	if (schet<x)  {cout<<"NO places!"<<endl; return;}
	schet=mesto1;
	while (mesto1<=mesto2)
	{
		mass[a][mesto1]=1;
		mesto1++;
	}
	cout<<"Yes! "<<"Places from "<<schet+1<<" to "<<mesto2+1<<endl;
}
void Kinoteatr()//�������� ������� ������� ����� ����������.
{
	int n,m;
	cout<<"Vvedite n=";
		cin>>n;
	cout<<"Vvedite m=";
		cin>>m;
	//������ ������ ����� � ����������.
	for (int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			mass[i][j]=0;
	//������ ��������.
	int zaprosRjad, zaprosMest;
	for(int i=0; i<n*m; i++)
	{
	L1:
		{if (ProvPustota(n,m)==false) {cout<<"Ok! Polniy kinoteatr! NO PLACES. "<<endl; return;}}//��������� ��������� �� �������������.
		cout<<endl<<"Vvedite rjad="; cin>>zaprosRjad;
		cout<<"Vvedite kol.mest="; cin>>zaprosMest;
		if (zaprosRjad>n || zaprosMest>m) {cout<<"Error! Povtorite popitku!"; goto L1;}
		Prov(zaprosRjad-1,zaprosMest, m);//��������� � ������� ���� �����. ���� �� - �� �������� ������-�����. ����� - NO. 
	}
}

//������� ��� ������ "������ �����"
void Algorithm(int i)
{
	//�������� �����
	int m=strlen(stroka);
	int z=m-i;
	for(int j=1; j<=z; j++)//������������ � ���� ������ ����������� �� ��������� ��������� ���������
	{
		stroka[m+j-1]=stroka[m-j];
	}
}
void StrokaChisel()//�������� ������� �� ���������� "������ �� �����".
{
	//������ ������.
	cout<<endl<<"Vvedite stroku: ";
	cin.getline(stroka, 100);
	int n;//���������� ����������.
	cout<<"Vvedite kolichestvo algorithmov= "; cin>>n;
	
	for (int i=0; i<8; i++)
	{
		Algorithm(i+1);//������� � �������� ����� ����.
		cout<<endl<<stroka<<endl;//��� ������������ ������� ������.
	}
	cout<<"Element pod nomerom 102: "<<stroka[101]<<endl;
		cout<<"Element pod nomerom 302: "<<stroka[301]<<endl;
			cout<<"Element pod nomerom 502: "<<stroka[501]<<endl;

}

//������� ��� ������ ��� ��� ���������� ���������� a,b,c.
bool TrueFalse(bool a, bool b, bool c)//������� ������ ������� ���������. � ������ - ��� ������ ������������� a.b.c. ������ ������� ���� ���������� �� �������������� ����� �����?
{
	/*
	* ���� ��� ���������� "����" - ���� b "����" ���� � "����".
	* �� ������� ���������� � ����� ������, �.�. ����� ���������� ����������. ����� - �������� b � c.
	*
	*
	*
	*/
	if (a==1) return 1; 
	else if (b==0) return 0;
	else if (c==0) return 0;
	else return 1;
	//����� 8 ���������� ��-���� ������� � ����? �����?
	/*
	*abc
	*000|0or1or0->  0
	*001|0or1->		0
	*010|0->		0
	*011|1->		1
	*100|1or0or0->	1
	*101|1or1->		1
	*110|1or0->		1
	*111|1->		1
	*/
}

int main()
{
	/*cout<<"Zadacha kinoteatr: "<<endl;
		Kinoteatr();

	cout<<endl<<"Zadacha o stroke iz chisel: "<<endl;
		StrokaChisel();
		*/
	cout<<endl<<"Logicheskaya zadacha: "<<endl<<"Vvedite logicheskie peremennie: ";
	int a,b,c;
	for(int i=0; i<8; i++)//������������ ���������� ��� ��������� ������������ �������.
	{
		cout<<endl<<"Vvod: ";
		cin>>a>>b>>c;
		cout<<"Vivod: "<<TrueFalse(a,b,c)<<endl;
	}

	getch();
	return 0;
}