#include <time.h>
#include "pila.h"

void delay (int seg);
void imprime();
int resolver(Pila *s, int f, int c  );
int resolverVerbose(Pila *s, int f, int c);
void direccionarArchivo(Pila *s);

#define fila 10
#define columna 10
int posic[fila][columna] =
   { { 'X','X','X','X','X','X','X','X','X','X'},
     { 'X',' ',' ','X',' ','X',' ',' ',' ','X'},
     { 'X',' ',' ','X',' ',' ',' ','X',' ','X'},
     { 'X',' ',' ',' ',' ','X','X','X',' ','X'},
     { 'X',' ','X','X','X','X',' ',' ',' ','X'},
     { 'X',' ',' ',' ','X',' ',' ','X','X','X'},
     { 'X',' ','X','X','X','X',' ','X',' ','X'},
     { 'X',' ','X',' ',' ',' ',' ',' ',' ','X'},
     { 'X',' ','X',' ','X','X','X','X',' ','X'},
     { 'X','X','X',' ','X','X','X','X','X','X'}
   };

   
int main(int argc, char const *argv[])
{
	Pila *s;
	Pila_Init(s);

	if(argv[2]=='v'){
		if(resolverVerbose(s, atoi(argv[3]), atoi(argv[4])))
			printf("\n\nLaberinto Resuelto!!");
		else
			printf("\n\nNo se encontro salida ;-;");
	}else{
		if(resolver(s, atoi(argv[2]), atoi(argv[3])))
			printf("\n\nLaberinto Resuelto!!");
		else
			printf("\n\nNo se encontro salida ;-;");
	}

	return 0;
}

void delay(int seg){
	time_t comienza = time ((time_t *)0);
  	double lapso = 0;

  	while (lapso < seg) {
    	time_t finish = time ((time_t *)0); // algoritmo para el retraso de un segundo con time.h
    	lapso = difftime (finish, comienza);
  	}
}

void imprime() {
   	int i, j;
	delay(1);
   	system("cls");
   	for (i=0; i<fila; i++) {
    	for (j=0; j<columna; j++) {
         	printf("%c ", posic[i][j]);
      	}
      	printf("\n");
   	}

   return;
}

int resolver(Pila *s, int f, int c  ){
	posic[f][c]='*';
	Push(s, f, c);

    if( f == 0 || c ==0  || f==fila-1 || c == columna-1 ){//si se esta al borde del arreglo, se encuentra la salida
        return 1; 
    }// se prueban las opciones de dirección (arriba, derecha, abajo, izquierda)
    if( posic[f-1][c]==' '){
        if( resolver(f-1,c)==1 )
            return 1;
    }
    if( posic[f][c+1]==' '){
        if( resolver(f,c+1)==1 )//se vuelve a llamar la funcion con un cambio en el parámetro
            return 1;
    }
    if( posic[f+1][c]==' '){
        if( resolver(f+1,c)==1 )
            return 1;
    }
    if( posic[f][c-1]==' '){
        if( resolver(f,c-1)==1 )//si se llega al final el valor de retorno es 1, de lo contrario se encerró y el valor es 0
            return 1;
    }
    posic[f][c]='*';
    direccionarArchivo(s);
    return 0; //Se quedó encerrado, no hay salida
}

int resolverVerbose(Pila *s, int f, int c){
	posic[f][c]='*';
	Push(s, f, c);
    imprime();

    if( f == 0 || c ==0  || f==fila-1 || c == columna-1 ){//si se esta al borde del arreglo, se encuentra la salida
        return 1; 
    }// se prueban las opciones de dirección (arriba, derecha, abajo, izquierda)
    if( posic[f-1][c]==' '){
        if( resolver(f-1,c)==1 )
            return 1;
    }
    if( posic[f][c+1]==' '){
        if( resolver(f,c+1)==1 )//se vuelve a llamar la funcion con un cambio en el parámetro
            return 1;
    }
    if( posic[f+1][c]==' '){
        if( resolver(f+1,c)==1 )
            return 1;
    }
    if( posic[f][c-1]==' '){
        if( resolver(f,c-1)==1 )//si se llega al final el valor de retorno es 1, de lo contrario se encerró y el valor es 0
            return 1;
    }
    posic[f][c]='*';
    direccionarArchivo(s);
    return 0; //Se quedó encerrado, no hay salida
}

void direccionarArchivo(Pila *s){
	FILE *f;
	f=fopen(salida.txt, "+w");

	while(Pila_Top(s)!=-1){
		Pop(s);
	}

	fclose(f);
}