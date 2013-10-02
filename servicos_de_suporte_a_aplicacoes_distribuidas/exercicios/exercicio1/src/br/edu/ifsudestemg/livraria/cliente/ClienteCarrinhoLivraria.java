package br.edu.ifsudestemg.livraria.cliente;

import javax.naming.InitialContext;

import br.edu.ifsudestemg.livraria.ejb.Carrinho;
import br.edu.ifsudestemg.livraria.modelo.Livro;

public class ClienteCarrinhoLivraria {
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		InitialContext contexto = new InitialContext();
		Carrinho carrinho = (Carrinho)contexto.lookup("ssadlivraria");
		Livro l1 = new Livro("EJB in Action 3.1", 200);
		carrinho.addLivro(l1);
		
		Livro l2 = new Livro("JPA 2.0", 150);
		carrinho.addLivro(l2);
		
		System.out.println("Preço Total = R$" + carrinho.getTotal());
		
	}
}
