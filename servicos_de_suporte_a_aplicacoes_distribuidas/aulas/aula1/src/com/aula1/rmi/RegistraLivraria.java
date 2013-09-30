package com.aula1.rmi;

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class RegistraLivraria {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		LocateRegistry.createRegistry(1099);
		Naming.rebind("carrinho/livraria", new LivrariaBean());
		System.out.println("Objeto Registro com Sucesso!");
	}
}
