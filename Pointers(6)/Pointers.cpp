#include <iostream>
#include <conio.h>
#include <stdio.h>

int main(){
	double **a, *b;
	int i,j,m,n,s;
	puts("Input array size");
	scanf("%d%d", &n, &m);
	//Выделение памяти для массивов
	a = new double *[n];
	b = new double [j];	
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			a[i]=new double [m];
		}
	}
	//Ввод и вывод массива А
	puts("Input element values");
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			scanf("%lf", &a[i][j]);
		}
	}
	puts("Matrix A");
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			printf("%3.0lf%c", a[i][j], j==m-1? '\n':' ');
		}
	}
	//Проверка нулевых элементов
	for (j=0; j<m; j++){
		for (s=i=0; i<n; i++){
			if (a[i][j]==0) s++;
				if (s==n) b[j]=0;
				else b[j]=1;
		}
	}
	//Выводы матрицы В
	puts("Vector B");
	for (j=0; j<m; j++){
			printf("%3.0lf", b[j]);
	}
	//Освобождение памяти
	delete []a;
	delete []b;	
	return 0;
}