#include "Expression.h"
#include <math.h>

Expression::Expression(String^ str)//���������� ���������
{
	s = str;//������ �� ������� ���������
	vars = gcnew ArrayList;//������ ����������
}
bool Expression::FindVars(){//�����,������� ���� ����������
	vars->Clear();//�������,���� ���-�� ����
	bool b = false;//������� ���������� �������� ������� �� ���
	array <String^>^ arr = s->Split(' ');//��������� ������ �� ��������	
	for each (String^ s in arr){	// ��� ������ ������ � ���� ������� �������� ������������� �� � �����		
		try{
			double k = Double::Parse(s);
		}
		catch(...){//���� �� �� ����� ����-�� �� �����,������ � ��� ���� ���������� �����-��
			if(s!="+"&&s!="-"&&s!="*"&&s!="/"&&s!="^"&&s!=""&&s!="x"&&s!="-x"){
				b = true;//��,��� ����
				String^s1;//������� ����� ������ ��1
				if(s[0]!='-'&&s[0]!='+')s1 = s;//���� ������ ������ �� ����  � �� ����,�� ��1 ����� ��
				else s1 = s->Remove(0,1);//����� �� ���� ������ ����� ��� ���� �������
				if(!vars->Contains(s1))vars->Add(s1);//���� ���������� � ������ �� ����,�� ��������� �� � ������ ����������
			}
		}
		
	}	
	return b;
}

double Expression::Calculate(double x){//��������� �������� ����� ��������� �� ���������� ���
	String^ str = s->Replace("x",x.ToString());//�������� ��� ��������� ��� �� �� ��������
	array<String^>^ symb = str->Split(' ');//����� ��������� �� �������� ������
				 Stack^ st = gcnew Stack;//� ���� ����� �������� �������� ��������
				 double a,b;//����� �����
				 double k;
				 for(int i=0;i<symb->Length;i++){//���������,����� ��� ������ ������ �� ���
					 if(symb[i]->Length>1&&symb[i][0]=='-'&&symb[i][1]=='-')symb[i]=symb[i]->Remove(0,2);
					 if(symb[i]->Length>1&&symb[i][0]=='+'&&symb[i][1]=='+')symb[i]=symb[i]->Remove(0,2);
					 if(symb[i]->Length>1&&symb[i][0]=='-'&&symb[i][1]=='+')symb[i]=symb[i]->Remove(1,1);
					 if(symb[i]->Length>1&&symb[i][0]=='+'&&symb[i][1]=='-')symb[i]=symb[i]->Remove(0,1);
					if(String::Compare(symb[i],"")){//���� �� ������ ������ 
					 try{
						 k = Double::Parse(symb[i]);//�������� ������������� � �����
						 st->Push(k);//� �������� �� �������
					 }
					 catch(...){//���� ��� �� �����
						 int count = st->Count;//���-�� ��������� � ������
						 if(count)//���� ��� �� 0,�� �� ������� ������� ������� �����
						 a = (double)st->Pop();	//��� ��� �������
						 count = st->Count;//����� ������� ���-�� ��������� � �����
						 if(count){//���� �� 0,������� ��� ���� �������
						b = (double)st->Pop();//��� ��� ��� ��� � ����
						 }
						 			 
							 else break;//���� ���� 0,�� �����������
						if(symb[i]=="+"){//��������� ��������
							
							st->Push(a+b);
						}
						if(symb[i]=="-"){
							
							st->Push(b-a);
						}
						if(symb[i]=="*"){
							
							st->Push(a*b);
						}
						if(symb[i]=="/"){
							try{
							st->Push(b/a);
							}
							catch(...){
								return 0;
							}

						}
						if(symb[i]=="^"){							
							st->Push(pow(b,a));
						}
						 
					 }
					}
				 }
				 int con = st->Count;//������� ���-�� ��������� �����
				 if(con!=1)throw "er";//���� �� 1,�� ������
				
				double ans = (double)st->Pop();//���� ���� �������,�� ��� �������� �� �����
				return ans;//���������� �����
}
ArrayList^ Expression::GetVars(){//������ ��������� ������ ���������
	return vars;
}


	
		
bool Expression::IsCorrect(){//��������� ������������ ���������
	array<String^>^ symb = s->Split(' ');//��������� �� �������
	int kol=0;//�������� ���������� ��������� �����
	for each(String^ s in symb){//��� ������ ������ �������,���� �� ��������� ���� ��������,�� �� ��� ���������,���� ���-�� ������,�� �����������
		if(s=="+"||s=="-"||s=="*"||s=="/"||s=="^")
			kol--;
		else if(s!="") kol++;
	}
	if(kol==1) return true;//���� ��� =1,�� ��� �����
	else return false;
}
String^ Expression:: GetS(){//������ ���������� ������
	return s;
}
