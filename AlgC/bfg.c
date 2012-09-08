#include <stdio.h>
#include <stdlib.h>


#define EDGES 20
#define VERTEX 5





typedef struct grafo1 {
    int arestas[EDGES];
    int vertices[VERTEX];
}Grafo1;

typedef struct arco {
    int destino;
    struct arco *next;
} Arco;

typedef Arco** Grafo2;

typedef struct queue {
    Arco* arc;
    struct queue* next;
}Queue;


Queue* enqueue (Queue *q,Arco* val) {
    
    if (!q) {
        q = (Queue*) malloc(sizeof(Queue));
        q->arc = val;
        q->next = NULL;        
    }
    else {
        Queue* front = q;
        Queue* aux = (Queue*) malloc(sizeof(Queue));
        aux->arc = val;
        aux->next = NULL;
        
        while (q->next)
            q = q->next;
        
        q->next = aux;
        q = front;
    }
    return q;
}


Queue* dequeue (Queue *q,Arco **t) {
    
    Queue *aux = q;
    *t = q->arc;
    
    q = q->next;
    free(aux);
    
    return q;    
}

int isEmpty(Queue *q) {
    
    return q ? 0 : 1;
    
}


Grafo2 insert(Grafo2 g,int or,int dst);

Grafo2 init(void);

Grafo2 init() {
    
    Grafo2 g = (Arco**) malloc(VERTEX * sizeof(Arco*));
    
    int i = 0;
    
    while (i < VERTEX) {
        g[i] = NULL;
        i++;
    }
    
    return g;
}
    
Grafo2 insert(Grafo2 g,int or,int dst) {
    
    if (g[or] == NULL) {
        g[or] = (Arco*) malloc(sizeof(Arco));
        g[or]->destino = dst;
        g[or]->next = NULL;
    }
    else{
        Arco *aux = (Arco*) malloc(sizeof(Arco));
        aux->destino = dst;
        aux->next = g[or];
        g[or] = aux;
    }
    return g;
}

void printAdjList (Grafo2 g) {
    int i = 0;
    
    while (i < VERTEX) {
        printf("%d : ",i);
        while (g[i]) {
            printf("%d -> ",g[i]->destino);
            g[i] = g[i]->next;
        }
        printf("\n");
        i++;
    }
    
}

int BFS (Grafo2 g,int root,int dst) {
    
    Queue *q = NULL;
    Arco *aux;
    int visited[VERTEX];
    
    q = enqueue(q, g[root]);
    visited[root] = 1;
    
    while (!isEmpty(q)) {
        q = dequeue(q, &aux);
        if (aux->destino == dst)
            return aux->destino;
        aux = aux->next;
        
        while(aux) {
            if(!visited[aux->destino]) {
                visited[aux->destino] = 1;
                q = enqueue(q, g[aux->destino]);
            }
            aux = aux->next;
        }
        
    }
    
    return 0;
}

int main () {
    
    Grafo2 g = init();
    g = insert(g, 1, 2);
    g = insert(g, 1, 3);
    g = insert(g, 2, 1);
    g = insert(g, 2, 3);
    g = insert(g, 2, 4);
    g = insert(g, 3, 1);
    g = insert(g, 3, 2);
    g = insert(g, 4, 2);
    printf("%d \n",BFS(g, 2, 4));
    printAdjList(g);
}