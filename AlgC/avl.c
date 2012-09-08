#include <stdio.h>
#include <stdlib.h>

#define L -1
#define B 0
#define R 1


typedef struct leaf {
	int info;
	int balFactor;
	struct leaf *left,*right;
}Tree;

int max (int a,int b) {
	if (a > b)
		return a;
	else
		return b;
	
}

int height (Tree *t) {
	
	if(!t) return -1;
	
	else
		return max(height(t->left),height(t->right)) + 1;
	
}

void updateBalance (Tree *t) {
	
	if(!t) return ;
	
	t->balFactor = height(t->right) - height(t->left);
	updateBalance(t->left);
	updateBalance(t->right);
	
}

Tree* insert (Tree *t,int i) {

	if (!t) {
        
		t = (Tree*) malloc(sizeof(Tree));
		t->info = i;
		t->balFactor = B;
		t->left = NULL;
		t->right = NULL;
	}
	else {
		if (i > t->info) t->right = insert(t->right,i);
		else t->left = insert(t->left,i);
	}

	updateBalance(t);
	return t;
}



void inOrder (Tree *t) {
	
	if(!t)
		return;
	inOrder(t->left);
	printf("%d ",t->info);
	inOrder(t->right);
}

void preOrder (Tree *t) {
	
	if(!t)
		return;
	printf("%d ",t->info);
	preOrder(t->left);
	preOrder(t->right);
}


void printBalInOrder (Tree *t) {
	
	if(!t)
		return;
	printBalInOrder(t->left);
	printf("%d ",t->balFactor);
	printBalInOrder(t->right);
}

void printBalPreOrder (Tree *t) {
	
	if(!t)
		return;
	
	printf("%d ",t->balFactor);	
	printBalPreOrder(t->left);
	printBalPreOrder(t->right);
}


Tree *rightRotation (Tree *t) {
	
	if(!t) return t;
	
	Tree *aux = t->left;
	if(!aux) return t;
	t->left = aux->right;
	aux->right = t;
	t = aux;
	return t;

	
}

Tree *leftRotation (Tree *t) {

	if(!t) return t;
	
	Tree *aux = t->right;
	if(!aux) return t;
	t->right = aux->left;
	aux->left = t;
	t = aux;
	return t;
	
}

Tree* balance (Tree *t) {
	
	if(!t) return NULL;

	if (t->balFactor == -2) {
		if (t->left && t->left->balFactor >= 1)
			t->left = leftRotation(t->left);
		t = rightRotation(t);
	}
	if (t->balFactor == 2) {
		if (t->right && t->right->balFactor <= -1) 
			t->right = rightRotation(t->right);
		t = leftRotation(t);
	}
	
	t->left = balance(t->left);
	t->right = balance(t->right);

	
	updateBalance(t);
	return t;
	
}
	

int main () {
	
	Tree *t = NULL;
	t = insert(t,32);
	t = insert(t,16);
	t = insert(t,8);
    printBalInOrder(t);
    printf("\n");
    inOrder(t);
    printf("\n");
    
    t = balance(t);
    printBalInOrder(t);
    printf("\n");
    inOrder(t);
    
	return 0;
}