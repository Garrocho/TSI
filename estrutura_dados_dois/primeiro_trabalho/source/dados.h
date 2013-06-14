// Autor: Charles Garrocho
// Data: 10/04/2012

#ifndef DADOS_H
#define DADOS_H

#define TAMANHO_TABELA 7057
#define TAMANHO_PALAVRA 30
#define N 10  // Defina aqui os primeiros caracteres

typedef char TipoPalavra[TAMANHO_PALAVRA];

typedef struct dado
{
	int idArquivo;
	int qtde;
	struct dado *prox;
}TipoDados;

typedef TipoDados *Dados;

typedef struct
{
  TipoPalavra palavra;
  Dados dados;
  int qtde;
}TipoRegistro;

typedef TipoRegistro *Registro;

/* CRIA UM NOVO TIPO DADOS E ADICIONA NO REGISTRO */
Dados CriaDados(int idArquivo);

/* VERIFICA O ID DO ARQUIVO, SE FOR IGUAL INCREMENTA A QUANTIDADE, CASO CONTRARIO CHAMA A FUNCAO CRIADADOS() */
int VerificaDados(Dados *dados, int idArquivo);

/* CRIA UM NOVO REGISTRO ALOCANDO MEMORIA E INICIALIZA OS CAMPOS COM VALORES DEFAULT DE INICIALIZACAO */
Registro CriaRegistro();

/* CRIA UM NOVO REGISTRO SEM ALOCAR MEMORIA E INICIALIZA OS CAMPOS COM VALORES DEFAULT DE INICIALIZACAO */
TipoRegistro CriaRegistroSemPonteiro();

#endif /* DADOS_H */
