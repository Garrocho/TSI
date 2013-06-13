/* Arquivo: ordenacao.h
 * Descrição: Este Arquivo Implementa o algoritimo Dikstra em C.
 * Autor: Charles Tim Batista Garrocho
 */

#define MAX 10
#define INFINITO 1000000;
#define MEMBRO 1;
#define NAOMEMBRO 0

int dijkstra(grafo g, tipo_chave origem, tipo_chave destino)
{
    int o, d, corrente, i, k;
    int per[MAX], path[MAX], dist[MAX];

    o = busca_vertice(g, origem);
    d = busca_vertice(g, destino);

    for(i = 0; i < g->num_vertices; i++)
    {
        dist[i] = INFINITO;
        per[i] = MEMBRO;
    }

    dist[0] = 0;
    corrente = origem;
    per[0] = MEMBRO;

    while(corrente != d)
    {
        menor_distancia = INIFINITO;
        for (i = 0; i < g->num_vertices; i++)
        {
            if(g->aresta[corrente][i].conectado && per[i] != MEMBRO)
            {
                if(dist[i] > dist[corrente] + g->arestas[corrente][i].peso)
                {
                    dist[i] = dist[corrente] + g->arestas[corrente][i].peso;
                    path = corrente;
                }//if
                if(menor_distancia > dist[i])
                {
                    menor_distancia = dist[i];
                    k = 1;
                }//if
                
	        }//if
	    }//for
        corrente = k;
    }//while]

    int i;
    char letra;
    int caminho;
    caminho = corrente;
    
    printf("%d<-",caminho);
    while (caminho != origem)
    {
        caminho = path[caminho];
        printf("%d",caminho);
        if(caminho!=origem)
            printf(“<-”);
    }
}// função dijkstra
