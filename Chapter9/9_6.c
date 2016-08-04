#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

double Polynomial(double x){
    return 3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6;
}
int main()
{
    printf("Enter number: ");
    double x;
    scanf("%lf",&x);
    printf("ans = %lf",Polynomial(x));
    getchar();
    getchar();
    return 0;
}
