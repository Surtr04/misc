#include <stdio.h>
#include <stdlib.h>

/*
 É possível definir um grafo orientado não pesado usando dois arrays: o primeiro armazena as arestas ordenadas
 por vértice de origem, indicando para cada uma delas qual o vértice destino; o segundo indica em que posição do
 primeiro array começam as arestas com origem em cada vértice; a última posição do array de vértices é usada para
 indicar qual é a primeira posição livre do array de arestas. Assumindo que o grafo tem exactamente V vértices e
 no máximo A arestas
 
 ex: converter grafo1 em listas de adjacência
 */

#define V 6
#define A 9

typedef struct {
	int arestas[A];
	int vertices[V];
}Grafo1;

typedef struct arco {
	int destino;
	struct arco *next;
}Arco;

typedef Arco *Grafo2[V];

Arco* insert (Arco *a,int dest) {

	if (a == NULL) {
		a = (Arco *) malloc (sizeof(Arco));
		a->destino = dest;
		a->next = NULL;
	}
	
	else {
		Arco *head;
		head = a;
		
		while (a->next!=NULL) 
			a=a->next;
		
		a->next = (Arco *) malloc (sizeof(Arco));
		a->next->destino = dest;
		a->next->next = NULL;
		a = head;
	}

	return a;
}

void print (Arco *a) {
	
	while (a) {
		printf("%d -> ",a->destino);
		a=a->next;
	}
	
}

void prtAdjencyList (Grafo2 h) {
	
	int i = 0;
	
	while (i<V) {
		printf("%d\t",i);
		print(h[i]);
		printf("\n");
		i++;
	}
	
}


void converte (Grafo1 *g, Grafo2 h) {

	int edges,i,j,count = 0;
	Arco *aux = (Arco *) malloc (sizeof(Arco));
	
	for (i = 0; i < V; i++) {
		edges = g->vertices[i+1] - g->vertices[i];
		for (j = count; j < (edges + count); j++) {
			h[i] = insert(h[i],g->arestas[j]);
		}
		count += edges;
	}
	
}

int main () {


	Grafo1 *g = (Grafo1*) malloc (sizeof(Grafo1)); 
	g->arestas[0] = 1;
	g->arestas[1] = 2;
	g->arestas[2] = 2;
	g->arestas[3] = 4;
	g->arestas[4] = 4;
	g->arestas[5] = 1;
	g->arestas[6] = 2;
	g->arestas[7] = 5;
	g->arestas[8] = 3;
	g->vertices[0] = 0;
	g->vertices[1] = 2;
	g->vertices[2] = 4;
	g->vertices[3] = 5;
	g->vertices[4] = 7;
	g->vertices[5] = 8;
	g->vertices[6] = 9;
	Grafo2 h;
	
	converte (g,h);
	prtAdjencyList(h);
	
}