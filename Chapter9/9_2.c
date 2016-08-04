#include <stdio.h>
#include <stdlib.h>

double Tax(double income){
    if (income <= 750.00)
        return income * 0.01;
    else if (income <= 2250.00)
        return 7.50 + (income-7.50)* 0.02;
    else if (income <= 3750.00)
        return 37.50 + (income-37.50) * 0.03;
    else if (income <= 5250.00)
        return 82.50 + (income-82.50)*0.04;
    else if (income <= 7000.00)
        return 142.50 + (income-142.50) * 0.05;
    else
        return 230.00 + (income-230.00) * 0.06;
}

int main()
{
    printf("Enter your income:");
    double income;
    scanf("%lf",&income);
    printf("Tax: %lf\n",Tax(income));
    getchar();
    getchar();
    return 0;
}
