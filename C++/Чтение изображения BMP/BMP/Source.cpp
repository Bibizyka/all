#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>// ��� calloc
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <Windows.h>


#pragma pack(push, 2)
struct BmpHeader {
	unsigned char b1, b2; // ������� BM (2 �����)
	unsigned long size; // ������ ����� (4 �����)
	unsigned short notUse1; // (2 �����)
	unsigned short notUse2; // (2 �����)
	unsigned long massPos; // ��������������� ������ ���������� ������� (4 �����)

	unsigned long headerLength; // ������ ����� ��������� (4 �����)
	unsigned long width; // ������ ����������� (4 �����)
	unsigned long height; // ������ ����������� (4 �����)
	unsigned short colorPlaneNumber; // ����� �������� ���������� (2 �����)
	unsigned short bitPixel; // ���/������� (2 �����)
	unsigned long compressMethod; // ����� ������ (4 �����)
	unsigned long massLength; // ������ ������� � ������ (4 �����)
	unsigned long massWidth; // ������ ������� � ������� (4 �����)
	unsigned long massHeight; // ������ ������� � ������� (4 �����)
	unsigned long colorNumber; // ����� ������ ����������� (4 �����)
	unsigned long generalColorNumber; // ����� �������� ������ (4 �����)

} bmpHeader;
#pragma pack(pop)

// � ���� ������ ������� ��� �����(�������
unsigned char* img;


void Change()
{
	int i, j;
	int bytes = bmpHeader.bitPixel / 8;
	int width = (bytes * bmpHeader.width + bytes) & (-4);

	// �������� ��������(X-��� ����� � �.�., �.�. ����� ��������� � ���������� �������� � ��������)
	int x = 100;// ��������� ����� ���������� �����
	int y = 200;// ��������� ����� ���������� ���
	int h = 10;// ������
	int w = 100;// ������
	
	printf("������� ��������� ���������� ��� �� 1 �� %i: ",bmpHeader.width);
	scanf("%i", &x);
	printf("������� ��������� ���������� ����� �� 1 �� %i: ", bmpHeader.height);
	scanf("%i", &y);
	printf("������� ������ �������� ������ �� 1 �� %i:", bmpHeader.width-x);
	scanf("%i", &h);
	printf("������� ������ �������� ����� �� 1 �� %i:", bmpHeader.height-y);
	scanf("%i", &w);
	printf("\n�������� ����: White=1, Red=2, Blue=3, Black=4\n");
	int color = 0;
	scanf("%i", &color);
	int c1 = 0, c2 = 0, c3 = 0;
	switch (color)
	{
	case 1:
		//c = (char)(RGB(255, 250, 250));
		c1 = 255;
		c2 = 250;
		c3 = 250;
		break;
	case 2:
		c1 = 00;
		c2 = 00;
		c3 = 255;
		break;
	case 3:
		c1 = 255;
		c2 = 00;
		c3 = 00;
		break;
	case 4:
		//c = (char)(RGB(00, 00, 00));
		c1 = 00;
		c2 = 00;
		c3 = 00;
		break;
	}

	for (i = x; i < x + w; i++)
		for (j = y; j < y + h; j++)
		{
			*(img + (i*width) + j*bytes) = (char)c1;
			*(img + (i*width) + j*bytes + 1) = (char)c2;
			*(img + (i*width) + j*bytes + 2) = (char)c3;
		};
}

void Create()
{

}


int readBMP(char* path) {
	FILE* file;
	long long i, j, u;
	long long v;
	file = fopen(path, "rb");
	if (file == NULL) return 0;
	fread(&bmpHeader, sizeof(bmpHeader), 1, file);
	if (bmpHeader.b1 != 'B' || bmpHeader.b2 != 'M' || bmpHeader.bitPixel != 24) {
		printf("corrupted file");
		return 0;
	}

	int mx = bmpHeader.width;
	int my = bmpHeader.height;
	int mx3 = (3 * mx + 3) & (-4);
	img = (unsigned char*)calloc(mx3*my, sizeof(char));
	fread(img, 1, mx3*my, file);
	
	// ������ �������
	Change();
	fclose(file);

	return 1;
}


int saveBMP(char* path) {
	FILE* file;
	int i, j;
	file = fopen(path, "wb");
	if (file == NULL) return 0;

	int mx = bmpHeader.width;
	int my = bmpHeader.height;
	int mx3 = (3 * mx + 3) & (-4);
	int filesize = 54 + my*mx3;

	fwrite(&bmpHeader, sizeof(bmpHeader), 1, file);
	fwrite(img, sizeof(char), mx3*my, file);
	fclose(file);
	return 1;
}

int main()
{
	//����� ��������� ������� ����:
	setlocale(LC_ALL, "Russian");

	// ������ ����
	if (readBMP("D:\\1.bmp") == 1) {
		printf("Read!\n");
		// ���� ��������� - ��������� ����
		if (saveBMP("D:\\_1.bmp")==1) {
			printf("Write!\n");
		}
		else
		{
			printf("Write error!\n");
		}
	}
	else
	{
		printf("Read error!\n");
	}


	_getch();
	return 0;
}
