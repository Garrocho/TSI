package cliente;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.Query;

import modelo.Livro;

public class ClienteJPA {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Livro l = new Livro();
		EntityManager manager = new JPAUtil().getEntityManager();
		l.setNome("Teste2");
		l.setValor(130);
		
		manager.getTransaction().begin();
		manager.persist(l);
		manager.getTransaction().commit();
		/*l = null;
		l = manager.find(Livro.class, 1);
		if (l !=null) {
			System.out.println(l.getNome());
			manager.getTransaction().begin();
			manager.remove(l);
			manager.getTransaction().commit();
		}
		else {
			System.out.println("Removido");
		}*/
		
		manager.getTransaction().begin();
		Query q = manager.createQuery("from Livro l");
		List<Livro> livros = (List<Livro>)q.getResultList();
		for (Livro l1 : livros) {
			System.out.println(l1.getNome());
		}
		manager.getTransaction().commit();
	}
}
