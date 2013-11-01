package br.edu.ifsudestemg.disciplinas.ejb;

import java.util.ArrayList;
import java.util.List;

import javax.ejb.Remote;
import javax.ejb.Remove;
import javax.ejb.Stateful;

import org.jboss.annotation.ejb.cache.simple.CacheConfig;

import br.edu.ifsudestemg.disciplinas.modelo.Disciplina;

@Stateful
@Remote(Disciplinas.class)
@CacheConfig(maxSize=1)
public class DisciplinasBean implements Disciplinas {
	
	private List<Disciplina> disciplinas = new ArrayList<Disciplina>();

	@Override
	public void addDisciplina(Disciplina disciplina) {
		disciplinas.add(disciplina);
	}

	@Override
	public List<Disciplina> getDisciplinas() {
		// TODO Auto-generated method stub
		return disciplinas;
	}

	@Override
	public void removeDisciplina(Disciplina disciplina) {
		int i;
		System.out.println("Removendo Disciplina de " + disciplina.getNome());
		for ( i =0;i<disciplinas.size();i++)
		{
	       Disciplina d = disciplinas.get(i);
	       if(d.getId()==disciplina.getId())
	       {
	    	   disciplinas.remove(i);
	    	   System.out.println("Disciplina Removida");
	    	   break;
	       }
		}
	}

	@Remove
	public void terminarMatricula() {
		for (Disciplina dic : disciplinas) {
			System.out.println(dic.toString());
		}
	}
}