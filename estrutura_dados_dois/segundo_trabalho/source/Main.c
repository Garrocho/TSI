/* Trabalho Pratico de Estrutura de Dados 2.
 * Especificação: Ordenação Externa de Palavras Com Multiplos Caminhos.
 * Autor: Charles Tim Batista Garrocho
 * Data: 08/06/2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "ordenacao.h"

int main()
{
    FILE *listaDeArquivos, *arquivoTexto, *vocabulario;
    int qtdeArquivo, // Numero de arquivos na pasta Arquivos
        i, qtdePalavras=0, aux, // Variaveis auxiliares
        numRuns=0, // Numero de Runs criadas
        tamBS=0, // Tamanho do bufer de saida
        tamFP; // Tamanho da fila de prioridade
        
    // Variaveis Auxiliares, para a leitura das palavras dos arquivos.
    char nomeAux[TAM_LINHA], nomeArquivo[TAM_LINHA], letra, letraAux;
    
    tipo_elemento e,  // Buffer auxiliar para ler as palavras
				  buffer[TAM_BUFFER], // buffer de palavras repetidas
                  buffer_escrita[TAM_BUFFER]; // buffer de escrita no arquivo invertido
                  
    system("rm Dados/*.*");
    system("rm Arquivos/.*txt~");
    system("clear");

    // Pega o quantidade de arquivos que serao lidos.
    qtdeArquivo = qtdeArquivos();
    
    printf("Quantidade de arquivos a Serem Lidos: %d\n",qtdeArquivo);

    // Abre o arquivo "Documentos.txt" que contem os nomes dos arquivos que serao lidos.
    listaDeArquivos = fopen("Dados/Documentos.txt", "r+");
    if(listaDeArquivos == NULL)
    {
        printf("\nNao Foi Possivel Abrir o Arquivo Documentos.txt");
        return 0;
    }

    // Faz a leitura de cada um dos arquivos.
    for(i = 1, rewind(listaDeArquivos); i <= qtdeArquivo; i++)
    {
        fgets(nomeArquivo, TAM_LINHA, listaDeArquivos);
        nomeArquivo[strlen(nomeArquivo)-1] = '\0';
        sprintf(nomeAux, "Arquivos/%s", nomeArquivo);
        printf("\nAbrindo Arquivo: %s",nomeAux);
        arquivoTexto = fopen(nomeAux, "r+");
        
        if(arquivoTexto == NULL)
        {
            printf("\nNao Foi Possivel Abrir o Arquivo %s", nomeAux);
            fclose(listaDeArquivos);
            return 0;
        }

        // Faz a leitura de cada palavra e vai armazenando no Buffer.
        for(aux = 0, rewind(arquivoTexto), letraAux = getc(arquivoTexto), letra = 65; letra != EOF ; aux++)
        {
                // variavel letraAux necessaria para que a ultima palavra do texto seja lida.
                letra = letraAux;
                
                //Separa as palavras da linha
                if((letra >= 48 && letra <=57) || (letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122) )
                {
                        e.palavra[aux] = paraMinuscula(letra);
                }
                else
                    if(aux == 0)
                        aux = -1;
                else
                {
                    e.palavra[aux] = '\0';
                    
					// Verifica se o Buffer esta cheio, se nao, e adicionado mais um elemento ao buffer.
					if(qtdePalavras != TAM_BUFFER)
					{
						buffer[qtdePalavras] = e;
						qtdePalavras++;
					}
					else  // Se o Buffer estiver cheio, Chama o QuickSort para ordenar buffer pelas palavras, e cria uma nova Run.
					{
						quickSort(0, qtdePalavras-1, buffer);
						criaRun(buffer, numRuns, TAM_BUFFER);
						numRuns++;
						qtdePalavras=0;
                    }
                    aux=-1;
                }
                letraAux = getc(arquivoTexto);
        }
    }
	
	// Verifica se ainda existe palavras no buffer, se sim, ordena o buffer e cria a ultima Run.
	if (qtdePalavras > 0) {
		quickSort(0, qtdePalavras-1, buffer);
		criaRun(buffer, numRuns, qtdePalavras);
		numRuns++;
	}
    printf("\nTerminada a Leitura dos Arquivos.\nQuantidade de runs Criadas: %d\n",numRuns);

    tipo_buffer buffer_entrada[numRuns]; // Cria um "Buffer de entrada" Com Apenas a Quantidade de Runs Criadas.
    fila fila_prioridade[numRuns]; // Cria uma "Fila de prioridade das palavras" Com Apenas a Quantidade de Runs Criadas.
	
	printf("\nAbrindo Todas as Runs Criadas e Referenciando Elas No Buffer de Entrada");
    // Joga os Elementos das Runs no Buffer de Entrada.
    for(i = 0; i < numRuns; i++)
    {
        // Abre a run.
        sprintf(nomeAux, "Temp/%d.run" ,i);
        buffer_entrada[i].arqBuffer = fopen(nomeAux, "rb");
        rewind(buffer_entrada[i].arqBuffer);
        
        // Verifica se e a ultima run criada (a ultima run criada pode conter menos elementos que as outras)
        if(i != numRuns-1)
        {
            // Caso Nao Seja a Ultima Run. Pega a metade dos elementos da run.
            fread(buffer_entrada[i].elemento, sizeof(tipo_elemento), TAM_BUFFER/2 , buffer_entrada[i].arqBuffer);
            
            // Armazena a Ultima Posicao do Buffer.
            buffer_entrada[i].ultimo = TAM_BUFFER-1;
        }
        else
        {
			// Caso Seja a Ultima Run. Verifica se a Quantidade de Palavras e Menor que a Metade da Quantidade do Buffer.
            if(qtdePalavras <= TAM_BUFFER/2)
            {
                // Se sim, Pega apenas a quantidade de elementos da Ultima Run.
		        fread(buffer_entrada[i].elemento, sizeof(tipo_elemento), qtdePalavras , buffer_entrada[i].arqBuffer);
            }
            else
            {
                // Se nao, Pega metade dos elementos da Ultima Run.
		        fread(buffer_entrada[i].elemento, sizeof(tipo_elemento), TAM_BUFFER/2, buffer_entrada[i].arqBuffer);
            }
            
            // Armazena a Ultima Posicao do Buffer.
            buffer_entrada[i].ultimo = qtdePalavras-1;
        }
        buffer_entrada[i].posbuff = 0;  // Define como "0" a posicao inicial da "Posicao atual no buffer de elementos".
        buffer_entrada[i].posicao = 0;  // Define como "0" a posicao inicial da "Posicao atual na Run".
    }

    // Coloca os elementos do buffer de entrada na fila de prioridades.
    for(i=0; i < numRuns ;i++)
    {
        fila_prioridade[i].e = buffer_entrada[i].elemento[0];
        fila_prioridade[i].run = i;
    }

    vocabulario = fopen("Dados/Vocabulario.txt", "a+");

    tamFP=numRuns-1;
    tipo_vocabulario voc;
    voc.palavra[0] = ' ';
    
    printf("\nComecando a Ordenacao Externa");
    do
    {
        // Ordena a fila de prioridades, Uilizando o "Heap Sort".
        heap_sort(fila_prioridade, tamFP+1);

        // Joga a menor palavra no buffer de saida.
        buffer_escrita[tamBS] = fila_prioridade[0].e;
        tamBS++;
        
        // Verifica se existe mais palavras dentro da run do elemento retirado.
        if(buffer_entrada[fila_prioridade[0].run].posicao == buffer_entrada[fila_prioridade[0].run].ultimo)
        {
            fila_prioridade[0] = fila_prioridade[tamFP];
            tamFP--;
        }
        else
        {
            // Verifica se e a ultima run criada.
            if(fila_prioridade[0].run != numRuns-1)
            {
                // Se Sim, Verifica se acabaram os elementos do buffer de elementos.
                if(buffer_entrada[fila_prioridade[0].run].posbuff+1 == TAM_BUFFER/2)
                {
					// Se Sim, Copia o Resto dos Elementos Para o Buffer de Entrada.
                    fread(buffer_entrada[fila_prioridade[0].run].elemento, sizeof(tipo_elemento), TAM_BUFFER/2 , (buffer_entrada[fila_prioridade[0].run].arqBuffer));
                    buffer_entrada[fila_prioridade[0].run].posicao++;
                    buffer_entrada[fila_prioridade[0].run].posbuff=0;
                    
                    // Joga o elemento do buffer de elementos na fila de Prioridade.
                    fila_prioridade[0].e = buffer_entrada[fila_prioridade[0].run].elemento[0];
                }
                else
                {
                    buffer_entrada[fila_prioridade[0].run].posicao++;
                    buffer_entrada[fila_prioridade[0].run].posbuff++;
                    
                    // Joga o elemento do buffer de elementos na fila de Prioridade.
                    fila_prioridade[0].e = buffer_entrada[fila_prioridade[0].run].elemento[buffer_entrada[fila_prioridade[0].run].posbuff];
                }
            }
            else
            {
            	// Verifica se acabaram os elementos do buffer de elementos.
                if(qtdePalavras > TAM_BUFFER/2)
                {
                    // Verifica se acabaram os elementos do buffer de elementos.
                    if(buffer_entrada[fila_prioridade[0].run].posbuff+1 == TAM_BUFFER/2)
                    {
                        fread(buffer_entrada[fila_prioridade[0].run].elemento, sizeof(tipo_elemento), qtdePalavras-(TAM_BUFFER/2) , (buffer_entrada[fila_prioridade[0].run].arqBuffer));
                        buffer_entrada[fila_prioridade[0].run].posicao++;
                        buffer_entrada[fila_prioridade[0].run].posbuff=0;
                        
                        // Joga o elemento do buffer de elementos na fila.
                        fila_prioridade[0].e = buffer_entrada[fila_prioridade[0].run].elemento[0];
                    }
                    else
                    {
                        buffer_entrada[fila_prioridade[0].run].posicao++;
                        buffer_entrada[fila_prioridade[0].run].posbuff++;
                        
                        // Joga o elemento do buffer de elementos na fila.
                        fila_prioridade[0].e = buffer_entrada[(fila_prioridade[0].run)].elemento[(buffer_entrada[(fila_prioridade[0].run)].posbuff)];
                    }
                }
                else
                {
                    buffer_entrada[fila_prioridade[0].run].posicao++;
                    buffer_entrada[fila_prioridade[0].run].posbuff++;
                    
                    // Joga o elemento do buffer de elementos na fila.
                    fila_prioridade[0].e = buffer_entrada[fila_prioridade[0].run].elemento[buffer_entrada[fila_prioridade[0].run].posbuff];
                }
            }
        }

        // Verifica se o buffer de saida esta cheio.
        if(tamBS == TAM_BUFFER)
        {
            for(i=0; i < TAM_BUFFER ;i++)
            {
				strcpy(voc.palavra, buffer_escrita[i].palavra);
				fprintf(vocabulario, "%s\n",voc.palavra);
            }
            tamBS=0;
        }
    }while(tamFP>=0);

    for(i=0; i < TAM_BUFFER ;i++)
	{
		strcpy(voc.palavra, buffer_escrita[i].palavra);
		fprintf(vocabulario, "%s\n",voc.palavra);
	}

    fprintf(vocabulario, "%s\n",voc.palavra);

	printf("\nFechando Todas as Runs Referenciadas nos Buffers");
    for(i=0; i < numRuns;i++)
        fclose(buffer_entrada[i].arqBuffer);

    fclose(vocabulario);
    fclose(arquivoTexto);
    fclose(listaDeArquivos);
  
    printf("\nArquivo \"Vocabulario.txt\" Criado Com Sucesso.");
    system("rm Temp/*.*");
    return 0;
}
