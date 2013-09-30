package com.aula1.cliente;

import java.rmi.Naming;

import com.aula1.rmi.Livraria;
import com.aula1.rmi.Livro;

public class ClienteLivraria {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Livraria livraria = (Livraria)Naming.lookup("rmi://localhost:1099/carrinho/livraria");
		
		Livro l1 = new Livro("1111", "EJB in Action 3.1", 200);
		livraria.adiciona(l1);
		
		Livro l2 = new Livro("2222", "JPA 2.0", 150);
		livraria.adiciona(l2);
		
		System.out.println("Preço Total = R$" + livraria.getTotal());
	}
}
