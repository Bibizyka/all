#define _CRT_SECURE_NO_WARNINGS
#include "CLogReader.h"
#include <fstream>

// ����� ���� �� � ����� ��������, ��... ������ �������, ����� ���� ����� ���������� ������ � ��������� �����
// � ������ ��� ������� ������� ����������� � ������, ������� �������� � ������� ���. � ���� ������� ������� ��� ��������� ������ ������� � ����.
// ���� �� ������ - �������, ����������, �, ���� ���� ��� �������� ������ - �������� �� ����� 9-b-rinat@rambler.ru . ���������������� �������.
// � ���������, ����� ���������. �� ������ �������� ������� ���, ����� ��� ����� ���������� ���������� ����� �����, ��� ���������� ��������� ��������� �����. ��������� O(n) ������� �������� ��.
// ��: printf - ��� ��, �� �������� ����-�����

// ���.�������, � ���, ��� � �������
// ���������:
// ���������� �����: abc, *abc, ?abc, abc*, abc?, *abc*, ?abc?, *abc?, ?abc*. 
// ������ ���������� �������� ����� ���� ��������� �����
// ������ ���� abc???? - ��������, ��� ������ ���� �������� ������, ������������ � abc � ���������������� ����� �������������� ��������(������� �������������)

// ������������ ������:
// ������, ��� * - ����� ������������������ ��������(������ �� ������ ������������������)
// ������, ��� ? - ���� ���������� ������
// ��� ���� ������������ * === ***..** � ? === ?????..?

// ����������������: ������� ����� � ~40 �� ���������� �� 21~ (��� ����� ������� �������� ***Some* ��� *Some**) - ����� ����� ����� ������ ����� ��� ������.
// ���� ����������� ������� �� 2��

// ������� ��� ������
void ReadTextFile()
{
	CLogReader 	sfText;
	CString		szLine;
	bool		bReturn = false;
	char mass[101];
	
	printf("Path to file or only name of file:\n");
	scanf("%100s", &mass);
	CString path = ((std::string)mass).c_str();
	
	// ���������� �����
	printf("Please, enter filter fo search:\n");
	scanf("%100s", &mass);
	CString filter = ((std::string)mass).c_str();

	// ���� ������ ����������������/�����������:
	if (sfText.SetFilter(filter))
	{
		// ��������� �������� ����
		if (sfText.Open(path))
		{
			std::ofstream fout;// ���� ��� ������
			fout.open("result.txt"); // ��������� ������ � ������

			printf("Result of filtering:\n");
			printf("------------------------------------");
			// ���������� ���� ����� (���� �� ������)
			// ���� ���������� �������� ������ - print :)
			while (sfText.GetNextLine(szLine) != 0)
			{
				// ��������� �� �����
				if (sfText.FilterLine(szLine))
				{
					fout << static_cast<CT2A>(szLine) << "\r\n";	//� ���������� � ����
					printf("%s\r\n",static_cast<CT2A>(szLine));	//� ����������  � �������
				}
			}
			printf("------------------------------------");

			printf("\nResult in file result.txt\n");
			sfText.Close(); // ��������� �������� ����
			fout.close();// ��������� ������ � �����
		}
	}
	else
	{
		printf("Invalid filter!\n");
	}

	
}


int main()
{
	std::string str;
	char tmp[101];
	while (true)
	{
		printf("\nAre you want to filter?(input 1 to YES, 0(or other symbol) for NO)\n");

		scanf("%100s", tmp);
		std::string str = tmp;
				
		if (str != "1")
			break;
		else
		{
			// ������� ������
			ReadTextFile();
		}
	}
	
	system("pause");
	return 0;
}