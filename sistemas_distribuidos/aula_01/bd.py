# coding: utf-8

import socket
import threading
import sqlite3

PORTA = 5555
CON = sqlite3.connect('teste.db')
CURSOR = CON.cursor()
CURSOR.execute('CREATE TABLE aluno (Nome TEXT, Nota INTEGER, PRIMARY KEY(Nome));')
CURSOR.execute('CREATE TABLE turma (Nome TEXT, Professor TEXT, NomeAluno TEXT, PRIMARY KEY(Nome, NomeAluno), FOREIGN KEY(NomeAluno) REFERENCES aluno(Nome));')
CURSOR.execute("INSERT INTO aluno(Nome, Nota) values ('charles', 40)")
CURSOR.execute("INSERT INTO aluno(Nome, Nota) values ('vinicius', 60)")
CURSOR.execute("INSERT INTO aluno(Nome, Nota) values ('alemao', 60)")
CURSOR.execute("INSERT INTO turma(Nome, Professor, NomeAluno) values ('Portugues', 'Rafael', 'charles')")
CURSOR.execute("INSERT INTO turma(Nome, Professor, NomeAluno) values ('Portugues', 'Rafael', 'vinicius')")
CURSOR.execute("INSERT INTO turma(Nome, Professor, NomeAluno) values ('Portugues', 'Rafael', 'alemao')")

CURSOR.execute('SELECT turma.Nome, turma.Professor, turma.NomeAluno, aluno.Nota FROM turma INNER JOIN aluno ON turma.NomeAluno = aluno.Nome WHERE aluno.Nota >= 60')
RESULTADO = CURSOR.fetchall()
APROVADOS = ''
for x in RESULTADO:
    APROVADOS += '{0}'.format(x)

CURSOR.execute('SELECT turma.Nome, turma.Professor, turma.NomeAluno, aluno.Nota FROM turma INNER JOIN aluno ON turma.NomeAluno = aluno.Nome WHERE aluno.Nota < 60')
RESULTADO = CURSOR.fetchall()
REPROVADOS = ''
for x in RESULTADO:
    REPROVADOS += '{0}'.format(x)

def trataCliente(conexao, endereco):
    print endereco
    requisicao = conexao.recv(1024)
    if requisicao == 'APROVADOS':
        conexao.send(APROVADOS)
    elif requisicao == 'REPROVADOS':
        conexao.send(REPROVADOS)

def servidor():
    soquete = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    soquete.bind(('', PORTA))
    soquete.listen(1)
    
    while True:
		threading.Thread(target=trataCliente, args=(soquete.accept())).start()

if __name__=='__main__':
    print 'Iniciou o servidor na porta {0}'.format(PORTA)
    threading.Thread(target=servidor).start() 
