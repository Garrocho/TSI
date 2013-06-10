#ifndef CHAMADA_H
#define CHAMADA_H

#include "Metodos.h"
#include "Pilha.h"
#include <stdio.h>
double geraTempo();

void vetorAle(tipo_item vetor[], int tamanho);

void vetorCres(tipo_item vetor[], int tamanho);

void gravarArq(tipo_item vetor[], FILE *arquivo, int tamanho);

void gravarArqTempo(FILE *arquivo, double tempo);

double calculaTempo(double tempoInicio, double tempoFim);

void gravarArqNome(FILE *arquivo, char nome);

void chamaMetodos(int tamanho);

#endif