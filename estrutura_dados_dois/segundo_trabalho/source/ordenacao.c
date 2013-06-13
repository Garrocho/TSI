#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "ordenacao.h"

// Ordena o buffer pela palavra.
int quickSort(int e, int d, tipo_elemento buffer[])
{
    tipo_elemento aux, pivo;
    int i, k;
    i=e;
    k=d;
    pivo=buffer[(e+d)/2];
    do
    {
       while (strcmp(buffer[i].palavra, pivo.palavra) == -1 ) i++;
       while (strcmp(buffer[k].palavra, pivo.palavra) == 1 ) k--;
       if (i<=k)
       {
          aux=buffer[i];
          buffer[i]=buffer[k];
          buffer[k]=aux;
          i++;
          k--;
       }
    }while (i<=k);
    if (e<k) quickSort(e, k, buffer);
    if (i<d) quickSort(i, d, buffer);
    return 0;
}

// Auxilia o heapsort.
int organiza(fila v[], int size, int posicao)
{
    fila aux;
    int troca, i, h;
    i=posicao;
    troca=1;
    do {
        if(2*i+1>size-1 && 2*i>size-1){
            troca=0;
        }
        else
        {
            if(2*i+1>size-1){
                h=2*i;
            }
            else{
                if(strcmp(v[2*i].e.palavra, v[2*i+1].e.palavra) == 1)
                    h=2*i;
                else
                    h=2*i+1;
            }
            if(strcmp(v[i].e.palavra, v[h].e.palavra)== -1){
                aux=v[i];
                v[i]=v[h];
                v[h]=aux;
                i=h;
            }
            else
                troca=0;
        }
    }while(troca==1);
    return 1;
}

// Heapsort para ordenar a fila de prioridades.
int heap_sort(fila v[], int size)
{
    int i;
    fila aux;
    
    // Construindo o heap.
    for(i=(size-1)/2;i>=0;i--)
        organiza(v,size,i);
    
    // Ordenar o vetor.
    for(i=size-1;i>0;i--)
    {
        aux=v[i];
        v[i]=v[0];
        v[0]=aux;
        organiza(v,i,0);
    }
    return 1;
}

// Cria uma nova Run e libera o Buffer.
int criaRun(tipo_elemento buffer[], int numRuns, int j)
{
    FILE *newRun;
    char nomeRun[TAM_LINHA];
    int i;

    sprintf(nomeRun, "Temp/%d.run", numRuns);
    newRun = fopen(nomeRun, "wb+");

    for(i = 0 ; i < j ; i++)
    {
          fwrite(&buffer[i],sizeof(tipo_elemento),1, newRun);
    }
    
    fclose(newRun);
    return 0;
}
