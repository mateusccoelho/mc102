#include <stdio.h>

/* Variaveis 
   p - contador de linha. 
   q - contador de coluna.
   i - posicao na linha da bomba.
   j - posicao na coluna da bomba. */

/* O objetivo eh marcar onde houve explosoes, descobrindo tambem onde outras bombas explodiram. */
void verificarBombas(char mapa[][51], int i, int j, int n, int m) {
	int raio, p, q;
	
	/* Calcula raio e troca o local da bomba por B. */
	raio = mapa[i][j] - 48;
	mapa[i][j] = 'B';
	/* Percorre o quadrado de destruicao de uma bomba verificando se as
	   posicoes do quadrado estao dentro do campo. */
	for(p = 0; i - raio + p <= i + raio; p++)
		if(i - raio + p >= 0 && i - raio + p < n)
			for(q = 0; j - raio + q <= j + raio; q++)
				if(j - raio + q >= 0 && j - raio + q < m) {
					/* Faz a verificacao do caractere e troca-o por x ou chama
					   a funcao novamente caso outra bomba seja encontrada. */
					if(mapa[i - raio + p][j - raio + q] == '.')
						mapa[i - raio + p][j - raio + q] = 'x';
					else if(mapa[i - raio + p][j - raio + q] >= 49 && mapa[i - raio + p][j - raio + q] <= 57)
						verificarBombas(mapa, i - raio + p, j - raio + q, n, m);
				}
}

/* Objetivo da funcao main eh basicamente fazer a leitura e a saida do programa. */
int main() {

	int i, j, m, n, p;
	char mapa[50][51];
	
	/* Leitura */
	scanf("%d %d %d %d", &n, &m, &i, &j);
	
	for(p = 0; p < n; p++)
		scanf("%s", mapa[p]);
	
	/* A funcao recursiva eh chamada pela primeira vez. */
	verificarBombas(mapa, i - 1, j - 1, n, m);
	
	/* Saida */
	for(p = 0; p < n; p++)
		printf("%s\n", mapa[p]);
	
	return 0;
}
