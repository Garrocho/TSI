package com.example.listausuarios;

import android.os.Parcel;
import android.os.Parcelable;

public class Usuario implements Parcelable {
	/**
	 * 
	 */
	private String nome, email;

	public Usuario() {
		this.nome = "";
		this.email = "";
	}
	
	public Usuario(Parcel in){
		this.nome = in.readString();
		this.email = in.readString();
	}

	public Usuario(String nome, String email) {
		this.nome = nome;
		this.email = email;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	@Override
	public int describeContents() {
		// TODO Auto-generated method stub
		return this.hashCode();
	}

	@Override
	public void writeToParcel(Parcel dest, int flags) {
		dest.writeString(nome);
		dest.writeString(email);
	}

	@SuppressWarnings("rawtypes")
	public static final Parcelable.Creator CREATOR = new Parcelable.Creator() {

		@Override
		public Usuario createFromParcel(Parcel in) {
			// TODO Auto-generated method stub
			return new Usuario(in);
		}

		@Override
		public Usuario[] newArray(int size) {
			// TODO Auto-generated method stub
			return new Usuario[size];
		}

	};
}
