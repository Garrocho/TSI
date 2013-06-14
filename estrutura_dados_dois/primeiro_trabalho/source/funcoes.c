// Autor: Charles Garrocho
// Data: 10/04/2012

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "funcoes.h"
#include "tabela_hash.h"
#include "arvore_avl.h"
#include "arvore_b.h"

/* CRIA UM NOVO ARQUIVO E ADICIONA NELE TEMPO DE EXECUCAO E O CONSUMO DE MEMORIA */
void CriaArquivoDesempenho()
{
	FILE *arquivoDesempenho;
	char *arquivosDesempenho = "Documentos\\Desempenho.txt"; 
	double inicio,fim,memoria;

	// Abre o arquivo para leitura
	arquivoDesempenho = fopen(arquivosDesempenho, "w");

	inicio = clock();
	memoria = ExecutaTabelaHASH();
	fim = clock();
	fprintf (arquivoDesempenho, "TABELA HASH\nTempo Execucao....: %.4f\nConsumo de Memoria: %.4f\n\n",CalculaTempo(inicio,fim),memoria);

	inicio = clock();
	memoria = ExecutaArvoreAVL();
	fim = clock();
	fprintf (arquivoDesempenho, "ARVORE AVL\nTempo Execucao....: %.4f\nConsumo de Memoria: %.4f\n\n",CalculaTempo(inicio,fim),memoria);

	inicio = clock();
	memoria = ExecutaArvoreB();
	fim = clock();
	fprintf (arquivoDesempenho, "ARVORE B\nTempo Execucao....: %.4f\nConsumo de Memoria: %.4f\n\n",CalculaTempo(inicio,fim),memoria);

	fclose(arquivoDesempenho);
}

/* CALCULA A DIVISAO DA SUBTRACAO DO TEMPO INICIO E FIM POR CLOCK */
double CalculaTempo(double inicio, double fim)
{
	return  ( fim - inicio ) / CLOCKS_PER_SEC;
}

/* RETORNA 1 SE FOR UM CARACTER VALIDO, OU 0 SE FOR UM CARACTER ESPECIAL */
int VerificaLetra(char c)
{
	int i = (int)c;
	if (!((
              (i >= 65  && i <= 90  )  ||
              (i >= 97  && i <= 122 )  ||
			  (i >= 130 && i <= 133 )  ||
			  (i >= 135 && i <= 138 )  ||
			  (i >= 147 && i <= 151 )  ||
			  (i >= 160 && i <= 163 )  || 
			  (i >= 181 && i <= 183 )  ||
			  (i >= 210 && i <= 212 )  ||
			  (i >= 226 && i <= 229 )  ||
			  (i >= 233 && i <= 235 )) ||
              (i == 128 || i == 144 )  || 
			  (i == 199 || i == 198 )))
			return 0;
	else
		return 1;
}

/* CRIA UM INDICE UNICO A PARTIR DO CODIGO ASCI DE CADA LETRA EM UMA PALAVRA */
int CriaIndice(TipoPalavra palavra)
{
    int i;
	unsigned int soma = 0;
	for (i = 0; i < N; i++)
        soma += toascii(palavra[i]);
	return soma % TAMANHO_TABELA;
}

/* RETORNA A QUANTIDADE DE LINHAS DE UM DETERMINADO ARQUIVO */
int QuantidadeLinhas(char *caminhoArquivo)
{
	FILE *arquivo;
	int contador = 0;
	char letra;

	// Abre o arquivo para leitura
    arquivo = fopen(caminhoArquivo, "r");
	rewind(arquivo);

	letra = getc(arquivo);
	while(letra != EOF)
	{
		letra = getc(arquivo);
		if (letra == '\n')
			contador++;
	}
	
	fclose(arquivo);
	return contador++;
}

/* ABRE O ARQUIVO ESPECIFICADO E ADICIONA AS PALAVRAS DOS ARQUIVOS NA TABELA HASH */
double ExecutaTabelaHASH()
{
	FILE *arquivoInvertido;
	char *arquivosInvertido = "Documentos\\ArquivoInvertidoHash.txt";
	FILE *arquivoTXT;
	FILE *arquivo;
	char *arquivosTXT = "Documentos\\Arquivos.txt";
	int contPalavra,idArquivo,qtdeLinhas,k;
	char letra;
	char palavra[50];
	Tabela novaTabela;
	TipoRegistro novoElemento;
	double memoria = 0;

	idArquivo = 0;

	// Abre o arquivo para leitura
	arquivoTXT = fopen(arquivosTXT, "r");

	// Posiciona na primeira linha dos arquivos
	rewind(arquivoTXT);
	
	// Cria uma nova Tabela e um novo Elemento
	CriaTabela(&novaTabela);
	novoElemento = CriaRegistroSemPonteiro();
	
	qtdeLinhas = QuantidadeLinhas(arquivosTXT);
	fscanf(arquivoTXT,"%s",&palavra);

	while(qtdeLinhas > 0)
	{
		char *nomeArquivo = palavra;

		idArquivo++;

		// Abre o arquivo para leitura
		arquivo = fopen(nomeArquivo, "r");
		
		// Posiciona no começo do arquivo
		rewind(arquivo);
		
		// tranforma cada palavra do texto em um número ASCII
		do {
			letra = getc(arquivo);
			for (contPalavra = 0; contPalavra <= TAMANHO_PALAVRA; contPalavra++)
				novoElemento.palavra[contPalavra] = ' ';
			contPalavra = 0;

			// Guarda cada palavra em uma variável
			while (letra != ' ' && letra != '\n' && letra != EOF)
			{
				if ( VerificaLetra(letra) )
					novoElemento.palavra[contPalavra++] = tolower(letra);
				letra = fgetc(arquivo);
				if (contPalavra == N)
				{
					while(letra != ' ' && letra != '\n' && letra != EOF)
					{
						letra = fgetc(arquivo);
					}
					contPalavra = 0;
				}
			}
			memoria += InsereItem(&novaTabela,novoElemento,idArquivo);
		} while (letra != EOF);

		fclose(arquivo);
		qtdeLinhas--;
		fscanf(arquivoTXT,"%s",&palavra);
	}

	arquivoInvertido = fopen(arquivosInvertido, "w"); 
	
	for (k = 0; k < TAMANHO_TABELA; k++)
		CriaArquivoInvertidoHash(novaTabela[k], arquivoInvertido);
	
	// Fecha os arquivos
	fclose(arquivoTXT);
	fclose(arquivoInvertido);
	return memoria;
}

/* ABRE O ARQUIVO ESPECIFICADO E ADICIONA AS PALAVRAS DOS ARQUIVOS NA ARVORE AVL */
double ExecutaArvoreAVL()
{
	FILE *arquivoInvertido;
	char *arquivosInvertido = "Documentos\\ArquivoInvertidoAVL.txt";
	FILE *arquivoTXT;
	FILE *arquivo;
	char *arquivosTXT = "Documentos\\Arquivos.txt";
	int contPalavra,idArquivo,qtdeLinhas;
	char letra;
	char palavra[50];
	double memoria = 0;

	TipoArvoreAVL ArvoreAVL = NULL;
	Registro novoElementoAVL;

	idArquivo = 0;
	
	// Abre o arquivo para leitura
	arquivoTXT = fopen(arquivosTXT, "r"); 

	// Posiciona na primeira linha dos arquivos
	rewind(arquivoTXT);

	novoElementoAVL = CriaRegistro();
	memoria += sizeof(TipoRegistro);
	
	qtdeLinhas = QuantidadeLinhas(arquivosTXT);
	fscanf(arquivoTXT,"%s",&palavra);
	
	while(qtdeLinhas > 0)
	{
		char *nomeArquivo = palavra;

		idArquivo++;

		// Abre o arquivo para leitura
		arquivo = fopen(nomeArquivo, "r");
		
		// Posiciona no começo do arquivo
		rewind(arquivo);
		
		// tranforma cada palavra do texto em um número ASCII
		do {
			letra = getc(arquivo);
			for (contPalavra = 0; contPalavra <= TAMANHO_PALAVRA; contPalavra++)
				novoElementoAVL->palavra[contPalavra] = ' ';
			contPalavra = 0;
			
			// Guarda cada palavra em uma variável
			while (letra != ' ' && letra != '\n' && letra != EOF)
			{
				if ( VerificaLetra(letra) )
					novoElementoAVL->palavra[contPalavra++] = tolower(letra);
				letra = fgetc(arquivo);
				if (contPalavra == N)
				{
					while(letra != ' ' && letra != '\n' && letra != EOF)
					{
						letra = fgetc(arquivo);
					}
					contPalavra = 0;
				}
			}
			
			memoria += InsereAVL(&ArvoreAVL,novoElementoAVL,idArquivo);
		} while (letra != EOF);

		fclose(arquivo);
		qtdeLinhas--;
		fscanf(arquivoTXT,"%s",&palavra);
	}
	arquivoInvertido = fopen(arquivosInvertido, "w"); 
	CriaArquivoInvertidoAVL(ArvoreAVL, arquivoInvertido);

	// Fecha os arquivos
	fclose(arquivoTXT);
	fclose(arquivoInvertido);
	return memoria;
}

/* ABRE O ARQUIVO ESPECIFICADO E ADICIONA AS PALAVRAS DOS ARQUIVOS NA ARVORE B */
double ExecutaArvoreB()
{
	FILE *arquivoInvertido;
	char *arquivosInvertido = "Documentos\\ArquivoInvertidoB.txt";
	FILE *arquivoTXT;
	FILE *arquivo;
	char *arquivosTXT = "Documentos\\Arquivos.txt";
	int contPalavra,idArquivo,qtdeLinhas;
	char letra;
	char palavra[50];
	Apontador *ArvoreB;
	TipoRegistro reg;
	double memoria = 0;

	memoria += sizeof(Pagina);
	ArvoreB = (Apontador*) malloc(sizeof(Apontador));
	Inicializa(ArvoreB);
	idArquivo = 0;

	// Abre o arquivo para leitura
    arquivoTXT = fopen(arquivosTXT, "r");
	
	qtdeLinhas = QuantidadeLinhas(arquivosTXT);
	fscanf(arquivoTXT,"%s",&palavra);
	
	while(qtdeLinhas > 0)
	{
		char *nomeArquivo = palavra;

		reg = CriaRegistroSemPonteiro();
		idArquivo++;

		// Abre o arquivo para leitura
		arquivo = fopen(nomeArquivo, "r");
		
		// Posiciona no começo do arquivo
		rewind(arquivo);
		
		// tranforma cada palavra do texto em um número ASCII
		do {
			letra = getc(arquivo);
			for (contPalavra = 0; contPalavra <= TAMANHO_PALAVRA+1; contPalavra++)
				reg.palavra[contPalavra] = ' ';
			contPalavra = 0;

			// Guarda cada palavra em uma variável
			while (letra != ' ' && letra != '\n' && letra != EOF)
			{
				if ( VerificaLetra(letra) )
					reg.palavra[contPalavra++] = tolower(letra);
				letra = fgetc(arquivo);
				if (contPalavra == N)
					{
					while(letra != ' ' && letra != '\n' && letra != EOF)
					{
						letra = fgetc(arquivo);
					}
					contPalavra = 0;
				}
			}
			memoria += Insere(reg, ArvoreB, idArquivo);

		} while (letra != EOF);

		fclose(arquivo);
		qtdeLinhas--;
		fscanf(arquivoTXT,"%s",&palavra);
	}

	// Gera arquivo invertido B
	arquivoInvertido = fopen(arquivosInvertido, "w"); 
	CriaArquivoInvertidoB(*ArvoreB, arquivoInvertido, mm);

	// Fecha os arquivos
	fclose(arquivoTXT);
	fclose(arquivoInvertido);
	return memoria;
}

/* RETORNA A QUANTIDADE DE CARACTERES EXISTENTE EM UMA PALAVRA */
int TamanhoString(TipoPalavra palavra)
{
	int i = 0;
	do {
	}while (palavra[i++] != ' ');
	return i;
}

/* CRIA UM ARQUIVO CONTENDO UM ID VINCULADO A UM ARQUIVO TXT */
void CriaDocID()
{
	FILE *arquivoTXT;
	FILE *arquivoDocID;
	char *arquivosTXT = "Documentos\\Arquivos.txt";
	char *arquivosDocID = "Documentos\\DocID.txt";
	char palavra[100];
	int qtdeLinhas,cont;

	system("dir /B *.txt > Documentos\\Arquivos.txt");
	cont = 0;

	// Abre o arquivo para leitura
    arquivoTXT = fopen(arquivosTXT, "r");
    arquivoDocID = fopen(arquivosDocID, "w");

	// Posiciona na primeira linha dos arquivos
	rewind(arquivoTXT);
	qtdeLinhas = QuantidadeLinhas(arquivosTXT);

	while(qtdeLinhas > 0)
	{
		cont++;
		fscanf(arquivoTXT,"%s",&palavra);
		fprintf (arquivoDocID, "ID: %d \tARQUIVO: %-35.35s\n",cont,palavra);
		qtdeLinhas--;
	}
	fclose(arquivoDocID);
	fclose(arquivoTXT);
}
