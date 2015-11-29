#include <stdio.h>

#ifndef libHeap
#define libHeap

 // Vetor[0] representa a quantidade de elemetos

int pai(int filho);

int filhoDir(int pai);

int filhoEsq(int pai);

int irmao(int filho);

void imprimirHeap(int* heap,int qnt);

int maior(int* heap,int a, int b);

void troca(int* heap, int a, int b);

void subir(int* heap,int subido);

void descer(int* heap,int descido);

void inserir(int* heap, int inserido);

void extracao(int* heap);


#endif