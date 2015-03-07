#include <stdio.h>

int main() {

	int d, t, campo[30][30], tempo = 0, i, j, flag = 0;
	char posicao = 'l';
	
	/* d - dimensao do campo.
	   t - tempo maximo.
	   campo - matriz que representa o campo.
	   tempo - conta o tempo necessario para o plano dar certo ou errado.
	   I e J - contadores da linha e coluna, respectivamente.
	   flag - sinal.
	   posicao - guarda a direcao em que o personagem esta virado. */
	
	/* Abaixo a entrada eh guardada em uma matriz e o valor de D e T eh lido. */
	
	scanf("%d %d", &d, &t);
	
	for(i = 0; i < d; i++)
		for(j = 0; j < d; j++)
			scanf("%d", &campo[i][j]);
	
	/* O loop abaixo tem como funcao ler cada posicao da matriz, realizando os
	   movimentos, por meio da mudanca do valor do contador das linhas ou colunas
	   e imprime uma mensagem dependendo da posicao da matriz que for lida. A
	   variavel flag eh 0 quando a leitura do campo ainda esta sendo feita e eh 
	   igual a 1 quando ja se sabe se Oliver morreu  ou conseguiu cumprir seu objetivo.
	   Vale lembrar que os movimentos dependem da posicao de Oliver e do tipo da
	   posicao da matriz, por isso pra cada combinacao de POSICAO, I e J ha um
	   movimento diferente. */
	
	i = 0;
	j = 0;
	while (flag == 0) {
		if((i < d && i >= 0) && (j < d && j >= 0)) {
			if(campo[i][j] == 0) {
				campo[i][j] = 1;
				if (posicao == 'l')
					j++;
				else if (posicao == 'o')
					j--;
				else if (posicao == 'n')
					i--;
				else
					i++;
			}	
			else if (campo[i][j] == 1) {
				campo[i][j] = 2;
				if (posicao == 'l') {
					posicao = 'n';
					i--;
				}
				else if (posicao == 'o') {
					posicao = 's';
					i++;
				}
				else if (posicao == 'n') {
					posicao = 'o';
					j--;
				}
				else {
					posicao = 'l';
					j++;
				}
			}
			else if( campo[i][j] == 2) {
				campo[i][j] = 0;
				if(posicao == 'l') {
					posicao = 's';
					i++;
				}
				else if (posicao == 'o') {
					posicao = 'n';
					i--;
				}
				else if (posicao == 'n') {
					posicao = 'l';
					j++;
				}
				else {
					posicao = 'o';
					j--;
				}
			}
			else if(campo[i][j] == 3) {
				flag = 1;
				printf("Oliver morre\n");
			}
			else {
				flag = 1;
				printf("Oliver destroi o dispositivo em %d segundos\n", tempo);
			}
			tempo++;
			if(tempo > t - 1 && flag == 0) {
				flag = 1;
				printf("Oliver nao chega ao dispositivo a tempo\n");
			}	
		}
		else {
			printf("Oliver morre\n");
			flag = 1;
		}
	}
	return 0;
}
