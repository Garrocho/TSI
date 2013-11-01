package br.edu.ifsudestemg.disciplinas.cliente;

import java.util.List;

import javax.naming.InitialContext;

import br.edu.ifsudestemg.disciplinas.ejb.Disciplinas;
import br.edu.ifsudestemg.disciplinas.modelo.Disciplina;

public class ClienteDisciplinas {
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		InitialContext contexto = new InitialContext();
		Disciplinas disciplinas = (Disciplinas)contexto.lookup("DisciplinasBean/remote");
		
		Disciplina discp = new Disciplina(5, "Ing");
		disciplinas.addDisciplina(discp);
		
		Disciplina discp2 = new Disciplina(6, "Lit");
		disciplinas.addDisciplina(discp2);
		
		disciplinas.terminarMatricula();
		
		disciplinas.removeDisciplina(discp2);
		
		List<Disciplina> todasDisciplinas = disciplinas.getDisciplinas();
		System.out.println(todasDisciplinas.size());
		
		for (Disciplina dic : todasDisciplinas) {
			System.out.println("Cliente\n " + dic.toString());
		}
	}
}
