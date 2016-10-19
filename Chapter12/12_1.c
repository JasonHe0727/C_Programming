#include<stdlib.h>
#include<stdio.h>
#define N 255

int main(){
	printf("Enter a message: ");
	char a[N],ch, *p;
	p = &a[0];
	while((ch = getchar()) != '\n'){
		*p = ch;
		p++;
	}
	p--;
	printf("Reversal is: ");
	char *start_index = &a[0];
	while(p>=start_index){
		putchar(*p);
		p--;
	}
	return 0;
}
