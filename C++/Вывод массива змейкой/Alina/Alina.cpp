#include <iostream>//������� ������ �����. ������� ������ ��������, ������ ���� N-������! (������� ��� ��������� ������� � ��������)
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
	const int N=100;
	const int M=100;
	 int a[N][M];
	 int n=4,u;
	/*cout<<"Vvedite chetnuyu razmernost' massiva"<<endl;
		cin>>n;*/
	u=n*n;
	cout<<"Zmeika: vvedite chislo elementov = "<<u<<": "<<endl;//���������� �� ��������� ������� ��� ���������� �������.
	
	for (int j=0; j==0  ; )//������ �������.
	{
		for (int i=0;i<n;i++)
		{
			cin>>a[i][j];
		}
		j++;
	}

	for (int j=1; j<n-1 ; j++)//��������e ��������� ����������� ����� ���������� �������.
		for (int i=1;i<n;i++)
		{
			cin>>a[i][j];
		}

	//��� ������� n:
	for (int j=n-1;j==n-1 ; )//��������� �������.
	{
		for (int i=n-1; i>0; i--)
		{
			cin>>a[i][j];
		}
		j--;
	}

	for (int i=0; i==0 ; )//������ ������ ��� �������� � ������� a[0][0].
	{
		for (int j=n-1;j>0;j--)
		{
			cin>>a[i][j];
		}
		i++;
	}

	cout<<"Zmeika:"<<endl;
	//������� ������:
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout<<setw(4)<<a[i][j];
		}
		cout<<endl;
	}
	getch();
return 0;
}