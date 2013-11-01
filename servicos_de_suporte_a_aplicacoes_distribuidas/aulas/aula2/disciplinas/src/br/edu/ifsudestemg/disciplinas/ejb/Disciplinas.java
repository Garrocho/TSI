package br.edu.ifsudestemg.disciplinas.ejb;

import java.util.List;

import br.edu.ifsudestemg.disciplinas.modelo.Disciplina;


public interface Disciplinas {
	
	void addDisciplina(Disciplina disciplina);
	List<Disciplina> getDisciplinas();
	void removeDisciplina(Disciplina disciplina);
	void terminarMatricula();
}
