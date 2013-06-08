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
