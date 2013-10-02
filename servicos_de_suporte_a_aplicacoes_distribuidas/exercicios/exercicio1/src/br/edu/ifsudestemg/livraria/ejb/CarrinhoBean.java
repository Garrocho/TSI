package br.edu.ifsudestemg.livraria.ejb;

import java.util.List;
import java.util.ArrayList;

import br.edu.ifsudestemg.livraria.modelo.Livro;

public class CarrinhoBean implements Carrinho {
	
	private List<Livro> livros = new ArrayList<Livro>();
	private float total = 0;

	@Override
	public void addLivro(Livro livro) {
		// TODO Auto-generated method stub
		livros.add(livro);
		total += livro.getPreco();
		System.out.println("Livro " + livro.getNome() + " adicionado.");
	}
	
	@Override
	public List<Livro> getLivros() {
		// TODO Auto-generated method stub
		System.out.println("Iniciando a Execução do Método GetLivros!");
		return livros;
	}

	@Override
	public double getTotal() {
		// TODO Auto-generated method stub
		System.out.println("Iniciando a Execução do Método GetTotal! Total= " + total);
		return total;
	}
	
	@Override
	public void finalizaCompra() {
		// TODO Auto-generated method stub
		for (int i=0; i < livros.size(); i++)
			System.out.println(livros.get(i).getNome() + " | " + livros.get(i).getPreco());
	}
}