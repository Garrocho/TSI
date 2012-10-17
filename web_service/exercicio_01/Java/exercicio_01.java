import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import com.google.gson.Gson;

public class exercicio_01 {

	public GitHubUser obterDadosGitHubUser(String nome) throws Exception {
		HttpURLConnection conn;
		BufferedReader rd;
		URL url = new URL("https://api.github.com/users/" + nome);
		conn = (HttpURLConnection) url.openConnection();
		conn.setRequestMethod("GET");
		if (conn.getResponseCode() == 200) {
			rd = new BufferedReader(new InputStreamReader(conn.getInputStream()));
			GitHubUser usuario = new Gson().fromJson(rd, GitHubUser.class);
			rd.close();
			return usuario;
		}
		else
			return null;
	}

	public static void main(String args[]) {
		if (args.length == 1) {
			exercicio_01 exerc = new exercicio_01();
			GitHubUser usuario = null;
			try {
				usuario = exerc.obterDadosGitHubUser(args[0]);
			} catch (Exception e) {
				System.out.println("Ocorreu um erro: " + e.getMessage());
			}
			if (usuario == null)
				System.out.println("Usuário Inexistente");
			else
				System.out.println(usuario.toString());
		}
		else
			System.out.println("Parâmetros: java exercicio_01 nome_usuario");
	}
}

class GitHubUser {
	protected String name;
	protected String email;
	protected int followers;

	public String toString() {
		return "Nome: " + name + "\nE-mail: " + email + "\nSeguidores: " + followers;
	}
}
