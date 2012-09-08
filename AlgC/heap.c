#include <stdio.h>
#include <stdlib.h>

#define PARENT(i) (i-1)/2
#define LCHILD(i) (2*i) + 1
#define RCHILD(i) (2*i) + 2
#define TOSTRING(x,y) 

typedef struct minHeap {
    int size;
    int used;
    int *values;
} *MinHeap;

void swap(int *arr,int p1, int p2);
MinHeap init(int size);
MinHeap minHeapify(MinHeap m);
MinHeap add (MinHeap m, int value);
void print(MinHeap m);
int findIndex(MinHeap m, int value);
void rem(MinHeap m, int value);

void swap(int *arr,int p1, int p2) {
    
    int tmp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = tmp;
}

MinHeap init(int size) {
    
    MinHeap m = (MinHeap) malloc (sizeof(MinHeap*));
    m->size = size;
    m->used = 0;
    m->values = (int*) malloc(size * sizeof(int));
    
    return m;
}

MinHeap minHeapify(MinHeap m) {
    
    int i = (m->used-1);
    
    while (i > 0 && (m->values[i] < (m->values[PARENT(i)]))) {
        swap((m->values), i, PARENT(i));
        i = PARENT(i);
    }
    
    return m;
}

MinHeap add (MinHeap m, int value) {

    m->values[m->used] = value;
    m->used++;
    m = minHeapify(m);
    return m;
}


void print(MinHeap m) {
    
    int i;
    
    for (i = 0; i < m->used; i++) {
        printf("%d ",m->values[i]);
    }
    
}

int findIndex(MinHeap m, int value) {
    
    int i = 0;
    
    while(i < m->used) {
        if(m->values[i] == value)
            return i;
        i++;
    }
    
    return -1;
}

void rem(MinHeap m, int value) {
    
    int index = findIndex(m, value);
    
    if (index < 0)
        return;
    
    int count = m->used - 1;
    m->used--;
    m->values[index] = m->values[count];
    
    while (LCHILD(index) < count && (m->values[index] > m->values[LCHILD(index)] ||
           m->values[index] > m->values[RCHILD(index)])) {
        if (m->values[LCHILD(index)] < m->values[RCHILD(index)]) {
            swap(m->values, LCHILD(index), index);
            index = LCHILD(index);
        }
        else {
            swap(m->values, RCHILD(index), index);
            index = RCHILD(index);            
        }
    }
    

    
}


int main() {
    
    MinHeap m = init(20);
    m = add(m, 3);
    print(m);
    printf("\n");
    m = add(m, 9);
    print(m);
    printf("\n");
    m = add(m, 12);
    print(m);
    printf("\n");
    m = add(m, 7);
    print(m);
    printf("\n");
    m = add(m, 1);
    print(m);
    printf("\n");
    rem(m,7);
    print(m);
    printf("\n");
    return 0;
}