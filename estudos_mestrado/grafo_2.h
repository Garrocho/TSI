#ifndef GRAFO_H
#define GRAFO_H

#define MEMBRO 1
#define NAOMEMBRO 0
#define INFINITO 1000000

typedef struct No {
    int chave;
    int distancia;
    struct No *prox;
}Tipo_Nodo;

typedef struct {
    int chave;
    Tipo_Nodo *prox;
}Tipo_Vertice;

typedef struct {
    Tipo_Vertice *vertices;
    int num_vertices;
}Tipo_Grafo;

Tipo_Grafo* cria_grafo(int tamanho);

int busca_vertice(Tipo_Grafo* grafo, int cidade, int tamanho);

int insere_vertice(Tipo_Grafo* grafo, int cidade, int tamanho);

void insere_aresta(Tipo_Grafo* grafo, int chave_1, int chave_2, int distancia);

void termina_grafo(Tipo_Grafo* grafo, int tamanho);

#endif