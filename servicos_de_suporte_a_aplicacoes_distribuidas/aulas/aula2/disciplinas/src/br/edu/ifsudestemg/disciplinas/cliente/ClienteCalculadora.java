package br.edu.ifsudestemg.disciplinas.cliente;

import javax.naming.InitialContext;

import br.edu.ifsudestemg.disciplinas.ejb.Calculadora;

public class ClienteCalculadora {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		InitialContext contexto = new InitialContext();
		Calculadora calculadora = (Calculadora)contexto.lookup("CalculadoraBean/remote");
		
		System.out.println(calculadora.soma(50, 20));
		Thread.sleep(20000);
		System.out.println(calculadora.soma(50, 20));
	}
}
