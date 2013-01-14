#coding: utf-8
import re

POS_RES = 20

def gera_bin(msg):
    return ''.join(bin(ord(caractere))[2:].zfill(8) for caractere in msg)

def recupera_str(str_bin):
    return ''.join(chr(int(bin, 2)) for bin in re.findall(r'.{8}', str_bin))

def cript(end_ori, end_dest, msg):

    msg_bin = gera_bin(msg)

    # as primeiras linhas definem o tamanho da informação a ser ocultada
    bits_tam = bin(len(msg_bin))[2:].zfill(POS_RES)
    msg_bin = bits_tam + msg_bin

    arq_ori = open(end_ori).read()
    lis_ori = arq_ori.split('\n')

    arq_final = open(end_dest, 'w')
    cont = 0
    
    for linha in lis_ori:
        if cont < POS_RES:
            binario = msg_bin[cont]
            if binario == '1':
                linha += '\r\n'
            else:
                linha += '\n'
            cont += 1
            arq_final.write(linha)
        elif cont < len(msg_bin):
            binario = msg_bin[cont]
            if binario == '1':
                linha += '\r\n'
            else:
                linha += '\n'
            cont += 1
            arq_final.write(linha)
        else:
            arq_final.write(linha + '\n')
    
    arq_final.close()
    arq_final = open(end_dest).readlines()
    arq_final[-1] = arq_final[-1][0:-2]
    arq = open(end_dest, 'w')
    arq.write(''.join(arq_final))
    arq.close()


def recupera(end_arq):
    arq_final = open(end_arq).readlines()
    cont = 0
    tam = ''

    for linha in arq_final:
        print cont
        if cont < POS_RES:
            cont += 1
            if linha.endswith('\r\n'):
                tam += '1'
            else:
                tam += '0'
        else:
            break

    print tam
    #tam = recupera_str(tam)
    tam = int(tam, 2)

    msg_final = ''
    for i in range(tam):
        tipo = arq_final[POS_RES + i]
        if tipo.endswith('\r\n'):
            msg_final += '1'
        else:
            msg_final += '0'

    return recupera_str(msg_final)


if __name__ == '__main__':
    cript('lusiadas.txt', 'teste_final.txt', 'Qualquer Coisa ' * 10)
    print recupera('teste_final.txt')
