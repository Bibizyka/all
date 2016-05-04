#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <thread>
#include <future>
#include <fstream>
#include <vector>
#include <algorithm>

enum MOVE
{
	NORTH = 0,
	WEST = 1,
	SOUTH = 2,
	EAST = 3
};

class Point {
public:
	int x = -1; // ����������
	int y = -1;
};

// ����� �����
class Cell:Point {
public:
	int ballNumber = -1;// ������������ �������� �����������: ���� ������������� �����, �� ��������� �� ����� ������, ����� - ��� ������� ������
};

class Ball:Point {
public:
	int number = -1;

	Ball(int number) {
		this->number = number;
	};

	bool CanMove(int moveType) {


		return true;
	}
};

// ������ � ����� �� �����������, ����� ����������� ��������

std::mutex locker;

// ������ �����
int SIZE = 0;
int COUNT = 0;

// ������
std::vector <Ball> balls(0);

// ������������ � �������������� ������� ������-����. �.�. ����� ������: ���� �����������, �� ������� ������, ���� �������������, �� ������� �����
std::vector<std::pair<int, std::vector<int>>> vertical_borders(0);
std::vector<std::pair<int, std::vector<int>>> horizontal_borders(0);

// �����, ������ ���� ����, ������ - ������������ ����� ������ ������.
std::vector<std::pair<int, std::vector<Cell>>> cells(0);

void BuildFrom( char * fileName) {
	std::ifstream fin;// ���� ��� ������
	fin.open( fileName ); // ��������� ������ � ������
		
	fin >> SIZE;	
	fin >> COUNT;
		
	int x0, y0, x1, y1;

	// ��������� ������
	for (int i = 0; i < COUNT; i++) {
		fin >> x0 >> y0;
		
		Ball ball( i );
		ball.x = x0;
		ball.y = y0;

		balls.push_back( ball );
	}
	
	// ������� �����
	for (int i = 0; i < COUNT; i++) {
		fin >> x0 >> y0;

		Cell cell;
		cell.x = x0;
		cell.y = y0;

		cell.ballNumber = i;
		
		// ������ ����, ���� �� ����������. �� ������ ����������������, ��� �� �����.
		int k = 0;
		for (; k < cells.size; k++) {
			if ( cells[ k ].first == y  ) {
				break;
			}// pass
		}

		if ( cells.size <= k ) {
	
			// ���� ����� �� ����� - ������ ���������, ������ ����� ������ ������ ���
			std::pair<int, std::vector<Cell >> newPair;

			newPair.first = y;
			newPair.second = std::vector<Cell>(0);

			newPair.second.push_back(cell);

			continue;
		}
		
		int j = 0;

		// � ��� ��� ��������������� ������� ������ �������� ������
		for (; j < cells[k].second.size; j++) {
			if (x0 > cells[k].second[j].x) {
				break;
			} // pass
		}

		// ���������� �������!
		cells[k].second.insert(cell ����� j-��);
	}
		
	// ��������� �������
	while (!fin.eof()) {

		fin >> x0 >> y0;// ��������� ������ ������ ������ �� �������
		fin >> x1 >> y1;

		// ��������� ������������
		if ( y0 == y1 ) {
			
			for(int i=0; i<vertical_borders.size; i)
			
		}
		// ��������� ��������������
		else if ( x0 == x1 ) {

		}
		else {
			throw "error";
		}


		// ����� �������� ���������� - �� �������� ������
	}
}

void Init() {

}

void Solve() {

}

int main() {
	
	try
	{
		BuildFrom("input.txt");


		printf("%i\n", &balls.size);
		
		printf("%i\n", &cells.size);
	}
	catch (const std::exception& error)
	{
		printf("������ � ������ �����: %s", (&error)->what());
	}
	

	return 0;
	system("pause");
}
