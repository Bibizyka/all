#include <iostream>
#include <conio.h>
using namespace std;


int main ()
{
	int a,b,d,n;
cin >> n >> a >> b;//������ ������ �� ������� ������, ��� ��������� �������� 4,2,4
	d=(b-a);
	
	n=n-2;//������ �������� ��������� ��� ���������� a&b

	while (n>0 && (b-a)==d)//�������
{
	a=b;
	cin >> b;
	n=(n-1);//���������� n ����������	���������� ���������� ���������
}
if (n==0) 
cout << "YES";
else cout << "NO";

return 0;

}