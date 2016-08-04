#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 10

void print_array(char walk[N][N])
{
    int i,j;
    for(i = 0;i<N;i++){
        for(j = 0;j<N;j++){
            putchar(walk[i][j]);
        }
        putchar('\n');
    }
}

void Init(char walk[N][N]){
    int i,j;
    for(i = 0;i<N;i++){
        for(j = 0;j<N;j++){
            walk[i][j] = '.';
        }
    }
}

bool CanWalk(char walk[N][N],int X,int Y,int direction){
    switch(direction){
        case 0:
            if(Y == 0 || walk[X][Y-1] != '.')return false;break;
        case 1:
            if(X == N - 1 || walk[X+1][Y] != '.')return false;break;
        case 2:
            if(Y == N - 1 || walk[X][Y+1] != '.')return false;break;
        case 3:
            if(X == 0 || walk[X-1][Y] != '.')return false;break;
    }
    return true;
}

void generate_random_walk(char walk[N][N]){
    srand((unsigned)time(NULL));
    int count = 0;
    char alphabet = 'A';
    int X = 0,Y = 0;
    walk[0][0] = 'A';alphabet++;//Letter 'A' is in the original position
    int i = 0;
    bool HasWay;
    while(alphabet<='Z'){
        HasWay = false;
        for(i = 0;i < 4;i++){
            if(CanWalk(walk,X,Y,i)){
                HasWay = true;break;
            }
        }
        if(!HasWay)break;
        while(true){
            int direction = rand() % 4;
            //0 Up
            //1 Right
            //2 Down
            //3 Left
            if(CanWalk(walk,X,Y,direction)){
            switch(direction){
                case 0:Y--;break;
                case 1:X++;break;
                case 2:Y++;break;
                case 3:X--;break;
                }
            walk[X][Y] = alphabet;
            break;
            }
        }
        alphabet++;
    }
}

int main()
{
    char walk[N][N];
    Init(walk);
    generate_random_walk(walk);
    print_array(walk);
    getchar();
    return 0;
}
