#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

// �������� �� ������� ����� �� ��� ��� ��������� �����( �� 2 �� ����� �� ����� �����).
// ���� ������� - �� ����� ������� �����. ��! �� �������� �� ������ ������, �� ���� �������� ������ �������� ����� � ����� 2: 1,3,5,7,9 � �.�.
bool ����������������������������������������(long long *number) {
	long long s = sqrt(*number) + 1;

	// ��� ������ ������������� ������ �����, �.�. ��� �� ������� �� ���
	for (long long i = 3; i <= s; i += 2) {
		if ((*number) % i == 0) {
			return false;
		}
	}

	return true;
}

// ��������� ������� ������ simples ����� �������� ������� ����� start � finish - ���������. ������� ���� ���������� ���������� ������� ����� � ������ - ��� ��������� ������� ����� � ������� simples
long long getCountSimples(long long start, long long finish, long long *simples) {
	long long index = 0;

	for (long long j = start; j < finish; j += 2) {
		if (j % 2 != 0) {

			if (����������������������������������������(&j)) {
				simples[index] = j;
				index = index + 1;
			}
		}
	}

	return index;
}


// ����� �������� � ����
void printValue(long long *i, FILE *fout) {

	fprintf(fout, "%lld \n", *i);
}

// �������� ������, �������� flush ��� �������� � ��� �������������� ������. ���� �� ����, �������.
void closeFiles(FILE **FOUT_FILES, int THREADS_COUNT) {

	for (int j = 0; j <= THREADS_COUNT; j++) {
		fclose(FOUT_FILES[j]);
	};
}

// �������������� ����� ��� ������ ����������. ������ ��� ����� - ����� ������ ������. ����� �� ��������� ������������ ��������.
// ����� ��������� ���� �� ������������ ���� ���� ��� ���� �������, �� ������ � ���������� �������� ����� ����� ���������-��������� ��������. ������� - ��������.
// ��������� ������ ����� �������� ��� ������ ���������.
void initFiles(FILE **FOUT_FILES, int THREADS_COUNT) {

	char tmp[20];

	for (int j = 0; j < THREADS_COUNT; j++) {

		string name = std::to_string(j) + ".txt";
		strcpy(tmp, name.c_str());

		FOUT_FILES[j] = fopen(tmp, "w");
	}

	FOUT_FILES[THREADS_COUNT] = fopen("stats.txt", "w");
}