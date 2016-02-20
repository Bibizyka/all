
// ���� ��� ����� �������-������
int A[] = { 2,3,5 };

// ������� ��� ��������� ���� ����� x,y �� ������ m
long long mulmod(long long *x, long long *y, long long *m)
{
	return ((*x)*(*y)) % (*m);
}

// ������� ���������� ����� x � ������ � �� ������ n
long long powmod(long long x, int a, long long *m)
{
	long long r = 1;

	while (a > 0)
	{
		if (a % 2 != 0)
			r = mulmod(&r, &x, m);
		a = a >> 1;
		x = mulmod(&x, &x, m);
	}

	return r;
}

// ������� ����� �������-������
bool test_Miller_Rabin(long long *m, int *a) {
	if (*m == 2 || *m == 3)
		return true;

	if (*m % 2 == 0 || *m == 1) {
		return false;
	}
	// ������� �� ������� ����� ������� ������

	long long s = 0;
	long long t = *m - 1;
	long long x = 0;
	long long y = 0;

	// ������� ���������� ������� ������
	while (t != 0 && t % 2 == 0) {
		s++;
		t = t >> 1;
	}

	x = powmod(*a, t, m);

	if (x == 1 || x == *m - 1)
		return true;

	// ���� B: s-1 ���
	for (int j = 0; j<s - 1; j++) {
		x = powmod(x, 2, m);

		if (x == 1)
			return false;

		if (x == *m - 1)
			return true;
	}

	return false;
}



// ������� ��������, ���������� ���� �������-������
bool ����������������������������(long long *number)
{
	for (int i = 0; i < 3; i++)
	{
		// ��������� ����
		if (!test_Miller_Rabin(number, &A[i]))
		{
			return false;
		}
	}
	return true;
}