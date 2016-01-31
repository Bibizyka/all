
#include <iostream>
#include <conio.h>

using namespace std;


class Date
{
private:
	unsigned int day, month, year;
public:

	//�����������
	Date(unsigned int Day=0,unsigned int Month=0,unsigned int Year=0)
	{
		this->day=Day;
		this->month=Month;
		this->year=Year;
	}
	//�������� ���
	int GetDays()
	{
		return this->day;
	}
	//�������� ������
	int GetMonths()
	{
		return this->month;
	}
	//�������� ����
	int GetYear()
	{
		return this->year;
	}
	
	//�������� ���
	void SetDays(int i)
	{
		this->day=i;
	}
	//�������� ������
	void SetMonths(int i)
	{
		this->month=i;
	}
	//�������� ����
	void SetYears(int i)
	{
		this->year=i;
	}

	Date(string s)//��������� ���� �� �������� ������ ������� 2013.12.14 ��� �� ������� 14.12.2013
	{
		//����� ������� �� 2 ����� - �������, � ����� ������� � ��� ����� ���. ���� � ����� - ���� �������, ���� � ������ - ������.
		int y=0;
		while(s[y]!='.')
		{
			y++;
		}
		if (y==4)//������ ������ ���� ���� 2013.12.14
		{
			int i=0;
			string Year, Month, Day;
			while (s[i]!='.')//��������� ������ ����
			{
				Year+=s[i];
				i++;
			}
			i++;

			while (s[i]!='.')//������ �� ������
			{
				Month+=s[i];
				i++;
			}
			i++;

			while (i<s.length())//������ �� ���
			{
				Day+=s[i];
				i++;
			}		
		
			day=atoi( Day.c_str() );
			month=atoi( Month.c_str() );
			year=atoi( Year.c_str() );
		}
		else// ����� ������ ���� 14.12.2013
		{
			int i=0;
			string Year, Month, Day;
			while (s[i]!='.')//��������� ������ ����
			{
				Day+=s[i];
				i++;
			}
			i++;

			while (s[i]!='.')//������ �� ������
			{
				Month+=s[i];
				i++;
			}
			i++;

			while (i<s.length())//������ �� ���
			{
				Year+=s[i];
				i++;
			}		
		
			day=atoi( Day.c_str() );
			month=atoi( Month.c_str() );
			year=atoi( Year.c_str() );
		}

	}

	//��������� ��������� ���: �������������� ���������
	bool operator == (Date d)
	{
		return (this->day==d.day && this->month==d.month && this->year==year);
	}
	bool operator != (Date d)
	{
		return (this->day!=d.day || this->month!=d.month || this->year!=year);
	}

	//���������� ���� ����� ������
	static int DaysBetween(Date*d1, Date*d2)
	{
		//������� ���������� ���� ��� ������� ����
		int kol1=d1->year*365+d1->month*30+d1->day;
		int kol2=d2->year*365+d2->month*30+d2->day;

		return unsigned (kol1-kol2);//����� �������
	}	

	//������ ����
	void print()
	{
		cout<<day<<"."<<month<<"."<<year<<".";
	}
	
	//�������� ���������� ���� �� ����
	void NewDateBeforeDays(unsigned int days)
	{
		//����� ���������� ���������� ���� �� ����-���-������
		int d,m,y;
		y=days/365;//����� �� ����
			days=days-y*365;
		m=days/30;//����� �� ������
			days=days-m*30;
		d=days;//��������� ������ - �������� ���.
		
		//����� �������� � ����� ������� �������� - �����.
		this->year=year-y;
		//����� - � �������
		if (this->month<m)//���� ���������� ���������� ������� - ������,��� � ����� �������� ����(���������� ������� � �������� ����)
		{
			this->year--;//��������� ��� �������� ��� �� �������
			this->month=12-(m-this->month);
		}
		else
		{
			if (this->month==m) //���� ���������� ���������� ������� - ����� ����� �������� ����
			{
				this->year--;
				this->month=12;
			}
			else
				this->month=this->month-m;
		}

		if (this->day<d)//���� ���������� ���������� ���� ������, ��� � ����� �������� ����
		{
			this->day=30-(d-this->day);
			if (this->month!=1)
				{
					this->year--;
					this->month=12;
				}
			else
				this->month--;
		}
		else
		{
			if (this->day==d)
			{
				this->day=30;
				if (this->month==1)
				{
					this->year--;
					this->month=12;
				}
				else
					this->month--;
			}
			else
				this->day=this->day-d;
		}
	}

	//����������
	~Date()
	{}
};


int main()
{
	int const N=3;
	Date *dates[N];//������� ������ ���
	dates[0]=new Date(12,2,1933);//�������������� ������ ���� �� �������. �� ������� ��� - �������, ��������� ����. ����� ������.
	cout<<"Examples:"<<endl;//�������� �������:
	dates[0]->print();//�������� ��� �������� - ������� � �������
	cout<<endl<<endl;

	dates[1]=new Date("2013.12.14");//�����, ������ ���� � �������.
	dates[1]->print();//�������� ��� �������� - ������� � �������
	cout<<endl<<endl;

	dates[2]=new Date("14.12.2013");//�����, ������ ���� � �������.
	dates[2]->print();//�������� ��� �������� - ������� � �������
	cout<<endl<<endl;
	//����� �������� ���������� ���� ����� ����� ����

	//�������� �� ���� ����������� ���������� ���� - �������� ������� ����� -N ����, ��������. � ����� ������ - 1 ���� � -366 ����
	int d=2;//���������� ����
	cout<<"Old Data: "; dates[2]->print(); cout<<endl;//������� ������� ������ ����, ��� ���������

	dates[2]->NewDateBeforeDays(d);
	cout<<endl<<"   1) New date -"<<d<<" day: "<<endl;
	dates[2]->print();//�������� ����� ����

	cout<<endl<<endl;

	d=365+1;
	dates[2]->NewDateBeforeDays(d);
	cout<<endl<<"   2) New date -"<<d<<" days: "<<endl;
	dates[2]->print();//�������� ����� ����

	cout<<endl<<endl;


	//C������ ����
	//1�� ����
	if (dates[0]==dates[1])
	{
		cout<<"Dates ==: "; dates[0]->print(); cout <<" and "; dates[1]->print(); 
	}
	else
	{
		cout<<"Dates !=: "; dates[0]->print(); cout <<" and "; dates[1]->print();
	}

	cout<<endl<<endl;

	//2�� ����
	dates[3]=dates[1];
	if (dates[1]==dates[3])
	{
		cout<<"Dates ==: "; dates[1]->print(); cout <<" and "; dates[3]->print(); 
	}
	else
	{
		cout<<"Dates !=: "; dates[1]->print(); cout <<" and "; dates[3]->print();
	}

	cout<<endl<<endl;

	int i=Date::DaysBetween(dates[1],dates[2]);//������� ���������� ���� ����� ������
	//���������� ���� ����� ������:
	cout<<"Days between "; 
		dates[1]->print(); 
		cout << " and "; 
		dates[2]->print(); 
		cout << "    = "<<i;



	_getch();
	return 0;
}