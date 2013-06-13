// Autor: Charles Tim Batista Garrocho
// Data: 25/09/2012
// Contato: ctgarrocho@gmail.com
// Descrição: Implementa uma busca de uma cidade com menor custo para chegar em outras.

#include "Grafo.h"

int main()
{
	FILE *arq;
    Grafo g;
	char origem[100], ch, destino[100], aux[100], palavra[100];
	int i = 0, distancia = 0, j = 0, codOrigem, codDestino;
	int menor = 0;
	
	criaGrafo(&g);
	arq = fopen("distancias.txt", "r");
	if(!arq)
	    printf("Não foi possível abrir o arquivo.");
	else {
		
		palavra[i] = getc(arq);
		while(palavra[i] != EOF){
		
			// Le a cidade origem da linha atual.		
			while(palavra[i]!= '#' && palavra[i] != EOF)
			{
				i++;
				palavra[i] = getc(arq);
			}
			palavra[i]= '\0';
			strcpy(origem, palavra);
			i = 0;
			
			// Insere a cidade em um vertice do Grafo e pega o codigo de origem.
			insereVertice(g, origem, &codOrigem);
			
			// Le a cidade destino da linha atual.
			palavra[i]= getc(arq);
			while(palavra[i]!= '#' && palavra[i] != EOF)
			{
				i++;
				palavra[i] = getc(arq);
			}

			palavra[i]= '\0';
			strcpy(destino, palavra);
			i = 0;
			
			// Insere a cidade em um vertice do Grafo e pega o codigo de destino.
			insereVertice(g, destino, &codDestino);
			
			// Le a distancia entre as duas cidades.
			aux[i] = getc(arq);
			while(aux[i] != '\n' && aux[i] != EOF)
			{
				i++;
				aux[i] = getc(arq);
			}
			
			aux[i] = '\0';
			i = 0;
			palavra[i] = getc(arq);
			distancia = atoi(aux);
			
			// Insere uma aresta(ligação) entre as cidades origem e destino.
            insereAresta(g, codOrigem, codDestino, distancia);
		}
    }
  
    int cidades[g->num_vertices];
		
	// Procura a cidade com menor distancia entre todas adicionadas ao Grafo.
    for (i=0; i < g->num_vertices; i++)
    {
        cidades[i] = dijkstra(g,i);
        if (cidades[i] < menor || menor == 0)
            menor = cidades[i];
    }
    for (i=0; i < g->num_vertices; i++)
        if (cidades[i] == menor)
            printf("\nCidade com melhor Localização: %s\n\n", g->vertices[i].cidade);   
 
 	// Libera o espaço de memória utilizado pelo Grafo.
    terminaGrafo(&g);
    return 1;
}
