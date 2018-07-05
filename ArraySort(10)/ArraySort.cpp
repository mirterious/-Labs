#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <stdlib.h>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

struct magaz
{
	char fio[40];
	char adress[30];
	int day;
	int month;
	int year;
	int key;
} Zap;

int size1 = sizeof(magaz);
long len;
FILE *FileZap;
char File_Zap[] = "zapisi.dat";
void Out(magaz);
void Qsort(magaz *a, int begin, int end);

int main()
{
	int option, DescriptorFILE, k, kol, check = 0, d, m, y, keygen, left, right, KY, mid, value;
	double x;
	long length;
	magaz *Array, temp;
	while (true) {
		cout << "\nCreate - 1\nView - 2\nAdd - 3\nTask - 4\nSearch - 5\nSort - 6\nQuickSort - 7\nBinarySearch - 8\nEXIT - 0\n";
		cin >> option;
		switch (option)
		{
		case 1:
			if ((FileZap = fopen(File_Zap, "wb")) == NULL)
			{
				cout << "\nCREATION ERROR";
				return 0;
			}
			fclose(FileZap);
			cout << "\nCreated New File " << File_Zap;
			break;
		case 2:
			if ((FileZap = fopen(File_Zap, "rb")) == NULL)
			{
				cout << "\nOPENING ERROR!";
				return 0;
			}
			while (1)
			{
				if (!fread(&Zap, size1, 1, FileZap)) break;
				Out(Zap);
			}
			fclose(FileZap);
			break;
		case 3:
			FileZap = fopen(File_Zap, "ab");
			cout << "Enter FIO" << endl;
			cin >> Zap.fio;
			cout << "Enter adress" << endl;
			cin >> Zap.adress;
			cout << "Enter date" << endl;
			cout << "Day";
			cin >> Zap.day;
			cout << "Month";
			cin >> Zap.month;
			cout << "Year";
			cin >> Zap.year;
			KY = Zap.year * 10000 + Zap.month * 100 + Zap.day;
			Zap.key = KY;
			KY = 0;
			fwrite(&Zap, size1, 1, FileZap);
			fclose(FileZap);
			break;
		case 4:
			FileZap = fopen(File_Zap, "rb");
			DescriptorFILE = fileno(FileZap);
			length = filelength(DescriptorFILE);
			kol = length / size1;
			Array = new magaz[kol];
			for (int i = 0; i < kol; i++)
				fread((Array + i), size1, 1, FileZap);
			fclose(FileZap);
			for (int i=0; i<kol; i++)
			{
				for (int j = i + 1; j < kol; j++)
				{	
					check = 0;
					if (strlen(Array[i].fio) == strlen(Array[j].fio) && strlen(Array[i].adress) == strlen(Array[j].adress))
					{
						for (int k = 0; k < strlen(Array[i].fio); k++)
						{
							if (Array[i].fio[k] == Array[j].fio[k]) check++;
						}
						for (int m = 0; m < strlen(Array[i].adress); m++)
						{
							if (Array[i].adress[m] == Array[j].adress[m]) check++;
						}
						if (check == (strlen(Array[i].fio) + strlen(Array[i].adress)))
						{
							for (int n=j; n < kol; n++)
							{
								Array[n] = Array[n + 1];
							}
							kol--;
						}
					}
				}
			}
			FileZap = fopen(File_Zap, "wb");
			for (int i = 0; i < kol; i++)
			{
				for (int j = 0; j < 39; j++)
				{
					Zap.adress[j] = Array[i].adress[j];
					Zap.fio[j] = Array[i].fio[j];
				}
				Zap.day = Array[i].day;
				Zap.month = Array[i].month;
				Zap.year = Array[i].year;
				Zap.key = Array[i].key;
				fwrite(&Zap, size1, 1, FileZap);
			}
			fclose(FileZap);
			delete[]Array;
			break;
		case 5:
			FileZap = fopen(File_Zap, "rb");
			DescriptorFILE = fileno(FileZap);
			length = filelength(DescriptorFILE);
			kol = length / size1;
			Array = new magaz[kol];
			for (int i = 0; i < kol; i++)
				fread((Array + i), size1, 1, FileZap);
			fclose(FileZap);
			cout << "Enter date" << endl;
			cout << "Day";
			cin >> d;
			cout << "Month";
			cin >> m;
			cout << "Year";
			cin >> y;
			for (int i = 0; i < kol; i++)
			{
				if (d == Array[i].day && m == Array[i].month && y == Array[i].year)
					Out(Array[i]);
			}
			delete[]Array;
			break;
		case 6:
			FileZap = fopen(File_Zap, "rb");
			DescriptorFILE = fileno(FileZap);
			length = filelength(DescriptorFILE);
			kol = length / size1;
			Array = new magaz[kol];
			for (int i = 0; i < kol; i++)
				fread((Array + i), size1, 1, FileZap);
			fclose(FileZap);
			for (int i = 0; i < kol; i++)
			{
				for (int j = i + 1; j < kol; j++)
				{
					if (Array[i].key > Array[j].key)
					{
						temp = Array[i];
						Array[i] = Array[j];
						Array[j] = temp;
					}
				}
			}
			for (int i = 0; i < kol; i++)
				Out(Array[i]);
			delete[]Array;
			break;
		case 7:
			FileZap = fopen(File_Zap, "rb");
			DescriptorFILE = fileno(FileZap);
			length = filelength(DescriptorFILE);
			kol = length / size1;
			Array = new magaz[kol];
			for (int i = 0; i < kol; i++)
				fread((Array + i), size1, 1, FileZap);
			fclose(FileZap);
			left = 0;
			right = kol - 1;
			Qsort(Array, left, right);
			for (int i = 0; i < kol; i++)
				Out(Array[i]);
			delete[]Array;
			break;
		case 8:
			FileZap = fopen(File_Zap, "rb");
			DescriptorFILE = fileno(FileZap);
			length = filelength(DescriptorFILE);
			kol = length / size1;
			Array = new magaz[kol];
			for (int i = 0; i < kol; i++)
				fread((Array + i), size1, 1, FileZap);
			fclose(FileZap);
			for (int i = 0; i < kol; i++)
			{
				for (int j = i + 1; j < kol; j++)
				{
					if (Array[i].key > Array[j].key)
					{
						temp = Array[i];
						Array[i] = Array[j];
						Array[j] = temp;
					}
				}
			}
			x = Array[kol / 2].key;
			cout << "Enter date" << endl;
			cout << "Day";
			cin >> d;
			cout << "Month";
			cin >> m;
			cout << "Year";
			cin >> y;
			keygen = y * 10000 + m * 100 + d;
			left = 0;
			right = kol;
			while (1)
			{
				mid = (left + right) / 2;
				if (keygen < Array[mid].key)      
					right = mid - 1;     
				else if (keygen > Array[mid].key)  
					left = mid + 1;	  
				else
				{
					Out(Array[mid]);
					break;
				}
				if (left > right)
				{
					cout << "Didn't found" << endl;
					break;
				}
			}
			delete[]Array;
			break;
		case 0:
			return 0;
		default: 
			cout << "Wrong Input" << endl;
			break;
		}
	}
}
void Out(magaz z)
{
	cout << z.fio << " " << z.adress << " " << z.day << "." << z.month << "." << z.year << endl;
}
void Qsort(magaz *a, int begin, int end)
{
	int left, right, x;
	left = begin;
	right = end;
	magaz temp;
	x = a[(left + right) / 2].key;
	do 
	{
		while (a[left].key < x)  left++;
		while (x < a[right].key) right--;
		if (left <= right) 
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) Qsort(a, begin, right);
	if (left < end) Qsort(a, left, end);
}