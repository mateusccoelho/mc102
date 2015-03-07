/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 13b - Fruit Crush Saga - Part III
*/

#include <stdio.h>

/* A funcao gravidade tem como objetivo aplicar o efeito da gravidade
   e contar quantas frutas podem ser removidas. */
int gravidade(char tab[51][51], int m, int n) {

	/* i, j, k sao contadores.  */
	int i, j, k, frutas = 0, gelo;

	/* Percorre todo o tabuleiro em busca de X. */
	for(j = 0; j < n; j++) {
		for(i = 0; i < m; i++) {
			if (tab[i][j] == 'X') {
				frutas++;
				/* Faz os caracteres de uma coluna serem movidos pra baixo ate 
				   chegar ao topo da tabela ou achar um gelo. */
				for(k = -1, gelo = 0; i + k >= 0 && gelo == 0; k--) {
					if(tab[i + k][j] == '*') 
						gelo = 1;
					else
						tab[i + k + 1][j] = tab[i + k][j];
				}
				/* Se chegar num gelo, sera posto um '.' embaixo do gelo.
				   Se chegar ao topo da tabela, sera posto um '.' na */
				if (gelo == 1)
					tab[i + k + 2][j] = '.';
				else
					tab[0][j] = '.';		
			}
		}
	}
	return frutas;
}

/* A funcao verifica a vizinhanca de uma fruta procurando outras frutas do mesmo tipo. */
void verificarVizinhanca(char tab[51][51], int m, int n, int i, int j, char aux) {
	 /* A fruta de origem sera mudada para o caractere X, a fim de indicar 
	    que ela pode ser removida. */
    tab[i - 1][j - 1] = 'X';

    /* O trecho abaixo faz a verificacao da vizinhanca direita */
    if(aux == tab[i - 1][j] && j < n)
    	verificarVizinhanca(tab, m, n, i, j + 1, aux);
	
	/* Esquerda */
    if(aux == tab[i - 1][j - 2] && j - 2 >= 0)
    	verificarVizinhanca(tab, m, n, i, j - 1, aux);
	
	/* Baixo */
    if(aux == tab[i][j - 1] && i < m)
    	verificarVizinhanca(tab, m, n, i + 1, j, aux);

	/* Cima */
    if(aux == tab[i - 2][j - 1] && i - 2 >= 0)
    	verificarVizinhanca(tab, m, n, i - 1, j, aux);
}

int main() {

	/* njogadas - numero de jogadas a serem realizadas.
	   i, j - coordenadas do ponto no tabuleiro a ser jogado.
	   cont - contador.
	   pontos - conta os pontos obtidos nas jogadas.
	   frutas - guarda a quantidade de frutas que podem ser removidas.
	   tab - tabela das frutas.
	   aux - numero DA fruta que deve ser removida em todo o tabuleiro.  */
	
	int njogadas, i, j, cont = 0, pontos = 0, frutas, m, n;
	char tab[51][51], aux;
	
	/* Leitura de dados. */
	scanf("%d %d %d", &m, &n, &njogadas);
	
	for(cont = 0; cont < m; cont++)
		scanf("%s", tab[cont]);
	
	/* le as coordenadas do ponto alvo, executa a jogada
	   e soma os pontos. */
	for(cont = 0; cont < njogadas; cont++) {
		scanf("%d %d", &i, &j);
		if (tab[i - 1][j - 1] != '.' && tab[i - 1][j - 1] != '*') {
			aux = tab[i - 1][j - 1];
			verificarVizinhanca(tab, m, n, i, j, aux);
			/* Atualizacao do tabuleiro. */
			frutas = gravidade(tab, m, n);
			pontos += frutas * frutas;
		}
	}

	/* Saida de dados. */
	printf("Score: %d\n", pontos);
	for(cont = 0; cont < m; cont++)
		printf("%s\n", tab[cont]);
	
	return 0;
}
