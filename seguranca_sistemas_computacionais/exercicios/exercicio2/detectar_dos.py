import re
import sys
import os

MAXIMO_CONEXOES = 200
IP_SERVIDOR = '10.10.10.200'
arq = open("/var/log/apache2/access.log").read()

filtro = re.findall('[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}', arq)
lista_ips = []
frequencia = []
indice = 0
for linha in filtro:
	if(linha != '127.0.0.1' and linha != IP_SERVIDOR):
		if(lista_ips.__contains__(linha)):
			indice = lista_ips.index(linha)
			frequencia[indice] = frequencia[indice] + 1
			if(frequencia[indice] >= MAXIMO_CONEXOES):
				print("Ataque de Dos detectado. IP: ", lista_ips[indice])
				op = raw_input("Deseja bloquear este IP? S/N: ")
				if(op == 'S' or op == "s"):
					os.system("clear")
					os.system("/sbin/iptables -A INPUT -s "+ lista_ips[indice] +" -j DROP")
					os.system("/sbin/iptables -A OUTPUT -d "+ lista_ips[indice] +" -j DROP")
					print("IP: ", lista_ips[indice], " bloqueado.")
				quit()
		else:
			lista_ips.append(linha)
			frequencia.append(1)
# para desbloquear o ip 
# /sbin/iptables -D INPUT -s <ip> -j DROP
# /sbin/iptables -D OUTPUT -d <ip> -j DROP
