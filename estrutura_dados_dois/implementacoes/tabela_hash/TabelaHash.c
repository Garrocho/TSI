/*
 * File:   TabelaHash.h
 * Author: charles
 */

#include <stdio.h>
#include <stdlib.h>

fila cria_fila(int c)
{
	fila auxFila;
	auxFila = (fila)malloc(sizeof(fila));
	if (!auxFila)
		return NULL;
	auxFila->inicio = NULL;
	auxFila->tamanho = c;
	return auxFila;
}

void insere_item(fila auxFila,tipo_elemento elemento)
{
	tipo_nodo *auxNodo;
	auxNodo = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	if (!auxNodo)
		return ;
	auxNodo->info = elemento;
	if ((auxFila->tamanho == 0) && (auxNodo->info.tamanho <= auxFila->tamanho))
	{
		auxFila->inicio = auxNodo;
		auxFila->tamanho -= auxNodo->info.tamanho;
	}
	else
	{
		tipo_nodo *antNodo;
		antNodo = (tipo_nodo*)malloc(sizeof(tipo_nodo));
		if (!antNodo)
			return ;
		int sair;
		sair = 0;
		antNodo = auxFila->inicio;
		do {
			if ((!antNodo->prox) && (auxNodo->info.tamanho <= auxFila->tamanho))
			{
				antNodo->prox = auxNodo;
				auxFila->tamanho -= auxNodo->info.tamanho;
				sair = 1;
				return;
			}
			antNodo = antNodo->prox;
		}while(sair != 1);
	}
	return;
}

void remove_item(fila auxFila,tipo_elemento elemento)
{
	tipo_nodo *antNodo;
	tipo_nodo *auxNodo;
	antNodo = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	auxNodo = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	if (!antNodo || !auxNodo)
		return;
	auxNodo = auxFila->inicio;
	antNodo = auxNodo;
	do {
		if (auxNodo->info.placa == elemento.placa)
		{
			antNodo->prox = auxNodo->prox;
			auxFila->tamanho += elemento.tamanho;
			free(auxNodo);
			return;
		}
		antNodo = auxNodo;
		auxNodo = auxNodo->prox;
	}while(antNodo->prox);
        return;
}

void termina_fila(fila auxFila)
{
	tipo_nodo *antNodo;
	tipo_nodo *auxNodo;
	antNodo = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	auxNodo = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	if (!antNodo || !auxNodo)
		return;
	auxNodo = auxFila->inicio;
	antNodo = auxNodo;
	do {
		antNodo = auxNodo;
		free(auxNodo);
		auxNodo = antNodo->prox;
	}while(antNodo->prox);
	free(auxFila);
	return;
}