import java.rmi.Remote;
import java.rmi.RemoteException;


public interface Servidor extends Remote {  
	public Operacoes getOperacoes() throws RemoteException;  
} 
