// ����� �������
#include <iostream>
#include <conio.h>

using namespace std;

int Rec(int N)
{
	int p = 1;
	for (int i = 1; i <= N; i++)
		p = p*i;
	return p;
}

int main()
{
	int N;
	// ������� ���� ����� N
	cout << "Vvedite N = ";
	cin>> N;

	// ������� ���������:
	cout<< "Recursia (2*N)! = "<< Rec(2 * N);

	_getch();
	return 0;
}