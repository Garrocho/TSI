package com.tempo.tarefas;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;
import org.json.JSONObject;

import android.os.AsyncTask;
import android.widget.TextView;

import com.tempo.classes.JsonTempo;

public class TarefaObterTempo extends AsyncTask<String, Integer, JsonTempo> {
	
	private TextView texto;
	
	public TarefaObterTempo(TextView texto) {
		this.texto = texto;
	}
	
	@Override
	protected JsonTempo doInBackground(String... arg0) {
		
		DefaultHttpClient httpCliente = new DefaultHttpClient();
		JsonTempo jsonTempo = null;

		HttpGet request = new HttpGet("http://www.previsaodotempo.org/api.php?city=Barbacena");
		try {
			HttpResponse response = httpCliente.execute(request);
			
			HttpEntity httpEntity = response.getEntity();
			String resultado = EntityUtils.toString(httpEntity);
			
			JSONObject result = new JSONObject(resultado);
            JSONObject dados = result.getJSONObject("data");
            jsonTempo = new JsonTempo(dados.getString("humidity"), dados.getString("temperature"));
		}catch(Exception error) {
			error.printStackTrace();
		}
		return jsonTempo;
	}

	@Override
	protected void onPostExecute(JsonTempo result) {
		texto.setText("Temperatura: " + result.temperatura + "\n\nHumidade: " + result.umidade);
		super.onPostExecute(result);
	}
}
