#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

double power(double x,int n){
    if(n == 0) return 1.0;
    double t;
    if(n % 2 == 0)
    {
        t = power(x, n / 2);
        return t * t;
    }
    else
        return x * power(x, n - 1);
}
int main()
{
    int n;
    double x;
    printf("Enter x:");
    scanf("%lf",&x);
    printf("Enter n:");
    scanf("%d",&n);
    printf("%lf",power(x,n));
    getchar();getchar();
    return 0;
}
