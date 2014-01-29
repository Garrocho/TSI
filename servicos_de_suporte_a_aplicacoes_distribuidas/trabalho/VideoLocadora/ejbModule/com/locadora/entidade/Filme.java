package com.locadora.entidade;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
import javax.persistence.Table;

@Entity
@Table(name = "filme")
@NamedQueries({
		@NamedQuery(name = "getFilmeId", query = "select l from Filme l where l.id = :id"),
		@NamedQuery(name = "getFilmeNome", query = "select l from Filme l where l.nome like :nome") })
public class Filme implements Serializable {

	private static final long serialVersionUID = 1L;
	private int id;
	private String nome;
	private String genero;
	private int anoLancamento;
	private String duracao;
	private float valorLocacao;

	private List<Diretor> diretores = new ArrayList<Diretor>();
	private List<Exemplar> exemplares = new ArrayList<Exemplar>();

	@Id
	@GeneratedValue
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getGenero() {
		return genero;
	}

	public void setGenero(String genero) {
		this.genero = genero;
	}

	public int getAnoLancamento() {
		return anoLancamento;
	}

	public void setAnoLancamento(int anoLancamento) {
		this.anoLancamento = anoLancamento;
	}

	public String getDuracao() {
		return duracao;
	}

	public void setDuracao(String duracao) {
		this.duracao = duracao;
	}

	public float getValorLocacao() {
		return valorLocacao;
	}

	public void setValorLocacao(float valorLocacao) {
		this.valorLocacao = valorLocacao;
	}

	@ManyToMany(cascade = { CascadeType.ALL })
	public List<Diretor> getDiretores() {
		return diretores;
	}

	public void setDiretores(List<Diretor> diretores) {
		this.diretores = diretores;
	}

	@OneToMany(mappedBy="filme",cascade = { CascadeType.ALL })
	public List<Exemplar> getExemplares() {
		return exemplares;
	}

	public void setExemplares(List<Exemplar> exemplares) {
		this.exemplares = exemplares;
	}

}
