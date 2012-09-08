#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int val;
	struct node *next;
}Stack;

void showStack (Stack *s) {
	
	while (s) {
		printf("%d ",s->val);
		s = s->next;
	}
	
	
}


Stack* push (Stack *s,int val) {

	if (s == NULL) {
		s = (Stack*) malloc (sizeof(Stack));
		s->val = val;
		s->next = NULL;
		return s;
	}
	else {
		Stack *aux = (Stack*) malloc (sizeof(Stack));
		aux->val = val;
		aux->next = s;
		s = aux;
		return s;
	}

}

Stack* pop (Stack *s) {

	if (s == NULL) 
		return NULL;
	
	if (s->next == NULL) {
		free(s);
		return NULL;
	}
	
	Stack *aux = s;
	s = s->next;
	free(aux);
	
	return s;

}

Stack* top (Stack *s) {
	
	Stack *aux = (Stack*) malloc (sizeof(Stack));
	
	aux->val = s->val;
	aux->next = NULL;
	
	return aux;
	
	
}

Stack* tail (Stack *s) {

	Stack *aux = (Stack*) malloc (sizeof(Stack));
	memcpy(aux,s,sizeof(Stack));
	
	aux = pop(aux);
	
	return aux;
}



int main () {


	Stack *s = NULL;
	Stack *s1 = NULL;
	s = push(s,1);
	s = push(s,2);
	s = push(s,3);
	
	showStack(s);
	printf("\n");
	s = pop(s);
	showStack(s);
	printf("\n");
	s1 = tail(s);
}