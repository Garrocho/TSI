#include "Metodos.h"
#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

tipo_item *criaVetor(int tamanho) //cria um vetor de tamanho N com elementos de 0 a 32767(RAND_MAX)
{
    tipo_item *vetor;
	vetor = (tipo_item*)malloc(sizeof(tipo_item)*tamanho);
    return vetor;
};

void bubbleSort(tipo_item *v, int tamanho)
{
	int i, ultima_troca, ultima_posicao;
	tipo_item aux;
	ultima_posicao=tamanho;
	do{
		ultima_troca = 0;
		for( i = 0 ; i < ultima_posicao-1 ; i++ )
			if (v[i].chave > v[i+1].chave)
			{
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				ultima_troca = i+1;
			}
		ultima_posicao = ultima_troca;
	}while(ultima_posicao>0);
};

void selectSort (tipo_item* v, int n)
{
	int i, j, posicao_menor;
	tipo_item aux;
	for (i = 0; i < n - 1; i++)
	{
		posicao_menor = i;
		for (j = i + 1 ; j < n; j++)
		if ( v[j].chave < v[posicao_menor].chave)
			posicao_menor = j;
		aux = v[posicao_menor];
		v[posicao_menor] = v[i];
		v[i] = aux;
	}
};

void insertSort (tipo_item* v, int n )
{
	int i,j;
	tipo_item aux;
	for (i = 1; i < n; i++)
	{
		aux = v[i];
		j = i - 1;
		while ( ( j >= 0 ) && ( aux.chave < v[j].chave ) )
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = aux;
	}
};

void shellSort (tipo_item* A, int n)
{
	int i, j;
	int h = 1;
	tipo_item aux;
	do 
		h = h * 3 + 1; 
	while (h < n);
	do {
			h /= 3;
			for( i = h ; i < n ; i++ )
			{
				aux = A[i]; 
				j = i;
				while (A[j-h].chave > aux.chave)
				{
					A[j] = A[j-h]; 
					j -= h;
					if (j < h)
						break;
				}
				A[j] = aux;
			}
	} while (h != 1);
};

//Metodo HeapSort
void heapSort(tipo_item *v, int tamanho)
{
     int i;
     tipo_item aux;

     //Construindo o Heap
     for(i = tamanho/2; i >= 0; i--)
        constroi(v,i,tamanho-1); // O(log n), v=vetor, i=posicao, tamanho-1=ultimo elemento do vetor

    //ordenando o vetor x
    for(i = tamanho-1; i > 0; i--)
     {
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        constroi(v,0,i-1);
     }
}

void constroi(tipo_item *v, int posicao, int fim) //fim = indice da ultima posicao
{
     int trocou, h, i;
     tipo_item aux;
     i = posicao;
     trocou = 1;

     do
     {
        if(2 * i > fim)
           trocou = 0;
        else
        {
           if(2 * i + 1 > fim)
              h = 2 * i;
           else
              if(v[2*i].chave > v[2*i+1].chave)
                 h = 2 * i;
              else
                 h = 2 * i + 1;
           if(v[i].chave < v[h].chave)
           {
              aux = v[i];
              v[i] = v[h];
              v[h] = aux;
              i = h;
           }
           else
              trocou = 0;
        }
     }while(trocou);
}

//Metodo QuickSort
void quickSort(tipo_item *v, int tamanho)
{
	particao(v,0,tamanho-1);
};

//Metodo QuickSort Segmento <= 20
void quickSortMenor20(tipo_item *v, int tamanho)
{
	int esq = 0,dir = tamanho-1;
	if ((esq - dir) <= 20)
    {    
        insertSort(v,tamanho);
        return;
    }
	else
		particao(v,0,tamanho-1);
};

void particao(tipo_item *v, int esq, int dir)
{
	int i,k;
	tipo_item aux, pivo;
	pivo = v[(esq+dir)/2];
	i = esq;
	k = dir;
	do {
		while(v[i].chave < pivo.chave)
			i++;
        while(v[k].chave > pivo.chave)
			k--;
		if (i <= k)
		{
			aux = v[i];
			v[i] = v[k];
			v[k] = aux;
			i++;
			k--;
		}
	}while(i <= k);
	if (esq < k)
		particao(v,esq,k);
	if (i < dir)
		particao(v,i,dir);
};

//Metodo QuickSort Com Mediana 3 Com recursao
void quickSortMediana3(tipo_item *v, int tamanho)
{
	particao3(v,0,tamanho-1);
};

void particao3(tipo_item *v, int esq, int dir)
{
	int i,k;
	tipo_item aux, pivo;
	pivo = v[(esq+dir+(esq+dir)/2)/3];
	i = esq;
	k = dir;
	do {
		while(v[i].chave < pivo.chave)
			i++;
        while(v[k].chave > pivo.chave)
			k--;
		if (i <= k)
		{
			aux = v[i];
			v[i] = v[k];
			v[k] = aux;
			i++;
			k--;
		}
	}while(i <= k);
	if (esq < k)
		particao(v,esq,k);
	if (i < dir)
		particao(v,i,dir);
};

void Particiona(tipo_item *A, int Esq, int Dir,int *i, int *j)
{ 
  tipo_item x, aux;
  *i = Esq; *j = Dir;
  x = A[(*i + *j)/2]; // obtem o pivo x
  do
  { 
    while (x.chave > A[*i].chave) (*i)++;
    while (x.chave < A[*j].chave) (*j)--;
    if (*i <= *j)
    { 
      aux = A[*i]; 
	  A[*i] = A[*j]; 
	  A[*j] = aux;
      (*i)++; 
	  (*j)--;
    }
  } while (*i <= *j);
};

//Metodo QuickSort Sem Recursao
void QuickSortNaoRec(tipo_item *v, int tamanho)
{
     TipoPilha pilha; 
	 TipoItem item;
     int esq, dir, i = 0, j;
     FPVazia(&pilha);
     esq = 0;
     dir = tamanho-1;
     item.dir = dir;
     item.esq = esq;
     Empilha(item, &pilha);
	 do 
	 {
		   if (dir > esq)
		   {
			  Particiona(v,esq,dir,&i, &j);
			  if ((j-esq)>(dir-i))
			  {
				 item.dir = j;
				 item.esq = esq;
				 Empilha(item, &pilha);
				 esq = i;
			  }
			  else 
			  {
				  item.esq = i;
				  item.dir = dir;
				  Empilha(item, &pilha);
				  dir = j;
			  }
		   }
		 else 
		 {
			Desempilha(&pilha,&item);
			dir = item.dir;
			esq = item.esq;
		 }
     }while (!Vazia(pilha));
};

//Metodo quickSortPivoMenor20Insert (QuickSort Pivo = Segmento <=20 usa InsertSort)
void quickSortInsert(tipo_item *v, int tamanho)
{
	particaoInsert(v,0,tamanho-1);
}

void particaoInsert(tipo_item *v, int esq, int dir)
{
	int i,k;
	tipo_item aux, pivo;
	pivo = v[(esq+dir+(esq+dir)/2)/3]; //mudou isso aki
	i = esq;
	k = dir;
	do {
		while(v[i].chave < pivo.chave)
			i++;
        while(v[k].chave > pivo.chave)
			k--;
		if (i <= k)
		{
			aux = v[i];
			v[i] = v[k];
			v[k] = aux;
			i++;
			k--;
		}
	}while(i <= k);
	if (k-i <=20) //insert
	{
	    //insertSort(v, k-i);
	    insertSortSeguimento(v, i, k);
	}
	if (esq < k)
		particaoInsert(v,esq,k);
	if (i < dir)
		particaoInsert(v,i,dir);
};

void insertSortSeguimento(tipo_item *v, int esq, int dir)
{
	int i,j;
	tipo_item aux;
	for (i = esq+1; i < dir; i++)
	{
		aux = v[i];
		j = i - 1;
		while ( ( j >= esq ) && ( aux.chave < v[j].chave ) )
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = aux;
	}
};