#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 100

struct Pila {
    int     x[STACK_MAX];
    int     y[STACK_MAX];
    int     size;
};
typedef struct Pila Pila;

void Pila_Init(Pila *S);
int Pila_Top(Pila *S);
void Push(Pila *S, int f, int c);
void Pop(Pila *S, FILE *f);

#endif // PILA_H_