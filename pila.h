#ifndef PILA_H_
#define PILA_H_

#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 100
int ELEMENTOS = 0;

enum boolean {false,true};

typedef struct Nodo{
     int x;
     int y;
     struct Nodo* ap;
}Nodo;

Nodo* tope=NULL;

Nodo* crearNodo(int f, int c){
     Nodo* nuevo= (Nodo *)malloc(sizeof(Nodo));
     nuevo->ap=NULL;
     nuevo->x=f;
     nuevo->y=c;
     return nuevo;
}

enum boolean push(Nodo* nodo){
     if(ELEMENTOS==MAXIMO)
          return false;
     else{
          nodo->ap=tope;
          tope=nodo;
          ELEMENTOS++;
          return true;
     }
}

int pop(FILE *f){
     if(tope==NULL)
          return 0;
     else{
          Nodo* tmp;
          tmp=tope;
          tope=tope->ap;
          tmp->ap=NULL;          
          ELEMENTOS--;
          fprintf(f,"%d   %d,",tmp->x, tmp->y);
          return 1;
     }
}

#endif // PILA_H_