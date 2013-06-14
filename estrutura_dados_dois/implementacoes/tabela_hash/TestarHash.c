/* 
 * File:   Main.c
 * Author: charles
 */

#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

int main()
{
	int total,tamanho,placa;
	fila auxFila;
	tipo_elemento elemento;
	int i;
	char tipo;

	scanf("%d%d",&total,&tamanho);
	auxFila = cria_fila(tamanho);


	for (i = 0;i <= total;i++)
	{
		scanf("%c%d%d",&tipo,&placa,&tamanho);
		elemento.placa = placa;
		elemento.tamanho = tamanho;
		if (tipo == 'C')
                    insere_item(auxFila,elemento);
                else
                    remove_item(auxFila,elemento);
		total--;
	}
	printf("\n%d",total*10);
	termina_fila(auxFila);
	return 0;
}

