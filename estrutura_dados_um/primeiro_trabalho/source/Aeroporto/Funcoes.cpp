#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Funcoes.h"

void setAux(int *aux)
{
	int i;
	for (i = 0; i < 63; i++)
	{
		aux[i] = -1;
	}
}

fila* criaFila(void)
{
	fila* f = (fila*) malloc(sizeof(fila));
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}

int filaVazia(fila* f)
{
	return ( f->inicio==NULL );
}

Voo* criaVoo(fila* fila, int indicadorDP, int combustivel, int indiceVoo)
{ /*cria voo a ser inserido ao final da lista*/
	Voo* p = (Voo*) malloc(sizeof(Voo));
	char *Voos[64] ={ "VG3001\0", "JJ4404\0", "LN7001\0", "TG1501\0",
	"GL7602\0", "TT1010\0", "AZ1009\0", "AZ1008\0", "AZ1010\0",
	"TG1506\0", "VG3002\0", "JJ4402\0", "GL7603\0", "RL7880\0",
	"AL0012\0", "TT4544\0", "TG1505\0", "VG3003\0", "JJ4403\0",
	"JJ4401\0", "LN7002\0", "AZ1002\0", "AZ1007\0", "GL7604\0",
	"AZ1006\0", "TG1503\0", "AZ1003\0", "JJ4403\0", "AZ1001\0",
	"LN7003\0", "AZ1004\0", "TG1504\0", "AZ1005\0", "TG1502\0",
	"GL7601\0", "TT4500\0", "RL7801\0", "JJ4410\0", "GL7607\0",
	"AL0029\0", "VV3390\0", "VV3392\0", "GF4681\0", "GF4690\0",
	"AZ1020\0", "JJ4435\0", "VG3010\0", "LF0920\0", "AZ1065\0",
	"LF0978\0", "RL7867\0", "TT4502\0", "GL7645\0", "LF0932\0",
	"JJ4434\0", "TG1510\0", "TT1020\0", "AZ1098\0", "BA2312\0",
	"VG3030\0", "BA2304\0", "KL5609\0", "KL5610\0", "KL5611\0" };
	p->comb = combustivel;
	p->indicadorDP = indicadorDP;
	strcpy(p->nome, Voos[indiceVoo]);
	p->prox = NULL;
	if (filaVazia(fila))
	{ /* verifica se lista não esta Vazia*/
		fila->fim = p;
		fila->inicio = p;
	}
	return p;
}

void terminaFila(fila* f)
{
	Voo *atual;
	Voo *prox;
	atual = f->inicio;
	while (atual->prox != NULL)
	{
		prox = atual;
		atual = atual->prox;
		free(prox);
	}
	free(atual);
}

void imprime(fila *n)
{
	Voo *a;
	a = n->inicio;
	while ( a != NULL)
	{
		if(a->indicadorDP==0)
		{
			printf("%s\t Decolagem\t%d\n\n",a->nome,a->comb);
		}
		else
			printf("%s\t Pouso \t%d\n\n",a->nome,a->comb);
		a = a->prox;
	}
}

int geraNomeVoo(int *aux, int i)
{
	int nomeVoo;
	int j, controle = 0;
	nomeVoo = geraRand(0, 63); /*gera um numero aleatorio pro nome do voo*/
	aux[i] = nomeVoo;
	do {/*para verificar se o valor de n ja foi usado*/
			for (j = 0; j <= i - 1; j++)
			{
				if (nomeVoo == aux[j])
				{
					controle = 1;/*houve mudança*/
					nomeVoo = geraRand(0, 63);
					aux[i] = nomeVoo;
					break;
				}
				else
					controle = 0;/*nao houve mudança*/
			}
	} while (controle == 1);
	return nomeVoo;
}

int geraRand(int min, int max)
{
	int r;
	r = min + rand() % (max - min + 1);
	return r;
}

void insereInicio(fila **pPista,int indicadorDP, int combustivel,int nomeVoo)
{
	Voo* pistaAux;
	fila* pista;
	pista = *(pPista);
	if(pista->inicio == pista->fim)
	{
		pista->inicio = criaVoo(pista, indicadorDP, combustivel, nomeVoo);
		pista->inicio->prox = pista->fim;
		return ;
	}
	pistaAux = pista->inicio;
	pista->inicio = criaVoo(pista, indicadorDP, combustivel, nomeVoo);
	pista->inicio->prox = pistaAux;
	return ;
}

void insereFim(fila **pPista,int indicadorDP, int combustivel,int nomeVoo)
{
	Voo* pistaAux;
	fila* pista;
	pista=*(pPista);
	if(pista->fim==pista->inicio)
	{
		pista->fim = criaVoo(pista, indicadorDP, combustivel, nomeVoo);
		pista->inicio->prox = pista->fim;
		return ;
	}
	pistaAux = pista->fim;
	pista->fim = criaVoo(pista, indicadorDP, combustivel, nomeVoo);
	pistaAux->prox = pista->fim;
	return ;
}