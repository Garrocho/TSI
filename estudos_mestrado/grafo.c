#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// Aloca memória para a criação de um Grafo e inicializa os dados das arestas.
Tipo_Grafo* cria_grafo(int tamanho)
{
    Tipo_Grafo *grafo;
    int i, j;
    
    grafo = (Tipo_Grafo*)malloc(sizeof(Tipo_Grafo));
    grafo->vertices = (Tipo_Vertice*)malloc(sizeof(Tipo_Vertice)*tamanho);
    grafo->arestas = (Tipo_Aresta**)malloc(sizeof(Tipo_Aresta)*tamanho);
    grafo->num_vertices = 0;

    for (i=0 ; i < tamanho; i++) {
        grafo->arestas[i] = (Tipo_Aresta*)malloc(sizeof(Tipo_Aresta)*tamanho);
    }

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++)
        {
            grafo->arestas[i][j].conectado = 0;
            grafo->arestas[i][j].distancia = INFINITO;
            grafo->arestas[i][j].status = pronto;
        }
    }
    return grafo;
}

// Faz uma busca para encontrar um vertice a partir de uma cidade.
int busca_vertice(Tipo_Grafo* grafo, int cidade, int tamanho)
{
    int i;
    for (i=0; i < tamanho; i++)
        if (grafo->vertices[i].cidade == cidade)
            return i;
    return -1;
}

void imprime(Tipo_Grafo* grafo)
{
    int i,k;
    for (i=0; i <= grafo->num_vertices; i++) {
        for (k=0; k <= grafo->num_vertices; k++)
            printf("%d %d %d\n", i, k, grafo->arestas[i][k].distancia);
    }
}

// Insere uma cidade em um vertice do Grafo.
int insere_vertice(Tipo_Grafo* grafo, int cidade, int tamanho)
{
    if (grafo->num_vertices < tamanho)
    {
        if (busca_vertice(grafo, cidade, tamanho) == -1)
        {
            grafo->vertices[grafo->num_vertices].cidade = cidade;
            grafo->vertices[grafo->num_vertices].chave = grafo->num_vertices;
            grafo->num_vertices++;
            return 1;
        }
    }
    return 0;
}

// Insere uma aresta (ligação de uma cidade a outra) no Grafo.
void insere_aresta(Tipo_Grafo* grafo, int chave_1, int chave_2, int distancia)
{
    grafo->arestas[chave_1][chave_2].conectado = 1;
    grafo->arestas[chave_1][chave_2].distancia = distancia;
    grafo->arestas[chave_1][chave_2].status = espera;
    grafo->arestas[chave_2][chave_1].conectado = 1;
    grafo->arestas[chave_2][chave_1].distancia = distancia;
    grafo->arestas[chave_2][chave_1].status = espera;
}

// Libera a memória utilizada pelo Grafo.
void termina_grafo(Tipo_Grafo *grafo, int tamanho)
{
    int i;
    for (i=0; i < tamanho; i++)
        free(grafo->arestas[i]);

    free(grafo->vertices);
    free(grafo);
}

// Calcula as distâncias de uma origem a todos os outros vértices do Grafo.
void dijkstra(Tipo_Grafo *grafo, int origem, int destino)
{
    int dist[grafo->num_vertices+2], perm[grafo->num_vertices+2], path[grafo->num_vertices+2];
    int corrente, i, k, dc;
    int menor_distancia, nova_distancia;

    /* Inicializa todos os índices de 'perm' como 0 e de 'dist' como INFINITY */
    for (i = 0; i <= grafo->num_vertices+2; i++) {
        perm[i] = NAOMEMBRO;
        dist[i] = INFINITO;
    }

    /* Inclui 's' em perm (perm[s]=1) e configura(armazena) sua distancia como sendo zero */
    perm[origem] = MEMBRO;
    dist[origem] = 0;

    /* define 's' como origem (fonte) da busca */
    corrente = origem;
    k = corrente;

    while (corrente != destino) {

        menor_distancia = INFINITO;
        dc = dist[corrente];

        for (i = 0; i <= grafo->num_vertices+2; i++) {

            //se o elemento NÃO está em perm
            if (perm[i] == NAOMEMBRO) {

                if (grafo->arestas[corrente][i].conectado) 
                {
                    nova_distancia = dc + grafo->arestas[corrente][i].distancia;

                    if (nova_distancia < dist[i]) 
                    {
                        dist[i] = nova_distancia;
                        path[i] = corrente;
                    }
                }
                
                if (dist[i] < menor_distancia) 
                {
                    menor_distancia = dist[i];
                    k = i;
                }
            } 
        }

        /* embora estamos assumindo grafos ponderados e conexos, este if garante que
         em caso de não existência de um caminho o programa não entre em loop infinito */
        if (corrente == k) {
            printf("\n\nCAMINHO NAO EXISTE\n\n");
            return;
        }
        corrente = k;
        perm[corrente] = MEMBRO;
    }

    printf("\n\nRESULTADO: ");
    int caminho = destino;

    printf("%d <- ", destino);

    while (caminho != origem)
    {
        printf("%d", path[caminho]);
        caminho = path[caminho];

        if (caminho != origem)
            printf (" <- ");
    }
    printf("\n\ncusto: %d\n\n", dist[destino]);
}