#include "Integral.h"
#include <time.h>
#include <stdlib.h>
#include"PolandStr.h"
#include"Expression.h"
#include<iostream>
using namespace std;
using namespace System::Threading;//��� ������ ���
using namespace System::Threading::Tasks;


Integral::Integral(double min,double max){//����������� � �����������
	minlim=min;
	maxlim=max;
	
}

String^Pervoobr(String^ s){     //������� ������������� ��������  
	String^r=")";//� ������ ��������� � ������
	String^r1="(";
	r1=r1+s;//������
	s=r1;//������ ��������� � ����� ��� � ������
	s=s+r;//��� ��� �����
	String^k="";//������� ������ ������,����� ������������� ���� ��������
	for(int i=0;i<s->Length;i++){//�� ����� ��������� ����,���� �������������
		if(isdigit(s[i])&&(s[i+1]=='+'||s[i+1]=='-'||s[i+1]==')')&&!(s[i-1]=='^')){//���� �����,��������� �� ���
		k=k+s[i]+"*x";
		}
		else{
			if((isdigit(s[i])||s[i]=='*'||s[i]=='/')&&!(s[i-1]=='^')){//���������,�������
				k=k+s[i];
		}
			else{if(s[i]=='x'&&(s[i+1]=='+'||s[i+1]=='-'||s[i+1]==')')){//���
				k=k+s[i]+"*x/2";
			}
			else{
				if(s[i]=='x'&&s[i+1]=='^'){//��� � �����-�� �������
					k=k+s[i]+"^"+s[i+2]+"*x/"+"("+s[i+2]+"+1)";//���� ��� � ��������,�� ��������� � ��� � ���� �������� �� ���
				
				}
				else{
					if(s[i]=='+'||s[i]=='-'){//������ ���� ����������,������ ����� ����
					k=k+s[i];
					}
					else{
						}
					   }
					   }
				       }
				       }
	                   }
	return k;//����������
	                  }
		

String^Integral::CalcK(String^ a){//����� ������������ �������������
	/*{��������������}*/
	String^perv=Pervoobr(a);//� ���������� � ������������� 
	PolandStr^�����������=gcnew PolandStr(perv);//��� ������� ��������� � �������� ������,���� �������,������� ������ ������ �������� ������
	String^ pols=�����������->GetPolandStr();//����������� �� �����-�� �����
	Expression^znach=gcnew Expression(pols);//������� ������ ������ ��������
	double verh=znach->Calculate(maxlim);//������ � ������ ������ �������������� 
	double vniz=znach->Calculate(minlim);
	Double integral=verh-vniz;//�������� 

	return integral.ToString();//��������� ������� � ������
}

