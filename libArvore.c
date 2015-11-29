#include "libArvore.h"

no* criarNo(int chave)
{
	no* folha = (no*) malloc(sizeof(no));
	if(folha == NULL)
	{
		return  NULL;
	}
	folha->chave = chave;
	folha->dir = NULL;
	folha->esq = NULL;
	return folha;
}

no** buscarBinaria(no** raiz, int chave)
{
	if(*(raiz)->chave == chave)
	{
		return raiz;
	}
	else
	{
		if(*(raiz)->chave > chave)
		{
			buscarBinaria(raiz->esq,chave);
		}
		else
		{
			if(*(raiz)->chave < chave)
			{
				buscarBinaria(raiz->dir,chave);
			}
			else
			{
				return NULL;
			}
		}
	}
}

no** buscaEndPonteiroMenor(no** raiz)
{	

	if(*(raiz)->esq != NULL)
	{
		buscaEndPonteiroMenor(&(*(raiz)->esq));	
	}
	return raiz;
}


void insereBinaria(no** raiz, int chave)
{
	if((*raiz) == NULL)
	{
		*raiz = criarNo(chave);
	}
	else
	{
		if(chave > (*raiz)->chave)
		{
			insereBinaria(&(*raiz)->dir, chave);
		}
		else
		{
			insereBinaria(&(*raiz)->esq, chave);
		}
	}
}

void mostrarArvore(no* raiz)
{
	if(raiz != NULL)
	{
		mostrarArvore((raiz)->esq);
		printf("%d \n", (raiz)->chave);
		mostrarArvore((raiz)->dir);
	}
}

int verificaDir(no* raiz)
{
	return (raiz->dir != NULL) ? 1 : 0;
}

int verificaEsq(no* raiz)
{
	return (raiz->esq != NULL) ? 1 : 0;
}

int verificaDoisFilhos(no* raiz)
{
	
	return (verificaDir(raiz) && verificaEsq(raiz)) ? 1 : 0;
}

no** acharMenorDaDireita(no** raiz)
{
	if(*(raiz)->esq != NULL)
	{
		acharMenorDaDireita(&(*(raiz)->esq));
	}
	return raiz;
}
]
void removerFolha(no** raiz)
{
	free(*raiz);
	*(raiz) = NULL;
}

void removerUmFilho(no** raiz)
{
	if()
	{

	}
}

void removerNo(no** raiz)
{
	no** subs = NULL;
	no* aux = NULL;

	if(verificaEsq() || verificaDir())
	{
		removerUmFilho(raiz);

		if(verificaDoisFilhos())
		{
			removeNo(raiz);
		}
	}
	else
	{
		removerFolha(raiz);
	}
}

void removerBinaria(no** raiz, int chave)
{
	if(raiz == NULL)
	{
		return;
	}
	else
	{
		if((*raiz)->chave == chave)
		{
			removerRaiz(raiz);
		}
		else
		{
			if((*raiz)->chave >= chave)
			{
				removerBinaria(&((*raiz)->esq), chave);
			}
			else
			{
				if(*(raiz)->chave < chave)
				{
					removerBinaria(&((*raiz)->dir), chave);
				}
			}
		}
	}
}