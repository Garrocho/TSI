import java.util.List;


public interface Gerenciador {
	void addLivro(Livro livro);
	List<Livro> getLivros();
	void delLivro(Livro livro);
}
