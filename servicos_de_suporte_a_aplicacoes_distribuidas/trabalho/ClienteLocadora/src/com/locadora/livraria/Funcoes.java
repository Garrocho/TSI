package com.locadora.livraria;

import javax.naming.InitialContext;


import com.locadora.gerencia.Gerenciador;
import com.locadora.menu.Menu;


public class Funcoes {

	public static void main(String[] args) throws Exception {
		Menu clienteFuncoes = new Menu();

		InitialContext ic = new InitialContext();
		Gerenciador g = (Gerenciador) ic
				.lookup("GerenciadorVideoLocadora/remote");

		int opcaoMenu;
		do {
			opcaoMenu = clienteFuncoes.menu();
			int opcaoMenu2;
			switch (opcaoMenu) {
			case 1:
				do {
					opcaoMenu2 = clienteFuncoes.menuDiretor();
					switch (opcaoMenu2) {
					case 1:
						clienteFuncoes.cadastroDiretor(g);
						break;
					case 2:
						clienteFuncoes.associaDiretorFilme(g);
						break;
					case 3:
						clienteFuncoes.filmesDiretor(g);
						break;
					case 4:
						clienteFuncoes.deletaDiretor(g);
						break;
					case 5:
						break;
					default:
						System.out.println("Opção inválida!");
					}
					System.out.println("\n");
				} while (opcaoMenu2 != 5);
				break;
			case 2:
				do {
					opcaoMenu2 = clienteFuncoes.menuFilme();
					switch (opcaoMenu2) {
					case 1:
						clienteFuncoes.cadastroFilme(g);
						break;
					case 2:
						clienteFuncoes.exemplarFilme(g);
						break;
					case 3:
						clienteFuncoes.filmeID(g);
						break;
					case 4:
						clienteFuncoes.filmeNome(g);
						break;
					case 5:
						clienteFuncoes.diretoresFilme(g);
						break;
					case 6:
						clienteFuncoes.exemplaresDispFilme(g);
						break;
					case 7:
						clienteFuncoes.filmeGeneroAno(g);
						break;
					case 8:
						break;
					default:
						System.out.println("Opção inválida!");
					}
					System.out.println("\n");
				} while (opcaoMenu2 != 8);
				break;
			case 3:
				do {
					opcaoMenu2 = clienteFuncoes.menuCliente();
					switch (opcaoMenu2) {
					case 1:
						clienteFuncoes.cadastroCliente(g);
						break;
					case 2:
						clienteFuncoes.clienteID(g);
						break;
					case 3:
						clienteFuncoes.clienteNome(g);
						break;
					case 4:
						break;
					default:
						System.out.println("Opção inválida!");
					}
					System.out.println("\n");
				} while (opcaoMenu2 != 4);
				break;
			case 4:
				do {
					opcaoMenu2 = clienteFuncoes.menuEmprestimo();
					switch (opcaoMenu2) {
					case 1:
						clienteFuncoes.cadastroEmprestimo(g);
						break;
					case 2:
						clienteFuncoes.terminaEmprestimo(g);
						break;
					case 3:
						break;
					default:
						System.out.println("Opção inválida!");
					}
					System.out.println("\n");
				} while (opcaoMenu2 != 3);
				break;
			case 0:
				break;
			default:
				System.out.println("Opção inválida!");
			}
			System.out.println("\n");
		} while (opcaoMenu != 0);
	}
}