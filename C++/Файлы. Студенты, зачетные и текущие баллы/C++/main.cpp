#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

const int N=100;//���������� ��������� �����������

#define DL_FIO 20 /* ����� ���� ��� � ����� */
#define DL_GROUP 10 /* ����� ����  �������� */

struct students2 /* ��������� �������� ��� ������ �������� ����� */
{	
	char fio[DL_FIO]; /* ������� � �������� ��������*/
    unsigned balls1; /*  ����� �� ������� �1 �� ������*/
};

struct students1 /* ��������� �������� ��� ������ �������� ����� */
{	
	char fio[DL_FIO]; /* ������� � �������� ��������*/
	char predmet[DL_FIO]; /* ������� � �������� ��������*/
    unsigned balls1; /*  ����� �� ������� �1 �� ������*/
};

struct students1 stud1[N];
struct students2 stud2[N];

/* ��������� ������� */
void Reading(FILE *f1, FILE *f2);
void SortingByBalls(students1 stud[N],int start, int end);
void SortingByGroup(students1 stud[N],int start, int end);
void SumBalls(students1 stud_1[N], int n, students1 stud_2[N], int m);//���������� �������, ������� ����� ��������������. ��� �������� � �������� � ��������� ������� ������������� � �� �����������(n � m).
//�.�. ��� ���� ������, ����� �� ���������, ��� ������� � ����� �� �����������. �� �� ����� ������������� � ������ ��������� � ��������� �������, �.�.
//��� ����� ���� ������, ����� �� �� ���� �����. ��� ��� �������� �� �����.

/*----------------------*/
/* ������� ������� */
/*----------------------*/
int main()
{
	setlocale(LC_ALL, "Russian");//������� ���� ����� �������������
    FILE *f1, *f2; /* ������ �� ������� ���� */
    
    f1 = fopen("file1.txt", "r");
	f2 = fopen("file2.txt", "r");

    if (f1==NULL)
    {
        puts ("���� file1.txt �� ������! �������� ����!");
        getch();
        return 1;
    };;
	if (f2==NULL)
    {
        puts ("���� file2.txt �� ������! �������� ����!");
        getch();
        return 1;
    };;

	//��������� ������ �� ������ � ��������� ��� ������. �� ��� �������
	Reading(f1,f2);

	//���������� ������ � �������
    fclose(f1);
	fclose(f2);

	system("pause");//�����
    return 0;
}
/*--------------------------------------*/
/*������ �� ������
/*--------------------------------------*/
void Reading(FILE *f1, FILE *f2)
{
    int n = 0, m = 0; /*����� ������� ���������� ��������� � �������� ������� � ���������*/
    
	//���������� � ������� ��������� stud1, stud2 ������ �� ������(�������� �� ������)	
	cout<<"������ ���� � �������� �������:"<<endl;
	while (fscanf (f1, "%s %s %u", stud1[n].fio, stud1[n].group, &(stud1[n].balls)) != EOF) {
		cout << n+1 << ". " << stud1[n].fio<<" "<< stud1[n].group << " " <<stud1[n].balls<<endl;
		n++;
	}
	cout<<endl<<"������ ���� � ��������� �������:"<<endl;
	while (fscanf (f2, "%s %s %u", stud2[m].fio, stud2[m].group, &(stud2[m].balls)) != EOF) {
		cout << m+1 << ". " << stud2[m].fio<<" "<< stud2[m].group << " " <<stud2[m].balls<<endl;	
		m++;
	}
	//��������� ���������� ����� ������ �� ������m(1�� ����) � �� ������(2�� ����)
	//1�� ����
	SortingByBalls(stud1,0,n);//�������� ��������, � ������ �� ����� �����������.
	SortingByBalls(stud2,0,m);//�������� ��������, � ������ �� ����� �����������.
	
	//������� ���������
	cout<<endl<<endl<<endl<<"��������������� 1�� ���� ������ �� ������:"<<endl;
	for(int i=0; i<n; i++)
		cout << i+1 << ". " << stud1[i].fio<<" "<< stud1[i].group << " " <<stud1[i].balls<<endl;	

	//2�� ����
	//������ ��������� �� ������� ������ ���������� ������
	for(int i=0; i<n; i++)
	{
		//���� �� �����, ������� � ����� ������ � ��������� ������ ������
		int start=i;//������ ������
		int end=i+1;
		while(end<n && stud1[start].balls==stud1[end].balls)
			end++;
		if (end-start==1) continue;//�� ����� ������ �����������, ���� 1 �������
		i=end;//��������� ����� ������
		//��������� ������� ���������� ������ ������ �� ������:
		SortingByGroup(stud1,start,end);
	}

	cout<<endl<<endl<<"��������������� 1�� ���� �� ������ � �� ������� ��� ��(���� ���������� ����� - ���������� �� �������):"<<endl;
	for(int i=0; i<n; i++)
		cout << i+1 << ". " << stud1[i].fio<<" "<< stud1[i].group << " " <<stud1[i].balls<<endl;

	//������ ��������� ����� ����� �� ������ ����� � ������������ �������� � ������� ������, ��� ���������� ������ � �������!
	//���� ��������� � ���� file3.txt
	SumBalls(stud1,n,stud2,m);

}


//���������� �� ������ (���������� ������� ��������)
void SortingByBalls(students1 *stud, int start, int end)
{
    for(int i = start; i < end - 1; i++)
    for(int j = 0; j < end - i - 1; j++)
		if(stud[j].balls > stud[j + 1].balls)
		{
            students1 tmp = stud[j];
			stud[j] = stud[j + 1];
			stud[j + 1] = tmp;
		}
}

//���������� �� �������
void SortingByGroup(students1 *stud, int start, int end)
{
    for(int i = start; i < end - 1; i++)
    for(int j = 0; j < end - i - 1; j++)
		if(strcmp(stud[j].group,stud[j + 1].group)>0)
		{
            students1 tmp = stud[j];
			stud[j] = stud[j + 1];
			stud[j + 1] = tmp;
		}
}

//������������ ������� � �������� ������, �� ����� � �������(���������) � � ���� file3.txt
void SumBalls(students1 *stud_1, int n, students1 *stud_2, int m)
{
	//����� ���� �������� ��������������� ����������, �� �.�. �������� ����� ������������� �� ������ ������ � ��������� ������� - ��� �������� � ������
	struct students1 stud3[N];//������� ��������� � ������������� ������
	int kol_stud=0;//����� ������� ���������� ���������, ������� ���� � ����� ������� � � ������� ����������� �����

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			//���� �� ����� �������� �� ��� � ������, �� ��������� �����
			//������� �� ����� ������������� � ����� �����! ��� �������� ������� ���������� ��� ������, �.�. � ������� �������� ������ ���� ���� ���������� ID, �� ����� ���� ���� ��������� � ��������� ����������� ����������
			if(strcmp(stud1[i].fio,stud2[j].fio)==0 && strcmp(stud1[i].group,stud2[j].group)==0)
			{
				//��������� �����
				stud3[kol_stud]=stud1[i];
				stud3[kol_stud].balls+=stud2[j].balls;
				kol_stud++;//�� �������� �������� -> ��������� �������
				break;//������ ������ ������ ���,�.�. ������� � ����� �� ������ ������������� - ��� "�����" ���
			}
		}

	//������� ��������� �� �������(�.�. �������� ����� ��� �� ��� ��������������� ������ ������� �����
	cout<<endl<<endl<<"����� ������ ��������� � ������������� �� ������(������� �����+�������� �����) /n ������������ ����������� �� ��� ���������, ������� ���� � ����� �������:"<<endl;
	//������� ���� ��� ������
	FILE *f; /* ������ �� ������� ���� */
    
    f = fopen("file3.txt", "w");
	
    if (f==NULL)
    {
        puts ("���� file3.txt �� ������! �������� ����!");
        getch();
        return;
    };;
	for(int i=0; i<kol_stud; i++)
	{
		//�������� �� �����
		cout << i+1 << ". " << stud3[i].fio<<" "<< stud3[i].group << " " <<stud3[i].balls<<endl;
		//����������� ������� � ����
		fprintf (f, "%s %s %i\n", stud3[i].fio, stud3[i].group, stud3[i].balls);
	}

	
	fclose(f);
}