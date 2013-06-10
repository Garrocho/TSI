#include <stdlib.h>
#include <stdio.h>
#include "Funcoes.h"

int criaLista(lista *a,int x,int y)
{
	int i;
	a = (lista*)malloc(sizeof(lista));
	if (!a)
		return 0;
	(*a)->inicio = NULL;
	(*a)->linha = x;
	(*a)->coluna = y;
	for (i = 0;i < (*a)->coluna;i++)
	{
		inicializaColuna(*a,i,1);
		inicializaLinha(*a,1,i);
	}
	return 1;
}

int inicializaColuna(lista *a,int coluna,int linha)
{
	int i;
	tipo_nodo *p,*aux;
	p = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	aux = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	if (!p || coluna > (*a)->coluna)
		return 0;
	p->abaixo = NULL;
	p->valor = -1;
	p->direita = NULL;
	p->coluna = coluna;
	p->linha = linha;
	aux = (*a)->inicio;
	if ((*a)->inicio == NULL)
	{
		aux = p;
		return 1;
	}
	for (i = 0;i < coluna;i++)
	{
		if (aux->coluna+1 == coluna)
		{
			aux->abaixo = p;
			return 1;
		}
		aux = aux->abaixo;
	}
	return 0;
}

int inicializaLinha(lista *a,int coluna,int linha)
{
	int i;
	tipo_nodo *p,*aux;
	p = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	aux = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	if (!p || coluna > (*a)->coluna)
		return 0;
	p->abaixo = NULL;
	p->valor = -1;
	p->direita = NULL;
	p->coluna = coluna;
	p->linha = linha;
	aux = (*a)->inicio;
	for (i = 0;i < coluna;i++)
	{
		if (aux->linha+1 == linha)
		{
			aux->direita = p;
			return 1;
		}
		aux = aux->direita;
	}
	return 0;
}

int insereValor(int linha,int coluna,int valor,lista a)
{
	int l,c;
	tipo_nodo *lin,*col,*p;
	p = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	col = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	lin = (tipo_nodo*)malloc(sizeof(tipo_nodo));
	if (!lin || !col || !p)
		return 0;
	p->valor = valor;
	p->coluna = coluna;
	p->linha = linha;
	p->abaixo =	NULL;
	p->direita = NULL;
	lin = a->inicio;
	col = a->inicio;
	for (l = 0;l < linha;l++)
	{
		if (lin->linha == linha)
		{
			if (lin->abaixo == NULL)
			{
				lin->abaixo = p;
				for (c = 0;c < coluna;c++)
				{
					if (col->coluna == coluna)
					{
						if (col->direita == NULL)
						{
							col->direita = p;
							return 1;
						}
						else
						{
							for (c = 0;c < linha;c++)
							{
								if (col->direita->linha > linha)
								{
									p->direita = col->direita;
									col->direita = p;
									return 1;
								}
								col = col->direita;
							}
						}
					}
					col = col->abaixo;
				}
			}
			else
			{
				for (l = 0;l < linha;l++)
				{
					if (lin->abaixo->l > linha)
				}
			}
		}

		lin = lin->direita;
	}
	

}

int leMatriz(lista a)
{
	int x,y,linha,coluna,valor,l,c;
	printf("Forneca o tamanho da matriz: ");
	scanf("%d%d",&x+1,&y);
	criaLista(&a,x,y);
	for (l = 0;l < a->linha;l++)
		insereValor(1,l,-1,a);
	for (l = 0;l < y;l++)
	{
		for (c = 0;c < y;c++)
		{
			printf("Forneca o %d valor da %d linha: ",c,l);
			scanf("%d%d%d",&linha,&coluna,&valor);
			insereValor(linha,coluna,valor,a);
		}
	}
	return 1;
}

int imprimeMatriz(lista);

int apagaMatriz(lista);

int somaMatriz(lista,lista,lista);

int multiplicaMatriz(lista,lista,lista);