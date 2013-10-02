package br.edu.ifsudestemg.livraria.ejb;

import java.awt.List;

import br.edu.ifsudestemg.livraria.modelo.Livro;

public interface Carrinho {
	
	void addLivro(Livro livro);
	List getLivros();
	double getTotal();
	void finalizaCompra();

}
