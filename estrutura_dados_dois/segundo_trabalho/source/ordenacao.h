/* Arquivo: ordenacao.h
 * Descrição: Este Arquivo Define as Estrutura Utilizadas para a ordenação de palavras.
 * Autor: Charles Tim Batista Garrocho
 * Data: 08/06/2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef int tipo_chave;

typedef struct
{
        char palavra[TAM_PALAVRA];
}tipo_elemento;

typedef struct
{
    char palavra[TAM_PALAVRA];
}tipo_vocabulario;

typedef struct
{
   tipo_elemento elemento[TAM_BUFFER/2]; // Elemento atual retirado da run.
   int  posicao, // Posicao atual na run.
        posbuff, // Posicao atual no buffer de elementos.
        ultimo; // Ultima posicao valida da run.
   FILE *arqBuffer; // Referencia ao arquivo da run.
}tipo_buffer;

typedef struct
{
    tipo_elemento e;
    int run; // Run do elemento.
}fila;

// Organiza o buffer pela palavra.
int quickSort(int e, int d, tipo_elemento buffer[]);

// Auxilia o heapsort.
int organiza(fila v[], int size, int posicao);

// Heapsort para ordenar a fila de prioridades.
int heap_sort(fila v[], int size);

// Cria uma nova Run e libera o Buffer.
int criaRun(tipo_elemento buffer[], int numRuns, int j);

#endif /* ORDENACAO_H */
