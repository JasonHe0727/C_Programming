#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

int roll_dice(void){
    int roll_1 = 1 + (rand() % 6);
    int roll_2 = 1 + (rand() % 6);
    return roll_1+roll_2;
}

bool play_game(void){
    bool firstTime = true;
    int target = -1;
    srand((unsigned)time(NULL));
    while(true){
        int point = roll_dice();
        printf("You rolled: %d\n",point);
        if(firstTime && (point == 7 || point == 11))
            return true;
        if(firstTime && (point == 2 || point == 3 || point == 12))
            return false;
        if(firstTime){
            target = point;firstTime=false;
        }
        else{
            if(point == target)return true;
            if(point == 7)return false;
        }
    }
}

int main()
{
    int wins = 0;
    int losses = 0;
    while(true){
        if(play_game()){
                printf("You win!\n");
                wins++;
        }
        else{
                printf("You lose!\n");
                losses++;
        }
        printf("Play again? ");
        char ch = getchar();
        if(ch == '\n')ch = getchar();
        if(tolower(ch)!='y'){
            printf("Wins: %d\tLosses: %d",wins,losses);
            break;
        }
    }
    getchar();
    return 0;
}
