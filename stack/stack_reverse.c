#include<stdio.h>
#include<string.h>
#define MAX 100

char st[MAX];
int top = -1;

int isFull(){
	if(top == MAX-1)
		return 1;
	else 
		return 0;
	}
	
int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
	}
	
void push(int val){
	if(isFull()){
		printf("Stack is overflow\n");
		return;
	}
	else {
		top++;
		st[top] = val;
	}
}

int pop(){
	int i;
	
	if(isEmpty()){
		printf("stack is underflow\n");
		return 0;	
	}
	else{
		i = st[top];
		top--;
		return i;	
	}
}

int main(){
	
	char restr[MAX];
	char str[MAX];
	int i;

	printf("input :");
	scanf("%[^\n]s",&str);

	for (i=0;i<strlen(str);i++){
		push(str[i]);
	}

	for ( i=0;i<strlen(str);i++){
		restr[i] = pop();
	}

	printf("reversed : %s\n",restr);
}
	


