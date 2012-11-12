#coding: utf-8
import socket
import sys
from threading import Thread

class Operacoes:

	def __init__(self, ip):
		self.ip = ip

	def soma(self, x, y):
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		try:
			sock.sendto('SOMA {0} {1}'.format(int(x),int(y)), (self.ip, 5555))
			dados, dados_cli = sock.recvfrom(1024)
		except:
			dados = 'Valores incorretos e/ou invalidos.'
		sock.close()
		return dados

	def _soma(self, x, y):
		Thread(target=soma, args=(x, y)).start()

	def produto(self, x, y):
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                try:
			sock.sendto('PRODUTO {0} {1}'.format(int(x),int(y)), (self.ip, 5555))
			dados, dados_cli = sock.recvfrom(1024)
		except:
			dados = 'Valores incorretos e/ou invalidos.'
		sock.close()
                return dados

	def _produto(self, x, y):
		Thread(target=produto, args=(x, y)).start()

	def divisao(self, x, y):
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                try:
			sock.sendto('DIVISAO {0} {1}'.format(int(x),int(y)), (self.ip, 5555))
			dados, dados_cli = sock.recvfrom(1024)
		except:
			dados = 'Valores incorretos e/ou invalidos.'
                sock.close()
                return dados

	def _divisao(self, x, y):
		Thread(target=divisao, args=(x, y)).start()

	def fatorial(self, x):
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
				
		try:
			x = int(x)
			if x >= 0:
				sock.sendto('FATORIAL {0}'.format(int(x)), (self.ip, 5555))
				dados, dados_cli = sock.recvfrom(1024)
				while True:
					total, dados_cli = sock.recvfrom(1024)
					#print total
					if total == 'NADA':
						break
					dados += total
			else:
				raise Exception
		except:
			dados = 'Valores incorretos e/ou invalidos.'
                sock.close()
                return dados

	def _fatorial(self, x, y):
		Thread(target=fatorial, args=(x, y)).start()

op = Operacoes('10.3.1.37')
print op.fatorial(300000)
