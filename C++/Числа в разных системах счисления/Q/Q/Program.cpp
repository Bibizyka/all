#include<fstream>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include"ScalenumFunctions.h"
;
#include"Visualisation.h"


;
int main()
{
			
	setlocale(LC_ALL, "Russian");//����� ������������� ������� �����

			ifstream rd("numbers.txt");
			ofstream wr("result.txt");

            int q = Initialize();//�������� ������� ��������� � ������� ��������
            Scalenum scl(q);
            Scalenum scl1(q);
            int n = 0;
            while (n != 4)
            {
                n = Choice();//�������� ����������� ��������
                if (n != 5)//���� �� ������� �����
                {
                    Read( scl, rd);
                    Read( scl1, rd);
                    
					wr<<"������ �����:"<<endl;
                    Write(scl, wr);
                    
					wr<<"������ �����:"<<endl;
                    Write(scl1, wr);
                    
					switch(n)//��������� ��������� ��������
                    {
                        case 1:
                        {
                            Scalenum s;
							s= scl+scl1;
                            wr<<endl<<"���������:"<<endl;
                            Write(s, wr);
                        }
                        break;
                        case 2:
                        {
                            Scalenum s = scl*scl1;
                            wr<<endl<<"���������:"<<endl;
                            Write(s, wr);
                        }
                        break;
                        case 3:
                        {
                            Scalenum s = scl%scl1;
                            wr<<endl<<"���������:"<<endl;
                            Write(s, wr);
                        }
                        break;
                    }
                }
            }
			//��������� ������
			wr.close();
			rd.close();
	return 0;
}
