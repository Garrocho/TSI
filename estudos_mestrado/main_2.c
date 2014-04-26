#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafo_2.h"

/* Obtem a quantidade de vertices */
int tam_arquivo(char* endereco) {
	FILE *arquivo;
	char linha[50];

	arquivo = fopen(endereco, "r");
	fgets(linha, 100, arquivo);
	fclose(arquivo);

	return atoi(linha);
}

/* Insere os vertices no grafo */
void ler_arquivo(char* endereco, Tipo_Grafo* grafo, int tamanho) {
	FILE *arquivo;
	char linha[50];
	char *partes;
	int vertice, aresta, distancia;

	arquivo = fopen(endereco, "r");
	fgets(linha, 100, arquivo);

	while (!feof(arquivo))
	{
		fgets(linha, 100, arquivo);
		partes = (char*)strtok(linha, " ");
		vertice = atoi(partes);
 		partes = (char*)strtok(NULL, " ");
 		aresta = atoi(partes);
 		partes = (char*)strtok(NULL, " ");
 		distancia = atoi(partes);
 		printf("%d %d %d\n", vertice, aresta, distancia);
 		insere_vertice(grafo, vertice, tamanho);
 		insere_aresta(grafo, vertice, aresta, distancia);
	}
	fclose(arquivo);
}

void main() {
    Tipo_Grafo *grafo;
    int tamanho = tam_arquivo("tspfase8.txt");
    grafo = cria_grafo(tamanho);
    ler_arquivo("tspfase8.txt", grafo, tamanho);
    termina_grafo(grafo, tamanho);
}