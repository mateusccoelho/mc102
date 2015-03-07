/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 09b - Concurso Publico para Professor da UNICAMP
*/

#include <stdio.h>

double calculoMedia(int j, double notas[5][30]) {
	
	/* A funcao abaixo tem como objetivo somar as notas do candidato, as quais
	   estao todas em uma coluna, e calcular a media, repassando este valor para
	   a matriz MEDIA. */
	
	int i;
	double soma = 0;
	
	for(i = 0; i < 5; i++)
		soma += notas[i][j];
	
	return (soma/5.0);
}
 
void ordenarPreferencia(int i, int k, double notas[5][30], int preferencia[5][30]) {
	
	/* A funcao tem como objetivo percorrer a matriz NOTAS e ir preenchendo a
	   a matriz PREFERENCIA com o numero do candidato com a maior nota do jurado.
	   Para isso, a linha eh percorrida e o indice da maior nota do jurado eh 
	   colocado na matriz PREFERENCIA. Alem disso, quando o indice da maior nota de
	   um jurado eh achado, a nota eh zerada pra quando a linha for percorrida 
	   novamente, tal nota ser "pulada". */
	
	int j, p, indice_maior;
	
	for(p = 0; p < k; p++) {
		indice_maior = 0;
		for(j = 1; j < k; j++) {
			if(notas[i][j] > notas[i][indice_maior])
				indice_maior = j;
			if (notas[i][j] == notas[i][indice_maior])
				if (j < indice_maior)
					indice_maior = j;
		}
		
		preferencia[i][p] = indice_maior + 1;
		notas[i][indice_maior] = 0;
	}
}

void formarClassificacao(int k, int contador[30], int preferencia[5][30], int classificacao[30], double media[30]) {
	
	/* A funcao abaixo tem como objetivo formar a classificacao do concurso,
	   definindo cada colocacao, colocando a colocacao dos candidator no vetor
	   CLASSIFICACAO e modificando a tabela de preferencias assim que
	   a colocacao de um candidato eh definida. */
	
	int i, j, l, p, indice_escolhido;
	
	/* As estruturas abaixo percorrem a cada coluna da matriz PREFERENCIAS e conta, no
	   vetor CONTADOR, quantas vezes os candidatos aparecem, sendo que o indice + 1
	   do vetor CONTADOR corresponde ao numero do candidato. Depois, eh verificado
	   qual contador eh o maior e a colocacao do candidato eh descoberta. */
	
	for(p = 0; k > p ; p++) {
		
		for(j = 0; j < k; j++)
			contador[j] = 0;
		
		for(i = 0; i < 5; i++)
			contador[preferencia[i][0] - 1]++;
		
		indice_escolhido = 0;
		for(j = 0; j < k; j++) {
			if(contador[j] > contador[indice_escolhido])
				indice_escolhido = j;
			if(contador[j] == contador[indice_escolhido]) {
				if(media[j] > media[indice_escolhido])
					indice_escolhido = j;
				if(media[j] == media[indice_escolhido])
					if(j < indice_escolhido)
						indice_escolhido = j;
			}	
		}
		
		classificacao[p] = indice_escolhido + 1;
		
		/* As estruturas abaixo tem como funcao atualizar a matriz PREFERENCIAS,
		   movendo a lista de preferencia de cada jurado para a esquerda. Para isso,
		   as linhas da matriz sao percorridas e quando o numero de um candidato, 
		   cuja classificacao acabou de ser determinada, aparecer, todos os numeros
		   a direita serao movidos uma posicao pra esquerda. */
		
		if(p < k - 1)
			for(i = 0; i < 5; i++)
				for(j = 0; j < k; j++)
					if(preferencia[i][j] == indice_escolhido + 1 && j < k - 1)
						for(l = 0; j + l + 1 < k; l++)
							preferencia[i][j + l] = preferencia[i][j + l + 1];			
	}	
	
}

int main() {

	int k, i, j, preferencia[5][30], contador[30], classificacao[30];
	double notas[5][30], media[30];
	
	/* Abaixo a entrada eh armazenada em variaveis, sendo K o numero de candidatos
	   e NOTAS a matriz que armazena as notas de cada candidato. */
	
	scanf("%d", &k);
	
	for(i = 0; i < 5; i++)
		for(j = 0; j < k; j++)
			scanf("%lf", &notas[i][j]);
	
	/* Abaixo a saida do programa eh impressa, sendo que em cada parte da saida,
	   a funcao correspondente ao que vai ser impresso eh chamada.  */
	
	printf("Nota Media:");
	for(j = 0; j < k; j++) {
		media[j] = calculoMedia(j, notas);
		printf(" %.1f", media[j]);
	}
	printf("\n\n");
	
	printf("Preferencia:\n");
	for(i = 0; i < 5; i++) {
		printf("Membro %d:", i + 1);
		ordenarPreferencia(i, k, notas, preferencia);
		for(j = 0; j < k; j++)
			printf(" %d", preferencia[i][j]);
		printf("\n");
	}
	printf("\n");
	
	formarClassificacao(k, contador, preferencia, classificacao, media);
	printf("Classificacao:");
	for(j = 0; j < k; j++) {
		printf(" %d", classificacao[j]);
	}
	printf("\n");
		
	return 0;
}
