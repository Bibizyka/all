#include <stdio.h>
#include <math.h>
#include <fstream>
#include <conio.h>


void GetColumn(int i)
{
	FILE *f = fopen("file.txt", "r"); 
	int h=0,w=0;// ������ � ������ �������
	fscanf(f,"%d",&h);//C�������� ������ � ������ int
	fscanf(f,"%d",&w);

	//������� � ��������� ��� ��������� ������ ��-�������
	double ** mass=new double*[h];
	for(int i=0; i<h; i++)
	{
		mass[i]=new double[w];
		for(int j=0; j<w; j++)
			fscanf(f,"%f",&mass[i][j]);
	}

	if (i>w) // ���� ������ ����� �������, ������� ��� � �������
	{
		printf("�� ����� ������ ����� �������!");
		return;
	}
	else
	{
	//������ ������������ - ������� ���� �������
	for(int j=0; j<h; j++)
		printf("%f",mass[j][i]);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");// ����� ��������� ������� ���� � �������

	
	int n=0;// ����� �������
	printf("������� ����� ������� � �������:\n");
	scanf("%i",&n);
	
	//�������� ���� �������
	GetColumn(n);

	_getch();
	return 0;
	
}