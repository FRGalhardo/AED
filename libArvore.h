#include <stdlib.h>
#include <stdio.h>

#ifndef libArvore
#define libArvore


struct no
{
	int chave;
	struct no* esq;
	struct no* dir;
};

typedef struct no no;

no* criarNo(int chave);

void insereBinaria(no** raiz, int chave);

void mostrarArvore(no* raiz);

#endif