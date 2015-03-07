/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 06a - Fruit Crush Saga - Part 1
*/


#include <stdio.h>

int main () {
    
    /*Lista de variaveis
      m - numero de linhas do tabuleiro.
      n - numero de colunas do tabuleiro.
      i - indica a linha do ponto a ser analisado.
      j - indica a coluna do ponto a ser analisado.
      x e y - contadores que percorrem, respectivamente, as linhas e as colunas.
      pontos - conta quantos lugares serao eliminados.
      tab - matriz do campo de jogo.
    */
    
    int m, n, i, j, x = 0, y = 0, pontos = 0;
    char tab[51][51];
    
    /* Leitura de variaveis e do tabuleiro */
    
    scanf ("%d %d %d %d", &m, &n, &i, &j);
    
    while (y < m) {
        scanf("%s", tab[y]);
        y++;
    }
    
    /* A condicional a seguir verifica se ha elementos iguais ao elemento da posicao i, j na direita. 
       Caso tenha, um loop sera criado para verificar se as proximas posicoes aa direita tambem sao 
       iguais ao elemento i, j e mudar os numeros para a letra X.  */
    
    y = 0;
    
    if (tab[i - 1][j - 1] == tab[i - 1][j]) {
    	pontos++;
    	tab[i - 1][j] = 'X';
    	do {
			tab[i - 1][j + y] = 'X';
			y++;
			pontos++;   		    	
    	} while (tab[i - 1][j - 1] == tab[i - 1][j + y] && (j + y) < n); 
        pontos--;
    
    }
    
    /* O loop abaixo faz o mesmo que o anterior, mas verificando os numeros para o lado esquerdo. */
    
    y = 0;
    
    if (tab[i - 1][j - 1] == tab[i - 1][j - 2]) {
    	pontos++;
    	tab[i - 1][j - 2] = 'X';
    	do {
			tab[i - 1][j - 2 + y] = 'X';
			y--;
			pontos++;    		    	
    	} while (tab[i - 1][j - 1] == tab[i - 1][j - 2 + y] && (j - 2 + y) >= 0); 
    
        pontos--;
    
    }
    
    /* O loop abaixo faz o mesmo que o anterior, mas verificando os numeros para cima. */
	
    x = 0;
    
    if (tab[i - 1][j - 1] == tab[i - 2][j - 1]) {
    	pontos++;
    	tab[i - 2][j - 1] = 'X';
    	do {
			tab[i - 2 + x][j - 1] = 'X';
			x--;
			pontos++;    	    	
    	} while (tab[i - 1][j - 1] == tab[i - 2 + x][j - 1] && (i - 2 + x) >= 0); 
    
        pontos--;
    
    }

	/* O loop abaixo faz o mesmo que o anterior, mas verificando os numeros para baixo. */
	
	x = 0;
    
    if (tab[i - 1][j - 1] == tab[i][j - 1]) {
    	pontos++;
    	tab[i][j - 1] = 'X';
    	do {
			tab[i + x][j - 1] = 'X';
			x++;
			pontos++;   	    	
    	} while (tab[i - 1][j - 1] == tab[i + x][j - 1] && (i + x) < m); 
    
        pontos--;
    
    }
    
    /* Abaixo eh adicionado um ponto porque anteriormente nao foi computado a posicao i, j. Tambem eh mudado o numero da posicao i, j para X. */
    
    pontos++;
    
    tab[i - 1][j - 1] = 'X';
    
    /* Saida de dados. */
    
    printf("Score: %d\n", pontos * pontos);
    
    x = 0;
    y = 0;
    
    while (y < m) {
    	printf("%s\n", tab[y]);
    	y++;
    }

return 0;

}





        

