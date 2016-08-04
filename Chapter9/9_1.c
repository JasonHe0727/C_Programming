#include <stdio.h>
#include <stdlib.h>
#define N 5

void selection_sort(int a[], int n)
{
    if(n <= 0)return;
    int i = 1;
    int imax = 0;
    double max = a[0];
    while(i<n){
        if(a[i] > max)
            {
            imax = i;
            max = a[i];
            }
        i++;
    }
    Swap(a,imax,n-1);
    display(a);
    selection_sort(a,n-1);
}
void Swap(int a[],int i,int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void display(int a[]){
    int i = 0;
    while(i< N){
        printf("%d  ",a[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    printf("Enter %d integers:\n",N);
    int i = 0;
    int a[N];
    do{
        scanf("%d",&a[i]);
        i++;
    }while(getchar()!='\n');
    selection_sort(a,N);
    printf("Sorted integers: ");
    display(a);
    getchar();
    return 0;
}
