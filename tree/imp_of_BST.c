#include<stdio.h>
#include<stdlib.h>

struct structTree{
	
	int data;
	struct structTree* left;
	struct structTree* right;
};
typedef struct structTree tree;

tree* root = NULL;

tree* create(int val){
	
	tree* newNode = (tree*)malloc(sizeof(tree));
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
}


tree* insert(int val){
	
	tree* temp = root, *parent = NULL;
	
	if (root == NULL){
		root = create(val);
	}
	else{
		while(temp != NULL){
			parent = temp;
			if (temp->data == val)
				break;
			else if(temp->data > val)
				temp = temp->left;
			else
				temp = temp->right;	
		}
		if(parent->data != val){
			if(parent->data > val)
				parent->left = create(val);
			else
				parent->right = create(val);
		}
	}
	return root;
}


tree* preOrder(tree* root){
	if(root != NULL){
		printf("%d -->",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}


tree* inOrder(tree* root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d -->",root->data);
		inOrder(root->right);
	}
}


tree* postOrder(tree* root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d -->",root->data);
	}
}


int smallestElement(){
	tree* temp = root;
	
	while(temp != NULL){
		if(temp->left != NULL){
			temp = temp->left;
		}
		else{
			return temp->data;
		}
	}
}


int largestElement(){
	tree* temp = root;
	
	while(temp != NULL){
		if(temp->right != NULL){
			temp = temp->right;
		}
		else{
			return temp->data;
		}
	}
}


int totalNodes(tree* root){
	if(root != NULL)
		return ( totalNodes(root->left) + totalNodes(root->right) + 1 );
	else
		return 0;	
}


int totalLeaves(tree* root){
	if(root != NULL){
		if(root->left == NULL && root->right == NULL)
			return 1;
		else
			return (totalLeaves(root->left) + totalLeaves(root->right));	
	}	
}


int totalNonLeaves(tree* root){
	if(root != NULL){
		if(root->left == NULL && root->right == NULL)
			return 0;
		else
			return ( totalNonLeaves(root->left) + totalNonLeaves(root->right) + 1 );
	}
}


tree* mirror(tree* root){
	if(root != NULL){
		tree* temp;
		
		mirror(root->left);
		mirror(root->right);
		
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	else
		printf("\nTree is empty...");
}


void deleteTree(tree* root){
	if(root != NULL){
		deleteTree(root->left);
		deleteTree(root->right);	
		free(root);
	}
	else
		printf("\nTree is empty...");
}


tree* deleteNode(int val){
	
	int num,t;
	tree* temp = root,*parent = NULL, *current = NULL;
	
	if(root != NULL){
		while(temp != NULL){
			parent = current;
			current = temp;
			if(temp->data > val)
				temp = temp->left;
			else if(temp->data < val)
				temp = temp->right;
			else if(temp->data == val){
				temp = NULL;
				t = val;
			}
		}	
		if(t == val){
			if(current->left == NULL  &&  current->right == NULL){
				if(parent->left == current)
					parent->left = NULL;
				else
					parent->right = NULL;
			
				free(current);
			}
			else if(current->left != NULL  && current->right == NULL){
				parent = current;
				current = current->left;
				parent->data = current->data;
				parent->left = NULL;
				free(current);
			}
			else if(current->left == NULL  && current->right != NULL){
				parent = current;
				current = current->right;
				parent->data = current->data;
				parent->right = NULL;
				free(current);
			}
			else{
				num = largestElement(current->left);
				deleteNode(num);
				current->data = num;	
			}
		}
		else{
			printf("The value not in the tree...");
		}
	}
}



int main(){
	
	int opt,n,m;
	
	do{
		printf("\n");
		printf("\n  ***** MAIN MENU *****\n\n");
		printf("  1 - INSERT an element\n");
		printf("  2 - DELETE an element\n");
		printf("  3 - PRE-ORDER traversal\n");
		printf("  4 - IN-ORDER traversal\n");
		printf("  5 - POST-ORDER traversal\n");
		printf("  6 - SMALLEST NUMBER\n");
		printf("  7 - LARGEST NUMBER\n");
		printf("  8 - TOTAL NODES\n");
		printf("  9 - TOTAL LEAVES\n");
		printf(" 10 - TOTAL NONLEAVES\n");
		printf(" 11 - MIRROR IMAGE\n");
		printf(" 12 - DELETE TREE\n");
		printf(" 13 - EXIT program\n");
		printf("\nEnter your choice : ");
		scanf("%d",&opt);
		
		switch(opt){
		
			case 1:
				printf("\nEnter element to insert : ");
				scanf("%d",&n);
				insert(n);
				break;
				
			case 2:
				if(root != NULL){
					printf("\nEnter element to be delete : ");
					scanf("%d",&m);
					deleteNode(m);
				}
				else
					printf("Tree is empty...");
				break;
				
			case 3:
				if(root == NULL)
					printf("tree is empty...");
				else
					printf("\nPre-Order traversal : ");preOrder(root);
				break;
					
			case 4:
				if(root == NULL)
					printf("tree is empty...");
				else
					printf("\nIn-Order traversal : ");inOrder(root);
				break;
				
			case 5:
				if(root == NULL) 
					printf("tree is empty...");
				else 
					printf("\nPost-Order traversal : ");postOrder(root);	
				break;
				
			case 6:
				if(root != NULL) 
					printf("\nSmallest element is : %d",smallestElement());
				else 
					printf("Tree is empty...");
				break;
				
			case 7:
				if(root != NULL) 
					printf("\nLargest element is : %d",largestElement());
				else 
					printf("Tree is empty...");
				break;
				
			case 8:
				if(root != NULL) 
					printf("\nTotal nodes : %d",totalNodes(root));
				else 
					printf("Tree is empty...");
				break;
				
			case 9:
				if(root != NULL) 
					printf("\nTotal leaves : %d",totalLeaves(root));
				else 
					printf("Tree is empty...");
				break;
				
			case 10:
				if(root != NULL) 
					printf("\nTotal nonleaves : %d",totalNonLeaves(root));
				else 
					printf("Tree is empty...");
				break;
				
			case 11:
				if(root != NULL) 
					mirror(root);
				else 
					printf("Tree is empty...");
				break;
				
			case 12:
				if(root != NULL) 
					deleteTree(root);
				else 
					printf("Tree is empty...");
				break;
		}
		
	}while(opt != 13 );
}
