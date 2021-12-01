// Sesion 35 - 09/11/2021

#include <stdio.h>				//   Para la I/O del programa (entrada / Salida)
#include <stdlib.h>				//  Para las funcionesde utilería P.E. system();
#include <string.h>
#include "Pila.h"


int main()
{
	nodo *pila = NULL;
	datos var1;
	datos var2;

	//  Guardando  en la pila
	var1.car = 'R';
	pila = push(pila, var1);

	imprimePila(pila);

	var2.num = 3.14159;
	pila = push(pila, var2);

	imprimePila(pila);

	// sacando de la pila
	pila = pop(pila, &var1);
	printf("Valor que salio: %7.3f\n", var1.num);

	pila = pop(pila, &var1);

	printf("Valor que salio: %c\n", var1.car);

	system("pause");
	return 1;
}