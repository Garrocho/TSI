// @author: Charles Tim Batista Garrocho
// @contact: charles.garrocho@gmail.com
// @copyright: (C) 2013 Software Open Source

#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;
typedef struct{
  int Chave, dir, esq;
}TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
  TipoItem Item;
  Apontador Prox;
}Celula;

typedef struct {
  Apontador Fundo, Topo;
  int Tamanho;
}TipoPilha;

void FPVazia(TipoPilha *Pilha);

int Vazia(TipoPilha Pilha);

void Empilha(TipoItem x, TipoPilha *Pilha);

void Desempilha(TipoPilha *Pilha, TipoItem *Item);

int Tamanho(TipoPilha Pilha);

#endif
