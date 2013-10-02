package br.edu.ifsudestemg.livraria.ejb;

import java.util.List;

import br.edu.ifsudestemg.livraria.modelo.Livro;

public interface Carrinho {
	
	void addLivro(Livro livro);
	List<Livro> getLivros();
	double getTotal();
	void finalizaCompra();

}
