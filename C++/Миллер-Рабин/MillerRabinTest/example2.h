
#include <thread>

// ������� �2 - ��������� ������������ ���� ������� ����� �� ��������� ������� simples.
// ��������, ������ �������� ��� ������� ����� �� 3 �� 1��� - �� ������� ������������ ������������ ���������� ����� leftBorder � rightBorder(�.�. � ������) - 
// � ������� ��������� �������� ������ �������-������ ����� � ����. ���� ��� ���������, � �������� ��������!
void threadFunctionRun2(long long leftBorder, long long rightBorder, long long maxCount, long long * simples, FILE *fout)//atomic<bool>& ab)
{
	long long multResult = 0;
	long long j = 0;
	long long p = 0;
	long long q = 0;

	for (long long i = leftBorder; i < rightBorder && i < maxCount; i++) {

		p = simples[i];

		if (p > 0) {

			for (j = leftBorder; j < maxCount; j++) {
				q = simples[j];

				if (q > 0) {
					multResult = p*q;

					if (����������������������������(&multResult)) {
						printValue(&multResult, fout);
						simples[j] = -1;
					}
				}
			}
		}

	}
}


// �������, ������� ��������� ��� ������� ����� � ���������� �� start �� finish � ������� ������� threadFunctionRun1
void run2(FILE **FOUT_FILES, atomic<bool> *COMPLETED_THREADS, thread * THREADS, int THREADS_COUNT) {

	// ������������ ���������� ������� �����. �� ��������� ����� ������� ������� ���������������� ����������
	long long max_count_simples = 100000; // 10000000 => 1400156 ������� �����
	long long *simples = new long long[max_count_simples];

	// ������� ���������� ������� �����
	long long count_simples = getCountSimples(3, max_count_simples, simples);
	long long step = count_simples / 20;

	for (int i = 0; i < count_simples; i++) {
		long long a = simples[i];
	}

	double koef = 1 + 1 / (double)(THREADS_COUNT * 3);
	int j = 0;

	printf("����������: �� %lld, ������� ����� �����: %lld, ������������ ����� = %lld\n\n", max_count_simples, count_simples, simples[count_simples - 2]);
	fprintf(FOUT_FILES[THREADS_COUNT], "����������: �� %lld, ������� ����� �����: %lld, ������������ ����� = %lld\n\n", max_count_simples, count_simples, simples[count_simples - 2]);

	for (long long i = 0; i < count_simples; ) {

		// ���� �������������� �������. ���� ����� ����������� - �� ��������� ��� ������� �� ������������ ������ ����������
		for (j = 0; j < THREADS_COUNT && i < count_simples; j++) {

			if (COMPLETED_THREADS[j] == true) {

				if (i + step > count_simples) {
					step = count_simples - i;
				}

				COMPLETED_THREADS[j] = false;
				fflush(FOUT_FILES[j]);

				if (THREADS[j].joinable()) {
					THREADS[j].join();
				}

				THREADS[j] = thread([&COMPLETED_THREADS, &FOUT_FILES, count_simples, &simples, i, step, j] {
					threadFunctionRun2(i, i + step, count_simples, simples, FOUT_FILES[j]);
					COMPLETED_THREADS[j] = true;
				});

				printf("������� %d ����� �� ���������� [%lld - %lld)\n", j, i, i + step);
				i += step;

				// �.�. ������� �������� ��� ������� �����, ��� ������ ��������������� ����� - ��������� ���������� step, ����� � ������ ������ ������ "������ �� ������"
				if (step > 3000) {
					step = (step) / (koef);
				}
			}
			else {

			}
		}
	}
}

