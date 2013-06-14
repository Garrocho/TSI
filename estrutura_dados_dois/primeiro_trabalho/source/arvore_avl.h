#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include "dados.h"

typedef struct NodoAVL
{
	TipoRegistro elemento;
	struct NodoAVL *esq, *dir;
}TipoNodoAVL;

typedef TipoNodoAVL *TipoArvoreAVL;

/* VERIFICA A DIFERENCA DE ALTURA ENTRE UM NODO */
int FB(TipoNodoAVL *raiz);

/* RETORNA A ALTURA DE UM NODO */
int Altura(TipoNodoAVL *raiz);

/* FAZ UMA ROTACAO SIMPLES PARA A ESQUERDA COM O NODO */
void RSE(TipoNodoAVL **raiz);

/* FAZ UMA ROTACAO SIMPLES PARA A DIREITA COM O NODO */
void RSD(TipoNodoAVL **raiz);

/* FAZ UM BALANCEAMENTO PARA A ESQUERDA NA ARVORE */
int BalancaEsquerda(TipoNodoAVL **raiz);

/* FAZ UM BALANCEAMENTO PARA A DIREITA NA ARVORE */
int BalancaDireita(TipoNodoAVL **raiz);

/* VERIFICA SE A NECESSIDADE DE BALANCEAMENTO NA ARVORE */
int Balanceamento(TipoNodoAVL **raiz);

/* INSERE UM NOVO REGISTRO NA ARVORE FAZENDO AS COMPARACOES ENTRE AS PALAVRAS E RETORNA A QUANTIDADE DE MEMORIA GASTA*/
double InsereAVL(TipoArvoreAVL *raiz, Registro elemento, int idArquivo);

/* IMPRIME TODAS AS PALAVRAS E SEUS DADOS NO TERMINAL DO SO */
void EmOrdemAVL(TipoNodoAVL *auxArvore);

/* GERA UM ARQUIVO INVERTIDO CONTENDO TODOS OS ARQUIVOS E OS SEUS RESPECTIVOS DADOS */
void CriaArquivoInvertidoAVL(TipoArvoreAVL auxArvore, FILE *arquivoInvertido);

#endif /* ARVORE_AVL_H */
