#include "Funcoes.h"
#include <stdlib.h>

pilhas cria_pilhas()
{
	pilhas p;
	p = (pilhas)malloc(sizeof(tipo_pilhas));
	if (!p)
		return 0;
	p->inicio = NULL;
	p->tamanho = 0;
	return p;
}

void termina_pilhas(pilhas *p)
{
	int i;
	tipo_nod *a,*b;
	a = (*p)->inicio;
	b = (*p)->inicio;
	for (i = 0;i < (*p)->tamanho;i++)
	{
		b = a->prox;
		free(a);
		a = b;
	}
	free(*p);
	return;
}

int colocar_item(pilhas p, char e)
{
	int i;
	tipo_nod *a,*b;
	a = (tipo_nod*)malloc(sizeof(tipo_nod));
	b = (tipo_nod*)malloc(sizeof(tipo_nod));
	if (!a || !b)
		return 0;
	b = p->inicio;
	a->elemento = e;
	a->prox = NULL;
	if (p->inicio == NULL)
	{
		p->inicio = a;
		p->tamanho++;
		return 1;
	}
	while(b != NULL)
	{
		if (b->prox == NULL)
		{
			b->prox = a;
			p->tamanho++;
			return 1;
		}
		b = b->prox;
	}
}

lista cria_item()
{
	lista l;
	l = (lista)malloc(sizeof(tipo_lista));
	if (!l)
		return 0;
	l->inicio = NULL;
	l->fim = NULL;
	l->tamanhofim = 0;
	l->tamanhoInicio = 0;
	l->tamanhoTotalFim = 0;
	l->tamanhoTotalInicio = 0;
	return l;
}

int termina_item(lista l)
{
	int i = 0;
	tipo_item *b,*a;
	a = l->inicio;
	b = l->inicio;
	while (i < l->tamanhoInicio)
	{
		if (l->inicio->prox == NULL)
		{
			l->inicio = NULL;
			l->tamanhoTotalInicio--;
			free(a);
			i = 0;
			a = l->fim;
			b = l->fim;
			if (l->fim->prox == NULL)
			{
				l->fim = NULL;
				l->tamanhoTotalFim--;
				free(a);
				return 1;
			}
			while (i < l->tamanhoTotalFim)
			{
				if (a->prox == NULL)
				{
					b->prox = NULL;
					free(a);
					l->tamanhoTotalFim--;
					return 1;
				}
				b = a;
				a = a->prox;
			}
		}
		else
		{
			i = 0;
			while (i < l->tamanhoTotalInicio)
			{
				if (a->prox == NULL)
				{
					b->prox = NULL;
					free(a);
					l->tamanhoTotalInicio--;
					i = 0;
					a = l->fim;
					b = l->fim;
					if (l->fim->prox == NULL)
					{
						l->fim = NULL;
						l->tamanhoTotalFim--;
						free(a);
						return 1;
					}
					while (i < l->tamanhoTotalFim)
					{
						if (a->prox == NULL)
						{
							b->prox = NULL;
							free(a);
							l->tamanhoTotalFim--;
						}
						b = a;
						a = a->prox;
					}
				}
				b = a;
				a = a->prox;
			}
		}
	}
}

int colocar_item(lista l,char e,int n)
{
	int i = 0;
	tipo_item *b;
	if (n == 1)
	{
		b = l->inicio;
		while (i < l->tamanhoInicio)
		{
			if (b->prox == NULL)
			{
				b->palavra[l->tamanhoInicio++] = e;
				return 1;
			}
			b = b->prox;
			i++;
		}
	}
	if (n == 2)
	{
		b = l->fim;
		while (i <l->tamanhofim)
		{
			if (b->prox == NULL)
			{
				b->palavra[l->tamanhofim++] = e;
				return 1;
			}
			b = b->prox;
		}
	}
}

int adicionar_item(lista l,int n)
{
	int i = 0;
	tipo_item *a,*b;
	b = (tipo_item*)malloc(sizeof(tipo_item));
	a = (tipo_item*)malloc(sizeof(tipo_item));
	if (!a || !b)
		return 0;
	a->prox = NULL;
	if (n == 1)
	{
		if (l->tamanhoTotalInicio == 0)
		{
			l->inicio = a;
			l->tamanhoTotalInicio++;
			return 1;
		}
		b = l->inicio;
		while (i < l->tamanhoTotalInicio)
		{
			if (b->prox == NULL)
			{
				b->prox = a;
				l->tamanhoTotalInicio++;
				return 1;
			}
			b = b->prox;
		}
	}
	i = 0;
	if (n == 2)
	{
		if (l->tamanhoTotalFim == 0)
		{
			l->fim = a;
			l->tamanhoTotalFim++;
			return 1;
		}
		b = l->fim;
		while (i < l->tamanhoTotalFim)
		{
			if (b->prox == NULL)
			{
				b->prox = a;
				l->tamanhoTotalFim++;
				return 1;
			}
			b = b->prox;
		}
	}
}

char *fim(lista l,int n)
{
	int i = 0;
	tipo_item *b;
	if (n == 1)
	{
		b = l->inicio;
		while (i < l->tamanhoTotalInicio)
		{
			if (b->prox == NULL)
			{
				return b->palavra;
			}
			b = b->prox;
		}
	}
	if (n == 2)
	{
		b = l->fim;
		while (i < l->tamanhoTotalFim)
		{
			if (b->prox == NULL)
			{
				return b->palavra;
			}
			b = b->prox;
		}
	}
}