#include <stdio.h>
#include <stdlib.h>
#include "libOrdenacao.h"

int* alocarVetor(int tam)
{
	return (int*) malloc(tam * sizeof(int));
}

int main()
{
	int qNum,i;
	scanf("%d",&qNum);
	int* v = alocarVetor(qNum);
	for(i = 0; i < qNum; i++)
	{	
		scanf("%d",v + i);
	}
	bubbleSort(v, qNum);
	//selectionSort(v, qNum);
	//insertionSort(v, qNum);
	for(i = 0; i < qNum; i++)
	{	
		printf("%d ",*(v + i));
	}
	printf("\n");
	return 0;
}