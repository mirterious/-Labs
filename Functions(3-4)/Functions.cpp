#include <vcl.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#pragma hdrstop
#pragma argsused
double module (double Y, double sum){
        double mod=fabs(Y-sum);
        return mod;
}
double sinus (double x){
        double Y=sin(x);
        return Y;
}
double factorial(int k){
        double fact = 1;
        for (int i = 1; i <= k; i++)
                fact *= i;
        return fact;
}
int main(int argc, char* argv[]){
double a, b, x, h, r, sum,Y;
int n,k;
puts("Input a,b,h,n");
scanf("%lf%lf%lf%d", &a, &b, &h, &n);
for(x = a; x<=b; x+=h) {
      r = sum = 0;
                for(k = 0; k<=n; k++) {
                        r = pow(-1,k)*pow(x, 2*k + 1)/factorial(2*k + 1);
                        sum += r;
                        Y = sinus(x);
                }
        printf("\n x = %8.1lf   Sum = %8.5lf   Y= %8.5lf   Module = %8.3lf", x, sum, Y, module(Y,sum));
        }
getch();
return 0;
}
