import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;


public class ServidorImpl implements Servidor {
	private Operacoes obj;

	public ServidorImpl() {
		obj = new Operacoes();
		inicia();
	}  

	public Operacoes getOperacoes() {  
		return obj;
	}
	
	public void inicia() {  
		try {  
			Servidor stub = (Servidor) UnicastRemoteObject.exportObject(this, 0);  
			Registry registry = LocateRegistry.createRegistry(6666);
			registry.bind("Servidor", stub);
			System.out.println("Servidor iniciado");    
		}catch(RemoteException Re) {  
			System.out.println(Re.getMessage());  
		} catch (AlreadyBoundException e) {
			e.printStackTrace();
		}
	}  

	public static void main(String args[]) {    
		new ServidorImpl();
	}
}  