# coding: utf-8

import socket
import threading
from sys import argv
from re import findall
from multiprocessing import Process


TIME_OUT = 0.1 # Tempo limite de resposta do host.
MAX_THREADS = 300 # Maximo de threads que poderam ser criadas.


def pesquisaPorta(porta):
	arquivo = open('/etc/services').readlines()
	for linha in arquivo:
		if findall('\W\s{0}/tcp'.format(porta), linha):
			print linha[:linha.index('\n')]


class Scan(threading.Thread):
    
	def __init__(self, host):
		threading.Thread.__init__(self)
		self.host = host
		self.portas = []
		
	def adicionaPorta(self, porta):
		self.portas.append(porta)

	def run(self):
		while self.portas:
			porta = self.portas.pop()
			soquete = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			soquete.settimeout(TIME_OUT)
			resposta = soquete.connect_ex((self.host, porta))
			soquete.close()
			if resposta == 0:
				pesquisaPorta(porta)


def executar(scanner):
	threading.Thread(target=scanner.run()).start()


def portaScanner(host, portaInicio, portaFim):
	print 'HOST: {0}\nPORTAS TCP: {1} a {2}\n\nPORTAS ABERTAS:'.format(host, portaInicio, 65535)
	portas = range(int(portaInicio), int(portaFim) + 1)
	porcentagem = (float(len(portas)) / MAX_THREADS)
	scanners = []
	while portas:		
		auxPor = 0
		scanner = Scan(host)
		while auxPor < porcentagem and portas:
			auxPor += 1
			scanner.adicionaPorta(int(portas.pop()))
		scanners.append(scanner)
		
	scanners.reverse()
	for i in range(len(scanners)):
		node = Process(target=executar, args=(scanners[i],))
                node.start()


if __name__ == '__main__':
	
	if len(argv) == 4:
		try:
			portaInicio = int(argv[2])
			portaFim = int(argv[3])
			if portaFim > 65535 or portaInicio > portaFim :
				print 'Portas Invalidas.\nUse: python Exercicio_5_1.py <dominio ou ip> <porta_inicio> <porta_fim>'
			else:
				portaScanner( argv[1], portaInicio, portaFim )
		except:
			print 'Você deve fornecer numeros inteiros para as portas.\nUse: python Exercicio_5_1.py <dominio ou ip> <porta_inicio> <porta_fim>'
	elif len(argv) == 2:
		portaScanner( argv[1], 1, 445)
	else:
		print 'Erro de entrada.\nUse: python Exercicio_5_1.py <dominio ou ip> <porta_inicio> <porta_fim>'
