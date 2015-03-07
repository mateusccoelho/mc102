/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 06b - Fruit Crush Saga - Part II
*/

#include <stdio.h>

/* Protoripo de funcoes.
   A funcao jogada conputa os pontos obtidos e marca com um X as frutas 
   atingidas pela jogada. A funcao gravidade elimina os X fazendo as frutas
   acimas das atingidas pela jogada cairem no tabuleiro. */

int jogada(int i, int j);
void gravidade();

/* Variaveis globais. m eh a quantidade de linhas do tabuleiro e n eh a
   quantidade de colunas do tabuleiro. tab eh a matriz do tabuleiro. */ 

int m, n;
char tab[51][51];

int main () {

	/* njogadas - numero de jogadas a serem realizadas.
	   i, j - coordenadas do ponto no tabuleiro a ser jogado.
	   cont - contador.
	   pontos - conta os pontos obtidos nas jogadas. */
	
	int njogadas, i, j, cont = 0, pontos = 0;
	
	/* Leitura de dados. */

	scanf("%d %d %d", &m, &n, &njogadas);
	
	while (cont < m) {
		scanf("%s", tab[cont]);
		cont++;
	}
	
	/* O loop abaixo le as coordenadas do ponto alvo de cada jogada, executa a jogada
	   e soma os pontos de cada jogada. */
	
	cont = 0;
	while (cont < njogadas) {
		scanf("%d %d", &i, &j);
		if (tab[i - 1][j - 1] != '.') {
			pontos = pontos + jogada(i, j);
			gravidade ();
		}
		cont++;	
	}

	/* Saida de dados. */
	
	printf("Score: %d\n", pontos);
	
	cont = 0;
	while (cont < m) {
		printf("%s\n", tab[cont]);
		cont++;
	}
	
	return 0;
}

int jogada(int i, int j) {
	
    /* cont - contador.
       pontos - vai contando os pontos ganhos na jogada. */
    
    int cont = 0, pontos = 0;
    
  	/* O loop abaixo testara se as frutas a direita da fruta i, j sao iguais 
  	   a esta. Caso seja, a fruta testada sera transformada em X e a variavel
  	   pontos sera acrescida em uma unidade. */
    
    cont = 0;
    while (tab[i - 1][j - 1] == tab[i - 1][j + cont] && (j + cont) < n) {
		tab[i - 1][j + cont] = 'X';
		cont++;
		pontos++;   		    	
    }
        
    
    /* O loop abaixo faz o mesmo que o anterior, mas verificando os numeros
       para o lado esquerdo. */
    
    cont = 0;
    while (tab[i - 1][j - 1] == tab[i - 1][j - 2 + cont] && (j - 2 + cont) >= 0) {
		tab[i - 1][j - 2 + cont] = 'X';
		cont--;
		pontos++;    		    	
    } 
    
    /* O loop abaixo faz o mesmo que o anterior, mas verificando os numeros
       para cima. */
	
    cont = 0;
    while (tab[i - 1][j - 1] == tab[i - 2 + cont][j - 1] && (i - 2 + cont) >= 0) {
		tab[i - 2 + cont][j - 1] = 'X';
		cont--;
		pontos++;    	    	
    } 

	/* O loop abaixo faz o mesmo que o anterior, mas verificando os numeros
	   para baixo. */
	
	cont = 0;
    while (tab[i - 1][j - 1] == tab[i + cont][j - 1] && (i + cont) < m) {
		tab[i + cont][j - 1] = 'X';
		cont++;
		pontos++;   	    	
    }
    
    /* Abaixo eh adicionado um ponto porque anteriormente nao foi computado a
       posicao i, j. Tambem eh mudado o numero da posicao i, j para X. */
    
    pontos++;
    tab[i - 1][j - 1] = 'X';   

	/* A funcao retorna a quantidade de pontos ganhos na jogada. */	
	
	return pontos * pontos;

}

void gravidade() {
	
	/* x, y e cont sao contadores. */
	
	int x, y, cont;
	
	/* A estrutura abaixo percorre todo o tabuleiro em busca de X. Se encontrar,
	   o X some e as frutas da coluna em que o X estava caem no tabuleiro. */
	
	while (y < m) {
		while (x < n) {
			if (tab[y][x] == 'X') {
				cont = 0;
				while (y + cont > 0) {
					tab[y + cont][x] = tab[y - 1 + cont][x];
					cont--;
				}
				tab[0][x] = '.';		
			}
			x++;
		}
		y++;
		x = 0;
	}
}
