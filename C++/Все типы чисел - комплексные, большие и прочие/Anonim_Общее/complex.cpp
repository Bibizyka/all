#include <iostream>
#include <algorithm>
#include <math.h>

#include<complex.h>
using namespace std;


Complex sum(Complex a, Complex b);//�������� �����. ���������� - ���� main
Complex dif(Complex a, Complex b);//�������� ��������
Complex mult(Complex a, Complex b);//�������� ������������


Complex::Complex()//����������� �� ���������
{
	real = 0;
	imag = 0;
}

Complex::Complex(double real, double imag)//����������� �� ���������� - ���� �������� �������� �������������� � ������ ������
{
	this->real = real;
	this->imag = imag;
}

Complex::~Complex()//����������
{
	real = 0;
	imag = 0;
}

void Complex::read()//������ ������������ ����� - ��� ���������
{
	cout << "�������������� ����� = ";
	cin >> real;
	cout << "������ ����� = ";
	cin >> imag;
}

void Complex::output()//���������� ����� �����
{
	if (real && imag)
	{
		cout << real;
		if (imag > 0)
			cout << '+';
		if ((imag != 1) && (imag != -1))
			cout << imag << 'i' << endl;
		if (imag == 1)
			cout << 'i' << endl;
		if (imag == -1)
			cout << "-i" << endl;
		return;
	}
	if (real)
	{
		cout << real << endl;
		return;
	}
	if (imag)
	{
		if ((imag != 1) && (imag != -1))
			cout << imag << 'i' << endl;
		if (imag == 1)
			cout << 'i' << endl;
		if (imag == -1)
			cout << "-i" << endl;
		return;
	}
	cout << 0 << endl;
}

double Complex::getreal()//������� - �������� �������������� ����� ������������ �����
{
	return real;
}

double Complex::getimag()// - �������� ������ �����
{
	return imag;
}

Complex sum(Complex a, Complex b)//�����
{
	Complex c(a.getreal() + b.getreal(), a.getimag() + b.getimag());
	return c;
};

Complex dif(Complex a, Complex b)//��������
{
	Complex c(a.getreal() - b.getreal(), a.getimag() - b.getimag());
	return c;
}

Complex mult(Complex a, Complex b)//���������
{
	Complex c(a.getreal() * b.getreal() - a.getimag() * b.getimag(), a.getreal() * b.getimag() + a.getimag() * b.getreal());
	return c;
}
