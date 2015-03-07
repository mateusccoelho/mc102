/* 
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 11b - BibTeX
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Abaixo eh declarado o registro de cada referencia. As flags indicam se os 
   campos paginas, volume e numero foram dados. A variavel ordem guarda em que
   ordem as referencias foram dadas.  */

struct Dados {
	char autor[501];
	char titulo[501];
	char midia[101];
	char volume[51];
	char numero[51];
	char paginas[51];
	char ano[51];	
	int flag_paginas;
	int flag_numero;
	int flag_volume;
	int ordem;
};

int main() {
	int n, i = 0, j = 0, ind;
	char lixo, primeiro_carac, campo;
	struct Dados *entrada, aux;
	
	/* Abaixo eh feita a leitura da quantidade de referencias fornecidas. Eh feita
	   tambem a alocação do vetor que armazenara os registros das referencias. */
	
	scanf("%*c %d", &n);
	entrada = malloc(n * sizeof(struct Dados));
	
	/* Abaixo os \n sao lidos, ja que nao sao uteis para o programa. */
	scanf("%c%c", &lixo, &lixo);
	
	/* O grande loop abaixo sera responsavel por ler os dados das referencias. */
	for(i = 0; i < n; i++) {
		entrada[i].ordem = i;
		
		/* O laco abaixo le a label da referencia, ja que esta nao eh util. */
		do{scanf("%c", &lixo);} while (lixo != '\n');
		
		/* A estrutura abaixo tem como funcao saber se a linha deve ser lida. Para isso,
		   quando o primeiro caractere da linha for um espaço, o dado contido na linha
		   sera lido. Quando for um }, isso indica que o article acabou. */
		scanf("%c", &primeiro_carac);
		while(primeiro_carac == ' ') {
			
			/* A estrutura abaixo lera apenas a primeira letra do tipo de dado
			   (titulo, autor etc) a ser lido, visto que as primeiras letras sao
			   todas diferentes. Em seguida a leitura da informacao sera feita,
			   dependendo da primeira letra.*/
			scanf("%c", &campo);
			do{scanf("%c", &lixo);} while(lixo != '{');
			j = 0;
			if(campo == 'a') {
				scanf("%c", &entrada[i].autor[j]);
				while(entrada[i].autor[j] != '}') { 
					j++;
					scanf("%c", &entrada[i].autor[j]);
				}
				entrada[i].autor[j] = '\0';
			}
			else if(campo == 't') {
				scanf("%c", &entrada[i].titulo[j]);
				while(entrada[i].titulo[j] != '}') { 
					j++;
					scanf("%c", &entrada[i].titulo[j]);
				}
				entrada[i].titulo[j] = '\0';
			}
			else if(campo == 'j') {
			scanf("%c", &entrada[i].midia[j]);
				while(entrada[i].midia[j] != '}') { 
					j++;
					scanf("%c", &entrada[i].midia[j]);
				}
				entrada[i].midia[j] = '\0';
			}
			else if(campo == 'y') {
			scanf("%c", &entrada[i].ano[j]);
				while(entrada[i].ano[j] != '}') { 
					j++;
					scanf("%c", &entrada[i].ano[j]);
				}
				entrada[i].ano[j] = '\0';
			}
			else if(campo == 'v') {
			scanf("%c", &entrada[i].volume[j]);
				while(entrada[i].volume[j] != '}') { 
					j++;
					scanf("%c", &entrada[i].volume[j]);
				}
				entrada[i].volume[j] = '\0';
				entrada[i].flag_volume = 1;
			}
			else if(campo == 'p') {
			scanf("%c", &entrada[i].paginas[j]);
				while(entrada[i].paginas[j] != '}') { 
					j++;
					scanf("%c", &entrada[i].paginas[j]);
				}
				entrada[i].paginas[j] = '\0';
				entrada[i].flag_paginas = 1;
			}
			else {
			scanf("%c", &entrada[i].numero[j]);
				while(entrada[i].numero[j] != '}') { 
					j++;
					scanf("%c", &entrada[i].numero[j]);
				}
				entrada[i].numero[j] = '\0';
				entrada[i].flag_numero = 1;
			}
			/* Os scanf's abaixo tem a funcao de ler os \n e o primeiro caractere
			   da proxima linha. */
			scanf("%c%c", &lixo, &lixo);
			scanf("%c", &primeiro_carac);
		}
		
		/* O scanf abaixo le os \n que ficam depois do fim de uma referencia. */
		scanf("%c%c", &lixo, &lixo);
	}
	
	/* A estrutura abaixo eh um selection sort que fara a ordenacao dos registros
	   de acordo com o titulo, e se forem iguais, serao ordenados pela ordem de 
	   entrada. Ind guarda o indice do registro que devera ser trocado e aux eh
	   um registro auxiliar. */
	for (i = 0; i < (n - 1); i++) {
		ind = i;
		for (j = (i + 1); j < n; j++) {
			if(strcmp(entrada[j].titulo, entrada[ind].titulo) < 0)
				ind = j;
			else if(strcmp(entrada[j].titulo, entrada[ind].titulo) == 0)
				if(entrada[j].ordem < entrada[ind].ordem)
					ind = j;
		}
		if (i != ind) {
			aux = entrada[i];
			entrada[i] = entrada[ind];
			entrada[ind] = aux;
		}
	}
	
	/* A estrutura abaixo tem como funcao imprimir os articles formatados. */
	for(i = 0; i < n; i++) {
		printf("%s, %s, %s", entrada[i].titulo, entrada[i].autor, entrada[i].midia);
		if(entrada[i].flag_volume == 1)
			printf(", %s", entrada[i].volume);
		if(entrada[i].flag_numero == 1)
			printf(", %s", entrada[i].numero);
		if(entrada[i].flag_paginas == 1)
			printf(", %s", entrada[i].paginas);
		printf(", %s.\n\n", entrada[i].ano);
	}
	
	free(entrada);
	
	return 0;
}
