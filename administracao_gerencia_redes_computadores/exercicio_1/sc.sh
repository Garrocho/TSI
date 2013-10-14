#!/bin/bash

while read linha 
do  
   nome_usuario=`echo $linha | cut -d ':' -f 1`
   nome_completo=`echo $linha | cut -d ':' -f 2`
   descricao=`echo $linha | cut -d ':' -f 3`
   matricula=`echo $linha | cut -d ':' -f 4`
   senha=`echo $linha | cut -d ':' -f 5`
   dir_pai=`echo $nome_usuario | cut -b 1`
   senha=`perl -e 'print crypt('$senha',q($5$salt$)), "\n";'`
   sudo mkdir -p /home/$dir_pai
   sudo useradd -m -s /bin/bash -k /etc/skel -c $descricao $nome_usuario -p $senha -d /home/$dir_pai/$nome_usuario
done < user_pass.txt
