#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<string.h>

using namespace std;

char* MyInsert(char *myString, char *subString, int N)
{
	// 1) �������� ������ �������� strlen(myString) + strlen(subString) + 1
	int Size, Size3;
	Size = strlen(myString) + strlen(subString) + 1;
	Size3 = strlen(myString) - N;
	char *returnChar = new char[Size];
	char *temp = new char[Size3];

	// 2) �������� ���� ����� ������ myString �� ������� n - 1
	strncpy(returnChar, myString + 0, N);
	returnChar[N] = '\0';

	// 3) �������� ���� subString
	strcat(returnChar, subString);

	// 4) �������� ���� ����� myString �� ������� n �� �����
	strncpy(temp, myString + N, strlen(myString) - N);
	temp[strlen(myString) - N] = '\0';
	strcat(returnChar, temp);

	return returnChar;
}


int main()
{
	setlocale(LC_ALL, "rus"); // ���������� ����������� ���������

	// ������ ������ ��� ������ � ����
	ofstream fout; /*��� �������*/; // ������ ������ ofstream	
	// ������ ��� ����������
	ifstream fin;

	// ��������� ���� ��� ������ � ����������� �����
	fin.open("text.txt");
	int length = 1000;
	
	// ������� � ���� ���������
	fout.open("result.txt");

	// ������ ������ ����� �����
	int k = 0;
	cout << "������� ���������� ������� � �����:" << endl;
	cin >> k;

	char* str = new char[length]; // ����� �������������� �������� ������������ �� ����� ������
	
	// ��������� ��-������� ��� ����
	while (!fin.eof())
	{
		fin.getline(str, length);// ��������� �����
		
		// ��������� ����� ���� � ����������� ������� "K", � ���� ��� ��� - �� ��������� ����� ����� ALSOU 
		char *s = "AEIOUYaeiouy";// ��� �������
		char *stroka = "ALSOU";
		int n = 0;// ������� ���������� ������� � �����
		int i = 0;
		while (str[i] != '\0')
		{
			// ���������� ������� ���� �� ������� �����(�� ������� ������ ����� - ������� ����� ���������)
			n = 0;
			while (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
			{
				// ��������� - �������� �� ���?
				for (int j = 0; j<12; j++)
				{
					if (str[i] == s[j])
						n++;
				}

				i++;
			}

			// ���������� ������� ����� "K" - �� ��������� ALSOU
			if (n == k)
			{
				str = MyInsert(str, stroka, i);
				i += 5;// �������� ������� �� 5(����� ����������� ��������)
			}

			i++;
		}

		i = 0;
		while (str[i] != '\0')
		{
			// ������� � ������� � � ����
			cout << str[i];
			fout << str[i];
			i++;
		}
		cout << endl;
		fout << endl;
	}

	fout.close();
	fin.close();

	cout << endl << "��������� � ����� result.txt"<<endl;

	system("pause");
	return 0;
}