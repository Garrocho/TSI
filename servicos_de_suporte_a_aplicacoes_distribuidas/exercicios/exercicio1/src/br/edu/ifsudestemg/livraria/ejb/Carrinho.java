package br.edu.ifsudestemg.livraria.ejb;

import java.util.List;

import javax.ejb.Remote;

import br.edu.ifsudestemg.livraria.modelo.Livro;

@Remote
public interface Carrinho {
	
	void addLivro(Livro livro);
	List<Livro> getLivros();
	double getTotal();
	void finalizaCompra();

}
