#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "tabela_hash.h"
#include "funcoes.h"
#include "dados.h"

/* CRIA UMA NOVA TABELA INICIALIZANDO TODAS AS POSICOES DA TABELA COM NULL */
void CriaTabela(Tabela *auxTabela)
{
	int i;
	for (i = 0; i < TAMANHO_TABELA; i++)
		(*auxTabela)[i] = NULL;
}

/* CRIA UMA NOVA ARVORE ALOCANDO MEMORIA E INICIALIZANDO OS VALORES COM VALORES DEFAULT DE INICIALIZACAO */
TipoArvore* CriaArvore()
{
	TipoArvore *auxArvore;
	auxArvore = (TipoArvore*)malloc(sizeof(TipoArvore));
	auxArvore->dir = NULL;
	auxArvore->esq = NULL;
	auxArvore->elemento = CriaRegistroSemPonteiro();
	return auxArvore;
}

/* VERIFICA A PARTIR DO INDICE SE A PALAVRA JA EXISTE NO ARQUIVO, CASO SIM A FUNCAO INSERENODO() E CHAMADA, CASO NAO E ADICIONADO NA POSICAO DA TABELA
   E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double InsereItem(Tabela *auxTabela, TipoRegistro auxElemento, int idArquivo)
{
	int indice;
	double memoria = 0;
	indice = CriaIndice(auxElemento.palavra);
	if ((*auxTabela)[indice] == NULL)
	{
		(*auxTabela)[indice] = CriaArvore();
		memoria = sizeof(TipoArvore);
		(*auxTabela)[indice]->elemento = auxElemento;
		(*auxTabela)[indice]->elemento.dados = CriaDados(idArquivo);
		memoria += sizeof(TipoDados);
		return memoria;
	}
	memoria += InsereNodo(&(*auxTabela)[indice],auxElemento,idArquivo);
	return memoria;
}

/* COMPARA AS PALAVRAS E ADICIONA NOS NODOS SEGUNDO O TAMANHO DAS PALAVRAS E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double InsereNodo(TipoNodo *auxArvore, TipoRegistro auxElemento, int idArquivo)
{
	double memoria = 0;
	while(*auxArvore)
    {
		if (strncmp(auxElemento.palavra, (*auxArvore)->elemento.palavra,N) == 0)
		{
			if ( VerificaDados(&(*auxArvore)->elemento.dados,idArquivo) == 1)
				memoria += sizeof(TipoDados);
			return memoria;
		}
		else if ((strncmp((*auxArvore)->elemento.palavra, auxElemento.palavra,N) > 0))
		{
            auxArvore = &(*auxArvore)->esq;
		}
		else if ((strncmp( (*auxArvore)->elemento.palavra, auxElemento.palavra,N) < 0))
		{
			auxArvore = &(*auxArvore)->dir;
		}
    }
	memoria += sizeof(TipoArvore);
	*auxArvore = CriaArvore();
    (*auxArvore)->elemento = auxElemento;
	(*auxArvore)->elemento.dados = CriaDados(idArquivo);
    return memoria;
}

/* CHAMA A FUNCAO EMORDEM ESPECIFICANDO CADA POSICAO DA TABELA */
void ImprimiTabela(Tabela auxTabela)
{
	int i;
	for (i = 0; i < TAMANHO_TABELA; i++)
	{
		if (auxTabela[i] != NULL)
			EmOrdem(auxTabela[i]);
	}
}

/* IMPRIME AS PALAVRAS E O TIPO DADOS NO TERMINAL DO SO */
void EmOrdem(TipoArvore *auxArvore)
{
    if (auxArvore)
	{
		Dados auxDados;
		int i;

		EmOrdem(auxArvore->esq);
    
		printf("\n");
		for (i = 0; i < N; i++)
			printf("%c",auxArvore->elemento.palavra[i]);

		auxDados = auxArvore->elemento.dados;
		if (auxDados == NULL)
			printf("Nao foi encontrado a palavra");
		else
		{
			while(auxDados != NULL)
			{
				printf("\t%d.%d",auxDados->qtde,auxDados->idArquivo);
				auxDados = auxDados->prox;
			}
		}
		EmOrdem(auxArvore->dir);
	}
}

/* GERA UM ARQUIVO INVERTIDO CONTENDO TODOS OS ARQUIVOS E OS SEUS RESPECTIVOS DADOS */
void CriaArquivoInvertidoHash(TipoArvore *auxArvore, FILE *arquivoInvertido)
{
	Dados auxDados;
	int k;
	if (!auxArvore)
		return;
	CriaArquivoInvertidoHash(auxArvore->esq, arquivoInvertido);
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
	CriaArquivoInvertidoHash(auxArvore->dir, arquivoInvertido);
}
