#include <iostream>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <string>

#include <time.h>

#include <thread>
#include <chrono>
#include <future>
#include <mutex>

#include"primegen.h"
#include"example1.h"
#include"example2.h"

using namespace std;


// ������������ ���������� �������. ����� ����� ����� ���� � ����������
int THREADS_COUNT = 0;

// ������������ ���������� ���������� �������� �������
const int MAX_THREADS_COUNT = 100;

// ������
thread THREADS[MAX_THREADS_COUNT];

// ������� �������� ��������� ������ �������
void waitEnding(atomic<bool> *COMPLETED_THREADS) {

	printf("\n\n�������� ���������� ��� ���������� �������");
	for (int j = 0; j < THREADS_COUNT; j++) {
			
		if (THREADS[j].joinable()) {

			THREADS[j].join();
			printf("\n�������� ����� %d", j);
		}
		else {

			printf("\n�������� ����� %d", j);
		}
	}
}


int main() {
	
	setlocale(LC_ALL, "Russian");// ����� ��������� ����� �� ������� �����
		 
	// ���������� ����
	int NUM_CORES = thread::hardware_concurrency();
	// ���������� �������
	THREADS_COUNT =  NUM_CORES;
	
	// �������� �����(� ������� ��������� ���������)
	FILE* FOUT_FILES[MAX_THREADS_COUNT];
	// �������������� �����
	initFiles(FOUT_FILES, THREADS_COUNT);
	
	// ������ ������� �������� - ��� �������� ������ �������(������������ � ����������)
	atomic<bool> COMPLETED_THREADS[MAX_THREADS_COUNT];
	// �������, ��� ������ ��� ��������
	for (int j = 0; j < THREADS_COUNT; j++) {
		COMPLETED_THREADS[j] = true;
	}

	fprintf(FOUT_FILES[THREADS_COUNT], "���������� ���� %d\n���������� �������: %d \n", NUM_CORES, THREADS_COUNT);
	
	// ������ ������
	clock_t start_at = clock();

	//run1(FOUT_FILES,COMPLETED_THREADS);
	// ����������� �������, ������� ��������� ������������� �����: �����, ������� �������� ������������� ���� ������� ����� 'p' � 'q', �� �������� ���� �������-������ �� 	���� 'A'
	run2(FOUT_FILES, COMPLETED_THREADS, THREADS, THREADS_COUNT);

	// ���� ��������� ������ ���� �������
	waitEnding(COMPLETED_THREADS);

	// ����� ������
	clock_t finish_at = clock();

	// ������� ���������
	float diff((float)finish_at - (float)start_at);

	fprintf(FOUT_FILES[THREADS_COUNT], "Time: %f milliseconds\n", diff);

	// ��������� �����
	closeFiles(FOUT_FILES, THREADS_COUNT);

	printf("\n\n�����");

	getch();
	return 0;
}

