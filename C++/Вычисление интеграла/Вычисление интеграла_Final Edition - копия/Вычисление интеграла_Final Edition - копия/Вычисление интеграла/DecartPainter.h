#pragma once
#include "Converter.h"
using namespace System::Drawing;

ref class DecartPainter//������ ��� � ������ �� ����
{
protected:
	PanelParameters^ pp;
public:
	DecartPainter(void);
	DecartPainter(PanelParameters^p);
	void PaintAxes(Graphics^g);//��� ������:��� � �������
	void PaintDiv(Graphics^ g);

};

