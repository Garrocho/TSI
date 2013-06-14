#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include "funcoes.h"
#include "dados.h"

typedef struct nodo
{
	TipoRegistro elemento;
	struct nodo *dir, *esq;
}TipoArvore;

typedef TipoArvore *TipoNodo;

typedef TipoArvore *Tabela[TAMANHO_TABELA];

/* CRIA UMA NOVA TABELA INICIALIZANDO TODAS AS POSICOES DA TABELA COM NULL */
void CriaTabela(Tabela*);

/* CRIA UMA NOVA ARVORE ALOCANDO MEMORIA E INICIALIZANDO OS VALORES COM VALORES DEFAULT DE INICIALIZACAO */
TipoArvore* CriaArvore();

/* VERIFICA A PARTIR DO INDICE SE A PALAVRA JA EXISTE NO ARQUIVO, CASO SIM A FUNCAO INSERENODO() E CHAMADA, CASO NAO E ADICIONADO NA POSICAO DA TABELA
   E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double InsereItem(Tabela *, TipoRegistro,int);

/* COMPARA AS PALAVRAS E ADICIONA NOS NODOS SEGUNDO O TAMANHO DAS PALAVRAS E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double InsereNodo(TipoNodo *, TipoRegistro,int);

/* CHAMA A FUNCAO EMORDEM ESPECIFICANDO CADA POSICAO DA TABELA */
void ImprimiTabela(Tabela);

/* IMPRIME AS PALAVRAS E O TIPO DADOS NO TERMINAL DO SO */
void EmOrdem(TipoArvore *auxArvore);

/* GERA UM ARQUIVO INVERTIDO CONTENDO TODOS OS ARQUIVOS E OS SEUS RESPECTIVOS DADOS */
void CriaArquivoInvertidoHash(TipoNodo auxArvore, FILE *arquivoInvertido);

#endif /* TABELA_HASH_H */
