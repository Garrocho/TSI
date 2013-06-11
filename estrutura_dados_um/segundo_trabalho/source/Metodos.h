// @author: Charles Tim Batista Garrocho
// @contact: charles.garrocho@gmail.com
// @copyright: (C) 2013 Software Open Source

#ifndef METODOS_H
#define METODOS_H

#include <stdio.h>

typedef int tipo_chave;

typedef struct 
{
	tipo_chave chave;
    char endereco[100];
}tipo_item;

tipo_item *criaVetor(int tamanho);

void Particiona(tipo_item *A, int Esq, int Dir,int *i, int *j);

void bubbleSort(tipo_item* v, int n );

void selectSort(tipo_item* v, int n );

void insertSort(tipo_item* v, int n );

void shellSort(tipo_item* A, int n );

void heapSort(tipo_item* V, int n );

void quickSort(tipo_item* V, int n );

void constroi(tipo_item* V, int posicao, int n );

void particao(tipo_item *V, int e, int d);

void QuickSortNaoRec(tipo_item *v, int tamanho);

void quickSortMediana3(tipo_item *v, int tamanho);

void particao3(tipo_item *v, int esq, int dir);

void quickSortMenor20(tipo_item *v, int tamanho);

void quickSortInsert(tipo_item *v, int tamanho);

void particaoInsert(tipo_item *v, int esq, int dir);

void insertSortSeguimento(tipo_item *v, int esq, int dir);

#endif
