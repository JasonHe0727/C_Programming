#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define STACK_SIZE 100
/* external variables */
int contents[STACK_SIZE];
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

void push(int i){
	if (is_full()){
		printf("stack overflow");
		exit(1);
	}
	else
		contents[top++] = i;
}

int pop(void){
	if (is_empty()){
		printf("stack_underflow");
		exit(1);
	}
	else
		return contents[--top];
}

		
int main(){
	char ch;
	int left,right;
	while (true){
		make_empty();
		printf("Enter an RPN expression: ");
		while ((ch = getchar()) != '\n'){
			if (ch == 'q') /* quit */
				return 0;
			if (ch >= '0' && ch <= '9')
				push(ch-'0');
			else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
				right = pop();
				left = pop();
				switch(ch){
					case '+':
						push(left+right);break;
					case '-':
						push(left-right);break;
					case '*':
						push(left*right);break;
					case '/':
						push(left/right);break;
				}
			}
			else if (ch == '='){
				getchar();
				break;
			}
			else if(ch != ' '){
				printf("error input: %c",ch);
				exit(1);
			}
		}
		printf("Value of expression: %d\n",pop());
	}
	return 0;
}
