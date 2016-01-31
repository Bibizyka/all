#include <stdio.h>
#include <fstream>
#include <conio.h>

int const N=1000; // ��������� ��� ����������� ��������
	
// ������� ������������������� - ��������
int* Merger(int *A, int na, int *B, int nb)
{
	static int C[N];
	//��������� �������
	for(int i=0, j=0; i<=na && j<=nb;)
	{
		while(A[i]<=B[j] && i<=na)
		{
			C[i+j]=A[i];
			i++;
		}
		while(B[j]<=A[i] && j<=nb)
		{
			C[i+j]=B[j];
			j++;
		}
	}

	return C;
}

int main()
{
	// ��� ������ �������� ����� � �������
	setlocale(LC_ALL, "Russian");
	
	//������� ������� ����� �������������������
	int A[N], B[N];
	int na=0,nb=0;

	//���� ������ - ��� ���� ������������������
	printf("������� ����� 1�� ������������������: \n");
	scanf("%i", &na);
	printf("������� ������ ����������� ������������������ ����� Enter: ");
	for(int i=0; i<na; i++)
	{
		scanf("%i",&A[i]);
	}

	printf("������� ����� 2�� ������������������: \n");
	scanf("%i", &nb);
	printf("������� ������ ����������� ������������������ ����� Enter: ");
	for(int i=0; i<nb; i++)
	{
		scanf("%i",&B[i]);
	}

	int * C=Merger(A,na,B,nb);
	printf("��������� �������:\n");
	for(int i=0; i<nb+na; i++)
	{
		printf("%i, ",C[i]);
	}

	_getch();// ����� ������ - ����� �� �� ���
	return 0;
	
}