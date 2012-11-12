import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;


public class Cliente {

	private Cliente() {
	}

	public static void main(String[] args) {    
		Operacoes op;
		try {
			Registry registry = LocateRegistry.getRegistry("10.3.1.37", 6666);  
			Servidor stub = (Servidor)registry.lookup("Servidor");  
			op = stub.getOperacoes();
			long tempoInicio = System.currentTimeMillis();
			System.out.println("Resposta: " + op.Fatorial(50000));
			System.out.println("Tempo Total: "+(System.currentTimeMillis()-tempoInicio) / 1000);
			System.out.println("Resposta: " + op.Soma(10, 30));
		}catch(RemoteException Re) {
			Re.printStackTrace();
		}catch(NotBoundException NBe) {
			NBe.printStackTrace();
		}
	}
}