#include <stdio.h>

/* A funcao tem o objetivo de computar quantas espacos de memoria
   foram criados e quantos programas serao executados.  */
void verificarLetra(int *espacos, int *programas) {
	char letra;
	
	/* Eh feita a leitura de uma letra e, dependendo de qual for, os contadores
	   serao acrescidos. */
	scanf("%c", &letra);
	
	if(letra == 'D') {
		*espacos += 2;
		*programas += 1;
		verificarLetra(espacos, programas);
	}	
	
	if(letra == 'I') {
		*programas += 1;	
		verificarLetra(espacos, programas);
	}
}

int main() {
	int espacos = 1, programas = 0;
	
	verificarLetra(&espacos, &programas);

	/* Sera feita a comparacao entre a quantidade de espacos de memoria e a
	   quantidade de programas que serao executados.	 */
	if(espacos == programas)
		printf("Alocacao total\n");
	else if(espacos > programas)
		printf("Alocacao parcial\n");
	else 
		printf("Alocacao invalida\n");


	return 0;
}
