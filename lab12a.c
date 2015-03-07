/***********************************************************
 * Autor: Mateus de Carvalho Coelho
 * RA: 156675
 * Turma: R
 * Laboratorio 12a: CUT++
 *
 ***********************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMEARQ 101

/* Prototipo das funcoes utilizadas pela main */
void gera_csv_reduzido(char fnamein[], char fnameout[]);

int main(int argc, char *argv[]) {
    char fnamein[MAX_NOMEARQ], fnameout[MAX_NOMEARQ];

    strcpy(fnamein, argv[1]);
    strcpy(fnameout, argv[2]);

    gera_csv_reduzido(fnamein, fnameout);

    return 0;
}

void gera_csv_reduzido(char fnamein[], char fnameout[]) {
	int i, j, k, cont_virgulas = 0, numero_campos, n, *seq_campos, flag = 0;
	char letra, **matriz, lixo;
	FILE *entrada, *saida;
	entrada = fopen(fnamein, "r");
	saida = fopen(fnameout, "w");
	
	/* Abaixo eh feita a leitura da entrada padrao. N eh o numero de campos que
	   devem ser mostrados e seq_campos eh a sequencia de campos.*/
	scanf("%d", &n);
	seq_campos = malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%c%d", &lixo, &seq_campos[i]);
	
	/* O trecho abaixo le a quantidade de campos do arquivo de entrada. O numero
	   de virgulas + 1 eh igual ao numero de campos. */
	do {
		fscanf(entrada, "%c", &letra);
		if(letra == ',') cont_virgulas++;
	} while(letra != '\n');
	numero_campos = cont_virgulas + 1;
	
	/* Alocacao dinamica da matriz responsavel por armazenar os dados. Cada linha
	   da matriz corresponde ao campo de uma linha do arquivo de entrada. */
	matriz = malloc(numero_campos * sizeof(char*));
	for(i = 0; i < numero_campos; i++)
		matriz[i] = malloc(501 * sizeof(char));
	
	rewind(entrada);

	/* O codigo que esta dentro do seguinte while sera responsavel por analisar
	   uma linha do arquivo de entrada e imprimi-la do jeito pedido. A variavel
	   flag sera igual a 0 quando houverem linhas a serem analisadas e sera igual
	   a 1 quando arquivo acabar.  */	
	while(flag == 0) {	
		/* Armazenamento dos dados de uma linha na matriz. A funcao feof serve para
		   verificar se o arquivo de entrada chegou ao fim. Sera 0 quando chegar ao fim
		   e diferente de 0 quando nao for o fim. */	
		for(i = 0; i < numero_campos; i++) {
			j = 0;
			fscanf(entrada, "%c", &matriz[i][j]);
			while(matriz[i][j] != ',' && matriz[i][j] != '\n' && flag == 0) {
				j++;
				fscanf(entrada, "%c", &matriz[i][j]);
				if(feof(entrada)) flag = 1;
			}
			matriz[i][j] = '\0';
		}
		
		/* Impressao das informacoes de uma linha do arquivo de entrada,
		   usando a matriz, de acordo com a sequencia dada na entrada padrao. No
		   modo de impressao usado, as virgulas e os campos serao imprimidos
		   separamente, por isso faz-se necessario calcular quantas impressoes serao 
		   feitas, que eh 2 * quantidade de quantidade de campos - 1.  */
		for(i = 0, k = 0; i < 2 * n - 1 && flag == 0; i++) {
			if(i % 2 == 0) {
				fprintf(saida, "%s", matriz[seq_campos[k] - 1]);
				k++;
			}
			else 
				fprintf(saida, ",");	
		}
		if(flag == 0) fprintf(saida, "\n");
	}
	
	/* No trecho abaixo os arquivos sao fechados e as matrizes sao desalocadas. */
	for(i = 0; i < numero_campos; i++)
		free(matriz[i]);
	free(matriz);
	fclose(saida);
	fclose(entrada);
}

