
//#pragma comment (lib,"mpfr.lib")
//#pragma comment (lib,"mpir.lib")

#include <stdio.h>
#include <conio.h>
#include <string>
#include <time.h>

#include <thread>
#include <chrono>
#include <future>
#include <mutex>

#include <iostream>
#include <fstream>
#include <math.h>

#include <boost/math/special_functions/log1p.hpp>
#include <boost/math/special_functions/pow.hpp>
#include<boost\multiprecision\cpp_int.hpp>
#include<boost\any.hpp>

using namespace boost::multiprecision;
using namespace std;

//#include "mpreal.h"
#include "functions.h"
#include "miller-rabin.h"
#include"primegen.h"

#include"official_algorithm.h"
#include"exhaustive_search.h"
#include"mult_simples_pq.h"

#include"ThreadsMikhail.h"

// ������������ uint1024_t: 2*179769313486231590772930519078902473361797697894230657273430081157732
//675805500963132708477322407536021120113879871393357658789768814416622492
//847430639474124377767893424865485276302219601246094119453082952085005768
//838150682342462881473913110540827237163350510684586298239947245938479716
//304835356329624224137216

// ������������ uint128_t: 2*340282366920938463463374607431768211456

// ������������ uint64_t: 2*18446744073709551616


// ������������ ���������� �������. ����� ����� ����� ���� � ����������
int THREADS_COUNT = 0;

// ������������ ���������� ���������� �������� �������
const int MAX_THREADS_COUNT = 100;

// ������
thread THREADS[MAX_THREADS_COUNT];

void some_function() {

	srand(_Xtime_get_ticks());

	std::this_thread::sleep_for(std::chrono::seconds(rand() % 10));
}

int main() {
	
	setlocale(LC_ALL, "Russian");// ����� ��������� ����� �� ������� �����
	// const int digits = 50;// 4096;
	// mpreal::set_default_prec(mpfr::digits2bits(digits));
	// mpf_set_default_prec(4096);

	// ���������� ����
	int NUM_CORES = thread::hardware_concurrency();
	// ���������� �������
	THREADS_COUNT = NUM_CORES;
	
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

	// ����������� �������, ������� ��������� ������������� �����: �����, ������� �������� ������������� ���� ������� ����� 'p' � 'q', �� �������� ���� �������-������ �� 	���� 'A'
	// exhaustive_search_run(FOUT_FILES, COMPLETED_THREADS, THREADS_COUNT, THREADS);// ������ �������
	// mult_simples_pq_run(FOUT_FILES, COMPLETED_THREADS, THREADS, THREADS_COUNT); // ����� ������ �������, ����� �� ������������� ������� �����
	official_algorithm_run(FOUT_FILES, COMPLETED_THREADS, THREADS_COUNT, THREADS);// ����������� ��������, �� ���������

	//void(*alias_func);
	//alias_func = some_function;

	ThreadsMikhail 	example;
	example.parallel_by_cores( [] { cout << 123 << endl; }, true);
	example.wait_for_end();

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

