package com.example.listausuarios;

import java.util.ArrayList;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	private Database database;
	private EditText editorNome;
	private EditText editorEmail;
	private ArrayList<Usuario> usuarios = new ArrayList<Usuario>();
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		database = new Database(this);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		database.clear();
		database.close();
	}
	
	public void cadastrarUsuario(View view){
		editorNome = (EditText) findViewById(R.id.campoNome);
		editorEmail = (EditText) findViewById(R.id.campoEmail);
		String nome = editorNome.getText().toString();
		String email = editorEmail.getText().toString();
		Usuario usuario = new Usuario(nome,email);
		database.insert(usuario);
		Toast.makeText(this, "Usuário inserido!", Toast.LENGTH_LONG).show();
	}

	public void mudarTelaLista(View view){
		Intent intent = new Intent(this, ActivityUsuarios.class);
		usuarios = database.getAll();
		intent.putParcelableArrayListExtra("usuarios", usuarios);
		startActivity(intent);
	}
}
