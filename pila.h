#ifndef PILA_H_
#define PILA_H_

#include <stdio.h>
#include <stdlib.h>


#define STACK_MAX 100

struct Pila {
    int     data[STACK_MAX];
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
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    } 

    return S->data[S->size-1];
}

void Push(Pila *S, int d)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Error: stack full\n");
}

void Pop(Pila *S)
{
    if (S->size == 0)
        fprintf(stderr, "Error: stack empty\n");
    else
        S->size--;
}

#endif // PILA_H_