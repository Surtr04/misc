#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}Tree;

typedef struct stack {
	Tree *tree;
	struct stack *next;
}Stack;

Stack *push (Stack *s,Tree *t) {
		
	if (s == NULL) {
		s = (Stack*) malloc (sizeof(Stack));
		s->tree = t;
		s->next = NULL;
		return s;
	}
	else {
		Stack *aux = (Stack*) malloc (sizeof(Stack));
		aux->tree = t;
		aux->next = s;
		s = aux;
		return s;
	}
}
	
Stack *pop (Stack *s) {
		
	if (s == NULL)
		return s;
	
	if (s->next == NULL) {
		free(s);
		return NULL;
	}
	
	Stack *aux;
	aux = s;
	s = s->next;
	free (aux);
	return s;
}

Tree* insert (Tree *t, int val) {

	if (t == NULL) {
		t = (Tree*) malloc (sizeof(Tree));
		t->val = val;
		t->left = NULL;
		t->right = NULL;
		return t;
	}

	else {
	
		if (val < t->val) {
			t->left = insert(t->left,val);
			return t;
		}
		else {
			t->right = insert(t->right,val);
			return t;
		}

		
	}

}

void inorder (Tree *t) {
	
	Tree* pre = NULL; 
	Tree* nodo = t;
		

	while (nodo != NULL) {
		
		if (nodo->left == NULL) {
			printf("%d ",nodo->val);
			nodo = nodo->right;
		}
		else {
			pre = nodo->left;
			
			while (pre->right != NULL && pre->right != nodo) {
				pre = pre->right;
			}
			
			if(pre->right == NULL) {
				pre->right = nodo;
				nodo = nodo->left;
			}
			else {
				pre->right = NULL;
				printf("%d ", nodo->val);
				nodo = nodo->right;
			}

		}

	}
	
	
}

void recurPreOrder (Tree *t) {
	if(t) {
		printf("%d ",t->val);
		recurPreOrder(t->left);
		recurPreOrder(t->right);
	}
}

void recurInOrder (Tree *t) {
	
	if(t) {
		recurInOrder(t->left);
		printf("%d ",t->val);
		recurInOrder(t->right);
	}
}

void recurPostOrder (Tree *t) {
	
	if(t) {
		recurPostOrder(t->left);
		recurPostOrder(t->right);
		printf("%d ",t->val);
	}
}
		

void iterPreOrder (Tree *t) {
	
	Stack *nodeList = NULL;
	
	if (t == NULL) 
		return ;
	
	nodeList = push(nodeList,t);
	
	while (nodeList) {
		
		t = nodeList->tree;
		nodeList = pop(nodeList);
		
		printf("%d ",t->val);
		
		if (t->right != NULL) 
			nodeList = push(nodeList,t->right);
		if (t->left != NULL)
			nodeList = push(nodeList,t->left);
	}
	
}


int main () {

	int i, v1[] = {7, 3, 10, 2, 5, 1, 6, 9, 4, 8}; 
	Tree* ab1 = NULL;
	for(i = 0; i < 10; i++) { 
	ab1 = insert(ab1, v1[i]);
	} 
	
	recurInOrder(ab1);
	printf("\n");	
	recurPreOrder(ab1);
	printf("\n");
	recurPostOrder(ab1);
	printf("\n");
	iterPreOrder(ab1);
	
	return 0;
}