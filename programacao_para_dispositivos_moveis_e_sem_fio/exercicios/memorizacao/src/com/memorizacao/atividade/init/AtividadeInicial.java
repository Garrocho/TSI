package com.memorizacao.atividade.init;

import android.app.Activity;
import android.graphics.Color;
import android.graphics.PorterDuff.Mode;
import android.graphics.PorterDuffColorFilter;
import android.os.Bundle;
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
		progresso = 0;
		barraProgresso.setProgress(progresso);
		um.setVisibility(View.VISIBLE);
		dois.setVisibility(View.VISIBLE);
		tres.setVisibility(View.VISIBLE);
		quatro.setVisibility(View.VISIBLE);
		cinco.setVisibility(View.VISIBLE);
		seis.setVisibility(View.VISIBLE);
		background.setBackgroundColor(Color.WHITE);
		vetorSequencias = gerarSequencia();
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
