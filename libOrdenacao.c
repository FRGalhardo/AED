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