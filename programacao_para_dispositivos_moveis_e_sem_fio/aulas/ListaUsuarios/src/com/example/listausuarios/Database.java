package com.example.listausuarios;

import java.util.ArrayList;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class Database {
	private static final String DATABASE_NAME = "usuarios";
	private static final int DATABASE_ACCESS = 0;
	private static final String SQL_STRUCT = "CREATE TABLE IF NOT EXISTS usuario (" +
			" id_ INTEGER PRIMARY KEY AUTOINCREMENT, nome TEXT NOT NULL, email TEXT NOT NULL);";
	private static final String SQL_INSERT = "INSERT INTO usuario (nome,email) VALUES ('%s','%s');";
	private static final String SQL_SELECT_ALL = "SELECT * FROM usuario ORDER BY nome;";
	private static final String SQL_CLEAR = "DROP TABLE IF EXISTS usuario;";

	private SQLiteDatabase database;
	private Cursor cursor;
	private int indexID, indexNome, indexEmail;

	public Database(Context context) {
		database = context.openOrCreateDatabase(DATABASE_NAME, DATABASE_ACCESS,
				null);
		database.execSQL(SQL_STRUCT);
	}
	
	public void clear(){
		database.execSQL(SQL_CLEAR);
	}
	
	public void close(){
		database.close();
	}
	
	public void insert(Usuario usuario){
		String query = String.format(SQL_INSERT, usuario.getNome(),usuario.getEmail());
		database.execSQL(query);
	}
	
	public ArrayList<Usuario> getAll(){
		ArrayList<Usuario> usuarios = new ArrayList<Usuario>();
		Usuario usuario;
		
		cursor = database.rawQuery(SQL_SELECT_ALL, null);
		if (cursor.moveToFirst()){
			indexID = cursor.getColumnIndex("id_");
			indexNome = cursor.getColumnIndex("nome");
			indexEmail = cursor.getColumnIndex("email");
			do {
				usuario = new Usuario(cursor.getString(indexNome),cursor.getString(indexEmail));
				usuarios.add(usuario);
			} while (cursor.moveToNext());
		}
		cursor.close();
		return usuarios;
	}
	
}
