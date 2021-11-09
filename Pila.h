#include <malloc.h>				//  Para la asignación (memory allocation) dinamica de memoria

struct Nodo 
{ 
	char info; 
	struct Nodo *sig; 
};

typedef struct Nodo nodo;

//  Prototipos
nodo *push(nodo *raiz, char dato);
void imprimePila(nodo *raiz);
nodo *pop(nodo *raiz, char *dato);
nodo *stackTop(nodo *tope, char *dato);
int isEmpty(nodo *tope);

nodo *push(nodo *raiz, char dato)		
{
	nodo *nuevo = NULL;			// Apuntador auxiliar para crear el nuevo nodo
	nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
	if( nuevo == NULL )			//  Error: Overflow!
	{
		printf("Error - Overflow: Ya no hay memoria disponible. \n");
		system("Pause");
		return NULL;          
	}
	nuevo -> info = dato;		//  Guardamos la información en el nodo
	nuevo -> sig = NULL;		//  No hay nodo delante..
	if( raiz == NULL )			//  ¿La lista está vacía?
	{							//  Verdadero: la lista está vacia
		raiz = nuevo;
	}
	else						//  Falso: la lista no esta vacía (al menos tiene 1 nodo)
	{
		nodo *ultimo = raiz;
		raiz = nuevo;
		raiz -> sig = ultimo;
	}
	return raiz;
}

void imprimePila(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre != NULL)		//  ¿Es el ultimo nodo?
	{							//  Verdadero: no es el ultimo nodo
		printf("%c, ", recorre->info);
		 recorre = recorre -> sig;	// Avanzo al diguiente nodo...
	}
	putchar('\n');
}

nodo *pop(nodo *raiz, char *dato)
{
	if(raiz != NULL)
	{
		nodo *siguiente = NULL, *anterior = NULL, *elimina = NULL;
		elimina = raiz;
		raiz = raiz -> sig;
		*dato = elimina -> info;
		free(elimina);
		return raiz;
	} 
	else
	{
		printf("Error - UnderFlow: No hay elementos en la lista. \n"); //  Error: Underflow!
		system("Pause");
		return NULL;   
	}
}

nodo *stackTop(nodo *tope, char *dato)
{
	if( isEmpty(tope) )
	{
		*dato = tope -> info;
		return tope;
	} 
	else
	{
		printf("Error - UnderFlow: No hay elementos en la lista. \n"); //  Error: Underflow!
		system("Pause");
		return NULL;   
	}
}

int isEmpty(nodo *tope)
{
	if(tope == NULL)	//  La pila está vacía?
		return 1;		//  Si, está vacía
	else
		return 0;		// No, tiene algo.
}