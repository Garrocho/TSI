/* Arquivo: funcoes.h
 * Descrição: Este Arquivo Define as funcoes utilizadas para ordenacao dos arquivos.
 * Autor: Charles Tim Batista Garrocho
 * Data: 08/06/2012
 */
 
#ifndef FUNCOES_H
#define FUNCOES_H

#define TAM_PALAVRA 100 // Tamanho Maximo de Uma Palavra.
#define TAM_LINHA 10000 // Tamanho Maximo de Uma Linha.
#define TAM_BUFFER 200 // Tamanho Maximo de Elementos.

// Conta quantos arquivos tem no diretorio "Arquivos/".
int qtdeArquivos();

// Transforma a letra em minuscula.
int paraMinuscula(int letra);

#endif /* FUNCOES_H */
