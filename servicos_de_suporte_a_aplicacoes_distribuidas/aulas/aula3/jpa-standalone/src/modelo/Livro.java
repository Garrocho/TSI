package modelo;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;

@Entity
public class Livro implements Serializable {

	private static final long serialVersionUID = 1L;
	
	@Id
	@GeneratedValue
	private int id;
	private String nome;
	private float valor;
	
	public Livro() {
		super();
		// TODO Auto-generated constructor stub
	}

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
	
	public float getValor() {
		return valor;
	}
	
	public void setValor(float valor) {
		this.valor = valor;
	}
}
