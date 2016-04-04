#ifndef PILA_H_
#define PILA_H_

#include <stdio.h>
#include <stdlib.h>


#define STACK_MAX 10000

struct Pila {
    int     x[STACK_MAX];
    int     y[STACK_MAX];
    int     size;
};
typedef struct Pila Pila;


void Pila_Init(Pila *S)
{
    S->size = 0;
}

int Pila_Top(Pila *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: Pila vacia\n");
        return -1;
    } 

    return 1;
}

void Push(Pila *S, int f, int c)
{
    if (S->size < STACK_MAX){
        S->x[S->size++] = f;
        S->y[S->size++] = c;
    }
    else
        fprintf(stderr, "Error: Pila llena\n");
}

void Pop(Pila *S)
{
    if (S->size == 0)
        fprintf(stderr, "Error: Pila vacia\n");
    else{
    	fprintf("   %d   %d,",x[S->size], y[S->size]);
    	S->size--;
    }
}

#endif // PILA_H_