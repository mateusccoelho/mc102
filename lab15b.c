/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 15b - DON'T PANIC - Part II
*/

#include <stdio.h>
#include <stdlib.h>

/* --------------- Funcoes utilizadas na parte I ---------------------------- */

void trocar(int perm[], int i, int j) {
	int *segaux, k;
	
	/* A funcao troca 2 segmentos, alocando o primeiro segmento em um vetor 
	   auxiliar, arrastando os elementos do segundo segmento para o comeco da
	   permutacao e, em seguida, recolocando os elementos do primeiro segmento.
	    */
	
	segaux = malloc(i * sizeof(int));
	for(k = 1; k <= i; k++)
		segaux[k - 1] = perm[k];
	for(k = i + 1; k <= j; k++)
		perm[k - i] = perm[k];
	for(k = j - i + 1; k <= j; k++)
		perm[k] = segaux[k - (j - i + 1)];
	free(segaux);
	
}

void verificar2bp(int perm[], int n, int i, int j) {
	int k, prox, flag;
	
	/* As estruturas abaixo verificam se 2 breakpoints podem ser retirados,
	   seguindo o algoritmo do enunciado. */
	
	prox = perm[j + 1];
	for(k = 0, flag = 0; k <= n && flag == 0; k++)
		if(perm[k] == prox - 1) {
			if(k > j || k == 0)
				trocar(perm, i, j);
			else if(k < j) {
				i = k;
				trocar(perm, i, j);
			}
			flag = 1;	
		}
			
}

int compararPesos(int perm[], int n, int pv_strip, int va_strip, int *peso, int *j, int *flag_pv, int *flag_va) {
	int k, flag, peso_pv, peso_va, j_pv, j_va;
	
	/* Os 2 loops abaixo determinam o peso de cada troca e o ultimo elemento do
	   segmento a ser trocado com a primeira strip. */
	
	if(*flag_pv == 1)
		for(k = 1, flag = 0; k <= n && flag == 0; k++)
			if(perm[k] == pv_strip) {
				peso_pv = k - 1;
				flag = 1;
				j_pv = k;
			}	
	if(*flag_va == 1)
		for(k = 1, flag = 0; k <= n && flag == 0; k++)
			if(perm[k] == va_strip) {
				peso_va = k;
				flag = 1;
				j_va = k;
			}
	
	/* As condicionais a seguir verificam qual troca tem o menor peso. */
	
	if(*flag_pv == 1 && *flag_va == 1) {
		if(peso_pv < peso_va) {
			*peso = peso_pv;
			*j = j_pv - 1;
			return 1;
		}
		else {
			*peso = peso_va;
			*j = j_va;
			return 0;
		}
	}
	else if(*flag_pv == 1 && *flag_va == 0) {
		*peso = peso_pv;
		*j = j_pv - 1;
		return 1; 
	}
	else {
		*peso = peso_va;
		*j = j_va;
		return 0;
	}	
		
}

int identificarStrip(int perm[], int n, int *pv_strip, int *va_strip, int *i, int *flag_pv, int *flag_va) {
	
	int k, flag = 0;
	
	/* O loop abaixo para com o valor K sendo o indice do ultimo numero da
	   primeira strip. */ 
	
	for(k = 1; k <= n - 1 && flag == 0; k++)			
		if(perm[k + 1] - perm[k] != 1) {
			flag = 1;	
			k--;
		}
	
	/* As condicionais a seguir verificara se os valores proximo e anterior
	   aa primeira strip existem, e, se existir, os descobrira. */
	
	if(k != n) {
		if(perm[1] - 1 < 1)
			*flag_va = 0;
		else
			*va_strip = perm[1] - 1;
		if(perm[k] + 1 > n)
			*flag_pv = 0;
		else
			*pv_strip = perm[k] + 1;
		*i = k;
		return 0;
	}
	else
		return 1;
}

int acharLS(int perm[], int n) {
	int flag = 0, pv_strip, va_strip, opcao, total = 0, peso, i, j;
	int flag_pv = 1, flag_va = 1;
	
	/*O loop abaixo sera rodado enquanto a permutacao nao estiver ordenada. 
	  A funcao identificarStrip tem como obejtivo retornar o valor 1 se a
	  permutacao estiver totalmente ordenada ou retornar 0 se ela nao estiver
	  ordenada. A funcao identificarStrip retornara tambem os valores 
	  anteriores e posteriores aa primeira strip da permutacao, os quais
      serao guardados nas variaveis pv_strip e va_strip */
	
	while(flag == 0) {
		flag = identificarStrip(perm, n, &pv_strip, &va_strip, &i, &flag_pv, &flag_va);	
		
		/* Alem disso, as variaveis flag_pv e flag_va serao 1 quando existir o
		   proximo valor e o valor anterior aa strip e sera 0 quando nao existir.
		   Ela retorna, ainda, o indice do ultimo elemento da primeira strip, 
		   guardado na variavel I. */
		
		if(flag == 0) {
			
			/* A funcao compararPesos tem como objetivo definir qual a melhor 
			   troca a ser feita, se eh com o proximo valor aa primeira strip
			   ou se eh com o valor anterior aa primeira strip. Retornara 1 se
			   a troca sera com o proximo valor ou retornara 0 se a troca for
			   com o valor anterior. Alem disso, ela retornara o peso da troca
			   mais vantajosa e retornara o indice (J) do ultimo elemento do
			   segmento que sera trocado de lugar com a primeira strip. */
			
			opcao = compararPesos(perm, n, pv_strip, va_strip, &peso, &j, &flag_pv, &flag_va);
			total += peso;
			
			/* Dependendo do valor retornado pela funcao compararPesos, uma
			   outra funcao sera chamada. A funcao trocar efetua uma troca
			   de segmentos da sequencia e a funcao verificar2bp verifica se uma
			   troca que tira 2 breakpoints eh possivel. */
			
			if(opcao)
				trocar(perm, i, j);
			else
				verificar2bp(perm, n, i, j);
		}
		flag_pv = 1;
		flag_va = 1;
	}

	return total;
}

/* -------------------------------------------------------------------------- */

/* Tem como objetivo encontrar o peso total minimo. */ 
int acharLI(int perm[], int n) {
	int k, peso, flag = 0;
	
	/* Percorre o vetor da permutacao a procura do peso minimo. */
	/* Flag sera 1 quando o peso for encontrado. */
	for(k = n; k > 0 && flag == 0; k--)
		if(perm[k] != k) {
			peso = k;
			flag = 1;
		}
		
	if (flag == 1)
		return peso;
	else
		return 0;
}

/* Verifica se a permutacao esta ordenada. */
int verificarOrdenacao(int perm[], int n) {
	int k;
	
	/* Percorre o vetor da permutacao verificando se os numeros estao nas
	   posicoes corretas, isto eh, se o valor eh igual ao indice. */
	/* Retorna 1 se estiver ordenado e 0 se NAO estiver ordenado. */
	for(k = 1; k <= n; k++)
		if(perm[k] != k)
			return 0;
	
	return 1;
}

void geraTransposicao(int perm[], int n, int *limite, int peso) {
	int k, i, j, *vet_aux;

	/* Verifica se a permutacao esta ordenada. Se estiver, testa se o limite do
	   peso pode ser alterado.*/
	if(verificarOrdenacao(perm, n) == 1) {
		if(peso < *limite) {
			*limite = peso;	
			return;
		}
	}
	
	/* Testa todas as possibilidades de transposicao. Se alguma for valida, um
	   vetor auxiliar eh criado para que mudanca nao interfira na sequencia atual,
	   visto que ela sera usada para fazer outras trocas. */
	for(j = 2; j <= n; j++) {
		for(i = 1; i < j; i++) {
			if(peso + j < *limite) {
				vet_aux = malloc((n + 2) * sizeof(int));
				for(k = 0; k < n + 2; k++)
					vet_aux[k] = perm[k];
				
				trocar(vet_aux, i, j);
				peso += j;
				geraTransposicao(vet_aux, n, limite, peso);
				/* Apos ter passado por uma troca, o peso sera diminuido para que
				   ele possa retornar ao seu valor original. */ 
				peso -= j;
				free(vet_aux);
			}
		}
	}
}

int main() {
	
	int n, *perm, k, lim_sup, limite, lim_inf, peso = 0, *vet_aux;
	
	/* Variaveis
	   n - numero de panquecas.
	   perm - vetor que guarda a ordem das panquecas. */
	
	/* Abaixo a leitura eh feita, um vetor dinamico eh criado. */
	scanf("%d", &n);
	perm = malloc((n + 2) * sizeof(int));
	
	perm[0] = 0;	
	for(k = 1; k <= n; k++)
		scanf("%d", &perm[k]);
	perm[n + 1] = n + 1;
	
	/* Acha o limite inferior. */
	lim_inf = acharLI(perm, n);
	
	/* Executa o algoritmo de ordenacao utilizado no lab10b. Retorna o peso 
	   total da ordenacao, que eh o limite superior. */
	vet_aux = malloc((n + 2) * sizeof(int));
	for(k = 0; k < n + 2; k++)
		vet_aux[k] = perm[k];
	lim_sup = acharLS(vet_aux, n);
	free(vet_aux);
	
	/* Funcao recursiva que executa todas as possibilidades de transposicao a fim
	   de encontrar a solucao com o menor peso possivel. */
	limite = lim_sup;
	geraTransposicao(perm, n, &limite, peso);
	
	printf("Limitante inferior: %d\n", lim_inf);
	printf("Peso: %d\n", limite);
	printf("Limitante superior: %d\n", lim_sup);
	
	free(perm);
	return 0;
}
