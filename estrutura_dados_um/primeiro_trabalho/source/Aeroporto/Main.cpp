#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Funcoes.h"

int main() 
{
	int qtdVoos, qtdPousos, qtdDecolagens;/*quantidades de total de voo, de pouso e decolagens*/
	int combustivel, nomeVoo,indicadorDP;/*variaveis a serem acrescentadas a cada no da fila*/
	int nroDecolagens = 1, nroPousos = 1;/*contador do numero de decolagens e pousos*/
	int isDecolagem;/*numero gerado aleatoriamente para decidir se é decolagem ou pouso*/
	int aux[64];/*vetor de inteiros que garante que o nome do voo não se repita*/
	int i;/*contador para o numero de voos*/
	int n=0;/*contador de casos de emergencia*/
	struct tm *local;
	time_t tempo;/*variavel de indicação de hora local*/
	fila *pista1, *pista2, *pista3;/*ponteiros de fila para cada uma das pistas*/
	pista1 = criaFila();
	pista2 = criaFila();
	pista3 = criaFila();
	srand(time(NULL));
	/*geradas variaveis aleatorias imutaveis até o final do programa*/ 
	qtdVoos = geraRand(0,63);
	qtdPousos = geraRand(0,qtdVoos);
	qtdDecolagens = qtdVoos - qtdPousos;
	tempo = time(NULL);
	local = localtime(&tempo);
	setAux(aux);
	for (i = 0; i < qtdVoos; i++)
	{
		isDecolagem = geraRand(0, 1);/*numero pra decidir se é pouso ou decolagem*/
		if ((isDecolagem == 0 || nroPousos> qtdPousos)&&nroDecolagens <= qtdDecolagens)
		{/*caso seja decolagem*/
			indicadorDP = 0;/*indicador de decolagem*/
			combustivel = geraRand(24, 48);/*indicador de combustivel de decolagem*/
			nomeVoo = geraNomeVoo(aux,i); /*gera um numero aleatorio pro nome do voo*/ 
			if (nroDecolagens % 3 == 0)
			{ /*coloca números divisíveis por 3 na pista 1*/
				insereFim(&pista1, indicadorDP, combustivel, nomeVoo);
			}
			else if (nroDecolagens % 3 == 1)
			{ /*coloca números que divididos por 3 dão resto 1 na pista 1*/
				insereFim(&pista2, indicadorDP, combustivel, nomeVoo);
			} 
			else
			{ /*coloca todos outros na pista 3*/
				insereFim(&pista3, indicadorDP, combustivel, nomeVoo);
			}
			nroDecolagens++;
		}
		if ((isDecolagem == 1 || nroDecolagens > qtdDecolagens) && nroPousos <= qtdPousos)
		{  //caso seja pouso
			indicadorDP = 1;  //indicador de Pouso
			combustivel = geraRand(0, 12);  // indicador de combustivel de pouso*/
			nomeVoo = geraNomeVoo(aux,i); 
			if (combustivel == 0) 
			{  //caso de emergencia
				if (n%3==0)
				{ // se o combustível é 0 e é a primeira vez seguida que é emergência, coloca em pista1
					insereInicio(&pista1, indicadorDP, combustivel, nomeVoo);
				}
				else if (n%3==1)
				{ // se o combustível é 0 e é a segunda vez seguida que é emergência, coloca em pista2
					insereInicio(&pista2, indicadorDP, combustivel, nomeVoo);
				}
				else
				{ // se o combustível é 0 e é a terceira vez seguida que é emergência, coloca em pista3
					insereInicio(&pista3, indicadorDP, combustivel, nomeVoo);
				}
				n++;
			}
			else if (nroPousos % 2 == 0)
			{ // nroPousos pares vão para pista1
				insereFim(&pista1, indicadorDP, combustivel, nomeVoo);
			}
			else
			{ // ímpares para pista2
				insereFim(&pista2, indicadorDP, combustivel, nomeVoo);
			}
			nroPousos++;
		}
	} 
	printf("Numero de Voos: %d\n",qtdVoos);
	printf("Numero de Decolagens: %d\n",qtdDecolagens);
	printf("Numero de Pousos: %d \n",qtdPousos);
	printf("\npista 1\n");
	imprime(pista1);
	printf("\npista 2\n");
	imprime(pista2);
	printf("\npista 3\n");
	imprime(pista3);
	getchar();
	terminaFila(pista1);
	terminaFila(pista2);
	terminaFila(pista3);
	return 0;
}