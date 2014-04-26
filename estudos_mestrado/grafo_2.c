#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafo_2.h"

// Aloca memória para a criação de um Grafo e inicializa os dados das arestas.
Tipo_Grafo* cria_grafo(int tamanho)
{
    Tipo_Grafo *grafo;
    
    grafo = (Tipo_Grafo*)malloc(sizeof(Tipo_Grafo));
    grafo->vertices = (Tipo_Vertice*)malloc(sizeof(Tipo_Vertice)*tamanho);
    grafo->num_vertices = 0;

    return grafo;
}

// Faz uma busca para encontrar um vertice a partir de uma cidade.
int busca_vertice(Tipo_Grafo* grafo, int chave, int tamanho)
{
    int i;
    for (i=0; i < grafo->num_vertices; i++)
        if (grafo->vertices[i].chave == chave)
            return i;
    return -1;
}

// Insere uma cidade em um vertice do Grafo.
int insere_vertice(Tipo_Grafo* grafo, int chave, int tamanho)
{
    if (grafo->num_vertices < tamanho)
    {
        if (busca_vertice(grafo, chave, tamanho) == -1)
        {
            grafo->vertices[grafo->num_vertices].chave = chave;
            grafo->vertices[grafo->num_vertices].prox = NULL;
            grafo->num_vertices++;
            return 1;
        }
    }
    return 0;
}

// Insere uma aresta (ligação de uma cidade a outra) no Grafo.
void insere_aresta(Tipo_Grafo* grafo, int chave_1, int chave_2, int distancia)
{
    Tipo_Nodo *aux;
    int i;
    for (i=0; i < grafo->num_vertices; i++) {
        if (grafo->vertices[i].chave == chave_1) {
            aux = grafo->vertices[i].prox;
            while (aux != NULL)
                aux = grafo->vertices[i].prox;
            aux = (Tipo_Nodo*)malloc(sizeof(Tipo_Nodo));
            aux->chave = chave_2;
            aux->distancia = distancia;
            break;
        }
    }
}

// Libera a memória utilizada pelo Grafo.
void termina_grafo(Tipo_Grafo *grafo, int tamanho)
{
    int i;
    Tipo_Nodo *aux1, *aux2;
    for (i=0; i < tamanho; i++) {
        aux1 = grafo->vertices[i].prox;
        while (aux1) {
            aux2 = aux1;
            aux1 = aux1->prox;
            free(aux2);
        }
    }
    free(grafo->vertices);
    free(grafo);
}

int dijkstra(Tipo_Grafo *g, int origem) {
    int dist[MAX], perm[MAX], path[MAX];
    int corrente, i, k, dc, testados=0, aux=0;
    int menor_dist, nova_dist;
    Tipo_Nodo aux;
    
    for (i = 0; i < g->num_vertices; i++) {
        perm[i] = NAOMEMBRO;
        dist[i] = INFINITO;
    }

    perm[origem] = MEMBRO;
    dist[origem] = 0;
    
    corrente = origem;
    k = corrente;

    while (testados != (g->num_vertices-1))
    {
        menor_dist = INFINITO;
        dc = dist[corrente];

        aux = grafo->vertices[corrente].prox;
        while (aux) {
            nova_dist = dc + g->arestas[corrente][i].peso;
            if (nova_dist < dist[i]) 
            {
                dist[i] = nova_dist;
                path[i] = corrente;
            }
        }

        for (i = 0; i < g->num_vertices; i++) 
        {
            if (perm[i] == NAOMEMBRO) 
            {
                if (g->vertices[corrente][i].conectado) 
                {
                   
                }
                
                if (dist[i] < menor_dist) 
                {
                    menor_dist = dist[i];
                    k = i;
                }
            }
        } 
        corrente = k;
        perm[corrente] = MEMBRO;
        aux += dist[corrente];  
        testados++;          
    } 
    return aux;
}