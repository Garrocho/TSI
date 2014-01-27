package com.example.listausuarios;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class ActivityUsuarios extends Activity {

	public void criaLista() {
		ListView listaUsuarios = (ListView) findViewById(R.id.lista);
		ArrayList<Usuario> usuarios = getIntent().getParcelableArrayListExtra(
				"usuarios");
		List<String> nomes = new ArrayList<String>();
		for (Usuario usu : usuarios) {
			nomes.add(usu.getNome() + " - " + usu.getEmail());
		}
		ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
				android.R.layout.simple_list_item_1, nomes);
		listaUsuarios.setAdapter(adapter);
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_lista_usuarios);
		criaLista();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.lista_usuarios, menu);
		return true;
	}

	public void mudarTelaPrincipal(View view) {
		Intent intent = new Intent(this, MainActivity.class);
		startActivity(intent);
	}

}
