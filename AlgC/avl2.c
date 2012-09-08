#include <stdio.h>
#include <stdlib.h>

#define BALANCED 0
#define LEFTHEAVY -1
#define RIGHTHEAVY 1

typedef struct tree {
    int val;
    struct tree *left,*right;
}Tree;

Tree* insert (Tree *t, int val);
Tree* leftRotation (Tree *t);
void inorder(Tree *t);
void preorder(Tree *t);
int max (int a, int b);
int height (Tree *t);
Tree* rightRotation (Tree *t);
Tree* checkBalance (Tree *t);
Tree* rightAndLeftRotation(Tree *t);
Tree* leftAndRightRotation(Tree *t);


int height (Tree *t) {
    if (t) {            
        return max(height(t->left), height(t->right)) + 1;    
    }
    return 0;
}

int max (int a, int b) {
    
    return (a > b) ? a : b;
    
}

Tree* checkBalance(Tree *t) {
    
    int h;
    
    if(t->left != NULL && t->right != NULL)        
        h = height(t);
        
    if(height(t->left) - height(t->right) > 1) {
        if (height(t->left->left) - height(t->left->right) > 0) 
            t = rightRotation(t);
        else   
            t = leftAndRightRotation(t);
    }
    else  
        if(height(t->left) - height(t->right) < -1) {
            if (height(t->right->left) - height(t->right->right) < 0)
                t = leftRotation(t);
            else
                t = rightAndLeftRotation(t);
        }                            
    return t;
}


Tree* insert (Tree *t, int val) {
    
    if (t == NULL) {
        t = (Tree*) malloc(sizeof(Tree));
        t->val = val;
        t->left = NULL;
        t->right = NULL;
    }
    else {
        if (val > t->val) 
            t->right = insert(t->right, val);        
        else
            t->left = insert(t->left, val);
    }
    
    return t;
}

Tree* leftRotation (Tree *t) {
        
    Tree* aux = t->right;
    t->right = aux->left;
    aux->left = t;
    
    
    return aux;
    
}

Tree* rightRotation (Tree *t) {
    
    Tree *aux = t->left;
    t->left = aux->right;
    aux->right = t;
    
    return aux;
}

Tree* leftAndRightRotation(Tree *t) {
    t = leftRotation(t);
    return rightRotation(t);
}

Tree* rightAndLeftRotation(Tree *t) {
    t = rightRotation(t);
    return leftRotation(t);
}

void inorder(Tree *t) {

    if (t != NULL) {
        inorder(t->left);
        printf("%d ",t->val);
        inorder(t->right);
    }
}

void preorder(Tree *t) {
    
    if (t != NULL) {
        printf("%d ",t->val);
        preorder(t->left);
        preorder(t->right);
    }
}

int main () {
    
    Tree *t = NULL;
    t = insert(t, 1);
    t = insert(t, -1);
    t = insert(t, 7);
    t = insert(t, 40000);
    t = insert(t, 42000);
    t = insert(t, 45000);
    t = insert(t, 30);
    t = insert(t, 32);
    t = insert(t, 19);    
    preorder(t);
    printf("\n");
    t = checkBalance(t);
    inorder(t);    
    printf("\n");
    preorder(t);
    printf("\n");
    return 0;
}