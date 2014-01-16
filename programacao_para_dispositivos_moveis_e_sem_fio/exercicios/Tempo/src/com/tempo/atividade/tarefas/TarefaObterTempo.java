package com.tempo.atividade.tarefas;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;

import android.os.AsyncTask;
import android.util.Log;
import android.widget.TextView;

public class TarefaObterTempo extends AsyncTask<String, Integer, String> {
	
	private String resultado = "nada";
	private TextView texto;
	
	public TarefaObterTempo(TextView texto) {
		this.texto = texto;
	}
	
	@Override
	protected String doInBackground(String... arg0) {
		
		DefaultHttpClient httpCliente = new DefaultHttpClient();

		HttpGet request = new HttpGet("http://www.previsaodotempo.org/api.php");
		request.getParams().setParameter("city", "Barbacena");
		try {
			HttpResponse response = httpCliente.execute(request);
			
			HttpEntity httpEntity = response.getEntity();
			resultado = EntityUtils.toString(httpEntity);
			Log.d("HTML", resultado);
		}catch(Exception error) {
			error.printStackTrace();
		}
		return resultado;
	}

	@Override
	protected void onPostExecute(String result) {
		texto.setText(result);
		super.onPostExecute(result);
	}
}
