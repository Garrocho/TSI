package br.edu.ifsudestemg.ssad.beans;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import javax.ejb.Remote;
import javax.ejb.Stateless;

import org.jboss.monitor.services.TimerService;

import br.edu.ifsudestemg.ssad.session.CotadorMoeda;

@Stateless
@Remote(CotadorMoeda.class)
public class CotadorMoedaBeans implements CotadorMoeda{

	private double fatorDeCotacao=1.71;

	@Resource
	private TimerService timerService;

	@PostConstruct
	public void inicializa(){
		timerService.createTimer(3000L, "timeout");
	}

	@Override
	public double fazCotacao(String moedaOrigem, String moedaDestino, double quantia){
		if("dollar".equals(moedaOrigem) && "real".equals(moedaDestino))
			return quantia * fatorDeCotacao;
		return 0;
	}
}