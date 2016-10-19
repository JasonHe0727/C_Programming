#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define N 255
int main(){
	printf("Enter a message: ");
	char a[N],ch,*p,*q;
	p = &a[0];
	while ( (ch = getchar()) != '\n' ){
		ch = tolower(ch);
		if(ch >= 'a' && ch <= 'z'){
			*p = ch;
			p++;
		}
	}
	p--;
	char *end;
	end = p;
	for(q = &a[0];q <= p;q++,p--){
		if(*q != *p){
			printf("Not a palindrome");
			return 0;
		}
	}
	printf("Palindrome");
	return 0;
}

