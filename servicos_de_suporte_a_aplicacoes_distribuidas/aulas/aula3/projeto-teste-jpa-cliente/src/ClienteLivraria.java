

import javax.naming.InitialContext;

public class ClienteLivraria {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		InitialContext ic = new InitialContext();
		Gerenciador g = (Gerenciador)ic.lookup("GerenciadorLivraria/remote");
		Livro livro = new Livro();
		livro.setNome("OMG");
		g.addLivro(livro);
		
		for (Livro l : g.getLivros())
			System.out.println(l.getNome());
	}
}