typedef struct nodo
{
	int valor;
	int linha,coluna;
	nodo *direita,*abaixo;
}tipo_nodo;

typedef struct
{
	int linha,coluna;
	tipo_nodo *inicio;
}tipo_lista;

typedef tipo_lista *lista;

int inicializaColuna(lista a,int coluna,int linha);

int inicializaLinha(lista a,int coluna,int linha);

int criaLista(lista*,int,int);

int imprimeMatriz(lista);

int leMatriz(lista);

int apagaMatriz(lista);

int somaMatriz(lista,lista,lista);

int multiplicaMatriz(lista,lista,lista);

int insereValor(int,int,int,lista);