# coding: utf-8

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(('localhost', 8888))

s.listen(1)
print 'Aguardando conexão...'

con, info_cli = s.accept()
print 'Conexão estabelecida por'

dados = con.recv(1024)
print 'Mensagem recebida: ', dados

con.send(dados.upper())

con.close()

