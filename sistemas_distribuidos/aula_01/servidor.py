# coding: utf-8

import socket
import threading
import re

PORTA = 8888
RESP = 'HTTP/1.0 200 OK\
Content-Type : text/HTML\
'
NOT_FOUND = 'HTTP/1.0 404 NOT FOUND\r\n\r\n<html><h1>404 NOT FOUND</h1></html'

def trataCliente(conexao, endereco):
    requisicao = conexao.recv(1024)
    requisicao = re.findall('GET(.*?)HTTP/1.1', requisicao)[0].strip()
    if requisicao == '/aprovados' or requisicao == '/reprovados':
        soquete = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        soquete.connect(('10.3.1.35', 5555))
        if requisicao == '/aprovados':
            soquete.send('APROVADOS')
        elif requisicao == '/reprovados':
            soquete.send('REPROVADOS')
        aluno = soquete.recv(1024)
        alunos = re.findall(r"u'([a-zA-Z]+)', u'([a-zA-Z]+)', u'([a-zA-Z]+)',.*?(\d+)", aluno)
        resultado = ''
        for x in alunos:
	    resultado += '\n<tr>\
	    <td>{0}</td>\
	    <td>{1}</td>\
	    <td>{2}</td>\
	    <td>{3}</td>\
	    </tr>'.format(x[0], x[1], x[2], x[3])
	
        HTML = '<!doctype html />\
    <html>\
        <head>\
            <meta charset = "utf-8">\
            <title id="doctitle">teste</title>\
            <body>\
		    <table border=1 width="100%" heigth="100%">\
		    <tr>\
			    <td>Turma</td>\
			    <td>Professor</td>\
			    <td>Nome</td>\
			    <td>Nota</td>\
		    </tr>\
		     {0}\
		    </table>\
	    </body>\
        </head>\
    </html>'.format(resultado)
        soquete.close()
        conexao.send('{0}\r\n\r\n{1}'.format(RESP, HTML))
    else:
        conexao.send(NOT_FOUND)

def servidor():
    soquete = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    soquete.bind(('', PORTA))
    
    soquete.listen(1)
    while True:
        threading.Thread(target=trataCliente, args=(soquete.accept())).start()

if __name__=='__main__':
    print 'Iniciou o servidor na porta {0}'.format(PORTA)
    threading.Thread(target=servidor).start() 
