
// ������� �1: ���� ����� �������� �������� �� ���� �������-������, �� �� �������� �������(�� ����������������������������������������) - �� ������� ��� � ����
void thread_function_exhaustive_search(uint64_t  start, uint64_t  finish, uint64_t  maxCount, uint64_t*numbers, mutex*locker, FILE *fout, vector<uint128_t> *spps)//atomic<bool>& ab)
{
	if (start % 2 == 0) 
		start = start + 1;

	for (uint64_t  i = start; i < finish; i+=2 ) {

		if (LABS_TEST_MILLER_RABIN_uint64_t( &i, 1 ) ) {

			if ( !SimpleDivisionTest( &i ) || !LABS_TEST_MILLER_RABIN_uint64_t( &i, 9 ) ) {

				if (FIRST_SIMPLES[COUNT_FIRST_SIMPLES - 1] < i) {

					locker->lock();

					printValue_uint64_t(&i, fout);

					locker->unlock();
				}// pass
			}// pass
		}// pass	
		
	}
}

// �������, ������� ��������� ��� ����� � ���������� �� start �� finish � ������� ������� threadFunctionRun1 
void exhaustive_search_run() {

	// ������������ ���������� ������� �����. �� ��������� ����� ������� ������� ���������������� ����������
	uint64_t  max_count_numbers = 10000;
	uint64_t  *numbers = NULL;

	//fprintf(FOUT_FILES[THREADS_COUNT], "����������: �� %lld, ������� ����� �����: %lld, ������������ ����� = %lld\n\n", max_count_simples, count_simples, simples[count_simples - 2]);
	std::atomic<bool> * is_completed_threads = NULL;
	FILE *f = NULL;

	ThreadsManager 	example;
	fprintf(example.FOUT_FILE, "����������: ��� ����� �� 2 �� %lld\n", max_count_numbers);
	printf("����������: ��� ����� �� 2 �� %lld\n", max_count_numbers);

	uint64_t  step = max_count_numbers / 30;

	example.parallel_by_cores(is_completed_threads, f, max_count_numbers, numbers, step, 3000, thread_function_exhaustive_search);
}
