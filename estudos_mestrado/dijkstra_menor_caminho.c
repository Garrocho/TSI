/*void dijkstra(Graph *graph, int origem, int destino, FILE *arquivo)
{
    int dist[graph->numero_vertices], perm[graph->numero_vertices], path[graph->numero_vertices];
    int corrente, i, k, dc;
    int menor_distancia, nova_distancia;

    for (i = 0; i < graph->numero_vertices; i++) {
        perm[i] = NAOMEMBRO;
        dist[i] = INFINITO;
    }

    perm[origem] = MEMBRO;
    dist[origem] = 0;

    corrente = origem;
    k = corrente;

    fprintf(arquivo, "Origem: %d\tDestino: %d", origem+1, destino+1);

    while (corrente != destino) {

        menor_distancia = INFINITO;
        dc = dist[corrente];

        for (i = 0; i < graph->numero_vertices; i++) {

            if (perm[i] == NAOMEMBRO) {

                nova_distancia = dc + graph->matriz_adjacencia[corrente][i];

                if (nova_distancia < dist[i]) {
                    dist[i] = nova_distancia;
                    path[i] = corrente;
                }

                if (dist[i] < menor_distancia) {
                    menor_distancia = dist[i];
                    k = i;
                }
            } 
        }
        if (corrente == k) {
             fprintf(arquivo, "\tCusto: Nao Existe");
             fprintf(arquivo, "\tCaminho: Nao Existe\n");
             return;
        }

        corrente = k;
        perm[corrente] = MEMBRO;
    }

    fprintf(arquivo, "\tCusto: %d", dist[destino]);
    fprintf(arquivo, "\tCaminho: ");
    int caminho = destino;

    fprintf(arquivo, "%d <- ", destino+1);

    while (caminho != origem)
    {
        fprintf(arquivo, "%d", path[caminho]+1);
        caminho = path[caminho];
        if (caminho != origem)
            fprintf(arquivo, " <- ");
    }
    fprintf(arquivo, "\n");
}*/
