#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int Array[10];
	cout << "Input values of array\'s elements (10)" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> Array[i];
	}
	int max = Array[0], min = Array[0], indexmax = 0, indexmin = 0, result = 1;
	cout << "Array: ";
	for (int i = 0; i < 10; i++)
		cout << Array[i] << " ";
	for (int i = 0; i < 10; i++)
	{
		if (Array[i] > max)
		{
			max = Array[i];
			indexmax = i;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (Array[i] < min)
		{
			min = Array[i];
			indexmin = i;
		}
	}
	cout << "\n" << "Max element: " << max << ";\nIndex of Max " << indexmax << ";\nMin element " << min << ";\nIndex of Min " << indexmin << "." << endl;
	if (indexmax > indexmin)
	{
		for (int i = indexmin; i < indexmax - 1; i++)
		{
			result *= Array[i + 1];
		}
	}
	if (indexmax < indexmin)
	{
		for (int i = indexmax; i < indexmin - 1; i++)
		{
			result *= Array[i + 1];
		}
	}
	cout << "Result: " << result << "." << endl;
    return 0;
}