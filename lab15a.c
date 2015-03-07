/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 15a - Transferencia de Bitcoins
*/

#include <stdio.h>

/* Testa se uma sequencia de sinais, quando aplicada aa sequencia de 9 numeros,
   chega no codigo verificador. */
int verificarIgualdade(char algarismos[], int sinais[], int verificador) {
	int i, sinal = 0, resultado = 0, numero = 0;
	
	/* Variaveis
	   sinal - guarda o sinal de soma ou subtracao lido.
	   resultado - guarda o numero resultante das operacoes realizadas.
	   numero - guarda o numero que esta sendo montado. */
	
	/* Percorre o vetor dos 9 algarismos ate a penultima posicao, montando os
	   numeros nele contidos, de acordo com a sequencia de sinais. Nesse algoritmo,
	   o sinal apos todo algarismo eh verificado. Tambem, quando um sinal igual
	   a 1 ou a 2 eh achado, a soma ou subtracao anterior eh realizada, e o sinal 
	   achado eh guardado na variavel 'sinal'. Inicialmente, o valor de 'sinal' 
	   sera igual a 0 para sinalizar de que nao existem operacoes anteriores a ela. */
	for(i = 0; i < 8; i++) {
		numero = numero*10 + (algarismos[i] - 48);
		if(sinais[i] != 3) {
			if(sinal == 0 || sinal == 1)
				resultado += numero;
			else if(sinal == 2)
				resultado -= numero;
			sinal = sinais[i];
			numero = 0;
		}
	}
	
	/* Analisa o ultimo algarismo do vetor separadamente dos outros, visto que
	   nao ha nenhum sinal apos esse algarismo. */
	numero = numero*10 + (algarismos[i] - 48);
	if(sinal == 1) 
		resultado += numero;
	else if(sinal == 2)
		resultado -= numero;
	else
		resultado = numero;
	
	/* Retorna 1 quando foi encontrada uma possbilidade se sinais valida. */
	if(resultado == verificador)
		return 1;
	else
		return 0;
}

/* Eh responsavel por criar combinacoes de sinais para serem testados na sequencia
   de 9 numeros. */
void permutacoes(int sinais[], char algarismos[], int verificador, int *flag, int local) {
	int i;
	
	/* Nessa funcao, numeros representam os sinais.
       1 - soma.
       2 - subtracao.
       3 - juncao de 2 algarismos. */
	
	/* O trecho abaixo cria possibilidades para cada local da sequencia, variando
	   os numeros dos locais e chamando a funcao novamente, para cada hipotese.*/
	if(local != 7) {
		for(i = 0; i < 3; i++) {
			sinais[local] = i + 1;
			permutacoes(sinais, algarismos, verificador, flag, local + 1);
			if(*flag == 1) return;
		}
	}
	
	/* Caso base. Acontece quando o algoritmo chega na ultima posicao do vetor.
	   Chama a funcao que testa se a sequencia de sinais montada no vetor,
	   quando aplicada aa sequencia de 9 numeros, chega no codigo verificador. */
	else {
		for(i = 0; i < 3; i++){
			sinais[local] = i + 1;
			*flag = verificarIgualdade(algarismos, sinais, verificador);
			if(*flag == 1) return;
		}
	}		
}

int main () {
    
	int i, verificador, local = 0, flag = 0, sinais[8];
	char algarismos[9];
	
	/* Variaveis
	   local - indica o ponto da sequencia no qual a funcao permutacoes sera
	           executada.
	   flag - sera 1 quando o programa achar uma resposta. */
	
	/* Leitura de dados. */
	for(i = 0; i < 9; i++)
		scanf("%c", &algarismos[i]);

	scanf("%d", &verificador);
	
	/* Funcao recursiva eh chamada pela primeira vez. */
	permutacoes(sinais, algarismos, verificador, &flag, local);
	
	/* Verificacao se o programa achou alguma combinacao de mais e menos para
	   a sequencia de numeros ser igual ao verificador. */
	if(flag == 1)
		printf("Transferencia aceita\n");
	else
		printf("Transferencia abortada\n");

	return 0;
}
