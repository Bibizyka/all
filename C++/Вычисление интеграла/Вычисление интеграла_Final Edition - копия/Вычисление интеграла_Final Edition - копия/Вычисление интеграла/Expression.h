#pragma once
using namespace System;
using namespace System::Collections;



ref class Expression//�����
{
	String^ s;//������,� ������� ����� ���������
	ArrayList^ vars;//������ ����������
public:
	Expression(String^ str);//�����������
	bool FindVars();//���� ����������
	double Calculate(double x);//������� ��������
	ArrayList^ GetVars();//���������� ������ ��������
	
	bool IsCorrect();//��������� ������������
	String^ GetS();//���������� ������
};

