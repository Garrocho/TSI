import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;

import com.google.gson.Gson;

public class exercicio_02 {

	public static Institutos BuscaInstituto(String arq) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(arq));
			Institutos instituto = new Gson().fromJson(in, Institutos.class);
			in.close();
			return instituto;
		} catch (IOException e) {
			System.err.println("Erro ao abrir o arquivo.");
		}
		return null;
	}

	public static void main(String args[]) {
		Institutos instituto = BuscaInstituto("./teste.txt");
		System.out.println(instituto.toString());
	}
}

class Institutos {
	private String Nome;
	private String Local;
	private Map<String, Turma[]> Turmas;

	public String toString() {
		return "Nome: " + Nome + "\nLocal: " + Local + "\nTurma: " + Turmas.get("2011")[0].toString();
	}
}

class Turma {
	private String Nome;
	private String Professor;
	private Map<String, String> Alunos[];
	
	public String toString() {
		return "Turma: " + Nome + "\nProfessor: " + Professor + "\nAluno: " + Alunos[0].get("Nome") + "\nNota: " + Alunos[0].get("Nota");
	}
}
