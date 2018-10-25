#include<stdio.h>
#include<stdlib.h>

struct structNode{
	
	int data;
	struct structNode *next;
};

typedef struct structNode node;

node *root = NULL;

node *createNode(int val){
	
	node *current = (node*)malloc(sizeof(node));
	current->data = val;
	current->next = NULL;
	return current;
} 


node* addNode(int val){
	
	node* newNode = createNode(val);
	
	if(root == NULL){	
		if(newNode == NULL)
			printf("No space in the memory...");
		else
			root = newNode;	
	}
	else{
		node* temp = root;
		
		while(temp->next != NULL)
			temp = temp->next;
		
		temp->next = newNode;
	}
}


node* addNodeStart(int val){
	
	node* newNode = createNode(val);
	
	if(root != NULL)
		newNode->next = root;
	
	root = newNode;
}


node* addAfterNode(int key,int val){ // given node value
	
	node* newNode = createNode(val);
	node* temp = root;
	
	if(root == NULL){
		printf("\nLinked list is empty...");
	}
	else{
		while(temp != NULL){	
			if(temp->data != key){
				temp = temp->next;	
			}
			else{
				newNode->next = temp->next;
		    	temp->next = newNode;
		    	printf("\n%d add after %d ...",val,key);
		    	break;
			}	
		}
		if(temp == NULL)
			printf("\n%d is not in the linked list...",key);
	}
}


node* addBeforNode(int key,int val){// given node value
	
	node* newNode = createNode(val), *ptr = root, *preptr = NULL;
	
	if(root == NULL){
		printf("\nLinked list is empty...");
	}
	else{
		while(ptr != NULL){
			if(ptr->data != key){
				preptr = ptr;
				ptr = ptr->next;
			}
			else{
				if(ptr == root){
					addNodeStart(val);
				}
				else{
					preptr->next = newNode;
					newNode->next = ptr;
				}
				
				printf("\n%d add befor %d ...",val,key);
				break;
			}
		}
		if(ptr == NULL)
			printf("\n%d is not in the linked list...",key);	
	}
}


node* display(){
	
	if(root == NULL){
		printf("\nLinked list is empty...");
	}
	else{
		node* temp= root;
		
		printf("\nCurrent linked list is : ");
		while(temp != NULL){
			printf("%d --> ",temp->data);
			temp = temp->next;
		}
		printf("NULL");	
	}
}


int length(){
	
	int count = 0;
	node* temp = root; 
	
	if(root == NULL){
		printf("\nLinked list is empty...");
	}
	else{
		while(temp != NULL){
			count++;
			temp = temp->next;
		}
	}
	printf("\nLenght of the linked list is : %d",count);
}

node* deleteFirstNode(){
	
	node* temp = root;
	
	if(root == NULL){
		printf("\nLinked list is empty...");
	}
	else{
		root = temp->next;
		temp->next = NULL;
		printf("\nDelete first node %d",temp->data);
		free(temp);
	}
}


node* deleteLastNode(){
	
	node* ptr = root, *preptr = NULL;
	
	if(root == NULL){
		printf("\nLinked list is empty...");
	}
	else{
		while(ptr->next != NULL){
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = NULL;
		printf("\nDelete last node %d",ptr->data);
		free(ptr);
	}
}


node* deleteGivenNode(int val){
	
	node* ptr = root, *preptr = NULL;
	
	if(root == NULL){
		
		printf("\nLinked list is empty...");
		
	}else{
		while(ptr != NULL){	
		    if(ptr->data != val){
		    	preptr = ptr;
				ptr = ptr->next;
			}
			else{	
				if(ptr == root){
					deleteFirstNode();
				}
				else{
					preptr->next = ptr->next;
					ptr->next = NULL;
					free(ptr);
				}
				
				printf("\n%d is deleted...",val);
				break;
			}
		}
	}
}


node* deleteAfterNode(int val){// given node value
	
	node*  preptr = root,*ptr = preptr->next;
	
	if(root == NULL){	
		printf("\nLinked list is empty...");
	}
	else{
		while(preptr != NULL){
			if(preptr->data == val){
				if(preptr->next != NULL){
					printf("\ndelete %d which after %d",ptr->data,val);
					preptr->next = ptr->next;
					ptr->next = NULL;
					free(ptr);	
				}
				else{
					printf("\nNo elements after the %d ...",val);
				}
				break;		
			}
			else{
				preptr = ptr;
				if(ptr != NULL)
					ptr = ptr->next;
			}
		}
		if(preptr == NULL)
			printf("\n%d is not in the linked list...",val);
	}
}


node* swappingNodes(int key){
	
	node* temp = NULL;  	
	node* preptr = NULL;
	node* ptr = root;
	
	if(root == NULL){	
		printf("\nLinked list is empty...");
	}
	else{
		if(ptr->data == key){
			temp = ptr->next;
			printf("\n%d and %d are swapped...",ptr->data,temp->data);
			ptr->next = temp->next; 
			temp->next = ptr;
			root = temp;
		}
		else{
			while(ptr != NULL){
				if(ptr->data == key){
					if(ptr->next != NULL){
						temp = ptr->next;
						printf("\n%d and %d are swapped...",ptr->data,temp->data);
						ptr->next =temp->next;
						temp->next = ptr;
						preptr->next = temp;	
					}
					else{
						printf("\n%d is last element of linked list...",key);	
					}
					break;
				}
				else{
					preptr = ptr;
					ptr = ptr->next;	
				}
			}
			if(ptr == NULL)
				printf("\n%d is not in the linked list...",key);
		}
	}
}


node* reversed(){
	
	if(root == NULL){
		printf("\nLinked list is empty...");
	}
	else{
		int i=1,j=0,k,t;
		
		node* tp = root;
		node* temp = root;
		node* first = root;
		
		while(tp != NULL){
			j++;
			tp = tp->next;	
		}
		while(i<j){
			k=1;
			while(k<j){
				temp = temp->next;
				k++;
			}
			t = first->data;
			first->data = temp->data;
			temp->data = t;
			
			first = first->next;
			temp = root;
			i++;
			j--;
		}
	}
}



int main(){

	addNode(5);
	addNode(10);
	addNode(15);
	addNode(20);
	addNode(25);
	addNode(30);
	addNodeStart(2);
	display();
	swappingNodes(30);
		display();
	}
