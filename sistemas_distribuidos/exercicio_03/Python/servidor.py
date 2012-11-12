# coding: utf-8

import socket
import threading
from multiprocessing import Process, Manager
from time import sleep

HOST = ''
PORTA = 5555
MAX_TAM = 1024

def soma(x, y):
    return '{0}'.format(x + y)
    

def produto(x, y):
    return '{0}'.format(x * y)


def fatorial(lista, inicio, fim):
    teste = range(inicio, fim + 1)
    inicio = 1
    for i in teste:
        inicio *= i
    lista.append(inicio)


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
            manager = Manager()
            lista = manager.list()
            CONTADOR = int(recebido[1])
            medio = CONTADOR / 7
            e = Process(target=fatorial, args=(lista, 1, medio ))
            e.start()
            f = Process(target=fatorial, args=(lista, medio + 1, medio * 2 ))
            f.start()
            g = Process(target=fatorial, args=(lista, medio * 2 + 1, medio * 3))
            g.start()
            h = Process(target=fatorial, args=(lista, medio * 3 + 1, medio * 4))
            h.start()
            i = Process(target=fatorial, args=(lista, medio * 4 + 1, medio * 5))
            i.start()
            j = Process(target=fatorial, args=(lista, medio * 5 + 1, medio * 6))
            j.start()
            l = Process(target=fatorial, args=(lista, medio * 6 + 1, CONTADOR))
            l.start()
            e.join()
            f.join()
            g.join()
            h.join()
            i.join()
            j.join()
            l.join()
            soma = 1
            for i in lista:
                soma *= i
            soma = '{0}'.format(soma)
            tamanho = len(soma)
            qtde = (tamanho / MAX_TAM) + 1
            aux = 0
            for i in range(qtde):
                soquete.sendto(soma[aux:aux+MAX_TAM], dados_cli)
                aux += MAX_TAM
            soquete.sendto('NADA', dados_cli)
        elif recebido[0] == 'DIVISAO':
            soquete.sendto(divisao(int(recebido[1]), int(recebido[2])), dados_cli)
        else:
            soquete.sendto('OPERAÇÃO NÃO PERMITIDA.', dados_cli)

if __name__ == '__main__':
    print 'Iniciou o servidor na porta {0}'.format(PORTA)
    threading.Thread(target=servidor).start()
