// Sesion 35 - 09/11/2021

#include <stdio.h>				//   Para la I/O del programa (entrada / Salida)
#include <stdlib.h>				//  Para las funcionesde utilería P.E. system();
#include "Pila.h"


int main()
{
	nodo *tope = NULL;
	char dato;

	tope = push(tope, 'R');
	tope = push(tope, 'o');
	tope = push(tope, 'b');
	tope = push(tope, 'e');
	tope = push(tope, 'r');
	tope = push(tope, 't');
	tope = push(tope, 'o');

	imprimePila(tope);

	tope = pop(tope, &dato);
	printf("El ddato que salió fue %c\n", dato);
	imprimePila(tope);
	
	system("pause");
	return 1;
}