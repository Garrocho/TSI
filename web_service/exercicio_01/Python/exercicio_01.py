#coding: utf-8
import requests
from sys import argv
import json

def requisicao(nome):
    r = requests.get('https://api.github.com/users/' + nome)
    if 200 == r.status_code:
        s = r.content
        s = json.loads(s)
        nome = 'Não Definido'
        email = 'Não Definido'
        seguidores = 'Não Definido'
        if 'name' in s:
            nome = s['name']
        if 'email' in s:
            email = s['email']
        if 'email' in s:
            seguidores = s['following']
        print 'Nome: {0}\nE-mail: {1}\nSeguidores: {2}'.format(nome, email, seguidores)
    else:
        print 'Usuário inexistente'

if __name__ == '__main__':

    if len(argv) == 2:
    	requisicao(argv[1])
    else:
        print 'Parâmetros: python exercicio_01.py nome_usuario'
