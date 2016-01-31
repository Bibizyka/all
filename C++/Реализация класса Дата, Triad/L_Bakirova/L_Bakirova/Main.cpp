//���������� �������, ��� ���� ���������� � ������������ ����

#include <iostream>
#include <conio.h>
#include "Date.h"


using namespace std;

int main()
{
	int const N = 3;
	Date *dates[N];//������� ������ ���
	dates[0] = new Date(12, 2, 2012);//�������������� ������ ���� �� �������. �� ������� ��� - �������, ��������� ����. ����� ������.
	cout << "Examples:" << endl;//�������� �������:
	dates[0]->print();//�������� ��� �������� - ������� � �������
	cout << endl << endl;

	dates[1] = new Date("2016.12.14");//�����, ������ ���� � �������.
	dates[1]->print();//�������� ��� �������� - ������� � �������
	cout << endl << endl;

	dates[2] = new Date("14.12.2013");//�����, ������ ���� � �������.
	dates[2]->print();//�������� ��� �������� - ������� � �������
	cout << endl;
	//����� �������� ���������� ���� ����� ����� ����
	cout << endl << "1." << endl;

	//�������� �� ���� ����������� ���������� ���� - �������� ������� ����� -N ����, ��������. � ����� ������ - 1 ���� � -366 ����
	int d = 2;//���������� ����
	cout << "Old Data: "; dates[2]->print(); cout << endl;//������� ������� ������ ����, ��� ���������

	dates[2]->NewDateBeforeDays(d);
	cout << endl << "   1) New date -" << d << " day: " << endl;
	dates[2]->print();//�������� ����� ����

	cout << endl << endl;

	d = 365 + 1;
	dates[2]->NewDateBeforeDays(d);
	cout << endl << "   2) New date -" << d << " days: " << endl;
	dates[2]->print();//�������� ����� ����
	cout << endl << endl<< "2.";

	//������� � ���� N ����
	cout << endl << "Old date :"; dates[2]->print();
	dates[2]->NewDateAfterDays(123);
	cout << endl << "   New date after 123 days: "; dates[2]->print();

	cout << endl << endl << "3." << endl;


	//C������ ����
	//1�� ����
	if (dates[0] == dates[1])
	{
		cout << "Dates ==: "; dates[0]->print(); cout << " and "; dates[1]->print();
	}
	else
	{
		cout << "Dates !=: "; dates[0]->print(); cout << " and "; dates[1]->print();
	}

	cout << endl;

	//2�� ����
	dates[3] = dates[1];//������� ����� ���� - ��� ��������� :)
	if (dates[1] == dates[3])
	{
		cout << "Dates ==: "; dates[1]->print(); cout << " and "; dates[3]->print();
	}
	else
	{
		cout << "Dates !=: "; dates[1]->print(); cout << " and "; dates[3]->print();
	}

	cout << endl << endl<< "4." << endl;


	int i = Date::DaysBetween(dates[1], dates[2]);//������� ���������� ���� ����� ������
	//���������� ���� ����� ������:
	cout << "Days between ";
	dates[1]->print();
	cout << " and ";
	dates[2]->print();
	cout << "    = " << i;

	cout << endl << endl << "5." << endl;

	//��������� ������������ ���
	for (int i = 0; i<N; i++)
	{
		if (dates[i]->VisokosYear())
		{
			dates[i]->print(); cout << "is Visokos year." << endl;
		}
		else
		{
			dates[i]->print(); cout << "is NOT Visokos year." << endl;
		}
	}


	//������ �������� ������:
	_getch();
	return 0;
}