package br.edu.ifsudestemg.disciplinas.ejb;

import javax.ejb.Remote;
import javax.ejb.Stateless;

@Stateless
@Remote(Calculadora.class)
public class CalculadoraBean implements Calculadora {

	@Override
	public float soma(float a, float b) {
		// TODO Auto-generated method stub
		return a+b;
	}

	@Override
	public float subtrai(float a, float b) {
		// TODO Auto-generated method stub
		return a-b;
	}
}
