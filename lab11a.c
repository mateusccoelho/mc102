#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A struct abaixo armazenara todos os dados referentes a cada selecao. Assim
   serao criados 32 registros, um para selecao. A variavel flag sera 0 quando o
   registro estiver sem selecao definida e sera 1 quando ja existir uma selecao
   associada. 
   selecao - nome da selecao.
   gp - gols pro (feitos)
   gc - gols contra (sofridos) */

struct Dados {
	int flag;
	char selecao[15];
	int pontos;
	int gp;
	int gc;
};

/* A funcao abaixo tem como objetivo realizar a leitura dos gols marcados por cada
   selecao e computar esses dados nas variaveis de dentro dos registros. */

void lerDados(struct Dados matriz[8][4]) {
	int i, j, k, gols1, gols2, indice_time1, indice_time2, flag;
	char time1[15], time2[15];
	
	/* Os loops abaixo fazem a leitura das linhas da entrada em blocos de 6, porque
	   para cada grupo sao realizadas 6 partidas. A variavel i eh o contador do 
	   grupo, a variavel k eh o contador das partidas e a variavel j percorre
	   as selecoes de cada grupo. */
	
	for(i = 0; i < 8; i++)	
		for(k = 0; k < 6; k++) {
			scanf("%s %d x %d %s", time1, &gols1, &gols2, time2);
			
			/* O for abaixo tem como funcao percorrer a matriz procurando o nome
			   da selecao lida. Ele para quando flag = 1, isto eh, quando a selecao
			   ja foi encontrada. */
			
			for(j = 0, flag = 0; j < 4 && flag == 0; j++) {
				
				/* O if abaixo testa se o nome da selecao lida eh igual ao campo
				   selecao no registro de cada selecao. Caso seja, os gols serao computados.  */
				
				if(strcmp(time1, matriz[i][j].selecao) == 0) {
					matriz[i][j].gp += gols1;
					matriz[i][j].gc += gols2;
					indice_time1 = j;
					flag = 1;
				}
				
				/* O if abaixo verificara se o nome da selecao lida eh diferente
				   do campo selecao e, se for, o registro agora passara a ser o
				   registro da selecao lida e os gols serao computados. */
				
				else if(strcmp(time1, matriz[i][j].selecao) != 0 && matriz[i][j].flag == 0) {
					strcpy(matriz[i][j].selecao, time1); 
					matriz[i][j].gp += gols1;
					matriz[i][j].gc += gols2;
					indice_time1 = j;
					flag = 1;
					matriz[i][j].flag = 1;
				}	
			}
			
			/* O codigo abaixo fara o mesmo que o anterior mas para o segundo time
			   lido. */
			
			for(j = 0, flag = 0; j < 4 && flag == 0; j++) {
				if(strcmp(time2, matriz[i][j].selecao) == 0) {
					matriz[i][j].gp += gols2;
					matriz[i][j].gc += gols1;
					indice_time2 = j;
					flag = 1;
				}
				else if(strcmp(time2, matriz[i][j].selecao) != 0 && matriz[i][j].flag == 0) {
					strcpy(matriz[i][j].selecao, time2); 
					matriz[i][j].gp += gols2;
					matriz[i][j].gc += gols1;
					indice_time2 = j;
					flag = 1;
					matriz[i][j].flag = 1;
				}	
			}
			
			/* O trecho abaixo definira o resultado da partida acrescentando os pontos
		    	obtidos por cada time no campo pontos do registro.*/
			
			if (gols1 == gols2) {
				matriz[i][indice_time1].pontos += 1;
				matriz[i][indice_time2].pontos += 1;
			}
			else if(gols1 > gols2)
				matriz[i][indice_time1].pontos += 3;
			else				
				matriz[i][indice_time2].pontos += 3;
		}
}

/* A funcao abaixo tem como objetivo inicializar as variaveis do registro com
   valores 0. */

void zerarRegistro(struct Dados matriz[8][4]) {
	int i, j;
	for(i = 0; i < 8; i++)	
		for(j = 0; j < 4; j++) {
			matriz[i][j].flag = 0;
			matriz[i][j].pontos = 0;
			matriz[i][j].gp = 0;
			matriz[i][j].gc = 0;
		}
}

/* A funcao imprimirOitavas tem como objetivo imprimir os jogos de oitavas de final
   da copa de acordo com a classificacao, no grupo, de cada selecao. */

void imprimirOitavas(struct Dados matriz[8][4]) {
	int i;
	printf("Oitavas de final:\n");
	for(i = 0; i < 8; i += 2) {
		printf("%15s x %s\n", matriz[i][0].selecao, matriz[i + 1][1].selecao);
		printf("%15s x %s\n", matriz[i + 1][0].selecao, matriz[i][1].selecao);
	}
}

/* Essa funcao tem como objetivo imprimir as selecoes e seus dados de acordo com
   a formatacao de saida. */

void imprimirGrupos(struct Dados matriz[8][4]) {
	int i, j;
	for(i = 0; i < 8; i++) {
		printf("Grupo %c:\n", 65 + i);
		for(j = 0; j < 4; j++)
			printf("%-15s %3d %3d %3d %3d\n", matriz[i][j].selecao, matriz[i][j].pontos, matriz[i][j].gp, matriz[i][j].gc, matriz[i][j].gp - matriz[i][j].gc);
		printf("\n");
	}
}

/* A funcao ordenacao tem como objetivo ordenar as linhas da matriz de acordo
   com os criterios estabelecidos. */

void ordenacao(struct Dados matriz[8][4]) {
	int ind, i, j, k;
	struct Dados aux;
	
	/* Abaixo eh utilizado o algoritmo select sort para ordenar as selecoes.
	   A variavel ind armazena o indice da posicao do registro que sera ordenado. */
	
	for(i = 0; i < 8; i++)	
		for (j = 0; j < 3; j++) {
			ind = j;
			for (k = j + 1; k < 4; k++) {
				if(matriz[i][k].pontos > matriz[i][ind].pontos)
					ind = k;
				else if(matriz[i][k].pontos == matriz[i][ind].pontos) {
					if(matriz[i][k].gp - matriz[i][k].gc > matriz[i][ind].gp - matriz[i][ind].gc)
						ind = k;
					else if(matriz[i][k].gp - matriz[i][k].gc == matriz[i][ind].gp - matriz[i][ind].gc) {
						if(matriz[i][k].gp > matriz[i][ind].gp)
							ind = k;
						else if(matriz[i][k].gp == matriz[i][ind].gp)
							if(strcmp(matriz[i][k].selecao, matriz[i][ind].selecao) < 0)
								ind = k;
					}				
				}					
			}				

			/* Abaixo eh feita a troca de posicao dos registros usando um registro
			   auxiliar. */
			
			if (j != ind) {
				aux = matriz[i][j];
				matriz[i][j] = matriz[i][ind];
				matriz[i][ind] = aux;
			}
		}
}

/* A funcao main tem como objetivo declarar a matriz de registros e chamar as
   outras funcoes responsaveis pelo tratamento dos dados. */

int main() {
	struct Dados matriz[8][4];
	
	zerarRegistro(matriz);
	lerDados(matriz);
	ordenacao(matriz);
	imprimirGrupos(matriz);
	imprimirOitavas(matriz);

	return 0;
}
