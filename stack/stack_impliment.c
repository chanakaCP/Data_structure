#include<stdio.h>
#define MAX 5

int st[MAX];
int top = -1;
int size;


int isEmpty(){
	if(top == -1)
		printf("stack is empty...\n");
	else
		printf("stack is not empty...\n");
}
	
int isFull(){
	if(top == MAX-1)
		printf("stack is full...\n");
	else 
		printf("stack is not full...\n");;
	}

int peek(){
	if(top == -1){
		printf("stack is empty...\n");
	}
	else{
		printf("%d \n",st[top]);
		return st[top];
	}
}
		
int pop(){
	if(top == -1){
		printf("stack is empty...\n");	
	}
	else{
		top--;
		return st[top];
	}
}

void push(int val){
	if(top == MAX-1){
		printf("Stack is full...\n");
	}
	else {
		top++;
		st[top] = val;
	}
}

int getSize(){
	size =top+1;
	printf("stack size : %d\n",size);
	return size;
}

int output(){
	int a;
	
	for( a=0;a<top+1;a++){
		printf("%d \n",st[a]);
	}
}


int main(){
	
	isEmpty();
	push(10);
	push(20);
	push(30);
	isFull();
 peek();	push(40);
	push(50);
	push(60);
	push(70);
	getSize();
	pop();
	peek();
	output();
	return 0;
}
