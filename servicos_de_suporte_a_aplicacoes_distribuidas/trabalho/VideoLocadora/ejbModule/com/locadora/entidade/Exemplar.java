package com.locadora.entidade;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;

@Entity
@Table(name="exemplar")
public class Exemplar implements Serializable {

	private static final long serialVersionUID = 1L;
	private int id;
	private String dataAquisicao;
	private boolean emprestado;
	private Filme filme;
	private List<ItemEmprestimo> itens = new ArrayList<ItemEmprestimo>();
	
	@Id
	@GeneratedValue
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getDataAquisicao() {
		return dataAquisicao;
	}
	public void setDataAquisicao(String dataAquisicao) {
		this.dataAquisicao = dataAquisicao;
	}
	public boolean isEmprestado() {
		return emprestado;
	}
	public void setEmprestado(boolean emprestado) {
		this.emprestado = emprestado;
	}
	
	@ManyToOne(cascade=CascadeType.ALL)
	public Filme getFilme() {
		return filme;
	}
	public void setFilme(Filme filme) {
		this.filme = filme;
	}
	
	@OneToMany
	public List<ItemEmprestimo> getItens() {
		return itens;
	}
	public void setItens(List<ItemEmprestimo> itens) {
		this.itens = itens;
	}
	
}
