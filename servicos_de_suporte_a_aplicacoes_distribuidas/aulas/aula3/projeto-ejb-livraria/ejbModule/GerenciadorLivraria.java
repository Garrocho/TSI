import java.util.List;

import javax.ejb.Remote;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

@Remote(Gerenciador.class)
@Stateless
public class GerenciadorLivraria implements Gerenciador {
	@PersistenceContext
	EntityManager em;
	
	@Override
	public void addLivro(Livro livro) {
		em.persist(livro);
	}

	@SuppressWarnings("unchecked")
	@Override
	public List<Livro> getLivros() {
		Query q = em.createQuery("from Livro l");
		return (List<Livro>)q.getResultList();
	}

	@Override
	public void delLivro(Livro livro) {
		livro = em.find(Livro.class, livro);
		em.remove(livro);
	}
}
