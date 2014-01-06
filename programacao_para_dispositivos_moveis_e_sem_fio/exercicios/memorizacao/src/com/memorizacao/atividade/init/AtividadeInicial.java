package com.memorizacao.atividade.init;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

import android.app.Activity;
import android.graphics.Color;
import android.graphics.PorterDuff.Mode;
import android.graphics.PorterDuffColorFilter;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.widget.ImageView;
import android.widget.ProgressBar;

import com.memorizacao.R;

public class AtividadeInicial extends Activity {

	private ProgressBar barraProgresso;
	private ImageView um, dois, tres, quatro, cinco, seis;
	private int progresso;
	private View background;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.atividade_inicial);

		barraProgresso = (ProgressBar)findViewById(R.id.atividade_inicial_barra_progresso);
		barraProgresso.getProgressDrawable().setColorFilter(new PorterDuffColorFilter(Color.RED, Mode.MULTIPLY));

		progresso = 0;
		barraProgresso.setProgress(progresso);

		background = this.getWindow().getDecorView();

		um = (ImageView)findViewById(R.id.atividade_inicial_imagem_um);
		dois = (ImageView)findViewById(R.id.atividade_inicial_imagem_dois);
		tres = (ImageView)findViewById(R.id.atividade_inicial_imagem_tres);
		quatro = (ImageView)findViewById(R.id.atividade_inicial_imagem_quatro);
		cinco = (ImageView)findViewById(R.id.atividade_inicial_imagem_cinco);
		seis = (ImageView)findViewById(R.id.atividade_inicial_imagem_seis);
	}

	public void gerarSequencia() {
		Random gerador = new Random(19700621);
		boolean sair;
		int[] numeros = new int[6];
		int contador = 0;
		for (int i = 0; i < numeros.length; i++) {
			sair = false;
			while (!sair) {
				sair = true;
				int numero = gerador.nextInt(6);
				for (int k =0; k < contador; k++) {
					if (numero == numeros[k]) {
						sair = false;
					}
				}
				if (sair)
					numeros[contador++] = numero+1;
			}
		}
		for (int g= 0; g < numeros.length; g++) {
			Log.d("numeros", String.valueOf(numeros[g]));
		}
	}

	public void reiniciar(View componente) {
		progresso = 0;
		barraProgresso.setProgress(progresso);
		um.setVisibility(View.VISIBLE);
		dois.setVisibility(View.VISIBLE);
		tres.setVisibility(View.VISIBLE);
		quatro.setVisibility(View.VISIBLE);
		cinco.setVisibility(View.VISIBLE);
		seis.setVisibility(View.VISIBLE);
		background.setBackgroundColor(Color.WHITE);
		gerarSequencia();
	}

	public void um(View componente) {
		progresso += 17;
		barraProgresso.setProgress(progresso);
		um.setVisibility(View.GONE);
		background.setBackgroundColor(Color.BLUE);
	}

	public void dois(View componente) {
		progresso += 17;
		barraProgresso.setProgress(progresso);
		dois.setVisibility(View.GONE);
		background.setBackgroundColor(Color.RED);
	}

	public void tres(View componente) {
		progresso += 17;
		barraProgresso.setProgress(progresso);
		tres.setVisibility(View.GONE);
		background.setBackgroundColor(Color.GREEN);
	}

	public void quatro(View componente) {
		progresso += 17;
		barraProgresso.setProgress(progresso);
		quatro.setVisibility(View.GONE);
		background.setBackgroundColor(Color.YELLOW);
	}

	public void cinco(View componente) {
		progresso += 17;
		barraProgresso.setProgress(progresso);
		cinco.setVisibility(View.GONE);
		background.setBackgroundColor(Color.GRAY);
	}

	public void seis(View componente) {
		progresso += 17;
		barraProgresso.setProgress(progresso);
		seis.setVisibility(View.GONE);
		background.setBackgroundColor(Color.DKGRAY);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.atividade_inicial, menu);
		return true;
	}
}
