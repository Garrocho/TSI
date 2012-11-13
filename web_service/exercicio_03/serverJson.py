# coding: utf-8

import socket
import json

ano = raw_input('Digite o ano da turma: ')
form = { "Ano": ano, "Disciplina": [] }
op = '1'
while op != '3':
	disc = raw_input('Digite o nome da disciplina: ')
	disciplina = { "Nome": disc, "Aluno":[]}
	op = '1';
	while op == '1':
		aluno = raw_input('Digite o nome do aluno: ')
		notas = raw_input('Digite as notas: ')
		notas = notas.split()
		alunos = {"Nome do Aluno": aluno, "Notas": notas}
		disciplina["Aluno"].append(alunos)
		op = raw_input('Digite 1 p/ inserir outro aluno, ou 2 p/ inserir outra disciplina e 3 p/ sair: ')
		if op == '2' or op == '3':
			form["Disciplina"].append(disciplina)

print form
jason = json.dumps(form)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.bind(('', 8888))
sock.listen(1)

while True:
    conn,addr = sock.accept()
    print '...conectado'
    conn.send(jason)
    conn.close()

sock.close()
arq.close()
