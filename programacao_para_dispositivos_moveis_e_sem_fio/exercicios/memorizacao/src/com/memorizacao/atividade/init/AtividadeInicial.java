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

import com.memorizacao.R;

public class AtividadeInicial extends Activity {

	private ProgressBar barraProgresso;
	private ImageView um, dois, tres, quatro, cinco, seis;
	private int progresso;
	private View background;
	private int[] vetorSequencias;

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
		RotateAnimation anim = new RotateAnimation(0, 360, Animation.RELATIVE_TO_SELF, 0.5f, Animation.RELATIVE_TO_SELF, 0.5f);
		anim.setInterpolator(new LinearInterpolator());
		anim.setDuration(500);

		final ImageView compReiniciar = (ImageView) findViewById(R.id.atividade_inicial_imagem_reiniciar);
		compReiniciar.startAnimation(anim);
		
		progresso = 0;
		barraProgresso.setProgress(progresso);
		restauraComponente(um);
		restauraComponente(dois);
		
		restauraComponente(tres);
		restauraComponente(quatro);
		restauraComponente(cinco);
		restauraComponente(seis);
		cinco.setVisibility(View.VISIBLE);
		seis.setVisibility(View.VISIBLE);
		background.setBackgroundColor(Color.WHITE);
		vetorSequencias = gerarSequencia();
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
	}

	public void um(View componente) {
		animaComponente(componente);
		background.setBackgroundColor(Color.BLUE);
	}

	public void dois(View componente) {
		animaComponente(componente);
		background.setBackgroundColor(Color.RED);
	}

	public void tres(View componente) {
		animaComponente(componente);
		background.setBackgroundColor(Color.GREEN);
	}

	public void quatro(View componente) {
		animaComponente(componente);
		background.setBackgroundColor(Color.YELLOW);
	}

	public void cinco(View componente) {
		animaComponente(componente);
		background.setBackgroundColor(Color.GRAY);
	}

	public void seis(View componente) {
		animaComponente(componente);
		background.setBackgroundColor(Color.DKGRAY);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.atividade_inicial, menu);
		return true;
	}
}
