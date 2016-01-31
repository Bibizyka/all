#include <stdio.h>//�������� ���������� ����� � ������.
#include <conio.h>//���������� �������� ������ ����� ���������� ���������
#include <cstring>//���������� ������ �� ��������

struct  Dates//��������� - ����
{                 
	/* ������ ����� ���������*/  
	int day;     /* ���� ��� - ����� �� 1 �� 31*/
	char month[3];  /* �����: ��-�� ������������������� ���������(��������� ��� ����������) �������� ������� - ������ ����� 01, 02 � �.�.*/
	int year;     /*���, �� ����� ���� �����, ���� ���������� �� ������ ���������� */
}; 

//������� ������ �������
void Swap(Dates mass[], int i, int j)
{
    Dates temp = mass[i];
    mass[i] = mass[j];
    mass[j] = temp;
}

int main()
{
	//�������������� ���� ������������ ���. ����� ���� �� ������� � ����� � ������ scanf ������������� - �� �� ��� ��������� ������ ���������� ���.
	struct Dates dates[5]={{12,"12",2321},{23,"12",2321},{31,"06",2321},{12,"12",2321},{16,"09",2321}};
	int n=5;//����� 5 ���
	//�������� ���� �� ����������
	printf("Before sorting:\n");
	for(int i=0; i<n; i++)
	{
		printf("%i.%s.%i.\n",dates[i].day,dates[i].month,dates[i].year);
	}
	printf("\n\n\n");

	//��������� - ����� "��������" - ����� "������-�������" �� ����� - ������ � ������ �������         
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n-1; j++)
                {
					if (dates[j].year>=dates[j + 1].year)
                    {	
						Swap(dates, j, j + 1);
                    }
                }
            }
			//��������� �� ������� c ����������� ������
		if (n>1)
		{
			for(int x=1; x<n; x++)
			{
				int y=1;//������� ��� ���������� ���-�����
				while(dates[x].year==dates[x-1].year)
				{
					y++;
					x++;
				}
				//���� �� ����� �� ����� ������ �����, �� ��������� ���
				if (y>1)
				{
					for (int i = x-y; i < x; i++)
					{
						for (int j = x-y; j < x-1; j++)
						{
							if (strcmp(dates[j].month,dates[j + 1].month)>=0)
							{	
								Swap(dates, j, j + 1);
							}
						}
					}
				}
			}

			//������ ��������� �� �������
			for(int x=1; x<n; x++)
			{
				int y=1;//������� ��� ���������� ���-����� � ����������� ��������(�� ������� �����!)
				while(dates[x].year==dates[x-1].year && (strcmp(dates[x].month,dates[x-1].month)==0))
				{
					y++;
					x++;
				}
				//���� �� ����� �� ����� ������ �����, �� ��������� ���
				if (y>1)
				{
					for (int i = x-y; i < x; i++)
					{
						for (int j = x-y; j < x-1; j++)
						{
							if (dates[j].day>=dates[j + 1].day)
							{	
								Swap(dates, j, j + 1);
							}
						}
					}
				}
			}
		}
		else;//��������� ����� �������.
	
	//������ ����������� ����� ����������
	printf("After sorting:\n");
	for(int i=0; i<n; i++)
	{
		printf("%i.%s.%i.\n",dates[i].day,dates[i].month,dates[i].year);
	}
	//����� - ��������
	getch();
	return 0;
}