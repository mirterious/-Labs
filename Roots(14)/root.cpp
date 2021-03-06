#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

const double eps = 1*10e-9;

double Function(double x)
{
	return 4 * x - 7 * sin(x);
}

double Derivative(double x)
{
	return 4 - 7 * cos(x);
}

double Task(double x1, double x2)
{
	double delta;
	do
	{
		x2 = x1 - Function(x1) / Derivative(x1);
		delta = fabs(x2 - x1);
		x1 = x2;

	} while (delta >= eps);
	cout << "Func = " << Function(x1) << endl;
	return x1;
}



int main()
{
	double x1 = -2, x2 = 2, result = 0, temp;
	double step = 0.01; 
	int n = (fabs(x1) + fabs(x2)) / step + 1; 
	double Lb = x1; 
	double Rb = Lb + step; 
	double *L = new double[n];  
	double *R = new double[n]; 
	for (int j = 0; j < n; j++) 
	{
		L[j] = 0;
		R[j] = 0;
	}
	int count = 0; 
	for (int i = 0; i < n; i++) 
	{
		if (Function(Lb)*Function(Rb) < 0) 
		{
			L[count] = Lb;
			R[count] = Rb;
			count++;
		}
		Lb += step;
		Rb += step;
	}
	int last = 0;
	for (int i = 0; i < n; i++)
	{
		if (L[i] == 0 && R[i] == 0) 
		{
			last = i;
			cout << "Last=" << i << endl;
			break;
		}
		cout << "L" << i + 1 << "=" << L[i] << "\t";
		cout << "R" << i + 1 << "=" << R[i];
		cout << endl;
	}
	for (int i = 0; i < last; i++)
	{
		cout << Task(L[i], R[i]) << endl;
	}
	return 0;
}