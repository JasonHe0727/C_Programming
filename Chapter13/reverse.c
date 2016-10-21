#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define STACK_SIZE 100
/* external variables */
char* contents[STACK_SIZE];
int top = 0;

void make_empty(void){
	top = 0;
}

bool is_empty(void){
	return top == 0;
}

bool is_full(void){
	return top == STACK_SIZE;
}

void push(char* i){
	if (is_full()){
		printf("stack overflow");
		exit(1);
	}
	else
		contents[top++] = i;
}

char* pop(void){
	if (is_empty()){
		printf("stack_underflow");
		exit(1);
	}
	else
		return contents[--top];
}



int main(int argc, char *argv[]){
	int i;
	for(i=1;i<argc;i++)
		push(argv[i]);
	for(i=1;i<argc;i++)
		printf("%s ",pop());
	return 0;
}
