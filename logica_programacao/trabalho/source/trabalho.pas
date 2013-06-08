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
