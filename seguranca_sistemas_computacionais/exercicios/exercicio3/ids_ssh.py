import re
import sys
import os

MAXIMO_CONEXOES = 10
IP_SERVIDOR = '10.0.0.20'
arq = open("/var/log/auth.log").read()
filtro = re.findall(r'([a-z:A-Z]{3}).([0-9]{2}).([0-9]{2})\:([0-9]{2})\:([0-9]{2}).+ ([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}) port ([0-9]+)', arq)

lista_ips = []
frequencia = []
meses = {'Jan':1, 'Feb':2, 'Mar':3, 'Apr':4, 'May':5, 'Jun':6, 'Jul':7, 'Agu':8, 'Sep':9, 'Oct':10, 'Nov':11, 'Dec':12}
indice = 0
dados_ip = {}
dia = 0
for linha in filtro:
    if(linha[5] != '127.0.0.1' and linha[5] != IP_SERVIDOR and linha[5] != '0.0.0.0'):
        dia = linha[1]
        if(lista_ips.__contains__(linha[5])):
            indice = lista_ips.index(linha[5])
            frequencia[indice] = frequencia[indice] + 1
            if (dados_ip[linha[5]].__contains__(dia)):
                dados_ip[linha[5]][dia] = dados_ip[linha[5]][dia] + 1
            else:
                dados_ip[linha[5]][dia] = 0
            if(frequencia[indice] >= MAXIMO_CONEXOES and dados_ip[linha[5]][dia] >= 10):
                print("Ataque de DDoS detectado. IP: ", lista_ips[indice])
                op = raw_input("Deseja bloquear este IP? S/N: ")
                if(op == 'S' or op == "s"):
                    os.system("clear")
                    os.system("/sbin/iptables -A INPUT -s "+ lista_ips[indice] +" -j DROP")
                    os.system("/sbin/iptables -A OUTPUT -d "+ lista_ips[indice] +" -j DROP")
                    print("IP: ", lista_ips[indice], " bloqueado.")
                quit()
        else:
            lista_ips.append(linha[5])
            frequencia.append(1)
            dados_ip = {linha[5]:{dia:0}}
# para desbloquear o ip 
# /sbin/iptables -D INPUT -s <ip> -j DROP
# /sbin/iptables -D OUTPUT -d <ip> -j DROP
