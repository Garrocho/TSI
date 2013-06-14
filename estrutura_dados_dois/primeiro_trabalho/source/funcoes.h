// Autor: Charles Garrocho
// Data: 10/04/2012

#ifndef FUNCOES_H
#define FUNCOES_H

#include "arvore_avl.h"
#include "arvore_b.h"
#include "tabela_hash.h"
#include "dados.h"

#define LETRA_A 65
#define LETRA_Z 90
#define LETRA_a 97
#define LETRA_z 122

/* CRIA UM NOVO ARQUIVO E ADICIONA NELE TEMPO DE EXECUCAO E CONSUMO DE MEMORIA */
void CriaArquivoDesempenho();

/* CALCULA A DIVISAO DA SUBTRACAO DO TEMPO INICIO E FIM POR CLOCK */
double CalculaTempo(double inicio, double fim);

/* RETORNA 1 SE FOR UM CARACTER VALIDO, OU 0 SE FOR UM CARACTER ESPECIAL */
int VerificaLetra(char c);

/* CRIA UM INDICE UNICO A PARTIR DO CODIGO ASCI DE CADA LETRA EM UMA PALAVRA */
int CriaIndice(TipoPalavra);

/* RETORNA A QUANTIDADE DE LINHAS DE UM DETERMINADO ARQUIVO */
int QuantidadeLinhas(char *);

/* ABRE O ARQUIVO ESPECIFICADO E ADICIONA AS PALAVRAS DOS ARQUIVOS NA TABELA HASH */
double ExecutaTabelaHASH();

/* ABRE O ARQUIVO ESPECIFICADO E ADICIONA AS PALAVRAS DOS ARQUIVOS NA ARVORE AVL */
double ExecutaArvoreAVL();

/* ABRE O ARQUIVO ESPECIFICADO E ADICIONA AS PALAVRAS DOS ARQUIVOS NA ARVORE B */
double ExecutaArvoreB();

/* RETORNA A QUANTIDADE DE CARACTERES EXISTENTE EM UMA PALAVRA */
int TamanhoString(TipoPalavra palavra);

/* CRIA UM ARQUIVO CONTENDO UM ID VINCULADO A UM ARQUIVO TXT */
void CriaDocID();

#endif /* FUNCOES_H */
