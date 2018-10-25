#include <stdio.h>
#include <stdlib.h>

struct structTree {
    int key;
    struct structTree* right;
    struct structTree* left;
}; 

typedef struct structTree tree;

tree *ROOT = NULL;

tree* insertEdge(tree *root, int key) {
    if (root == NULL) {
        tree *newEdge = (tree *) malloc(sizeof(tree));
        newEdge->key = key;
        newEdge->left = NULL;
        newEdge->right = NULL;
        root = newEdge;
    } else {
        if (root->key > key) 
            root->left = insertEdge(root->left, key);
        else
            root->right = insertEdge(root->right, key);
    }
    return root;
}

tree *getDeepest(tree *root) {
    if (root->left != NULL) {
        return getDeepest(root->left);
    } else if (root->right != NULL) {
        return getDeepest(root->right);
    } else {
        return root;
    }
}

tree *deleteEdge(tree *root, int key) {
    if (root != NULL) {
        if (root->key == key) {
            if (root->left == NULL) {
                tree *temp = root;
                root = root->right;
                free(temp);
            } else if (root->right == NULL) {
                tree *temp = root;
                root = root->left;
                free(temp);
            } else {
                tree *lowestInRightBranch = getDeepest(root->right);
                root->key = lowestInRightBranch->key;
                root->right = deleteEdge(root->right, lowestInRightBranch->key);
            }
        } else {
            root->left = deleteEdge(root->left, key);
            root->right = deleteEdge(root->right, key);
        }
    }
    return root;
}

void inorderTraverse(tree *root) {
    if (root != NULL) {
        inorderTraverse(root->left);
        printf("%d -> ", root->key);
        inorderTraverse(root->right);
        //printf("\n");
    }
}

int main() {
    ROOT = insertEdge(ROOT, 30);
    ROOT = insertEdge(ROOT, 40);
    ROOT = insertEdge(ROOT, 50);
    ROOT = insertEdge(ROOT, 55);
    ROOT = insertEdge(ROOT, 60);
    ROOT = insertEdge(ROOT, 53);
    ROOT = insertEdge(ROOT, 57);
    ROOT = insertEdge(ROOT, 70);
    ROOT = insertEdge(ROOT, 65);
    ROOT = insertEdge(ROOT, 80);
    
    
    
    ROOT = deleteEdge(ROOT, 60);
    inorderTraverse(ROOT);
    return 0;
}
