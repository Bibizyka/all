#include <iostream>
#include <algorithm>
#include <math.h>

#include "complex.cpp"

using namespace std;



Complex sum(Complex a, Complex b);//�������� �����. ���������� - ���� main
Complex dif(Complex a, Complex b);//�������� ��������
Complex mult(Complex a, Complex b);//�������� ������������

int main()
{
	setlocale(LC_ALL, "RUSSIAN");//����� ����� ���� ������������ ������� ����


/////////�������� � ����������� ������:
	cout<<"������ � ����������� ������:"<<endl;
	Complex a, b, c;
	char d;
	cout << "������� ��� �����:" << endl;
	a.read();
	b.read();

	cout << "������� ���� ��������:" << endl;
	cin >> d;//������� ���� + ��� - ��� *
	switch (d)
	{
	case '+':
	{
				c = sum(a, b);
				c.output();
	}
		break;
	case '-':
	{
				c = dif(a, b);
				c.output();
	}
		break;
	case '*':
	{
				c = mult(a, b);
				c.output();
	}
		break;
	}






	system("PAUSE");
	return 0;
	
}

