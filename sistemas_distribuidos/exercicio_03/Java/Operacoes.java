import java.io.Serializable;
import java.math.BigInteger;

public class Operacoes implements Serializable {

	private static final long serialVersionUID = 1L;

	public Operacoes() {
	}
	
	public String Soma(int valor1, int valor2) {
		FazOp processo = new FazOp(valor1, valor2, "SOMA");
		processo.start();
		try {
			processo.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		return processo.getResultado();
	}  

	public String Produto(int valor1, int valor2) {  
		return String.format("%d", valor1 * valor2);
	}

	public String Divisao(int valor1, int valor2) {  
		return String.format("%d", valor1 / valor2);
	}

	public String Fatorial(int valor1) {
		FazOp processo = new FazOp(valor1, "FATORIAL");
		processo.start();
		try {
			processo.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		return processo.getResultado();
	}
} 

class FazOp extends Thread {
	private int valor1, valor2;
	private String op, resultado;

	public FazOp(int valor1, int valor2, String op) {
		super();
		this.valor1 = valor1;
		this.valor2 = valor2;
		this.op = op;
	}

	public FazOp(int valor1, String op) {
		super();
		this.valor1 = valor1;
		this.op = op;
	}
	
	public String getResultado() {
		return resultado;
	}

	public synchronized void run() {
		switch(op) {
			case "FATORIAL":
				BigInteger um = new BigInteger("1");
				BigInteger result = um;
				BigInteger contador = um;
				BigInteger limite = new BigInteger(String.valueOf(valor1));

				while( contador.compareTo(limite) <= 0){
					result = result.multiply(contador);
					contador = contador.add(um);
				}
				resultado = String.format("%d", result);
				; break;
			case "PRODUTO":
				resultado = String.format("%d", valor1 * valor2);
				; break;
			case "DIVISAO": 
				resultado = String.format("%d", valor1 / valor2);
			; break;
			case "SOMA": 
				resultado = String.format("%d", valor1 + valor2);
				; break;
		}
	}
}
