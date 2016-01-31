#pragma once
#include <iostream>
using namespace std;

class Triad
{
protected:
	unsigned int day, month, year;
public:
	Triad(int day = 0, int month = 0, int year = 0)
	{
		this->day = day;
			this->month = month;
		this->year = year;
	};
	//�������� ���
	virtual int GetDays()=0;

	//�������� ������
	virtual int GetMonths()=0;

	//�������� ����
	virtual int GetYear()=0;

	//�������� ���
	virtual void SetDays(int i)=0;

	//�������� ������
	virtual void SetMonths(int i)=0;

	//�������� ����
	virtual void SetYears(int i)=0;

	//������ ����
	virtual void print() = 0;

	~Triad() {};
};

class Date: public Triad
{


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
