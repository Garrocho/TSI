import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import javax.xml.parsers.FactoryConfigurationError;

import xmlwise.XmlElement;
import xmlwise.Xmlwise;

public class parseXML {

    public parseXML() {
    }

	public static void main(String args[]) throws FactoryConfigurationError, Exception {

                parseXML parse = new parseXML();
		String cep = args[0];
		String xmlCep = parse.carregaCep(cep);
		parse.escreveArquivo(cep, xmlCep);

		XmlElement bancada = Xmlwise.loadXml(cep + ".xml");
		XmlElement resultado = bancada.getUnique("resultado");

		if (resultado.getValue().equalsIgnoreCase("1")) {
			XmlElement uf = bancada.getUnique("uf");
			XmlElement cidade = bancada.getUnique("cidade");
			XmlElement bairro = bancada.getUnique("bairro");
			XmlElement tipo_logradouro = bancada.getUnique("tipo_logradouro");
			XmlElement logradouro = bancada.getUnique("logradouro");

			System.out.println("Estado: " + uf.getValue());
			System.out.println("Cidade: " + cidade.getValue());
			System.out.println("Bairro: " + bairro.getValue());
			System.out.println("Logradouro: " + tipo_logradouro.getValue() + " " + logradouro.getValue());
		}
		else
			System.out.println("Cep Nao Encontrado");
	}

	public String carregaCep(String cep) throws Exception {

		URL url = new URL("http://cep.republicavirtual.com.br/web_cep.php?cep=" + cep);
		HttpURLConnection connection =  (HttpURLConnection) url.openConnection();  
		connection.setRequestProperty("Request-Method", "GET");
		connection.setDoInput(true);  
		connection.setDoOutput(false); 
		connection.connect(); 
		BufferedReader br = new BufferedReader(new InputStreamReader(connection.getInputStream()));
		StringBuffer dados = new StringBuffer(10000);  
		String s = "";  
		while (null != ((s = br.readLine()))) {  
			dados.append(s);  
		}  
		br.close();
		return new String(dados);  
	}

	public void escreveArquivo(String cep, String texto) {
		try {  
			File arquivo;  
			arquivo = new File(cep + ".xml");  
			FileOutputStream fos = new FileOutputStream(arquivo);  
			fos.write(texto.getBytes());  
			fos.close();  
		}  
		catch (Exception ee) {  
			ee.printStackTrace();  
		}  
	}
}
