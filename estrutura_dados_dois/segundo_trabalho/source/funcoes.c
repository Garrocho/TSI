#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Retorna a quantidade de arquivos que tem no diretorio "Arquivos/".
int qtdeArquivos()
{
    FILE *arquivos;
    int numArquivos;
    char arquivo[TAM_LINHA];

    system("ls Arquivos/ > Dados/Documentos.txt");
    arquivos = fopen("Dados/Documentos.txt", "r+");

    if(arquivos == NULL)
        return -2;
        
    numArquivos = -1;
    for(rewind(arquivos); !feof(arquivos); numArquivos++)
        fgets(arquivo, TAM_LINHA, arquivos);

    fclose(arquivos);
    return numArquivos;
}

// Transforma a letra em minuscula.
int paraMinuscula(int letra)
{
    if(letra >= 65 && letra <= 90)
        letra = letra+32;
    return letra;
}
