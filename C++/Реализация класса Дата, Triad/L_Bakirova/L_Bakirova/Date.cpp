#include "Date.h"

//�����������
Date::Date(unsigned int Day, unsigned int Month, unsigned int Year)
{
	this->day = Day;
	this->month = Month;
	this->year = Year;
}
//�������� ���
int Date::GetDays()
{
	return this->day;
}
//�������� ������
int Date::GetMonths()
{
	return this->month;
}
//�������� ����
int Date::GetYear()
{
	return this->year;
}

//�������� ���
void Date::SetDays(int i)
{
	this->day = i;
}
//�������� ������
void Date::SetMonths(int i)
{
	this->month = i;
}
//�������� ����
void Date::SetYears(int i)
{
	this->year = i;
}

Date::Date(string s)//��������� ���� �� �������� ������ ������� 2013.12.14 ��� �� ������� 14.12.2013
{
	//����� ������� �� 2 ����� - �������, � ����� ������� � ��� ����� ���. ���� � ����� - ���� �������, ���� � ������ - ������.
	int y = 0;
	while (s[y] != '.')
	{
		y++;
	}
	if (y == 4)//������ ������ ���� ���� 2013.12.14
	{
		unsigned int i = 0;
		string Year, Month, Day;
		while (s[i] != '.')//��������� ������ ����
		{
			Year += s[i];
			i++;
		}
		i++;

		while (s[i] != '.')//������ �� ������
		{
			Month += s[i];
			i++;
		}
		i++;

		while (i<s.length())//������ �� ���
		{
			Day += s[i];
			i++;
		}

		this->day = atoi(Day.c_str());
		this->month = atoi(Month.c_str());
		this->year = atoi(Year.c_str());
	}
	else// ����� ������ ���� 14.12.2013
	{
		unsigned int i = 0;
		string Year, Month, Day;
		while (s[i] != '.')//��������� ������ ����
		{
			Day += s[i];
			i++;
		}
		i++;

		while (s[i] != '.')//������ �� ������
		{
			Month += s[i];
			i++;
		}
		i++;

		while (i<(unsigned int)s.length())//������ �� ���
		{
			Year += s[i];
			i++;
		}

		this->day = atoi(Day.c_str());
		this->month = atoi(Month.c_str());
		this->year = atoi(Year.c_str());
	}

}

//��������� ��������� ���: �������������� ���������
bool Date::operator == (Date d)
{
	return (this->day == d.day && this->month == d.month && this->year == year);
}
bool Date::operator != (Date d)
{
	return (this->day != d.day || this->month != d.month || this->year != year);
}
//���������� - ������ ���� ��� ������(�� ��� �����)
bool Date::operator < (Date d)
{
	return (this->day + this->month * 30 + this->year * 365 < d.day + d.month * 30 + d.year * 365);
}
bool Date::operator > (Date d)
{
	return (this->day + this->month * 30 + this->year * 365 > d.day + d.month * 30 + d.year * 365);
}

//���������� ���� ����� ������
int Date::DaysBetween(Date*d1, Date*d2)
{
	//������� ���������� ���� ��� ������� ����
	int kol1 = d1->year * 365 + d1->month * 30 + d1->day;
	int kol2 = d2->year * 365 + d2->month * 30 + d2->day;

	return unsigned(kol1 - kol2);//����� �������
}

//���������� ��� ��� ���
bool Date::VisokosYear()
{
	bool y = false;
	if (this->year % 4 == 0) y = true;;
	if (this->year >= 400 && this->year % 100 == 0)
	{
		if (this->year % 400 != 0)
			y = false;;
	};;

	return y;
}

//������ ����
void Date::print()
{
	cout << day << "." << month << "." << year << ".";
}

//�������� ���������� ���� �� ����
void Date::NewDateBeforeDays(unsigned int days)
{
	unsigned int safeYear1 = this->year;
	//����� ���������� ���������� ���� �� ����-���-������
	unsigned int d, m, y, saveYear = this->year;
	y = days / 365;//����� �� ����
	days = days - y * 365;
	m = days / 30;//����� �� ������
	days = days - m * 30;
	d = days;//��������� ������ - �������� ���.

	//����� �������� � ����� ������� �������� - �����.
	this->year = year - y;
	//����� - � �������
	if (this->month<m)//���� ���������� ���������� ������� - ������,��� � ����� �������� ����(���������� ������� � �������� ����)
	{
		this->year--;//��������� ��� �������� ��� �� �������
		this->month = 12 - (m - this->month);
	}
	else
	{
		if (this->month == m) //���� ���������� ���������� ������� - ����� ����� �������� ����
		{
			this->year--;
			this->month = 12;
		}
		else
			this->month = this->month - m;
	}

	if (this->day<d)//���� ���������� ���������� ���� ������, ��� � ����� �������� ����
	{
		this->day = 30 - (d - this->day);
		if (this->month != 1)
		{
			this->year--;
			this->month = 12;
		}
		else
			this->month--;
	}
	else
	{
		if (this->day == d)
		{
			this->day = 30;
			if (this->month == 1)
			{
				this->year--;
				this->month = 12;
			}
			else
				this->month--;
		}
		else
			this->day = this->day - d;
	}
	//������ ������� �������� - � �� �������� �� �� ����� ���������� ��� ���������� ����? ���� �� - �� �������� +1 ����  �� ������ ���������� ���
	unsigned int safeYear2 = this->year;

	while (safeYear2<safeYear1)//�������� �� ������������ � �������������� - ����������� +1 ��� ��� ������������� ������������ ����
	{
		bool y = false;
		if (safeYear2 % 4 == 0) y = true;;
		if (safeYear2 >= 400 && safeYear2 % 100 == 0)
		{
			if (safeYear2 % 400 != 0)
				y = false;;
		};;

		safeYear2++;
	}


}

//��������� � ���� N-�� ���������� ����
void Date::NewDateAfterDays(unsigned int days)
{
	int safeYear1 = this->year;

	int kol = this->year * 365 + this->month * 30 + this->day;

	kol = kol + days;
	this->year = kol / 365;
	kol = kol - this->year * 365;
	this->month = kol / 30;
	kol = kol - this->month * 30; if (this->month == 0) this->month++;;
	this->day = kol; if (this->day == 0) this->day++;;

	//��������� ���������� � ����������� ������, ������� ���� ��������� ����� ����������� �����. ���� ��� ���� - ����� ������� �� �������
	int safeYear2 = this->year;

	while (safeYear1<safeYear2)
	{
		bool y = false;
		if (safeYear1 % 4 == 0) y = true;;
		if (safeYear1 >= 400 && safeYear1 % 100 == 0)
		{
			if (safeYear1 % 400 != 0)
				y = false;;
		};;


		if (y == true) NewDateBeforeDays(1);;

		safeYear1++;
	}
}


//����������
Date::~Date()
{};
