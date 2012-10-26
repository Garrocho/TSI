import socket
import sys

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

	def produto(self, x, y):
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                try:
			sock.sendto('PRODUTO {0} {1}'.format(int(x),int(y)), (self.ip, 5555))
			dados, dados_cli = sock.recvfrom(1024)
		except:
			dados = 'Valores incorretos e/ou invalidos.'
		sock.close()
                return dados

	def divisao(self, x, y):
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                try:
			sock.sendto('DIVISAO {0} {1}'.format(int(x),int(y)), (self.ip, 5555))
			dados, dados_cli = sock.recvfrom(1024)
		except:
			dados = 'Valores incorretos e/ou invalidos.'
                sock.close()
                return dados

	def fatorial(self, x):
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
				
		try:
			x = int(x)
			if x >= 0:
				sock.sendto('FATORIAL {0}'.format(int(x)), (self.ip, 5555))
				dados, dados_cli = sock.recvfrom(1024)
			else:
				raise Exception
		except:
			dados = 'Valores incorretos e/ou invalidos.'
                sock.close()
                return dados

