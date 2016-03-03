#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

// �������� �� ������� ����� �� ��� ��� ��������� �����( �� 2 �� ����� �� ����� �����).
// ���� ������� - �� ����� ������� �����. ��! �� �������� �� ������ ������, �� ���� �������� ������ �������� ����� � ����� 2: 1,3,5,7,9 � �.�.
bool ����������������������������������������(uint128_t *number) {
	uint128_t s = *number / 2;// sqrt(*number) + 1;

	// ��� ������ ������������� ������ �����, �.�. ��� �� ������� �� ���
	for (uint128_t i = 3; i <= s; i += 2) {
		if (*number % i == 0 ) {
			return false;
		}
	}

	return true;
}


// ��������� ������� ������ simples ����� �������� ������� ����� start � finish - ���������. ������� ���� ���������� ���������� ������� ����� � ������ - ��� ��������� ������� ����� � ������� simples
/*int1024_t getCountSimples(int1024_t start, int1024_t finish, int1024_t *simples) {
	int1024_t index = 0;

	for (int1024_t j = start; j < finish; j += 2) {
		if (j % 2 != 0) {

			if (����������������������������������������(&j)) {
				simples[index] = j;
				index = index + 1;
			}
		}
	}

	return index;
}
*/

// ����� �������� � ����
void printValue(uint128_t *i, FILE *fout) {
	
	fprintf(fout, "%s\n", boost::lexical_cast<std::string>(*i).c_str());
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


// ��������� ��� ������� �����
uint128_t getNOK(uint128_t *array, int length, int index = 0) {

	uint128_t lcm = (array[index] * array[index + 1]) / gcd(array[index], array[index + 1]);

	if (index + 2  < length) {

		array[index + 1] = lcm;
		return getNOK(array, index + 1);
	}
	else {
		
		return lcm;
	}
}

// ��������� ord �����
uint128_t ord(uint128_t * number) {
	uint128_t value = *number;

	int max_ord = 0;
	int current_ord = 0;

	for (int i = 0; i < value && value != 0; i++) {

		current_ord = 0;

		while ( value % i == 0 ) {
			current_ord++;
			value = value % i;
		}

		if (current_ord > max_ord) {
			max_ord = current_ord;
		}

	}

	return max_ord;
}

