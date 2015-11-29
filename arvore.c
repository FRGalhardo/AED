#include "libArvore.h"
#include <stdio.h>

int main()
{
	int chave = 0;
	no* raiz = NULL;
	printf("Digite um valor:\n");
	scanf("%d", &chave);
	insereBinaria(&raiz,chave);
	mostrarArvore(raiz);
}