
#include <iostream>
#include <conio.h>
#include <math.h>//��� �������������� ������� - ���������� ����� � �.�.
#include <stdio.h>

using namespace std;
 

class Root//����������� ����� ������
{
public:
	virtual void Roots() = 0;//����������� ������. ��� ����������� ���������������
	virtual void print() = 0;//��� ������
}
;

class Linear: public Root//��������� - �������� ���������
{
private:
	double _a,_b;//���������� ��� ��������� ���������
public:
		//y=a*x+c
	 void print()//��� ������
	 {
		 cout <<"y = "<<_a<<"*x"<<" + "<<_b<<endl;
	 }

	 //������ �����������:
	 Linear(double a=0, double b=0): _a(a), _b(b)
	 {	 
	 }

	 void Roots()//��� ����������� ���������������
	 {		 
		 //������ ��������� � ���������� �����
		 cout<<"Koren lineinogo uravnenija = "<<(-1)*_b/_a<<endl;
	 }

	~Linear () {};//���������� - �������

}
;

class Binary: public Root//��������� - �������� ���������
{
private:
	double _a,_b,_c;//���������� ��� ��������� ���������
public:
		//a*x^2+b*y^2+c=0
	 void print()//��� ������
	 {
		 cout <<_a<<"*x^2 + "<<_b<<"*x + "<<_c<<" = 0"<<endl;
	 }

	 //������ �����������:
	 Binary(double a=0, double b=0, double c=0): _a(a), _b(b), _c(c)
	 {	 
	 }

	 void Roots( )//��� ����������� ��������������� - ����� ������
	 {		 
		 //������ ��������� � ���������� �����
		double korenDiscr=pow(_b*_b-4*_a*_c,1/2);//������� ������ �� �������������.
		if ((_b*_b-4*_a*_c)>0)
		{
			double x1=((-1)*_b-korenDiscr)/(2*_a);//������ ������.
			double x2=((-1)*_b+korenDiscr)/(2*_a);//������ ������.
			cout<<"Korni binarnogo uravnenija: x1 = "<<x1<<", x2 = "<<x2<<endl;
		}
		else
			if ((_b*_b-4*_a*_c)==0)//������ - ���� ������
			{
				double x=((-1)*_b)/(2*_a);//���� ������
				cout<<"1 koren: x = "<<x;
			}
			else//��� ������
			cout<<"Korney net!"<<endl;
	 }

	~Binary () {};//���������� - �������
}
;

int main()// ������ ����� "� �����".
{
	Root *Uravnenie[1];//������ ���������
	Uravnenie[0] = new Linear(1,2);//�������� ��������� � ������� ��������� - ����� ������
	//������� �� �����:
	Uravnenie[0]->print();
	//������� �� ����� ������
	Uravnenie[0]->Roots();

	cout<<endl;

	Uravnenie[1] = new Binary(1,4,4);//�������� ��������� � ������� ��������� - ������
	//������� �� �����:
	Uravnenie[1]->print();
	//������� �� ����� ������-�����
	Uravnenie[1]->Roots();

	_getch();
	return 0;
}