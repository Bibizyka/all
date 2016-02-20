
#include"functions.h"
#include <thread>
#include"miller-rabin.h"

// ������� �1: ���� ����� �������� �������� �� ���� �������-������, �� �� �������� �������(�� ����������������������������������������) - �� ������� ��� � ����
void threadFunctionRun1(long long start, long long finish, FILE *fout)//atomic<bool>& ab)
{
	if (start % 2 == 0) start++;

	for (long long i = start; i < finish; i++) {

		if (����������������������������(&i) && !����������������������������������������(&i)) {

			printValue(&i, fout);
		}
		else {

			//pass	
		}
	}
}

// �������, ������� ��������� ��� ����� � ���������� �� start �� finish � ������� ������� threadFunctionRun1 
void run1(FILE **FOUT_FILES, atomic<bool> *COMPLETED_THREADS, int THREADS_COUNT, thread * THREADS) {
	// ���������� ������ � ����, ��� ������ �������
	long long start = 3;
	long long finish = pow(10, 12);//12 - ������������� ������� ������� �  1���� �����
	long long step = pow(10, 9);//9

	fprintf(FOUT_FILES[THREADS_COUNT], "%lld to %lld by %lld\n", start, finish, step);

	double koef = 1 + 1 / (double)THREADS_COUNT;
	int j = 0;

	for (long long i = start; i < finish; ) {

		for (j = 0; j < THREADS_COUNT && i <= finish; j++) {

			if (COMPLETED_THREADS[j] == true) {

				COMPLETED_THREADS[j] = false;
				fflush(FOUT_FILES[j]);

				THREADS[j] = thread([&COMPLETED_THREADS, &FOUT_FILES, i, &step, j] {threadFunctionRun1(i + 1, i + step, FOUT_FILES[j]);  COMPLETED_THREADS[j]

					= true; });
				THREADS[j].detach();

				//cout << "�������: " << j << " �� ���������� [" << (i+1) << " - " << (i + step) <<"]"<< endl;
				i += step;

				if (step > 10000000) {
					step = (step) / (koef);
				}
			}
		}
	}
}
