// Autor: Charles Garrocho
// Data: 10/04/2012

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

/* CRIA UM NOVO TIPO DADOS E ADICIONA NO REGISTRO */
Dados CriaDados(int idArquivo)
{
	Dados auxDados;
	auxDados = (Dados)malloc(sizeof(TipoDados));
	auxDados->idArquivo = idArquivo;
	auxDados->qtde = 1;
	auxDados->prox = NULL;
	return auxDados;
}

/* VERIFICA O ID DO ARQUIVO, SE FOR IGUAL INCREMENTA A QUANTIDADE, CASO CONTRARIO CHAMA A FUNCAO CRIADADOS() */
int VerificaDados(Dados *dados, int idArquivo)
{
	if (*dados == NULL)
	{
		*dados = CriaDados(idArquivo);
		return 1;
	}
	else if ((*dados)->idArquivo == idArquivo)
	{
		(*dados)->qtde++;
		return 0;
	}
	return VerificaDados(&(*dados)->prox, idArquivo);
}

/* CRIA UM NOVO REGISTRO ALOCANDO MEMORIA E INICIALIZA OS CAMPOS COM VALORES DEFAULT DE INICIALIZACAO */
Registro CriaRegistro()
{
	Registro auxRegistro;
	auxRegistro = (Registro)malloc(sizeof(TipoRegistro));
	auxRegistro->dados = NULL;
	auxRegistro->qtde = 1;
	return auxRegistro;
}

/* CRIA UM NOVO REGISTRO SEM ALOCAR MEMORIA E INICIALIZA OS CAMPOS COM VALORES DEFAULT DE INICIALIZACAO */
TipoRegistro CriaRegistroSemPonteiro()
{
	TipoRegistro auxRegistro;
	auxRegistro.dados = NULL;
	auxRegistro.qtde = 1;
	return auxRegistro;
}
