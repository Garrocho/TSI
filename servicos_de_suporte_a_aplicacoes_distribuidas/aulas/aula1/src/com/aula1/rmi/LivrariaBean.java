package com.aula1.rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.List;

public class LivrariaBean extends UnicastRemoteObject implements Livraria {

	private static final long serialVersionUID = 1L;
	private List<Livro> livros = new ArrayList<Livro>();
	private float total = 0;

	public LivrariaBean() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	public void adiciona(Livro livro) throws RemoteException {
		// TODO Auto-generated method stub
		livros.add(livro);
		total += livro.getPreco();
	}

	@Override
	public float getTotal() throws RemoteException {
		// TODO Auto-generated method stub
		return total;
	}

	@Override
	public List<Livro> getLivros() throws RemoteException {
		// TODO Auto-generated method stub
		return livros;
	}
}