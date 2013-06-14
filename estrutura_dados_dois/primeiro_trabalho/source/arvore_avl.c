// Autor: Charles Garrocho
// Data: 10/04/2012

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_avl.h"
#include "funcoes.h"

/* VERIFICA A DIFERENCA DE ALTURA ENTRE UM NODO */
int FB(TipoNodoAVL *raiz)
{
  if (raiz == NULL)
    return 0;
 
  return Altura(raiz->esq) - Altura(raiz->dir);
}

/* RETORNA A ALTURA DE UM NODO */
int Altura(TipoNodoAVL *raiz)
{
  int esq,dir;

  if (raiz == NULL)
    return 0;

  esq = Altura(raiz->esq);
  dir = Altura(raiz->dir);

  if ( esq > dir )
    return esq + 1;
  else
    return dir + 1;
}

/* FAZ UMA ROTACAO SIMPLES PARA A ESQUERDA COM O NODO */
void RSE(TipoNodoAVL **raiz)
{
  TipoNodoAVL *aux;
  aux = (*raiz)->dir;
  (*raiz)->dir = aux->esq;
  aux->esq = (*raiz);
  (*raiz) = aux;
}

/* FAZ UMA ROTACAO SIMPLES PARA A DIREITA COM O NODO */
void RSD(TipoNodoAVL **raiz)
{
  TipoNodoAVL *aux;
  aux = (*raiz)->esq;
  (*raiz)->esq = aux->dir;
  aux->dir = (*raiz);
  (*raiz) = aux;
}

/* FAZ UM BALANCEAMENTO PARA A ESQUERDA NA ARVORE */
int BalancaEsquerda(TipoNodoAVL **raiz)
{
  int fbe = FB ( (*raiz)->esq );
  if ( fbe > 0 )
  {
    RSD(raiz);
    return 1;
  }
  else if (fbe < 0 )
  { /* Rotação Dupla Direita */
    RSE( &((*raiz)->esq) );
    RSD( raiz ); /* &(*raiz) */
    return 1;
  }
  return 0;
}

/* FAZ UM BALANCEAMENTO PARA A DIREITA NA ARVORE */
int BalancaDireita(TipoNodoAVL **raiz)
{
  int fbd = FB( (*raiz)->dir);
  if ( fbd < 0 )
  {
    RSE (raiz);
    return 1;
  }
  else if (fbd > 0 )
  { /* Rotação Dupla Esquerda */
    RSD( &((*raiz)->dir) );
    RSE( raiz ); /* &(*raiz) */
    return 1;
  }
  return 0;
}

/* VERIFICA SE A NECESSIDADE DE BALANCEAMENTO NA ARVORE */
int Balanceamento(TipoNodoAVL **raiz)
{
	int fb = FB(*raiz);
	if ( fb > 1)
		return BalancaEsquerda(raiz);
	else if (fb < -1 )
		return BalancaDireita(raiz);
	else
		return 0;
}

/* INSERE UM NOVO REGISTRO NA ARVORE FAZENDO AS COMPARACOES ENTRE AS PALAVRAS E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double InsereAVL(TipoArvoreAVL *raiz, Registro novoElemento, int idArquivo)
{
	double memoria = 0;
	if (*raiz == NULL)
	{
		*raiz = (TipoNodoAVL*)malloc(sizeof(TipoNodoAVL));
		(*raiz)->elemento = *novoElemento;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->elemento.dados = CriaDados(idArquivo);
		memoria += sizeof(TipoNodoAVL);
		memoria += sizeof(TipoDados);
		return memoria;
	}
	if ( strncmp((*raiz)->elemento.palavra, novoElemento->palavra,N) == 0)
		{
			if ( VerificaDados(&(*raiz)->elemento.dados,idArquivo) == 1)
				memoria += sizeof(TipoDados);
			return memoria;
		}
		else if ( strncmp((*raiz)->elemento.palavra, novoElemento->palavra,N) > 0 )
		{
			memoria += InsereAVL(&(*raiz)->esq,novoElemento,idArquivo);
			if (Balanceamento(&(*raiz)))
				return memoria;
			 else
				return memoria;
		}
		else if ( strncmp((*raiz)->elemento.palavra, novoElemento->palavra,N) < 0 )
		{
			memoria += InsereAVL(&(*raiz)->dir,novoElemento,idArquivo);
			if (Balanceamento(&(*raiz)))
				return memoria;
			 else
				return memoria;
		}
}

/* IMPRIME TODAS AS PALAVRAS E SEUS DADOS NO TERMINAL DO SO */
void EmOrdemAVL(TipoNodoAVL *auxArvore)
{
    if (auxArvore)
	{
		Dados auxDados;
		int i;

		EmOrdemAVL(auxArvore->esq);
    
		printf("\n");
		for (i = 0; i < N; i++)
			printf("%c",auxArvore->elemento.palavra[i]);

		auxDados = auxArvore->elemento.dados;
		while(auxDados != NULL)
		{
			printf("\t%d.%d",auxDados->qtde,auxDados->idArquivo);
			auxDados = auxDados->prox;
		}
		EmOrdemAVL(auxArvore->dir);
	}
}

/* GERA UM ARQUIVO INVERTIDO CONTENDO TODOS OS ARQUIVOS E OS SEUS RESPECTIVOS DADOS */
void CriaArquivoInvertidoAVL(TipoArvoreAVL auxArvore, FILE *arquivoInvertido)
{
	Dados auxDados;
	int k;
	if (!auxArvore)
		return;
	CriaArquivoInvertidoAVL(auxArvore->esq, arquivoInvertido);
	fprintf(arquivoInvertido, "PALAVRA: ");
	for (k = 0; k < N; k++)
		fputc(auxArvore->elemento.palavra[k],arquivoInvertido);
	auxDados = auxArvore->elemento.dados;
	fprintf (arquivoInvertido, "      "); 
	while(auxDados != NULL)
	{
		fprintf (arquivoInvertido, "DocId: %d  Qtde: %d      ",auxDados->idArquivo,auxDados->qtde);
		auxDados = auxDados->prox;
	}
	fputc('\n',arquivoInvertido);
	CriaArquivoInvertidoAVL(auxArvore->dir, arquivoInvertido);
}
