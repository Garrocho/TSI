/* 
 * File:   TabelaHash.h
 * Author: charles
 */

#ifndef TABELAHASH_H
#define	TABELAHASH_H

typedef struct
{
	int tamanho;
	int placa;
}tipo_elemento;

typedef struct nodo
{
	tipo_elemento info;
	struct nodo *prox;
}tipo_nodo;

typedef struct
{
	tipo_nodo *inicio;
	int tamanho;
}tipo_fila;

typedef tipo_fila *fila;

fila cria_fila(int);

void insere_item(fila,tipo_elemento);

void remove_item(fila,tipo_elemento);

void termina_fila(fila);

#endif	/* TABELAHASH_H */