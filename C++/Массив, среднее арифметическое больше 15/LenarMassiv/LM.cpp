
#include <iostream>
#include <conio.h>
#include <fstream>//����� ��� �����������
#include <math.h>//��� �������������� ������� - ���������� �����
#include <iomanip>// ������������ - ��� ���������� ������.
using namespace std;

void BiggerThen(int chislo)
	{
	//1.
		//�������� ���������� ��������� � ����� input.txt
		//��������� ����
		ifstream in("input.txt");
		int kol=0;
		int safe[100];
		while (!in.eof()) 
		{
			in>>safe[kol];
			kol++;
		}
		in.close();//��������� �������� ����
		
		cout << "Kolichestvo chisel = "<<kol<<"\n"; 

	//2.
		//������ ��� ���������� ������
		int n = sqrt((double)kol);
		int mass[100][100];

		//�������� �� ����� ������
		int schet=0;
		for(int j=0; j<n; j++)
		{
			int i=0;
			while (i<n)
			{
				mass[j][i]=safe[schet];
				schet++;
				i++;
			}    
		}

		//������� � ������� ��� ������!
		cout<<"\n Vidod massiva: \n";
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{			
				cout<<setw (3)<<mass[i][j]<<" ";
			}
			cout<<"\n";
		}

		//������� ������� ��������������
		//��� ������ � ����!
		ofstream out_file("output.txt");

		int sred=0;//��� �������� �������� ���������������.
		
			for(int i=0; i<n; i++)
			{
				int sum=0;
				for(int j=0; j<n; j++)
				{			
					sum=sum+mass[i][j];
				}
				sred=sum/n;
				if (sred>chislo) {out_file << i <<" ";} ;//�������� ������ ������. � �.�.
			}
		


		out_file.close();//��������� �������� ����
	};

int main()// ������ ����� "� �����".
{
	

	//�������� ��������� - ������� �����, ������� ������ ������ ����� - 15, �� ������� ������
	BiggerThen(15);




	
	_getch();
	return 0;
}