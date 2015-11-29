#include "libHeap.h"
#include <stdio.h>

int main()
{
	int val, vet[20];
	vet[0] = 7;
	vet[1] = 54;
	vet[2] = 38;
	vet[3] = 36;
	vet[4] = 5;
	vet[5] = 20;
	vet[6] = 15;
	vet[7] = 34;

	
	imprimirHeap(vet, vet[0]);

	inserir(vet, 60);

	imprimirHeap(vet, vet[0]);

	return 0;
}