/*
Nome: Mateus de Carvalho Coêlho
RA: 156675
Turma: R
Lab 07b - Modern Word Search
*/

#include <stdio.h>

int cont;

/* Cada funcao abaixo tem como objetivo percorrer a tabela de formas diferentes,
   na horizontal, vertical e diagonal.*/

void horizontal(int m, int n, int tamanho, char tab[50][51], char palavra[26], char resultado[50][51]);
void vertical(int m, int n, int tamanho, char tab[50][51], char palavra[26], char resultado[50][51]);
void diagonal(int m, int n, int tamanho, char tab[50][51], char palavra[26], char resultado[50][51]);

int main () {
	
	/*
	tab - matriz que armazena a entrada dos caracteres.
	resultado - matriz onde sera armazenada a resposta do caca palavra.
	palavra - vetor que contem a palavra a ser buscada na tabela.
	M e N - numero de linhas e colunas, respectivamente.
	I e J - contadores.
	tamanho - quantidade de caracteres da palavra a ser buscada.
	*/
	
	/* A funcao main tera como objetivo fazer a leitura da entrada, preencher 
	   a matriz resultado de pontos, chamar as outras funcoes e imprimir a
	   saida do programa. */
	
	char tab[50][51], resultado[50][51], palavra[26];
	int m, n, i, j, tamanho;
	
	scanf("%d %d %s", &m, &n, palavra);
	
	for(tamanho = 0; palavra[tamanho] != '\0'; tamanho++);
	
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			resultado[i][j] = '.';
	
	for(i = 0; i < m; i++)
		scanf("%s", tab[i]);
		
	horizontal(m, n, tamanho, tab, palavra, resultado);
	vertical(m, n, tamanho, tab, palavra, resultado);
	diagonal(m, n, tamanho, tab, palavra, resultado);
	
	printf("%s %d\n", palavra, cont);
	
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++)
			printf("%c", resultado[i][j]);
		printf("\n");
	}
	
	return 0;
}

void vertical(int m, int n, int tamanho, char tab[50][51], char palavra[26], char resultado[50][51]) {
	
	/* O objetivo dessa funcao eh verificar se nas colunas da tabela existem a 
	   palavra a ser buscada. Ela so eh executada se a quantidade de linhas for
	   maior do que o tamanho da palavra. */
	
	int i, j, k, l, flag;
	
	if (tamanho <= m)
		for(j = 0; j < n; j++)
			for(i = 0; i <= m - tamanho; i++) {
				
				/* A funcao do loop abaixo eh verificar letra por letra se os 
				   caracteres da tabela formam a palavra escolhida, sempre
				   testando se o caractere eh uma letra ou um simbolo. O contador
				   k conta quantas letras da tabela sao iguais aas letras da
				   palavra. A flag indicara que ainda nao houve resultado quando
				   foi igual a 0 e indicara que ja eh conhecido o valor de k
				   quando for igual flag = 1. */
				
				for(k = 0, flag = 0; flag == 0 && k <= tamanho - 1; k++) {
					if (tab[i + k][j] != palavra[k] && tab[i + k][j] != '_' && tab[i + k][j] != '#' && tab[i + k][j] != '%') {
						flag = 1;
						k--;
					}
					if (tab[i + k][j] == '%')
						if (palavra[k] == 'a' || palavra[k] == 'e' || palavra[k] == 'i' || palavra[k] == 'o' || palavra[k] == 'u') {
							k--;
							flag = 1;
						}
					if (tab[i + k][j] == '#')
						if (palavra[k] != 'a' && palavra[k] != 'e' && palavra[k] != 'i' && palavra[k] != 'o' && palavra[k] != 'u') {
							flag = 1;
							k--;
						}
				}
				
				/* Se ele encontrar a palavra, isto eh, se o contador for igual
				   a 5, a palavra encontrada sera copiada para a matriz resultado
				   e cont (o qual conta quantas vezes a palavra foi achada na 
				   tabela) tambem sera acrescido em uma unidade. */
				
				if (k == tamanho) {
					for(l = 0; l < k; l++)
						resultado[i + l][j] = tab[i + l][j]; 
					cont++;
				}
			}
}

void horizontal(int m, int n, int tamanho, char tab[50][51], char palavra[26], char resultado[50][51]) {

	/* A funcao horizotal tem objetivo e estrutura bem semelhante aa da funcao
	   vertical, com a diferenca de que nessa funcao a verificacao eh feita nas
	   linhas. */
	
	int i, j, k, l, flag;
	
	if (tamanho <= n)
		for(i = 0; i < m; i++)
			for(j = 0; j <= n - tamanho; j++) {
				for(k = 0, flag = 0; flag == 0 && k <= tamanho - 1; k++) {
					if (tab[i][j + k] != palavra[k] && tab[i][j + k] != '_' && tab[i][j + k] != '#' && tab[i][j + k] != '%') {
						flag = 1;
						k--;
					}
					if (tab[i][j + k] == '%')
						if (palavra[k] == 'a' || palavra[k] == 'e' || palavra[k] == 'i' || palavra[k] == 'o' || palavra[k] == 'u') {
							k--;
							flag = 1;
						}
					if (tab[i][j + k] == '#')
						if (palavra[k] != 'a' && palavra[k] != 'e' && palavra[k] != 'i' && palavra[k] != 'o' && palavra[k] != 'u') {
							flag = 1;
							k--;
						}
				}
				if (k == tamanho) {
					for(l = 0; l < k; l++)
						resultado[i][j + l] = tab[i][j + l];
					cont++; 
				}
			}
}

void diagonal(int m, int n, int tamanho, char tab[50][51], char palavra[26], char resultado[50][51]) {

/* A funcao diagonal tem objetivo semelhante ao das outras funcoes, com a
   diferenca de que ela verifica caractere por caractere da tabela se ele forma
   a palavra na diagonal. */

int i, j, k, l, flag;

for(i = 0; i <= m - tamanho; i++)
	for(j = 0; j <= 	n - tamanho; j++) {
		for(k = 0, flag = 0; flag == 0 && k <= tamanho - 1; k++) {
			if (tab[i + k][j + k] != palavra[k] && tab[i + k][j + k] != '_' && tab[i + k][j + k] != '#' && tab[i + k][j + k] != '%') {
				flag = 1;
				k--;
			}
			if (tab[i + k][j + k] == '%')
				if (palavra[k] == 'a' || palavra[k] == 'e' || palavra[k] == 'i' || palavra[k] == 'o' || palavra[k] == 'u') {
					k--;
					flag = 1;
				}
			if (tab[i + k][j + k] == '#')
				if (palavra[k] != 'a' && palavra[k] != 'e' && palavra[k] != 'i' && palavra[k] != 'o' && palavra[k] != 'u') {
					flag = 1;
					k--;
				}
		}
		if (k == tamanho) {
			for(l = 0; l < k; l++)
				resultado[i + l][j + l] = tab[i + l][j + l]; 
			cont++;
		}
	}
}
