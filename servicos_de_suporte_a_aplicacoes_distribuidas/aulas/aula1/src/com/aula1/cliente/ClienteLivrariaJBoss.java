package com.aula1.cliente;

import javax.naming.InitialContext;

import com.aula1.rmi.Livraria;
import com.aula1.rmi.Livro;

public class ClienteLivrariaJBoss {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		InitialContext contexto = new InitialContext();
		Livraria livraria = (Livraria)contexto.lookup("livraria");
		Livro l1 = new Livro("1111", "EJB in Action 3.1", 200);
		livraria.adiciona(l1);
		
		Livro l2 = new Livro("2222", "JPA 2.0", 150);
		livraria.adiciona(l2);
		
		System.out.println("Preço Total = R$" + livraria.getTotal());
		
	}
}
