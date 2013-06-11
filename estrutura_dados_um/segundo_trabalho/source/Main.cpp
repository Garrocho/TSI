// @author: Charles Tim Batista Garrocho
// @contact: charles.garrocho@gmail.com
// @copyright: (C) 2013 Software Open Source

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Metodos.h"
#include "Chamada.h"

#define MAX_5000 5000
#define MAX_10000 10000
#define MAX_50000 50000
#define MAX_100000 100000
#define MAX_500000 500000
#define MAX_1000000 1000000

int main()
{
	char op;
	do {
		system("cls");
		printf("Selecione o Tamanho do Vetor a Ser Criado e Ordenado");
		printf("\nLocal Que os Arquivos Seram Gravados: C:\\arquivos1\\");
		printf("\n\n1 - Calcula Tempo de 5.000");
		printf("\n2 - Calcula Tempo de 10.000");
		printf("\n3 - Calcula Tempo de 50.000");
		printf("\n4 - Calcula Tempo de 100.000");
		printf("\n5 - Calcula Tempo de 500.000");
		printf("\n6 - Calcula Tempo de 1.000.000");
		printf("\n7 - Sair");
		printf("\n\nOpcao: ");
		op = getchar();
		switch(op)
		{
			case '1':chamaMetodos(MAX_5000);break;
			case '2':chamaMetodos(MAX_10000);break;
			case '3':chamaMetodos(MAX_50000);break;
			case '4':chamaMetodos(MAX_100000);break;
			case '5':chamaMetodos(MAX_500000);break;
			case '6':chamaMetodos(MAX_1000000);break;
		}
	}while(op != '7');
	return 0;
};
