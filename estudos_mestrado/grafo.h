#ifndef GRAFO_H
#define GRAFO_H

#define MEMBRO 1
#define NAOMEMBRO 0
#define INFINITO 1000000 // Distancia inicial

enum Tipo_Status {espera, pronto, processado};

typedef struct {
    int chave;
    int cidade;
    enum Tipo_Status status;
}Tipo_Vertice;

typedef struct {
    int conectado;
    int distancia;
    enum Tipo_Status status;
}Tipo_Aresta;

typedef struct {
    Tipo_Vertice *vertices;
    Tipo_Aresta **arestas;
    int num_vertices;
}Tipo_Grafo;

Tipo_Grafo* cria_grafo(int tamanho);

int busca_vertice(Tipo_Grafo* grafo, int cidade, int tamanho);

int insere_vertice(Tipo_Grafo* grafo, int cidade, int tamanho);

void insere_aresta(Tipo_Grafo* grafo, int chave_1, int chave_2, int distancia);

void termina_grafo(Tipo_Grafo* grafo, int tamanho);

void dijkstra(Tipo_Grafo *grafo, int origem, int destino);

void imprime(Tipo_Grafo *grafo);

#endif