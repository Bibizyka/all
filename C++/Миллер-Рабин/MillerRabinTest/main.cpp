
// ���.������: ����� 10�16��, �� �.�.��������������� ������ �������� �����, �� ���������� ��������� ����� �� ����� ��� log(3, 10�16��)
const int MAX_FACTORS_COUNT = 33;
const int MAX_BORDER_C = 10000000000000000;
const int MAX_BORDER_C_SQRT = 100000000;

#include <stdio.h>
#include <conio.h>
#include <string>


#include <iostream>
#include <fstream>
#include <math.h>

#include <boost/math/special_functions/log1p.hpp>
#include <boost/math/special_functions/pow.hpp>
#include<boost\multiprecision\cpp_int.hpp>
#include<boost\any.hpp>
#include"primegen.h"

using namespace boost::multiprecision;
using namespace std;

#include "functions.h"
#include "miller-rabin.h"

#include "ThreadsManager.h"
#include "TimeManager.h"

#include "official_algorithm_tuples.h"
#include "official_algorithm_pq_pqr.h"
#include "exhaustive_search.h"
#include "mult_simples_pq.h"



// ������������ uint1024_t: 2*179769313486231590772930519078902473361797697894230657273430081157732
//675805500963132708477322407536021120113879871393357658789768814416622492
//847430639474124377767893424865485276302219601246094119453082952085005768
//838150682342462881473913110540827237163350510684586298239947245938479716
//304835356329624224137216

// ������������ uint128_t: 2*340282366920938463463374607431768211456

// ������������ uint64_t: 2*18446744073709551616


int main() {
	
	setlocale(LC_ALL, "Russian");// ����� ��������� ����� �� ������� �����
		
	TimeManager example;// ��� ������� - ������� ����������� �������

	example.run(official_algorithm_run_pq);// ����������� ��������, �� ���������, ��������� pq - �����
	// example.run( official_algorithm_run_pqr );// ����������� ��������, �� ���������, ��������� pqr, r>q - �����
	// example.run( exhaustive_search_run );// ������ ������� ���� ����� �� ���������� �������
	// example.run( mult_simples_pq_run ); // ����� ������ �������, ����� �� ������������� ������� ����� p � q

	// official_algorithm_run_simpletuples();// ������� �������� ������� �����, ��� �� ��������������
	
	printf("\n\n�����");

	getch();
	return 0;
}

