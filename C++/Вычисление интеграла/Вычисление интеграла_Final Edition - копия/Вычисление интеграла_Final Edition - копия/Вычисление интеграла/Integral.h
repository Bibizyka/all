#pragma once
#include "FunctionPainter.h"

ref class Integral//����� ��������
{

	double minlim;//������ � ������� ������� ��������������
	double maxlim;

public:
	Integral(double min,double max);//�����������
	

	String^CalcK(String^ a);//�����,������� ������� �������� ��������� � ���������� �������� � ������
	
};
