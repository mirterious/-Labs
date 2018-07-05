#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;

double a, b, c, x=14.26, y=-1.22, z=3.5e-2; //0.564846

int main(){
	a=2*cos(x-PI/6)/(0.5 + pow(sin(y),2));
	b=1+(pow(z,2)/(3 - pow(z,2)/5));
	c=a*b;
	cout << c << endl;
	return 0;
}