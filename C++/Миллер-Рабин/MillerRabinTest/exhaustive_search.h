
// ������� �1: ���� ����� �������� �������� �� ���� �������-������, �� �� �������� �������(�� ����������������������������������������) - �� ������� ��� � ����
void thread_function_exhaustive_search(uint64_t  start, uint64_t  finish, uint64_t*numbers, mutex*locker, FILE *fout)//atomic<bool>& ab)
{
	if (start % 2 == 0) 
		start = start + 1;

	for (uint64_t  i = start; i < finish; i+=2) {

		if ( LABS_TEST_MILLER_RABIN_uint64_t( &i, A_LENGTH ) ) {

			if (!LABS_TEST_MILLER_RABIN_uint128_t(&i, 9)) {
				locker->lock();
				printValue(&i, fout);
				locker->unlock();
			}
		}
		else {

			//pass	
		}
	}
}

// �������, ������� ��������� ��� ����� � ���������� �� start �� finish � ������� ������� threadFunctionRun1 
void exhaustive_search_run() {

	// ������������ ���������� ������� �����. �� ��������� ����� ������� ������� ���������������� ����������
	uint64_t  max_count_numbers = 1000000;
	uint64_t  *numbers = NULL;

	//fprintf(FOUT_FILES[THREADS_COUNT], "����������: �� %lld, ������� ����� �����: %lld, ������������ ����� = %lld\n\n", max_count_simples, count_simples, simples[count_simples - 2]);
	std::atomic<bool> * is_completed_threads = NULL;
	FILE *f = NULL;

	ThreadsManager 	example;
	fprintf(example.FOUT_FILE, "����������: ��� ����� �� 2 �� %lld\n", max_count_numbers);
	example.parallel(is_completed_threads, f, max_count_numbers, numbers, max_count_numbers/10, 3000, thread_function_exhaustive_search);
}
