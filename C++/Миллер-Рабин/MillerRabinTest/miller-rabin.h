
// ���� ��� ����� �������-������
uint128_t A_uint128_t[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
int A_int[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

const int A_LENGTH = 2;// ����������� ����� ����

cpp_int FOR_THREADS[100];

/*
// ������� ��� ��������� ���� ����� x,y �� ������ m
uint128_t mulmod(uint128_t *x, uint128_t *y, uint128_t *m, int *current_index)
{
	FOR_THREADS[*current_index] = (*x);
	FOR_THREADS[*current_index + 1] = (*y);
	FOR_THREADS[*current_index + 2] = FOR_THREADS[*current_index] * FOR_THREADS[*current_index + 1] % (*m);
	return FOR_THREADS[*current_index + 2].convert_to<uint128_t>();;
}

// ������� ���������� ����� x � ������ � �� ������ n
uint128_t powmod(uint128_t x, uint128_t a, uint128_t *m, int *index_j)
{
	uint128_t r = 1;
	int current_index = (*index_j) * 3;

	while (a > 0)
	{
		if ( a % 2 != 0 )
			r = mulmod(&r, &x, m, &current_index);
		a = a >> 1;//  1;
		x = mulmod(&x, &x, m, &current_index);
	}	

	return r;
}
*/


// ������� ����� �������-������ - �� [2,3] ��� [2,3,5]
bool LABS_TEST_MILLER_RABIN_uint128_t( uint128_t *m, int a_length ) {
	
	int s = 0;
	uint128_t t = *m - 1;
	uint128_t two = 2;

	// ������� ���������� ������� ������
	while (t != 0 && t % 2 == 0) {
		s = s + 1;
		t = t >> 1;
	}

	bool flag = false;
	uint128_t x = 0;

	bool isBreaked = false;
	for (int i = 0; i < a_length; i++)
	{
		x = powm(A_uint128_t[i], t, *m);
		//x = powmod(A[i], t, m, index_j);

		if ( x == 1 || x == *m - 1 ) {
			flag = true;
			continue ;
		}

		isBreaked = false;
		// ���� B: s-1 ���
		for (int j = 0; j < s - 1; j++) {
			x = powm(x, two, *m);
			//x = powmod(x, two, m, index_j);

			if (x == 1)
				return false;

			if (x == *m - 1) {
				flag = true;
				isBreaked = true;
				break;
			}
		}
		if( !isBreaked )
			flag = false;
	}

	return flag;
}

