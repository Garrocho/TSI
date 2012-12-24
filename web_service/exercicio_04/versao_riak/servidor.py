# coding: utf-8
# Autor: Charles Tim Batista Garrocho

from re import findall
from threading import Thread
from json import loads
import settings
import socket
import urllib
import urllib2
import riak

client = riak.RiakClient()
bucket = client.bucket('teste')

def trata_cliente(conexao, endereco):
    print 'Conexão Estabelecida\nEndereço: {0}'.format(endereco)
    cep = conexao.recv(settings.BUFFER)
    
    teste = bucket.get(cep)
    if teste is not None:
        conexao.send(teste)
        conexao.close()
        
    else:
        url = settings.URL_CORREIOS
        p = {'cepEntrada': cep, 'tipoCep': '', 'cepTemp': '', 'metodo': 'buscarCep'}
        post = urllib.urlencode(p)
        req = urllib2.Request(url, post)
        con = urllib2.urlopen(req)
        html = con.read()
        
        resp = findall(r'<span class="respostadestaque">(.*)</.', html)
        resp += findall(r'<span class="respostadestaque">\n(.*)', html)
        try:
            cep = resp[1].strip()
            rua = resp[2].strip()
            bairro = resp[0].strip()
            municipio = resp[3].strip()
            dados = '{\"cep\": \"' + cep + '\",' + '\"rua\": ' + '\"' + rua + '\",' + '\"bairro\": ' + '\"' + bairro + '\",' + '\"municipio\": ' + '\"' + municipio + '\"}'
        except:
            dados = '{\"cep\": \"' + cep + '\",' + '\"rua\": ' + '\"Não Encontrado\",' + '\"bairro\": ' + '\"Não Encontrado\",' + '\"municipio\": \"Não Encontrado\"}'
        
        dados = dados.decode('iso-8859-1').encode('utf-8')
        conexao.send(dados)
        conexao.close()
        
        person = bucket.new(cep, data=dados)
        person.store()


def inicia_servidor():
    soquete = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    soquete.bind((settings.HOST, settings.PORT))
    soquete.listen(settings.LISTEN)

    print 'Servidor Iniciado na Porta: {0}'.format(settings.PORT)

    while True:
        Thread(target=trata_cliente, args=(soquete.accept())).start()		


if __name__ == '__main__':
    Thread(target=inicia_servidor).start()
