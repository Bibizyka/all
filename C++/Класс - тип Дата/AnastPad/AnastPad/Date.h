#pragma once
#include <iostream>
using namespace std;

class Date
{
protected:
	unsigned int day, month, year;

public:
	//�����������
	Date(unsigned int Day, unsigned int Month, unsigned int Year);

	//�������� ���
	int GetDays();

	//�������� ������
	int GetMonths();

	//�������� ����
	int GetYear();

	//�������� ���
	void SetDays(int i);

	//�������� ������
	void SetMonths(int i);

	//�������� ����
	void SetYears(int i);

	Date(string s);//��������� ���� �� �������� ������ ������� 2013.12.14 ��� �� ������� 14.12.2013

	//��������� ��������� ���: �������������� ���������
	bool operator == (Date d);

	bool operator != (Date d);
	//���������� - ������ ���� ��� ������(�� ��� �����)
	bool operator < (Date d);

	bool operator > (Date d);

	//���������� ���� ����� ������
	static int DaysBetween(Date*d1, Date*d2);

	//���������� ��� ��� ���
	bool VisokosYear();

	//������ ����
	void print();

	//�������� ���������� ���� �� ����
	void NewDateBeforeDays(unsigned int days);

	//��������� � ���� N ���������� ����
	void NewDateAfterDays(unsigned int days);

	//����������
	~Date();
};
