#pragma once

//����� ������� ����������� �� ���������� � �������� � ��������
ref struct PanelParameters{//��������� ��������� ������ ������
	double xmin,xmax,ymin,ymax;
	int W,H;//������ � ������ ����
public:PanelParameters(double xmin, double xmax,double ymin,double ymax,int W,int H){//����������� ,����������� ��� �������� �����
	   this->xmin=xmin;
	   this->xmax=xmax;
	   this->ymin=ymin;
	   this->ymax=ymax;
	   this->W=W;
	   this->H=H;
	   }
};


namespace Convertation{//� ����� ��+++ ���� ����� ��������� ����������,����� ��� �� �����������,�����-�� ����

ref class Converter{
protected:
	PanelParameters^pp;//������������ ���� ������,����� ��������������� �����,������...
	
public:
	Converter(void);//��� ������������
	Converter(PanelParameters^p);
	int XtoPx(double x);//�� ���������� � ��������
	int YtoPy(double y);
	double PxtoX(int X);//��� ��������
	double PytoY(int Y);

};
}