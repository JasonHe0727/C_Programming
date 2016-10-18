#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define STACK_SIZE 100
/* external variables */
char contents[STACK_SIZE];
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

void push(char c){
	if (is_full()){
		printf("stack overflow");
		exit(1);
	}
	else
		contents[top++] = c;
}

char pop(void){
	if (is_empty()){
		printf("stack_underflow");
		exit(1);
	}
	else
		return contents[--top];
}

		
int main(){
	char ch;
	bool is_proper = true;
	printf("Enter parenteses and/or braces: ");
	while ((ch = getchar()) != '\n'){
		if (ch == '(' || ch == '{')
			push(ch);
		else if (ch == ')'){
			if(pop()!='('){
				is_proper = false;
				break;
			}
		}
		else if (ch == '}'){
			if(pop()!='{'){
				is_proper = false;
				break;
			}
		}
		else{
			is_proper = false;
			printf("error input");
			break;
		}
	}
	if (is_proper)
		printf("Parenteses/braces are nested properly");
	else
		printf("Parenteses/braces are not nested properly");
	return 0;
}
