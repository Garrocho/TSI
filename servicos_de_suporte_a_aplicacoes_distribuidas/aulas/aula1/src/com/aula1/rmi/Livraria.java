package com.aula1.rmi;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface Livraria extends Remote {
	
	void adiciona(Livro livro) throws RemoteException;
	float getTotal() throws RemoteException;
	List<Livro> getLivros() throws RemoteException;

}
