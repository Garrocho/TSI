package com.memorizacao.atividade.init;

import android.app.Activity;
import android.graphics.Color;
import android.graphics.PorterDuff.Mode;
import android.graphics.PorterDuffColorFilter;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.animation.AccelerateInterpolator;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.DecelerateInterpolator;
import android.view.animation.LinearInterpolator;
import android.view.animation.RotateAnimation;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.memorizacao.R;

public class CapMem extends Activity {

	private ProgressBar barraProgresso;
	private ImageView reiniciar, um, dois, tres, quatro, cinco, seis;
	private int progresso, contador;
	private View background;
	private TextView rotuloParabens, rotuloVoceTem, rotuloProgresso;
	private int[] vetorSequencias;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.atividade_inicial);
		
		reiniciar = (ImageView)findViewById(R.id.atividade_inicial_imagem_reiniciar);

		rotuloParabens = (TextView)findViewById(R.id.atividade_inicial_rotulo_parabens);
		rotuloVoceTem = (TextView)findViewById(R.id.atividade_inicial_rotulo_voce_tem);
		rotuloProgresso = (TextView)findViewById(R.id.atividade_inicial_rotulo_progresso);
		
		rotuloParabens.setVisibility(View.GONE);
		rotuloVoceTem.setVisibility(View.GONE);
		
		barraProgresso = (ProgressBar)findViewById(R.id.atividade_inicial_barra_progresso);
		barraProgresso.getProgressDrawable().setColorFilter(new PorterDuffColorFilter(Color.RED, Mode.MULTIPLY));

		progresso = 0;
		contador = 0;
		barraProgresso.setProgress(progresso);

		background = this.getWindow().getDecorView();

		um = (ImageView)findViewById(R.id.atividade_inicial_imagem_um);
		dois = (ImageView)findViewById(R.id.atividade_inicial_imagem_dois);
		tres = (ImageView)findViewById(R.id.atividade_inicial_imagem_tres);
		quatro = (ImageView)findViewById(R.id.atividade_inicial_imagem_quatro);
		cinco = (ImageView)findViewById(R.id.atividade_inicial_imagem_cinco);
		seis = (ImageView)findViewById(R.id.atividade_inicial_imagem_seis);
		
		vetorSequencias = gerarSequencia();
	}

	public int[] gerarSequencia() {
		int valor;  
		int vetor[] = new int[6];  
		boolean Salvar = false;  

		for (int i = 0; i < 6 ; i++){  
			valor = 1 + (int) (Math.random()*6);   
			Salvar = true ;  
			for (int y=0;y<=i;y++ ){  
				if (vetor[y] == valor){  
					Salvar = false;  
					i--;  
				}  
			}   
			if (Salvar){                            
				vetor[i] = valor;
			}                                               
		}
		return vetor;
	}

	public void reiniciar(View componente) {
		if (componente != null) {
			vetorSequencias = gerarSequencia();
			barraProgresso.setVisibility(View.VISIBLE);
			rotuloProgresso.setVisibility(View.VISIBLE);
			rotuloParabens.setVisibility(View.GONE);
			rotuloVoceTem.setVisibility(View.GONE);
		}
		RotateAnimation anim = new RotateAnimation(0, 360, Animation.RELATIVE_TO_SELF, 0.5f, Animation.RELATIVE_TO_SELF, 0.5f);
		anim.setInterpolator(new LinearInterpolator());
		anim.setDuration(500);
		reiniciar.startAnimation(anim);
		restauraComponente(um);
		restauraComponente(dois);
		restauraComponente(tres);
		restauraComponente(quatro);
		restauraComponente(cinco);
		restauraComponente(seis);
		progresso = 0;
		contador = 0;
		barraProgresso.setProgress(progresso);
		background.setBackgroundColor(Color.WHITE);
	}
	
	public void restauraComponente(View componente) {
		componente.setEnabled(true);
		Animation fadeIn = new AlphaAnimation(0, 1);
	    fadeIn.setInterpolator(new DecelerateInterpolator());
	    fadeIn.setDuration(1500);
	    componente.setAnimation(fadeIn);
		componente.setVisibility(View.VISIBLE);
	}
	
	public void animaComponente(View componente) {
		componente.setEnabled(false);
		Animation fadeOut = new AlphaAnimation(1, 0);
	    fadeOut.setInterpolator(new AccelerateInterpolator());
	    fadeOut.setDuration(1000);
	    componente.setAnimation(fadeOut);
		progresso += 17;
		barraProgresso.setProgress(progresso);
		componente.setVisibility(View.GONE);
		if (contador == vetorSequencias.length) {
			rotuloParabens.setVisibility(View.VISIBLE);
			rotuloVoceTem.setVisibility(View.VISIBLE);
			barraProgresso.setVisibility(View.GONE);
			rotuloProgresso.setVisibility(View.GONE);
		}
	}
	
	public boolean valida(int numero) {
		if (numero == vetorSequencias[contador]) {
			contador++;
			return true;
		}
		reiniciar(null);
		return false;
	}

	public void um(View componente) {
		if (valida(1)) {
			animaComponente(componente);
			background.setBackgroundColor(Color.BLUE);
		}
	}

	public void dois(View componente) {
		if (valida(2)) {
			animaComponente(componente);
			background.setBackgroundColor(Color.RED);
		}
	}

	public void tres(View componente) {
		if (valida(3)) {
			animaComponente(componente);
			background.setBackgroundColor(Color.GREEN);
		}
	}

	public void quatro(View componente) {
		if (valida(4)) {
			animaComponente(componente);
			background.setBackgroundColor(Color.YELLOW);
		}
	}

	public void cinco(View componente) {
		if (valida(5)) {
			animaComponente(componente);
			background.setBackgroundColor(Color.GRAY);
		}
	}

	public void seis(View componente) {
		if (valida(6)) {
			animaComponente(componente);
			background.setBackgroundColor(Color.DKGRAY);
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.atividade_inicial, menu);
		return true;
	}
}
