#define STACK_MAX 100

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

void Pop(Pila *S, FILE *f)
{
    if (S->size == 0)
        fprintf(stderr, "Error: Pila vacia\n");
    else{
    	fprintf(f, "   %d   %d,",S->x[S->size], S->y[S->size]);
    	S->size--;
    }
}