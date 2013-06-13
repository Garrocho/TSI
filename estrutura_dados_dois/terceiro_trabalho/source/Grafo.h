#ifndef GRAFO_H
#define GRAFO_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Quantidade máxima de vértices
#define MEMBRO 1
#define NAOMEMBRO 0
#define INFINITO 1000000 // Distancia inicial do dijkstra

typedef int tipo_chave;
typedef int tipo_peso;

enum tipo_status {espera, pronto, processado};

typedef struct {
    tipo_chave chave;
    char cidade[100];
    enum tipo_status status;
}tipo_elemento;

typedef struct {
    int conectado;
    tipo_peso peso;
    enum tipo_status status;
}tipo_aresta;

struct tipo_Grafo {
    tipo_elemento vertices[MAX];
    tipo_aresta arestas[MAX][MAX];
    int num_vertices;
};

typedef struct tipo_Grafo *Grafo;

// Aloca memória para a criação de um Grafo e inicializa os dados das arestas.
int criaGrafo(Grafo *g)
{
    int i, j;
    
    if(!(*g = (Grafo)malloc(sizeof(struct tipo_Grafo))))
        return 0;
    (*g)->num_vertices = 0;
    
    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
        {
            (*g)->arestas[i][j].conectado = 0;
            (*g)->arestas[i][j].peso = 0;
            (*g)->arestas[i][j].status = pronto;
        }
    return 1;
}

// Faz uma busca para encontrar um vertice a partir de uma cidade.
int buscaVertice(Grafo g, char cidade[])
{
    int i;
    for(i = 0; i < MAX && i < g->num_vertices; i++)
        if(strcmp(g->vertices[i].cidade, cidade) == 0)
            return i;
            
    return -1;
}

// Insere uma cidade em um vertice do Grafo.
int insereVertice(Grafo g, char cidade[], int *cod)
{
    int pesquisa;
    if(g->num_vertices < MAX)
    {
        pesquisa = buscaVertice(g,cidade);                   
        if(pesquisa == -1)
        {
            strcpy(g->vertices[g->num_vertices].cidade, cidade);
            g->vertices[g->num_vertices].chave = g->num_vertices;
            *cod = g->num_vertices;
            g->num_vertices++;
            return 1;
        }
        else
        {
            *cod = g->vertices[pesquisa].chave; 
            return 1;     
        }
    }
    return 0;
}

// Insere uma aresta (ligação de uma cidade a outra) no Grafo.
int insereAresta(Grafo g,tipo_chave ch1,tipo_chave ch2,tipo_peso peso)
{
    g->arestas[ch1][ch2].conectado = 1;
    g->arestas[ch1][ch2].peso = peso;
    g->arestas[ch1][ch2].status = espera;
    g->arestas[ch2][ch1].conectado = 1;
    g->arestas[ch2][ch1].peso = peso;
    g->arestas[ch2][ch1].status = espera;
    return 1;
}

// Libera a memória utilizada pelo Grafo.
int terminaGrafo(Grafo *g)
{
    free(*g);
    return 1;
}

// Calcula as distâncias de uma origem a todos os outros vértices do Grafo.
int dijkstra(Grafo g, tipo_chave origem)
{
    int dist[MAX], perm[MAX], path[MAX];
    int corrente, i, k, dc, testados=0, aux=0;
    int menor_dist, nova_dist;
    
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

        for (i = 0; i < g->num_vertices; i++) 
        {
            if (perm[i] == NAOMEMBRO) 
            {
                if (g->arestas[corrente][i].conectado) 
                {
                    nova_dist = dc + g->arestas[corrente][i].peso;

                    if (nova_dist < dist[i]) 
                    {
                        dist[i] = nova_dist;
                        path[i] = corrente;
                    }
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
#endif
