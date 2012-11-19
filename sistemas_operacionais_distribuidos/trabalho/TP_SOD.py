#coding: utf-8
"""
@author: Charles Garrocho
@author: Vinicius Lehman
@descrição: Trabalho prático de sistemas operacionais distribuidos.
"""

import hashlib
import itertools
import string
import re
import crypt
from multiprocessing import Process
from threading import Thread
from sys import exit

PRINTABLE = string.printable
ALFABETO = PRINTABLE[0:84]
NUMEROS = PRINTABLE[0:10]
LETRAS = PRINTABLE[10:62]
LET_NUM = PRINTABLE[0:5] + PRINTABLE[10:15]

class ForcaBruta:
    """
    Classe responsável por verificar todoas as combinações possíveis passadas com a senha do computador.
    """

    def __init__(self, combinacao, crpt, salt):
		self.combinacao = combinacao
		self.salt = salt
		self.crpt = crpt

    def run(self):
        for senha in self.combinacao:
            print senha
            if crypt.crypt(''.join(senha), self.salt) == self.crpt:
                print 'Senha: {0}'.format(''.join(senha))
                exit()

def obterUsuarios():
	"""
	Obtem as linhas com os dados dos usuarios do arquivo /etc/shadow
	"""
	arq = open('/etc/shadow').read()
	return re.findall(u'\n(.*?):\$(.*?)\$(.*?)\$(.*?):', arq)
	
def geraCombinacoes(caracteres, tamanhoMaximo):
	"""Gera combinações de acordo com os caracteres e com o tamanho máximo fornecidos."""
	return itertools.product(caracteres, repeat = tamanhoMaximo)
 
def descobreSenha():
	"""
	Função responsável por criar as combinações e criar várias Threads para tratarem as classes ForcaBruta criadas.
	"""
	
	senhas = []
	salt = obterUsuarios()[0]
	crpt = '${0}${1}${2}'.format(salt[1], salt[2], salt[3])
	salt = '${0}${1}$'.format(salt[1], salt[2])
	print salt
	print crpt
	
	senhas.append(ForcaBruta(geraCombinacoes(NUMEROS, 6), crpt, salt))
	#senhas.append(ForcaBruta(geraCombinacoes(NUMEROS, 7), crpt, salt))
	#senhas.append(ForcaBruta(geraCombinacoes(LET_NUM, 6), crpt, salt))
	#senhas.append(ForcaBruta(geraCombinacoes(LET_NUM, 7), crpt, salt))
	#senhas.append(ForcaBruta(geraCombinacoes(LETRAS, 6), crpt, salt))
	#senhas.append(ForcaBruta(geraCombinacoes(LETRAS, 7), crpt, salt))
	#senhas.append(ForcaBruta(geraCombinacoes(ALFABETO, 6), crpt, salt))
	#senhas.append(ForcaBruta(geraCombinacoes(ALFABETO, 7), crpt, salt))
	
	for forca in senhas:
	    Process(target=forca.run())

if __name__ == '__main__':
    Thread(target = descobreSenha).start()
