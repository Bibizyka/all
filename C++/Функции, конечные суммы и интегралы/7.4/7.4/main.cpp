#include <Windows.h>//���������� Win32 API
#include <stdlib.h>
#include <stdio.h>
#include <math.h>//����� ������������ �������, ���������� �����
 
int main(void)
{
	//������ ������� sin � �������
    float x=0,xmin=0,xmax=0;//�������� �������
	//������� ������ �� x
	printf("Xmin=");
		scanf("%f",&xmin);
	printf("Xmax=");
		scanf("%f",&xmax);
	printf("y=cos(x), %f<x<%f\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",xmin,xmax);//��������� �������
	//���������� ���������
    HDC hDC = GetDC(GetConsoleWindow());
	 int x_max, y_max;//������������ �������� ���� ��������
	 int center_x, center_y; //������ ��������
	   x_max = GetSystemMetrics(SM_CXSCREEN)/3;//�������� ��������� ������ � ���������� ������ � ����� �� 3 - ����� ������ � �������
	   y_max = GetSystemMetrics(SM_CYSCREEN)/3;
	   center_x = x_max / 2;//�������� ����� �������
	   center_y = y_max / 2;
	
	   
	//������� ����� - ���� �� ����� �������, ������� � ����� ��������
    HPEN Pen = CreatePen( PS_SOLID, 2, RGB(255, 255, 255));//����� � ����

	//�������� ������� ���������- ������� � �����
    SelectObject( hDC, Pen );//��������� ����� ���� � ������. SelectObject() �������� � �������� ������� (hDC) ����� ����� Pen

	/*
	����� ���������� ����������� GDI-������� ���� Windows ��� ������.
	����� ������������ ��� �������: MoveToEx � LineTo.
	������ ������ ��� ����������� ������������ ������� �� ���������, �������� � ������ ���������,
	� ����� � ������������ �� ������ � ������� ����������. 
	��������� �������� ������ �� ������������ (NULL). 
	�� ��������� ��� OX �������� ����� �������, OY - ������ ����, � ������ ������� � ��������. 
	LineTo() ������ ����� �� ��������� hDC �� ������� ������� ������� � �����, �������� ������ � ������� ����������� ������� ������ (� ��� ��� �����),
	������������� ���������� ����������� ������. 
	*/			// 0-x 85-y
    MoveToEx( hDC, 0, center_y, NULL );
    LineTo( hDC, center_x*2, center_y );
    MoveToEx( hDC, center_x, 15, NULL );
    LineTo( hDC, center_x, center_y*2 );
    
	for (x = xmin; x <= xmax; x += 0.01f ) // O(100,85) - center, 0.01f - ��� ���������
    {
        MoveToEx( hDC, 10*x+center_x, -10*cos(x)+center_y, NULL );//10 - �����-��������
        LineTo( hDC, 10*x+center_x, -10*cos(x)+center_y );
    }


    system("pause");//����� - ����� ����� ���������� ��������� ����� �� �����
    return 0;
}