#ifndef ARVORE_B_H
#define ARVORE_B_H

#include "dados.h"
#define m 2
#define mm 4

typedef struct Pagina_str *Apontador;

typedef struct Pagina_str
{
  int n;
  TipoRegistro r[mm];
  Apontador p[mm + 1];
}Pagina;

typedef Apontador TipoDicionario;

/* INICIALIZA A ARVORE COM NULL */
void Inicializa(TipoDicionario *Dicionario);

/* INSERE UM NOVO REGISTRO EM UM DETERMINADA PAGINA */
void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir, int idArquivo);

/* INSERE UM NOVO REGISTRO VERIFICANDO AS PALAVRAS, CASO EXISTA A QUANTIDADE E INCREMENTADA, CASO CONTRARIA A FUNCAO INSERENAPAGINA() E CHAMADA 
    E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double Ins(Registro Reg, Apontador Ap, int *Cresceu, Registro RegRetorno, Apontador *ApRetorno, int idArquivo);

/* CRIA E INICIALIZA VARIAVEIS PARA A VERIFICACAO SE A ARVORE CRESCE E RETORNA A QUANTIDADE DE MEMORIA GASTA  E RETORNA A QUANTIDADE DE MEMORIA GASTA */
double Insere(TipoRegistro Reg, Apontador *Ap, int idArquivo);

/* IMPRIME TODAS AS PALAVRAS E OS DADOS DAS MESMAS NO TERMINAL DO SO */
void Imprime(Apontador p, int nivel);

/* GERA UM ARQUIVO INVERTIDO CONTENDO TODOS OS ARQUIVOS E OS SEUS RESPECTIVOS DADOS */
void CriaArquivoInvertidoB(Apontador auxArvore, FILE *arquivoInvertido, int nivel);

#endif /* ARVORE_B_H */