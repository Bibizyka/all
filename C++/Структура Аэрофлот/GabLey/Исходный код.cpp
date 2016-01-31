#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>//��� ����������� �������� ������. �� � ����� getch()
using namespace std;

/*
���������
-�������� ������ ����������
-����� �����
-��� ��������

-���� �� ����� � ������ ��������
-�������� �������� ������ ���������� � ����� ������� ������ � ����� ���������(���������)
-���� ������ ��� - ������� ��������������� ���������;
*/


int main()
{
	//����� ��������� ������� ����:
	setlocale(LC_ALL, "Russian");

	const int length=10;//����� ��� ���������� �����

	//���������� ��� �������� ������(��� ������):
	const int l_buf=3*length;

	struct AEROFLOT
	{
		char p_nazn[length+1];//�������� ������ ���������� - ���������� ������
		int nomer_reys;//����� ����� - ����� �����
		char type_reys[length+1];//��� �������� - ����. ������
	};
	
	const int l_aeroflot=100;//��� ������� ��������,�������� � �����

	AEROFLOT aeroflot[l_aeroflot];

	//�������� ������ ��� ������:
	char buf[l_buf+1];
	char p_nazn[length+1];

	//����� ��� ������ � �����:
	ifstream fin("aeroflot.txt");

	//���� ����� �� ����������:
	if(!fin){cout<<"���� �� ����������!"; return 0;};;

	int i=0;//������� ���������� ������
	//��������� ������ �� ����� � ������ ��������:
	while(fin.getline(buf, l_buf))//���� ����� ��������� ����������
	{
		if(i>=l_aeroflot){cout<<"������� ����� ������. ��������� �������� ���������� l_aeroflot!"<<endl; return 1;};;
		
		strncpy(aeroflot[i].p_nazn,buf,length);
		aeroflot[i].p_nazn[length]='\0';
		
		aeroflot[i].nomer_reys=atoi(&buf[length]);//��������� �� ������� char � ����� ����� int

		strncpy(aeroflot[i].type_reys,buf+2*length,length);//�������� � ������ ������� 2*length �� ����� length
		aeroflot[i].type_reys[length]='\0';
		
		i++;
	}

	//������ ���� ���������
	while(true)
	{
		cout<<"������� ����� ���������� ��� end(��� ����������): ";
		gets(p_nazn);
		int kol=1;//������� ��� ���������� ������ �� ����� ������
		if (strcmp(p_nazn,"end")==0) break;//����� �� ����� ����� ������ "end"

		int not_reys=1;//1 - ����� ���, 0 - ���� ����������(����)
		
		
		for(int j=0; j<i; j++)
		{
			//���� ������ ���� � ������ ������
			if(strstr(aeroflot[j].p_nazn,p_nazn))
			{
				//���� ����� ������ ���������� � ����� ������ - ������, ������, ���� ���� ��������� � ���� ������
				if (aeroflot[j].p_nazn[strlen(p_nazn)]==' ')
				{
					cout<<kol<<") "<<aeroflot[j].p_nazn<<" "<<aeroflot[j].nomer_reys<<" "<<aeroflot[j].type_reys<<endl;
						kol++;
					//���� ���� ���� - �������, ��� �� ����������
					not_reys=0;
				}
			}

		}
		//������� "������ ���� �����������", ���� � ������� ������ ��� �� �����
		if(not_reys)
			cout<<"���� �����������!"<<endl;
	}
	

	getch();//��� ��������
	return 0;
}