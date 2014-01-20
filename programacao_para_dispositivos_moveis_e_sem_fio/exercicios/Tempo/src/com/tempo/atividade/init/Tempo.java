package com.tempo.atividade.init;

import java.util.concurrent.ExecutionException;

import android.app.Activity;
import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.tempo.R;
import com.tempo.tarefas.TarefaObterTempo;

public class Tempo extends Activity {
	
	private TextView texto;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.atividade_tempo);
		texto = (TextView)findViewById(R.id.textView1);
		//obterTempo(null);
	}
	
	public void obterTempo(View componente) throws InterruptedException, ExecutionException {
		if (verificaConexao(this)) {
			TarefaObterTempo tarefa = new TarefaObterTempo(texto);
			tarefa.execute("");
		}
		else
			texto.setText("Sem Conexao com Internet");
	}
	
	public static boolean verificaConexao(Context contexto) {
		ConnectivityManager cn = (ConnectivityManager)contexto.getSystemService(Context.CONNECTIVITY_SERVICE);
		NetworkInfo infoRede = cn.getActiveNetworkInfo();

		if(infoRede != null && infoRede.isConnected()){
			return true;
		}
		else{
			return false;
		}
	}
}
