#include <stdio.h>

void bubble_sort(int *vetor, int tamanho) {
	int i, j, aux;
	for (i=tamanho-1; i > 1; i--)
		for (j=0; j < i; j++)
			if (vetor[j] > vetor[j+1]) {
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
};

void insertion_sort(int *vetor, int tamanho) {
	int i, j, aux;
	for (i=1; i < tamanho; i++) {
		j = i;
		while (j > 0 && vetor[j] < vetor[j-1]) {
			aux = vetor[j];
			vetor[j] = vetor[j-1];
			vetor[j-1] = aux;
			j = j-1;
		}
	}
};

void selection_sort(int *vetor, int tamanho) {
	int i, j, menor, aux;
	for (i=0; i < tamanho; i++) {
		j = i+1;
		menor = i;
		while (j < tamanho) {
			if (vetor[j] < vetor[menor])
				menor = j;
			j++;
		}
		aux = vetor[menor];
		vetor[menor] = vetor[i];
		vetor[i] = aux;
	}
};