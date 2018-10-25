#include<stdio.h>
#include<stdlib.h>

struct structNode{
	
	int data;
	struct structNode* next;
};
typedef struct structNode link;

link* root = NULL;

link* create(int val){
	
	link* newNode = (link*)malloc(sizeof(link));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}


link* insert(int val){
	link* current = create(val);
	link* temp = root;
	
	if (root != NULL){
		while(temp->next != root){
			temp = temp->next;
		}
		temp->next = current;
		current->next = root;
	}
	else{
		root = current;
		root->next = root;
	}
}


link* addStart(int val){
	link* current = create(val);
	link* last = root;
	
	if(root == NULL){
		root = current;
		root->next = root;
	}
	else{
		while(last->next != root){
			last = last->next;
		}
		last->next = current;
		current->next = root;	
		root = current;
	}
}


link* deleteStart(){
	link* last = root;
	
	if(root != NULL){
		if(root->next != root){
			while(last->next != root){
				last = last->next;
			}
			last->next = root->next;
			last = root; //*** root---> last for deleting link
			root = root->next;
			last->next = NULL; // delete link
			free(last);	// delete node
		}
		else{
			free(root);
			root = NULL;
		}
	}
	else{
		printf("\nLinked list is empty...");
	}	
}


link* deleteLast(){
	link* last = root;
	link* ptr = root;
	
	if(root != NULL){
		if(root->next != root){
			while(last->next != root){
				ptr = last;
				last = last->next;
			}
			ptr->next = root;
			last->next = NULL;
			free(last);	
		}
		else{
			free(root);
			root = NULL;
		}
	}
	else{
		printf("\nLinked list is empty...");
	}
}


link* display(){
	
	if(root == NULL){
		printf("\nLinked list is empty...");
	}
	else{
		link* temp= root;
		
		printf("\nCurrent linked list is : ");
		while(temp->next != root){
			printf("%d --> ",temp->data);
			temp = temp->next;
		}
		printf("%d --> NULL",temp->data);	
	}
}



int main (){
	
	return 0;
}
