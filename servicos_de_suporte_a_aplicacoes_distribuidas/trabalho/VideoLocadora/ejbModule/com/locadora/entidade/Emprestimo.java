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
@Table(name="emprestimo")
public class Emprestimo implements Serializable{

	private static final long serialVersionUID = 1L;
	private int id;
	private String dataEmprestimo;
	private String enderecoEntrega;
	private float valorTotal;
	
	private Cliente cliente;
	private List<ItemEmprestimo> itens = new ArrayList<ItemEmprestimo>();
	
	@Id
	@GeneratedValue
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getDataEmprestimo() {
		return dataEmprestimo;
	}
	public void setDataEmprestimo(String dataEmprestimo) {
		this.dataEmprestimo = dataEmprestimo;
	}
	public String getEnderecoEntrega() {
		return enderecoEntrega;
	}
	public void setEnderecoEntrega(String enderecoEntrega) {
		this.enderecoEntrega = enderecoEntrega;
	}
	public float getValorTotal() {
		return valorTotal;
	}
	public void setValorTotal(float valorTotal) {
		this.valorTotal = valorTotal;
	}
	
	@ManyToOne(cascade={CascadeType.ALL})
	public Cliente getCliente() {
		return cliente;
	}
	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}
	
	@OneToMany(mappedBy="emprestimo",cascade={CascadeType.ALL})
	public List<ItemEmprestimo> getItens() {
		return itens;
	}
	public void setItens(List<ItemEmprestimo> itens) {
		this.itens = itens;
	}
	
}
