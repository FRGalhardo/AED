#include "libHeap.h"


int pai(int valFilho)
{
	return valFilho/2;
}

int filhoDir(int pai)
{
	return pai*2;
}

int filhoEsq(int pai)
{
	return (pai*2)+1;
}

int irmao(int filho)
{
	if(filho == 1) return 1;

	if(filho % 2 == 0)
	{
		return filho + 1;
	}
	else
	{
		return filho - 1;
	}
}

void imprimirHeap(int* heap,int qnt)
{
	int i = 0;
	qnt++;
	for(i;i <= qnt; i++)
	{
		printf("%d ", heap[i]);
	}
	printf("\n");
}

int maior(int* heap,int a, int b)
{
	if(heap[a] > heap[b])
	{
		return a;
	}
	else
	{
		return b;
	}
}

void troca(int* heap, int a, int b)
{
	int aux = heap[a];
	heap[a] = heap[b];
	heap[b] = aux;
}

void subir(int* heap,int subido)
{
	printf("%d\n", pai(subido));
	while(heap[subido] > heap[pai(subido)]) 
	{
		if(subido == 1) return;
		troca(heap, subido, pai(subido));
		subido = pai(subido);
	}
}

void descer(int* heap,int descido)
{
	int mai;
	while(heap[descido] < heap[filhoDir(descido)] || 
		heap[descido] < heap[filhoEsq(descido)])
	{
		int mai = maior(heap, filhoDir(descido), filhoEsq(descido));
		troca(heap, descido, mai);
		descido = mai;
	}
}

void inserir(int* heap, int inserido)
{
	int qnt = heap[0];

	qnt++;

	heap[0] = qnt;

	heap[qnt] = inserido;

	subir(heap, qnt);
}

void extracao(int* heap)
{
	int qnt = heap[0];

	heap[1] = heap[qnt];

	heap[qnt] = 0;

	descer(heap, 1);

	qnt--;

	heap[0] = qnt;
}

