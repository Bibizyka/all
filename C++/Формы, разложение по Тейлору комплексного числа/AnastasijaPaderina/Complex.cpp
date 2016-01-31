#include "stdafx.h"


//����� - ����������� �����
class Complex
	{
	private:
		double real;
		double imag;
	public:
		Complex();
		Complex(double real, double imag);
		~Complex();
		
		void read();
		void output();
		double getreal();
		double getimag();
		
		Complex ZvMinusPervoiStepeni();//����������� ����� � ����� ������ �������
		
	};

	Complex operator+(Complex a, Complex b);
	Complex operator-(Complex a, Complex b);
	Complex operator*(Complex a, Complex b);//��������� ����������� �����
	Complex operator*(int a, Complex b);//��������� ������ ����� �� �����������
	Complex operator/(Complex a, int b);//������� ������������ ����� �� ����� �������
	

	//������������
	Complex::Complex()
	{
		real = 0;
		imag = 0;
	}

	Complex::Complex(double real, double imag)
	{
		this->real = real;
		this->imag = imag;
	}
	//����������
	Complex::~Complex()
	{
		real = 0;
		imag = 0;
	}
	/*
	void Complex::output()
	{
		if(real && imag)
		{
			cout << real;
			if(imag > 0)
				cout << '+';
			if((imag != 1) && (imag != -1))
				cout << imag << 'i' << endl;
			if(imag == 1)
				cout << 'i' << endl;
			if(imag == -1)
				cout << "-i" << endl;
			return;
		}
		if(real)
		{
			cout << real << endl;
			return;
		}
		if(imag)
		{
			if((imag != 1) && (imag != -1))
				cout << imag << 'i' << endl;
			if(imag == 1)
				cout << 'i' << endl;
			if(imag == -1)
				cout << "-i" << endl;
			return;
		}
		cout << 0 << endl;
	}*/

	//��������� �������������� �����
	double Complex::getreal()
	{
		return real;
	}
	//��������� ������������ ����� �����
	double Complex::getimag()
	{
		return imag;
	}

	//������� ��������, ��������� � ���������
	Complex operator+(Complex a, Complex b)
	{
		Complex c(a.getreal() + b.getreal(), a.getimag() + b.getimag());
		return c;
	};

	Complex operator-(Complex a, Complex b)
	{
		Complex c(a.getreal() - b.getreal(), a.getimag() - b.getimag());
		return c;
	}

	Complex operator*(Complex a, Complex b)
	{
		Complex c(a.getreal() * b.getreal() - a.getimag() * b.getimag(), a.getreal() * b.getimag() + a.getimag() * b.getreal());
		return c;
	}

	Complex operator*(int a, Complex b)
	{
		Complex c(a * b.getreal(), a* b.getimag());
		return c;
	}

	Complex operator/(Complex a, int b)
	{
		Complex c(a.getreal()/b, a.getimag()/b);
		return c;
	}
	//����������� ����� � ����� ������ �������
	Complex Complex::ZvMinusPervoiStepeni()
	{
		Complex c(real/(real*real+imag*imag),(-1)*imag/(real*real+imag*imag));
		return c;
	}

	