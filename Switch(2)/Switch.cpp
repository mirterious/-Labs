#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, x, y, z, function;
	cout << "Input a: ";
	cin >> a;
	cout << "Input z: ";
	cin >> z;
	if (z < 1)
		x = pow(z, 2);
	else x = z + 1;
	int b;
	cout << "Choose function: \n1 - 2x \n2 - x^2 \n3 - x/3" << endl;
	cin >> b;
	switch(b) 
	{
	case 1: function = 2 * x;
		break;
	case 2: function = pow(x, 2);
		break;
	case 3: function = x / 3;
		break;
	}
	y = a * log(1 + pow(x, 1 / 5)) + pow(cos(function + 1), 2);
	cout << "Result: " << y << endl;
    return 0;
}