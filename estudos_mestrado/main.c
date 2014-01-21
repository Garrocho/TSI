#include "ordenacao.h"
#include "recursao.h"

int main() {
	//int vetor[10] = {8,5,3,2,7,10,9,6,1,4};
	//imprime(vetor, 10);
	//selection_sort(&vetor, 10);
	//imprime(vetor, 10);
	//char frase[7] = "charles";
	//frase_ao_contrario(frase, 7);
	//int i;
	//for(i=0; i<13; i++)
    //   printf("%d ", fibonacci(i+1));
    int resultado;
    resultado = soma(20,20);
    printf("%d", resultado);
	return 0;
};

void imprime(int vetor[], int tamanho) {
	int i;
	for (i=0; i < tamanho; i++)
		printf("%d ", vetor[i]);
	printf("\n");
};