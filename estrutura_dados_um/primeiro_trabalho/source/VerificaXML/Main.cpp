#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"
#include <string.h>

int verificaXML(pilhas p)
{
	lista l; //LISTA QUE GUARDARA OS ITENS.EX: <nome> </nome>  (NELA IREI COMPARAR AS STRINGS)
	l = cria_item();
	tipo_nod *a; //UTILIZAREI PARA PERCORRER TODA A PILHA QUE CONTEM TODO O TEXTO XML
	a = p->inicio;
	while (a != NULL)
	{
		if ((a->elemento == '<' && a->prox->elemento == '\0')||(a->elemento == '<' && a->prox->elemento == '\n')) //ERROS PRIMARIOS
			return 0;
		if (a->elemento == '<' && a->prox->elemento == '?' && a->prox->prox != NULL) //SE FOR A PRIMEIRA LINHA
		{
			a = a->prox->prox;
			while (a->elemento != '?')
			{
				if (a->elemento == '\0' || a->elemento == '\n' || a->prox == NULL)
					return 0;
				a = a->prox;
			}
			if (a->elemento == '?' && a->prox->elemento != '>')
			{
				return 0;
       		}
		}
		if (a->elemento == '<' && a->prox->elemento == '!' && a->prox->prox != NULL)  //SE FOR UM COMENTARIO
        {
			a = a->prox->prox;
			if (a->elemento == '>')
				return 0;
			while (a->elemento != '>')
			{
				if (a->elemento == '\0' || a->elemento == '\n' || a->prox == NULL)
					return 0;
				a = a->prox;
			}
		}
		if (a->elemento == '<' && a->prox->elemento != ' '  && a->prox->elemento != '?' && a->prox->elemento != '/' && a->prox != NULL)  //VERIFICA LINHA POR LINHA
		{
			adicionar_item(l,1);  //CRIA UM ITEM VAZIO E COLOCA NA PILHA
			a = a->prox;
			if (a->elemento == '>')
				return 0;
			while (a->elemento != '>')
			{
				if (a->elemento == '\0' || a->elemento == '\n' || a == NULL)
					return 0;
				colocar_item(l,a->elemento,1);  //COLOCA LETRA POR LETRA NO ITEM CRIADO ANTERIORMENTE (CASO SEJA <> COLOCA NA PRIMEIRA PILHA SENAO </> COLOCA NA SEGUNDA PILHA
				a = a->prox;
			}
			if (a->elemento == '<' && a->prox->elemento != ' ' && a->prox->prox != NULL)
			{
				adicionar_item(l,1);  //SE CASO FOR <> E <> ELE COLOCA NOVAMENTE NA PILHA
				a = a->prox->prox;
				if (a->elemento == '>')
					return 0;
				while (a->elemento != '>')
				{
					if (a->elemento == '\0' || a->elemento == '\n' || a == NULL)
						return 0;
					colocar_item(l,a->elemento,1);  //COLOCA LETRA POR LETRA
					a = a->prox;
				}
			}
		}
		if (a->elemento == '<' && a->prox->elemento == '/' && a->prox->prox != NULL && a->prox->elemento != ' ') //CASO TENHA ENCONTRADO UM </>
		{
			adicionar_item(l,2); //CRIA UM ITEM EM UMA PILHA SEPARADA DA PRIMEIRA
			a = a->prox->prox;
			if (a->elemento == '>')
				return 0;
			while (a->elemento != '>')
			{
				if (a->elemento == '\0' || a->elemento == '\n' || a == NULL)
					return 0;
				colocar_item(l,a->elemento,2); //COLOCA LETRA POR LETRA
				a = a->prox;
				if (a->elemento == '>')
				{
					if (strcmp(fim(l,1),fim(l,2)) != 0) //COMPARA A ULTIMA PALAVRA DA PRIMEIRA PILHA COM A ULTIMA PALAVRA DA SEGUNDA PILHA
						return 0;
					termina_item(l); //SE VERDADE, ELE RETIRA AS PALAVRAS E CONTINUA A VERIFICACAO
				}
			}
		}
		if ((a->prox == NULL && l->tamanhoTotalFim > l->tamanhoTotalInicio) || (a->prox == NULL && l->tamanhoTotalFim < l->tamanhoTotalInicio)) // CASO TENHA PALAVRAS A MAIS EM ALGUMA PILHA = ERRO, POIS SE EXISTE UM <> DEVA AHAVER UM </>
		{
			return 0;
		}
		a = a->prox;
	}
	return 1;
}
int main()
{
	tipo_nod *a;
	int i,conta;
	conta = 0;
	pilhas p;
	p = cria_pilhas();
	FILE *arquivo;
	arquivo = fopen("c:\\arquivo.xml", "r");
	char caractere;
	// testa se o arquivo foi aberto com sucesso
	if(arquivo != NULL)
	{
		// vamos usar um laço para ler o conteúdo do arquivo
		// e exibí-lo
		while((caractere = fgetc(arquivo)) != EOF)
		{
			colocar_item(p,caractere);
		}
		if (!verificaXML(p))
			printf("Arquivo inconsistente!\n\n");
		else
			printf("Arquivo Consistente!\n\n");
	}
	else
		printf("Nao foi possivel abrir o arquivo.");
	a = p->inicio;
	while(a != NULL)
	{
		printf("%c",a->elemento);
		a = a->prox;
	}
	fclose(arquivo); // libera o ponteiro para o arquivo
	printf("\n\n");
	termina_pilhas(&p);
	return 0;
}