#include<conio.h>
#include<iostream>
#include<math.h>

using  namespace std;

// ���� ����������� �������
double function(double x, double e, int stepen)
{
	// ������� �������� �������
	double f=(pow(2.0,stepen)*pow(x,stepen))/(sqrt((1+4*stepen)*pow(5.0,stepen)));

	cout<<f<<endl;// �������� ������������� ����������
	// ������� �������� - ��������� � ������������
	if (f>e)
	{
		return f+function(x,e,stepen+1);// ������� ����� �������� �� ��������
	}
	else
	{
		return f;// ����� ������ �������� ��������
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");// ��� ������ �������� �����

	double x=0, e=0; // x - �������� ����������, e - �������� ����������

	cout<<"������� �������� 'x' = ";
	cin>>x;
	
	cout<<"������� 'e'(�����������) = ";
	cin>>x;

	cout<<"��������� = "<<function(x,e,0);// �������� ������� � �������� ���������. �������� �����, �������� � ��������� �������

	getch();// �����, ����� ������� �� ���������
}