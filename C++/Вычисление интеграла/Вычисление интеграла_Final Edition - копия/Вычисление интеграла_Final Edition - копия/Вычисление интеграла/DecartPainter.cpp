#include "DecartPainter.h"

#include "math.h"

using namespace System::Drawing;

using namespace Convertation;


DecartPainter::DecartPainter(void)//����������� �� ���������,���� �����������
{
	pp = gcnew PanelParameters(-1,1,-1,1,500,500);	
}

DecartPainter::DecartPainter(PanelParameters^p){
	pp=p;//���������� � ���� ������
}

void DecartPainter::PaintAxes(Graphics^ g){//������ ���,�����,��� �������� ��������� ������
	Pen^p = gcnew Pen(Color::Black,1);//�����
	Converter^ con = gcnew Converter(pp);//������� ���������
	int x0 = con->XtoPx(0);//��� ���������� ������
	int y0 = con->YtoPy(0);

	g->DrawLine(p,0,y0,pp->W,y0);//������ ������ ���� ����� �����
	g->DrawLine(p,x0,0,x0,pp->H);

	g->DrawLine(p,x0-4,10,x0,0);//������ ������ ���������
	g->DrawLine(p,x0,0,x0+4,10);

	g->DrawLine(p,pp->W-10,y0+4,pp->W,y0)//������ ���������
	g->DrawLine(p,pp->W,y0,pp->W-10,y0-4);
}

void DecartPainter::PaintDiv(Graphics^ g){//����� PaintDiv ������ ������� ����� 0.1
	Pen^p = gcnew Pen(Color::Black,1);//�����
	PanelParameters^ tmp = gcnew PanelParameters(pp->xmin*10,pp->xmax*10,pp->ymin*10,pp->ymax*10,pp->W,pp->H);//������� ����� ��������� ���� ��� � 10 ��� ����������� ����� ������ � ������
	
	Converter^ con = gcnew Converter(tmp);//������� ���������
	int ed = con->XtoPx(1)-con->XtoPx(0);//��������� ������� �� ������
	int x0 = con->XtoPx(0);//���������� �����
	int y0 = con->YtoPy(0);
	Font^ fnt = gcnew Font("Cambria", 12);//�����,���� � ������
	Brush^br = gcnew SolidBrush(Color::Black);//�����
	for(int x = 10*pp->xmin+1;x<10*pp->xmax;x+=1){//����,������� ������ �������
		int px = con->XtoPx(x);//��� �������� �������� ���� ��������� � �������� ����������
		if(x%10==0){//���� ��� ������� �� 10,�� �� ������ ������� �����
			
			g->DrawLine(p,px,y0-6,px,y0+6);	//������ ������� �����		
			System::String^ s=((double)x/10).ToString();//��������� � ������ ��� �������� �� 10
			if(x>0){//����� ����� �������� ����� � ������� ����					
				g->DrawString(s,fnt,br,px-8,y0+5);
				}
			else {
				g->DrawString(s,fnt,br,px-12,y0+5);//���� ������ ���� ����� ������ ������
			}
		}
		else if(x%5==0){//���� ������� �� 5,�� �� ������ ������� ��������
			
			g->DrawLine(p,px,y0-3,px,y0+3);
		}
		else{
			g->DrawLine(p,px,y0-1,px,y0+1);//������ ������ �������� �������� 0.1
		}

	}

	for(int y = 10*pp->ymin+1;y<10*pp->ymax;y+=1){// �� �� ����� ������ ��� �
		int py = con->YtoPy(y);
		if(y%10==0){
			
			g->DrawLine(p,x0-6,py,x0+6,py);			
			System::String^ s=((double)y/10).ToString();
			if(y>0){					
				g->DrawString(s,fnt,br,x0-20,py-8);
				}
			else if(y<0){
				g->DrawString(s,fnt,br,x0-25,py-8);
			}
		}
		else if(y%5==0){
			
			g->DrawLine(p,x0-3,py,x0+3,py);
		}
		else{
			g->DrawLine(p,x0-1,py,x0+1,py);
		}

	}

}
	