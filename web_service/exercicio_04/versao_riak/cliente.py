#coding: utf-8
import socket
import settings
from json import loads
from sys import argv

def inicia_cliente(cep):
    soquete = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    soquete.connect((settings.HOST, settings.PORT))
    
    print 'Cliente Conectou ao HOST {0} na PORT {1}'.format(settings.HOST, settings.PORT)
    soquete.send(cep)
    
    dados = soquete.recv(settings.BUFFER)
    dados = loads(dados)
    soquete.close()
    print 'CEP: ' + dados['cep'] + '\nRua: ' + dados['rua'] + '\nBairro: ' + dados['bairro'] + '\nMunicipio: ' + dados['municipio']
    
if __name__ == '__main__':
    inicia_cliente(argv[1])
