typedef struct ite
{
	char palavra[40];
	ite *prox;
}tipo_item;

typedef struct
{
	tipo_item *inicio;
	tipo_item *fim;
	int tamanhoInicio,tamanhofim;
	int tamanhoTotalInicio,tamanhoTotalFim;
}tipo_lista;

typedef struct nod
{
	char elemento;
	struct nod *prox;
}tipo_nod;

typedef struct 
{
	tipo_nod *inicio;
	int tamanho;
}tipo_pilhas;

typedef tipo_pilhas *pilhas;

typedef tipo_lista *lista;

lista cria_item();

int termina_item(lista i);

int colocar_item(lista i,char e,int n);

pilhas cria_pilhas();

void termina_pilhas(pilhas *pilhas);

int colocar_item(pilhas p, char e);

int adicionar_item(lista l,int n);

char *fim(lista l,int n);