#include <stdio.h>
//#include <math.h>
#include <fstream>
#include <conio.h>

// ������� �������� - ���������, �����
// ����� ���� ������� ����������� �������
const int nA = 3;
const int nB = 3;

int* Merger(int *A, int *B, int* C) {
	for (int i = 0, j = 0; i < nA || j < nB;) {
		// ���� ���� �� �������� ������� �� ����� - ��� ������ �� �������
		if (i == nA) {
			C[i+j] = B[j];
			j++;
			continue;
		}
		else if (j == nB) {
			C[i+j] = A[i];
			i++;
			continue;
		}

		// ���� �������� ���������, ���������� ��� � C ���������������
		if (A[i] == B[j]) {
			C[i+j] = A[i];
			i++;
			C[i+j] = B[j];
			j++;
		}
		else if (A[i] > B[j]) {
			C[i+j] = B[j];
			j++;
		}
		else {
			C[i+j] = A[i];
			i++;
		}
	}

	return C;
}

int main() {
	setlocale(LC_ALL, "Russian");// ����� ��������� ������� ���� � �������

	// ����������� �������
	int A[nA];
	int B[nB];
	int C[nA+nB]; // ���� ��������� ��������� �������

	// ��������� �������
	printf("������� ������ A �� 3 ���������:\n");
	for (int i = 0; i < nA; i++)
		scanf("%i", &A[i]);

	printf("������� ������ B �� 3 ���������:\n");
	for (int i = 0; i < nB; i++)
		scanf("%i", &B[i]);

	// ������� �������
	int* Cnew = Merger(A, B, C); 
	printf("��������� �������:\n");
	for (int i = 0; i < nA+nB; i++) {
		printf("%d ", Cnew[i]);
	}

	_getch();
	return 0;
}