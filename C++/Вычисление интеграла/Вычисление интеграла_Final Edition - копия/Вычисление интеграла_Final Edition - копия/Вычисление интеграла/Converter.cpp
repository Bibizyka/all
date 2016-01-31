#include "Converter.h"
using namespace Convertation;

Converter::Converter(void){//����������� 
	pp = gcnew PanelParameters(-1,1,-1,1,500,500);//��������� �� ���������
}

Converter::Converter(PanelParameters^ p){//������ �����������
	if(p->xmin>=p->xmax) p->xmin = p->xmax-1;//�������� �������� ������� ��� ������ ��������� � ������ � ������ ���� ������ ����
	if(p->ymin>=p->ymax) p->ymin = p->ymax-1;
	if(p->W<=0) p->W = 500;
	if(p->H<=0) p->H = 500;
	pp=p;//��� ����������� ���� ������ ��� ��� ��������
}

int Converter::XtoPx(double x){//��������� �� ��������� � ����������
	if (x<pp->xmin){//������ ���,����� ���� ��� �� ����� � ������� ������� ������,�������� ���,����� �� ���� �� �����
		x=pp->xmin-1;
	}
	if(x>pp->xmax){//�� �� �����
		x=pp->xmax+1;
	}
	return  (x-pp->xmin)*pp->W/(pp->xmax-pp->xmin);//���������,������� ��������
}


int Converter::YtoPy(double y){//�� �� ����� � �
	if (y<pp->ymin){
		y=pp->ymin-1;
	}
	if(y>pp->ymax){
		y=pp->ymax+1;
	}
	
	return (pp->ymax-y)*pp->H/(pp->ymax-pp->ymin);
}


double Converter::PxtoX(int X){//��� ��������
	if(X<0) X=-1;//�� �� �����,��� � ��� ��������� ��������
	if(X>pp->W) X=pp->W+1;
	
	return pp->xmin+X*(double)(pp->xmax-pp->xmin)/pp->W;
}


double Converter::PytoY(int Y){
	if(Y<0) Y=-1;
	if(Y>pp->H) Y=pp->H+1;
	return pp->ymax-Y*(double)(pp->ymax-pp->ymin)/pp->H;
}