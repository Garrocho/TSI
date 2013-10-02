package br.edu.ifsudestemg.livraria.modelo;

import java.io.Serializable;

public class Livro implements Serializable {

	private static final long serialVersionUID = 1L;
	private String nome;
	private float preco;
	
	public Livro() {
		super();
	}
	
	public Livro(String nome, float preco) {
		super();
		this.nome = nome;
		this.preco = preco;
	}

	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public float getPreco() {
		return preco;
	}
	
	public void setPreco(float preco) {
		this.preco = preco;
	}
}
