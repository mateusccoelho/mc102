#include <stdio.h>

int main () {

	int sequencia[100]; 
	int i, k, maior, somatermos, indice, termos, exclusao, tamanho, flag;
	
	i = 0;
	k = 0;
	maior = 0;
	flag = 0;
	somatermos = 0;
	
	scanf ("%d %d", &termos, &exclusao);
			
	tamanho = termos - exclusao;
	
	while (i < termos) {
	
		scanf ("%d", &sequencia[i]);
		
		i++;
	
	}
	
	i = 0; 
	
	while (flag == 0) {
	
		while ((i + k) < (termos - (tamanho - 1 - k))) {
	
			if (sequencia[i] > maior) {
		
				maior = sequencia[i];
			
				indice = i;
		
			}
	
			i++;
	
		}
	
		i = 0;
	
		if (indice != k) {	
		
			while (indice < termos) {
			
				sequencia[i + k] = sequencia[indice];
		
				somatermos++;	
				indice++;
				i++; 
	
			}
		
		}
		
		termos = somatermos + k;
		
		if (termos == tamanho) {
	
			flag = 1;
	
		}
		
		else if (k + 1 + (tamanho - 1 - k) == tamanho + 1) {
			
			i = 0;
			
			flag = 1;
			
			while (i <= (termos - 3 - k)) {
			
				sequencia[k + 1 + i] = sequencia[k + 2 + i];				
			
				i++;
				
			}
			
			termos = tamanho;
			
		}
		
		k++;
		maior = 0;
		i = 0;
		somatermos = 0;
	
	}
	
	while (i < termos) {
	
		printf("%d", sequencia[i]);
	
		i++;
		
	}
	
	return 0;

}
