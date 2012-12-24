#coding: utf-8

import sys
import settings
import forca_bruta
from multiprocessing import Process
from threading import Thread


def descobreSenha(qtdePartes):
    """
    Função responsável por criar vários processos para tratarem as classes ForcaBrutas criadas.
    """
    erros = []
    try:
        shadowRoot = forca_bruta.obterUsuarios(settings.SHADOW)
        crpt = '${0}${1}${2}'.format(shadowRoot[1], shadowRoot[2], shadowRoot[3])
        salt = '${0}${1}$'.format(shadowRoot[1], shadowRoot[2])
        print '{0} carregado com sucesso.'.format(settings.SHADOW)
    except:
        erros.append('Arquivo não encontrado: {0}'.format(settings.SHADOW))

    listas = []
    try:
        listas = forca_bruta.carregaWordList(settings.WORD_LIST, qtdePartes)
        print '{0} carregado com sucesso.'.format(settings.WORD_LIST)
    except:
        erros.append('Arquivo não encontrado: {0}'.format(settings.WORD_LIST))

    print len(listas)
    if len(erros) > 0:
        print 'Erros ao descobrir a senha...'
        for erro in erros:
            print erro
    else:
        cont = 0
        processos = []
        for lista in listas:
            cont += 1
            forca = forca_bruta.ForcaBruta(lista, crpt, salt, cont)
            Process(target=forca.run()).start()
        print 'Falha\nNão Foi Possível Encontrar a Senha...'


if __name__ == '__main__':
    if len(sys.argv) == 2:
        erro = False
        try:
            qtdePartes = int(sys.argv[1])
        except:
            erro = True
            print 'Arqumentos Inválidos.\nFormato: descobre_senha <Inteiro com a Quantidade de Partes da WordList>'
        if erro == False:
            descobreSenha(qtdePartes)
    else:
        print 'Arqumentos Inválidos.\nFormato: descobre_senha <Quantidade de Partes da WordList>'
