package com.locadora.gerencia;

import java.util.ArrayList;
import java.util.List;

import javax.ejb.EJBException;
import javax.ejb.Remote;
import javax.ejb.Stateful;
import javax.persistence.EntityManager;
import javax.persistence.NoResultException;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import com.locadora.entidade.Cliente;
import com.locadora.entidade.Diretor;
import com.locadora.entidade.Emprestimo;
import com.locadora.entidade.Exemplar;
import com.locadora.entidade.Filme;
import com.locadora.entidade.ItemEmprestimo;


@Remote(Gerenciador.class)
@Stateful
public class GerenciadorVideoLocadora implements Gerenciador {
	@PersistenceContext
	EntityManager em;

	@Override
	public Filme addFilme(Filme filme) {
		try {
			em.persist(filme);
		} catch (EJBException e) {
			return null;
		}
		return filme;
	}

	@Override
	public Exemplar addExemplar(Exemplar exemplar, int idFilme) {
		Filme filme = em.find(Filme.class, idFilme);
		if (filme != null) {
			List<Exemplar> exemplares = filme.getExemplares();
			exemplar.setFilme(filme);
			em.persist(exemplar);
			exemplares.add(exemplar);
			em.merge(filme);
			em.flush();
		} else {
			exemplar = null;
		}
		return exemplar;
	}

	@Override
	public Cliente addCliente(Cliente cliente) {
		em.persist(cliente);
		return cliente;
	}

	@Override
	public Diretor addDiretor(Diretor diretor) {
		em.persist(diretor);
		return diretor;
	}

	@SuppressWarnings("unchecked")
	@Override
	public List<Filme> buscaFilmes(Diretor diretor) {
		List<Filme> filmes = new ArrayList<Filme>();
		Query q = em
				.createQuery("select f from Filme as f inner join f.diretores as d where d.id = :idDiretor");
		q.setParameter("idDiretor", diretor.getId());
		try {
			filmes = (List<Filme>) q.getResultList();
		} catch (NoResultException e) {
			return null;
		}
		return filmes;
	}

	@Override
	public int totalExemplares(Filme filme) {
		filme = em.find(Filme.class, filme.getId());
		List<Exemplar> exemplares = filme.getExemplares();
		int numeroExemplaresDisp = 0;
		System.out.println(exemplares);
		for (Exemplar e : exemplares) {
			if (!e.isEmprestado())
				numeroExemplaresDisp += 1;
		}
		return numeroExemplaresDisp;
	}

	@SuppressWarnings("unchecked")
	@Override
	public List<Diretor> buscaDiretores(Filme filme) {
		List<Diretor> diretores;
		Query q = em
				.createQuery("select d from Diretor as d inner join d.filmes as f where f.id = :idFilme");
		q.setParameter("idFilme", filme.getId());
		try {
			diretores = (List<Diretor>) q.getResultList();
		} catch (NoResultException e) {
			return null;
		}
		return diretores;
	}

	@Override
	public Diretor buscaDiretor(int id) {
		Query q = em.createQuery("select d from Diretor d where d.id = :id");
		q.setParameter("id", id);
		Diretor diretor;
		try {
			diretor = (Diretor) q.getSingleResult();
		} catch (NoResultException e) {
			return null;
		}
		return diretor;
	}

	@Override
	public Filme buscaFilme(int id) {
		Query q = em.createNamedQuery("getFilmeId");
		q.setParameter("id", id);
		Filme f;
		try {
			f = (Filme) q.getSingleResult();
		} catch (Exception e) {
			return null;
		}
		return f;
	}

	@Override
	public Filme buscaFilme(String nome) {
		Query q = em.createNamedQuery("getFilmeNome");
		q.setParameter("nome", "%" + nome + "%");
		Filme f;
		try {
			f = (Filme) q.getSingleResult();
		} catch (Exception e) {
			return null;
		}
		return f;
	}

	@SuppressWarnings("unchecked")
	@Override
	public List<Filme> buscaFilmes(String genero, int ano) {
		List<Filme> filmes;
		Query q = em
				.createQuery("select f from Filme f where f.anoLancamento = :ano and f.genero LIKE :genero");
		q.setParameter("ano", ano);
		q.setParameter("genero", "%" + genero + "%");
		try {
			filmes = (List<Filme>) q.getResultList();
		} catch (NoResultException e) {
			return null;
		}
		return filmes;
	}

	@Override
	public Cliente buscaCliente(int id) {
		Query q = em.createQuery("select c from Cliente c where c.id = :id");
		q.setParameter("id", id);
		Cliente cliente;
		try {
			cliente = (Cliente) q.getSingleResult();
		} catch (NoResultException e) {
			return null;
		}
		return cliente;
	}

	@Override
	public Cliente buscaCliente(String nome) {
		Query q = em
				.createQuery("select c from Cliente c where c.nome LIKE :nome");
		q.setParameter("nome", "%" + nome + "%");
		Cliente cliente;
		try {
			cliente = (Cliente) q.getSingleResult();
		} catch (NoResultException e) {
			return null;
		}
		return cliente;
	}

	@Override
	public Exemplar buscaExemplar(int id) {
		Query q = em.createQuery("select e from Exemplar e where e.id = :id");
		q.setParameter("id", id);
		Exemplar exemplar;
		try {
			exemplar = (Exemplar) q.getSingleResult();
		} catch (NoResultException e) {
			return null;
		}
		return exemplar;
	}

	@Override
	public void delDiretor(Diretor diretor) {
		diretor = em.find(Diretor.class, diretor.getId());
		em.remove(diretor);
	}

	@Override
	public ItemEmprestimo addItem(int idFilme, float valorEmprestimo) {
		Filme filme = em.find(Filme.class, idFilme);
		List<Exemplar> exemplares = filme.getExemplares();
		ItemEmprestimo itemEmprestimo = new ItemEmprestimo();

		Exemplar exemplar = null;
		for (Exemplar e : exemplares) {
			if (!e.isEmprestado()) {
				exemplar = em.find(Exemplar.class, e.getId());
				itemEmprestimo.setExemplar(exemplar);
				break;
			}
		}
		if (exemplar == null)
			return null;
		itemEmprestimo.setValorEmprestimo(valorEmprestimo);

		return itemEmprestimo;
	}

	@Override
	public Emprestimo Locacao(Emprestimo emprestimo) {
		em.persist(emprestimo);
		return emprestimo;
	}

	@SuppressWarnings("unchecked")
	@Override
	public void devolucaoFilmes(Emprestimo emprestimo, String dataAtual) {
		List<ItemEmprestimo> itens;
		Query q = em
				.createQuery("select i from Emprestimo as e inner join e.itens as i where e.id = :idEmprestimo");
		q.setParameter("idEmprestimo", emprestimo.getId());
		itens = (List<ItemEmprestimo>) q.getResultList();
		for (ItemEmprestimo ie : itens) {
			ItemEmprestimo itemEmprestimo = buscaItem(ie.getId());
			itemEmprestimo.setDataDevolucao(dataAtual);
			Exemplar exemplar = itemEmprestimo.getExemplar();
			exemplar = buscaExemplar(exemplar.getId());
			exemplar.setEmprestado(false);
			em.merge(itemEmprestimo);
			em.merge(exemplar);
			em.flush();
		}
	}

	@Override
	public boolean associa(int idDiretor, int idFilme) {
		Filme f = buscaFilme(idFilme);
		Diretor d = buscaDiretor(idDiretor);
		if (f == null || d == null)
			return false;
		f.getDiretores().add(d);
		em.merge(f);
		em.flush();
		return true;
	}

	public void finalizaProcessoLocacao(Cliente cliente, Emprestimo emprestimo,
			List<ItemEmprestimo> itens) {
		em.persist(emprestimo);
		int idEmprestimo = emprestimo.getId();
		emprestimo = em.find(Emprestimo.class, idEmprestimo);
		for (ItemEmprestimo ie : itens) {
			Exemplar exemplar = ie.getExemplar();
			exemplar = em.find(Exemplar.class, exemplar.getId());
			exemplar.setEmprestado(true);
			em.merge(exemplar);
			ie.setEmprestimo(emprestimo);
			ie.setExemplar(exemplar);
			em.persist(ie);
			emprestimo.getItens().add(ie);
		}
		cliente = em.find(Cliente.class, cliente.getId());
		cliente.getEmprestimos().add(emprestimo);
		emprestimo.setCliente(cliente);
		em.merge(emprestimo);
		em.merge(cliente);
		em.flush();
	}

	@Override
	public Emprestimo buscaEmprestimo(int id) {
		Emprestimo emprestimo;
		try {
			emprestimo = em.find(Emprestimo.class, id);
		} catch (NoResultException e) {
			return null;
		}
		return emprestimo;
	}

	@Override
	public ItemEmprestimo buscaItem(int id) {
		ItemEmprestimo item = em.find(ItemEmprestimo.class, id);
		return item;
	}

}
