// @author: Charles Tim Batista Garrocho
// @contact: charles.garrocho@gmail.com
// @copyright: (C) 2013 Software Open Source


#include "Chamada.h"
#include "Metodos.h"
#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

double geraTempo()
{
	return (double)clock();
};

double calculaTempo(double tempoInicio, double tempoFim)
{
   return ((tempoFim-tempoInicio)/CLOCKS_PER_SEC); 
};

void vetorAle(tipo_item vetor[], int tamanho)
{
	srand(time(NULL));
	tipo_chave k;
	for (k = 0;k < tamanho;k++)
	{
		vetor[k].chave = rand();
	}
};

void vetorCres(tipo_item vetor[], int tamanho)
{
	tipo_chave k,num = 1;
	for (k = 0;k < tamanho;k++)
	{
		num += 2;
		vetor[k].chave = num;
	}
};

void vetorDec(tipo_item vetor[], int tamanho)
{
	tipo_chave k,num = 1000000;
	for (k = 0;k < tamanho;k++)
	{
		num -= 1;
		vetor[k].chave = num;
	}
};

void gravarArqValor(tipo_item vetor[], FILE *arquivo, int tamanho)
{
	int numero,k;
	char buff[10];
	fputs("\n", arquivo);
	fputs("\n", arquivo);
	for (k = 0;k < tamanho;k++)
	{
		numero = vetor[k].chave;
		itoa(numero, buff, 10);
		strcat(buff,"\t");
		fputs(buff, arquivo);
	}
	fputs("\n", arquivo);
	fputs("\n", arquivo);
};

void gravarArqTempo(FILE *arquivo, double tempo)
{
	char string[20] = "Tempo Gasto: ";
	char nl = '\n',buff[20];
	putc(nl, arquivo);
	fputs(string, arquivo);
	sprintf(buff,"%8.4f",tempo);
	fputs(buff, arquivo);
	putc(nl, arquivo);
	putc(nl, arquivo);
};

void gravarArqNome(FILE *arquivo, char nome[])
{
	char nl = '\n';
	putc(nl, arquivo);
	fputs(nome, arquivo);
};

void chamaMetodos(int tamanho)
{
	double tempoAleBubble,tempoAleSelect,tempoAleInsert,tempoAleShell,tempoAleHeap,tempoAleQuick,tempoAleSemRecu,tempoAleMed,tempoAleQuickInsert;
	double tempoCreBubble,tempoCreSelect,tempoCreInsert,tempoCreShell,tempoCreHeap,tempoCreQuick,tempoCreSemRecu,tempoCreMed,tempoCreQuickInsert;
	double tempoDecBubble,tempoDecSelect,tempoDecInsert,tempoDecShell,tempoDecHeap,tempoDecQuick,tempoDecSemRecu,tempoDecMed,tempoDecQuickInsert;
	double inicio,fim;
	double menorAle,menorCre,menorDec;
	int nomeAle,nomeCre,nomeDec;
	tipo_chave numero,k;
	FILE *arquivo;
	FILE *resultado;
	char titulo[100] = "ARQUIVO CONTEM A QUANTIDADE DE TEMPO QUE CADA METODO GASTOU PARA ORDENAR\n";
	tipo_item *vetor;
	vetor = criaVetor(tamanho);
	menorAle = 999.000;
	menorCre = 999.000;
	menorDec = 999.000;
	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//bubbleSort: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome1[50] = "bubbleSort Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	bubbleSort(vetor,tamanho);
	fim = geraTempo();
	tempoAleBubble = calculaTempo(inicio,fim);
	menorAle = tempoAleBubble;
	nomeAle = 1;
	gravarArqNome(arquivo,nome1);
	gravarArqValor(vetor, arquivo, tamanho);
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,titulo);
	gravarArqNome(resultado,nome1);
	gravarArqTempo(arquivo, tempoAleBubble);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//bubbleSort: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome2[50] = "bubbleSort Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	bubbleSort(vetor,tamanho);
	fim = geraTempo();
	tempoCreBubble = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome2);
	gravarArqValor(vetor, arquivo, tamanho);
	menorCre = tempoCreBubble;
	nomeCre = 1;
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome2);
	gravarArqTempo(resultado, tempoCreBubble);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//bubbleSort: Modifica e Calcula o Tempo do Vetor Ordenando Decrescente
	char nome3[50] = "bubbleSort Ordenado Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	bubbleSort(vetor,tamanho);	
	fim = geraTempo();
	tempoDecBubble = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome3);
	gravarArqValor(vetor, arquivo, tamanho);
	menorDec = tempoDecBubble;
	nomeDec = 1;
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome3);
	gravarArqTempo(resultado, tempoDecBubble);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//selectSort: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome4[50] = "selectSort Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	selectSort(vetor,tamanho);
	fim = geraTempo();
	tempoAleSelect = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome4);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoAleSelect < menorAle)
	{
		nomeAle = 2;
		menorAle = tempoAleSelect;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome4);
	gravarArqTempo(resultado, tempoAleSelect);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//selectSort: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome5[50] = "selectSort Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	selectSort(vetor,tamanho);
	fim = geraTempo();
	tempoCreSelect = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome5);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoCreSelect < menorCre)
	{
		nomeCre = 2;
		menorCre = tempoCreSelect;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome5);
	gravarArqTempo(resultado, tempoCreSelect);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//selectSort: Modifica e Calcula o Tempo do Vetor Ordenando Decrescente
	char nome6[50] = "selectSort Ordenado Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	selectSort(vetor,tamanho);
	fim = geraTempo();
	tempoDecSelect = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome6);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoDecSelect < menorDec)
	{
		nomeDec = 2;
		menorDec = tempoDecSelect;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome6);
	gravarArqTempo(resultado, tempoDecSelect);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//insertSort: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome7[50] = "insertSort Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	insertSort(vetor,tamanho);
	fim = geraTempo();
	tempoAleInsert = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome7);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoAleInsert < menorAle)
	{
		nomeAle = 3;
		menorAle = tempoAleInsert;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome7);
	gravarArqTempo(resultado, tempoAleInsert);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//insertSort: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome8[50] = "insertSort Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	insertSort(vetor,tamanho);
	fim = geraTempo();
	tempoCreInsert = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome8);
	gravarArqValor(vetor, arquivo, tamanho);
	gravarArqNome(arquivo,nome8);
	if (tempoCreInsert < menorCre)
	{
		nomeCre = 3;
		menorCre = tempoCreInsert;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome8);
	gravarArqTempo(resultado, tempoCreInsert);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//insertSort: Modifica e Calcula o Tempo do Vetor Ordenando Decrescente
	char nome9[50] = "insertSort Ordenado Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	insertSort(vetor,tamanho);
	fim = geraTempo();
	tempoDecInsert = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome9);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoDecInsert < menorDec)
	{
		nomeDec = 3;
		menorDec = tempoDecInsert;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome9);
	gravarArqTempo(resultado, tempoDecInsert);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//shellSort: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome10[50] = "shellSort Ordenado Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	shellSort(vetor,tamanho);
	fim = geraTempo();
	tempoAleShell = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome10);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoAleShell < menorAle)
	{
		nomeAle = 4;
		menorAle = tempoAleShell;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome10);
	gravarArqTempo(resultado, tempoAleShell);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//shellSort: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome11[50] = "shellSort Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	shellSort(vetor,tamanho);
	fim = geraTempo();
	tempoCreShell = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome11);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoCreShell < menorCre)
	{
		nomeCre = 4;
		menorCre = tempoCreShell;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome11);
	gravarArqTempo(resultado, tempoCreShell);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//shellSort: Modifica e Calcula o Tempo do Vetor Ordenando Decrescente
	char nome12[50] = "shellSort Ordenado Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	shellSort(vetor,tamanho);
	fim = geraTempo();
	tempoDecShell = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome12);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoDecShell < menorDec)
	{
		nomeDec = 4;
		menorDec = tempoDecShell;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome12);
	gravarArqTempo(resultado, tempoDecShell);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");
	
	//heapSort: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome13[50] = "heapSort Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	heapSort(vetor,tamanho);
	fim = geraTempo();
	tempoAleHeap = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome13);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoAleHeap < menorAle)
	{
		nomeAle = 5;
		menorAle = tempoAleHeap;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome13);
	gravarArqTempo(resultado, tempoAleHeap);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//heapSort: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome14[50] = "heapSort Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	heapSort(vetor,tamanho);
	fim = geraTempo();
	tempoCreHeap = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome14);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoCreHeap < menorCre)
	{
		nomeCre = 5;
		menorCre = tempoCreHeap;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome14);
	gravarArqTempo(resultado, tempoCreHeap);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//heapSort: Modifica e Calcula o Tempo do Vetor Ordenando Decrescente
	char nome15[50] = "heapSort Ordenado Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	heapSort(vetor,tamanho);
	fim = geraTempo();
	tempoDecHeap = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome15);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoDecHeap < menorDec)
	{
		nomeDec = 5;
		menorDec = tempoDecHeap;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome15);
	gravarArqTempo(resultado, tempoAleHeap);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//quickSort: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome16[50] = "quickSort Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	quickSort(vetor,tamanho);
	fim = geraTempo();
	tempoAleQuick = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome16);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoAleQuick < menorAle)
	{
		nomeAle = 6;
		menorAle = tempoAleQuick;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome16);
	gravarArqTempo(resultado, tempoAleQuick);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//quickSort: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome17[50] = "quickSort Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	quickSort(vetor,tamanho);
	fim = geraTempo();
	tempoCreQuick = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome17);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoCreQuick < menorCre)
	{
		nomeCre = 6;
		menorCre = tempoCreQuick;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome17);
	gravarArqTempo(resultado, tempoCreQuick);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	//quickSort: Modifica e Calcula o Tempo do Vetor Ordenando Decrescente
	char nome18[50] = "quickSort Ordenado Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	quickSort(vetor,tamanho);
	fim = geraTempo();
	tempoDecQuick = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome18);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoDecQuick < menorDec)
	{
		nomeDec = 6;
		menorDec = tempoDecQuick;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome18);
	gravarArqTempo(resultado, tempoDecQuick);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	// quickSort Sem Recursao: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome19[50] = "quickSort Sem Recursao Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	QuickSortNaoRec(vetor,tamanho);
	fim = geraTempo();
	tempoAleSemRecu = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome19);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoAleSemRecu < menorAle)
	{
		nomeAle = 7;
		menorAle = tempoAleSemRecu;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome19);
	gravarArqTempo(resultado, tempoAleSemRecu);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	// quickSort Sem Recursao: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome20[50] = "quickSort Sem Recursao Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	QuickSortNaoRec(vetor,tamanho);
	fim = geraTempo();
	tempoCreSemRecu = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome20);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoCreSemRecu < menorCre)
	{
		nomeCre = 7;
		menorCre = tempoCreSemRecu;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome20);
	gravarArqTempo(resultado, tempoCreSemRecu);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	// quickSort Sem Recursao: Modifica e Calcula o Tempo do Vetor Ordenado Decrescente
	char nome21[50] = "quickSort Sem Recursao Ordenado Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	QuickSortNaoRec(vetor,tamanho);
	fim = geraTempo();
	tempoDecSemRecu = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome21);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoDecSemRecu < menorDec)
	{
		nomeDec = 7;
		menorDec = tempoDecSemRecu;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome21);
	gravarArqTempo(resultado, tempoDecSemRecu);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");


	// quickSort MEDIANA 3: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome22[50] = "quickSort MEDIANA 3 Ordenado Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	quickSortMediana3(vetor,tamanho);
	fim = geraTempo();
	tempoAleMed = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome22);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoAleMed < menorAle)
	{
		nomeAle = 8;
		menorAle = tempoAleMed;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome22);
	gravarArqTempo(resultado, tempoAleMed);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	// quickSort MEDIANA 3: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome23[50] = "quickSort MEDIANA 3 Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	quickSortMediana3(vetor,tamanho);
	fim = geraTempo();
	tempoCreMed = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome23);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoCreMed < menorCre)
	{
		nomeCre = 8;
		menorCre = tempoCreMed;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome23);
	gravarArqTempo(resultado, tempoCreMed);
	fclose(resultado);

	// quickSort MEDIANA 3: Modifica e Calcula o Tempo do Vetor Ordenado Decrescente
	char nome24[50] = "quickSort MEDIANA 3 Ordenando Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	quickSortMediana3(vetor,tamanho);
	fim = geraTempo();
	tempoDecMed = calculaTempo(inicio,fim);
	gravarArqValor(vetor, arquivo, tamanho);
	gravarArqNome(arquivo,nome24);
	if (tempoDecMed < menorDec)
	{
		nomeDec = 8;
		menorDec = tempoDecMed;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome24);
	gravarArqTempo(resultado, tempoDecMed);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	// quickSort Seguimento <= 20: Modifica e Calcula o Tempo do Vetor Aleatorio
	char nome25[50] = "quickSort Seguimento <= 20 Ordenado Aleatorio";
	vetorAle(vetor,tamanho);
	inicio = geraTempo();
	quickSortInsert(vetor,tamanho);
	fim = geraTempo();
	tempoAleQuickInsert = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome25);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoAleQuickInsert < menorAle)
	{
		nomeAle = 9;
		menorAle = tempoAleQuickInsert;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome25);
	gravarArqTempo(resultado, tempoAleQuickInsert);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	// quickSort Seguimento <= 20: Modifica e Calcula o Tempo do Vetor Ordenado Crescente
	char nome26[50] = "quickSort Seguimento <= 20 Ordenado Crescente";
	vetorCres(vetor,tamanho);
	inicio = geraTempo();
	quickSortInsert(vetor,tamanho);
	fim = geraTempo();
	tempoCreQuickInsert = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome26);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoCreQuickInsert < menorCre)
	{
		nomeCre = 9;
		menorCre = tempoCreQuickInsert;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome26);
	gravarArqTempo(resultado, tempoCreQuickInsert);
	fclose(resultado);

	arquivo = fopen("C:\\arquivos1\\vetores.txt","a+");

	// quickSort Seguimento <= 20: Modifica e Calcula o Tempo do Vetor Ordenado Decrescente
	char nome27[50] = "quickSort Seguimento <= 20 Ordenando Decrescente";
	vetorDec(vetor,tamanho);
	inicio = geraTempo();
	quickSortInsert(vetor,tamanho);
	fim = geraTempo();
	tempoDecQuickInsert = calculaTempo(inicio,fim);
	gravarArqNome(arquivo,nome27);
	gravarArqValor(vetor, arquivo, tamanho);
	if (tempoDecQuickInsert < menorDec)
	{
		nomeDec = 9;
		menorDec = tempoDecQuickInsert;
	}
	fclose(arquivo);

	resultado = fopen("C:\\arquivos1\\resultados.txt","a+");
	gravarArqNome(resultado,nome27);
	gravarArqTempo(resultado, tempoDecQuickInsert);

	char texto1[50] = "Melhores Tempos\n\nMenor Tempo Aleatorio: ";
	char texto2[50] = "Menor Tempo Ordenando Crescente: ";
	char texto3[50] = "Menor Tempo Ordenando Decrescente: ";
	gravarArqNome(resultado,texto1);
	switch(nomeAle)
	{
	//case 1:gravarArqNome(resultado,nome1);break;
	//case 2:gravarArqNome(resultado,nome4);break;
	//case 3:gravarArqNome(resultado,nome7);break;
	case 4:gravarArqNome(resultado,nome10);break;
	case 5:gravarArqNome(resultado,nome13);break;
	case 6:gravarArqNome(resultado,nome16);break;
	case 7:gravarArqNome(resultado,nome19);break;
	case 8:gravarArqNome(resultado,nome22);break;
	case 9:gravarArqNome(resultado,nome25);break;
	}
	gravarArqTempo(resultado,menorAle);
	gravarArqNome(resultado,texto2);
	switch(nomeCre)
	{
	//case 1:gravarArqNome(resultado,nome2);break;
	//case 2:gravarArqNome(resultado,nome5);break;
	//case 3:gravarArqNome(resultado,nome8);break;
	case 4:gravarArqNome(resultado,nome11);break;
	case 5:gravarArqNome(resultado,nome14);break;
	case 6:gravarArqNome(resultado,nome17);break;
	case 7:gravarArqNome(resultado,nome20);break;
	case 8:gravarArqNome(resultado,nome23);break;
	case 9:gravarArqNome(resultado,nome26);break;
	}
	gravarArqTempo(resultado,menorCre);
	gravarArqNome(resultado,texto3);
	switch(nomeDec)
	{
	//case 1:gravarArqNome(resultado,nome3);break;
	//case 2:gravarArqNome(resultado,nome6);break;
	//case 3:gravarArqNome(resultado,nome9);break;
	case 4:gravarArqNome(resultado,nome12);break;
	case 5:gravarArqNome(resultado,nome15);break;
	case 6:gravarArqNome(resultado,nome18);break;
	case 7:gravarArqNome(resultado,nome21);break;
	case 8:gravarArqNome(resultado,nome24);break;
	case 9:gravarArqNome(resultado,nome27);break;
	}
	gravarArqTempo(resultado,menorDec);

	//Libera o espaco utilizado pelo vetor e fecha o arquivo
	fclose(resultado);
	free(vetor);
};
