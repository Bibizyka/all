#include "TimeManager.h"

TimeManager::TimeManager(){
}


TimeManager::~TimeManager(){
}

void TimeManager::run(callback func)
{
	// ������ ������
	clock_t start_at = clock();

	func();

	// ����� ������
	clock_t finish_at = clock();

	// ������� ���������
	float diff = (float)finish_at - (float)start_at;

	printf("Time: %f milliseconds\n", diff);
}
