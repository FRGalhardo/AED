#include "libOrdenacao.h"
#include <stdio.h>	

void troca(int* v, int* p1, int* p2)
{
	int aux;
	aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}

void arrastaVetor(int* v, int w, int aInserir)
{
	int aux = *(v + aInserir);
	aInserir--;
	while(aInserir >= w)
	{
		*(v + (aInserir + 1)) = *(v + aInserir);
		aInserir--;
	}
	*(v + w) = aux;
}

void bubbleSort(int* v, int tam)
{
	int u, i;
	u = tam - 1;
	while(u > 0)
	{
		for(i = 0; i < (tam - 1); i++)
		{
			if(*(v + i) > *(v + (i+1)))
			{
				troca(v, (v + i), (v + (i + 1)));
			}
		}
		u--;
	}
}

void selectionSort(int* v, int tam)
{
	int menor, u = 0, i, pos;
	while(u < (tam - 1))
	{
		menor = 99999999; 
		for(i = u; i <= (tam - 1); i++)
		{
			if(*(v + i) < menor)
			{
				menor = *(v + i);
				pos = i;
			}
		}
		troca(v, (v + u), (v + pos));
		u++;
	}
}

void insertionSort(int* v, int tam)
{
	int qOrdenados, aInserir, aux, i, w;
	int* pos;
	aInserir = 1;
	aux = 0;
	while(aInserir <= (tam - 1))
	{
		w = aInserir - 1;
		//while(v[aInserir] < v[w] && w >= 0)
		while((*(v + aInserir) < *(v + w)) && w >= 0) 
		{
			w--;
		}
		arrastaVetor(v, w + 1, aInserir);
		aInserir++;
	}
}

void merge(int* v, int ini, int meio, int fim)
{
	int* rascunho = (int*) malloc((fim - ini + 1) * sizeof(int));
	if(rascunho == NULL)
	{
		printf("FAIL!");
		return;
	}
	int i, dir, esq, x;
	dir = meio + 1;
	esq = ini;
	i = 0;
	while((esq <= meio) && (dir <= fim))
	{
		if(*(v + esq) < *(v + dir))
		{
			*(rascunho + i) = *(v + esq);
			esq++;
		}
		else
		{
			*(rascunho + i) = *(v + dir);
			dir++;
		}
		i++;
	}
	if(esq > meio)
	{
		while(dir <= fim)
		{
			*(rascunho + i) = *(v + dir);
			dir++;
			i++;
		}
	}
	else
	{
		while(esq <= meio)
		{
			*(rascunho + i) = *(v + esq);
			esq++;
			i++;
		}
	}
	for(i = ini, x = 0; i <= fim; i++, x++)
	{
		*(v + i) = *(rascunho + x);
	}

	free(rascunho);
}

void mergeSort(int* v, int ini, int fim)
{
	int i;
	if((fim - ini) >= 1)
	{
		int meio; 	
		meio = ((ini + fim) / 2);
		mergeSort(v, ini, meio);
		mergeSort(v, meio + 1, fim);
		merge(v, ini, meio, fim);
	}
}

void quickSort(int* v, int ini, int fim)
{
	int pivot, bMa, bMe, a;

	pivot = ini; 
	bMa = ini+1;
	bMe = fim;

	//printf(">>>%d %d\n", ini, fim);

	if(ini >= fim)
	{
		return;
	}

	while(bMa < bMe)
	{
		//printf("====%d %d\n", bMe, bMa);
		while((*(v + bMa) < *(v + pivot)) && (bMa <= bMe))
		{
			bMa++;
		}

		while((*(v + bMe) > *(v + pivot)) && (bMa <= bMe))
		{
			bMe--;
		}

		if(bMa < bMe){
			troca(v, (v + bMa), (v + bMe));
			bMa++;
			bMe--;
		}
	
	}
	if(bMe - 1 > 0)
		a = bMe - 1;
	else
		a = 0;
	troca(v, (v + bMe), (v + pivot));
	quickSort(v, ini, a); // (((bMe - 1) > 0)?(bMe - 1):0));
	quickSort(v, bMe + 1, fim);
}