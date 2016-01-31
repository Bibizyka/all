#pragma once
#include "Converter.h"
#include "DecartPainter.h"
#include "Expression.h"
#include <math.h>

using namespace System::Drawing;//���������� �������,�������




ref class Function//����� �������
{
protected:
PanelParameters^ pp;//��������� ����
Expression^ ex;//�������� ��� ������ 
double inf,sup;//���� ������
public:
	Function(Expression^ ex){//����������� ����������� ���� �� �����-�� ��������
		this->ex = ex;		
		
	}
	double Calc(double x){//������� �������� ������� �� ��������� �,��� ���������
		return ex->Calculate(x);
	}
	void FindInfSup(double xmin,double xmax);//�����,���� ������� � ��������
	double GetSup();//���������� �������� ��������� � ��������
	double GetInf();
};



ref class FunctionPainter:DecartPainter//����������� ������� �� ������
{
protected:
	Function^ p;//���� ������
	
public:
	FunctionPainter(Function^ p,PanelParameters^pan);//�����������
	void DrawFunc(Graphics^ g,double min,double max);//�����,������� ������ �������

};

