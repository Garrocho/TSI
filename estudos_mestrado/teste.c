#include <stdio.h>
#include <stdlib.h>
#define TOTALVERTICES 8

typedef struct item {
	int chave;
	struct item* prox;
}VERTICE;

ITEM *lista;

void Imprimir(ITEM *lista, int tamanho);
void Inserir_Aresta(ITEM *lista, int a, int b);


int main(int argc, char *argv[]){
  int i,a,b,tamanho;
  char linha[50];
  FILE *fp;

  fp = fopen(argv[1],"r");
  if (!fp) {
    printf("Erro ao abrir o arquivo %s.\n",argv[1]);
    return 0;
  }

  fgets(linha, 100, fp);

  tamanho = atoi(linha) +1 ;
  printf("%d\n", tamanho);
  ITEM lista[tamanho+1];
  
  // Inicialização da lista. 
  for(i=1; i<=tamanho; i++){
    printf("erro\n");
    lista[i].campo = 0;
    lista[i].prox = NULL;
  }

  //leitura dos vertices (a,b) - passagem para a função Inserir_Aresta.
  fscanf(fp,"%d %d", &a, &b);
  while (!feof(fp)) {
    printf("%d - %d\n", a, b);
    Inserir_Aresta(lista,a,b);
    Inserir_Aresta(lista,b,a);
    fscanf(fp,"%d%d", &a, &b);
  }

  Imprimir(lista, tamanho);
}


void Imprimir(ITEM *lista, int tamanho) {
  int i;
  ITEM * tmp;
  for(i=1; i<=tamanho; i++) {
    tmp = lista[i].prox;
    printf("%2d: (%d) ==>", i, lista[i].campo);
    while (tmp != NULL) {
      printf("%d  ", tmp->campo);
      tmp = tmp->prox;
    }
    printf("\n");
  }
}

void Inserir_Aresta(ITEM *lista, int a, int b){
  ITEM *aux;
  ITEM *tmp;
 
  aux = (ITEM*) malloc((int)sizeof(ITEM));    //retorno de um ponteiro genérico.
  aux->campo = b;
  aux->prox = NULL;
  
  lista[a].campo++;
  if(lista[a].prox == NULL) // Caso a lista estiver vazia - Insere.	
    lista[a].prox = aux;
  else	{
    tmp = lista[a].prox;
    if (tmp->campo > b) { //insere como primeiro da lista
      aux->prox = tmp;
      lista[a].prox = aux;
    } 		          //insere os vértices ordenados
    else if (tmp->prox == NULL) { 
      aux->prox = tmp->prox;
      tmp->prox = aux;  
    }
    else {
      while((tmp->prox != NULL) &&(tmp->prox->campo < b))
	tmp = tmp->prox;
      aux->prox = tmp->prox;
      tmp->prox = aux;  
    }
  }
}