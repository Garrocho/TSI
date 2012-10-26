# coding: utf-8

import socket
import threading

HOST = ''
PORTA = 5555

def soma(x, y):
    return '{0}'.format(x + y)
    

def produto(x, y):
    return '{0}'.format(x * y)
    

def fatorial(x):
    soma = 1
    for i in range(2, x + 1):
        soma *= i
    return '{0}'.format(soma)


def divisao(x, y):
    return '{0}'.format(x / y)


def servidor():
    soquete = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    soquete.bind((HOST, PORTA))

    while True:
        recebido, dados_cli = soquete.recvfrom(1024)
        recebido = recebido.split(' ')
        if recebido[0] == 'SOMA':
            soquete.sendto(soma(int(recebido[1]), int(recebido[2])), dados_cli)
        elif recebido[0] == 'PRODUTO':
            soquete.sendto(produto(int(recebido[1]), int(recebido[2])), dados_cli)
        elif recebido[0] == 'FATORIAL':
            soquete.sendto(fatorial(int(recebido[1])), dados_cli)
        elif recebido[0] == 'DIVISAO':
            soquete.sendto(divisao(int(recebido[1]), int(recebido[2])), dados_cli)
        else:
            soquete.sendto('OPERAÇÃO NÃO PERMITIDA.', dados_cli)

if __name__ == '__main__':
    print 'Iniciou o servidor na porta {0}'.format(PORTA)
    threading.Thread(target=servidor).start()
