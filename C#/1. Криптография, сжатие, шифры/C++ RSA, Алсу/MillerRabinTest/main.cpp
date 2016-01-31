#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
#include <iomanip>

using namespace std;


        // ����������� �������� �������
        void ��������������������������(long a, long b, long *x, long *y, long *d)
        {
            long q, r, x1, x2, y1, y2;

            if (b == 0)
            {
                *d = a;
                *x = 1;
                *y = 0;
                return;
            }

            x2 = 1;
            x1 = 0;
            y2 = 0;
            y1 = 1;

            while (b > 0)
            {
                q = a/b;
                r = a - q*b;
                *x = x2 - q*x1;
                *y = y2 - q*y1;
                a = b;
                b = r;
                x2 = x1;
                x1 = *x;
                y2 = y1;
                y1 = *y;
            }

            *d = a;
            *x = x2;
            *y = y2;
        }

        long ���������������������(long a, long n)
        {
            long x, y, d;
            ��������������������������(a, n,&x, &y, &d);

            if (d == 1) return x;

            return 0;

        }

// ������� ��� ��������� ���� ����� x,y �� ������ m
long long mulmod(long long x,long long y, long long m)
{
    return (x*y)%m;
}

// ������� ���������� ����� x � ������ � �� ������ n
long long powmod(long long x,long long a,long long m)
{
        long r=1;
        while(a>0)
        {
                if(a%2!=0) 
                   r=mulmod(r,x,m);
                a=a>>1; 
                x=mulmod(x,x,m);
        }
        return r;
}

// ������� ����� �������-������
bool test_Miller_Rabin(long long m, long long a) {		
       if(m==2 || m==3)
             return true;

       if(m % 2 == 0 || m == 1){
             return false;
       }
	   // ������� �� ������� ����� ������� ������

       long long s = 0;
       long long t = m-1;
       long long x=0;
	   long long y=0;

	   // ������� ���������� ������� ������
       while(t!=0 && t % 2 == 0){
             s++;
             t/=2;
       }

				// ���������� �������� �� ���������� � ������� �� ������ 'n'
                long r = 1;
                x = (long)powmod(a, t, m);
                if (x == 1 || x == m - 1)
                    return true;

                x = (long)powmod((long)pow(a,(double)t), (long)pow(2.0, r), m);

                if (x == 1)
                    return false;
            
                if (x != m - 1)
                    return false;
            
            return true;
}

        // ������� ��������, ���������� ���� �������-������
        bool ���������������������������������(long i)
        {
            // �������� �� �� 2� ���������� 'a', � �� 10! �.�. ��� ������ ��������� - ��� ������ �������� ����� �� �������� long[] massA = new long [11];
            // ������ ��������� '�' �� 2 �� 10
            for (long a = 2; a < i && a < 11; a++)
            {
                // ��������� ����
                bool b = test_Miller_Rabin((long)i, (long)a);// �������� ����� � ���������
                if (!b)
                {
                    return false;
                }
            }
            return true;
        }

		        // �������� ������� �����
        long ��������������������()
        {
            long �����=0;
            bool isCorrect = false;
            // ���� ������ ������ �����
            while (!isCorrect)
            {
				cout<<"������� ������� �����:";
				cin>>�����;
                //����� = (long)rand();
                if (���������������������������������(�����))
                {
					break;
                }
				else
					cout<<"��������� ����� �� �������!"<<endl;
            }
            return �����;
        }


		        // �������� ����� RSA
        void ����RSA(long p, long q, long *code, long *decoded)
        {
            // �������� ������ ��������������� ��������� 'm'
            cout<<"������� ��������� = "<<endl;
			char message[1000];
            cin>>message;

            // ��������� ��������� 'e'
			int a[3];
			a[0]=17;
			a[1]=257;
			a[2]=65537;//{ 17, 257, 65537 }
			long e = a[rand()%3];// ���� �� 3� ������� ����� �����

            // ��������� ����� 'm' �������� ������ �����
			// ��������� ���������:
			string result="";
			long n = p * q;
			for(int i=0; message[i]; i++)
			{
				result +=(char) powmod((int)message[i], e, n);
			}
			printf("������������� ��������� = %s",result);
            /*long n = p * q;
            *code = powmod(m, e, n);
            *//*cout<<"\n���� ����� 'm' �������� ������ �����(e,n) = " << *code<<endl;
*/

            // ����������
            // ������ ������� ��������� 'd' - �������� ���� ����
            //long fn = (p - 1) * (q - 1);
            //long d = ���������������������(e, fn);
            //if (d < 0) d = fn + d;
            //*decoded = powmod(*code, d, n);
            //cout<<"����������� ����� 'm' �������� ������ ����(d,n) = " << *decoded<<endl;

            //// ������� � ������� ���������
            //if (*decoded == m)
            //    cout<<"\n����� ����� �������� � ����������� �������!"<<endl;
            //else
            //{
            //    cout<<"\n�������� �����������!"<<endl;
            //}
        }


int main()
{
	setlocale( LC_ALL,"Russian" );// ����� ��������� ����� �� ������� �����
	ofstream fout("mytest.txt",ios::out);

			 // 2 ������� ����� � ��������� �� 1 �� 10 ���
            long p=0, q=0;

            // ���� ������ ������� �����
            p = ��������������������();
            // ���� ������ ������� �����
            q = p;
            while(q==p)
                q = ��������������������();

            // ������� ���������� ��������� - 2 ������� �����. ���� ��� ������������� �������, �� �� ������ ���������
            cout<<"������� �����: 'p' = "<<p<<"; 'q'="<<q<<endl;

            long code=0;
            long decoded=0;
            ����RSA(p,q,&code, &decoded);
            

			getch();

			return 0;			
}