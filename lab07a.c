/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 07a - The Voice - Blind Auditions 
*/

#include <stdio.h>

int main () {
	
	/* Lista de variaveis
	   num - numero de participantes.
	   i, j, cont - contadores usados em loops.
	   flag - bandeira usada em um loop.
	   id - matriz com os dados de entrada. Cada linha corresponde a um candidato.
	   resultado - matriz que armazena em que time cada participante ficou. Cada linha da matriz, representa um time.
	 */
	
	int num, i, j, cont = 0, flag = 0;
	int id[100][8], resultado[4][100];
	
	/* Abaixo a matriz resultado eh zerada e os dados de entrada sao lidos. */
	
	for(i = 0; i <= 3; i++)
		for (j = 0; j <= 99; j++)
			resultado[i][j] = 0;
		
	scanf("%d", &num);
	
	for (i = 0; i < num; i++)
		for (j = 0; j < 8; j++)
			scanf("%d", &id[i][j]);
	
	/* O loop abaixo verificara em que time cada participante ficou, analisando
	   linha por linha a matriz. */
	
	for (i = 0; i < num; i++) {
		
		/* O loop abaixo verificara se o jurado de mais preferencia virou a cadeira.
		   Caso nao tenha virado, sera verificado se o segundo jurado de maior
		   preferencia virou a cadeia, e assim por diante ate que se tenha um
		   resultado. A flag sera zero enquanto nao houver um resultado e sera um
		   quando houver um resultado. Assim o loop pode ser encerrado.*/
		
		for (j = 4; j <= 7 && flag == 0; j++)
			if ( id[i][id[i][j] - 1] == 1) {
				resultado[id[i][j] - 1][i] = i + 1;
				flag = 1;
			}
		flag = 0;
	}		
	
	/* O loop abaixo vai imprimir a saida do programa, isto eh, a matriz
	   resultado excluindo os zeros da matriz para mostrar apenas o numeros dos
	   candidatos. */
	
	for (i = 0; i <= 3; i++) {
		printf("Time %d:", i + 1);
		for (j = 0; j < num; j++) {
			if (resultado[i][j] != 0)
				printf(" %d", resultado[i][j]);
			else
				cont++;
		}
		if (cont == num)
			printf(" Nenhum participante");
		printf("\n");
		cont = 0;
	}
	
	return 0;
}	

