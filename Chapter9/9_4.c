#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define N 10

void read_word(int counts[26]){
    char ch;
    int i;
    while((ch = getchar())!= '\n'){
        ch = tolower(ch);
        i = ch - 'a';
        counts[i]++;
    }
}

bool equal_array(int counts1[26],int counts2[26]){
    int i;
    for(i = 0;i<26;i++){
        if(counts1[i] != counts2[i])
            return false;
    }
    return true;
}
void init(int a[26]){
    int i;
    for(i=0;i<26;i++)
        a[i]=0;
}
int main()
{
    int counts1[26];
    int counts2[26];
    init(counts1);
    init(counts2);
    printf("Enter first word: ");
    read_word(counts1);
    printf("Enter second word: ");
    read_word(counts2);
    if(equal_array(counts1,counts2))
        printf("The words are anagrams");
    else
        printf("The words are not anagrams");
    getchar();
    return 0;
}
