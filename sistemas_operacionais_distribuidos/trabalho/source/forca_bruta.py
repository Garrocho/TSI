#!/usr/bin/env python
#coding: utf-8
"""
@descrição: Trabalho prático de sistemas operacionais distribuidos.
"""

import hashlib
import itertools
import string
from sys import exit
from re import findall
from crypt import crypt
from multiprocessing import Manager

manager = Manager()
verifica = manager.list(range(1))
verifica.append(0)


class ForcaBruta:
    """
    Classe responsável por verificar todoas as combinações possíveis da lista de
    senhas da wordList passada, com a senha do computador.
    """

    def __init__(self, combinacao, crpt, salt, cont):
		self.combinacao = combinacao
		self.salt = salt
		self.crpt = crpt
		self.cont = cont

    def run(self):
        print 'Processo {0} criado.'.format(self.cont)
        for senha in self.combinacao:
            if verifica[0] == 0:
                if crypt(senha[:-2], self.salt) == self.crpt:
                    verifica[0] = 1
                    print 'Sucesso\nSenha Encontrada: {0}\nProcesso {1} Encontrou a Senha.'.format(senha, self.cont)
                    exit()
            else:
                 exit()
        print 'Processo {0} Terminado.'.format(self.cont)

def obterUsuarios(shadow):
    """
    Obtêm as linhas com os dados do usuário root do linux do shadow.
    """
    arq = open(shadow).read()
    return findall(u'\n(.*?):\$(.*?)\$(.*?)\$(.*?):', arq)[0]


def reparte(l , tam):
	return [l[i:i+tam] for i in range(0, len(l), tam)]


def carregaWordList(wordList, qtdePartes):
    """
    Carrega o arquivo wordlist e retorna uma lista com o arquivo repartido
    com quantidade de partes passadas como argumento para a função.
    """
    arquivo = open(wordList).readlines()
    return reparte(arquivo, qtdePartes)
