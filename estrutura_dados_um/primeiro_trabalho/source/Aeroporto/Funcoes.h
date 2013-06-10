typedef struct voo 
{
	char nome[6]; /*indicador do código do voo*/
	int indicadorDP; /*indicador se o avião est? pousando ou decolando*/
	int comb; /*indicador de combustível*/
	struct voo* prox;
}Voo;

typedef struct fila 
{ /*estrutura que indica inicio e final de fila*/
	Voo* inicio;
	Voo* fim;
} fila;

fila* criaFila(void);/*função para criar a fila*/

int filaVazia(fila*) ;/*função para verificar se a fila esta vazia*/

Voo* criaVoo(fila*, int , int , int ); /*cria voo a ser inserido ao final da lista*/

void terminaFila(fila*);/*função para terminar as listas*/

void imprime(fila*);/*função para imprimir as filas*/

int geraNomeVoo(int*,int);/*função para gerar n de voo aleatoriamente*/

int geraRand(int,int);/*função para gerar numero aleatoriamente*/

void insereInicio(fila**,int,int,int);/*função para inserir no inicio da fila*/

void insereFim(fila**,int,int,int);/*função para inserir no final da fila*/

void setAux(int*);/*coloca -1 em todas as posições de aux*/