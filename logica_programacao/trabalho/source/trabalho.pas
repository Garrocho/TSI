program trabalho;

uses crt;
type tregdep = record
				codigo:integer;
				nome:string[10];
				codigogerente:integer;
				ramal:string;
			   end;
	tregfunc = record
				salario:real;
				matricula:integer;
				nome:string[25];
				codigodepartamento:integer;
				datacontratacao:string;
				datanascimento:string;
				cpf:string;
				rua:string;
				bairro:string;
				numero:integer;
				complemento:string;
				cidade:string;
				estado:string;
				telefone:integer;
				email:string;
			   end;
	treghistsal = record
					matricula:integer;
					salario:real;
					mes,ano:word;
				  end;
	treghistdep = record
					codigodepartamento:integer;
					codigogerente:integer;
					data:string;
				  end;
	treghistfunc = record
					matriculafuncionario:integer;
					codigodepartamento:integer;
					data:string;
				  end;
	tarqdep = file of tregdep;
	tarqfunc = file of tregfunc;
	tarqhistsal = file of treghistsal;
	tarqhistdep = file of treghistdep;
	tarqhistfunc = file of treghistfunc;
var arqdep:tarqdep;
	arqfunc:tarqfunc;
	arqhistsal:tarqhistsal;
	arqhistdep:tarqhistdep;
	arqhistfunc:tarqhistfunc;
	op,opc,opd,ope:char;

//BORDA
procedure borda;
var i:integer;
begin
     for i:=2 to 63 do
     begin
          gotoxy(i,2);
          write('-');
     end;
     for i:=2 to 63 do
     begin
          gotoxy(i,21);
          write('-');
     end;
end;

//FUNCAO VALIDA CPF
function validacpf(cpf:string):boolean;
var cp,aux:string ;
    vet:array[1..11] of integer;
    Soma1,Soma2,d1,d2,i,convaux:integer; 
Begin
	    cp:=cpf;
        for i:=1 to 11 do
        begin
                aux:=cp[i];
                val(aux,convaux);
                vet[i]:=convaux;
        end;  
        Soma1:= (Vet[1]*10)+(Vet[2]*9)+(vet[3]*8)+(vet[4]*7)+(vet[5]*6)+(vet[6]*5)+(vet[7]*4)+(vet[8]*3)+(vet[9]*2);
        d1:= 11 -( soma1 mod 11);
        If (d1 = 10) or (d1=11) then
                D1:=0;
        Soma2:= (Vet[1]*11)+(Vet[2]*10)+(vet[3]*9)+(vet[4]*8)+(vet[5]*7)+(vet[6]*6)+(vet[7]*5)+(vet[8]*4)+(vet[9]*3)+(D1*2);    
        d2:= 11- (Soma2 mod 11);
        if (d2=10) or (d2=11) then
        d2:=0;
        
        If (Vet[10] =D1) and (Vet[11] = D2) Then
           validacpf:=true
        Else
        validacpf:=false;
end;

//VERIFICACAO DE DATA
function verificadata(dia:integer;mes:integer;ano:integer):boolean;
begin
	if (mes > 12) or (ano<1000) or (ano>3000) or (dia >31) or (dia<=0) or (mes<=0) then
					begin
						verificadata:=false;
					end
					else
					if (mes=4) or (mes=6) or (mes=9) or (mes=11)  then
					begin
						if dia > 30 then
						begin
							verificadata:=false;
						end
                        else
                        begin
							verificadata:=true;
                        end;
					end
					else
					if (mes=1) or (mes=3) or (mes=5) or (mes=7) or (mes=8) or (mes=10) or (mes=12) then
					begin
						if dia > 31 then
						begin
							verificadata:=false;
						end
						else
						begin
							verificadata:=true;
						end;
					end
					else
					if mes=2 then
					begin
						if dia > 29 then
						begin
							verificadata:=false;
						end
						else
						if ((ano mod 4)=0) and ((ano mod 100)<>0) or ((ano mod 400)=0) then
						begin
							if mes=2 then
							begin
								if dia <= 29 then
								begin
									verificadata:=true;
								end
                                else
                                begin
                                    verificadata:=false;
                                end;
							end;
						end
						else
						begin
							if mes=2 then
							begin
								if dia > 29 then
								begin
									verificadata:=false;
								end;
							end
							else
							begin
								verificadata:=true;
							end;
						end;
					end
					else
					begin
						verificadata:=true;
					end;
end;

//PESQUISA DEPARTAMENTO
function pesquisadep (var ad:tarqdep; cod:integer):integer;
var r:tregdep;
	posicao:integer;
	achou:boolean;
begin
	seek(ad,0);
	posicao:=0;
	achou:=false;
	while (eof(ad)=false) and (achou=false) do
	begin
		read(ad,r);
		if r.codigo=cod then
			achou:=true
		else
			posicao:=posicao+1;
	end;
	if achou=true then
		pesquisadep:=posicao
	else
		pesquisadep:=-1;
end;

//PESQUISA HISTORICO SALARIO
function pesquisahistoricosalario (var hs:tarqhistsal; matricula,mes,ano:integer):integer;
var r:treghistsal;
	posicao:integer;
	achou:boolean;
begin
	seek(hs,0);

	posicao:=0;
	achou:=false;
	while (eof(hs)=false) and (achou=false) do
	begin
		read(hs,r);
		if (r.matricula=matricula) and (r.mes>=mes) and (r.ano=ano) then
			achou:=true
		else
			posicao:=posicao+1;
	end;
	if achou=true then
		pesquisahistoricosalario:=posicao
	else
		pesquisahistoricosalario:=-1;
end;

//PESQUISA FUNCIONARIO
function pesquisafunc (var af:tarqfunc; cod:integer):integer;
var r:tregfunc;
	posicao:integer;
	achou:boolean;
begin
	seek(af,0);
	posicao:=0;
	achou:=false;
	while (eof(af)=false) and (achou=false) do
	begin
		read(af,r);
		if r.codigodepartamento=cod then
			achou:=true
		else
			posicao:=posicao+1;
	end;
	if achou=true then
		pesquisafunc:=posicao
	else
		pesquisafunc:=-1;
end;


//CADASTRO DEPARTAMENTO
procedure cadastrodepartamento(var ad:tarqdep);
var r:tregdep;
	sair:char;
begin
	repeat
		clrscr;
        borda;
        gotoxy(2,1);
        write('CADASTRO DE DEPARTAMENTO');
        gotoxy(30,2);
        gotoxy(2,3);
        write('CODIGO: ');
        gotoxy(2,4);
        write('NOME: ');
        gotoxy(2,5);
        write('RAMAL: ');
        gotoxy(10,3);
        readln(r.codigo);
        if pesquisadep(arqdep,r.codigo) <> -1 then
		begin
            gotoxy(2,22);
       		writeln('CODIGO REPETIDO!');
            gotoxy(2,23);
            writeln('DESEJA SAIR? S/N: ');
            gotoxy(19,23);
            sair:=readkey;
            sair:=upcase(sair);
		end
		else
		begin
            gotoxy(8,4);
            readln(r.nome);
            gotoxy(9,5);
            readln(r.ramal);
            seek(ad,filesize(ad));
            write(ad,r);
            gotoxy(2,22);
       		writeln('CADASTRO EFETUADO');
            gotoxy(2,23);
            writeln('DESEJA SAIR? S/N: ');
            gotoxy(19,23);
            sair:=readkey;
            sair:=upcase(sair);
        end;
	until sair='S';
end;

//CADASTRO FUNCIONARIO
procedure cadastrofuncionario(var af:tarqfunc;var ad:tarqdep;var ah:tarqhistsal);
var r:tregfunc;
	rh:treghistsal;
	sair:char;
	status:integer;
	aux:string[4];
	d,m,a:integer;
begin
	repeat
		clrscr;
        borda;
        gotoxy(2,1);
        write('CADASTRO DE FUNCIONARIOS');
        gotoxy(2,3);
		write('CODIGO DEPARTAMENTO: ');
        gotoxy(2,4);
        write('MATRICULA: ');
        gotoxy(2,5);
        write('NOME: ');
        gotoxy(2,6);
        write('SALARIO: ');
        gotoxy(2,7);
        write('DATA CONTRATACAO: ');
        gotoxy(2,8);
        write('DATA NASCIMENTO: ');
        gotoxy(2,9);
        write('RUA: ');
        gotoxy(2,10);
        write('NUMERO: ');
        gotoxy(2,11);
        write('COMPLEMENTO: ');
        gotoxy(2,12);
        write('BAIRRO: ');
        gotoxy(2,13);
        write('CIDADE: ');
        gotoxy(2,14);
        write('ESTADO: ');
        gotoxy(2,15);
        write('TELEFONE: ');
        gotoxy(2,16);
        write('E-MAIL: ');
        gotoxy(2,17);
        write('CPF: ');
        gotoxy(23,3);
		readln(r.codigodepartamento);
		if pesquisadep(ad,r.codigodepartamento)=-1 then
		begin
            gotoxy(2,22);
       		writeln('DEPARTAMENTO INEXISTENTE');
		end
		else
		begin
			gotoxy(13,4);
			readln(r.matricula);
			if pesquisafunc(af,r.matricula) <> -1 then
			begin
                 gotoxy(2,22);
                 write('MATRICULA REPETIDA');
			end
            else
            begin
                 gotoxy(8,5);
                 readln(r.nome);
				 if (r.nome = '') or (r.nome = ' ') or (r.nome = '   ') or (r.nome = '    ') or (r.nome = '    ') or (r.nome = '     ') or (r.nome = '      ')   then
				 begin
                    gotoxy(2,22);
                    writeln('NOME INVALIDO');
                 end
                 else
                 begin
                     gotoxy(11,6);
			         readln(r.salario);
					 if r.salario <= 0 then
					 begin
                        gotoxy(2,22);
						writeln('SALARIO INVALIDO');
					 end
					 else
					 begin
                        gotoxy(20,7);
						readln(r.datacontratacao);
						aux:=copy(r.datacontratacao,1,2);
						val(aux,d,status);
						if status <> 0 then
						begin
                            gotoxy(2,22);
							writeln('DIA INVALIDO');
						end
						else
						begin
							aux:=copy(r.datacontratacao,4,2);
							val(aux,m,status);
							if status <> 0 then
							begin
                                gotoxy(2,22);
								writeln('MES INVALIDO');
							end
							else
							begin
								aux:=copy(r.datacontratacao,7,4);
								val(aux,a,status);
								if status <> 0 then
								begin
                                    gotoxy(2,22);
									writeln('ANO INVALIDO');
								end
								else
								if (verificadata(d,m,a)=false) then
								begin
                                    gotoxy(2,22);
									writeln('DATA INVALIDA');
								end
								else
								begin		
									gotoxy(19,8);
									readln(r.datanascimento);
									aux:=copy(r.datanascimento,1,2);
									val(aux,d,status);
									if status <> 0 then
									begin
                                        gotoxy(2,22);
										writeln('DIA INVALIDO');
									end
									else
									begin
										aux:=copy(r.datanascimento,4,2);
										val(aux,m,status);
										if status <> 0 then
										begin
                                            gotoxy(2,22);
											writeln('MES INVALIDO');
										end
										else
										begin
											aux:=copy(r.datanascimento,7,4);
											val(aux,a,status);
										if status <> 0 then
										begin
                                            gotoxy(2,22);
											writeln('ANO INVALIDO');
										end
										else
										begin
											if verificadata(d,m,a) <> true then
											begin
			                                     gotoxy(2,22);
                                                 writeln('DATA INVALIDA');
											end
											else
											begin
                                                gotoxy(7,9);
												readln(r.rua);
                                                gotoxy(10,10);
												readln(r.numero);
                                                gotoxy(15,11);
												readln(r.complemento);
                                                gotoxy(10,12);
												readln(r.bairro);
                                                gotoxy(10,13);
												readln(r.cidade);
                                                gotoxy(10,14);
												readln(r.estado);
												gotoxy(12,15);
												readln(r.telefone);
												gotoxy(10,16);
												readln(r.email);		
												gotoxy(7,17);
												readln(r.cpf);
												if validacpf(r.cpf) = false then
												begin
                                                    gotoxy(2,22);
													writeln('CPF INVALIDO');
												end
												else
												begin
												     seek(af,filesize(af));
												     write(af,r);
												     rh.matricula:=r.matricula;
												     rh.salario:=r.salario;
												     aux:=copy(r.datacontratacao,4,2);
												     val(aux,rh.mes,status);
												     aux:=copy(r.datacontratacao,7,4);
                                                     val(aux,rh.ano,status);
                                                     seek(ah,filesize(ah));
                                                     write(ah,rh);
                                                     gotoxy(2,22);
                                                     writeln('CADASTRO EFETUADO');
												end;
											end;
										end;
									end;
								end;
							end;
						end;
					end;
                end;
             end;
         end;
       end;
      gotoxy(2,23);
      writeln('DESEJA SAIR? S/N: ');
      gotoxy(19,23);
      sair:=readkey;
      sair:=upcase(sair);
  	until sair = 'S';
end;

//ALTERAR SALARIO
procedure alterarsalario(var af:tarqfunc;var hs:tarqhistsal);
var rf:tregfunc;
	posicao:integer;
	rh:treghistsal;
	sair:char;
begin
	repeat
		clrscr;
        borda;
        gotoxy(2,1);
        write('ALTERACAO DE SALARIO');
        gotoxy(2,3);
        write('MATRICULA: ');
        gotoxy(13,3);
        readln(rf.matricula);
		posicao:=pesquisafunc(af,rf.matricula);
		if posicao = -1 then
		begin
            gotoxy(2,22);
			writeln('MATRICULA INEXISTENTE');
		end
		else
        begin
             gotoxy(2,4);
             write('NOVO SALARIO: ');
             gotoxy(2,5);
             write('MES DE ALTERACAO: ');
             gotoxy(2,6);
             write('ANO DE ALTERACAO: ');
			seek(af,posicao);
			read(af,rf);
            gotoxy(16,4);
			readln(rf.salario);
			if rf.salario <= 0 then
			begin
                gotoxy(2,22);
				writeln('SALARIO INVALIDO');
			end
			else
			begin
				rh.matricula:=rf.matricula;
                gotoxy(20,5);
				readln(rh.mes);
                gotoxy(20,6);
				readln(rh.ano);
				if pesquisahistoricosalario(arqhistsal,rf.matricula,rh.mes,rh.ano) = -1 then
				begin
					seek(af,posicao);
					write(af,rf);
					seek(hs,filesize(hs));
					write(hs,rh);
                    gotoxy(2,22);
                    writeln('ALTERACAO EFETUADA');
				end
				else
				begin
                    gotoxy(2,22);
					writeln('DATA INVALIDA');
				end;
			end;
		end;
        gotoxy(2,23);
        writeln('DESEJA SAIR? S/N: ');
        gotoxy(19,23);
        sair:=readkey;
        sair:=upcase(sair);
	until sair = 'S';
end;

//ALTERAR GERENTE DEPARTAMENTO
procedure alterardepartamento(var ad:tarqdep;var hd:tarqhistdep);
var rd:tregdep;
	rh:treghistdep;
	rf:tregfunc;
	posicao,status:integer;
	sair:char;
	d,m,a:integer;
	aux,mes,ano:string[6];
begin
	repeat
		clrscr;
        borda;
        gotoxy(2,1);
        write('ALTERACAO DE GERENTE DE UM DEPARTAMENTO');
        gotoxy(2,3);
		write('CODIGO DO DEPARTAMENTO: ');
        gotoxy(26,3);
		readln(rd.codigo);
		posicao:=pesquisadep(ad,rd.codigo);
		if posicao = -1 then
		begin
            gotoxy(27,20);
			writeln('DEPARTAMENTO INEXISTENTE');
		end
		else
		begin
            gotoxy(2,4);
			write('MATRICULA DO NOVO GERENTE: ');
            gotoxy(2,5);
            write('DATA DE ALTERACAO: ');
            gotoxy(29,4);
			readln(rf.matricula);
			if pesquisafunc(arqfunc,rf.matricula)=-1 then
			begin
                gotoxy(2,22);
				writeln('FUNCIONARIO INEXISTENTE');
			end
			else
			begin
                gotoxy(21,5);
				readln(rh.data);
				aux:=copy(rh.data,1,2);
				val(aux,d,status);
				if status <> 0 then
				begin
                    gotoxy(2,22);
					writeln('DIA INVALIDO');
				end
				else
				begin
					aux:=copy(rh.data,4,2);
					val(aux,m,status);
					if status <> 0 then
					begin
                        gotoxy(2,22);
						writeln('MES INVALIDO');
					end
					else
					begin
						aux:=copy(rh.data,7,4);
						val(aux,a,status);
						if status <> 0 then
						begin
                            gotoxy(2,22);
							writeln('ANO INVALIDO');
						end
						else
						if verificadata(d,m,a)=false then
						begin
                            gotoxy(2,22);
							writeln('DATA INVALIDA');
						end
						else
						begin
						     aux:=copy(rh.data,4,3);
						     mes:=aux;
						     aux:=copy(rh.data,7,5);
						     ano:=aux;
							 rh.data:=mes+ano;
							 rh.codigogerente:=rf.matricula;
							 rh.codigodepartamento:=rd.codigo;
							 seek(hd,filesize(hd));
							 write(hd,rh);
							 seek(ad,posicao);
						     write(ad,rd);
                             gotoxy(2,22);
                             writeln('ALTERACAO EFETUADA');
						end;
					end;
				end;
			end;
		end;
        gotoxy(2,23);
        writeln('DESEJA SAIR? S/N: ');
        gotoxy(19,23);
        sair:=readkey;
        sair:=upcase(sair);;
	until sair = 'S';
end;
//ALTERAR FUNCIONARIO
procedure alterarfuncionario(var af:tarqfunc;var hf:tarqhistfunc);
var r:tregfunc;
	rd:tregdep;
	posicao:integer;
	rf:treghistfunc;
	sair:char;
	d,m,a:integer;
	aux:string[4];
	status:integer;
begin
	repeat
		clrscr;
        borda;
        gotoxy(2,1);
        write('ALTERACAO DE FUNCIONARIO');
        gotoxy(2,3);
		write('MATRICULA: ');
        gotoxy(13,3);
		readln(r.matricula);
		posicao:=pesquisafunc(af,r.matricula);
		if posicao = -1 then
		begin
            gotoxy(2,22);
			writeln('MATRICULA INEXISTENTE');
		end
		else
		begin
			seek(af,posicao);
			read(af,r);
            gotoxy(2,4);
			write('NOME: ');
            gotoxy(2,5);
            write('CODIGO DE DEPARTAMENTO: ');
            gotoxy(2,6);
            write('SALARIO: ');
            gotoxy(2,7);
            write('DATA DE NASCIMENTO: ');
            gotoxy(2,8);
            write('RUA: ');
            gotoxy(2,9);
			write('NUMERO: ');
			gotoxy(2,10);
			write('BAIRRO: ');
            gotoxy(2,11);
			write('COMPLEMENTO: ');
            gotoxy(2,12);
			write('CIDADE: ');
			gotoxy(2,13);
			write('ESTADO: ');
			gotoxy(2,14);
			write('TELEFONE: ');
            gotoxy(2,15);
		    write('E-MAIL: ');
            gotoxy(2,16);
			write('CPF: ');
            gotoxy(2,17);
            write('DATA DE MODIFICACAO: ');
            gotoxy(8,4);
			readln(r.nome);
			if (r.nome = '') or (r.nome = ' ') or (r.nome = '   ') or (r.nome = '    ') or (r.nome = '    ') or (r.nome = '     ') or (r.nome = '      ')   then
			begin
                gotoxy(2,22);
				writeln('O NOME NAO PODE SER VAZIO');
			end
			else
			begin
            gotoxy(26,5);
			readln(rd.codigo);
			if pesquisadep(arqdep,rd.codigo)=-1 then
			begin
                gotoxy(2,22);
				writeln('DEPARTAMENTO INEXISTENTE');
			end
			else
			begin
				gotoxy(11,6);
				readln(r.salario);
				if r.salario <= 0 then
				begin
                    gotoxy(2,22);
					writeln('VALOR INCORRETO');
				end
				else
				begin
                                    gotoxy(22,7);
									readln(r.datanascimento);
									aux:=copy(r.datanascimento,1,2);
									val(aux,d,status);
									if status <> 0 then
									begin
                                        gotoxy(2,22);
										writeln('DIA INVALIDO');
									end
									else
									begin
										aux:=copy(r.datanascimento,4,2);
										val(aux,m,status);
										if status <> 0 then
										begin
                                            gotoxy(2,22);
											writeln('MES INVALIDO');
										end
										else
										begin
											aux:=copy(r.datanascimento,7,4);
											val(aux,a,status);
											if status <> 0 then
											begin
                                                gotoxy(2,22);
												writeln('ANO INVALIDO');
											end
											else
											begin
												if verificadata(d,m,a)=true then
												begin
                                                    gotoxy(7,8);
													readln(r.rua);
													gotoxy(10,9);
													readln(r.numero);
													gotoxy(10,10);
													readln(r.bairro);
                                                    gotoxy(15,11);
													readln(r.complemento);
													gotoxy(10,12);
													readln(r.cidade);
													gotoxy(10,13);
													readln(r.estado);
													gotoxy(12,14);
													readln(r.telefone);
													gotoxy(10,15);
													readln(r.email);		
													gotoxy(7,16);
													readln(r.cpf);
													if validacpf(r.cpf) = false then
													begin
                                                        gotoxy(2,22);
														writeln('CPF INVALIDO');
													end
													else
													begin
                                                            gotoxy(21,17);
															readln(rf.data);
															aux:=copy(rf.data,1,2);
															val(aux,d,status);
															if status <> 0 then
															begin
                                                                 gotoxy(2,22);
                                                                 writeln('DIA INVALIDO');
															end
															else
															begin
																aux:=copy(rf.data,4,2);
																val(aux,m,status);
																if status <> 0 then
																begin
																	gotoxy(2,22);
                                                                    writeln('MES INVALIDO');
																end
																else
																begin
																	aux:=copy(rf.data,7,4);
																	val(aux,a,status);
																	if status <> 0 then
																	begin
                                                                         gotoxy(2,22);
                                                                         writeln('ANO INVALIDO');
																	end
																	else
																	begin
																		if verificadata(d,m,a)=true then
																		begin
																			rf.matriculafuncionario:=r.matricula;
																			rf.codigodepartamento:=rd.codigo;
																			seek(af,posicao);
																			write(af,r);
																			seek(hf,filesize(hf));
																			write(hf,rf);
																		end
																		else
																		begin
                                                                             gotoxy(2,22);
                                                                             writeln('DATA INVALIDA');
																		end;
																	end;
																end;
															end;
														end;
													end;
												end;
											end;
										end;
									end;
								end;
							end;
						end;
        gotoxy(2,23);
        writeln('DESEJA SAIR? S/N: ');
        gotoxy(19,23);
        sair:=readkey;
        sair:=upcase(sair);
	until sair = 'S';
end;

//ALTERAR DEPARTAMENTO FUNCIONARIO
procedure alterardepartamentofuncionario(var af:tarqfunc;var hd:tarqhistdep;var ad:tarqdep);
var rf:tregfunc;
	rd:tregdep;
	rh:treghistfunc;
	rhd:treghistdep;
	posicao:integer;
	sair:char;
	d,m,a:integer;
	aux:string[4];
	status:integer;
	mes,ano:string;
begin
	repeat
		clrscr;
        borda;
        gotoxy(2,1);
        write('ALTERACAO DE DEPARTAMENTO DE FUNCIONARIO');
        gotoxy(2,3);
		write('MATRICULA: ');
        gotoxy(13,3);
		readln(rf.matricula);
		if pesquisafunc(af,rf.matricula) = -1 then
		begin
            gotoxy(2,22);
			writeln('MATRICULA INEXISTENTE');
		end
		else
		begin
            gotoxy(2,4);
            write('CODIGO DO NOVO DEPARTAMENTO: ');
            gotoxy(2,5);
            write('DATA DE ALTERACAO: ');
            gotoxy(31,4);
			readln(rd.codigo);
			posicao:=pesquisadep(ad,rd.codigo);
			if posicao = -1 then
			begin
                gotoxy(2,22);
				write('DEPARTAMENTO INEXISTENTE');
			end
			else
			begin
                gotoxy(20,5);
				readln(rh.data);
				aux:=copy(rh.data,1,2);
				val(aux,d,status);
				if status <> 0 then
				begin
                     gotoxy(2,22);
				     write('DIA INVALIDO');
				end
				else
				begin
					aux:=copy(rh.data,4,2);
					val(aux,m,status);
					if status <> 0 then
					begin
                         gotoxy(2,22);
                         write('MES INVALIDO')
					end
					else
					begin
						aux:=copy(rh.data,7,4);
						val(aux,a,status);
						if status <> 0 then
						begin
                             gotoxy(2,22);
                             write('ANO INVALIDO')
						end
						else
						if  verificadata(d,m,a)=false then
						begin
                             gotoxy(2,22);
                             write('DATA INVALIDA')
						end
						else
						begin
								aux:=copy(rh.data,3,3);
								mes:=aux;
								aux:=copy(rh.data,6,5);
								ano:=aux;
								rhd.data:=mes+ano;
								rhd.codigodepartamento:=rd.codigo;
								rh.matriculafuncionario:=rf.matricula;
								seek(hd,filesize(hd));
								write(hd,rhd);
								seek(ad,posicao);
								write(ad,rd);
                                gotoxy(2,22);
                                writeln('ALTERACAO EFETUADA');
						end;
					end;
				end;
			end;
		end;			
        gotoxy(2,23);
        writeln('DESEJA SAIR? S/N: ');
        gotoxy(19,23);
        sair:=readkey;
        sair:=upcase(sair);
	until sair = 'S';
end;

//CONSULTA FUNCIONARIO MATRICULA
procedure consultafuncionariomatricula(var af:tarqfunc;var ad:tarqdep);
var rf:tregfunc;
	rd:tregdep;
	sair:char;
	posicao:integer;
begin
	repeat
		clrscr;
        borda;
        gotoxy(2,1);
        write('CONSULTA DE FUNCIONARIO POR MATRICULA');
        gotoxy(2,3);
		write('MATRICULA: ');
        gotoxy(13,3);
		readln(rf.matricula);
		posicao:=pesquisafunc(arqfunc,rf.matricula);
		if  posicao = -1 then
		begin
            gotoxy(2,22);
			write('MATRICULA INEXISTENTE');
		end
		else
		begin
			seek(af,posicao);
			read(af,rf);
			writeln(' NOME: ',rf.nome);
			writeln(' DATA DE NASCIMENTO: ',rf.datanascimento);
			writeln(' RUA: ',rf.rua);
			writeln(' NUMERO: ',rf.numero);
			writeln(' BAIRRO: ',rf.bairro);
			writeln(' COMPLEMENTO: ',rf.complemento);
			writeln(' CIDADE: ',rf.cidade);
			writeln(' ESTADO: ',rf.estado);
			writeln(' TELEFONE: ',rf.telefone);
			writeln(' E-MAIL: ',rf.email);
			writeln(' CPF: ',rf.cpf);
			posicao:=pesquisadep(ad,rf.codigodepartamento);
			seek(ad,posicao);
			read(ad,rd);
			writeln(' DEPARTAMENTO: ',rd.nome);
		end;
        gotoxy(2,23);
        writeln('DESEJA SAIR? S/N: ');
        gotoxy(19,23);
        sair:=readkey;
        sair:=upcase(sair);
	until sair = 'S';
end;

//GERAR FOLHA PAGAMENTO
procedure gerarfolhapagamento(var af:tarqfunc;var ad:tarqdep);
var rf:tregfunc;
	rd:tregdep;
	posicaofunc,posicao:integer;
    i,l:integer;
begin
	clrscr;
    borda;
    posicaofunc:=filesize(af)-1;
    gotoxy(2,1);
    write('GERADOR DE FOLHA DE PAGAMENTO');
    gotoxy(2,3);
    write('NOME');
    gotoxy(23,3);
    write('SALARIO');
    gotoxy(40,3);
    write('DEPARTAMENTO');
    i:=4;
    l:=0;
	while l<=posicaofunc do
	begin
        seek(af,l);
		read(af,rf);
        gotoxy(2,i);
		write(rf.nome);
        gotoxy(23,i);
        write('R$ ',rf.salario:8:2);
        posicao:=pesquisadep(ad,rf.codigodepartamento);
		seek(ad,posicao);
		read(ad,rd);
        gotoxy(40,i);
		write(rd.nome);
        l:=l+1;
	end;
    gotoxy(2,23);
	write('PRESSIONE ENTER PARA SAIR');
    gotoxy(29,23);
	readkey;
end;

//GERENTES DE UM DEPARTAMENTO
procedure gerentesdeumdepartamento(var af:tarqfunc;var ah:tarqhistdep;var ad:tarqdep);
var rf:tregfunc;
	ra:treghistdep;
	rd:tregdep;
	sair:char;
	posicao,posicaohist,l,i:integer;
begin
	repeat
		clrscr;
        borda;
        gotoxy(2,1);
        write('GERENTES DE UM DEPARTAMENTO');
        gotoxy(2,3);
		write('CODIGO DO DEPARTAMENTO: ');
        gotoxy(26,3);
		readln(rd.codigo);
		posicao:=pesquisadep(ad,rd.codigo);
		if posicao = -1 then
		begin
            gotoxy(2,22);
			write('DEPARTAMENTO INEXISTENTE');
		end
		else
		begin
            gotoxy(2,4);
            write('PERIODO');
            gotoxy(12,4);
            write('NOME');
            gotoxy(40,4);
            write('TELEFONE');
            i:=5;
            l:=0;
            posicaohist:=filesize(ah)-1;
            seek(ah,0);
            while (l<=posicaohist) do
            begin
                seek(ah,l);
                read(ah,ra);
                gotoxy(2,i);
                writeln(ra.data);
				if ra.codigodepartamento = rd.codigo then
				begin
					posicao:=pesquisafunc(af,ra.codigogerente);
					seek(af,posicao);
					read(af,rf);
                    gotoxy(12,i);
					writeln(rf.nome);
                    gotoxy(40,i);
                    writeln(rf.telefone);
				end;
                i:=i+1;
                l:=l+1;
			end;
		end;
        gotoxy(2,23);
        writeln('DESEJA SAIR? S/N: ');
        gotoxy(19,23);
        sair:=readkey;
        sair:=upcase(sair);
	until sair = 'S';
end;

//RELATORIO DE FUNCIONARIOS POR DEPARTAMENTO
procedure relatoriodefuncionariopordepartamento(var af:tarqfunc;var ad:tarqdep);
var rf:tregfunc;
    rd:tregdep;
    posicaofunc,posicaodep:integer;
    sair:char;
    i:integer;
    total:real;
begin
     repeat
           clrscr;
           borda;
           posicaofunc:=0;
           posicaodep:=0;
           gotoxy(2,1);
           write('RELATORIO DE FUNCIONARIO POR DEPARTAMENTO');
           gotoxy(2,3);
           write('CODIGO DO DEPARTAMENTO: ');
           gotoxy(26,3);
           readln(rd.codigo);
           posicaodep:=pesquisadep(ad,rd.codigo);
           if posicaodep = -1 then
           begin
                gotoxy(2,22);
                write('DEPARTAMENTO INEXISTENTE');
           end
           else
           begin
                total:=0;
                seek(ad,posicaodep);
                read(ad,rd);
                gotoxy(2,4);
                write('NOME DO DEPARTAMENTO: ');
                gotoxy(24,4);
                write(rd.nome);
                gotoxy(2,5);
                write('MATRICULA');
                gotoxy(15,5);
                write('NOME');
                gotoxy(29,5);
                write('SALARIO');
                i:=6;
                seek(af,posicaofunc);
                while eof(af)=false do
                begin
                     read(af,rf);
                     if rd.codigo = rf.codigodepartamento then
                     begin
                          gotoxy(2,i);
                          write(rf.nome);
                          gotoxy(15,i);
                          write(rf.nome);
                          gotoxy(29,i);
                          write('R$ ',rf.salario:8:2);
                          i:=i+1;
                          total:=total+rf.salario;
                     end;
               end;
               gotoxy(2,i+1);
               write('TOTAL DA FOLHA DO DEPARTAMENTO: ');
               gotoxy(34,i+1);
               write(' R$ ',total:8:2);
          end;
          gotoxy(2,23);
          writeln('DESEJA SAIR? S/N: ');
          gotoxy(19,23);
          sair:=readkey;
          sair:=upcase(sair);
     until sair = 'S';
end;

//HISTORICO DO SALARIO EM UM PERIODO
procedure historicosalarioemperiodo(var af:tarqfunc;var ah:tarqhistsal);
var rf:tregfunc;
    rh:treghistsal;
    sair:char;
    datainicio,datafinal:string[15];
    status,i,l,posicao,mesinicio,anoinicio,anofinal,mesfinal:integer;
    aux:string[4];
begin
     repeat
           clrscr;
           borda;
           gotoxy(2,1);
           write('HISTORICO DE SALARIO DE UM FUNCIONARIO EM UM PERIODO');
           gotoxy(2,3);
           write('MATRICULA: ');
           gotoxy(13,3);
           readln(rf.matricula);
           posicao:=pesquisafunc(af,rf.matricula);
           if posicao = -1 then
           begin
                gotoxy(2,22);
                write('MATRICULA INEXISTENTE');
           end
           else
           begin
                gotoxy(2,4);
                write('DE MES / ANO: ');
                gotoxy(24,4);
                write('A MES / ANO: ');
                gotoxy(16,4);
                readln(datainicio);
				aux:=copy(datainicio,1,2);
				val(aux,mesinicio,status);
				if status <> 0 then
				begin
                     gotoxy(2,22);
                     writeln('MES INVALIDO');
				end
				else
				begin
				     aux:=copy(datainicio,4,4);
				     val(aux,anoinicio,status);
				     if status <> 0 then
				     begin
                          gotoxy(2,22);
                          writeln('ANO INVALIDO');
                     end
                     else
                     gotoxy(37,4);
                     readln(datafinal);
                     aux:=copy(datafinal,1,2);
                     val(aux,mesfinal,status);
                     if status <> 0 then
                     begin
                          gotoxy(2,22);
                          writeln('MES INVALIDO');
                     end
                     else
                     begin
                          aux:=copy(datafinal,4,4);
                          val(aux,anofinal,status);
                          if status <> 0 then
                          begin
                               gotoxy(2,22);
                               writeln('ANO INVALIDO');
                          end
                          else
                          begin
                               if (mesinicio<=0) and (mesinicio>31) and (anoinicio<=1900) and (anoinicio>=3000) and (mesfinal<=0) and (mesfinal>31) and (anofinal<=1900) and (anofinal>=3000) then
                               begin
                                    gotoxy(2,22);
                                    writeln('DATA INVALIDA');
                               end
                               else
                               begin
                                    gotoxy(2,6);
                                    write('PERIODO');
                                    gotoxy(14,6);
                                    write('SALARIO');
                                    i:=8;
                                    posicao:=filesize(ah)-1;
                                    l:=0;
                                    while l<posicao do
                                    begin
                                         seek(ah,l);
                                         read(ah,rh);
                                         if (rh.matricula = rf.matricula) then
                                         begin
                                              if (rh.ano>=anoinicio) and (rh.ano<=anofinal) then
                                              begin
                                                   if (rh.mes>=mesinicio) and (rh.ano=anoinicio) then
                                                   begin
                                                        gotoxy(2,i);
                                                        write(rh.mes,'/',rh.ano);
                                                        gotoxy(14,i);
                                                        write('R$ ',rh.salario:8:2);
                                                   end
                                                   else
                                                   begin
                                                         if (rh.ano>anoinicio) and (rh.ano<anofinal) then
                                                         begin
                                                              gotoxy(2,i);
                                                              write(rh.mes,'/',rh.ano);
                                                              gotoxy(14,i);
                                                              write('R$ ',rh.salario:8:2);
                                                         end
                                                         else
                                                         begin
                                                              if (rh.ano=anofinal) and (rh.mes<=mesfinal) then
                                                              begin
                                                                   gotoxy(2,i);
                                                                   write(rh.mes,'/',rh.ano);
                                                                   gotoxy(14,i);
                                                                   write('R$ ',rh.salario:8:2);
                                                              end;
                                                         end;
                                                   end;
                                              end;
                                         end;
                                         l:=l+1;
                                         i:=i+1;
                                    end;
                               end;
                          end;
                     end;
               end;
          end;
          gotoxy(2,23);
          writeln('DESEJA SAIR? S/N: ');
          gotoxy(19,23);
          sair:=readkey;
          sair:=upcase(sair);
     until sair = 'S';
end;


//MENU DO PROGRAMA
begin
	assign(arqdep,'c:\tp\dep.dat');
	{$I-}
	reset(arqdep);
	{$I+}
	if IOresult <> 0 then
		rewrite(arqdep);
	assign(arqfunc,'c:\tp\func.dat');
	{$I-}
	reset(arqfunc);
	{$I+}
	if IOresult <> 0 then
		rewrite(arqfunc);
	assign(arqhistsal,'c:\tp\histsal.dat');
	{$I-}
	reset(arqhistsal);
	{$I+}
	if IOresult <> 0 then
		rewrite(arqhistsal);
	assign(arqhistdep,'c:\tp\histdep.dat');
	{$I-}
	reset(arqhistdep);
	{$I+}
	if IOresult <> 0 then
		rewrite(arqhistdep);
	assign(arqhistfunc,'c:\tp\histfunc.dat');
	{$I-}
	reset(arqhistfunc);
	{$I+}
	if IOresult <> 0 then
		rewrite(arqhistfunc);
    textbackground(black);
    clrscr;
    window(2,2,65,25);
    textbackground(15);
    clrscr;
    writeln;
    gotoXY(2,3);
    textcolor(0);
	repeat
        textbackground(3);
        clrscr;
        borda;
        gotoxy(2,1);
        writeln('           CONTROLE DE FUNCIONARIOS                    ');
		gotoxy(2,3);
		writeln('           1 - CADASTRO                                 ');
		gotoxy(2,5);
		writeln('           2 - ALTERACAO                                 ');;
		gotoxy(2,7);
		writeln('           3 - CONSULTA                                  ');
		gotoxy(2,9);
		writeln('           4 - SAIR                                      ');
        gotoxy(2,11);
		writeln('           OPCAO:               ');
        gotoxy(2,22);
        writeln('IFET 2011 - CAMPUS BARBACENA');
        gotoxy(2,23);
        writeln('CHARLES GARROCHO, THIAGO GARROCHO');
        gotoxy(19,11);
		op:=readkey;
        op:=upcase(op);
		case op of
			'1':begin
                    repeat
                       clrscr;
                       borda;
                       gotoxy(2,1);
                       write('           CADASTRO    ');
                       gotoxy(2,3);
                       write('           1 - CADASTRO DE DEPARTAMENTO');
                       gotoxy(2,5);
                       write('           2 - CADASTRO DE FUNCIONARIO');
                       gotoxy(2,7);
                       write('           3 - SAIR');
                       gotoxy(2,9);
                       write('           OPCAO: ');
                       gotoxy(19,9);
                       opc:=readkey;
                       case opc of
                            '1':cadastrodepartamento(arqdep);
                            '2':cadastrofuncionario(arqfunc,arqdep,arqhistsal);
                       end;
                    until opc = '3';
                end;
                '2':begin
                    repeat
                       clrscr;
                       borda;
                       gotoxy(2,1);
                       write('           ALTERACAO  ');
                       gotoxy(2,3);
                       write('           1 - ALTERACAO DE FUNCIONARIO');
                       gotoxy(2,5);
                       write('           2 - ALTERACAO DE GERENTE DE DEPARTAMENTO');
                       gotoxy(2,7);
                       write('           3 - ALTERACAO DE SALARIO');
                       gotoxy(2,9);
                       write('           4 - ALTERACAO DE DEPARTAMENTO DE FUNCIONARIO');
                       gotoxy(2,11);
                       write('           5 - SAIR ');
                       gotoxy(2,13);
                       write('           OPCAO: ');
                       gotoxy(19,13);
                       opd:=readkey;
                       case opd of
                            '1':alterarfuncionario(arqfunc,arqhistfunc);
                            '2':alterardepartamento(arqdep,arqhistdep);
                            '3':alterarsalario(arqfunc,arqhistsal);
                            '4':alterardepartamentofuncionario(arqfunc,arqhistdep,arqdep);
                       end;
                    until opd = '5';
                end;
             '3':begin
                    repeat
                       clrscr;
                       borda;
                       gotoxy(2,1);
                       write('           CONSULTA  ');
                       gotoxy(2,3);
                       write('           1 - CONSULTA FUNCIONARIO POR MATRICULA');
                       gotoxy(2,5);
                       write('           2 - GERAR FOLHA PAGAMENTO ');
                       gotoxy(2,7);
                       write('           3 - GERENTES DE UM DEPARTAMENTO');
                       gotoxy(2,9);
                       write('           4 - RELATORIO DE FUNCIONARIO POR DEPARTAMENTO');
                       gotoxy(2,11);
                       write('           5 - HISTORICO DE SALARIO DE UM FUNCIONARIO ');
                       gotoxy(2,13);
                       write('           6 - SAIR');
                       gotoxy(2,15);
                       write('           OPCAO: ');
                       gotoxy(19,15);
                       ope:=readkey;
                       case ope of
                            '1':consultafuncionariomatricula(arqfunc,arqdep);
                            '2':gerarfolhapagamento(arqfunc,arqdep);
                            '3':gerentesdeumdepartamento(arqfunc,arqhistdep,arqdep);
                            '4':relatoriodefuncionariopordepartamento(arqfunc,arqdep);
                            '5':historicosalarioemperiodo(arqfunc,arqhistsal);
                       end;
                    until ope = '6';
                end;
		  end;
	until op = '4';
	close(arqdep);
	close(arqfunc);
	close(arqhistsal);
	close(arqhistdep);
	close(arqhistfunc);
end.
