#include<fstream>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<algorithm>

;
int initialize();
int Choise();
void Read(Scalenum &sc, ifstream &rd);
void Write(Scalenum sc, ofstream &wr);

	int Initialize()//������� ������� ���������:
        {
            cout<<"������� ��������� ������� ���������:"<<endl;
            int  t;
			cin>>t;

            return t;
        };

	int Choice()//����� ��������:
        {
            cout<<"������� ����� ��� ��������:"<<endl;
            cout<<"1 - ��� ������������ ���� �����;"<<endl;
            cout<<"2 - ��� ��������� ���� �����;"<<endl;
            cout<<"3 - ��� ���������� ������� �� �������;"<<endl;
            cout<<"4 - exit(�����)."<<endl;
			int t;
			cin>>t;
            return t;
        };

	void Read(Scalenum &sc, ifstream &rd)//���������� ����� �� �����:
        {//sc - ����� � ������� ���������;rd - �������� ����� ������ ���������
			int t;
			rd>>t;
            sc = Coding(t, sc.q);
        };


	void Write(Scalenum sc, ofstream &wr)//����� ������ � ����� 
        {//sc - �����;wr - �������� ����� � ������� ����������
            wr<<"������������� ����� � ���������� �������:" << Decoding(sc)<<endl;//10-����� ������� ���������
            wr<<"������������� ����� � q-����� ������� ���������:\r\n" << sc.ToString()<<endl;//q-����� ������� ���������
        };