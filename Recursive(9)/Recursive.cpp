#include <iostream>
using namespace std;

int fibonacci(int n) 
{ 
	int a = 1; 
	int b = 1; 
	int sum = 0; 
	if (n == 2 | n == 1){ 
		sum = 1; 
		} 
	for (int i = 3; i <= n; i++) { 
		sum = a + b; 
		a = b; 
		b = sum; 
		} 
	return sum;
}

int fibonacci_R(int n)
{
	if (n<0) return 1;
	if (n==0 | n==1) return n;
	else
		return fibonacci_R(n-1)+fibonacci_R(n-2);
}

int main()
{
	int k;
	cout << "Enter K" << endl;
	cin >> k;
	cout << fibonacci(k) << " " << fibonacci_R(k) << endl;
	system("pause");
	return 0;
}