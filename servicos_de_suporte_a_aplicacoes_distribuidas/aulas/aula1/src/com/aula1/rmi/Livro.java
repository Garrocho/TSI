package com.aula1.rmi;

import java.io.Serializable;

public class Livro implements Serializable {
	
	private static final long serialVersionUID = 1L;
	private String ispn, nome;
	private float preco;
	
	public Livro() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public Livro(String ispn, String nome, float preco) {
		super();
		this.ispn = ispn;
		this.nome = nome;
		this.preco = preco;
	}

	public String getIspn() {
		return ispn;
	}
	
	public void setIspn(String ispn) {
		this.ispn = ispn;
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
