#include<stdio.h>
#include<stdlib.h>

struct structNode{
	int data;
	struct structNode* next;;
};
typedef struct structNode link;

link* top = NULL;


void push(int val){
	
	link* newNode = (link*)malloc(sizeof(link));
	
	newNode->data = val;
	newNode->next = top;
	top = newNode;
}

void pop(){
	
	link* temp = top;
	
	if(top != NULL){
		printf("\n%d is deleted...\n",top->data);
		top = top->next;
		temp->next = NULL;
		free(temp);
	}
	else{
		printf("\nStack is Underflow...\n");
	}
}


int peek(){
	if(top != NULL)
		printf("\nTop data of stack is : %d\n",top->data);
	else
		printf("\nStact is underflow...\n");
}


int print(){
	if(top != NULL){
		printf("\n");
		link* temp = top;
		while(temp != NULL){
			printf(" %d ",temp->data);
			printf("\n");
			temp = temp->next;
		}
	}
	else{
		printf("\nStack is underflow...\n");
	}
}


int main(){
	peek();
	print();
	pop();
	push(10);
	push(20);
	push(30);
	push(40);
	print();
	peek();
	pop();
	peek();
	print();
	
	
	
}
