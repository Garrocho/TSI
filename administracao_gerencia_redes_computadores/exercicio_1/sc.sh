#!/bin/bash

while read linha 
do  
   nome_usuario=`echo $linha | cut -d ':' -f 1`
   nome_completo=`echo $linha | cut -d ':' -f 2`
   descricao=`echo $linha | cut -d ':' -f 3`
   matricula=`echo $linha | cut -d ':' -f 4`
   senha=`echo $linha | cut -d ':' -f 5`
   dir_pai=`echo $nome_usuario | cut -b 1`

done < user_pass.txt
