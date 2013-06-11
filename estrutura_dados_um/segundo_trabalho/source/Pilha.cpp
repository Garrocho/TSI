// @author: Charles Tim Batista Garrocho
// @contact: charles.garrocho@gmail.com
// @copyright: (C) 2013 Software Open Source

#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"


void FPVazia(TipoPilha *Pilha)
{
  Pilha->Topo = (Apontador) malloc(sizeof(Celula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
};  /* FPVazia */

int Vazia(TipoPilha Pilha)
{
  return (Pilha.Topo == Pilha.Fundo);
};  /* Vazia */

void Empilha(TipoItem x, TipoPilha *Pilha)
{
  Apontador Aux;

  Aux = (Apontador) malloc(sizeof(Celula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
};  /* Empilha */


void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{
  Apontador q;
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);
  Pilha->Tamanho--;
}; /* Desempilha */

int Tamanho(TipoPilha Pilha)
{
  return (Pilha.Tamanho);
};  /* Tamanho */
