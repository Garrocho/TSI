package com.aula1.rmi;

import javax.naming.InitialContext;

public class RegistraLivrariaNoJBoss {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		InitialContext contexto = new InitialContext();
		contexto.rebind("livraria", new LivrariaBean());
		System.out.println("Sucesso");
	}
}
