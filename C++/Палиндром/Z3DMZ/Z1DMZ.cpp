#include <iostream>//�������� ������ �� �������������� ��� ������� ������������� ��� ������� ������ ��������. ������ ���� ����� �������.
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

char s[100];
int main()
{
	srand(time(NULL));
	int n,k=0,m=0,l;

	cout<<"Vvedite stroku: "<<endl<<endl;
	cin.getline(s,100);//������ ������
	n = strlen (s);//������ � �����.
	
	cout<<"Vivod stroki: "<<endl;//��� ������������ ������� ������.
	for (int i=0; i<n; i++)
	{
		cout<<s[i];		
	}
	cout<<endl;

	for (int i=0; i<n; i++)// ��������� ���������� ��������.
	{
		if (s[i]==' ') m++;		
	}

	l=n-m;

	for (int i=0, j=n-1; i<=j; i++, j--)//�������� �� ��������������.
	{
		if (s[i]==' ')
		{
			while (s[i]==' ')
				{
					i++;		
				}
		}
		if (s[j]==' ')
		{
			while (s[j]==' ')
				{
					j--;		
				}
		}
		if (s[i]==s[j]) k++;
	}
	cout<<endl;

	//����� � ��������������:
	if (n%2==0)
	{
		if ((l/2)==k) cout<<"Stroka palindrom";
			else cout<<"Stroka NE palindrom";
	}
	else 
	{
		if (n%2==1)
		{
			if (((l/2)+1)==k) cout<<"Stroka palindrom";
			else cout<<"Stroka NE palindrom";
		}
	}
	getch();
	return 0;
}