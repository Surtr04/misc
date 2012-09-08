#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

typedef struct node {
	char *info;
	struct node *next;
}Node;

typedef Node* Hash[SIZE];

int length (char *string) {
	
	int length = 0;
	char *head = string;
	
	while (*string != '\0') {
		length++;
		string++;
	}
	
	string = head;
	
	return length;
}
	

int hash (char *string) {

	int i = 0;
	char *head = string;
	
	while (*string != '\0') {
		i += (int)*string;
		string++;
	}
	
	i = i%SIZE;
	
	string = head;
	
	return i;
}

void insert (Hash h, char *string) {
	
	int 
	key = hash(string),
	size = strlen(string);	
	
	
	if(h[key] == NULL) {
		h[key] = (Node*) malloc (sizeof(Node));
		h[key] -> info = (char*) malloc(sizeof(char)*size);
		strcpy(h[key] -> info,string);
		h[key] -> next = NULL;
	}
	else {
		Node *aux = (Node*) malloc (sizeof(Node));
		aux->info = (char*) malloc (sizeof(char)*size);
		strcpy(aux->info,string);
		aux->next = h[key];
		h[key] = aux;
	}
	
}

int existsCol (Hash h, int pos) {
		
	if (h[pos] == NULL || h[pos] -> next == NULL)
		return 0;
	else
		return 1;
}

void delete (Hash h, char *string) {
	
	int key = hash(string);
	
	if (!existsCol(h,key)) {
		if(h[key] == NULL)
			fprintf(stderr,"Elemento nao existente");
		else {
			free(h[key]);
			h[key] = NULL;
		}
	}
	else {
		Node *curr = h[key];
		Node *head = curr;
		Node *prev = curr;
		curr = curr->next;
		Node *next = curr ->next;


		
		while (aux != NULL && 
			   strcmp(aux->info,string)!=0) {
			aux = aux->next;
			aux2 = aux2->next;
		}
		
		if (aux = NULL) 
			fprintf(stderr,"Elemento nao existente");
		else {
			aux2->next = (aux->next != NULL) ? aux->next : NULL;
			//free(aux);
			aux2 = head;
			h[key] = aux2;
		}
	}	
}

void printHash (Hash h) {
	
	int i = 0;
	Node *aux;

	while (i < SIZE) {
		if (h[i] != NULL) {
			printf("%d -> ",i);
			aux = h[i];
			while (aux) {
				printf("%s \t",aux->info);
				aux = aux->next;
			}
			printf("\n");
		}
		i++;
	}
		
}

void init (Hash h) {	
	int i;
	for (i=0; i<SIZE; i++) {
		h[i] = NULL;
	}
}


int main () {
	
	Hash h;
	init(h);
	
	insert(h,"joao");
	insert(h,"rodrigo");
	insert(h,"afonso");
	insert(h,"diogo");
	insert(h,"diana");
	insert(h,"eunice");
	insert(h,"baltazar");
	insert(h,"filipe");
	insert(h,"mafalda");
	insert(h,"mariana");
	insert(h,"rita");
	insert(h,"marta");
	insert(h,"catarina");
	insert(h,"luis");
	insert(h,"marcos");
	insert(h,"pedro");
	insert(h,"sonia");
	insert(h,"ana");
	insert(h,"antonio");
	insert(h,"manuel");
	insert(h,"maria");
	insert(h,"jorge");
	insert(h,"maria duarte");
	insert(h,"isabel");
	insert(h,"liliana");
	insert(h,"joelma");
	insert(h,"ricardo");
	insert(h,"rui pedro");
	insert(h,"raquel");
	insert(h,"francisca");
	insert(h,"fernando");
	insert(h,"joaquim");
	insert(h,"anibal");
	insert(h,"augusto");
	insert(h,"guilherme");
	insert(h,"gustavo");
	insert(h,"joao pedro");
	insert(h,"maria rita");
	insert(h,"ana jorge");
	insert(h,"ana duarte");
	insert(h,"leonor");
	insert(h,"carolina");
	insert(h,"beatriz");
	insert(h,"faustino");
	insert(h,"mauricio");
	insert(h,"margarida");
	insert(h,"micael");
	insert(h,"vitor");
	insert(h,"abilio");
	insert(h,"joao manuel");
	insert(h,"nuno");
	insert(h,"henriquta");
	insert(h,"tatiana");
	insert(h,"carla");
	insert(h,"carlota");
	insert(h,"bianca");
	insert(h,"susana");
	insert(h,"tania");
	insert(h,"vaia");
	insert(h,"margarete");
	insert(h,"bruno");
	insert(h,"hugo");
	insert(h,"francisco");
	insert(h,"maximiano");
	insert(h,"guilhermina de jesus");
	insert(h,"marco horacio");
	insert(h,"xavier");
	insert(h,"vandoma");
	insert(h,"eduarda");
	insert(h,"nadia");
	insert(h,"duarte");
	insert(h,"olga");
	insert(h,"maria teresa");
	insert(h,"teresa");
	insert(h,"ruca");
	insert(h,"noddy");
	insert(h,"anita");
	insert(h,"mia");
	insert(h,"katie");
	insert(h,"tom");
	insert(h,"michael");
	insert(h,"zac");
	insert(h,"eurico");
	insert(h,"barbara");
	insert(h,"silvia");
	insert(h,"joana raquel");
	insert(h,"sam");
	insert(h,"moises");

	
	printHash(h);
	delete(h,"rodrigo");
	printf("\n");
	printHash(h);
	
	

	
	return 0;

}