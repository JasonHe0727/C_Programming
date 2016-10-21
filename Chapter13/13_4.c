#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define N 10
#define WORD_LEN 20
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


int read_word(char* word){
	char ch;
	int i = 0;
	bool is_end = false;
	do{
		ch = getchar();
		if (ch == '\n'){
			is_end = true;
			break;
		}
		if (ch == ' ')
			break;
		word[i] = ch;
		i++;
	}while(true);
	word[i] = '\0';
	if(is_end)
		return (-1)*(i+1);
	return i+1;
}	 

int main(){
	char a[N], ch;
	char* p;
	int len = 0;
	for(;;){
		len = read_word(a);
		if(len < 0){
			p = (char*) malloc(-len*sizeof(char));
			strcpy(p,a);
			push(p);
			break;
		}
		else {
			p = (char *) malloc(len * sizeof(char));
			strcpy(p,a);
			push(p);
		}
	}
	while(top>1){
		p = pop();
		printf("%s ",p);
		free(p);
	}
	return 0;
}
