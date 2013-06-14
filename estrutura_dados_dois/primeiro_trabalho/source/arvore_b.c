#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "arvore_b.h"
#include "funcoes.h"

/* INICIALIZA A ARVORE COM NULL */
void Inicializa(TipoDicionario *Dicionario)
{
	*Dicionario = NULL;
} 

/* INSERE UM NOVO REGISTRO EM UM DETERMINADA PAGINA */
void InsereNaPagina(Apontador Ap, TipoRegistro Reg, Apontador ApDir, int idArquivo)
{
	int NaoAchouPosicao,k;
	k = Ap->n;
	NaoAchouPosicao = (k > 0);
	while (NaoAchouPosicao) 
	{ 
		if ( strncmp(Reg.palavra, Ap->r[k - 1].palavra,N) >= 0 )
		{
			NaoAchouPosicao = 0;
			break;
		}
		Ap->r[k] = Ap->r[k-1];
		Ap->p[k+1] = Ap->p[k];
		k--;
		if (k < 1)  
			NaoAchouPosicao = 0;
	}
	Ap->r[k] = Reg;
	Ap->p[k+1] = ApDir;
	Ap->n++;
} 

/* INSERE UM NOVO REGISTRO VERIFICANDO AS PALAVRAS, CASO EXISTA A QUANTIDADE E INCREMENTADA, CASO CONTRARIA A FUNCAO INSERENAPAGINA() E CHAMADA 
    E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double Ins(TipoRegistro Reg, Apontador Ap, int *Cresceu, Registro RegRetorno, Apontador *ApRetorno, int idArquivo)
{
	Apontador ApTemp;
	int i, j;
	double memoria = 0;
	if (Ap == NULL)
	{
		if ( VerificaDados(&Reg.dados, idArquivo) == 1)
			memoria += sizeof(TipoDados);
		*Cresceu = 1;
		*RegRetorno = Reg;
		*ApRetorno = NULL;
		return memoria;
	}
	i = 1;
	while (i < Ap->n && (strncmp(Reg.palavra, Ap->r[i - 1].palavra,N) > 0 )) 
		i++;
	if ( strncmp(Reg.palavra, Ap->r[i - 1].palavra,N) == 0 )
	{
		if ( VerificaDados(&Ap->r[i - 1].dados, idArquivo) == 1)
			memoria += sizeof(TipoDados);
		*Cresceu = 0;
		return memoria;
	}
	if (strncmp(Reg.palavra, Ap->r[i - 1].palavra,N) < 0)
		i--;
	Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno, idArquivo);
	if (!*Cresceu)
		return memoria;
	if (Ap->n < mm)
	{  /* Pagina tem espaco */
		InsereNaPagina(Ap, *RegRetorno, *ApRetorno, idArquivo);
		*Cresceu = 0;
		return memoria;
	}
	/* Overflow: Pagina tem que ser dividida */
	ApTemp = (Apontador)malloc(sizeof(Pagina));
	memoria += sizeof(Pagina);
	ApTemp->n = 0;
	ApTemp->p[0] = NULL;
	if (i <= m + 1)
	{
		InsereNaPagina(ApTemp, Ap->r[mm - 1], Ap->p[mm], idArquivo);
		Ap->n--;
		InsereNaPagina(Ap, *RegRetorno, *ApRetorno, idArquivo);
	}
	else
		InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno, idArquivo);
	for (j = m + 2; j <= mm; j++)
		InsereNaPagina(ApTemp, Ap->r[j - 1], Ap->p[j], idArquivo);
	Ap->n = m;
	ApTemp->p[0] = Ap->p[m + 1];
	*RegRetorno = Ap->r[m];
	*ApRetorno = ApTemp;
	return memoria;
}

/* CRIA E INICIALIZA VARIAVEIS PARA A VERIFICACAO SE A ARVORE CRESCE  E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double Insere(TipoRegistro Reg, Apontador *Ap, int idArquivo)
{
	int Cresceu;
	TipoRegistro RegRetorno;
	Apontador ApRetorno;
	Apontador ApTemp;
	double memoria = 0;
	memoria += Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno, idArquivo);
	if (Cresceu != 0)
	{ /* Arvore cresce na altura pela raiz */
		ApTemp = (Apontador) malloc(sizeof(Pagina));
		memoria += sizeof(Pagina);
		ApTemp->n = 1;
		ApTemp->r[0] = RegRetorno;
		ApTemp->p[1] = ApRetorno;
		ApTemp->p[0] = *Ap;
		*Ap = ApTemp;
	}
	return memoria;
}

/* IMPRIME TODAS AS PALAVRAS E OS DADOS DAS MESMAS NO TERMINAL DO SO */
void Imprime(Apontador p, int nivel)
{ 
	Dados auxDados;
	int i,k;
	if (p == NULL)
		return;

	for (i = 0; i < p->n; i++)
	{
		printf("\n");
		for (k = 0; k < N; k++)
			printf("%c",p->r[i].palavra[k]);
	
		auxDados = p->r[i].dados;
		while(auxDados != NULL)
		{
			printf("\t%d.%d",auxDados->qtde, auxDados->idArquivo);
			auxDados = auxDados->prox;
		}
	}
	
	nivel++;
	for (i = 0; i <= p->n; i++)
		Imprime(p->p[i], nivel);
}

/* GERA UM ARQUIVO INVERTIDO CONTENDO TODOS OS ARQUIVOS E OS SEUS RESPECTIVOS DADOS */
void CriaArquivoInvertidoB(Apontador auxArvore, FILE *arquivoInvertido, int nivel)
{
	Dados auxDados;
	int k,i;
	if (!auxArvore)
		return;

	for (i = 0; i < auxArvore->n; i++)
	{
		fprintf(arquivoInvertido, "PALAVRA: ");
		for (k = 0; k < N; k++)
			fputc(auxArvore->r[i].palavra[k], arquivoInvertido);
		fprintf (arquivoInvertido, "      ");
		auxDados = auxArvore->r[i].dados;
		while(auxDados != NULL)
		{
			fprintf (arquivoInvertido, "DocId: %d  Qtde: %d      ",auxDados->idArquivo,auxDados->qtde);
			auxDados = auxDados->prox;
		}
		fputc('\n',arquivoInvertido);
	}
	nivel++;
	for (i = 0; i <= auxArvore->n; i++)
		CriaArquivoInvertidoB(auxArvore->p[i], arquivoInvertido, nivel);
}
