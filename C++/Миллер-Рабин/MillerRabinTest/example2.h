
#include <thread>

// ������� �2 - ��������� ������������ ���� ������� ����� �� ��������� ������� simples.
// ��������, ������ �������� ��� ������� ����� �� 3 �� 1��� - �� ������� ������������ ������������ ���������� ����� leftBorder � rightBorder(�.�. � ������) - 
// � ������� ��������� �������� ������ �������-������ ����� � ����. ���� ��� ���������, � �������� ��������!
void threadFunctionRun2(uint64_t  leftBorder, uint64_t  rightBorder, uint64_t  maxCount, uint64_t  * simples, FILE *fout)
{
	uint64_t  multResult = 0;
	uint64_t  j = 0;
	uint64_t  p = 0;
	uint64_t  q = 0;

	for (uint64_t  i = leftBorder; i < rightBorder && i < maxCount; i++) {

		p = simples[i];

		for (j = leftBorder; j < maxCount; j++) {
			q = simples[j];

			multResult = p*q;

			if (����������������������������(&multResult)) {
				printValue(&multResult, fout);
			}
		}
	}
}


// �������, ������� ��������� ��� ������� ����� � ���������� �� start �� finish � ������� ������� threadFunctionRun1
void run2(FILE **FOUT_FILES, atomic<bool> *COMPLETED_THREADS, thread * THREADS, int THREADS_COUNT) {

	// ������������ ���������� ������� �����. �� ��������� ����� ������� ������� ���������������� ����������
	uint64_t  max_count_simples = 100; // 10000000 => 1400156 ������� �����
	uint64_t  *simples = new uint64_t [max_count_simples];

	// ������� ���������� ������� ����� � ��� ������� �����
	uint64_t  count_simples = 0;// getCountSimples(3, max_count_simples, simples);
	getPrimes(simples, &count_simples, 1, max_count_simples, THREADS_COUNT);
	
	uint64_t  step = count_simples / 20;
	
	double koef = 1 + 1 / (double)(THREADS_COUNT * 3);
	int j = 0;

	printf("����������: �� %lld, ������� ����� �����: %lld, ������������ ����� = %lld\n\n", max_count_simples, count_simples, simples[count_simples - 2]);
	fprintf(FOUT_FILES[THREADS_COUNT], "����������: �� %lld, ������� ����� �����: %lld, ������������ ����� = %lld\n\n", max_count_simples, count_simples, simples[count_simples - 2]);

	for (uint64_t  i = 0; i < count_simples; ) {

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

