#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define N 5

void create_magic_square(int n,int magic_square[n][n]){
    magic_square[0][n/2]=1;
    int i;
    int nsq = n*n;
    int nextX=0,nextY=n/2;
    int curX,curY;
    for(i=2;i<=nsq;i++){
        curX = nextX;
        curY = nextY;
        nextX--;
        nextY++;
        if(nextX==-1) nextX = n-1;
        if(nextY== n) nextY = 0;
        if(magic_square[nextX][nextY]!=0){
            nextX = curX+1;
            nextY = curY;
        }
        magic_square[nextX][nextY]= i;
    }
}
void print_magic_square(int n,int magic_square[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",magic_square[i][j]);
            putchar('\t');
        }
        putchar('\n');
    }
}
void init(int n,int magic_square[n][n]){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            magic_square[i][j]=0;
}
int main()
{
    int magic_square[N][N];
    init(N,magic_square);
    create_magic_square(N,magic_square);
    print_magic_square(N,magic_square);
    getchar();
    return 0;
}
