#include <iostream>
#include <fstream>
#include <cmath>
#include<conio.h>
#include <algorithm>

using namespace std;

// ������� ����� �����(��� �������� �����������)
long long n, m;
long long result[1000][1000];// ��� �������� ���������� ������������
long long matrix[1000][1000]; // ��������� ������� ������� ����� �������� � �������
long long answer[1000][1000]; // ��� ��������� ������

// ������ ��������
void Print(int n)
{
	cout << "������-���������:"<<endl;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout << answer[i][j] << " ";
		cout << endl;
	}
}

// ���������� ������ - ���������� ���������� ������� � �����������
void Mult(long long matrix1[1000][1000], long long matrix2[1000][1000], int n)
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k <n; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			matrix1[i][j] = result[i][j];
}

// ������� �������� ���������� � �������
void ans(int n, int m)
{
	while (m)// m - ������������ �������
	{
		if (m & 1)
			Mult(answer, matrix, n);

		Mult(matrix, matrix, n);

		m >>= 1;// �������� ������� ������
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");// ����� �������� �����
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	// n - ����������� ( ������� ���������� ������ ����)
	// m - �������
	cout << "������� ��������� �������(���������� �����/��������) � �������:";
	cin >> n >> m;

	cout << "������� �������� �������";
	
	// �������������� ������������� ������ �� ����� ����� ���������:
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			cout << "mass[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
			answer[i][j] = matrix[i][j];

			cout << endl;
		}

	// �������� � �������:
	ans(n, m - 1);

	// �������� ���������(������� � ������� answer)
	Print(n);

	getch();
	
	return 0;
}
