#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 255
int read_line(char str[], int n){
	int ch,i = 0;

	while((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';  /* terminates string */
	return i; /* number of characters stored */
}


int main(){
	char a[N], b[N], *smallest_word, *largest_word;
	smallest_word = &a[0];
	largest_word = &b[0];
	char str[N];
	bool first_word = true;
	for(;;){
		printf("Enter word: ");
		int n = read_line(str, N);
		if (first_word){
			strcpy(smallest_word, str);
			strcpy(largest_word, str);
			first_word = false;
		}
		else {
			if (strcmp(str,smallest_word) < 0)
				strcpy(smallest_word,str);
			if (strcmp(str,largest_word) > 0)
				strcpy(largest_word,str);
		}
		if (strlen(str) == 4)
			break;
	}
	printf("Smallest word: %s ",smallest_word);
	printf("\nLargest word: %s ",largest_word);
	return 0;
}
