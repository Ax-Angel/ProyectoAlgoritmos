#include "pila.h"
#include <time.h>
#include <string.h>
#define archivo "ejemploLaberinto1.txt"

void cualDimension();
char **creaMatriz(int ene, int eme);
void guardaLaberinto();

FILE *f;
int i,j,ene=0,eme=0;
char **matriz1,c;

void delay (int seg);
void imprime();
int resolver(Nodo *s, int f, int c  );
int resolverVerbose(Nodo *s, int f, int c);
void direccionarArchivo(Nodo *s);

int main(int argc, char const *argv[])
{
    cualDimension();
    posic=creaMatriz(ene,ene);
    guardaLaberinto();

    eme=ene;

	Nodo *s;
	char ch[1];
	strcpy(ch, argv[1]);

	if(ch[0]=='v'){
		push(crearNodo(atoi(argv[2]), atoi(argv[3])));
		if(resolverVerbose(s, atoi(argv[2]), atoi(argv[3])))
			printf("\n\nLaberinto Resuelto!!\n");
		else
			printf("\n\nNo se encontro salida ;-;\n");
	}else{
		push(crearNodo(atoi(argv[1]), atoi(argv[2])));
		if(resolver(s, atoi(argv[1]), atoi(argv[2])))
			printf("\n\nLaberinto Resuelto!!\n");
		else
			printf("\n\nNo se encontro salida ;-;\n");
	}

	return 0;
}

void delay (int seg)
{
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
   	system("clear");
   	for (i=0; i<fila; i++) {
     	for (j=0; j<columna; j++) {
        	 printf("%c ", posic[i][j]);
    	  }
     	printf("\n");
   }
   return;
}

int resolver(Nodo *s, int f, int c  ){
	 posic[f][c]='O';
	 push(crearNodo(f, c));

    if( f == 0 || c ==0  || f==fila-1 || c == columna-1 ){//si se esta al borde del arreglo, se encuentra la salida
        return 1; 
    }// se prueban las opciones de dirección (arriba, derecha, abajo, izquierda)
    if( posic[f-1][c]==' '){
        if( resolver(s,f-1,c)==1 )
            return 1;
    }
    if( posic[f][c+1]==' '){
        if( resolver(s,f,c+1)==1 )//se vuelve a llamar la funcion con un cambio en el parámetro
            return 1;
    }
    if( posic[f+1][c]==' '){
        if( resolver(s,f+1,c)==1 )
            return 1;
    }
    if( posic[f][c-1]==' '){
        if( resolver(s,f,c-1)==1 )//si se llega al final el valor de retorno es 1, de lo contrario se encerró y el valor es 0
            return 1;
    }
    posic[f][c]='O';
    push(crearNodo(f, c));
    	direccionarArchivo(s);
    return 0; //Se quedó encerrado, no hay salida
}

int resolverVerbose(Nodo *s, int f, int c){
	posic[f][c]='O';
	push(crearNodo(f, c));
    imprime();

    if( f == 0 || c ==0  || f==fila-1 || c == columna-1 ){//si se esta al borde del arreglo, se encuentra la salida
        return 1; 
    }// se prueban las opciones de dirección (arriba, derecha, abajo, izquierda)
    if( posic[f-1][c]==' '){
        if( resolverVerbose(s,f-1,c)==1 )
            return 1;
    }
    if( posic[f][c+1]==' '){
        if( resolverVerbose(s,f,c+1)==1 )//se vuelve a llamar la funcion con un cambio en el parámetro
            return 1;
    }
    if( posic[f+1][c]==' '){
        if( resolverVerbose(s,f+1,c)==1 )
            return 1;
    }
    if( posic[f][c-1]==' '){
        if( resolverVerbose(s,f,c-1)==1 )//si se llega al final el valor de retorno es 1, de lo contrario se encerró y el valor es 0
            return 1;
    }
    posic[f][c]='O';
    push(crearNodo(f, c));
    direccionarArchivo(s);
    return 0; //Se quedó encerrado, no hay salida
}

void direccionarArchivo(Nodo *s){
	FILE *a;
	f=fopen("salida.txt", "wb");

	while(pop(a)!=0){
	}

	fclose(a);
}

FILE *f;
int i,j,ene=0,eme=0;
char **matriz1,c;

void cualDimension(){
    f= fopen(archivo,"r");
    ene=1;
    if(f==0){
        printf("No es posible leer el archivo.\n");
        return;
    }
    
    while(!feof(f)){
        do{
        c = fgetc(f);
            if(c=='\n'){
                ene++;
            }
        }while(c!=EOF);
    }   
    fclose(f);
}

char **creaMatriz(int ene, int eme){
    char **ap,i;
    ap=(char**)malloc(ene*sizeof(char*));

    for(i=0;i<ene;i++){
        ap[i]=(char*)malloc(eme*sizeof(char));
    }
    return ap;
}

void guardaLaberinto(){
    ene=0;
    f= fopen(archivo,"r");

    while(!feof(f)){
        do{
        c = fgetc(f);

            if (c=='0' ||  c=='1'){
                *(*(matriz1+ene)+eme)=c;
                eme++;
            }else if(c=='\n'){
                eme=0;
                ene++;
            }
    
        }while(c!=EOF);
    }
    fclose(f);
}